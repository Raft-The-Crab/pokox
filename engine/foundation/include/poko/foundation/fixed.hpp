#pragma once

#include <bit>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>

namespace poko::math {

// ENG-60 / spec 24 "Fixed-point arithmetic" and spec 21 "Math library":
// Q16.16 fixed-point scalar for the deterministic sim physics path. The value
// is a signed 32-bit two's-complement integer with 16 fractional bits, so the
// representable range is [-32768.0, 32767.99998] with a resolution of
// 1/65536 (~1.5e-5).
//
// Determinism contract: every operation is pure integer arithmetic — no
// libm, no float, no SIMD, no host rounding mode. Identical inputs produce
// identical raw results on x64 and arm64. Spec rule "no float anywhere in
// sim code, including constants" is honored: this header contains no
// floating-point literal or operation.
//
// Overflow and error policy (all documented, all deterministic):
//   add/sub  wrap modulo 2^32 ("plain integer ops" per spec)
//   mul      64-bit intermediate, result truncated toward zero, saturated
//            to the int32 raw range on overflow
//   div      64-bit intermediate, truncated toward zero, saturated;
//            division by zero returns std::nullopt (no silent inf/NaN)
//   sqrt     exact floor(isqrt(raw << 16)); negative input yields zero
//   sin/cos  1024-entry table + linear interpolation, argument reduced
//            modulo 2*pi (constants below); worst-case error <= 2 LSB
//            (~3.05e-5), verified by sweep in pokox_fixed_test
class Fixed {
 public:
  static constexpr std::int32_t kFractionBits = 16;
  static constexpr std::int32_t kScale = 1 << kFractionBits;  // 65536

  constexpr Fixed() noexcept = default;

  // Raw constructors never fail; callers own range discipline.
  static constexpr Fixed from_raw(std::int32_t raw) noexcept {
    Fixed f;
    f.raw_ = raw;
    return f;
  }
  // Saturating: |value| above the representable range clamps to the
  // nearest representable raw value instead of wrapping.
  static constexpr Fixed from_int(std::int32_t value) noexcept {
    return from_raw(saturate_i32(static_cast<std::int64_t>(value) * kScale));
  }

  constexpr std::int32_t raw() const noexcept { return raw_; }
  // Truncation toward zero, matching fixed-point division semantics.
  constexpr std::int32_t to_int() const noexcept { return raw_ / kScale; }

  static constexpr Fixed zero() noexcept { return from_raw(0); }
  static constexpr Fixed one() noexcept { return from_raw(kScale); }

  // Angle constants in radians, correctly rounded to Q16.16. two_pi is the
  // reduction modulus used by sin/cos; half_pi is the cos offset.
  static constexpr Fixed pi() noexcept { return from_raw(205887); }
  static constexpr Fixed two_pi() noexcept { return from_raw(411775); }
  static constexpr Fixed half_pi() noexcept { return from_raw(102944); }

  constexpr bool is_zero() const noexcept { return raw_ == 0; }
  constexpr bool is_negative() const noexcept { return raw_ < 0; }

  constexpr Fixed operator-() const noexcept { return from_raw(negate(raw_)); }
  constexpr Fixed& operator+=(Fixed o) noexcept { raw_ = add(raw_, o.raw_); return *this; }
  constexpr Fixed& operator-=(Fixed o) noexcept { raw_ = add(raw_, negate(o.raw_)); return *this; }
  constexpr Fixed& operator*=(Fixed o) noexcept { raw_ = multiply(raw_, o.raw_); return *this; }

  constexpr Fixed abs() const noexcept { return from_raw(raw_ < 0 ? negate(raw_) : raw_); }

  constexpr bool operator==(Fixed o) const noexcept { return raw_ == o.raw_; }
  constexpr auto operator<=>(Fixed o) const noexcept { return raw_ <=> o.raw_; }

 private:
  std::int32_t raw_ = 0;

