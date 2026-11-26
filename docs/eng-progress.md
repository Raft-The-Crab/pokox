# Engine milestone progress (ENG-01..22)

---

## eng03-progress

# ENG-03 — Vulkan clear seed, acceptance still open

## Status

**In progress, not accepted.** The user deferred Windows/Android checks to the
laptop and explicitly requested continued development on 2026-11-20. This is an
execution-order exception, not completion of INF-02/INF-04 or any phase gate.

**2026-11-20/21 laptop update:** the seed builds and runs on real Windows
MSYS2 UCRT64 MinGW dependencies — SDL3 with the `vulkan` vcpkg feature and
static Diligent-GraphicsEngineVk-static — and presented clear frames on
the real AMD Radeon GPU. A screen capture confirmed the blue clear color
visually (sRGB values match the configured linear clear exactly); an
interactive run submitted 123 frames with validation requested and zero
captured errors/warnings. The ENG-03 "clear color appears" criterion is
met on Windows MinGW. MSVC, Android, GitHub CI and resize recreation
(ENG-05) remain open; no phase gate is waived. See
`eng03-windows-laptop-evidence.txt` and `build.md`.

The previous graphics-window prerequisite is retained. This continuation adds
an opt-in Diligent/Vulkan clear-color source candidate and failure-path tests.
The candidate has been built against real SDL/Diligent libraries on Windows
MinGW only; MSVC, Android, and non-Windows builds remain unverified.

## Implemented source

- `VulkanClearRenderer`: transactional device/context/swapchain initialization,
  render-target binding, color clear and presentation using pinned Diligent API
  names/signatures checked against upstream headers.
- SDL-to-Diligent native mappings for Win32, Android and optional Linux X11.
  Missing pointers, invalid XIDs and unsupported window systems fail explicitly.
- Resource ownership and cleanup on partial creation, exceptions, repeated
  shutdown and destruction. GPU resources are released before SDL teardown.
- Explicit handling of zero drawable size, changed window identity, failed size
  queries, unavailable backbuffers and resize deferral to ENG-05.
- `pokox_vulkan_clear` desktop demo, blue clear, optional bounded `--frames N`
  mode, explicit `--no-validation` diagnostic flag and strict argument parsing.
- Default-off `POKO_WITH_VULKAN_DEMO` CMake option, pinned static Vulkan backend
  integration and separate dependency-free tests for three native layouts.

Only the platform and RHI code modules are involved. Existing character assets
are untouched. D3D12 preference, fallback order and all determinism gates are
unchanged; no fallback, shader, triangle, frame graph or resize implementation
is claimed. Android activity/lifecycle packaging is not implemented, and the
desktop demo configuration explicitly rejects Android.

## Evidence from this continuation

Host: Linux x64, GCC 11.5.0.

- Actual platform/renderer sources compile with strict warnings and run with
  test-owned dependency doubles for Linux, Win32 and Android native layouts.
  All three branches pass; this is not cross-platform SDK or OS validation.
- The bounded demo runs with the doubles, both with and without validation
  requested. Six invalid argument forms are rejected.
- The portable runner supports optimized, sanitizer and deliberate-mutation
  checks. See `eng03-clear-seed-evidence.txt` for final recorded outcomes.
- Existing Python regression checks: D1 reservations 5, UV overlap 7, golden
  harness 11, all pass (23 total).

The host still lacks CMake, SDL3, the Diligent checkout, a display server and
GPU/target-platform test access. Prior package/download attempts failed DNS
resolution. The web documentation reader could inspect pinned headers, but
that is not a real dependency build. CMake integration, static-library linkage,
runtime DLL deployment, validation layers, GPU output and target behavior
remain unverified.

## Important limits

Diligent clear/present APIs return void: returning success after those calls
is not independent proof of GPU success. Validation is requested by default. The demo now fails on captured error/fatal
messages, including during teardown. Actual layer availability and callback
coverage remain unverified; device-loss recovery remains unimplemented.

The renderer must be destroyed/shut down before window/platform destruction.
The identity check detects misuse while the platform object is alive; it does
not make dangling platform references or prematurely destroyed native windows
safe. At zero size the demo pauses; on changed pixel size it exits with status
2 instead of claiming ENG-05 resize support. The pinned Linux mapping is X11,
not Wayland; Android native mapping alone is not a working Android application.

## Next acceptance target

The clear-color criterion is met on Windows MinGW with visual confirmation.
Remaining work before broader acceptance: build the same path on MSVC,
run the GitHub Actions matrix, keep Android packaging as future work, and
leave ENG-04 fallback / ENG-05 resize recreation to their queue tasks.
No phase gate is waived.

Build commands, reproduction scripts and lifetime details are in
`../engine/rhi/README.md`. Retain the earlier plain-window and `--vulkan`
window-only probes as separate diagnostics.

## API references inspected

DiligentCore commit `b036337d68be2353c9950a85929acf796b9a6d50`:

- `Graphics/GraphicsEngineVulkan/interface/EngineFactoryVk.h`
- `Graphics/GraphicsEngine/interface/GraphicsTypes.h` and `DeviceContext.h`
- `Platforms/interface/NativeWindow.h` and Win32/Android/Linux native structs
- `Common/interface/RefCntAutoPtr.hpp`
- `Graphics/GraphicsEngineVulkan/CMakeLists.txt` (static target and dependencies)

Source base: https://github.com/DiligentGraphics/DiligentCore/tree/b036337d68be2353c9950a85929acf796b9a6d50
SDL property mapping: https://wiki.libsdl.org/SDL3/SDL_GetWindowProperties

## Diagnostics and laptop evidence continuation

Added scoped Diligent callback capture, demo-level error/fatal failure policy,
and a fresh-build desktop evidence runner. Creation, presentation and cleanup
errors are injected in dependency-double tests and fail instead of reporting
success. Callback ownership/restoration/forwarding, warnings, exceptions from
prior callbacks and external interference are covered. Twelve Python evidence
handling tests also pass. See `eng03-diagnostics-evidence.txt` for fresh results
and `../engine/rhi/README.md` for laptop commands. No real SDK, Windows/Android,
GPU, visual-output or validation-layer acceptance was performed here.

---

## eng04-progress

# ENG-04 — desktop fallback clear prototype (in progress)

The opt-in `pokox_fallback_clear` prototype connects Vulkan and OpenGL to the same clear-selection contract. It attempts Vulkan first, cleans it up before trying OpenGL, and uses the same linear RGBA clear value on the selected backend. `--force-opengl` bypasses Vulkan for testing. **ENG-04 is not accepted:** the same displayed color on a real fallback device has not yet been demonstrated. Android OpenGL ES and app lifecycle support are not implemented.

## Implementation and boundaries

- `ClearBackendSelection` handles startup selection, defers zero-drawable startup, refuses fallback after uncertain cleanup, and does not silently switch after a runtime error. `VulkanClearBackend` and `OpenGLClearBackend` each own their SDL window, renderer and diagnostics. Failed Vulkan startup must be cleaned up before a new OpenGL window is created. Partial Vulkan teardown is deferred until the adapter can separately detect teardown-time diagnostic errors; those errors block fallback.
- The desktop OpenGL seed uses the pinned Diligent OpenGL factory and requires OpenGL 4.6, an sRGB swapchain description and an actual sRGB default framebuffer (queried at runtime). Linux creates an SDL GLX context and supports X11 only. On Windows Diligent creates the WGL context; the SDL window is deliberately created without SDL's OpenGL flag so that Diligent can set the native pixel format. The pinned Diligent WGL version list tops out at 4.4, so the opt-in Windows build applies an anchor-checked, idempotent configure-time patch to try 4.6 and 4.5 first. **That integration and patch still require a real Windows build and driver test.** Diligent uses legacy WGL pixel-format selection, which does not guarantee an sRGB-capable default framebuffer; the prototype now rejects such a window rather than falsely claiming color parity. A target may therefore need an sRGB-capable WGL pixel-format selection path before the fallback can work. Supplying a custom `FETCHCONTENT_SOURCE_DIR_DILIGENTCORE` means this patch modifies that checkout.
- The SDL GL attributes are process-global on Linux; this prototype assumes exclusive main-thread ownership. A renderer/window must not be destroyed while graphics resources still depend on it. A cleanup failure blocks startup fallback; GL context-destroy failures may be retried, while errors during unbind/idling remain uncertain. The demo exits on unrecoverable cleanup failure and scoped destructors still run; this experimental teardown is not a device-loss recovery strategy.
- Debug error/fatal messages from the selected backend or during cleanup fail the run. Expected startup errors from an unsuccessful Vulkan attempt are not attributed to a subsequent selected OpenGL backend. A successful submit is not proof of GPU execution or displayed pixels.
- The original Vulkan-only demo remains available. No D3D12 selection, Android ES, live backend switching or device-loss recovery is implemented. ENG-05 now has experimental desktop Vulkan and OpenGL resize paths; real OpenGL resize remains unverified. See `eng-progress.md`.

## Build and run on a provisioned Windows machine

Start from the pinned vcpkg/SDK setup in `docs/build.md`, including SDL3 with its Vulkan feature and the Vulkan loader. In PowerShell using MSVC:

```powershell
cmake -S . -B build-fallback -G "Visual Studio 17 2022" -A x64 `
  "-DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  -DVCPKG_TARGET_TRIPLET=x64-windows `
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON `
  -DPOKO_WITH_FALLBACK_DEMO=ON -DPOKO_D3D12=OFF -DBUILD_TESTING=ON
cmake --build build-fallback --config Debug --parallel 2
ctest --test-dir build-fallback -C Debug --output-on-failure
.\build-fallback\Debug\pokox_fallback_clear.exe --frames 120
.\build-fallback\Debug\pokox_fallback_clear.exe --force-opengl --frames 120
```

The first command run normally selects Vulkan when available; forcing OpenGL tests the fallback implementation but is not proof that an actual Vulkan failure automatically recovers. Record startup logs, GPU/driver and validation-layer details and compare captured displayed pixels for both paths on a real device; also test a controlled Vulkan startup failure. `--no-validation` is diagnostic only. Remove `--frames 120` for an interactive run. For MinGW/Ninja follow the additional flags and runtime DLL notes in `engine/rhi/README.md`. Linux can be used as an X11 development check but is not a substitute for Windows or Android target acceptance.

## Verification and remaining work

The selector, the production adapters and the GL renderer have deterministic fault-injection tests using dependency doubles, including startup/cleanup failure and color forwarding. These do not validate GPU rendering, graphics drivers, platform window behavior, actual sRGB pixels, or Android. Local test/build results are recorded below; no release or phase gate is waived.

To complete ENG-04, build/run the actual fallback on Windows with a suitable OpenGL 4.6 device, demonstrate automatic recovery after a controlled Vulkan startup failure, compare displayed colors and capture validation evidence. Implement and test the separate Android OpenGL ES/EGL activity lifecycle path and its target fallback behavior. Resolve any target-specific defects found before claiming acceptance.

### Local regression results — 2026-11-21

Linux x64, GCC 11.5.0, CMake 3.31.10: the default Debug build passed 26/26 CTest entries; the SDL 3.4.20-enabled build passed 28/28 using SDL's dummy video driver. The new OpenGL/native-platform and demo tests use fakes, including both Win32 and Linux branches and simulated Vulkan failure. The platform and Vulkan-seed fault-sensitivity mutations were caught. The Windows WGL patch anchor matched the pinned source in a local text check; that is not a Windows build. These results are not real Win32, GLX, GPU, Android or visual validation.

At this earlier check, the fallback, Vulkan, diagnostics and demo translation units compiled as objects against real SDL and Diligent headers, but the linked graphics build and runtime had not yet completed. The later ENG-01–ENG-04 audit completed a Linux linked build and a software Vulkan smoke test; see `eng01-eng04-audit.md` for results and the unsuccessful real GL attempt.

## Android OpenGL ES primitive — 2026-11-22 (physical device, offscreen)

First real Android GPU evidence for the ENG-04 fallback direction. New files:

- `engine/rhi/include/poko/rhi/device/opengles_clear_renderer.hpp` and
  `engine/rhi/src/device/opengles_clear_renderer.cpp`: an EGL + OpenGL ES 3.2
  clear renderer over an offscreen EGL **pbuffer** surface (320x240). There is
  no ANativeWindow, swapchain, surface lifecycle or activity integration yet;
  `clear_and_present()` clears and `glFinish`es without a real present.
  Non-Android builds compile to an `unsupported_window_system` stub.
- `engine/rhi/src/device/opengles_clear_demo.cpp`: `pokox_gles_clear` clears N
  frames with the same linear color as the desktop fallback demo
  ({0.035,0.12,0.28,1}) and verifies the center pixel via `glReadPixels`.

