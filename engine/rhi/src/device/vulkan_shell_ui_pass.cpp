#include "poko/rhi/device/vulkan_shell_ui_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "read_spirv.hpp"

#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>

#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace poko::rhi {

namespace {
constexpr std::size_t kShellVertexFloats = 6;
constexpr std::size_t kShellVertexStride = kShellVertexFloats * sizeof(float);

struct TextureEntry {
  Diligent::RefCntAutoPtr<Diligent::ITexture> texture;
  Diligent::RefCntAutoPtr<Diligent::ITextureView> view;
};
}  // namespace

struct VulkanShellUiPass::Impl {
  std::vector<std::uint32_t> vertex_spirv;
  std::vector<std::uint32_t> fragment_spirv;
  VulkanDiagnostics& diagnostics;
  Diligent::IRenderDevice* owner = nullptr;
  Diligent::TEXTURE_FORMAT format = Diligent::TEX_FORMAT_UNKNOWN;
  Diligent::RefCntAutoPtr<Diligent::IPipelineState> pipeline;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> frame_buffer;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> vertex_buffer;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> index_buffer;
  Diligent::RefCntAutoPtr<Diligent::ISampler> sampler;
  Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> binding;
  std::unordered_map<std::uint64_t, TextureEntry> textures;
  std::size_t vertex_capacity = 0;
  std::size_t index_capacity = 0;

  Impl(const std::string& vs, const std::string& fs, VulkanDiagnostics& d)
      : vertex_spirv(detail::read_spirv(vs)),
        fragment_spirv(detail::read_spirv(fs)),
        diagnostics(d) {}

  RenderError ensure_sampler(Diligent::IRenderDevice& device) {
    if (sampler) return RenderError::none;
    Diligent::SamplerDesc desc{};
    desc.Name = "Poko Shell UI sampler";
    desc.MinFilter = Diligent::FILTER_TYPE_LINEAR;
    desc.MagFilter = Diligent::FILTER_TYPE_LINEAR;
    desc.MipFilter = Diligent::FILTER_TYPE_LINEAR;
    desc.AddressU = Diligent::TEXTURE_ADDRESS_CLAMP;
    desc.AddressV = Diligent::TEXTURE_ADDRESS_CLAMP;
    desc.AddressW = Diligent::TEXTURE_ADDRESS_CLAMP;
    Diligent::RefCntAutoPtr<Diligent::ISampler> created;
    device.CreateSampler(desc, &created);
    if (!created || diagnostics.messages().errors) return RenderError::backend_failure;
    sampler = std::move(created);
    return RenderError::none;
  }

  RenderError apply_texture_deltas(Diligent::IRenderDevice& device,
                                   const ShellTextureDelta* updates,
                                   std::uint32_t update_count,
                                   const std::uint8_t* pixels,
                                   std::uint32_t pixel_bytes) {
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (owner && owner != &device) return RenderError::backend_failure;
    if (!owner) owner = &device;
    if (update_count == 0) return RenderError::none;
    if (!updates) return RenderError::backend_failure;
    if (ensure_sampler(device) != RenderError::none) return RenderError::backend_failure;

    for (std::uint32_t i = 0; i < update_count; ++i) {
      const auto& u = updates[i];
      if (u.pixels_len == 0) {
        textures.erase(u.id);
        continue;
      }
      if (!pixels || u.width == 0 || u.height == 0) return RenderError::backend_failure;
      const std::uint64_t end_offset =
          static_cast<std::uint64_t>(u.pixels_offset) + u.pixels_len;
      const std::uint64_t min_bytes =
          static_cast<std::uint64_t>(u.width) * u.height * 4u;
      if (end_offset > pixel_bytes || u.pixels_len < min_bytes) {
        return RenderError::backend_failure;
      }

      Diligent::TextureDesc desc{};
      desc.Name = "Poko Shell UI texture";
      desc.Type = Diligent::RESOURCE_DIM_TEX_2D;
      desc.Width = u.width;
      desc.Height = u.height;
      desc.Format = Diligent::TEX_FORMAT_RGBA8_UNORM;
      desc.MipLevels = 1;
      desc.ArraySize = 1;
      desc.BindFlags = Diligent::BIND_SHADER_RESOURCE;
      desc.Usage = Diligent::USAGE_IMMUTABLE;

      Diligent::TextureSubResData sub{};
      sub.pData = pixels + u.pixels_offset;
      sub.Stride = static_cast<Diligent::Uint64>(u.width) * 4u;
      Diligent::TextureSubResData subs[1] = {sub};
      Diligent::TextureData initial{subs, 1};

      Diligent::RefCntAutoPtr<Diligent::ITexture> tex;
      device.CreateTexture(desc, &initial, &tex);
      if (!tex || diagnostics.messages().errors) return RenderError::backend_failure;

      Diligent::TextureViewDesc view_desc{};
      view_desc.ViewType = Diligent::TEXTURE_VIEW_SHADER_RESOURCE;
      Diligent::RefCntAutoPtr<Diligent::ITextureView> view;
      tex->CreateView(view_desc, &view);
      if (!view || diagnostics.messages().errors) return RenderError::backend_failure;
      view->SetSampler(sampler);
      if (diagnostics.messages().errors) return RenderError::backend_failure;

      textures[u.id] = TextureEntry{std::move(tex), std::move(view)};
    }
    return RenderError::none;
  }

