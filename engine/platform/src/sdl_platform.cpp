#include "poko/platform/sdl_platform.hpp"

#include <SDL3/SDL.h>

#include <climits>
#include <string>

namespace poko::platform {

SdlPlatform::~SdlPlatform() { shutdown(); }

PlatformError SdlPlatform::initialize() noexcept {
  if (initialized_) return PlatformError::already_initialized;
  if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) return PlatformError::platform_failure;
  initialized_ = true;
  return PlatformError::none;
}

void SdlPlatform::shutdown() noexcept {
  destroy_window();
  if (initialized_) {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    initialized_ = false;
  }
}

PlatformError SdlPlatform::create_window(const WindowConfig& config) noexcept {
  if (!initialized_) return PlatformError::not_initialized;
  if (window_) return PlatformError::window_exists;
  if (config.width == 0 || config.height == 0 || config.width > INT_MAX ||
      config.height > INT_MAX || config.title.find('\0') != std::string_view::npos) {
    return PlatformError::invalid_window_config;
  }
  SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY;
  switch (config.graphics_api) {
    case WindowGraphicsApi::none: break;
    case WindowGraphicsApi::vulkan: flags |= SDL_WINDOW_VULKAN; break;
    default: return PlatformError::invalid_window_config;
  }
  try {
    // string_view is not necessarily NUL-terminated; SDL copies this title.
    const std::string title(config.title);
    window_ = SDL_CreateWindow(title.c_str(), static_cast<int>(config.width),
                               static_cast<int>(config.height),
                               flags);
  } catch (...) {
    return PlatformError::platform_failure;
  }
  return window_ ? PlatformError::none : PlatformError::platform_failure;
}

void SdlPlatform::destroy_window() noexcept {
  if (window_) {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
  }
}

PlatformError SdlPlatform::get_window_size(WindowSize& size) noexcept {
  if (!initialized_) return PlatformError::not_initialized;
  if (!window_) return PlatformError::window_not_created;
  int w = 0, h = 0, pw = 0, ph = 0;
  if (!SDL_GetWindowSize(window_, &w, &h) || !SDL_GetWindowSizeInPixels(window_, &pw, &ph)) {
    return PlatformError::platform_failure;
  }
  const auto nonnegative = [](int x) { return static_cast<std::uint32_t>(x > 0 ? x : 0); };
  size = {nonnegative(w), nonnegative(h), nonnegative(pw), nonnegative(ph)};
  return PlatformError::none;
}

bool SdlPlatform::poll_event(Event& event) noexcept {
  if (!initialized_) return false;
  SDL_Event raw;
  while (SDL_PollEvent(&raw)) {
    if (raw.type == SDL_EVENT_QUIT) {
      event = {EventType::quit_requested, {}};
      return true;
    }
    if (raw.type != SDL_EVENT_WINDOW_CLOSE_REQUESTED && raw.type != SDL_EVENT_WINDOW_RESIZED &&
        raw.type != SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) continue;
    if (!window_ || raw.window.windowID != SDL_GetWindowID(window_)) continue;
    if (raw.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
      event = {EventType::window_close_requested, {}};
      return true;
    }
    if (raw.type == SDL_EVENT_WINDOW_RESIZED || raw.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) {
      WindowSize size{};
      if (get_window_size(size) != PlatformError::none) continue;
      event = {EventType::window_resized, size};
      return true;
    }
  }
  return false;
}

}  // namespace poko::platform
