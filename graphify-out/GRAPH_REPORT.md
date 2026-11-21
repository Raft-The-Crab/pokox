# Graph Report - Project Poko  (2026-11-21)

## Corpus Check
- 240 files · ~141,559 words
- Verdict: corpus is large enough that graph structure adds value.
- Unclassified: 82 file(s) not represented in the graph (top: .blend 60, .glb 4, .frag 4)
- WARNING: 82 of 370 files seen (22%) have no supported extractor and are missing from this graph entirely. It may look complete while representing only part of the codebase.

## Summary
- 2332 nodes · 3227 edges · 211 communities (166 shown, 45 thin omitted)
- Extraction: 97% EXTRACTED · 3% INFERRED · 0% AMBIGUOUS · INFERRED: 99 edges (avg confidence: 0.86)
- Token cost: 0 input · 0 output

## Graph Freshness
- Built from commit: `59e80fab`
- Run `git rev-parse HEAD` and compare to check if the graph is stale.
- Run `graphify update .` after code changes (no API cost).

## Community Hubs (Navigation)
- json
- 21 — Engine core
- 12 — App interface (egui and Kotlin)
- VulkanTrianglePass::Impl
- OpenGLClearRenderer::Impl
- ClearBackend
- with
- vulkan_clear_faults.cpp
- subprocess
- LayoutElement
- triangle_demo.cpp
- debug/vulkan_diagnostics.hpp
- VulkanImGuiPass::Impl
- verify_desktop.py
- find_cross_mesh_overlaps
- Build status
- README.md
- 04 — Mute language and VM
- sdl_platform_faults.cpp
- 29 — R6 character asset adaptation (BoyR6 and BlockyR6)
- SdlPlatform
- 02 — Ordered work queue
- RenderError
- VulkanClearRenderer
- EvidenceTests
- 05 — pkB validation contract
- 06 — Network and wire protocol
- 10 — Poko Mod
- 24 — Engine physics
- 26 — Engine animation
- PlatformError
- VulkanDiagnostics
- GoldenHarnessTests
- 03 — Architecture and services
- 07 — Matchmaker, slots and donated servers
- 17 — Identity and security
- 22 — Engine RHI
- 23 — Engine renderer
- 25 — Engine audio
- 27 — Engine scene
- fakes/EngineFactoryVk.h
- vulkan_diagnostics.cpp
- 08 — Publishing, word versions and distribution
- 15 — Asset pipeline
- 16 — Localization and accessibility
- Actual directory structure
- ClearBackendSelection
- OpenGLClearRenderer
- FrameGraph
- FrameGraphError
- cstdint
- VulkanClearRenderer::Impl
- R6 preparation: file guide
- test_triangle_x11_visual.py
- 09 — Economy and Exchange
- 28 — Engine diagnostics
- Directory purposes
- OpenGLClearBackend
- VulkanClearBackend
- device/vulkan_clear_renderer.hpp
- .draw
- Chain
- Fake
- validate_production.py
- Contributing to PokoX
- triangle/EngineFactoryVk.h
- IDeviceContext
- 00 — Decision log
- 19 — Economy simulator
- Platform module
- VulkanImGuiPass
- BufferDesc
- GraphicsPipelineStateCreateInfo
- IBuffer
- Marketplace and Exchange Terms (draft)
- Terms of Service (draft)
- Virtual Currency and Refund Terms (draft)
- 18 — Contributors and community
- 20 — Legal and privacy
- Event
- IPlatform
- TestPlatform
- VulkanDiagnostics::Impl
- fakes/EngineFactoryVk.h
- RESOURCE_STATE_TRANSITION_MODE
- SwapChainDesc
- IPipelineState
- Contributor Covenant Code of Conduct
- IDeviceObject
- StartResult
- ENG-03 — Vulkan clear seed, acceptance still open
- Community Guidelines (draft)
- Developer Agreement (draft)
- Moderator Code of Conduct (draft)
- .native_window
- RHI — experimental Vulkan clear seed
- EngineGLCreateInfo
- build_refined.py
- StartStatus
- [Unreleased]
- frame_graph.cpp
- Children's Privacy Notice (draft)
- DMCA Policy (draft)
- End User Licence Agreement (draft)
- Privacy Policy (draft)
- 01 — Roadmap and gates
- FramePass
- FrameGraph::Compiled
- imgui/EngineFactoryVk.h
- IEngineFactoryVk
- ISwapChain
- RefCntAutoPtr
- vulkan_triangle_pass_test.cpp
- ReservationMigrationTests
- ENG-06 — frame-graph skeleton
- PokoX plan index
- Character visual review — 2026-11-20
- ENG-01–ENG-03 integration review
- ENG-01–ENG-05 folder and code audit
- ENG-04 — desktop fallback clear prototype (in progress)
- GitHub repositories
- FrameGraphExecution
- DiagnosticsError
- ISSUE_TEMPLATE/bug_report.md
- ISSUE_TEMPLATE/feature_request.md
- issue_templates/bug_report.md
- issue_templates/feature_request.md
- pull_request_template.md
- PokoX — Project Root
- Security Policy
- vcpkg.json
- Preservation-first R6 prototype
- ENG-01–ENG-04 code audit — 2026-11-21
- ENG-01–06 follow-up audit
- ENG-05 — desktop resize prototype (in progress)
- ENG-08 — forward-pass colored triangle
- ENG-09 — experimental Vulkan depth test
- ENG-10 — per-frame uniform buffer prototype
- Engine reorganization and ENG-01–03 review
- Data map (LEG-03)
- FrameGraphPlan
- composite
- BasicPlatformDebug
- command
- ENG-01–07 follow-up review
- ENG-01–ENG-08 follow-up review
- ENG-07 — build-time GLSL to SPIR-V
- Vendor DPA checklist (LEG-02)
- ENG-13 — Structured logging with file sink
- DrawAttribs
- logging.cpp
- trace_face.py
- CLAUDE.md
- .claude/CLAUDE.md
- BufferData
- Rect
- IRenderDevice
- opengl_clear_faults.cpp
- IEngineFactoryOpenGL
- OpenGLClearRenderer::initialize
- BlendModeRenderTargetDesc
- ITexture
- FakeBuffer
- WindowConfig
- VulkanTrianglePass
- IDeviceContext
- ImGuiContextGuard
- GraphicsPipelineDesc
- FakeVariable
- ISampler
- FakeContext
- FakeDevice
- SamplerDesc
- TextureDesc
- FakeChain
- 02-work-queue.md
- SHADER_TYPE
- TEXTURE_FORMAT
- SDL_Delay
- RasterizerDesc
- IRenderDevice
- tests/dependency_smoke.cpp
- ISwapChain
- LayoutElement
- RefCntAutoPtr
- IEngineFactoryVk
- Viewport
- DrawIndexedAttribs
- DEBUG_MESSAGE_SEVERITY
- IPipelineState
- IShaderResourceVariable
- Build status
- ClearConfig
- RefCntAutoPtr
- .CommitShaderResources

