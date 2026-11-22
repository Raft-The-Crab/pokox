# ENG-22 — lit-cube screenshot golden

Status: **implemented locally; CI acceptance remains open until the new job runs green on GitHub.** The owner explicitly requested this task while earlier gates remain open; no gate is waived. See `eng01-eng21-audit-2026-11-22.md` for unresolved ENG-15 timing, ENG-17 ready/install semantics, and platform coverage.

## Defect found during reference review

The first fixed-view screenshot showed a flat, ambient-only silhouette: the cube's exterior faces were being culled. The built-in cube is authored counterclockwise from the outside, but Diligent's rasterizer defaults to clockwise front faces. The Vulkan mesh pass now sets `FrontCounterClockwise = True` with back-face culling. The corrected image has three separately illuminated faces; a golden of the broken silhouette was **not** adopted. The mesh path assumes CCW outward-facing triangles. This is a Vulkan software-rendering observation; target-GPU and other-backend verification is still required.

## What was added

- `pokox_cube --golden-view` selects a fixed, zoomed-out camera and ignores mouse and arrow-key camera/light interactions. Window close/resize events still work; normal demo behavior is unchanged without the option. The screenshot test supplies an explicit light and 320x240 window configuration.
- `engine/render/tests/integration/cube_golden.py` runs the real cube for 300 frames on an isolated X11 display, checks for a stable, nonblank 24-bit RGB image, and requires the expected Mesa llvmpipe LLVM 23.1.6 / 128-bit / Mesa 26.3.1 software adapter, validation requested, clean process exit and zero captured graphics errors/warnings. It writes RGB8 PNG with fixed filtering and uncompressed DEFLATE blocks for byte-stable encoding, then invokes the existing INF-05 byte-for-byte golden harness. The optional saved actual cannot be a symlink or alias the reference; capture also refuses to overwrite the shipped reference.
- `engine/render/tests/fixtures/golden/lit_cube_llvmpipe.png` is the reviewed 320x240 reference, with SHA-256 `46f3556f3477b57f8db90c4f6b2281297237f16ffa7dff74e08d7dadd4dc0e32`. The reference represents one software stack, **not** all GPU vendors or drivers.
- `test_cube_fixed_view_x11.py` optionally uses python-xlib/XTest to inject orbit, wheel and light input and check that the fixed screenshot stays unchanged.
- `pokox_cube_golden_encoder` runs in dependency-free CTest and checks PNG roundtrips, multi-block data, invalid input, output-path safety and the reference's three lit face samples. `pokox_cube_golden` is opt-in through `POKO_WITH_CUBE_GOLDEN=ON`; it requires Linux, testing, the real Vulkan cube, shader artifacts and an isolated X11 display. The actual is retained in the build directory for diagnostics.
- A new `linux-lit-cube-golden` GitHub Actions job installs the pinned conda-forge package set and uses pinned action commits, builds the Vulkan-only cube, runs the exact comparison under Xvfb and uploads the actual image on failure when available. This job has **not** run on GitHub yet. The Ubuntu runner, system packages and compiler remain external variables, so the first hosted run may uncover compatibility or exact-pixel differences; the local clean build used GCC 11.5 on Amazon Linux, not the GitHub-hosted Ubuntu runner. The dependency URLs identify exact package builds but do not include cryptographic hashes in the explicit file. No automatic golden updates occur in CI.

## Local evidence

- Reviewed screenshot contains the full cube: background `(53,97,144)`, three sampled lit faces `(217,217,217)`, `(195,195,195)` and `(228,228,228)`.
- Three independent real software-Vulkan screenshot runs matched the same reference; a separate clean, Vulkan-only CI-equivalent build also matched it; a deliberately dimmed fragment shader produced a byte mismatch (exit 1), demonstrating that the comparison detects a real lighting change. A subsequent run with retained actual image matched byte-for-byte.
- Real SDL3 + pinned Diligent graphics suite: **57/57 CTest entries** passed, including the opt-in golden. After the culling change the synthetic orbit/resize smoke test and live light-control smoke test each submitted 300 frames, reporting zero captured graphics errors/warnings. A separate fixed-view test confirmed synthetic orbit, wheel and light input leave the image unchanged. The tests do not establish real-device, high-DPI or OpenGL correctness.
- Strict C++20 dependency-free suite: **41/41**; changed renderer sources also passed real-header syntax checks with `-Wall -Wextra -Wpedantic -Werror`. ASan/UBSan dependency-free suite: **41/41**; these do not sanitize the actual graphics path. Vulkan 1.1 SPIR-V validation passed.
- `actionlint` 1.7.12 and YAML parsing passed for the expanded workflow. These are static checks, not a GitHub execution. CMake configuration emitted 19 upstream Diligent deprecation warnings; Xvfb emitted nonfatal keyboard-map warnings. Warning-free build is not claimed.

## Local execution

Recreate the Linux x86-64 graphics environment using `tools/dependencies/linux-graphics-conda-explicit.txt`, with the project's pinned Diligent checkout/submodules and a CMake >=3.28 build tool. Set the environment's `bin` on `PATH` and `lib` on `LD_LIBRARY_PATH`; set `CMAKE_PREFIX_PATH` and `PKG_CONFIG_PATH` to the environment. The GitHub workflow contains the full configure flags and CI setup. The test assumes a free, isolated X11 display, not an interactive desktop.

```sh
export SDL_VIDEODRIVER=x11 LIBGL_ALWAYS_SOFTWARE=1 LP_NATIVE_VECTOR_WIDTH=128 LP_NUM_THREADS=1
export VK_ICD_FILENAMES="$CONDA_PREFIX/share/vulkan/icd.d/lvp_icd.x86_64.json"
export LIBGL_DRIVERS_PATH="$CONDA_PREFIX/lib/dri"
xvfb-run -a -s '-screen 0 1280x800x24 -nolisten tcp' \
  ctest --test-dir build-golden -R '^pokox_cube_golden$' --output-on-failure --no-tests=error
```

`--capture /tmp/candidate.png` writes only a candidate, without updating a reference. To deliberately change a golden, capture and visually inspect it on the pinned stack, examine the intended code/image difference, then explicitly use `golden.py --update` as documented in `tools/testutils/harness/README.md` and update the unit-test sample expectations if appropriate. Never silently regenerate in CI. An exact mismatch on another software stack or GPU is not, by itself, proof of a rendering bug.

## Remaining

First verify the hosted CI job and resolve any reproducibility or dependency failures without weakening the comparison. Then complete the existing ENG-15/17 fixes and target-device, OpenGL, Windows/MSVC, Android and infrastructure acceptance gates. ENG-22 is not accepted until CI actually compares the golden successfully.
