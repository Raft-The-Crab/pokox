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
2. Repeat on the Vulkan path of `pokox_fallback_clear`. Exercise the OpenGL path separately, resizing, minimizing and restoring it while checking for errors and artifacts. Test ENG-04's color and fallback separately using `eng04-progress.md`.
3. Investigate Android pre-transform, lifecycle and surface recreation on a target device. Handle device loss separately.

ENG-05 is not accepted: Linux software submissions alone do not prove artifact-free rendering on Windows/Android, and real OpenGL resize remains unverified.
