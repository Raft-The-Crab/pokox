#include "poko/rhi/device/vulkan_triangle_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include <EngineFactoryVk.h>
#include <cstdio>
#include <cstdint>
#include <fstream>
#include <iostream>

namespace { Diligent::IRenderDevice device1, device2; Diligent::IRenderDevice* device=&device1; Diligent::IDeviceContext context; Diligent::ISwapChain chain; Diligent::ITextureView target, depth; }
namespace poko::rhi {
struct VulkanDiagnostics::Impl {};
VulkanDiagnostics::VulkanDiagnostics() noexcept = default;
VulkanDiagnostics::~VulkanDiagnostics() = default;
GraphicsMessages VulkanDiagnostics::messages() const noexcept { return {static_cast<std::uint64_t>(triangle_fake::errors),0}; }
struct VulkanClearRenderer::Impl {};
VulkanClearRenderer::VulkanClearRenderer() noexcept = default;
VulkanClearRenderer::~VulkanClearRenderer() = default;
RenderError VulkanClearRenderer::draw_and_present(VulkanDrawCallback cb, void* user) noexcept {
 try { auto r=cb(*device, context, chain, target, user); if(r==RenderError::none) ++triangle_fake::presents; return r; } catch (...) { return RenderError::backend_failure; }
}
}
#define CHECK(x) do { if (!(x)) { std::cerr << "failed: " << #x << " at line " << __LINE__ << '\n'; return 1; } } while(false)
void reset() { using namespace triangle_fake; errors=presents=shaders=pipelines=bindings=clears=depth_clears=states=draws=vertices=fail_at=0; depth_enabled=depth_write=false; depth_func=depth_format=0; depth_clear=-1.f; buffers=variables=srbs=maps=unmaps=commits=0; for(auto& x: uploaded) x=0; device=&device1; chain=Diligent::ISwapChain{}; chain.depth=&depth; }
int main(int argc, char** argv) {
 CHECK(argc==2); const std::uint32_t words[5]={0x07230203U,0x00010000U,0,1,0}; { std::ofstream f(argv[1],std::ios::binary); f.write(reinterpret_cast<const char*>(words),sizeof(words)); CHECK(f.good()); }
 using namespace poko::rhi; using namespace triangle_fake;
 VulkanDiagnostics diag; VulkanClearRenderer renderer;
 reset(); {
  VulkanTrianglePass pass(argv[1],argv[1],diag); CHECK(pass.draw_and_present(renderer)==RenderError::none); CHECK(draws==1 && vertices==3 && presents==1 && !depth_enabled && depth_clears==0);
  CHECK(pass.draw_and_present(renderer)==RenderError::none); CHECK(pipelines==1 && shaders==2);
  chain.desc.ColorBufferFormat=3; CHECK(pass.draw_and_present(renderer)==RenderError::none); CHECK(pipelines==2 && shaders==4);
  device=&device2; CHECK(pass.draw_and_present(renderer)==RenderError::backend_failure); CHECK(presents==3 && draws==3 && pipelines==2);
 }
 reset(); {
  VulkanTrianglePass pass(argv[1],argv[1],diag,TriangleMode::depth_test); chain.depth=nullptr; CHECK(pass.draw_and_present(renderer)==RenderError::backend_failure); CHECK(shaders==0 && presents==0);
  chain.depth=&depth; CHECK(pass.draw_and_present(renderer)==RenderError::none); CHECK(depth_enabled && depth_write && depth_func==Diligent::COMPARISON_FUNC_LESS && depth_format==Diligent::TEX_FORMAT_D32_FLOAT); CHECK(depth_clears==1 && depth_clear==1.f && vertices==6 && presents==1);
 }
 reset(); {
  VulkanTrianglePass pass(argv[1],argv[1],diag,TriangleMode::depth_disabled_control); CHECK(pass.draw_and_present(renderer)==RenderError::none); CHECK(!depth_enabled && !depth_write && depth_clears==1 && vertices==6);
 }
 for(int stage=1; stage<=8; ++stage) { reset(); fail_at=stage; VulkanTrianglePass pass(argv[1],argv[1],diag,TriangleMode::depth_test); CHECK(pass.draw_and_present(renderer)==RenderError::backend_failure); CHECK(presents==0); if(stage!=7) CHECK(draws==0); if(stage<6 || stage==8) CHECK(states==0); }
 reset(); { VulkanTrianglePass pass(argv[1],argv[1],diag,TriangleMode::depth_test); chain.desc.DepthBufferFormat=Diligent::TEX_FORMAT_UNKNOWN; CHECK(pass.draw_and_present(renderer)==RenderError::backend_failure && shaders==0); }
 reset(); {
  VulkanTrianglePass pass(argv[1],argv[1],diag,TriangleMode::uniform_depth);
  CHECK(pass.draw_and_present(renderer, {0.25f,0.5f,0.75f,1.f})==RenderError::none);
  CHECK(depth_enabled && depth_write && buffers==1 && srbs==1 && maps==1 && unmaps==1 && commits==1 && draws==1 && vertices==6);
  CHECK(uploaded[0]==0.25f && uploaded[1]==0.5f && uploaded[2]==0.75f && uploaded[3]==1.f);
  CHECK(pass.draw_and_present(renderer, {0.8f,0.1f,0.2f,1.f})==RenderError::none);
  CHECK(buffers==1 && pipelines==1 && maps==2 && unmaps==2 && commits==2 && uploaded[0]==0.8f);
  chain.desc.ColorBufferFormat=3; CHECK(pass.draw_and_present(renderer)==RenderError::none); CHECK(buffers==2 && srbs==2 && pipelines==2);
 }
 for(int stage=9; stage<=16; ++stage) {
  reset(); fail_at=stage; VulkanTrianglePass pass(argv[1],argv[1],diag,TriangleMode::uniform_depth);
  CHECK(pass.draw_and_present(renderer)==RenderError::backend_failure); CHECK(presents==0 && draws==0);
  if(stage==13) CHECK(maps==1 && unmaps==0);
  if(stage==14 || stage==15) CHECK(maps==1 && unmaps==1);
  if(stage==16) CHECK(commits==1);
 }
 std::remove(argv[1]); std::cout << "triangle pass control-flow checks passed\n";
}
