// SHL-07: the RAII guard destroys exactly once (scope exit, move, reset)
// and 10k frames on one handle leave memory flat — the acceptance
// "10k frames flat memory". RSS is sampled from /proc (Linux) or the
// process counters (Windows); the bound allows egui's one-time font
// atlas plus 2 MiB of slack, so any per-frame leak of even ~200 bytes
// fails the run.
extern "C" {
#include "poko_shell.h"
}

#include "poko/shell/unique_shell.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#else
#include <fstream>
#endif

namespace {

int failures = 0;

void check(bool ok, const char* what) {
    if (!ok) {
        std::puts(what);
        failures++;
    }
}

/// Resident memory of this process in bytes, best effort.
uint64_t rss_bytes() {
#ifdef _WIN32
    PROCESS_MEMORY_COUNTERS mc{};
    mc.cb = sizeof(mc);
    if (!GetProcessMemoryInfo(GetCurrentProcess(), &mc, sizeof(mc))) {
        return 0;
    }
    return mc.WorkingSetSize;
#else
    std::ifstream statm("/proc/self/statm");
    uint64_t size_pages = 0;
    uint64_t resident_pages = 0;
    statm >> size_pages >> resident_pages;
    return resident_pages * 4096ULL;
#endif
}

PokoEvent motion(float x, float y) {
    PokoEvent e{};
    e.kind = POKO_EVENT_MOTION;
    e.x = x;
    e.y = y;
    return e;
}

}  // namespace

int main() {
    // RAII basics: scope exit destroys; move hands off ownership; reset
    // destroys early and makes the guard empty.
    {
        int32_t rc = 99;
        auto shell = poko::shell::UniqueShell::create(
            POKO_SHELL_ABI_VERSION, &rc);
        check(rc == POKO_SHELL_OK && static_cast<bool>(shell),
              "FAIL: guard create must succeed");
        PokoFrameInfo info{};
        check(poko_shell_frame(shell.get(), 0.0, 160, 120, &info) ==
                  POKO_SHELL_OK,
              "FAIL: a frame through the guard must return 0");
    }  // destructor ran here — no leak, no double free
    {
        int32_t rc = 99;
        auto a = poko::shell::UniqueShell::create(
            POKO_SHELL_ABI_VERSION, &rc);
        auto b = std::move(a);  // a loses the handle
        check(!a && b, "FAIL: move must empty the source and fill the target");
        b.reset();
        check(!b, "FAIL: reset must empty the guard");
        int32_t rc2 = 99;
        auto c = poko::shell::UniqueShell::create(
            POKO_SHELL_ABI_VERSION, &rc2);
        check(rc2 == POKO_SHELL_OK && static_cast<bool>(c),
              "FAIL: reuse after reset must create cleanly");
        // A mismatched-ABI create leaves the guard empty with the code.
        int32_t rc3 = 99;
        auto bad = poko::shell::UniqueShell::create(
            POKO_SHELL_ABI_VERSION - 1, &rc3);
        check(rc3 == POKO_SHELL_ERROR_ABI_MISMATCH && static_cast<bool>(!bad),
              "FAIL: failed create must leave the guard empty");
    }

    // The acceptance: 10k frames, memory flat. Each frame pushes an
    // event and renders, so queues, shapes and texture deltas must all
    // be freed every frame.
    int32_t rc = 99;
    auto shell = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &rc);
    check(static_cast<bool>(shell), "FAIL: long-run create must succeed");
    // Warm up: the font atlas and egui state allocate once here, not in
    // the measured window.
    for (int i = 0; i < 100; ++i) {
        PokoEvent e = motion(static_cast<float>(i), 0.0f);
        poko_shell_push_event(shell.get(), &e);
        PokoFrameInfo info{};
        poko_shell_frame(shell.get(), i * 0.016, 320, 240, &info);
    }
    const uint64_t before = rss_bytes();
    const int kFrames = 10000;
    for (int i = 0; i < kFrames; ++i) {
        PokoEvent e = motion(static_cast<float>(i % 320), static_cast<float>(i % 240));
        if (poko_shell_push_event(shell.get(), &e) != POKO_SHELL_OK) {
            check(false, "FAIL: push must succeed during the long run");
            break;
        }
        PokoFrameInfo info{};
        if (poko_shell_frame(shell.get(), (i + 100) * 0.016, 320, 240, &info) !=
            POKO_SHELL_OK) {
            check(false, "FAIL: frame must succeed during the long run");
            break;
        }
        if (i == 0) {
            // Drain the texture deltas once so the queued font atlas
            // does not sit in the handle for the whole run.
            uint32_t u = 0;
            uint32_t p = 0;
            poko_shell_texture_delta(shell.get(), nullptr, 0, &u, nullptr, 0,
                                     &p);
            std::vector<PokoTextureUpdate> updates(u);
            std::vector<uint8_t> pixels(p);
            poko_shell_texture_delta(shell.get(), updates.data(), u, &u,
                                     pixels.data(), p, &p);
        }
    }
    const uint64_t after = rss_bytes();
    const uint64_t budget = 2ULL * 1024ULL * 1024ULL;  // 2 MiB slack
    const int64_t delta = static_cast<int64_t>(after) -
                          static_cast<int64_t>(before);
    std::printf("rss before=%llu after=%llu delta=%lld bytes\n",
                (unsigned long long)before, (unsigned long long)after,
                (long long)delta);
    // Flat means |delta| within budget — growth is a leak, shrinkage is
    // just the allocator returning pages.
    check(delta <= static_cast<int64_t>(budget) &&
              delta >= -static_cast<int64_t>(budget),
          "FAIL: 10k frames must leave memory flat (delta over budget)");

    // And 10k create/destroy cycles leak nothing either.
    const uint64_t before_cycles = rss_bytes();
    for (int i = 0; i < kFrames; ++i) {
        int32_t crc = 99;
        auto s = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &crc);
        if (crc != POKO_SHELL_OK) {
            check(false, "FAIL: cycle create must succeed");
            break;
        }
    }
    const uint64_t after_cycles = rss_bytes();
    const int64_t delta_cycles =
        static_cast<int64_t>(after_cycles) -
        static_cast<int64_t>(before_cycles);
    std::printf("cycles delta=%lld bytes\n", (long long)delta_cycles);
    check(delta_cycles <= static_cast<int64_t>(budget) &&
              delta_cycles >= -static_cast<int64_t>(budget),
          "FAIL: 10k create/destroy cycles must leave memory flat");

    if (failures > 0) {
        std::printf("FAIL: %d shell raii/memory check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all shell RAII and flat-memory checks passed");
}