Device run (Xiaomi 24117RN76G / tanzanite, arm64, Mali GPU, Android 15-ish,
NDK r25 `aarch64-linux-android30` clang++, `-lEGL -lGLESv3`):
`pokox_gles_clear --frames 60` submitted 60 clears and the center pixel read
back as bytes 9/31/71/255 — matching the linear clear within tolerance,
**PASS, exit 0**. The driver rejected `EGL_GL_COLORSPACE_SRGB` (no
`EGL_KHR_gl_colorspace` pbuffer support), so the framebuffer is linear and the
demo verified linear-encoded bytes; `framebuffer_is_srgb()` reports which
encoding was negotiated.

This is **not** ENG-04 acceptance: it proves a GLES 3.2 context, clear and
pixel readback work on the real Android GPU, but it is offscreen, bypasses the
`ClearBackend` selection contract, does not exercise Vulkan→ES fallback, and
has no window/swapchain/lifecycle path. Still required: ANativeWindow/EGL
surface integration (SDL Android or native activity), the ES backend behind
the same RHI contract, controlled Vulkan-failure fallback on device, and
displayed-color comparison.

## Android ES backend behind ClearBackend contract — 2026-11-22 (same session)

Added `engine/rhi/include/poko/rhi/device/opengles_clear_backend.hpp` +
`engine/rhi/src/device/opengles_clear_backend.cpp`: `OpenGLESClearBackend`
implements the shared `ClearBackend` interface (`initialize` /
`clear_and_present` / `shutdown`) over the pbuffer GLES renderer, exposing
`framebuffer_is_srgb()` and `read_center_pixel()` for evidence runs.

`pokox_gles_clear --select` now drives `ClearBackendSelection` with a stub
primary that always fails `initialize()` (standing in for a Vulkan startup
failure) and the ES backend as fallback. On-device result:

```
selection status=0 selected=2 primary_error=13 fallback_error=0
submitted 60 clear frames via fallback; shutdown ok
center pixel rgba = 0.0353 0.1216 0.2784 1.0000
expected linear bytes 9 31 71 255; PASS (exit 0)
```

This exercises the real selection contract — primary failure → fallback
initialize → clear via `owned_->clear_and_present` → verified shutdown — on
the Android GPU. Still not ENG-04 acceptance: the primary failure is
simulated (no real Vulkan attempt on device), the surface is offscreen
pbuffer (no ANativeWindow/present/swapchain), and there is no activity
lifecycle or displayed-color comparison.

## Android windowed GLES surface — 2026-11-22 (real display, physical device)

Extended `opengles_clear_renderer` with `initialize_window(ANativeWindow*, w, h)`
(EGL window surface + `eglSwapBuffers` on present) and `clear_and_verify()`
(clear → readback → swap, deterministic because post-swap back-buffer contents
are undefined). Non-windowed pbuffer path unchanged.

New `engine/rhi/src/device/opengles_native_activity.cpp`: a minimal
`android_native_app_glue` activity that waits for `APP_CMD_INIT_WINDOW`,
presents 120 clear frames on the real surface, verifies the final frame's
center pixel, writes `gles_result.txt` to the app's external files dir, holds
800 ms so the color is visible, and finishes.

Packaging is fully scripted in `engine/rhi/android/gles-clear/`:
`AndroidManifest.xml` (NativeActivity, `hasCode=false`) and `build_apk.sh`
(NDK clang .so + `libc++_shared.so` + aapt2 link + zipalign + apksigner debug
key). Two packaging lessons recorded: the APK must bundle `libc++_shared.so`,
and `-static-libstdc++` does not apply to NDK libc++.

On-device result (Xiaomi 24117RN76G, Mali GPU):

```
windowed surface: 120 frames, 2400x1080, pixel 9 31 71 255,
expected linear 9 31 71 255 -> PASS
```

This is real presented-frame evidence on the Android display path — still not
ENG-04 acceptance: the clear goes through the renderer directly (not the
`ClearBackendSelection` contract with a real Vulkan primary), there is no
Vulkan→ES fallback triggered by an actual Vulkan failure on device, no
resize/orientation lifecycle handling (configChanges are fixed for the probe),
and displayed-color comparison is readback-based, not a screen capture.

## Android Vulkan primary attempt — 2026-11-22 (physical device)

`engine/rhi/src/device/vulkan_clear_android.cpp` + `.hpp`: minimal Vulkan
clear/present renderer over `ANativeWindow` (instance + `VK_KHR_android_surface`
+ `VK_KHR_swapchain`, FIFO present, one clear render pass per frame, per-image
framebuffers/views). Non-Android builds stub to `unsupported_window_system`.

`opengles_native_activity.cpp` now runs the **real primary-first path**: Vulkan
on the ANativeWindow surface, OpenGL ES only on init failure (or a
`force_gles` flag file in the app files dir). The Vulkan attempt runs on a
worker thread with a 15 s watchdog after an earlier build ANR'd inside driver
init; a timed-out worker is intentionally leaked (probe code, documented).

On-device result (Xiaomi 24117RN76G, Mali `vulkan.mali.so` driver):

```
trying vulkan primary
vulkan primary: 4/120 frames presented on 1080x2400
```

Vulkan **works** on this device — instance, surface, device, swapchain,
render pass and FIFO present all function — but `clear_and_present` failed on
the ~5th frame (likely `VK_ERROR_OUT_OF_DATE_KHR`/suboptimal or device loss
after rotation/first real composition). Swapchain recreation on
out-of-date/suboptimal is the required next fix; after that the same probe
can demonstrate a genuine Vulkan→ES fallback by forcing a Vulkan failure.
Earlier GLES-only runs remain valid fallback evidence (120 frames, PASS).

## Android Vulkan debugging session — 2026-11-22 (continued)

Fixes applied to `vulkan_clear_android.cpp` / `opengles_native_activity.cpp`:
- `vkResetFences` before each submit (fence was never reset — spec violation,
  plausible cause of mid-run present failures).
- Swapchain recreation on `VK_ERROR_OUT_OF_DATE_KHR` from acquire AND present,
  with `poko_vulkan` logcat instrumentation on every failure path.
- Watchdog wait loop now pumps `ALooper_pollOnce` — the previous blocking wait
  was itself an ANR (confirmed via MIUIScout backtrace: main thread starved
  in `onInputQueueCreatedNative`).
- Result file moved from `/sdcard` (FUSE, can stall) to `internalDataPath`;
  manifest now `android:debuggable="true"` for `run-as` reads.

Observed on-device behavior across builds: Vulkan init+surface+swapchain+present
consistently works for ~3-7 frames before a silent failure; later builds stall
before `APP_CMD_INIT_WINDOW` entirely (native thread polls but the command
never arrives despite the window existing and the activity being resumed —
points to a MIUI/NativeActivity lifecycle interaction rather than renderer
code). GLES-only path remained PASS throughout. This remains experimental
probe code; ENG-04 is not closeable until the Vulkan frame loop survives
hundreds of presents and a real Vulkan-failure fallback is demonstrated.

## ENG-04 Android acceptance evidence — 2026-11-22 (BREAKTHROUGH)

The NativeActivity/`android_native_app_glue` probe was abandoned after repeated
MIUI lifecycle stalls (window command never delivered). Replaced with a real
Activity: `engine/rhi/android/gles-clear/PokoActivity.java` (SurfaceView +
SurfaceHolder.Callback) + `engine/rhi/src/device/poko_jni.cpp` (JNI →
`ANativeWindow_fromSurface`, render on worker thread, UI thread never blocks).

On-device results (Xiaomi 24117RN76G, Mali GPU, arm64):

```
vulkan primary: 120/120 frames on 1080x2400 -> PASS   (real Vulkan, real Surface)
gles fallback:  1080x2400 pixel 9 31 71 255 expected linear 9 31 71 255 -> PASS
               (force_gles flag file skips Vulkan → real fallback path)
```

Displayed-color validation via `adb shell screencap` during the post-frame
hold, decoded and sampled at screen center:

```
poko_vk.png   center = [9, 31, 71, 255]
poko_gles.png center = [9, 31, 71, 255]
```

Both backends present the identical clear color on the physical display —
the ENG-04 "same clear on fallback device" criterion is now evidenced on real
hardware, not just readback. Remaining honest gaps: single fixed resolution
(configChanges handled, no rotation test), no Vulkan→ES fallback triggered by
a *real* Vulkan runtime failure (fallback proven via forced skip + earlier
simulated-primary selector run), single-device evidence, and this is still
probe code — not integrated into a shipping shell (SHL-15+ remains the plan).

---

## eng05-progress

# ENG-05 — desktop resize prototype (in progress)

The owner requested development continue while personally testing ENG-04's OpenGL path. This is an execution-order exception, not acceptance of ENG-04 or a waiver of earlier infrastructure or phase gates.

## Behavior

On desktop Vulkan and OpenGL, the clear renderer compares the SDL pixel size with the swapchain, unbinds render targets and asks Diligent to resize on change. It checks the resulting dimensions and returns `resize_attempted` without submitting a frame; callers must check the graphics diagnostics before calling again. The provided demo and fallback adapter do this. Exceptions or mismatched dimensions make the renderer fail closed until shutdown. A zero-size drawable or SDL-minimized window is deferred without resize or present, including when SDL still reports nonzero dimensions; changed window identity is rejected. The selected backend is not silently switched on runtime failure.

Diligent's `Resize` returns void and its Vulkan implementation can catch errors and report them via the diagnostics callback. A matching descriptor is not proof that recreation or presentation succeeded. Callers must use an active, exclusively owned diagnostics scope and stop on errors, including errors reported after the call. `resize_attempted` is not a successful frame or visual validation. Device-loss recovery remains out of scope.

Android resize is deliberately not enabled: rotation, pre-transforms and surface/activity lifecycle require target-specific handling. The OpenGL resize implementation has only been exercised with dependency doubles, not an actual GL context or driver.

## Verification

- Linux GCC 11.5/CMake 3.31: default suite 26/26 and SDL-enabled strict-warning suite 28/28 passed. Tests use dependency doubles for graphics faults, including repeated width and height changes, zero-size deferral, resize exceptions, mismatched descriptions, sticky failure, unbinding order and an error callback without a present. The strict-warning build emitted no project compiler warnings.
- Both desktop demos compile and link against real SDL 3.4.20 and pinned Diligent on Linux. A Mesa lavapipe/Xvfb Vulkan/X11 test resized the window to 640×480, 900×650 and 720×540 and completed 1,800 submissions with zero captured graphics errors or warnings; validation was disabled and pixels were not verified. See the acceptance limitations below.
- The Vulkan native-layout fault suite runs with AddressSanitizer/UndefinedBehaviorSanitizer and mutation checks; the GL/fallback fault tests also run with sanitizers; these are function-double tests, not target GPU or visual validation.

## Target-device follow-up

1. Build the latest package using the Windows instructions in `engine/rhi/README.md`. Run `pokox_vulkan_clear` interactively (without `--frames`; use `--adapter N` if needed). With validation layers installed, drag the window repeatedly, including rapid size changes, minimize and restore, and monitor stdout/stderr. Confirm the blue clear fills the drawable without visible artifacts and that no graphics errors are reported. Save GPU/driver, toolchain and validation details plus screenshots or a recording.
2. Repeat on the Vulkan path of `pokox_fallback_clear`. Exercise the OpenGL path separately, resizing, minimizing and restoring it while checking for errors and artifacts. Test ENG-04's color and fallback separately using `eng-progress.md`.
3. Investigate Android pre-transform, lifecycle and surface recreation on a target device. Handle device loss separately.

ENG-05 is not accepted: Linux software submissions alone do not prove artifact-free rendering on Windows/Android, and real OpenGL resize remains unverified.

---

## eng06-progress

# ENG-06 — frame-graph skeleton

The owner requested the next task after the ENG-01–05 audit. Continuing implementation does not accept ENG-04/05, close the earlier infrastructure checks or waive project phase gates.

## Implemented

- A CPU-only, single-threaded `FrameGraph` under `engine/render/` registers logical resource reads/writes, explicit predecessors and callbacks. It derives edges and uses deterministic registration-order tie breaking. The required two dummy passes execute producer first even when registered consumer first.
- The whole graph is validated before execution: missing imports/producers, duplicate names/resources/writers, missing callbacks, unknown pass dependencies and cycles fail without running any pass. Duplicate edges are deduplicated. The prototype requires one writer per name and rejects read/write of the same name within a pass; callers must model versions with different names.
- `compile()` returns a non-executing plan. `execute()` revalidates, stops and reports the first callback exception and completed count, with no rollback of earlier callbacks. Graph mutation and re-entrant execution are rejected while callbacks run. Allocation failures may propagate; the graph and callback captures must outlive execution.
- The new default CMake library and CTest target are independent of SDL/Diligent. The version-integration fixture copies the new build inputs. See `engine/render/README.md` for API and limitations.

## Boundaries

