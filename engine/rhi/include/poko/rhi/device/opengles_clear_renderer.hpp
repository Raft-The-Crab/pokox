#pragma once
#include "poko/rhi/device/render_error.hpp"
#include <array>
#include <cstdint>
namespace poko::rhi {
// Experimental Android OpenGL ES 3.2 clear renderer over an EGL pbuffer
// surface. Offscreen only: there is no ANativeWindow, swapchain or lifecycle
// integration yet, so clear_and_present() clears and finishes without a real
// present. Readback verifies stored pixels for evidence runs. Main thread only.
class OpenGLClearESRenderer final {
 public:
  OpenGLClearESRenderer() noexcept;
  ~OpenGLClearESRenderer();
  OpenGLClearESRenderer(const OpenGLClearESRenderer&) = delete;
  OpenGLClearESRenderer& operator=(const OpenGLClearESRenderer&) = delete;
  OpenGLClearESRenderer(OpenGLClearESRenderer&&) = delete;
  OpenGLClearESRenderer& operator=(OpenGLClearESRenderer&&) = delete;
  [[nodiscard]] RenderError initialize(std::uint32_t width, std::uint32_t height) noexcept;
  // Windowed variant: 'native_window' is an ANativeWindow* (Android only).
  // Creates a real EGL window surface; clear_and_present() then performs
  // eglSwapBuffers. The window must outlive the renderer.
  [[nodiscard]] RenderError initialize_window(void* native_window, std::uint32_t width,
                                              std::uint32_t height) noexcept;
  [[nodiscard]] RenderError clear_and_present(const std::array<float, 4>& color) noexcept;
  // Clears, reads the center pixel from the back buffer, then swaps. On a
  // windowed surface this is the deterministic way to verify the color that
  // was just presented, since post-swap back-buffer contents are undefined.
  [[nodiscard]] RenderError clear_and_verify(const std::array<float, 4>& color,
                                             std::array<float, 4>& pixel) noexcept;
  // Reads the center pixel after the last clear as normalized RGBA. False on
  // GL errors or before initialize(). Values are the stored framebuffer bytes
  // divided by 255, not a color-managed conversion.
  [[nodiscard]] bool read_center_pixel(std::array<float, 4>& out) const noexcept;
  // Releases context, surface and display. Safe after partial init.
  void shutdown() noexcept;
  [[nodiscard]] bool shutdown_checked() noexcept;
  // True when the pbuffer config requested sRGB colorspace; false means the
  // driver fell back to a linear framebuffer and stored values are unencoded.
  [[nodiscard]] bool framebuffer_is_srgb() const noexcept;
 private:
  struct Impl;
  Impl* impl_ = nullptr;
  bool cleanup_uncertain_ = false;
  [[nodiscard]] RenderError initialize_impl(void* native_window, std::uint32_t width,
                                            std::uint32_t height) noexcept;
};
} // namespace poko::rhi
