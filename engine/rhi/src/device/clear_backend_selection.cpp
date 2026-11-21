#include "poko/rhi/device/clear_backend_selection.hpp"

namespace poko::rhi {
ClearBackendSelection::ClearBackendSelection(ClearBackend& primary, ClearBackend& fallback) noexcept
    : primary_(primary), fallback_(fallback) {}
ClearBackendSelection::~ClearBackendSelection() { (void)shutdown(); }
StartResult ClearBackendSelection::start() noexcept {
  StartResult result{};
  if (owned_) {
    result.status = selected_ == SelectedBackend::none ? StartStatus::cleanup_failed : StartStatus::already_started;
    result.selected = selected_;
    return result;
  }
  owned_ = &primary_;
  result.primary_error = primary_.initialize();
  if (result.primary_error == RenderError::none) {
    selected_ = result.selected = SelectedBackend::primary;
    result.status = StartStatus::success;
    return result;
  }
  if (!shutdown()) { result.status = StartStatus::cleanup_failed; return result; }
  // A minimized/zero-size drawable is transient, not a backend capability failure.
  if (result.primary_error == RenderError::not_drawable) {
    result.status = StartStatus::deferred;
    return result;
  }
  owned_ = &fallback_;
  result.fallback_attempted = true;
  result.fallback_error = fallback_.initialize();
  if (result.fallback_error == RenderError::none) {
    selected_ = result.selected = SelectedBackend::fallback;
    result.status = StartStatus::success;
    return result;
  }
  if (!shutdown()) { result.status = StartStatus::cleanup_failed; return result; }
  result.status = result.fallback_error == RenderError::not_drawable ? StartStatus::deferred : StartStatus::failed;
  return result;
}
RenderError ClearBackendSelection::clear_and_present(const std::array<float, 4>& color) noexcept {
  if (!owned_ || selected_ == SelectedBackend::none) return RenderError::not_initialized;
  return owned_->clear_and_present(color);
}
bool ClearBackendSelection::shutdown() noexcept {
  selected_ = SelectedBackend::none;
  if (!owned_) return true;
  if (!owned_->shutdown()) return false;
  owned_ = nullptr;
  return true;
}
} // namespace poko::rhi