This is a tested scheduling skeleton, not an integrated renderer or a complete resource graph. No GPU resource ownership, pass command context, GPU execution, transient allocation, resource barriers, read-write/present state tracking, multiple writes/versioning, asynchronous work or backend submission is implemented. The Vulkan/OpenGL demos do not yet use this graph. The narrow queue criterion is CPU dummy-pass ordering; it does not imply graphics correctness or production readiness.

ENG-04/05 and platform gates retain their previously documented unverified target-device checks. Real Windows/MSVC, Android and CI verification of the new C++ code are also outstanding.

## Verification

- Fresh Linux GCC 11.5 / CMake 3.31 Debug build with `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`: **27/27 CTests passed**. An SDL-enabled build passed **29/29** with no compiler warnings in that incremental build.
- Frame-graph tests also passed in an optimized `-O2 -DNDEBUG` build and with AddressSanitizer and UndefinedBehaviorSanitizer; eight deliberately injected scheduling, validation, reentrancy and callback-failure mutations were detected. GCC 11 `-fanalyzer` reported no warnings for the frame-graph translation unit.
- The graph target and existing demos built alongside real SDL and pinned Diligent. This only verifies coexistence/build integration; the graph is not used by those demos. That configuration still reports upstream Diligent/third-party configure-time warnings.

---

## eng07-progress

# ENG-07 — build-time GLSL to SPIR-V

The owner requested continuation after the ENG-01–06 audit. This slice implements the build-time artifact criterion, not the subsequent rendering task, and does not waive earlier device or project gates.

## Implemented

- Opt in with `POKO_WITH_SHADER_ARTIFACTS=ON` and an available host `glslangValidator`/`glslang`; the default build does not need the compiler. CMake reports the selected executable and version. No SDK is downloaded or bundled, and compiler versions are not pinned.
- The `pokox_shaders` build target compiles checked-in vertex and fragment GLSL 450 samples to Vulkan 1.1 SPIR-V in the build tree, separated by configuration. See `engine/render/README.md` for commands and cross-compilation notes.
- Inputs, rule script and compiler identity/executable are dependencies. Compilation uses a temporary file; failures remove old and temporary outputs. The rule rejects unsupported includes, including comment-separated directives and escaped-line forms, and checks lexical and existing canonical paths before removing an output or temporary file that could alias the source or compiler. If the build system fails before the rule starts (for example, a missing source dependency), an older output can still remain: only use artifacts from a successful build. Its size and magic checks are not a full SPIR-V validator.
- The integration test invokes a real host compiler in paths containing spaces, verifies headers and a source-triggered rebuild, checks compiler path changes on non-Windows hosts, and tests syntax failures, cleanup, include rejection (including disguised directives), commented-out includes and output/source/compiler collision protection, including symlinked parent paths on non-Windows hosts.

## Verification and boundaries

On Linux, glslang 14.3.0 produced vertex and fragment SPIR-V. Both particular artifacts passed a separate SPIRV-Tools Vulkan 1.1 validation; that independent local check is not a validation stage installed in the build pipeline. Shader-enabled, default and SDL audit suites are summarized in `eng01-eng06-followup-audit.md`.

At the ENG-07 milestone no runtime shader loading or GPU rendering was implemented. ENG-08 subsequently added an experimental Vulkan triangle demo; see `eng-progress.md`. General shader reflection, include dependency tracking, shader variants and OpenGL/ES translation remain unimplemented. Windows/MSVC, Android and actual GPU visual acceptance remain unverified, as do the earlier OpenGL fallback and resize checks. Do not treat offline artifacts as evidence of a rendered triangle.

---

## eng08-progress

# ENG-08 — forward-pass colored triangle

The owner requested the next task. This is an experimental Vulkan implementation, not a waiver of earlier phase or target-device acceptance gates.

## Implemented

- `POKO_WITH_TRIANGLE_DEMO=ON` is opt-in and requires the existing SDL, Vulkan-demo and build-time shader options. `pokox_triangle` loads the ENG-07 vertex/fragment SPIR-V artifacts and renders a procedural RGB triangle on a blue background. It does not require a vertex buffer or depth attachment.
- The demo registers a `forward triangle` frame-graph node with a logical `swapchain color` output; the callback invokes the Vulkan RHI pass to clear, draw and present. The graph is a CPU scheduler, not a resource allocator, barrier planner or general GPU executor. Diligent performs the actual target transitions.
- The Vulkan seed exposes a guarded draw callback, retaining its existing drawable and desktop-resize checks. Callback failure/exception prevents present; nested drawing and shutdown during the callback are rejected. Pipeline/shader creation and graphics diagnostics are checked; the triangle pipeline is released before renderer/window teardown. A configured format change triggers pipeline recreation.
- Invalid, missing, misaligned-size or oversized shader inputs are rejected before window setup. This is basic size/magic checking, not full SPIR-V validation. Only consume artifacts from a successful build.

## Verification — Linux development host

- Actual SDL 3.4.20 and pinned Diligent Vulkan backend: the complete build and **33/33 CTests passed**, including demo argument/shader-input tests and previous engine regressions. Project incremental build emitted no compiler warnings; the pinned third-party Diligent configuration still emits upstream CMake policy/deprecation and optimization warnings.
- A separate strict-warning (`-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`) compile check passed for the three new/changed renderer source files against the real SDK; the SDL/shader strict-warning regression suite passed **30/30**. Vulkan/frame-graph/OpenGL-double sanitizer checks passed **7/7**. Doubles are not platform or GPU acceptance tests.
- On Xvfb with Mesa lavapipe software Vulkan, the real demo submitted **1,800 frames**, with zero captured Diligent errors/warnings, while the window was resized to 640×480, 900×650 and 720×540. The saved screenshot `eng08-software-vulkan.png` shows the final resized image; sampled red, green, blue and background pixels were checked by `engine/render/tests/integration/test_triangle_x11_visual.py`. Validation layers were explicitly disabled. This is software-rendered Linux/X11 evidence, not Windows, hardware, OpenGL, or validation-layer evidence.

## Reproduction and remaining work

See `engine/render/README.md` for build and run commands. The optional Linux visual test needs a dedicated X11 display, X11 libraries, ImageMagick `import`, Pillow and a working Vulkan device or software ICD; it manipulates the demo window and should not run on a shared desktop. For example, with an isolated display already configured:

```sh
python3 engine/render/tests/integration/test_triangle_x11_visual.py \
  --exe ./build-triangle/pokox_triangle \
  --vertex ./build-triangle/shaders/Debug/triangle.vert.spv \
  --fragment ./build-triangle/shaders/Debug/triangle.frag.spv \
  --screenshot ./triangle-smoke.png
```

Windows/MSVC, the owner's Windows GPU, Android, real OpenGL/ES fallback and validation-layer execution remain unverified for this triangle. The software screenshot is not proof of artifact-free behavior on a target display. Depth testing is ENG-09; there is no depth buffer in ENG-08. Device loss, shader reflection/permutations, graph-managed resources/barriers and production recovery are still open.

---

## eng09-progress

# ENG-09 — experimental Vulkan depth test

The owner requested a review of ENG-01–08 followed by the next task. The review is in `eng01-eng08-review.md`. ENG-09 now has a desktop Vulkan prototype; its target-device and phase acceptance remains open.

## Implementation

- With `POKO_WITH_DEPTH_DEMO=ON` and the existing Vulkan and shader options, `pokox_depth` creates a D32 float swapchain depth attachment. If the depth view or format is missing, drawing fails rather than silently proceeding without depth. Device/driver support for this format is required; no alternative format selection is implemented.
- The graph-driven pass clears depth to 1.0, enables depth writes and `LESS` testing, and draws a near red triangle at depth 0.2 **first**, then a farther green triangle at depth 0.8. The red triangle should remain visible where they overlap. `--show-no-depth` deliberately disables depth testing and writes as a negative control: green then overwrites the same overlap. This is not a new general material or scene renderer.
- The depth and color resource names are logical frame-graph outputs only. Diligent and the swapchain own actual resource creation and transitions. Pipeline caching is scoped to the device and formats; destroy the pass before renderer shutdown. The default clear and triangle demos retain their original no-depth behavior.
- `depth.vert` and `depth.frag` compile as separate Vulkan 1.1 SPIR-V artifacts; pass the matching depth pair, not the triangle shaders. Artifact loading checks the header/size only, not shader interfaces or full module semantics.

## Verification on Linux

- The actual SDL/Diligent build passed 37/37 CTests with no warnings in the incremental build. The separate strict-warning SDL/shader baseline passed 31/31 CTests. A focused address/undefined-behavior sanitizer selection passed 8/8. Production sources and the new test were also checked with `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`. Vulkan 1.1 SPIR-V semantic validation passed for both generated depth shader artifacts. Third-party configuration warnings and tests based on doubles do not establish target-device acceptance.
- Mesa lavapipe software Vulkan on isolated X11/Xvfb: the triangle, depth and no-depth-control runs each submitted 1,800 frames and survived 640×480, 900×650 and 720×540 resizes, with zero captured Diligent errors and warnings. With depth enabled, sampled near/far/overlap pixels were red/green/red; with depth disabled they were red/green/green. The final window captures are `eng09-software-vulkan.png` and `eng09-software-vulkan-control.png`.
- `engine/render/tests/integration/test_triangle_x11_visual.py` checks these samples and window sizes. This isolated-display test needs X11, ImageMagick `import`, Pillow and a working Vulkan ICD. It explicitly passes `--no-validation`; therefore it is not Vulkan validation-layer evidence or Windows/hardware acceptance. X11 capture samples pixels from the displayed window, not a GPU readback or a full-image correctness proof.

## Running and remaining work

See `engine/render/README.md` for build and execution examples, including Windows. Use the depth demo with validation enabled by default where the validation layers are installed; do not treat `--no-validation` as validation evidence. Verify the near red triangle remains in front on the intended Windows GPU, compare with `--show-no-depth`, resize the window, and inspect graphics errors/warnings.

Hardware/Windows/MSVC, Android, OpenGL/ES, validation-layer, device-loss and production-lifecycle acceptance remain open. This is not the full rendering engine. ENG-10 (per-frame uniform buffer) remains the next planned task and was not implemented here.

---

## eng10-progress

# ENG-10 — per-frame uniform buffer prototype

The owner requested ENG-10. The implementation is an opt-in desktop Vulkan demonstration, not a production-wide uniform system or a waiver of outstanding ENG-01–09 acceptance gates.

## Implementation

- `POKO_WITH_UNIFORM_DEMO=ON` builds `pokox_uniform` and the matching `uniform.vert.spv` and `uniform.frag.spv` artifacts. It requires the existing Vulkan and shader build options. The shader pair is specific to this demo; it requires a pixel-stage `FrameData` uniform block containing one std140 `vec4` (four 32-bit floats).
- A Diligent dynamic uniform buffer is created with CPU write access, bound through a static pipeline variable and shader-resource binding, and mapped using write/discard on each drawable frame. The pass writes a time-varying color, unmaps, binds the pipeline and commits the resource before drawing. Diligent owns backing allocation/renaming and transitions. Missing depth or uniform resources, failed mapping and captured graphics errors prevent presentation. The renderer still owns resize handling, and pipeline recreation rebuilds the associated uniform buffer and binding.
- ENG-09 depth remains enabled: the near triangle is submitted first and gradually changes red-to-blue-to-red over four seconds; the far green triangle is submitted second and must remain behind it. The frame graph still tracks only logical color/depth writes; it does not manage real GPU resources or implement a general graphics executor. ENG-08/09 demos remain separate.
- Destroy the pass before renderer shutdown; do not reuse it after a renderer restart or across devices. Current SPIR-V loading checks size and magic only, not full shader validity or interface compatibility.

## Verification — Linux development host

- Real SDL/Diligent build: **40/40 CTests passed**. The strict SDL/shader baseline passed **31/31**. The frame-graph and backend/failure-test ASan/UBSan selection passed **8/8**. Production renderer/demo translation units and the control-flow test passed `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`. The incremental project build reported no compiler warnings; third-party configuration/build warnings may still occur.
- Both produced uniform SPIR-V modules passed Vulkan 1.1 semantic validation. Test doubles cover two distinct per-frame payloads, buffer reuse, format-change recreation, explicit depth state, and injected creation/binding/map/unmap/commit failures. Double tests are not device/driver acceptance.
- Isolated X11/Xvfb with Mesa lavapipe software Vulkan: the demo submitted **2,400 frames**, resized to 640×480, 900×650 and 720×540, and reported zero captured Diligent errors/warnings. Eight displayed-window pixel samples showed red and blue channels changing over time while the near and overlap pixels matched and the far triangle stayed green. `eng10-software-vulkan-red.png` and `eng10-software-vulkan-blue.png` are selected captures. This is sampled display evidence, not exhaustive image or GPU-memory readback validation.
- The existing triangle, depth and no-depth-control visual regressions also passed after the change. Supplying valid depth shaders without the required uniform block caused the uniform demo to fail before presenting a frame.
- The visual test explicitly disables Vulkan validation layers. Linux software output is not Windows/hardware, validation-layer, OpenGL/ES or Android evidence.

