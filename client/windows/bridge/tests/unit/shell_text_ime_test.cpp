// SHL-10: Text input and IME — SDL_StartTextInput/StopTextInput, CJK UTF-8
// events through sdl_event_observer, and codepoint-safe truncation at
// POKO_SHELL_EVENT_TEXT_MAX.
#include "poko/platform/window/sdl_platform.hpp"
#include "poko/shell/sdl_event_bridge.hpp"
#include "poko/shell/unique_shell.hpp"

#include <SDL3/SDL.h>

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>

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
    SDL_Window* window = reinterpret_cast<SDL_Window*>(static_cast<uintptr_t>(0x5678));
    SDL_WindowID window_id = 11;
    bool text_input_active = false;
};

FakeSdlState g_sdl;

}  // namespace

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
    *w = 640;
    *h = 480;
    return true;
}
bool SDL_StartTextInput(SDL_Window* w) {
    if (!w) return false;
    g_sdl.text_input_active = true;
    return true;
}
bool SDL_StopTextInput(SDL_Window* w) {
    if (!w) return false;
    g_sdl.text_input_active = false;
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
    check(platform.create_window({"SHL-10", 640, 480}) ==
              poko::platform::PlatformError::none,
          "FAIL: SdlPlatform create_window");

    check(poko::shell::start_text_input(platform.native_window()) &&
              g_sdl.text_input_active,
          "FAIL: start_text_input must enable SDL text input");

    int32_t create_rc = -1;
    auto shell = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &create_rc);
    check(create_rc == POKO_SHELL_OK && static_cast<bool>(shell),
          "FAIL: UniqueShell create");

    // 1. CJK UTF-8 text input ("你好世界日本語한국어").
    const char* cjk = "\xE4\xBD\xA0\xE5\xA5\xBD\xE4\xB8\x96\xE7\x95\x8C"
                      "\xE6\x97\xA5\xE6\x9C\xAC\xE8\xAA\x9E"
                      "\xED\x95\x9C\xEA\xB5\xAD\xEC\x96\xB4";
    SDL_Event text_ev{};
    text_ev.type = SDL_EVENT_TEXT_INPUT;
    text_ev.text.windowID = g_sdl.window_id;
    text_ev.text.text = cjk;
    g_sdl.events.push(text_ev);

    // 2. Oversized CJK string (45 * 3 = 135 bytes > 127): must truncate on a
    // clean 3-byte UTF-8 boundary (126 bytes = 42 chars), never mid-codepoint.
    std::string long_cjk;
    for (int i = 0; i < 45; ++i) {
        long_cjk += "\xE4\xB8\xAD";  // '中' (3 bytes)
    }
    SDL_Event long_ev{};
    long_ev.type = SDL_EVENT_TEXT_INPUT;
    long_ev.text.windowID = g_sdl.window_id;
    long_ev.text.text = long_cjk.c_str();
    g_sdl.events.push(long_ev);

    poko::shell::SdlEventBridgeContext ctx{};
    ctx.shell = shell.get();
    ctx.window_id = g_sdl.window_id;
    poko::platform::Event ev{};
    while (platform.poll_event(ev, poko::shell::sdl_event_observer, &ctx)) {}

    check(ctx.pushed_count == 2 && ctx.last_error == POKO_SHELL_OK,
          "FAIL: expected 2 CJK text events pushed");

    PokoEvent drained[2]{};
    uint32_t count = 0;
    check(poko_shell_drain_events(shell.get(), drained, 2, &count) == POKO_SHELL_OK &&
              count == 2,
          "FAIL: drain 2 CJK text events");
    check(drained[0].kind == POKO_EVENT_TEXT &&
              drained[0].text_len == std::strlen(cjk) &&
              std::memcmp(drained[0].text, cjk, drained[0].text_len) == 0,
          "FAIL: CJK UTF-8 bytes must round-trip intact");
    check(drained[1].kind == POKO_EVENT_TEXT && drained[1].text_len == 126,
          "FAIL: oversized CJK string must truncate at UTF-8 codepoint boundary (126)");

    // Re-push and run poko_shell_frame so egui processes the CJK events.
    check(poko_shell_push_event(shell.get(), &drained[0]) == POKO_SHELL_OK,
          "FAIL: re-push CJK event");
    PokoFrameInfo frame{};
    check(poko_shell_frame(shell.get(), 0.016, 640, 480, &frame) == POKO_SHELL_OK,
          "FAIL: frame with CJK text");
    check(frame.events_consumed == 1 && frame.shape_count > 0,
          "FAIL: frame must consume CJK event");

    check(poko::shell::stop_text_input(platform.native_window()) &&
              !g_sdl.text_input_active,
          "FAIL: stop_text_input must disable SDL text input");

    platform.shutdown();

    if (failures > 0) {
        std::printf("FAIL: %d shell text/IME check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all SHL-10 text input and IME checks passed");
}
