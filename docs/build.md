# Build status

## INF-02 — implementation in place; Windows acceptance pending

The minimal CMake executable, vcpkg dependencies and pinned DiligentCore source integration are in place. **Do not mark INF-02 complete yet:** the plan requires builds on both MSYS2/MinGW and MSVC, and neither has been run in this Linux environment. INF-03 flag contracts are implemented and tested on Linux; Windows checks remain pending. The INF-04 CI workflow has run on GitHub (around 40 runs; the last fully green run was 2026-11-24, after which Actions billing blocked new jobs). The INF-05 golden harness and INF-06 build versioning pass local tests. Standalone SDL window and Vulkan clear-color demos are implemented; no product-ready application is implemented. Historical notes from the supplied archive are preserved in [build-historical.md](build-historical.md).

### Verified on 2026-11-20

- Linux x64; GCC 11.5.0; CMake 4.4.5: the dependency-free Debug build succeeded and `pokox_starts` passed.
- Linux x64, same tools: the **unmodified vcpkg manifest with SDL3 default features** installed successfully. The full dependency-enabled build linked SDL3, ImGui, spdlog, Catch2 and DiligentCore; `pokox_starts` and `pokox_dependency_smoke` both passed. This used a local checkout of the exact DiligentCore revision below.
- The automatic `FetchContent` path was separately configured successfully, and its source and eight submodules matched the pinned revisions. A separate headless dependency probe also passed.
- These are build/link checks only: they do not create a window, initialize Vulkan/OpenGL, test Android, or validate rendering. MSVC and MSYS2 remain unverified.

## Dependency setup

CMake **3.28 or newer**, a C++20 compiler and a generator are required. Git is required for Git checkouts and for tests; Python 3.9+ is required when `BUILD_TESTING=ON`. An archive with testing disabled can build without Git. Dependency mode also needs a bootstrapped vcpkg checkout and network access. The manifest pins the vcpkg baseline to `4b089e9116ef2715919c32dd6ca3ab98bc341eb8` and includes SDL3, ImGui, spdlog and Catch2. DiligentCore is fetched separately from its official repository at commit `b036337d68be2353c9950a85929acf796b9a6d50` (v2.5.6); Git submodule revisions are fixed by that commit. DiligentCore is Apache-2.0 licensed; see its upstream repository for the license and third-party notices. D3D12 is disabled by default; Vulkan and OpenGL are not initialized by this task.

To prepare vcpkg on Windows in PowerShell (choose a directory that does not already exist):

```powershell
$env:VCPKG_ROOT = "C:/src/vcpkg"
git clone https://github.com/microsoft/vcpkg.git $env:VCPKG_ROOT
git -C $env:VCPKG_ROOT checkout 4b089e9116ef2715919c32dd6ca3ab98bc341eb8
& "$env:VCPKG_ROOT/bootstrap-vcpkg.bat" -disableMetrics
```

