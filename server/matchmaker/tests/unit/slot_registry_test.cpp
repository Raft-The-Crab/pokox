// BAK-11 acceptance: "CCU never exceeds 20". Platform CCU is a hard cap
// enforced inside the single admission step; the per-game platform-slot
// cap is 3; per-slot player cap is 20 matching the heartbeat; a missing
// heartbeat flips the slot to Dead within the 60 s TTL; Full recovers to
// Ready when players leave; donated/BYO admissions bypass the platform
// CCU term but never the per-slot cap; heartbeat reports above the cap
// are clamped (the registry count, not the report, is the truth).
#include "poko/matchmaker/slot_registry.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;
using Reg = SlotRegistry;

Reg::Slot mk(const std::string& id, Reg::Source src = Reg::Source::platform, const std::string& game = "g1") {
  Reg::Slot s;
  s.slot_id = id;
  s.game_id = game;
  s.source = src;
  return s;
}
} // namespace

int main() {
  // The headline: 3 platform slots x 20 players = 60 theoretical seats,
  // but the global platform CCU cap of 20 binds first. Admit 25 times
  // across slots; exactly 20 succeed and the 21st is refused.
  Reg reg;
  check(reg.register_slot(mk("s1"), 0) == Reg::Register::registered, "slot 1 registered");
  check(reg.register_slot(mk("s2"), 0) == Reg::Register::registered, "slot 2 registered");
  check(reg.register_slot(mk("s3"), 0) == Reg::Register::registered, "slot 3 registered");
  std::uint32_t admitted = 0;
  for (int i = 0; i < 25; ++i) {
    const char* slot = (i % 3 == 0) ? "s1" : (i % 3 == 1) ? "s2" : "s3";
    if (reg.admit(slot, 0) == Reg::Admit::admitted) ++admitted;
  }
  check(admitted == Reg::kPlatformCcuCap, "admissions stop exactly at the 20 CCU cap");
  check(reg.platform_ccu(0) == 20, "global counter reads exactly 20, never above");
  check(reg.admit("s1", 0) == Reg::Admit::platform_ccu_full, "next admission refused on global cap");

  // Donated capacity bypasses the platform-CCU term but not the per-slot
  // cap: a donated slot fills to 20 while the platform stays saturated.
  check(reg.register_slot(mk("d1", Reg::Source::donated), 0) == Reg::Register::registered, "donated slot registered");
  for (int i = 0; i < 25; ++i) reg.admit("d1", 0);
  auto* d1 = reg.find("d1");
  check(d1->players == Reg::kMaxPlayersPerSlot && d1->state == Reg::State::full,
        "donated slot fills to its own cap and goes Full");
  check(reg.platform_ccu(0) == 20, "donated fill left the platform counter untouched");
  check(reg.admit("d1", 0) == Reg::Admit::slot_full, "donated slot refuses past 20 players");

  // Per-game platform-slot cap: the 4th platform slot for a game is
  // refused; another game gets its own 3.
  check(reg.register_slot(mk("s4", Reg::Source::platform, "g1"), 0) == Reg::Register::platform_slot_cap,
        "4th platform slot for g1 refused");
  check(reg.register_slot(mk("o1", Reg::Source::platform, "g2"), 0) == Reg::Register::registered,
        "other game's first platform slot accepted");

  // Duplicate registration refused.
  check(reg.register_slot(mk("s1"), 0) == Reg::Register::duplicate, "duplicate slot refused");

  // Missing heartbeat: 60 s TTL flips the slot to Dead and releases its
  // seats from the global counter.
  Reg reg2;
  check(reg2.register_slot(mk("t1"), 0) == Reg::Register::registered, "ttl slot registered");
  for (int i = 0; i < 5; ++i) reg2.admit("t1", 0);
  check(reg2.platform_ccu(0) == 5, "counter reflects 5 admissions");
  check(reg2.platform_ccu(59) == 5, "alive at tick 59");
  check(reg2.platform_ccu(60) == 0, "missing heartbeat at 60 s flips to Dead and frees seats");
  check(reg2.find("t1")->state == Reg::State::dead, "state is Dead");
  check(reg2.admit("t1", 60) == Reg::Admit::not_alive, "dead slot refuses admission");
  check(reg2.ready_slots(60).empty(), "dead slot is not an allocation candidate");

  // Heartbeat refresh keeps it alive; recovery from Full happens on a
  // departure (release), never from a client report — reports cannot set
  // the count (the registry's admission count is the truth).
  Reg reg3;
  check(reg3.register_slot(mk("h1"), 0) == Reg::Register::registered, "hb slot registered");
  for (int i = 0; i < 20; ++i) reg3.admit("h1", 0);
  check(reg3.find("h1")->state == Reg::State::full, "20 admissions make the slot Full");
  for (std::uint64_t t = 0; t < 120; t += 30) reg3.heartbeat("h1", 20, t);
  check(reg3.find("h1")->state != Reg::State::dead, "beats every 30 s keep it alive past 60 s");
  check(reg3.heartbeat("h1", 99, 120), "heartbeat accepted");
  check(reg3.find("h1")->players == 20, "a forged higher report left the registry count untouched");
  check(reg3.heartbeat("h1", 0, 121) && reg3.find("h1")->players == 20,
        "a forged lower report cannot free seats either");
  check(reg3.release("h1") && reg3.find("h1")->state == Reg::State::ready,
        "a real departure recovers Full to Ready");
  check(reg3.heartbeat("h1", 99, 122) && reg3.find("h1")->players == 19,
        "reports never set the count or the state");

  // Wake path: Cold -> Waking -> Ready; a Waking slot refuses admission
  // (the honest "wait till HF #2 is available" state).
  Reg reg4;
  check(reg4.register_slot(mk("w1"), 0) == Reg::Register::registered, "cold-slot registration lands Ready");
  Reg reg5;
  Reg::Slot cold = mk("c1");
  cold.state = Reg::State::cold;
  check(reg5.register_slot(cold, 0) == Reg::Register::registered, "explicit Cold registered as Cold");
  check(reg5.admit("c1", 0) == Reg::Admit::not_alive, "Cold refuses admission");
  check(reg5.begin_wake("c1", 0) && reg5.admit("c1", 0) == Reg::Admit::not_alive, "Waking refuses admission");
  check(reg5.wake_ready("c1", 10) && reg5.admit("c1", 10) == Reg::Admit::admitted, "Ready admits");

  // Drain: a draining slot refuses new admissions and expires to Dead
  // after the 5-minute window.
  check(reg5.begin_drain("c1", 20) && reg5.admit("c1", 25) == Reg::Admit::not_alive, "Draining refuses admission");
  reg5.expire(20 + Reg::kDrainTicks - 1);
  check(reg5.find("c1")->state == Reg::State::draining, "still draining inside the window");
  reg5.expire(20 + Reg::kDrainTicks);
  check(reg5.find("c1")->state == Reg::State::dead, "draining expires to Dead at 5 min");

  // Audit regression: a platform slot that drains to Dead must return its
  // seats to the global counter (it used to zero players without
  // decrementing, leaking CCU permanently).
  Reg reg6;
  check(reg6.register_slot(mk("d1"), 0) == Reg::Register::registered, "drain slot registered");
  for (int i = 0; i < 7; ++i) reg6.admit("d1", 0);
  check(reg6.platform_ccu(0) == 7, "7 platform seats counted");
  check(reg6.begin_drain("d1", 10), "drain started");
  check(reg6.platform_ccu(10 + Reg::kDrainTicks) == 0, "drained-to-Dead slot returned its seats");

  // Audit regression: a Full slot can shut down (previously only Ready
  // could), freeing all 20 seats.
  Reg reg7;
  check(reg7.register_slot(mk("f1"), 0) == Reg::Register::registered, "full slot registered");
  for (int i = 0; i < 20; ++i) reg7.admit("f1", 0);
  check(reg7.find("f1")->state == Reg::State::full && reg7.shut_down("f1"), "Full slot shuts down");
  check(reg7.platform_ccu(1) == 0 && reg7.find("f1")->state == Reg::State::cold, "shutdown freed all seats, Cold");

  if (errors == 0) std::cout << "OK: all slot registry checks passed\n";
  else std::cout << errors << " check(s) FAILED\n";
  return errors == 0 ? 0 : 1;
}
