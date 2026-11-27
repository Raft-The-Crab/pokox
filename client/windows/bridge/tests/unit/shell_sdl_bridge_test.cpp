// SHL-09: SDL3 event bridge in engine — SdlPlatform::poll_event forwards
// raw SDL_Event values through sdl_event_observer into PokoShell, and
// poko_shell_frame consumes mouse and keyboard events into egui.
#include "poko/platform/window/sdl_platform.hpp"
#include "poko/shell/sdl_event_bridge.hpp"
#include "poko/shell/unique_shell.hpp"

#include <SDL3/SDL.h>

#include <cstdint>
#include <cstdio>
#include <queue>

namespace {

int failures = 0;

void check(bool ok, const char* what) {
    if (!ok) {
        std::puts(what);
        failures++;
    }
}

struct FakeSdlState {
    std::queue<SDL_Event> events;
    SDL_Window* window = reinterpret_cast<SDL_Window*>(static_cast<uintptr_t>(0x1234));
    SDL_WindowID window_id = 7;
};

FakeSdlState g_sdl;

}  // namespace

// Minimal SDL3 fake implementations for sdl_platform.cpp.
bool SDL_InitSubSystem(SDL_InitFlags) { return true; }
void SDL_QuitSubSystem(SDL_InitFlags) {}
SDL_Window* SDL_CreateWindow(const char*, int, int, SDL_WindowFlags) {
    return g_sdl.window;
}
void SDL_DestroyWindow(SDL_Window*) {}
SDL_WindowID SDL_GetWindowID(SDL_Window*) { return g_sdl.window_id; }
bool SDL_GetWindowSize(SDL_Window*, int* w, int* h) {
    *w = 640;
    *h = 480;
    return true;
}
bool SDL_GetWindowSizeInPixels(SDL_Window*, int* w, int* h) {
    *w = 1280;
    *h = 960;
    return true;
}
bool SDL_PollEvent(SDL_Event* out) {
    if (g_sdl.events.empty()) return false;
    *out = g_sdl.events.front();
    g_sdl.events.pop();
    return true;
}

int main() {
    poko::platform::SdlPlatform platform;
    check(platform.initialize() == poko::platform::PlatformError::none,
          "FAIL: SdlPlatform initialize");
    check(platform.create_window({"SHL-09", 640, 480}) ==
              poko::platform::PlatformError::none,
          "FAIL: SdlPlatform create_window");

    int32_t create_rc = -1;
    auto shell = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &create_rc);
    check(create_rc == POKO_SHELL_OK && static_cast<bool>(shell),
          "FAIL: UniqueShell create");

    // Queue SDL3 mouse, keyboard, focus, and wrong-window events.
    SDL_Event wrong_win{};
    wrong_win.type = SDL_EVENT_MOUSE_MOTION;
    wrong_win.motion.windowID = 999;
    wrong_win.motion.x = 10.0f;
    wrong_win.motion.y = 10.0f;
    g_sdl.events.push(wrong_win);

    SDL_Event motion{};
    motion.type = SDL_EVENT_MOUSE_MOTION;
    motion.motion.windowID = g_sdl.window_id;
    motion.motion.x = 200.0f;
    motion.motion.y = 100.0f;
    g_sdl.events.push(motion);

    SDL_Event btn{};
    btn.type = SDL_EVENT_MOUSE_BUTTON_DOWN;
    btn.button.windowID = g_sdl.window_id;
    btn.button.button = SDL_BUTTON_LEFT;
    btn.button.x = 200.0f;
    btn.button.y = 100.0f;
    g_sdl.events.push(btn);

    SDL_Event key_down{};
    key_down.type = SDL_EVENT_KEY_DOWN;
    key_down.key.windowID = g_sdl.window_id;
    key_down.key.key = 'a';
    key_down.key.mod = SDL_KMOD_LCTRL;
    key_down.key.down = true;
    g_sdl.events.push(key_down);

    SDL_Event focus_ev{};
    focus_ev.type = SDL_EVENT_WINDOW_FOCUS_GAINED;
    focus_ev.window.windowID = g_sdl.window_id;
    g_sdl.events.push(focus_ev);

    SDL_Event quit_ev{};
    quit_ev.type = SDL_EVENT_QUIT;
    g_sdl.events.push(quit_ev);

    poko::shell::SdlEventBridgeContext ctx{};
    ctx.shell = shell.get();
    ctx.window_id = g_sdl.window_id;
    ctx.dpi_scale = 2.0f;  // 200x100 -> 100x50 logical px

    poko::platform::Event ev{};
    bool saw_quit = false;
    while (platform.poll_event(ev, poko::shell::sdl_event_observer, &ctx)) {
        if (ev.type == poko::platform::EventType::quit_requested) {
            saw_quit = true;
        }
    }
    check(saw_quit, "FAIL: platform poll_event must still deliver quit_requested");
    check(ctx.pushed_count == 4,
          "FAIL: expected 4 matching events pushed (motion, button, key, focus)");
    check(ctx.last_error == POKO_SHELL_OK, "FAIL: last_error must be 0");

    // Verify DPI scaling on the queued motion event before running the frame.
    PokoEvent peeked[8]{};
    uint32_t pending = 0;
    check(poko_shell_drain_events(shell.get(), nullptr, 0, &pending) == POKO_SHELL_OK &&
              pending == 4,
          "FAIL: 4 events should be queued");
    check(poko_shell_drain_events(shell.get(), peeked, 4, &pending) == POKO_SHELL_OK &&
              pending == 4,
          "FAIL: drain 4 events");
    check(peeked[0].kind == POKO_EVENT_MOTION && peeked[0].x == 100.0f &&
              peeked[0].y == 50.0f,
          "FAIL: motion coordinates must divide by dpi_scale");
    check(peeked[1].kind == POKO_EVENT_BUTTON && peeked[1].button == 0 &&
              peeked[1].pressed == 1,
          "FAIL: SDL_BUTTON_LEFT must map to button 0 pressed");
    check(peeked[2].kind == POKO_EVENT_KEY && peeked[2].key == 'a' &&
              peeked[2].pressed == 1 &&
              peeked[2].modifiers == poko::shell::kModCtrl,
          "FAIL: SDL_EVENT_KEY_DOWN must map key and Ctrl modifier");
    check(peeked[3].kind == POKO_EVENT_FOCUS && peeked[3].focus == 1,
          "FAIL: focus gained must map to focus=1");

    // Re-push and run poko_shell_frame to confirm egui consumes all 4.
    for (uint32_t i = 0; i < 4; ++i) {
        check(poko_shell_push_event(shell.get(), &peeked[i]) == POKO_SHELL_OK,
              "FAIL: re-push event");
    }
    PokoFrameInfo frame{};
    check(poko_shell_frame(shell.get(), 0.016, 640, 480, &frame) == POKO_SHELL_OK,
          "FAIL: poko_shell_frame");
    check(frame.events_consumed == 4 && frame.shape_count > 0 &&
              frame.label_rendered == 1,
          "FAIL: frame must consume 4 events and render label");

    platform.shutdown();

    if (failures > 0) {
        std::printf("FAIL: %d SDL bridge check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all SHL-09 SDL3 event bridge checks passed");
}
