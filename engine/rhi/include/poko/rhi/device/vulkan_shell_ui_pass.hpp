#pragma once

#include "poko/rhi/device/vulkan_clear_renderer.hpp"

#include <cstdint>
#include <memory>
#include <string>

namespace Diligent {
struct IRenderDevice;
struct IDeviceContext;
struct ISwapChain;
struct ITextureView;
}  // namespace Diligent

namespace poko::rhi {
class VulkanDiagnostics;

// Matches PokoTextureUpdate layout without coupling engine/rhi to the
// Windows shell C ABI header. Zero pixels_len disposes the texture id.
struct ShellTextureDelta {
  std::uint64_t id = 0;
  std::uint32_t width = 0;
  std::uint32_t height = 0;
  std::uint32_t pixels_offset = 0;
  std::uint32_t pixels_len = 0;
};

// SHL-11: Vulkan UI pass drawing the Windows egui shell mesh over an
// already-rendered game viewport target. Does not clear, acquire, or present.
// No depth testing; alpha blending enabled; one dynamic vertex/index upload.
class VulkanShellUiPass final {
 public:
  VulkanShellUiPass(const std::string& vertex_path,
                    const std::string& fragment_path,
                    VulkanDiagnostics& diagnostics);
  ~VulkanShellUiPass();
  VulkanShellUiPass(const VulkanShellUiPass&) = delete;
  VulkanShellUiPass& operator=(const VulkanShellUiPass&) = delete;
  VulkanShellUiPass(VulkanShellUiPass&&) = delete;
  VulkanShellUiPass& operator=(VulkanShellUiPass&&) = delete;

  [[nodiscard]] RenderError apply_texture_deltas(
      Diligent::IRenderDevice& device,
      const ShellTextureDelta* updates,
      std::uint32_t update_count,
      const std::uint8_t* pixels,
      std::uint32_t pixel_bytes) noexcept;

  [[nodiscard]] RenderError draw(Diligent::IRenderDevice& device,
                                 Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain,
                                 Diligent::ITextureView& target,
                                 const float* vertices_6f,
                                 std::uint32_t vertex_count,
                                 const std::uint32_t* indices,
                                 std::uint32_t index_count,
                                 std::uint32_t viewport_width,
                                 std::uint32_t viewport_height) noexcept;

 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace poko::rhi
