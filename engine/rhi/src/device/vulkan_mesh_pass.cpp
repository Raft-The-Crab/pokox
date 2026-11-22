#include "poko/rhi/device/vulkan_mesh_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/rhi/directional_light.hpp"
#include "read_spirv.hpp"
#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>
#include <Buffer.h>
#include <InputLayout.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <limits>
#include <string>
#include <utility>
#include <vector>

namespace poko::rhi {
namespace {
constexpr Diligent::Uint32 kVertexStride = sizeof(MeshVertex);  // 24
}
struct VulkanMeshPass::Impl {
  std::vector<std::uint32_t> vertex, fragment;
  VulkanDiagnostics& diagnostics;
  Diligent::RefCntAutoPtr<Diligent::IPipelineState> pipeline;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> vertex_buffer, index_buffer;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> camera_buffer, light_buffer;
  DirectionalLight light;
  Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> binding;
  // Identity until set_view_proj() — a zero matrix would collapse the draw.
  std::array<float, 16> view_proj{1.f,0.f,0.f,0.f, 0.f,1.f,0.f,0.f,
                                  0.f,0.f,1.f,0.f, 0.f,0.f,0.f,1.f};
  Diligent::TEXTURE_FORMAT format = Diligent::TEX_FORMAT_UNKNOWN;
  Diligent::TEXTURE_FORMAT depth_format = Diligent::TEX_FORMAT_UNKNOWN;
  Diligent::IRenderDevice* owner = nullptr;
  // CPU copies until first draw after set_mesh().
  std::vector<MeshVertex> mesh_vertices;
  std::vector<std::uint32_t> mesh_indices;
  bool buffers_dirty = true;
  Impl(const std::string& vs, const std::string& fs, VulkanDiagnostics& d)
      : vertex(detail::read_spirv(vs)), fragment(detail::read_spirv(fs)), diagnostics(d) {}

  RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                   Diligent::ISwapChain& chain, Diligent::ITextureView& target) {
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (owner && owner != &device) return RenderError::backend_failure;
    if (mesh_vertices.empty() || mesh_indices.empty()) return RenderError::not_initialized;
    const auto& desc = chain.GetDesc();
    const auto current_format = desc.ColorBufferFormat;
    const auto current_depth_format = desc.DepthBufferFormat;
    auto* depth_view = chain.GetDepthBufferDSV();
    if (current_format == Diligent::TEX_FORMAT_UNKNOWN ||
        current_depth_format == Diligent::TEX_FORMAT_UNKNOWN || !depth_view)
      return RenderError::backend_failure;
    // Resources created below belong to this device even if setup fails.
    owner = &device;

    if (buffers_dirty || !vertex_buffer || !index_buffer) {
      // ENG-19: immutable vertex/index buffers, uploaded once per set_mesh().
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created_vertices, created_indices;
      Diligent::BufferDesc vb_desc{};
      vb_desc.Name = "Poko mesh vertices";
      vb_desc.Size = mesh_vertices.size() * kVertexStride;
      vb_desc.BindFlags = Diligent::BIND_VERTEX_BUFFER;
      vb_desc.Usage = Diligent::USAGE_IMMUTABLE;
      Diligent::BufferData vb_data{mesh_vertices.data(), vb_desc.Size, nullptr};
      device.CreateBuffer(vb_desc, &vb_data, &created_vertices);
      if (!created_vertices || diagnostics.messages().errors) return RenderError::backend_failure;
      Diligent::BufferDesc ib_desc{};
      ib_desc.Name = "Poko mesh indices";
      ib_desc.Size = mesh_indices.size() * sizeof(std::uint32_t);
      ib_desc.BindFlags = Diligent::BIND_INDEX_BUFFER;
      ib_desc.Usage = Diligent::USAGE_IMMUTABLE;
      Diligent::BufferData ib_data{mesh_indices.data(), ib_desc.Size, nullptr};
      device.CreateBuffer(ib_desc, &ib_data, &created_indices);
      if (!created_indices || diagnostics.messages().errors) return RenderError::backend_failure;
      vertex_buffer = std::move(created_vertices);
      index_buffer = std::move(created_indices);
      buffers_dirty = false;
    }

    if (!pipeline || format != current_format || depth_format != current_depth_format) {
      Diligent::RefCntAutoPtr<Diligent::IShader> vs, ps;
      Diligent::ShaderCreateInfo shader{};
      shader.Desc.Name = "Poko mesh vertex"; shader.Desc.ShaderType = Diligent::SHADER_TYPE_VERTEX;
      shader.ByteCode = vertex.data(); shader.ByteCodeSize = vertex.size() * sizeof(std::uint32_t);
      device.CreateShader(shader, &vs);
      if (!vs || diagnostics.messages().errors) return RenderError::backend_failure;
      shader.Desc.Name = "Poko mesh fragment"; shader.Desc.ShaderType = Diligent::SHADER_TYPE_PIXEL;
      shader.ByteCode = fragment.data(); shader.ByteCodeSize = fragment.size() * sizeof(std::uint32_t);
      device.CreateShader(shader, &ps);
      if (!ps || diagnostics.messages().errors) return RenderError::backend_failure;
      static const Diligent::LayoutElement kLayout[] = {
          {"ATTRIB", 0, 0, 3, Diligent::VT_FLOAT32, Diligent::True, 0, kVertexStride,
           Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX, 1},
          {"ATTRIB", 1, 0, 3, Diligent::VT_FLOAT32, Diligent::True, 12, kVertexStride,
           Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX, 1}};
      Diligent::GraphicsPipelineStateCreateInfo info{};
      info.PSODesc.Name = "Poko mesh pipeline";
      info.GraphicsPipeline.NumRenderTargets = 1;
      info.GraphicsPipeline.RTVFormats[0] = current_format;
      info.GraphicsPipeline.DSVFormat = current_depth_format;
      info.GraphicsPipeline.DepthStencilDesc.DepthEnable = Diligent::True;
      info.GraphicsPipeline.DepthStencilDesc.DepthWriteEnable = Diligent::True;
      info.GraphicsPipeline.DepthStencilDesc.DepthFunc = Diligent::COMPARISON_FUNC_LESS;
      info.GraphicsPipeline.RasterizerDesc.CullMode = Diligent::CULL_MODE_BACK;
      // Mesh faces are authored CCW from outside. The default is clockwise,
      // which culls the exterior and exposes the unlit back faces.
      info.GraphicsPipeline.RasterizerDesc.FrontCounterClockwise = Diligent::True;
      info.GraphicsPipeline.PrimitiveTopology = Diligent::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
      info.GraphicsPipeline.InputLayout = Diligent::InputLayoutDesc{kLayout, 2};
      info.pVS = vs; info.pPS = ps;
      Diligent::RefCntAutoPtr<Diligent::IPipelineState> created;
      device.CreateGraphicsPipelineState(info, &created);
      if (!created || diagnostics.messages().errors) return RenderError::backend_failure;
      // ENG-20: per-frame view*projection uniform (std140 mat4).
      Diligent::BufferDesc cam_desc{};
      cam_desc.Name = "Poko camera";
      cam_desc.Size = sizeof(float) * 16;
      cam_desc.BindFlags = Diligent::BIND_UNIFORM_BUFFER;
      cam_desc.Usage = Diligent::USAGE_DYNAMIC;
      cam_desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created_camera, created_light;
      Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> created_binding;
      device.CreateBuffer(cam_desc, nullptr, &created_camera);
      if (!created_camera || diagnostics.messages().errors) return RenderError::backend_failure;
      auto* variable = created->GetStaticVariableByName(Diligent::SHADER_TYPE_VERTEX, "Camera");
      if (!variable || diagnostics.messages().errors) return RenderError::backend_failure;
      variable->Set(created_camera);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
      Diligent::BufferDesc light_desc{};
      light_desc.Name = "Poko directional light";
      light_desc.Size = sizeof(float) * 4;
      light_desc.BindFlags = Diligent::BIND_UNIFORM_BUFFER;
      light_desc.Usage = Diligent::USAGE_DYNAMIC;
      light_desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
      device.CreateBuffer(light_desc, nullptr, &created_light);
      if (!created_light || diagnostics.messages().errors) return RenderError::backend_failure;
      auto* light_var = created->GetStaticVariableByName(Diligent::SHADER_TYPE_PIXEL, "DirectionalLight");
      if (!light_var || diagnostics.messages().errors) return RenderError::backend_failure;
      light_var->Set(created_light);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
      created->CreateShaderResourceBinding(&created_binding, true);
      if (!created_binding || diagnostics.messages().errors) return RenderError::backend_failure;
      pipeline = std::move(created);
      camera_buffer = std::move(created_camera);
      light_buffer = std::move(created_light);
      binding = std::move(created_binding);
      format = current_format; depth_format = current_depth_format;
    }

    auto* view = &target;
    context.SetRenderTargets(1, &view, depth_view, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    constexpr float background[4] = {0.035f, 0.12f, 0.28f, 1.f};
    context.ClearRenderTarget(view, background, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    context.ClearDepthStencil(depth_view, Diligent::CLEAR_DEPTH_FLAG, 1.0f, 0,
                              Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    void* mapped = nullptr;
    context.MapBuffer(camera_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped);
    if (!mapped) return RenderError::backend_failure;
    if (!diagnostics.messages().errors) std::memcpy(mapped, view_proj.data(), sizeof(view_proj));
    context.UnmapBuffer(camera_buffer, Diligent::MAP_WRITE);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    mapped = nullptr;
    context.MapBuffer(light_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped);
    if (!mapped) return RenderError::backend_failure;
    if (!diagnostics.messages().errors) std::memcpy(mapped, light.data().data(), sizeof(float) * 4);
    context.UnmapBuffer(light_buffer, Diligent::MAP_WRITE);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    context.CommitShaderResources(binding, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    context.SetPipelineState(pipeline);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::IBuffer* vb = vertex_buffer;
    const Diligent::Uint64 offset = 0;
    context.SetVertexBuffers(0, 1, &vb, &offset,
                             Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    context.SetIndexBuffer(index_buffer, 0, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::DrawIndexedAttribs draw{};
    draw.NumIndices = static_cast<Diligent::Uint32>(mesh_indices.size());
    draw.IndexType = Diligent::VT_UINT32;
    draw.Flags = Diligent::DRAW_FLAG_VERIFY_ALL;
    context.DrawIndexed(draw);
    return diagnostics.messages().errors ? RenderError::backend_failure : RenderError::none;
  }
};

VulkanMeshPass::VulkanMeshPass(const std::string& vs, const std::string& fs, VulkanDiagnostics& d)
    : impl_(std::make_unique<Impl>(vs, fs, d)) {}
VulkanMeshPass::~VulkanMeshPass() = default;

bool VulkanMeshPass::set_light_direction(float x, float y, float z) noexcept {
  return impl_->light.set_direction(x, y, z);
}
void VulkanMeshPass::set_view_proj(const float* mat16) noexcept {
  if (!mat16) return;
  auto& impl = *impl_;
  std::memcpy(impl.view_proj.data(), mat16, sizeof(impl.view_proj));
}
void VulkanMeshPass::set_mesh(const MeshVertex* vertices, std::size_t vertex_count,
                              const std::uint32_t* indices, std::size_t index_count) {
  auto& impl = *impl_;
  // Validate counts before reading raw pointers, and retain the old mesh if
  // allocation throws. Invalid/empty input intentionally clears the mesh.
  bool valid = vertices && indices && vertex_count && index_count &&
      index_count <= std::numeric_limits<Diligent::Uint32>::max() &&
      vertex_count <= std::numeric_limits<std::size_t>::max() / sizeof(MeshVertex) &&
      index_count <= std::numeric_limits<std::size_t>::max() / sizeof(std::uint32_t);
  if (valid) {
    for (std::size_t i = 0; i < index_count; ++i)
      if (indices[i] >= vertex_count) { valid = false; break; }
  }
  std::vector<MeshVertex> vertices_copy;
  std::vector<std::uint32_t> indices_copy;
  if (valid) {
    vertices_copy.assign(vertices, vertices + vertex_count);
    indices_copy.assign(indices, indices + index_count);
  }
  impl.mesh_vertices.swap(vertices_copy);
  impl.mesh_indices.swap(indices_copy);
  impl.buffers_dirty = true;
  impl.vertex_buffer = Diligent::RefCntAutoPtr<Diligent::IBuffer>();
  impl.index_buffer = Diligent::RefCntAutoPtr<Diligent::IBuffer>();
}

RenderError VulkanMeshPass::draw_and_present(VulkanClearRenderer& renderer) noexcept {
  struct Call { Impl* impl; } call{impl_.get()};
  return renderer.draw_and_present([](Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                      Diligent::ISwapChain& chain, Diligent::ITextureView& target, void* user) {
    return static_cast<Call*>(user)->impl->draw(device, context, chain, target);
  }, &call);
}

RenderError VulkanMeshPass::draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target) noexcept {
  try {
    return impl_->draw(device, context, chain, target);
  } catch (...) {
    return RenderError::backend_failure;
  }
}
}  // namespace poko::rhi
