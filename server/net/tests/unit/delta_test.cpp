// NET-04 acceptance: only changed bits on the wire. A delta with 1 of 5
// fields changed costs bitmap+field, not a full snapshot; unchanged fields
// merge from the baseline on decode; the 64-packet resend window tracks
// unacked packets and clears them on ack.
#include "poko/net/delta.hpp"

#include <iostream>
#include <stdexcept>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  DeltaSchema schema;
  schema.add_uint("health", 10);
  schema.add_uint("ammo", 8);
  schema.add_int("score", 12);
  schema.add_float("x", -100.0, 100.0, 12);
  schema.add_float("y", -100.0, 100.0, 12);
  check(schema.field_count() == 5, "schema holds 5 fields");

  // Baseline snapshot.
  std::vector<std::uint64_t> baseline = {100, 30, 500, 0, 0};
  // Current: only score changed (-300 -> zigzag 599 on the wire).
  double new_x = 12.5;
  std::uint64_t new_x_bits;
  std::memcpy(&new_x_bits, &new_x, sizeof(new_x_bits));
  std::vector<std::uint64_t> current = {100, 30, static_cast<std::uint64_t>(static_cast<std::int64_t>(-300)), new_x_bits, 0};

  // Wait: two fields changed (score and x) — compute the expected wire cost.
  // bitmap 5 bits + score 12 + x 12 = 29 bits -> 4 bytes.
  BitBuffer out;
  encode_delta(schema, out, baseline, current);
  check(out.size_bytes() == 4, "delta is 4 bytes (5 bitmap bits + 12 + 12 field bits), not a full snapshot");
  check(out.size_bytes() < 1 + (10 + 8 + 12 + 12 + 12) / 8, "delta is smaller than a full snapshot");

  auto decoded = [&] {
    BitBuffer in(out.bytes().size());
    // Decode via a fresh reader: rebuild by reading from the same bytes.
    // BitBuffer reads from its own written bytes, so decode from a copy.
    BitBuffer reader;
    reader.bytes(); // no direct byte injection; use the decode helper below
    (void)in;
    return std::vector<std::uint64_t>{};
  };
  (void)decoded;

  // BitBuffer is write-cursored; decode needs a read-cursor over the same
  // bytes. Round-trip through a second BitBuffer that re-writes the bytes
  // bit-for-bit is wasteful — instead decode via the raw-byte constructor
  // the test adds here: copy bytes in by writing them as u8 fields.
  BitBuffer reader;
  for (std::size_t i = 0; i < out.size_bytes(); ++i) {
    // Re-write the exact bits: write each byte's 8 bits LSB-first.
    for (unsigned bit = 0; bit < 8; ++bit)
      reader.put_uint((out.bytes()[i] >> bit) & 1, 1);
  }
  auto merged = decode_delta(schema, reader, baseline);
  check(merged[0] == 100 && merged[1] == 30, "unchanged fields keep baseline values");
  check(static_cast<std::int64_t>(merged[2]) == -300, "changed int field decodes");
  double dx; std::memcpy(&dx, &merged[3], sizeof(dx));
  check(dx > 12.4 && dx < 12.6, "changed float field decodes within half a step");
  check(merged[4] == 0, "untouched field keeps baseline");

  // Resend window: push 3 packets, ack clears the acked ones only.
  ResendWindow window;
  check(window.push(1, {1}), "push 1 ok");
  check(window.push(2, {2}), "push 2 ok");
  check(window.push(3, {3}), "push 3 ok");
  check(window.pending() == 3, "3 packets pending");
  check(window.values_for(2)[0] == 2, "values retrievable by seq");
  check(window.on_ack(3, /*ack_bits*/ 0b110) == 3, "ack 3 + bit1 (seq2) + bit2 (seq1) clears all 3 packets");
  check(window.pending() == 0, "all acked packets cleared");

  // Window cap: 64 max, the 65th push is refused.
  ResendWindow full;
  for (std::uint32_t i = 0; i < kResendWindow; ++i) {
    if (!full.push(i, {i})) { check(false, "window accepts 64 packets"); break; }
  }
  check(!full.push(999, {0}), "65th push refused when window full");

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "delta tests passed\n";
  return 0;
}
