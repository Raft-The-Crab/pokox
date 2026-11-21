// Actual platform + renderer sources, test-owned SDL/Diligent function doubles.
// No real SDK, OS window, driver, Vulkan device or presentation is exercised.
#include "poko/platform/window/sdl_platform.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include <SDL3/SDL.h>
#include <EngineFactoryVk.h>
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
struct SDL_Window { SDL_WindowID id = 1; };
namespace fake {
SDL_Window storage;
SDL_Window* live_window = nullptr;
SDL_WindowFlags flags = 0;
int refs = 0, w = 800, h = 600, pw = 800, ph = 600;
int devices = 0, contexts = 0, chains = 0, clears = 0, presents = 0;
int resizes = 0;
bool no_driver = false, no_properties = false, no_native = false, fail_size = false;
bool no_factory = false, throw_factory = false, no_device = false, no_context = false, no_chain = false;
bool throw_device = false, throw_chain = false, no_target = false;
bool throw_clear = false, throw_present = false, throw_idle = false;
bool throw_resize = false, resize_no_update = false, emit_resize_error = false;
bool validation = false, throw_set_callback = false, throw_previous = false, emit_shutdown_error = false;
int forwarded = 0;
void DILIGENT_CALL_TYPE previous(Diligent::DEBUG_MESSAGE_SEVERITY, const char*, const char*, const char*, int) {
  ++forwarded; if (throw_previous) throw std::runtime_error("previous callback failed");
}
void emit(const char* phase) {
  const char* requested = std::getenv("POKO_TEST_GRAPHICS_MESSAGE");
  if (!requested || !Diligent::DebugMessageCallback) return;
  const std::string message{requested}; const auto split = message.find(':');
  if (split == std::string::npos || message.substr(split + 1) != phase) return;
  Diligent::DebugMessageCallback(message.substr(0, split) == "warning" ? Diligent::DEBUG_MESSAGE_SEVERITY_WARNING :
    Diligent::DEBUG_MESSAGE_SEVERITY_ERROR, "test-owned diagnostic", "emit", "dependency-double", 1);
}
Sint64 xid = 42;
std::vector<std::string> releases;
std::array<float, 4> color{};
Diligent::ITextureView target;
Diligent::SwapChainDesc last_desc;
#if PLATFORM_WIN32
const char* driver = "windows";
#elif PLATFORM_ANDROID
const char* driver = "android";
#else
const char* driver = "x11";
#endif
}
bool SDL_InitSubSystem(SDL_InitFlags) { ++fake::refs; return true; }
void SDL_QuitSubSystem(SDL_InitFlags) { --fake::refs; }
SDL_Window* SDL_CreateWindow(const char*, int w, int h, SDL_WindowFlags flags) {
  fake::w = w; fake::h = h; fake::pw = w; fake::ph = h; fake::flags = flags;
  fake::live_window = &fake::storage; return fake::live_window;
}
void SDL_DestroyWindow(SDL_Window*) { fake::live_window = nullptr; }
bool SDL_PollEvent(SDL_Event*) { return false; }
SDL_WindowID SDL_GetWindowID(SDL_Window* w) { return w->id; }
bool SDL_GetWindowSize(SDL_Window*, int* w, int* h) {
  if (fake::fail_size) return false;
  *w = fake::w; *h = fake::h; return true;
}
bool SDL_GetWindowSizeInPixels(SDL_Window*, int* w, int* h) {
  if (fake::fail_size) return false;
  *w = fake::pw; *h = fake::ph; return true;
}
SDL_WindowFlags SDL_GetWindowFlags(SDL_Window*) { return fake::flags; }
const char* SDL_GetCurrentVideoDriver() { return fake::no_driver ? nullptr : fake::driver; }
SDL_PropertiesID SDL_GetWindowProperties(SDL_Window*) { return fake::no_properties ? 0U : 1U; }
void* SDL_GetPointerProperty(SDL_PropertiesID, const char* name, void* fallback) {
#if PLATFORM_WIN32
  const char* expected = SDL_PROP_WINDOW_WIN32_HWND_POINTER;
#elif PLATFORM_ANDROID
  const char* expected = SDL_PROP_WINDOW_ANDROID_WINDOW_POINTER;
#else
  const char* expected = SDL_PROP_WINDOW_X11_DISPLAY_POINTER;
#endif
  return fake::no_native || std::string_view(name) != expected ? fallback : static_cast<void*>(&fake::storage);
}
Sint64 SDL_GetNumberProperty(SDL_PropertiesID, const char* name, Sint64 fallback) {
  return std::string_view(name) == SDL_PROP_WINDOW_X11_WINDOW_NUMBER ? fake::xid : fallback;
}
const char* SDL_GetError() { return "test-owned SDL double"; }
void SDL_Delay(std::uint32_t) {}
namespace Diligent {
DebugMessageCallbackType DebugMessageCallback = nullptr;
struct Device final : IRenderDevice {
  Device() { ++fake::devices; }
  RenderDeviceInfo info{};
  const RenderDeviceInfo& GetDeviceInfo() const override { return info; }
  void Release() override { --fake::devices; fake::releases.push_back("device"); delete this; }
};
struct Context final : IDeviceContext {
  Context() { ++fake::contexts; }
  void SetRenderTargets(Uint32 count, ITextureView* views[], ITextureView*, RESOURCE_STATE_TRANSITION_MODE) override {
    if (count == 0) fake::releases.push_back("unbind");
    else if (count != 1 || !views || views[0] != &fake::target) throw std::runtime_error("bad render target");
  }
  void ClearRenderTarget(ITextureView* view, const void* color, RESOURCE_STATE_TRANSITION_MODE) override {
    if (fake::throw_clear || view != &fake::target) throw std::runtime_error("clear failed");
    const auto* floats = static_cast<const float*>(color);
    std::copy(floats, floats + 4, fake::color.begin()); ++fake::clears;
  }
  void WaitForIdle() override {
    fake::releases.push_back("idle");
    fake::emit("shutdown");
    if (fake::emit_shutdown_error && Diligent::DebugMessageCallback)
      Diligent::DebugMessageCallback(Diligent::DEBUG_MESSAGE_SEVERITY_ERROR, "teardown error", "WaitForIdle", "fake", 1);
    if (fake::throw_idle || std::getenv("POKO_TEST_THROW_IDLE")) throw std::runtime_error("idle failed");
  }
  void Release() override { --fake::contexts; fake::releases.push_back("context"); delete this; }
};
struct Chain final : ISwapChain {
  SwapChainDesc desc;
  explicit Chain(const SwapChainDesc& d) : desc(d) { ++fake::chains; }
  const SwapChainDesc& GetDesc() const override { return desc; }
  void Resize(Uint32 width, Uint32 height) override {
    ++fake::resizes;
    if (fake::emit_resize_error && DebugMessageCallback)
      DebugMessageCallback(DEBUG_MESSAGE_SEVERITY_ERROR, "resize error", "Resize", "fake", 1);
    if (fake::throw_resize) throw std::runtime_error("resize failed");
    if (!fake::resize_no_update) { desc.Width = width; desc.Height = height; }
  }
  ITextureView* GetCurrentBackBufferRTV() override { return fake::no_target ? nullptr : &fake::target; }
  void Present(Uint32) override {
    fake::emit("present");
    if (fake::throw_present) throw std::runtime_error("present failed");
    ++fake::presents;
  }
  void SetMaximumFrameLatency(Uint32) override {}
  void Release() override { --fake::chains; fake::releases.push_back("swapchain"); delete this; }
};
struct Factory final : IEngineFactoryVk {
  void SetMessageCallback(DebugMessageCallbackType callback) const override {
    if (fake::throw_set_callback) throw std::runtime_error("callback install failed");
    DebugMessageCallback = callback;
  }
  void CreateDeviceAndContextsVk(const EngineVkCreateInfo& ci, IRenderDevice** d, IDeviceContext** c) override {
    fake::validation = ci.EnableValidation;
    fake::emit("create");
    if (!fake::no_device) *d = new Device;
    if (fake::throw_device) throw std::runtime_error("partial device creation failed");
    if (!fake::no_context) *c = new Context;
  }
  void CreateSwapChainVk(IRenderDevice*, IDeviceContext*, const SwapChainDesc& desc,
                          const NativeWindow& window, ISwapChain** out) override {
#if PLATFORM_WIN32
    if (!window.hWnd) throw std::runtime_error("missing HWND");
#elif PLATFORM_ANDROID
    if (!window.pAWindow) throw std::runtime_error("missing Android window");
#else
    if (!window.pDisplay || window.WindowId != 42) throw std::runtime_error("bad X11 window");
#endif
    fake::last_desc = desc;
    if (!fake::no_chain) *out = new Chain(desc);
    if (fake::throw_chain) throw std::runtime_error("partial swapchain creation failed");
  }
};
IEngineFactoryVk* GetEngineFactoryVk() {
  if (fake::throw_factory) throw std::runtime_error("factory retrieval failed");
  static Factory f;
  return (fake::no_factory || std::getenv("POKO_TEST_VULKAN_UNAVAILABLE")) ? nullptr : &f;
}
}
#define CHECK(condition) do { if (!(condition)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #condition); return 1; \
} } while (false)
int main() {
  using namespace poko;
  using rhi::RenderError;
  constexpr std::array<float, 4> color{0.1f, 0.2f, 0.3f, 1.0f};
  {
    platform::SdlPlatform window;
    rhi::VulkanClearRenderer renderer;
    CHECK(renderer.clear_and_present(color) == RenderError::not_initialized);
    CHECK(renderer.initialize(window) == RenderError::invalid_window);
    renderer.shutdown(); renderer.shutdown();
    CHECK(window.initialize() == platform::PlatformError::none);
    CHECK(window.create_window({"plain", 800, 600}) == platform::PlatformError::none);
    CHECK(renderer.initialize(window) == RenderError::invalid_window);
    window.destroy_window();
    CHECK(window.create_window({"vulkan", 800, 600, platform::WindowGraphicsApi::vulkan}) == platform::PlatformError::none);
    fake::pw = 0;
    CHECK(renderer.initialize(window) == RenderError::not_drawable); fake::pw = 800;
    fake::fail_size = true;
    CHECK(renderer.initialize(window) == RenderError::size_query_failed); fake::fail_size = false;
    fake::no_driver = true;
    CHECK(renderer.initialize(window) == RenderError::unsupported_window_system); fake::no_driver = false;
    const char* driver = fake::driver; fake::driver = "unsupported";
    CHECK(renderer.initialize(window) == RenderError::unsupported_window_system); fake::driver = driver;
    fake::no_properties = true;
    CHECK(renderer.initialize(window) == RenderError::native_window_unavailable); fake::no_properties = false;
    fake::no_native = true;
    CHECK(renderer.initialize(window) == RenderError::native_window_unavailable); fake::no_native = false;
#if PLATFORM_LINUX
    fake::xid = -1;
    CHECK(renderer.initialize(window) == RenderError::native_window_unavailable);
    fake::xid = 0x100000000LL;
    CHECK(renderer.initialize(window) == RenderError::native_window_unavailable); fake::xid = 42;
#endif
    fake::no_factory = true;
    CHECK(renderer.initialize(window) == RenderError::factory_unavailable); fake::no_factory = false;
    for (int failure = 0; failure != 5; ++failure) {
      fake::no_device = failure == 0; fake::no_context = failure == 1;
      fake::throw_device = failure == 2; fake::no_chain = failure == 3; fake::throw_chain = failure == 4;
      const auto expected = failure < 2 ? RenderError::device_creation_failed :
                            failure == 3 ? RenderError::swapchain_creation_failed : RenderError::backend_failure;
      CHECK(renderer.initialize(window) == expected);
      CHECK(fake::devices == 0 && fake::contexts == 0 && fake::chains == 0);
    }
    fake::no_device = fake::no_context = fake::throw_device = fake::no_chain = fake::throw_chain = false;
    {
      rhi::ClearConfig deferred{};
      deferred.defer_failed_cleanup = true;
      fake::no_chain = true;
      CHECK(renderer.initialize(window, deferred) == RenderError::swapchain_creation_failed);
      CHECK(renderer.clear_and_present(color) == RenderError::not_initialized);
      CHECK(fake::devices == 1 && fake::contexts == 1);
      CHECK(renderer.shutdown_checked());
      CHECK(fake::devices == 0 && fake::contexts == 0);
      fake::no_chain = false;
    }
    {
      rhi::ClearConfig depth{}; depth.enable_depth = true;
      CHECK(renderer.initialize(window, depth) == RenderError::none);
      CHECK(fake::last_desc.DepthBufferFormat == Diligent::TEX_FORMAT_D32_FLOAT);
      CHECK(renderer.shutdown_checked());
    }
    fake::flags |= SDL_WINDOW_MINIMIZED;
    CHECK(renderer.initialize(window, {false}) == RenderError::not_drawable);
    fake::flags &= ~SDL_WINDOW_MINIMIZED;
    CHECK(renderer.initialize(window, {false}) == RenderError::none);
    CHECK(!fake::validation);
    CHECK(renderer.initialize(window) == RenderError::already_initialized);
    CHECK(fake::last_desc.Width == 800 && fake::last_desc.Height == 600);
    CHECK(fake::last_desc.DepthBufferFormat == Diligent::TEX_FORMAT_UNKNOWN);
    int calls = 0;
    const auto failed_draw = [](Diligent::IRenderDevice&, Diligent::IDeviceContext&, Diligent::ISwapChain&,
                                Diligent::ITextureView&, void* user) -> RenderError {
      ++*static_cast<int*>(user); return RenderError::backend_failure;
    };
    const auto throwing_draw = [](Diligent::IRenderDevice&, Diligent::IDeviceContext&, Diligent::ISwapChain&,
                                  Diligent::ITextureView&, void*) -> RenderError { throw std::runtime_error("draw"); };
    CHECK(renderer.draw_and_present(nullptr, nullptr) == RenderError::backend_failure);
    CHECK(renderer.draw_and_present(failed_draw, &calls) == RenderError::backend_failure);
    CHECK(calls == 1 && fake::presents == 0);
    CHECK(renderer.draw_and_present(throwing_draw, nullptr) == RenderError::backend_failure);
    CHECK(fake::presents == 0);
    struct Reentry { rhi::VulkanClearRenderer* renderer; bool shutdown_blocked = false; bool draw_blocked = false; } reentry{&renderer};
    const auto successful_draw = [](Diligent::IRenderDevice&, Diligent::IDeviceContext&, Diligent::ISwapChain&,
                                    Diligent::ITextureView&, void* user) -> RenderError {
      auto& state = *static_cast<Reentry*>(user);
      state.shutdown_blocked = !state.renderer->shutdown_checked();
      state.draw_blocked = state.renderer->clear_and_present({0, 0, 0, 1}) == RenderError::backend_failure;
      return RenderError::none;
    };
    fake::no_target = true;
    CHECK(renderer.draw_and_present(successful_draw, &reentry) == RenderError::backbuffer_unavailable);
    fake::no_target = false;
    CHECK(renderer.draw_and_present(successful_draw, &reentry) == RenderError::none);
    CHECK(reentry.shutdown_blocked && reentry.draw_blocked && fake::presents == 1);
    fake::presents = 0; // Keep subsequent legacy clear counts independent.
    CHECK(renderer.clear_and_present(color) == RenderError::none);
    CHECK(fake::clears == 1 && fake::presents == 1 && fake::color == color);
    fake::pw = 801;
    fake::flags |= SDL_WINDOW_MINIMIZED;
    CHECK(renderer.clear_and_present(color) == RenderError::not_drawable);
    CHECK(fake::clears == 1 && fake::presents == 1 && fake::resizes == 0);
    fake::flags &= ~SDL_WINDOW_MINIMIZED;
    fake::pw = 800;
    fake::pw = 0;
    CHECK(renderer.clear_and_present(color) == RenderError::not_drawable);
    CHECK(fake::clears == 1 && fake::presents == 1);
    fake::pw = 801;
#if PLATFORM_ANDROID
    CHECK(renderer.clear_and_present(color) == RenderError::resize_required);
    CHECK(fake::clears == 1 && fake::presents == 1); fake::pw = 800;
#else
    fake::releases.clear();
    CHECK(renderer.clear_and_present(color) == RenderError::resize_attempted);
    CHECK(fake::resizes == 1 && fake::clears == 1 && fake::presents == 1);
    CHECK((fake::releases == std::vector<std::string>{"unbind"}));
    CHECK(renderer.clear_and_present(color) == RenderError::none);
    fake::pw = 800; fake::ph = 601;
    CHECK(renderer.clear_and_present(color) == RenderError::resize_attempted);
    CHECK(fake::resizes == 2 && fake::clears == 2 && fake::presents == 2);
    CHECK(renderer.clear_and_present(color) == RenderError::none);
    fake::ph = 600;
    CHECK(renderer.clear_and_present(color) == RenderError::resize_attempted);
    CHECK(fake::resizes == 3 && fake::clears == 3 && fake::presents == 3);
    CHECK(renderer.clear_and_present(color) == RenderError::none);
#endif
    fake::fail_size = true;
    CHECK(renderer.clear_and_present(color) == RenderError::size_query_failed); fake::fail_size = false;
    ++fake::storage.id; // Simulated identity replacement, not permitted real teardown ordering.
    CHECK(renderer.clear_and_present(color) == RenderError::invalid_window); --fake::storage.id;
    fake::no_target = true;
    CHECK(renderer.clear_and_present(color) == RenderError::backbuffer_unavailable); fake::no_target = false;
    fake::throw_clear = true;
    CHECK(renderer.clear_and_present(color) == RenderError::backend_failure); fake::throw_clear = false;
#if PLATFORM_ANDROID
    CHECK(fake::presents == 1);
#else
    CHECK(fake::presents == 4);
#endif
    fake::throw_present = true;
    CHECK(renderer.clear_and_present(color) == RenderError::backend_failure); fake::throw_present = false;
    fake::releases.clear(); renderer.shutdown(); renderer.shutdown();
    CHECK((fake::releases == std::vector<std::string>{"unbind", "idle", "swapchain", "context", "device"}));
    CHECK(fake::devices == 0 && fake::contexts == 0 && fake::chains == 0);
    CHECK(renderer.clear_and_present(color) == RenderError::not_initialized);
    CHECK(renderer.initialize(window) == RenderError::none);
    CHECK(fake::validation);
    fake::throw_idle = true; // Destructor must still release every owned object.
  }
  CHECK(fake::devices == 0 && fake::contexts == 0 && fake::chains == 0);
  CHECK(fake::refs == 0 && fake::live_window == nullptr);
  fake::throw_idle = false;
#if !PLATFORM_ANDROID
  for (int failure = 0; failure < 2; ++failure) {
    platform::SdlPlatform window;
    rhi::VulkanClearRenderer renderer;
    CHECK(window.initialize() == platform::PlatformError::none);
    CHECK(window.create_window({"resize", 800, 600, platform::WindowGraphicsApi::vulkan}) == platform::PlatformError::none);
    CHECK(renderer.initialize(window) == RenderError::none);
    const int before = fake::presents;
    fake::pw = 900;
    fake::throw_resize = failure == 0;
    fake::resize_no_update = failure == 1;
    CHECK(renderer.clear_and_present(color) == RenderError::backend_failure);
    fake::throw_resize = fake::resize_no_update = false;
    fake::pw = 800;
    CHECK(renderer.clear_and_present(color) == RenderError::backend_failure);
    CHECK(fake::presents == before);
    CHECK(renderer.shutdown_checked());
  }
#endif
  using rhi::DiagnosticsError;
  Diligent::DebugMessageCallback = fake::previous;
  {
    rhi::VulkanDiagnostics first, second;
    fake::throw_factory = true;
    CHECK(first.start() == DiagnosticsError::backend_failure); fake::throw_factory = false;
    fake::no_factory = true;
    CHECK(first.start() == DiagnosticsError::factory_unavailable); fake::no_factory = false;
    fake::throw_set_callback = true;
    CHECK(first.start() == DiagnosticsError::backend_failure); fake::throw_set_callback = false;
    CHECK(first.start() == DiagnosticsError::none);
    fake::throw_factory = true;
    CHECK(first.start() == DiagnosticsError::already_active);
    fake::throw_factory = false;
    CHECK(first.start() == DiagnosticsError::already_active);
    CHECK(second.start() == DiagnosticsError::busy);
    CHECK(first.messages().errors == 0 && first.messages().warnings == 0);
    Diligent::DebugMessageCallback(Diligent::DEBUG_MESSAGE_SEVERITY_INFO, nullptr, nullptr, nullptr, 0);
    Diligent::DebugMessageCallback(Diligent::DEBUG_MESSAGE_SEVERITY_WARNING, "warning", nullptr, nullptr, 0);
    Diligent::DebugMessageCallback(Diligent::DEBUG_MESSAGE_SEVERITY_ERROR, "error", nullptr, nullptr, 0);
    Diligent::DebugMessageCallback(Diligent::DEBUG_MESSAGE_SEVERITY_FATAL_ERROR, "fatal", nullptr, nullptr, 0);
    CHECK(first.messages().errors == 2 && first.messages().warnings == 1 && fake::forwarded == 4);
    fake::throw_previous = true;
    Diligent::DebugMessageCallback(Diligent::DEBUG_MESSAGE_SEVERITY_INFO, "previous throws", nullptr, nullptr, 0);
    fake::throw_previous = false;
    CHECK(first.messages().errors == 3);
    first.stop(); first.stop();
    CHECK(Diligent::DebugMessageCallback == fake::previous);
    CHECK(first.messages().errors == 3 && first.messages().warnings == 1);
    CHECK(second.start() == DiagnosticsError::none);
    CHECK(second.messages().errors == 0 && second.messages().warnings == 0); second.stop();
    CHECK(first.messages().errors == 3);
    CHECK(first.start() == DiagnosticsError::none);
    Diligent::DebugMessageCallback = nullptr;
    first.stop();
    CHECK(Diligent::DebugMessageCallback == nullptr && first.messages().errors == 1);
  }
  {
    rhi::VulkanDiagnostics scoped; CHECK(scoped.start() == DiagnosticsError::none);
  }
  CHECK(Diligent::DebugMessageCallback == nullptr);
  {
    rhi::VulkanDiagnostics broken, next;
    CHECK(broken.start() == DiagnosticsError::none);
    fake::throw_set_callback = true;
    broken.stop();
    fake::throw_set_callback = false;
    CHECK(broken.messages().errors == 1);
    // Recovery: the next start retries the failed restore; with the fake
    // healthy again it succeeds, clears the poison flag, and starts normally.
    CHECK(next.start() == DiagnosticsError::none);
    next.stop();
    CHECK(Diligent::DebugMessageCallback == nullptr);
    // Persistent failure stays fail-closed: poison again, then retry while
    // the setter still throws — recovery must not clear the flag.
    rhi::VulkanDiagnostics third, fourth;
    CHECK(third.start() == DiagnosticsError::none);
    fake::throw_set_callback = true;
    third.stop();
    CHECK(fourth.start() == DiagnosticsError::backend_failure);
    fake::throw_set_callback = false;
    // Once the setter works again, the following start recovers.
    CHECK(fourth.start() == DiagnosticsError::none);
    fourth.stop();
    // Reset the test-owned pointer; production remains fail-closed for this process.
    Diligent::DebugMessageCallback = nullptr;
  }
  std::puts("PASS: actual renderer control flow with dependency doubles; no real GPU validation");
  return 0;
}
