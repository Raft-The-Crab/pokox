# Graph Report - Project Poko  (2026-11-24)

## Corpus Check
- 460 files · ~408,410 words
- Verdict: corpus is large enough that graph structure adds value.
- Unclassified: 258 file(s) not represented in the graph (top: .blend 60, .mute 59, .ast 56)
- WARNING: 258 of 773 files seen (33%) have no supported extractor and are missing from this graph entirely. It may look complete while representing only part of the codebase.

## Summary
- 5347 nodes · 8742 edges · 462 communities (343 shown, 119 thin omitted)
- Extraction: 97% EXTRACTED · 3% INFERRED · 0% AMBIGUOUS · INFERRED: 304 edges (avg confidence: 0.88)
- Token cost: 0 input · 0 output

## Graph Freshness
- Built from commit: `d6139c3d`
- Run `git rev-parse HEAD` and compare to check if the graph is stale.
- Run `graphify update .` after code changes (no API cost).

## Community Hubs (Navigation)
- json
- 21 — Engine core
- 12 — App interface (egui and Kotlin)
- VulkanTrianglePass::Impl
- ExprOp
- VulkanImGuiPass
- with
- pokomesh_test.cpp
- test_triangle_x11_visual.py
- VulkanTrianglePass
- OpenGLClearRenderer::Impl
- imgui/EngineFactoryVk.h
- VulkanImGuiPass::Impl
- subprocess
- find_cross_mesh_overlaps
- Build status
- README.md
- 04 — Mute language and VM
- vector
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
- xxhash64
- BufferDesc
- GoldenHarnessTests
- 03 — Architecture and services
- 07 — Matchmaker, slots and donated servers
- 17 — Identity and security
- 22 — Engine RHI
- 23 — Engine renderer
- 25 — Engine audio
- 27 — Engine scene
- fakes/EngineFactoryVk.h
- IDeviceContext
- 08 — Publishing, word versions and distribution
- 15 — Asset pipeline
- 16 — Localization and accessibility
- Actual directory structure
- pokomesh.cpp
- string
- FrameGraph
- FrameGraphError
- AddressSanitizer (ASan)
- R6 preparation: file guide
- Console
- 09 — Economy and Exchange
- 28 — Engine diagnostics
- Directory purposes
- C++23 Features (Usable Today)
- console.cpp
- Kind
- DeclarationNode
- Chain
- OrbitCamera
- TypeTag
- rules
- Contributing to PokoX
- triangle/EngineFactoryVk.h
- IDeviceContext
- 00 — Decision log
- 19 — Economy simulator
- cstdio
- config_file_test.cpp
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
- cube_golden.py
- ExprNode
- fakes/EngineFactoryVk.h
- config.cpp
- SwapChainDesc
- IPipelineState
- Contributor Covenant Code of Conduct
- IDeviceObject
- AssetStore
- ENG-03 — Vulkan clear seed, acceptance still open
- Community Guidelines (draft)
- Developer Agreement (draft)
- Moderator Code of Conduct (draft)
- rules
- RHI — experimental Vulkan clear seed
- FrameStats
- evaluator.cpp
- array
- [Unreleased]
- frame_graph.cpp
- Children's Privacy Notice (draft)
- DMCA Policy (draft)
- End User Licence Agreement (draft)
- Privacy Policy (draft)
- 01 — Roadmap and gates
- FramePass
- FrameGraph::Compiled
- rules
- IEngineFactoryVk
- ISwapChain
- RefCntAutoPtr
- ExprKind
- ReservationMigrationTests
- ENG-06 — frame-graph skeleton
- PokoX plan index
- AssetHandle
- VulkanMeshPass::Impl
- Character visual review — 2026-11-20
- ENG-01–ENG-03 integration review
- ENG-01–ENG-05 folder and code audit
- memory
- GitHub repositories
- FrameGraphExecution
- MeshVertex
- ISSUE_TEMPLATE/bug_report.md
- ISSUE_TEMPLATE/feature_request.md
- issue_templates/bug_report.md
- issue_templates/feature_request.md
- pull_request_template.md
- OpenGLESClearBackend
- Security Policy
- vcpkg.json
- Final audit — MUT-01 through MUT-12
- ENG-01–ENG-04 code audit — 2026-11-21
- ENG-01–06 follow-up audit
- ENG-05 — desktop resize prototype (in progress)
- ENG-08 — forward-pass colored triangle
- ENG-09 — experimental Vulkan depth test
- ENG-10 — per-frame uniform buffer prototype
- Engine reorganization and ENG-01–03 review
- Data map (LEG-03)
- FrameGraphPlan
- Job
- vulkan_clear_android.cpp
- rules
- ENG-01–07 follow-up review
- ENG-01–ENG-08 follow-up review
- ENG-07 — build-time GLSL to SPIR-V
- Vendor DPA checklist (LEG-02)
- ENG-13 — Structured logging with file sink
- DrawAttribs
- logging.cpp
- mesh/EngineFactoryVk.h
- CLAUDE.md
- .claude/CLAUDE.md
- ktx2_test.cpp
- argparse
- Analyzer
- rules
- Box
- lexer.cpp
- LayoutElement
- FakeDevice
- BlendModeRenderTargetDesc
- TextureData
- LayoutElement
- Safe C++ Idioms
- OpenGLClearESRenderer
- IDeviceContext
- VulkanDiagnostics::Impl
- Modern C++
- GraphicsPipelineDesc
- semantic.cpp
- SamplerDesc
- VulkanClearRenderer::Impl
- Parser
- ENG-17 — Async load queue
- TextureDesc
- FakeChain
- MUT-01 — lexer core progress (2026-11-22)
- bytecode.cpp
- Compiler Hardening
- ClearBackendSelection
- IRenderDevice
- vulkan_clear_faults.cpp
- ISwapChain
- C++20 Features (Default Practice)
- RefCntAutoPtr
- IEngineFactoryVk
- Variant Analysis Report
- DrawIndexedAttribs
- Context
- verify_desktop.py
- load_state_snapshot
- Build status
- size_t
- parser.cpp
- StatementNode
- TextureDesc
- Findings to address
- SDL_Event
- AssetStore::State
- Contracts
- linux-lit-cube-golden
- EngineGLCreateInfo
- Root Cause and Expansion Axes
- VulkanMeshPass
- program.cpp
- Value
- Kind
- steps
- SamplerDesc
- Type
- Reader
- Searching: The Abstraction Ladder
- Ktx2Image
- FakeContext
- Triage: Deciding Whether a Candidate Is Real
- IPipelineState
- TriangleMode
- os
- SamplerDesc
- Anti-Patterns: Legacy to Modern C++
- linux-build
- string
- device/vulkan_clear_renderer.hpp
- evaluator_test.cpp
- windows-build
- camera.cpp
- EvalErrorCode
- SDL_Delay
- GraphicsPipelineStateCreateInfo
- TextureDesc
- Post-implementation audit — ENG-01 through ENG-13
- Entry
- parse_arithmetic
- VulkanClearAndroidRenderer::Impl
- interface
- ENG-20 — Camera with view/projection
- cbor.cpp
- ENG-22 — lit-cube screenshot golden
- StatementParser
- interface
- Variant Analysis
- 0001_word_reservations.sql
- MUT-01–MUT-03 integration audit (2026-11-22)
- BytecodeErrorCode
- Linux graphics setup and review — 2026-11-22
- mute/README.md
- WindowConfig
- ExpressionParser
- Box
- Reflection (Game-Changer)
- pkb_draft.cpp
- mut03-progress.md
- Concepts
- The Ladder
- SnapshotErrorCode
- Integration review — 2026-11-22
- OpenGLClearRenderer
- sdl_platform_faults.cpp
- IEngineFactoryOpenGL
- Reporting a Variant Hunt
- bit
- StatementErrorCode
- MUT-11 and `.pkB` progress audit — 2026-11-22
- DrawIndexedAttribs
- transform
- OpenGLClearESRenderer::Impl
- PokoActivity
- Instruction
- DEBUG_MESSAGE_SEVERITY
- DeclarationErrorCode
- StatementKind
- MUT-01–07 follow-up audit — 2026-11-22
- Level
- config.cpp
- VulkanTrianglePass::draw
- Memory Safety
- primary
- lexer_contract_test.cpp
- Token
- Essential Compiler Flags
- DrawAttribs
- VulkanDiagnostics
- mcp_client.py
- RasterizerDesc
- Deducing this
- 30 — Mute v1 completion plan
- build_apk.sh
- Mute
- DirectionalLight
- statement_test.cpp
- MUT-08–10 progress and integration audit — 2026-11-22
- Opcode
- SemanticErrorCode
- ENG-01–ENG-22 hardening audit — 2026-11-22
- Renderer — frame-graph skeleton
- DeclarationKind
- MUT-01–05 audit — 2026-11-22
- NumericBinding
- MUT-02 — arithmetic AST (2026-11-22)
- Project layout check — 2026-11-22
- Post-MUT audit fixes and G1/G2 preflight
- Error
- Position
- Frame
- tests/dependency_smoke.cpp
- lexer_test.cpp
- ENG-04 — desktop fallback clear prototype (in progress)
- MUT-08–10 completion audit — 2026-11-22
- MUT-01–12: MUT-12 implementation and three audit passes
- declaration_test.cpp
- SHADER_TYPE
- VulkanClearRenderer::initialize
- main
- FloatEnvironment
- MUT-01–03 follow-up fixes and audit (2026-11-22)
- PlatformError
- NumericType
- DurationQueryState
- Audit findings and open work
- PokoX — Project Root
- EventType
- MUT-06 — initial functions and locals
- 11 — Engine, rendering and physics
- ParseErrorCode
- TestPlatform
- Frame
- ArithmeticOp
- VmErrorCode
- RefCntAutoPtr
- TraceTests
- MSVC Toolchain (this machine)
- Factory
- SemanticDiagnostic
- ProgramDiagnostic
- decode_item
- TypeDef
- Device
- build_refined.py
- frame_stats.cpp
- ENG-14 — CBOR config loader
- run_register_vm
- MUT-13 — Mute v1 scope and API matrix (APPROVED)
- rem_pio2_large
- WindowSize
- PokoMeshVertex
- TextureMip
- analyze
- Poko UI Design
- composite
- AppState
- Overrides
- MUT-04 — debug ImGui arithmetic console (2026-11-22)
- main
- .draw
- FrameKind
- 2026-11-24
- MUT-07 — initial if/while and runaway trap (2026-11-22)
- DeclarationParser
- Session report — ENG-14 through ENG-20 + audits
- load_ktx2
- Poko Engine Development
- MUT-05 — print hostcall to the debug console (2026-11-22)
- IRenderDevice
- VulkanDiagnostics
- BasicPlatformDebug
- RefCntAutoPtr
- StateDecl
- Mute bytecode and program snapshots
- Entry
- linux-build
- windows-msvc-nodeps
- TypeKind
- Sink
- Depth
- LoopScope
- checksum
- Depth
- Program

