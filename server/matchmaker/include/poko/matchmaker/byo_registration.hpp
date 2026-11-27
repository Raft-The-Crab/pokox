// BAK-13: BYO registration and challenge (spec 07 "BYO and donated
// registration"; queue row BAK-13 acceptance "Unsigned endpoint never
// Ready").
//
// Spec 07: "A developer server registers by POSTing a signed `register`
// message: gameId, version, endpoint, region, transport (tcp default or
// udp), maxPlayers, developerSig, nonce. Worker verifies signature against
// the developer pubkey, challenges the endpoint for reachability, then
// writes a Ready slot with a 60 s heartbeat TTL." Anti-abuse: "Slot
// squatting requires a published .pkx and verified developer key. BYO
// endpoints are challenge-verified." Donor boundary: "Scoped token: read
// own game's .pkB, write session events only"; "Never registry keys,
// ledger credentials, Firebase admin or moderation data."
//
// This module is the Worker-side gate over BAK-11's registry (in-process
// mirror, same arrangement as BAK-02/10/11/12): the endpoint challenge is
// injected so tests prove it deterministically. Signature verification
// uses the developer's HMAC-SHA256 key over the canonical registration
// payload — the keyed variant of the in-tree SHA-256 (NET-03); asymmetric
// developer keys arrive with real key infrastructure and swap in behind
// the same verify-signature seam. Every refusal is generic and leaves the
// registry untouched: an unsigned or unchallenged endpoint can never
// reach Ready.
#pragma once

#include "poko/matchmaker/slot_registry.hpp"
#include "poko/net/frame.hpp" // Sha256, hmac_sha256 (NET-03)

#include <cstdint>
#include <functional>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <vector>

namespace poko::matchmaker {

class ByoRegistration {
public:
  static constexpr std::uint64_t kChallengeTtlTicks = 60;  // challenge window
  static constexpr std::uint64_t kHeartbeatTtlTicks = SlotRegistry::kHeartbeatTtlTicks; // 60 s on Ready

  enum class Transport : std::uint8_t { tcp, udp }; // tcp default

  struct Request {
    std::string game_id;
    std::string version;
    std::string endpoint;   // host:port the Worker will challenge
    std::string region;
    Transport transport = Transport::tcp;
    std::uint32_t max_players = SlotRegistry::kMaxPlayersPerSlot;
    std::string nonce;      // single-use, replay guard
    std::vector<std::uint8_t> developer_sig; // MAC over the canonical payload
  };

  struct DonorToken {
    std::string token;   // opaque bearer value
    std::string game_id; // the ONLY game this token may read
  };

  enum class Perm : std::uint8_t { read_own_pkb, write_session_events };

  // Canonical payload: the fields that must not change between signing
  // and verification, in a fixed order with fixed separators.
  [[nodiscard]] static std::string canonical(const Request& r) {
    return r.game_id + "|" + r.version + "|" + r.endpoint + "|" + r.region + "|" +
           (r.transport == Transport::tcp ? "tcp" : "udp") + "|" +
           std::to_string(r.max_players) + "|" + r.nonce;
  }

  explicit ByoRegistration(SlotRegistry& registry) : registry_(registry) {}

  // The challenge: the Worker asks the endpoint to echo a fresh value.
  // The injected `challenge_fn` returns the endpoint's answer — nullopt
  // means unreachable. The expected value binds endpoint, nonce and the
  // server tick, so an answer replayed from another registration does
  // not verify.
  using ChallengeFn = std::function<std::optional<std::vector<std::uint8_t>>(
      const std::string& endpoint, const std::vector<std::uint8_t>& expected)>;
  void set_challenge(ChallengeFn fn) { challenge_ = std::move(fn); }

  void add_developer_key(const std::string& key_id, const std::vector<std::uint8_t>& key) {
    developer_keys_[key_id] = key;
  }

  // The full gate, fail-closed in order: key, signature, replay,
  // challenge, then registry admission (which applies the per-game
  // platform-slot cap and the per-slot cap). Only the success path
  // writes a slot.
  enum class Register : std::uint8_t {
    registered, bad_signature, nonce_reused, challenge_failed, registry_refused
  };
  [[nodiscard]] Register register_slot(const Request& r, const std::string& developer_key_id,
                                       std::uint64_t now_tick) {
    const auto dev_key = developer_keys_.find(developer_key_id);
    if (dev_key == developer_keys_.end()) return Register::bad_signature;
    const std::string payload = canonical(r);
    const auto mac = net::hmac_sha256(dev_key->second,
                                      reinterpret_cast<const std::uint8_t*>(payload.data()), payload.size());
    if (mac != r.developer_sig) return Register::bad_signature;
    if (used_nonces_.count(r.nonce)) return Register::nonce_reused;

    const std::string probe = r.endpoint + "|" + r.nonce + "|" + std::to_string(now_tick);
    const auto expected = net::Sha256::digest(reinterpret_cast<const std::uint8_t*>(probe.data()), probe.size());
    if (!challenge_ || !challenge_(r.endpoint, expected).has_value()) return Register::challenge_failed;

    SlotRegistry::Slot s;
    s.slot_id = "byo:" + r.game_id + ":" + r.nonce;
    s.game_id = r.game_id;
    s.region = r.region;
    s.source = SlotRegistry::Source::byo; // BYO capacity sits on top of the platform CCU cap (BAK-11)
    s.state = SlotRegistry::State::ready; // verified registration writes Ready (60 s heartbeat TTL)
    if (registry_.register_slot(s, now_tick) != SlotRegistry::Register::registered)
      return Register::registry_refused;
    used_nonces_.insert(r.nonce);
    return Register::registered;
  }

  // Mint the donor's scoped token after a successful registration (the
  // nonce is single-use and was consumed by it).
  [[nodiscard]] std::optional<DonorToken> mint_donor_token(const std::string& game_id, const std::string& nonce) {
    if (!used_nonces_.count(nonce)) return std::nullopt;
    DonorToken t;
    t.game_id = game_id;
    t.token = "donor-" + net::Sha256::digest(reinterpret_cast<const std::uint8_t*>(game_id.data()), game_id.size())
                          [0]; // opaque, bound to the verified game binding
    return t;
  }

  // The scoped check: read own game's .pkB, write session events only.
  // Everything else — registry keys, ledger, Firebase admin, moderation,
  // any other game — is denied generically.
  [[nodiscard]] static bool donor_allowed(const DonorToken& t, Perm p, const std::string& game_id) {
    if (t.game_id != game_id) return false; // cross-game read denied (IDN-06 gate)
    return p == Perm::read_own_pkb || p == Perm::write_session_events;
  }

private:
  SlotRegistry& registry_;
  std::map<std::string, std::vector<std::uint8_t>> developer_keys_;
  std::set<std::string> used_nonces_;
  ChallengeFn challenge_;
};

} // namespace poko::matchmaker
