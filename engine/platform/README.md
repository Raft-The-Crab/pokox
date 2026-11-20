# Platform module

ENG-01 defines the backend-independent single-window `IPlatform` contract in `include/poko/platform/i_platform.hpp`. ENG-02 adds `SdlPlatform` in `include/poko/platform/sdl_platform.hpp` and `src/sdl_platform.cpp`, plus a standalone `pokox_window_demo`. The demo creates a blank, resizable window; it is not a renderer or game.

## Build

The dependency-free default remains unchanged. To enable this module, provide an SDL3 CMake package and set `POKO_WITH_SDL_PLATFORM=ON`. The pinned vcpkg manifest has SDL3 3.4.20 at its baseline. With an already configured project vcpkg checkout on Windows, for example:

```powershell
cmake -S . -B build-sdl -G "Visual Studio 17 2022" -A x64 `
  "-DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  -DVCPKG_TARGET_TRIPLET=x64-windows -DPOKO_WITH_SDL_PLATFORM=ON -DBUILD_TESTING=ON
cmake --build build-sdl --config Debug
ctest --test-dir build-sdl -C Debug --output-on-failure
.\build-sdl\Debug\pokox_window_demo.exe
```

This Windows command is **not yet verified on MSVC**. On 2026-11-20 the SDL
path was built and tested on Windows MSYS2 UCRT64 MinGW (g++ 16.2.0,
Ninja, vcpkg `x64-mingw-dynamic`): 21/21 CTest passed and the demo opened a
real window; see `../../docs/eng03-windows-laptop-evidence.txt`. Ensure the
SDL3 runtime DLL is available to the executable. A standalone SDL package can instead be found through `CMAKE_PREFIX_PATH` or `SDL3_DIR`; full `POKO_WITH_DEPENDENCIES` mode is not required for the platform module. `pokox_sdl_dummy` and `pokox_sdl_invalid_driver` are automated CTest checks; they do not validate a visible window. The Windows workflow enables this option for future CI but has not been run.

For an optional Linux/X11 test host, with an X11 display and the SDL demo built:

```sh
DISPLAY=:99 python3 engine/platform/tests/integration/x11_demo_smoke.py build-sdl/pokox_window_demo
```

Use an isolated X11 display; this test creates a unique window, resizes it, sends a `WM_DELETE_WINDOW` request and checks that the demo exits. It is not a Windows or Android test.

## Contract and limits

- The platform object owns one SDL video subsystem reference and one window. Initialize, poll and shut it down on the main thread. Destruction releases its own resources; close and quit events are requests, not automatic destruction.
- Only one platform instance should own the process-wide SDL event queue. The current pump consumes events it does not expose, including input; input is **not implemented**. SDL clients must not poll the same queue independently. This design must be revisited before input and other SDL event consumers are integrated.
- Resize events report current logical and pixel dimensions. They can be duplicated or reflect the latest size rather than every intermediate size. A failed SDL size query causes that resize event to be skipped.
- Window creation now accepts an explicit Vulkan intent as an ENG-03 prerequisite; the default remains a plain window. `SdlPlatform::native_window()` provides borrowed backend-specific access for future RHI integration. No GPU device, Vulkan surface, swapchain, Diligent renderer, D3D12/OpenGL backend or automatic fallback is implemented. Real Vulkan-window creation remains unverified. See `../../docs/eng03-progress.md`.
- Desktop SDL window behavior has been tested only on a Linux virtual X11 display. Windows/MSVC, MSYS2, Android activity/lifecycle integration, real hardware, high-DPI behavior and device-specific failure paths remain unverified.

## ENG-01 / ENG-02 lifecycle hardening

`pokox_sdl_platform_faults` compiles the **production backend source** against
`tests/fakes/SDL3/SDL.h` and controlled function implementations. It runs in the
dependency-free test build, without an SDL package. Its include path is private
to that test executable; the real backend target continues to use actual SDL3.
The double is deliberately only a subset of SDL: passing this test does not
prove SDL compatibility, real-window behavior, or Windows/Android acceptance.

It covers initialization/window failure and retry, repeated lifecycle calls,
destructor-only cleanup, external SDL-reference ownership, invalid dimensions
and titles, event filtering, high-DPI dimensions, failed size queries and
no-event output preservation. The real-SDL integration test additionally checks
reinitialization and destructor-only cleanup; those additions need a fresh run
on a host with SDL3. No production behavior or public API was changed.

The optional regression-sensitivity runner deliberately changes temporary
copies of the backend and requires every change to be caught by the tests:

```sh
python3 engine/platform/tests/unit/check_fault_sensitivity.py --cxx g++
```

This optional runner needs a GCC/Clang-compatible command line and is not part
of CTest. See `../../docs/eng01-eng02-hardening-evidence.txt` for independently
reproduced results and commands; historical SDL results are separate.

### Target acceptance checklist (still open)

- [ ] MSVC and MSYS2: configure, build and pass the full CTest suite with SDL on.
- [ ] Windows 11: run the demo; open, resize, minimize/restore and close it.
- [ ] Windows 11: verify logical/pixel sizing on a high-DPI display.
- [ ] Run the prepared GitHub Actions matrix and retain its logs.
- [ ] Android: supply the SDL activity/native entry point and lifecycle
  integration, then verify creation, resizing/orientation, suspend/resume and
  teardown on an actual target. The current desktop demo does not establish this.

Do not close INF-02/INF-04 or target-platform ENG-02 acceptance on the strength
of a function double, desktop compilation, or historical Linux logs.

## ENG-03 prerequisite: graphics intent and initial dimensions

`WindowConfig` has a trailing `graphics_api` field, defaulting to
`WindowGraphicsApi::none`. Existing `{title, width, height}` calls keep their
plain-window behavior. `WindowGraphicsApi::vulkan` requests `SDL_WINDOW_VULKAN`;
if SDL cannot create it, the result is `platform_failure`, with no automatic
fallback and no new live window. Unknown enum values are rejected.

`IPlatform::get_window_size()` provides logical and pixel dimensions without
waiting for a resize event. It leaves output unchanged on failure. Before
initialization it returns `not_initialized`; with no window it returns
`window_not_created`. Zero pixel dimensions are allowed: the future renderer
must avoid drawing/presenting until a drawable area returns.

`SdlPlatform::native_window()` is a borrowed, main-thread-only SDL pointer for
the platform/RHI bridge. Do not destroy it, reconfigure it, cache it across
window recreation, or expose it to gameplay code. Release renderer/surface
resources before destroying the window or platform. Adding `get_window_size`
is a source-level interface extension: any external IPlatform implementer must
implement it, and consumers must rebuild. No binary ABI stability is promised.

On a provisioned laptop, after building the existing SDL demo:

```powershell
.\build-sdl\Debug\pokox_window_demo.exe --vulkan
```

For a single-configuration generator the executable may instead be directly
under `build-sdl`. This requests a Vulkan-compatible **blank window only** and
prints its initial size; it is not proof of device creation or rendering.
The original plain-window demo and X11 smoke invocation remain supported.

## Renderer continuation

An opt-in Diligent/Vulkan clear seed now consumes this platform from
`../rhi/`. The window-only probes above are intentionally separate. The seed
has only dependency-double compile/control-flow evidence here; consult
`../rhi/README.md` before building/running it with real dependencies.