## God Nodes (most connected - your core abstractions)
1. `RenderError` - 58 edges
2. `StatementParser` - 45 edges
3. `Position` - 45 edges
4. `ExprOp` - 45 edges
5. `VulkanClearAndroidRenderer::Impl` - 42 edges
6. `DeclarationParser` - 41 edges
7. `VulkanImGuiPass::Impl` - 37 edges
8. `VulkanTrianglePass::Impl` - 37 edges
9. `Token` - 33 edges
10. `OpenGLClearESRenderer` - 33 edges

## Surprising Connections (you probably didn't know these)
- `Full MUT-01–20 audit — committed and pushed (c7a411f)` --references--> `prepare_globals()`  [INFERRED]
  .workbuddy-ai/memory/2026-11-24.md → mute/src/program/program.cpp
- `Bugs found during implementation` --references--> `Box`  [INFERRED]
  docs/eng18-progress.md → engine/rhi/tests/fakes/triangle/EngineFactoryVk.h
- `State behavior` --references--> `ProgramState`  [INFERRED]
  docs/mut11-pkb-audit-2026-11-22.md → mute/include/poko/mute/state.hpp
- `Fixed or improved` --references--> `LexOptions`  [INFERRED]
  docs/mut01-mut03-followup-audit-2026-11-22.md → mute/include/poko/mute/lexer.hpp
- `Bugs found during implementation` --references--> `SDL_Event`  [INFERRED]
  docs/eng20-progress.md → engine/platform/tests/fakes/SDL3/SDL.h

## Import Cycles
- None detected.

## Communities (462 total, 119 thin omitted)

### Community 0 - "json"
Cohesion: 0.07
Nodes (4): foot(), interp(), smooth(), dump_tree()

### Community 1 - "21 — Engine core"
Cohesion: 0.12
Nodes (17): 21 — Engine core, Coding standards, Console and CVars, Design principles, ECS, Error handling, Filesystem abstraction, Hot reload (+9 more)

### Community 2 - "12 — App interface (egui and Kotlin)"
Cohesion: 0.05
Nodes (36): Client, 12 — App interface (egui and Kotlin), 2008 + modern rule, Android Kotlin bridge, App surfaces, Boundary, Input mapping, Rendering (+28 more)

### Community 3 - "VulkanTrianglePass::Impl"
Cohesion: 0.07
Nodes (21): VulkanTrianglePass::Impl, binding, depth_format, format, fragment, mode, owner, pipeline (+13 more)

### Community 4 - "ExprOp"
Cohesion: 0.05
Nodes (37): ExprOp, assign, assign_add, assign_and, assign_div, assign_mod, assign_mul, assign_or (+29 more)

### Community 5 - "VulkanImGuiPass"
Cohesion: 0.17
Nodes (6): ENG-12 — ImGui F1 toggle and release strip, Implementation, Reproduce / open work, Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon), VulkanImGuiPass, impl_

### Community 6 - "with"
Cohesion: 0.12
Nodes (17): with, cache-environment, environment-file, environment-name, fetch-depth, if-no-files-found, install, micromamba-version (+9 more)

### Community 7 - "pokomesh_test.cpp"
Cohesion: 0.11
Nodes (17): count_stamps(), main(), read_file(), main(), make_pmes(), put32(), putf(), write() (+9 more)

### Community 8 - "test_triangle_x11_visual.py"
Cohesion: 0.13
Nodes (5): ClientData, ClientMessage, XEvent, find_window(), find_window()

### Community 9 - "VulkanTrianglePass"
Cohesion: 0.11
Nodes (11): Bugs found during implementation, ENG-18 — KTX2 placeholder texture on quad, Integration review, 2026-11-22, Mip-chain continuation, Not done / future, Verified, What was built, VulkanTrianglePass (+3 more)

### Community 10 - "OpenGLClearRenderer::Impl"
Cohesion: 0.07
Nodes (22): SDL_FunctionPointer, SDL_GLContext, default_framebuffer_is_srgb(), OpenGLClearRenderer::Impl, cleanup_uncertain, context, device, gl_context (+14 more)

### Community 11 - "imgui/EngineFactoryVk.h"
Cohesion: 0.05
Nodes (34): BufferData, DataSize, pData, BufferDesc, BindFlags, CPUAccessFlags, Name, Size (+26 more)

### Community 12 - "VulkanImGuiPass::Impl"
Cohesion: 0.06
Nodes (20): VulkanImGuiPass::draw(), VulkanImGuiPass::Impl, binding, font_sampler, font_tex_id, font_texture, font_view, format (+12 more)

### Community 13 - "subprocess"
Cohesion: 0.09
Nodes (8): main(), find_window(), main(), main(), find_window(), main(), expression(), run()

### Community 14 - "find_cross_mesh_overlaps"
Cohesion: 0.18
Nodes (5): OverlapTests, _cross(), find_cross_mesh_overlaps(), intersection_area(), _signed_area()

### Community 15 - "Build status"
Cohesion: 0.06
Nodes (31): Build status, Character-validation regression check, Dependency-enabled builds, Dependency setup, ENG-01 / ENG-02 test hardening — 2026-11-20, ENG-01 platform interface, ENG-02 SDL window backend, ENG-03 continuation — opt-in clear-color source candidate (+23 more)

### Community 16 - "README.md"
Cohesion: 0.13
Nodes (11): Evidence and limits, Preservation-first R6 prototype, Proposed engine integration — not implemented, Reproduce with Blender 5.2.1, Tools, Golden-file harness, Layout, Usage (+3 more)

### Community 17 - "04 — Mute language and VM"
Cohesion: 0.12
Nodes (16): 04 — Mute language and VM, Branch encoding decision, Bytecode ISA, Capabilities, Compiler passes, Determinism contract, Goals, Lexical rules (+8 more)

### Community 18 - "vector"
Cohesion: 0.09
Nodes (8): Bytecode, DeclarationParser, Result, ExpressionParser, StatementParser, write(), check(), main()

### Community 19 - "29 — R6 character asset adaptation (BoyR6 and BlockyR6)"
Cohesion: 0.12
Nodes (16): 1. Head shading architecture, 29 — R6 character asset adaptation (BoyR6 and BlockyR6), 2. Missing pin attachments, Connection method, Diagnosed problems, Earlier simplified adaptation (legacy), Files, Known remaining issues (+8 more)

### Community 20 - "SdlPlatform"
Cohesion: 0.13
Nodes (13): SdlPlatform, has_last_resize_, initialized_, last_resize_, pending_resize_, window_, SdlPlatform::create_window(), SdlPlatform::destroy_window() (+5 more)

### Community 21 - "02 — Ordered work queue"
Cohesion: 0.11
Nodes (19): 02 — Ordered work queue, Broader review, 2026-11-22, Canonical ID map, Corrections, additions and enhancements placement, Engine completion tasks (specs 21–28), First 20 tasks — exact execution order, Integration review, 2026-11-22, Mute v1 completion tasks (planned; span later waves) (+11 more)

### Community 22 - "RenderError"
Cohesion: 0.07
Nodes (26): RenderError, already_initialized, backbuffer_unavailable, backend_failure, device_creation_failed, factory_unavailable, invalid_window, native_window_unavailable (+18 more)

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

### Community 30 - "xxhash64"
Cohesion: 0.23
Nodes (10): StateError, invalid_state, uninitialized, hash_state(), merge(), read32(), read64(), round() (+2 more)

### Community 31 - "BufferDesc"
Cohesion: 0.12
Nodes (14): BufferData, context, DataSize, pData, BufferDesc, BindFlags, CPUAccessFlags, Name (+6 more)

### Community 33 - "03 — Architecture and services"
Cohesion: 0.14
Nodes (10): Backend, 03 — Architecture and services, Critical correction, Free-tier facts verified at planning time, Naming, Quota budget, Service assignments, Topology (+2 more)

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

### Community 41 - "IDeviceContext"
Cohesion: 0.17
Nodes (6): IBuffer, values, IDeviceContext, ITexture, view, ITextureView

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
Cohesion: 0.08
Nodes (26): ENG-01–22 hardening additions (2026-11-22), ENG-03 clear-seed additions (2026-11-20), ENG-03 continuation (2026-11-20), ENG-03 diagnostics/evidence files (2026-11-20), ENG-04 fallback prototype (2026-11-21), ENG-09 additions (2026-11-21), ENG-10 additions (2026-11-21), ENG-21 directional-light prototype (2026-11-22) (+18 more)

### Community 46 - "pokomesh.cpp"
Cohesion: 0.20
Nodes (9): PokoMesh, indices, vertices, fail(), finite_vec3(), load_pokomesh(), parse_pokomesh(), read_f32() (+1 more)

### Community 47 - "string"
Cohesion: 0.08
Nodes (13): SDL_GLContextState, SDL_Window, feed_imgui_event(), imgui_key(), ImGuiContextGuard, print_to_console(), IDeviceContext, IRenderDevice (+5 more)