## Reproduce / open work

See `engine/render/README.md` for Linux and Windows build/run commands. On the target GPU, run without `--no-validation` when validation layers are installed; observe the near triangle cycling red/blue while remaining in front of the green triangle, resize the window, and check captured warnings/errors. Confirm actual GPU and validation-layer results rather than assuming software results transfer.

No Android or OpenGL/ES uniform path, GPU device-loss recovery, shader-interface reflection, general per-frame constants allocator, reusable material system or multi-frame resource synchronization policy is claimed. These remain future production work. ENG-11, the ImGui frame-graph pass, is the next queued task and is not included here.

---

## eng11-progress

# ENG-11 — ImGui pass in the frame graph

The owner requested ENG-11 after ENG-10. This is an opt-in desktop Vulkan prototype, not a production UI system or a waiver of outstanding ENG-01–10 acceptance gates.

## Implementation

- `POKO_WITH_IMGUI_DEMO=ON` builds `pokox_imgui_demo` plus the `imgui.vert`/`imgui.frag` SPIR-V artifacts through the existing ENG-07 host-glslang path. It requires `POKO_WITH_DEPENDENCIES=ON` (the `imgui` vcpkg package), `POKO_WITH_VULKAN_DEMO=ON` and `POKO_WITH_SHADER_ARTIFACTS=ON`. Dear ImGui 1.93.0 core is used; no platform/renderer backend ships with the vcpkg port, so the demo feeds `ImGuiIO` display size, delta time and mouse state directly from SDL.
- `engine/rhi/include/poko/rhi/device/vulkan_imgui_pass.hpp` + `src/device/vulkan_imgui_pass.cpp` add `VulkanImGuiPass`, which uploads and draws the current `ImGui::GetDrawData()` through Diligent inside an already-acquired frame. It does not clear, acquire or present. Only the Dear ImGui font atlas texture is supported; commands referencing any other `ImTextureID` fail rather than binding an arbitrary texture, and draw callbacks other than `ImDrawCallback_ResetRenderState` are rejected.
- The font atlas is built on the CPU before the first `NewFrame` (ImGui asserts `TexIsBuilt` otherwise); the pass uploads the cached RGBA32 pixels once as an immutable `TEX_FORMAT_RGBA8_UNORM` texture with a linear/clamp sampler attached to the texture view for the combined image sampler. A 16-byte dynamic uniform buffer carries the display-to-clip transform, refreshed per frame. Vertex/index data is streamed into dynamic vertex/index buffers that grow on demand; `ImDrawIdx` is 16-bit (`VT_UINT16`) and `BaseVertex` is `list base + cmd.VtxOffset`, matching official backend behavior for both `RendererHasVtxOffset` modes. Scissor rects come from `ImDrawCmd::ClipRect` scaled by `FramebufferScale`; alpha blending is enabled and depth is detached for the UI subpass.
- `VulkanTrianglePass` gained non-presenting `draw(device, context, chain, target[, color])` overloads so several passes can composite inside one `draw_and_present` callback; `draw_and_present` behavior is unchanged.
- The demo's frame graph has two nodes: `ui imgui` (CPU pass: SDL-fed IO update, `NewFrame`, demo window, `Render`; writes the logical `imgui draw data` resource) and `forward frame` (reads `imgui draw data`, writes `swapchain color`; its callback runs the triangle scene draw then the ImGui draw inside one acquire/present). The graph orders the UI frame before the composite GPU frame. The demo window shows FPS, a checkbox and instructions; the window is draggable with the mouse.

## Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon iGPU)

- `POKO_WITH_IMGUI_DEMO=ON` configure + `pokox_imgui_demo` build: clean, no warnings in the new translation units.
- Real run, `--frames 120 --adapter 0 --no-validation`: `POKO_IMGUI_RESULT submitted=120 validation_requested=false graphics_errors=0 graphics_warnings=0` on the AMD Radeon GPU. The triangle scene renders with the ImGui demo window composited on top.
- **Visual acceptance (owner-verified on the Windows AMD GPU):** the "PokoX ImGui demo" window renders at the top-left above the triangle, is readable, draggable and resizable. Two rendering bugs were found and fixed during bring-up: (1) the `LayoutElement` aggregate initializers omitted the leading `HLSLSemantic` field, shifting every vertex-layout field by one and producing a corrupt input layout that silently rasterized nothing; (2) the display→clip transform initially copied `imgui_impl_vulkan`'s raw Vulkan y convention, but Diligent's swapchain presents y-up, so the UI rendered vertically flipped at the bottom — the y scale/translate are now negated accordingly. The scene shaders (`triangle`/`depth`/`uniform`) were also flipped at the owner's request to match the conventional orientation, and the X11 visual-test pixel samples were mirrored to match.
- After the fixes, `--frames 60` **with validation requested**: `submitted=60 graphics_errors=0 graphics_warnings=0`, and `ctest -R "imgui|triangle"`: 9/9 pass including `pokox_imgui_demo_missing_shader`, `pokox_imgui_demo_bad_args` and `pokox_imgui_demo_inputs` (bad SPIR-V rejected before window creation).
- With validation requested (`--frames 60`), the run initially reported `VUID-vkAcquireNextImageKHR-semaphore-01779`. Root cause: Diligent's swapchain acquire-fence wait bounds pending *acquires*, not the semaphore's pending *wait* operation inside the submitted command buffer, so a fast CPU can reuse the acquire semaphore while the GPU still waits on it. `VulkanClearRenderer` now calls `ISwapChain::SetMaximumFrameLatency(1)` at init and, only when validation is enabled, `IDeviceContext::WaitForIdle()` before each acquire — validation runs are diagnostic, so the synchronized path is acceptable there while the default fast path is unchanged. After the fix, `pokox_triangle` and `pokox_imgui_demo` each complete `--frames 60` with validation requested, 0 graphics errors/warnings. This also repairs the same latent race in the ENG-03/08/09/10 demos under validation; the fakes gained the new interface methods.
- ImGui draw-data indexing was verified empirically against ImGui 1.93.0 (`VtxOffset`/`IdxOffset`/`ElemCount`, `ImTextureRef`/`SetTexID`) before implementing the upload path.

## Reproduce / open work

```sh
cmake -B build-imgui -G Ninja -DCMAKE_TOOLCHAIN_FILE=<vcpkg>/scripts/buildsystems/vcpkg.cmake \
  -DPOKO_WITH_DEPENDENCIES=ON -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON \
  -DPOKO_WITH_FALLBACK_DEMO=ON -DPOKO_WITH_SHADER_ARTIFACTS=ON \
  -DPOKO_WITH_TRIANGLE_DEMO=ON -DPOKO_WITH_DEPTH_DEMO=ON -DPOKO_WITH_UNIFORM_DEMO=ON \
  -DPOKO_WITH_IMGUI_DEMO=ON
ninja -C build-imgui pokox_imgui_demo
./build-imgui/pokox_imgui_demo --vertex build-imgui/shaders/Debug/triangle.vert.spv \
  --fragment build-imgui/shaders/Debug/triangle.frag.spv \
  --imgui-vertex build-imgui/shaders/Debug/imgui.vert.spv \
  --imgui-fragment build-imgui/shaders/Debug/imgui.frag.spv --adapter 0
```

Keyboard/text input, gamepad, multi-texture `ImTextureData` updates, `ImGuiBackendFlags_RendererHasTextures`, multi-viewport, backend-owned platform texture management, OpenGL/ES and Android ImGui paths, device-loss recovery and the ENG-12 F1 toggle/release strip are not implemented. The frame graph remains CPU-only; `imgui draw data` is a logical ordering token, not a managed GPU resource. Target-device, validation-layer, MSVC and Android acceptance remain open, as do all prior infrastructure and phase gates. ENG-12 (ImGui F1 toggle and release strip) is the next queued task and is not included here.

---

## eng12-progress

# ENG-12 — ImGui F1 toggle and release strip

Built on ENG-11. Acceptance from the queue: *"Debug shows UI, release has no ImGui symbols."*

## Implementation

- `POKO_DEBUG` is the switch (it already existed as "compile debug-only feature paths" and is propagated as `POKO_DEBUG=0/1`).
- **F1 toggle (debug only):** the `ui imgui` frame-graph pass polls `SDL_GetKeyboardState` for `SDL_SCANCODE_F1` each frame and toggles `ui_enabled` on the rising edge, printing `ImGui UI shown/hidden (F1).` to stdout. When hidden, the pass still runs `NewFrame`/`Render` with no windows, so `ImGui::GetDrawData()` is empty and `VulkanImGuiPass::draw` early-outs — no stale draw data is ever presented.
- **Release strip:** `imgui_demo.cpp` wraps every ImGui include, context, IO update, window builder and pass registration in `#if POKO_DEBUG`. CMake compiles `vulkan_imgui_pass.cpp` and links `imgui::imgui` only when `POKO_DEBUG=ON`. In strip mode the graph is a single `forward frame` pass (scene only), `--imgui-*` args are still accepted for interface compatibility but unused, and the demo prints "release strip" at startup. `composite` guards the `ui->draw` call with `#if POKO_DEBUG` so no `VulkanImGuiPass` symbol is referenced.
- Note: `POKO_DEBUG` is defined as `0`/`1`, so `#if` (not `#ifdef`) is required — matching `poko/foundation/build_flags.hpp`.

## Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon)

- `POKO_DEBUG=ON` configure + `pokox_imgui_demo` build: clean.
- Strip proof, two levels: (a) `imgui_demo.cpp` compiled with `-DPOKO_DEBUG=0` and no ImGui/Diligent include paths succeeds and `nm` shows 0 ImGui symbols; (b) a dedicated `pokox_imgui_demo_strip` target (same sources, `POKO_DEBUG=0`, no `vulkan_imgui_pass.cpp`, no `imgui::imgui` link) builds, links — impossible if any ImGui symbol were referenced — runs `--frames 30` clean (`submitted=30, graphics_errors=0`), and `nm -C` on the exe reports **0 `ImGui::` symbols**.
- F1 toggle verified by owner on the AMD GPU during ENG-11 bring-up; the ENG-12 refactor kept the same code path (scancode edge detection inside the `ui imgui` pass) and the debug exe runs clean — interactive F1 re-press not re-tested after refactor (low risk).
- `ctest -R imgui_demo`: 6/6 pass — missing-shader, bad-args and inputs tests now run against **both** `pokox_imgui_demo` and `pokox_imgui_demo_strip`.

## Reproduce / open work

```sh
# Debug (UI + F1):
cmake -B build-imgui -DPOKO_DEBUG=ON # plus the ENG-11 option set
ninja -C build-imgui pokox_imgui_demo
./build-imgui/pokox_imgui_demo --vertex ... --fragment ... --imgui-vertex ... --imgui-fragment ... --adapter 0

# Release strip check:
g++ -std=c++20 -DPOKO_DEBUG=0 -Iengine/render/include -Iengine/rhi/include \
  -Iengine/platform/include -I<vcpkg-include> -c engine/render/src/passes/imgui_demo.cpp -o strip.o
nm -C strip.o | grep -i imgui   # expect no output
```

Keyboard/text input beyond F1, mouse wheel, gamepad, multi-texture `ImTextureData` updates, `ImGuiBackendFlags_RendererHasTextures`, multi-viewport, OpenGL/ES and Android ImGui paths, device-loss recovery, MSVC/CI and Android acceptance remain open, as do all prior infrastructure and phase gates. A full strip-configure CTest leg (POKO_DEBUG=OFF end-to-end) is not yet wired; the object-level proof above is the current evidence.

---

## eng13-progress

# ENG-13 — Structured logging with file sink

Acceptance: *"Log file with timestamps."*

## Implementation

- New `poko_logging` STATIC library (`engine/foundation/`), built only under `POKO_WITH_DEPENDENCIES` since it wraps spdlog (already a vcpkg dependency).
- `poko/foundation/logging.hpp`: `init(Config{file_path, level, echo_to_console})`, `shutdown()`, and level functions `trace/debug/info/warn/error/critical(category, message, fields)`.
- Each record renders as `[YYYY-MM-DD HH:MM:SS.mmm] [level] [poko] category: message key=value ...` via an fmt pattern on a `basic_file_sink_mt` (truncate-on-open) plus optional `stdout_color_sink_mt` echo.
- Structured fields are `key=value` pairs appended to the message — deliberately simple; CBOR/JSON structured sinks are ENG-14+ territory.
- Thread-safe init/shutdown via mutex; calls before `init` or after `shutdown` are dropped (checked via an explicit `g_initialized` flag — `spdlog::default_logger()` auto-creates a console logger, so it cannot be used as the guard).
- Double `init` returns `errc::device_or_resource_busy`; sink/logger failures return `errc::io_error`. Re-init after `shutdown` drops the stale named logger (`spdlog::drop("poko")`) since `spdlog::shutdown()` flushes but does not unregister.