## God Nodes (most connected - your core abstractions)
1. `RenderError` - 43 edges
2. `VulkanImGuiPass::Impl` - 37 edges
3. `SdlPlatform` - 36 edges
4. `VulkanDiagnostics` - 28 edges
5. `VulkanClearRenderer` - 23 edges
6. `FrameGraph` - 22 edges
7. `VulkanTrianglePass::Impl` - 22 edges
8. `Build status` - 22 edges
9. `OpenGLClearRenderer::Impl` - 20 edges
10. `VulkanClearBackend` - 19 edges

## Surprising Connections (you probably didn't know these)
- `Bugs fixed` --references--> `init()`  [INFERRED]
  docs/audit-eng01-13.md → engine/foundation/src/logging.cpp
- `Windows laptop verification — 2026-11-20 (MSYS2 UCRT64 MinGW)` --references--> `ClearConfig`  [INFERRED]
  docs/build.md → engine/rhi/include/poko/rhi/device/vulkan_clear_renderer.hpp
- `Final audit round (pre-closeout)` --references--> `BIND_FLAGS`  [INFERRED]
  docs/audit-eng01-13.md → engine/rhi/tests/fakes/imgui/EngineFactoryVk.h
- `Final audit round (pre-closeout)` --references--> `DrawIndexedAttribs`  [INFERRED]
  docs/audit-eng01-13.md → engine/rhi/tests/fakes/imgui/EngineFactoryVk.h
- `Implementation` --references--> `composite()`  [INFERRED]
  docs/eng12-progress.md → engine/render/src/passes/imgui_demo.cpp

## Import Cycles
- None detected.

## Communities (211 total, 45 thin omitted)

### Community 0 - "json"
Cohesion: 0.06
Nodes (4): foot(), interp(), smooth(), send()

### Community 1 - "21 — Engine core"
Cohesion: 0.05
Nodes (39): 11 — Engine, rendering and physics, Determinism split, Frame graph, Graphics tiers, Layer structure, Performance budgets, Physics tiers, Platform differences (+31 more)

### Community 2 - "12 — App interface (egui and Kotlin)"
Cohesion: 0.05
Nodes (36): Client, 12 — App interface (egui and Kotlin), 2008 + modern rule, Android Kotlin bridge, App surfaces, Boundary, Input mapping, Rendering (+28 more)

### Community 3 - "VulkanTrianglePass::Impl"
Cohesion: 0.11
Nodes (17): TriangleMode, color, depth_disabled_control, depth_test, uniform_depth, read_spirv(), VulkanTrianglePass::Impl, binding (+9 more)

### Community 4 - "OpenGLClearRenderer::Impl"
Cohesion: 0.13
Nodes (11): OpenGLClearRenderer::Impl, cleanup_uncertain, context, device, gl_context, gl_library_loaded, initialized, platform (+3 more)

### Community 5 - "ClearBackend"
Cohesion: 0.28
Nodes (4): ClearBackend, ClearBackendSelection::clear_and_present(), ClearBackendSelection::ClearBackendSelection(), ClearBackendSelection::shutdown()

### Community 6 - "with"
Cohesion: 0.06
Nodes (34): MSYS2_LOCATION, jobs, windows-build, toolchain, name, on, pull_request, push (+26 more)

### Community 7 - "vulkan_clear_faults.cpp"
Cohesion: 0.13
Nodes (19): SDL_PropertiesID, SDL_WindowFlags, Sint64, native_window(), native_window(), NativeWindow, DILIGENT_CALL_TYPE previous(), SDL_CreateWindow() (+11 more)

### Community 8 - "subprocess"
Cohesion: 0.15
Nodes (4): run(), first_difference(), main(), update_golden()

### Community 9 - "LayoutElement"
Cohesion: 0.15
Nodes (13): EngineVkCreateInfo, AdapterId, EnableValidation, NumDeferredContexts, InputLayoutDesc, LayoutElements, NumElements, RenderDeviceInfo (+5 more)

### Community 12 - "VulkanImGuiPass::Impl"
Cohesion: 0.08
Nodes (20): read_spirv(), VulkanImGuiPass::Impl, binding, font_sampler, font_tex_id, font_texture, font_view, format (+12 more)

### Community 13 - "verify_desktop.py"
Cohesion: 0.14
Nodes (9): ClientData, ClientMessage, XEvent, run(), update_shader(), classify(), main(), parse_runtime() (+1 more)

### Community 14 - "find_cross_mesh_overlaps"
Cohesion: 0.18
Nodes (5): OverlapTests, _cross(), find_cross_mesh_overlaps(), intersection_area(), _signed_area()

### Community 15 - "Build status"
Cohesion: 0.08
Nodes (24): Build status, Character-validation regression check, Dependency-enabled builds, Dependency setup, ENG-01 / ENG-02 test hardening — 2026-11-20, ENG-01 platform interface, ENG-02 SDL window backend, ENG-03 continuation — opt-in clear-color source candidate (+16 more)

### Community 16 - "README.md"
Cohesion: 0.21
Nodes (7): Tools, Golden-file harness, Layout, Usage, Build version metadata, Layout, Version policy

