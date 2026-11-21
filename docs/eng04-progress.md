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
