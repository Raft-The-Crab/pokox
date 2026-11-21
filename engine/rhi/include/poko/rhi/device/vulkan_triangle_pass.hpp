#pragma once
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include <array>
#include <memory>
#include <string>
namespace poko::rhi {
class VulkanDiagnostics;
enum class TriangleMode { color, depth_test, depth_disabled_control, uniform_depth };
// Experimental Vulkan-only pass. The renderer and diagnostic scope must
// outlive this object; release the pass before shutting the renderer down.
// A pass is bound to the first device used; do not reuse it after renderer restart.
class VulkanTrianglePass final {
 public:
  VulkanTrianglePass(const std::string& vertex_path, const std::string& fragment_path,
                     VulkanDiagnostics& diagnostics, TriangleMode mode = TriangleMode::color);
  ~VulkanTrianglePass();
  VulkanTrianglePass(const VulkanTrianglePass&) = delete;
  VulkanTrianglePass& operator=(const VulkanTrianglePass&) = delete;
  [[nodiscard]] RenderError draw_and_present(VulkanClearRenderer& renderer) noexcept;
  // Uniform-depth mode consumes four floats (std140 vec4), refreshed each draw.
  [[nodiscard]] RenderError draw_and_present(VulkanClearRenderer& renderer,
                                              const std::array<float, 4>& color) noexcept;
  // Draw into an already-acquired frame without clearing or presenting; the
  // caller must supply the objects a renderer draw callback receives. Used to
  // composite several passes inside one presented frame.
  [[nodiscard]] RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target) noexcept;
  [[nodiscard]] RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target,
                                 const std::array<float, 4>& color) noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
}
