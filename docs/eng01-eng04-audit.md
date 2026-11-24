# ENG-01–ENG-04 code audit — 2026-11-21

This audit covers the current foundation/build setup, SDL platform, Vulkan clear seed, and experimental desktop fallback. It does not certify the entire engine or close a platform acceptance gate.

## Fixes

- **ENG-03 cleanup:** The Vulkan-only demo now treats a failed or uncertain renderer cleanup as an unsuccessful run, including an idle exception, and follows the normal cleanup/reporting path after a render error. Previously a run could print success after cleanup failed.
- **ENG-03 diagnostics:** Factory lookup exceptions are caught instead of escaping a `noexcept` entry point. A failed callback restoration is counted and prevents a later diagnostics scope from taking over an uncertain callback. Repeated start while already active no longer fetches the factory first.
- **ENG-03 evidence runner:** Non-finite timeouts are rejected before starting a subprocess, and the source hash manifest includes the SDL platform, public RHI headers and manifest used by the run.
- **ENG-04 startup:** Vulkan partial-initialization teardown is deferred to the adapter, so teardown-time diagnostic errors can be distinguished from startup errors and prevent fallback. The partially initialized renderer cannot draw. An exception fetching the GL factory is also handled rather than terminating the process.
- **ENG-04 color safety:** The GL path now checks the actual default framebuffer's color encoding as well as Diligent's swapchain description. It rejects linear, unknown, missing-procedure and GL-error cases and preserves the previous framebuffer binding. It loads SDL's GL library before creating the context and holds the reference until teardown: on Windows the initial SDL load can otherwise disturb Diligent's current WGL context. This prevents a false sRGB/parity assumption; it does not by itself create an sRGB-capable WGL pixel format.
- Clarified outdated Vulkan README status and the GL cleanup contract.

Regression tests cover the new failure cases with dependency doubles. The original source archive and its unrelated contents remain intact; no history was reset.

## Remaining risks

- The pinned Diligent Windows backend uses legacy WGL pixel-format selection, which does not guarantee an sRGB-capable default framebuffer. The new check intentionally rejects a non-sRGB result; a suitable WGL selection/attachment path and real Windows driver tests may be needed for a working fallback. The existing WGL context-version patch also requires a real target build/test.
- The sRGB encoding check and matching linear clear inputs do not prove equal displayed pixels or equal presentation color spaces. Compare actual captured pixels on target devices and exercise a controlled automatic Vulkan-to-GL fallback before accepting ENG-04.
- At the time of this audit, Android OpenGL ES/EGL/activity lifecycle, device-loss recovery and resize recreation were not implemented. For subsequent desktop Vulkan resize work, see `eng-progress.md`. Linux X11 and test doubles are not Windows/MSVC, Android, real target-GPU, or CI validation.

## Audit verification

- GCC 11.5.0 / CMake 3.31.10, Linux x64: 26/26 default CTests and 28/28 SDL-enabled CTests passed. The SDL integration tests used the dummy video driver; the native-layout and graphics fault cases used dependency doubles. An expanded `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion` build reported no project compiler warnings.
- The platform and Vulkan fault-sensitivity mutations were caught. AddressSanitizer and UndefinedBehaviorSanitizer runs passed the Vulkan seed fault suite and six GL/fallback double-based tests. The first sanitizer attempt could not load its runtime library; the successful runs used locally supplied GCC runtime libraries.
- Both desktop demo targets built and linked against real SDL 3.4.20 and the pinned Diligent source on Linux. On Xvfb with Mesa 24.2.6 llvmpipe/lavapipe, the Vulkan-only demo and the fallback demo's Vulkan path each submitted three frames with exit 0, validation explicitly disabled, and no independently verified pixels. This is a software-rendered smoke check, not target GPU validation.
- A real forced-OpenGL attempt failed safely at SDL window creation: `Couldn't find matching GLX visual`. The available Mesa software implementation reports a maximum core version of 4.5, below the required 4.6. Even with a diagnostic version override, the Xvfb environment provided no matching visual; no real GL clear, color comparison or automatic Vulkan-to-GL recovery was demonstrated.
- The real dependency configuration still emits upstream Diligent/third-party CMake warnings: deprecated minimum CMake versions/policy notices, plus Diligent's warning that GCC release optimization is downgraded to `-O1`. These are not warnings in project translation units; they were not hidden or patched blindly. Review/update the pinned dependencies and release-toolchain policy separately.
