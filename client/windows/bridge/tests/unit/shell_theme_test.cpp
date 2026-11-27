// SHL-12: theme tokens and bevel widgets — Classic and Flat goldens.
#include "poko/shell/unique_shell.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

namespace {

int failures = 0;

void check(bool ok, const char* what) {
    if (!ok) {
        std::puts(what);
        failures++;
    }
}

bool capture_mesh(PokoShell* shell, std::vector<float>& out_v,
                  std::vector<uint32_t>& out_i) {
    PokoFrameInfo frame{};
    if (poko_shell_frame(shell, 1.0, 320, 240, &frame) != POKO_SHELL_OK) return false;
    if (frame.shape_count == 0 || frame.label_rendered != 1) return false;
    uint32_t vc = 0, ic = 0;
    if (poko_shell_mesh(shell, nullptr, 0, &vc, nullptr, 0, &ic) != POKO_SHELL_OK) {
        return false;
    }
    out_v.resize(vc * 6);
    out_i.resize(ic);
    return poko_shell_mesh(shell, out_v.data(), vc, &vc, out_i.data(), ic, &ic) ==
           POKO_SHELL_OK;
}

}  // namespace

int main() {
    check(poko_shell_set_theme(nullptr, POKO_THEME_CLASSIC) ==
              POKO_SHELL_ERROR_NULL,
          "FAIL: null shell set_theme must return -1");

    int32_t rc = -1;
    auto shell_a = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &rc);
    auto shell_b = poko::shell::UniqueShell::create(POKO_SHELL_ABI_VERSION, &rc);
    check(static_cast<bool>(shell_a) && static_cast<bool>(shell_b),
          "FAIL: create shells");

    check(poko_shell_set_theme(shell_a.get(), 99) == POKO_SHELL_ERROR_SHELL,
          "FAIL: unknown theme must return -2");

    // Classic golden: two handles with Classic produce byte-identical meshes.
    check(poko_shell_set_theme(shell_a.get(), POKO_THEME_CLASSIC) == POKO_SHELL_OK,
          "FAIL: set Classic on shell_a");
    check(poko_shell_set_theme(shell_b.get(), POKO_THEME_CLASSIC) == POKO_SHELL_OK,
          "FAIL: set Classic on shell_b");
    std::vector<float> classic_v1, classic_v2;
    std::vector<uint32_t> classic_i1, classic_i2;
    check(capture_mesh(shell_a.get(), classic_v1, classic_i1),
          "FAIL: capture Classic mesh 1");
    check(capture_mesh(shell_b.get(), classic_v2, classic_i2),
          "FAIL: capture Classic mesh 2");
    check(classic_v1 == classic_v2 && classic_i1 == classic_i2,
          "FAIL: Classic theme golden must be deterministic");

    // Flat golden: two handles with Flat produce byte-identical meshes.
    check(poko_shell_set_theme(shell_a.get(), POKO_THEME_FLAT) == POKO_SHELL_OK,
          "FAIL: set Flat on shell_a");
    check(poko_shell_set_theme(shell_b.get(), POKO_THEME_FLAT) == POKO_SHELL_OK,
          "FAIL: set Flat on shell_b");
    std::vector<float> flat_v1, flat_v2;
    std::vector<uint32_t> flat_i1, flat_i2;
    check(capture_mesh(shell_a.get(), flat_v1, flat_i1),
          "FAIL: capture Flat mesh 1");
    check(capture_mesh(shell_b.get(), flat_v2, flat_i2),
          "FAIL: capture Flat mesh 2");
    check(flat_v1 == flat_v2 && flat_i1 == flat_i2,
          "FAIL: Flat theme golden must be deterministic");
    check(!flat_v1.empty() && !flat_i1.empty(),
          "FAIL: Flat theme must produce non-empty geometry");

    if (failures > 0) {
        std::printf("FAIL: %d SHL-12 theme check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all SHL-12 Classic and Flat theme golden checks passed");
}