### Community 48 - "FrameGraph"
Cohesion: 0.18
Nodes (7): FrameGraph, executing_, imports_, passes_, FrameGraph::compile(), FrameGraph::execute(), main()

### Community 49 - "FrameGraphError"
Cohesion: 0.15
Nodes (13): FrameGraphError, busy, callback_failed, dependency_cycle, duplicate_import, duplicate_pass, duplicate_resource_use, empty_name (+5 more)

### Community 50 - "AddressSanitizer (ASan)"
Cohesion: 0.06
Nodes (30): AddressSanitizer (ASan), Advanced Usage, AFL++, Anti-Patterns, cargo-fuzz (Rust), Combining Sanitizers, Common Patterns, honggfuzz (+22 more)

### Community 52 - "R6 preparation: file guide"
Cohesion: 0.17
Nodes (10): Clips, R6 animation refinement (v2), Regeneration and verification, Transitions and combination with looks, Animations — one file per clip, per rig, Faces, R6 preparation: file guide, Starter clothing (+2 more)

### Community 53 - "Console"
Cohesion: 0.17
Nodes (9): build_demo_window(), Console, input, log, output, scroll_to_end, state, main() (+1 more)

### Community 54 - "09 — Economy and Exchange"
Cohesion: 0.17
Nodes (11): 09 — Economy and Exchange, Activity proof, API, Dynamic rate, Exchange, Fraud detection, Idempotency, Ledger invariant (+3 more)

### Community 55 - "28 — Engine diagnostics"
Cohesion: 0.17
Nodes (11): 28 — Engine diagnostics, Assertion policy, Console, Crash handler, Debug draw, Limits, Logging, Profiler (+3 more)

### Community 56 - "Directory purposes"
Cohesion: 0.12
Nodes (14): Folder scaffold, `applications`, `assets`, `backend`, `cmake`, Directory purposes, Directory structure, `docs` (+6 more)

### Community 57 - "C++23 Features (Usable Today)"
Cohesion: 0.08
Nodes (25): Basic Usage, Basic Usage, C++23 Features (Usable Today), Caveats, Compiler Support, Compiler Support, Compiler Support, Compiler Support (+17 more)

### Community 58 - "console.cpp"
Cohesion: 0.09
Nodes (29): ConsoleLog, max_bytes, max_entries, max_input_bytes, PrintHost, context, StateField, name (+21 more)

### Community 59 - "Kind"
Cohesion: 0.29
Nodes (7): Kind, binary, boolean, call, integer, unary, variable

### Community 60 - "DeclarationNode"
Cohesion: 0.08
Nodes (23): DeclarationAst, DeclarationNode, begin, body, children, end_byte, kind, spelling (+15 more)

### Community 62 - "OrbitCamera"
Cohesion: 0.12
Nodes (11): OrbitCamera, aspect_, kFar, kFovY, kMaxDist, kMaxPitch, kMinDist, kMinPitch (+3 more)

### Community 63 - "TypeTag"
Cohesion: 0.13
Nodes (15): TypeTag, array, enumeration, error, function, int_literal, map, never (+7 more)

### Community 64 - "rules"
Cohesion: 0.09
Nodes (21): category, confidence, exclude, pattern, pattern, pattern, pattern, pattern-either (+13 more)

### Community 65 - "Contributing to PokoX"
Cohesion: 0.18
Nodes (10): Coding conventions, Commit and PR conventions, Contributing to PokoX, Development setup, Documentation and status updates, How work is organized, License and confidentiality, Questions (+2 more)

### Community 66 - "triangle/EngineFactoryVk.h"
Cohesion: 0.24
Nodes (8): ISwapChain, depth, desc, SwapChainDesc, ColorBufferFormat, DepthBufferFormat, TEXTURE_FORMAT, Uint32

### Community 67 - "IDeviceContext"
Cohesion: 0.18
Nodes (5): ENG-11 — ImGui pass in the frame graph, Implementation, Reproduce / open work, Verification — Windows laptop (MSYS2 UCRT64, AMD Radeon iGPU), IDeviceContext

### Community 68 - "00 — Decision log"
Cohesion: 0.18
Nodes (10): 00 — Decision log, Community, Economy, Final open items resolved, Language and runtime, Platform, Rendering and apps, Security (+2 more)

### Community 69 - "19 — Economy simulator"
Cohesion: 0.18
Nodes (10): 19 — Economy simulator, Agents, Analysis output, Contract, Gate, Honest limit, Scenario, Simulated week (+2 more)

### Community 70 - "cstdio"
Cohesion: 0.09
Nodes (6): VulkanClearRenderer::Impl, VulkanDiagnostics::Impl, main(), reset(), VulkanClearRenderer::Impl, VulkanDiagnostics::Impl

### Community 71 - "config_file_test.cpp"
Cohesion: 0.23
Nodes (18): head(), main(), put_arr(), put_b(), put_bool(), put_double(), put_float(), put_half() (+10 more)

### Community 72 - "BufferDesc"
Cohesion: 0.12
Nodes (13): BufferData, DataSize, pData, BufferDesc, BindFlags, CPUAccessFlags, Name, Size (+5 more)

### Community 73 - "GraphicsPipelineStateCreateInfo"
Cohesion: 0.14
Nodes (8): GraphicsPipelineStateCreateInfo, GraphicsPipeline, pPS, PSODesc, pVS, IRenderDevice, ISampler, IShader

### Community 74 - "IBuffer"
Cohesion: 0.17
Nodes (6): IBuffer, values, IDeviceContext, ITexture, view, ITextureView

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
Nodes (8): Event, button, dx, dy, pressed, size, type, wheel

### Community 82 - "cube_golden.py"
Cohesion: 0.10
Nodes (10): canonical_png(), main(), png_chunk(), run(), X11, XImage, decode(), GoldenEncoderTests (+2 more)

### Community 83 - "ExprNode"
Cohesion: 0.11
Nodes (14): AST and dump, MUT-02 arithmetic parser contract, Ast, ExprNode, begin, children, end_byte, kind (+6 more)

### Community 84 - "fakes/EngineFactoryVk.h"
Cohesion: 0.19
Nodes (12): Char, EngineVkCreateInfo, AdapterId, EnableValidation, NumDeferredContexts, ITextureView, RenderDeviceInfo, APIVersion (+4 more)

### Community 85 - "config.cpp"
Cohesion: 0.10
Nodes (15): EngineConfig, adapter_id, log_echo_to_console, log_file, log_level, validation, window_height, window_width (+7 more)

### Community 86 - "SwapChainDesc"
Cohesion: 0.20
Nodes (10): SwapChainDesc, ColorBufferFormat, DepthBufferFormat, Height, Width, TEXTURE_FORMAT, TEX_FORMAT_D32_FLOAT, TEX_FORMAT_RGBA8_UNORM (+2 more)

### Community 87 - "IPipelineState"
Cohesion: 0.19
Nodes (5): IPipelineState, var, IShaderResourceBinding, var, IShaderResourceVariable

### Community 88 - "Contributor Covenant Code of Conduct"
Cohesion: 0.22
Nodes (8): Attribution, Contributor Covenant Code of Conduct, Enforcement, Enforcement Guidelines, Enforcement Responsibilities, Our Pledge, Our Standards, Scope

### Community 89 - "IDeviceObject"
Cohesion: 0.08
Nodes (10): IBuffer, IDeviceObject, ISampler, IShader, ITexture, ITextureView, FakeVariable, buffer (+2 more)

### Community 90 - "AssetStore"
Cohesion: 0.13
Nodes (11): What was built, AssetStore, state_, AssetHandle::release(), AssetStore::AssetStore(), AssetStore::is_loading(), AssetStore::load_count(), AssetStore::poll_async() (+3 more)

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

### Community 95 - "rules"
Cohesion: 0.10
Nodes (20): exclude, pattern, pattern, pattern, pattern, pattern, pattern-either, pattern-not (+12 more)

### Community 96 - "RHI — experimental Vulkan clear seed"
Cohesion: 0.22
Nodes (8): Desktop laptop build (MSVC path not yet verified), ENG-04 desktop fallback prototype (in progress), Graphics diagnostics and repeatable laptop verification, Included, Ownership and failure behavior, Reproducible dependency-free checks, RHI — experimental Vulkan clear seed, Verified Windows MinGW notes (2026-11-20)

### Community 97 - "FrameStats"
Cohesion: 0.11
Nodes (14): ENG-15 — Frame timing and stats, Not done / future, Verification, What was built, FrameStats, cpu_count_, cpu_head_, cpu_window_ (+6 more)

### Community 98 - "evaluator.cpp"
Cohesion: 0.24
Nodes (24): to_arithmetic(), E, evaluate_arithmetic(), fail(), float_binary(), integer_suffix(), is_float(), is_unsigned() (+16 more)

### Community 99 - "array"
Cohesion: 0.07
Nodes (10): SdlPlatform, Java_com_poko_glesclear_PokoActivity_nativeInit(), Java_com_poko_glesclear_PokoActivity_nativeSetSurface(), Java_com_poko_glesclear_PokoActivity_nativeSurfaceDestroyed(), run_probe(), write_line(), contains(), Range (+2 more)

### Community 100 - "[Unreleased]"
Cohesion: 0.25
Nodes (7): Added, Added (continued), Changed, Changelog, Fixed, Notes, [Unreleased]

### Community 101 - "frame_graph.cpp"
Cohesion: 0.25
Nodes (3): FrameGraph::add_pass(), FrameGraph::build_plan(), FrameGraph::clear()

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
Cohesion: 0.29
Nodes (6): FramePass, after, execute, name, reads, writes

### Community 108 - "FrameGraph::Compiled"
Cohesion: 0.25
Nodes (5): FrameGraph::Compiled, detail, error, order, FrameGraph::import_resource()

### Community 109 - "rules"
Cohesion: 0.11
Nodes (18): exclude, pattern, pattern, pattern, pattern, pattern-either, pattern-not, rules (+10 more)

