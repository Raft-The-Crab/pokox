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
  view*projection mat4 for a std140 uniform.
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
