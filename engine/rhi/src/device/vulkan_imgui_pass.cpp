#include "poko/rhi/device/vulkan_imgui_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "read_spirv.hpp"
#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>
#include <imgui.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <string>
#include <utility>
#include <vector>

namespace poko::rhi {
struct VulkanImGuiPass::Impl {
  static_assert(sizeof(ImDrawVert) == 20 && sizeof(ImDrawIdx) == 2,
                "ImGui vertex/index layout changed; update the input layout and index type");
  static_assert(offsetof(ImDrawVert, pos) == 0 && offsetof(ImDrawVert, uv) == 8 &&
                offsetof(ImDrawVert, col) == 16, "Unexpected ImDrawVert layout");
  std::vector<std::uint32_t> vertex, fragment;
  VulkanDiagnostics& diagnostics;
  Diligent::RefCntAutoPtr<Diligent::IPipelineState> pipeline;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> frame_buffer;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> vertex_buffer;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> index_buffer;
  Diligent::RefCntAutoPtr<Diligent::ITexture> font_texture;
  Diligent::RefCntAutoPtr<Diligent::ITextureView> font_view;
  Diligent::RefCntAutoPtr<Diligent::ISampler> font_sampler;
  Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> binding;
  Diligent::TEXTURE_FORMAT format = Diligent::TEX_FORMAT_UNKNOWN;
  Diligent::IRenderDevice* owner = nullptr;
  ImTextureID font_tex_id = ImTextureID_Invalid;
  std::size_t vertex_capacity = 0, index_capacity = 0;
  Impl(const std::string& vs, const std::string& fs, VulkanDiagnostics& d)
      : vertex(detail::read_spirv(vs)), fragment(detail::read_spirv(fs)), diagnostics(d) {}
  RenderError ensure_font(Diligent::IRenderDevice& device, ImGuiIO& io) {
    if (font_view) return RenderError::none;
    unsigned char* pixels = nullptr;
    int width = 0, height = 0;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    if (!pixels || width <= 0 || height <= 0) return RenderError::backend_failure;
    Diligent::TextureDesc desc{};
    desc.Name = "Poko ImGui font atlas";
    desc.Type = Diligent::RESOURCE_DIM_TEX_2D;
    desc.Width = static_cast<Diligent::Uint32>(width);
    desc.Height = static_cast<Diligent::Uint32>(height);
    desc.Format = Diligent::TEX_FORMAT_RGBA8_UNORM;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.BindFlags = Diligent::BIND_SHADER_RESOURCE;
    desc.Usage = Diligent::USAGE_IMMUTABLE;
    Diligent::TextureSubResData subresource{};
    subresource.pData = pixels;
    subresource.Stride = static_cast<Diligent::Uint64>(width) * 4;
    Diligent::TextureSubResData subresources[1] = {subresource};
    Diligent::TextureData initial{subresources, 1};
    Diligent::RefCntAutoPtr<Diligent::ITexture> created_texture;
    Diligent::RefCntAutoPtr<Diligent::ITextureView> created_view;
    Diligent::RefCntAutoPtr<Diligent::ISampler> created_sampler;
    device.CreateTexture(desc, &initial, &created_texture);
    if (!created_texture || diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::TextureViewDesc view_desc{};
    view_desc.ViewType = Diligent::TEXTURE_VIEW_SHADER_RESOURCE;
    created_texture->CreateView(view_desc, &created_view);
    if (!created_view || diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::SamplerDesc sampler_desc{};
    sampler_desc.Name = "Poko ImGui sampler";
    sampler_desc.MinFilter = Diligent::FILTER_TYPE_LINEAR;
    sampler_desc.MagFilter = Diligent::FILTER_TYPE_LINEAR;
    sampler_desc.MipFilter = Diligent::FILTER_TYPE_LINEAR;
    sampler_desc.AddressU = Diligent::TEXTURE_ADDRESS_CLAMP;
    sampler_desc.AddressV = Diligent::TEXTURE_ADDRESS_CLAMP;
    sampler_desc.AddressW = Diligent::TEXTURE_ADDRESS_CLAMP;
    device.CreateSampler(sampler_desc, &created_sampler);
    if (!created_sampler || diagnostics.messages().errors) return RenderError::backend_failure;
    created_view->SetSampler(created_sampler);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    const ImTextureID created_id = reinterpret_cast<ImTextureID>(created_view.RawPtr());
    if (created_id == ImTextureID_Invalid) return RenderError::backend_failure;
    font_texture = std::move(created_texture);
    font_view = std::move(created_view);
    font_sampler = std::move(created_sampler);
    font_tex_id = created_id;
    io.Fonts->SetTexID(ImTextureRef(font_tex_id));
    return diagnostics.messages().errors ? RenderError::backend_failure : RenderError::none;
  }
  RenderError ensure_buffers(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                             ImDrawData* draw_data) {
    const auto needed_vertices = static_cast<std::size_t>(draw_data->TotalVtxCount);
    const auto needed_indices = static_cast<std::size_t>(draw_data->TotalIdxCount);
    if (needed_vertices > vertex_capacity) {
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created;
      Diligent::BufferDesc desc{};
      desc.Name = "Poko ImGui vertices";
      desc.Size = needed_vertices * sizeof(ImDrawVert);
      desc.BindFlags = Diligent::BIND_VERTEX_BUFFER;
      desc.Usage = Diligent::USAGE_DYNAMIC;
      desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
      device.CreateBuffer(desc, nullptr, &created);
      if (!created || diagnostics.messages().errors) {
        // Keep capacity in sync with the (released) buffer so the next frame
        // retries creation instead of mapping a null buffer.
        vertex_buffer.Release(); vertex_capacity = 0;
        return RenderError::backend_failure;
      }
      vertex_buffer = std::move(created);
      vertex_capacity = needed_vertices;
    }
    if (needed_indices > index_capacity) {
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created;
      Diligent::BufferDesc desc{};
      desc.Name = "Poko ImGui indices";
      desc.Size = needed_indices * sizeof(ImDrawIdx);
      desc.BindFlags = Diligent::BIND_INDEX_BUFFER;
      desc.Usage = Diligent::USAGE_DYNAMIC;
      desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
      device.CreateBuffer(desc, nullptr, &created);
      if (!created || diagnostics.messages().errors) {
        index_buffer.Release(); index_capacity = 0;
        return RenderError::backend_failure;
      }
      index_buffer = std::move(created);
      index_capacity = needed_indices;
    }
    void* mapped_vertices = nullptr;
    context.MapBuffer(vertex_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped_vertices);
    if (!mapped_vertices) return RenderError::backend_failure;
    void* mapped_indices = nullptr;
    context.MapBuffer(index_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped_indices);
    if (!mapped_indices) {
      context.UnmapBuffer(vertex_buffer, Diligent::MAP_WRITE);
      return RenderError::backend_failure;
    }
    auto* out_vertices = static_cast<ImDrawVert*>(mapped_vertices);
    auto* out_indices = static_cast<ImDrawIdx*>(mapped_indices);
    std::size_t vertex_offset = 0, index_offset = 0;
    for (ImDrawList* list : draw_data->CmdLists) {
      const auto vertex_count = list->VtxBuffer.Size;
      const auto index_count = list->IdxBuffer.Size;
      if (vertex_offset + vertex_count > vertex_capacity ||
          index_offset + index_count > index_capacity) {
        context.UnmapBuffer(vertex_buffer, Diligent::MAP_WRITE);
        context.UnmapBuffer(index_buffer, Diligent::MAP_WRITE);
        return RenderError::backend_failure;
      }
      std::memcpy(out_vertices + vertex_offset, list->VtxBuffer.Data,
                  vertex_count * sizeof(ImDrawVert));
      if (index_count)
        std::memcpy(out_indices + index_offset, list->IdxBuffer.Data,
                    index_count * sizeof(ImDrawIdx));
      vertex_offset += vertex_count;
      index_offset += index_count;
    }
    context.UnmapBuffer(vertex_buffer, Diligent::MAP_WRITE);
    context.UnmapBuffer(index_buffer, Diligent::MAP_WRITE);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    // Per-list base offsets are needed while iterating commands.
    vertex_bases.clear(); index_bases.clear();
    vertex_offset = 0;
    index_offset = 0;
    for (ImDrawList* list : draw_data->CmdLists) {
      vertex_bases.push_back(vertex_offset);
      index_bases.push_back(index_offset);
      vertex_offset += list->VtxBuffer.Size;
      index_offset += list->IdxBuffer.Size;
    }
    return RenderError::none;
  }
  std::vector<std::size_t> vertex_bases, index_bases;
  RenderError ensure_pipeline(Diligent::IRenderDevice& device, Diligent::TEXTURE_FORMAT format) {
    if (pipeline && this->format == format) return RenderError::none;
    Diligent::RefCntAutoPtr<Diligent::IShader> vs, ps;
    Diligent::ShaderCreateInfo shader{};
    shader.Desc.Name = "Poko ImGui vertex"; shader.Desc.ShaderType = Diligent::SHADER_TYPE_VERTEX;
    shader.ByteCode = vertex.data(); shader.ByteCodeSize = vertex.size() * sizeof(std::uint32_t);
    device.CreateShader(shader, &vs);
    if (!vs || diagnostics.messages().errors) return RenderError::backend_failure;
    shader.Desc.Name = "Poko ImGui fragment"; shader.Desc.ShaderType = Diligent::SHADER_TYPE_PIXEL;
    shader.ByteCode = fragment.data(); shader.ByteCodeSize = fragment.size() * sizeof(std::uint32_t);
    device.CreateShader(shader, &ps);
    if (!vs || !ps || diagnostics.messages().errors) return RenderError::backend_failure;
    const Diligent::LayoutElement elements[] = {
        {"ATTRIB", 0, 0, 2, Diligent::VT_FLOAT32, true, 0, sizeof(ImDrawVert),
         Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX},
        {"ATTRIB", 1, 0, 2, Diligent::VT_FLOAT32, true, 8, sizeof(ImDrawVert),
         Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX},
        {"ATTRIB", 2, 0, 4, Diligent::VT_UINT8, true, 16, sizeof(ImDrawVert),
         Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX},
    };
    Diligent::GraphicsPipelineStateCreateInfo info{};
    info.PSODesc.Name = "Poko ImGui pipeline";
    info.GraphicsPipeline.InputLayout = {elements, 3};
    info.GraphicsPipeline.NumRenderTargets = 1;
    info.GraphicsPipeline.RTVFormats[0] = format;
    info.GraphicsPipeline.DSVFormat = Diligent::TEX_FORMAT_UNKNOWN;
    info.GraphicsPipeline.BlendDesc.IndependentBlendEnable = false;
    auto& blend = info.GraphicsPipeline.BlendDesc.RenderTargets[0];
    blend.BlendEnable = true;
    blend.SrcBlend = Diligent::BLEND_FACTOR_SRC_ALPHA;
    blend.DestBlend = Diligent::BLEND_FACTOR_INV_SRC_ALPHA;
    blend.BlendOp = Diligent::BLEND_OPERATION_ADD;
    blend.SrcBlendAlpha = Diligent::BLEND_FACTOR_ONE;
    blend.DestBlendAlpha = Diligent::BLEND_FACTOR_INV_SRC_ALPHA;
    blend.BlendOpAlpha = Diligent::BLEND_OPERATION_ADD;
    info.GraphicsPipeline.RasterizerDesc.CullMode = Diligent::CULL_MODE_NONE;
    info.GraphicsPipeline.RasterizerDesc.FillMode = Diligent::FILL_MODE_SOLID;
    info.GraphicsPipeline.RasterizerDesc.ScissorEnable = true;
    info.GraphicsPipeline.DepthStencilDesc.DepthEnable = false;
    info.GraphicsPipeline.DepthStencilDesc.DepthWriteEnable = false;
    info.GraphicsPipeline.PrimitiveTopology = Diligent::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    info.pVS = vs; info.pPS = ps;
    Diligent::RefCntAutoPtr<Diligent::IPipelineState> created;
    device.CreateGraphicsPipelineState(info, &created);
    if (!created || diagnostics.messages().errors) return RenderError::backend_failure;
    // Static resources: per-frame transform buffer and the font atlas view.
    auto* transform = created->GetStaticVariableByName(Diligent::SHADER_TYPE_VERTEX, "FrameData");
    if (!transform || diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::BufferDesc buffer_desc{};
    buffer_desc.Name = "Poko ImGui transform";
    buffer_desc.Size = 16;
    buffer_desc.BindFlags = Diligent::BIND_UNIFORM_BUFFER;
    buffer_desc.Usage = Diligent::USAGE_DYNAMIC;
    buffer_desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
    Diligent::RefCntAutoPtr<Diligent::IBuffer> created_frame_buffer;
    device.CreateBuffer(buffer_desc, nullptr, &created_frame_buffer);
    if (!created_frame_buffer || diagnostics.messages().errors) return RenderError::backend_failure;
    transform->Set(created_frame_buffer);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    auto* texture = created->GetStaticVariableByName(Diligent::SHADER_TYPE_PIXEL, "FontTexture");
    if (!texture || diagnostics.messages().errors) return RenderError::backend_failure;
    texture->Set(font_view);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> created_binding;
    created->CreateShaderResourceBinding(&created_binding, true);
    if (!created_binding || diagnostics.messages().errors) return RenderError::backend_failure;
    pipeline = std::move(created); this->format = format; owner = &device;
    frame_buffer = std::move(created_frame_buffer);
    binding = std::move(created_binding);
    return RenderError::none;
  }
  RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                   Diligent::ISwapChain& chain, Diligent::ITextureView& target) {
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (owner && owner != &device) return RenderError::backend_failure;
    if (!owner) owner = &device;  // Bind the device before any resource creation.
    ImGuiIO& io = ImGui::GetIO();
    ImDrawData* draw_data = ImGui::GetDrawData();
    if (!draw_data || !draw_data->Valid || draw_data->TotalVtxCount == 0 ||
        draw_data->TotalIdxCount == 0 || draw_data->DisplaySize.x <= 0.f || draw_data->DisplaySize.y <= 0.f)
      return RenderError::none;
    const auto& desc = chain.GetDesc();
    if (desc.ColorBufferFormat == Diligent::TEX_FORMAT_UNKNOWN) return RenderError::backend_failure;
    const auto setup = ensure_font(device, io);
    if (setup != RenderError::none) return setup;
    const auto buffers = ensure_buffers(device, context, draw_data);
    if (buffers != RenderError::none) return buffers;
    const auto pipe = ensure_pipeline(device, desc.ColorBufferFormat);
    if (pipe != RenderError::none) return pipe;
    // Display-space to clip space. Diligent's swapchain presents y-up (the
    // same convention that made the scene triangle look GL-style), so y is
    // negated relative to imgui_impl_vulkan's raw Vulkan transform. Vertex
    // positions are in display units; FramebufferScale applies only to
    // scissor rects.
    const float sx = 2.f / draw_data->DisplaySize.x;
    const float sy = -2.f / draw_data->DisplaySize.y;
    const float tx = -1.f - draw_data->DisplayPos.x * sx;
    const float ty = 1.f - draw_data->DisplayPos.y * sy;
    void* mapped = nullptr;
    context.MapBuffer(frame_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped);
    if (!mapped) return RenderError::backend_failure;
    const float transform[4] = {sx, sy, tx, ty};
    std::memcpy(mapped, transform, sizeof(transform));
    context.UnmapBuffer(frame_buffer, Diligent::MAP_WRITE);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    auto* view = &target;
    context.SetRenderTargets(1, &view, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::Viewport viewport{0.f, 0.f, static_cast<float>(desc.Width), static_cast<float>(desc.Height)};
    context.SetViewports(1, &viewport, 0, 0);
    context.SetPipelineState(pipeline);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    context.CommitShaderResources(binding, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    Diligent::IBuffer* vertex_slot = vertex_buffer;
    const Diligent::Uint64 vertex_offset = 0;
    context.SetVertexBuffers(0, 1, &vertex_slot, &vertex_offset,
                             Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    context.SetIndexBuffer(index_buffer, 0, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    const float fb_w = static_cast<float>(desc.Width), fb_h = static_cast<float>(desc.Height);
    std::size_t list_index = 0;
    for (ImDrawList* list : draw_data->CmdLists) {
      const auto vertex_base = vertex_bases[list_index];
      const auto index_base = index_bases[list_index];
      ++list_index;
      for (const ImDrawCmd& cmd : list->CmdBuffer) {
        // Callback commands carry ElemCount == 0, so they must be handled
        // before the empty-command skip or ResetRenderState is dead code.
        if (cmd.UserCallback) {
          if (cmd.UserCallback != ImDrawCallback_ResetRenderState)
            return RenderError::backend_failure;
          context.SetPipelineState(pipeline);
          context.CommitShaderResources(binding, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
          context.SetVertexBuffers(0, 1, &vertex_slot, &vertex_offset,
                                   Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
          context.SetIndexBuffer(index_buffer, 0, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
          context.SetViewports(1, &viewport, 0, 0);
          const Diligent::Rect full{0, 0, static_cast<Diligent::Int32>(fb_w),
                                    static_cast<Diligent::Int32>(fb_h)};
          context.SetScissorRects(1, &full, desc.Width, desc.Height);
          if (diagnostics.messages().errors) return RenderError::backend_failure;
        }
        if (cmd.ElemCount == 0) continue;
        if (cmd.GetTexID() != font_tex_id) return RenderError::backend_failure;
        const float x1 = (cmd.ClipRect.x - draw_data->DisplayPos.x) * draw_data->FramebufferScale.x;
        const float y1 = (cmd.ClipRect.y - draw_data->DisplayPos.y) * draw_data->FramebufferScale.y;
        const float x2 = (cmd.ClipRect.z - draw_data->DisplayPos.x) * draw_data->FramebufferScale.x;
        const float y2 = (cmd.ClipRect.w - draw_data->DisplayPos.y) * draw_data->FramebufferScale.y;
        const Diligent::Int32 left = static_cast<Diligent::Int32>(std::clamp(x1, 0.f, fb_w));
        const Diligent::Int32 top = static_cast<Diligent::Int32>(std::clamp(y1, 0.f, fb_h));
        const Diligent::Int32 right = static_cast<Diligent::Int32>(std::clamp(x2, 0.f, fb_w));
        const Diligent::Int32 bottom = static_cast<Diligent::Int32>(std::clamp(y2, 0.f, fb_h));
        if (right <= left || bottom <= top) continue;
        const Diligent::Rect scissor{left, top, right, bottom};
        context.SetScissorRects(1, &scissor, desc.Width, desc.Height);
        Diligent::DrawIndexedAttribs attribs{};
        attribs.NumIndices = cmd.ElemCount;
        attribs.IndexType = Diligent::VT_UINT16;
        attribs.FirstIndexLocation = static_cast<Diligent::Uint32>(index_base + cmd.IdxOffset);
        attribs.BaseVertex = static_cast<Diligent::Uint32>(vertex_base + cmd.VtxOffset);
        context.DrawIndexed(attribs);
        if (diagnostics.messages().errors) return RenderError::backend_failure;
      }
    }
    return RenderError::none;
  }
};
VulkanImGuiPass::VulkanImGuiPass(const std::string& vs, const std::string& fs, VulkanDiagnostics& d)
    : impl_(std::make_unique<Impl>(vs, fs, d)) {}
VulkanImGuiPass::~VulkanImGuiPass() = default;
RenderError VulkanImGuiPass::draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                  Diligent::ISwapChain& chain, Diligent::ITextureView& target) noexcept {
  try {
    return impl_->draw(device, context, chain, target);
  } catch (...) {
    return RenderError::backend_failure;
  }
}
}  // namespace poko::rhi
