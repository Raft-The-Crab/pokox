// SHL-13: reentrancy guard — any nested poko_shell_* call on the same
// handle while a call is active returns POKO_SHELL_ERROR_REENTRANT (-5),
// and the guard releases on exit so subsequent calls succeed.
extern "C" {
#include "poko_shell.h"
using PokoTestFrameCallback = void (*)(PokoShell*, void*);
void poko_shell_test_set_frame_callback(PokoTestFrameCallback cb, void* user);
void poko_shell_test_force_panic(void);
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

struct ReentryCheckState {
    bool callback_ran = false;
};

void nested_callback(PokoShell* shell, void* user) {
    auto* state = static_cast<ReentryCheckState*>(user);
    state->callback_ran = true;

    PokoEvent ev{};
    ev.kind = POKO_EVENT_MOTION;
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_ERROR_REENTRANT,
          "FAIL: nested push_event must return -5");

    uint32_t written = 0;
    check(poko_shell_drain_events(shell, nullptr, 0, &written) ==
              POKO_SHELL_ERROR_REENTRANT,
          "FAIL: nested drain_events must return -5");

    PokoFrameInfo nested_info{};
    check(poko_shell_frame(shell, 0.0, 320, 240, &nested_info) ==
              POKO_SHELL_ERROR_REENTRANT,
          "FAIL: nested frame must return -5");

    uint32_t vw = 0;
    uint32_t iw = 0;
    check(poko_shell_mesh(shell, nullptr, 0, &vw, nullptr, 0, &iw) ==
              POKO_SHELL_ERROR_REENTRANT,
          "FAIL: nested mesh must return -5");

    uint32_t uw = 0;
    uint32_t pw = 0;
    check(poko_shell_texture_delta(shell, nullptr, 0, &uw, nullptr, 0, &pw) ==
              POKO_SHELL_ERROR_REENTRANT,
          "FAIL: nested texture_delta must return -5");
}

void panicking_callback(PokoShell* shell, void*) {
    poko_shell_test_force_panic();
    PokoEvent ev{};
    ev.kind = POKO_EVENT_MOTION;
    // Triggers the armed panic inside push_event's catch_unwind; must return -3
    // and not leave the outer frame's reentrancy guard stuck.
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_ERROR_PANIC,
          "FAIL: forced panic inside callback must return -3");
}

}  // namespace

int main() {
    PokoShell* shell = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) == POKO_SHELL_OK &&
              shell != nullptr,
          "FAIL: create must succeed");

    ReentryCheckState state{};
    poko_shell_test_set_frame_callback(nested_callback, &state);

    PokoFrameInfo info{};
    check(poko_shell_frame(shell, 0.0, 320, 240, &info) == POKO_SHELL_OK,
          "FAIL: outer frame must succeed");
    check(state.callback_ran, "FAIL: nested callback did not run");

    // Guard must be released after frame returns.
    poko_shell_test_set_frame_callback(nullptr, nullptr);
    PokoEvent ev{};
    ev.kind = POKO_EVENT_MOTION;
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_OK,
          "FAIL: push_event after frame must succeed");

    // Guard must also remain clean if a panic happens inside a callback.
    poko_shell_test_set_frame_callback(panicking_callback, nullptr);
    check(poko_shell_frame(shell, 0.016, 320, 240, &info) == POKO_SHELL_OK,
          "FAIL: outer frame after caught callback panic must succeed");
    poko_shell_test_set_frame_callback(nullptr, nullptr);
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_OK,
          "FAIL: push_event after callback panic must succeed");

    poko_shell_destroy(shell);

    if (failures > 0) {
        std::printf("FAIL: %d shell reentrancy check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all SHL-13 reentrancy guard checks passed");
}
