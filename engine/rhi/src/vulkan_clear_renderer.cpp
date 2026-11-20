#include "poko/rhi/vulkan_clear_renderer.hpp"
#include "poko/platform/sdl_platform.hpp"
#include <SDL3/SDL.h>
#include <EngineFactoryVk.h>
#include <RefCntAutoPtr.hpp>
#include <limits>
#include <string_view>
#include <utility>

namespace poko::rhi {
namespace {
RenderError native_window(SDL_Window* window, Diligent::NativeWindow& native) {
  const char* driver = SDL_GetCurrentVideoDriver();
  if (!driver) return RenderError::unsupported_window_system;
  const auto props = SDL_GetWindowProperties(window);
  if (!props) return RenderError::native_window_unavailable;
#if PLATFORM_WIN32
  if (std::string_view(driver) != "windows") return RenderError::unsupported_window_system;
  native.hWnd = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
  if (!native.hWnd) return RenderError::native_window_unavailable;
#elif PLATFORM_ANDROID
  if (std::string_view(driver) != "android") return RenderError::unsupported_window_system;
  native.pAWindow = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_ANDROID_WINDOW_POINTER, nullptr);
  if (!native.pAWindow) return RenderError::native_window_unavailable;
#elif PLATFORM_LINUX
  // This pinned Diligent NativeWindow has Xlib/XCB fields, no Wayland surface.
  if (std::string_view(driver) != "x11") return RenderError::unsupported_window_system;
  native.pDisplay = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_DISPLAY_POINTER, nullptr);
  const auto xid = SDL_GetNumberProperty(props, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0);
  if (!native.pDisplay || xid <= 0 ||
      static_cast<std::uint64_t>(xid) > std::numeric_limits<Diligent::Uint32>::max())
    return RenderError::native_window_unavailable;
  native.WindowId = static_cast<Diligent::Uint32>(xid);
#else
  (void)native;
  return RenderError::unsupported_window_system;
#endif
  return RenderError::none;
}
}
struct VulkanClearRenderer::Impl {
  platform::SdlPlatform* platform = nullptr;
  SDL_WindowID window_id = 0;
  Diligent::RefCntAutoPtr<Diligent::IRenderDevice> device;
  Diligent::RefCntAutoPtr<Diligent::IDeviceContext> context;
  Diligent::RefCntAutoPtr<Diligent::ISwapChain> swapchain;
  ~Impl() { shutdown(); }
  void shutdown() noexcept {
    if (context) {
      try {
        context->SetRenderTargets(0, nullptr, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_NONE);
      } catch (...) { /* Continue cleanup even after backend failure. */ }
      try { context->WaitForIdle(); } catch (...) { /* Best effort on device loss. */ }
    }
    swapchain.Release();
    context.Release();
    device.Release();
  }
};
VulkanClearRenderer::VulkanClearRenderer() noexcept = default;
VulkanClearRenderer::~VulkanClearRenderer() = default;
RenderError VulkanClearRenderer::initialize(platform::SdlPlatform& platform,
                                           ClearConfig config) noexcept {
  if (impl_) return RenderError::already_initialized;
  auto* window = platform.native_window();
  if (!window || (SDL_GetWindowFlags(window) & SDL_WINDOW_VULKAN) == 0)
    return RenderError::invalid_window;
  platform::WindowSize size{};
  if (platform.get_window_size(size) != platform::PlatformError::none)
    return RenderError::size_query_failed;
  if (size.pixel_width == 0 || size.pixel_height == 0) return RenderError::not_drawable;
  try {
    Diligent::NativeWindow native{};
    const auto bridge = native_window(window, native);
    if (bridge != RenderError::none) return bridge;
    auto pending = std::make_unique<Impl>();
    pending->platform = &platform;
    pending->window_id = SDL_GetWindowID(window);
    if (pending->window_id == 0) return RenderError::invalid_window;
    auto* factory = Diligent::GetEngineFactoryVk();
    if (!factory) return RenderError::factory_unavailable;
    Diligent::EngineVkCreateInfo engine{};
    engine.EnableValidation = config.enable_validation;
    engine.AdapterId = config.adapter_id;
    // Zero requests Diligent's default single immediate context; no deferred contexts.
    engine.NumDeferredContexts = 0;
    factory->CreateDeviceAndContextsVk(engine, &pending->device, &pending->context);
    if (!pending->device || !pending->context) return RenderError::device_creation_failed;
    Diligent::SwapChainDesc desc{};
    desc.Width = size.pixel_width;
    desc.Height = size.pixel_height;
    desc.DepthBufferFormat = Diligent::TEX_FORMAT_UNKNOWN;
    factory->CreateSwapChainVk(pending->device.RawPtr(), pending->context.RawPtr(),
                                desc, native, &pending->swapchain);
    if (!pending->swapchain) return RenderError::swapchain_creation_failed;
    impl_ = std::move(pending);
    return RenderError::none;
  } catch (...) { return RenderError::backend_failure; }
}
RenderError VulkanClearRenderer::clear_and_present(const std::array<float, 4>& color) noexcept {
  if (!impl_) return RenderError::not_initialized;
  // The caller must keep the platform object alive. Detect window destruction
  // and recreation, including an allocator reusing the old pointer address.
  auto* window = impl_->platform->native_window();
  if (!window || SDL_GetWindowID(window) != impl_->window_id) return RenderError::invalid_window;
  platform::WindowSize size{};
  if (impl_->platform->get_window_size(size) != platform::PlatformError::none)
    return RenderError::size_query_failed;
  if (size.pixel_width == 0 || size.pixel_height == 0) return RenderError::not_drawable;
  try {
    const auto& desc = impl_->swapchain->GetDesc();
    if (size.pixel_width != desc.Width || size.pixel_height != desc.Height)
      return RenderError::resize_required;
    auto* target = impl_->swapchain->GetCurrentBackBufferRTV();
    if (!target) return RenderError::backbuffer_unavailable;
    impl_->context->SetRenderTargets(1, &target, nullptr, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    impl_->context->ClearRenderTarget(target, color.data(), Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    impl_->swapchain->Present(1);
    return RenderError::none;
  } catch (...) { return RenderError::backend_failure; }
}
void VulkanClearRenderer::shutdown() noexcept { impl_.reset(); }
}  // namespace poko::rhi
