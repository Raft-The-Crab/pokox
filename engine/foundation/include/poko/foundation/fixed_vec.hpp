#pragma once

#include <compare>
#include <cstddef>
#include <optional>

#include "poko/foundation/fixed.hpp"

namespace poko::math {

// ENG-61: fixed-point 3-vector for the deterministic sim physics path
// (spec 21 "Math library", Q16.16 precision path). Pure Fixed arithmetic —
// no float, no libm — so results are bit-identical on x64 and arm64.
// Component layout is public and POD-like; this is a value type, not a
// handle. Vec2/4, Mat4 and Quat land with their first consumers.
struct FixedVec3 {
  Fixed x;
  Fixed y;
  Fixed z;

  constexpr FixedVec3() noexcept = default;
  constexpr FixedVec3(Fixed x, Fixed y, Fixed z) noexcept : x(x), y(y), z(z) {}

  static constexpr FixedVec3 zero() noexcept { return FixedVec3{}; }
  static constexpr FixedVec3 one() noexcept {
    return FixedVec3{Fixed::one(), Fixed::one(), Fixed::one()};
  }

  constexpr Fixed& operator[](std::size_t i) noexcept {
    return i == 0 ? x : (i == 1 ? y : z);
  }
  constexpr const Fixed& operator[](std::size_t i) const noexcept {
    return i == 0 ? x : (i == 1 ? y : z);
  }

  constexpr FixedVec3 operator-() const noexcept {
    return FixedVec3{-x, -y, -z};
  }
  constexpr FixedVec3& operator+=(FixedVec3 o) noexcept {
    x += o.x; y += o.y; z += o.z;
    return *this;
  }
  constexpr FixedVec3& operator-=(FixedVec3 o) noexcept {
    x -= o.x; y -= o.y; z -= o.z;
    return *this;
  }
  constexpr FixedVec3& operator*=(Fixed s) noexcept {
    x = x * s; y = y * s; z = z * s;
    return *this;
  }

  constexpr bool operator==(FixedVec3 o) const noexcept {
    return x == o.x && y == o.y && z == o.z;
  }
  constexpr auto operator<=>(FixedVec3 o) const noexcept {
    if (auto c = x <=> o.x; c != 0) return c;
    if (auto c = y <=> o.y; c != 0) return c;
    return z <=> o.z;
  }
};

constexpr FixedVec3 operator+(FixedVec3 a, FixedVec3 b) noexcept {
  return FixedVec3{a.x + b.x, a.y + b.y, a.z + b.z};
}
constexpr FixedVec3 operator-(FixedVec3 a, FixedVec3 b) noexcept {
  return FixedVec3{a.x - b.x, a.y - b.y, a.z - b.z};
}
constexpr FixedVec3 operator*(FixedVec3 v, Fixed s) noexcept {
  return FixedVec3{v.x * s, v.y * s, v.z * s};
}
constexpr FixedVec3 operator*(Fixed s, FixedVec3 v) noexcept { return v * s; }

// Component-wise minimum/maximum — used to normalize bounds.
constexpr FixedVec3 min(FixedVec3 a, FixedVec3 b) noexcept {
  return FixedVec3{a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y,
                   a.z < b.z ? a.z : b.z};
}
constexpr FixedVec3 max(FixedVec3 a, FixedVec3 b) noexcept {
  return FixedVec3{a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y,
                   a.z > b.z ? a.z : b.z};
}

// ENG-62 narrowphase primitives. dot/cross are exact Q16.16 Fixed ops;
// lengthSquared stays in Fixed (dot of a vector with itself).
constexpr Fixed dot(FixedVec3 a, FixedVec3 b) noexcept {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
constexpr FixedVec3 cross(FixedVec3 a, FixedVec3 b) noexcept {
  return FixedVec3{a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x};
}
constexpr Fixed lengthSquared(FixedVec3 v) noexcept { return dot(v, v); }
// Unit vector along v, or nullopt when v is the zero vector (callers
// handle the degenerate direction explicitly — there is no NaN).
constexpr std::optional<FixedVec3> normalized(FixedVec3 v) noexcept {
  const Fixed len_sq = lengthSquared(v);
  if (len_sq.is_zero()) return std::nullopt;
  const auto inv_len = divide(Fixed::one(), sqrt(len_sq));
  if (!inv_len.has_value()) return std::nullopt;
  return FixedVec3{v.x * inv_len.value(), v.y * inv_len.value(),
                   v.z * inv_len.value()};
}

}  // namespace poko::math
