// BAK-07: projected state hash verification and the per-client sequence
// window (spec 05 "Sequence and replay" + "Projected state hash"; queue row
// BAK-07 acceptance "Mismatch rejected generically").
//
// A client packs its local state with the .pkB declared widths (the same
// algorithm PkbAuthority::projected_hash runs — BAK-05), puts the hash and
// the frame sequence number on the wire (NET-03 header fields), and the
// authority checks both before serving that client the next snapshot:
//
//   1. seq must land in (lastAccepted, lastAccepted + 8] per client; a
//      replay (`seq <= lastAccepted`) and a jump too far ahead are both
//      rejected with the SAME generic outcome — sequence violations +3.
//   2. The client hash is compared to the authority's projected hash for
//      the committed tick; a mismatch is trap 0x0D: generic rejection,
//      never naming a field — hash mismatch +1.
//   3. Every accepted tick's hash goes on a 64-deep ring (spec: "Redis
//      stores the last 64 projected hashes"; the Redis-backed store for
//      cross-process sessions is a later row — this is the in-memory one).
//
// Penalty model (spec 05): hash mismatch +1, rule violation +2, sequence
// violation +3. At 10 suspicion the client is forced to resync; at 25 the
// session is suspended. Suspicion never decreases inside the window.
#pragma once

#include "poko/authority/pkb_schema.hpp"

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace poko::authority {

class ProjectionGate {
public:
  enum class Verdict : std::uint8_t { accepted, rejected, forced_resync, suspended };
  struct Outcome {
    Verdict verdict = Verdict::accepted;
    // Generic only: a client-visible reason bucket, never a field or rule
    // name (spec 05: "returns generic rejection ... without revealing the
    // field").
    enum class Why : std::uint8_t { none, sequence, hash_mismatch, suspended_client };
    Why why = Why::none;
  };

  // Weights from the spec 05 penalty model.
  static constexpr std::uint64_t kHashMismatchWeight = 1;
  static constexpr std::uint64_t kRuleViolationWeight = 2;
  static constexpr std::uint64_t kSequenceViolationWeight = 3;
  static constexpr std::uint64_t kResyncAt = 10;
  static constexpr std::uint64_t kSuspendAt = 25;
  static constexpr std::size_t kHashRing = 64;   // last 64 projected hashes
  static constexpr std::uint32_t kSeqAhead = 8;  // reject seq > last + 8

  explicit ProjectionGate(PkbAuthority& auth) : auth_(auth) {}

  // Rules violations counted elsewhere (PkbAuthority's counter, BAK-06)
  // enter the same penalty model at the spec's +2 weight.
  [[nodiscard]] std::uint64_t suspicion() const {
    return kRuleViolationWeight * auth_.suspicion() + own_suspicion_;
  }

  // One client packet: its frame sequence number and the projected hash it
  // computed over its local copy of the committed state.
  [[nodiscard]] Outcome receive(std::uint32_t client, std::uint32_t seq, std::uint64_t client_hash) {
    Client& c = clients_[client];
    if (c.suspended) return {Verdict::suspended, Outcome::Why::suspended_client};

    // Sequence window: the same generic rejection for a replay and for a
    // jump too far ahead (spec 05: "Reject seq <= lastAccepted, seq >
    // lastAccepted + 8"), so a probing client cannot tell which it hit.
    if (c.has_last && (seq <= c.last_accepted || seq > c.last_accepted + kSeqAhead)) {
      own_suspicion_ += kSequenceViolationWeight;
      return settle(c, Verdict::rejected, Outcome::Why::sequence);
    }

    // Projected hash: the authority hash for the tick the client is
    // acknowledging is the one from the last committed snapshot (the client
    // packs tick, nonce and ack exactly as spec 05 orders them — BAK-05's
    // hook already does).
    const std::uint64_t authority_hash = auth_.authority().snapshot_for(client).projected_hash;
    if (client_hash != authority_hash) {
      own_suspicion_ += kHashMismatchWeight;
      return settle(c, Verdict::rejected, Outcome::Why::hash_mismatch);
    }

    c.last_accepted = seq;
    c.has_last = true;
    if (ring_.size() == kHashRing) ring_.erase(ring_.begin());
    ring_.push_back(authority_hash);
    return settle(c, Verdict::accepted, Outcome::Why::none);
  }

  // The server-side ring of accepted projected hashes, oldest first
  // (the Redis mirror replays exactly this to a joining replica).
  [[nodiscard]] std::vector<std::uint64_t> hash_ring() const { return ring_; }

  [[nodiscard]] bool suspended(std::uint32_t client) const {
    const auto it = clients_.find(client);
    return it != clients_.end() && it->second.suspended;
  }

  // Forced resync clears the window: the client restarts at the authority's
  // next accepted sequence number (it re-acks the current snapshot).
  void resync(std::uint32_t client) {
    Client& c = clients_[client];
    c.has_last = false;
    c.last_accepted = 0;
  }

  void suspend(std::uint32_t client) { clients_[client].suspended = true; }

private:
  struct Client {
    std::uint32_t last_accepted = 0;
    bool has_last = false;
    bool suspended = false;
  };

  // Penalty thresholds apply at the total (rule-weighted) suspicion; a
  // suspension latches for that client.
  [[nodiscard]] Outcome settle(Client& c, Verdict v, Outcome::Why why) {
    Outcome out{v, why};
    if (suspicion() >= kSuspendAt) {
      c.suspended = true;
      out.verdict = Verdict::suspended;
      out.why = Outcome::Why::suspended_client;
    } else if (suspicion() >= kResyncAt && v == Verdict::rejected) {
      out.verdict = Verdict::forced_resync;
    }
    return out;
  }

  PkbAuthority& auth_;
  std::unordered_map<std::uint32_t, Client> clients_;
  std::vector<std::uint64_t> ring_;
  std::uint64_t own_suspicion_ = 0;
};

} // namespace poko::authority
