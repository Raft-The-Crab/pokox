#include "poko/platform/sdl_platform.hpp"

#include <SDL3/SDL.h>

#include <cstdio>
#include <string_view>

int main(int argc, char** argv) {
  using namespace poko::platform;
  const bool vulkan = argc > 1 && std::string_view(argv[1]) == "--vulkan";
  const char* title = vulkan ? (argc > 2 ? argv[2] : "PokoX - Vulkan window probe")
                             : (argc > 1 ? argv[1] : "PokoX - platform demo");
  poko::platform::SdlPlatform platform;
  if (platform.initialize() != poko::platform::PlatformError::none) {
    std::fprintf(stderr, "SDL video initialization failed: %s\n", SDL_GetError());
    return 1;
  }
  const WindowConfig config{title, 800, 600,
      vulkan ? WindowGraphicsApi::vulkan : WindowGraphicsApi::none};
  if (platform.create_window(config) !=
      poko::platform::PlatformError::none) {
    std::fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
    return 1;
  }
  WindowSize initial{};
  if (platform.get_window_size(initial) != PlatformError::none) {
    std::fprintf(stderr, "Initial window-size query failed: %s\n", SDL_GetError());
    return 1;
  }
  std::printf("Initial size: logical %ux%u, pixels %ux%u\n", initial.logical_width,
              initial.logical_height, initial.pixel_width, initial.pixel_height);
  if (vulkan) std::puts("Vulkan-compatible window requested; no GPU device, surface or rendering initialized.");
  std::puts("PokoX platform demo: resize the blank window or close it to exit.");
  bool running = true;
  while (running) {
    poko::platform::Event event;
    while (platform.poll_event(event)) {
      if (event.type == poko::platform::EventType::quit_requested ||
          event.type == poko::platform::EventType::window_close_requested) running = false;
      if (event.type == poko::platform::EventType::window_resized) {
        std::printf("Resize: logical %ux%u, pixels %ux%u\n", event.size.logical_width,
                    event.size.logical_height, event.size.pixel_width, event.size.pixel_height);
      }
    }
    SDL_Delay(10);
  }
  platform.shutdown();
  return 0;
}
