#pragma once

#include "poko/platform/window/i_platform.hpp"

struct SDL_Window;
union SDL_Event;

namespace poko::platform {

// SDL video/event operations must run on the main thread. One SdlPlatform
// instance must own event polling for the process; it consumes unhandled SDL
// events too. An optional synchronous SDL event observer supports backend UI integration.
class SdlPlatform final : public IPlatform {
 public:
  SdlPlatform() noexcept = default;
  ~SdlPlatform() override;
  [[nodiscard]] PlatformError initialize() noexcept override;
  void shutdown() noexcept override;
  [[nodiscard]] PlatformError create_window(const WindowConfig& config) noexcept override;
  void destroy_window() noexcept override;
  [[nodiscard]] PlatformError get_window_size(WindowSize& size) noexcept override;

  // Backend-specific bridge for RHI integration, not gameplay code.
  // Borrowed, main-thread-only; null before creation/after destruction. Never
  // destroy this pointer or change its graphics mode. It becomes invalid at
  // destroy_window/shutdown/destruction; a recreated window is a new lifetime,
  // even if its address is reused. Release all GPU/surface references first.
  [[nodiscard]] SDL_Window* native_window() const noexcept { return window_; }
  [[nodiscard]] WindowGraphicsApi graphics_api() const noexcept { return graphics_api_; }
  [[nodiscard]] bool poll_event(Event& event) noexcept override;
  // Called synchronously on the polling thread for each raw SDL event before
  // translation, including events otherwise ignored. The event is borrowed
  // only for the call. Observer must filter window IDs, must not poll or
  // mutate the platform, and must not throw. No observer is retained.
  using EventObserver = void (*)(const SDL_Event&, void*) noexcept;
  [[nodiscard]] bool poll_event(Event& event, EventObserver observer, void* user) noexcept;

 private:
  bool initialized_ = false;
  SDL_Window* window_ = nullptr;
  WindowGraphicsApi graphics_api_ = WindowGraphicsApi::none;
  // SDL3 emits WINDOW_RESIZED and WINDOW_PIXEL_SIZE_CHANGED for one HiDPI
  // resize; both map to identical WindowSize, so consecutive duplicates are
  // dropped. Reset whenever the window is (re)created.
  WindowSize last_resize_{};
  bool has_last_resize_ = false;
  // Set when an SDL resize event arrived but the size query failed; retried
  // on the next poll_event instead of silently dropping the notification.
  bool pending_resize_ = false;
};

}  // namespace poko::platform
