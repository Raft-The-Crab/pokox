#pragma once
#include "poko/rhi/device/render_error.hpp"
#include <array>
#include <cstdint>
#include <memory>
namespace Diligent { struct IRenderDevice; struct IDeviceContext; struct ISwapChain; struct ITextureView; }
namespace poko::platform { class SdlPlatform; }
namespace poko::rhi {
struct ClearConfig {
  bool enable_validation = true;
  // Vulkan physical-device index; 0xFFFFFFFF keeps Diligent's automatic choice.
  std::uint32_t adapter_id = 0xFFFFFFFFU;
  // Keep failed partial resources until shutdown_checked(), so an enclosing
  // diagnostics scope can distinguish teardown errors from startup errors.
  bool defer_failed_cleanup = false;
  // Allocate a D32 depth attachment for the experimental depth demo.
  bool enable_depth = false;
};
// Main-thread-only seed, not the full future RHI. Desktop Vulkan can resize.
// The platform/window must outlive this object and all its GPU resources.
// Called on the owning thread after resize and backbuffer checks, before present.
// The callback must not retain borrowed objects or destroy the renderer/window.
// Nested draws and shutdown during a callback are rejected.
using VulkanDrawCallback = RenderError (*)(Diligent::IRenderDevice&, Diligent::IDeviceContext&,
                                           Diligent::ISwapChain&, Diligent::ITextureView&, void*);
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
  // With defer_failed_cleanup, call shutdown_checked() even after init fails.
  // 'none' means the backend calls completed, not that a GPU/pixel readback
  // independently confirmed presentation. A failed desktop resize is sticky:
  // shut down the instance instead of presenting or retrying. Diligent can log
  // errors rather than throw, so callers must also monitor graphics diagnostics.
  // resize_attempted means no frame was submitted; inspect diagnostics before
  // calling again. Android resize and device-loss reporting are future work.
  [[nodiscard]] RenderError clear_and_present(const std::array<float, 4>& color) noexcept;
  // A non-success callback result (or exception) prevents presentation. The
  // caller must inspect diagnostics after each call, including after resize.
  [[nodiscard]] RenderError draw_and_present(VulkanDrawCallback draw, void* user) noexcept;
  // Unbind, idle, then release swapchain/context/device before SDL destruction.
  // Best-effort cleanup if a backend call throws; safe after partial init.
  void shutdown() noexcept;
  // False means cleanup failed or could not be confirmed; do not reuse the window.
  [[nodiscard]] bool shutdown_checked() noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
  bool cleanup_uncertain_ = false;
  bool drawing_ = false;
};
}  // namespace poko::rhi
