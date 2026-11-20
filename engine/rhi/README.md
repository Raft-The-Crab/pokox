# RHI — experimental Vulkan clear seed

**Real Windows MinGW build and GPU smoke run recorded; visual acceptance
and MSVC/Android remain pending.** This is still not completion of the full
RHI or the clear-color gate. See `../../docs/eng03-windows-laptop-evidence.txt`.

## Included

`VulkanClearRenderer` hides Diligent types behind a PIMPL and uses the existing
SDL platform. It validates the window's Vulkan intent and nonzero pixel size,
maps native window properties, asks the pinned Diligent factory for one default
immediate context/device and a no-depth swapchain, then binds, clears and presents.
No shaders, geometry, frame graph, backend fallback or resize recreation is added.

Native bridges are implemented for Win32 HWND, Android ANativeWindow and Linux
X11 Display/32-bit XID. Linux Wayland is explicitly rejected: this pinned
Diligent NativeWindow layout has no Wayland surface field. Android bridge code
is not Android app packaging or lifecycle support; the standalone demo build is
intentionally desktop-only until an activity/native-entry-point integration exists.

## Ownership and failure behavior

- Initialize/render/shut down on the main thread. The SDL platform and window
  must outlive the renderer. Native pointers are borrowed, never destroyed here.
- Initialization is transactional: pending device/context/swapchain pointers are
  owned before success is published. Failed/throwing initialization releases them.
- Shutdown unbinds render targets, waits for the immediate context, then releases
  swapchain, context and device. It is repeatable and best-effort if idling fails.
- Zero drawable size returns `not_drawable`; the demo waits rather than presents.
- Pixel-size changes return `resize_required` before another clear. The demo
  stops with exit code 2; ENG-05 owns resize recreation.
- Window identity changes are rejected. This does not permit destroying a real
  window while GPU objects still reference it; callers must preserve lifetime.
- Diligent's clear/present calls return void. A success result means the calls
  completed, not independent confirmation of GPU execution or correct pixels.
- Validation is requested by default. Layer availability, errors reported only
  through Diligent diagnostics, and device-loss behavior need actual SDK/GPU
  verification. The demo now fails on captured error/fatal messages, including cleanup-time messages; see the diagnostics continuation below.

## Desktop laptop build (not yet verified)

Use CMake 3.28+, a C++20 compiler, Git, Python for tests, a bootstrapped pinned
vcpkg checkout as described in `../../docs/build.md`, a Vulkan-capable driver,
and validation layers for the default validation-enabled run. PowerShell/MSVC:

```powershell
cmake -S . -B build-vulkan -G "Visual Studio 17 2022" -A x64 `
  "-DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  -DVCPKG_TARGET_TRIPLET=x64-windows `
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON `
  -DPOKO_D3D12=OFF -DDILIGENT_NO_VULKAN=OFF -DBUILD_TESTING=ON
cmake --build build-vulkan --config Debug --parallel 2
ctest --test-dir build-vulkan -C Debug --output-on-failure
.\build-vulkan\Debug\pokox_vulkan_clear.exe --frames 120
```

Ensure SDL3's runtime DLL is available. Diligent Vulkan is statically linked;
no Diligent engine DLL is intentionally used. The option does not enable the
full ImGui/spdlog/Catch dependency smoke-test path, although the vcpkg manifest
may still install its declared dependencies. Keep the standalone SDL window
probe as a separate diagnostic if renderer initialization fails.

`ClearConfig::adapter_id` / `--adapter N` selects the Vulkan physical-device
index; the default `0xFFFFFFFF` keeps Diligent's automatic choice. On
multi-adapter machines the automatic choice may select a software/WARP
adapter — observed on the verification laptop, where it failed a captured
Diligent assertion while `--adapter 0` selected the real AMD Radeon GPU.

For an explicitly validation-disabled diagnostic run, use `--no-validation`.
Do not treat that as a successful validation-layer check. Omit `--frames` for
an interactive run. With a finite frame count, early close/resize returns 2;
argument errors also return 2 and initialization/backend errors return 1.
An expected run displays a blue background; submitted frames alone do not
prove visual correctness. Retain stdout/stderr, device/driver details, a
screenshot and validation output for acceptance.

