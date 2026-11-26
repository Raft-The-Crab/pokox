// Review 2026-11-26 M1: FixedVec3 dot / lengthSquared / length / normalized
// over the full Q16.16 range. dot used to saturate each product and then
// WRAP on the sums (lengthSquared(150,150,0) was negative); normalized()
// failed or returned non-unit vectors above ~181 units and below ~0.004.
// Test code may use floating point as an independent reference; the header
// under test contains none.
#include "poko/foundation/fixed_vec.hpp"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <random>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)

using poko::math::Fixed;
using poko::math::FixedVec3;
namespace math = poko::math;

constexpr std::int32_t kI32Max = std::numeric_limits<std::int32_t>::max();

FixedVec3 raw3(std::int32_t x, std::int32_t y, std::int32_t z) {
  return FixedVec3{Fixed::from_raw(x), Fixed::from_raw(y), Fixed::from_raw(z)};
}
FixedVec3 v3(double x, double y, double z) {
  return raw3(static_cast<std::int32_t>(std::llround(x * 65536.0)),
              static_cast<std::int32_t>(std::llround(y * 65536.0)),
              static_cast<std::int32_t>(std::llround(z * 65536.0)));
}
// The pre-fix formula: three saturating Fixed products, wrapping adds.
Fixed naive_dot(FixedVec3 a, FixedVec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
bool naive_in_range(FixedVec3 a, FixedVec3 b) {
  const auto t = [](Fixed p, Fixed q) {
    return static_cast<std::int64_t>(p.raw()) * q.raw() / 65536;
  };
  const std::int64_t x = t(a.x, b.x), y = t(a.y, b.y), z = t(a.z, b.z);
  const auto ok = [](std::int64_t v) { return v >= INT32_MIN && v <= INT32_MAX; };
  return ok(x) && ok(y) && ok(z) && ok(x + y) && ok(x + y + z);
}
double len_d(FixedVec3 v) {
  const double x = v.x.raw(), y = v.y.raw(), z = v.z.raw();
  return std::sqrt(x * x + y * y + z * z);  // raw units
}
}  // namespace