## Verification — Windows laptop (MSYS2 UCRT64)

`pokox_logging_file_test` (CTest): writes `%TEMP%/poko_eng13_logging/engine.log`, asserts ≥4 timestamped lines via regex `\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d+\]`, asserts category/field content, double-init rejection, and re-init after shutdown. **PASS**; sample line:

```
[2026-11-21 12:35:32.584] [debug] [poko] rhi: device created adapter=0 api=vulkan
```

## Reproduce / open work

```sh
cmake -B build-full -DPOKO_WITH_DEPENDENCIES=ON # plus prior options
ninja -C build-full pokox_logging_file_test && ./build-full/pokox_logging_file_test.exe
```

Not yet wired into engine subsystems (RHI/platform call sites) — ENG-14 (CBOR config) will consume settings such as log level/path. Async/file-rotation sinks, per-category levels, O(1) structured (CBOR) output, log shipping, MSVC/CI and Android legs remain open.

---

## eng14-progress

# ENG-14 — CBOR config loader

Status: implemented and verified on Windows (MSYS2 UCRT64, GCC 16, Ninja).

## What was built

- `engine/foundation/include/poko/foundation/cbor.hpp` + `src/cbor.cpp` —
  dependency-free decode-only CBOR data model (spec 21 assigns CBOR
  serialization to foundation). Supports uint/nint/bytes/text/array/map/
  bool/null/half/float/double. Rejects tags, indefinite lengths, reserved
  argument forms, trailing bytes, invalid UTF-8, nesting > 32 and > 262144
  values. Container reserves are capped at the remaining input so a hostile
  length header cannot over-allocate. Never throws.
- `engine/foundation/include/poko/foundation/config.hpp` + `src/config.cpp` —
  `EngineConfig` + `load_file(path)` + `resolve(path, overrides)`:
  top-level `window` (width/height), `graphics` (adapter_id, validation) and
  `logging` (level, file, echo) sections, all optional with defaults. Wrong
  types, non-map sections, zero window dimensions and unknown level names
  fail the load; unknown keys are reported (`section.key`) not fatal. Files
  capped at 1 MiB. `resolve()` merges explicit CLI overrides over file
  settings (CLI wins for validation/adapter; window/logging are file-only).
- `engine/foundation/include/poko/foundation/config_logging.hpp` —
  `config::LogGuard` RAII bridge to ENG-13 logging; a no-op unless the
  target defines `POKO_ENGINE_LOGGING=1` and links `poko_logging`.
- `poko_config` CMake target (always built, no dependencies).
- `--config file.cbor` on every runnable engine demo:
  `pokox_vulkan_clear`, `pokox_triangle`/`pokox_depth`/`pokox_uniform`,
  `pokox_imgui_demo`/`pokox_imgui_demo_strip`, `pokox_fallback_clear`
  (and the dependency-free `pokox_fallback_demo_double` test binary).
  Window size, adapter_id and validation come from the file; explicit CLI
  flags still win. `logging.file` initializes ENG-13 logging where
  `poko_logging` is linked.
- `VulkanClearBackend`/`OpenGLClearBackend` gained defaulted
  adapter/width/height parameters (source-compatible) so the fallback demo
  honors file settings.

## Verification

- `pokox_config_file_test` (both build trees): decoder edge cases
  (argument widths, negatives, floats, nesting, truncation, reserved/
  indefinite forms, UTF-8, depth/value caps) and config accept/reject/merge
  paths (full, partial+unknown keys, wrong types, zero size, bad level,
  bad section, bad root, malformed CBOR, missing file, CLI-override wins,
  empty-path defaults).
- `build/` 24/24 and `build-full/` 29/29 targeted CTest pass.
- End-to-end on the AMD GPU: `pokox_vulkan_clear` and
  `pokox_fallback_clear --frames 5 --config x.cbor` both applied
  `validation=false` from the file (`validation_requested=false`) and wrote
  the structured `config: settings loaded` record to the configured log.

## Defects found by the new tests during implementation

- Major-7 items consumed their float payload twice (argument reader ran
  before the simple/float branch) — floats decoded as truncated.
- `half_to_double` used the single-precision exponent bias (exp-25)
  instead of 15 — all half floats decoded wrong.
- Unimplemented simple values were reported `malformed` instead of
  `unsupported`.

## Not done / future

- No CBOR *encoder* yet — ENG-36 (schema versioning/migrations) and asset
  manifests will need canonical encoding; the decoder is ready for it.
- `pokox` and `pokox_window_demo` do not consume config yet (no settings
  surface to apply).
- OpenGL backend ignores `adapter_id` (GL has no adapter selection); the
  Vulkan fallback path honors it.

## Integration review, 2026-11-22

The configuration loader now catches allocation failures at its public boundary. Allocation-fault coverage was added; see `project-review-2026-11-22.md` for limitations.

---

## eng15-progress

# ENG-15 — Frame timing and stats

Status: implemented and verified on the AMD GPU (Windows, MSYS2 UCRT64).

## What was built

- `engine/foundation/include/poko/foundation/frame_stats.hpp` +
  `src/frame_stats.cpp` — `poko::stats::FrameStats`: dependency-free rolling
  statistics. `record_cpu()` once per presented frame, `record_gpu()` as
  duration-query results land; 120-sample windows give `cpu_ms()`, `gpu_ms()`
  and `fps()`. NaN/inf/negative samples are rejected.
- `pokox_frame_stats_test` (both trees): means, FPS, window wraparound,
  independent CPU/GPU windows, invalid-sample rejection.
- `pokox_imgui_demo` (+ `_strip`):
  - CPU frame time measured around `graph.execute()` (event poll + passes +
    submit).
  - GPU frame time via a lazily created Diligent `QUERY_TYPE_DURATION` query
    bracketing the scene+ImGui composite in `composite()`. A
    `DurationQueryState` gate allows only one outstanding query: `BeginQuery`
    is skipped while a previous result is still pending, and `GetData` is
    polled only then, so Diligent never discards an uncollected sample.
    Devices without `DurationQueries` support keep `gpu_ms()` at 0.
  - The ImGui demo window shows `CPU: x.xx ms   GPU: x.xx ms` alongside FPS.
  - `POKO_IMGUI_RESULT` now reports `cpu_ms=`/`gpu_ms=` averages.

## Verification

- `pokox_frame_stats_test` passes in `build/` and `build-full/`.
- Both trees build clean; `build/` 25/25 and `build-full/` 30/30 CTest pass.
- End-to-end on the AMD GPU:
  `pokox_imgui_demo --frames 120` →
  `POKO_IMGUI_RESULT submitted=120 ... cpu_ms=14.68 gpu_ms=0.25` — the
  duration query reports real GPU frame time and the ImGui window shows it.
- Note: Vulkan device init intermittently tripped a Diligent debug
  assertion (`FindQueueFamily` granularity VERIFY, VulkanPhysicalDevice.cpp:435)
  during this session — a transient driver/enumeration state, not a code
  defect; `--adapter 0` runs cleanly.

## Not done / future

- Per-pass GPU timings (ENG-44 builds on this: timestamps, validation
  layers, profiler ring per ENG-100).
- CPU stats are only wired into the ImGui demo; other demos can adopt
  `FrameStats` as the engine loop stabilizes.
- GPU timer measures the whole composite (scene + UI), not per-pass.

---

## eng16-progress

# ENG-16 — Asset handle with refcount

Status: implemented and verified in both build trees.

## What was built

- `engine/resource/include/poko/resource/asset_store.hpp` +
  `src/asset_store.cpp` — `poko::resource`, dependency-free, single-threaded
  (ENG-17 owns the async load queue later):
  - `AssetStore::acquire(key, loader, error)` — first acquire (or first after
    full release) invokes the loader once; concurrent holders share one
    type-erased `AssetPayload` (`shared_ptr<void>`). Loader failure
    (empty key, null/throwing loader, null payload) returns an invalid
    handle with an error string; no resident entry is left behind.
  - `AssetHandle` — RAII copyable/movable guard. Copies share the entry
    refcount; the last release erases the entry and destroys the payload.
    Handles keep the store `State` alive via `shared_ptr`, so they are safe
    after the `AssetStore` object is destroyed.
  - Diagnostics: `resident_count()`, `load_count()`, `unload_count()`.
- `poko_resource` CMake target (always built) + `pokox_asset_store_test`
  (both trees): shared acquire, copy/move ownership, failure paths,
  store-teardown safety, and a 1000-cycle leak-balance check.

## Defect found by the new test during implementation

`AssetHandle::operator=` called `this->~AssetHandle()` explicitly — which
runs the *full* destructor including member destruction — then assigned
into the destroyed `state_`/`key_` members. Result: double-release of the
`State` control block (use_count went negative → heap-use-after-free,
observed as `0xfeeefeee` freed-memory reads and SIGSEGV in
`unordered_map::find`). Fixed by extracting a `release()` helper that only
decrements the entry refcount; `~AssetHandle()` and both assignment
operators now call it instead of the explicit destructor.

## Audit round 2 — additional defects found and fixed

- **Re-entrant loader use-after-free**: `acquire()` held an
  `unordered_map` element reference across the `loader(key)` call; a loader
  that recursively acquires assets can rehash the map and dangle it.
  Restructured: fast-path `find` for live entries, loader runs with no map
  reference held, entry re-found afterwards.
- **Copy-assign exception safety**: `key_ = other.key_` (can throw
  `bad_alloc`) ran after `state_` was overwritten, leaving a mismatched
  state/key pair. Now copies the key first, then releases, then assigns
  (shared_ptr assign is noexcept).
- **Moved-from `AssetStore` crash**: default move leaves `state_` null;
  `acquire()` now lazily re-initializes and the counters return 0.
- **`error` out-param** is now cleared on entry so stale text can't mislead.
- **`version_integration` regression (since ENG-14)**: the test copies a
  fixed source manifest; unconditional `poko_config`/`poko_stats`/
  `poko_resource` libraries referenced files absent from it. Manifest
  updated; test passes again (was masked by excluding it as "slow").

## Verification

- `pokox_asset_store_test` passes in `build/` (31/31) and `build-full/`
  (32/32), including re-entrant-loader, moved-from-store, and error-clear
  regression cases.

## Not done / future

- Single-threaded only; ENG-17 adds the async load queue and will need
  internal synchronization.
- No typed asset registry, hot reload, or chunk reader yet (spec 21 lists
  those under `resource`; later ENG tasks).
- `typed<T>()` is an unchecked `static_pointer_cast` — caller must match
  the loader's concrete type.

## Integration review, 2026-11-22

Fixed a reference leak when handle key allocation throws; added fault-injection coverage. Typed payload access is unchecked. See `project-review-2026-11-22.md`.

---

## eng17-progress

# ENG-17 — Async load queue

Status: implemented and verified in both build trees.

## What was built

Extends `poko::resource` (ENG-16) with non-blocking loads:

- `AssetStore::request_async(key, loader)` — enqueues a job on the store's
  single worker thread and returns immediately. Duplicate requests for a
  key already queued/running are deduplicated.
- `AssetStore::poll_async()` — call once per frame; installs finished
  payloads into the asset map and records failures. Cheap when idle.
- `load_state(key)` / `is_loading(key)` / `last_error(key)` —
  `LoadState::{none, loading, ready, awaiting_install, failed}`.
  `ready` means installed and acquirable; `awaiting_install` is a
  worker-finished job that still needs `poll_async()` before `acquire()`
  can return a handle (audit ENG-17 contract clarification).
- `acquire()` on an in-flight key fails fast with "still loading"
  instead of blocking or double-loading; the sync `acquire()` path is
  unchanged for callers that want it.

## Concurrency design

- Worker thread lives in `AssetStore::State`; `~State` sets `stop`,
  notifies, and joins — clean shutdown even with queued/running jobs.
- The worker only produces `Job::payload`/`error` and publishes
  `Job::phase` with release ordering; `poll_async`/`load_state` read with
  acquire ordering. **All map and refcount mutation stays on the calling
  thread** — ENG-16's single-threaded invariants are preserved; no mutex
  is needed on `assets`/`jobs`/`failures`.
- Job objects are `shared_ptr` so worker and poller can both hold them
  after `jobs_` entries are erased.

## Verification

- `pokox_asset_store_test` new cases: async load completes without
  blocking, dedup, acquire-during-flight fails fast, `poll_async` install,
  failed loader → `failed` + `last_error`, explicit retry, store teardown
  with a sleeping job.
- `build/` 30/30 (excluding `version_integration`, verified separately)
  and `build-full/` build + asset test pass.

## Audit round — defects found and fixed

- **`ensure_worker` flag ordering**: `worker_started` was set before
  `std::thread` construction; a throwing ctor would leave it stuck true
  with jobs never running. Flag now set only after the thread exists.
- **`request_async` re-loaded ready assets**: no check for an installed
  payload — now returns early when the key is already `ready`.