### Community 17 - "04 — Mute language and VM"
Cohesion: 0.13
Nodes (15): 04 — Mute language and VM, Bytecode ISA, Capabilities, Compiler passes, Determinism contract, Goals, Lexical rules, Limits (+7 more)

### Community 18 - "sdl_platform_faults.cpp"
Cohesion: 0.15
Nodes (16): SDL_Event, type, window, SDL_WindowEvent, type, windowID, SDL_WindowID, SDL_CreateWindow() (+8 more)

### Community 19 - "29 — R6 character asset adaptation (BoyR6 and BlockyR6)"
Cohesion: 0.12
Nodes (16): 1. Head shading architecture, 29 — R6 character asset adaptation (BoyR6 and BlockyR6), 2. Missing pin attachments, Connection method, Diagnosed problems, Earlier simplified adaptation (legacy), Files, Known remaining issues (+8 more)

### Community 20 - "SdlPlatform"
Cohesion: 0.14
Nodes (9): SdlPlatform, has_last_resize_, initialized_, last_resize_, window_, SdlPlatform::destroy_window(), SdlPlatform::poll_event(), SdlPlatform::~SdlPlatform() (+1 more)

### Community 21 - "02 — Ordered work queue"
Cohesion: 0.12
Nodes (16): 02 — Ordered work queue, Canonical ID map, Corrections, additions and enhancements placement, Engine completion tasks (specs 21–28), First 20 tasks — exact execution order, Rules, Scaffold progress, Wave 0 — Infrastructure (INF) (+8 more)

### Community 22 - "RenderError"
Cohesion: 0.12
Nodes (16): RenderError, already_initialized, backbuffer_unavailable, backend_failure, device_creation_failed, factory_unavailable, invalid_window, native_window_unavailable (+8 more)

### Community 23 - "VulkanClearRenderer"
Cohesion: 0.14
Nodes (6): VulkanClearRenderer, cleanup_uncertain_, drawing_, impl_, VulkanClearRenderer::clear_and_present(), VulkanClearRenderer::shutdown()

### Community 25 - "05 — pkB validation contract"
Cohesion: 0.13
Nodes (14): 05 — pkB validation contract, Anti-cheat coverage, Authority policy, Binary layout, Clicker class rule (FIX F2, F8), Field encoding, Integration points, Limits (+6 more)

### Community 26 - "06 — Network and wire protocol"
Cohesion: 0.13
Nodes (14): 06 — Network and wire protocol, BitBuffer primitives, Channels, Delta encoding, Design contract, Frame structure, Jitter buffer and MTU, Lag reduction stack (+6 more)

### Community 27 - "10 — Poko Mod"
Cohesion: 0.13
Nodes (14): 10 — Poko Mod, Additional features, API, Appeals, Case management, Contract, Dashboard panels, Data model (+6 more)

### Community 28 - "24 — Engine physics"
Cohesion: 0.13
Nodes (14): 24 — Engine physics, Broadphase, Character controller, Collision shapes, Constraint solver, Debug visualization, Determinism rules, Fixed-point arithmetic (+6 more)

### Community 29 - "26 — Engine animation"
Cohesion: 0.13
Nodes (14): 26 — Engine animation, Animation clips, Animation events, Blend trees, Debug features, Determinism boundary, IK, Limits (+6 more)

### Community 30 - "PlatformError"
Cohesion: 0.13
Nodes (15): PlatformError, already_initialized, invalid_window_config, none, not_initialized, platform_failure, window_exists, window_not_created (+7 more)

### Community 31 - "VulkanDiagnostics"
Cohesion: 0.17
Nodes (5): VulkanDiagnostics, impl_, saved_, VulkanDiagnostics::start(), VulkanDiagnostics::messages()

### Community 33 - "03 — Architecture and services"
Cohesion: 0.25
Nodes (8): 03 — Architecture and services, Critical correction, Free-tier facts verified at planning time, Naming, Quota budget, Service assignments, Topology, Two-plane network summary

### Community 34 - "07 — Matchmaker, slots and donated servers"
Cohesion: 0.14
Nodes (14): 07 — Matchmaker, slots and donated servers, Allocation algorithm, Anti-abuse, API, BYO and donated registration, Capacity accounting, Cold start integration, Moderation visibility (+6 more)

### Community 35 - "17 — Identity and security"
Cohesion: 0.14
Nodes (13): 17 — Identity and security, Account hardening, Account lifecycle, Anti-cheat layers, Glyph map security note, Identity, Incident response, Recovery (+5 more)

### Community 36 - "22 — Engine RHI"
Cohesion: 0.14
Nodes (13): 22 — Engine RHI, Barriers and frame graph integration, Contract, Debug features, Descriptor management, Device and queues, Interface surface, Multi-frame in-flight (+5 more)

### Community 37 - "23 — Engine renderer"
Cohesion: 0.14
Nodes (13): 23 — Engine renderer, Camera, Culling, Debug rendering, Frame flow, Lighting, Material system, Post-processing order (+5 more)

### Community 38 - "25 — Engine audio"
Cohesion: 0.14
Nodes (13): 25 — Engine audio, Architecture, Asset integration, Budgets, Codecs, Debug features, Determinism boundary, Effects (+5 more)

### Community 39 - "27 — Engine scene"
Cohesion: 0.14
Nodes (13): 27 — Engine scene, Determinism boundary, Editor integration, Limits, Prefabs, Queries, Runtime lifecycle, Save state (+5 more)

### Community 40 - "fakes/EngineFactoryVk.h"
Cohesion: 0.40
Nodes (5): DEBUG_MESSAGE_SEVERITY, DEBUG_MESSAGE_SEVERITY_ERROR, DEBUG_MESSAGE_SEVERITY_FATAL_ERROR, DEBUG_MESSAGE_SEVERITY_INFO, DEBUG_MESSAGE_SEVERITY_WARNING

### Community 41 - "vulkan_diagnostics.cpp"
Cohesion: 0.17
Nodes (9): GraphicsMessages, errors, warnings, DILIGENT_CALL_TYPE capture(), since(), totals(), VulkanDiagnostics::messages(), VulkanDiagnostics::start_with_factory() (+1 more)

