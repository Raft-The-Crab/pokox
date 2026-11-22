#pragma once
#include <array>
#include <cstdint>

namespace poko::render {

// ENG-20: minimal orbit camera — yaw/pitch/distance around a target,
// perspective projection. Produces a column-major mat4 suitable for a
// std140 `mat4` uniform in GLSL/SPIR-V. Deterministic, dependency-free.
class OrbitCamera {
 public:
  OrbitCamera() = default;
  // eye = target + distance * (cos(pitch)sin(yaw), sin(pitch), cos(pitch)cos(yaw))
  void orbit(float delta_yaw, float delta_pitch) noexcept;
  void zoom(float wheel_detents) noexcept;  // wheel >0 moves closer
  void set_aspect(float aspect) noexcept { aspect_ = aspect > 0.f ? aspect : 1.f; }
  // Drawable pixel dimensions determine projection; preserve the previous
  // aspect while minimized or otherwise without a drawable area.
  void set_viewport(std::uint32_t width, std::uint32_t height) noexcept {
    if (width && height) set_aspect(static_cast<float>(width) / static_cast<float>(height));
  }
  // Column-major projection * view with Vulkan [0, 1] depth, ready for a mat4 uniform.
  [[nodiscard]] std::array<float, 16> view_proj() const noexcept;
  [[nodiscard]] float yaw() const noexcept { return yaw_; }
  [[nodiscard]] float pitch() const noexcept { return pitch_; }
  [[nodiscard]] float distance() const noexcept { return distance_; }

 private:
  float yaw_ = 0.6f;          // radians
  float pitch_ = 0.35f;       // radians, clamped to avoid pole flip
  float distance_ = 2.4f;     // eye-to-target distance
  float aspect_ = 1.f;
  static constexpr float kFovY = 0.9f;    // ~52 deg vertical fov
  static constexpr float kNear = 0.1f;
  static constexpr float kFar = 100.f;
  static constexpr float kMinPitch = -1.45f, kMaxPitch = 1.45f;
  static constexpr float kMinDist = 0.5f, kMaxDist = 20.f;
};

}  // namespace poko::render