- **Dedup gap (phase 2)**: a done-awaiting-`poll_async` job did not dedup,
  enqueueing a duplicate; dedup now covers phases 0–2 (phase 3 failed
  still allows explicit retry).
- **`acquire` guard gap**: phase-2 jobs fell through to the sync loader,
  double-loading; now treated as busy like phases 0–1.
- **`poll_async` noexcept + `bad_alloc`**: `assets[key]` could throw
  inside a `noexcept` function → terminate. Install is now wrapped; a
  failed install records `failures[key]` instead, and `failures.erase`
  only runs on success.
- **Thread affinity** (documented, unchanged): `request_async`,
  `poll_async`, `acquire`, and the counters must be called from one
  owner thread; only the worker runs concurrently and it touches only
  `Job` fields published via release/acquire ordering.

## Not done / future

- Single worker thread — a pool can be added if profiling shows queue
  starvation; the job interface already supports it.
- Completed-but-never-acquired async loads stay resident until store
  destruction (same cache semantics as sync loads).
- No priority lanes, cancellation, or progress reporting yet.

## Integration review, 2026-11-22

Fixed unpolled-failure retry state, queue insertion rollback and allocation-failure handling. `last_error()` can now throw when copying its result. See `project-review-2026-11-22.md` for tests and remaining validation.

---

## eng18-progress

# ENG-18 — KTX2 placeholder texture on quad

Status: implemented and verified on the real AMD Vulkan GPU.

## What was built

- `poko::resource::load_ktx2` — dependency-free KTX2 reader for uncompressed
  `R8G8B8A8_UNORM`/`B8G8R8A8_UNORM`, level-0 pixels, full bounds checking,
  64 MiB cap. Basis supercompression explicitly rejected (AST-02 scope).
- `TriangleMode::textured` + `VulkanTrianglePass::set_texture()` — the pass
  lazily creates a 2D texture + linear sampler + SRV on first draw, uploads
  CPU pixels via `UpdateTexture`, and binds `Tex` (set=0/binding=0) through
  the pipeline's static shader variable — the same pattern the ImGui pass
  uses for `FontTexture` (the SRB snapshots constants at creation, so the
  upload must happen before `CreateShaderResourceBinding`).
- `textured.vert`/`textured.frag` — fullscreen quad generated from
  `gl_VertexIndex` (no vertex buffer), UVs, `texture(sampler2D, uv)`.
- `pokox_triangle --texture file.ktx2` — loads via `load_ktx2`, selects the
  compiled-in textured shaders, renders the textured quad. `--texture` is
  rejected on the depth/uniform demo variants.
- `pokox_ktx2_test` — accept/reject fixture coverage in both trees.
- Fake Diligent headers extended (`ITexture`/`ISampler`/`TextureDesc`/
  `SamplerDesc`/`UpdateTexture`) so `pokox_triangle_pass_faults` still
  compiles the pass.

## Verified

- `pokox_triangle --texture checker.ktx2 --frames 60 --adapter 0` on the
  AMD Radeon GPU: `submitted=60 graphics_errors=0 graphics_warnings=0`.
- `pokox_ktx2_test` + `pokox_asset_store_test` pass in `build/` and
  `build-full/`; `triangle_pass_faults` and all demo input tests pass.

## Bugs found during implementation

- KTX2 header layout: fields start at offset 12 (96-byte header), level
  index at offset 96 — caught before first test run.
- Diligent API mismatches fixed against real headers: `RESOURCE_DIM_TEX_2D`,
  `SamplerDesc.AddressU/V/W`, `GetDefaultView(type)` returns an unowned
  raw view (sampler attached via `view->SetSampler`), `Box` field order is
  `{MinX,MaxX,MinY,MaxY,MinZ,MaxZ}`, `UpdateTexture` takes 7 args and
  `TextureSubResData` needs `Stride`+`DepthStride`.
- SRB constant-snapshot ordering: texture upload moved before pipeline
  creation so `Tex` is bound before `CreateShaderResourceBinding`.

## Mip-chain continuation

- `Ktx2Image` now carries `mips[]` — every level index entry is parsed with
  per-level dimensions (`max(1, dim>>i)`) and bounds-checked payload.
- `VulkanTrianglePass::set_texture_mips()` uploads the full chain
  (`MipLevels=N`, per-level `UpdateTexture`); `set_texture()` delegates
  with a single level.
- `pokox_triangle --texture` passes all loaded mips; demo verified with a
  3-level KTX2: `submitted=60 graphics_errors=0` on the AMD GPU.
- `pokox_ktx2_test` covers a 4x4+2x2 two-level fixture.

## sRGB continuation

- `Ktx2Format` gained `rgba8_srgb`(43)/`bgra8_srgb`(50); loader accepts all
  four UNORM/SRGB 8-bit formats and maps them distinctly.
- `set_texture_mips(..., bgra, srgb)` selects `TEX_FORMAT_*_UNORM_SRGB`
  (Diligent naming); demo derives both flags from `Ktx2Format`.
- Verified on AMD GPU with the multi-mip fixture: `submitted=30
  graphics_errors=0`. `pokox_ktx2_test` covers all four format accepts.

## Not done / future

- Other channel layouts/depth formats, Basis/UASTC transcode → AST-02,
  async texture streaming via ENG-17 queue.
- No texture streaming integration with ENG-17's async queue yet.
- `set_texture` replaces GPU objects on each call (no hot-swap diffing).

## Integration review, 2026-11-22

The earlier 96-byte-header claim and fixtures were incorrect. The reader now uses the Khronos 80-byte layout and non-array 2D fields, with bounds and regression tests. Corrected code has not yet been tested against independent KTX tooling or on a GPU. See `project-review-2026-11-22.md`.

---

## eng19-progress

# ENG-19 — Hand-written binary mesh load

Status: implemented and verified on the real AMD Vulkan GPU.

## What was built

- **PMES format** (`poko/resource/pokomesh.hpp/.cpp`): hand-written
  little-endian binary mesh — `PMES` magic, version 1, vertex/index counts,
  vertex stride. Per-vertex float3 position + float3 normal (24-byte v1
  layout, stride >= 24 tolerated for forward compat). u32 indices.
  Loader is fully bounds-checked: exact file-size match, count/stride caps
  (4M verts / 16M indices / 64 MiB), index range validation, finite-value
  rejection, multiple-of-3 index count. `load_pokomesh(path)` +
  `parse_pokomesh(data,size)` for in-memory use.
- **`VulkanMeshPass`** (`engine/rhi`): first real vertex-buffer path —
  `MeshVertex` (pos+normal, 24 B), `set_mesh()` CPU copy → immutable
  `BIND_VERTEX_BUFFER`/`BIND_INDEX_BUFFER` buffers uploaded once per set,
  `InputLayout` (2 elements, stride 24, offsets 0/12), depth test +
  back-face culling, `SetVertexBuffers`/`SetIndexBuffer`/`DrawIndexed`.
- **`mesh.vert`/`mesh.frag`**: `layout(location=0/1)` pos+normal inputs;
  fragment does a fixed-light lambert term so face orientation reads.
  Positions are NDC-space (camera is ENG-20, real lighting ENG-21).
- **`pokox_cube`** demo: builtin 24-vert/36-index cube by default,
  `--mesh file.pmes` exercises the PMES loader end-to-end; same
  `--frames/--adapter/--no-validation/--config` surface as other demos.
- `pokox_pokomesh_test` in both trees: accept path + 8 reject cases
  (magic, version, stride, index range, truncation, NaN, missing/empty).

## Verified

- `pokox_pokomesh_test` PASS in `build/` and `build-full/`.
- `pokox_cube --frames 60 --adapter 0`: `submitted=60 graphics_errors=0`.
- `pokox_cube --mesh cube.pmes --frames 30`: `Loaded PMES mesh: 24
  vertices, 36 indices` + `submitted=30 graphics_errors=0`.
- `pokox_cube_missing_shader`/`pokox_cube_bad_args` CTest pass;
  `triangle_pass_faults` unaffected.

## Bugs found during implementation

- Test fixture wrote 28 B/vertex (extra float) vs declared 24 B stride —
  caught by the exact-size check; fixed fixture.
- `BufferDesc` has no `Format` member — index type comes from
  `DrawIndexedAttribs.IndexType` (`VT_UINT32`); removed the bad field.

## Not done / future

- Positions are NDC-space floats; quantization/delta compression is AST-04.
- No UVs/tangents/materials yet; camera (ENG-20) and lighting (ENG-21)
  will replace the fixed NDC transform and hardcoded light dir.
- `set_mesh` reallocates buffers per call — fine for load-once meshes;
  streaming/double-buffering comes with AST work.

---

## eng20-progress

# ENG-20 — Camera with view/projection

Status: implemented and verified on the real AMD Vulkan GPU.

## What was built

- **Platform mouse events** (`i_platform.hpp`, `sdl_platform.cpp`):
  `EventType::{mouse_motion, mouse_button, mouse_wheel}` with dx/dy,
  button/pressed, and wheel detents. Motion is gated on left-button held
  (`SDL_BUTTON_LMASK`) so orbit drags don't fire on hover. Fake SDL header
  extended for the fault-test build.
- **`poko::render::OrbitCamera`** (`engine/render/camera.*`): dependency-free
  orbit camera — yaw/pitch clamped, exponential wheel zoom, perspective
  projection (fov 0.9, near 0.1, far 100), produces a column-major
  projection*view mat4 for a std140 uniform.
- **`VulkanMeshPass::set_view_proj()`**: per-frame mat4 uploaded through a
  dynamic uniform buffer (`BIND_UNIFORM_BUFFER`, `USAGE_DYNAMIC`,
  `MAP_WRITE`/`DISCARD`) bound to the vertex shader's `Camera` block
  (set=0/binding=0) via `GetStaticVariableByName(SHADER_TYPE_VERTEX)` +
  `CreateShaderResourceBinding(..., true)` + `CommitShaderResources` —
  the same constant-snapshot pattern as ENG-18's texture binding.
- **`mesh.vert`**: `view_proj * vec4(aPos, 1.0)`; positions are now
  world-space (the builtin cube uses ±0.9 units at distance ~2.4).
- **`pokox_cube`**: left-drag orbits, wheel dollies; aspect set from the
  configured window size each run.

## Verified

- `pokox_cube --frames 60 --adapter 0`: `submitted=60
  graphics_errors=0 graphics_warnings=0` (real GPU, validation on).
- `pokox_sdl_platform_faults`, `pokox_pokomesh_test`, `pokox_ktx2_test`,
  `pokox_asset_store_test` all pass in `build/`.

## Bugs found during implementation

- `CreateShaderResourceBinding(&binding)` without `UseConstants=true`
  left `Camera` unbound → VUID-vkCmdDrawIndexed-08114. Same SRB
  constant-snapshot ordering rule as ENG-18; fixed by passing `true`.
- Fake `SDL_Event` union lacked mouse members — extended.

## Not done / future

- Orbit only (no pan/first-person modes); aspect updates on window
  resize aren't hooked yet (set once from config).
- Lighting still uses untransformed normals — correct-looking for orbit
  but real view-space lighting lands with ENG-21.
- Camera matrices are CPU-side float; Q16.16 deterministic math is
  ENG-60/MUT-09 scope.

## Integration review, 2026-11-22

A CPU regression test found and fixed a homogeneous-coordinate and Vulkan depth-range defect in the camera projection. See `integration-review-2026-11-22.md` for before/after evidence and verification limits. The corrected revision has not yet been visually verified on a GPU; prior submitted-frame counts do not establish visible output. Resize aspect remains open.


### Review update — 2026-11-22

The cube demo now derives camera aspect from drawable pixel dimensions at startup and on resize; zero-sized viewports retain the last valid aspect. CPU regression tests cover the calculation and the demo passed a stub-based syntax check. This supersedes earlier notes that aspect is fixed at startup. Actual SDL/Diligent, high-DPI and GPU resize behavior still require device validation. See `project-review-2026-11-22.md`.


### Linux software-rendering update — 2026-11-22

The corrected cube and camera built against real SDL3 and the pinned DiligentCore Vulkan backend. On Xvfb + Mesa llvmpipe, a synthetic mouse drag changed the rendered image, a resize produced a nonuniform frame, and 300 frames completed with validation requested and zero reported graphics errors/warnings. This is CPU software rendering, not physical-GPU or high-DPI acceptance. See `graphics-setup-2026-11-22.md`.

---

## eng22-progress

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

---

## eng30-progress

# ENG-30 — main loop with fixed accumulator and spiral guard (2026-11-25)

## Implemented

- `poko/foundation/loop.hpp` + `engine/foundation/src/loop.cpp` (`poko_loop`,
  dependency-free): `FixedStepLoop` feeds one presented frame delta to
  `advance()` and returns how many 20 Hz sim steps to execute now. `alpha()`
  supplies the render interpolation weight; `backlog_seconds()`,
  `total_steps()`, `frames()` and `clamped_last_frame()` expose loop state.
  `reset_backlog()` drops debt after focus loss/minimize/debugger break.
