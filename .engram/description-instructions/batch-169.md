# Node Description Batch 170 of 208

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
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "lexer_lexer_name": "name()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L157 | neighbors=[lexer.cpp] | lang=en
- "lexer_unicode_xid_contains": "contains()" | kind=code-symbol | source=mute/src/lexer/unicode_xid.hpp:L1455 | neighbors=[unicode_xid.hpp] | lang=en
- "medievalbattle_battle_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L521 | neighbors=[battle_map.py] | lang=en
- "medievalbattle_battle_map_rationale_285": "flagstone courtyard inside a keep (static hardscape)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L285 | neighbors=[courtyard()] | lang=pt
- "medievalbattle_battle_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L529 | neighbors=[battle_map.py] | lang=en
- "medievalbattle_battle_props_rationale_158": "one real block (ruins, rubble, steps, quoins)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L158 | neighbors=[stone()] | lang=en
- "medievalbattle_battle_props_rationale_347": "elliptical / segmental arch outline in XY, open at the bottom (feet at y = 0)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L347 | neighbors=[ell_outline()] | lang=en
- "medievalbattle_battle_props_rationale_626": "one face of the bridge tower in canonical orientation (face plane z = -d)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L626 | neighbors=[tower_face()] | lang=en
- "medievalbattle_battle_props_rationale_63": "square timber from a to b (w across, t thick)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L63 | neighbors=[bar()] | lang=en
- "mesh_enginefactoryvk_cleardepthstencil": "ClearDepthStencil()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L76 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_clearrendertarget": "ClearRenderTarget()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L75 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_commitshaderresources": "CommitShaderResources()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L73 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_creategraphicspipelinestate": "CreateGraphicsPipelineState()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L60 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_createsampler": "CreateSampler()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L59 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_createshader": "CreateShader()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L55 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_createshaderresourcebinding": "CreateShaderResourceBinding()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L40 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_createtexture": "CreateTexture()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L58 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_diligent": "Diligent()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L6 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_draw": "Draw()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L81 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_drawindexed": "DrawIndexed()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L80 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_getdepthbufferdsv": "GetDepthBufferDSV()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L66 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_mesh_fake": "mesh_fake()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L5 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_release": "Release()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L34 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_set": "Set()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L29 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_setindexbuffer": "SetIndexBuffer()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L79 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_setpipelinestate": "SetPipelineState()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L77 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_setrendertargets": "SetRenderTargets()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L74 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_setsampler": "SetSampler()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L32 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_setvertexbuffers": "SetVertexBuffers()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L78 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_unmapbuffer": "UnmapBuffer()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L69 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_enginefactoryvk_updatetexture": "UpdateTexture()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L72 | neighbors=[EngineFactoryVk.h] | lang=en
- "mesh_refcntautoptr_refcntautoptr_refcntautoptr": ".RefCntAutoPtr()" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/RefCntAutoPtr.hpp:L7 | neighbors=[RefCntAutoPtr] | lang=en
- "migrations_0002_ledger_balances_balances": "balances" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L20 | neighbors=[0002_ledger_balances.sql] | lang=en
- "migrations_0002_ledger_balances_ledger_entries": "ledger_entries" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L4 | neighbors=[0002_ledger_balances.sql] | lang=en
- "migrations_0003_cases_audit_audit_log": "audit_log" | kind=code-symbol | source=backend/storage/postgres/migrations/0003_cases_audit.sql:L12 | neighbors=[0003_cases_audit.sql] | lang=en
- "migrations_0003_cases_audit_cases": "cases" | kind=code-symbol | source=backend/storage/postgres/migrations/0003_cases_audit.sql:L2 | neighbors=[0003_cases_audit.sql] | lang=en
- "moonclean_moon_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L486 | neighbors=[moon_map.py] | lang=en
- "moonclean_moon_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L516 | neighbors=[moon_map.py] | lang=en
- "moonclean_moon_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L524 | neighbors=[moon_map.py] | lang=en
- "moonclean_moon_map_tang_yaw": "tang_yaw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L181 | neighbors=[moon_map.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-169.json

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
