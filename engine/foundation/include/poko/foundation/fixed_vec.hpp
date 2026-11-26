#pragma once

#include <algorithm>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <limits>
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

namespace detail {

inline constexpr std::int64_t kFixedRawMax = std::numeric_limits<std::int32_t>::max();
inline constexpr std::int64_t kFixedRawMin = std::numeric_limits<std::int32_t>::min();

constexpr Fixed saturate_raw64(std::int64_t r) noexcept {
  return Fixed::from_raw(static_cast<std::int32_t>(
      r > kFixedRawMax ? kFixedRawMax : (r < kFixedRawMin ? kFixedRawMin : r)));
}

// floor(sqrt(n)) for the full uint64 domain, digit-by-digit (fixed 32
// rounds, no division, no float).
constexpr std::uint64_t isqrt_u64(std::uint64_t n) noexcept {
  std::uint64_t root = 0;
  std::uint64_t bit = std::uint64_t{1} << 62;
  while (bit > n) bit >>= 2;
  while (bit != 0) {
    if (n >= root + bit) {
      n -= root + bit;
      root = (root >> 1) + bit;
    } else {
      root >>= 1;
    }
    bit >>= 2;
  }
  return root;
}

// Exact sum of squared raw components (Q32.32). Each square is < 2^62, so
// three fit in uint64 without overflow.
constexpr std::uint64_t raw_length_sq(std::int64_t x, std::int64_t y,
                                      std::int64_t z) noexcept {
  return static_cast<std::uint64_t>(x * x) + static_cast<std::uint64_t>(y * y) +
         static_cast<std::uint64_t>(z * z);
}

}  // namespace detail

// ENG-62 narrowphase primitives. dot/lengthSquared accumulate in 64 bits:
// each product is truncated toward zero exactly like Fixed multiply, the
// three are summed in int64 (no intermediate wrap or saturation) and the
// total saturates ONCE to the Q16.16 range. Results are bit-identical to
// the plain Fixed expression whenever that expression did not overflow;
// out of range they clamp instead of wrapping (lengthSquared(150,150,0)
// used to wrap negative). cross stays component-wise Fixed.
constexpr Fixed dot(FixedVec3 a, FixedVec3 b) noexcept {
  const auto term = [](Fixed p, Fixed q) {
    return static_cast<std::int64_t>(p.raw()) * q.raw() / Fixed::kScale;
  };
  return detail::saturate_raw64(term(a.x, b.x) + term(a.y, b.y) + term(a.z, b.z));
}
constexpr FixedVec3 cross(FixedVec3 a, FixedVec3 b) noexcept {
  return FixedVec3{a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x};
}
// Saturates to Fixed max for |v| above ~181 units; use length() for the
// exact magnitude.
constexpr Fixed lengthSquared(FixedVec3 v) noexcept { return dot(v, v); }

// Euclidean length, floor-exact to 1 LSB over the whole FixedVec3 domain
// (64-bit sum of squares + integer sqrt). Saturates only when the true
// length exceeds the Q16.16 range (|v| >= 32768).
constexpr Fixed length(FixedVec3 v) noexcept {
  const std::uint64_t root =
      detail::isqrt_u64(detail::raw_length_sq(v.x.raw(), v.y.raw(), v.z.raw()));
  return detail::saturate_raw64(static_cast<std::int64_t>(root));
}

// Unit vector along v, or nullopt when v is the zero vector (callers
// handle the degenerate direction explicitly — there is no NaN). Valid for
// every nonzero input: components are first scaled up by a power of two
// (direction-preserving, exact) so tiny vectors keep full precision, then
// divided by the exact 64-bit length. Each result component is within
// 2 LSB of the true unit vector.
constexpr std::optional<FixedVec3> normalized(FixedVec3 v) noexcept {
  std::int64_t c[3] = {v.x.raw(), v.y.raw(), v.z.raw()};
  std::int64_t m = 0;
  for (const auto r : c) m = std::max(m, r < 0 ? -r : r);
  if (m == 0) return std::nullopt;
  // Largest k with m << k <= 2^31 keeps each square <= 2^62.
  int k = 0;
  while ((m << (k + 1)) <= (std::int64_t{1} << 31)) ++k;
  for (auto& r : c) r *= (std::int64_t{1} << k);
  const std::uint64_t len =
      detail::isqrt_u64(detail::raw_length_sq(c[0], c[1], c[2]));
  if (len == 0) return std::nullopt;
  const auto unit = [&](std::int64_t r) {
    return Fixed::from_raw(static_cast<std::int32_t>(
        r * Fixed::kScale / static_cast<std::int64_t>(len)));
  };
  return FixedVec3{unit(c[0]), unit(c[1]), unit(c[2])};
}

}  // namespace poko::math
