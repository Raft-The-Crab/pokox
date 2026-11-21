#include "poko/render/camera.hpp"

#include <algorithm>
#include <cmath>

namespace poko::render {
namespace {
constexpr float kPi = 3.14159265358979323846f;

// Column-major 4x4 helpers; m[col*4+row].
void perspective(std::array<float, 16>& m, float fovy, float aspect,
                 float zn, float zf) {
  const float f = 1.f / std::tan(fovy * 0.5f);
  m.fill(0.f);
  m[0] = f / aspect;
  m[5] = f;
  m[10] = (zf + zn) / (zn - zf);
  m[11] = -1.f;
  m[14] = (2.f * zf * zn) / (zn - zf);
}
void look_at(std::array<float, 16>& m, const float eye[3], const float target[3],
             const float up[3]) {
  float f[3] = {target[0] - eye[0], target[1] - eye[1], target[2] - eye[2]};
  const float fl = std::sqrt(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
  f[0] /= fl; f[1] /= fl; f[2] /= fl;
  float s[3] = {f[1] * up[2] - f[2] * up[1], f[2] * up[0] - f[0] * up[2],
                f[0] * up[1] - f[1] * up[0]};
  const float sl = std::sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
  s[0] /= sl; s[1] /= sl; s[2] /= sl;
  const float u[3] = {s[1] * f[2] - s[2] * f[1], s[2] * f[0] - s[0] * f[2],
                      s[0] * f[1] - s[1] * f[0]};
  m = {s[0], u[0], -f[0], 0.f,
       s[1], u[1], -f[1], 0.f,
       s[2], u[2], -f[2], 0.f,
       -(s[0] * eye[0] + s[1] * eye[1] + s[2] * eye[2]),
       -(u[0] * eye[0] + u[1] * eye[1] + u[2] * eye[2]),
       (f[0] * eye[0] + f[1] * eye[1] + f[2] * eye[2]), 0.f};
}
void multiply(std::array<float, 16>& out, const std::array<float, 16>& a,
              const std::array<float, 16>& b) {
  // out = a * b, column-major.
  for (int c = 0; c < 4; ++c)
    for (int r = 0; r < 4; ++r) {
      float sum = 0.f;
      for (int k = 0; k < 4; ++k) sum += a[k * 4 + r] * b[c * 4 + k];
      out[c * 4 + r] = sum;
    }
}
}  // namespace

void OrbitCamera::orbit(float delta_yaw, float delta_pitch) noexcept {
  yaw_ += delta_yaw;
  pitch_ = std::clamp(pitch_ + delta_pitch, kMinPitch, kMaxPitch);
}
void OrbitCamera::zoom(float wheel_detents) noexcept {
  // Wheel up (positive) dollies in; scale is exponential for smooth feel.
  distance_ = std::clamp(distance_ * std::pow(0.9f, wheel_detents), kMinDist, kMaxDist);
}

std::array<float, 16> OrbitCamera::view_proj() const noexcept {
  const float cp = std::cos(pitch_), sp = std::sin(pitch_);
  const float cy = std::cos(yaw_), sy = std::sin(yaw_);
  const float eye[3] = {distance_ * cp * sy, distance_ * sp, distance_ * cp * cy};
  const float target[3] = {0.f, 0.f, 0.f};
  const float up[3] = {0.f, 1.f, 0.f};
  std::array<float, 16> proj{}, view{};
  perspective(proj, kFovY, aspect_, kNear, kFar);
  look_at(view, eye, target, up);
  std::array<float, 16> out{};
  multiply(out, proj, view);
  return out;
}

}  // namespace poko::render
