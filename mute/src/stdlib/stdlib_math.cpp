#include "poko/mute/stdlib_math.hpp"

#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>

namespace poko::mute {
namespace {
constexpr double kQ16 = 65536.0;
constexpr double kEpsilon = 1e-12;

std::uint64_t splitmix64(std::uint64_t& state) noexcept {
  state += 0x9E3779B97F4A7C15ULL;
  std::uint64_t z = state;
  z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
  z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
  return z ^ (z >> 31);
}
}  // namespace

double det_sqrt(double x) noexcept { return x < 0.0 ? std::numeric_limits<double>::quiet_NaN() : std::sqrt(x); }
double det_floor(double x) noexcept { return std::floor(x); }
double det_round(double x) noexcept { return std::round(x); }
double det_clamp(double x, double lo, double hi) noexcept { return std::clamp(x, lo, hi); }
double det_lerp(double a, double b, double t) noexcept { return a + (b - a) * t; }
double det_pow(double base, double exponent) noexcept { return std::pow(base, exponent); }

Vec2 vec2_add(Vec2 a, Vec2 b) noexcept { return {a.x + b.x, a.y + b.y}; }
Vec2 vec2_sub(Vec2 a, Vec2 b) noexcept { return {a.x - b.x, a.y - b.y}; }
Vec2 vec2_scale(Vec2 a, double k) noexcept { return {a.x * k, a.y * k}; }
Vec2 vec2_lerp(Vec2 a, Vec2 b, double t) noexcept { return {det_lerp(a.x, b.x, t), det_lerp(a.y, b.y, t)}; }
double vec2_dot(Vec2 a, Vec2 b) noexcept { return a.x * b.x + a.y * b.y; }
double vec2_length_squared(Vec2 a) noexcept { return vec2_dot(a, a); }
std::optional<Vec2> vec2_normalize(Vec2 a) noexcept {
  const auto len2 = vec2_length_squared(a);
  if (len2 <= kEpsilon) return std::nullopt;
  const auto inv = 1.0 / det_sqrt(len2);
  return Vec2{a.x * inv, a.y * inv};
}

Vec3 vec3_add(Vec3 a, Vec3 b) noexcept { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
Vec3 vec3_sub(Vec3 a, Vec3 b) noexcept { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
Vec3 vec3_scale(Vec3 a, double k) noexcept { return {a.x * k, a.y * k, a.z * k}; }
Vec3 vec3_cross(Vec3 a, Vec3 b) noexcept {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
Vec3 vec3_lerp(Vec3 a, Vec3 b, double t) noexcept {
  return {det_lerp(a.x, b.x, t), det_lerp(a.y, b.y, t), det_lerp(a.z, b.z, t)};
}
double vec3_dot(Vec3 a, Vec3 b) noexcept { return a.x * b.x + a.y * b.y + a.z * b.z; }
double vec3_length_squared(Vec3 a) noexcept { return vec3_dot(a, a); }
std::optional<Vec3> vec3_normalize(Vec3 a) noexcept {
  const auto len2 = vec3_length_squared(a);
  if (len2 <= kEpsilon) return std::nullopt;
  const auto inv = 1.0 / det_sqrt(len2);
  return Vec3{a.x * inv, a.y * inv, a.z * inv};
}

Vec4 vec4_add(Vec4 a, Vec4 b) noexcept { return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
Vec4 vec4_scale(Vec4 a, double k) noexcept { return {a.x * k, a.y * k, a.z * k, a.w * k}; }
double vec4_dot(Vec4 a, Vec4 b) noexcept { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
std::optional<Vec4> vec4_normalize(Vec4 a) noexcept {
  const auto len2 = vec4_dot(a, a);
  if (len2 <= kEpsilon) return std::nullopt;
  const auto inv = 1.0 / det_sqrt(len2);
  return Vec4{a.x * inv, a.y * inv, a.z * inv, a.w * inv};
}

Mat4 mat4_identity() noexcept { return {}; }
Mat4 mat4_multiply(const Mat4& a, const Mat4& b) noexcept {
  Mat4 out;
  for (std::size_t r = 0; r < 4; ++r) {
    for (std::size_t c = 0; c < 4; ++c) {
      double sum = 0.0;
      for (std::size_t k = 0; k < 4; ++k) sum += a.m[r * 4 + k] * b.m[k * 4 + c];
      out.m[r * 4 + c] = sum;
    }
  }
  return out;
}
Vec3 mat4_transform_point(const Mat4& m, Vec3 p) noexcept {
  const double x = m.m[0] * p.x + m.m[1] * p.y + m.m[2] * p.z + m.m[3];
  const double y = m.m[4] * p.x + m.m[5] * p.y + m.m[6] * p.z + m.m[7];
  const double z = m.m[8] * p.x + m.m[9] * p.y + m.m[10] * p.z + m.m[11];
  return {x, y, z};
}

Quat quat_normalize(Quat q) noexcept {
  const auto len2 = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
  if (len2 <= kEpsilon) return {0, 0, 0, 1};
  const auto inv = 1.0 / det_sqrt(len2);
  return {q.x * inv, q.y * inv, q.z * inv, q.w * inv};
}
Quat quat_multiply(Quat a, Quat b) noexcept {
  return {
    a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
    a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
    a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w,
    a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z};
}
Vec3 quat_rotate(Quat q, Vec3 v) noexcept {
  q = quat_normalize(q);
  const Vec3 u{q.x, q.y, q.z};
  const Vec3 t = vec3_scale(vec3_cross(u, v), 2.0);
  const Vec3 wt = vec3_scale(t, q.w);
  const Vec3 ut = vec3_cross(u, t);
  return vec3_add(vec3_add(v, wt), ut);
}

XorShift128Plus::XorShift128Plus(std::uint64_t seed) noexcept {
  std::uint64_t state = seed;
  s0_ = splitmix64(state);
  s1_ = splitmix64(state);
  if ((s0_ | s1_) == 0) s0_ = 1;
}
std::uint64_t XorShift128Plus::next_u64() noexcept {
  std::uint64_t x = s0_;
  const std::uint64_t y = s1_;
  s0_ = y;
  x ^= x << 23;
  x ^= x >> 17;
  x ^= y;
  x ^= y >> 26;
  s1_ = x;
  return x + y;
}
std::int32_t XorShift128Plus::next_i32() noexcept {
  return static_cast<std::int32_t>(static_cast<std::uint32_t>(next_u64() >> 32));
}
XorShift128Plus XorShift128Plus::from_state(std::uint64_t s0, std::uint64_t s1) noexcept {
  XorShift128Plus rng{0};
  rng.s0_ = s0;
  rng.s1_ = s1;
  return rng;
}

SimClock::SimClock(std::uint32_t sim_hz) noexcept
    : sim_hz_(sim_hz == 0 ? 1 : sim_hz),
      dt_q16_(static_cast<std::uint32_t>(kQ16 / static_cast<double>(sim_hz_))) {}
void SimClock::advance(std::uint64_t ticks) noexcept { tick_ += ticks; }

std::vector<HostcallDef> time_hostcall_defs(SimClock& clock) {
  std::vector<HostcallDef> defs;
  defs.reserve(3);
  HostcallDef tick;
  tick.id = static_cast<std::uint32_t>(TimeHostcall::tick);
  tick.result = HostType::integer;
  tick.capabilities = capability_time;
  tick.serializable = true;
  tick.handler = [&clock](HostcallArgs) { return HostcallResult{static_cast<std::int32_t>(clock.tick())}; };
  defs.push_back(std::move(tick));
  HostcallDef dt;
  dt.id = static_cast<std::uint32_t>(TimeHostcall::dt_q16);
  dt.result = HostType::integer;
  dt.capabilities = capability_time;
  dt.serializable = true;
  dt.handler = [&clock](HostcallArgs) { return HostcallResult{static_cast<std::int32_t>(clock.dt_q16())}; };
  defs.push_back(std::move(dt));
  HostcallDef now;
  now.id = static_cast<std::uint32_t>(TimeHostcall::sim_now);
  now.result = HostType::integer;
  now.capabilities = capability_time;
  now.serializable = true;
  now.handler = [&clock](HostcallArgs) { return HostcallResult{static_cast<std::int32_t>(clock.sim_now())}; };
  defs.push_back(std::move(now));
  return defs;
}

}  // namespace poko::mute
