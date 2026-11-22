// ENG-19/21/22: indexed cube, adjustable light and fixed golden view.
// Default geometry is a builtin 24-vertex cube; --mesh file.pmes loads a
// hand-written PMES binary instead (positions + normals + u32 indices).
#include "poko/platform/window/sdl_platform.hpp"
#include "poko/render/framegraph/frame_graph.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_mesh_pass.hpp"
#include "poko/rhi/directional_light.hpp"
#include "poko/foundation/config.hpp"
#include "poko/foundation/config_logging.hpp"
#include "poko/resource/pokomesh.hpp"
#include "poko/render/camera.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <algorithm>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <exception>
#include <memory>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

#ifndef POKO_MESH_VERTEX_SPV
#define POKO_MESH_VERTEX_SPV ""
#endif
#ifndef POKO_MESH_FRAGMENT_SPV
#define POKO_MESH_FRAGMENT_SPV ""
#endif

namespace {
// 24 vertices / 36 indices, per-face normals, CCW front faces, NDC space.
std::vector<poko::rhi::MeshVertex> cube_vertices() {
  using V = poko::rhi::MeshVertex;
  constexpr float h = 0.9f;
  std::vector<V> out;
  out.reserve(24);
  // Each face authored CCW when viewed from outside; per-face normals give
  // flat shading so the cube's orientation reads clearly.
  struct Face { float n[3]; float v[4][3]; };
  const Face fs[6] = {
      {{0,0,1},  {{-h,-h,h},{h,-h,h},{h,h,h},{-h,h,h}}},
      {{0,0,-1}, {{h,-h,-h},{-h,-h,-h},{-h,h,-h},{h,h,-h}}},
      {{0,1,0},  {{-h,h,h},{h,h,h},{h,h,-h},{-h,h,-h}}},
      {{0,-1,0}, {{-h,-h,-h},{h,-h,-h},{h,-h,h},{-h,-h,h}}},
      {{1,0,0},  {{h,-h,h},{h,-h,-h},{h,h,-h},{h,h,h}}},
      {{-1,0,0}, {{-h,-h,-h},{-h,-h,h},{-h,h,h},{-h,h,-h}}}};
  for (const auto& f : fs)
    for (int i = 0; i < 4; ++i) {
      V v{};
      for (int k = 0; k < 3; ++k) { v.position[k] = f.v[i][k]; v.normal[k] = f.n[k]; }
      out.push_back(v);
    }
  return out;
}
std::vector<std::uint32_t> cube_indices() {
  std::vector<std::uint32_t> idx;
  idx.reserve(36);
  for (std::uint32_t f = 0; f < 6; ++f)
    for (std::uint32_t i : {0u, 1u, 2u, 0u, 2u, 3u})
      idx.push_back(f * 4 + i);
  return idx;
}
}  // namespace

