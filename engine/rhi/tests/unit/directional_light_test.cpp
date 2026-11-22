#include "poko/rhi/directional_light.hpp"
#include <cmath>
#include <cstdio>
#include <limits>

int main() {
  using poko::rhi::DirectionalLight;
  DirectionalLight light;
  auto old = light.data();
  const auto check = [](bool value, const char* message) {
    if (!value) std::fprintf(stderr, "FAIL: %s\n", message);
    return value;
  };
  if (!check(std::abs(std::hypot(old[0], old[1], old[2]) - 1.f) < 0.00001f, "default normalized") ||
      !check(old[3] == 0.25f, "ambient") ||
      !check(!light.set_direction(0, 0, 0) && light.data() == old, "zero rejected, unchanged") ||
      !check(!light.set_direction(std::numeric_limits<float>::infinity(), 0, 1) && light.data() == old, "infinity rejected") ||
      !check(!light.set_direction(0, std::numeric_limits<float>::quiet_NaN(), 1) && light.data() == old, "NaN rejected") ||
      !check(light.set_direction(3, 4, 0), "valid direction") ||
      !check(std::abs(light.data()[0] - 0.6f) < 0.00001f && std::abs(light.data()[1] - 0.8f) < 0.00001f && light.data()[3] == old[3], "normalized and ambient preserved") ||
      !check(light.set_direction(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), 0) && std::abs(light.data()[0] - 0.70710678f) < 0.00001f, "large input") ||
      !check(light.set_direction(std::numeric_limits<float>::denorm_min(), 0, 0) && light.data()[0] == 1.f, "tiny input")) return 1;
  std::puts("PASS: directional light normalization and invalid input");
  return 0;
}
