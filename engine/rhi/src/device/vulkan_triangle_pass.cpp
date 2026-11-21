#include "poko/rhi/device/vulkan_triangle_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace poko::rhi {
namespace {
static_assert(sizeof(float) == 4, "std140 frame color requires 32-bit floats");
std::vector<std::uint32_t> read_spirv(const std::string& path) {
  constexpr std::streamoff max_bytes = 16 * 1024 * 1024;
  std::ifstream file(path, std::ios::binary | std::ios::ate);
  if (!file) throw std::runtime_error("Cannot open shader: " + path);
  const auto length = file.tellg();
  if (length < 20 || length > max_bytes || length % 4 != 0)
    throw std::runtime_error("Invalid SPIR-V size: " + path);
  std::vector<std::uint32_t> words(static_cast<std::size_t>(length) / 4);
  file.seekg(0);
  if (!file.read(reinterpret_cast<char*>(words.data()), length) || words[0] != 0x07230203U)
    throw std::runtime_error("Invalid SPIR-V data or byte order: " + path);
  return words;
}
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
  Impl(const std::string& vs, const std::string& fs, VulkanDiagnostics& d, TriangleMode m)
      : vertex(read_spirv(vs)), fragment(read_spirv(fs)), diagnostics(d), mode(m) {}
  RenderError draw(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                   Diligent::ISwapChain& chain, Diligent::ITextureView& target, const std::array<float, 4>& color) {
    if (diagnostics.messages().errors) return RenderError::backend_failure;
    if (owner && owner != &device) return RenderError::backend_failure;
    const bool has_depth = mode != TriangleMode::color;
    const auto& desc = chain.GetDesc();
    const auto current_format = desc.ColorBufferFormat;
    const auto current_depth_format = has_depth ? desc.DepthBufferFormat : Diligent::TEX_FORMAT_UNKNOWN;
    auto* depth_view = has_depth ? chain.GetDepthBufferDSV() : nullptr;
    if (current_format == Diligent::TEX_FORMAT_UNKNOWN ||
        (has_depth && (current_depth_format == Diligent::TEX_FORMAT_UNKNOWN || !depth_view)))
      return RenderError::backend_failure;
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
    if (mode == TriangleMode::uniform_depth) {
      context.CommitShaderResources(binding, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
      if (diagnostics.messages().errors) return RenderError::backend_failure;
    }
    Diligent::DrawAttribs draw{}; draw.NumVertices = has_depth ? 6 : 3; draw.Flags = Diligent::DRAW_FLAG_VERIFY_ALL;
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