  RenderError ensure_buffers(Diligent::IRenderDevice& device,
                             Diligent::IDeviceContext& context,
                             const float* vertices_6f,
                             std::uint32_t vertex_count,
                             const std::uint32_t* indices,
                             std::uint32_t index_count) {
    if (vertex_count > vertex_capacity) {
      Diligent::BufferDesc desc{};
      desc.Name = "Poko Shell UI vertices";
      desc.Size = static_cast<Diligent::Uint64>(vertex_count) * kShellVertexStride;
      desc.BindFlags = Diligent::BIND_VERTEX_BUFFER;
      desc.Usage = Diligent::USAGE_DYNAMIC;
      desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created;
      device.CreateBuffer(desc, nullptr, &created);
      if (!created || diagnostics.messages().errors) {
        vertex_buffer.Release();
        vertex_capacity = 0;
        return RenderError::backend_failure;
      }
      vertex_buffer = std::move(created);
      vertex_capacity = vertex_count;
    }
    if (index_count > index_capacity) {
      Diligent::BufferDesc desc{};
      desc.Name = "Poko Shell UI indices";
      desc.Size = static_cast<Diligent::Uint64>(index_count) * sizeof(std::uint32_t);
      desc.BindFlags = Diligent::BIND_INDEX_BUFFER;
      desc.Usage = Diligent::USAGE_DYNAMIC;
      desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created;
      device.CreateBuffer(desc, nullptr, &created);
      if (!created || diagnostics.messages().errors) {
        index_buffer.Release();
        index_capacity = 0;
        return RenderError::backend_failure;
      }
      index_buffer = std::move(created);
      index_capacity = index_count;
    }

    void* mapped_v = nullptr;
    context.MapBuffer(vertex_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped_v);
    if (!mapped_v) return RenderError::backend_failure;
    void* mapped_i = nullptr;
    context.MapBuffer(index_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped_i);
    if (!mapped_i) {
      context.UnmapBuffer(vertex_buffer, Diligent::MAP_WRITE);
      return RenderError::backend_failure;
    }

    std::memcpy(mapped_v, vertices_6f, static_cast<std::size_t>(vertex_count) * kShellVertexStride);
    std::memcpy(mapped_i, indices, static_cast<std::size_t>(index_count) * sizeof(std::uint32_t));
    context.UnmapBuffer(vertex_buffer, Diligent::MAP_WRITE);
    context.UnmapBuffer(index_buffer, Diligent::MAP_WRITE);
    return diagnostics.messages().errors ? RenderError::backend_failure : RenderError::none;
  }