### Community 113 - "ExprKind"
Cohesion: 0.14
Nodes (14): ExprKind, await, binary, boolean, call, floating, identifier, index (+6 more)

### Community 115 - "ENG-06 — frame-graph skeleton"
Cohesion: 0.29
Nodes (4): Boundaries, ENG-06 — frame-graph skeleton, Implemented, Verification

### Community 116 - "PokoX plan index"
Cohesion: 0.29
Nodes (6): Current continuation, Known shallow areas, Non-negotiable rules, PokoX plan index, Reading order, Status

### Community 117 - "AssetHandle"
Cohesion: 0.13
Nodes (8): Defect found by the new test during implementation, Concurrency design, AssetHandle, state_, AssetHandle::AssetHandle(), AssetHandle::operator=(), counting_loader(), main()

### Community 118 - "VulkanMeshPass::Impl"
Cohesion: 0.08
Nodes (17): VulkanMeshPass::Impl, binding, buffers_dirty, camera_buffer, depth_format, format, fragment, index_buffer (+9 more)

### Community 119 - "Character visual review — 2026-11-20"
Cohesion: 0.33
Nodes (5): Character visual review — 2026-11-20, Face direction and attachment concern, Helper visibility, Scope and result, Windows build status

### Community 120 - "ENG-01–ENG-03 integration review"
Cohesion: 0.33
Nodes (5): Acceptance and outstanding work, ENG-01–ENG-03 integration review, Fresh checks in this sandbox, Organization, Wiring examined

### Community 121 - "ENG-01–ENG-05 folder and code audit"
Cohesion: 0.33
Nodes (5): Checks, ENG-01–ENG-05 folder and code audit, Fixes, Folder layout, Still open

### Community 122 - "memory"
Cohesion: 0.10
Nodes (9): allocate_or_throw(), operator delete(), operator new(), operator delete(), operator new(), operator delete(), operator new(), Payload (+1 more)

### Community 123 - "GitHub repositories"
Cohesion: 0.33
Nodes (5): Creation, Decision (2026-11-21): monorepo, GitHub repositories, Open decisions before creating anything, Proposed repositories

### Community 124 - "FrameGraphExecution"
Cohesion: 0.33
Nodes (4): FrameGraphExecution, completed, detail, error

### Community 125 - "MeshVertex"
Cohesion: 0.15
Nodes (9): Bugs found during implementation, ENG-19 — Hand-written binary mesh load, Not done / future, Verified, What was built, MeshVertex, normal, position (+1 more)

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

### Community 131 - "OpenGLESClearBackend"
Cohesion: 0.09
Nodes (12): OpenGLESClearBackend, height_, renderer_, shutdown_failed_, width_, OpenGLESClearBackend::clear_and_present(), OpenGLESClearBackend::initialize(), OpenGLESClearBackend::shutdown() (+4 more)

### Community 132 - "Security Policy"
Cohesion: 0.33
Nodes (5): Reporting a vulnerability, Scope notes, Security Policy, Supported versions, What to expect

### Community 133 - "vcpkg.json"
Cohesion: 0.33
Nodes (5): builtin-baseline, dependencies, description, name, version-string

### Community 134 - "Final audit — MUT-01 through MUT-12"
Cohesion: 0.20
Nodes (9): 1. Medium — Bytecode compilation accepts an invalid state initializer, 2. Medium — Automated console interaction coverage is absent from normal CTest/CI, 3. Low — Exhaustive arithmetic test is opt-in, absent from configured CI, Evidence and method, Final audit — MUT-01 through MUT-12, Findings, in priority order, Outcome, Recommendation (+1 more)

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

### Community 144 - "Job"
Cohesion: 0.16
Nodes (11): AssetLoader, AssetHandle::key(), AssetStore::acquire(), AssetStore::last_error(), AssetStore::request_async(), Job, error, key (+3 more)

### Community 145 - "vulkan_clear_android.cpp"
Cohesion: 0.13
Nodes (15): VulkanClearAndroidRenderer, cleanup_uncertain_, impl_, destroy_swapchain_resources(), make_device_objects(), make_instance(), make_surface(), make_swapchain() (+7 more)

### Community 146 - "rules"
Cohesion: 0.11
Nodes (18): exclude, pattern, pattern, pattern, pattern, pattern-either, pattern-inside, rules (+10 more)

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
Cohesion: 0.28
Nodes (11): Field, key, value, critical(), debug(), emit(), error(), info() (+3 more)

### Community 154 - "mesh/EngineFactoryVk.h"
Cohesion: 0.17
Nodes (12): ISwapChain, depth, desc, SwapChainDesc, ColorBufferFormat, DepthBufferFormat, TEXTURE_FORMAT, TextureSubResData (+4 more)

### Community 157 - "ktx2_test.cpp"
Cohesion: 0.35
Nodes (7): main(), make_ktx2(), put32(), put64(), set32(), set64(), write()

### Community 158 - "argparse"
Cohesion: 0.17
Nodes (8): run(), run(), compare(), load_corpus(), load_trace(), main(), _object(), _read()

### Community 160 - "Analyzer"
Cohesion: 0.17
Nodes (10): Analyzer, diagnostics_, functions_, return_type_, scopes_, types_, Binding, mutable_binding (+2 more)

### Community 161 - "rules"
Cohesion: 0.11
Nodes (18): exclude, pattern, pattern, pattern, pattern, pattern-either, pattern-not, rules (+10 more)

### Community 163 - "Box"
Cohesion: 0.14
Nodes (12): Box, MaxX, MaxY, MaxZ, MinX, MinY, MinZ, TextureSubResData (+4 more)

### Community 164 - "lexer.cpp"
Cohesion: 0.06
Nodes (39): Diagnostic, code, position, ErrorCode, bom, invalid_escape, invalid_number, invalid_utf8 (+31 more)

### Community 165 - "LayoutElement"
Cohesion: 0.14
Nodes (14): InputLayoutDesc, n, p, LayoutElement, BufferSlot, Frequency, InputIndex, InstanceDataStepRate (+6 more)

### Community 166 - "FakeDevice"
Cohesion: 0.07
Nodes (9): FakeDevice, last_pipeline, FakePipeline, font_texture, frame_data, FakeSampler, FakeTargetView, FakeTextureView (+1 more)

### Community 167 - "BlendModeRenderTargetDesc"
Cohesion: 0.11
Nodes (18): BLEND_FACTOR, BLEND_FACTOR_INV_SRC_ALPHA, BLEND_FACTOR_ONE, BLEND_FACTOR_SRC_ALPHA, BLEND_FACTOR_ZERO, BLEND_OPERATION, BLEND_OPERATION_ADD, BlendDesc (+10 more)

### Community 168 - "TextureData"
Cohesion: 0.12
Nodes (11): TEXTURE_VIEW_TYPE, TEXTURE_VIEW_SHADER_RESOURCE, TextureData, NumSubresources, pSubresources, TextureSubResData, pData, Stride (+3 more)

### Community 169 - "LayoutElement"
Cohesion: 0.08
Nodes (25): EngineVkCreateInfo, AdapterId, EnableValidation, NumDeferredContexts, INPUT_ELEMENT_FREQUENCY, INPUT_ELEMENT_FREQUENCY_PER_VERTEX, InputLayoutDesc, LayoutElements (+17 more)

### Community 170 - "Safe C++ Idioms"
Cohesion: 0.09
Nodes (21): Always Initialize, Atomics, Compiler Warnings, Concurrency Safety, constexpr / consteval, Enum Class, Initialization Safety, Integer Safety (+13 more)

### Community 171 - "OpenGLClearESRenderer"
Cohesion: 0.10
Nodes (14): OpenGLClearESRenderer, cleanup_uncertain_, impl_, OpenGLClearRenderer::clear_and_present(), OpenGLClearESRenderer::clear_and_present(), OpenGLClearESRenderer::clear_and_verify(), OpenGLClearESRenderer::framebuffer_is_srgb(), OpenGLClearESRenderer::initialize() (+6 more)

### Community 175 - "VulkanDiagnostics::Impl"
Cohesion: 0.18
Nodes (8): VulkanDiagnostics::Impl, baseline, break_on_error, break_on_error_changed, factory, installed, owns, previous

### Community 176 - "Modern C++"
Cohesion: 0.12
Nodes (17): Anti-Patterns to Avoid, Best Practices Checklist, Clang-Specific, Compiler Hardening Quick Reference, Decision Tree, Essential Flags (GCC + Clang), Feature Tiers, Hardened libc++ (Clang/libc++ only) (+9 more)

### Community 177 - "GraphicsPipelineDesc"
Cohesion: 0.11
Nodes (19): DepthStencilDesc, DepthEnable, DepthWriteEnable, GraphicsPipelineDesc, BlendDesc, DepthStencilDesc, DSVFormat, InputLayout (+11 more)

### Community 178 - "semantic.cpp"
Cohesion: 0.21
Nodes (11): accepts(), generic_arity(), generic_tag(), is_assign_op(), is_float_scalar(), is_integer_scalar(), name(), numeric() (+3 more)

### Community 179 - "SamplerDesc"
Cohesion: 0.17
Nodes (12): FILTER_TYPE, FILTER_TYPE_LINEAR, SamplerDesc, AddressU, AddressV, AddressW, MagFilter, MinFilter (+4 more)

### Community 180 - "VulkanClearRenderer::Impl"
Cohesion: 0.13
Nodes (10): VulkanClearRenderer::Impl, context, device, initialized, platform, resize_failed, swapchain, validation_enabled (+2 more)

### Community 181 - "Parser"
Cohesion: 0.37
Nodes (5): Parser, at_, parse_depth_, program_, source_

### Community 182 - "ENG-17 — Async load queue"
Cohesion: 0.14
Nodes (11): Audit round — defects found and fixed, ENG-17 — Async load queue, Integration review, 2026-11-22, Not done / future, Verification, Project map and review scope, Project review and repairs — 2026-11-22, Remaining work and next safe step (+3 more)

