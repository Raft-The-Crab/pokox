// SHL-11: Vulkan UI pass — renders poko_shell tessellated PMES v1 mesh and
// texture deltas over a game viewport target using test-owned Diligent doubles.
#include "poko/rhi/device/vulkan_shell_ui_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/shell/unique_shell.hpp"

#include <EngineFactoryVk.h>

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

using namespace poko::rhi;

namespace shell_vk_fake {
inline int buffers = 0, textures = 0, samplers = 0, shaders = 0, pipelines = 0, srbs = 0;
inline int draws = 0, scissors = 0, commits = 0, rendertargets = 0;
inline int fail_buffer_creates = 0;
inline int fail_sampler_creates = 0;
inline bool depth_disabled = false;
inline bool alpha_blended = false;
inline std::uint32_t last_drawn_indices = 0;
inline void reset() {
  buffers = textures = samplers = shaders = pipelines = srbs = 0;
  draws = scissors = commits = rendertargets = 0;
  fail_buffer_creates = fail_sampler_creates = 0;
  depth_disabled = alpha_blended = false;
  last_drawn_indices = 0;
}
}  // namespace shell_vk_fake

namespace Diligent {
DebugMessageCallbackType DebugMessageCallback = nullptr;
IEngineFactoryVk* GetEngineFactoryVk() { return nullptr; }
}  // namespace Diligent

