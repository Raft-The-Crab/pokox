#include "poko/platform/window/sdl_platform.hpp"
#include "poko/render/framegraph/frame_graph.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_triangle_pass.hpp"
#include "poko/foundation/config.hpp"
#include "poko/foundation/config_logging.hpp"
#include "poko/resource/ktx2.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <array>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <exception>
#include <memory>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

#ifndef POKO_DEMO_DEPTH
#define POKO_DEMO_DEPTH 0
#endif
#ifndef POKO_DEMO_UNIFORM
#define POKO_DEMO_UNIFORM 0
#endif
#ifndef POKO_TEXTURED_VERTEX_SPV
#define POKO_TEXTURED_VERTEX_SPV ""
#endif
#ifndef POKO_TEXTURED_FRAGMENT_SPV
#define POKO_TEXTURED_FRAGMENT_SPV ""
#endif

int main(int argc, char** argv) {
  using namespace poko;
  std::string vertex, fragment, config_path, texture_path;
  std::uint32_t limit = 0;
  rhi::ClearConfig config{};
  config::Overrides overrides;
  constexpr bool uniform_demo = POKO_DEMO_UNIFORM != 0;
  constexpr bool depth_demo = POKO_DEMO_DEPTH != 0 || uniform_demo;
  bool disable_depth = false;
  config.enable_depth = depth_demo;
  for (int i = 1; i < argc; ++i) {
    const std::string_view arg{argv[i]};
    if (arg == "--no-validation") { overrides.validation = false; overrides.validation_set = true; continue; }
    if (depth_demo && !uniform_demo && arg == "--show-no-depth") { disable_depth = true; continue; }
    if (arg == "--adapter" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), overrides.adapter_id);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size()) { overrides.adapter_set = true; continue; }
    }
    if (arg == "--config" && i + 1 < argc) { config_path = argv[++i]; continue; }
    if (arg == "--vertex" && i + 1 < argc) { vertex = argv[++i]; continue; }
    if (arg == "--fragment" && i + 1 < argc) { fragment = argv[++i]; continue; }
    if (arg == "--texture" && i + 1 < argc) { texture_path = argv[++i]; continue; }
    if (arg == "--frames" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), limit);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() && limit) continue;
    }
    std::fprintf(stderr, "Usage: %s --vertex file.spv --fragment file.spv [--frames positive-integer] [--adapter index] [--no-validation] [--config file.cbor]%s%s\n",
                 uniform_demo ? "pokox_uniform" : depth_demo ? "pokox_depth" : "pokox_triangle", (depth_demo && !uniform_demo) ? " [--show-no-depth]" : "",
                 depth_demo || uniform_demo ? "" : " [--texture file.ktx2]");
    return 2;
  }
  // ENG-18: --texture selects the compiled-in textured-quad shaders and mode.
  if (!texture_path.empty() && (depth_demo || uniform_demo)) {
    std::fputs("--texture is only supported by pokox_triangle.\n", stderr);
    return 2;
  }
  if (!texture_path.empty()) {
    if (vertex.empty()) vertex = POKO_TEXTURED_VERTEX_SPV;
    if (fragment.empty()) fragment = POKO_TEXTURED_FRAGMENT_SPV;
  }
  if (vertex.empty() || fragment.empty()) {
    std::fputs("Both --vertex and --fragment SPIR-V paths are required.\n", stderr);
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
  rhi::VulkanDiagnostics diagnostics;
  rhi::VulkanClearRenderer renderer;
  std::uint32_t submitted = 0;
  int code = 0;
  try {
    // This scope releases the pipeline before the renderer and window.
    const auto mode = !texture_path.empty() ? rhi::TriangleMode::textured
        : uniform_demo ? rhi::TriangleMode::uniform_depth : !depth_demo ? rhi::TriangleMode::color :
        disable_depth ? rhi::TriangleMode::depth_disabled_control : rhi::TriangleMode::depth_test;
    std::unique_ptr<resource::Ktx2Image> ktx2;
    if (!texture_path.empty()) {
      std::string ktx_error;
      ktx2 = resource::load_ktx2(texture_path, &ktx_error);
      if (!ktx2) {
        std::fprintf(stderr, "KTX2 load failed: %s\n", ktx_error.c_str());
        return 2;
      }
    }
    rhi::VulkanTrianglePass triangle{vertex, fragment, diagnostics, mode};
    if (ktx2 && !ktx2->mips.empty()) {
      std::vector<rhi::VulkanTrianglePass::TextureMip> mips;
      mips.reserve(ktx2->mips.size());
      for (const auto& mip : ktx2->mips)
        mips.push_back({mip.pixels.data(), mip.width, mip.height});
      const auto fmt = ktx2->format;
      triangle.set_texture_mips(mips.data(), mips.size(),
                                fmt == resource::Ktx2Format::bgra8_unorm ||
                                fmt == resource::Ktx2Format::bgra8_srgb,
                                fmt == resource::Ktx2Format::rgba8_srgb ||
                                fmt == resource::Ktx2Format::bgra8_srgb);
    }
    if (window.initialize() != platform::PlatformError::none ||
        window.create_window({uniform_demo ? "PokoX - Vulkan uniform" : depth_demo ? "PokoX - Vulkan depth" : "PokoX - Vulkan triangle",
                              settings.window_width, settings.window_height,
                              platform::WindowGraphicsApi::vulkan}) != platform::PlatformError::none) {
      std::fprintf(stderr, "SDL setup failed: %s\n", SDL_GetError()); return 1;
    }
    if (diagnostics.start() != rhi::DiagnosticsError::none) {
      std::fputs("Could not acquire graphics diagnostics.\n", stderr); return 1;
    }
    config.defer_failed_cleanup = true;
    const auto initial = renderer.initialize(window, config);
    if (initial != rhi::RenderError::none || diagnostics.messages().errors) {
      std::fprintf(stderr, "Vulkan setup failed (stage %u).\n", static_cast<unsigned>(initial)); return 1;
    }
    render::FrameGraph graph;
    rhi::RenderError frame_result = rhi::RenderError::not_initialized;
    const auto start = std::chrono::steady_clock::now();
    const auto added = graph.add_pass({uniform_demo ? "forward uniform" : depth_demo ? "forward depth" : "forward triangle", {},
        depth_demo ? std::vector<std::string>{"swapchain color", "depth"} : std::vector<std::string>{"swapchain color"}, {},
        [&] {
          if constexpr (uniform_demo) {
            const auto seconds = std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
            const auto phase = static_cast<float>(std::fmod(seconds, 4.0) / 4.0);
            const float blend = phase < 0.5f ? phase * 2.f : (1.f - phase) * 2.f;
            frame_result = triangle.draw_and_present(renderer, {1.f - blend, 0.1f, blend, 1.f});
          } else frame_result = triangle.draw_and_present(renderer);
        }});
    if (added != render::FrameGraphError::none || graph.compile().error != render::FrameGraphError::none) {
      std::fputs("Could not compile triangle frame graph.\n", stderr); return 1;
    }
    if (uniform_demo) std::puts("Vulkan uniform: near triangle changes from red to blue. Close to exit.");
    else if (depth_demo) std::printf("Vulkan depth: near red, far green; depth test %s. Close to exit.\n", disable_depth ? "OFF (control)" : "ON");
    else std::puts("Vulkan triangle: RGB triangle on a blue background. Close to exit.");
    bool running = true;
    while (running) {
      const auto tick = std::chrono::steady_clock::now();
      platform::Event event;
      while (window.poll_event(event)) {
        if (event.type == platform::EventType::quit_requested ||
            event.type == platform::EventType::window_close_requested) running = false;
      }
      if (!running) break;
      if (diagnostics.messages().errors) { code = 1; break; }
      const auto executed = graph.execute();
      if (executed.error != render::FrameGraphError::none || executed.completed != 1 ||
          diagnostics.messages().errors) { code = 1; break; }
      if (frame_result == rhi::RenderError::not_drawable) { SDL_Delay(20); continue; }
      if (frame_result == rhi::RenderError::resize_attempted) continue;
      if (frame_result != rhi::RenderError::none) {
        std::fprintf(stderr, "Triangle draw failed (stage %u).\n", static_cast<unsigned>(frame_result)); code = 1; break;
      }
      if (submitted != UINT32_MAX) ++submitted;
      if (limit && submitted >= limit) break;
      // Pace to ~60 fps: unthrottled submission can outrun swapchain semaphore
      // reuse on some drivers (VUID-vkAcquireNextImageKHR-semaphore-01779).
      const auto spent = std::chrono::steady_clock::now() - tick;
      constexpr auto budget = std::chrono::milliseconds(16);
      if (spent < budget)
        SDL_Delay(static_cast<std::uint32_t>(
            std::chrono::duration_cast<std::chrono::milliseconds>(budget - spent).count()));
    }
  } catch (const std::exception& error) {
    std::fprintf(stderr, "Triangle setup failed: %s\n", error.what()); code = 1;
  } catch (...) {
    std::fputs("Triangle setup failed with an unknown error.\n", stderr); code = 1;
  }
  if (!renderer.shutdown_checked()) { std::fputs("Vulkan cleanup failed.\n", stderr); code = 1; }
  diagnostics.stop(); window.shutdown();
  const auto messages = diagnostics.messages();
  if (messages.errors) code = 1;
  if (!code && limit && submitted < limit) code = 2;
  std::printf("%s submitted=%u validation_requested=%s graphics_errors=%llu graphics_warnings=%llu\n",
    uniform_demo ? "POKO_UNIFORM_RESULT" : depth_demo ? "POKO_DEPTH_RESULT" : "POKO_TRIANGLE_RESULT", submitted, config.enable_validation ? "true" : "false", static_cast<unsigned long long>(messages.errors),
    static_cast<unsigned long long>(messages.warnings));
  return code;
}