### Community 183 - "TextureDesc"
Cohesion: 0.09
Nodes (22): RESOURCE_DIMENSION, RESOURCE_DIM_TEX_2D, SwapChainDesc, ColorBufferFormat, DepthBufferFormat, Height, Width, TEXTURE_FORMAT (+14 more)

### Community 184 - "FakeChain"
Cohesion: 0.09
Nodes (15): Int32, Rect, Bottom, Left, Right, Top, Viewport, Height (+7 more)

### Community 186 - "MUT-01 — lexer core progress (2026-11-22)"
Cohesion: 0.25
Nodes (7): Completion follow-up (2026-11-22), Implemented, Local evidence, MUT-01 — lexer core progress (2026-11-22), Remaining gates, Scope and integration, Unicode data provenance

### Community 187 - "bytecode.cpp"
Cohesion: 0.27
Nodes (9): DecodeResult, EncodeResult, assemble_bytecode(), branch(), decode_bytecode(), disassemble_bytecode(), encode_bytecode(), mnemonic() (+1 more)

### Community 188 - "Compiler Hardening"
Cohesion: 0.10
Nodes (20): AddressSanitizer (ASan), checksec, CI Integration, Combining Sanitizers, Compiler Explorer, Compiler Hardening, Complete Hardened Compilation Example, Google's Results (+12 more)

### Community 189 - "ClearBackendSelection"
Cohesion: 0.07
Nodes (26): Android ES backend behind ClearBackend contract — 2026-11-22 (same session), Android OpenGL ES primitive — 2026-11-22 (physical device, offscreen), ClearBackend, ClearBackendSelection, owned_, SelectedBackend, fallback, none (+18 more)

### Community 191 - "vulkan_clear_faults.cpp"
Cohesion: 0.13
Nodes (20): SDL_PropertiesID, SDL_WindowFlags, Sint64, native_window(), native_window(), VulkanClearRenderer::initialize(), NativeWindow, DILIGENT_CALL_TYPE foreign() (+12 more)

### Community 193 - "C++20 Features (Default Practice)"
Cohesion: 0.18
Nodes (11): C++20 Features (Default Practice), Coroutines, Custom Formatters, Designated Initializers, std::format, std::jthread, std::span<T>, Three-Way Comparison (<=>) (+3 more)

### Community 196 - "Variant Analysis Report"
Cohesion: 0.18
Nodes (10): False Positive Patterns, Findings, Immediate, Original Vulnerability, Preventive, Recommendations, Search Methodology, Summary (+2 more)

### Community 197 - "DrawIndexedAttribs"
Cohesion: 0.10
Nodes (21): Final audit round (pre-closeout), BIND_FLAGS, BIND_INDEX_BUFFER, BIND_NONE, BIND_SHADER_RESOURCE, BIND_UNIFORM_BUFFER, BIND_VERTEX_BUFFER, DRAW_FLAGS (+13 more)

### Community 199 - "verify_desktop.py"
Cohesion: 0.16
Nodes (8): capture(), floats(), capture(), floats(), classify(), main(), parse_runtime(), run_step()

### Community 200 - "load_state_snapshot"
Cohesion: 0.21
Nodes (8): LoadStateResult, SaveStateResult, append_le(), load_state_snapshot(), read_le(), save_state_snapshot(), schema_for(), SchemaResult

### Community 201 - "Build status"
Cohesion: 0.22
Nodes (8): Build status, Build status, Commands, Full dependencies, Golden files, Historical build notes — not current status, Historical build notes (unverified), Toolchain matrix

### Community 205 - "parser.cpp"
Cohesion: 0.36
Nodes (4): expr_op(), name(), op_spelling(), quoted()

### Community 206 - "StatementNode"
Cohesion: 0.13
Nodes (13): StatementAst, StatementNode, begin, children, end_byte, expression, kind, spelling (+5 more)

### Community 207 - "TextureDesc"
Cohesion: 0.20
Nodes (10): TextureDesc, ArraySize, BindFlags, Format, Height, MipLevels, Name, Type (+2 more)

### Community 208 - "Findings to address"
Cohesion: 0.18
Nodes (9): Findings to address, Scope and outcome, Task-by-task evidence and gaps, Audit round 2 — additional defects found and fixed, ENG-16 — Asset handle with refcount, Integration review, 2026-11-22, Not done / future, Verification (+1 more)

### Community 209 - "SDL_Event"
Cohesion: 0.06
Nodes (32): SDL_Event, button, motion, type, wheel, window, SDL_MouseButtonEvent, button (+24 more)

### Community 210 - "AssetStore::State"
Cohesion: 0.11
Nodes (12): AssetStore::State, assets, cv, failures, jobs, loads, mutex, queue (+4 more)

### Community 211 - "Contracts"
Cohesion: 0.12
Nodes (17): Before / After, C++26 Features, Contracts, #embed, Enforcement Modes, Erroneous Behavior for Uninitialized Reads, Hardened Standard Library, Honest Limitations (+9 more)

### Community 212 - "linux-lit-cube-golden"
Cohesion: 0.17
Nodes (12): run, LIBGL_ALWAYS_SOFTWARE, LP_NATIVE_VECTOR_WIDTH, LP_NUM_THREADS, SDL_VIDEODRIVER, linux-lit-cube-golden, defaults, env (+4 more)

### Community 213 - "EngineGLCreateInfo"
Cohesion: 0.22
Nodes (4): EngineGLCreateInfo, EnableValidation, NumDeferredContexts, Window

### Community 214 - "Root Cause and Expansion Axes"
Cohesion: 0.20
Nodes (10): 1. Semantically related identifiers, 2. Other boolean-logic errors, 3. Data-type edge cases, 4. Documentation/code mismatches, Extracting the Root Cause, Pitfalls at This Stage, Root Cause and Expansion Axes, The Expansion Checklist (+2 more)

### Community 215 - "VulkanMeshPass"
Cohesion: 0.17
Nodes (5): VulkanMeshPass, impl_, VulkanMeshPass::draw_and_present(), VulkanMeshPass::set_light_direction(), VulkanMeshPass::set_view_proj()

### Community 216 - "program.cpp"
Cohesion: 0.12
Nodes (23): Audit fixes, ProgramBytecodeResult, ProgramOptions, max_allowed_steps, max_steps, ProgramResult, ProgramState, fields (+15 more)

### Community 217 - "Value"
Cohesion: 0.12
Nodes (12): Member, first, second, Value, boolean, entries, i, items (+4 more)

### Community 218 - "Kind"
Cohesion: 0.29
Nodes (7): Kind, assign, conditional, declare_let, declare_var, ret, while_loop

### Community 219 - "steps"
Cohesion: 0.31
Nodes (11): MSYS2_LOCATION, steps, steps, env, id, if, name, run (+3 more)

### Community 220 - "SamplerDesc"
Cohesion: 0.25
Nodes (8): SamplerDesc, AddressU, AddressV, AddressW, MagFilter, MinFilter, MipFilter, Name

### Community 221 - "Type"
Cohesion: 0.20
Nodes (10): Type, array, boolean, bytes, map, nint, null, real (+2 more)

### Community 222 - "Reader"
Cohesion: 0.22
Nodes (3): in_bounds(), Reader, pos

### Community 225 - "Searching: The Abstraction Ladder"
Cohesion: 0.22
Nodes (8): Acceptable rates by context, Common FP sources and filters, Decision points, False Positive Management, One Change at a Time, Search Scope, Searching: The Abstraction Ladder, Tool Selection

### Community 226 - "Ktx2Image"
Cohesion: 0.12
Nodes (15): sRGB continuation, Ktx2Format, bgra8_srgb, bgra8_unorm, rgba8_srgb, rgba8_unorm, Ktx2Image, format (+7 more)

### Community 227 - "FakeContext"
Cohesion: 0.09
Nodes (10): MAP_FLAGS, MAP_FLAG_DISCARD, MAP_FLAG_NONE, MAP_TYPE, MAP_READ, MAP_WRITE, FakeBuffer, storage (+2 more)

### Community 228 - "Triage: Deciding Whether a Candidate Is Real"
Cohesion: 0.22
Nodes (9): Argue Against the Candidate, Documentation/code mismatch, Edge Cases That Hide Real Bugs, Exploitability, Null equality bypasses, Others worth testing, Recording False Positives, Severity and Confidence (+1 more)

### Community 229 - "IPipelineState"
Cohesion: 0.19
Nodes (5): IPipelineState, var, IShaderResourceBinding, var, IShaderResourceVariable

### Community 230 - "TriangleMode"
Cohesion: 0.24
Nodes (7): TriangleMode, color, depth_disabled_control, depth_test, textured, uniform_depth, VulkanTrianglePass::VulkanTrianglePass()

### Community 232 - "os"
Cohesion: 0.10
Nodes (10): check_spirv(), run(), update_shader(), first_difference(), main(), update_golden(), command(), VersionIntegrationTests (+2 more)

### Community 233 - "SamplerDesc"
Cohesion: 0.15
Nodes (9): ISampler, SamplerDesc, AddressU, AddressV, AddressW, MagFilter, MinFilter, MipFilter (+1 more)

### Community 234 - "Anti-Patterns: Legacy to Modern C++"
Cohesion: 0.25
Nodes (8): Anti-Patterns: Legacy to Modern C++, Concurrency, Containers, Error Handling, I/O and Formatting, Memory Management, Metaprogramming, Type Safety

### Community 235 - "linux-build"
Cohesion: 0.22
Nodes (8): jobs, name, on, pull_request, push, workflow_dispatch, permissions, contents

### Community 236 - "string"
Cohesion: 0.29
Nodes (7): LoadState, awaiting_install, failed, loading, none, ready, AssetStore::load_state()

### Community 238 - "evaluator_test.cpp"
Cohesion: 0.26
Nodes (11): EvalResult, bindings(), cases(), check(), deep(), error_case(), eval(), floating() (+3 more)

