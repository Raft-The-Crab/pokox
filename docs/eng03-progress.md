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
