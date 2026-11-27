// SHL-01: the cbindgen header and the Rust staticlib link, and the two
// sides agree on the ABI version and the spec-12 error codes.
// The header is emitted for C consumers; C++ includes it under extern "C".
extern "C" {
#include "poko_shell.h"
}

#include <cstdio>

int main() {
    static_assert(POKO_SHELL_OK == 0, "spec 12 error code");
    static_assert(POKO_SHELL_ERROR_NULL == -1, "spec 12 error code");
    static_assert(POKO_SHELL_ERROR_SHELL == -2, "spec 12 error code");
    static_assert(POKO_SHELL_ERROR_PANIC == -3, "spec 12 error code");
    static_assert(POKO_SHELL_ERROR_ABI_MISMATCH == -4, "spec 12 error code");
    static_assert(POKO_SHELL_ERROR_REENTRANT == -5, "spec 12 error code");
    static_assert(POKO_SHELL_ABI_VERSION == 6, "SHL-14 ABI version");

    if (poko_shell_abi_version() != POKO_SHELL_ABI_VERSION) {
        std::puts("FAIL: poko_shell_abi_version disagrees with the header");
        return 1;
    }
    std::puts("OK: all shell bridge link checks passed");
}
