#include "poko/rhi/device/fallback_clear_backends.hpp"
#include <SDL3/SDL.h>
#include <EngineFactoryOpenGL.h>
#include <cstdio>
namespace poko::rhi {
RenderError VulkanClearBackend::initialize() noexcept {
  if (!enabled_) return RenderError::factory_unavailable;
  if (window_.initialize()!=platform::PlatformError::none) {
    std::fprintf(stderr,"Vulkan SDL video initialization failed: %s\n",SDL_GetError());
    return RenderError::backend_failure;
  }
  if (window_.create_window({"PokoX - Vulkan clear",800,600,platform::WindowGraphicsApi::vulkan})!=platform::PlatformError::none) {
    std::fprintf(stderr,"Vulkan SDL window creation failed: %s\n",SDL_GetError());
    return RenderError::invalid_window;
  }
  if (diagnostics_.start()!=DiagnosticsError::none) return RenderError::backend_failure;
  ClearConfig config{};
  config.enable_validation=validation_;
  config.defer_failed_cleanup=true;
  const auto result=renderer_.initialize(window_, config);
  return diagnostics_.messages().errors ? RenderError::backend_failure : result;
}
RenderError VulkanClearBackend::clear_and_present(const std::array<float,4>& color) noexcept {
  if (diagnostics_.messages().errors) return RenderError::backend_failure;
  const auto result=renderer_.clear_and_present(color);
  return diagnostics_.messages().errors ? RenderError::backend_failure : result;
}
bool VulkanClearBackend::shutdown() noexcept {
  if (cleanup_error_) return false;
  const auto before=diagnostics_.messages().errors;
  const bool renderer_ok=renderer_.shutdown_checked();
  // Always release diagnostics and the window even when renderer cleanup
  // fails; otherwise the SDL window and Diligent callback stay installed.
  diagnostics_.stop();
  const bool diagnostics_ok=diagnostics_.messages().errors<=before;
  window_.shutdown();
  if (!renderer_ok || !diagnostics_ok) { cleanup_error_=true; return false; }
  return true;
}
RenderError OpenGLClearBackend::initialize() noexcept {
  if (window_.initialize()!=platform::PlatformError::none) {
    std::fprintf(stderr,"OpenGL SDL video initialization failed: %s\n",SDL_GetError());
    return RenderError::backend_failure;
  }
#if PLATFORM_LINUX
  // Diligent's GLX path attaches to a current SDL-created context. Set global
  // GL attributes before SDL creates the window, requesting the planned 4.6.
  if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4) ||
      !SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,6) ||
      !SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE) ||
      !SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1) ||
      !SDL_GL_SetAttribute(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,1)) {
    std::fprintf(stderr,"OpenGL SDL attribute setup failed: %s\n",SDL_GetError());
    return RenderError::backend_failure;
  }
#endif
  if (window_.create_window({"PokoX - OpenGL clear",800,600,platform::WindowGraphicsApi::opengl})!=platform::PlatformError::none) {
    std::fprintf(stderr,"OpenGL SDL window creation failed: %s\n",SDL_GetError());
    return RenderError::invalid_window;
  }
  try {
    if (diagnostics_.start_with_factory(Diligent::GetEngineFactoryOpenGL())!=DiagnosticsError::none)
      return RenderError::backend_failure;
  } catch (...) { return RenderError::backend_failure; }
  const auto result=renderer_.initialize(window_,validation_);
  return diagnostics_.messages().errors ? RenderError::backend_failure : result;
}
RenderError OpenGLClearBackend::clear_and_present(const std::array<float,4>& color) noexcept {
  if (diagnostics_.messages().errors) return RenderError::backend_failure;
  const auto result=renderer_.clear_and_present(color);
  return diagnostics_.messages().errors ? RenderError::backend_failure : result;
}
bool OpenGLClearBackend::shutdown() noexcept {
  if (cleanup_error_) return false;
  const auto before=diagnostics_.messages().errors;
  const bool cleaned=renderer_.shutdown();
  // A context-destroy failure is retryable, but any diagnostic emitted during
  // that failed attempt must remain sticky; it cannot become the next
  // attempt's baseline and be mistaken for clean teardown.
  if (diagnostics_.messages().errors > before) { cleanup_error_=true; return false; }
  if (!cleaned) return false;
  diagnostics_.stop();
  if (diagnostics_.messages().errors > before) { cleanup_error_=true; return false; }
  window_.shutdown(); return true;
}
}
