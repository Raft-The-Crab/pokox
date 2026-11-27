// BAK-12 acceptance: "Two triggers produce one wake". The 30 s Valkey
// lock admits any number of triggers inside its window and boots exactly
// one Space; /health writes Ready and releases the lock; every wake logs
// duration and outcome; two timed-out attempts in a row kill the slot
// (offered donated/BYO or a queued retry); a success clears the count;
// a Waking slot refuses admission until Ready or Dead.
#include "poko/matchmaker/wake_lock.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;
} // namespace

int main() {
  SlotRegistry reg;
  SlotRegistry::Slot cold;
  cold.slot_id = "c1";
  cold.game_id = "g1";
  cold.state = SlotRegistry::State::cold;
  check(reg.register_slot(cold, 0) == SlotRegistry::Register::registered, "Cold slot registered as Cold");

  WakeLock wl(reg);

  // The headline: two triggers produce one wake.
  const auto first = wl.trigger("c1", 0);
  const auto second = wl.trigger("c1", 1);
  check(first.has_value(), "first trigger takes the lock and returns a boot token");
  check(!second.has_value(), "second trigger inside the lock window starts no second wake");
  check(!wl.trigger("c1", 15).has_value(), "a third trigger also starts nothing");
  check(wl.locked("c1", 15), "lock is held inside its 30 s window");
  check(reg.find("c1")->state == SlotRegistry::State::waking, "slot sits in the honest Waking state");
  check(reg.admit("c1", 15) == SlotRegistry::Admit::not_alive, "Waking refuses admission");

  // /health: write Ready and release the lock; the slot admits.
  check(wl.health("c1", 20), "health write succeeds while locked");
  check(!wl.locked("c1", 20), "lock released on health");
  check(reg.find("c1")->state == SlotRegistry::State::ready, "health wrote Ready");
  check(reg.admit("c1", 20) == SlotRegistry::Admit::admitted, "Ready slot admits after cold start");
  check(!wl.health("c1", 21), "a health with no wake in flight is refused");

  // Log: one ready wake with duration 20.
  check(wl.log().size() == 1 && wl.log()[0].outcome == WakeLock::Outcome::ready &&
            wl.log()[0].started_tick == 0 && wl.log()[0].ended_tick == 20,
        "wake logged with duration and outcome");

  // Lock TTL: past 30 s without health the lock is gone and the attempt
  // counts; a fresh trigger after expiry can start a new wake.
  SlotRegistry reg2;
  SlotRegistry::Slot c2;
  c2.slot_id = "c2";
  c2.state = SlotRegistry::State::cold;
  reg2.register_slot(c2, 0);
  WakeLock wl2(reg2);
  check(wl2.trigger("c2", 0).has_value(), "first wake started");
  check(!wl2.locked("c2", 30), "lock expired at its 30 s TTL");
  check(wl2.log().size() == 1 && wl2.log()[0].outcome == WakeLock::Outcome::timeout, "timeout logged");
  check(wl2.trigger("c2", 30).has_value(), "a fresh trigger after expiry starts a new wake");

  // Two strikes: the second consecutive timeout flips the slot Dead; the
  // caller is told so it can offer donated/BYO or a queued retry.
  check(!wl2.trigger("c2", 31).has_value(), "no double-trigger while second wake is in flight");
  wl2.expire_locks(61); // second wake times out at 30+30+1
  check(reg2.find("c2")->state == SlotRegistry::State::dead, "two failed wakes go Dead");
  check(!reg2.wake_dead("c2"), "Dead is terminal for the wake path");
  check(wl2.log().size() == 2 && wl2.log()[1].outcome == WakeLock::Outcome::failed_twice,
        "second failure logged as failed_twice");
  check(wl2.dead_via_wake().size() == 1 && wl2.dead_via_wake()[0] == "c2",
        "slot reported dead-via-wake for the donated/BYO-or-queue answer");

  // A success clears the streak: timeout, success, timeout is not Dead.
  SlotRegistry reg3;
  SlotRegistry::Slot c3;
  c3.slot_id = "c3";
  c3.state = SlotRegistry::State::cold;
  reg3.register_slot(c3, 0);
  WakeLock wl3(reg3);
  check(wl3.trigger("c3", 0).has_value(), "streak wake 1 started");
  wl3.expire_locks(30); // attempt 1 times out
  check(wl3.trigger("c3", 30).has_value(), "retry after first timeout starts");
  check(wl3.health("c3", 40), "retry succeeds");
  check(reg3.shut_down("c3"), "the space later shuts down and the slot returns to Cold");
  check(wl3.trigger("c3", 41).has_value(), "another wake starts");
  wl3.expire_locks(71); // would be a second consecutive timeout if the streak counted the old one
  check(reg3.find("c3")->state != SlotRegistry::State::dead, "success cleared the two-strikes count");
  check(wl3.log().size() == 3, "all three wakes logged");

  if (errors == 0) std::cout << "OK: all wake lock checks passed\n";
  else std::cout << errors << " check(s) FAILED\n";
  return errors == 0 ? 0 : 1;
}