  static constexpr std::int32_t add(std::int32_t a, std::int32_t b) noexcept {
    // Unsigned add wraps modulo 2^32; the bit pattern is then reinterpreted
    // as the two's-complement result. Well-defined on every platform.
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(a) +
                                     static_cast<std::uint32_t>(b));
  }
  static constexpr std::int32_t negate(std::int32_t a) noexcept {
    // INT32_MIN has no positive counterpart; it wraps to itself, which is
    // the only consistent two's-complement behavior.
    return static_cast<std::int32_t>(0u - static_cast<std::uint32_t>(a));
  }
  static constexpr std::int32_t multiply(std::int32_t a, std::int32_t b) noexcept {
    // Q16.16 * Q16.16 -> Q16.16: 64-bit product shifted right 16 with
    // truncation toward zero (C++ integer division), then saturated.
    const std::int64_t product =
        static_cast<std::int64_t>(a) * static_cast<std::int64_t>(b);
    return saturate_i32(product / kScale);
  }
  static constexpr std::int32_t saturate_i32(std::int64_t v) noexcept {
    if (v > std::numeric_limits<std::int32_t>::max())
      return std::numeric_limits<std::int32_t>::max();
    if (v < std::numeric_limits<std::int32_t>::min())
      return std::numeric_limits<std::int32_t>::min();
    return static_cast<std::int32_t>(v);
  }

  friend constexpr Fixed operator+(Fixed a, Fixed b) noexcept {
    return Fixed::from_raw(Fixed::add(a.raw_, b.raw_));
  }
  friend constexpr Fixed operator-(Fixed a, Fixed b) noexcept {
    return Fixed::from_raw(Fixed::add(a.raw_, Fixed::negate(b.raw_)));
  }
  friend constexpr Fixed operator*(Fixed a, Fixed b) noexcept {
    return Fixed::from_raw(Fixed::multiply(a.raw_, b.raw_));
  }
};

// Q16.16 division: (a / b) computed as (a_raw << 16) / b_raw in 64-bit,
// truncated toward zero and saturated. Returns std::nullopt on a zero
// divisor — sim code must handle the empty result explicitly; there is no
// infinite or NaN fixed-point value.
constexpr std::optional<Fixed> divide(Fixed a, Fixed b) noexcept {
  if (b.raw() == 0) return std::nullopt;
  const std::int64_t numerator = static_cast<std::int64_t>(a.raw()) * Fixed::kScale;
  const std::int64_t quotient = numerator / b.raw();
  if (quotient > std::numeric_limits<std::int32_t>::max())
    return Fixed::from_raw(std::numeric_limits<std::int32_t>::max());
  if (quotient < std::numeric_limits<std::int32_t>::min())
    return Fixed::from_raw(std::numeric_limits<std::int32_t>::min());
  return Fixed::from_raw(static_cast<std::int32_t>(quotient));
}

// Exact integer square root of the represented value: returns
// floor(sqrt(raw << 16)) as a raw Q16.16 result, i.e. the correctly rounded-
// down square root within 1 LSB. Newton iteration from a power-of-two seed
// with a fixed 32 steps; the final step takes the minimum of the last two
// iterates because integer Newton can settle into a 2-cycle one unit above
// the floor (e.g. raw inputs just below a perfect square). Verified exact
// for every raw input in [0, 2^21) and 300k random inputs across the full
// int32 domain by pokox_fixed_test's reference sweep. Negative input
// yields zero; callers validate sign before calling.
constexpr Fixed sqrt(Fixed x) noexcept {
  const std::int64_t raw = x.raw();
  if (raw <= 0) return Fixed::zero();
  const std::uint64_t n = static_cast<std::uint64_t>(raw) << Fixed::kFractionBits;
  const int bits = 64 - std::countl_zero(n);
  std::uint64_t guess = std::uint64_t{1} << ((bits + 1) / 2);
  for (int i = 0; i < 32; ++i) guess = (guess + n / guess) / 2;
  const std::uint64_t next = (guess + n / guess) / 2;
  const std::uint64_t root = guess < next ? guess : next;
  return Fixed::from_raw(static_cast<std::int32_t>(root));
}