int main() {
  {  // review repro values
    CHECK(math::lengthSquared(v3(150, 150, 0)).raw() == kI32Max);  // was -20536
    CHECK(!math::lengthSquared(v3(150, 150, 0)).is_negative());
    CHECK(math::dot(v3(200, 0, 0), v3(-200, 0, 0)).raw() == std::numeric_limits<std::int32_t>::min());
    const auto n200 = math::normalized(v3(200, 0, 0));
    CHECK(n200 && *n200 == v3(1, 0, 0));  // was x = 1.1047
    const auto tiny = math::normalized(v3(0.003, 0.001, 0));
    CHECK(tiny.has_value());  // was nullopt
    if (tiny) {
      const auto in = v3(0.003, 0.001, 0);
      const double L = len_d(in);
      CHECK(std::abs(tiny->x.raw() - in.x.raw() / L * 65536.0) <= 2.0);
      CHECK(std::abs(tiny->y.raw() - in.y.raw() / L * 65536.0) <= 2.0);
    }
    CHECK(!math::normalized(FixedVec3::zero()).has_value());
    CHECK(math::normalized(raw3(1, 0, 0)) == std::optional<FixedVec3>(v3(1, 0, 0)));
    CHECK(math::normalized(raw3(0, 0, -1)) == std::optional<FixedVec3>(v3(0, 0, -1)));
    CHECK(math::length(v3(3, 4, 0)) == Fixed::from_int(5));
    CHECK(math::length(v3(30000, 40000 / 2, 0)).raw() > 0);
    CHECK(math::length(raw3(kI32Max, kI32Max, kI32Max)).raw() == kI32Max);  // saturates
    CHECK(math::length(v3(-20000, 0, 0)) == Fixed::from_int(20000));
  }
  {  // isqrt_u64 edges
    CHECK(math::detail::isqrt_u64(0) == 0);
    CHECK(math::detail::isqrt_u64(1) == 1);
    CHECK(math::detail::isqrt_u64(3) == 1);
    CHECK(math::detail::isqrt_u64(4) == 2);
    CHECK(math::detail::isqrt_u64(~std::uint64_t{0}) == 0xffffffffu);
    CHECK(math::detail::isqrt_u64(std::uint64_t{0xffffffffu} * 0xffffffffu) == 0xffffffffu);
  }
  std::mt19937_64 rng(0x5eedf00du);
  {  // in range, dot is bit-identical to the old formula (no golden drift)
    std::uniform_int_distribution<std::int32_t> small(-(181 << 16) / 2, (181 << 16) / 2);
    int compared = 0;
    for (int i = 0; i < 200000; ++i) {
      const auto a = raw3(small(rng), small(rng), small(rng));
      const auto b = raw3(small(rng), small(rng), small(rng));
      if (!naive_in_range(a, b)) continue;
      ++compared;
      if (math::dot(a, b) != naive_dot(a, b)) { CHECK(math::dot(a, b) == naive_dot(a, b)); break; }
    }
    CHECK(compared > 100000);
  }
  {  // full domain: never wraps; equals the clamped exact value
    std::uniform_int_distribution<std::int32_t> any(INT32_MIN, INT32_MAX);
    for (int i = 0; i < 200000; ++i) {
      const auto a = raw3(any(rng), any(rng), any(rng));
      const auto b = raw3(any(rng), any(rng), any(rng));
      const auto t = [](Fixed p, Fixed q) {
        return static_cast<std::int64_t>(p.raw()) * q.raw() / 65536;
      };
      std::int64_t want = t(a.x, b.x) + t(a.y, b.y) + t(a.z, b.z);
      if (want > INT32_MAX) want = INT32_MAX;
      if (want < INT32_MIN) want = INT32_MIN;
      if (math::dot(a, b).raw() != want) { CHECK(math::dot(a, b).raw() == want); break; }
      if (math::lengthSquared(a).is_negative()) { CHECK(!math::lengthSquared(a).is_negative()); break; }
    }
  }
  {  // length is floor-exact; normalized is unit within 2 LSB per component
    std::uniform_int_distribution<int> mag_bits(0, 31);
    int worst_len = 0;
    double worst_comp = 0;
    for (int i = 0; i < 200000; ++i) {
      const int bits = mag_bits(rng);
      const std::int64_t lim = bits == 31 ? INT32_MAX : (std::int64_t{1} << bits);
      std::uniform_int_distribution<std::int64_t> d(-lim, lim);
      const auto v = raw3(static_cast<std::int32_t>(d(rng)), static_cast<std::int32_t>(d(rng)),
                          static_cast<std::int32_t>(d(rng)));
      const double L = len_d(v);
      const std::int64_t got = math::length(v).raw();
      const double want = std::floor(L) > INT32_MAX ? INT32_MAX : std::floor(L);
      if (std::abs(static_cast<double>(got) - want) > 1.0) {
        CHECK(std::abs(static_cast<double>(got) - want) <= 1.0);
        break;
      }
      const auto u = math::normalized(v);
      if (v == FixedVec3::zero()) { CHECK(!u); continue; }
      if (!u) { CHECK(u.has_value()); break; }
      const double comps[3] = {double(v.x.raw()), double(v.y.raw()), double(v.z.raw())};
      for (std::size_t c = 0; c < 3; ++c) {
        const double ref = comps[c] / L * 65536.0;
        worst_comp = std::max(worst_comp, std::abs((*u)[c].raw() - ref));
      }
      const double ul = len_d(*u);
      worst_len = std::max(worst_len, static_cast<int>(std::abs(ul - 65536.0)));
    }
    std::printf("normalized worst component error %.3f LSB, worst |len-1| %d LSB\n",
                worst_comp, worst_len);
    CHECK(worst_comp <= 2.0);
    CHECK(worst_len <= 4);
  }
  if (failures != 0) {
    std::fprintf(stderr, "%d check(s) failed\n", failures);
    return 1;
  }
  std::puts("pokox_fixed_vec_test: all checks passed");
  return 0;
}
