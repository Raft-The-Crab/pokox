// BAK-12: wake lock and cold start (spec 07 "Cold start integration";
// queue row BAK-12 acceptance "Two triggers produce one wake").
//
// Spec 07: "A Valkey wake lock (wakeLock:slotId, 30 s TTL) ensures one
// trigger boots a Space. On GET /health, the Space writes Ready and
// releases the lock. Every wake logs duration and outcome in D1." Slot
// states: "If wake fails twice, the slot goes Dead and the player is
// offered donated/BYO servers or a queued retry." Wake timeout is 30 s.
//
// This module is the in-process mirror of the Valkey lock — the same
// arrangement as BAK-02's in-memory authority, BAK-10's queue and BAK-11's
// registry: the Worker swaps the backing store for real Valkey (SET NX EX
// semantics), and the unit tests prove the lock semantics
// deterministically. The acceptance property comes from the lock itself:
// while the lock is held there is no code path from a second trigger to a
// second boot — trigger returns nothing unless this call took the lock.
#pragma once

#include "poko/matchmaker/slot_registry.hpp"

#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace poko::matchmaker {

class WakeLock {
public:
  static constexpr std::uint64_t kLockTtlTicks = 30;     // wakeLock:slotId, 30 s TTL
  static constexpr std::uint64_t kWakeTimeoutTicks = 30; // wake timeout (same window)
  static constexpr std::uint64_t kMedianWatchTicks = 20; // "if median wake exceeds 20 s over a week" — logged only

  enum class Outcome : std::uint8_t { ready, timeout, failed_twice };

  struct WakeLog {
    std::string slot_id;
    std::uint64_t started_tick = 0;
    std::uint64_t ended_tick = 0;
    Outcome outcome = Outcome::timeout;
  };

  explicit WakeLock(SlotRegistry& registry) : registry_(registry) {}

  // Trigger a wake on a Cold slot (allocator step 4: "trigger wake on the
  // nearest Cold slot"). Returns a boot token only if this call took the
  // lock and started the wake; any trigger while the lock is held —
  // regardless of how many arrive inside the 30 s window — gets nullopt
  // and one Space boots.
  [[nodiscard]] std::optional<std::string> trigger(const std::string& slot_id, std::uint64_t now_tick) {
    expire_locks(now_tick);
    if (!registry_.begin_wake(slot_id, now_tick)) return std::nullopt; // Waking already, or not Cold
    locks_[slot_id] = now_tick + kLockTtlTicks;
    return "wake:" + slot_id + ":" + std::to_string(now_tick);
  }

  // The Space came up (GET /health): write Ready and release the lock.
  // Returns false when no wake is in flight for the slot.
  [[nodiscard]] bool health(const std::string& slot_id, std::uint64_t now_tick) {
    auto it = locks_.find(slot_id);
    if (it == locks_.end()) return false;
    const auto started = it->second - kLockTtlTicks;
    if (!registry_.wake_ready(slot_id, now_tick)) return false;
    log_.push_back({slot_id, started, now_tick, Outcome::ready});
    attempts_[slot_id] = 0; // a success clears the two-strikes count
    locks_.erase(it);
    return true;
  }

  // Timeout sweep at server time: a lock past its 30 s window with no
  // health is a failed attempt. "If wake fails twice, the slot goes Dead"
  // and the caller offers donated/BYO servers or a queued retry.
  void expire_locks(std::uint64_t now_tick) {
    for (auto it = locks_.begin(); it != locks_.end();) {
      if (now_tick < it->second) { ++it; continue; }
      const auto& slot_id = it->first;
      auto& attempts = attempts_[slot_id];
      ++attempts;
      log_.push_back({slot_id, it->second - kLockTtlTicks, now_tick,
                      attempts >= 2 ? Outcome::failed_twice : Outcome::timeout});
      if (attempts >= 2) {
        static_cast<void>(registry_.wake_dead(slot_id));
        dead_via_wake_.push_back(slot_id);
        attempts = 0;
      } else {
        static_cast<void>(registry_.wake_reset(slot_id)); // not Dead yet: rewakeable
      }
      it = locks_.erase(it);
    }
  }

  // Slots the two-strikes rule killed; the caller answers with
  // donated/BYO servers or a queued retry for these.
  [[nodiscard]] const std::vector<std::string>& dead_via_wake() const { return dead_via_wake_; }

  [[nodiscard]] bool locked(const std::string& slot_id, std::uint64_t now_tick) {
    expire_locks(now_tick);
    return locks_.count(slot_id) != 0;
  }

  // The D1 wake log: duration and outcome for every wake.
  [[nodiscard]] const std::vector<WakeLog>& log() const { return log_; }

private:
  SlotRegistry& registry_;
  std::map<std::string, std::uint64_t> locks_;    // slot -> lock deadline tick
  std::map<std::string, std::uint32_t> attempts_; // consecutive timed-out attempts
  std::vector<std::string> dead_via_wake_;
  std::vector<WakeLog> log_;
};

} // namespace poko::matchmaker
