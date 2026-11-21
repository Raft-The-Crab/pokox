#include "poko/platform/window/sdl_platform.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/foundation/config.hpp"
#include "poko/foundation/config_logging.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <array>
#include <charconv>
#include <chrono>
#include <cstdint>
#include <string>
#include <string_view>
#include <system_error>
#include <cstdio>
int main(int argc, char** argv) {
  using namespace poko;
  std::string config_path;
  std::uint32_t frame_limit = 0;
  rhi::ClearConfig config{};
  config::Overrides overrides;
  for (int i = 1; i < argc; ++i) {
    const std::string_view arg{argv[i]};
    if (arg == "--no-validation") { overrides.validation = false; overrides.validation_set = true; continue; }
    if (arg == "--adapter" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), overrides.adapter_id);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size()) { overrides.adapter_set = true; continue; }
    }
    if (arg == "--config" && i + 1 < argc) { config_path = argv[++i]; continue; }
    if (arg == "--frames" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), frame_limit);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() && frame_limit != 0) continue;
    }
    std::fprintf(stderr, "Usage: pokox_vulkan_clear [--frames positive-integer] [--no-validation] [--adapter index] [--config file.cbor]\n");
    return 2;
  }
  const auto loaded = config::resolve(config_path, overrides);
  if (loaded.error) {
    std::fprintf(stderr, "Config load failed: %s (%s)\n",
                 loaded.detail.c_str(), loaded.error.message().c_str());
    return 2;
  }
  for (const auto& key : loaded.unknown_keys)
    std::fprintf(stderr, "config: unknown key ignored: %s\n", key.c_str());
  const auto& settings = loaded.config;
  config.enable_validation = settings.validation;
  config.adapter_id = settings.adapter_id;
  config::LogGuard log_guard{settings};
  platform::SdlPlatform window;
  // Reverse destruction: renderer, diagnostics, SDL.
  rhi::VulkanDiagnostics diagnostics;
  rhi::VulkanClearRenderer renderer;
  if (window.initialize() != platform::PlatformError::none ||
      window.create_window({"PokoX - Vulkan clear seed", settings.window_width,
                            settings.window_height,
                            platform::WindowGraphicsApi::vulkan}) != platform::PlatformError::none) {
    std::fprintf(stderr, "SDL setup failed: %s\n", SDL_GetError());
    return 1;
  }
  if (diagnostics.start() != rhi::DiagnosticsError::none) {
    std::fputs("Could not acquire exclusive graphics diagnostics; refusing an unmonitored run.\n", stderr);
    return 1;
  }
  const auto initialized = renderer.initialize(window, config);
  if (initialized != rhi::RenderError::none || diagnostics.messages().errors != 0) {
    std::fprintf(stderr, "Vulkan renderer setup failed (stage %u); inspect Diligent/SDL diagnostics.\n",
                 static_cast<unsigned>(initialized));
    return 1;
  }
  std::puts("Vulkan clear seed: blue background expected. Close to exit.");
  std::puts("Desktop drawable-size changes recreate the swapchain; Android resize is not yet supported.");
  constexpr std::array<float, 4> blue{0.035f, 0.12f, 0.28f, 1.0f};
  bool running = true;
  std::uint32_t frames = 0;
  int exit_code = 0;
  while (running) {
    const auto tick = std::chrono::steady_clock::now();
    platform::Event event;
    while (window.poll_event(event)) {
      if (event.type == platform::EventType::quit_requested ||
          event.type == platform::EventType::window_close_requested) running = false;
    }
    if (!running) break;
    if (diagnostics.messages().errors != 0) { exit_code = 1; break; }
    const auto result = renderer.clear_and_present(blue);
    if (diagnostics.messages().errors != 0) { exit_code = 1; break; }
    if (result == rhi::RenderError::not_drawable) { SDL_Delay(20); continue; }
    if (result == rhi::RenderError::resize_attempted) continue;
    if (result == rhi::RenderError::resize_required) {
      std::puts("Drawable size changed on an unsupported resize path; stopping before drawing.");
      exit_code = 2;
      break;
    }
    if (result != rhi::RenderError::none) {
      std::fprintf(stderr, "Clear/present failed (stage %u); no fallback attempted.\n",
                   static_cast<unsigned>(result));
      exit_code = 1;
      break;
    }
    if (frames != UINT32_MAX) ++frames;
    if (frame_limit != 0 && frames >= frame_limit) break;
    // Pace to ~60 fps: unthrottled submission can outrun swapchain semaphore
    // reuse on some drivers (VUID-vkAcquireNextImageKHR-semaphore-01779).
    const auto spent = std::chrono::steady_clock::now() - tick;
    constexpr auto budget = std::chrono::milliseconds(16);
    if (spent < budget)
      SDL_Delay(static_cast<std::uint32_t>(
          std::chrono::duration_cast<std::chrono::milliseconds>(budget - spent).count()));
  }
  if (!renderer.shutdown_checked()) {
    std::fputs("Vulkan renderer cleanup failed or could not be confirmed.\n", stderr);
    exit_code = 1;
  }
  diagnostics.stop();
  window.shutdown();
  const auto messages = diagnostics.messages();
  if (messages.errors != 0) exit_code = 1;
  std::printf("POKO_CLEAR_RESULT submitted=%u validation_requested=%s graphics_errors=%llu graphics_warnings=%llu\n",
    frames, config.enable_validation ? "true" : "false", static_cast<unsigned long long>(messages.errors),
    static_cast<unsigned long long>(messages.warnings));
  if (exit_code == 0 && frame_limit != 0 && frames < frame_limit) exit_code = 2;
  if (frame_limit != 0 && exit_code == 0)
    std::printf("Completed %u clear/present submissions; pixels not independently verified.\n", frames);
  return exit_code;
}
