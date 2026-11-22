# Linux graphics setup and review — 2026-11-22

## Scope

This is a Linux x86-64 development/test environment, not a replacement for the project's pinned vcpkg manifest or the required Windows and Android acceptance runs. Software rendering does not establish physical GPU or high-DPI device behavior. No phase gate was closed.

## Skills and C++20

The existing Graphify skill was retained. The `modern-cpp`, `variant-analysis`, and `address-sanitizer` skills were copied into `.agents/skills` from Trail of Bits commit `149d7b21f4067765b82e67029730b42d228ef4b4`; provenance and the CC BY-SA 4.0 license are included alongside them. The project remains C++20: suggestions requiring C++23/26, such as `std::expected` and `std::print`, were not introduced.

A focused variant review of the earlier allocation-in-`noexcept` issue found that `config::LogGuard` could terminate if argument or diagnostic construction allocated and failed. It also shut down the shared logger even when the guard had not acquired it (empty path or busy logger). The guard now catches setup/reporting exceptions and shuts down only a logger it successfully initialized. The test uses a controlled logger double: the original failed ownership testing and aborted under injected allocation failure; the repair passes ownership, allocation and reporting-exception cases. This is a focused review, not proof that every exception-safety variant has been found. A real spdlog build also revealed that this host's GCC 11 C++ library does not implement `atomic<shared_ptr>`. Logger pointer access now uses the existing shared/exclusive mutex instead, with an explicit `<memory>` include; all pointer accesses remain under that lock.

## Environment

SDL 3.4.20, Vulkan loader/headers, glslang 16.6.0, Xvfb 21.1.26, Mesa lavapipe and Mesa llvmpipe 26.3.1, Vulkan validation layers and spdlog 1.17.0 were installed into an isolated conda-forge environment; DiligentCore source and eight submodules were checked out at the project's pinned commit `b036337d68be2353c9950a85929acf796b9a6d50`. The project's configure step applied its existing local glslang `<cstdint>` compatibility patch to the source checkout. These dependencies are sandbox-local, not installed on a recipient's computer. `tools/dependencies/linux-graphics-conda-explicit.txt` records the package URLs for this Linux x86-64 environment; using it downloads third-party packages and may run their package scripts.

To recreate a similar local environment with a separately installed micromamba:

```sh
micromamba create -y -p /path/to/poko-graphics --file tools/dependencies/linux-graphics-conda-explicit.txt
```

Configure with the local environment in `CMAKE_PREFIX_PATH`, and allow CMake to fetch the project's pinned DiligentCore revision, or use `FETCHCONTENT_SOURCE_DIR_DILIGENTCORE` to point to a checked-out copy of that revision with submodules initialized. The graphics smoke build intentionally does **not** enable `POKO_WITH_DEPENDENCIES`, so it does not validate the full vcpkg manifest, ImGui, or Catch2 integration. The separate spdlog tests below were compiled directly against the conda package.

```sh
cmake -S . -B build-real -G Ninja -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH=/path/to/poko-graphics -DBUILD_TESTING=ON \
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON \
  -DPOKO_WITH_SHADER_ARTIFACTS=ON -DPOKO_WITH_CUBE_DEMO=ON \
  -DDILIGENT_NO_OPENGL=ON
cmake --build build-real --target pokox_cube pokox_vulkan_clear
```

Set `PATH`, `LD_LIBRARY_PATH`, and `PKG_CONFIG_PATH` to the local environment as needed. Prefer the documented vcpkg flow for the project's normal supported build.
To additionally compile the fallback target, reconfigure with `-DPOKO_WITH_FALLBACK_DEMO=ON -DDILIGENT_NO_OPENGL=OFF` and build `pokox_fallback_clear`; a software display may lack the required sRGB GLX format.

## Verification

- Strict C++20 dependency-free build: **39/39** CTest entries passed with `-Wall -Wextra -Wpedantic -Werror`.
- ASan + UBSan dependency-free build: **39/39** passed, including the new allocation/ownership tests; logger calls there use the controlled double.
- Real SDL3 configuration: **41/41** passed, including SDL dummy-driver tests. A separate SDL X11 integration test passed create, resize, close-event translation, quit and teardown on Xvfb. Some events were synthetic; this is not an interactive device test.
- The real SDL3 + pinned DiligentCore Vulkan/cube configuration built successfully and **44/44** CTest entries passed. This is not the full vcpkg manifest. Configure emitted 19 upstream Diligent/CMake deprecation warnings; they are not silently counted as a warning-free build.
- Vulkan loader identified llvmpipe as a **CPU** device, and the cube log showed the Khronos validation layer. A standalone Xvfb test rendered 300 frames, observed a changed image after a synthetic drag and a nonuniform image after resizing 800x600 to 700x500; the demo returned `graphics_errors=0 graphics_warnings=0`. This is a smoke test, not pixel-perfect visual, high-DPI or hardware acceptance.
- Real spdlog 1.17.0: the existing log-file integration test and a new guard ownership integration test both passed when compiled directly with GCC 11, C++20 and strict warnings. The full vcpkg logging configuration was not run.
- The real Diligent OpenGL fallback target also compiled, and the fallback-enabled build passed **44/44** CTest entries. A forced OpenGL run failed safely during SDL window creation with `Couldn't find matching GLX visual`. A separate GLX probe found 240 framebuffer configurations but **zero reporting sRGB capability** on this Xvfb display. Vulkan in the same fallback demo submitted 180 frames; no OpenGL pixels or backend color parity were verified. Xvfb also emitted nonfatal keyboard-map warnings. The sRGB requirement was not relaxed; real-device fallback testing remains open.

### Repeat the X11 smoke test

Requires Python with `python-xlib` installed, the built cube, the environment libraries/ICD on their usual paths, and a free X display. This optional test is not registered in default CTest. It uses Xvfb's 24-bit screen and synthetic mouse input, not a human interaction or high-DPI check.

```sh
export PATH=/path/to/poko-graphics/bin:$PATH
export LD_LIBRARY_PATH=/path/to/poko-graphics/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export DISPLAY=:88 SDL_VIDEODRIVER=x11
Xvfb :88 -screen 0 1280x800x24 -nolisten tcp &
xvfb_pid=$!
python engine/render/tests/integration/test_cube_x11_smoke.py build-real/pokox_cube
kill "$xvfb_pid"
```

## Next task and outstanding gates

The next numbered feature is **ENG-21 — directional light shader**, with acceptance that lighting responds. It follows ENG-20 and the current mesh shader's fixed prototype Lambert light is not that acceptance. The queue's rule says failed gates stop the queue: first verify the corrected cube/camera and earlier Vulkan, fallback, and resize requirements on the relevant target devices and complete the outstanding infrastructure checks. ENG-04/05, MSVC/CI and Android checks remain open. Do not claim GPU, Windows or Android acceptance from a software-only Linux test.

## Subsequent ENG-01–21 audit

The later owner-directed ENG-21 prototype and expanded audit supersede the next-task recommendation above. See `eng01-eng21-audit-2026-11-22.md`; the gates remain open.
