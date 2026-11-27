// BAK-09: matchmaker allocation and HMAC tickets (spec 07 "Allocation
// algorithm"; queue row BAK-09 acceptance "Ticket issued").
//
// One allocation request runs the spec's pipeline: authenticate (the
// Firebase-token step is the Worker's job — this module takes the
// already-authenticated player), rank candidates
// `score = latencyWeight*rtt + loadPenalty*playerCount - affinityBonus`,
// filter Full/Dead/Draining and version-mismatched slots, pick the best
// Ready platform slot (respecting the 20-CCU platform cap, FIX F3), else
// an opted-in donated/BYO slot, else trigger a wake on the nearest Cold
// slot, else queue — and on a pick issue a 30-second truncated
// HMAC-SHA256 ticket containing sessionId, slotId, nonce and version
// (NET-03's frame.hpp supplies the HMAC primitive). Tickets carry no
// player identity; the slot validates MAC and expiry, nothing else.
// Fail-closed: an expired or MAC-mismatched ticket is refused generically.
#pragma once

#include "poko/net/frame.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace poko::matchmaker {

class TicketSigner {
public:
  struct Ticket {
    std::uint32_t session_id = 0;
    std::uint32_t slot_id = 0;
    std::uint64_t nonce = 0;
    std::uint32_t version = 0;
    std::uint64_t issued_tick = 0;  // validity window in ticks
    std::uint64_t expires_tick = 0;
    std::array<std::uint8_t, 16> mac{}; // truncated HMAC, NET-03 discipline
  };

  // The ticket layer counts seconds as ticks; callers convert their own
  // tick rate once, at the boundary.
  static constexpr std::uint64_t kValidityTicks = 30; // 30-second ticket

  explicit TicketSigner(std::string_view secret) : key_(secret.begin(), secret.end()) {}
  TicketSigner(const void* data, std::size_t len) : key_(static_cast<const std::uint8_t*>(data), static_cast<const std::uint8_t*>(data) + len) {}

  [[nodiscard]] Ticket issue(std::uint32_t session_id, std::uint32_t slot_id,
                             std::uint32_t version, std::uint64_t now_tick) const {
    Ticket t;
    t.session_id = session_id;
    t.slot_id = slot_id;
    t.nonce = nonce_for(now_tick, session_id, slot_id);
    t.version = version;
    t.issued_tick = now_tick;
    t.expires_tick = now_tick + kValidityTicks;
    t.mac = mac_of(t);
    return t;
  }

  // Fail-closed: expiry first, then MAC. Expiry is computed from the
  // MAC-covered issued_tick, never from the client-carried expires_tick
  // (which the MAC does not cover and a client could rewrite to keep a
  // ticket alive forever). The refusal bucket is generic — a probing
  // client learns only "rejected", not which.
  enum class Check : std::uint8_t { ok, expired, bad_mac };
  [[nodiscard]] static Check check(const Ticket& t, const TicketSigner& signer, std::uint64_t now_tick) {
    if (now_tick >= t.issued_tick + kValidityTicks) return Check::expired;
    return t.mac == signer.mac_of(t) ? Check::ok : Check::bad_mac;
  }

private:
  [[nodiscard]] std::array<std::uint8_t, 16> mac_of(const Ticket& t) const {
    std::uint8_t body[28];
    auto put32 = [&](std::size_t off, std::uint32_t v) {
      for (int i = 0; i < 4; ++i) body[off + i] = static_cast<std::uint8_t>(v >> (8 * i));
    };
    auto put64 = [&](std::size_t off, std::uint64_t v) {
      for (int i = 0; i < 8; ++i) body[off + i] = static_cast<std::uint8_t>(v >> (8 * i));
    };
    put32(0, t.session_id);
    put32(4, t.slot_id);
    put64(8, t.nonce);
    put32(16, t.version);
    put64(20, t.issued_tick);
    const auto full = poko::net::hmac_sha256(key_, body, sizeof body);
    std::array<std::uint8_t, 16> out{};
    std::copy(full.begin(), full.begin() + 16, out.begin());
    return out;
  }

