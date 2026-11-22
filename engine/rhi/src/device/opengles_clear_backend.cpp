#include "poko/rhi/device/opengles_clear_backend.hpp"
namespace poko::rhi {
RenderError OpenGLESClearBackend::initialize() noexcept {
  if (shutdown_failed_) return RenderError::backend_failure;
  return renderer_.initialize(width_, height_);
}
RenderError OpenGLESClearBackend::clear_and_present(const std::array<float, 4>& color) noexcept {
  return renderer_.clear_and_present(color);
}
bool OpenGLESClearBackend::shutdown() noexcept {
  renderer_.shutdown();
  if (!renderer_.shutdown_checked()) { shutdown_failed_ = true; return false; }
  return true;
}
} // namespace poko::rhi
