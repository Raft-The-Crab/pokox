# Integration review — 2026-11-22

## Scope and findings

PokoX is a C++20 engine/platform scaffold. The queue identifies infrastructure,
renderer/platform prototypes, and ENG-14–20 configuration, statistics, assets,
texture/mesh loaders, and orbit camera work; many product systems and target
platform gates are still open. The original archive contains existing uncommitted
changes; they were retained. Earlier GPU reports are historical evidence, not
fresh validation of this revision.

- **Fixed: cube camera clips its target.** `look_at` used 0 rather than 1 as
  the affine matrix's homogeneous bottom-right element. The default orbit
  target projected to z/w = 1.002, outside Vulkan's far clipping plane.
  The projection also used an OpenGL-style [-1, 1] depth interval; it now
  uses Vulkan's [0, 1] range, matching the current cube backend. The API
  comment now states the correct multiplication order and depth convention.
- **Added regression coverage:** `pokox_camera_test` builds the real camera
  without a GPU and checks the origin, Vulkan near/far planes, aspect, orbit,
  and zoom. Its origin and depth checks failed before the fix and passed after.
- **Fixed strict-build warnings:** signed/unsigned comparison in the frame
  statistics test and unused argument in the triangle test double.

## Verification on this host

Linux x86-64; GCC 11.5.0; CMake 3.31.10; C++20. No graphics dependencies,
window server, target GPU, Windows or Android environment were used.

- Original dependency-free Debug build and CTest: **33/33 passed**.
- Updated dependency-free Debug build and CTest: **34/34 passed**.
- Fresh Debug build with `-Wall -Wextra -Wpedantic -Werror`: **34/34 passed**.
- Focused camera test with AddressSanitizer and UndefinedBehaviorSanitizer:
  passed using the host's installed sanitizer runtimes.
- Test doubles exercise control flow, not actual SDL, Diligent, Vulkan,
  shader compilation, display or GPU rendering.

Reproduce (with CMake 3.28+ and Python 3.9+):

```sh
cmake -S . -B build-review -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON \
  -DCMAKE_CXX_FLAGS='-Wall -Wextra -Wpedantic -Werror'
cmake --build build-review -j 4
ctest --test-dir build-review --output-on-failure
```

## Remaining limitations and risks

1. The changed camera has **not** been rebuilt with the real SDL/Diligent SDK,
   visually checked, or tested on a Vulkan device. Run the existing cube demo
   with validation enabled and visually check the cube and orbit/zoom after the
   full dependency build. Existing historical frame counts do not prove this fix.
2. Camera aspect is still set only at startup; resizing can stretch the cube.
   ENG-04/05 OpenGL, resize, Android and visual acceptance remain open.
3. `config::load_file` and helpers are declared `noexcept` but allocate strings
   and vectors; allocation failure can terminate the process. CBOR allocation
   failures are mapped to generic malformed/truncated/limit errors. These error
   paths were not redesigned in this focused review.
4. Full dependency builds, CI, MSVC, Android and target-device checks were not
   run. The repository's status documents include older contradictory summaries;
   do not infer completion of gates from them.
5. The archive includes a graphify graph but the `graphify` executable was not
   available here, so the graph was not refreshed and may be stale for changes.

This is a scoped integration review, not a proof that all completed tasks are
free of defects, security issues, or warnings in configurations not built here.

## Subsequent review

Configuration allocation handling and Graphify availability were addressed in the subsequent review; see `project-review-2026-11-22.md`. The remaining target-device and GPU limitations above still apply.
