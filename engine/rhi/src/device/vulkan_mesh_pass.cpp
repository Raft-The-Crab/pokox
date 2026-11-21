#include "poko/rhi/device/vulkan_mesh_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "read_spirv.hpp"
#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>
#include <Buffer.h>
#include <InputLayout.h>
#include <array>
#include <cstdint>
#include <cstring>
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
  Diligent::RefCntAutoPtr<Diligent::IBuffer> camera_buffer;
  Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> binding;
  std::array<float, 16> view_proj{};
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

    if (buffers_dirty || !vertex_buffer || !index_buffer) {
      // ENG-19: immutable vertex/index buffers, uploaded once per set_mesh().
      Diligent::BufferDesc vb_desc{};
      vb_desc.Name = "Poko mesh vertices";
      vb_desc.Size = mesh_vertices.size() * kVertexStride;
      vb_desc.BindFlags = Diligent::BIND_VERTEX_BUFFER;
      vb_desc.Usage = Diligent::USAGE_IMMUTABLE;
      Diligent::BufferData vb_data{mesh_vertices.data(), vb_desc.Size, nullptr};
      device.CreateBuffer(vb_desc, &vb_data, &vertex_buffer);
      if (!vertex_buffer || diagnostics.messages().errors) return RenderError::backend_failure;
      Diligent::BufferDesc ib_desc{};
      ib_desc.Name = "Poko mesh indices";
      ib_desc.Size = mesh_indices.size() * sizeof(std::uint32_t);
      ib_desc.BindFlags = Diligent::BIND_INDEX_BUFFER;
      ib_desc.Usage = Diligent::USAGE_IMMUTABLE;
      Diligent::BufferData ib_data{mesh_indices.data(), ib_desc.Size, nullptr};
      device.CreateBuffer(ib_desc, &ib_data, &index_buffer);
      if (!index_buffer || diagnostics.messages().errors) return RenderError::backend_failure;
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
      device.CreateBuffer(cam_desc, nullptr, &camera_buffer);
      if (!camera_buffer || diagnostics.messages().errors) return RenderError::backend_failure;
      auto* variable = created->GetStaticVariableByName(Diligent::SHADER_TYPE_VERTEX, "Camera");
      if (!variable || diagnostics.messages().errors) return RenderError::backend_failure;
      variable->Set(camera_buffer);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
      created->CreateShaderResourceBinding(&binding, true);
      if (!binding || diagnostics.messages().errors) return RenderError::backend_failure;
      pipeline = std::move(created); format = current_format;
      depth_format = current_depth_format; owner = &device;
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

void VulkanMeshPass::set_view_proj(const float* mat16) noexcept {
  if (!mat16) return;
  auto& impl = *impl_;
  std::memcpy(impl.view_proj.data(), mat16, sizeof(impl.view_proj));
}
void VulkanMeshPass::set_mesh(const MeshVertex* vertices, std::size_t vertex_count,
                              const std::uint32_t* indices, std::size_t index_count) {
  auto& impl = *impl_;
  impl.mesh_vertices.assign(vertices, vertices + vertex_count);
  impl.mesh_indices.assign(indices, indices + index_count);
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