### Verified Windows MinGW notes (2026-11-20)

- `vcpkg.json` enables `sdl3`'s `vulkan` feature; without it
  `SDL_WINDOW_VULKAN` is rejected at window creation.
- With Ninja (or any non-`MinGW*`) generator name, pass
  `-DMINGW_BUILD=TRUE` so Diligent skips its DXC/`atlbase.h` path, which
  MinGW cannot compile. This disables the DXC shader path only; the Vulkan
  engine itself builds. The CI mingw job passes this flag.
- GCC 16 requires a configure-time patch the root CMakeLists applies to the
  pinned glslang `SpvBuilder.h` (missing `<cstdint>`).
- Runtime needs `vulkan-1.dll` (Vulkan SDK `Bin` on PATH or alongside the
  executable) in addition to `SDL3.dll`.

The default build leaves `POKO_WITH_VULKAN_DEMO=OFF`. On a provisioned Linux
host the same option supports X11 only; Linux is not a new shipping target.
The existing Windows CI matrix does not yet opt into the real Vulkan seed.

## Reproducible dependency-free checks

```sh
python3 engine/rhi/tests/unit/run_seed_checks.py --cxx g++
python3 engine/rhi/tests/unit/run_seed_checks.py --cxx g++ --mutations
python3 engine/rhi/tests/unit/run_seed_checks.py --cxx g++ --sanitize
```

These compile the **actual renderer and platform source** against test-owned
SDL/Diligent declarations. The three native-layout branches run on the same
host; they are not Windows/Android cross-builds or OS/device tests. A fake
entry-point shim also exercises bounded demo execution and invalid arguments.
The declaration subsets are not replacements for compiling against real SDKs.

CTest registers three dependency-free renderer checks. The optional runner
also covers CLI behavior and deliberate regressions. Default CTest registration
is now expected to be 18 entries, or 20 with SDL enabled (before the full
dependency smoke-test entry); this is a static count, not a completed CTest run.
See `../../docs/eng03-progress.md` for evidence and remaining acceptance work.

## Graphics diagnostics and repeatable laptop verification

The desktop demo now owns a scoped, exclusive Diligent message callback through
renderer cleanup. Reported error/fatal diagnostics cause nonzero exit even if
the backend API returns void; warnings are counted and logged. Prior callbacks
are forwarded/restored. Counters use process-lifetime atomic storage rather
than per-scope callback pointers. Duplicate owners are rejected; unsupported
external callback replacement is detected without clobbering the new callback.
Start/stop must be serialized on the main thread and GPU resources/work must
be released before stopping diagnostics. This is not a shared callback service.

`--no-validation` changes the requested layer setting, not error handling.
Zero captured errors cannot prove layers loaded or all driver errors were
routed through this callback. Real SDK, target platform, GPU and layer behavior
still require laptop validation. Device-loss recovery remains future work.

Use the new fresh-build evidence runner on a provisioned Windows laptop:

```powershell
python engine/rhi/scripts/verify_desktop.py `
  --generator "Visual Studio 17 2022" --arch x64 `
  --toolchain-file "$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  --triplet x64-windows --frames 120
```

It configures/builds the real candidate, runs CTest and a finite smoke run,
and saves logs, JUnit output, source/binary hashes and `report.json` in a new
folder under `build-validation-results/`. Use `--output-dir` for an empty/new
custom folder and repeatable `--cmake-arg=-D...` for standalone SDL package paths.
It refuses to reuse nonempty output and applies process timeouts. Configure,
build, test, nonzero runtime and missing/malformed summary failures are preserved.
It never runs the smoke test with validation disabled. Warnings remain visible.

Even successful automation records `accepted: false`,
`visual_output_verified: false` and `validation_layer_verified: false`.
Review actual blue output, layer availability, warnings and target behavior
before closing ENG-03. No Windows run of this script occurred here: only its
unit/simulated-process tests and POSIX process-control paths were exercised.

Run evidence-handling tests without SDKs:

```sh
python3 engine/rhi/tests/unit/test_verify_desktop.py
```

Expected static CTest registration is now 18 entries, or 20 with SDL enabled,
before any full dependency smoke-test entry. These are not completed CTest runs.
