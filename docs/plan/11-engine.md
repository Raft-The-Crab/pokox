# 11 — Engine, rendering and physics

## Layer structure

| Layer | Component | Policy |
|---|---|---|
| Platform | SDL3 window, input, audio | Temporary, behind `IPlatform`, long-lived in practice |
| RHI | DiligentCore | Permanent, never replaced |
| Renderer | Frame graph over Diligent | Ours |
| Physics | Custom C++ | Ours |
| Script | Mute VM | Defined in 04-mute.md |
| UI | Retained-mode in-game compositor | Ours, separate from app shells |

## Renderer decision

The owner's future direction is D3D12 first on supported Windows 11 builds/devices, then Vulkan, then OpenGL 4.6. Android 11 targets Vulkan, then OpenGL ES 3.2. These are plans, not implemented runtime fallback or hardware guarantees. The current project explicitly rejects D3D12 on MSYS2/MinGW and requires Windows SDK headers for the opt-in `POKO_D3D12=ON`; the flag remains OFF by default and is not a working renderer. A future Windows MSVC CI job may validate builds, but GPU execution needs separate testing. Linux is a development/test host, not a shipping target.

Shaders are authored once in PokoX shading language, compiled to SPIR-V, cross-compiled to GLSL ES via SPIRV-Cross. The HLSL path stays dormant until D3D12 is real.

## Frame graph

Shadow and depth -> geometry -> lighting and reflections -> post-process -> UI composite. Each pass declares resource dependencies; the graph orders execution.

## Determinism split

| System | Runs | Precision | Purpose |
|---|---|---|---|
| Sim physics | Client and authority, inside `.pkB` rules | Fixed-point Q16.16 | Position, collision, damage, inventory |
| Visual physics | Client only | f32 | Ragdolls, debris, cloth, particles |

Sim physics has deterministic broadphase, contact ordering and solver iteration order. Mute `physics.*` hostcalls route to sim or visual by field policy. A developer cannot make a cosmetic ragdoll affect validated state.

## Graphics tiers

**A tier (20, all platforms):** forward PBR, directional/point/spot lights, 4 cascaded shadow maps, normal mapping, HDR RGBA16F, ACES tone mapping, MSAA 4x, fog, skinned animation, instancing, frustum culling, 4-level LOD, bloom, SSAO, texture streaming, alpha blend/cutout, decals, GPU sprite particles, FXAA, color grading LUTs.

**AA tier (12, feature-detected):** clustered lighting, TAA, SSR, PCSS soft shadows, IBL probes, motion blur, depth of field, volumetric fog, terrain splatting, wind vegetation, GPU occlusion culling, planar reflections.

**AAA partial (20 curated):** RT shadows, RT AO, SSGI, virtual shadow maps, mesh shaders, manual virtualized geometry, screen-space SSS, strand hair, FFT water, volumetric clouds, atmospheric sky, FSR-style upscale, compute particles, GPU-driven indirect draw, bokeh DOF, parallax probes, baked light probes, auto exposure, tessellation, multi-layer materials.

Out of scope: full path tracing, neural upscaling, full GI, Nanite-style geometry, VR rendering.

## Physics tiers

**A tier (20):** static/dynamic/kinematic bodies, box/sphere/capsule colliders, SAP broadphase, SAT/GJK narrowphase, contact manifolds, sequential impulse solver, friction/restitution, character controller, raycasts, overlaps, mass properties, fixed/hinge/distance joints, triggers, sleep, fixed-step integration, gravity, collision layers, shape casts, deterministic ordering, Q16.16 sim path.

**AA tier:** compound colliders, convex hulls, static mesh colliders, ragdolls, spring/slider joints, motors, CCD, force fields, buoyancy, raycast vehicles, CPU verlet cloth, ropes, pre-fractured destruction, warm starting, solver islands.

**AAA partial (20+):** soft-body mass-spring lattices, limited FEM, SPH fluid, deformable terrain, stress fracture, articulated figures, IK, XPBD, shape matching, anisotropic friction, blade constraints, tensegrity, multi-body constraints, parallel islands, speculative contacts, cached manifolds, contact callbacks, per-body gravity, constraint breaking, deterministic replay mode.

## UI tiers

**A (18 components):** Panel, Label, Image, BevelButton, GlossInput, Checkbox, Radio, ComboBox, Slider, ProgressBar, Scrollbar, ListView, InventoryGrid, TabStrip, Tooltip, Dialog, WindowFrame, TitleBar.

**AA:** 9-slice, theme tokens, 150–250 ms animation, safe areas, DPI scaling, localization, accessibility tree, keyboard/gamepad nav, focus rings, drag-drop, list virtualization, rich text subset.

**AAA (~80%):** constraint solver, custom UI shaders, data-binding profiler, runtime theme editor, advanced vector shapes, in-world 3D UI. Out of scope: full SVG, complex-script shaping beyond basic RTL, VR UI, HTML import.

## Performance budgets

| Target | Windows 11 | Android 11 |
|---|---|---|
| Frame time A tier | <= 16.6 ms | <= 33 ms |
| Sim physics tick | <= 2 ms | <= 5 ms |
| Renderer CPU submit | <= 3 ms | <= 6 ms |
| Draw calls typical | <= 1,500 | <= 500 |
| Memory | <= 2 GB | <= 800 MB |
| Shader compile first run | <= 5 s | <= 15 s |

## Platform differences

Planned Windows D3D12 → Vulkan → OpenGL and Android Vulkan → OpenGL ES; no selection logic is implemented. SDL3 Win32 vs Android JNI lifecycle. Android must freeze sim on suspend and resume at the same tick, handle thermal throttling with adaptive tick and resolution scale, and respect cutouts. Windows uses a single instance and staged updates at exit.

## Test gates

G1/G2 require bit-identical sim physics replay across x64 and arm64 for 10k ticks. If this fails, stop. No Slice B until fixed. AA/AAA features must fall back cleanly to A tier (G15).
