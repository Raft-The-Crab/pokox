// SHL-14: DPI resize path — changing DPI scale regenerates the font atlas.
#include "poko/shell/unique_shell.hpp"

#include <cstdint>
#include <cstdio>
#include <vector>

namespace {

int failures = 0;

void check(bool ok, const char* what) {
    if (!ok) {
        std::puts(what);
        failures++;
    }
}

bool drain_atlas(PokoShell* shell, uint32_t& out_updates, uint32_t& out_bytes) {
    out_updates = 0;
    out_bytes = 0;
    if (poko_shell_texture_delta(shell, nullptr, 0, &out_updates, nullptr, 0,
                                 &out_bytes) != POKO_SHELL_OK) {
        return false;
    }
    if (out_updates == 0) return true;
    std::vector<PokoTextureUpdate> updates(out_updates);
    std::vector<uint8_t> pixels(out_bytes);
    return poko_shell_texture_delta(shell, updates.data(), out_updates, &out_updates,
                                    pixels.data(), out_bytes, &out_bytes) ==
           POKO_SHELL_OK;
}

}  // namespace

int main() {
    check(poko_shell_set_dpi_scale(nullptr, 1.5f) == POKO_SHELL_ERROR_NULL,
          "FAIL: null shell set_dpi_scale must return -1");

    int32_t rc = -1;
    auto shell = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &rc);
    check(rc == POKO_SHELL_OK && static_cast<bool>(shell),
          "FAIL: UniqueShell create");

    check(poko_shell_set_dpi_scale(shell.get(), 0.0f) == POKO_SHELL_ERROR_SHELL,
          "FAIL: zero dpi_scale must return -2");
    check(poko_shell_set_dpi_scale(shell.get(), -1.5f) == POKO_SHELL_ERROR_SHELL,
          "FAIL: negative dpi_scale must return -2");

    // 100% DPI (1.0x)
    PokoFrameInfo frame{};
    check(poko_shell_frame(shell.get(), 0.0, 640, 480, &frame) == POKO_SHELL_OK &&
              frame.pixels_per_point == 1.0f,
          "FAIL: initial frame must report 1.0 pixels_per_point");
    uint32_t u1 = 0, b1 = 0;
    check(drain_atlas(shell.get(), u1, b1) && u1 >= 1 && b1 > 0,
          "FAIL: 1.0x DPI must queue initial font atlas");

    // Drained queue has 0 pending updates at the same DPI.
    uint32_t u_idle = 99, b_idle = 99;
    check(poko_shell_frame(shell.get(), 0.016, 640, 480, &frame) == POKO_SHELL_OK,
          "FAIL: steady frame");
    check(drain_atlas(shell.get(), u_idle, b_idle) && u_idle == 0 && b_idle == 0,
          "FAIL: steady DPI must not regenerate atlas");

    // 200% DPI (2.0x) + resized logical viewport: font atlas must regenerate larger.
    check(poko_shell_set_dpi_scale(shell.get(), 2.0f) == POKO_SHELL_OK,
          "FAIL: set 2.0x dpi_scale");
    check(poko_shell_frame(shell.get(), 0.032, 960, 540, &frame) == POKO_SHELL_OK &&
              frame.pixels_per_point == 2.0f,
          "FAIL: 2.0x frame must report 2.0 pixels_per_point");
    uint32_t u2 = 0, b2 = 0;
    check(drain_atlas(shell.get(), u2, b2) && u2 >= 1 && b2 > 0,
          "FAIL: 2.0x DPI must regenerate font atlas delta");

    if (failures > 0) {
        std::printf("FAIL: %d SHL-14 DPI resize check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all SHL-14 DPI resize and atlas regeneration checks passed");
}
