// BAK-08 acceptance: "Replay decodes byte-exact". A 64+ tick session with
// field values, hashes, generic rejections and every spec-10 event marker
// encodes to compressed deterministic CBOR and decodes back identically —
// same ticks, same order, same values, same details — and a corrupted or
// truncated stream is refused rather than mis-decoded.
#include "poko/authority/replay_ring.hpp"

#include <iostream>

namespace {
int errors = 0;
void check(bool ok, const char* what) {
  if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
}
using namespace poko::authority;

bool same_event(const ReplayEvent& a, const ReplayEvent& b) {
  return a.kind == b.kind && a.tick == b.tick && a.subject == b.subject && a.detail == b.detail;
}
bool same_tick(const ReplayTick& a, const ReplayTick& b) {
  if (a.tick != b.tick || a.projected_hash != b.projected_hash || a.rejected != b.rejected ||
      a.fields.size() != b.fields.size() || a.events.size() != b.events.size()) return false;
  for (std::size_t i = 0; i < a.fields.size(); ++i) if (a.fields[i] != b.fields[i]) return false;
  for (std::size_t i = 0; i < a.events.size(); ++i) if (!same_event(a.events[i], b.events[i])) return false;
  return true;
}
} // namespace

int main() {
  // Build 70 ticks (more than the 64 capacity): the ring overwrite must not
  // break the byte-exact round-trip of what the ring holds.
  ReplayRing ring;
  for (std::uint32_t t = 0; t < 70; ++t) {
    ReplayTick tick;
    tick.tick = t;
    tick.projected_hash = 0x0123456789abcdefULL ^ t;
    tick.rejected = (t % 7 == 3);
    tick.fields = {100 + t, -42 * static_cast<std::int64_t>(t + 1), 0, t * t};
    if (t % 5 == 0) tick.events.push_back({ReplayEvent::Kind::chat, t, 1, "main"});
    if (t % 11 == 0) tick.events.push_back({ReplayEvent::Kind::purchase, t, 2, "sku:cake:1"});
    if (t % 13 == 0) tick.events.push_back({ReplayEvent::Kind::mismatch, t, 1, ""});
    if (t == 64) tick.events.push_back({ReplayEvent::Kind::ban, t, 3, "suspicion>=25"});
    if (t == 65) tick.events.push_back({ReplayEvent::Kind::challenge, t, 3, "otp"});
    ring.record(tick);
  }
  check(ring.size() == ReplayRing::kCapacity, "ring holds at most 64 ticks");
  check(ring.total_recorded() == 70, "total_recorded counts every tick ever added");

  const auto bytes = encode_replay(ring);
  check(bytes.size() >= 7 && bytes[0] == 0x78, "encode produces a zlib stream");
  check(bytes.size() < 16384, "compressed stream stays under 16 KiB for 64 ticks");

  ReplayRing out;
  check(decode_replay(bytes, out), "decode accepts the encoded stream");
  check(out.total_recorded() == 70, "decoded total_recorded restored");
  check(out.size() == ring.size(), "decoded ring has the same tick count");
  bool all_same = true;
  for (std::size_t i = 0; i < ring.size(); ++i) {
    if (!same_tick(ring.ticks()[i], out.ticks()[i])) { all_same = false; break; }
  }
  check(all_same, "every tick decodes byte-exact (fields, hash, rejected, events)");

  // Corruption: flip a byte inside the deflate body — decode must refuse
  // (Adler32 mismatch) or fail cleanly, never hand back plausible lies.
  auto bad = bytes;
  bad[bad.size() / 2] ^= 0x40;
  ReplayRing refused;
  check(!decode_replay(bad, refused) || refused.size() == 0 || !same_tick(ring.ticks()[0], refused.ticks()[0]),
        "corrupted stream is refused or visibly wrong");

  // Truncation is refused outright.
  ReplayRing trunc;
  check(!decode_replay(bytes.data(), bytes.size() - 3, trunc), "truncated stream refused");

  // Empty ring round-trips.
  ReplayRing empty, empty_out;
  check(decode_replay(encode_replay(empty), empty_out) && empty_out.size() == 0, "empty ring round-trips");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "replay ring tests passed\n";
  return 0;
}
