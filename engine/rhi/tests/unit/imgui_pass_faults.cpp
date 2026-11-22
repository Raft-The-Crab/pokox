// ENG-11 gap closure: fault-injection coverage for VulkanImGuiPass against
// test-owned Diligent doubles (fakes/imgui). No real GPU or Diligent ABI.
#include "poko/rhi/device/vulkan_imgui_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include <EngineFactoryVk.h>
#include <imgui.h>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace poko::rhi;

namespace imgui_fake {
inline int buffers = 0, textures = 0, samplers = 0, shaders = 0, pipelines = 0, srbs = 0;
inline int maps = 0, unmapped = 0, draws = 0, scissors = 0, commits = 0, rendertargets = 0, errors = 0;
inline int fail_sampler_creates = 0;
inline int fail_buffer_creates = 0;   // next N CreateBuffer calls return null
inline void reset() { buffers=textures=samplers=shaders=pipelines=srbs=maps=unmapped=draws=scissors=commits=rendertargets=errors=0; fail_buffer_creates=0; fail_sampler_creates=0; }
}
namespace Diligent {
DebugMessageCallbackType DebugMessageCallback = nullptr;
IEngineFactoryVk* GetEngineFactoryVk() { return nullptr; }
}

namespace {
using namespace Diligent;
struct FakeBuffer : IBuffer { std::vector<char> storage; void Release() override { delete this; } };
struct FakeTextureView : ITextureView { ISampler* sampler = nullptr; void SetSampler(ISampler* s) override { sampler = s; } void Release() override { delete this; } };
struct FakeTexture : ITexture {
  void CreateView(const TextureViewDesc&, ITextureView** out) override { *out = new FakeTextureView{}; }
  void Release() override { delete this; }
};
struct FakeSampler : ISampler { void Release() override { delete this; } };
struct FakeShader : IShader { SHADER_TYPE type = SHADER_TYPE_VERTEX; explicit FakeShader(SHADER_TYPE t) : type(t) {} void Release() override { delete this; } };
struct FakeVariable : IShaderResourceVariable {
  IDeviceObject* object = nullptr;
  IBuffer* buffer = nullptr; ITextureView* view = nullptr;
  void Set(IDeviceObject* o) override {
    object = o;
    buffer = dynamic_cast<IBuffer*>(o);
    view = dynamic_cast<ITextureView*>(o);
  }
  void Release() override {}
};
struct FakeSRB : IShaderResourceBinding { void Release() override { delete this; } };
struct FakePipeline : IPipelineState {
  FakeVariable frame_data, font_texture;
  IShaderResourceVariable* GetStaticVariableByName(SHADER_TYPE t, const Char* name) override {
    if (t == SHADER_TYPE_VERTEX && std::strcmp(name, "FrameData") == 0) return &frame_data;
    if (t == SHADER_TYPE_PIXEL && std::strcmp(name, "FontTexture") == 0) return &font_texture;
    return nullptr;
  }
  void CreateShaderResourceBinding(IShaderResourceBinding** out, bool) override { ++imgui_fake::srbs; *out = new FakeSRB{}; }
  void Release() override { delete this; }
};
struct FakeDevice : IRenderDevice {
  FakePipeline* last_pipeline = nullptr;
  const RenderDeviceInfo& GetDeviceInfo() const override { static RenderDeviceInfo i{}; return i; }
  void Release() override {}
  void CreateBuffer(const BufferDesc& d, const BufferData*, IBuffer** out) override {
    if (imgui_fake::fail_buffer_creates > 0) { --imgui_fake::fail_buffer_creates; *out = nullptr; return; }
    // Validate descriptor content like the triangle fake does: dynamic
    // CPU-writable buffers only, nonzero size, expected bind flags.
    const bool dynamic_write = d.Usage == USAGE_DYNAMIC && d.CPUAccessFlags == CPU_ACCESS_WRITE && d.Size > 0;
    if (!dynamic_write || !(d.BindFlags & (BIND_VERTEX_BUFFER | BIND_INDEX_BUFFER | BIND_UNIFORM_BUFFER))) {
      ++imgui_fake::errors; *out = nullptr; return;
    }
    ++imgui_fake::buffers; auto* b = new FakeBuffer{}; b->storage.resize(d.Size); *out = b;
  }
  void CreateTexture(const TextureDesc& d, const TextureData*, ITexture** out) override {
    if (d.Format != TEX_FORMAT_RGBA8_UNORM || !d.Width || !d.Height || !(d.BindFlags & BIND_SHADER_RESOURCE)) {
      ++imgui_fake::errors; *out = nullptr; return;
    }
    ++imgui_fake::textures; *out = new FakeTexture{};
  }
  void CreateSampler(const SamplerDesc&, ISampler** out) override { ++imgui_fake::samplers; if (imgui_fake::fail_sampler_creates > 0) { --imgui_fake::fail_sampler_creates; *out = nullptr; return; } *out = new FakeSampler{}; }
  void CreateShader(const ShaderCreateInfo& i, IShader** out) override {
    // Bytecode must be non-empty and 4-byte aligned, as read_spirv guarantees.
    if (!i.ByteCode || !i.ByteCodeSize || (i.ByteCodeSize % 4) != 0) { ++imgui_fake::errors; *out = nullptr; return; }
    ++imgui_fake::shaders; *out = new FakeShader{i.Desc.ShaderType};
  }
  void CreateGraphicsPipelineState(const GraphicsPipelineStateCreateInfo& info, IPipelineState** out) override {
    ++imgui_fake::pipelines;
    const auto& gp = info.GraphicsPipeline;
    const bool layout_ok = gp.InputLayout.NumElements == 3 && gp.InputLayout.LayoutElements != nullptr &&
        gp.NumRenderTargets == 1 && gp.RTVFormats[0] != TEX_FORMAT_UNKNOWN;
    if (!info.pVS || !info.pPS || !layout_ok) { ++imgui_fake::errors; *out = nullptr; return; }
    auto* p = new FakePipeline{}; last_pipeline = p; *out = p;
  }
};
struct FakeContext : IDeviceContext {
  void SetRenderTargets(Uint32, ITextureView*[], ITextureView*, RESOURCE_STATE_TRANSITION_MODE) override { ++imgui_fake::rendertargets; }
  void ClearRenderTarget(ITextureView*, const void*, RESOURCE_STATE_TRANSITION_MODE) override {}
  void WaitForIdle() override {}
  void Release() override {}
  void SetViewports(Uint32, const Viewport*, Uint32, Uint32) override {}
  void SetPipelineState(IPipelineState*) override {}
  void SetVertexBuffers(Uint32, Uint32, IBuffer* const*, const Uint64*, RESOURCE_STATE_TRANSITION_MODE) override {}
  void SetIndexBuffer(IBuffer*, Uint64, RESOURCE_STATE_TRANSITION_MODE) override {}
  void SetScissorRects(Uint32, const Rect*, Uint32, Uint32) override { ++imgui_fake::scissors; }
  void DrawIndexed(const DrawIndexedAttribs& a) override { imgui_fake::draws += static_cast<int>(a.NumIndices); }
  void MapBuffer(IBuffer* b, MAP_TYPE, MAP_FLAGS, void*& ptr) override {
    ++imgui_fake::maps; auto* f = static_cast<FakeBuffer*>(b); ptr = f->storage.data();
  }
  void UnmapBuffer(IBuffer*, MAP_TYPE) override { ++imgui_fake::unmapped; }
  void CommitShaderResources(IShaderResourceBinding*, RESOURCE_STATE_TRANSITION_MODE) override { ++imgui_fake::commits; }
};
struct FakeChain : ISwapChain {
  SwapChainDesc desc{1280, 720, TEX_FORMAT_RGBA8_UNORM, TEX_FORMAT_D32_FLOAT};
  const SwapChainDesc& GetDesc() const override { return desc; }
  void Resize(Uint32, Uint32) override {} ITextureView* GetCurrentBackBufferRTV() override { return nullptr; }
  void Present(Uint32) override {} void SetMaximumFrameLatency(Uint32) override {} void Release() override {}
};
struct FakeTargetView : ITextureView { void SetSampler(ISampler*) override {} void Release() override {} };
std::string write_spirv(const std::filesystem::path& p) {
  std::ofstream f(p, std::ios::binary);
  const std::uint32_t words[8] = {0x07230203, 0x00010000, 0, 0, 0, 0, 0, 0};
  f.write(reinterpret_cast<const char*>(words), sizeof(words));
  return p.string();
}
}  // namespace

