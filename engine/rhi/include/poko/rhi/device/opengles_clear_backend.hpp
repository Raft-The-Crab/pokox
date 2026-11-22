#pragma once
#include "poko/rhi/device/clear_backend_selection.hpp"
#include "poko/rhi/device/opengles_clear_renderer.hpp"
#include <array>
#include <cstdint>
namespace poko::rhi {
// Android OpenGL ES 3.2 backend behind the shared ClearBackend contract.
// Offscreen EGL pbuffer only: no ANativeWindow/swapchain yet, so
// clear_and_present() clears and finishes without presenting to a display.
// On non-Android targets initialize() reports unsupported_window_system.
// Main thread only; must outlive the ClearBackendSelection that owns it.
class OpenGLESClearBackend final : public ClearBackend {
 public:
  explicit OpenGLESClearBackend(std::uint32_t width = 320, std::uint32_t height = 240) noexcept
      : width_(width), height_(height) {}
  [[nodiscard]] RenderError initialize() noexcept override;
  [[nodiscard]] RenderError clear_and_present(const std::array<float, 4>& color) noexcept override;
  [[nodiscard]] bool shutdown() noexcept override;
  [[nodiscard]] bool framebuffer_is_srgb() const noexcept { return renderer_.framebuffer_is_srgb(); }
  [[nodiscard]] bool read_center_pixel(std::array<float, 4>& out) const noexcept {
    return renderer_.read_center_pixel(out);
  }
 private:
  std::uint32_t width_, height_;
  OpenGLClearESRenderer renderer_;
  bool shutdown_failed_ = false;
};
} // namespace poko::rhi