namespace {
using namespace Diligent;

struct FakeBuffer : IBuffer {
  std::vector<char> storage;
  void Release() override { delete this; }
};
struct FakeTextureView : ITextureView {
  ISampler* sampler = nullptr;
  void SetSampler(ISampler* s) override { sampler = s; }
  void Release() override { delete this; }
};
struct FakeTexture : ITexture {
  void CreateView(const TextureViewDesc&, ITextureView** out) override {
    *out = new FakeTextureView{};
  }
  void Release() override { delete this; }
};
struct FakeSampler : ISampler {
  void Release() override { delete this; }
};
struct FakeShader : IShader {
  SHADER_TYPE type = SHADER_TYPE_VERTEX;
  explicit FakeShader(SHADER_TYPE t) : type(t) {}
  void Release() override { delete this; }
};
struct FakeVariable : IShaderResourceVariable {
  IDeviceObject* object = nullptr;
  void Set(IDeviceObject* o) override { object = o; }
  void Release() override {}
};
struct FakeSRB : IShaderResourceBinding {
  void Release() override { delete this; }
};
struct FakePipeline : IPipelineState {
  FakeVariable frame_data, font_texture;
  IShaderResourceVariable* GetStaticVariableByName(SHADER_TYPE t, const Char* name) override {
    if (t == SHADER_TYPE_VERTEX && std::strcmp(name, "FrameData") == 0) return &frame_data;
    if (t == SHADER_TYPE_PIXEL && std::strcmp(name, "FontTexture") == 0) return &font_texture;
    return nullptr;
  }
  void CreateShaderResourceBinding(IShaderResourceBinding** out, bool) override {
    ++shell_vk_fake::srbs;
    *out = new FakeSRB{};
  }
  void Release() override { delete this; }
};
struct FakeDevice : IRenderDevice {
  const RenderDeviceInfo& GetDeviceInfo() const override {
    static RenderDeviceInfo i{};
    return i;
  }
  void Release() override {}
  void CreateBuffer(const BufferDesc& d, const BufferData*, IBuffer** out) override {
    if (shell_vk_fake::fail_buffer_creates > 0) {
      --shell_vk_fake::fail_buffer_creates;
      *out = nullptr;
      return;
    }
    ++shell_vk_fake::buffers;
    auto* b = new FakeBuffer{};
    b->storage.resize(d.Size);
    *out = b;
  }
  void CreateTexture(const TextureDesc& d, const TextureData*, ITexture** out) override {
    if (d.Format != TEX_FORMAT_RGBA8_UNORM || !d.Width || !d.Height ||
        !(d.BindFlags & BIND_SHADER_RESOURCE)) {
      *out = nullptr;
      return;
    }
    ++shell_vk_fake::textures;
    *out = new FakeTexture{};
  }
  void CreateSampler(const SamplerDesc&, ISampler** out) override {
    if (shell_vk_fake::fail_sampler_creates > 0) {
      --shell_vk_fake::fail_sampler_creates;
      *out = nullptr;
      return;
    }
    ++shell_vk_fake::samplers;
    *out = new FakeSampler{};
  }
  void CreateShader(const ShaderCreateInfo& i, IShader** out) override {
    if (!i.ByteCode || !i.ByteCodeSize || (i.ByteCodeSize % 4) != 0) {
      *out = nullptr;
      return;
    }
    ++shell_vk_fake::shaders;
    *out = new FakeShader{i.Desc.ShaderType};
  }
  void CreateGraphicsPipelineState(const GraphicsPipelineStateCreateInfo& info,
                                   IPipelineState** out) override {
    ++shell_vk_fake::pipelines;
    const auto& gp = info.GraphicsPipeline;
    shell_vk_fake::depth_disabled = !gp.DepthStencilDesc.DepthEnable &&
                                    !gp.DepthStencilDesc.DepthWriteEnable;
    shell_vk_fake::alpha_blended = gp.BlendDesc.RenderTargets[0].BlendEnable;
    const bool layout_ok = gp.InputLayout.NumElements == 2 &&
                           gp.InputLayout.LayoutElements != nullptr &&
                           gp.NumRenderTargets == 1 &&
                           gp.RTVFormats[0] != TEX_FORMAT_UNKNOWN;
    if (!info.pVS || !info.pPS || !layout_ok) {
      *out = nullptr;
      return;
    }
    *out = new FakePipeline{};
  }
};
struct FakeContext : IDeviceContext {
  void SetRenderTargets(Uint32, ITextureView*[], ITextureView*,
                        RESOURCE_STATE_TRANSITION_MODE) override {
    ++shell_vk_fake::rendertargets;
  }
  void ClearRenderTarget(ITextureView*, const void*, RESOURCE_STATE_TRANSITION_MODE) override {}
  void WaitForIdle() override {}
  void Release() override {}
  void SetViewports(Uint32, const Viewport*, Uint32, Uint32) override {}
  void SetScissorRects(Uint32, const Rect*, Uint32, Uint32) override {
    ++shell_vk_fake::scissors;
  }
  void SetPipelineState(IPipelineState*) override {}
  void CommitShaderResources(IShaderResourceBinding*,
                             RESOURCE_STATE_TRANSITION_MODE) override {
    ++shell_vk_fake::commits;
  }
  void SetVertexBuffers(Uint32, Uint32, IBuffer* const*, const Uint64*,
                        RESOURCE_STATE_TRANSITION_MODE) override {}
  void SetIndexBuffer(IBuffer*, Uint64, RESOURCE_STATE_TRANSITION_MODE) override {}
  void MapBuffer(IBuffer* b, MAP_TYPE, MAP_FLAGS, void*& out) override {
    auto* fb = static_cast<FakeBuffer*>(b);
    out = fb ? fb->storage.data() : nullptr;
  }
  void UnmapBuffer(IBuffer*, MAP_TYPE) override {}
  void DrawIndexed(const DrawIndexedAttribs& a) override {
    ++shell_vk_fake::draws;
    shell_vk_fake::last_drawn_indices = a.NumIndices;
  }
};
struct FakeSwapChain : ISwapChain {
  SwapChainDesc desc{640, 480, TEX_FORMAT_RGBA8_UNORM};
  const SwapChainDesc& GetDesc() const override { return desc; }
  ITextureView* GetCurrentBackBufferRTV() override { return nullptr; }
  void Present(Uint32) override {}
  void SetMaximumFrameLatency(Uint32) override {}
  void Resize(Uint32 w, Uint32 h) override {
    desc.Width = w;
    desc.Height = h;
  }
  void Release() override {}
};

std::filesystem::path write_dummy_spirv(const char* name) {
  const auto path = std::filesystem::temp_directory_path() / name;
  std::ofstream out(path, std::ios::binary);
  const std::uint32_t words[5] = {0x07230203u, 0x00010000u, 0u, 1u, 0u};
  out.write(reinterpret_cast<const char*>(words), sizeof(words));
  return path;
}

int failures = 0;
void check(bool ok, const char* what) {
  if (!ok) {
    std::puts(what);
    ++failures;
  }
}

}  // namespace

