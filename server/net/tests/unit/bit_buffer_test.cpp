// NET-02 acceptance: bit-width goldens. Pinned byte sequences for each
// primitive — the wire format cannot drift silently, so expected bytes are
// hand-computed from the spec's encoding rules, not from the code.
#include "poko/net/bit_buffer.hpp"

#include <iostream>
#include <stdexcept>

using namespace poko::net;

int main() {
  int errors = 0;
  auto check = [&](bool ok, const char* what) {
    if (!ok) { ++errors; std::cerr << "FAIL: " << what << "\n"; }
  };

  // Golden 1: putBool(1) + putUint(0b10, 2) + putUint(0b101, 3).
  // Bits: 1 | 0,1 | 1,0,1 = byte0 bit0..5 = 0b110101 -> 0x35.
  {
    BitBuffer b;
    b.put_bool(true);
    b.put_uint(0b10, 2);
    b.put_uint(0b101, 3);
    check(b.size_bytes() == 1, "7 bits fit in one byte");
    check(b.bytes()[0] == 0x2D, "bit-packed golden is 0x2D (LSB-first: 1,0,1,1,0,1)");
  }

  // Golden 2: putUint over a byte boundary. putUint(0x1FF, 10): 9 ones
  // then 0, LSB-first — byte 0 = 0xFF, byte 1 bit0..1 = 0b01 -> 0x01.
  {
    BitBuffer b;
    b.put_uint(0x1FF, 10);
    check(b.size_bytes() == 2, "10 bits span two bytes");
    check(b.bytes()[0] == 0xFF && b.bytes()[1] == 0x01, "cross-byte golden is FF 01");
  }

  // Round-trip: uint across widths, zigzag ints, quantized floats.
  {
    BitBuffer b;
    b.put_uint(0xDEADBEEF, 32);
    b.put_int(-1, 8);      // zigzag 1
    b.put_int(64, 8);      // zigzag 128
    b.put_int(-300, 12);   // zigzag 599
    b.put_quant_float(0.5, 0.0, 1.0, 8);
    b.put_string("poko");
    b.put_array(2, 4, [&](std::size_t) { b.put_uint(7, 4); });
    b.put_delta(true, [&] { b.put_uint(42, 8); });
    b.put_delta(false, [&] {});

    check(b.get_uint(32) == 0xDEADBEEF, "u32 round-trip");
    check(b.get_int(8) == -1, "zigzag -1 round-trip");
    check(b.get_int(8) == 64, "zigzag 64 round-trip");
    check(b.get_int(12) == -300, "zigzag -300 round-trip");
    double q = b.get_quant_float(0.0, 1.0, 8);
    check(q > 0.49 && q < 0.51, "quantized 0.5 round-trips within half a step");
    check(b.get_string() == "poko", "string round-trip");
    std::size_t count = 0;
    b.get_array(4, [&](std::size_t) { check(b.get_uint(4) == 7, "array element round-trip"); ++count; });
    check(count == 2, "array length round-trips");
    check(b.get_delta([&] { b.get_uint(8); }) == true, "changed delta returns true");
    check(b.get_delta([&] {}) == false, "unchanged delta returns false");
  }

  // Trapping: overflow values and reads past the end throw, never truncate.
  {
    bool threw = false;
    try { BitBuffer b; b.put_uint(0x1F, 4); } catch (const std::invalid_argument&) { threw = true; }
    check(threw, "putUint overflow throws");

    threw = false;
    try { BitBuffer b; b.get_uint(9); } catch (const std::runtime_error&) { threw = true; }
    check(threw, "read past end throws");

    threw = false;
    try { BitBuffer b; b.put_quant_float(1.5, 0.0, 1.0, 8); } catch (const std::invalid_argument&) { threw = true; }
    check(threw, "quantized value out of range throws");
  }

  if (errors) { std::cerr << errors << " failure(s)\n"; return 1; }
  std::cout << "bit buffer tests passed\n";
  return 0;
}