### Community 42 - "08 — Publishing, word versions and distribution"
Cohesion: 0.15
Nodes (12): 08 — Publishing, word versions and distribution, Automated gates, Distribution, GitHub distribution, Local build, Publishing pipeline, Registry schema, Review tiers (+4 more)

### Community 43 - "15 — Asset pipeline"
Cohesion: 0.15
Nodes (12): 15 — Asset pipeline, Audio handling, CDN and caching, Chunk packing, Contract, Fonts and text, Import settings, Limits (+4 more)

### Community 44 - "16 — Localization and accessibility"
Cohesion: 0.15
Nodes (12): 16 — Localization and accessibility, Accessibility tree, Contract, Data and limits, Extraction, Font fallback, Input accessibility, Platform hooks (+4 more)

### Community 45 - "Actual directory structure"
Cohesion: 0.15
Nodes (13): Actual directory structure, Counts, Directory inventory, ENG-03 clear-seed additions (2026-11-20), ENG-03 continuation (2026-11-20), ENG-03 diagnostics/evidence files (2026-11-20), ENG-04 fallback prototype (2026-11-21), ENG-09 additions (2026-11-21) (+5 more)

### Community 46 - "ClearBackendSelection"
Cohesion: 0.22
Nodes (4): ClearBackendSelection, owned_, ClearBackendSelection::start(), main()

### Community 47 - "OpenGLClearRenderer"
Cohesion: 0.15
Nodes (6): OpenGLClearRenderer, impl_, OpenGLClearBackend::clear_and_present(), OpenGLClearBackend::shutdown(), VulkanClearBackend::clear_and_present(), OpenGLClearRenderer::clear_and_present()

### Community 48 - "FrameGraph"
Cohesion: 0.18
Nodes (7): FrameGraph, executing_, imports_, passes_, FrameGraph::compile(), FrameGraph::execute(), main()

### Community 49 - "FrameGraphError"
Cohesion: 0.15
Nodes (13): FrameGraphError, busy, callback_failed, dependency_cycle, duplicate_import, duplicate_pass, duplicate_resource_use, empty_name (+5 more)

### Community 50 - "cstdint"
Cohesion: 0.10
Nodes (13): count_stamps(), main(), read_file(), IDeviceContext, IRenderDevice, ISwapChain, ITextureView, VulkanDiagnostics (+5 more)

### Community 51 - "VulkanClearRenderer::Impl"
Cohesion: 0.13
Nodes (10): VulkanClearRenderer::Impl, context, device, initialized, platform, resize_failed, swapchain, validation_enabled (+2 more)

### Community 52 - "R6 preparation: file guide"
Cohesion: 0.17
Nodes (10): Clips, R6 animation refinement (v2), Regeneration and verification, Transitions and combination with looks, Animations — one file per clip, per rig, Faces, R6 preparation: file guide, Starter clothing (+2 more)

### Community 54 - "09 — Economy and Exchange"
Cohesion: 0.17
Nodes (11): 09 — Economy and Exchange, Activity proof, API, Dynamic rate, Exchange, Fraud detection, Idempotency, Ledger invariant (+3 more)

### Community 55 - "28 — Engine diagnostics"
Cohesion: 0.17
Nodes (11): 28 — Engine diagnostics, Assertion policy, Console, Crash handler, Debug draw, Limits, Logging, Profiler (+3 more)

### Community 56 - "Directory purposes"
Cohesion: 0.12
Nodes (14): Folder scaffold, `applications`, `assets`, `backend`, `cmake`, Directory purposes, Directory structure, `docs` (+6 more)

### Community 57 - "OpenGLClearBackend"
Cohesion: 0.13
Nodes (9): SDL_GLAttr, OpenGLClearBackend, cleanup_error_, diagnostics_, renderer_, validation_, window_, OpenGLClearBackend::initialize() (+1 more)

### Community 58 - "VulkanClearBackend"
Cohesion: 0.17
Nodes (8): VulkanClearBackend, cleanup_error_, diagnostics_, enabled_, renderer_, validation_, window_, VulkanClearBackend::shutdown()

### Community 59 - "device/vulkan_clear_renderer.hpp"
Cohesion: 0.11
Nodes (10): SdlPlatform, IDeviceContext, IRenderDevice, ISwapChain, ITextureView, SdlPlatform, VulkanDrawCallback, VulkanClearBackend::initialize() (+2 more)

### Community 61 - "Chain"
Cohesion: 0.07
Nodes (8): Chain, desc, Context, Device, info, emit(), Factory, GetEngineFactoryVk()

### Community 63 - "Fake"
Cohesion: 0.20
Nodes (6): Fake, clean, draw, id, init, seen

### Community 64 - "validate_production.py"
Cohesion: 0.35
Nodes (5): capture(), floats(), capture(), floats(), check_spirv()

### Community 65 - "Contributing to PokoX"
Cohesion: 0.18
Nodes (10): Coding conventions, Commit and PR conventions, Contributing to PokoX, Development setup, Documentation and status updates, How work is organized, License and confidentiality, Questions (+2 more)

### Community 66 - "triangle/EngineFactoryVk.h"
Cohesion: 0.24
Nodes (7): ISwapChain, depth, desc, SwapChainDesc, ColorBufferFormat, DepthBufferFormat, TEXTURE_FORMAT

### Community 67 - "IDeviceContext"
Cohesion: 0.18
Nodes (5): ENG-11 — ImGui pass in the frame graph, Implementation, Reproduce / open work, Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon iGPU), IDeviceContext

### Community 68 - "00 — Decision log"
Cohesion: 0.18
Nodes (10): 00 — Decision log, Community, Economy, Final open items resolved, Language and runtime, Platform, Rendering and apps, Security (+2 more)

### Community 69 - "19 — Economy simulator"
Cohesion: 0.18
Nodes (10): 19 — Economy simulator, Agents, Analysis output, Contract, Gate, Honest limit, Scenario, Simulated week (+2 more)

### Community 70 - "Platform module"
Cohesion: 0.29
Nodes (6): Build, Contract and limits, ENG-01 / ENG-02 lifecycle hardening, Platform module, Renderer continuation, Target acceptance checklist (still open)

