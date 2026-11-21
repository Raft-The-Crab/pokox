#pragma once
#include "poko/rhi/device/render_error.hpp"
#include <array>
#include <memory>
namespace poko::platform { class SdlPlatform; }
namespace poko::rhi {
// Desktop-only experimental Diligent GL seed. Main thread; platform/window
// must outlive this renderer. Linux owns an SDL GLX context; Windows uses WGL
// owned by Diligent. The caller must configure SDL GL attributes before window
// creation on Linux. Desktop resize is experimental; no device-loss recovery.
class OpenGLClearRenderer final {
 public:
  OpenGLClearRenderer() noexcept;
  ~OpenGLClearRenderer();
  OpenGLClearRenderer(const OpenGLClearRenderer&) = delete;
  OpenGLClearRenderer& operator=(const OpenGLClearRenderer&) = delete;
  [[nodiscard]] RenderError initialize(platform::SdlPlatform&, bool validation = true) noexcept;
  // resize_attempted submits no frame; check graphics diagnostics before the
  // next call. A failed resize is sticky until shutdown.
  [[nodiscard]] RenderError clear_and_present(const std::array<float,4>&) noexcept;
  // False signals incomplete/uncertain cleanup. Keep the window alive; context
  // destruction failures may be retried, but an idle/unbind error is sticky.
  [[nodiscard]] bool shutdown() noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
} // namespace poko::rhi