### Community 239 - "windows-build"
Cohesion: 0.25
Nodes (8): windows-build, toolchain, fail-fast, matrix, name, runs-on, strategy, timeout-minutes

### Community 240 - "camera.cpp"
Cohesion: 0.46
Nodes (6): look_at(), multiply(), OrbitCamera::orbit(), OrbitCamera::view_proj(), OrbitCamera::zoom(), perspective()

### Community 241 - "EvalErrorCode"
Cohesion: 0.08
Nodes (24): Errors and cost, Floating-point safeguards and limitations, Host numeric bindings, MUT-03 arithmetic evaluator — initial contract, Numeric rules for this baseline, EvalDiagnostic, code, position (+16 more)

### Community 242 - "SDL_Delay"
Cohesion: 0.21
Nodes (10): main(), cube_indices(), cube_vertices(), main(), main(), VulkanClearBackend::initialize(), main(), main() (+2 more)

### Community 243 - "GraphicsPipelineStateCreateInfo"
Cohesion: 0.20
Nodes (7): GraphicsPipelineStateCreateInfo, GraphicsPipeline, pPS, PSODesc, pVS, IRenderDevice, IShader

### Community 244 - "TextureDesc"
Cohesion: 0.20
Nodes (10): TextureDesc, ArraySize, BindFlags, Format, Height, MipLevels, Name, Type (+2 more)

### Community 245 - "Post-implementation audit — ENG-01 through ENG-13"
Cohesion: 0.18
Nodes (7): Gap-closure round 2, Independent review round 4 (2026-11-21), Known remaining gaps (documented, not defects), Post-implementation audit — ENG-01 through ENG-13, Test updates, Verified, read_spirv()

### Community 247 - "Entry"
Cohesion: 0.33
Nodes (5): AssetPayload, AssetHandle::payload(), Entry, payload, refs

### Community 248 - "parse_arithmetic"
Cohesion: 0.44
Nodes (9): dump_ast(), parse_arithmetic(), cases(), check(), main(), parse_error(), randomized_input(), stress() (+1 more)

### Community 249 - "VulkanClearAndroidRenderer::Impl"
Cohesion: 0.05
Nodes (24): VulkanClearAndroidRenderer::Impl, color_space, command_buffer, command_pool, device, extent, fence, format (+16 more)

### Community 250 - "interface"
Cohesion: 0.29
Nodes (6): interface, brand_color, display_name, icon_large, icon_small, short_description

### Community 251 - "ENG-20 — Camera with view/projection"
Cohesion: 0.20
Nodes (8): Bugs found during implementation, ENG-20 — Camera with view/projection, Integration review, 2026-11-22, Linux software-rendering update — 2026-11-22, Not done / future, Review update — 2026-11-22, Verified, What was built

### Community 252 - "cbor.cpp"
Cohesion: 0.22
Nodes (5): Cursor, data, pos, size, values

### Community 255 - "ENG-22 — lit-cube screenshot golden"
Cohesion: 0.29
Nodes (6): Defect found during reference review, ENG-22 — lit-cube screenshot golden, Local evidence, Local execution, Remaining, What was added

### Community 257 - "StatementParser"
Cohesion: 0.19
Nodes (9): name(), StatementParser, ast_, depth_, depth_limit, loop_depth_, pos_, source_ (+1 more)

### Community 258 - "interface"
Cohesion: 0.29
Nodes (6): interface, brand_color, display_name, icon_large, icon_small, short_description

### Community 259 - "Variant Analysis"
Cohesion: 0.29
Nodes (7): Resources, Running it as a Workflow, The Five Steps, Variant Analysis, What Makes Hunts Fail, When NOT to Use, When to Use

### Community 261 - "MUT-01–MUT-03 integration audit (2026-11-22)"
Cohesion: 0.33
Nodes (5): Evidence, Findings and action, MUT-01–MUT-03 integration audit (2026-11-22), Reproduce the exhaustive audit, Scope

### Community 262 - "BytecodeErrorCode"
Cohesion: 0.15
Nodes (12): BytecodeError, code, offset, BytecodeErrorCode, bad_header, invalid_assembly, invalid_opcode, invalid_operands (+4 more)

### Community 263 - "Linux graphics setup and review — 2026-11-22"
Cohesion: 0.22
Nodes (8): Environment, Linux graphics setup and review — 2026-11-22, Next task and outstanding gates, Repeat the X11 smoke test, Scope, Skills and C++20, Subsequent ENG-01–21 audit, Verification

### Community 264 - "mute/README.md"
Cohesion: 0.17
Nodes (7): Input and positions, MUT-01 lexical contract, initial implementation, Tokens, Unsigned `.pkB` schema preview, Host API, Initial Mute state and deterministic hash, Validation

### Community 265 - "WindowConfig"
Cohesion: 0.15
Nodes (10): WindowConfig, graphics_api, height, title, width, WindowGraphicsApi, none, opengl (+2 more)

### Community 266 - "ExpressionParser"
Cohesion: 0.17
Nodes (10): ParseResult, ExpressionParser, ast_, frames_, pos_, source_, tokens_, values_ (+2 more)

### Community 267 - "Box"
Cohesion: 0.25
Nodes (7): Box, MaxX, MaxY, MaxZ, MinX, MinY, MinZ

### Community 268 - "Reflection (Game-Changer)"
Cohesion: 0.29
Nodes (7): Before / After, Compiler Support, Core Syntax, Enum-to-String (Classic Pain Point), Reflection (Game-Changer), What It Eliminates, When to Use / Not Use

### Community 269 - "pkb_draft.cpp"
Cohesion: 0.46
Nodes (3): head(), make_pkb_schema_draft(), text()

### Community 271 - "Concepts"
Cohesion: 0.33
Nodes (6): Before / After, Concepts, Custom Concepts, requires Clauses vs concept Keyword, Standard Concepts, What They Replace

### Community 272 - "The Ladder"
Cohesion: 0.33
Nodes (6): Choosing your level, Level 0: Exact match, Level 1: Variable abstraction, Level 2: Structural abstraction, Level 3: Semantic abstraction, The Ladder

### Community 273 - "SnapshotErrorCode"
Cohesion: 0.15
Nodes (12): SnapshotError, code, offset, SnapshotErrorCode, checksum_mismatch, invalid_format, invalid_source, invalid_state (+4 more)

### Community 274 - "Integration review — 2026-11-22"
Cohesion: 0.33
Nodes (5): Integration review — 2026-11-22, Remaining limitations and risks, Scope and findings, Subsequent review, Verification on this host

### Community 276 - "OpenGLClearRenderer"
Cohesion: 0.05
Nodes (27): SDL_GLAttr, OpenGLClearBackend, cleanup_error_, diagnostics_, height_, renderer_, validation_, width_ (+19 more)

### Community 277 - "sdl_platform_faults.cpp"
Cohesion: 0.14
Nodes (19): SDL_Window, SDL_InitFlags, SDL_WindowID, main(), main(), push(), SDL_CreateWindow(), SDL_DestroyWindow() (+11 more)

### Community 278 - "IEngineFactoryOpenGL"
Cohesion: 0.25
Nodes (4): IEngineFactoryOpenGL, DebugMessageCallbackType, GetEngineFactoryOpenGL(), GlFactory

### Community 279 - "Reporting a Variant Hunt"
Cohesion: 0.40
Nodes (5): Leave a Regression Guard, Quote the Real Code, Reporting a Variant Hunt, Structure, The Methodology Table

### Community 280 - "bit"
Cohesion: 0.11
Nodes (12): MathError, unsupported_environment, MathResult, calculate(), deterministic_cos(), deterministic_sin(), supported(), cosine() (+4 more)

### Community 281 - "StatementErrorCode"
Cohesion: 0.09
Nodes (21): StatementDiagnostic, code, position, StatementErrorCode, break_outside_loop, continue_outside_loop, depth_exceeded, expected_arrow (+13 more)

### Community 282 - "MUT-11 and `.pkB` progress audit — 2026-11-22"
Cohesion: 0.29
Nodes (6): Evidence, Follow-up, MUT-11 and `.pkB` progress audit — 2026-11-22, Outcome, Schema preview and `.pkB` boundary, State behavior

### Community 283 - "DrawIndexedAttribs"
Cohesion: 0.33
Nodes (5): DrawIndexedAttribs, Flags, IndexType, NumIndices, Uint32

### Community 284 - "transform"
Cohesion: 0.50
Nodes (4): Key Patterns, Ranges, Useful Views, transform()

### Community 286 - "OpenGLClearESRenderer::Impl"
Cohesion: 0.15
Nodes (10): OpenGLClearESRenderer::Impl, context, display, height, initialized, srgb, surface, width (+2 more)

### Community 288 - "Instruction"
Cohesion: 0.22
Nodes (8): Instruction, a, b, c, op, branch_offset(), long_offset(), long_payload()

### Community 290 - "DEBUG_MESSAGE_SEVERITY"
Cohesion: 0.40
Nodes (5): DEBUG_MESSAGE_SEVERITY, DEBUG_MESSAGE_SEVERITY_ERROR, DEBUG_MESSAGE_SEVERITY_FATAL_ERROR, DEBUG_MESSAGE_SEVERITY_INFO, DEBUG_MESSAGE_SEVERITY_WARNING

### Community 291 - "DeclarationErrorCode"
Cohesion: 0.09
Nodes (21): DeclarationDiagnostic, code, position, DeclarationErrorCode, depth_exceeded, expected_arrow, expected_colon, expected_declaration (+13 more)

### Community 292 - "StatementKind"
Cohesion: 0.13
Nodes (15): StatementKind, block, break_stmt, continue_stmt, expression, for_stmt, guard_stmt, if_stmt (+7 more)

### Community 293 - "MUT-01–07 follow-up audit — 2026-11-22"
Cohesion: 0.33
Nodes (5): Checks and remaining limitations, Finding fixed, Local verification, MUT-01–07 follow-up audit — 2026-11-22, Scope

### Community 294 - "Level"
Cohesion: 0.12
Nodes (15): Bugs fixed, Config, echo_to_console, file_path, level, Level, critical, debug (+7 more)

