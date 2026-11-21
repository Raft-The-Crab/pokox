#pragma once
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include <memory>
#include <string>
namespace Diligent { struct IRenderDevice; struct IDeviceContext; struct ISwapChain; struct ITextureView; }
namespace poko::rhi {
class VulkanDiagnostics;
// Experimental Vulkan-only ImGui draw-data pass. Draws the current
// ImGui::GetDrawData() (font atlas only) into an already-acquired frame;
// it does not clear, acquire or present. The renderer and diagnostic scope
// must outlive this object; release the pass before shutting the renderer
// down. A pass is bound to the first device used; do not reuse it after
// renderer restart. Only the Dear ImGui font atlas texture is supported:
// commands referencing any other ImTextureID fail instead of binding an
// arbitrary texture. Draw callbacks other than ImDrawCallback_ResetRenderState
// are rejected. draw() leaves its pipeline, vertex/index buffers, viewport
// and last scissor rect bound on the context — it must be the last pass in
// the frame or followed by explicit state reset.
class VulkanImGuiPass final {
 public:
  VulkanImGuiPass(const std::string& vertex_path, const std::string& fragment_path,
                  VulkanDiagnostics& diagnostics);
  ~VulkanImGuiPass();
  VulkanImGuiPass(const VulkanImGuiPass&) = delete;
  VulkanImGuiPass& operator=(const VulkanImGuiPass&) = delete;
  VulkanImGuiPass(VulkanImGuiPass&&) = delete;
  VulkanImGuiPass& operator=(VulkanImGuiPass&&) = delete;
  [[nodiscard]] RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target) noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
}  // namespace poko::rhi
