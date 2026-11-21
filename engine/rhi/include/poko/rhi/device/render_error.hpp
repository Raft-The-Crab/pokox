#pragma once
#include <cstdint>
namespace poko::rhi {
// Backend-neutral errors shared by clear renderers and selection.
enum class RenderError : std::uint8_t {
  none, already_initialized, not_initialized, invalid_window, not_drawable,
  unsupported_window_system, native_window_unavailable, factory_unavailable,
  device_creation_failed, swapchain_creation_failed, backbuffer_unavailable,
  size_query_failed, resize_required, backend_failure,
  // Recreation was requested; no frame was submitted. Check diagnostics
  // before calling again, because the backend can report errors via callback.
  resize_attempted,
};
} // namespace poko::rhi
