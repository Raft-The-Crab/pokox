// BAK-11: slot registry with atomic counters (spec 07 "Capacity
// boundaries" and "Slot states"; queue row BAK-11 acceptance "CCU never
// exceeds 20").
//
// Spec 07: "Global platform CCU | D1 | Atomic, hard cap 20", "Per-game
// platform slots | D1 | Max 3", "Per-slot players | Slot process | Max 20,
// matches heartbeat". "D1 is the source of truth; Redis is a fast mirror."
// Slot states: "Cold, Waking, Ready, Full, Draining, Dead" with "wake
// timeout 30 s, drain 5 min"; BYO registration writes "a Ready slot with a
// 60 s heartbeat TTL. Missing heartbeat flips to Dead." Anti-abuse: "CCU
// reports are cross-checked against admitted tickets every 10 s."
//
// This module is the in-process mirror of the D1 registry — same
// arrangement as BAK-02's in-memory authority and BAK-10's in-memory
// queue: the Worker swaps the backing store for the real database, and the
// unit tests prove the capacity semantics deterministically. "Atomic" here
// means every admission goes through one check-and-increment step that
// either succeeds completely or leaves every counter untouched — there is
// no path that adds a player without first proving every cap has room, so
// platform CCU above 20 is structurally impossible, not merely checked
// after the fact.
#pragma once

#include <algorithm>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace poko::matchmaker {

class SlotRegistry {
public:
  static constexpr std::uint32_t kPlatformCcuCap = 20;    // atomic, hard cap
  static constexpr std::uint32_t kPlatformSlotsPerGame = 3;
  static constexpr std::uint32_t kMaxPlayersPerSlot = 20; // matches heartbeat
  static constexpr std::uint64_t kHeartbeatTtlTicks = 60; // missing heartbeat flips to Dead
  static constexpr std::uint64_t kWakeTimeoutTicks = 30;
  static constexpr std::uint64_t kDrainTicks = 300;       // drain 5 min

  enum class State : std::uint8_t { cold, waking, ready, full, draining, dead };
  enum class Source : std::uint8_t { platform, donated, byo };

  struct Slot {
    std::string slot_id;
    std::string game_id;
    Source source = Source::platform;
    State state = State::ready;
    std::string region;
    std::uint32_t players = 0;
    std::uint64_t last_heartbeat_tick = 0;
  };

  // Register a slot (POST /dev/slot/register). Platform slots beyond the
  // 3-per-game boundary are refused; donated/BYO capacity is uncapped
  // ("Donated nodes add capacity on top; global CCU is uncapped" — the
  // per-slot 20 still binds everywhere).
  enum class Register : std::uint8_t { registered, platform_slot_cap, duplicate };
  [[nodiscard]] Register register_slot(const Slot& s, std::uint64_t now_tick) {
    if (find(s.slot_id)) return Register::duplicate;
    if (s.source == Source::platform) {
      std::uint32_t count = 0;
      for (const auto& [id, slot] : slots_) {
        (void)id;
        if (slot.source == Source::platform && slot.game_id == s.game_id) ++count;
      }
      if (count >= kPlatformSlotsPerGame) return Register::platform_slot_cap;
    }
    Slot copy = s; // state kept as given; the default is Ready (spec: a
                   // registration writes a Ready slot)
    copy.last_heartbeat_tick = now_tick;
    slots_[copy.slot_id] = copy;
    return Register::registered;
  }

