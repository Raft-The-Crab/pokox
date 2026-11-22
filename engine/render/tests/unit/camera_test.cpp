#include "poko/render/camera.hpp"

#include <array>
#include <cmath>
#include <cstdio>

namespace {
int failures = 0;
#define CHECK(cond) do { if (!(cond)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #cond); ++failures; \
} } while (0)
bool near(float a, float b, float eps = 0.0001f) { return std::abs(a - b) < eps; }
std::array<float, 4> transform(const std::array<float, 16>& m,
                               const std::array<float, 4>& p) {
  std::array<float, 4> result{};
  for (int row = 0; row < 4; ++row)
    for (int col = 0; col < 4; ++col) result[row] += m[col * 4 + row] * p[col];
  return result;
}
}

int main() {
  poko::render::OrbitCamera camera;
  auto matrix = camera.view_proj();
  auto origin = transform(matrix, {0.f, 0.f, 0.f, 1.f});
  CHECK(near(origin[0], 0.f) && near(origin[1], 0.f));
  CHECK(origin[3] > 0.f && origin[2] >= 0.f && origin[2] <= origin[3]);

  // Points on the eye-to-target axis at the stated near/far distances map to
  // Vulkan's [0, 1] NDC depth range, including the translation's homogeneous w.
  const float cp = std::cos(camera.pitch());
  const std::array<float, 3> dir{cp * std::sin(camera.yaw()),
      std::sin(camera.pitch()), cp * std::cos(camera.yaw())};
  const auto at_distance = [&](float d) {
    const float factor = camera.distance() - d;
    return transform(matrix, {factor * dir[0], factor * dir[1], factor * dir[2], 1.f});
  };
  const auto near_point = at_distance(0.1f);
  const auto far_point = at_distance(100.f);
  CHECK(near(near_point[2] / near_point[3], 0.f));
  CHECK(near(far_point[2] / far_point[3], 1.f));
  camera.set_aspect(2.f);
  auto wide = camera.view_proj();
  CHECK(near(wide[0] * 2.f, matrix[0]));
  camera.set_viewport(1280, 720);
  const auto viewport = camera.view_proj();
  CHECK(near(viewport[0] * (1280.f / 720.f), matrix[0]));
  camera.set_viewport(0, 0);  // minimized: keep the last usable projection
  CHECK(near(camera.view_proj()[0], viewport[0]));
  camera.orbit(0.2f, 100.f);
  CHECK(camera.pitch() < 1.57f);
  camera.zoom(100.f);
  CHECK(camera.distance() >= 0.5f);
  if (failures) return 1;
  std::puts("PASS: camera target, Vulkan depth, aspect, orbit and zoom");
  return 0;
}
