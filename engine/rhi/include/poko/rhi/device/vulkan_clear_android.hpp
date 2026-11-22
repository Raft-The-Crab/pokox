#pragma once
#include "poko/rhi/device/render_error.hpp"
#include <array>
#include <cstdint>
namespace poko::rhi {
// Minimal Android Vulkan clear/present renderer over an ANativeWindow surface.
// Experimental ENG-04 evidence path only: single device, FIFO present, one
// clear render pass per frame. Not the engine RHI. Main thread only.
class VulkanClearAndroidRenderer final {
 public:
  VulkanClearAndroidRenderer() noexcept;
  ~VulkanClearAndroidRenderer();
  VulkanClearAndroidRenderer(const VulkanClearAndroidRenderer&) = delete;
  VulkanClearAndroidRenderer& operator=(const VulkanClearAndroidRenderer&) = delete;
  // Returns device_creation_failed when no usable Vulkan device/driver exists;
  // callers treat that as the fallback trigger.
  [[nodiscard]] RenderError initialize(void* native_window, std::uint32_t width,
                                       std::uint32_t height) noexcept;
  [[nodiscard]] RenderError clear_and_present(const std::array<float, 4>& color) noexcept;
  void shutdown() noexcept;
  [[nodiscard]] bool shutdown_checked() noexcept;
  // Exposed for the translation-unit-local helpers in the .cpp; not part of
  // the public contract.
  struct Impl;
 private:
  Impl* impl_ = nullptr;
  bool cleanup_uncertain_ = false;
};
} // namespace poko::rhi