int main(int argc, char** argv) {
  using namespace poko;
  std::string vertex, fragment, config_path, mesh_path;
  std::uint32_t limit = 0;
  bool golden_view = false;
  rhi::ClearConfig config{};
  rhi::DirectionalLight light;
  config::Overrides overrides;
  config.enable_depth = true;
  for (int i = 1; i < argc; ++i) {
    const std::string_view arg{argv[i]};
    if (arg == "--golden-view") { golden_view = true; continue; }
    if (arg == "--light" && i + 3 < argc) {
      float value[3]{};
      bool valid = true;
      for (auto& component : value) {
        const std::string_view text{argv[++i]};
        const auto result = std::from_chars(text.data(), text.data() + text.size(), component);
        valid = valid && result.ec == std::errc{} && result.ptr == text.data() + text.size();
      }
      if (valid && light.set_direction(value[0], value[1], value[2])) continue;
      std::fputs("--light requires three finite components and a nonzero direction.\n", stderr);
      return 2;
    }
    if (arg == "--no-validation") { overrides.validation = false; overrides.validation_set = true; continue; }
    if (arg == "--adapter" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), overrides.adapter_id);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size()) { overrides.adapter_set = true; continue; }
    }
    if (arg == "--config" && i + 1 < argc) { config_path = argv[++i]; continue; }
    if (arg == "--vertex" && i + 1 < argc) { vertex = argv[++i]; continue; }
    if (arg == "--fragment" && i + 1 < argc) { fragment = argv[++i]; continue; }
    if (arg == "--mesh" && i + 1 < argc) { mesh_path = argv[++i]; continue; }
    if (arg == "--frames" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), limit);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() && limit) continue;
    }
    std::fprintf(stderr, "Usage: pokox_cube --vertex file.spv --fragment file.spv [--mesh file.pmes] [--frames positive-integer] [--adapter index] [--no-validation] [--config file.cbor] [--light x y z] [--golden-view]\n");
    return 2;
  }
  if (vertex.empty()) vertex = POKO_MESH_VERTEX_SPV;
  if (fragment.empty()) fragment = POKO_MESH_FRAGMENT_SPV;
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
    rhi::VulkanMeshPass cube{vertex, fragment, diagnostics};
    const auto& initial_light = light.data();
    if (!cube.set_light_direction(initial_light[0], initial_light[1], initial_light[2])) return 2;
    if (!mesh_path.empty()) {
      std::string mesh_error;
      auto mesh = resource::load_pokomesh(mesh_path, &mesh_error);
      if (!mesh) {
        std::fprintf(stderr, "PMES load failed: %s\n", mesh_error.c_str());
        return 2;
      }
      std::vector<rhi::MeshVertex> verts(mesh->vertices.size());
      for (std::size_t i = 0; i < mesh->vertices.size(); ++i)
        std::memcpy(verts[i].position, mesh->vertices[i].position, sizeof(verts[i].position)),
        std::memcpy(verts[i].normal, mesh->vertices[i].normal, sizeof(verts[i].normal));
      cube.set_mesh(verts.data(), verts.size(), mesh->indices.data(), mesh->indices.size());
      std::printf("Loaded PMES mesh: %zu vertices, %zu indices.\n",
                  verts.size(), mesh->indices.size());
    } else {
      auto verts = cube_vertices();
      auto idx = cube_indices();
      cube.set_mesh(verts.data(), verts.size(), idx.data(), idx.size());
    }
    if (window.initialize() != platform::PlatformError::none ||
        window.create_window({"PokoX - Vulkan mesh cube", settings.window_width, settings.window_height,
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
    render::OrbitCamera camera;
    if (golden_view) camera.zoom(-6.f);  // deterministic full-cube composition
    camera.set_viewport(settings.window_width, settings.window_height);
    platform::WindowSize actual_size{};
    if (window.get_window_size(actual_size) == platform::PlatformError::none)
      camera.set_viewport(actual_size.pixel_width, actual_size.pixel_height);
    const auto added = graph.add_pass({"forward mesh", {},
        {"swapchain color", "depth"}, {},
        [&] {
          const auto mvp = camera.view_proj();
          cube.set_view_proj(mvp.data());
          frame_result = cube.draw_and_present(renderer);
        }});
    if (added != render::FrameGraphError::none || graph.compile().error != render::FrameGraphError::none) {
      std::fputs("Could not compile mesh frame graph.\n", stderr); return 1;
    }
    std::puts(golden_view ? "Vulkan mesh: fixed golden view. Close to exit." :
              "Vulkan mesh: left-drag orbits; arrow keys rotate the world-space light. Close to exit.");
    auto previous = std::chrono::steady_clock::now();
    bool running = true;
    while (running) {
      const auto tick = std::chrono::steady_clock::now();
      platform::Event event;
      while (window.poll_event(event)) {
        if (event.type == platform::EventType::quit_requested ||
            event.type == platform::EventType::window_close_requested) running = false;
        // ENG-20: left-drag orbits, wheel dollies. Motion arrives only while
        // the left button is held (platform gates on SDL_BUTTON_LMASK).
        if (event.type == platform::EventType::window_resized)
          camera.set_viewport(event.size.pixel_width, event.size.pixel_height);
        if (!golden_view && event.type == platform::EventType::mouse_motion)
          camera.orbit(event.dx * 0.01f, -event.dy * 0.01f);
        if (!golden_view && event.type == platform::EventType::mouse_wheel)
          camera.zoom(event.wheel);
      }
      if (!running) break;
      const float elapsed = std::min(0.1f, std::chrono::duration<float>(tick - previous).count());
      previous = tick;
      const bool* keys = SDL_GetKeyboardState(nullptr);
      const int turn = static_cast<int>(keys[SDL_SCANCODE_RIGHT]) - static_cast<int>(keys[SDL_SCANCODE_LEFT]);
      if (!golden_view && turn != 0) {
        const auto direction = light.data();
        const float angle = static_cast<float>(turn) * elapsed * 1.5f;
        const float x = direction[0] * std::cos(angle) + direction[2] * std::sin(angle);
        const float z = -direction[0] * std::sin(angle) + direction[2] * std::cos(angle);
        if (!light.set_direction(x, direction[1], z) || !cube.set_light_direction(x, direction[1], z)) {
          std::fputs("Invalid light direction.\n", stderr); code = 1; break;
        }
      }
      if (diagnostics.messages().errors) { code = 1; break; }
      const auto executed = graph.execute();
      if (executed.error != render::FrameGraphError::none || executed.completed != 1 ||
          diagnostics.messages().errors) { code = 1; break; }
      if (frame_result == rhi::RenderError::not_drawable) { SDL_Delay(20); continue; }
      if (frame_result == rhi::RenderError::resize_attempted) continue;
      if (frame_result != rhi::RenderError::none) {
        std::fprintf(stderr, "Mesh draw failed (stage %u).\n", static_cast<unsigned>(frame_result)); code = 1; break;
      }
      if (submitted != UINT32_MAX) ++submitted;
      if (limit && submitted >= limit) break;
      const auto spent = std::chrono::steady_clock::now() - tick;
      constexpr auto budget = std::chrono::milliseconds(16);
      if (spent < budget)
        SDL_Delay(static_cast<std::uint32_t>(
            std::chrono::duration_cast<std::chrono::milliseconds>(budget - spent).count()));
    }
  } catch (const std::exception& error) {
    std::fprintf(stderr, "Mesh setup failed: %s\n", error.what()); code = 1;
  } catch (...) {
    std::fputs("Mesh setup failed with an unknown error.\n", stderr); code = 1;
  }
  if (!renderer.shutdown_checked()) { std::fputs("Vulkan cleanup failed.\n", stderr); code = 1; }
  diagnostics.stop(); window.shutdown();
  const auto messages = diagnostics.messages();
  if (messages.errors) code = 1;
  if (!code && limit && submitted < limit) code = 2;
  std::printf("POKO_CUBE_RESULT submitted=%u validation_requested=%s graphics_errors=%llu graphics_warnings=%llu\n",
    submitted, config.enable_validation ? "true" : "false",
    static_cast<unsigned long long>(messages.errors),
    static_cast<unsigned long long>(messages.warnings));
  return code;
}
