// BAK-14: reconnection flow (spec 07 "Reconnection"; queue row BAK-14
// acceptance "Same tick within 30 s").
//
// Spec 07: "Within 30 s, a client presents sessionId and nonce. If the
// session and player slot still exist, a new ticket is issued and the
// game plane resumes from the last accepted tick. If the slot died, rejoin
// the queue. No cross-slot state migration in v1." Anti-abuse: "Reconnect
// nonces are single-use." API: "All authenticated and idempotent via
// requestId."
//
// This module is the Worker-side reconnection gate over BAK-09's tickets
// and BAK-11's registry (in-process mirror, same arrangement as
// BAK-02/10/11/12/13). "Same tick within 30 s" is proven as a resumption
// property: the reconnecting player's view resumes at exactly the last
// accepted tick recorded for the session — never a rewound or advanced
// tick — whenever the reconnect lands inside the 30 s window on the same
// slot. No cross-slot state migration: a reconnect against a dead or
// different slot is refused, and the queue path (BAK-10) is the only
// fallback.
#pragma once

#include "poko/matchmaker/allocator.hpp"   // TicketSigner
#include "poko/matchmaker/slot_registry.hpp"

#include <cstdint>
#include <map>
#include <optional>
#include <set>
#include <string>

namespace poko::matchmaker {

class ReconnectFlow {
public:
  static constexpr std::uint64_t kReconnectWindowTicks = 30; // "Within 30 s"

  struct Session {
    std::uint32_t session_id = 0;
    std::uint32_t slot_id = 0;
    std::string game_id;
    std::uint32_t version = 0;
    std::uint64_t last_accepted_tick = 0; // the game plane's resume point
    bool active = true;                   // a departed player ends the session
  };

  struct Result {
    enum class Kind : std::uint8_t {
      reconnected,        // new ticket issued; resume at last_accepted_tick
      unknown_session,    // generic refusal (never says which part failed)
      window_closed,      // past the 30 s window
      slot_gone,          // slot dead/draining: rejoin the queue
      nonce_reused,
      inactive
    };
    Kind kind = Kind::unknown_session;
    TicketSigner::Ticket ticket{};      // valid when kind == reconnected
    std::uint64_t resume_tick = 0;      // the game plane's resume point
  };

  ReconnectFlow(SlotRegistry& registry, const TicketSigner& signer)
      : registry_(registry), signer_(signer) {}

  void register_session(const Session& s) { sessions_[s.session_id] = s; }

  [[nodiscard]] const Session* session(std::uint32_t session_id) const {
    auto it = sessions_.find(session_id);
    return it == sessions_.end() ? nullptr : &it->second;
  }

  // POST /match/reconnect: sessionId + single-use nonce inside 30 s.
  // Fail-closed in order: session exists and is active, nonce single-use,
  // window, slot alive — only then a new ticket and the resume tick.
  [[nodiscard]] Result reconnect(std::uint32_t session_id, std::uint64_t nonce, std::uint64_t now_tick) {
    Result r;
    const auto* s = session(session_id);
    if (!s) return r; // generic: unknown session
    if (!s->active) { r.kind = Result::Kind::inactive; return r; }

    const std::string key = std::to_string(session_id) + ":" + std::to_string(nonce);
    if (used_nonces_.count(key)) { r.kind = Result::Kind::nonce_reused; return r; }

    if (now_tick > s->last_accepted_tick + kReconnectWindowTicks) {
      r.kind = Result::Kind::window_closed;
      used_nonces_.insert(key); // a failed attempt still burns the nonce
      return r;
    }

    const auto* slot = registry_.find(std::to_string(s->slot_id));
    if (!slot || (slot->state != SlotRegistry::State::ready && slot->state != SlotRegistry::State::full)) {
      r.kind = Result::Kind::slot_gone; // "if the slot died, rejoin the queue"
      used_nonces_.insert(key);
      return r;
    }

    r.kind = Result::Kind::reconnected;
    r.resume_tick = s->last_accepted_tick; // same tick: the plane resumes exactly here
    r.ticket = signer_.issue(s->session_id, s->slot_id, s->version, now_tick);
    used_nonces_.insert(key);
    return r;
  }

  // The game plane accepted a new tick for the session (advances the
  // resume point for the next reconnect).
  void advance(std::uint32_t session_id, std::uint64_t accepted_tick) {
    auto it = sessions_.find(session_id);
    if (it != sessions_.end()) it->second.last_accepted_tick = accepted_tick;
  }

  // Player departure ends the session (a reconnect then refuses).
  void end_session(std::uint32_t session_id) {
    auto it = sessions_.find(session_id);
    if (it != sessions_.end()) it->second.active = false;
  }

private:
  SlotRegistry& registry_;
  const TicketSigner& signer_;
  std::map<std::uint32_t, Session> sessions_;
  std::set<std::string> used_nonces_;
};

} // namespace poko::matchmaker
