#pragma once

#include "poko/platform/i_platform.hpp"

struct SDL_Window;

namespace poko::platform {

// SDL video/event operations must run on the main thread. One SdlPlatform
// instance must own event polling for the process; it consumes unhandled SDL
// events too. Input is not exposed by ENG-02 and must not depend on this pump.
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
  [[nodiscard]] bool poll_event(Event& event) noexcept override;

 private:
  bool initialized_ = false;
  SDL_Window* window_ = nullptr;
};

}  // namespace poko::platform
