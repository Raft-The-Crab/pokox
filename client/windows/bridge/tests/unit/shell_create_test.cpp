// SHL-02: poko_shell_create returns the spec-12 codes for null and ABI
// mismatch, hands out an owning handle on success, and destroy frees it.
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

}  // namespace

int main() {
    // Null out handle is refused before anything else.
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, nullptr) ==
              POKO_SHELL_ERROR_NULL,
          "FAIL: null out handle must return -1");

    // Wrong caller ABI version: -4, and the out handle stays null.
    PokoShell* stale = reinterpret_cast<PokoShell*>(static_cast<uintptr_t>(0x1));
    check(poko_shell_create(POKO_SHELL_ABI_VERSION + 1, &stale) ==
              POKO_SHELL_ERROR_ABI_MISMATCH,
          "FAIL: newer ABI must return -4");
    check(poko_shell_create(POKO_SHELL_ABI_VERSION - 1, &stale) ==
              POKO_SHELL_ERROR_ABI_MISMATCH,
          "FAIL: older ABI must return -4");
    check(stale == nullptr,
          "FAIL: out handle must be null after an ABI mismatch");

    // Matching version: 0 and a non-null owning handle.
    PokoShell* shell = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) == POKO_SHELL_OK,
          "FAIL: matching ABI must return 0");
    check(shell != nullptr, "FAIL: success must store a handle");

    poko_shell_destroy(shell);
    poko_shell_destroy(nullptr);  // no-op

    if (failures > 0) {
        std::printf("FAIL: %d shell create check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all shell create checks passed");
}
