# Session report — ENG-14 through ENG-20 + audits

Date: 2026-11-21. Scope: work-queue ENG-14→ENG-20, consolidated audits,
bug fixes, and verification on the AMD Radeon Vulkan GPU.

## Delivered

| Task | Result | Evidence |
|---|---|---|
| ENG-14 CBOR config | `poko::cbor` decoder + `poko::config` loader, `--config` on all demos | `pokox_config_file_test` both trees; e2e on GPU |
| ENG-15 frame stats | `poko::stats::FrameStats` + Diligent duration query in ImGui demo | `gpu_ms=0.25` verified live |
| ENG-16 asset store | `AssetStore` + RAII `AssetHandle`, refcounted payloads | `pokox_asset_store_test` both trees |
| ENG-17 async queue | single worker thread, `request_async`/`poll_async`, owner-thread invariants | dedup/fail-fast/teardown tests |
| ENG-18 KTX2 texture | dependency-free KTX2 loader (4 UNORM/SRGB formats, full mip chains) + textured quad on `VulkanTrianglePass` | `pokox_ktx2_test`; `submitted=60, graphics_errors=0` on GPU |
| ENG-19 PMES mesh | hand-written binary mesh format + loader + `VulkanMeshPass` (real VB/IB, depth, indexed draw) + `pokox_cube` | `pokox_pokomesh_test`; cube renders `graphics_errors=0` |
| ENG-20 camera | platform mouse events + `OrbitCamera` + per-frame view_proj uniform | cube orbits with left-drag/wheel; `submitted=60, errors=0` |

## Audits performed

- **ENG-14**: clean (decoder bounds, UTF-8, merge order, LogGuard exit paths).
- **ENG-15**: clean (ring-buffer math, query refcounting, strip-build parity).
- **ENG-16**: 4 defects found & fixed — explicit-dtor double-release heap UAF,
  re-entrant loader UAF, copy-assign exception safety, moved-from crash,
  stale error out-param.
- **ENG-17**: 5 defects found & fixed — worker-start flag ordering,
  ready-asset reload, phase-2 dedup + acquire gaps, `noexcept`+`bad_alloc`.
- **ENG-18**: KTX2 header layout bug (96-byte header), 5 Diligent API
  mismatches fixed against real headers, SRB constant-snapshot ordering.
- **ENG-19**: `set_mesh` buffer leak on re-upload, `parse_pokomesh` null
  guard, fixture stride bug.
- **ENG-20**: `CreateShaderResourceBinding` missing `UseConstants=true`
  (VUID-08114), fake SDL mouse union extension.
- **Cross-cutting**: `version_integration` manifest updated twice for new
  unconditional sources (config/stats/resource/pokomesh).

## Verification

- `build/` (dependency-free): all CTest green including `version_integration`.
- `build-full/` (Diligent Vulkan): all CTest green.
- GPU-verified on AMD Radeon: `pokox_triangle --texture` (60 frames),
  `pokox_cube` builtin + `--mesh` PMES (60/30 frames), all
  `graphics_errors=0 graphics_warnings=0` with validation enabled.
- Previously excluded slow/demo suites run: 20/20 pass.

## Known gaps / not done

- ENG-04/05 still owe real-device OpenGL + interactive-resize evidence.
- KTX2: no Basis/UASTC transcode (AST-02), no sRGB transfer beyond format flag.
- PMES: unquantized float vertices; quantization/delta → AST-04.
- Camera: orbit-only, aspect set once (no live resize hook), normals not yet
  view-transformed (fine for orbit, ENG-21 handles lighting properly).
- No CBOR encoder (ENG-36), no async texture streaming, single worker thread.

## Files of note

New modules: `engine/foundation` (cbor, config, frame_stats),
`engine/resource` (asset_store, ktx2, pokomesh), `engine/render`
(camera, textured/mesh shaders, cube_demo), `engine/rhi`
(vulkan_mesh_pass + texture paths on triangle pass).
Progress docs: `docs/eng14..eng-progress.md`.