  RenderError ensure_pipeline(Diligent::IRenderDevice& device, Diligent::TEXTURE_FORMAT target_fmt) {
    if (pipeline && format == target_fmt) return RenderError::none;

    Diligent::RefCntAutoPtr<Diligent::IShader> vs, ps;
    Diligent::ShaderCreateInfo shader{};
    shader.Desc.Name = "Poko Shell UI vertex";
    shader.Desc.ShaderType = Diligent::SHADER_TYPE_VERTEX;
    shader.ByteCode = vertex_spirv.data();
    shader.ByteCodeSize = vertex_spirv.size() * sizeof(std::uint32_t);
    device.CreateShader(shader, &vs);
    if (!vs || diagnostics.messages().errors) return RenderError::backend_failure;

    shader.Desc.Name = "Poko Shell UI fragment";
    shader.Desc.ShaderType = Diligent::SHADER_TYPE_PIXEL;
    shader.ByteCode = fragment_spirv.data();
    shader.ByteCodeSize = fragment_spirv.size() * sizeof(std::uint32_t);
    device.CreateShader(shader, &ps);
    if (!ps || diagnostics.messages().errors) return RenderError::backend_failure;

    const Diligent::LayoutElement elements[] = {
        {"ATTRIB", 0, 0, 3, Diligent::VT_FLOAT32, false, 0, kShellVertexStride,
         Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX},
        {"ATTRIB", 1, 0, 3, Diligent::VT_FLOAT32, false, 12, kShellVertexStride,
         Diligent::INPUT_ELEMENT_FREQUENCY_PER_VERTEX},
    };
    Diligent::GraphicsPipelineStateCreateInfo info{};
    info.PSODesc.Name = "Poko Shell UI pipeline";
    info.GraphicsPipeline.InputLayout = {elements, 2};
    info.GraphicsPipeline.NumRenderTargets = 1;
    info.GraphicsPipeline.RTVFormats[0] = target_fmt;
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
    info.pVS = vs;
    info.pPS = ps;

    Diligent::RefCntAutoPtr<Diligent::IPipelineState> created;
    device.CreateGraphicsPipelineState(info, &created);
    if (!created || diagnostics.messages().errors) return RenderError::backend_failure;

    auto* transform = created->GetStaticVariableByName(Diligent::SHADER_TYPE_VERTEX, "FrameData");
    if (!transform || diagnostics.messages().errors) return RenderError::backend_failure;

    Diligent::BufferDesc buf_desc{};
    buf_desc.Name = "Poko Shell UI transform";
    buf_desc.Size = 16;
    buf_desc.BindFlags = Diligent::BIND_UNIFORM_BUFFER;
    buf_desc.Usage = Diligent::USAGE_DYNAMIC;
    buf_desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
    Diligent::RefCntAutoPtr<Diligent::IBuffer> created_fb;
    device.CreateBuffer(buf_desc, nullptr, &created_fb);
    if (!created_fb || diagnostics.messages().errors) return RenderError::backend_failure;
    transform->Set(created_fb);
    if (diagnostics.messages().errors) return RenderError::backend_failure;

    if (auto* font_var = created->GetStaticVariableByName(Diligent::SHADER_TYPE_PIXEL, "FontTexture")) {
      auto it = textures.find(0);
      if (it != textures.end() && it->second.view) {
        font_var->Set(it->second.view);
      }
    }

    Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> created_srb;
    created->CreateShaderResourceBinding(&created_srb, true);
    if (!created_srb || diagnostics.messages().errors) return RenderError::backend_failure;

    pipeline = std::move(created);
    format = target_fmt;
    owner = &device;
    frame_buffer = std::move(created_fb);
    binding = std::move(created_srb);
    return RenderError::none;
  }

