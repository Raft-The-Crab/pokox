// SHL-08: panic boundary on all exports — a forced panic inside Rust must
// never unwind across the C ABI; every status-returning export returns
// POKO_SHELL_ERROR_PANIC (-3) and destroy absorbs panics safely.
extern "C" {
#include "poko_shell.h"
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

}  // namespace

int main() {
    // 1. poko_shell_create: forced panic returns -3 and leaves out_shell null.
    PokoShell* shell = reinterpret_cast<PokoShell*>(static_cast<uintptr_t>(0x1));
    poko_shell_test_force_panic();
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) ==
              POKO_SHELL_ERROR_PANIC,
          "FAIL: create forced panic must return -3");
    check(shell == nullptr,
          "FAIL: create forced panic must leave out_shell null");

    // Normal create works afterward.
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) == POKO_SHELL_OK &&
              shell != nullptr,
          "FAIL: create must recover after panic");

    // 2. poko_shell_push_event: forced panic returns -3.
    PokoEvent ev{};
    ev.kind = POKO_EVENT_MOTION;
    poko_shell_test_force_panic();
    check(poko_shell_push_event(shell, &ev) == POKO_SHELL_ERROR_PANIC,
          "FAIL: push_event forced panic must return -3");

    // 3. poko_shell_drain_events: forced panic returns -3.
    uint32_t written = 0;
    poko_shell_test_force_panic();
    check(poko_shell_drain_events(shell, nullptr, 0, &written) ==
              POKO_SHELL_ERROR_PANIC,
          "FAIL: drain_events forced panic must return -3");

    // 4. poko_shell_frame: forced panic returns -3.
    PokoFrameInfo frame{};
    poko_shell_test_force_panic();
    check(poko_shell_frame(shell, 0.0, 320, 240, &frame) ==
              POKO_SHELL_ERROR_PANIC,
          "FAIL: frame forced panic must return -3");

    // 5. poko_shell_mesh: forced panic returns -3.
    uint32_t vw = 0;
    uint32_t iw = 0;
    poko_shell_test_force_panic();
    check(poko_shell_mesh(shell, nullptr, 0, &vw, nullptr, 0, &iw) ==
              POKO_SHELL_ERROR_PANIC,
          "FAIL: mesh forced panic must return -3");

    // 6. poko_shell_texture_delta: forced panic returns -3.
    uint32_t uw = 0;
    uint32_t pw = 0;
    poko_shell_test_force_panic();
    check(poko_shell_texture_delta(shell, nullptr, 0, &uw, nullptr, 0, &pw) ==
              POKO_SHELL_ERROR_PANIC,
          "FAIL: texture_delta forced panic must return -3");

    // Normal frame still works after all those caught panics.
    check(poko_shell_frame(shell, 0.0, 320, 240, &frame) == POKO_SHELL_OK,
          "FAIL: frame must succeed after caught panics");

    // 7. poko_shell_destroy: forced panic on null and non-null does not abort.
    poko_shell_test_force_panic();
    poko_shell_destroy(nullptr);
    poko_shell_test_force_panic();
    poko_shell_destroy(shell);

    if (failures > 0) {
        std::printf("FAIL: %d shell panic check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all shell panic boundary checks passed");
}
