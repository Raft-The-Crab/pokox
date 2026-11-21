#include "poko/rhi/device/opengl_clear_renderer.hpp"
#include "poko/platform/window/sdl_platform.hpp"
#include <SDL3/SDL.h>
#include <EngineFactoryOpenGL.h>
#include <RefCntAutoPtr.hpp>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <string_view>
#include <utility>
namespace poko::rhi {
namespace {
// A Diligent swapchain description alone doesn't prove the default framebuffer
// is sRGB: on WGL its legacy ChoosePixelFormat need not select an sRGB visual.
// Query the actual default framebuffer while the new GL context is current.
#if defined(_WIN32) && !defined(_WIN64)
#define POKO_GL_CALL __stdcall
#else
#define POKO_GL_CALL
#endif
bool default_framebuffer_is_srgb() noexcept {
  constexpr unsigned draw_framebuffer = 0x8CA9, draw_binding = 0x8CA6;
  constexpr unsigned back_left = 0x0402, color_encoding = 0x8210, srgb = 0x8C40;
  using GetInt = void (POKO_GL_CALL *)(unsigned, int*);
  using Bind = void (POKO_GL_CALL *)(unsigned, unsigned);
  using GetAttachment = void (POKO_GL_CALL *)(unsigned, unsigned, unsigned, int*);
  using GetError = unsigned (POKO_GL_CALL *)();
  const auto proc = [](const char* name) {
    const auto pointer = SDL_GL_GetProcAddress(name);
    // WGL can return these sentinel values instead of null for an unsupported
    // entry point; never call them as functions.
    const auto address = reinterpret_cast<std::uintptr_t>(pointer);
    return address <= 3 || address == std::numeric_limits<std::uintptr_t>::max()
        ? nullptr : pointer;
  };
  const auto get_int = reinterpret_cast<GetInt>(proc("glGetIntegerv"));
  const auto bind = reinterpret_cast<Bind>(proc("glBindFramebuffer"));
  const auto get_attachment = reinterpret_cast<GetAttachment>(proc("glGetFramebufferAttachmentParameteriv"));
  const auto get_error = reinterpret_cast<GetError>(proc("glGetError"));
  bool ok = false;
  if (get_int && bind && get_attachment && get_error && get_error() == 0) {
    int old_binding = 0, encoding = 0;
    get_int(draw_binding, &old_binding);
    if (old_binding != 0) bind(draw_framebuffer, 0);
    get_attachment(draw_framebuffer, back_left, color_encoding, &encoding);
    if (old_binding != 0) bind(draw_framebuffer, static_cast<unsigned>(old_binding));
    ok = get_error() == 0 && encoding == static_cast<int>(srgb);
  }
  return ok;
}
#undef POKO_GL_CALL
RenderError native_window(SDL_Window* window, Diligent::NativeWindow& native) {
  const auto* driver = SDL_GetCurrentVideoDriver();
  if (!driver) return RenderError::unsupported_window_system;
  auto props = SDL_GetWindowProperties(window);
  if (!props) return RenderError::native_window_unavailable;
#if PLATFORM_WIN32
  if (std::string_view{driver} != "windows") return RenderError::unsupported_window_system;
  native.hWnd = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
  if (!native.hWnd) return RenderError::native_window_unavailable;
#elif PLATFORM_LINUX
  if (std::string_view{driver} != "x11") return RenderError::unsupported_window_system;
  native.pDisplay = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_DISPLAY_POINTER, nullptr);
  const auto xid = SDL_GetNumberProperty(props, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0);
  if (!native.pDisplay || xid <= 0 || static_cast<std::uint64_t>(xid) > std::numeric_limits<Diligent::Uint32>::max())
    return RenderError::native_window_unavailable;
  native.WindowId = static_cast<Diligent::Uint32>(xid);
#else
  (void)native;
  return RenderError::unsupported_window_system;
#endif
  return RenderError::none;
}
}
struct OpenGLClearRenderer::Impl {
  platform::SdlPlatform* platform = nullptr;
  SDL_WindowID window_id = 0;
  SDL_GLContext gl_context = nullptr;
  bool gl_library_loaded = false;
  Diligent::RefCntAutoPtr<Diligent::IRenderDevice> device;
  Diligent::RefCntAutoPtr<Diligent::IDeviceContext> context;
  Diligent::RefCntAutoPtr<Diligent::ISwapChain> swapchain;
  bool initialized = false;
  bool resize_failed = false;
  bool cleanup_uncertain = false;
  bool cleanup() noexcept {
    initialized = false;
    bool ok = true;
    if (context) {
      try { context->SetRenderTargets(0, nullptr, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_NONE); }
      catch (...) { cleanup_uncertain = true; }
      try { context->WaitForIdle(); } catch (...) { cleanup_uncertain = true; }
    }
    swapchain.Release(); context.Release(); device.Release();
    if (gl_context) {
      if (SDL_GL_DestroyContext(gl_context)) gl_context = nullptr;
      else ok = false;
    }
    if (gl_library_loaded && !gl_context) {
      SDL_GL_UnloadLibrary();
      gl_library_loaded = false;
    }
    return ok && !cleanup_uncertain;
  }
  ~Impl() { (void)cleanup(); }
};
OpenGLClearRenderer::OpenGLClearRenderer() noexcept = default;
OpenGLClearRenderer::~OpenGLClearRenderer() { (void)shutdown(); }
RenderError OpenGLClearRenderer::initialize(platform::SdlPlatform& platform, bool validation) noexcept {
  if (impl_) return RenderError::already_initialized;
  auto* window = platform.native_window();
  if (!window || platform.graphics_api() != platform::WindowGraphicsApi::opengl) return RenderError::invalid_window;
  if ((SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) != 0) return RenderError::not_drawable;
  platform::WindowSize size{};
  if (platform.get_window_size(size) != platform::PlatformError::none) return RenderError::size_query_failed;
  if (!size.pixel_width || !size.pixel_height) return RenderError::not_drawable;
  try {
    Diligent::EngineGLCreateInfo info{};
    auto result = native_window(window, info.Window);
    if (result != RenderError::none) return result;
    // Build into a pending impl so a failed initialize() leaves impl_ null
    // and a later call can retry instead of returning already_initialized.
    auto pending = std::make_unique<Impl>();
    pending->platform = &platform; pending->window_id = SDL_GetWindowID(window);
    if (!pending->window_id) return RenderError::invalid_window;
    // On Windows, SDL's first GL library load creates a temporary WGL context
    // and clears the current context. Do it before Diligent creates its own.
    if (!SDL_GL_LoadLibrary(nullptr)) {
      std::fprintf(stderr,"OpenGL library load failed: %s\n",SDL_GetError());
      return RenderError::backend_failure;
    }
    pending->gl_library_loaded = true;
#if PLATFORM_LINUX
    // The pinned Diligent GLX implementation attaches to a current context.
    pending->gl_context = SDL_GL_CreateContext(window);
    if (!pending->gl_context) {
      std::fprintf(stderr,"OpenGL context creation failed: %s\n",SDL_GetError());
      return RenderError::device_creation_failed;
    }
    if (!SDL_GL_MakeCurrent(window, pending->gl_context)) {
      std::fprintf(stderr,"Making the OpenGL context current failed: %s\n",SDL_GetError());
      return RenderError::device_creation_failed;
    }
#endif
    auto* factory = Diligent::GetEngineFactoryOpenGL();
    if (!factory) return RenderError::factory_unavailable;
    info.EnableValidation = validation; info.NumDeferredContexts = 0;
    Diligent::SwapChainDesc desc{};
    desc.Width = size.pixel_width; desc.Height = size.pixel_height;
    desc.DepthBufferFormat = Diligent::TEX_FORMAT_UNKNOWN;
    factory->CreateDeviceAndSwapChainGL(info, &pending->device, &pending->context, desc, &pending->swapchain);
    if (!pending->device || !pending->context) return RenderError::device_creation_failed;
    if (!pending->swapchain) return RenderError::swapchain_creation_failed;
    // The desktop fallback policy requires OpenGL 4.6, not merely a context.
    const auto version = pending->device->GetDeviceInfo().APIVersion;
    if (version.Major < 4 || (version.Major == 4 && version.Minor < 6))
      return RenderError::backend_failure;
    // Check both Diligent's description and the actual default framebuffer.
    // Either check can fail independently, particularly with legacy WGL formats.
    if (pending->swapchain->GetDesc().ColorBufferFormat != Diligent::TEX_FORMAT_RGBA8_UNORM_SRGB ||
        !default_framebuffer_is_srgb()) {
      std::fputs("OpenGL default framebuffer is not confirmed sRGB; refusing color-parity claim.\n", stderr);
      return RenderError::backend_failure;
    }
    pending->initialized = true;
    impl_ = std::move(pending);
    return RenderError::none;
  } catch (...) { return RenderError::backend_failure; }
}
RenderError OpenGLClearRenderer::clear_and_present(const std::array<float,4>& color) noexcept {
  if (!impl_ || !impl_->initialized) return RenderError::not_initialized;
  if (impl_->resize_failed) return RenderError::backend_failure;
  auto* window = impl_->platform->native_window();
  if (!window || SDL_GetWindowID(window) != impl_->window_id) return RenderError::invalid_window;
  if ((SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) != 0) return RenderError::not_drawable;
  platform::WindowSize size{};
  if (impl_->platform->get_window_size(size) != platform::PlatformError::none) return RenderError::size_query_failed;
  if (!size.pixel_width || !size.pixel_height) return RenderError::not_drawable;
  try {
    const auto& desc = impl_->swapchain->GetDesc();
    if (size.pixel_width != desc.Width || size.pixel_height != desc.Height) {
      // Release bindings before resizing; never reuse a partially failed resize.
      impl_->resize_failed = true;
      impl_->context->SetRenderTargets(0, nullptr, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_NONE);
      impl_->swapchain->Resize(size.pixel_width, size.pixel_height);
      const auto& resized = impl_->swapchain->GetDesc();
      if (resized.Width != size.pixel_width || resized.Height != size.pixel_height)
        return RenderError::backend_failure;
      impl_->resize_failed = false;
      return RenderError::resize_attempted; // Check diagnostics before presenting.
    }
    auto* target = impl_->swapchain->GetCurrentBackBufferRTV();
    if (!target) return RenderError::backbuffer_unavailable;
    impl_->context->SetRenderTargets(1, &target, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    impl_->context->ClearRenderTarget(target, color.data(), Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    impl_->swapchain->Present(1);
    return RenderError::none;
  } catch (...) { return RenderError::backend_failure; }
}
bool OpenGLClearRenderer::shutdown() noexcept {
  if (!impl_) return true;
  if (!impl_->cleanup()) return false;
  impl_.reset(); return true;
}
} // namespace poko::rhi