  RenderError draw(Diligent::IRenderDevice& device,
                   Diligent::IDeviceContext& context,
                   Diligent::ISwapChain& chain,
                   Diligent::ITextureView& target,
                   const float* vertices_6f,
                   std::uint32_t vertex_count,
                   const std::uint32_t* indices,
                   std::uint32_t index_count,
                   std::uint32_t viewport_width,
                   std::uint32_t viewport_height) {
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (owner && owner != &device) return RenderError::backend_failure;
    if (!owner) owner = &device;
    if (vertex_count == 0 || index_count == 0) return RenderError::none;
    if (!vertices_6f || !indices || viewport_width == 0 || viewport_height == 0) {
      return RenderError::backend_failure;
    }

    const auto& desc = chain.GetDesc();
    if (desc.ColorBufferFormat == Diligent::TEX_FORMAT_UNKNOWN) {
      return RenderError::backend_failure;
    }

    if (ensure_buffers(device, context, vertices_6f, vertex_count, indices, index_count) !=
        RenderError::none) {
      return RenderError::backend_failure;
    }
    if (ensure_pipeline(device, desc.ColorBufferFormat) != RenderError::none) {
      return RenderError::backend_failure;
    }

    void* mapped_frame = nullptr;
    context.MapBuffer(frame_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped_frame);
    if (!mapped_frame) return RenderError::backend_failure;
    const float frame_constants[4] = {
        2.0f / static_cast<float>(viewport_width),
        -2.0f / static_cast<float>(viewport_height),
        -1.0f,
        1.0f,
    };
    std::memcpy(mapped_frame, frame_constants, sizeof(frame_constants));
    context.UnmapBuffer(frame_buffer, Diligent::MAP_WRITE);

    Diligent::ITextureView* targets[] = {&target};
    context.SetRenderTargets(1, targets, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

    Diligent::Viewport vp{};
    vp.Width = static_cast<float>(desc.Width > 0 ? desc.Width : viewport_width);
    vp.Height = static_cast<float>(desc.Height > 0 ? desc.Height : viewport_height);
    vp.MaxDepth = 1.0f;
    context.SetViewports(1, &vp, desc.Width, desc.Height);

    Diligent::Rect scissor{};
    scissor.Left = 0;
    scissor.Top = 0;
    scissor.Right = static_cast<Diligent::Int32>(desc.Width > 0 ? desc.Width : viewport_width);
    scissor.Bottom = static_cast<Diligent::Int32>(desc.Height > 0 ? desc.Height : viewport_height);
    context.SetScissorRects(1, &scissor, desc.Width, desc.Height);

    context.SetPipelineState(pipeline);
    context.CommitShaderResources(binding, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

    Diligent::IBuffer* vb[] = {vertex_buffer};
    Diligent::Uint64 offsets[] = {0};
    context.SetVertexBuffers(0, 1, vb, offsets,
                             Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    context.SetIndexBuffer(index_buffer, 0, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

    Diligent::DrawIndexedAttribs draw_attribs{};
    draw_attribs.NumIndices = index_count;
    draw_attribs.IndexType = Diligent::VT_UINT32;
    draw_attribs.Flags = Diligent::DRAW_FLAG_NONE;
    context.DrawIndexed(draw_attribs);

    return diagnostics.messages().errors ? RenderError::backend_failure : RenderError::none;
  }
};

VulkanShellUiPass::VulkanShellUiPass(const std::string& vertex_path,
                                     const std::string& fragment_path,
                                     VulkanDiagnostics& diagnostics)
    : impl_(std::make_unique<Impl>(vertex_path, fragment_path, diagnostics)) {}

VulkanShellUiPass::~VulkanShellUiPass() = default;

RenderError VulkanShellUiPass::apply_texture_deltas(
    Diligent::IRenderDevice& device,
    const ShellTextureDelta* updates,
    std::uint32_t update_count,
    const std::uint8_t* pixels,
    std::uint32_t pixel_bytes) noexcept {
  try {
    return impl_->apply_texture_deltas(device, updates, update_count, pixels, pixel_bytes);
  } catch (...) {
    return RenderError::backend_failure;
  }
}

RenderError VulkanShellUiPass::draw(Diligent::IRenderDevice& device,
                                    Diligent::IDeviceContext& context,
                                    Diligent::ISwapChain& chain,
                                    Diligent::ITextureView& target,
                                    const float* vertices_6f,
                                    std::uint32_t vertex_count,
                                    const std::uint32_t* indices,
                                    std::uint32_t index_count,
                                    std::uint32_t viewport_width,
                                    std::uint32_t viewport_height) noexcept {
  try {
    return impl_->draw(device, context, chain, target, vertices_6f, vertex_count,
                       indices, index_count, viewport_width, viewport_height);
  } catch (...) {
    return RenderError::backend_failure;
  }
}

}  // namespace poko::rhi