namespace detail {

// Reduction modulus and cos offset as 64-bit raw values so argument
// reduction cannot overflow even for extreme inputs.
inline constexpr std::int64_t kTwoPiRaw = 411775;
inline constexpr std::int64_t kHalfPiRaw = 102944;
inline constexpr int kSinTableSize = 1024;  // entries per full turn

// Sine table: round(sin(2*pi*i/1024) * 65536), i in [0,1024). Generated
// offline; entries are Q16.16 raw integers. Symmetry is exact by
// construction (entry i+512 == -entry i) so sin/cos stay consistent across
// quadrants.
inline constexpr std::int32_t kSinTable[kSinTableSize] = {
       0,    402,    804,   1206,   1608,   2010,   2412,   2814,
    3216,   3617,   4019,   4420,   4821,   5222,   5623,   6023,
    6424,   6824,   7224,   7623,   8022,   8421,   8820,   9218,
    9616,  10014,  10411,  10808,  11204,  11600,  11996,  12391,
   12785,  13180,  13573,  13966,  14359,  14751,  15143,  15534,
   15924,  16314,  16703,  17091,  17479,  17867,  18253,  18639,
   19024,  19409,  19792,  20175,  20557,  20939,  21320,  21699,
   22078,  22457,  22834,  23210,  23586,  23961,  24335,  24708,
   25080,  25451,  25821,  26190,  26558,  26925,  27291,  27656,
   28020,  28383,  28745,  29106,  29466,  29824,  30182,  30538,
   30893,  31248,  31600,  31952,  32303,  32652,  33000,  33347,
   33692,  34037,  34380,  34721,  35062,  35401,  35738,  36075,
   36410,  36744,  37076,  37407,  37736,  38064,  38391,  38716,
   39040,  39362,  39683,  40002,  40320,  40636,  40951,  41264,
   41576,  41886,  42194,  42501,  42806,  43110,  43412,  43713,
   44011,  44308,  44604,  44898,  45190,  45480,  45769,  46056,
   46341,  46624,  46906,  47186,  47464,  47741,  48015,  48288,
   48559,  48828,  49095,  49361,  49624,  49886,  50146,  50404,
   50660,  50914,  51166,  51417,  51665,  51911,  52156,  52398,
   52639,  52878,  53114,  53349,  53581,  53812,  54040,  54267,
   54491,  54714,  54934,  55152,  55368,  55582,  55794,  56004,
   56212,  56418,  56621,  56823,  57022,  57219,  57414,  57607,
   57798,  57986,  58172,  58356,  58538,  58718,  58896,  59071,
   59244,  59415,  59583,  59750,  59914,  60075,  60235,  60392,
   60547,  60700,  60851,  60999,  61145,  61288,  61429,  61568,
   61705,  61839,  61971,  62101,  62228,  62353,  62476,  62596,
   62714,  62830,  62943,  63054,  63162,  63268,  63372,  63473,
   63572,  63668,  63763,  63854,  63944,  64031,  64115,  64197,
   64277,  64354,  64429,  64501,  64571,  64639,  64704,  64766,
   64827,  64884,  64940,  64993,  65043,  65091,  65137,  65180,
   65220,  65259,  65294,  65328,  65358,  65387,  65413,  65436,
   65457,  65476,  65492,  65505,  65516,  65525,  65531,  65535,
   65536,  65535,  65531,  65525,  65516,  65505,  65492,  65476,
   65457,  65436,  65413,  65387,  65358,  65328,  65294,  65259,
   65220,  65180,  65137,  65091,  65043,  64993,  64940,  64884,
   64827,  64766,  64704,  64639,  64571,  64501,  64429,  64354,
   64277,  64197,  64115,  64031,  63944,  63854,  63763,  63668,
   63572,  63473,  63372,  63268,  63162,  63054,  62943,  62830,
   62714,  62596,  62476,  62353,  62228,  62101,  61971,  61839,
   61705,  61568,  61429,  61288,  61145,  60999,  60851,  60700,
   60547,  60392,  60235,  60075,  59914,  59750,  59583,  59415,
   59244,  59071,  58896,  58718,  58538,  58356,  58172,  57986,
   57798,  57607,  57414,  57219,  57022,  56823,  56621,  56418,
   56212,  56004,  55794,  55582,  55368,  55152,  54934,  54714,
   54491,  54267,  54040,  53812,  53581,  53349,  53114,  52878,
   52639,  52398,  52156,  51911,  51665,  51417,  51166,  50914,
   50660,  50404,  50146,  49886,  49624,  49361,  49095,  48828,
   48559,  48288,  48015,  47741,  47464,  47186,  46906,  46624,
   46341,  46056,  45769,  45480,  45190,  44898,  44604,  44308,
   44011,  43713,  43412,  43110,  42806,  42501,  42194,  41886,
   41576,  41264,  40951,  40636,  40320,  40002,  39683,  39362,
   39040,  38716,  38391,  38064,  37736,  37407,  37076,  36744,
   36410,  36075,  35738,  35401,  35062,  34721,  34380,  34037,
   33692,  33347,  33000,  32652,  32303,  31952,  31600,  31248,
   30893,  30538,  30182,  29824,  29466,  29106,  28745,  28383,
   28020,  27656,  27291,  26925,  26558,  26190,  25821,  25451,
   25080,  24708,  24335,  23961,  23586,  23210,  22834,  22457,
   22078,  21699,  21320,  20939,  20557,  20175,  19792,  19409,
   19024,  18639,  18253,  17867,  17479,  17091,  16703,  16314,
   15924,  15534,  15143,  14751,  14359,  13966,  13573,  13180,
   12785,  12391,  11996,  11600,  11204,  10808,  10411,  10014,
    9616,   9218,   8820,   8421,   8022,   7623,   7224,   6824,
    6424,   6023,   5623,   5222,   4821,   4420,   4019,   3617,
    3216,   2814,   2412,   2010,   1608,   1206,    804,    402,
       0,   -402,   -804,  -1206,  -1608,  -2010,  -2412,  -2814,
   -3216,  -3617,  -4019,  -4420,  -4821,  -5222,  -5623,  -6023,
   -6424,  -6824,  -7224,  -7623,  -8022,  -8421,  -8820,  -9218,
   -9616, -10014, -10411, -10808, -11204, -11600, -11996, -12391,
  -12785, -13180, -13573, -13966, -14359, -14751, -15143, -15534,
  -15924, -16314, -16703, -17091, -17479, -17867, -18253, -18639,
  -19024, -19409, -19792, -20175, -20557, -20939, -21320, -21699,
  -22078, -22457, -22834, -23210, -23586, -23961, -24335, -24708,
  -25080, -25451, -25821, -26190, -26558, -26925, -27291, -27656,
  -28020, -28383, -28745, -29106, -29466, -29824, -30182, -30538,
  -30893, -31248, -31600, -31952, -32303, -32652, -33000, -33347,
  -33692, -34037, -34380, -34721, -35062, -35401, -35738, -36075,
  -36410, -36744, -37076, -37407, -37736, -38064, -38391, -38716,
  -39040, -39362, -39683, -40002, -40320, -40636, -40951, -41264,
  -41576, -41886, -42194, -42501, -42806, -43110, -43412, -43713,
  -44011, -44308, -44604, -44898, -45190, -45480, -45769, -46056,
  -46341, -46624, -46906, -47186, -47464, -47741, -48015, -48288,
  -48559, -48828, -49095, -49361, -49624, -49886, -50146, -50404,
  -50660, -50914, -51166, -51417, -51665, -51911, -52156, -52398,
  -52639, -52878, -53114, -53349, -53581, -53812, -54040, -54267,
  -54491, -54714, -54934, -55152, -55368, -55582, -55794, -56004,
  -56212, -56418, -56621, -56823, -57022, -57219, -57414, -57607,
  -57798, -57986, -58172, -58356, -58538, -58718, -58896, -59071,
  -59244, -59415, -59583, -59750, -59914, -60075, -60235, -60392,
  -60547, -60700, -60851, -60999, -61145, -61288, -61429, -61568,
  -61705, -61839, -61971, -62101, -62228, -62353, -62476, -62596,
  -62714, -62830, -62943, -63054, -63162, -63268, -63372, -63473,
  -63572, -63668, -63763, -63854, -63944, -64031, -64115, -64197,
  -64277, -64354, -64429, -64501, -64571, -64639, -64704, -64766,
  -64827, -64884, -64940, -64993, -65043, -65091, -65137, -65180,
  -65220, -65259, -65294, -65328, -65358, -65387, -65413, -65436,
  -65457, -65476, -65492, -65505, -65516, -65525, -65531, -65535,
  -65536, -65535, -65531, -65525, -65516, -65505, -65492, -65476,
  -65457, -65436, -65413, -65387, -65358, -65328, -65294, -65259,
  -65220, -65180, -65137, -65091, -65043, -64993, -64940, -64884,
  -64827, -64766, -64704, -64639, -64571, -64501, -64429, -64354,
  -64277, -64197, -64115, -64031, -63944, -63854, -63763, -63668,
  -63572, -63473, -63372, -63268, -63162, -63054, -62943, -62830,
  -62714, -62596, -62476, -62353, -62228, -62101, -61971, -61839,
  -61705, -61568, -61429, -61288, -61145, -60999, -60851, -60700,
  -60547, -60392, -60235, -60075, -59914, -59750, -59583, -59415,
  -59244, -59071, -58896, -58718, -58538, -58356, -58172, -57986,
  -57798, -57607, -57414, -57219, -57022, -56823, -56621, -56418,
  -56212, -56004, -55794, -55582, -55368, -55152, -54934, -54714,
  -54491, -54267, -54040, -53812, -53581, -53349, -53114, -52878,
  -52639, -52398, -52156, -51911, -51665, -51417, -51166, -50914,
  -50660, -50404, -50146, -49886, -49624, -49361, -49095, -48828,
  -48559, -48288, -48015, -47741, -47464, -47186, -46906, -46624,
  -46341, -46056, -45769, -45480, -45190, -44898, -44604, -44308,
  -44011, -43713, -43412, -43110, -42806, -42501, -42194, -41886,
  -41576, -41264, -40951, -40636, -40320, -40002, -39683, -39362,
  -39040, -38716, -38391, -38064, -37736, -37407, -37076, -36744,
  -36410, -36075, -35738, -35401, -35062, -34721, -34380, -34037,
  -33692, -33347, -33000, -32652, -32303, -31952, -31600, -31248,
  -30893, -30538, -30182, -29824, -29466, -29106, -28745, -28383,
  -28020, -27656, -27291, -26925, -26558, -26190, -25821, -25451,
  -25080, -24708, -24335, -23961, -23586, -23210, -22834, -22457,
  -22078, -21699, -21320, -20939, -20557, -20175, -19792, -19409,
  -19024, -18639, -18253, -17867, -17479, -17091, -16703, -16314,
  -15924, -15534, -15143, -14751, -14359, -13966, -13573, -13180,
  -12785, -12391, -11996, -11600, -11204, -10808, -10411, -10014,
   -9616,  -9218,  -8820,  -8421,  -8022,  -7623,  -7224,  -6824,
   -6424,  -6023,  -5623,  -5222,  -4821,  -4420,  -4019,  -3617,
   -3216,  -2814,  -2412,  -2010,  -1608,  -1206,   -804,   -402,
};

// sin/cos take radians as a Fixed angle. The argument is reduced modulo
// 2*pi in 64-bit, mapped onto the table by (rem * 1024) / 411775, and
// linearly interpolated between adjacent entries with truncation toward
// zero. Table quantization contributes <= 0.5 LSB per entry, segment
// curvature <= ~0.31 LSB (h = 2*pi/1024, |sin''| <= 1), and interpolation
// truncation < 1 LSB: total worst case <= 2 LSB, matching the documented
// bound above. cos is sin evaluated at angle + pi/2 with the offset applied
// before reduction, so no second table is needed.
constexpr Fixed sine_lookup(std::int64_t angle_raw) noexcept {
  std::int64_t rem = angle_raw % kTwoPiRaw;
  if (rem < 0) rem += kTwoPiRaw;
  const std::int64_t pos = rem * kSinTableSize;
  const std::int64_t index = pos / kTwoPiRaw;  // [0, 1023]
  const std::int64_t frac = pos - index * kTwoPiRaw;  // [0, kTwoPiRaw)
  const std::int32_t s0 = kSinTable[static_cast<std::size_t>(index)];
  const std::int32_t s1 = kSinTable[static_cast<std::size_t>(
      index + 1 == kSinTableSize ? 0 : index + 1)];
  const std::int64_t delta = static_cast<std::int64_t>(s1) - s0;
  const std::int64_t adjust = delta * frac / kTwoPiRaw;  // trunc toward zero
  const std::int64_t value = static_cast<std::int64_t>(s0) + adjust;
  const std::int64_t clamped = value > std::numeric_limits<std::int32_t>::max()
                                  ? std::numeric_limits<std::int32_t>::max()
                              : value < std::numeric_limits<std::int32_t>::min()
                                  ? std::numeric_limits<std::int32_t>::min()
                                  : value;
  return Fixed::from_raw(static_cast<std::int32_t>(clamped));
}

}  // namespace detail

constexpr Fixed sin(Fixed radians) noexcept {
  return detail::sine_lookup(radians.raw());
}
constexpr Fixed cos(Fixed radians) noexcept {
  return detail::sine_lookup(static_cast<std::int64_t>(radians.raw()) +
                             detail::kHalfPiRaw);
}

}  // namespace poko::math
