# ENG-04 — desktop fallback clear prototype (in progress)

The opt-in `pokox_fallback_clear` prototype connects Vulkan and OpenGL to the same clear-selection contract. It attempts Vulkan first, cleans it up before trying OpenGL, and uses the same linear RGBA clear value on the selected backend. `--force-opengl` bypasses Vulkan for testing. **ENG-04 is not accepted:** the same displayed color on a real fallback device has not yet been demonstrated. Android OpenGL ES and app lifecycle support are not implemented.

## Implementation and boundaries

- `ClearBackendSelection` handles startup selection, defers zero-drawable startup, refuses fallback after uncertain cleanup, and does not silently switch after a runtime error. `VulkanClearBackend` and `OpenGLClearBackend` each own their SDL window, renderer and diagnostics. Failed Vulkan startup must be cleaned up before a new OpenGL window is created. Partial Vulkan teardown is deferred until the adapter can separately detect teardown-time diagnostic errors; those errors block fallback.
- The desktop OpenGL seed uses the pinned Diligent OpenGL factory and requires OpenGL 4.6, an sRGB swapchain description and an actual sRGB default framebuffer (queried at runtime). Linux creates an SDL GLX context and supports X11 only. On Windows Diligent creates the WGL context; the SDL window is deliberately created without SDL's OpenGL flag so that Diligent can set the native pixel format. The pinned Diligent WGL version list tops out at 4.4, so the opt-in Windows build applies an anchor-checked, idempotent configure-time patch to try 4.6 and 4.5 first. **That integration and patch still require a real Windows build and driver test.** Diligent uses legacy WGL pixel-format selection, which does not guarantee an sRGB-capable default framebuffer; the prototype now rejects such a window rather than falsely claiming color parity. A target may therefore need an sRGB-capable WGL pixel-format selection path before the fallback can work. Supplying a custom `FETCHCONTENT_SOURCE_DIR_DILIGENTCORE` means this patch modifies that checkout.
- The SDL GL attributes are process-global on Linux; this prototype assumes exclusive main-thread ownership. A renderer/window must not be destroyed while graphics resources still depend on it. A cleanup failure blocks startup fallback; GL context-destroy failures may be retried, while errors during unbind/idling remain uncertain. The demo exits on unrecoverable cleanup failure and scoped destructors still run; this experimental teardown is not a device-loss recovery strategy.
- Debug error/fatal messages from the selected backend or during cleanup fail the run. Expected startup errors from an unsuccessful Vulkan attempt are not attributed to a subsequent selected OpenGL backend. A successful submit is not proof of GPU execution or displayed pixels.
- The original Vulkan-only demo remains available. No D3D12 selection, Android ES, live backend switching or device-loss recovery is implemented. ENG-05 now has experimental desktop Vulkan and OpenGL resize paths; real OpenGL resize remains unverified. See `eng05-progress.md`.

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
