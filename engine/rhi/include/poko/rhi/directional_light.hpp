#pragma once
#include <array>
#include <cmath>

namespace poko::rhi {
// World-space direction from a surface toward the light, plus ambient level.
// The four floats match the fragment shader's std140 vec4 exactly.
class DirectionalLight final {
 public:
  [[nodiscard]] bool set_direction(float x, float y, float z) noexcept {
    if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z)) return false;
    const double length = std::hypot(static_cast<double>(x), static_cast<double>(y), static_cast<double>(z));
    if (length == 0.0 || !std::isfinite(length)) return false;
    data_[0] = static_cast<float>(x / length);
    data_[1] = static_cast<float>(y / length);
    data_[2] = static_cast<float>(z / length);
    return true;
  }
  [[nodiscard]] const std::array<float, 4>& data() const noexcept { return data_; }
 private:
  std::array<float, 4> data_{0.39801488f, 0.69652603f, 0.5970223f, 0.25f};
};
}  // namespace poko::rhi