- Spiral guard: per-frame delta is clamped to 0.25 s, at most 5 sim steps run
  per frame, and any debt beyond one step after a capped frame is discarded.
  Repeated 5 s stalls therefore run exactly 5 steps each frame with bounded
  backlog — no catch-up spiral. Invalid or non-finite deltas pause the loop;
  absurd limits pause instead of overflowing.
- Accumulation is on integer nanoseconds internally, so long runs cannot
  drift the way repeated floating-point addition does. Identical delta
  sequences produce identical step counts, backlog and alpha — MUT-38 input
  snapshots can drive the same clock for replay.

## Verified

- `pokox_loop_test` (`engine/foundation/tests/unit/loop_test.cpp`):
  20 Hz default and 60 Hz sim rates, 60 Hz variable render over 3 s (one step
  per 50 ms accumulated tick), 0.2 s catch-up (4 steps), 5 s stall clamp (5
  steps, debt discarded), repeated-stall bound, backlog reset, invalid delta
  and limit handling, alpha bounds, determinism, and two 10,000-frame drift
  runs (0.1 s → exactly 20,000 steps; 0.049 s → exactly 9,800).
- Full Debug MSVC `ctest`: **89/89**, including `version_integration`.
  `pokox_loop_test` under ASan: **1/1**, no sanitizer errors.

## Defect fixed

- `tools/version/tests/integration/test_version.py` copies a hard-coded file
  set into a temp source tree, which had fallen behind the real CMakeLists:
  `fold.cpp`, `optimize.cpp`, `vm_core.cpp`, `debugger.cpp`, `hostcall.cpp`
  and their headers were missing, so the minimal `pokox` configure failed.
  Added those plus ENG-30's `loop.cpp`/`loop.hpp`. This is the MUT-15
  hard-coded-source-list failure mode recurring; full ctest is green again.

## Remaining

- The clock is a standalone component; existing demos still use their own
  ad-hoc frame loops. Wiring the engine-owned loop into a demo/sim driver
  belongs with ENG-31 (jobs) and ENG-33 (ECS), when there is a real sim to
  step. Formal MUT-38 still needs ENG-02 target-platform acceptance; this
  milestone does not accept any gate.

# ENG-02 — target-platform window evidence (2026-11-25)

## Implemented and verified

- Windows 11 x64: `sdl_platform.cpp` and the real SDL integration test were
  compiled with MSVC against the vendored SDL3 3.4.20 headers/DLL (an MSVC
  import library was generated from the DLL exports in
  `artifacts/sdl-msvc/`). Running with the real `windows` video driver passed
  create, resize, close translation, quit, teardown, repeat-init and
  destructor-only cleanup.
- Physical Android arm64 (`24117RN76G`, Android 16/API 36): the NativeActivity
  GLES/Vulkan window probe was rebuilt and installed after uninstalling the
  old app. It presented 120/120 frames on the real surface at both
  `1080x2400` and `720x1600`; display size was restored afterward. The
  activity finishes after presenting, covering teardown.
- Repairs exposed by this evidence: `FixedStepLoop` now uses separate default
  and explicit constructors so NDK libc++ accepts the header; `build_apk.sh`
  builds from a stable cwd, signs with `java -jar apksigner.jar`, and links
  `vulkan_clear_android.cpp` plus `-lvulkan`; the native activity picks up an
  already-published `ANativeWindow` and uses a small looper timeout.
- Full two-target G1/ENG-02 evidence is in
  `docs/two-target-gate-evidence-2026-11-25.md`. G1 was accepted; G2 remains
  deferred to ENG-60→63.

## Limitations

- Live Android rotation/resize is not exercised here; it remains ENG-05 work.
  This evidence covers window creation, presentation at two sizes and
  teardown on the real device.
- The MSVC SDL3 link uses an import library generated from the vendored
  MinGW SDL3 DLL, not an MSVC vcpkg SDL3 package. The ABI surface exercised is
  the SDL3 C API used by `SdlPlatform`.

# ENG-60 — Q16.16 math primitive suite (2026-11-26)

## Implemented and verified

- `engine/foundation/include/poko/foundation/fixed.hpp`: header-only,
  `constexpr`-clean `poko::math::Fixed` — a signed 32-bit Q16.16 scalar
  (range [-32768.0, 32767.99998], resolution 1/65536). Pure integer
  arithmetic only: no libm, no float literal or operation, no SIMD, so
  sim-path results are bit-identical on x64 and arm64 (spec 24 rules 1–2).
- Arithmetic policy, all documented on the type: add/sub wrap modulo 2^32
  (plain integer ops); mul uses a 64-bit intermediate with truncation
  toward zero and saturates to the int32 raw range; `divide` returns
  `std::optional<Fixed>` — a zero divisor yields `std::nullopt`, never a
  silent infinity; `sqrt` is an exact integer Newton iteration (fixed 32
  steps from a power-of-two seed, final min-of-pair correction — integer
  Newton can settle into a 2-cycle one unit above the floor, e.g. raw
  inputs just below a perfect square) returning `floor(isqrt(raw << 16))`;
  negative input yields zero.
- Trigonometry: `sin`/`cos` take radians as `Fixed`, reduce modulo 2*pi in
  64-bit (cannot overflow), and evaluate a 1024-entry Q16.16 sine table
  with linear interpolation. cos reuses the sine path at +pi/2. Worst-case
  error measured at 1.94 LSB, inside the documented <= 2 LSB bound
  (table quantization <= 0.5 LSB/entry + segment curvature ~0.31 LSB +
  interpolation truncation < 1 LSB).
- `pokox_fixed_test` (`engine/foundation/tests/unit/fixed_test.cpp`):
  exact integer goldens for every operator (including truncation-toward-
  zero vs floor cases, saturation, INT32_MIN negation), constexpr
  `static_assert`s, an exhaustive sqrt check for every raw input in
  [0, 400000) plus 200k deterministic pseudo-random inputs across the full
  positive int32 domain against an independent bit-by-bit isqrt, trig
  anchors/symmetry/periodicity checks, and a dense libm-reference sweep
  asserting the 2 LSB bound.

## Verified

- `pokox_fixed_test`: all checks passed; trig max error 1.9413 LSB.
- Full Debug MSVC `ctest`: **99/99** (was 98/98; +1 new test).
- `pokox_fixed_test` under MSVC ASan (`build-msvc-asan`): clean.

## Scope boundary and remaining

- Scalar primitives + trig only, per the ENG-60 row ("Q16.16 math
  primitive suite"). Spec-21 vector/matrix types (`Vec*`, `Mat4`, `Quat`,
  `AABB`, ...) land with their first consumer — ENG-61 broadphase needs
  fixed vectors — rather than speculatively now.
- Fixed-point vectors are the expected next math increment inside this
  lane; the determinism lint that rejects float literals in sim physics
  code is still unimplemented (spec calls for it; no such tool exists yet).
- Execution-order exception, same pattern as ENG-30: wave-21/22 engine
  lanes (ENG-31–44, ENG-50–53) stay queued; this lands the G2 critical
  path first. No gate accepted — G2 remains open until ENG-60→63 complete
  and produce the dual-target physics replay evidence.

# ENG-61 — SAP broadphase with sorted pair output (2026-11-26)

## Implemented and verified

- New `physics` module (`engine/physics/`, `poko_physics`): first engine
  module in the spec-21 dependency chain after `scene` (which does not
  exist yet — physics is self-contained on foundation math for now).
- `engine/foundation/include/poko/foundation/fixed_vec.hpp`:
  `poko::math::FixedVec3`, the Q16.16 fixed vector — first consumer of
  the spec-21 "two precision paths" math library. Component-wise
  add/sub/negate, scalar multiply, `min`/`max` for bounds normalization.
  Vec2/4, Mat4, Quat remain deferred to their first consumers.
- `poko/physics/sap_broadphase.hpp` + `src/sap_broadphase.cpp`:
  `SapBroadphase` sweep-and-prune on the X axis.
  - Bodies are caller-indexed u32s carrying normalized AABB bounds
    (component-wise min/max applied on insert, so corner order is free).
  - `insert`/`remove` are a deterministic FIFO command buffer applied in
    submission order by `commit()`; insert upserts, remove of an absent
    index is a no-op. `pairs()` reflects the last commit only.
  - Endpoint sort is a strict total order — (x, min-before-max,
    body slot), with bodies_ kept sorted by index — so the sweep cannot
    depend on insertion order, command history or scheduling.
  - Each overlapping pair is emitted exactly once at the later min
    endpoint as (min(index), max(index)); the final list is sorted by
    (a, b). Touching X intervals count as overlapping (inclusive),
    matching broadphase candidate semantics.
- `pokox_sap_broadphase_test`: empty/single/disjoint/touching cases,
  X-only overlap semantics, command-buffer staleness and upsert/remove
  ordering, inverted-corner normalization, insertion-order independence,
  a 200-body deterministic pseudo-random cross-check against a brute-force
  O(n^2) reference, and a 50-tick churn loop asserting sorted canonical
  output every tick.

## Verified

- `pokox_sap_broadphase_test`: all checks passed.
- Full Debug MSVC `ctest`: **100/100** (was 99/99; +1 new test).
- `pokox_sap_broadphase_test` under MSVC ASan (`build-msvc-asan`): clean.

## Scope boundary and remaining

- X-axis SAP only, per ENG-61. Multi-axis SAP, incremental endpoint
  resort, and the 512-body island structures belong to ENG-62/63 when
  there is a real consumer; endpoints are fully re-sorted per commit
  (documented deviation — identical pair set, deferred optimization).
- Pairs are X-overlap candidates only; Y/Z rejection and actual contact
  generation are ENG-62 narrowphase work.
- No gate accepted — G2 remains open until ENG-60→63 complete.

# ENG-62 — GJK/EPA narrowphase and manifolds (2026-11-26)

## Implemented and verified

- `engine/foundation/include/poko/foundation/fixed_vec.hpp`: added `dot`,
  `cross`, `lengthSquared`, `normalized` (optional on zero vector) — the
  narrowphase vector primitives, all Q16.16.
- `poko/physics/convex_shape.hpp/.cpp`: `ConvexShape` — world-space
  vertices + sphere-sweep radius covering sphere (1v+r), capsule (2v+r),
  AABB/box (8v) and hull (<=64v) uniformly; `support(d)` = argmax dot with
  lowest-index tie-break plus radius*normalize(d). Sphere/box "fast paths"
  hold by construction (1/8-vertex scans).
- `poko/physics/narrowphase.hpp/.cpp`: `collide(a, b) -> ContactManifold`.
  - GJK: CSO support `sA(d)-sB(-d)`, simplex <= 4 with Johnson-style
    reduction via winning-subset mask, closest-point-on-hull by subset
    enumeration (segment/triangle Ericson regions/tetra inside test),
    fixed 64-iteration cap, duplicate-vertex and no-progress termination.
  - EPA: seed tetra searched over GJK simplex + 6 axis supports (first
    origin-containing tetra in fixed enumeration order), horizon-edge
    expansion with sorted edge order, fixed 64-iteration cap, convergence
    on expansion progress (`reach - dist <= eps`), NOT absolute distance.
  - Manifold: up to 4 contact points — deepest barycentric witness plus
    the three EPA-face vertex witness pairs; coincident contacts merged
    within fixed tolerance; sorted by (depth-proxy, witness coords) for
    stable contact order. normal = -closest-face normal (B -> A).
- `pokox_narrowphase_test`: separated/overlapping/identical spheres,
  AABB-sphere overlap and separation, exact touch, capsule-sphere,
  determinism (bit-identical manifold), empty shape.

## Verified

- `pokox_narrowphase_test`: all checks passed.
- Full Debug MSVC `ctest`: **101/101** (+1).
- `pokox_narrowphase_test` under MSVC ASan: clean.

## Scope boundary and remaining

- EPA depth is polytope-approximated (measured ~1.9% over true on the
  sphere case; deterministic). Face-clipping manifolds with reference/
  incident faces need hull topology — current manifold uses EPA-face
  witness pairs (documented simplification, still genuine touch pairs).
- Vertices are world-space; per-tick transform baking is the caller's job
  until ENG-63/scene provides placement.
- No gate accepted — G2 remains open until ENG-60->63.

# ENG-63 — sequential impulse solver, translational (2026-11-26)

## Implemented and verified