### Community 71 - "VulkanImGuiPass"
Cohesion: 0.20
Nodes (6): Frame, result, scene, ui, VulkanImGuiPass, impl_

### Community 72 - "BufferDesc"
Cohesion: 0.18
Nodes (10): BufferDesc, BindFlags, CPUAccessFlags, Name, Size, Usage, ShaderCreateInfo, ByteCode (+2 more)

### Community 73 - "GraphicsPipelineStateCreateInfo"
Cohesion: 0.20
Nodes (7): GraphicsPipelineStateCreateInfo, GraphicsPipeline, pPS, PSODesc, pVS, IRenderDevice, IShader

### Community 74 - "IBuffer"
Cohesion: 0.24
Nodes (4): IBuffer, values, IDeviceContext, ITextureView

### Community 75 - "Marketplace and Exchange Terms (draft)"
Cohesion: 0.20
Nodes (9): 1. Terminology, 2. Eligibility, 3. Supply and pricing, 4. Tax, dividends and caps, 5. Perks, 6. Misconduct, 7. Conservation, Marketplace and Exchange Terms (draft) (+1 more)

### Community 76 - "Terms of Service (draft)"
Cohesion: 0.20
Nodes (9): 1. Parties and eligibility, 2. Nature of the service, 3. User obligations, 4. Virtual currency, 5. User content and licences, 6. Enforcement, 7. Changes, Open questions for counsel (+1 more)

### Community 77 - "Virtual Currency and Refund Terms (draft)"
Cohesion: 0.20
Nodes (9): 1. Nature of Pokoins, 2. Ledger authority, 3. Grants and payouts, 4. Activity proof, 5. Transfers and holds, 6. Refunds, 7. Developer responsibility, Open questions for counsel (+1 more)

### Community 78 - "18 — Contributors and community"
Cohesion: 0.20
Nodes (9): 18 — Contributors and community, Contribution roles, Contributor portal, Donated servers, Donor agreement clauses, Glyph table v1, Governance, Onboarding ladder (+1 more)

### Community 79 - "20 — Legal and privacy"
Cohesion: 0.20
Nodes (9): 20 — Legal and privacy, Data map, Donor and contributor documents, Entity and documents, Jurisdictions, Operational legal tasks, Pre-launch gates, Privacy by design already in the architecture (+1 more)

### Community 80 - "Event"
Cohesion: 0.18
Nodes (8): Event, size, type, EventType, none, quit_requested, window_close_requested, window_resized

### Community 81 - "IPlatform"
Cohesion: 0.24
Nodes (3): IPlatform, ENG-03 prerequisite: graphics intent and initial dimensions, main()

### Community 82 - "TestPlatform"
Cohesion: 0.22
Nodes (5): TestPlatform, events_, initialized_, next_, window_

### Community 83 - "VulkanDiagnostics::Impl"
Cohesion: 0.18
Nodes (8): VulkanDiagnostics::Impl, baseline, break_on_error, break_on_error_changed, factory, installed, owns, previous

### Community 84 - "fakes/EngineFactoryVk.h"
Cohesion: 0.19
Nodes (12): Char, EngineVkCreateInfo, AdapterId, EnableValidation, NumDeferredContexts, ITextureView, RenderDeviceInfo, APIVersion (+4 more)

### Community 85 - "RESOURCE_STATE_TRANSITION_MODE"
Cohesion: 0.67
Nodes (3): RESOURCE_STATE_TRANSITION_MODE, RESOURCE_STATE_TRANSITION_MODE_NONE, RESOURCE_STATE_TRANSITION_MODE_TRANSITION

### Community 86 - "SwapChainDesc"
Cohesion: 0.20
Nodes (10): SwapChainDesc, ColorBufferFormat, DepthBufferFormat, Height, Width, TEXTURE_FORMAT, TEX_FORMAT_D32_FLOAT, TEX_FORMAT_RGBA8_UNORM (+2 more)

### Community 87 - "IPipelineState"
Cohesion: 0.22
Nodes (4): IPipelineState, var, IShaderResourceBinding, IShaderResourceVariable

### Community 88 - "Contributor Covenant Code of Conduct"
Cohesion: 0.22
Nodes (8): Attribution, Contributor Covenant Code of Conduct, Enforcement, Enforcement Guidelines, Enforcement Responsibilities, Our Pledge, Our Standards, Scope

### Community 89 - "IDeviceObject"
Cohesion: 0.15
Nodes (4): IBuffer, IDeviceObject, IShader, ITextureView

### Community 90 - "StartResult"
Cohesion: 0.20
Nodes (10): SelectedBackend, fallback, none, primary, StartResult, fallback_attempted, fallback_error, primary_error (+2 more)

### Community 91 - "ENG-03 — Vulkan clear seed, acceptance still open"
Cohesion: 0.22
Nodes (8): API references inspected, Diagnostics and laptop evidence continuation, ENG-03 — Vulkan clear seed, acceptance still open, Evidence from this continuation, Implemented source, Important limits, Next acceptance target, Status

### Community 92 - "Community Guidelines (draft)"
Cohesion: 0.22
Nodes (8): 1. Scope, 2. Expected conduct, 3. Prohibited conduct, 4. Moderation process, 5. Enforcement ladder, 6. Taxonomy status, Community Guidelines (draft), Open questions for counsel

### Community 93 - "Developer Agreement (draft)"
Cohesion: 0.22
Nodes (8): 1. Developer role, 2. Licence to PokoX, 3. Publishing obligations, 4. Review and distribution, 5. Economy terms, 6. Takedown and removal, Developer Agreement (draft), Open questions for counsel

### Community 94 - "Moderator Code of Conduct (draft)"
Cohesion: 0.22
Nodes (8): 1. Separate elevation, 2. Identity and safety, 3. Decision rules, 4. Evidence, 5. Misconduct, 6. Support, Moderator Code of Conduct (draft), Open questions for counsel

### Community 95 - ".native_window"
Cohesion: 0.15
Nodes (11): SDL_Window, SDL_InitFlags, main(), main(), push(), SDL_InitSubSystem(), SDL_QuitSubSystem(), update_imgui_io() (+3 more)

