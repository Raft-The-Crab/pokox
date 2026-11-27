// BAK-07 acceptance: "Mismatch rejected generically". A client's projected
// hash and frame sequence number are checked against the authority; any
// rejection is generic (no field, no reason a probing client can compare),
// sequence violations and hash mismatches weight the spec-05 penalty model,
// and the thresholds force a resync at 10 and suspend at 25.
#include "poko/authority/pkb_schema.hpp"
#include "poko/authority/projection_gate.hpp"

#include <cstdint>
#include <iostream>
#include <string>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::authority;

// Generic means generic: the rejection must not encode which check failed
// beyond the four-verdict bucket, and suspicion weights follow spec 05.
bool same_generic(const ProjectionGate::Outcome& a, const ProjectionGate::Outcome& b) {
  return a.verdict == b.verdict && a.why == b.why;
}
} // namespace

int main() {
  const std::string pkb_text =
      "game poko-bakery\n"
      "seed 777\n"
      "field player.position.x int Validated bits=12 initial=100\n"
      "field player.score int Validated bits=20 initial=0\n";
  PkbSchema schema;
  check(load_pkb_schema(pkb_text, schema).code == PkbLoadError::Code::none, "schema loads");

  PkbAuthority pa(schema, 0x1234);
  const std::uint32_t client = pa.authority().add_client();
  ProjectionGate gate(pa);

  // Tick 2 commits so a real projected hash exists to agree on.
  pa.authority().tick();
  const std::uint64_t good = pa.authority().snapshot_for(client).projected_hash;

  // In-window, matching hash: accepted; the window's lastAccepted advances.
  auto o1 = gate.receive(client, 1, good);
  check(o1.verdict == ProjectionGate::Verdict::accepted, "in-window matching hash accepted");
  check(pa.authority().snapshot_for(client).tick == 2, "hash is the committed tick's");
  check(gate.hash_ring().size() == 1 && gate.hash_ring()[0] == good, "accepted hash lands on the ring");

  // Replay: seq <= lastAccepted. Generic rejection, +3.
  auto o2 = gate.receive(client, 1, good);
  check(same_generic(o2, {ProjectionGate::Verdict::rejected, ProjectionGate::Outcome::Why::sequence}),
        "replayed seq rejected generically as sequence");
  check(gate.suspicion() == ProjectionGate::kSequenceViolationWeight, "sequence violation weighs +3");

  // Too far ahead: seq > lastAccepted + 8. SAME generic outcome as the
  // replay — a probing client cannot tell which bound it crossed.
  auto o3 = gate.receive(client, 100, good);
  check(same_generic(o3, o2), "too-far-ahead seq rejected identically to replay");

  // Hash mismatch: same verdict bucket, different weight (+1).
  const std::uint64_t bad = good ^ 0xdeadbeef;
  auto o4 = gate.receive(client, 2, bad);
  check(o4.verdict == ProjectionGate::Verdict::rejected && o4.why == ProjectionGate::Outcome::Why::hash_mismatch,
        "hash mismatch rejected generically");
  check(gate.suspicion() ==
            ProjectionGate::kSequenceViolationWeight * 2 + ProjectionGate::kHashMismatchWeight,
        "hash mismatch weighs +1 on top of the two sequence violations");

  // Thresholds: at 10 total suspicion a rejection becomes a forced resync
  // (rule-weighted suspicion also counts: 2 rule rejections = 2*2 = 4 via
  // the BAK-06 counter; here sequence 3*2 + hash 1*2 = 8, plus 4 = 12).
  pa.propose(client, pa.field_id("player.position.x"), 4096); // out of 12-bit width: refused
  check(pa.suspicion() == 1, "invalid proposal raises the authority's counter");
  auto o5 = gate.receive(client, 2, bad); // another hash mismatch
  check(o5.verdict == ProjectionGate::Verdict::forced_resync, "at 10 suspicion a rejection forces resync");
  gate.resync(client);
  check(gate.receive(client, 1, good).verdict == ProjectionGate::Verdict::accepted,
        "after resync the window restarts");

  // Suspension latches at 25.
  for (int i = 0; i < 12; ++i) gate.receive(client, 2 + static_cast<std::uint32_t>(i), bad);
  check(gate.suspended(client), "client suspended at 25 suspicion");
  check(gate.receive(client, 500, good).verdict == ProjectionGate::Verdict::suspended,
        "suspended client stays suspended");

  // The ring holds at most the last 64 accepted hashes.
  check(gate.hash_ring().size() <= ProjectionGate::kHashRing, "ring capped at 64");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "projection gate tests passed\n";
  return 0;
}
