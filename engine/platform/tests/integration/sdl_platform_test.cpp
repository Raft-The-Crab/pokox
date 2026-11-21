#include "poko/platform/window/sdl_platform.hpp"

#include <SDL3/SDL.h>

#include <climits>
#include <cstdio>
#include <string_view>

using namespace poko::platform;
#define CHECK(condition) do { if (!(condition)) { \
  std::fprintf(stderr, "FAIL line %d: %s (SDL: %s)\n", __LINE__, #condition, SDL_GetError()); \
  return 1; } } while (false)

int main(int argc, char** argv) {
  const bool bad_driver = argc == 2 && std::string_view{argv[1]} == "--bad-driver";
  if (bad_driver) {
    SdlPlatform bad;
    CHECK(bad.initialize() == PlatformError::platform_failure);
    bad.shutdown();
    bad.shutdown();
    return 0;
  }
  // An independent SDL video reference should survive this object's shutdown.
  CHECK(SDL_InitSubSystem(SDL_INIT_VIDEO));
  SdlPlatform platform;
  const char title_storage[] = "PokoX SDL test EXTRA";
  const WindowConfig valid{std::string_view(title_storage, 14), 640, 480};
  WindowSize queried{1, 2, 3, 4};
  CHECK(platform.native_window() == nullptr);
  CHECK(platform.get_window_size(queried) == PlatformError::not_initialized);
  CHECK(queried.pixel_height == 4);
  CHECK(platform.create_window(valid) == PlatformError::not_initialized);
  CHECK(platform.initialize() == PlatformError::none);
  CHECK(platform.initialize() == PlatformError::already_initialized);
  CHECK(platform.get_window_size(queried) == PlatformError::window_not_created);
  CHECK(queried.pixel_height == 4);
  CHECK(platform.create_window({"zero", 0, 480}) == PlatformError::invalid_window_config);
  CHECK(platform.create_window({"large", static_cast<std::uint32_t>(INT_MAX) + 1U, 1}) ==
        PlatformError::invalid_window_config);
  const char embedded[] = {'a', '\0', 'b'};
  CHECK(platform.create_window({std::string_view(embedded, 3), 1, 1}) ==
        PlatformError::invalid_window_config);
  CHECK(platform.create_window(valid) == PlatformError::none);
  CHECK(platform.create_window(valid) == PlatformError::window_exists);

  int count = 0;
  SDL_Window** windows = SDL_GetWindows(&count);
  CHECK(windows && count == 1);
  SDL_Window* window = windows[0];
  CHECK(platform.native_window() == window);
  CHECK(platform.get_window_size(queried) == PlatformError::none);
  CHECK(queried.logical_width > 0 && queried.pixel_width > 0);
  CHECK(std::string_view(SDL_GetWindowTitle(window)) == "PokoX SDL test");
  const SDL_WindowID id = SDL_GetWindowID(window);
  SDL_free(windows);
  CHECK(id != 0);
  Event event{};
  while (platform.poll_event(event)) {}  // Discard initial show events.
  CHECK(SDL_SetWindowSize(window, 800, 500));
  CHECK(SDL_SyncWindow(window));
  bool saw_resize = false;
  const Uint64 deadline = SDL_GetTicks() + 3000;
  while (!saw_resize && SDL_GetTicks() < deadline) {
    while (platform.poll_event(event)) {
      if (event.type == EventType::window_resized && event.size.logical_width == 800 &&
          event.size.logical_height == 500 && event.size.pixel_width > 0 &&
          event.size.pixel_height > 0) saw_resize = true;
    }
    if (!saw_resize) SDL_Delay(5);
  }
  CHECK(saw_resize);

  // Events for a different window must not be delivered as ours.
  SDL_Event raw{};
  raw.type = SDL_EVENT_WINDOW_CLOSE_REQUESTED;
  raw.window.windowID = id + 1000;
  CHECK(SDL_PushEvent(&raw));
  event = {EventType::window_resized, {1, 2, 3, 4}};
  CHECK(!platform.poll_event(event));
  CHECK(event.type == EventType::window_resized && event.size.pixel_height == 4);

  // This synthetic close checks event translation; it is not an OS close-button test.
  raw = {};
  raw.type = SDL_EVENT_WINDOW_CLOSE_REQUESTED;
  raw.window.windowID = id;
  CHECK(SDL_PushEvent(&raw));
  bool saw_close = false;
  while (platform.poll_event(event)) if (event.type == EventType::window_close_requested) saw_close = true;
  CHECK(saw_close);
  CHECK(SDL_GetWindowFromID(id) == window);  // Close requests do not destroy the window.
  raw = {};
  raw.type = SDL_EVENT_QUIT;
  CHECK(SDL_PushEvent(&raw));
  bool saw_quit = false;
  while (platform.poll_event(event)) if (event.type == EventType::quit_requested) saw_quit = true;
  CHECK(saw_quit);
  event = {EventType::window_close_requested, {1, 2, 3, 4}};
  CHECK(!platform.poll_event(event));
  CHECK(event.type == EventType::window_close_requested && event.size.pixel_height == 4);
  platform.destroy_window();
  CHECK(SDL_GetWindowFromID(id) == nullptr);
  CHECK(platform.native_window() == nullptr);
  CHECK(platform.get_window_size(queried) == PlatformError::window_not_created);
  platform.destroy_window();
  CHECK(platform.create_window(valid) == PlatformError::none);
  platform.shutdown();
  platform.shutdown();
  CHECK((SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO) != 0);
  CHECK(platform.create_window(valid) == PlatformError::not_initialized);
  std::printf("SDL %s driver: create/resize/close translation/quit/teardown passed\n", SDL_GetCurrentVideoDriver());
  // Repeat the lifecycle on the same object after a complete shutdown.
  CHECK(platform.initialize() == PlatformError::none);
  CHECK(platform.create_window(valid) == PlatformError::none);
  platform.shutdown();
  CHECK((SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO) != 0);

  // Destruction, without explicit shutdown, must release the window but not
  // this test's independent video-subsystem reference.
  SDL_WindowID scoped_id = 0;
  {
    SdlPlatform scoped;
    CHECK(scoped.initialize() == PlatformError::none);
    CHECK(scoped.create_window(valid) == PlatformError::none);
    windows = SDL_GetWindows(&count);
    CHECK(windows && count == 1);
    scoped_id = SDL_GetWindowID(windows[0]);
    SDL_free(windows);
    CHECK(scoped_id != 0);
  }
  CHECK(SDL_GetWindowFromID(scoped_id) == nullptr);
  CHECK((SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO) != 0);
  std::puts("SDL repeat-initialize and destructor-only cleanup passed");
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  return 0;
}