### Community 96 - "RHI — experimental Vulkan clear seed"
Cohesion: 0.22
Nodes (8): Desktop laptop build (MSVC path not yet verified), ENG-04 desktop fallback prototype (in progress), Graphics diagnostics and repeatable laptop verification, Included, Ownership and failure behavior, Reproducible dependency-free checks, RHI — experimental Vulkan clear seed, Verified Windows MinGW notes (2026-11-20)

### Community 97 - "EngineGLCreateInfo"
Cohesion: 0.22
Nodes (4): EngineGLCreateInfo, EnableValidation, NumDeferredContexts, Window

### Community 98 - "build_refined.py"
Cohesion: 0.32
Nodes (3): ease(), foot(), interp()

### Community 99 - "StartStatus"
Cohesion: 0.33
Nodes (6): StartStatus, already_started, cleanup_failed, deferred, failed, success

### Community 100 - "[Unreleased]"
Cohesion: 0.25
Nodes (7): Added, Added (continued), Changed, Changelog, Fixed, Notes, [Unreleased]

### Community 102 - "Children's Privacy Notice (draft)"
Cohesion: 0.25
Nodes (7): 1. Age gates, 2. Information collected, 3. No profiling, 4. Retention and deletion, 5. Contact, Children's Privacy Notice (draft), Open questions for counsel

### Community 103 - "DMCA Policy (draft)"
Cohesion: 0.25
Nodes (7): 1. Registered agent, 2. Notice, 3. Action, 4. Counter-notice, 5. Repeat infringers, DMCA Policy (draft), Open questions for counsel

### Community 104 - "End User Licence Agreement (draft)"
Cohesion: 0.25
Nodes (7): 1. Licence granted, 2. Restrictions, 3. Open source components, 4. Updates, 5. Termination, End User Licence Agreement (draft), Open questions for counsel

### Community 105 - "Privacy Policy (draft)"
Cohesion: 0.25
Nodes (7): 1. What we collect, 2. Lawful basis and regimes, 3. Privacy by design already in the architecture, 4. Deletion, 5. Vendors, Open questions for counsel, Privacy Policy (draft)

### Community 106 - "01 — Roadmap and gates"
Cohesion: 0.25
Nodes (7): 01 — Roadmap and gates, Dependency map, Explicitly deferred, Gate register, Phases, Pre-mortem summary, What exists at each checkpoint

### Community 107 - "FramePass"
Cohesion: 0.25
Nodes (7): FramePass, after, execute, name, reads, writes, FrameGraph::add_pass()

### Community 108 - "FrameGraph::Compiled"
Cohesion: 0.25
Nodes (5): FrameGraph::Compiled, detail, error, order, FrameGraph::import_resource()

### Community 109 - "imgui/EngineFactoryVk.h"
Cohesion: 0.07
Nodes (32): BufferData, DataSize, pData, BufferDesc, BindFlags, CPUAccessFlags, Name, Size (+24 more)

### Community 113 - "vulkan_triangle_pass_test.cpp"
Cohesion: 0.14
Nodes (4): main(), reset(), VulkanClearRenderer::Impl, VulkanDiagnostics::Impl

### Community 115 - "ENG-06 — frame-graph skeleton"
Cohesion: 0.29
Nodes (4): Boundaries, ENG-06 — frame-graph skeleton, Implemented, Verification

### Community 116 - "PokoX plan index"
Cohesion: 0.29
Nodes (6): Current continuation, Known shallow areas, Non-negotiable rules, PokoX plan index, Reading order, Status

### Community 119 - "Character visual review — 2026-11-20"
Cohesion: 0.33
Nodes (5): Character visual review — 2026-11-20, Face direction and attachment concern, Helper visibility, Scope and result, Windows build status

### Community 120 - "ENG-01–ENG-03 integration review"
Cohesion: 0.33
Nodes (5): Acceptance and outstanding work, ENG-01–ENG-03 integration review, Fresh checks in this sandbox, Organization, Wiring examined

### Community 121 - "ENG-01–ENG-05 folder and code audit"
Cohesion: 0.33
Nodes (5): Checks, ENG-01–ENG-05 folder and code audit, Fixes, Folder layout, Still open

### Community 122 - "ENG-04 — desktop fallback clear prototype (in progress)"
Cohesion: 0.33
Nodes (5): Build and run on a provisioned Windows machine, ENG-04 — desktop fallback clear prototype (in progress), Implementation and boundaries, Local regression results — 2026-11-21, Verification and remaining work

### Community 123 - "GitHub repositories"
Cohesion: 0.33
Nodes (5): Creation, Decision (2026-11-21): monorepo, GitHub repositories, Open decisions before creating anything, Proposed repositories

### Community 124 - "FrameGraphExecution"
Cohesion: 0.33
Nodes (4): FrameGraphExecution, completed, detail, error

### Community 125 - "DiagnosticsError"
Cohesion: 0.33
Nodes (6): DiagnosticsError, already_active, backend_failure, busy, factory_unavailable, none

### Community 126 - "ISSUE_TEMPLATE/bug_report.md"
Cohesion: 0.33
Nodes (5): Additional context, Description, Environment, Logs / evidence, Reproduction

### Community 127 - "ISSUE_TEMPLATE/feature_request.md"
Cohesion: 0.33
Nodes (5): Alternatives considered, Motivation, Proposed behavior, Summary, Task-queue impact

### Community 128 - "issue_templates/bug_report.md"
Cohesion: 0.33
Nodes (5): Additional context, Description, Environment, Logs / evidence, Reproduction

### Community 129 - "issue_templates/feature_request.md"
Cohesion: 0.33
Nodes (5): Alternatives considered, Motivation, Proposed behavior, Summary, Task-queue impact

### Community 130 - "pull_request_template.md"
Cohesion: 0.33
Nodes (5): Changes, Checklist, Remaining gaps, Summary, Verification

### Community 131 - "PokoX — Project Root"
Cohesion: 0.33
Nodes (6): Character assets, Current scaffold status, Important caveat, Live Blender, PokoX — Project Root, Where things are

