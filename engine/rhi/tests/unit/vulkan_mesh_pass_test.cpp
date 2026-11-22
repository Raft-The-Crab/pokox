#include "poko/rhi/device/vulkan_mesh_pass.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include <EngineFactoryVk.h>
#include <cstdio>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
namespace { Diligent::IRenderDevice device1, device2; Diligent::IRenderDevice* device=&device1; Diligent::IDeviceContext context; Diligent::ISwapChain chain; Diligent::ITextureView target, depth; }
namespace poko::rhi {
struct VulkanDiagnostics::Impl {};
VulkanDiagnostics::VulkanDiagnostics() noexcept = default;
VulkanDiagnostics::~VulkanDiagnostics() = default;
GraphicsMessages VulkanDiagnostics::messages() const noexcept { return {static_cast<std::uint64_t>(mesh_fake::errors),0}; }
struct VulkanClearRenderer::Impl {};
VulkanClearRenderer::VulkanClearRenderer() noexcept = default;
VulkanClearRenderer::~VulkanClearRenderer() = default;
RenderError VulkanClearRenderer::draw_and_present(VulkanDrawCallback cb, void* user) noexcept {
  try { return cb(*device,context,chain,target,user); } catch (...) { return RenderError::backend_failure; }
}
}
#define CHECK(x) do { if (!(x)) { std::cerr << "failed: " << #x << " line " << __LINE__ << '\n'; return 1; } } while(false)
int main(int argc,char** argv) {
 CHECK(argc==2); const std::uint32_t words[5]={0x07230203U,0x00010000U,0,1,0};
 { std::ofstream f(argv[1],std::ios::binary); f.write(reinterpret_cast<const char*>(words),sizeof(words)); CHECK(f.good()); }
 using namespace poko::rhi; using namespace mesh_fake;
 VulkanDiagnostics diag; chain.depth=&depth;
 const MeshVertex v[3]={{{0,0,0},{0,1,0}},{{1,0,0},{0,1,0}},{{0,1,0},{0,1,0}}};
 const std::uint32_t idx[3]={0,1,2};
 {
  VulkanMeshPass pass(argv[1],argv[1],diag); pass.set_mesh(v,3,idx,3);
  CHECK(pass.draw(*device,context,chain,target)==RenderError::none);
  CHECK(draws==1 && vertices==3 && buffers==4);
  void* const old_camera=last_camera;
  // Camera creation succeeds, then light creation fails. Returning to the
  // original format must retain the original pipeline and uniform buffers.
  chain.desc.ColorBufferFormat=3; fail_buffer_number=buffers+2;
  CHECK(pass.draw(*device,context,chain,target)==RenderError::backend_failure);
  fail_buffer_number=0; chain.desc.ColorBufferFormat=1;
  CHECK(pass.draw(*device,context,chain,target)==RenderError::none);
  CHECK(last_camera==old_camera && draws==2);
  if (std::numeric_limits<std::size_t>::max() > std::numeric_limits<std::uint32_t>::max()) {
    pass.set_mesh(v,3,idx,static_cast<std::size_t>(std::numeric_limits<std::uint32_t>::max())+1);
    CHECK(pass.draw(*device,context,chain,target)==RenderError::not_initialized);
  }
 }
 {
  errors=0; fail_at=1; chain.desc.ColorBufferFormat=1;
  VulkanMeshPass pass(argv[1],argv[1],diag); pass.set_mesh(v,3,idx,3);
  CHECK(pass.draw(device1,context,chain,target)==RenderError::backend_failure);
  errors=0; fail_at=0;
  CHECK(pass.draw(device2,context,chain,target)==RenderError::backend_failure);
 }
 std::remove(argv[1]); std::cout << "mesh pass fault checks passed\n";
}
