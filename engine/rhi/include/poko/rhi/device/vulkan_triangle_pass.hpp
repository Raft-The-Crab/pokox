#pragma once
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include <array>
#include <memory>
#include <string>
namespace poko::rhi {
class VulkanDiagnostics;
enum class TriangleMode { color, depth_test, depth_disabled_control, uniform_depth, textured };
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
  // ENG-18: textured mode samples a 2D texture bound at set=0/binding=0.
  // Provide tightly packed RGBA (or BGRA when `bgra` is set) level-0 pixels;
  // the pass copies them and uploads on the first textured draw.
  void set_texture(const void* pixels, std::uint32_t width, std::uint32_t height,
                   bool bgra = false);
  // Full mip chain: `count` levels, index 0 = base. Each level's pixels are
  // tightly packed at that level's dimensions (halving per level). Invalid
  // inputs clear the texture; allocation failure preserves the previous one.
  // The caller supplies valid readable arrays throughout the call.
  struct TextureMip {
    const void* pixels = nullptr;
    std::uint32_t width = 0;
    std::uint32_t height = 0;
  };
  void set_texture_mips(const TextureMip* mips, std::size_t count, bool bgra = false,
                        bool srgb = false);
  [[nodiscard]] RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target,
                                 const std::array<float, 4>& color) noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
}
