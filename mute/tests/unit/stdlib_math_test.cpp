// MUT-51: pinned deterministic math/vector/RNG/time API checks.
#include "poko/mute/stdlib_math.hpp"

#include <array>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>
#include <span>
#include <string_view>
#include <vector>

using namespace poko::mute;
namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)
bool near(double a, double b) { return std::fabs(a - b) < 1e-12; }
bool near_vec(Vec3 a, Vec3 b) { return near(a.x,b.x) && near(a.y,b.y) && near(a.z,b.z); }
}  // namespace

int main() {
  CHECK(near(det_sqrt(9.0), 3.0));
  CHECK(near(det_floor(-1.2), -2.0));
  CHECK(near(det_round(2.5), 3.0));
  CHECK(near(det_clamp(7.0, 0.0, 5.0), 5.0));
  CHECK(near(det_lerp(2.0, 6.0, 0.25), 3.0));
  CHECK(near(det_pow(2.0, 10.0), 1024.0));
  // Review 2026-11-26 M3: det_pow is binary exponentiation over IEEE
  // multiplies, never libm pow. Integer exponents only; others are NaN.
  CHECK(det_pow(3.0, 0.0) == 1.0);
  CHECK(det_pow(-2.0, 3.0) == -8.0);
  CHECK(det_pow(2.0, -2.0) == 0.25);
  CHECK(det_pow(10.0, 22.0) == 1e22);  // exact: 10^22 is representable
  CHECK(det_pow(1.5, 2000.0) == std::numeric_limits<double>::infinity());
  CHECK(det_pow(0.5, 1e300) == 0.0);
  CHECK(det_pow(-1.0, 1e300) == 1.0);
  CHECK(std::isnan(det_pow(2.0, 0.5)));
  CHECK(std::isnan(det_pow(2.0, std::numeric_limits<double>::quiet_NaN())));
  {  // pinned bit patterns: identical on every host (no libm involved)
    const double v = det_pow(1.0000001, 1000003.0);
    std::uint64_t bits = 0;
    std::memcpy(&bits, &v, sizeof bits);
    CHECK(bits == 0x3ff1aec80ae24feaULL);
  }
  CHECK(std::isnan(det_sqrt(-1.0)));

  const auto v2 = vec2_normalize({3.0, 4.0});
  CHECK(v2 && near(v2->x, 0.6) && near(v2->y, 0.8));
  CHECK(!vec2_normalize({0.0, 0.0}));
  const Vec3 a{1, 2, 3}, b{4, 5, 6};
  CHECK(near_vec(vec3_add(a, b), Vec3{5, 7, 9}));
  CHECK(near_vec(vec3_sub(b, a), Vec3{3, 3, 3}));
  CHECK(near_vec(vec3_cross(a, b), Vec3{-3, 6, -3}));
  CHECK(near(vec3_dot(a, b), 32.0));
  const auto v3 = vec3_normalize({0, 0, 5});
  CHECK(v3 && near_vec(*v3, Vec3{0, 0, 1}));
  const auto v4 = vec4_normalize({0, 0, 0, 4});
  CHECK(v4 && near(v4->w, 1.0));

  const auto ident = mat4_identity();
  const auto squared = mat4_multiply(ident, ident);
  CHECK(squared == ident);
  CHECK(near_vec(mat4_transform_point(ident, Vec3{7, 8, 9}), Vec3{7, 8, 9}));

  // 90 degrees around +Z maps +X to +Y.
  const double s = det_sqrt(0.5);
  const Quat q{0, 0, s, s};
  CHECK(near_vec(quat_rotate(q, Vec3{1, 0, 0}), Vec3{0, 1, 0}));
  CHECK(near(quat_normalize({0,0,0,0}).w, 1.0));

  // Pinned xorshift128+ vectors for seed 12345.
  XorShift128Plus rng{12345};
  const auto initial = rng.state();
  CHECK(initial[0] == 0x22118258a9d111a0ULL);
  CHECK(initial[1] == 0x346edce5f713f8edULL);
  constexpr std::uint64_t expected[4] = {
    0x6e9a8e001731e5c5ULL, 0xb6ea7861a20c7f4cULL,
    0x4843ea70bfa31bb6ULL, 0xe0809fd3bcca15d0ULL};
  for (std::uint64_t value : expected) CHECK(rng.next_u64() == value);
  auto replay = XorShift128Plus::from_state(initial[0], initial[1]);
  for (std::uint64_t value : expected) CHECK(replay.next_u64() == value);
  CHECK(replay.state() == rng.state());

  SimClock clock{20};
  CHECK(clock.tick() == 0 && clock.sim_now() == 0);
  CHECK(clock.dt_q16() == 3276);  // floor(65536 / 20)
  clock.advance(3);
  CHECK(clock.tick() == 3 && clock.sim_now() == 3);
  const auto defs = time_hostcall_defs(clock);
  CHECK(defs.size() == 3);
  for (const auto& def : defs) {
    CHECK(def.capabilities == capability_time);
    CHECK(def.serializable);
    CHECK(def.version == 1);
  }
  const std::array<std::int32_t, 0> no_args{};
  const auto tick_result = defs[0].handler(std::span<const std::int32_t>{no_args});
  CHECK(std::holds_alternative<std::int32_t>(tick_result));
  CHECK(std::get<std::int32_t>(tick_result) == 3);

  if (failures) { std::fprintf(stderr, "%d MUT-51 check(s) failed\n", failures); return 1; }
  std::puts("PASS: deterministic math vectors, seeded RNG replay, tick clock");
  return 0;
}
