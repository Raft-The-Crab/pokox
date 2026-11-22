// Experimental Android OpenGL ES 3.2 clear probe: EGL pbuffer surface, N
// clear frames, then a center-pixel readback compared against the same linear
// clear color used by the desktop fallback demo ({0.035,0.12,0.28,1}).
// --select additionally routes the same clear through ClearBackendSelection
// with a deliberately failing primary, exercising the Vulkan->ES fallback
// contract on the device (the primary failure is simulated, not a real
// Vulkan attempt).
// Usage: pokox_gles_clear [--frames N] [--no-verify] [--select]
#include "poko/rhi/device/clear_backend_selection.hpp"
#include "poko/rhi/device/opengles_clear_backend.hpp"
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
namespace {
constexpr std::array<float, 4> kClear{0.035f, 0.12f, 0.28f, 1.0f};
int linear_to_srgb_byte(float linear) {
  const float encoded = linear <= 0.0031308f
      ? linear * 12.92f
      : 1.055f * std::pow(linear, 1.0f / 2.4f) - 0.055f;
  return static_cast<int>(std::lround(encoded * 255.0f));
}
// Stands in for a primary backend (e.g. Vulkan) that fails to initialize.
class FailingPrimaryBackend final : public poko::rhi::ClearBackend {
 public:
  [[nodiscard]] poko::rhi::RenderError initialize() noexcept override {
    return poko::rhi::RenderError::backend_failure;
  }
  [[nodiscard]] poko::rhi::RenderError clear_and_present(const std::array<float, 4>&) noexcept override {
    return poko::rhi::RenderError::not_initialized;
  }
  [[nodiscard]] bool shutdown() noexcept override { return true; }
};
int report_pixel(const std::array<float, 4>& pixel, bool srgb, bool verify) {
  std::printf("center pixel rgba = %.4f %.4f %.4f %.4f\n",
              pixel[0], pixel[1], pixel[2], pixel[3]);
  if (!verify) return 0;
  const std::array<int, 4> expected{
      srgb ? linear_to_srgb_byte(kClear[0]) : static_cast<int>(std::lround(kClear[0] * 255.0f)),
      srgb ? linear_to_srgb_byte(kClear[1]) : static_cast<int>(std::lround(kClear[1] * 255.0f)),
      srgb ? linear_to_srgb_byte(kClear[2]) : static_cast<int>(std::lround(kClear[2] * 255.0f)),
      255};
  const std::array<int, 4> actual{static_cast<int>(std::lround(pixel[0] * 255.0f)),
                                 static_cast<int>(std::lround(pixel[1] * 255.0f)),
                                 static_cast<int>(std::lround(pixel[2] * 255.0f)),
                                 static_cast<int>(std::lround(pixel[3] * 255.0f))};
  bool ok = true;
  for (int i = 0; i < 4; ++i) ok = ok && std::abs(actual[i] - expected[i]) <= 2;
  std::printf("expected %s bytes %d %d %d %d; %s\n", srgb ? "sRGB" : "linear",
              expected[0], expected[1], expected[2], expected[3], ok ? "PASS" : "FAIL");
  return ok ? 0 : 1;
}
}
int main(int argc, char** argv) {
  int frames = 60;
  bool verify = true, select = false;
  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];
    if (arg == "--no-verify") verify = false;
    else if (arg == "--select") select = true;
    else if (arg == "--frames" && i + 1 < argc) frames = std::atoi(argv[++i]);
    else { std::fprintf(stderr, "usage: pokox_gles_clear [--frames N] [--no-verify] [--select]\n"); return 64; }
  }
  if (frames < 1) return 64;
  if (select) {
    FailingPrimaryBackend primary;
    poko::rhi::OpenGLESClearBackend fallback;
    poko::rhi::ClearBackendSelection selection(primary, fallback);
    const auto start = selection.start();
    std::printf("selection status=%d selected=%d primary_error=%d fallback_error=%d\n",
                static_cast<int>(start.status), static_cast<int>(start.selected),
                static_cast<int>(start.primary_error), static_cast<int>(start.fallback_error));
    if (start.status != poko::rhi::StartStatus::success ||
        start.selected != poko::rhi::SelectedBackend::fallback) {
      std::fprintf(stderr, "fallback selection failed\n");
      return 3;
    }
    for (int i = 0; i < frames; ++i) {
      if (selection.clear_and_present(kClear) != poko::rhi::RenderError::none) {
        std::fprintf(stderr, "clear_and_present failed at frame %d\n", i);
        (void)selection.shutdown();
        return 3;
      }
    }
    std::array<float, 4> pixel{};
    if (!fallback.read_center_pixel(pixel)) {
      std::fprintf(stderr, "readback failed\n");
      (void)selection.shutdown();
      return 3;
    }
    const bool srgb = fallback.framebuffer_is_srgb();
    const bool cleaned = selection.shutdown();
    std::printf("submitted %d clear frames via fallback; %s\n", frames,
                cleaned ? "shutdown ok" : "shutdown FAILED");
    if (!cleaned) return 3;
    return report_pixel(pixel, srgb, verify);
  }
  poko::rhi::OpenGLClearESRenderer renderer;
  const auto init = renderer.initialize(320, 240);
  if (init != poko::rhi::RenderError::none) {
    std::fprintf(stderr, "initialize failed: %d\n", static_cast<int>(init));
    return 3;
  }
  for (int i = 0; i < frames; ++i) {
    if (renderer.clear_and_present(kClear) != poko::rhi::RenderError::none) {
      std::fprintf(stderr, "clear_and_present failed at frame %d\n", i);
      renderer.shutdown();
      return 3;
    }
  }
  std::array<float, 4> pixel{};
  if (!renderer.read_center_pixel(pixel)) {
    std::fprintf(stderr, "readback failed\n");
    renderer.shutdown();
    return 3;
  }
  const bool srgb = renderer.framebuffer_is_srgb();
  renderer.shutdown();
  std::printf("submitted %d clear frames; ", frames);
  return report_pixel(pixel, srgb, verify);
}
