#include "poko/rhi/device/opengles_clear_renderer.hpp"
#if defined(__ANDROID__)
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>
#include <array>
#include <cstdint>
#include <new>
namespace poko::rhi {
namespace {
#ifndef EGL_OPENGL_ES3_BIT
#define EGL_OPENGL_ES3_BIT 0x00000040
#endif
#ifndef EGL_CONTEXT_MAJOR_VERSION
#define EGL_CONTEXT_MAJOR_VERSION 0x3098
#endif
#ifndef EGL_CONTEXT_MINOR_VERSION
#define EGL_CONTEXT_MINOR_VERSION 0x30FB
#endif
#ifndef EGL_GL_COLORSPACE_SRGB
#define EGL_GL_COLORSPACE_SRGB 0x3089
#endif
}
struct OpenGLClearESRenderer::Impl {
  EGLDisplay display = EGL_NO_DISPLAY;
  EGLSurface surface = EGL_NO_SURFACE;
  EGLContext context = EGL_NO_CONTEXT;
  void* window = nullptr;
  std::uint32_t width = 0, height = 0;
  bool initialized = false;
  bool windowed = false;
  bool srgb = false;
};
OpenGLClearESRenderer::OpenGLClearESRenderer() noexcept = default;
OpenGLClearESRenderer::~OpenGLClearESRenderer() { shutdown(); }
RenderError OpenGLClearESRenderer::initialize(std::uint32_t width, std::uint32_t height) noexcept {
  return initialize_impl(nullptr, width, height);
}
RenderError OpenGLClearESRenderer::initialize_window(void* native_window, std::uint32_t width,
                                                     std::uint32_t height) noexcept {
#if defined(__ANDROID__)
  if (!native_window) return RenderError::native_window_unavailable;
  return initialize_impl(native_window, width, height);
#else
  (void)native_window;
  return RenderError::unsupported_window_system;
#endif
}
RenderError OpenGLClearESRenderer::initialize_impl(void* window, std::uint32_t width,
                                                   std::uint32_t height) noexcept {
  if (impl_) return RenderError::already_initialized;
  if (!width || !height) return RenderError::invalid_window;
  impl_ = new (std::nothrow) Impl{};
  if (!impl_) return RenderError::device_creation_failed;
  impl_->width = width; impl_->height = height;
  impl_->window = window; impl_->windowed = window != nullptr;
#if !defined(__ANDROID__)
  shutdown();
  return RenderError::unsupported_window_system;
#else
  auto* p = impl_;
  p->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
  EGLint major = 0, minor = 0;
  if (p->display == EGL_NO_DISPLAY || !eglInitialize(p->display, &major, &minor)) {
    shutdown(); return RenderError::device_creation_failed;
  }
  if (!eglBindAPI(EGL_OPENGL_ES_API)) { shutdown(); return RenderError::device_creation_failed; }
  const EGLint surface_type = p->windowed ? EGL_WINDOW_BIT : EGL_PBUFFER_BIT;
  const EGLint base_attribs[] = {
      EGL_SURFACE_TYPE, surface_type,
      EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
      EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_ALPHA_SIZE, 8,
      EGL_NONE};
  const EGLint srgb_attribs[] = {
      EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
      EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
      EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_ALPHA_SIZE, 8,
      EGL_GL_COLORSPACE, EGL_GL_COLORSPACE_SRGB,
      EGL_NONE};
  EGLint count = 0;
  EGLConfig config = nullptr;
  if (p->windowed) {
    if (!eglChooseConfig(p->display, base_attribs, &config, 1, &count) || count < 1) {
      shutdown(); return RenderError::device_creation_failed;
    }
  } else {
    // Prefer an sRGB framebuffer like the desktop window path; drivers without
    // EGL_KHR_gl_colorspace reject the attribute, so retry without it.
    p->srgb = eglChooseConfig(p->display, srgb_attribs, &config, 1, &count) && count >= 1;
    if (!p->srgb &&
        (!eglChooseConfig(p->display, base_attribs, &config, 1, &count) || count < 1)) {
      shutdown(); return RenderError::device_creation_failed;
    }
  }
  const EGLint context_attribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
  p->context = eglCreateContext(p->display, config, EGL_NO_CONTEXT, context_attribs);
  if (p->context == EGL_NO_CONTEXT) { shutdown(); return RenderError::device_creation_failed; }
  if (p->windowed) {
    p->surface = eglCreateWindowSurface(p->display, config,
                                        static_cast<EGLNativeWindowType>(p->window), nullptr);
  } else {
    const EGLint surface_attribs[] = {EGL_WIDTH, static_cast<EGLint>(width),
                                      EGL_HEIGHT, static_cast<EGLint>(height), EGL_NONE};
    p->surface = eglCreatePbufferSurface(p->display, config, surface_attribs);
  }
  if (p->surface == EGL_NO_SURFACE ||
      !eglMakeCurrent(p->display, p->surface, p->surface, p->context)) {
    shutdown(); return RenderError::swapchain_creation_failed;
  }
  p->initialized = true;
  return RenderError::none;
#endif
}
RenderError OpenGLClearESRenderer::clear_and_present(const std::array<float, 4>& color) noexcept {
  if (!impl_ || !impl_->initialized) return RenderError::not_initialized;
  glClearColor(color[0], color[1], color[2], color[3]);
  glClear(GL_COLOR_BUFFER_BIT);
  glFinish();
  if (glGetError() != GL_NO_ERROR) return RenderError::backend_failure;
  if (impl_->windowed && !eglSwapBuffers(impl_->display, impl_->surface))
    return RenderError::backend_failure;
  return RenderError::none;
}
RenderError OpenGLClearESRenderer::clear_and_verify(const std::array<float, 4>& color,
                                                    std::array<float, 4>& pixel) noexcept {
  if (!impl_ || !impl_->initialized) return RenderError::not_initialized;
  glClearColor(color[0], color[1], color[2], color[3]);
  glClear(GL_COLOR_BUFFER_BIT);
  glFinish();
  if (glGetError() != GL_NO_ERROR) return RenderError::backend_failure;
  std::array<std::uint8_t, 4> raw{};
  const auto x = static_cast<GLint>(impl_->width / 2), y = static_cast<GLint>(impl_->height / 2);
  glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, raw.data());
  if (glGetError() != GL_NO_ERROR) return RenderError::backend_failure;
  for (int i = 0; i < 4; ++i) pixel[static_cast<std::size_t>(i)] = raw[static_cast<std::size_t>(i)] / 255.0f;
  if (impl_->windowed && !eglSwapBuffers(impl_->display, impl_->surface))
    return RenderError::backend_failure;
  return RenderError::none;
}
bool OpenGLClearESRenderer::read_center_pixel(std::array<float, 4>& out) const noexcept {
  if (!impl_ || !impl_->initialized) return false;
  std::array<std::uint8_t, 4> pixel{};
  const auto x = static_cast<GLint>(impl_->width / 2), y = static_cast<GLint>(impl_->height / 2);
  glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixel.data());
  if (glGetError() != GL_NO_ERROR) return false;
  for (int i = 0; i < 4; ++i) out[static_cast<std::size_t>(i)] = pixel[static_cast<std::size_t>(i)] / 255.0f;
  return true;
}
void OpenGLClearESRenderer::shutdown() noexcept {
  if (!impl_) return;
  auto* p = impl_;
  p->initialized = false;
  if (p->display != EGL_NO_DISPLAY) {
    eglMakeCurrent(p->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    if (p->surface != EGL_NO_SURFACE) eglDestroySurface(p->display, p->surface);
    if (p->context != EGL_NO_CONTEXT) eglDestroyContext(p->display, p->context);
    eglTerminate(p->display);
  }
  delete p;
  impl_ = nullptr;
}
bool OpenGLClearESRenderer::shutdown_checked() noexcept {
  if (cleanup_uncertain_) return false;
  shutdown();
  return true;
}
bool OpenGLClearESRenderer::framebuffer_is_srgb() const noexcept {
  return impl_ && impl_->srgb;
}
} // namespace poko::rhi
#else
#include <new>
namespace poko::rhi {
struct OpenGLClearESRenderer::Impl {};
OpenGLClearESRenderer::OpenGLClearESRenderer() noexcept = default;
OpenGLClearESRenderer::~OpenGLClearESRenderer() = default;
RenderError OpenGLClearESRenderer::initialize(std::uint32_t, std::uint32_t) noexcept { return RenderError::unsupported_window_system; }
RenderError OpenGLClearESRenderer::initialize_window(void*, std::uint32_t, std::uint32_t) noexcept { return RenderError::unsupported_window_system; }
RenderError OpenGLClearESRenderer::clear_and_present(const std::array<float, 4>&) noexcept { return RenderError::not_initialized; }
RenderError OpenGLClearESRenderer::clear_and_verify(const std::array<float, 4>&, std::array<float, 4>&) noexcept { return RenderError::not_initialized; }
bool OpenGLClearESRenderer::read_center_pixel(std::array<float, 4>&) const noexcept { return false; }
void OpenGLClearESRenderer::shutdown() noexcept {}
bool OpenGLClearESRenderer::shutdown_checked() noexcept { return true; }
bool OpenGLClearESRenderer::framebuffer_is_srgb() const noexcept { return false; }
}
#endif
