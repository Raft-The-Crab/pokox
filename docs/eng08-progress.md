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
