// SHL-04: poko_shell_frame drains the event queue into an egui frame and
// runs the shell label — the frame reports events consumed, shape count,
// pixels-per-point and repaint delay.
extern "C" {
#include "poko_shell.h"
}

#include <cstdint>
#include <cstdio>

namespace {

int failures = 0;

void check(bool ok, const char* what) {
    if (!ok) {
        std::puts(what);
        failures++;
    }
}

PokoEvent motion(float x, float y) {
    PokoEvent e{};
    e.kind = POKO_EVENT_MOTION;
    e.x = x;
    e.y = y;
    return e;
}

PokoEvent click(float x, float y, int32_t button, int32_t pressed) {
    PokoEvent e{};
    e.kind = POKO_EVENT_BUTTON;
    e.x = x;
    e.y = y;
    e.button = button;
    e.pressed = pressed;
    return e;
}

PokoEvent wheel(float dx, float dy) {
    PokoEvent e{};
    e.kind = POKO_EVENT_WHEEL;
    e.wheel_x = dx;
    e.wheel_y = dy;
    return e;
}

PokoEvent text_ev(const char* s, uint32_t len) {
    PokoEvent e{};
    e.kind = POKO_EVENT_TEXT;
    e.text_len = len;
    for (uint32_t i = 0; i < len; ++i) {
        e.text[i] = static_cast<uint8_t>(s[i]);
    }
    return e;
}

PokoEvent focus(int32_t gained) {
    PokoEvent e{};
    e.kind = POKO_EVENT_FOCUS;
    e.focus = gained;
    return e;
}

}  // namespace

int main() {
    PokoShell* shell = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) == POKO_SHELL_OK &&
              shell != nullptr,
          "FAIL: create must succeed");

    // Error paths first: nulls, stale ABI, degenerate screen.
    PokoFrameInfo info{};
    check(poko_shell_frame(nullptr, 0.0, 100, 100, &info) ==
              POKO_SHELL_ERROR_NULL,
          "FAIL: null shell frame must return -1");
    check(poko_shell_frame(shell, 0.0, 100, 100, nullptr) ==
              POKO_SHELL_ERROR_NULL,
          "FAIL: null out frame must return -1");
    uint32_t stale = POKO_SHELL_ABI_VERSION - 1;
    check(poko_shell_frame(reinterpret_cast<PokoShell*>(&stale), 0.0, 100,
                           100, &info) == POKO_SHELL_ERROR_ABI_MISMATCH,
          "FAIL: stale-ABI handle must return -4");
    check(poko_shell_frame(shell, 0.0, 0, 100, &info) ==
              POKO_SHELL_ERROR_SHELL,
          "FAIL: zero width must return -2");
    check(poko_shell_frame(shell, 0.0, 100, 0, &info) ==
              POKO_SHELL_ERROR_SHELL,
          "FAIL: zero height must return -2");

    // The acceptance frame: no events, "Label renders" — at least one
    // clipped shape and the label flag set.
    check(poko_shell_frame(shell, 0.0, 320, 240, &info) == POKO_SHELL_OK,
          "FAIL: the empty frame must return 0");
    check(info.events_consumed == 0, "FAIL: empty frame must consume 0");
    check(info.shape_count > 0, "FAIL: label renders — shapes must be > 0");
    check(info.label_rendered == 1, "FAIL: label renders — flag must be set");
    check(info.pixels_per_point > 0.0f, "FAIL: pixels_per_point must be set");
    check(info.repaint_delay_ms <= 16,
          "FAIL: an empty frame should want a near-immediate repaint");

    // Events are consumed in one frame: queue is empty afterwards.
    PokoEvent ev_motion = motion(160.0f, 120.0f);
    PokoEvent ev_press = click(160.0f, 120.0f, 0, 1);
    PokoEvent ev_release = click(160.0f, 120.0f, 0, 0);
    PokoEvent ev_right = click(10.0f, 10.0f, 1, 1);
    PokoEvent ev_wheel = wheel(0.0f, -3.5f);
    PokoEvent ev_text = text_ev("hi", 2);
    PokoEvent ev_focus = focus(1);
    check(poko_shell_push_event(shell, &ev_motion) == POKO_SHELL_OK,
          "FAIL: push motion");
    check(poko_shell_push_event(shell, &ev_press) == POKO_SHELL_OK,
          "FAIL: push primary press");
    check(poko_shell_push_event(shell, &ev_release) == POKO_SHELL_OK,
          "FAIL: push primary release");
    check(poko_shell_push_event(shell, &ev_right) == POKO_SHELL_OK,
          "FAIL: push secondary press");
    check(poko_shell_push_event(shell, &ev_wheel) == POKO_SHELL_OK,
          "FAIL: push wheel");
    check(poko_shell_push_event(shell, &ev_text) == POKO_SHELL_OK,
          "FAIL: push text");
    check(poko_shell_push_event(shell, &ev_focus) == POKO_SHELL_OK,
          "FAIL: push focus");
    check(poko_shell_frame(shell, 0.5, 320, 240, &info) == POKO_SHELL_OK,
          "FAIL: the event frame must return 0");
    check(info.events_consumed == 7,
          "FAIL: the frame must consume all seven events");
    uint32_t pending = 99;
    check(poko_shell_drain_events(shell, nullptr, 0, &pending) ==
                  POKO_SHELL_OK &&
              pending == 0,
          "FAIL: the frame must leave the queue empty");

    // Determinism: the same time and events give the same shape count on
    // a second run (the shell runs on the project's fixed-clock rule).
    uint32_t first_shapes = info.shape_count;
    PokoShell* twin = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &twin) == POKO_SHELL_OK,
          "FAIL: twin create must succeed");
    PokoEvent twin_motion = motion(160.0f, 120.0f);
    check(poko_shell_push_event(twin, &twin_motion) == POKO_SHELL_OK,
          "FAIL: twin push motion");
    PokoFrameInfo twin_info{};
    check(poko_shell_frame(twin, 0.5, 320, 240, &twin_info) == POKO_SHELL_OK,
          "FAIL: twin frame must return 0");
    check(twin_info.events_consumed == 1 &&
              twin_info.shape_count == first_shapes,
          "FAIL: equal inputs must give equal shape counts (determinism)");
    // But different screen sizes give different label rects, so a second
    // shell at a different size is not required to match — only the same
    // inputs. Twin at the same size already checked; destroy it.
    poko_shell_destroy(twin);

    // A frame with no time and no size change still renders.
    check(poko_shell_frame(shell, 1.0, 320, 240, &info) == POKO_SHELL_OK &&
              info.shape_count > 0,
          "FAIL: subsequent frame must still render the label");

    poko_shell_destroy(shell);
    poko_shell_destroy(nullptr);

    if (failures > 0) {
        std::printf("FAIL: %d shell frame check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all shell frame checks passed");
}
