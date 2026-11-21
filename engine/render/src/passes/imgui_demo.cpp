#include "poko/platform/window/sdl_platform.hpp"
#include "poko/render/framegraph/frame_graph.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_imgui_pass.hpp"
#include "poko/rhi/device/vulkan_triangle_pass.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#if POKO_DEBUG
#include <imgui.h>
#endif
#include <cfloat>
#include <charconv>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <exception>
#include <string>
#include <string_view>
#include <system_error>

namespace {
struct Frame {
  poko::rhi::VulkanTrianglePass* scene;
  poko::rhi::VulkanImGuiPass* ui = nullptr;
  poko::rhi::RenderError result = poko::rhi::RenderError::not_initialized;
};
poko::rhi::RenderError composite(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target, void* user) {
  auto& frame = *static_cast<Frame*>(user);
  const auto scene = frame.scene->draw(device, context, chain, target);
  if (scene != poko::rhi::RenderError::none) return scene;
#if POKO_DEBUG
  if (frame.ui) {
    frame.result = frame.ui->draw(device, context, chain, target);
    return frame.result;
  }
#endif
  frame.result = scene;
  return frame.result;
}
#if POKO_DEBUG
void update_imgui_io(poko::platform::SdlPlatform& window,
                     std::chrono::steady_clock::time_point& previous) {
  auto& io = ImGui::GetIO();
  poko::platform::WindowSize size{};
  if (window.get_window_size(size) == poko::platform::PlatformError::none &&
      size.logical_width && size.logical_height) {
    io.DisplaySize = ImVec2(static_cast<float>(size.logical_width),
                            static_cast<float>(size.logical_height));
    if (size.logical_width && size.pixel_width && size.logical_height && size.pixel_height)
      io.DisplayFramebufferScale = ImVec2(static_cast<float>(size.pixel_width) / size.logical_width,
                                          static_cast<float>(size.pixel_height) / size.logical_height);
  }
  const auto now = std::chrono::steady_clock::now();
  io.DeltaTime = std::chrono::duration<float>(now - previous).count();
  previous = now;
  float mx = 0.f, my = 0.f;
  SDL_Window* mouse_focus = SDL_GetMouseFocus();
  if (mouse_focus != window.native_window()) {
    io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
    for (auto& down : io.MouseDown) down = false;
  } else {
    const auto buttons = SDL_GetMouseState(&mx, &my);
    io.MousePos = ImVec2(mx, my);
    // SDL3 button constants are indices; the state bitmask uses *_MASK bits.
    io.MouseDown[0] = (buttons & SDL_BUTTON_LMASK) != 0;
    io.MouseDown[1] = (buttons & SDL_BUTTON_RMASK) != 0;
    io.MouseDown[2] = (buttons & SDL_BUTTON_MMASK) != 0;
    io.MouseDown[3] = (buttons & SDL_BUTTON_X1MASK) != 0;
    io.MouseDown[4] = (buttons & SDL_BUTTON_X2MASK) != 0;
  }
}
void build_demo_window() {
  ImGui::SetNextWindowPos(ImVec2(10.f, 10.f), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowSize(ImVec2(320.f, 0.f), ImGuiCond_FirstUseEver);
  if (ImGui::Begin("PokoX ImGui demo")) {
    ImGui::Text("Vulkan triangle + ImGui pass (ENG-11/12 prototype)");
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::Separator();
    static bool show_stats = true;
    ImGui::Checkbox("Show stats", &show_stats);
    if (show_stats) ImGui::Text("F1 toggles this UI. Drag the window; close the app to exit.");
  }
  ImGui::End();
}
// RAII guard so every exit path (including early error returns) destroys the
// ImGui context exactly once.
struct ImGuiContextGuard {
  ImGuiContextGuard() { ImGui::CreateContext(); }
  ~ImGuiContextGuard() { ImGui::DestroyContext(); }
};
#endif
}  // namespace

int main(int argc, char** argv) {
  using namespace poko;
  std::string vertex, fragment, imgui_vertex, imgui_fragment;
  std::uint32_t limit = 0;
  rhi::ClearConfig config{};
  for (int i = 1; i < argc; ++i) {
    const std::string_view arg{argv[i]};
    if (arg == "--no-validation") { config.enable_validation = false; continue; }
    if (arg == "--adapter" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), config.adapter_id);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size()) continue;
    }
    if (arg == "--vertex" && i + 1 < argc) { vertex = argv[++i]; continue; }
    if (arg == "--fragment" && i + 1 < argc) { fragment = argv[++i]; continue; }
    if (arg == "--imgui-vertex" && i + 1 < argc) { imgui_vertex = argv[++i]; continue; }
    if (arg == "--imgui-fragment" && i + 1 < argc) { imgui_fragment = argv[++i]; continue; }
    if (arg == "--frames" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), limit);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() && limit) continue;
    }
    std::fprintf(stderr, "Usage: %s --vertex file.spv --fragment file.spv%s [--frames positive-integer] [--adapter index] [--no-validation]\n",
                 "pokox_imgui_demo",
#if POKO_DEBUG
                 " --imgui-vertex file.spv --imgui-fragment file.spv"
#else
                 ""
#endif
    );
    return 2;
  }
  if (vertex.empty() || fragment.empty()
#if POKO_DEBUG
      || imgui_vertex.empty() || imgui_fragment.empty()
#endif
  ) {
    std::fputs("Scene --vertex/--fragment SPIR-V paths are required"
#if POKO_DEBUG
               " (plus --imgui-vertex/--imgui-fragment in debug builds)"
#endif
               ".\n",
               stderr);
    return 2;
  }