### Community 132 - "Security Policy"
Cohesion: 0.33
Nodes (5): Reporting a vulnerability, Scope notes, Security Policy, Supported versions, What to expect

### Community 133 - "vcpkg.json"
Cohesion: 0.33
Nodes (5): builtin-baseline, dependencies, description, name, version-string

### Community 134 - "Preservation-first R6 prototype"
Cohesion: 0.40
Nodes (4): Evidence and limits, Preservation-first R6 prototype, Proposed engine integration — not implemented, Reproduce with Blender 5.2.1

### Community 135 - "ENG-01–ENG-04 code audit — 2026-11-21"
Cohesion: 0.40
Nodes (4): Audit verification, ENG-01–ENG-04 code audit — 2026-11-21, Fixes, Remaining risks

### Community 136 - "ENG-01–06 follow-up audit"
Cohesion: 0.40
Nodes (4): ENG-01–06 follow-up audit, Improvements, Remaining acceptance work, Verification (Linux, GCC 11.5 and CMake 3.31)

### Community 137 - "ENG-05 — desktop resize prototype (in progress)"
Cohesion: 0.40
Nodes (4): Behavior, ENG-05 — desktop resize prototype (in progress), Target-device follow-up, Verification

### Community 138 - "ENG-08 — forward-pass colored triangle"
Cohesion: 0.40
Nodes (4): ENG-08 — forward-pass colored triangle, Implemented, Reproduction and remaining work, Verification — Linux development host

### Community 139 - "ENG-09 — experimental Vulkan depth test"
Cohesion: 0.40
Nodes (4): ENG-09 — experimental Vulkan depth test, Implementation, Running and remaining work, Verification on Linux

### Community 140 - "ENG-10 — per-frame uniform buffer prototype"
Cohesion: 0.40
Nodes (4): ENG-10 — per-frame uniform buffer prototype, Implementation, Reproduce / open work, Verification — Linux development host

### Community 141 - "Engine reorganization and ENG-01–03 review"
Cohesion: 0.40
Nodes (4): Engine reorganization and ENG-01–03 review, Fresh verification, Remaining limits, Source organization

### Community 142 - "Data map (LEG-03)"
Cohesion: 0.40
Nodes (4): Colour by plane, Data map (LEG-03), Deletion behaviour, Privacy controls already in the architecture

### Community 143 - "FrameGraphPlan"
Cohesion: 0.40
Nodes (4): FrameGraphPlan, detail, error, order

### Community 144 - "composite"
Cohesion: 0.18
Nodes (5): ENG-12 — ImGui F1 toggle and release strip, Implementation, Reproduce / open work, Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon), composite()

### Community 146 - "command"
Cohesion: 0.60
Nodes (4): command(), VersionIntegrationTests, build_and_version(), git()

### Community 147 - "ENG-01–07 follow-up review"
Cohesion: 0.50
Nodes (3): Checks and limits, ENG-01–07 follow-up review, Findings and improvements

### Community 148 - "ENG-01–ENG-08 follow-up review"
Cohesion: 0.50
Nodes (3): Changes, ENG-01–ENG-08 follow-up review, Still open

### Community 149 - "ENG-07 — build-time GLSL to SPIR-V"
Cohesion: 0.50
Nodes (3): ENG-07 — build-time GLSL to SPIR-V, Implemented, Verification and boundaries

### Community 150 - "Vendor DPA checklist (LEG-02)"
Cohesion: 0.50
Nodes (3): Gate, Required evidence per vendor, Vendor DPA checklist (LEG-02)

### Community 151 - "ENG-13 — Structured logging with file sink"
Cohesion: 0.40
Nodes (4): ENG-13 — Structured logging with file sink, Implementation, Reproduce / open work, Verification — Windows laptop (MSYS2 UCRT64)

### Community 152 - "DrawAttribs"
Cohesion: 0.50
Nodes (3): DrawAttribs, Flags, NumVertices

### Community 153 - "logging.cpp"
Cohesion: 0.09
Nodes (29): Bugs fixed, Gap-closure round 2, Known remaining gaps (documented, not defects), Post-implementation audit — ENG-01 through ENG-13, Test updates, Verified, Config, echo_to_console (+21 more)

### Community 157 - "BufferData"
Cohesion: 0.50
Nodes (3): BufferData, DataSize, pData

### Community 158 - "Rect"
Cohesion: 0.29
Nodes (6): Int32, Rect, Bottom, Left, Right, Top

### Community 160 - "opengl_clear_faults.cpp"
Cohesion: 0.20
Nodes (3): OpenGLClearRenderer::shutdown(), SDL_GL_DestroyContext(), SDL_GL_UnloadLibrary()

### Community 161 - "IEngineFactoryOpenGL"
Cohesion: 0.25
Nodes (4): IEngineFactoryOpenGL, DebugMessageCallbackType, GetEngineFactoryOpenGL(), GlFactory

### Community 163 - "OpenGLClearRenderer::initialize"
Cohesion: 0.24
Nodes (8): SDL_FunctionPointer, SDL_GLContext, default_framebuffer_is_srgb(), OpenGLClearRenderer::initialize(), SDL_GL_CreateContext(), SDL_GL_GetProcAddress(), SDL_GL_LoadLibrary(), SDL_GL_MakeCurrent()

### Community 167 - "BlendModeRenderTargetDesc"
Cohesion: 0.11
Nodes (18): BLEND_FACTOR, BLEND_FACTOR_INV_SRC_ALPHA, BLEND_FACTOR_ONE, BLEND_FACTOR_SRC_ALPHA, BLEND_FACTOR_ZERO, BLEND_OPERATION, BLEND_OPERATION_ADD, BlendDesc (+10 more)

### Community 168 - "ITexture"
Cohesion: 0.11
Nodes (12): ITexture, TEXTURE_VIEW_TYPE, TEXTURE_VIEW_SHADER_RESOURCE, TextureData, NumSubresources, pSubresources, TextureSubResData, pData (+4 more)

### Community 169 - "FakeBuffer"
Cohesion: 0.40
Nodes (3): FakeBuffer, releases, storage