  // Deterministic nonce: tick, session and slot mixed (splitmix-style).
  // Two tickets for the same session never share a nonce; nothing random.
  [[nodiscard]] static std::uint64_t nonce_for(std::uint64_t tick, std::uint32_t session, std::uint32_t slot) {
    std::uint64_t z = tick * 0x9e3779b97f4a7c15ULL ^ (static_cast<std::uint64_t>(session) << 32) ^ slot;
    z ^= z >> 33; z *= 0xff51afd7ed558ccdULL; z ^= z >> 33;
    return z;
  }

  std::vector<std::uint8_t> key_;
};

struct Slot {
  std::uint32_t id = 0;
  enum class State : std::uint8_t { cold, waking, ready, full, draining, dead };
  State state = State::cold;
  enum class Source : std::uint8_t { platform, donated, byo };
  Source source = Source::platform;
  std::uint32_t player_count = 0;
  std::uint32_t version = 0;
  double rtt_ms = 0;
  bool opted_in = true; // donated/BYO: owner opted into this realm
};

class Matchmaker {
public:
  static constexpr std::uint32_t kPlatformCcuCap = 20; // FIX F3: platform slots only
  static constexpr std::uint32_t kSlotCap = 20;        // per-slot players

  Matchmaker(double latency_weight, double load_penalty, std::uint32_t platform_ccu_now)
      : latency_weight_(latency_weight), load_penalty_(load_penalty), platform_ccu_(platform_ccu_now) {}

  struct Decision {
    enum class Outcome : std::uint8_t { allocated_platform, allocated_donated, waking, queued };
    Outcome outcome = Outcome::queued;
    std::uint32_t slot_id = 0; // 0 when queued
    double score = 0;
  };

  // Candidates in any order; the decision is deterministic — score ties
  // break by lower slot id.
  [[nodiscard]] Decision allocate(const std::vector<Slot>& slots, std::uint32_t version,
                                  const std::vector<std::uint32_t>& affinity_slot_ids) const {
    Decision d;
    double best = 0;
    std::uint32_t wake_candidate = 0;
    bool have_pick = false, have_wake = false;
    for (const auto& s : slots) {
      if (s.version != version) continue;                                   // version mismatch: filtered
      if (s.state == Slot::State::dead || s.state == Slot::State::draining ||
          s.state == Slot::State::full) continue;                           // filtered per spec
      if (s.player_count >= kSlotCap) continue;
      const double score = latency_weight_ * s.rtt_ms + load_penalty_ * s.player_count - affinity_bonus(s.id, affinity_slot_ids);
      const bool better = !have_pick || score < best || (score == best && s.id < d.slot_id);
      if (s.state == Slot::State::ready) {
        if (s.source == Slot::Source::platform) {
          if (platform_ccu_ >= kPlatformCcuCap) continue; // FIX F3: at cap, fall through to donated/queue
          if (better) { best = score; d.slot_id = s.id; d.outcome = Decision::Outcome::allocated_platform; have_pick = true; }
        } else if (s.opted_in && better) {
          best = score; d.slot_id = s.id; d.outcome = Decision::Outcome::allocated_donated; have_pick = true;
        }
      } else if (s.state == Slot::State::cold && !have_wake) {
        wake_candidate = s.id;
        have_wake = true;
      }
    }
    if (have_pick) { d.score = best; return d; }
    if (have_wake) { d.outcome = Decision::Outcome::waking; d.slot_id = wake_candidate; return d; }
    return d; // queued, slot_id 0
  }

  // The worker decrements this as platform sessions end; a single allocate
  // call consumes at most the remaining cap.
  void set_platform_ccu(std::uint32_t ccu) { platform_ccu_ = ccu; }

private:
  [[nodiscard]] static double affinity_bonus(std::uint32_t slot_id, const std::vector<std::uint32_t>& affinity) {
    for (const auto a : affinity) if (a == slot_id) return 10.0;
    return 0.0;
  }

  double latency_weight_, load_penalty_;
  std::uint32_t platform_ccu_;
};

} // namespace poko::matchmaker