- `poko/physics/solver.hpp/.cpp`: `SequentialImpulseSolver` — PGS
  sequential impulse over `ContactConstraint`s derived from narrowphase
  manifolds, all Q16.16 Fixed (no float in the solve path).
  - Constraint model: `vn = dot(n, vA - vB)` with `n` the B->A manifold
    normal (solver normalizes it once); positive accumulated normal
    impulse `lambda_n >= 0` separates. Target separating velocity =
    Baumgarte (`beta=0.2`, slop `0.05`, `/dt`, dt<=0 disables bias) +
    restitution (`e * approach`, gated at approach > 1.0).
  - Friction: two deterministic tangent axes (least-aligned coordinate
    axis cross product), accumulated tangential impulses clamped to
    `+/-(mu * lambda_n)`; negative friction coefficients treated as 0.
  - Effective mass is translational only: `kn = 1/(invMassA + invMassB)`
    per contact; both-static and degenerate contacts (missing body,
    zero normal, zero mass sum, failed division) are skipped without
    disturbing canonical order.
  - Warm start: accumulated `(normal, t1, t2)` impulses persist in a
    member map keyed by caller-stable `contact_key`, replayed once per
    solve before iterations; keys absent from a step are evicted at the
    next `solve()`. Keys must be unique within a step's contact set.
  - Determinism: contacts sorted canonically by (min body, max body,
    key); union-find islands ordered by lowest member body index with
    stable in-island canonical order; fixed iteration count (default 8,
    no early-out); all lookups binary search over index-sorted bodies.
  - `integrate(dt)` does `position += velocity * dt` for non-static
    bodies only; positions are never touched inside `solve()`.
- `pokox_solver_test`: floor push-off, no-op when separating faster
  than target, restitution bounce (~e*approach), symmetric two-body
  impulse split, friction bleed-off, 60-step warm-started resting
  stability, bit-identical determinism across runs, body
  upsert/remove/replace and missing-body contact robustness.

## Verified

- `pokox_solver_test`: all checks passed.
- Full Debug MSVC `ctest`: **102/102** (+1). `version_integration`
  requires the MSVC env on PATH (fresh CMake configure); passes with
  `tools/msvc/msvcenv.bat` env — same caveat as before, not a regression.
- Full MSVC ASan `ctest`: **102/102**, `pokox_solver_test` clean.

## Scope boundary and remaining (contractual limitations)

- Translational dynamics only: no angular velocity, inertia tensor or
  torque. `point_a`/`point_b` are carried on `ContactConstraint` but
  unused — lever arms (`r x n`) are the first thing rotational dynamics
  needs. Box/hull contacts are point approximations; correct for spheres.
- No sleep/wake (bodies never sleep; static is inv_mass = 0 only), no
  split impulses (Baumgarte bias can add energy on deep penetration —
  positional correction is the documented future fix), no joint
  constraints, no island parallelism (islands are computed for solve
  ORDER only; the solve itself is sequential).
- Warm-start cache is per-solver-instance and keyed by caller-supplied
  `key`; key reuse across different contact pairs silently inherits the
  old impulse — callers must keep keys pair+point stable and unique.
- Tuning constants are fixed (beta 0.2, slop 0.05, restitution gate
  1.0, 8 iterations default); per-material or per-island iteration
  budgets are future work.
- G2 primitive chain ENG-60->63 is now code-complete on this branch;
  gate acceptance still requires the spec's remaining evidence (target
  platforms, replay/determinism harness wiring) — NOT claimed here.

# G2 — two-target determinism evidence (2026-11-26)

- `engine/physics/tools/g2_replay_probe.cpp` (`poko_physics_g2_replay_probe`):
  compiled-in deterministic scenario (static floor slab + pillar, 8 spheres,
  4 boxes; staggered drops, varied mass/friction/restitution/horizontal
  velocity). Per tick: gravity -> SAP bounds -> `collide()` per pair ->
  `ContactConstraint`s -> warm-started sequential impulse solve ->
  `integrate()` -> `tick pairs contacts hash` line; the hash is 64-bit
  FNV-1a over raw Q16.16 position/velocity bits — integer-only, no floats,
  pointers or platform state.
- `tools/targets/run_dual_target_tests.py` extended: `PHYSICS_SOURCES`
  (sap_broadphase, convex_shape, narrowphase, solver) added to the NDK
  Android build, a `g2_replay_probe` target linked on device, G2 probe legs
  on both targets, LF-normalized byte comparison, G2 gate status in
  `gate-report.json` and the exit code; probe timeouts raised for the
  10,000-tick physics trace.
- `CMakeLists.txt`: `poko_physics_g2_replay_probe` executable (not a ctest;
  gate tool like the G1 probe).

## Narrowphase fixes driven by probe validation

- `origin_in_tetra` accepted coplanar "tetrahedra" unconditionally (the
  sign test is vacuous when every opposite vertex lies in the face plane),
  so EPA's seed search could lock onto a `vol = 0` sliver for separated
  shapes and expand a garbage hull — observed depths ~34 world units on a
  sphere 8 units below a floor slab. Added a minimum per-face altitude
  check (`kTetraMinAltRaw` ~0.001 units); separated pairs now correctly
  report `touching = false`.
- Sphere-sphere pairs hit EPA's iteration cap every call (~8.5 ms; the CSO
  is curved so expansion never reaches `depth_eps`). Added an analytic
  fast path for two single-vertex radius shapes — exact penetration,
  B->A normal, same near-touch window — ~10,000x faster and more accurate.
- Post-fix column sweep (sphere vs 80x2x80 floor slab, centers y = +0.49
  to -10): touching/depth/normal sane across the whole range, separated
  cases clean.

## Verified

- `pokox_narrowphase_test`, `pokox_solver_test`: all checks passed.
- Full MSVC Debug `ctest`: **102/102**.
- `tools/targets/run_dual_target_tests.py` full run (Windows x64 MSVC Debug
  + physical Xiaomi `24117RN76G` arm64, NDK r22 `-O2`):
  - Windows ctest 102/102; Android 12/12 Mute binaries.
  - G1 re-verified byte-identical, sha256
    `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68`.
  - **G2 byte-identical**: both legs exit 0, 10,000 LF trace lines each,
    sha256 `dd383cc338cd4ba179622aa64918d896de994c9ce20366b7018ba28c4eba1385`.
  - Runner verdict: `all_tests_ok: true`, `G1: accepted-evidence`,
    `G2: accepted-evidence`.
- Evidence doc: `docs/two-target-gate-evidence-2026-11-26.md`;
  artifacts under `artifacts/dual-target/` (traces + `gate-report.json`).

## Remaining (unchanged scope boundaries)

- Solver stays translational-only; EPA depth polytope-approximated;
  scale-guard widens the near-touch window in scaled units for large
  scenes; no sleep/wake, split impulses or joints (ENG-63 documented).
- G2 covers the probe scenario + unit suites on the two gate targets —
  not production-scene coverage or ENG-64+ features.

# ENG-64 — character controller through the solver (2026-11-26)

## Implemented and verified

- `SimBody::kinematic` (`poko/physics/solver.hpp`): inv_mass = 0 bodies
  flagged kinematic are skipped by solver impulses (infinite mass) but
  DO integrate under their velocity in `integrate()` — static bodies
  (inv_mass = 0, !kinematic) are still skipped. This is the mechanism
  the controller uses to move through the solver as a velocity target.
- `poko/physics/character_controller.hpp/.cpp`:
  `CharacterController::update()` (pre-solve, once per tick) reads the
  body, builds the capsule (`capsule_at`: vertical segment +/- half_length
  + sweep radius), runs a downward shape cast for ground detection,
  classifies walkability by `ground_normal.y >= slope_cos`, tests each
  wish axis independently against the next-tick pose (per-axis slide),
  probes a step-up path when grounded + blocked, then writes the velocity
  target via `upsert_body`. `resolve()` (post-integrate) pushes the
  capsule out of penetration along manifold normals, total correction
  capped at `max_depenetration`.
- Grounding semantics that made it correct: `grounded` requires the down
  cast to come to rest within a 0.3-unit snap of the capsule (a distant
  floor must NOT ground — the first implementation let the character
  hover mid-air because `vy` was zeroed while still falling); gravity
  always applies with a -10 u/s terminal clamp sized so per-tick fall
  stays inside the depenetration budget; grounded vertical velocity is a
  constant -0.5 u/s "stick" (not accumulating, not zero) so the capsule
  presses gently into the ground and `resolve()` cancels the ~0.008
  u/tick penetration — no floating, no tunneling.
- Step-up is a bounded POSITIONAL lift of exactly `step_height`, applied
  in `update()` only when the probe passes (raised capsule clear,
  raised destination wall-free, landing cast drops > ~0.02 below the
  raised pose). It is deliberately NOT a velocity: `vy = step_height/dt`
  persists as body velocity and launches the capsule ballistically
  (observed apex ~47 units). The `grounded_` gate prevents mid-air
  re-lifts, so tall walls cannot be ratcheted.
- Contacts with `depth < ~0.002` and degenerate EPA manifolds
  (`touching` with ~0 depth and garbage normals) are filtered before
  being treated as walls/blockers — tangent grazes were falsely
  triggering step-up on flat ground.
- `pokox_character_controller_test`: fall-and-land, walk + step-up +
  wall stop, close-range block stop, jump apex/landing, depenetration
  from inside the floor, 30-deg walkable vs 56-deg non-walkable slope,
  bit-identical determinism. ctest `TIMEOUT 900` — the test is
  EPA-cast-heavy and takes ~207 s in MSVC Debug.

## Verified

- `pokox_character_controller_test`: all checks passed (Debug).
- Physics subset (`fixed`, `sap_broadphase`, `narrowphase`, `solver`,
  `character_controller`): all pass; full Debug `ctest` 103/103 with
  `version_integration` passing under the MSVC env (environmental caveat
  unchanged).

## Scope boundary and remaining

- Capsule is axis-aligned vertical only; no rotation, no angular response,
  no stair-snapping below step_height, no vault/mantle, no moving-
  platform carry (kinematic ground is not yet a concept).
- `resolve()` depenetration uses manifold normals summed then length-
  clamped; EPA depth is polytope-approximated so resting penetration
  jitters ~ +/-0.03 units (bounded, deterministic).
- Per-axis slide tests each axis independently — diagonal motion into a
  corner is approximate (standard kinematic-controller simplification).
- The test's `tick()` adds solver contacts with a dummy static partner
  that the solver skips (im_sum = 0); kinematic bodies get no impulse
  response by design — `resolve()` is the only positional correction.
- ENG-65 (visual f32 solver + soft bodies) is STARTED, not complete —
  see below.

# ENG-65 — visual physics and soft body path (2026-11-26)

## Implemented and verified

- `engine/foundation/include/poko/foundation/vec3f.hpp`: `poko::math::Vec3f`
  — f32 3-vector for the visual physics path only (distinct type from
  `FixedVec3`, not implicitly convertible, never used in sim physics).
- `engine/physics/include/poko/physics/visual_solver.hpp` &
  `engine/physics/src/visual_solver.cpp`:
  `VisualSolver` (f32 PGS mirror of `SequentialImpulseSolver`,
  `kDefaultIterations = 12` per spec 24, warm-start cache, canonical
  contact ordering + union-find islands, kinematic support), `collide_visual`
  (analytic f32 narrowphase for sphere-sphere, sphere-AABB, AABB-sphere,
  AABB-AABB), and `VisualWorld` (gravity + narrowphase + solve + integrate).
- `engine/physics/include/poko/physics/soft_body.hpp` &
  `engine/physics/src/soft_body.cpp`:
  Feature-flagged under `POKO_SOFT_BODY` (`option(POKO_SOFT_BODY ... ON)` in
  `CMakeLists.txt`, `poko::build::soft_body` in `poko/foundation/build_flags.hpp`,
  and `pokox_flag_soft_body_0`/`1` in `flags_contract.cpp`). Implements
  `SoftBody` (Verlet mass-spring lattice with `kMaxSoftBodyNodes = 256`,
  structural + shear springs, pinning, plane/sphere collision) and
  `ClothGrid` (2D grid with top-row pinning and wind driven by `sim_time_seconds`).
- `tools/targets/run_dual_target_tests.py`: added `visual_solver.cpp` and
  `soft_body.cpp` to `PHYSICS_SOURCES` and `POKO_*` flag defines to the
  Android NDK compile flags.
- `pokox_visual_solver_test` and `pokox_soft_body_test`: cover PGS
  separation/restitution/friction/kinematic, all 4 `collide_visual` shape
  pairs, `VisualWorld` settling, `Vec3f`/`FixedVec3` type-split `static_assert`s,
  256-node cap enforcement, pinned lattice sag, sphere collision, and
  `ClothGrid` wind response.

## Verified

- MSVC Debug `ctest`: 107/107 passed (including `version_integration` under
  `tools/msvc/msvcenv.bat`).
- MSVC ASan `ctest` physics + flag subset (`fixed`, `sap_broadphase`,
  `narrowphase`, `solver`, `visual_solver`, `soft_body`, `pokox_flag_*`):
  14/14 passed, ASan-clean.

## Scope boundary and remaining

- Visual physics is f32 and client-only; Mute compiler enforcement of
  `ServerOwned` field binding rejection remains MUT-42 scope.
- Soft-body collision is limited to plane/sphere helpers (no general mesh
  or self-collision).