See [vcpkg CMake integration](https://learn.microsoft.com/en-us/vcpkg/users/buildsystems/cmake-integration) and [MinGW guidance](https://learn.microsoft.com/en-us/vcpkg/users/platforms/mingw). Default-feature Linux builds also need the relevant X11, Wayland and OpenGL development libraries and package build tools; the verification host needed Autoconf 2.71, automake, libtool and Perl modules.

## Minimal build, no dependencies

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

`pokox` exits immediately without arguments; it is not a window or engine. Pass `--build-info` to inspect the three compiled flag values.

## Dependency-enabled builds

Set `VCPKG_ROOT` to a bootstrapped vcpkg checkout. The toolchain must be specified at initial configuration; use a fresh build directory when changing toolchains or triplets. These examples are **pending verification on Windows**. CMake downloads the pinned DiligentCore repository and submodules on the first dependency-enabled configure.

### MSVC (PowerShell)

```powershell
cmake -S . -B build-msvc -G "Visual Studio 17 2022" -A x64 `
  "-DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  -DVCPKG_TARGET_TRIPLET=x64-windows -DPOKO_WITH_DEPENDENCIES=ON -DBUILD_TESTING=ON
cmake --build build-msvc --config Debug
ctest --test-dir build-msvc -C Debug --output-on-failure
```

### MSYS2 MinGW x64

Use a MinGW64 shell with its C++ compiler, CMake and Ninja, plus a bootstrapped Windows vcpkg checkout. Set `VCPKG_ROOT` to its path in the shell. MinGW triplets are community-supported; follow the upstream guide's advice about mixed MSYS2 installations and PATH.

```sh
cmake -S . -B build-mingw -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON -DPOKO_WITH_DEPENDENCIES=ON \
  -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" \
  -DVCPKG_TARGET_TRIPLET=x64-mingw-dynamic -DVCPKG_HOST_TRIPLET=x64-mingw-dynamic
cmake --build build-mingw
ctest --test-dir build-mingw --output-on-failure
```

## Remaining acceptance work

1. Run the dependency-enabled configure, build and tests above on MSYS2/MinGW and MSVC; fix and record any issues. At minimum the empty executable must build on both, as required by the queue.
2. Record toolchain versions, commands and results here and update the queue only after the Windows checks pass. The INF-03 flag contracts, INF-04 workflow, INF-05 harness and INF-06 versioning were prepared under the documented execution-order exception; both Windows CI jobs must still pass.

## INF-03 build flags

All three options default to `OFF`, independently of `CMAKE_BUILD_TYPE`. The `poko_build_options` CMake interface target supplies 0/1 compile definitions, and `pokox --build-info` reports the values compiled into the executable. Future PokoX targets that use the flags should link that interface target.

| Option | Current behavior | Not implemented yet |
|---|---|---|
| `POKO_IMGUI` | Selects the ImGui compile-time flag | The actual UI pass and release stripping are ENG-11/ENG-12; setting the flag does not initialize or link ImGui into `pokox`. |
| `POKO_DEBUG` | Selects the debug compile-time flag | Debug commands and diagnostics are future work; this flag is not automatically set by Debug builds. |
| `POKO_D3D12` | Selects the D3D12 flag, checks for a supported Windows SDK toolchain and headers, and controls DiligentCore's D3D12 configure option when dependencies are enabled | D3D12 rendering and a successful Windows SDK build have not been tested. MinGW/MSYS2 and non-Windows configurations are rejected when this option is ON. |

Example, without dependencies:

```sh
cmake -S . -B build-flags -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON \
  -DPOKO_IMGUI=ON -DPOKO_DEBUG=ON
cmake --build build-flags --config Debug
ctest --test-dir build-flags -C Debug --output-on-failure
```

On 2026-11-20, Linux GCC 11.5.0/CMake 4.4.5 builds passed for all four `POKO_IMGUI`/`POKO_DEBUG` combinations with D3D12 OFF (8 tests each). Each flag's 0/1 header branches were also compiled separately, including a platform-neutral D3D12 flag-contract test; a real D3D12-enabled configuration was not tested. Unsupported Linux `POKO_D3D12=ON` correctly failed configuration. A dependency-enabled build with `POKO_IMGUI=ON`, `POKO_DEBUG=ON` and D3D12 OFF passed 9 tests, using previously installed full-manifest dependencies and the verified pinned source checkout.

## INF-04 GitHub Actions workflow

`.github/workflows/ci.yml` runs on pushes, pull requests and manual dispatch. It defines independent Windows Server 2022 jobs for MSVC and MSYS2 MinGW64. Each fetches the project history and tags, checks out a pinned vcpkg revision, sets up Python 3.12, enables the full dependency configuration, builds Debug and runs CTest with `--no-tests=error`. The Windows jobs use D3D12 OFF and do not validate D3D12 rendering. The action references and vcpkg revision are pinned; MSYS2 package versions and the hosted runner image can still change.

The workflow passed `actionlint` 1.7.12 static validation on 2026-11-20. A Linux run using equivalent CMake/CTest flags and previously installed full-manifest dependencies passed 9 tests; it is **not** a Windows or GitHub Actions run. No GitHub repository was created or modified and no CI run has been observed. **INF-04 remains open until both Windows jobs run green on a push.**

To activate it, place the contents of the project root (including the hidden `.github` directory) at the root of the chosen GitHub repository and push a commit. Check both **Windows msvc** and **Windows mingw** results under Actions; investigate failed steps and record actual results here and in the work queue. Repository visibility and other setup decisions remain open in `repos.md`.

## INF-05 golden harness

The shared harness is `tools/testutils/harness/golden.py`, its tests are in `tools/testutils/harness/tests/`, and its own binary/PNG fixtures are in `tools/testutils/fixtures/golden/`. See the [harness README](../tools/testutils/harness/README.md) for commands, exit codes and deliberate reference updates. CTest runs the harness self-test when `BUILD_TESTING=ON`; Python is not required when testing is disabled.

Screenshot comparison is byte-exact, not pixel-based; visually identical images can differ due to encoding or metadata. On 2026-11-20, the harness passed 11 local cases, including match, intentional mismatch, missing input, explicit update and chunk-boundary cases. The dependency-free Linux CTest run passed 9 tests; the dependency-enabled Linux run passed 10, including the harness. Windows and GitHub Actions execution remain unverified.

## INF-06 build version

The version generator lives under `tools/version/cmake/`, and the integration test under `tools/version/tests/integration/`. At build time it generates `generated/poko/build_version.hpp` under the selected build directory. Run `pokox --version` to inspect the compiled value. See [version tooling](../tools/version/README.md) for exact-tag selection, `unversioned` fallback and limitations.

On 2026-11-20, Linux GCC 11.5.0/CMake 4.4.5 tests built and ran a real temporary-project executable across archive, untagged, lightweight, annotated, multiple, punctuation, UTF-8 and changed-tag cases. Make and Ninja test runs passed; the full dependency-enabled Linux CTest run passed 11 tests. An archive build without Git and with testing disabled also passed. Windows/MSVC/MSYS2 and GitHub Actions runs remain unverified.

## Character-validation regression check

On 2026-11-20, a dependency-free Linux GCC 11.5.0 / CMake 4.4.5 build passed all 12 CTest entries, including `character_uv_overlap` (seven pure-Python cases). This is not a Windows, dependency-enabled, or GPU build. See `plan/29-boyr6-character-adaptation.md` for Blender checks and outstanding asset issues.

## ENG-01 platform interface

`engine/platform/include/poko/platform/window/i_platform.hpp` defines a small backend-independent, single-window lifecycle and close/resize event contract. `poko_platform` is a header-only CMake interface target. `pokox_platform_contract` compiles the public header and tests its use through a fake backend, including initialization, invalid window sizes, events and repeated shutdown. The test double is not an OS window implementation. Input, audio, timing and native graphics-surface interoperability are explicitly deferred.

On 2026-11-20, a dependency-free Linux x64 GCC 11.5.0 and CMake 3.31.10 Debug build passed 13/13 CTest entries. Linux is the test host, not an added shipping target. MSVC, MSYS2 and Android builds have not been run for ENG-01. INF-02 and INF-04 acceptance remains outstanding. ENG-02 subsequently added an SDL window implementation; see below.

## Graphics direction (future work, not enabled)

The owner requested a Windows 11 preference for D3D12 where a supported build and device permit it, falling back to Vulkan, then OpenGL; Android 11 uses Vulkan with OpenGL ES as fallback. Successful initialization and actual feature availability must be tested; even OpenGL/ES has minimum version and hardware requirements. The existing configuration stays D3D12 OFF, including CI; no renderer, selection logic, fallback or D3D12 initialization is implemented or tested. A future Windows MSVC GitHub Actions job can test an SDK-enabled build, but compilation on hosted CI alone cannot establish GPU compatibility or runtime fallback. MSYS2 remains D3D12-disabled under the current build rules. Linux is a development/test host, not a new supported app target. See the graphics direction note in `plan/00-decision-log.md`.

## ENG-02 SDL window backend

The opt-in `POKO_WITH_SDL_PLATFORM=ON` target builds an SDL3 implementation, a blank-window demo and two CTest integration checks. It leaves the dependency-free default intact. See `../engine/platform/README.md` for build and test commands, SDL event ownership and graphics interoperability limits. The Windows GitHub Actions matrix has been configured to compile the SDL path and run its dummy tests, but has not run; D3D12 remains OFF.

On 2026-11-20, Linux x64 GCC 11.5.0, CMake 3.31.10 and SDL 3.4.20 were used. SDL was built locally from the pinned release with a reduced X11 configuration, not the full vcpkg manifest. A Debug build with `-Wall -Wextra -Wpedantic -Werror` passed **15/15** CTest entries (including the dummy video driver and failed-initialization tests). The default dependency-free build passed **13/13**. A separate virtual X11 display test created a real X11 window, requested a 704x448 resize, observed that size in the demo, sent an X11 `WM_DELETE_WINDOW` protocol message and observed a clean exit. The integration test also passed under X11; its close and quit SDL events were synthetic. These are Linux host tests, not proof of Windows/Android behavior, actual mouse clicks, GPU rendering or device-specific compatibility.

Outstanding: run the SDL build and interactive open/resize/close on Windows 11 (MSVC and MSYS2), run the prepared GitHub CI jobs, and implement/test Android SDL activity and lifecycle integration. `INF-02` and `INF-04` remain open. At the ENG-02 snapshot the window lacked graphics creation modes and native-window access. The later ENG-03 prerequisite below adds an explicit Vulkan-window request and borrowed SDL access; no Vulkan surface/device or renderer exists yet.

## ENG-01 / ENG-02 test hardening — 2026-11-20

Tests were strengthened without changing the production platform source or API.
The interface contract has expanded compile-time ownership/noexcept checks.
A new dependency-free test compiles the actual SDL backend against a controlled,
test-only SDL function double for lifecycle, failure/retry and event cases.
Its strict-warning and optimized builds pass locally, and all ten deliberately
introduced regressions were detected. The existing 23 Python checks also pass.
The real-SDL test now includes full reinitialization and destructor-only cleanup,
but those additions have not run against SDL here.

The full CMake/CTest and SDL suites could not be rerun: this host lacks CMake
and SDL3 and external package/download hosts could not be resolved. Sanitizer
execution was blocked by a missing runtime library. Do not interpret earlier
build records as fresh verification. See `eng01-eng02-hardening-evidence.txt`
for exact scope and reproduction commands. Windows, Android, real-window and
CI acceptance remain open; ENG-03 has not started.

## ENG-03 in progress — graphics-window prerequisite

The user deferred Windows/Android acceptance to the laptop and authorized
continued development. WindowConfig now supports an explicit Vulkan request
(default unchanged), IPlatform exposes actual logical/pixel dimensions, and the
SDL backend exposes borrowed native-window access for future RHI integration.
The demo has an opt-in `--vulkan` blank-window probe. This is not device/surface
initialization, rendering, fallback, or completed ENG-03 acceptance.

Current contract and backend/function-double tests pass strict warnings,
optimized builds and ASan/UBSan/leak detection. Eleven deliberate regressions
are caught; the 23 Python checks pass. Real-SDL, CMake, target-platform and GPU
validation remain pending. See `eng-progress.md` for the interface extension,
resource-lifetime obligations, evidence limits and next implementation steps.

## ENG-03 continuation — opt-in clear-color source candidate

Added a default-off `POKO_WITH_VULKAN_DEMO` option, pinned static Diligent Vulkan
integration, a PIMPL renderer and bounded desktop demo. The candidate uses
SDL native-property mappings; Android source mapping is not Android packaging.
The actual renderer/platform source and demo have only been compiled against
isolated test-owned dependency declarations here, not real SDL/Diligent SDKs.
The existing real Windows CI matrix does not enable this option yet.

The default build gains three dependency-free native-layout checks; selecting
Win32/Android layouts in these tests is not executing on those OSes. No real
CMake/CTest run, SDK compile/link, visible blue frame or validation-layer pass
is claimed. See `../engine/rhi/README.md` for unverified laptop build commands,
`eng-progress.md` for acceptance limits and `eng03-clear-seed-evidence.txt`
for the final local test record. ENG-03 and infrastructure acceptance stay open.

## ENG-03 graphics diagnostics and desktop evidence runner

The demo now captures Diligent error/fatal diagnostics and returns failure,
including for cleanup-time messages. Exclusive callback ownership and prior
callback forwarding/restoration are tested with isolated dependency doubles.
A new fresh-build laptop runner preserves build/test/runtime logs and a JSON
report that never auto-accepts the gate. Twelve evidence-handling unit tests
pass, including simulated pipeline outcomes and POSIX timeout handling. No
real CMake/CTest, SDK build, Windows/Android, GPU or layer acceptance is claimed.
See `../engine/rhi/README.md` and `eng03-diagnostics-evidence.txt`.

## Windows laptop verification — 2026-11-20 (MSYS2 UCRT64 MinGW)

First real Windows run of the pending acceptance checks. Host: Windows
laptop, MSYS2 UCRT64 g++ 16.2.0, CMake 4.4.2, Ninja, Python 3.14.7,
Vulkan SDK 1.4.363.1, AMD Radeon integrated GPU (Vulkan 1.3.260).
No working MSVC was installed (stale vswhere entries), so the MSVC leg
remains open; UCRT64 is not the CI's MINGW64 environment.

- Dependency-free build: **18/18 CTest passed.** This exposed and fixed a
  real defect — `version_integration` corrupted non-ASCII Git tags on
  Windows because `execute_process` decoded git output with the OEM
  codepage; `generate_version.cmake` now passes `ENCODING NONE`.
- Full dependency build (`POKO_WITH_DEPENDENCIES=ON`,
  `POKO_WITH_SDL_PLATFORM=ON`): vcpkg manifest installed SDL3 3.4.20,
  ImGui 1.93.0, spdlog 1.17.0, Catch2 3.16.1 and pinned DiligentCore
  b036337d; **21/21 CTest passed**, including the real-SDL dummy-driver
  and invalid-driver tests and `pokox_dependency_smoke`.
- `pokox_window_demo.exe` opened a real Windows window (interactive open
  verified; manual resize/high-DPI gestures not exercised).
- `POKO_WITH_VULKAN_DEMO=ON` required three real-dependency fixes:
  `vcpkg.json` now enables sdl3's non-default `vulkan` feature;
  `-DMINGW_BUILD=TRUE` is required for non-MinGW generator names so
  Diligent skips its DXC/atlbase path (upstream MinGW intent, now also in
  the CI mingw job); and the root CMakeLists patches a missing `<cstdint>`
  include into the pinned glslang `SpvBuilder.h` for GCC 16.
- `pokox_vulkan_clear.exe --frames 120 --adapter 0` ran on the real AMD
  Radeon GPU: **120 clear/present submissions, validation requested,
  0 captured errors, 0 warnings, exit 0.** Without `--adapter`, Diligent's
  automatic selection chose the WARP adapter and a captured Diligent
  assertion failed the run with exit 3 — the diagnostics path worked.
  `ClearConfig`/`--adapter` were added for explicit physical-device
  selection.

See `eng03-windows-laptop-evidence.txt` for exact commands and limits.
On 2026-11-21 an interactive run plus screen capture visually confirmed
the blue clear color on the AMD Radeon GPU (sRGB pixels match the
configured linear clear; 123 frames, 0 captured errors) — the ENG-03
clear-color criterion is met on Windows MinGW. Still open: MSVC leg,
first GitHub Actions run, Android, and resize recreation (ENG-05).

## Windows laptop verification — 2026-11-22 (MSYS2 UCRT64 MinGW, full demo set)

Host: same MSYS2 UCRT64 laptop, g++ 16.2.0, CMake 4.4.2. vcpkg checkout at
`~/vcpkg` (2026-10-29); manifest installed SDL3 3.4.20, ImGui 1.93.0,
spdlog 1.17.0, Catch2 3.16.1 into `vcpkg_installed/x64-mingw-dynamic`
(restored from binary cache).

- Configure used `-G "MinGW Makefiles"` (DiligentCore auto-detects MinGW
  via the generator name; the Ninja path still requires
  `-DMINGW_BUILD=TRUE` as noted above) with `POKO_WITH_DEPENDENCIES`,
  `POKO_WITH_SDL_PLATFORM`, `POKO_WITH_VULKAN_DEMO`,
  `POKO_WITH_SHADER_ARTIFACTS`, `POKO_WITH_TRIANGLE_DEMO`,
  `POKO_WITH_IMGUI_DEMO`, `POKO_WITH_CUBE_DEMO`, Debug, `x64-mingw-dynamic`
  target+host triplets.
- One interrupted parallel build left a 0-byte
  `SPIRV-Tools-opt.dir/build_module.cpp.obj`; deleting it fixed the
  `spvtools::BuildModule` link failure. No source changes needed.
- `pokox_config_logging_guard_real_test` failed on Windows because the
  test deleted its log while `std::ifstream` was still open; the stream is
  now scoped before `std::filesystem::remove`.
- **80/80 CTest passed** including all mute tests, SDL dummy-driver
  tests, shader-pipeline, triangle/cube/imgui demo input checks and
  `version_integration`.
- `pokox_vulkan_clear.exe --frames 60` and `--frames 30 --no-validation`
  both exited 0 on the real GPU, but Diligent logged a debug assertion
  `FindQueueFamily(), VulkanPhysicalDevice.cpp:435` during adapter
  enumeration on these runs — needs investigation; earlier `--adapter 0`
  runs were clean.
- `mute_evaluator_unit` previously crashed on MinGW: `feholdexcept` does
  not mask SSE exceptions there, so `FloatEnvironment` now also
  saves/masks/restores MXCSR on SSE targets.
- Still open: MSVC leg, GitHub Actions run, Android, physical-device
  gates.

## ENG-08 — experimental Vulkan triangle

An opt-in graph-driven Vulkan triangle demo now consumes the ENG-07 SPIR-V artifacts. Linux software Vulkan produced a visually checked triangle and passed a three-resize smoke test; this is not Windows GPU or validation-layer acceptance. Build and run instructions and remaining limits are in `../engine/render/README.md` and `eng-progress.md`.

## ENG-09 — experimental Vulkan depth

The opt-in desktop depth demonstration and its no-depth control are documented in `../engine/render/README.md` and `eng-progress.md`. Software Vulkan pixel tests passed; hardware and validation-layer acceptance remain open.

## ENG-10 — experimental Vulkan per-frame uniform

The opt-in depth-tested per-frame uniform demo is documented in `../engine/render/README.md` and `eng-progress.md`. Linux software Vulkan visual checks passed; target hardware and validation-layer acceptance remain open.
