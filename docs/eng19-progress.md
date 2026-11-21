# ENG-19 — Hand-written binary mesh load

Status: implemented and verified on the real AMD Vulkan GPU.

## What was built

- **PMES format** (`poko/resource/pokomesh.hpp/.cpp`): hand-written
  little-endian binary mesh — `PMES` magic, version 1, vertex/index counts,
  vertex stride. Per-vertex float3 position + float3 normal (24-byte v1
  layout, stride >= 24 tolerated for forward compat). u32 indices.
  Loader is fully bounds-checked: exact file-size match, count/stride caps
  (4M verts / 16M indices / 64 MiB), index range validation, finite-value
  rejection, multiple-of-3 index count. `load_pokomesh(path)` +
  `parse_pokomesh(data,size)` for in-memory use.
- **`VulkanMeshPass`** (`engine/rhi`): first real vertex-buffer path —
  `MeshVertex` (pos+normal, 24 B), `set_mesh()` CPU copy → immutable
  `BIND_VERTEX_BUFFER`/`BIND_INDEX_BUFFER` buffers uploaded once per set,
  `InputLayout` (2 elements, stride 24, offsets 0/12), depth test +
  back-face culling, `SetVertexBuffers`/`SetIndexBuffer`/`DrawIndexed`.
- **`mesh.vert`/`mesh.frag`**: `layout(location=0/1)` pos+normal inputs;
  fragment does a fixed-light lambert term so face orientation reads.
  Positions are NDC-space (camera is ENG-20, real lighting ENG-21).
- **`pokox_cube`** demo: builtin 24-vert/36-index cube by default,
  `--mesh file.pmes` exercises the PMES loader end-to-end; same
  `--frames/--adapter/--no-validation/--config` surface as other demos.
- `pokox_pokomesh_test` in both trees: accept path + 8 reject cases
  (magic, version, stride, index range, truncation, NaN, missing/empty).

## Verified

- `pokox_pokomesh_test` PASS in `build/` and `build-full/`.
- `pokox_cube --frames 60 --adapter 0`: `submitted=60 graphics_errors=0`.
- `pokox_cube --mesh cube.pmes --frames 30`: `Loaded PMES mesh: 24
  vertices, 36 indices` + `submitted=30 graphics_errors=0`.
- `pokox_cube_missing_shader`/`pokox_cube_bad_args` CTest pass;
  `triangle_pass_faults` unaffected.

## Bugs found during implementation

- Test fixture wrote 28 B/vertex (extra float) vs declared 24 B stride —
  caught by the exact-size check; fixed fixture.
- `BufferDesc` has no `Format` member — index type comes from
  `DrawIndexedAttribs.IndexType` (`VT_UINT32`); removed the bad field.

## Not done / future

- Positions are NDC-space floats; quantization/delta compression is AST-04.
- No UVs/tangents/materials yet; camera (ENG-20) and lighting (ENG-21)
  will replace the fixed NDC transform and hardcoded light dir.
- `set_mesh` reallocates buffers per call — fine for load-once meshes;
  streaming/double-buffering comes with AST work.
