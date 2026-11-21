# ENG-01–ENG-05 folder and code audit

Date: 2026-11-21. This review does not close the project's acceptance gates.

## Folder layout

- ENG-01/02 canonical headers are in `engine/platform/include/poko/platform/window/`; implementations and demo are in `engine/platform/src/window/`. Unit, integration and fake SDL declarations are under the corresponding `engine/platform/tests/` subdirectories.
- ENG-03/04/05 canonical device and selection headers and implementations are under `engine/rhi/include/poko/rhi/device/` and `engine/rhi/src/device/`; diagnostic code is under the matching `debug/` directories. The test doubles, unit tests, compatibility test and evidence script are kept under `engine/rhi/tests/` and `engine/rhi/scripts/`.
- Older headers in `engine/platform/include/poko/platform/` and `engine/rhi/include/poko/rhi/` are intentional one-line compatibility forwarders, not duplicate implementations. `engine/foundation/include/build_flags.hpp` is likewise a compatibility header; `engine/foundation/src/main.cpp` is the executable entry point. Removing or moving these would break existing include paths or the build.
- CMake and current test runners reference the organized production paths; historical dated reports can still describe old paths. No ENG-01–05 implementation file needed moving in this review. Existing unrelated project files and Git history were preserved.

## Fixes

- SDL can report nonzero pixel dimensions while the window is minimized. Both renderer initialization and drawing now defer when SDL reports the window minimized, so resize/present is not attempted in that state. Tests simulate a minimized window with nonzero dimensions and a changed size, then restore it. Real Windows/Android minimize behavior still needs target testing.
- If an OpenGL cleanup attempt both logged a Diligent error and failed to destroy its SDL context, retrying previously counted that error as the new baseline and could incorrectly claim clean shutdown. The adapter now records a teardown diagnostic even when context destruction fails, and remains fail-closed. A regression test simulates both failures; an injected removal of the new check was caught.
- Corrected stale platform README claims about the location of GPU functionality and previously recorded Windows evidence. The source organization and legacy forwarding headers are intentional.

## Checks

- Linux x64, GCC 11.5/CMake 3.31: default 26/26 CTests and SDL-enabled strict-warning 28/28 CTests passed. An incremental build with `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion` reported no project compiler warnings.
- The actual desktop demo targets rebuilt and linked against SDL 3.4.20 and pinned Diligent; the incremental rebuild emitted no compiler warnings. AddressSanitizer/UndefinedBehaviorSanitizer passed the Vulkan seed tests and six GL/fallback test-double tests. Platform mutation tests caught 11 injected changes; Vulkan mutation tests caught nine, including the minimized-state check. These double-based checks are not actual Windows/Android or GPU tests.
- A final Mesa lavapipe/Xvfb Vulkan smoke run resized the X11 window to 640×480, 900×650 and 720×540 and completed 1,800 submissions with zero captured graphics errors/warnings. Validation was disabled and pixels were not independently checked; actual minimize/restore requires target testing.
- GCC 11 `-fanalyzer` reported three possible-null warnings within `std::make_unique` on ordinary throwing `operator new`, for the Vulkan renderer, OpenGL renderer and diagnostics implementations. Standard throwing `new` reports allocation failure by throwing, and the allocation sites are enclosed by exception handlers. These appear to be analyzer false positives; they were not hidden or changed to unsafe allocation logic. No other analyzer warnings were reported for the six reviewed translation units with test declarations.
- Earlier fresh real-dependency configurations emitted upstream third-party CMake policy/deprecation notices and Diligent's warning that GCC release optimization is reduced to `-O1`. The incremental build does not resolve those configure-time warnings; review the dependency/toolchain policy separately.

## Still open

The OpenGL fallback, its color parity, resize and cleanup need real Windows/OpenGL-driver validation. The existing pinned WGL legacy pixel-format choice may not produce an sRGB framebuffer; the prototype deliberately rejects an unconfirmed framebuffer. Android OpenGL ES/activity lifecycle and Android resize/pre-transform remain unimplemented. Windows MSVC and CI, hardware resize/minimize/restore, validation-layer presence, displayed pixel checks and device-loss recovery remain unverified. The Linux Vulkan resize smoke test uses software rendering and cannot prove artifact-free target display.
