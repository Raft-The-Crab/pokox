#include "poko/rhi/vulkan_diagnostics.hpp"
#include <EngineFactoryVk.h>
#include <atomic>
#include <cstdio>
#include <utility>
namespace poko::rhi {
namespace {
// Static storage avoids callback pointers to destroyed per-renderer state.
std::atomic_flag owned = ATOMIC_FLAG_INIT;
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
  if (error) errors.fetch_add(1, std::memory_order_release);
  else if (severity == Diligent::DEBUG_MESSAGE_SEVERITY_WARNING) warnings.fetch_add(1, std::memory_order_release);
  std::fprintf(stderr, "[Poko graphics %s] %s (%s:%d; %s)\n",
    error ? "error" : severity == Diligent::DEBUG_MESSAGE_SEVERITY_WARNING ? "warning" : "info",
    message ? message : "(no message)", file ? file : "?", line, function ? function : "?");
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
  Diligent::IEngineFactoryVk* factory = nullptr;
  Diligent::DebugMessageCallbackType previous = nullptr;
  GraphicsMessages baseline{};
  bool owns = false, installed = false;
  ~Impl() {
    if (!owns) return;
    if (factory && Diligent::DebugMessageCallback == capture) {
      try { factory->SetMessageCallback(previous); }
      catch (...) { errors.fetch_add(1, std::memory_order_release); }
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
  try {
    auto pending = std::make_unique<Impl>();
    if (owned.test_and_set(std::memory_order_acquire)) return DiagnosticsError::busy;
    pending->owns = true;
    pending->factory = Diligent::GetEngineFactoryVk();
    if (!pending->factory) return DiagnosticsError::factory_unavailable;
    pending->previous = Diligent::DebugMessageCallback;
    pending->baseline = totals();
    previous_callback.store(pending->previous, std::memory_order_release);
    pending->factory->SetMessageCallback(capture);
    pending->installed = true;
    if (Diligent::DebugMessageCallback != capture) return DiagnosticsError::backend_failure;
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