#if POKO_DEBUG
  ImGuiContextGuard imgui_context;
  ImGui::GetIO().Fonts->AddFontDefault();
  // Build the atlas before the first NewFrame; the Vulkan pass uploads the
  // same cached pixels when it creates the font texture.
  {
    unsigned char* pixels = nullptr;
    int width = 0, height = 0;
    ImGui::GetIO().Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    if (!pixels || width <= 0 || height <= 0) {
      std::fputs("Could not build the ImGui font atlas.\n", stderr);
      return 1;
    }
  }
#endif
  platform::SdlPlatform window;
  rhi::VulkanDiagnostics diagnostics;
  rhi::VulkanClearRenderer renderer;
  std::uint32_t submitted = 0;
  int code = 0;
  try {
    // This scope releases the passes before the renderer and window.
    rhi::VulkanTrianglePass triangle{vertex, fragment, diagnostics, rhi::TriangleMode::color};
#if POKO_DEBUG
    rhi::VulkanImGuiPass imgui{imgui_vertex, imgui_fragment, diagnostics};
#endif
    if (window.initialize() != platform::PlatformError::none ||
        window.create_window({"PokoX - Vulkan ImGui", 800, 600,
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
    Frame frame{&triangle};
#if POKO_DEBUG
    frame.ui = &imgui;
#endif
#if POKO_DEBUG
    bool ui_enabled = true;
    bool f1_was_down = false;
    auto io_previous = std::chrono::steady_clock::now();
    // The CPU pass records the ImGui frame (F1 toggles the demo window);
    // the GPU pass composites scene and UI into one presented frame.
    const auto ui_added = graph.add_pass({"ui imgui", {}, {"imgui draw data"}, {},
        [&] {
          int numkeys = 0;
          const bool* keys = SDL_GetKeyboardState(&numkeys);
          const bool focused = SDL_GetKeyboardFocus() == window.native_window();
          const bool f1 = focused && numkeys > SDL_SCANCODE_F1 && keys[SDL_SCANCODE_F1];
          if (f1 && !f1_was_down) {
            ui_enabled = !ui_enabled;
            std::puts(ui_enabled ? "ImGui UI shown (F1)." : "ImGui UI hidden (F1).");
          }
          f1_was_down = f1;
          update_imgui_io(window, io_previous);
          ImGui::NewFrame();
          if (ui_enabled) build_demo_window();
          ImGui::Render();
        }});
#endif
    const auto frame_added = graph.add_pass({"forward frame",
#if POKO_DEBUG
        {"imgui draw data"},
#else
        {},
#endif
        {"swapchain color"}, {},
        [&] {
          frame.result = rhi::RenderError::not_initialized;
          frame_result = renderer.draw_and_present(composite, &frame);
        }});
    if (frame_added != render::FrameGraphError::none
#if POKO_DEBUG
        || ui_added != render::FrameGraphError::none ||
        graph.compile().order != std::vector<std::string>{"ui imgui", "forward frame"}
#else
        || graph.compile().order != std::vector<std::string>{"forward frame"}
#endif
    ) {
      std::fputs("Could not compile ImGui frame graph.\n", stderr); return 1;
    }
#if POKO_DEBUG
    std::puts("Vulkan ImGui: triangle scene plus a draggable demo window. F1 toggles UI. Close to exit.");
#else
    std::puts("Vulkan demo (release strip): triangle scene only, no ImGui. Close to exit.");
#endif
    bool running = true;
    const std::size_t expected_passes =
#if POKO_DEBUG
        2;
#else
        1;
#endif
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
      if (executed.error != render::FrameGraphError::none || executed.completed != expected_passes ||
          diagnostics.messages().errors) { code = 1; break; }
      if (frame_result == rhi::RenderError::not_drawable) { SDL_Delay(20); continue; }
      if (frame_result == rhi::RenderError::resize_attempted) continue;
      if (frame_result != rhi::RenderError::none) {
        std::fprintf(stderr, "ImGui frame failed (stage %u).\n", static_cast<unsigned>(frame_result)); code = 1; break;
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
    std::fprintf(stderr, "ImGui demo setup failed: %s\n", error.what()); code = 1;
  } catch (...) {
    std::fputs("ImGui demo setup failed with an unknown error.\n", stderr); code = 1;
  }
  if (!renderer.shutdown_checked()) { std::fputs("Vulkan cleanup failed.\n", stderr); code = 1; }
  diagnostics.stop(); window.shutdown();
  const auto messages = diagnostics.messages();
  if (messages.errors) code = 1;
  if (!code && limit && submitted < limit) code = 2;
  std::printf("POKO_IMGUI_RESULT submitted=%u validation_requested=%s graphics_errors=%llu graphics_warnings=%llu\n",
    submitted, config.enable_validation ? "true" : "false",
    static_cast<unsigned long long>(messages.errors),
    static_cast<unsigned long long>(messages.warnings));
  return code;
}
