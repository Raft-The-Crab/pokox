# 23 — Engine renderer

## Frame flow

Shadow and depth -> occlusion -> geometry -> lighting -> reflections -> post -> UI. Each pass is a node in the frame graph with declared inputs and outputs. The renderer never issues RHI calls directly; it builds a graph the RHI executes.

## Material system

A material is a set of typed properties plus a template that references a shader permutation. Properties are packed into a uniform buffer with a fixed layout derived from the template; the compiler rejects a material whose properties do not match its template.

```cbor
{
  "template": "pbr/opaque",
  "properties": {
    "albedo": { "texture": "brick_albedo" },
    "normal": { "texture": "brick_normal" },
    "metallic": 0.1,
    "roughness": 0.7
  }
}
```

Material templates declare which properties are required, their types and the shader permutation flags they trigger. Materials are data-only; no code execution. A developer can create a material in Studio by filling a property grid, never by writing shader code. The advanced material graph is an AA feature; A tier is a fixed set of templates.

| Template | A tier |
|---|---|
| Unlit, PBR opaque, PBR cutout, PBR transparent, emissive, UI, particle, sky | Yes |
| Layered terrain, hair, cloth, glass, water | AA |
| Custom graph | AAA partial |

## Camera

Cameras hold position, orientation, projection type, FOV, near and far planes, and a visibility mask. Perspective and orthographic supported. The renderer builds view and projection matrices once per frame and exposes them through a uniform block. Multiple cameras render to viewports with declared rects; the UI camera is separate and composites last. Frustum extraction is shared by culling and debug draw.

## Culling

Three stages: frustum rejection using bounding spheres, occlusion testing using hierarchical depth on supported hardware with a fallback to distance culling, and LOD selection by screen-space size. Results are deterministic: the order of visible draws is sorted by material, then mesh id, never by completion order.

## Lighting

Clustered forward lighting at A tier: screen-space clusters contain light lists; the fragment shader evaluates lights in the cluster. Eight shadow-casting directional cascades are optional; A tier uses four. Point and spot lights use clustered lists with a per-cluster cap of 32. IBL uses prefiltered environment maps and irradiance probes. Light data is packed into a storage buffer in a stable order so rendered output is reproducible.

## Shadows

Cascaded shadow maps split by logarithmic distance. Casters are filtered by the shadow camera frustum. PCF 3x3 at A tier, PCSS at AA, ray-traced shadows at AAA when hardware supports it. Shadow map resolution defaults to 2,048 per cascade on Windows and 1,024 on Android, halved under thermal stress.

## Reflections

A tier: no dynamic screen-space reflections; IBL probes only. AA: SSR with a depth-based validity test and a limited ray count. AAA: parallax-corrected probes and planar reflections. Any reflection feature can be disabled with no missing geometry — only the reflected contribution disappears.

## Post-processing order

1. Exposure and tonemap preparation
2. Bloom threshold and blur
3. Motion-vector generation from the previous frame's transforms
4. TAA resolve, or FXAA on A tier without motion vectors
5. Depth of field at AA and above
6. Volumetric fog and god rays at AA and above
7. Color grading LUT
8. Dither and output conversion

Tonemapping is ACES by default with an AgX option. HDR is RGBA16F throughout. Every effect is feature-flagged; disabling one must leave a correct image. G15 requires this to be tested for each AA/AAA feature.

## Sky, terrain, vegetation, particles

Sky is an atmospheric scattering shader with a time-of-day parameter, never a wall clock. Terrain uses heightmaps and splat maps with up to eight layers. Vegetation is instanced with wind driven by sim time. Particles are GPU sprites with a compute simulation at AAA and a CPU-emitted, GPU-animated path at A tier. None of these write to validated state.

## Debug rendering

`debug.line`, `debug.sphere`, `debug.aabb`, `debug.text` draw through a dedicated pass with no depth write by default. Debug draws are compiled out in release unless `POKO_DEBUG_DRAW` is set. The renderer exposes toggles for normals, overdraw, light complexity, cluster occupancy, LOD bands and culling results.

## Scalability

Three presets: A, AA, AAA partial, plus a user quality slider that scales resolution, shadow resolution, particle count and post effects within the selected tier. The runtime probes device capability and never enables a feature the device cannot support. A device that fails a feature falls back to the next tier without a crash or missing geometry.

## Renderer data ownership

All render state is derived from the scene and animation systems each frame. The renderer owns no authoritative game state. Anything it caches — culling results, visible lists, GPU buffers — is reconstructible. This is what allows the authority to run without a renderer at all.
