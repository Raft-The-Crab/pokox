# ENG-18 — KTX2 placeholder texture on quad

Status: implemented and verified on the real AMD Vulkan GPU.

## What was built

- `poko::resource::load_ktx2` — dependency-free KTX2 reader for uncompressed
  `R8G8B8A8_UNORM`/`B8G8R8A8_UNORM`, level-0 pixels, full bounds checking,
  64 MiB cap. Basis supercompression explicitly rejected (AST-02 scope).
- `TriangleMode::textured` + `VulkanTrianglePass::set_texture()` — the pass
  lazily creates a 2D texture + linear sampler + SRV on first draw, uploads
  CPU pixels via `UpdateTexture`, and binds `Tex` (set=0/binding=0) through
  the pipeline's static shader variable — the same pattern the ImGui pass
  uses for `FontTexture` (the SRB snapshots constants at creation, so the
  upload must happen before `CreateShaderResourceBinding`).
- `textured.vert`/`textured.frag` — fullscreen quad generated from
  `gl_VertexIndex` (no vertex buffer), UVs, `texture(sampler2D, uv)`.
- `pokox_triangle --texture file.ktx2` — loads via `load_ktx2`, selects the
  compiled-in textured shaders, renders the textured quad. `--texture` is
  rejected on the depth/uniform demo variants.
- `pokox_ktx2_test` — accept/reject fixture coverage in both trees.
- Fake Diligent headers extended (`ITexture`/`ISampler`/`TextureDesc`/
  `SamplerDesc`/`UpdateTexture`) so `pokox_triangle_pass_faults` still
  compiles the pass.

## Verified

- `pokox_triangle --texture checker.ktx2 --frames 60 --adapter 0` on the
  AMD Radeon GPU: `submitted=60 graphics_errors=0 graphics_warnings=0`.
- `pokox_ktx2_test` + `pokox_asset_store_test` pass in `build/` and
  `build-full/`; `triangle_pass_faults` and all demo input tests pass.

## Bugs found during implementation

- KTX2 header layout: fields start at offset 12 (96-byte header), level
  index at offset 96 — caught before first test run.
- Diligent API mismatches fixed against real headers: `RESOURCE_DIM_TEX_2D`,
  `SamplerDesc.AddressU/V/W`, `GetDefaultView(type)` returns an unowned
  raw view (sampler attached via `view->SetSampler`), `Box` field order is
  `{MinX,MaxX,MinY,MaxY,MinZ,MaxZ}`, `UpdateTexture` takes 7 args and
  `TextureSubResData` needs `Stride`+`DepthStride`.
- SRB constant-snapshot ordering: texture upload moved before pipeline
  creation so `Tex` is bound before `CreateShaderResourceBinding`.

## Mip-chain continuation

- `Ktx2Image` now carries `mips[]` — every level index entry is parsed with
  per-level dimensions (`max(1, dim>>i)`) and bounds-checked payload.
- `VulkanTrianglePass::set_texture_mips()` uploads the full chain
  (`MipLevels=N`, per-level `UpdateTexture`); `set_texture()` delegates
  with a single level.
- `pokox_triangle --texture` passes all loaded mips; demo verified with a
  3-level KTX2: `submitted=60 graphics_errors=0` on the AMD GPU.
- `pokox_ktx2_test` covers a 4x4+2x2 two-level fixture.

## sRGB continuation

- `Ktx2Format` gained `rgba8_srgb`(43)/`bgra8_srgb`(50); loader accepts all
  four UNORM/SRGB 8-bit formats and maps them distinctly.
- `set_texture_mips(..., bgra, srgb)` selects `TEX_FORMAT_*_UNORM_SRGB`
  (Diligent naming); demo derives both flags from `Ktx2Format`.
- Verified on AMD GPU with the multi-mip fixture: `submitted=30
  graphics_errors=0`. `pokox_ktx2_test` covers all four format accepts.

## Not done / future

- Other channel layouts/depth formats, Basis/UASTC transcode → AST-02,
  async texture streaming via ENG-17 queue.
- No texture streaming integration with ENG-17's async queue yet.
- `set_texture` replaces GPU objects on each call (no hot-swap diffing).

## Integration review, 2026-11-22

The earlier 96-byte-header claim and fixtures were incorrect. The reader now uses the Khronos 80-byte layout and non-array 2D fields, with bounds and regression tests. Corrected code has not yet been tested against independent KTX tooling or on a GPU. See `project-review-2026-11-22.md`.