  // Heartbeat (POST /dev/slot/heartbeat): refresh the TTL only. The
  // player count is the registry's own admission count — the truth — and
  // reports can never set it: a forged lower report cannot free seats,
  // a forged higher one cannot exceed the cap (anti-abuse: CCU reports
  // are cross-checked against admitted tickets). Full -> Ready happens
  // only through release (a real departure).
  [[nodiscard]] bool heartbeat(const std::string& slot_id, std::uint32_t reported_players, std::uint64_t now_tick) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end()) return false;
    it->second.last_heartbeat_tick = now_tick;
    return true;
  }

  // "Missing heartbeat flips to Dead": run at read/admission time with
  // server time. Draining slots expire to Dead after the drain window.
  // A dead platform slot releases its seats from the global counter.
  void expire(std::uint64_t now_tick) {
    for (auto& [id, slot] : slots_) {
      (void)id;
      if (slot.state == State::dead) continue;
      if (slot.state == State::draining) {
        if (now_tick >= slot.last_heartbeat_tick + kDrainTicks) { slot.state = State::dead; free_seats(slot); }
      } else if (now_tick >= slot.last_heartbeat_tick + kHeartbeatTtlTicks) {
        slot.state = State::dead;
        free_seats(slot);
      }
    }
  }

  // The atomic admission: one step checks slot liveness, per-slot room
  // and — platform sources only — the global CCU cap, and only then
  // increments. Donated/BYO admissions skip the platform-CCU term (their
  // capacity is on top of the platform's) but never the per-slot cap.
  // Every refusal leaves every counter untouched.
  enum class Admit : std::uint8_t { admitted, slot_unknown, not_alive, slot_full, platform_ccu_full };
  [[nodiscard]] Admit admit(const std::string& slot_id, std::uint64_t now_tick) {
    expire(now_tick);
    auto it = slots_.find(slot_id);
    if (it == slots_.end()) return Admit::slot_unknown;
    auto& slot = it->second;
    if (slot.state == State::full) return Admit::slot_full;
    if (slot.state != State::ready) return Admit::not_alive;
    if (slot.players >= kMaxPlayersPerSlot) return Admit::slot_full;
    if (slot.source == Source::platform && platform_ccu_ >= kPlatformCcuCap) return Admit::platform_ccu_full;
    ++slot.players;
    if (slot.source == Source::platform) ++platform_ccu_;
    if (slot.players >= kMaxPlayersPerSlot) slot.state = State::full;
    return Admit::admitted;
  }

  // A player leaves: counters go down, Full recovers to Ready.
  [[nodiscard]] bool release(const std::string& slot_id) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end() || it->second.players == 0) return false;
    --it->second.players;
    if (it->second.source == Source::platform) --platform_ccu_;
    if (it->second.state == State::full && it->second.players < kMaxPlayersPerSlot) it->second.state = State::ready;
    return true;
  }

  // Wake transitions (the allocator's "trigger wake on the nearest Cold
  // slot"): Cold -> Waking -> Ready. The 30 s wake timeout and the
  // two-strikes Dead rule belong to the wake orchestrator (BAK-12's lock);
  // the registry exposes the honest Waking state and the moves.
  [[nodiscard]] bool begin_wake(const std::string& slot_id, std::uint64_t now_tick) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end() || it->second.state != State::cold) return false;
    it->second.state = State::waking;
    it->second.last_heartbeat_tick = now_tick;
    return true;
  }
  [[nodiscard]] bool wake_ready(const std::string& slot_id, std::uint64_t now_tick) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end() || it->second.state != State::waking) return false;
    it->second.state = State::ready;
    it->second.last_heartbeat_tick = now_tick;
    return true;
  }

  // A started Space shuts down (host process exits) from Ready or Full:
  // its seats free and the slot returns to Cold, so the next players
  // trigger a fresh wake.
  [[nodiscard]] bool shut_down(const std::string& slot_id) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end() || (it->second.state != State::ready && it->second.state != State::full)) return false;
    free_seats(it->second);
    it->second.state = State::cold;
    return true;
  }

  // A wake attempt failed but the slot is not Dead yet: back to Cold so
  // the next trigger can take it again.
  [[nodiscard]] bool wake_reset(const std::string& slot_id) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end() || it->second.state != State::waking) return false;
    it->second.state = State::cold;
    return true;
  }

  // "If wake fails twice, the slot goes Dead" — the wake orchestrator's
  // two-strikes move, freeing any seats (a Waking slot holds none).
  [[nodiscard]] bool wake_dead(const std::string& slot_id) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end() || it->second.state != State::waking) return false;
    it->second.state = State::dead;
    free_seats(it->second);
    return true;
  }

  // Start draining; a draining slot expires to Dead after the window.
  [[nodiscard]] bool begin_drain(const std::string& slot_id, std::uint64_t now_tick) {
    auto it = slots_.find(slot_id);
    if (it == slots_.end()) return false;
    it->second.state = State::draining;
    it->second.last_heartbeat_tick = now_tick;
    return true;
  }

  [[nodiscard]] std::uint32_t platform_ccu(std::uint64_t now_tick) { expire(now_tick); return platform_ccu_; }

  [[nodiscard]] const Slot* find(const std::string& slot_id) const {
    auto it = slots_.find(slot_id);
    return it == slots_.end() ? nullptr : &it->second;
  }

  // Allocation-candidate view: Ready slots only (Full, Dead, Draining and
  // Waking are the allocator's filtered states), after expiry.
  [[nodiscard]] std::vector<const Slot*> ready_slots(std::uint64_t now_tick) {
    expire(now_tick);
    std::vector<const Slot*> out;
    for (auto& [id, slot] : slots_) {
      (void)id;
      if (slot.state == State::ready) out.push_back(&slot);
    }
    return out;
  }

private:
  // Free a slot's seats exactly once: platform seats return to the global
  // counter (non-platform seats never entered it). Every path that empties
  // a slot goes through here so the counter cannot leak or underflow.
  void free_seats(Slot& slot) {
    if (slot.source == Source::platform) platform_ccu_ -= std::min(platform_ccu_, slot.players);
    slot.players = 0;
  }

  std::map<std::string, Slot> slots_;
  std::uint32_t platform_ccu_ = 0; // the atomic global counter (D1 truth)
};

} // namespace poko::matchmaker
