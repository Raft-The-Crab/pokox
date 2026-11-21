// Use the existing SDL/Diligent fixtures; no real SDK, OS window or GPU.
#ifdef main
#pragma push_macro("main")
#undef main
#define POKO_RESTORE_TEST_MAIN
#endif
#define main poko_existing_vulkan_fixture_main
#include "vulkan_clear_faults.cpp"
#undef main
#ifdef POKO_RESTORE_TEST_MAIN
#pragma pop_macro("main")
#undef POKO_RESTORE_TEST_MAIN
#endif
#include "poko/rhi/device/opengl_clear_renderer.hpp"
#include "poko/rhi/device/fallback_clear_backends.hpp"
#include <EngineFactoryOpenGL.h>
namespace glfake {
bool no_context = false, make_current_fails = false, destroy_fails = false;
int contexts = 0;
bool no_factory = false, throw_factory = false, no_device = false, no_device_context = false, no_chain = false, throw_device = false, non_srgb = false, old_version = false;
bool load_fails = false, missing_proc = false, invalid_proc = false, framebuffer_linear = false, gl_error = false, late_load = false;
int library_refs = 0, framebuffer_binding = 7;
void get_int(unsigned, int* value) { *value = framebuffer_binding; }
void bind(unsigned, unsigned framebuffer) { framebuffer_binding = static_cast<int>(framebuffer); }
void get_attachment(unsigned, unsigned, unsigned, int* value) { *value = framebuffer_linear ? 0x2601 : 0x8C40; }
unsigned get_error() { return gl_error ? 0x0500 : 0; }
}
bool SDL_GL_SetAttribute(SDL_GLAttr, int) { return true; }
SDL_GLContext SDL_GL_CreateContext(SDL_Window*) {
  if (glfake::no_context) return nullptr;
  ++glfake::contexts; return reinterpret_cast<SDL_GLContext>(static_cast<std::uintptr_t>(1));
}
bool SDL_GL_MakeCurrent(SDL_Window*, SDL_GLContext) { return !glfake::make_current_fails; }
bool SDL_GL_DestroyContext(SDL_GLContext) { if (glfake::destroy_fails) return false; --glfake::contexts; return true; }
bool SDL_GL_LoadLibrary(const char*) {
  if (glfake::contexts || fake::devices) glfake::late_load = true;
  if (glfake::load_fails) return false;
  ++glfake::library_refs; return true;
}
void SDL_GL_UnloadLibrary() { --glfake::library_refs; }
SDL_FunctionPointer SDL_GL_GetProcAddress(const char* name) {
  if (glfake::missing_proc || glfake::library_refs==0) return nullptr;
  if (glfake::invalid_proc) return reinterpret_cast<SDL_FunctionPointer>(static_cast<std::uintptr_t>(1));
  const std::string_view proc{name};
  if (proc=="glGetIntegerv") return reinterpret_cast<SDL_FunctionPointer>(glfake::get_int);
  if (proc=="glBindFramebuffer") return reinterpret_cast<SDL_FunctionPointer>(glfake::bind);
  if (proc=="glGetFramebufferAttachmentParameteriv") return reinterpret_cast<SDL_FunctionPointer>(glfake::get_attachment);
  if (proc=="glGetError") return reinterpret_cast<SDL_FunctionPointer>(glfake::get_error);
  return nullptr;
}
namespace Diligent {
struct GlFactory final : IEngineFactoryOpenGL {
  void SetMessageCallback(DebugMessageCallbackType callback) const override { DebugMessageCallback = callback; }
  void CreateDeviceAndSwapChainGL(const EngineGLCreateInfo& info, IRenderDevice** d,
                                  IDeviceContext** c, const SwapChainDesc& desc, ISwapChain** sc) override {
#if PLATFORM_WIN32
    if (!info.Window.hWnd) throw std::runtime_error("missing HWND");
#elif PLATFORM_LINUX
    if (!info.Window.pDisplay || info.Window.WindowId != 42) throw std::runtime_error("bad X11 window");
#endif
    fake::validation = info.EnableValidation; fake::last_desc = desc;
    if (!glfake::no_device) { auto* device = new Device; if (glfake::old_version) device->info.APIVersion.Minor=4; *d = device; }
    if (glfake::throw_device) throw std::runtime_error("partial creation");
    if (!glfake::no_device_context) *c = new Context;
    auto actual = desc; if (glfake::non_srgb) actual.ColorBufferFormat = TEX_FORMAT_RGBA8_UNORM;
    if (!glfake::no_chain) *sc = new Chain(actual);
    if (fake::throw_chain) throw std::runtime_error("partial chain");
  }
};
IEngineFactoryOpenGL* GetEngineFactoryOpenGL() {
  if (glfake::throw_factory) throw std::runtime_error("GL factory retrieval failed");
  static GlFactory f; return glfake::no_factory ? nullptr : &f;
}
}
int main() {
  using namespace poko; using rhi::RenderError;
  constexpr std::array<float,4> blue{0.035f,0.12f,0.28f,1.f};
  platform::SdlPlatform w; rhi::OpenGLClearRenderer r;
  CHECK(r.clear_and_present(blue)==RenderError::not_initialized);
  CHECK(w.initialize()==platform::PlatformError::none);
  CHECK(w.create_window({"plain",800,600})==platform::PlatformError::none);
  CHECK(r.initialize(w)==RenderError::invalid_window);
  w.destroy_window();
  CHECK(w.create_window({"gl",800,600,platform::WindowGraphicsApi::opengl})==platform::PlatformError::none);
  CHECK(w.graphics_api()==platform::WindowGraphicsApi::opengl);
  fake::flags|=SDL_WINDOW_MINIMIZED;
  CHECK(r.initialize(w)==RenderError::not_drawable);
  fake::flags&=~SDL_WINDOW_MINIMIZED;
  fake::no_native=true; CHECK(r.initialize(w)==RenderError::native_window_unavailable); fake::no_native=false;
#if PLATFORM_LINUX
  glfake::no_context=true; CHECK(r.initialize(w)==RenderError::device_creation_failed); CHECK(r.shutdown()); glfake::no_context=false;
  glfake::make_current_fails=true; CHECK(r.initialize(w)==RenderError::device_creation_failed); CHECK(r.shutdown()); CHECK(glfake::contexts==0); glfake::make_current_fails=false;
#endif
  glfake::no_factory=true; CHECK(r.initialize(w)==RenderError::factory_unavailable);
  CHECK(r.clear_and_present(blue)==RenderError::not_initialized);
  CHECK(r.shutdown()); glfake::no_factory=false;
  for (int failure=0;failure<4;++failure) {
    glfake::no_device=failure==0; glfake::no_device_context=failure==1; glfake::no_chain=failure==2; glfake::throw_device=failure==3;
    const auto error=r.initialize(w);
    CHECK(error==(failure==2 ? RenderError::swapchain_creation_failed : failure==3 ? RenderError::backend_failure : RenderError::device_creation_failed));
    CHECK(r.shutdown()); CHECK(fake::devices==0 && fake::contexts==0 && fake::chains==0 && glfake::contexts==0);
  }
  glfake::no_device=glfake::no_device_context=glfake::no_chain=glfake::throw_device=false;
  glfake::non_srgb=true; CHECK(r.initialize(w)==RenderError::backend_failure); CHECK(r.shutdown()); glfake::non_srgb=false;
  glfake::old_version=true; CHECK(r.initialize(w)==RenderError::backend_failure); CHECK(r.shutdown()); glfake::old_version=false;
  for (int failure=0; failure<5; ++failure) {
    glfake::load_fails=failure==0; glfake::missing_proc=failure==1;
    glfake::framebuffer_linear=failure==2; glfake::gl_error=failure==3; glfake::invalid_proc=failure==4;
    CHECK(r.initialize(w)==RenderError::backend_failure);
    // A failed initialize() now cleans up immediately (pending impl), so the
    // GL library is unloaded for every failure mode, not just load failure.
    CHECK(glfake::library_refs==0 && glfake::framebuffer_binding==7);
    CHECK(r.shutdown());
    CHECK(glfake::library_refs==0);
  }
  glfake::load_fails=glfake::missing_proc=glfake::invalid_proc=glfake::framebuffer_linear=glfake::gl_error=false;
  CHECK(r.initialize(w,false)==RenderError::none); CHECK(!fake::validation);
  CHECK(glfake::library_refs==1 && glfake::framebuffer_binding==7);
  CHECK(r.initialize(w)==RenderError::already_initialized);
  CHECK(r.clear_and_present(blue)==RenderError::none && fake::color==blue);
  const int before_minimize=fake::presents;
  const int resizes_before_minimize=fake::resizes;
  fake::pw=801;
  fake::flags|=SDL_WINDOW_MINIMIZED;
  CHECK(r.clear_and_present(blue)==RenderError::not_drawable && fake::presents==before_minimize && fake::resizes==resizes_before_minimize);
  fake::flags&=~SDL_WINDOW_MINIMIZED;
  fake::pw=800;
  fake::pw=0; CHECK(r.clear_and_present(blue)==RenderError::not_drawable);
  const int before_resize=fake::presents;
  fake::pw=801; fake::releases.clear();
  CHECK(r.clear_and_present(blue)==RenderError::resize_attempted);
  CHECK(fake::presents==before_resize && (fake::releases==std::vector<std::string>{"unbind"}));
  CHECK(r.clear_and_present(blue)==RenderError::none && fake::presents==before_resize+1);
  fake::pw=800; fake::ph=601;
  CHECK(r.clear_and_present(blue)==RenderError::resize_attempted);
  CHECK(r.clear_and_present(blue)==RenderError::none && fake::presents==before_resize+2);
  fake::ph=600;
  CHECK(r.clear_and_present(blue)==RenderError::resize_attempted);
  CHECK(r.clear_and_present(blue)==RenderError::none && fake::presents==before_resize+3);
  fake::no_target=true; CHECK(r.clear_and_present(blue)==RenderError::backbuffer_unavailable); fake::no_target=false;
#if PLATFORM_LINUX
  glfake::destroy_fails=true; CHECK(!r.shutdown()); CHECK(glfake::contexts==1 && glfake::library_refs==1);
  CHECK(r.clear_and_present(blue)==RenderError::not_initialized);
  glfake::destroy_fails=false; CHECK(r.shutdown()); CHECK(glfake::library_refs==0);
#else
  CHECK(r.shutdown());
#endif
  CHECK(fake::devices==0 && fake::contexts==0 && fake::chains==0 && glfake::contexts==0);
  for (int failure=0;failure<2;++failure) {
    rhi::OpenGLClearRenderer failed{};
    CHECK(failed.initialize(w)==RenderError::none);
    const int before=fake::presents;
    fake::pw=900; fake::throw_resize=failure==0; fake::resize_no_update=failure==1;
    CHECK(failed.clear_and_present(blue)==RenderError::backend_failure);
    fake::throw_resize=fake::resize_no_update=false; fake::pw=800;
    CHECK(failed.clear_and_present(blue)==RenderError::backend_failure);
    CHECK(fake::presents==before);
    CHECK(failed.shutdown());
  }
  {
    rhi::OpenGLClearRenderer uncertain{};
    CHECK(uncertain.initialize(w)==RenderError::none);
    fake::throw_idle=true; CHECK(!uncertain.shutdown());
    fake::throw_idle=false; CHECK(!uncertain.shutdown());
  }
  w.destroy_window(); CHECK(w.graphics_api()==platform::WindowGraphicsApi::none); w.shutdown();
  {
    // Exercise the actual adapters, selector and diagnostics against doubles.
    rhi::VulkanClearBackend primary{}; rhi::OpenGLClearBackend fallback{};
    rhi::ClearBackendSelection select{primary,fallback};
    auto start=select.start();
    CHECK(start.status==rhi::StartStatus::success && start.selected==rhi::SelectedBackend::primary);
    CHECK(select.clear_and_present(blue)==RenderError::none && fake::color==blue);
    CHECK(select.shutdown());
    fake::no_factory=true; // Vulkan diagnostics cannot acquire its factory.
    start=select.start();
    CHECK(start.status==rhi::StartStatus::success && start.selected==rhi::SelectedBackend::fallback && start.fallback_attempted);
    CHECK(select.clear_and_present(blue)==RenderError::none && fake::color==blue);
    CHECK(select.shutdown()); fake::no_factory=false;
    fake::no_device=true; // Vulkan device failure must be cleaned before GL begins.
    start=select.start();
    CHECK(start.status==rhi::StartStatus::success && start.selected==rhi::SelectedBackend::fallback);
    CHECK(select.clear_and_present(blue)==RenderError::none && fake::color==blue);
    CHECK(select.shutdown()); fake::no_device=false;
    CHECK(fake::refs==0 && fake::devices==0 && fake::contexts==0 && fake::chains==0 && glfake::contexts==0);
    {
      rhi::VulkanClearBackend uncertain{}; rhi::OpenGLClearBackend blocked{};
      rhi::ClearBackendSelection safe{uncertain,blocked};
      fake::no_chain=true; fake::throw_idle=true;
      auto failed=safe.start();
      CHECK(failed.status==rhi::StartStatus::cleanup_failed && !failed.fallback_attempted);
      fake::no_chain=false; fake::throw_idle=false;
      CHECK(!safe.shutdown());
    }
    {
      rhi::VulkanClearBackend uncertain{}; rhi::OpenGLClearBackend blocked{};
      rhi::ClearBackendSelection safe{uncertain,blocked};
      fake::no_chain=true; fake::emit_shutdown_error=true;
      const auto failed=safe.start();
      CHECK(failed.status==rhi::StartStatus::cleanup_failed && !failed.fallback_attempted);
      fake::no_chain=false; fake::emit_shutdown_error=false;
      CHECK(!safe.shutdown());
    }
    rhi::VulkanClearBackend disabled{false}; rhi::OpenGLClearBackend forced{};
    rhi::ClearBackendSelection force{disabled,forced};
    glfake::throw_factory=true;
    CHECK(force.start().status==rhi::StartStatus::failed);
    CHECK(fake::refs==0 && fake::live_window==nullptr);
    glfake::throw_factory=false;
    CHECK(force.start().selected==rhi::SelectedBackend::fallback);
    CHECK(force.shutdown());
  }
#if !PLATFORM_ANDROID
  {
    // A void Resize can log an error instead of throwing. The adapter must
    // inspect diagnostics before any new backbuffer is cleared or presented.
    rhi::VulkanClearBackend primary{}; rhi::OpenGLClearBackend fallback{};
    rhi::ClearBackendSelection select{primary,fallback};
    CHECK(select.start().selected==rhi::SelectedBackend::primary);
    const int before=fake::presents;
    fake::pw=801; fake::emit_resize_error=true;
    CHECK(select.clear_and_present(blue)==RenderError::backend_failure);
    CHECK(fake::presents==before);
    fake::emit_resize_error=false;
    CHECK(select.clear_and_present(blue)==RenderError::backend_failure);
    CHECK(fake::presents==before);
    CHECK(select.shutdown());
  }
  {
    rhi::VulkanClearBackend disabled{false}; rhi::OpenGLClearBackend fallback{};
    rhi::ClearBackendSelection select{disabled,fallback};
    CHECK(select.start().selected==rhi::SelectedBackend::fallback);
    const int before=fake::presents;
    fake::pw=801; fake::emit_resize_error=true;
    CHECK(select.clear_and_present(blue)==RenderError::backend_failure);
    CHECK(fake::presents==before);
    fake::emit_resize_error=false;
    CHECK(select.clear_and_present(blue)==RenderError::backend_failure);
    CHECK(fake::presents==before);
    CHECK(select.shutdown());
  }
#endif
#if PLATFORM_LINUX
  {
    rhi::VulkanClearBackend disabled{false}; rhi::OpenGLClearBackend fallback{};
    rhi::ClearBackendSelection select{disabled,fallback};
    CHECK(select.start().selected==rhi::SelectedBackend::fallback);
    // A logged teardown error must not disappear into the baseline of a
    // retryable SDL context-destroy failure.
    glfake::destroy_fails=true; fake::emit_shutdown_error=true;
    CHECK(!select.shutdown());
    glfake::destroy_fails=false; fake::emit_shutdown_error=false;
    CHECK(!select.shutdown());
    CHECK(select.start().status==rhi::StartStatus::cleanup_failed);
  }
#endif
  CHECK(!glfake::late_load && glfake::library_refs==0);
  std::puts("PASS: GL clear and cleanup with dependency doubles, not a real GPU test");
  return 0;
}
