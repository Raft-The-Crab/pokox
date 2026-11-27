// SHL-07: RAII ownership of the shell handle. Every poko_shell_* export
// takes the raw pointer, so engine code hands out UniqueShell::get() and
// the destructor guarantees poko_shell_destroy exactly once — including
// on early returns and exceptions. Spec 12: the engine never frees Rust
// memory; the exported release path does it, through this guard.
#pragma once

extern "C" {
#include "poko_shell.h"
}

#include <cstdint>
#include <utility>

namespace poko::shell {

/// Owning handle. Null by default; create with `UniqueShell::create`.
/// Copying is impossible by construction (double-free).
class UniqueShell {
public:
    UniqueShell() = default;

    /// Creates a shell handle at the caller's ABI version. `ok` says
    /// whether creation succeeded; on failure the guard stays empty and
    /// the caller reads `create_error` for the spec-12 code.
    static UniqueShell create(uint32_t abi_version, int32_t* create_error) {
        UniqueShell shell;
        PokoShell* raw = nullptr;
        int32_t rc = poko_shell_create(abi_version, &raw);
        if (create_error) {
            *create_error = rc;
        }
        if (rc == POKO_SHELL_OK) {
            shell.raw_ = raw;
        }
        return shell;
    }

    ~UniqueShell() { reset(); }

    UniqueShell(const UniqueShell&) = delete;
    UniqueShell& operator=(const UniqueShell&) = delete;

    UniqueShell(UniqueShell&& other) noexcept
        : raw_(std::exchange(other.raw_, nullptr)) {}

    UniqueShell& operator=(UniqueShell&& other) noexcept {
        if (this != &other) {
            reset();
            raw_ = std::exchange(other.raw_, nullptr);
        }
        return *this;
    }

    /// Destroys the held handle (if any) and returns to empty.
    void reset() {
        if (raw_) {
            poko_shell_destroy(raw_);
            raw_ = nullptr;
        }
    }

    /// The raw handle for the poko_shell_* exports, or null when empty.
    [[nodiscard]] PokoShell* get() const { return raw_; }

    [[nodiscard]] explicit operator bool() const { return raw_ != nullptr; }

private:
    PokoShell* raw_ = nullptr;
};

}  // namespace poko::shell
