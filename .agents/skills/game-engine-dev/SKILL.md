---
name: game-engine-dev
description: Working agreements for Poko engine development — architecture boundaries, the Mute language, RHI backends, and verification workflow. Use for any engine feature, renderer, resource, or language work.
---

# Poko Engine Development

## Architecture

- `engine/foundation` — CBOR, config, frame stats (no deps)
- `engine/resource` — KTX2, PMES/pokomesh, AssetStore
- `engine/render` — camera, frame graph, directional light
- `engine/rhi` — Vulkan, OpenGL/GLES, D3D12 (MSVC+SDK only), SDL platform, Android JNI
- `engine/platform` — SDL3 windowing/input
- `mute/` — Mute language: lexer, parser, evaluator, bytecode VM, program VM, deterministic musl_math

## Hard rules

- External/binary input is untrusted: CBOR, KTX2, PMES, bytecode, Mute source — always bounds-check and cap allocations.
- `run_program`/`evaluate_arithmetic` paths have strict depth/budget guards — preserve them; recursion depth is bounded by design (VM needs ~8MB stack on MSVC debug).
- FP determinism: evaluator masks host FP traps via MXCSR; do NOT enable fast-math or change rounding on `poko_mute_evaluator`/`poko_mute_math`.
- New public options go through `POKO_WITH_*` CMake flags; demos behind `POKO_WITH_*_DEMO`.
- D3D12 requires MSVC + Windows SDK (`POKO_D3D12=ON` fails under MinGW by design).

## Verify before done

1. `graphify query` first for codebase questions (graphify-out/ exists).
2. Build: `msvc-debug.bat` (or `build-msvc` for plain debug).
3. `ctest -j 12` — baseline is 65 tests; all must pass.
4. After source edits run `graphify update .`.
5. Match existing style: compact code, no new comments unless needed, exceptions only at documented boundaries.