### Community 295 - "config.cpp"
Cohesion: 0.33
Nodes (9): collect_unknown(), fail(), find_key(), load_file(), parse_level(), read_bool(), read_text(), read_u32() (+1 more)

### Community 297 - "Memory Safety"
Cohesion: 0.40
Nodes (5): Memory Safety, Non-Owning Views, Optional vs Nullable Pointers, Ownership: Smart Pointers, Value Semantics by Default

### Community 298 - "primary"
Cohesion: 1.00
Nodes (4): reference(), add(), mul(), primary()

### Community 299 - "lexer_contract_test.cpp"
Cohesion: 0.47
Nodes (7): check(), deterministic_streams(), diagnostic(), examples(), Expected, main(), tokens()

### Community 300 - "Token"
Cohesion: 0.25
Nodes (6): LexOptions, max_source_bytes, Token, begin, end_byte, kind

### Community 301 - "Essential Compiler Flags"
Cohesion: 0.25
Nodes (8): Auto-Initialization, Control Flow Integrity, Essential Compiler Flags, Fortification, Linker Hardening, Position-Independent Code, Stack Protection, Warnings

### Community 302 - "DrawAttribs"
Cohesion: 0.50
Nodes (3): DrawAttribs, Flags, NumVertices

### Community 303 - "VulkanDiagnostics"
Cohesion: 0.09
Nodes (20): DiagnosticsError, already_active, backend_failure, busy, factory_unavailable, none, GraphicsMessages, errors (+12 more)

### Community 305 - "RasterizerDesc"
Cohesion: 0.22
Nodes (9): CULL_MODE, CULL_MODE_BACK, CULL_MODE_NONE, FILL_MODE, FILL_MODE_SOLID, RasterizerDesc, CullMode, FillMode (+1 more)

### Community 306 - "Deducing this"
Cohesion: 0.40
Nodes (5): Compiler Support, Deducing this, Recursive Lambdas, Simplified CRTP, The Problem It Solves

### Community 307 - "30 — Mute v1 completion plan"
Cohesion: 0.22
Nodes (8): 30 — Mute v1 completion plan, Branch encoding decision, Dependencies and open decisions, Language and compiler, Optimizer safety contract, Proposed game-facing API coverage, Tooling, evidence and release, What “Mute v1 complete” would mean

### Community 312 - "Mute"
Cohesion: 0.20
Nodes (10): Arithmetic evaluator, Arithmetic parser, Debug console, Debug print hostcall, Initial branching and loops, Initial functions and locals, Initial register VM, math and bytecode, Lexer (+2 more)

### Community 315 - "DirectionalLight"
Cohesion: 0.22
Nodes (6): ENG-01–20 audit and ENG-21 — 2026-11-22, ENG-21 implementation, Next work, Subsequent ENG-22 finding, Verification on this Linux x86-64 host, DirectionalLight

### Community 317 - "statement_test.cpp"
Cohesion: 0.31
Nodes (11): StatementResult, parse_statements(), StatementFailure, result, cases(), check(), depth_guard(), dump() (+3 more)

### Community 318 - "MUT-08–10 progress and integration audit — 2026-11-22"
Cohesion: 0.25
Nodes (7): Audit findings and remaining risks, MUT-08–10 progress and integration audit — 2026-11-22, MUT-08 — register execution of existing programs, MUT-09 — deterministic binary64 sin/cos, MUT-10 — experimental low-level bytecode, Status, Validation

### Community 319 - "Opcode"
Cohesion: 0.10
Nodes (20): Opcode, add, branch_false, branch_true, div, eq, ext_prefix, ge (+12 more)

### Community 322 - "SemanticErrorCode"
Cohesion: 0.13
Nodes (15): SemanticErrorCode, duplicate_binding, duplicate_declaration, immutable_assignment, invalid_assignment, invalid_generic_arity, invalid_operand, invalid_return (+7 more)

### Community 323 - "ENG-01–ENG-22 hardening audit — 2026-11-22"
Cohesion: 0.29
Nodes (6): ENG-01–ENG-22 hardening audit — 2026-11-22, Evidence by task, Final verification, Findings and fixes, Open risks and next work, Scope

### Community 324 - "Renderer — frame-graph skeleton"
Cohesion: 0.17
Nodes (12): Boundaries, Build and verify, ENG-07: build-time SPIR-V, ENG-08: Vulkan triangle through the frame graph, ENG-09: experimental depth test, ENG-10: per-frame uniform-buffer demo, ENG-11: ImGui pass in the frame graph, ENG-12: ImGui F1 toggle and release strip (+4 more)

### Community 325 - "DeclarationKind"
Cohesion: 0.14
Nodes (14): DeclarationKind, allow, attribute, enum_decl, field, fn_decl, import, module (+6 more)

### Community 326 - "MUT-01–05 audit — 2026-11-22"
Cohesion: 0.40
Nodes (4): Findings, Local verification and observation, MUT-01–05 audit — 2026-11-22, Scope and method

### Community 327 - "NumericBinding"
Cohesion: 0.50
Nodes (3): NumericBinding, name, value

### Community 328 - "MUT-02 — arithmetic AST (2026-11-22)"
Cohesion: 0.40
Nodes (4): Evidence, MUT-02 — arithmetic AST (2026-11-22), Remaining, Scope and status

### Community 329 - "Project layout check — 2026-11-22"
Cohesion: 0.40
Nodes (4): Checks and limits, Documentation fix, Project layout check — 2026-11-22, Result

### Community 330 - "Post-MUT audit fixes and G1/G2 preflight"
Cohesion: 0.29
Nodes (6): Current gate status, Evidence, G1 replay scenario v0 (2026-11-22, Windows x64 leg only), Outstanding work, Post-MUT audit fixes and G1/G2 preflight, Windows laptop run (2026-11-22, MSYS2 UCRT64 MinGW g++ 16.2)

### Community 331 - "Error"
Cohesion: 0.15
Nodes (12): Error, invalid_utf8, malformed, none, too_deep, too_many_items, truncated, unsupported (+4 more)

### Community 332 - "Position"
Cohesion: 0.12
Nodes (23): NumericData, NumericValue, data, type, Position, byte, column, line (+15 more)

### Community 333 - "Frame"
Cohesion: 0.20
Nodes (7): Frame, args, await_node, kind, left, op, token

### Community 335 - "lexer_test.cpp"
Cohesion: 0.46
Nodes (5): check(), error(), main(), test_cases(), unicode_conformance()

### Community 336 - "ENG-04 — desktop fallback clear prototype (in progress)"
Cohesion: 0.18
Nodes (9): Android Vulkan debugging session — 2026-11-22 (continued), Android Vulkan primary attempt — 2026-11-22 (physical device), Android windowed GLES surface — 2026-11-22 (real display, physical device), Build and run on a provisioned Windows machine, ENG-04 Android acceptance evidence — 2026-11-22 (BREAKTHROUGH), ENG-04 — desktop fallback clear prototype (in progress), Implementation and boundaries, Local regression results — 2026-11-21 (+1 more)

### Community 337 - "MUT-08–10 completion audit — 2026-11-22"
Cohesion: 0.25
Nodes (7): MUT-08–10 completion audit — 2026-11-22, MUT-08: program execution, MUT-09: deterministic math, MUT-10: compiled-program and word-code round trips, Outcome and scope, Remaining gates and risks, Verification

### Community 338 - "MUT-01–12: MUT-12 implementation and three audit passes"
Cohesion: 0.22
Nodes (8): Audit 1 — Task behavior and feature coverage, Audit 2 — Inputs, safety and edge cases, Audit 3 — Integration, layout and reproducibility, Evidence, Follow-up and release status, MUT-01–12: MUT-12 implementation and three audit passes, MUT-12 contract, Scope and outcome

### Community 339 - "declaration_test.cpp"
Cohesion: 0.29
Nodes (11): DeclarationResult, DeclarationFailure, result, parse_declarations(), cases(), check(), depth_guard(), error() (+3 more)

### Community 340 - "SHADER_TYPE"
Cohesion: 0.14
Nodes (6): DILIGENT_CALL_TYPE capture(), SHADER_TYPE, SHADER_TYPE_PIXEL, SHADER_TYPE_VERTEX, FakeShader, type

### Community 341 - "VulkanClearRenderer::initialize"
Cohesion: 0.17
Nodes (7): Build, Contract and limits, ENG-01 / ENG-02 lifecycle hardening, Platform module, Renderer continuation, Target acceptance checklist (still open), Engine

### Community 342 - "main"
Cohesion: 0.43
Nodes (6): main(), click(), image(), press(), send(), window()

### Community 343 - "FloatEnvironment"
Cohesion: 0.22
Nodes (3): FloatEnvironment, active_, saved_

### Community 344 - "MUT-01–03 follow-up fixes and audit (2026-11-22)"
Cohesion: 0.33
Nodes (5): Fixed or improved, MUT-01–03 follow-up fixes and audit (2026-11-22), Scope and result, Still open / not safely closable here, Verification

### Community 345 - "PlatformError"
Cohesion: 0.22
Nodes (8): PlatformError, already_initialized, invalid_window_config, none, not_initialized, platform_failure, window_exists, window_not_created

### Community 346 - "NumericType"
Cohesion: 0.15
Nodes (12): NumericType, f32, f64, i16, i32, i64, i8, u16 (+4 more)

### Community 347 - "DurationQueryState"
Cohesion: 0.31
Nodes (4): DurationQueryState, active_, pending_, main()

### Community 348 - "Audit findings and open work"
Cohesion: 0.18
Nodes (10): Audit findings and open work, Integration finding fixed, MUT-08–10 implementation progress and audit — 2026-11-22, MUT-08 — high: language integration missing, MUT-09 — high: deterministic math not ported or validated, MUT-10 — high: format is provisional and incomplete, Other limits, Summary (+2 more)

