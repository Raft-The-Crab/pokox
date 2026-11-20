// Compile the real sdl_platform.cpp against a test-only SDL function double.
// These checks validate backend control flow, NOT real SDL/OS compatibility.
#include "poko/platform/sdl_platform.hpp"
#include <SDL3/SDL.h>
#include <climits>
#include <cstdio>
#include <deque>
#include <exception>
#include <string>
#include <string_view>

struct SDL_Window { SDL_WindowID id; };
namespace fake {
int refs = 0, init_calls = 0, quit_calls = 0, create_calls = 0, destroy_calls = 0;
bool fail_init = false, fail_create = false, fail_logical = false, fail_pixels = false;
int width = 640, height = 480, pixel_width = 1280, pixel_height = 960;
SDL_Window storage{1};
SDL_Window* live = nullptr;
SDL_WindowFlags flags = 0;
std::string title;
std::deque<SDL_Event> events;
void push(std::uint32_t type, SDL_WindowID id = 1) {
  SDL_Event event{};
  event.window = {type, id};
  events.push_back(event);
}
}
bool SDL_InitSubSystem(SDL_InitFlags) {
  ++fake::init_calls;
  if (fake::fail_init) return false;
  ++fake::refs;
  return true;
}
void SDL_QuitSubSystem(SDL_InitFlags) { ++fake::quit_calls; --fake::refs; }
SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags) {
  ++fake::create_calls;
  if (fake::fail_create) return nullptr;
  fake::title = title;
  fake::width = w; fake::height = h; fake::flags = flags;
  fake::live = &fake::storage;
  return fake::live;
}
void SDL_DestroyWindow(SDL_Window* window) {
  if (window != fake::live) std::terminate();
  ++fake::destroy_calls;
  fake::live = nullptr;
}
bool SDL_PollEvent(SDL_Event* event) {
  if (fake::events.empty()) return false;
  *event = fake::events.front(); fake::events.pop_front();
  return true;
}
SDL_WindowID SDL_GetWindowID(SDL_Window* window) { return window->id; }
bool SDL_GetWindowSize(SDL_Window*, int* w, int* h) {
  if (fake::fail_logical) return false;
  *w = fake::width; *h = fake::height; return true;
}
bool SDL_GetWindowSizeInPixels(SDL_Window*, int* w, int* h) {
  if (fake::fail_pixels) return false;
  *w = fake::pixel_width; *h = fake::pixel_height; return true;
}
using namespace poko::platform;
#define CHECK(condition) do { if (!(condition)) { \
  std::fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #condition); return 1; \
} } while (false)
int main() {
  const WindowConfig valid{"PokoX", 640, 480};
  Event event{EventType::window_close_requested, {1, 2, 3, 4}};
  WindowSize size{1, 2, 3, 4};
  {
    SdlPlatform platform;
    CHECK(platform.native_window() == nullptr);
    CHECK(platform.get_window_size(size) == PlatformError::not_initialized);
    CHECK(size.pixel_height == 4);
    CHECK(platform.create_window(valid) == PlatformError::not_initialized);
    CHECK(!platform.poll_event(event));
    CHECK(event.size.pixel_height == 4);
    platform.shutdown(); platform.destroy_window();
    CHECK(fake::quit_calls == 0 && fake::destroy_calls == 0);
    fake::fail_init = true;
    CHECK(platform.initialize() == PlatformError::platform_failure);
    platform.shutdown(); platform.shutdown();
    CHECK(fake::refs == 0 && fake::quit_calls == 0);
    fake::fail_init = false;
    CHECK(platform.initialize() == PlatformError::none);
    CHECK(platform.initialize() == PlatformError::already_initialized);
    CHECK(fake::refs == 1 && fake::init_calls == 2);
    CHECK(platform.get_window_size(size) == PlatformError::window_not_created);
    CHECK(size.pixel_height == 4);
    CHECK(platform.create_window({"unknown", 1, 1, static_cast<WindowGraphicsApi>(255)}) == PlatformError::invalid_window_config);
    CHECK(platform.create_window({"zero", 0, 1}) == PlatformError::invalid_window_config);
    CHECK(platform.create_window({"zero", 1, 0}) == PlatformError::invalid_window_config);
    CHECK(platform.create_window({"wide", static_cast<std::uint32_t>(INT_MAX) + 1U, 1}) == PlatformError::invalid_window_config);
    CHECK(platform.create_window({"tall", 1, static_cast<std::uint32_t>(INT_MAX) + 1U}) == PlatformError::invalid_window_config);
    const char embedded[] = {'x', '\0', 'y'};
    CHECK(platform.create_window({std::string_view(embedded, 3), 1, 1}) == PlatformError::invalid_window_config);
    CHECK(fake::create_calls == 0);
    fake::fail_create = true;
    CHECK(platform.create_window(valid) == PlatformError::platform_failure);
    CHECK(fake::live == nullptr && fake::refs == 1);
    platform.destroy_window();
    CHECK(fake::destroy_calls == 0);
    fake::fail_create = false;
    char title[] = "PokoX extra";
    CHECK(platform.create_window({std::string_view(title, 5), 640, 480}) == PlatformError::none);
    title[0] = 'X';
    CHECK(fake::title == "PokoX");
    CHECK(platform.native_window() == fake::live);
    CHECK((fake::flags & SDL_WINDOW_VULKAN) == 0);
    CHECK(platform.get_window_size(size) == PlatformError::none);
    CHECK(size.logical_width == 640 && size.logical_height == 480);
    CHECK(size.pixel_width == 1280 && size.pixel_height == 960);
    CHECK((fake::flags & SDL_WINDOW_RESIZABLE) != 0);
    CHECK((fake::flags & SDL_WINDOW_HIGH_PIXEL_DENSITY) != 0);
    CHECK(platform.create_window(valid) == PlatformError::window_exists);
    CHECK(fake::create_calls == 2);
    // Unhandled and foreign-window events are skipped, not delivered.
    fake::push(0x999); fake::push(SDL_EVENT_WINDOW_CLOSE_REQUESTED, 999);
    CHECK(!platform.poll_event(event));
    CHECK(event.type == EventType::window_close_requested && event.size.pixel_height == 4);
    fake::push(SDL_EVENT_WINDOW_RESIZED);
    CHECK(platform.poll_event(event));
    CHECK(event.type == EventType::window_resized);
    CHECK(event.size.logical_width == 640 && event.size.logical_height == 480);
    CHECK(event.size.pixel_width == 1280 && event.size.pixel_height == 960);
    fake::width = 700; fake::pixel_width = 1400;
    fake::push(SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED);
    CHECK(platform.poll_event(event));
    CHECK(event.size.logical_width == 700 && event.size.pixel_width == 1400);
    // Either failed size query must leave the caller's output untouched.
    for (int which = 0; which != 2; ++which) {
      fake::fail_logical = which == 0; fake::fail_pixels = which == 1;
      size = {1, 2, 3, 4};
      CHECK(platform.get_window_size(size) == PlatformError::platform_failure);
      CHECK(size.logical_width == 1 && size.pixel_height == 4);
      fake::push(SDL_EVENT_WINDOW_RESIZED);
      CHECK(!platform.poll_event(event));
      CHECK(event.size.logical_width == 700 && event.size.pixel_width == 1400);
    }
    fake::fail_logical = fake::fail_pixels = false;
    // Defensive clamping also covers a minimized/non-drawable window.
    fake::width = 0; fake::height = -1; fake::pixel_width = -2; fake::pixel_height = 0;
    fake::push(SDL_EVENT_WINDOW_RESIZED);
    CHECK(platform.poll_event(event));
    CHECK(event.size.logical_width == 0 && event.size.logical_height == 0);
    CHECK(event.size.pixel_width == 0 && event.size.pixel_height == 0);
    fake::push(SDL_EVENT_WINDOW_CLOSE_REQUESTED);
    CHECK(platform.poll_event(event));
    CHECK(event.type == EventType::window_close_requested && event.size.pixel_width == 0);
    CHECK(fake::live != nullptr);
    fake::push(SDL_EVENT_QUIT);
    CHECK(platform.poll_event(event));
    CHECK(event.type == EventType::quit_requested && event.size.logical_width == 0);
    platform.destroy_window(); platform.destroy_window();
    CHECK(fake::live == nullptr && fake::destroy_calls == 1);
    CHECK(platform.native_window() == nullptr);
    CHECK(platform.get_window_size(size) == PlatformError::window_not_created);
    fake::push(SDL_EVENT_WINDOW_RESIZED); fake::push(SDL_EVENT_WINDOW_CLOSE_REQUESTED);
    CHECK(!platform.poll_event(event));
    CHECK(event.type == EventType::quit_requested);
    // Quit is process-level and remains observable with no window.
    fake::push(SDL_EVENT_QUIT);
    CHECK(platform.poll_event(event));
    const WindowConfig vulkan{"Vulkan request", 640, 480, WindowGraphicsApi::vulkan};
    fake::fail_create = true;
    CHECK(platform.create_window(vulkan) == PlatformError::platform_failure);
    CHECK(platform.native_window() == nullptr);
    fake::fail_create = false;
    CHECK(platform.create_window(vulkan) == PlatformError::none);
    CHECK((fake::flags & SDL_WINDOW_VULKAN) != 0);
    CHECK(platform.native_window() != nullptr);
    platform.shutdown(); platform.shutdown();
    CHECK(platform.native_window() == nullptr);
    CHECK(fake::refs == 0 && fake::quit_calls == 1 && fake::destroy_calls == 2);
    CHECK(platform.initialize() == PlatformError::none);
    CHECK(platform.create_window(valid) == PlatformError::none);
    // Destructor alone must clean up this new lifecycle.
  }
  CHECK(fake::refs == 0 && fake::quit_calls == 2 && fake::destroy_calls == 3);
  // Never release an independent consumer's video reference.
  CHECK(SDL_InitSubSystem(SDL_INIT_VIDEO));
  {
    SdlPlatform platform;
    CHECK(platform.initialize() == PlatformError::none);
    CHECK(platform.create_window(valid) == PlatformError::none);
    CHECK(fake::refs == 2);
  }
  CHECK(fake::refs == 1 && fake::live == nullptr);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  CHECK(fake::refs == 0 && fake::events.empty());
  {
    SdlPlatform failed;
    fake::fail_init = true;
    CHECK(failed.initialize() == PlatformError::platform_failure);
  }
  CHECK(fake::refs == 0 && fake::live == nullptr);
  std::puts("PASS: real backend control flow with fault-injected SDL double (not OS validation)");
  return 0;
}
