#include "poko/platform/window/sdl_platform.hpp"
#include "poko/render/framegraph/frame_graph.hpp"
#include "poko/rhi/debug/vulkan_diagnostics.hpp"
#include "poko/rhi/device/vulkan_clear_renderer.hpp"
#include "poko/rhi/device/vulkan_imgui_pass.hpp"
#include "poko/rhi/device/vulkan_triangle_pass.hpp"
#include "poko/foundation/config.hpp"
#include "poko/foundation/config_logging.hpp"
#include "poko/foundation/frame_stats.hpp"
#include "poko/foundation/duration_query_state.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <DeviceContext.h>
#include <Query.h>
#include <RefCntAutoPtr.hpp>
#include <RenderDevice.h>
#if POKO_DEBUG
#include <imgui.h>
#include "poko/mute/console.hpp"
#include <array>
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
  poko::rhi::VulkanTrianglePass* scene = nullptr;
  poko::rhi::VulkanImGuiPass* ui = nullptr;
  poko::rhi::RenderError result = poko::rhi::RenderError::not_initialized;
  // ENG-15 GPU frame timer: 0 = unchecked, 1 = unsupported, 2 = armed query.
  Diligent::RefCntAutoPtr<Diligent::IQuery> gpu_timer;
  int gpu_timer_state = 0;
  poko::stats::DurationQueryState query_state;
};
// Lazily creates the duration query once per device; unsupported devices keep
// state 1 so gpu_ms() simply stays at zero.
void ensure_gpu_timer(Diligent::IRenderDevice& device, Frame& frame) {
  if (frame.gpu_timer_state) return;
  frame.gpu_timer_state = 1;
  if (device.GetDeviceInfo().Features.DurationQueries != Diligent::DEVICE_FEATURE_STATE_ENABLED)
    return;
  Diligent::QueryDesc desc;
  desc.Type = Diligent::QUERY_TYPE_DURATION;
  Diligent::IQuery* query = nullptr;
  try {
    device.CreateQuery(desc, &query);
  } catch (...) { query = nullptr; }
  if (query) {
    frame.gpu_timer = query;
    query->Release();
    frame.gpu_timer_state = 2;
  }
}
poko::rhi::RenderError composite(Diligent::IRenderDevice& device, Diligent::IDeviceContext& context,
                                 Diligent::ISwapChain& chain, Diligent::ITextureView& target, void* user) {
  auto& frame = *static_cast<Frame*>(user);
  ensure_gpu_timer(device, frame);
  const bool timing = frame.gpu_timer_state == 2 &&
      frame.query_state.begin([&] { context.BeginQuery(frame.gpu_timer); });
  const auto scene = frame.scene->draw(device, context, chain, target);
  poko::rhi::RenderError out = scene;
#if POKO_DEBUG
  if (scene == poko::rhi::RenderError::none && frame.ui) {
    out = frame.ui->draw(device, context, chain, target);
    frame.result = out;
  } else
#endif
  {
    frame.result = scene;
  }
  if (timing) frame.query_state.end([&] { context.EndQuery(frame.gpu_timer); });
  return out;
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
ImGuiKey imgui_key(SDL_Scancode code) {
  if (code >= SDL_SCANCODE_A && code <= SDL_SCANCODE_Z)
    return static_cast<ImGuiKey>(ImGuiKey_A + (code - SDL_SCANCODE_A));
  if (code >= SDL_SCANCODE_1 && code <= SDL_SCANCODE_9)
    return static_cast<ImGuiKey>(ImGuiKey_1 + (code - SDL_SCANCODE_1));
  switch (code) {
    case SDL_SCANCODE_0: return ImGuiKey_0;
    case SDL_SCANCODE_RETURN: return ImGuiKey_Enter;
    case SDL_SCANCODE_KP_ENTER: return ImGuiKey_KeypadEnter;
    case SDL_SCANCODE_ESCAPE: return ImGuiKey_Escape;
    case SDL_SCANCODE_BACKSPACE: return ImGuiKey_Backspace;
    case SDL_SCANCODE_DELETE: return ImGuiKey_Delete;
    case SDL_SCANCODE_TAB: return ImGuiKey_Tab;
    case SDL_SCANCODE_LEFT: return ImGuiKey_LeftArrow;
    case SDL_SCANCODE_RIGHT: return ImGuiKey_RightArrow;
    case SDL_SCANCODE_UP: return ImGuiKey_UpArrow;
    case SDL_SCANCODE_DOWN: return ImGuiKey_DownArrow;
    case SDL_SCANCODE_HOME: return ImGuiKey_Home;
    case SDL_SCANCODE_END: return ImGuiKey_End;
    case SDL_SCANCODE_PAGEUP: return ImGuiKey_PageUp;
    case SDL_SCANCODE_PAGEDOWN: return ImGuiKey_PageDown;
    default: return ImGuiKey_None;
  }
}
void feed_imgui_event(const SDL_Event& event, void* user) noexcept {
  const auto id = SDL_GetWindowID(static_cast<SDL_Window*>(user));
  auto& io = ImGui::GetIO();
  if (event.type == SDL_EVENT_TEXT_INPUT && event.text.windowID == id && event.text.text)
    io.AddInputCharactersUTF8(event.text.text);
  else if ((event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_KEY_UP) && event.key.windowID == id) {
    const auto mods = event.key.mod;
    io.AddKeyEvent(ImGuiMod_Ctrl, (mods & SDL_KMOD_CTRL) != 0);
    io.AddKeyEvent(ImGuiMod_Shift, (mods & SDL_KMOD_SHIFT) != 0);
    io.AddKeyEvent(ImGuiMod_Alt, (mods & SDL_KMOD_ALT) != 0);
    io.AddKeyEvent(ImGuiMod_Super, (mods & SDL_KMOD_GUI) != 0);
    const auto key=imgui_key(event.key.scancode);
    if (key != ImGuiKey_None) io.AddKeyEvent(key, event.type == SDL_EVENT_KEY_DOWN);
  } else if ((event.type == SDL_EVENT_WINDOW_FOCUS_GAINED || event.type == SDL_EVENT_WINDOW_FOCUS_LOST) && event.window.windowID == id)
    io.AddFocusEvent(event.type == SDL_EVENT_WINDOW_FOCUS_GAINED);
  else if (event.type == SDL_EVENT_MOUSE_WHEEL && event.wheel.windowID == id)
    io.AddMouseWheelEvent(event.wheel.x, event.wheel.y);
}
struct Console {
  std::array<char,4096> input{};
  std::string output = "Enter an arithmetic expression or print(...).";
  poko::mute::ConsoleLog log;
  poko::mute::ProgramState state;
  bool scroll_to_end = false;
};
bool print_to_console(std::string_view text, void* user) {
  auto& console=*static_cast<Console*>(user);
  if (!console.log.append(text)) return false;
  console.scroll_to_end = true;
  return true;
}
void build_demo_window(const poko::stats::FrameStats& stats, Console& console) {
  ImGui::SetNextWindowPos(ImVec2(10.f, 10.f), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowSize(ImVec2(320.f, 0.f), ImGuiCond_FirstUseEver);
  if (ImGui::Begin("PokoX ImGui demo")) {
    ImGui::Text("Vulkan triangle + ImGui pass (ENG-11/12 prototype)");
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::Text("CPU: %.2f ms", stats.cpu_ms());
    if (stats.has_gpu_sample()) ImGui::Text("GPU: %.2f ms", stats.gpu_ms());
    else ImGui::TextUnformatted("GPU: unavailable");
    ImGui::Separator();
    static bool show_stats = true;
    ImGui::Checkbox("Show stats", &show_stats);
    if (show_stats) ImGui::TextWrapped("F1 toggles this UI. Drag the window; close the app to exit.");
    ImGui::Separator();
    ImGui::TextUnformatted("Mute console");
    ImGui::SameLine();
    if (ImGui::SmallButton("Reset state")) console.state = {};
    ImGui::SetNextItemWidth(-1.f);
    if (ImGui::InputText("##expression", console.input.data(), console.input.size(), ImGuiInputTextFlags_EnterReturnsTrue)) {
      if (poko::mute::console_input_full(console.input)) {
        // A full buffer may have silently rejected later input or paste bytes.
        // Do not execute a potentially truncated expression.
        console.output = "Input limit reached; shorten the expression.";
      } else {
        console.output = poko::mute::execute_console_stateful(console.input.data(), console.state, {print_to_console, &console});
        console.input.fill('\0');
      }
      ImGui::SetKeyboardFocusHere(-1);
    }
    ImGui::TextWrapped("%s",console.output.c_str());
    if (console.state.initialized) {
      const auto hash=poko::mute::hash_state(console.state);
      if (const auto* value=std::get_if<std::uint64_t>(&hash)) ImGui::Text("State hash: %016llx",static_cast<unsigned long long>(*value));
    }
    ImGui::Separator();
    ImGui::TextUnformatted("Print log");
    ImGui::SameLine();
    if (ImGui::SmallButton("Clear")) console.log.clear();
    if (ImGui::BeginChild("##print_log", ImVec2(0.f,90.f), ImGuiChildFlags_Borders,
                          ImGuiWindowFlags_HorizontalScrollbar)) {
      for (const auto& line:console.log.entries())
        ImGui::TextUnformatted(line.data(),line.data()+line.size());
      if (console.scroll_to_end) ImGui::SetScrollHereY(1.f);
      console.scroll_to_end = false;
    }
    ImGui::EndChild();
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
  std::string vertex, fragment, imgui_vertex, imgui_fragment, config_path;
  std::uint32_t limit = 0;
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
    if (arg == "--vertex" && i + 1 < argc) { vertex = argv[++i]; continue; }
    if (arg == "--fragment" && i + 1 < argc) { fragment = argv[++i]; continue; }
    if (arg == "--imgui-vertex" && i + 1 < argc) { imgui_vertex = argv[++i]; continue; }
    if (arg == "--imgui-fragment" && i + 1 < argc) { imgui_fragment = argv[++i]; continue; }
    if (arg == "--frames" && i + 1 < argc) {
      const std::string_view value{argv[++i]};
      const auto parsed = std::from_chars(value.data(), value.data() + value.size(), limit);
      if (parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() && limit) continue;
    }
    std::fprintf(stderr, "Usage: %s --vertex file.spv --fragment file.spv%s [--frames positive-integer] [--adapter index] [--no-validation] [--config file.cbor]\n",
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
  poko::stats::FrameStats stats;
  try {
    // This scope releases the passes before the renderer and window.
    rhi::VulkanTrianglePass triangle{vertex, fragment, diagnostics, rhi::TriangleMode::color};
#if POKO_DEBUG
    rhi::VulkanImGuiPass imgui{imgui_vertex, imgui_fragment, diagnostics};
#endif
    if (window.initialize() != platform::PlatformError::none ||
        window.create_window({"PokoX - Vulkan ImGui", settings.window_width,
                              settings.window_height,
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
    Frame frame{};
    frame.scene = &triangle;
#if POKO_DEBUG
    frame.ui = &imgui;
#endif
#if POKO_DEBUG
    Console console;
    bool text_input_active = false;
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
          if (ui_enabled) build_demo_window(stats, console);
          ImGui::Render();
          const bool wants_text = ui_enabled && ImGui::GetIO().WantTextInput;
          if (wants_text != text_input_active) {
            const bool ok = wants_text ? SDL_StartTextInput(window.native_window()) : SDL_StopTextInput(window.native_window());
            if (ok) text_input_active = wants_text;
          }
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
      while (window.poll_event(event
#if POKO_DEBUG
                               , feed_imgui_event, window.native_window()
#endif
                               )) {
        if (event.type == platform::EventType::quit_requested ||
            event.type == platform::EventType::window_close_requested) running = false;
      }
      if (!running) break;
      if (diagnostics.messages().errors) { code = 1; break; }
      const auto executed = graph.execute();
      stats.record_cpu(std::chrono::duration<double>(
          std::chrono::steady_clock::now() - tick).count());
      // Poll only submitted queries. Do not reuse one until its result is
      // ready: Diligent discards an outstanding result on BeginQuery.
      if (frame.gpu_timer_state == 2) {
        Diligent::QueryDataDuration data{};
        const bool collected = frame.query_state.poll([&] {
          return frame.gpu_timer->GetData(&data, sizeof(data), true);
        });
        if (collected && data.Frequency)
          stats.record_gpu(static_cast<double>(data.Duration) / data.Frequency);
      }
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
#if POKO_DEBUG
    if (text_input_active) (void)SDL_StopTextInput(window.native_window());
#endif
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
  std::printf("POKO_IMGUI_RESULT submitted=%u validation_requested=%s graphics_errors=%llu graphics_warnings=%llu cpu_ms=%.2f gpu_ms=%.2f gpu_available=%s\n",
    submitted, config.enable_validation ? "true" : "false",
    static_cast<unsigned long long>(messages.errors),
    static_cast<unsigned long long>(messages.warnings),
    stats.cpu_ms(), stats.gpu_ms(), stats.has_gpu_sample() ? "true" : "false");
  return code;
}
