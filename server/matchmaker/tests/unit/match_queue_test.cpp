// BAK-10 acceptance: "FIFO under load". The queue admits in enqueue order
// under load, is idempotent per requestId, carries server-assigned
// timestamps, applies party-size boosts without breaking FIFO for equal
// scores, expires at 5 minutes, refuses at the 500/realm depth, pulls
// whole parties only (never splits one), and reports position and ETA
// from the slot drain rate.
#include "poko/matchmaker/match_queue.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::matchmaker;

MatchQueue::Entry req(const std::string& id, std::uint32_t party = 1, std::uint32_t session = 0) {
  MatchQueue::Entry e;
  e.request_id = id;
  e.party_size = party;
  e.session_id = session;
  return e;
}
} // namespace

int main() {
  MatchQueue q;

  // FIFO under load: 100 single requests enqueued at the same tick come
  // out in exactly enqueue order.
  for (int i = 0; i < 100; ++i) {
    auto e = req("r" + std::to_string(i));
    check(q.enqueue("realm", e) == MatchQueue::Enqueue::enqueued, "load enqueue accepted");
  }
  const auto pulled = q.pull("realm", 100, 0);
  check(pulled.size() == 100, "capacity wake pulls a full load");
  for (std::size_t i = 0; i < pulled.size(); ++i) {
    check(pulled[i].request_id == "r" + std::to_string(i), "FIFO order preserved under load");
  }
  check(q.depth("realm", 0) == 0, "pulled entries leave the queue");

  // Idempotency: the same requestId never double-queues.
  check(q.enqueue("realm", req("dup")) == MatchQueue::Enqueue::enqueued, "first enqueue accepted");
  check(q.enqueue("realm", req("dup")) == MatchQueue::Enqueue::duplicate, "retry is a duplicate");
  check(q.depth("realm", 0) == 1, "duplicate did not enqueue twice");

  // Party-size boost: a party of 4 that enqueued 12 ticks after a single
  // still jumps ahead of it (12 - 3*5 = -3 < 0-equivalent score).
  MatchQueue q2;
  check(q2.enqueue("r", req("early_single")) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  auto party = req("party4", 4);
  party.enqueue_tick = 12;
  check(q2.enqueue("r", party) == MatchQueue::Enqueue::enqueued, "party enqueued");
  const auto order = q2.pull("r", 10, 0);
  check(order.size() == 2 && order[0].request_id == "party4" && order[1].request_id == "early_single",
        "party-size boost moves the party ahead of an earlier single");

  // Whole-party admission: a party of 6 never splits to fit capacity 4,
  // and a later pair behind it can still be pulled.
  MatchQueue q3;
  auto big = req("party6", 6);
  check(q3.enqueue("r", big) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  check(q3.enqueue("r", req("pair", 2)) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  const auto partial = q3.pull("r", 4, 0);
  check(partial.size() == 1 && partial[0].request_id == "pair",
        "oversized party skipped whole, later party admitted");
  const auto rest = q3.pull("r", 20, 0);
  check(rest.size() == 1 && rest[0].request_id == "party6", "party survives to the next pull");

  // Expiry: an entry older than 300 ticks of server time is gone.
  MatchQueue q4;
  auto stale = req("stale");
  stale.enqueue_tick = 0;
  auto fresh = req("fresh");
  fresh.enqueue_tick = 100;
  check(q4.enqueue("r", stale) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  check(q4.enqueue("r", fresh) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  check(q4.expire("r", 299) == 0, "nothing expires before 300 ticks");
  check(q4.expire("r", 300) == 1, "entry expires at exactly 300 ticks");
  check(q4.position("r", "fresh", 300) == 1 && q4.position("r", "stale", 300) == 0,
        "expired entry has no position");

  // Depth cap: the 501st request in a realm is refused, generically.
  MatchQueue q5;
  for (std::size_t i = 0; i < MatchQueue::kMaxDepthPerRealm; ++i) {
    auto e = req("q" + std::to_string(i));
    if (q5.enqueue("r", e) != MatchQueue::Enqueue::enqueued) { check(false, "depth fill accepted"); break; }
  }
  check(q5.enqueue("r", req("over")) == MatchQueue::Enqueue::full, "501st request refused at depth cap");
  check(q5.depth("r", 0) == MatchQueue::kMaxDepthPerRealm, "depth stays at the cap");

  // Position and ETA from the drain rate: position 3, party of 2, drain
  // 0.5 seats/tick -> (3-1)+2 = 4 seats -> 8 ticks. Integer-only ceil.
  check(MatchQueue::eta_ticks(3, 2, 0.5) == 8, "ETA is seats ahead over drain rate, ceil");
  check(MatchQueue::eta_ticks(1, 1, 0.5) == 2, "front-of-queue single waits its own admission");
  check(MatchQueue::eta_ticks(0, 1, 0.5) == 0, "absent request has no ETA");
  MatchQueue q6;
  check(q6.enqueue("r", req("a")) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  check(q6.enqueue("r", req("b")) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  check(q6.enqueue("r", req("me")) == MatchQueue::Enqueue::enqueued, "enqueue accepted");
  check(q6.position("r", "me", 0) == 3, "position counts ahead of the request");

  // Leave: /match/leave removes the entry; a second leave is false.
  check(q6.remove("r", "b") && !q6.remove("r", "b"), "leave removes once");
  check(q6.position("r", "me", 0) == 2, "a departure pulls everyone behind forward");

  if (errors == 0) std::cout << "OK: all match queue checks passed\n";
  else std::cout << errors << " check(s) FAILED\n";
  return errors == 0 ? 0 : 1;
}
