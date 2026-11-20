# 22 — Engine RHI

## Contract

The RHI is the only module that calls DiligentCore. Everything above it uses engine types. The planned selection is D3D12 → Vulkan → OpenGL 4.6 on Windows and Vulkan → OpenGL ES 3.2 on Android, after support and device initialization are validated. No backend or automatic fallback exists yet; the D3D12 build option remains off by default and requires a supported Windows SDK toolchain.

## Interface surface

| Engine type | Wraps |
|---|---|
| `Device` | Diligent engine, queues, device caps |
| `Buffer` | Vertex, index, uniform, storage, staging |
| `Texture` | 1D/2D/3D, arrays, cubemaps, mip levels |
| `Sampler` | Filtering, addressing, comparison |
| `Shader` | SPIR-V module with reflection data |
| `Pipeline` | Vertex layout, blend, depth, raster, shader stages |
| `RenderPass` | Attachment declarations and load/store ops |
| `Framebuffer` | Bound attachments for a pass |
| `CommandList` | Draw, dispatch, copy, barrier commands |
| `DescriptorSet` | Resource bindings, bindless where supported |
| `Fence` | CPU-GPU synchronization |

All resource creation returns `Result`. Creating a resource on the wrong thread is a debug assertion. Every resource has a debug name that appears in the profiler.

## Device and queues

One graphics queue, one optional compute queue, one transfer queue. Present happens on the graphics queue. Compute work that can overlap with graphics is dispatched to the compute queue with semaphore dependencies. On OpenGL fallback there is one queue; overlap is disabled.

Device capabilities queried at init: max texture size, anisotropy, bindless support, ray tracing support, timestamp queries, subgroup ops. AA/AAA features enable only when capabilities are present; missing capability falls back cleanly to the A-tier path.

## Resource lifetimes

Resources are reference-counted handles. Destruction is deferred until the fence for the last command list using the resource has signaled. A per-frame retirement list holds destroyed handles for three frames in flight, which eliminates use-after-free without stalls. Debug mode poisons retired handles.

Transient render targets are allocated from a frame-greedy pool keyed by format, size and sample count. The pool reuses textures across frames; anything unused for 60 frames is released.

## Barriers and frame graph integration

The frame graph declares resource usage for each pass: read, write, read-write, present. The RHI derives barriers from the transition between consecutive passes. No pass writes a barrier manually. Hazard detection in debug asserts that a resource is not written by two passes without a declared dependency.

## Multi-frame in-flight

Three frames in flight. Per-frame resources: uniform buffers, descriptor sets, command lists and the transient pool. The CPU can prepare frame N+2 while the GPU executes N. Simulation state remains authoritative and is not double-buffered for gameplay; only render data is.

## Descriptor management

Bindless layouts on Vulkan where supported: one large descriptor set for textures and one for buffers, indexed by stable slot. Materials reference slots by integer. On OpenGL fallback, traditional per-draw descriptor sets are used through the same engine API; the material system is unaware of the difference.

## Shader pipeline

Source is authored in PokoX shading language, a C-like language with explicit stages and resource bindings.

```glsl
vertex VS(in vec3 position, in vec2 uv, out VSOut o) {
    o.position = MVP * vec4(position, 1.0);
    o.uv = uv;
}
fragment FS(in VSOut i, out vec4 color, sampler2D albedo) {
    color = texture(albedo, i.uv);
}
```

Compilation: source -> SPIR-V at build time -> SPIRV-Cross to GLSL ES for fallback. Results cached by source hash. Shader permutations are generated only for explicitly declared variants; a combinatorial explosion is a compile error. Reflection data extracts bindings and vertex layout so pipelines are built from the same source of truth.

Failed compilation shows the original source line and the generated GLSL side by side in Studio.

## Render passes

| Pass | Inputs | Outputs |
|---|---|---|
| Shadow depth | Light matrices, casters | Shadow maps |
| Main depth | Scene geometry | Depth target |
| Occlusion | Depth | Visibility results |
| G-buffer or forward color | Geometry, materials, lights | HDR color, normal, roughness |
| Lighting | G-buffer, shadow maps, probes | Lit HDR color |
| Reflections | Lit color, depth, probes | Reflected color |
| Post | HDR color, depth, motion vectors | LDR color |
| UI | In-game UI meshes, app shell meshes | Final color |

Pass order and resource dependencies are declared in the frame graph, not hardcoded.

## Debug features

Debug markers name every pass and draw range. GPU timestamp queries measure pass time where supported. A "render what" mode visualizes a single feature: albedo, normals, roughness, shadows only, overdraw or culling results. Pipeline statistics report draw calls, triangles, state changes and texture binds per frame. Validation layers are enabled in debug builds; any Vulkan error is a hard failure with the offending resource name.

## Platform notes

Vulkan on Android uses `VK_KHR_surface` with the SDL3 window. Device lost on Android is handled by tearing down the RHI and recreating it on resume; resources reload from cache. OpenGL ES fallback disables compute, bindless, MSAA resolve tricks and ray tracing, and caps texture size to device limits. D3D12, when enabled, uses the same engine API and HLSL cross-compiled from the shared source; it is not tested in CI until the build environment exists.

## Performance

Target CPU submit under 3 ms Windows and 6 ms Android at 1,500 and 500 draw calls respectively. Bindless and instancing are preferred; per-draw state changes are counted and reported. Texture streaming uses sparse or staged uploads depending on backend capability.
