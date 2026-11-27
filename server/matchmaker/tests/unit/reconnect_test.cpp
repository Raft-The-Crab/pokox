// BAK-14 acceptance: "Same tick within 30 s". A reconnect inside the
// 30 s window on a live slot resumes the game plane at exactly the last
// accepted tick and issues a fresh ticket; past the window, with a reused
// nonce, against a dead slot, or for an ended/unknown session it refuses
// generically (dead slot -> rejoin the queue). Nonces are single-use.
#include "poko/matchmaker/reconnect.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;
using RF = ReconnectFlow;
} // namespace

int main() {
  SlotRegistry reg;
  TicketSigner signer("unit-test-secret");
  ReconnectFlow rf(reg, signer);

  // Live slot + registered session.
  SlotRegistry::Slot s;
  s.slot_id = "7";
  reg.register_slot(s, 0);
  RF::Session sess;
  sess.session_id = 1000;
  sess.slot_id = 7;
  sess.game_id = "g1";
  sess.version = 3;
  sess.last_accepted_tick = 5000;
  rf.register_session(sess);

  // The headline: reconnect inside the window resumes at the same tick
  // and issues a fresh, verifiable ticket.
  const auto ok = rf.reconnect(1000, 0xDEADBEEF, 5020);
  check(ok.kind == RF::Result::Kind::reconnected, "reconnect inside the window succeeds");
  check(ok.resume_tick == 5000, "resume tick is exactly the last accepted tick (same tick)");
  check(ok.ticket.session_id == 1000 && ok.ticket.slot_id == 7 && ok.ticket.version == 3,
        "fresh ticket carries the session identity");
  check(TicketSigner::check(ok.ticket, signer, 5020) == TicketSigner::Check::ok, "new ticket verifies");

  // Nonces are single-use: the same nonce again is refused, even inside
  // the window, and returns no ticket.
  const auto replay = rf.reconnect(1000, 0xDEADBEEF, 5021);
  check(replay.kind == RF::Result::Kind::nonce_reused && replay.resume_tick == 0,
        "reused nonce refused, no resume point");

  // A new nonce after the plane advanced resumes at the new tick.
  rf.advance(1000, 5030);
  const auto later = rf.reconnect(1000, 2, 5040);
  check(later.kind == RF::Result::Kind::reconnected && later.resume_tick == 5030,
        "resume follows the last accepted tick");

  // Window: past 30 s of server time since the last accepted tick.
  rf.advance(1000, 5030);
  const auto late = rf.reconnect(1000, 3, 5061);
  check(late.kind == RF::Result::Kind::window_closed, "past 30 s the window is closed");
  check(rf.reconnect(1000, 3, 5061).kind == RF::Result::Kind::nonce_reused,
        "a window-closed attempt still burned the nonce");

  // Dead slot: rejoin the queue (no ticket, no migration).
  SlotRegistry::Slot dead;
  dead.slot_id = "8";
  reg.register_slot(dead, 0);
  reg.begin_drain("8", 0);
  RF::Session dying;
  dying.session_id = 2000;
  dying.slot_id = 8;
  dying.last_accepted_tick = 100;
  rf.register_session(dying);
  const auto gone = rf.reconnect(2000, 9, 105);
  check(gone.kind == RF::Result::Kind::slot_gone, "dead/draining slot refuses with slot_gone");

  // Ended session and unknown session: generic refusals.
  rf.end_session(1000);
  check(rf.reconnect(1000, 4, 5045).kind == RF::Result::Kind::inactive, "ended session refuses");
  check(rf.reconnect(9999, 5, 5045).kind == RF::Result::Kind::unknown_session, "unknown session refuses");

  // The gate never migrated state cross-slot: the refused reconnects
  // left no ticket material behind.
  check(late.ticket.session_id == 0 && gone.ticket.session_id == 0, "refusals carry no ticket");

  if (errors == 0) std::cout << "OK: all reconnection checks passed\n";
  else std::cout << errors << " check(s) FAILED\n";
  return errors == 0 ? 0 : 1;
}