int main() {
  shell_vk_fake::reset();
  const auto vs_path = write_dummy_spirv("poko_shell_ui_vert_test.spv");
  const auto fs_path = write_dummy_spirv("poko_shell_ui_frag_test.spv");

  int32_t create_rc = -1;
  auto shell = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &create_rc);
  check(create_rc == POKO_SHELL_OK && static_cast<bool>(shell), "FAIL: UniqueShell create");

  PokoFrameInfo frame{};
  check(poko_shell_frame(shell.get(), 0.0, 640, 480, &frame) == POKO_SHELL_OK,
        "FAIL: poko_shell_frame");

  uint32_t u_cnt = 0, p_cnt = 0;
  check(poko_shell_texture_delta(shell.get(), nullptr, 0, &u_cnt, nullptr, 0, &p_cnt) ==
            POKO_SHELL_OK,
        "FAIL: texture sizing");
  std::vector<PokoTextureUpdate> updates(u_cnt);
  std::vector<uint8_t> pixels(p_cnt);
  check(poko_shell_texture_delta(shell.get(), updates.data(), u_cnt, &u_cnt,
                                 pixels.data(), p_cnt, &p_cnt) == POKO_SHELL_OK,
        "FAIL: texture drain");

  uint32_t v_cnt = 0, i_cnt = 0;
  check(poko_shell_mesh(shell.get(), nullptr, 0, &v_cnt, nullptr, 0, &i_cnt) == POKO_SHELL_OK,
        "FAIL: mesh sizing");
  std::vector<float> verts(v_cnt * 6);
  std::vector<uint32_t> idx(i_cnt);
  check(poko_shell_mesh(shell.get(), verts.data(), v_cnt, &v_cnt,
                        idx.data(), i_cnt, &i_cnt) == POKO_SHELL_OK,
        "FAIL: mesh drain");

  VulkanDiagnostics diag;
  VulkanShellUiPass pass(vs_path.string(), fs_path.string(), diag);
  FakeDevice device;
  FakeContext context;
  FakeSwapChain chain;
  FakeTextureView viewport_target;

  std::vector<ShellTextureDelta> deltas(updates.size());
  for (std::size_t i = 0; i < updates.size(); ++i) {
    deltas[i] = {updates[i].id, updates[i].width, updates[i].height,
                 updates[i].pixels_offset, updates[i].pixels_len};
  }
  check(pass.apply_texture_deltas(device, deltas.data(),
                                  static_cast<uint32_t>(deltas.size()),
                                  pixels.data(), p_cnt) == RenderError::none,
        "FAIL: apply_texture_deltas");
  check(shell_vk_fake::textures == static_cast<int>(updates.size()),
        "FAIL: expected font atlas texture created");

  check(pass.draw(device, context, chain, viewport_target,
                  verts.data(), v_cnt, idx.data(), i_cnt, 640, 480) == RenderError::none,
        "FAIL: VulkanShellUiPass::draw");
  check(shell_vk_fake::rendertargets == 1 && shell_vk_fake::draws == 1 &&
            shell_vk_fake::last_drawn_indices == i_cnt,
        "FAIL: expected 1 render target bind and 1 DrawIndexed of all shell indices");
  check(shell_vk_fake::depth_disabled && shell_vk_fake::alpha_blended,
        "FAIL: UI pipeline must disable depth and enable alpha blending");

  // Zero-length delta disposes texture id cleanly.
  ShellTextureDelta dispose_delta{updates[0].id, 0, 0, 0, 0};
  check(pass.apply_texture_deltas(device, &dispose_delta, 1, nullptr, 0) == RenderError::none,
        "FAIL: zero-length delta dispose must succeed");

  // Fault injection: buffer creation failure and device mismatch.
  shell_vk_fake::fail_buffer_creates = 1;
  std::vector<float> bigger_verts((v_cnt + 10) * 6, 0.0f);
  check(pass.draw(device, context, chain, viewport_target,
                  bigger_verts.data(), v_cnt + 10, idx.data(), i_cnt, 640, 480) ==
            RenderError::backend_failure,
        "FAIL: buffer creation failure must return backend_failure");

  FakeDevice other_device;
  check(pass.draw(other_device, context, chain, viewport_target,
                  verts.data(), v_cnt, idx.data(), i_cnt, 640, 480) ==
            RenderError::backend_failure,
        "FAIL: mismatched device must return backend_failure");

  std::filesystem::remove(vs_path);
  std::filesystem::remove(fs_path);

  if (failures > 0) {
    std::printf("FAIL: %d SHL-11 Vulkan UI pass check(s) failed\n", failures);
    return 1;
  }
  std::puts("OK: all SHL-11 Vulkan UI pass checks passed");
}