### Community 349 - "PokoX — Project Root"
Cohesion: 0.33
Nodes (6): Character assets, Current scaffold status, Important caveat, Live Blender, PokoX — Project Root, Where things are

### Community 355 - "EventType"
Cohesion: 0.25
Nodes (8): EventType, mouse_button, mouse_motion, mouse_wheel, none, quit_requested, window_close_requested, window_resized

### Community 356 - "MUT-06 — initial functions and locals"
Cohesion: 0.40
Nodes (4): Evidence and open gates, Implemented, Limits and safety boundaries, MUT-06 — initial functions and locals

### Community 357 - "11 — Engine, rendering and physics"
Cohesion: 0.18
Nodes (11): 11 — Engine, rendering and physics, Determinism split, Frame graph, Graphics tiers, Layer structure, Performance budgets, Physics tiers, Platform differences (+3 more)

### Community 358 - "ParseErrorCode"
Cohesion: 0.20
Nodes (10): ParseDiagnostic, code, position, ParseErrorCode, expected_closing_bracket, expected_closing_parenthesis, expected_expression, expected_member_name (+2 more)

### Community 359 - "TestPlatform"
Cohesion: 0.22
Nodes (5): TestPlatform, events_, initialized_, next_, window_

### Community 360 - "Frame"
Cohesion: 0.22
Nodes (7): Frame, gpu_timer, gpu_timer_state, query_state, result, scene, ui

### Community 361 - "ArithmeticOp"
Cohesion: 0.29
Nodes (7): ArithmeticOp, divide, minus, multiply, none, plus, remainder

### Community 363 - "VmErrorCode"
Cohesion: 0.18
Nodes (10): VmError, code, pc, VmErrorCode, budget_exceeded, divide_by_zero, invalid_budget, invalid_bytecode (+2 more)

### Community 366 - "MSVC Toolchain (this machine)"
Cohesion: 0.33
Nodes (5): Build dirs, Debug profile flags (cl.exe), MSVC Toolchain (this machine), Performance tuning (Ryzen 7 5700U, 16 GB), Test

### Community 369 - "SemanticDiagnostic"
Cohesion: 0.16
Nodes (11): SemanticDiagnostic, code, position, SemanticResult, diagnostics, Type, args, name (+3 more)

### Community 370 - "ProgramDiagnostic"
Cohesion: 0.29
Nodes (6): ProgramDiagnostic, code, position, stage, Failure, diagnostic

### Community 371 - "decode_item"
Cohesion: 0.27
Nodes (7): Defects found by the new tests during implementation, decode(), decode_item(), fail(), half_to_double(), read_argument(), valid_utf8()

### Community 372 - "TypeDef"
Cohesion: 0.20
Nodes (9): FunctionSig, parameters, position, result, TypeDef, is_enum, member_types, members (+1 more)

### Community 374 - "build_refined.py"
Cohesion: 0.32
Nodes (3): ease(), foot(), interp()

### Community 376 - "frame_stats.cpp"
Cohesion: 0.36
Nodes (6): FrameStats::cpu_ms(), FrameStats::fps(), FrameStats::gpu_ms(), FrameStats::record_cpu(), FrameStats::record_gpu(), window_mean()

### Community 377 - "ENG-14 — CBOR config loader"
Cohesion: 0.33
Nodes (5): ENG-14 — CBOR config loader, Integration review, 2026-11-22, Not done / future, Verification, What was built

### Community 379 - "MUT-13 — Mute v1 scope and API matrix (APPROVED)"
Cohesion: 0.22
Nodes (8): 1. Language feature matrix (proposed v1 decisions), 2. Device and platform matrix (proposed), 3. Game-facing API matrix (proposed v1 contract), 4. Compatibility matrix (proposed), 5. Decisions — APPROVED by owner, 6. Testable criteria this matrix implies, 7. Explicit deferrals (proposed), MUT-13 — Mute v1 scope and API matrix (APPROVED)

### Community 380 - "rem_pio2_large"
Cohesion: 0.29
Nodes (4): floor_value(), Pinned deterministic sin/cos kernels, rem_pio2_large(), scalbn_value()

### Community 388 - "WindowSize"
Cohesion: 0.29
Nodes (5): WindowSize, logical_height, logical_width, pixel_height, pixel_width

### Community 389 - "PokoMeshVertex"
Cohesion: 0.67
Nodes (3): PokoMeshVertex, normal, position

### Community 390 - "TextureMip"
Cohesion: 0.29
Nodes (5): TextureMip, height, pixels, width, VulkanTrianglePass::set_texture_mips()

### Community 391 - "analyze"
Cohesion: 0.28
Nodes (6): analyze(), main(), cases(), error(), main(), ok()

### Community 424 - "Poko UI Design"
Cohesion: 0.50
Nodes (3): Poko UI Design, Rules, Workflow

### Community 425 - "composite"
Cohesion: 0.20
Nodes (3): composite(), ensure_gpu_timer(), Context

### Community 426 - "AppState"
Cohesion: 0.12
Nodes (15): android_main(), AppState, app, done, frames_done, have_size, height, renderer_ready (+7 more)

### Community 427 - "Overrides"
Cohesion: 0.33
Nodes (5): Overrides, adapter_id, adapter_set, validation, validation_set

### Community 428 - "MUT-04 — debug ImGui arithmetic console (2026-11-22)"
Cohesion: 0.33
Nodes (4): Build, MUT-04 — debug ImGui arithmetic console (2026-11-22), Scope and safety, Tests and remaining gates

### Community 430 - "main"
Cohesion: 0.47
Nodes (4): main(), click_input(), image(), window()

### Community 433 - "FrameKind"
Cohesion: 0.33
Nodes (6): FrameKind, binary, call, group, index, prefix

### Community 435 - "2026-11-24"
Cohesion: 0.29
Nodes (6): is_environment_layer_version_warning(), main(), 2026-11-24, CI check at start of session, CI fixed — green on all 5 legs (d6139c3, run 45324845861), Full MUT-01–20 audit — committed and pushed (c7a411f)

### Community 436 - "MUT-07 — initial if/while and runaway trap (2026-11-22)"
Cohesion: 0.40
Nodes (4): Deterministic execution budget, Implemented subset, MUT-07 — initial if/while and runaway trap (2026-11-22), Test evidence and remaining gates

### Community 437 - "DeclarationParser"
Cohesion: 0.26
Nodes (8): decl_fail(), DeclarationParser, ast_, depth_, depth_limit, pos_, source_, tokens_

### Community 438 - "Session report — ENG-14 through ENG-20 + audits"
Cohesion: 0.29
Nodes (6): Audits performed, Delivered, Files of note, Known gaps / not done, Session report — ENG-14 through ENG-20 + audits, Verification

### Community 442 - "Poko Engine Development"
Cohesion: 0.40
Nodes (4): Architecture, Hard rules, Poko Engine Development, Verify before done

### Community 443 - "MUT-05 — print hostcall to the debug console (2026-11-22)"
Cohesion: 0.50
Nodes (3): Evidence and known limitations, Initial contract and boundaries, MUT-05 — print hostcall to the debug console (2026-11-22)

### Community 444 - "IRenderDevice"
Cohesion: 0.24
Nodes (4): IRenderDevice, RESOURCE_STATE_TRANSITION_MODE, RESOURCE_STATE_TRANSITION_MODE_NONE, RESOURCE_STATE_TRANSITION_MODE_TRANSITION

### Community 448 - "StateDecl"
Cohesion: 0.40
Nodes (5): StateDecl, literal, name, negative, pos

### Community 449 - "Mute bytecode and program snapshots"
Cohesion: 0.50
Nodes (3): Mute bytecode and program snapshots, Source-backed compiled-program snapshot `MUTP` v1, Word ISA branch decision and `MUTB` v1

### Community 450 - "Entry"
Cohesion: 0.50
Nodes (4): Entry, integer, pending_integer, value

### Community 453 - "linux-build"
Cohesion: 0.50
Nodes (4): linux-build, name, runs-on, timeout-minutes

### Community 454 - "windows-msvc-nodeps"
Cohesion: 0.50
Nodes (4): windows-msvc-nodeps, name, runs-on, timeout-minutes

### Community 455 - "TypeKind"
Cohesion: 0.50
Nodes (4): TypeKind, generic, named, tuple

### Community 456 - "Sink"
Cohesion: 0.40
Nodes (4): Sink, accept, calls, text

### Community 465 - "Program"
Cohesion: 0.08
Nodes (24): Depth, Expr, args, left, pos, right, text, Function (+16 more)

## Knowledge Gaps
- **1160 isolated node(s):** `cleanup_uncertain`, `context`, `device`, `gl_context`, `gl_library_loaded` (+1155 more)
  These have ≤1 connection - possible missing edges or undocumented components. (Counts symbols only; 3152 node(s) total have ≤1 connection when file, concept and rationale nodes are included.)
- **119 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `transform()` connect `transform` to `array`, `OpenGLClearESRenderer`, `OrbitCamera`?**
  _High betweenness centrality (0.062) - this node is a cross-community bridge._
- **What connects `cleanup_uncertain`, `context`, `device` to the rest of the system?**
  _1160 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `json` be split into smaller, more focused modules?**
  _Cohesion score 0.06656426011264721 - nodes in this community are weakly interconnected._
- **Why does `C++20 Features (Default Practice)` connect `C++20 Features (Default Practice)` to `modern-cpp/SKILL.md`, `transform`, `Concepts`?**
  _High betweenness centrality (0.062) - this node is a cross-community bridge._
- **Should `21 — Engine core` be split into smaller, more focused modules?**
  _Cohesion score 0.11764705882352941 - nodes in this community are weakly interconnected._
- **Should `12 — App interface (egui and Kotlin)` be split into smaller, more focused modules?**
  _Cohesion score 0.04878048780487805 - nodes in this community are weakly interconnected._
- **Should `VulkanTrianglePass::Impl` be split into smaller, more focused modules?**
  _Cohesion score 0.06666666666666667 - nodes in this community are weakly interconnected._