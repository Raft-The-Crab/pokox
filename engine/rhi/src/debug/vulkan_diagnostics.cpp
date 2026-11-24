#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/rhi/debug/vulkan_diagnostics_filter.hpp"
#include <BasicPlatformDebug.hpp>
#include <EngineFactoryVk.h>
#include <atomic>
#include <cstdio>
#include <string_view>
#include <utility>
namespace poko::rhi {
namespace {
// Static storage avoids callback pointers to destroyed per-renderer state.
std::atomic_flag owned = ATOMIC_FLAG_INIT;
// If restoration failed, acquiring another scope could save our capture
// function as the "previous" callback and silently lose the original one.
std::atomic<bool> callback_restore_failed{false};
std::atomic<std::uint64_t> errors{0}, warnings{0};
std::atomic<Diligent::DebugMessageCallbackType> previous_callback{nullptr};
GraphicsMessages totals() noexcept { return {errors.load(std::memory_order_acquire), warnings.load(std::memory_order_acquire)}; }
GraphicsMessages since(GraphicsMessages base) noexcept {
  const auto now = totals(); return {now.errors - base.errors, now.warnings - base.warnings};
}
void DILIGENT_CALL_TYPE capture(Diligent::DEBUG_MESSAGE_SEVERITY severity,
    const Diligent::Char* message, const Diligent::Char* function,
    const Diligent::Char* file, int line) noexcept {
  const bool error = severity >= Diligent::DEBUG_MESSAGE_SEVERITY_ERROR;
  const bool warning = severity == Diligent::DEBUG_MESSAGE_SEVERITY_WARNING;
  const char* text = message ? message : "(no message)";
  const bool environment_warning = warning && is_environment_layer_version_warning(text);
  if (error) errors.fetch_add(1, std::memory_order_release);
  else if (warning && !environment_warning) warnings.fetch_add(1, std::memory_order_release);
  std::fprintf(stderr, "[Poko graphics %s%s] %s (%s:%d; %s)\n",
    error ? "error" : warning ? "warning" : "info",
    environment_warning ? " (known environment)" : "",
    text, file ? file : "?", line, function ? function : "?");
  const auto previous = previous_callback.load(std::memory_order_acquire);
  if (previous && previous != capture) {
    try { previous(severity, message, function, file, line); }
    catch (...) {
      errors.fetch_add(1, std::memory_order_release);
      std::fputs("[Poko graphics error] Previous message callback threw.\n", stderr);
    }
  }
}
}
struct VulkanDiagnostics::Impl {
  Diligent::IEngineFactory* factory = nullptr;
  Diligent::DebugMessageCallbackType previous = nullptr;
  GraphicsMessages baseline{};
  bool owns = false, installed = false;
  bool break_on_error = true, break_on_error_changed = false;
  ~Impl() {
    if (break_on_error_changed)
      Diligent::BasicPlatformDebug::SetBreakOnError(break_on_error);
    if (!owns) return;
    // Only restore when this scope actually installed capture: an early
    // return (e.g. failed poisoned-state recovery) leaves previous==nullptr,
    // and restoring it would clear a still-installed capture callback.
    if (installed && factory && Diligent::DebugMessageCallback == capture) {
      try {
        factory->SetMessageCallback(previous);
        if (Diligent::DebugMessageCallback != previous) {
          callback_restore_failed.store(true, std::memory_order_release);
          errors.fetch_add(1, std::memory_order_release);
        }
      } catch (...) {
        callback_restore_failed.store(true, std::memory_order_release);
        errors.fetch_add(1, std::memory_order_release);
      }
    } else if (installed) {
      errors.fetch_add(1, std::memory_order_release);
      std::fputs("[Poko graphics error] Callback changed while diagnostics owned it.\n", stderr);
    }
    owned.clear(std::memory_order_release);
  }
};
VulkanDiagnostics::VulkanDiagnostics() noexcept = default;
VulkanDiagnostics::~VulkanDiagnostics() = default;
DiagnosticsError VulkanDiagnostics::start() noexcept {
  if (impl_) return DiagnosticsError::already_active;
  try { return start_with_factory(Diligent::GetEngineFactoryVk()); }
  catch (...) { return DiagnosticsError::backend_failure; }
}
DiagnosticsError VulkanDiagnostics::start_with_factory(Diligent::IEngineFactory* factory) noexcept {
  if (impl_) return DiagnosticsError::already_active;
  try {
    auto pending = std::make_unique<Impl>();
    if (owned.test_and_set(std::memory_order_acquire)) return DiagnosticsError::busy;
    pending->owns = true;
    pending->factory = factory;
    if (!pending->factory) return DiagnosticsError::factory_unavailable;
    if (callback_restore_failed.load(std::memory_order_acquire)) {
      // A previous restore failed, leaving our capture installed. Retry
      // restoring the original callback (still held in previous_callback)
      // only while capture is actually the installed callback — a foreign
      // callback installed since must not be clobbered. If capture is gone,
      // there is nothing to restore and the poison can clear.
      const auto original = previous_callback.load(std::memory_order_acquire);
      if (Diligent::DebugMessageCallback == capture) {
        try {
          pending->factory->SetMessageCallback(original);
          if (Diligent::DebugMessageCallback == original)
            callback_restore_failed.store(false, std::memory_order_release);
        } catch (...) {}
      } else {
        callback_restore_failed.store(false, std::memory_order_release);
      }
      if (callback_restore_failed.load(std::memory_order_acquire))
        return DiagnosticsError::backend_failure;
    }
    pending->previous = Diligent::DebugMessageCallback;
    pending->baseline = totals();
    previous_callback.store(pending->previous, std::memory_order_release);
    pending->factory->SetMessageCallback(capture);
    pending->installed = true;
    if (Diligent::DebugMessageCallback != capture) return DiagnosticsError::backend_failure;
    // Debug builds assert-fatal on Diligent VERIFY_EXPR failures (Win32 raises
    // and exits). While this scope owns reporting, asserts must stay non-fatal
    // so callers can clean up and try a fallback backend instead of dying.
    pending->break_on_error = Diligent::BasicPlatformDebug::GetBreakOnError();
    Diligent::BasicPlatformDebug::SetBreakOnError(false);
    pending->break_on_error_changed = true;
    saved_ = {}; impl_ = std::move(pending);
    return DiagnosticsError::none;
  } catch (...) { return DiagnosticsError::backend_failure; }
}
GraphicsMessages VulkanDiagnostics::messages() const noexcept { return impl_ ? since(impl_->baseline) : saved_; }
void VulkanDiagnostics::stop() noexcept {
  if (!impl_) return;
  const auto baseline = impl_->baseline; impl_.reset(); saved_ = since(baseline);
}
}
