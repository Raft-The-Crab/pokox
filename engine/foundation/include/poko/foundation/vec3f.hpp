#pragma once

#include <cmath>

namespace poko::math {

// ENG-65: float 3-vector for the VISUAL physics path only (spec 24
// "Two solvers, one contract" — visual physics is f32, client-only,
// trusted cosmetic state). This type must never appear in sim physics
// code: the sim path is Q16.16 Fixed only (spec 24 determinism rule 1).
// Value type, POD-like; not deterministic across platforms by design.
struct Vec3f {
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;

  constexpr Vec3f() noexcept = default;
  constexpr Vec3f(float x, float y, float z) noexcept : x(x), y(y), z(z) {}

  static constexpr Vec3f zero() noexcept { return Vec3f{}; }
  static constexpr Vec3f one() noexcept { return Vec3f{1.0f, 1.0f, 1.0f}; }

  constexpr Vec3f operator-() const noexcept { return Vec3f{-x, -y, -z}; }
  constexpr Vec3f& operator+=(Vec3f o) noexcept {
    x += o.x; y += o.y; z += o.z;
    return *this;
  }
  constexpr Vec3f& operator-=(Vec3f o) noexcept {
    x -= o.x; y -= o.y; z -= o.z;
    return *this;
  }
  constexpr Vec3f& operator*=(float s) noexcept {
    x *= s; y *= s; z *= s;
    return *this;
  }
  constexpr Vec3f& operator/=(float s) noexcept {
    x /= s; y /= s; z /= s;
    return *this;
  }
};

constexpr Vec3f operator+(Vec3f a, Vec3f b) noexcept {
  return Vec3f{a.x + b.x, a.y + b.y, a.z + b.z};
}
constexpr Vec3f operator-(Vec3f a, Vec3f b) noexcept {
  return Vec3f{a.x - b.x, a.y - b.y, a.z - b.z};
}
constexpr Vec3f operator*(Vec3f v, float s) noexcept {
  return Vec3f{v.x * s, v.y * s, v.z * s};
}
constexpr Vec3f operator*(float s, Vec3f v) noexcept { return v * s; }
constexpr Vec3f operator/(Vec3f v, float s) noexcept {
  return Vec3f{v.x / s, v.y / s, v.z / s};
}

constexpr float dot(Vec3f a, Vec3f b) noexcept {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
constexpr Vec3f cross(Vec3f a, Vec3f b) noexcept {
  return Vec3f{a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x};
}
inline float length(Vec3f v) noexcept { return std::sqrt(dot(v, v)); }
inline float lengthSquared(Vec3f v) noexcept { return dot(v, v); }
// Unit vector along v, or Vec3f::zero() when v is (near-)zero — callers
// handle the degenerate direction explicitly.
inline Vec3f normalized(Vec3f v) noexcept {
  const float len = length(v);
  return len > 1e-12f ? v / len : Vec3f::zero();
}

}  // namespace poko::math
