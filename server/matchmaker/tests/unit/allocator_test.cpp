// BAK-09 acceptance: "Ticket issued". A valid allocation path ends in a
// signed 30-second ticket; the pipeline ranks by the spec's score, filters
// dead/draining/full/version-mismatched slots, prefers Ready platform
// slots under the 20-CCU cap, falls back to opted-in donated/BYO, then a
// Cold-slot wake, then queues — and tickets fail closed on expiry or MAC
// tamper, with no player identity on the wire.
#include "poko/matchmaker/allocator.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;

Slot ready_platform(std::uint32_t id, std::uint32_t players, double rtt) {
  Slot s;
  s.id = id; s.state = Slot::State::ready; s.source = Slot::Source::platform;
  s.player_count = players; s.version = 7; s.rtt_ms = rtt;
  return s;
}
} // namespace

int main() {
  const std::string secret = "matchmaker-ticket-secret";

  // Ranking: the lower-score slot wins (rtt dominates with weight 1, both Ready).
  Matchmaker mm(1.0, 1.0, 0);
  const auto d1 = mm.allocate({ready_platform(1, 0, 80), ready_platform(2, 0, 30)}, 7, {});
  check(d1.outcome == Matchmaker::Decision::Outcome::allocated_platform && d1.slot_id == 2,
        "best-scoring Ready platform slot wins");
  check(d1.score == 30.0, "score is latencyWeight*rtt + loadPenalty*players");

  // Load penalty: a fuller but lower-latency slot can lose.
  const auto d2 = mm.allocate({ready_platform(3, 0, 10), ready_platform(4, 15, 10)}, 7, {});
  check(d2.slot_id == 3, "load penalty steers away from the fuller slot");

  // Affinity: a party's preferred slot gets a -10 bonus.
  const auto d3 = mm.allocate({ready_platform(5, 0, 50), ready_platform(6, 0, 45)}, 7, {5});
  check(d3.slot_id == 5, "affinity bonus pulls the party's slot ahead");

  // Filtering: dead, draining, full and version-mismatched are skipped.
  Slot dead = ready_platform(7, 0, 1); dead.state = Slot::State::dead;
  Slot draining = ready_platform(8, 0, 1); draining.state = Slot::State::draining;
  Slot full = ready_platform(9, 20, 1);
  Slot wrong_version = ready_platform(10, 0, 1); wrong_version.version = 8;
  const auto d4 = mm.allocate({dead, draining, full, wrong_version}, 7, {});
  check(d4.outcome == Matchmaker::Decision::Outcome::queued && d4.slot_id == 0,
        "all filtered slots leave the request queued");

  // Platform cap: at 20 CCU a platform slot is not picked even when Ready.
  Slot platform = ready_platform(11, 5, 10);
  Matchmaker mm_full(1.0, 1.0, 20);
  Slot donated = platform; donated.id = 12; donated.source = Slot::Source::donated;
  const auto d5 = mm_full.allocate({platform, donated}, 7, {});
  check(d5.outcome == Matchmaker::Decision::Outcome::allocated_donated && d5.slot_id == 12,
        "at platform cap the opted-in donated slot is picked instead");
  // Donated opt-out falls through to queue.
  donated.opted_in = false;
  const auto d6 = mm_full.allocate({platform, donated}, 7, {});
  check(d6.outcome == Matchmaker::Decision::Outcome::queued, "opted-out donated slot is skipped");
  // Under the cap, platform wins.
  Matchmaker mm_room(1.0, 1.0, 19);
  const auto d7 = mm_room.allocate({platform, donated}, 7, {});
  check(d7.outcome == Matchmaker::Decision::Outcome::allocated_platform && d7.slot_id == 11,
        "below the cap the platform slot is picked");

  // Wake: no Ready anywhere, a Cold slot triggers a wake decision.
  Slot cold = ready_platform(13, 0, 10); cold.state = Slot::State::cold;
  const auto d8 = mm_room.allocate({cold}, 7, {});
  check(d8.outcome == Matchmaker::Decision::Outcome::waking && d8.slot_id == 13,
        "Cold slot triggers wake when nothing is Ready");

  // Ticket issued: MAC verifies, expiry 30 s, deterministic nonce.
  TicketSigner signer(secret);
  const auto t1 = signer.issue(42, 2, 7, 1000);
  check(t1.expires_tick - t1.issued_tick == TicketSigner::kValidityTicks, "ticket valid 30 seconds");
  check(TicketSigner::check(t1, signer, 1000) == TicketSigner::Check::ok &&
        TicketSigner::check(t1, signer, 1029) == TicketSigner::Check::ok,
        "ticket checks through second 29");
  check(TicketSigner::check(t1, signer, 1030) == TicketSigner::Check::expired, "ticket expired at second 30");
  auto stretched = t1;
  stretched.expires_tick = ~0ULL; // client rewrites the unsigned expiry field
  check(TicketSigner::check(stretched, signer, 1030) == TicketSigner::Check::expired,
        "rewritten expires_tick cannot extend a ticket (expiry derives from MAC-covered issued_tick)");
  const auto t2 = signer.issue(42, 2, 7, 1000);
  check(t2.nonce == t1.nonce && t2.mac == t1.mac, "ticket issuance is deterministic");
  check(signer.issue(42, 2, 7, 1001).nonce != t1.nonce, "nonce changes with the tick");

  // Tamper: a flipped session id (or MAC bit) fails closed as bad_mac.
  auto forged = t1;
  forged.session_id = 43;
  check(TicketSigner::check(forged, signer, 1000) == TicketSigner::Check::bad_mac, "forged body refused");
  auto flipped = t1;
  flipped.mac[0] ^= 1;
  check(TicketSigner::check(flipped, signer, 1000) == TicketSigner::Check::bad_mac, "flipped MAC refused");
  // Wrong secret fails closed too.
  TicketSigner other("other-secret");
  check(TicketSigner::check(t1, other, 1000) == TicketSigner::Check::bad_mac, "wrong-signer MAC refused");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "matchmaker tests passed\n";
  return 0;
}
