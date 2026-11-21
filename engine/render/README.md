# Renderer — frame-graph skeleton

ENG-06 adds a dependency-free, CPU-only graph in `include/poko/render/framegraph/` and `src/framegraph/`. This is not a GPU resource manager. The ENG-08 Vulkan triangle demo invokes an RHI draw-and-present callback as a graph pass; the existing Vulkan/OpenGL clear demos are not routed through it.

## Use

Register named passes with logical resources read or written, optionally explicit predecessor pass names, and a callback. Names are case-sensitive. Registration order need not be dependency order:

```cpp
#include "poko/render/framegraph/frame_graph.hpp"
using namespace poko::render;
FrameGraph graph;
// Check each returned status in production code.
(void)graph.add_pass({"draw", {"color"}, {}, {}, [] { /* consume color */ }});
(void)graph.add_pass({"prepare", {}, {"color"}, {}, [] { /* produce color */ }});
const auto plan = graph.compile(); // order: prepare, draw; does not run callbacks
if (plan.error == FrameGraphError::none) {
  const auto result = graph.execute(); // revalidates, then runs callbacks
  // Inspect result.error and result.completed.
}
```

A resource without a writer must be declared with `import_resource`. All readers of a written resource run after its sole writer, including if that name is imported; model input and output versions with different names when needed. Each logical name has at most one writer. Multiple writers, same-pass read/write, repeated declarations, missing producers, duplicate pass names, missing callbacks, unknown predecessor names and dependency cycles are rejected before *any* callback runs. Explicit predecessor and resource edges can overlap without creating duplicate dependencies. Independent ready passes are chosen by registration order.

`compile` returns the planned names without execution. `execute` validates afresh and runs one callback at a time; it stops on the first exception, reports `callback_failed` and the number of callbacks that completed. Previous side effects cannot be rolled back. Build/compile allocations may throw. The graph is single-threaded: graph and callback captures must remain alive through execution, and callbacks must not destroy the graph. Mutation, compile or nested execution during a callback returns `busy`. `clear` resets the graph outside execution.

## Build and verify

The static target `poko_framegraph` is part of the default build; `pokox_framegraph_tests` is registered when `BUILD_TESTING=ON`. No SDL or Diligent dependency is required.

```sh
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build --parallel 2
ctest --test-dir build --output-on-failure
python3 engine/render/tests/unit/check_framegraph_mutations.py --cxx c++
```

## Boundaries

The graph itself does not create or version real textures/buffers, derive barriers, track read-write/present states, pool transient resources, submit GPU commands, manage RHI lifetimes, parallelize passes or recover from device loss. The triangle demonstration invokes the RHI inside a callback rather than providing a general graph-to-GPU executor. These remain future work. The current strict single-writer rule rejects even explicitly ordered multiple writes rather than guessing version semantics. See `../../docs/eng06-progress.md`.

## ENG-07: build-time SPIR-V

Sample GLSL vertex and fragment shaders live in `shaders/`. Shader compilation is opt-in and requires a separately installed **host** `glslangValidator` or `glslang` executable. It is not bundled or downloaded. For example, using CMake 3.28+:

```sh
cmake -S . -B build-shaders -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON \
  -DPOKO_WITH_SHADER_ARTIFACTS=ON \
  -DPOKO_GLSLANG_EXECUTABLE=/absolute/path/to/glslangValidator
cmake --build build-shaders --parallel 2
ctest --test-dir build-shaders --output-on-failure
```

If the executable option is omitted, CMake searches the host PATH. The target `pokox_shaders` builds `shaders/<configuration>/triangle.vert.spv` and `triangle.frag.spv` under the build directory, targeting Vulkan 1.1. For multi-configuration generators, supply `--config Debug` to the build and `-C Debug` to CTest. Choose a host executable when cross-compiling; it must run on the machine performing the build.

Source, build-rule, compiler executable and selected tool identity changes trigger rebuilding. When the compilation rule runs and fails, it removes the old artifact rather than leaving stale output. A build system can fail before the rule runs (for example, if an input is missing), so consume outputs only after a successful build. Includes are unsupported until transitive dependency tracking is implemented. The build checks only the basic SPIR-V header/size, not full module semantics. Compiler versions are not pinned by this project, so outputs may vary across installations.

