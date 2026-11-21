#pragma once

#include "poko/rhi/device/render_error.hpp"
#include <array>
#include <cstdint>

namespace poko::rhi {
// A backend owns its window/context and must release them in shutdown(). An
// implementation must outlive the selector, and both run on the owning thread.
class ClearBackend {
 public:
  virtual ~ClearBackend() = default;
  [[nodiscard]] virtual RenderError initialize() noexcept = 0;
  [[nodiscard]] virtual RenderError clear_and_present(const std::array<float, 4>& color) noexcept = 0;
  // True only when all backend/window resources are released. May be retried.
  [[nodiscard]] virtual bool shutdown() noexcept = 0;
};

enum class SelectedBackend : std::uint8_t { none, primary, fallback };
enum class StartStatus : std::uint8_t { success, already_started, deferred, failed, cleanup_failed };
struct StartResult {
  StartStatus status = StartStatus::failed;
  SelectedBackend selected = SelectedBackend::none;
  RenderError primary_error = RenderError::none;
  RenderError fallback_error = RenderError::none;
  bool fallback_attempted = false;
};

// Selection happens only during initialization. Never switch after a draw,
// resize, device loss or any other runtime error: future work owns recovery.
class ClearBackendSelection final {
 public:
  ClearBackendSelection(ClearBackend& primary, ClearBackend& fallback) noexcept;
  ~ClearBackendSelection();
  ClearBackendSelection(const ClearBackendSelection&) = delete;
  ClearBackendSelection& operator=(const ClearBackendSelection&) = delete;
  ClearBackendSelection(ClearBackendSelection&&) = delete;
  ClearBackendSelection& operator=(ClearBackendSelection&&) = delete;
  [[nodiscard]] StartResult start() noexcept;
  [[nodiscard]] RenderError clear_and_present(const std::array<float, 4>& color) noexcept;
  [[nodiscard]] bool shutdown() noexcept;
  [[nodiscard]] SelectedBackend selected() const noexcept { return selected_; }
 private:
  ClearBackend& primary_;
  ClearBackend& fallback_;
  ClearBackend* owned_ = nullptr; // Includes failed attempts awaiting cleanup.
  SelectedBackend selected_ = SelectedBackend::none;
};
} // namespace poko::rhi
