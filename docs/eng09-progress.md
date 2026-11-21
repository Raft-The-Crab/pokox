# ENG-09 — experimental Vulkan depth test

The owner requested a review of ENG-01–08 followed by the next task. The review is in `eng01-eng08-review.md`. ENG-09 now has a desktop Vulkan prototype; its target-device and phase acceptance remains open.

## Implementation

- With `POKO_WITH_DEPTH_DEMO=ON` and the existing Vulkan and shader options, `pokox_depth` creates a D32 float swapchain depth attachment. If the depth view or format is missing, drawing fails rather than silently proceeding without depth. Device/driver support for this format is required; no alternative format selection is implemented.
- The graph-driven pass clears depth to 1.0, enables depth writes and `LESS` testing, and draws a near red triangle at depth 0.2 **first**, then a farther green triangle at depth 0.8. The red triangle should remain visible where they overlap. `--show-no-depth` deliberately disables depth testing and writes as a negative control: green then overwrites the same overlap. This is not a new general material or scene renderer.
- The depth and color resource names are logical frame-graph outputs only. Diligent and the swapchain own actual resource creation and transitions. Pipeline caching is scoped to the device and formats; destroy the pass before renderer shutdown. The default clear and triangle demos retain their original no-depth behavior.
- `depth.vert` and `depth.frag` compile as separate Vulkan 1.1 SPIR-V artifacts; pass the matching depth pair, not the triangle shaders. Artifact loading checks the header/size only, not shader interfaces or full module semantics.

## Verification on Linux

- The actual SDL/Diligent build passed 37/37 CTests with no warnings in the incremental build. The separate strict-warning SDL/shader baseline passed 31/31 CTests. A focused address/undefined-behavior sanitizer selection passed 8/8. Production sources and the new test were also checked with `-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Werror`. Vulkan 1.1 SPIR-V semantic validation passed for both generated depth shader artifacts. Third-party configuration warnings and tests based on doubles do not establish target-device acceptance.
- Mesa lavapipe software Vulkan on isolated X11/Xvfb: the triangle, depth and no-depth-control runs each submitted 1,800 frames and survived 640×480, 900×650 and 720×540 resizes, with zero captured Diligent errors and warnings. With depth enabled, sampled near/far/overlap pixels were red/green/red; with depth disabled they were red/green/green. The final window captures are `eng09-software-vulkan.png` and `eng09-software-vulkan-control.png`.
- `engine/render/tests/integration/test_triangle_x11_visual.py` checks these samples and window sizes. This isolated-display test needs X11, ImageMagick `import`, Pillow and a working Vulkan ICD. It explicitly passes `--no-validation`; therefore it is not Vulkan validation-layer evidence or Windows/hardware acceptance. X11 capture samples pixels from the displayed window, not a GPU readback or a full-image correctness proof.

## Running and remaining work

See `engine/render/README.md` for build and execution examples, including Windows. Use the depth demo with validation enabled by default where the validation layers are installed; do not treat `--no-validation` as validation evidence. Verify the near red triangle remains in front on the intended Windows GPU, compare with `--show-no-depth`, resize the window, and inspect graphics errors/warnings.

Hardware/Windows/MSVC, Android, OpenGL/ES, validation-layer, device-loss and production-lifecycle acceptance remain open. This is not the full rendering engine. ENG-10 (per-frame uniform buffer) remains the next planned task and was not implemented here.
