// ENG-60: Q16.16 fixed-point primitive suite — exact integer goldens,
// overflow/rounding policy, sqrt reference sweep, and trig error bound.
// Test code may use floating point as an independent reference; the header
// under test contains none.
#include "poko/foundation/fixed.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using poko::math::Fixed;

constexpr std::int32_t kI32Min = std::numeric_limits<std::int32_t>::min();
constexpr std::int32_t kI32Max = std::numeric_limits<std::int32_t>::max();

constexpr Fixed fx(std::int32_t raw) { return Fixed::from_raw(raw); }

// Independent bit-by-bit integer square root (different algorithm than the
// Newton iteration under test).
std::uint64_t isqrt_ref(std::uint64_t n) {
  std::uint64_t res = 0;
  std::uint64_t bit = std::uint64_t{1} << 62;
  while (bit > n) bit >>= 2;
  while (bit != 0) {
    if (n >= res + bit) {
      n -= res + bit;
      res = (res >> 1) + bit;
    } else {
      res >>= 1;
    }
    bit >>= 2;
  }
  return res;
}
}  // namespace

int main() {
  // ---- construction, representation, comparisons ----
  static_assert(Fixed().raw() == 0);
  static_assert(Fixed::zero().raw() == 0 && Fixed::one().raw() == 65536);
  static_assert(Fixed::from_int(3).raw() == 196608);
  static_assert(Fixed::from_int(-2).raw() == -131072);
  static_assert(fx(123).to_int() == 0);          // 123/65536 truncates to 0
  static_assert(fx(-70000).to_int() == -1);      // trunc toward zero, not floor
  CHECK(Fixed::pi().raw() == 205887);
  CHECK(Fixed::two_pi().raw() == 411775);
  CHECK(Fixed::half_pi().raw() == 102944);
  CHECK(fx(5) == fx(5) && !(fx(5) == fx(6)) && fx(5) < fx(6) && fx(-1) < fx(0));
  CHECK(Fixed::from_int(40000).raw() == kI32Max);  // saturating from_int

  // ---- add/sub: wrap modulo 2^32 ----
  CHECK((fx(kI32Max) + Fixed::one()).raw() == kI32Min + 65535);
  CHECK((fx(kI32Min) - Fixed::one()).raw() == kI32Max - 65535);
  CHECK((fx(100) + fx(-100)).is_zero());
  CHECK((-fx(77)).raw() == -77);
  CHECK((-fx(kI32Min)).raw() == kI32Min);  // no positive counterpart
  CHECK(fx(10).abs().raw() == 10 && fx(-10).abs().raw() == 10);

  // ---- mul: 64-bit intermediate, trunc toward zero, saturate ----
  CHECK((Fixed::from_int(3) * Fixed::from_int(2)).raw() == 393216);  // 6.0
  CHECK((Fixed::one() * fx(1)).raw() == 1);                        // exact tiny
  // Negative non-integer product truncates toward zero: -65537/65536 -> -1
  // (floor would give -2).
  CHECK((fx(1) * fx(-65537)).raw() == -1);
  CHECK((fx(-1) * fx(65537)).raw() == -1);
  CHECK((Fixed::from_int(30000) * Fixed::from_int(30000)).raw() == kI32Max);
  CHECK((Fixed::from_int(-30000) * Fixed::from_int(30000)).raw() == kI32Min);
  {  // half-LSB products: 0.5*0.5 = 0.25 exact; 1/3-ish truncation
    CHECK((Fixed::from_raw(32768) * Fixed::from_raw(32768)).raw() == 16384);
    CHECK((fx(21846) * fx(21846)).raw() == 7282);  // 477247716/65536 trunc
  }

  // ---- div: 64-bit, trunc toward zero, saturate, zero -> nullopt ----
  {
    const auto three_half = divide(Fixed::from_int(7), Fixed::from_int(2));
    CHECK(three_half.has_value() && three_half->raw() == 229376);  // 3.5
    CHECK(!divide(Fixed::one(), Fixed::zero()).has_value());
    CHECK(!divide(Fixed::zero(), Fixed::zero()).has_value());
    const auto neg = divide(fx(-1), fx(3));
    CHECK(neg.has_value() && neg->raw() == -21845);  // -1/65536/3 trunc
    const auto sat = divide(Fixed::from_int(30000), fx(1));
    CHECK(sat.has_value() && sat->raw() == kI32Max);
    CHECK(divide(Fixed::zero(), Fixed::one())->raw() == 0);
    CHECK(divide(Fixed::one(), Fixed::one()).value().raw() == 65536);
  }

  // ---- sqrt: exact floor(isqrt(raw << 16)) ----
  CHECK(sqrt(Fixed::zero()).raw() == 0);
  CHECK(sqrt(fx(-5)).raw() == 0);                    // documented: negative -> 0
  CHECK(sqrt(Fixed::from_int(4)).raw() == 131072);   // sqrt(4) = 2
  CHECK(sqrt(Fixed::from_int(2)).raw() == 92681);    // floor(sqrt(2)*65536)
  CHECK(sqrt(Fixed::from_raw(16384)).raw() == 32768);  // sqrt(0.25) = 0.5
  CHECK(sqrt(Fixed::from_int(1)).raw() == 65536);
  CHECK(sqrt(fx(kI32Max)).raw() == 11863283);
  // Reference sweep: every raw input in [0, 400000) plus deterministic
  // pseudo-random inputs across the full positive int32 domain.
  for (std::int64_t raw = 0; raw < 400000; ++raw) {
    const std::uint64_t n = static_cast<std::uint64_t>(raw) << 16;
    const std::int32_t got = sqrt(fx(static_cast<std::int32_t>(raw))).raw();
    const std::uint64_t want = isqrt_ref(n);
    if (got != static_cast<std::int32_t>(want)) {
      std::fprintf(stderr, "FAIL sqrt raw=%lld got=%d want=%llu\n",
                   static_cast<long long>(raw), got,
                   static_cast<unsigned long long>(want));
      ++failures;
      break;
    }
  }
  {
    std::uint64_t state = 0x9e3779b97f4a7c15ull;
    for (int i = 0; i < 200000; ++i) {
      state = state * 6364136223846793005ull + 1442695040888963407ull;
      const std::int32_t raw =
          static_cast<std::int32_t>(state >> 33) & 0x7fffffff;
      const std::uint64_t n = static_cast<std::uint64_t>(raw) << 16;
      const std::int32_t got = sqrt(fx(raw)).raw();
      const std::uint64_t want = isqrt_ref(n);
      if (got != static_cast<std::int32_t>(want)) {
        std::fprintf(stderr, "FAIL sqrt random raw=%d got=%d want=%llu\n", raw,
                     got, static_cast<unsigned long long>(want));
        ++failures;
        break;
      }
    }
  }

  // ---- trig: anchors, symmetry, periodicity, error bound ----
  static_assert(poko::math::sin(Fixed::zero()).raw() == 0);
  CHECK(poko::math::cos(Fixed::zero()).raw() == 65536);
  CHECK(poko::math::sin(Fixed::two_pi()).raw() == 0);
  CHECK(poko::math::sin(Fixed::pi()).raw() >= -3 &&
        poko::math::sin(Fixed::pi()).raw() <= 3);   // sin(pi) ~ 0
  CHECK(std::abs(poko::math::cos(Fixed::half_pi()).raw()) <= 3);
  CHECK(std::abs(poko::math::sin(Fixed::half_pi()).raw() - 65536) <= 2);
  // Odd symmetry within interpolation tolerance (<= 4 LSB slack).
  for (std::int32_t a = -200000; a <= 200000; a += 977) {
    const int sum = poko::math::sin(fx(a)).raw() +
                    poko::math::sin(fx(-a)).raw();
    CHECK(std::abs(sum) <= 4);
    const int cdiff = std::abs(poko::math::cos(fx(a)).raw() -
                               poko::math::cos(fx(-a)).raw());
    CHECK(cdiff <= 4);  // cos is even within interpolation tolerance
  }
  // Periodicity: sin(x + 2pi) == sin(x) bit-exact (same reduced rem).
  for (std::int32_t a = -100000; a <= 100000; a += 1237) {
    CHECK(poko::math::sin(fx(a)).raw() ==
          poko::math::sin(fx(a) + Fixed::two_pi()).raw());
    CHECK(poko::math::cos(fx(a)).raw() ==
          poko::math::cos(fx(a) + Fixed::two_pi()).raw());
  }
  // Error bound: |fixed - true| <= 2 LSB over a dense multi-period sweep,
  // using libm only as the test-side reference.
  {
    double max_err = 0.0;
    for (double a = -20.0; a <= 20.0; a += 0.0007) {
      const Fixed angle = Fixed::from_raw(
          static_cast<std::int32_t>(std::llround(a * 65536.0)));
      const double want_s = std::sin(static_cast<double>(angle.raw()) / 65536.0) * 65536.0;
      const double want_c = std::cos(static_cast<double>(angle.raw()) / 65536.0) * 65536.0;
      max_err = std::max(max_err, std::abs(poko::math::sin(angle).raw() - want_s));
      max_err = std::max(max_err, std::abs(poko::math::cos(angle).raw() - want_c));
    }
    std::printf("trig max error: %.4f LSB\n", max_err);
    CHECK(max_err <= 2.0);
  }

  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_fixed_test: all checks passed");
  return 0;
}
