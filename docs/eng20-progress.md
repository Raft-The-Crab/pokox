# ENG-20 — Camera with view/projection

Status: implemented and verified on the real AMD Vulkan GPU.

## What was built

- **Platform mouse events** (`i_platform.hpp`, `sdl_platform.cpp`):
  `EventType::{mouse_motion, mouse_button, mouse_wheel}` with dx/dy,
  button/pressed, and wheel detents. Motion is gated on left-button held
  (`SDL_BUTTON_LMASK`) so orbit drags don't fire on hover. Fake SDL header
  extended for the fault-test build.
- **`poko::render::OrbitCamera`** (`engine/render/camera.*`): dependency-free
  orbit camera — yaw/pitch clamped, exponential wheel zoom, perspective
  projection (fov 0.9, near 0.1, far 100), produces a column-major
  projection*view mat4 for a std140 uniform.
- **`VulkanMeshPass::set_view_proj()`**: per-frame mat4 uploaded through a
  dynamic uniform buffer (`BIND_UNIFORM_BUFFER`, `USAGE_DYNAMIC`,
  `MAP_WRITE`/`DISCARD`) bound to the vertex shader's `Camera` block
  (set=0/binding=0) via `GetStaticVariableByName(SHADER_TYPE_VERTEX)` +
  `CreateShaderResourceBinding(..., true)` + `CommitShaderResources` —
  the same constant-snapshot pattern as ENG-18's texture binding.
- **`mesh.vert`**: `view_proj * vec4(aPos, 1.0)`; positions are now
  world-space (the builtin cube uses ±0.9 units at distance ~2.4).
- **`pokox_cube`**: left-drag orbits, wheel dollies; aspect set from the
  configured window size each run.

## Verified

- `pokox_cube --frames 60 --adapter 0`: `submitted=60
  graphics_errors=0 graphics_warnings=0` (real GPU, validation on).
- `pokox_sdl_platform_faults`, `pokox_pokomesh_test`, `pokox_ktx2_test`,
  `pokox_asset_store_test` all pass in `build/`.

## Bugs found during implementation

- `CreateShaderResourceBinding(&binding)` without `UseConstants=true`
  left `Camera` unbound → VUID-vkCmdDrawIndexed-08114. Same SRB
  constant-snapshot ordering rule as ENG-18; fixed by passing `true`.
- Fake `SDL_Event` union lacked mouse members — extended.

## Not done / future

- Orbit only (no pan/first-person modes); aspect updates on window
  resize aren't hooked yet (set once from config).
- Lighting still uses untransformed normals — correct-looking for orbit
  but real view-space lighting lands with ENG-21.
- Camera matrices are CPU-side float; Q16.16 deterministic math is
  ENG-60/MUT-09 scope.

## Integration review, 2026-11-22

A CPU regression test found and fixed a homogeneous-coordinate and Vulkan depth-range defect in the camera projection. See `integration-review-2026-11-22.md` for before/after evidence and verification limits. The corrected revision has not yet been visually verified on a GPU; prior submitted-frame counts do not establish visible output. Resize aspect remains open.


### Review update — 2026-11-22

The cube demo now derives camera aspect from drawable pixel dimensions at startup and on resize; zero-sized viewports retain the last valid aspect. CPU regression tests cover the calculation and the demo passed a stub-based syntax check. This supersedes earlier notes that aspect is fixed at startup. Actual SDL/Diligent, high-DPI and GPU resize behavior still require device validation. See `project-review-2026-11-22.md`.


### Linux software-rendering update — 2026-11-22

The corrected cube and camera built against real SDL3 and the pinned DiligentCore Vulkan backend. On Xvfb + Mesa llvmpipe, a synthetic mouse drag changed the rendered image, a resize produced a nonuniform frame, and 300 frames completed with validation requested and zero reported graphics errors/warnings. This is CPU software rendering, not physical-GPU or high-DPI acceptance. See `graphics-setup-2026-11-22.md`.
