#pragma once
#include <cstdint>
#include <memory>
namespace Diligent { struct IEngineFactory; }
namespace poko::rhi {
enum class DiagnosticsError { none, already_active, busy, factory_unavailable, backend_failure };
struct GraphicsMessages { std::uint64_t errors = 0, warnings = 0; };
// Exclusive process-wide Diligent callback scope for the standalone demo.
// Start/stop on the main thread; do not modify the callback from other code.
// Release all GPU resources/work before stop. Counters support callback threads.
class VulkanDiagnostics final {
 public:
  VulkanDiagnostics() noexcept;
  ~VulkanDiagnostics();
  VulkanDiagnostics(const VulkanDiagnostics&) = delete;
  VulkanDiagnostics& operator=(const VulkanDiagnostics&) = delete;
  VulkanDiagnostics(VulkanDiagnostics&&) = delete;
  VulkanDiagnostics& operator=(VulkanDiagnostics&&) = delete;
  [[nodiscard]] DiagnosticsError start() noexcept;
  // Shared callback owner; caller supplies a live Diligent factory.
  [[nodiscard]] DiagnosticsError start_with_factory(Diligent::IEngineFactory*) noexcept;
  [[nodiscard]] GraphicsMessages messages() const noexcept;
  void stop() noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
  GraphicsMessages saved_{};
};
}
