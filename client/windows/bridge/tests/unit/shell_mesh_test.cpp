// SHL-05/06: poko_shell_mesh tessellates the last frame into the PMES v1
// vertex layout (6 floats: pos3 + normal3, u32 indices, per-primitive
// offsets) and poko_shell_texture_delta drains the font atlas upload.
// The vertex golden: a single push_button frame must give a valid,
// self-consistent mesh — indices in range, normals all (0,0,1), positions
// inside the screen rect, and the same frame twice byte-identical.
extern "C" {
#include "poko_shell.h"
}

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

PokoEvent click(float x, float y) {
    PokoEvent e{};
    e.kind = POKO_EVENT_BUTTON;
    e.x = x;
    e.y = y;
    e.button = 0;
    e.pressed = 1;
    return e;
}

}  // namespace

int main() {
    PokoShell* shell = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &shell) == POKO_SHELL_OK,
          "FAIL: create must succeed");

    // Error paths: mesh export before any frame is -2; nulls are -1.
    uint32_t v_needed = 0;
    uint32_t i_needed = 0;
    check(poko_shell_mesh(shell, nullptr, 0, &v_needed, nullptr, 0,
                          &i_needed) == POKO_SHELL_ERROR_SHELL,
          "FAIL: mesh before frame must return -2");
    check(poko_shell_mesh(nullptr, nullptr, 0, &v_needed, nullptr, 0,
                          &i_needed) == POKO_SHELL_ERROR_NULL,
          "FAIL: null shell mesh must return -1");
    uint32_t u_needed = 0;
    uint32_t p_needed = 0;
    check(poko_shell_texture_delta(nullptr, nullptr, 0, &u_needed, nullptr, 0,
                                   &p_needed) == POKO_SHELL_ERROR_NULL,
          "FAIL: null shell texture delta must return -1");

    // Frame one: the font atlas upload is queued.
    PokoFrameInfo info{};
    check(poko_shell_frame(shell, 0.0, 320, 240, &info) == POKO_SHELL_OK,
          "FAIL: first frame must return 0");

    // SHL-06 sizing call: at least one update (the font atlas), nonzero
    // pixels, and the counts are stable.
    check(poko_shell_texture_delta(shell, nullptr, 0, &u_needed, nullptr, 0,
                                   &p_needed) == POKO_SHELL_OK,
          "FAIL: texture sizing call must return 0");
    check(u_needed >= 1, "FAIL: the font atlas must be queued");
    check(p_needed >= u_needed * 4,
          "FAIL: every texture must carry at least 4 bytes per pixel");

    // The full drain into real buffers.
    std::vector<PokoTextureUpdate> updates(u_needed);
    std::vector<uint8_t> pixels(p_needed);
    uint32_t u_got = 0;
    uint32_t p_got = 0;
    check(poko_shell_texture_delta(shell, updates.data(),
                                   static_cast<uint32_t>(updates.size()),
                                   &u_got, pixels.data(),
                                   static_cast<uint32_t>(pixels.size()),
                                   &p_got) == POKO_SHELL_OK,
          "FAIL: texture drain must return 0");
    check(u_got == u_needed && p_got == p_needed,
          "FAIL: the drain must hand back exactly the sized counts");
    // First update is Managed(0), the font atlas — square-ish, RGBA8,
    // and its pixels fit in the buffer.
    check(updates[0].id == 0 && updates[0].width > 0 && updates[0].height > 0 &&
              updates[0].pixels_offset == 0 &&
              updates[0].pixels_len == updates[0].width * updates[0].height * 4,
          "FAIL: the font atlas update must be id 0, w*h*4 bytes at 0");
    // A second drain finds nothing new (nothing rendered since).
    uint32_t u2 = 99;
    uint32_t p2 = 99;
    check(poko_shell_texture_delta(shell, nullptr, 0, &u2, nullptr, 0, &p2) ==
                  POKO_SHELL_OK &&
              u2 == 0 && p2 == 0,
          "FAIL: a drained queue must report zero pending");

    // SHL-05 sizing call on the same frame.
    check(poko_shell_mesh(shell, nullptr, 0, &v_needed, nullptr, 0,
                          &i_needed) == POKO_SHELL_OK,
          "FAIL: mesh sizing call must return 0");
    check(v_needed >= 3 && i_needed >= 3,
          "FAIL: a laid-out label must have at least one triangle");

    // Half-null calls (one output buffer null, the other non-null) must fail
    // with -2 rather than silently succeeding as sizing calls, and preserve shapes.
    std::vector<float> half_v(v_needed * 6);
    std::vector<uint32_t> half_i(i_needed);
    uint32_t hv = 0;
    uint32_t hi = 0;
    check(poko_shell_mesh(shell, nullptr, 0, &hv, half_i.data(),
                          static_cast<uint32_t>(half_i.size()),
                          &hi) == POKO_SHELL_ERROR_SHELL,
          "FAIL: half-null mesh (null vertices) must return -2");
    check(hv == v_needed && hi == i_needed,
          "FAIL: counts must still be written on half-null (null vertices)");
    check(poko_shell_mesh(shell, half_v.data(),
                          static_cast<uint32_t>(half_v.size()), &hv, nullptr, 0,
                          &hi) == POKO_SHELL_ERROR_SHELL,
          "FAIL: half-null mesh (null indices) must return -2");
    check(hv == v_needed && hi == i_needed,
          "FAIL: counts must still be written on half-null (null indices)");

    // Caps too small is -2 with the counts still written, and a refused
    // drain must not consume the frame's shapes.
    uint32_t v_small = 0;
    uint32_t i_small = 0;
    std::vector<float> small_v(v_needed - 1);
    std::vector<uint32_t> small_i(i_needed - 1);
    check(poko_shell_mesh(shell, small_v.data(), v_needed - 1, &v_small,
                          small_i.data(), i_needed - 1,
                          &i_small) == POKO_SHELL_ERROR_SHELL,
          "FAIL: too-small caps must return -2");
    check(v_small == v_needed && i_small == i_needed,
          "FAIL: counts must still be written on a refused drain");
    check(poko_shell_mesh(shell, nullptr, 0, &v_small, nullptr, 0,
                          &i_small) == POKO_SHELL_OK &&
              v_small == v_needed,
          "FAIL: the shapes must survive a refused drain");

    // Re-run the frame to get fresh shapes, then drain for real. Two
    // frames with the same time and screen give the same vertex bytes —
    // the determinism the golden pins.
    check(poko_shell_frame(shell, 1.0, 320, 240, &info) == POKO_SHELL_OK,
          "FAIL: second frame must return 0");
    std::vector<float> verts(v_needed * 6);
    std::vector<uint32_t> idx(i_needed);
    uint32_t v_got = 0;
    uint32_t i_got = 0;
    check(poko_shell_mesh(shell, verts.data(),
                          static_cast<uint32_t>(verts.size()), &v_got,
                          idx.data(), static_cast<uint32_t>(idx.size()),
                          &i_got) == POKO_SHELL_OK,
          "FAIL: mesh drain must return 0");
    check(v_got == v_needed && i_got == i_needed,
          "FAIL: the mesh drain must hand back exactly the sized counts");

    // Vertex golden — the PMES v1 layout rules, checked over every
    // vertex: normal exactly (0,0,1), positions inside the 320x240 rect
    // and finite. Also the index rule: every index < vertex count.
    bool layout_ok = true;
    for (uint32_t v = 0; v < v_got; ++v) {
        const float* f = &verts[v * 6];
        if (f[3] != 0.0f || f[4] != 0.0f || f[5] != 1.0f) {
            layout_ok = false;  // normal
        }
        if (!(f[0] >= 0.0f && f[0] <= 320.0f && f[1] >= 0.0f &&
              f[1] <= 240.0f)) {
            layout_ok = false;  // position in rect
        }
    }
    bool index_ok = true;
    for (uint32_t i = 0; i < i_got; ++i) {
        if (idx[i] >= v_got) {
            index_ok = false;
        }
    }
    check(layout_ok, "FAIL: vertex layout (normal (0,0,1), pos in rect)");
    check(index_ok, "FAIL: all indices must be below the vertex count");
    // Triangle rule: the index count is a multiple of 3.
    check(i_got % 3 == 0, "FAIL: index count must be a multiple of 3");

    // Determinism: an identical frame (same time, same screen) on a twin
    // handle gives byte-identical vertices.
    PokoShell* twin = nullptr;
    check(poko_shell_create(POKO_SHELL_ABI_VERSION, &twin) == POKO_SHELL_OK,
          "FAIL: twin create must succeed");
    PokoFrameInfo twin_info{};
    check(poko_shell_frame(twin, 1.0, 320, 240, &twin_info) == POKO_SHELL_OK,
          "FAIL: twin frame must return 0");
    uint32_t tv_needed = 0;
    uint32_t ti_needed = 0;
    check(poko_shell_mesh(twin, nullptr, 0, &tv_needed, nullptr, 0,
                          &ti_needed) == POKO_SHELL_OK,
          "FAIL: twin mesh sizing must return 0");
    check(tv_needed == v_needed && ti_needed == i_needed,
          "FAIL: equal frames must size equally");
    std::vector<float> tverts(tv_needed * 6);
    std::vector<uint32_t> tidx(ti_needed);
    uint32_t tv_got = 0;
    uint32_t ti_got = 0;
    check(poko_shell_mesh(twin, tverts.data(),
                          static_cast<uint32_t>(tverts.size()), &tv_got,
                          tidx.data(), static_cast<uint32_t>(tidx.size()),
                          &ti_got) == POKO_SHELL_OK,
          "FAIL: twin mesh drain must return 0");
    check(std::memcmp(verts.data(), tverts.data(), v_got * 6 * sizeof(float)) ==
                  0 &&
              std::memcmp(idx.data(), tidx.data(), i_got * 4) == 0,
          "FAIL: equal frames must give byte-identical meshes (the golden)");

    poko_shell_destroy(twin);
    poko_shell_destroy(shell);

    if (failures > 0) {
        std::printf("FAIL: %d shell mesh/texture check(s) failed\n", failures);
        return 1;
    }
    std::puts("OK: all shell mesh and texture checks passed");
}
