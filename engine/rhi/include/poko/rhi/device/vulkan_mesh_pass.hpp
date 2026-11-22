#pragma once
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>

namespace poko::rhi {
class VulkanDiagnostics;
// ENG-19: indexed geometry pass — real vertex/index buffers, per-vertex
// position + normal, depth-tested. Geometry is supplied CPU-side via
// set_mesh() and uploaded once per set (USAGE_IMMUTABLE buffers).
struct MeshVertex {
  float position[3];
  float normal[3];
};
static_assert(sizeof(MeshVertex) == 24, "mesh vertex layout must match shader input");

// Experimental Vulkan-only pass. The renderer and diagnostic scope must
// outlive this object; release the pass before shutting the renderer down.
// A pass is bound to the first device used; do not reuse it after renderer restart.
class VulkanMeshPass final {
 public:
  VulkanMeshPass(const std::string& vertex_path, const std::string& fragment_path,
                 VulkanDiagnostics& diagnostics);
  ~VulkanMeshPass();
  VulkanMeshPass(const VulkanMeshPass&) = delete;
  VulkanMeshPass& operator=(const VulkanMeshPass&) = delete;
  // Replaces the mesh between draws. Empty/invalid input clears it; allocation
  // failure throws and preserves the previous mesh. Caller owns valid input
  // arrays for the duration of the call. Index counts must fit in uint32_t.
  void set_mesh(const MeshVertex* vertices, std::size_t vertex_count,
                const std::uint32_t* indices, std::size_t index_count);
  // ENG-20: column-major view*projection mat4 uploaded per draw. Until set,
  // the identity matrix is used.
  void set_view_proj(const float* mat16) noexcept;
  // Set the world-space direction from a surface toward the light. Invalid,
  // non-finite or zero vectors are rejected without changing the last value.
  [[nodiscard]] bool set_light_direction(float x, float y, float z) noexcept;
  [[nodiscard]] RenderError draw_and_present(VulkanClearRenderer& renderer) noexcept;
  // Draw into an already-acquired frame without clearing or presenting; the
  // caller must supply the objects a renderer draw callback receives.
  [[nodiscard]] RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target) noexcept;
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
}  // namespace poko::rhi
