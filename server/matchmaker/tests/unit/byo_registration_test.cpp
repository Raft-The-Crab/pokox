// BAK-13 acceptance: "Unsigned endpoint never Ready". A registration
// without a valid developer signature is refused before anything is
// written; a signed one must still pass the endpoint challenge; a
// verified registration writes a Ready slot with the 60 s heartbeat TTL;
// nonces are single-use; donor tokens read only their own game's .pkB and
// write session events — cross-game reads are denied.
#include "poko/matchmaker/byo_registration.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;
using Byo = ByoRegistration;
namespace net = poko::net;

Byo::Request req(const std::string& game = "g1", const std::string& endpoint = "10.0.0.1:9000") {
  Byo::Request r;
  r.game_id = game;
  r.version = "1.0.0";
  r.endpoint = endpoint;
  r.region = "eu-west";
  r.nonce = "n1";
  return r;
}
std::vector<std::uint8_t> key(std::uint8_t b) { return std::vector<std::uint8_t>(32, b); }
} // namespace

int main() {
  SlotRegistry reg;
  Byo byo(reg);
  byo.add_developer_key("dev1", key(0xAA));

  // The headline: an unsigned endpoint never reaches Ready.
  auto unsigned_req = req();
  check(byo.register_slot(unsigned_req, "dev1", 0) == Byo::Register::bad_signature, "unsigned refused");
  check(reg.find("byo:g1:n1") == nullptr, "nothing was written for the unsigned request");

  // Wrong key refused too.
  auto wrong_key = req();
  wrong_key.developer_sig = std::vector<std::uint8_t>(32, 0);
  check(byo.register_slot(wrong_key, "dev1", 0) == Byo::Register::bad_signature, "bad MAC refused");

  // Signed but no challenge (unreachable endpoint): still never Ready.
  auto signed_req = req();
  const auto mac = net::hmac_sha256(key(0xAA),
                                    reinterpret_cast<const std::uint8_t*>(Byo::canonical(signed_req).data()),
                                    Byo::canonical(signed_req).size());
  signed_req.developer_sig = mac;
  check(byo.register_slot(signed_req, "dev1", 5) == Byo::Register::challenge_failed,
        "signed but unchallenged endpoint refused");
  check(reg.find("byo:g1:n1") == nullptr, "unchallenged endpoint wrote nothing");

  // Signed + challenged: Ready slot written, bound to the game.
  bool challenged = false;
  byo.set_challenge([&](const std::string& endpoint, const std::vector<std::uint8_t>& expected) {
    check(endpoint == "10.0.0.1:9000", "challenge went to the registered endpoint");
    check(expected.size() == 32, "challenge value is a fresh 32-byte probe");
    challenged = true;
    return expected; // the endpoint echoes the probe
  });
  check(byo.register_slot(signed_req, "dev1", 10) == Byo::Register::registered, "verified registration accepted");
  check(challenged, "endpoint was actually challenged");
  const auto* slot = reg.find("byo:g1:n1");
  check(slot != nullptr && slot->state == SlotRegistry::State::ready, "verified registration wrote Ready");
  check(slot->game_id == "g1" && slot->source == SlotRegistry::Source::byo, "slot bound to the game, BYO source");

  // Replay: the same nonce is single-use, even with a valid signature.
  auto replay = req();
  replay.developer_sig = net::hmac_sha256(key(0xAA),
                                          reinterpret_cast<const std::uint8_t*>(Byo::canonical(replay).data()),
                                          Byo::canonical(replay).size());
  check(byo.register_slot(replay, "dev1", 11) == Byo::Register::nonce_reused, "replayed nonce refused");

  // Tamper one canonical field after signing: signature no longer holds.
  auto tampered = req();
  tampered.endpoint = "10.0.0.9:9999"; // different endpoint than signed
  tampered.developer_sig = net::hmac_sha256(key(0xAA),
                                            reinterpret_cast<const std::uint8_t*>(
                                                Byo::canonical(req()).data()),
                                            Byo::canonical(req()).size());
  check(byo.register_slot(tampered, "dev1", 12) == Byo::Register::bad_signature, "tampered payload refused");

  // Donor token scoping: own game's .pkB and session events allowed;
  // cross-game reads and everything else denied (IDN-06 gate).
  const auto token = byo.mint_donor_token("g1", "n1");
  check(token.has_value(), "token minted after the verified registration");
  check(Byo::donor_allowed(*token, Byo::Perm::read_own_pkb, "g1"), "own game .pkB read allowed");
  check(Byo::donor_allowed(*token, Byo::Perm::write_session_events, "g1"), "own session-event write allowed");
  check(!Byo::donor_allowed(*token, Byo::Perm::read_own_pkb, "g2"), "cross-game read denied");
  check(Byo::donor_allowed(*token, Byo::Perm::read_own_pkb, "g1"), "own-game read still allowed after a denial");

  // Token minting requires a verified registration; unknown nonce -> no.
  check(!byo.mint_donor_token("g1", "never-seen").has_value(), "no token without a verified registration");

  // Registry caps still apply through the gate: a 4th platform slot for a
  // game is refused (BYO source here, so platform cap is bypassed, but a
  // duplicate slot id — same nonce — is a registry refusal).
  auto dup = req();
  dup.developer_sig = net::hmac_sha256(key(0xAA),
                                       reinterpret_cast<const std::uint8_t*>(Byo::canonical(dup).data()),
                                       Byo::canonical(dup).size());
  check(byo.register_slot(dup, "dev1", 13) == Byo::Register::nonce_reused, "duplicate registration is a replay");

  // The written slot follows the registry heartbeat rules: 60 s silence
  // flips it Dead.
  check(reg.platform_ccu(70) == 0, "silent BYO slot expired by the registry TTL");
  check(reg.find("byo:g1:n1")->state == SlotRegistry::State::dead, "missing heartbeat flips to Dead");

  if (errors == 0) std::cout << "OK: all BYO registration checks passed\n";
  else std::cout << errors << " check(s) FAILED\n";
  return errors == 0 ? 0 : 1;
}