int main() {
  namespace fs = std::filesystem;
  const auto dir = fs::temp_directory_path() / "poko_imgui_pass_faults";
  fs::create_directories(dir);
  const auto vs = write_spirv(dir / "imgui.vert.spv");
  const auto fs_path = write_spirv(dir / "imgui.frag.spv");

  // Constructor rejects unreadable/invalid shaders.
  {
    VulkanDiagnostics bad_diag;
    bool threw = false;
    try { VulkanImGuiPass bad(dir.string() + "/missing.vert.spv", fs_path, bad_diag); }
    catch (const std::exception&) { threw = true; }
    if (!threw) { std::fputs("missing shader did not throw\n", stderr); return 1; }
  }

  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.IniFilename = nullptr;  // deterministic layout; no imgui.ini state
  io.DisplaySize = ImVec2(800.f, 600.f);
  io.DeltaTime = 1.f / 60.f;
  io.FontDefault = io.Fonts->AddFontDefault();
  { unsigned char* px = nullptr; int w = 0, h = 0; io.Fonts->GetTexDataAsRGBA32(&px, &w, &h); }  // build atlas before Render, as the demo does

  VulkanDiagnostics diag;
  VulkanImGuiPass pass(vs, fs_path, diag);
  FakeDevice device; FakeContext context; FakeChain chain; FakeTargetView target;

  // Empty frame: NewFrame/Render with no windows produces no draw data.
  ImGui::NewFrame(); ImGui::Render();
  imgui_fake::reset();
  if (pass.draw(device, context, chain, target) != RenderError::none || imgui_fake::textures != 0) {
    std::fputs("empty draw data was not a no-op\n", stderr); return 1;
  }

  // Buffer-create failure on the first real draw reports backend_failure and
  // leaves capacity at zero, so the next frame retries creation instead of
  // mapping a null buffer (the ensure_buffers regression this harness guards).
  ImGui::NewFrame(); ImGui::ShowDemoWindow(); ImGui::Render();
  // A failure after creating the view must not mark the font as initialized.
  {
    VulkanImGuiPass font_retry(vs, fs_path, diag);
    imgui_fake::reset(); imgui_fake::fail_sampler_creates = 1;
    if (font_retry.draw(device, context, chain, target) != RenderError::backend_failure) {
      std::fputs("sampler failure was not reported\n", stderr); return 1;
    }
    imgui_fake::reset();
    if (font_retry.draw(device, context, chain, target) != RenderError::none ||
        imgui_fake::textures != 1 || imgui_fake::samplers != 1) {
      std::fputs("font retry did not rebuild resources\n", stderr); return 1;
    }
  }
  imgui_fake::fail_buffer_creates = 1;
  imgui_fake::reset(); imgui_fake::fail_buffer_creates = 1;
  if (pass.draw(device, context, chain, target) != RenderError::backend_failure) {
    std::fputs("injected buffer failure was not reported\n", stderr); return 1;
  }
  imgui_fake::fail_buffer_creates = 0;
  imgui_fake::reset();
  if (pass.draw(device, context, chain, target) != RenderError::none) {
    std::fputs("retry after buffer failure did not recover\n", stderr); return 1;
  }
  // Font resources were created during the failed attempt and survived it;
  // the retry only creates the three buffers plus shaders/pipeline.
  const bool ok1 = imgui_fake::textures == 0 && imgui_fake::samplers == 0 &&
      imgui_fake::shaders == 2 && imgui_fake::pipelines == 1 &&
      imgui_fake::buffers == 3 && imgui_fake::commits == 1 &&
      imgui_fake::rendertargets == 1 && imgui_fake::draws > 0 &&
      imgui_fake::scissors > 0 && imgui_fake::maps == imgui_fake::unmapped;
  if (!ok1) {
    std::fprintf(stderr, "unexpected counters: tex=%d smp=%d shd=%d pso=%d buf=%d com=%d rt=%d draw=%d sci=%d map=%d unmap=%d\n",
      imgui_fake::textures, imgui_fake::samplers, imgui_fake::shaders, imgui_fake::pipelines,
      imgui_fake::buffers, imgui_fake::commits, imgui_fake::rendertargets,
      imgui_fake::draws, imgui_fake::scissors, imgui_fake::maps, imgui_fake::unmapped);
    return 1;
  }
  // Static bindings: FrameData must have received the transform IBuffer and
  // FontTexture the atlas ITextureView — catches missing/swapped bindings.
  if (!device.last_pipeline || !device.last_pipeline->frame_data.buffer ||
      !device.last_pipeline->font_texture.view || imgui_fake::srbs != 1) {
    std::fputs("shader resource bindings incorrect\n", stderr); return 1;
  }
  // Second draw reuses all GPU resources.
  imgui_fake::reset();
  if (pass.draw(device, context, chain, target) != RenderError::none ||
      imgui_fake::textures != 0 || imgui_fake::pipelines != 0) {
    std::fputs("second draw recreated resources\n", stderr); return 1;
  }
  // Growth: a frame with far more vertices than capacity recreates the two
  // dynamic buffers (vertex + index) while reusing font/pipeline resources.
  ImGui::NewFrame();
  auto* bg = ImGui::GetBackgroundDrawList();
  for (int i = 0; i < 400; ++i) bg->AddText(ImVec2(0.f, static_cast<float>(i) * 1.f), 0xFFFFFFFF, "growth row");
  ImGui::ShowDemoWindow();
  ImGui::Render();
  imgui_fake::reset();
  if (pass.draw(device, context, chain, target) != RenderError::none) {
    std::fputs("growth draw failed\n", stderr); return 1;
  }
  if (imgui_fake::buffers != 2 || imgui_fake::textures != 0 || imgui_fake::pipelines != 0) {
    std::fprintf(stderr, "growth counters wrong: buf=%d tex=%d pso=%d\n",
      imgui_fake::buffers, imgui_fake::textures, imgui_fake::pipelines);
    return 1;
  }
  // ImDrawCallback_ResetRenderState commands carry ElemCount == 0; the pass
  // must still process them and re-commit shader resources, or the font and
  // uniform bindings are lost for subsequent draws.
  ImGui::NewFrame();
  bg = ImGui::GetBackgroundDrawList();
  bg->AddCallback(ImDrawCallback_ResetRenderState, nullptr);
  bg->AddText(ImVec2(1.f, 1.f), 0xFFFFFFFF, "after reset");
  ImGui::Render();
  imgui_fake::reset();
  if (pass.draw(device, context, chain, target) != RenderError::none) {
    std::fputs("reset-callback draw failed\n", stderr); return 1;
  }
  if (imgui_fake::commits != 2 || imgui_fake::draws == 0) {
    std::fprintf(stderr, "reset callback not honored: commits=%d draws=%d\n",
      imgui_fake::commits, imgui_fake::draws);
    return 1;
  }
  // Device binding: a different device is rejected.
  FakeDevice other;
  if (pass.draw(other, context, chain, target) != RenderError::backend_failure) {
    std::fputs("foreign device was not rejected\n", stderr); return 1;
  }
  ImGui::DestroyContext();
  std::puts("PASS: imgui pass fault injection (create/draw/reuse/retry/device-binding)");
  return 0;
}
