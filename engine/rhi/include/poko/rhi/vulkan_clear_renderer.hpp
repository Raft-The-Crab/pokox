#pragma once
#include <array>
#include <cstdint>
#include <memory>
namespace poko::platform { class SdlPlatform; }
namespace poko::rhi {
enum class RenderError : std::uint8_t {
  none, already_initialized, not_initialized, invalid_window, not_drawable,
  unsupported_window_system, native_window_unavailable, factory_unavailable,
  device_creation_failed, swapchain_creation_failed, backbuffer_unavailable,
  size_query_failed, resize_required, backend_failure,
};
struct ClearConfig {
  bool enable_validation = true;
  // Vulkan physical-device index; 0xFFFFFFFF keeps Diligent's automatic choice.
  std::uint32_t adapter_id = 0xFFFFFFFFU;
};
// ENG-03 seed, not the full future RHI. Main-thread-only, no fallback or resize.
// The platform/window must outlive this object and all its GPU resources.
class VulkanClearRenderer final {
 public:
  VulkanClearRenderer() noexcept;
  ~VulkanClearRenderer();
  VulkanClearRenderer(const VulkanClearRenderer&) = delete;
  VulkanClearRenderer& operator=(const VulkanClearRenderer&) = delete;
  VulkanClearRenderer(VulkanClearRenderer&&) = delete;
  VulkanClearRenderer& operator=(VulkanClearRenderer&&) = delete;
  [[nodiscard]] RenderError initialize(platform::SdlPlatform& platform,
                                        ClearConfig config = {}) noexcept;
  // 'none' means the backend calls completed, not that a GPU/pixel readback
  // independently confirmed presentation. Device-loss reporting is future work.
  [[nodiscard]] RenderError clear_and_present(const std::array<float, 4>& color) noexcept;
  // Unbind, idle, then release swapchain/context/device before SDL destruction.
  // Best-effort cleanup if a backend call throws; safe after partial init.
  void shutdown() noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
}  // namespace poko::rhi