ENG-08 loads these sample artifacts in the experimental Vulkan triangle demo described below. General shader-interface reflection, runtime shader management and OpenGL/ES shader translation are not included. See `../../docs/eng07-progress.md` and `../../docs/eng08-progress.md`.


## ENG-08: Vulkan triangle through the frame graph

This default-off desktop demo requires SDL3 with Vulkan support, the pinned Diligent Vulkan backend and a runnable host glslang compiler. On a configured host with SDL3 and Vulkan SDK dependencies:

```sh
cmake -S . -B build-triangle -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON \
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON \
  -DPOKO_WITH_SHADER_ARTIFACTS=ON -DPOKO_WITH_TRIANGLE_DEMO=ON \
  -DPOKO_GLSLANG_EXECUTABLE=/absolute/path/to/glslangValidator
cmake --build build-triangle --parallel 2
ctest --test-dir build-triangle --output-on-failure
./build-triangle/pokox_triangle --vertex ./build-triangle/shaders/Debug/triangle.vert.spv \
  --fragment ./build-triangle/shaders/Debug/triangle.frag.spv --frames 120
```

For Windows/MSVC using the project's vcpkg setup (not yet verified on MSVC):

```powershell
cmake -S . -B build-triangle -G "Visual Studio 17 2022" -A x64 `
  "-DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  -DVCPKG_TARGET_TRIPLET=x64-windows -DBUILD_TESTING=ON `
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON `
  -DPOKO_WITH_SHADER_ARTIFACTS=ON -DPOKO_WITH_TRIANGLE_DEMO=ON `
  "-DPOKO_GLSLANG_EXECUTABLE=$env:VULKAN_SDK/Bin/glslangValidator.exe"
cmake --build build-triangle --config Debug --parallel 2
ctest --test-dir build-triangle -C Debug --output-on-failure
.\build-triangle\Debug\pokox_triangle.exe `
  --vertex .\build-triangle\shaders\Debug\triangle.vert.spv `
  --fragment .\build-triangle\shaders\Debug\triangle.frag.spv --frames 120
```

Ensure SDL3 and the Vulkan loader are available at runtime. Use `--adapter INDEX` when a known Vulkan adapter needs explicit selection; the actual index depends on the machine. Omit `--frames` for an interactive run. Validation is requested by default; `--no-validation` explicitly disables it for diagnostic runs and is not validation evidence. Only use SPIR-V produced by a successful shader build. Loading checks size and magic, not full SPIR-V validity.

The demo registers one forward pass whose callback clears, draws and presents. The graph tracks the logical color name only; the RHI owns the real backbuffer, its transitions and presentation. This triangle path has no depth attachment. The separate ENG-09 depth prototype is described below; a general resource-graph executor, OpenGL/ES fallback, device-loss handling and target-device acceptance remain future work. See `../../docs/eng08-progress.md` for evidence and Linux/X11 visual-test prerequisites.

## ENG-09: experimental depth test

In an existing build configured as in the Vulkan triangle section above, enable the separate depth target, rebuild, and pass the matching depth shaders:

```sh
cmake -S . -B build-triangle -DPOKO_WITH_DEPTH_DEMO=ON
cmake --build build-triangle --parallel 2
ctest --test-dir build-triangle --output-on-failure
./build-triangle/pokox_depth --vertex ./build-triangle/shaders/Debug/depth.vert.spv \
  --fragment ./build-triangle/shaders/Debug/depth.frag.spv --frames 120
```

For an existing Windows multi-configuration build:

```powershell
cmake -S . -B build-triangle -DPOKO_WITH_DEPTH_DEMO=ON
cmake --build build-triangle --config Debug --parallel 2
ctest --test-dir build-triangle -C Debug --output-on-failure
.\build-triangle\Debug\pokox_depth.exe `
  --vertex .\build-triangle\shaders\Debug\depth.vert.spv `
  --fragment .\build-triangle\shaders\Debug\depth.frag.spv --frames 120
