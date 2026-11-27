# Node Description Batch 199 of 209

Engram is running in assistant/skill mode (no API key). You are the host
assistant (Claude Code / Codex / Gemini CLI). Read the prompt below and write
your JSON answer to the answer file.

## Prompt

You are documenting nodes in a knowledge graph.
For each entry below, write ONE concise factual plain-language sentence
describing what it is or does. Use only the provided context.
For a code symbol (kind=code-symbol — a function, class, or constant),
describe what the function/symbol does based on its name, source location
and neighbors — e.g. "Resolves the configured ontology profile from graphify.yaml.".
For an entity node (any other kind — e.g. a person, place, event, object),
describe what the entity is and its role, grounded in its type, its
relations (neighbors) and the provided citations/evidence — e.g.
"Lady Carfax, a wealthy heiress who disappears en route to Lausanne.".
Ground entity descriptions in the citations/evidence when present; do not
speculate beyond the context, so a node with no supporting context may be
left out of the reply.
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "triangle_enginefactoryvk_diligent": "Diligent()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L6 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_draw": "Draw()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L74 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_getdepthbufferdsv": "GetDepthBufferDSV()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L63 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_if": "if()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L52 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_release": "Release()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L33 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_set": "Set()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L28 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_setpipelinestate": "SetPipelineState()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L73 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_setrendertargets": "SetRenderTargets()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L70 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_setsampler": "SetSampler()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L31 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_triangle_fake": "triangle_fake()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L5 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_unmapbuffer": "UnmapBuffer()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L65 | neighbors=[EngineFactoryVk.h]
- "triangle_enginefactoryvk_updatetexture": "UpdateTexture()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L68 | neighbors=[EngineFactoryVk.h]
- "triangle_refcntautoptr_refcntautoptr_refcntautoptr": ".RefCntAutoPtr()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/RefCntAutoPtr.hpp:L7 | neighbors=[RefCntAutoPtr]
- "unit_asset_allocation_test_main": "main()" | kind=code-symbol | source=engine/resource/tests/unit/asset_allocation_test.cpp:L18 | neighbors=[asset_allocation_test.cpp]
- "unit_bit_buffer_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/bit_buffer_test.cpp:L11 | neighbors=[bit_buffer_test.cpp]
- "unit_bytecode_vm_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/bytecode_vm_test.cpp:L14 | neighbors=[bytecode_vm_test.cpp]
- "unit_check_framegraph_mutations_rationale_1": "Optional fault-sensitivity test; compiles intentional defects in temp files." | kind=entity | source=engine/render/tests/unit/check_framegraph_mutations.py:L1 | neighbors=[check_framegraph_mutations.py]
- "unit_clear_backend_selection_fake": "Fake()" | kind=code-symbol | source=engine/rhi/tests/unit/clear_backend_selection.cpp:L10 | neighbors=[clear_backend_selection.cpp]
- "unit_clear_backend_selection_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/clear_backend_selection.cpp:L15 | neighbors=[clear_backend_selection.cpp]
- "unit_config_allocation_test_allocate_or_throw": "allocate_or_throw()" | kind=code-symbol | source=engine/foundation/tests/unit/config_allocation_test.cpp:L17 | neighbors=[config_allocation_test.cpp]
- "unit_config_allocation_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/config_allocation_test.cpp:L62 | neighbors=[config_allocation_test.cpp]
- "unit_config_logging_guard_test_info": "info()" | kind=code-symbol | source=engine/foundation/tests/unit/config_logging_guard_test.cpp:L32 | neighbors=[config_logging_guard_test.cpp]
- "unit_config_logging_guard_test_init": "init()" | kind=code-symbol | source=engine/foundation/tests/unit/config_logging_guard_test.cpp:L26 | neighbors=[config_logging_guard_test.cpp]
- "unit_config_logging_guard_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/config_logging_guard_test.cpp:L36 | neighbors=[config_logging_guard_test.cpp]
- "unit_config_logging_guard_test_shutdown": "shutdown()" | kind=code-symbol | source=engine/foundation/tests/unit/config_logging_guard_test.cpp:L31 | neighbors=[config_logging_guard_test.cpp]
- "unit_console_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/console_test.cpp:L19 | neighbors=[console_test.cpp]
- "unit_console_test_write": "write()" | kind=code-symbol | source=mute/tests/unit/console_test.cpp:L15 | neighbors=[console_test.cpp]
- "unit_cube_sync_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/cube_sync_test.cpp:L12 | neighbors=[cube_sync_test.cpp]
- "unit_declaration_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/declaration_dump.cpp:L12 | neighbors=[declaration_dump.cpp]
- "unit_delta_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/delta_test.cpp:L12 | neighbors=[delta_test.cpp]
- "unit_deterministic_math_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/deterministic_math_dump.cpp:L8 | neighbors=[deterministic_math_dump.cpp]
- "unit_deterministic_math_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/deterministic_math_test.cpp:L12 | neighbors=[deterministic_math_test.cpp]
- "unit_device_binding_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/device_binding_test.cpp:L12 | neighbors=[device_binding_test.cpp]
- "unit_directional_light_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/directional_light_test.cpp:L6 | neighbors=[directional_light_test.cpp]
- "unit_duration_query_state_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/duration_query_state_test.cpp:L3 | neighbors=[duration_query_state_test.cpp]
- "unit_evaluator_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/evaluator_dump.cpp:L16 | neighbors=[evaluator_dump.cpp]
- "unit_flags_contract_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/flags_contract.cpp:L8 | neighbors=[flags_contract.cpp]
- "unit_frame_graph_test_main": "main()" | kind=code-symbol | source=engine/render/tests/unit/frame_graph_test.cpp:L15 | neighbors=[frame_graph_test.cpp]
- "unit_frame_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/frame_test.cpp:L10 | neighbors=[frame_test.cpp]
- "unit_i_platform_contract_main": "main()" | kind=code-symbol | source=engine/platform/tests/unit/i_platform_contract.cpp:L64 | neighbors=[i_platform_contract.cpp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-198.json

Keep each description factual and concise (one sentence). No markdown, no prose
outside the JSON object. It is acceptable to omit a node if context is
insufficient — but include every node you can ground confidently.

Example answer format:
```json
{
  "node_id_1": "Resolves the configured ontology profile from graphify.yaml.",
  "node_id_2": "Colonel James Barclay, an antagonist in The Crooked Man."
}
```
