#include "poko/rhi/device/vulkan_triangle_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "read_spirv.hpp"
#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>
#if __has_include(<Sampler.h>)
#include <Sampler.h>
#endif
#if __has_include(<Texture.h>)
#include <Texture.h>
#endif
#include <cstdint>
#include <cstring>
#include <limits>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

namespace poko::rhi {
namespace {
static_assert(sizeof(float) == 4, "std140 frame color requires 32-bit floats");
}
struct VulkanTrianglePass::Impl {
  std::vector<std::uint32_t> vertex, fragment;
  VulkanDiagnostics& diagnostics;
  Diligent::RefCntAutoPtr<Diligent::IPipelineState> pipeline;
  Diligent::RefCntAutoPtr<Diligent::IBuffer> uniform_buffer;
  Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> binding;
  Diligent::TEXTURE_FORMAT format = Diligent::TEX_FORMAT_UNKNOWN;
  Diligent::TEXTURE_FORMAT depth_format = Diligent::TEX_FORMAT_UNKNOWN;
  Diligent::IRenderDevice* owner = nullptr;
  TriangleMode mode;
  // ENG-18 textured mode: CPU copies until first draw, then GPU objects.
  std::vector<std::vector<std::uint8_t>> tex_levels;
  std::vector<std::uint32_t> tex_level_w, tex_level_h;
  std::uint32_t tex_width = 0, tex_height = 0;
  bool tex_bgra = false, tex_srgb = false, tex_uploaded = false;
  Diligent::RefCntAutoPtr<Diligent::ITexture> texture;
  Diligent::RefCntAutoPtr<Diligent::ISampler> sampler;
  Diligent::ITextureView* tex_view = nullptr;  // owned by texture, no AddRef
  Impl(const std::string& vs, const std::string& fs, VulkanDiagnostics& d, TriangleMode m)
      : vertex(detail::read_spirv(vs)), fragment(detail::read_spirv(fs)), diagnostics(d), mode(m) {}
  RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                   Diligent::ISwapChain& chain, Diligent::ITextureView& target, const std::array<float, 4>& color) {
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (owner && owner != &device) return RenderError::backend_failure;
    const bool has_depth = mode == TriangleMode::depth_test ||
                           mode == TriangleMode::depth_disabled_control ||
                           mode == TriangleMode::uniform_depth;
    const bool textured = mode == TriangleMode::textured;
    const auto& desc = chain.GetDesc();
    const auto current_format = desc.ColorBufferFormat;
    const auto current_depth_format = has_depth ? desc.DepthBufferFormat : Diligent::TEX_FORMAT_UNKNOWN;
    auto* depth_view = has_depth ? chain.GetDepthBufferDSV() : nullptr;
    if (current_format == Diligent::TEX_FORMAT_UNKNOWN ||
        (has_depth && (current_depth_format == Diligent::TEX_FORMAT_UNKNOWN || !depth_view)))
      return RenderError::backend_failure;
    // Bind before any GPU allocation, even if initialization later fails.
    owner = &device;
    if (textured && !tex_levels.empty() && !tex_uploaded) {
      // ENG-18: one-time upload of the CPU-side pixels supplied via
      // set_texture(). Runs inside draw() where device+context exist, and
      // BEFORE pipeline creation so the static 'Tex' variable can be bound
      // while the shader-resource binding snapshots its constants.
      Diligent::TextureDesc tdesc{};
      tdesc.Name = "Poko textured quad";
      tdesc.Type = Diligent::RESOURCE_DIM_TEX_2D;
      tdesc.Format = tex_bgra ? (tex_srgb ? Diligent::TEX_FORMAT_BGRA8_UNORM_SRGB
                                          : Diligent::TEX_FORMAT_BGRA8_UNORM)
                              : (tex_srgb ? Diligent::TEX_FORMAT_RGBA8_UNORM_SRGB
                                          : Diligent::TEX_FORMAT_RGBA8_UNORM);
      tdesc.Width = tex_width; tdesc.Height = tex_height;
      tdesc.MipLevels = static_cast<Diligent::Uint32>(tex_levels.size()); tdesc.ArraySize = 1;
      tdesc.Usage = Diligent::USAGE_DEFAULT;
      tdesc.BindFlags = Diligent::BIND_SHADER_RESOURCE;
      Diligent::RefCntAutoPtr<Diligent::ITexture> created_texture;
      Diligent::RefCntAutoPtr<Diligent::ISampler> created_sampler;
      device.CreateTexture(tdesc, nullptr, &created_texture);
      if (!created_texture || diagnostics.messages().errors) return RenderError::backend_failure;
      Diligent::SamplerDesc sdesc{};
      sdesc.Name = "Poko textured quad sampler";
      sdesc.MinFilter = Diligent::FILTER_TYPE_LINEAR;
      sdesc.MagFilter = Diligent::FILTER_TYPE_LINEAR;
      sdesc.MipFilter = Diligent::FILTER_TYPE_LINEAR;
      sdesc.AddressU = Diligent::TEXTURE_ADDRESS_CLAMP;
      sdesc.AddressV = Diligent::TEXTURE_ADDRESS_CLAMP;
      sdesc.AddressW = Diligent::TEXTURE_ADDRESS_CLAMP;
      device.CreateSampler(sdesc, &created_sampler);
      if (!created_sampler || diagnostics.messages().errors) return RenderError::backend_failure;
      auto* created_view = created_texture->GetDefaultView(Diligent::TEXTURE_VIEW_SHADER_RESOURCE);
      if (!created_view || diagnostics.messages().errors) return RenderError::backend_failure;
      created_view->SetSampler(created_sampler);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
      for (Diligent::Uint32 level = 0; level < tex_levels.size(); ++level) {
        const auto lw = tex_level_w[level], lh = tex_level_h[level];
        Diligent::Box box{0, lw, 0, lh, 0, 1};
        Diligent::TextureSubResData sub{};
        sub.pData = tex_levels[level].data();
        sub.Stride = static_cast<Diligent::Uint64>(lw) * 4;
        sub.DepthStride = static_cast<Diligent::Uint64>(lw) * lh * 4;
        context.UpdateTexture(created_texture, level, 0, box, sub,
                              Diligent::RESOURCE_STATE_TRANSITION_MODE_NONE,
                              Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
        if (diagnostics.messages().errors) return RenderError::backend_failure;
      }
      texture = std::move(created_texture);
      sampler = std::move(created_sampler);
      tex_view = created_view;
      tex_uploaded = true;
    }
    if (!pipeline || format != current_format || depth_format != current_depth_format) {
      Diligent::RefCntAutoPtr<Diligent::IShader> vs, ps;
      Diligent::ShaderCreateInfo shader{};
      shader.Desc.Name = "Poko triangle vertex"; shader.Desc.ShaderType = Diligent::SHADER_TYPE_VERTEX;
      shader.ByteCode = vertex.data(); shader.ByteCodeSize = vertex.size() * sizeof(std::uint32_t);
      device.CreateShader(shader, &vs);
      if (!vs || diagnostics.messages().errors) return RenderError::backend_failure;
      shader.Desc.Name = "Poko triangle fragment"; shader.Desc.ShaderType = Diligent::SHADER_TYPE_PIXEL;
      shader.ByteCode = fragment.data(); shader.ByteCodeSize = fragment.size() * sizeof(std::uint32_t);
      device.CreateShader(shader, &ps);
      if (!vs || !ps || diagnostics.messages().errors) return RenderError::backend_failure;
      Diligent::GraphicsPipelineStateCreateInfo info{};
      info.PSODesc.Name = "Poko triangle pipeline";
      info.GraphicsPipeline.NumRenderTargets = 1;
      info.GraphicsPipeline.RTVFormats[0] = current_format;
      info.GraphicsPipeline.DepthStencilDesc.DepthEnable = mode == TriangleMode::depth_test || mode == TriangleMode::uniform_depth;
      info.GraphicsPipeline.DepthStencilDesc.DepthWriteEnable = mode == TriangleMode::depth_test || mode == TriangleMode::uniform_depth;
      info.GraphicsPipeline.DepthStencilDesc.DepthFunc = Diligent::COMPARISON_FUNC_LESS;
      info.GraphicsPipeline.DSVFormat = current_depth_format;
      info.GraphicsPipeline.RasterizerDesc.CullMode = Diligent::CULL_MODE_NONE;
      info.GraphicsPipeline.PrimitiveTopology = Diligent::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
      info.pVS = vs; info.pPS = ps;
      Diligent::RefCntAutoPtr<Diligent::IPipelineState> created;
      device.CreateGraphicsPipelineState(info, &created);
      if (!created || diagnostics.messages().errors) return RenderError::backend_failure;
      Diligent::RefCntAutoPtr<Diligent::IBuffer> created_buffer;
      Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding> created_binding;
      if (mode == TriangleMode::uniform_depth || textured) {
        if (mode == TriangleMode::uniform_depth) {
          Diligent::BufferDesc buffer_desc{};
          buffer_desc.Name = "Poko per-frame color";
          buffer_desc.Size = sizeof(float) * 4;
          buffer_desc.BindFlags = Diligent::BIND_UNIFORM_BUFFER;
          buffer_desc.Usage = Diligent::USAGE_DYNAMIC;
          buffer_desc.CPUAccessFlags = Diligent::CPU_ACCESS_WRITE;
          device.CreateBuffer(buffer_desc, nullptr, &created_buffer);
          if (!created_buffer || diagnostics.messages().errors) return RenderError::backend_failure;
          auto* variable = created->GetStaticVariableByName(Diligent::SHADER_TYPE_PIXEL, "FrameData");
          if (!variable || diagnostics.messages().errors) return RenderError::backend_failure;
          variable->Set(created_buffer);
          if (diagnostics.messages().errors) return RenderError::backend_failure;
        }
        if (textured && tex_view) {
          auto* variable = created->GetStaticVariableByName(Diligent::SHADER_TYPE_PIXEL, "Tex");
          if (!variable || diagnostics.messages().errors) return RenderError::backend_failure;
          variable->Set(tex_view);
          if (diagnostics.messages().errors) return RenderError::backend_failure;
        }
        created->CreateShaderResourceBinding(&created_binding, true);
        if (!created_binding || diagnostics.messages().errors) return RenderError::backend_failure;
      }
      pipeline = std::move(created); uniform_buffer = std::move(created_buffer);
      binding = std::move(created_binding); format = current_format;
      depth_format = current_depth_format; owner = &device;
    }
    auto* view = &target;
    context.SetRenderTargets(1, &view, depth_view, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    constexpr float background[4] = {0.035f, 0.12f, 0.28f, 1.f};
    context.ClearRenderTarget(view, background, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (depth_view) {
      context.ClearDepthStencil(depth_view, Diligent::CLEAR_DEPTH_FLAG, 1.0f, 0,
                                Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
    }
    if (mode == TriangleMode::uniform_depth) {
      void* mapped = nullptr;
      context.MapBuffer(uniform_buffer, Diligent::MAP_WRITE, Diligent::MAP_FLAG_DISCARD, mapped);
      if (!mapped) return RenderError::backend_failure;
      if (!diagnostics.messages().errors) std::memcpy(mapped, color.data(), sizeof(float) * color.size());
      context.UnmapBuffer(uniform_buffer, Diligent::MAP_WRITE);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
    }
    context.SetPipelineState(pipeline);
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (mode == TriangleMode::uniform_depth || textured) {
      context.CommitShaderResources(binding, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
    }
    Diligent::DrawAttribs draw{}; draw.NumVertices = (has_depth || textured) ? 6 : 3; draw.Flags = Diligent::DRAW_FLAG_VERIFY_ALL;
    context.Draw(draw);
    return diagnostics.messages().errors ? RenderError::backend_failure : RenderError::none;
  }
};
VulkanTrianglePass::VulkanTrianglePass(const std::string& vs, const std::string& fs, VulkanDiagnostics& d, TriangleMode mode)
    : impl_(std::make_unique<Impl>(vs, fs, d, mode)) {}
VulkanTrianglePass::~VulkanTrianglePass() = default;
RenderError VulkanTrianglePass::draw_and_present(VulkanClearRenderer& renderer) noexcept {
  return draw_and_present(renderer, {1.f, 0.f, 0.f, 1.f});
}
RenderError VulkanTrianglePass::draw_and_present(VulkanClearRenderer& renderer,
                                                  const std::array<float, 4>& color) noexcept {
  struct Call { Impl* impl; const std::array<float, 4>* color; } call{impl_.get(), &color};
  return renderer.draw_and_present([](Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                      Diligent::ISwapChain& chain, Diligent::ITextureView& target, void* user) {
    const auto& args = *static_cast<Call*>(user);
    return args.impl->draw(device, context, chain, target, *args.color);
  }, &call);
}
RenderError VulkanTrianglePass::draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                     Diligent::ISwapChain& chain, Diligent::ITextureView& target) noexcept {
  return draw(device, context, chain, target, {1.f, 0.f, 0.f, 1.f});
}
void VulkanTrianglePass::set_texture(const void* pixels, std::uint32_t width,
                                     std::uint32_t height, bool bgra) {
  const TextureMip mip{pixels, width, height};
  set_texture_mips(&mip, 1, bgra);
}
void VulkanTrianglePass::set_texture_mips(const TextureMip* mips, std::size_t count,
                                          bool bgra, bool srgb) {
  auto& impl = *impl_;
  std::vector<std::vector<std::uint8_t>> levels;
  std::vector<std::uint32_t> widths, heights;
  bool valid = mips && count && count <= 32;
  std::uint32_t expected_w = valid ? mips[0].width : 0;
  std::uint32_t expected_h = valid ? mips[0].height : 0;
  for (std::size_t i = 0; valid && i < count; ++i) {
    const auto& mip = mips[i];
    valid = mip.pixels && mip.width && mip.height &&
        mip.width == expected_w && mip.height == expected_h &&
        static_cast<std::size_t>(mip.width) <=
            std::numeric_limits<std::size_t>::max() / 4 / mip.height;
    if (!valid) break;
    const std::size_t bytes = static_cast<std::size_t>(mip.width) * mip.height * 4;
    const auto* begin = static_cast<const std::uint8_t*>(mip.pixels);
    levels.emplace_back(begin, begin + bytes);
    widths.push_back(mip.width); heights.push_back(mip.height);
    if (i + 1 < count && expected_w == 1 && expected_h == 1) valid = false;
    expected_w = std::max<std::uint32_t>(1, expected_w / 2);
    expected_h = std::max<std::uint32_t>(1, expected_h / 2);
  }
  if (!valid) { levels.clear(); widths.clear(); heights.clear(); }
  impl.tex_levels.swap(levels); impl.tex_level_w.swap(widths); impl.tex_level_h.swap(heights);
  impl.tex_width = impl.tex_levels.empty() ? 0 : impl.tex_level_w.front();
  impl.tex_height = impl.tex_levels.empty() ? 0 : impl.tex_level_h.front();
  impl.tex_bgra = bgra; impl.tex_srgb = srgb; impl.tex_uploaded = false;
  // Static texture bindings are captured by the SRB; a replacement must
  // rebuild the pipeline/binding rather than continue sampling the old view.
  impl.pipeline = Diligent::RefCntAutoPtr<Diligent::IPipelineState>();
  impl.binding = Diligent::RefCntAutoPtr<Diligent::IShaderResourceBinding>();
  impl.texture = Diligent::RefCntAutoPtr<Diligent::ITexture>();
  impl.sampler = Diligent::RefCntAutoPtr<Diligent::ISampler>();
  impl.tex_view = nullptr;
}
RenderError VulkanTrianglePass::draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                     Diligent::ISwapChain& chain, Diligent::ITextureView& target,
                                     const std::array<float, 4>& color) noexcept {
  try {
    return impl_->draw(device, context, chain, target, color);
  } catch (...) {
    return RenderError::backend_failure;
  }
}
}