```

The red near triangle is submitted before the green far triangle; red should remain in front in the overlap. Add `--show-no-depth` as an intentional control: green should then overwrite the overlap. Omit `--frames` to interactively resize the window. Select a device with `--adapter INDEX` if needed. Vulkan validation is requested by default; `--no-validation` disables it and is not validation-layer evidence. The demonstration requires a supported D32 float depth attachment and has no format fallback. Linux software Vulkan has been checked; Windows hardware and validation layers remain to be verified. `../../docs/eng09-progress.md` describes limits and evidence.

## ENG-10: per-frame uniform-buffer demo

In an existing build configured for the Vulkan triangle above, turn on the uniform demo and use its matching shaders:

```sh
cmake -S . -B build-triangle -DPOKO_WITH_UNIFORM_DEMO=ON
cmake --build build-triangle --parallel 2
ctest --test-dir build-triangle --output-on-failure
./build-triangle/pokox_uniform --vertex ./build-triangle/shaders/Debug/uniform.vert.spv \
  --fragment ./build-triangle/shaders/Debug/uniform.frag.spv --frames 120
```

For an existing Windows/MSVC multi-configuration build:

```powershell
cmake -S . -B build-triangle -DPOKO_WITH_UNIFORM_DEMO=ON
cmake --build build-triangle --config Debug --parallel 2
ctest --test-dir build-triangle -C Debug --output-on-failure
.\build-triangle\Debug\pokox_uniform.exe `
  --vertex .\build-triangle\shaders\Debug\uniform.vert.spv `
  --fragment .\build-triangle\shaders\Debug\uniform.frag.spv
```

The near triangle continuously cycles red and blue and remains in front of a green triangle. Omit `--frames` for an interactive run; 120 frames may end before a complete color cycle. Use `--adapter INDEX` for a specific Vulkan adapter. Validation is requested by default and requires installed validation layers; `--no-validation` disables it and is not validation evidence. The demo requires D32 float depth support and uses a dynamic per-frame color buffer; it does not implement a general renderer resource allocator. To run the optional visual test, use an isolated Linux/X11 display with ImageMagick `import`, Pillow and a working Vulkan ICD:

```sh
python3 engine/render/tests/integration/test_uniform_x11_visual.py \
  --exe ./build-triangle/pokox_uniform \
  --vertex ./build-triangle/shaders/Debug/uniform.vert.spv \
  --fragment ./build-triangle/shaders/Debug/uniform.frag.spv \
  --screenshot-red ./uniform-red.png --screenshot-blue ./uniform-blue.png
```

The script manipulates windows and explicitly disables validation; do not run it on a shared desktop. See `../../docs/eng10-progress.md` for evidence and remaining limitations.

## ENG-11: ImGui pass in the frame graph

`POKO_WITH_IMGUI_DEMO=ON` (requires dependencies, Vulkan and shader artifacts) builds `pokox_imgui_demo` with `imgui.vert`/`imgui.frag` SPIR-V artifacts. A two-node frame graph runs a CPU `ui imgui` pass (`NewFrame`, demo window, `Render`) before a `forward frame` pass that composites the triangle scene and the ImGui draw data inside one presented frame.

```sh
cmake -S . -B build-imgui -DPOKO_WITH_IMGUI_DEMO=ON
cmake --build build-imgui --parallel 2
ctest --test-dir build-imgui --output-on-failure
./build-imgui/pokox_imgui_demo \
  --vertex ./build-imgui/shaders/Debug/triangle.vert.spv \
  --fragment ./build-imgui/shaders/Debug/triangle.frag.spv \
  --imgui-vertex ./build-imgui/shaders/Debug/imgui.vert.spv \
  --imgui-fragment ./build-imgui/shaders/Debug/imgui.frag.spv --adapter 0
```

Only the font atlas texture is supported; other `ImTextureID`s and non-reset draw callbacks fail. Mouse state is fed from SDL; keyboard/text input, `RendererHasTextures` updates and non-Vulkan backends are future work. See `../../docs/eng11-progress.md`.

## ENG-12: ImGui F1 toggle and release strip

With `POKO_DEBUG=ON`, the `pokox_imgui_demo` window's demo panel can be toggled with **F1** (edge-triggered via `SDL_GetKeyboardState`); hiding it still runs an empty ImGui frame so no stale draw data is presented. With `POKO_DEBUG=OFF` every ImGui path is compiled out — `vulkan_imgui_pass.cpp` is excluded, `imgui::imgui` is not linked, and the demo runs the scene-only frame graph — so release binaries contain no ImGui symbols. See `../../docs/eng12-progress.md`.