### Community 170 - "WindowConfig"
Cohesion: 0.15
Nodes (10): WindowConfig, graphics_api, height, title, width, WindowGraphicsApi, none, opengl (+2 more)

### Community 171 - "VulkanTrianglePass"
Cohesion: 0.18
Nodes (4): VulkanTrianglePass, impl_, VulkanTrianglePass::draw(), VulkanTrianglePass::draw_and_present()

### Community 177 - "GraphicsPipelineDesc"
Cohesion: 0.11
Nodes (19): DepthStencilDesc, DepthEnable, DepthWriteEnable, GraphicsPipelineDesc, BlendDesc, DepthStencilDesc, DSVFormat, InputLayout (+11 more)

### Community 178 - "FakeVariable"
Cohesion: 0.18
Nodes (7): FakePipeline, font_texture, frame_data, FakeVariable, buffer, object, view

### Community 179 - "ISampler"
Cohesion: 0.17
Nodes (5): ISampler, FakeSampler, FakeTargetView, FakeTextureView, sampler

### Community 180 - "FakeContext"
Cohesion: 0.13
Nodes (7): MAP_FLAGS, MAP_FLAG_DISCARD, MAP_FLAG_NONE, MAP_TYPE, MAP_READ, MAP_WRITE, FakeContext

### Community 182 - "SamplerDesc"
Cohesion: 0.17
Nodes (12): FILTER_TYPE, FILTER_TYPE_LINEAR, SamplerDesc, AddressU, AddressV, AddressW, MagFilter, MinFilter (+4 more)

### Community 183 - "TextureDesc"
Cohesion: 0.17
Nodes (12): RESOURCE_DIMENSION, RESOURCE_DIM_TEX_2D, TextureDesc, ArraySize, BindFlags, Format, Height, MipLevels (+4 more)

### Community 185 - "02-work-queue.md"
Cohesion: 0.22
Nodes (3): Backend, Mute, Server

### Community 186 - "SHADER_TYPE"
Cohesion: 0.22
Nodes (5): SHADER_TYPE, SHADER_TYPE_PIXEL, SHADER_TYPE_VERTEX, FakeShader, type

### Community 187 - "TEXTURE_FORMAT"
Cohesion: 0.20
Nodes (10): SwapChainDesc, ColorBufferFormat, DepthBufferFormat, Height, Width, TEXTURE_FORMAT, TEX_FORMAT_D32_FLOAT, TEX_FORMAT_RGBA8_UNORM (+2 more)

### Community 188 - "SDL_Delay"
Cohesion: 0.31
Nodes (8): main(), build_demo_window(), main(), main(), main(), main(), SDL_Delay(), SDL_GetError()

### Community 189 - "RasterizerDesc"
Cohesion: 0.22
Nodes (9): CULL_MODE, CULL_MODE_BACK, CULL_MODE_NONE, FILL_MODE, FILL_MODE_SOLID, RasterizerDesc, CullMode, FillMode (+1 more)

### Community 193 - "LayoutElement"
Cohesion: 0.12
Nodes (16): INPUT_ELEMENT_FREQUENCY, INPUT_ELEMENT_FREQUENCY_PER_VERTEX, LayoutElement, BufferSlot, Frequency, HLSLSemantic, InputIndex, IsNormalized (+8 more)

### Community 196 - "Viewport"
Cohesion: 0.29
Nodes (7): Viewport, Height, MaxDepth, MinDepth, Width, X, Y

### Community 197 - "DrawIndexedAttribs"
Cohesion: 0.12
Nodes (17): Final audit round (pre-closeout), BIND_FLAGS, BIND_INDEX_BUFFER, BIND_NONE, BIND_SHADER_RESOURCE, BIND_UNIFORM_BUFFER, BIND_VERTEX_BUFFER, DRAW_FLAGS (+9 more)

### Community 198 - "DEBUG_MESSAGE_SEVERITY"
Cohesion: 0.40
Nodes (5): DEBUG_MESSAGE_SEVERITY, DEBUG_MESSAGE_SEVERITY_ERROR, DEBUG_MESSAGE_SEVERITY_FATAL_ERROR, DEBUG_MESSAGE_SEVERITY_INFO, DEBUG_MESSAGE_SEVERITY_WARNING

### Community 201 - "Build status"
Cohesion: 0.22
Nodes (8): Build status, Build status, Commands, Full dependencies, Golden files, Historical build notes — not current status, Historical build notes (unverified), Toolchain matrix

### Community 207 - "ClearConfig"
Cohesion: 0.29
Nodes (6): Windows laptop verification — 2026-11-20 (MSYS2 UCRT64 MinGW), ClearConfig, adapter_id, defer_failed_cleanup, enable_depth, enable_validation

## Knowledge Gaps
- **403 isolated node(s):** `factory`, `previous`, `baseline`, `owns`, `installed` (+398 more)
  These have ≤1 connection - possible missing edges or undocumented components. (Counts symbols only; 1504 node(s) total have ≤1 connection when file, concept and rationale nodes are included.)
- **45 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `Platform module` connect `Platform module` to `IPlatform`?**
  _High betweenness centrality (0.064) - this node is a cross-community bridge._
- **Are the 12 inferred relationships involving `SdlPlatform` (e.g. with `main()` and `main()`) actually correct?**
  _`SdlPlatform` has 12 INFERRED edges - model-reasoned connections that need verification._
- **What connects `factory`, `previous`, `baseline` to the rest of the system?**
  _403 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `json` be split into smaller, more focused modules?**
  _Cohesion score 0.06398809523809523 - nodes in this community are weakly interconnected._
- **Why does `ENG-03 prerequisite: graphics intent and initial dimensions` connect `IPlatform` to `WindowConfig`, `Platform module`, `.native_window`?**
  _High betweenness centrality (0.048) - this node is a cross-community bridge._
- **Should `21 — Engine core` be split into smaller, more focused modules?**
  _Cohesion score 0.046511627906976744 - nodes in this community are weakly interconnected._
- **Why does `Build status` connect `Build status` to `README.md`, `ClearConfig`?**
  _High betweenness centrality (0.047) - this node is a cross-community bridge._