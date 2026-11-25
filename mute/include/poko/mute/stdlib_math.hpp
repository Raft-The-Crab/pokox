#pragma once

#include "poko/mute/deterministic_math.hpp"
#include "poko/mute/hostcall.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <variant>
#include <vector>

namespace poko::mute {

// MUT-51: the approved deterministic stdlib math surface. Floating-point
// operations here are host-side and compiled with the same strict flags as
// poko_mute_math. No operation reads a wall clock or host environment.

struct Vec2 { double x{0.0}, y{0.0}; };
struct Vec3 { double x{0.0}, y{0.0}, z{0.0}; };
struct Vec4 { double x{0.0}, y{0.0}, z{0.0}, w{0.0}; };
struct Quat { double x{0.0}, y{0.0}, z{0.0}, w{1.0}; };

struct Mat4 {
  // Row-major, 16 doubles. Identity by default.
  std::array<double, 16> m{1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
  bool operator==(const Mat4&) const noexcept = default;
};

[[nodiscard]] double det_sqrt(double x) noexcept;
[[nodiscard]] double det_floor(double x) noexcept;
[[nodiscard]] double det_round(double x) noexcept;
[[nodiscard]] double det_clamp(double x, double lo, double hi) noexcept;
[[nodiscard]] double det_lerp(double a, double b, double t) noexcept;
[[nodiscard]] double det_pow(double base, double exponent) noexcept;

[[nodiscard]] Vec2 vec2_add(Vec2 a, Vec2 b) noexcept;
[[nodiscard]] Vec2 vec2_sub(Vec2 a, Vec2 b) noexcept;
[[nodiscard]] Vec2 vec2_scale(Vec2 a, double k) noexcept;
[[nodiscard]] Vec2 vec2_lerp(Vec2 a, Vec2 b, double t) noexcept;
[[nodiscard]] double vec2_dot(Vec2 a, Vec2 b) noexcept;
[[nodiscard]] double vec2_length_squared(Vec2 a) noexcept;
[[nodiscard]] std::optional<Vec2> vec2_normalize(Vec2 a) noexcept;

[[nodiscard]] Vec3 vec3_add(Vec3 a, Vec3 b) noexcept;
[[nodiscard]] Vec3 vec3_sub(Vec3 a, Vec3 b) noexcept;
[[nodiscard]] Vec3 vec3_scale(Vec3 a, double k) noexcept;
[[nodiscard]] Vec3 vec3_cross(Vec3 a, Vec3 b) noexcept;
[[nodiscard]] Vec3 vec3_lerp(Vec3 a, Vec3 b, double t) noexcept;
[[nodiscard]] double vec3_dot(Vec3 a, Vec3 b) noexcept;
[[nodiscard]] double vec3_length_squared(Vec3 a) noexcept;
[[nodiscard]] std::optional<Vec3> vec3_normalize(Vec3 a) noexcept;

[[nodiscard]] Vec4 vec4_add(Vec4 a, Vec4 b) noexcept;
[[nodiscard]] Vec4 vec4_scale(Vec4 a, double k) noexcept;
[[nodiscard]] double vec4_dot(Vec4 a, Vec4 b) noexcept;
[[nodiscard]] std::optional<Vec4> vec4_normalize(Vec4 a) noexcept;

[[nodiscard]] Mat4 mat4_identity() noexcept;
[[nodiscard]] Mat4 mat4_multiply(const Mat4& a, const Mat4& b) noexcept;
[[nodiscard]] Vec3 mat4_transform_point(const Mat4& m, Vec3 p) noexcept;

[[nodiscard]] Quat quat_normalize(Quat q) noexcept;
[[nodiscard]] Quat quat_multiply(Quat a, Quat b) noexcept;
[[nodiscard]] Vec3 quat_rotate(Quat q, Vec3 v) noexcept;

// Deterministic xorshift128+. State is fully serializable so a seeded replay
// can restore the exact stream. splitmix64 expands one seed into both words.
class XorShift128Plus {
 public:
  explicit XorShift128Plus(std::uint64_t seed) noexcept;
  [[nodiscard]] std::uint64_t next_u64() noexcept;
  [[nodiscard]] std::int32_t next_i32() noexcept;
  [[nodiscard]] std::array<std::uint64_t, 2> state() const noexcept { return {s0_, s1_}; }
  static XorShift128Plus from_state(std::uint64_t s0, std::uint64_t s1) noexcept;
  bool operator==(const XorShift128Plus&) const noexcept = default;

 private:
  std::uint64_t s0_{0}, s1_{0};
};

// Simulation time is derived only from integer ticks. No wall-clock source is
// exposed; wall-clock builtins are rejected by the determinism analyzer.
class SimClock {
 public:
  explicit SimClock(std::uint32_t sim_hz = 20) noexcept;
  void advance(std::uint64_t ticks = 1) noexcept;
  [[nodiscard]] std::uint64_t tick() const noexcept { return tick_; }
  [[nodiscard]] std::uint64_t sim_now() const noexcept { return tick_; }
  [[nodiscard]] std::uint32_t dt_q16() const noexcept { return dt_q16_; }
  [[nodiscard]] std::uint32_t sim_hz() const noexcept { return sim_hz_; }

 private:
  std::uint32_t sim_hz_{20};
  std::uint32_t dt_q16_{0};
  std::uint64_t tick_{0};
};

enum class TimeHostcall : std::uint32_t {
  tick = 201,
  dt_q16 = 202,
  sim_now = 203
};

// Integer-only hostcall definitions. All require the Time capability and are
// serializable; wall-clock reads are deliberately absent.
[[nodiscard]] std::vector<HostcallDef> time_hostcall_defs(SimClock& clock);

}  // namespace poko::mute
