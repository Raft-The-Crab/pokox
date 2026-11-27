# Node Description Batch 197 of 208

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

- "towncity_town_street_rationale_111": "municipal bin: base, ribbed teal body, yellow band, dome lid with a dark mouth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L111 | neighbors=[litter_bin()] | lang=en
- "towncity_town_street_rationale_124": "fire hydrant: lathed red body, bonnet + yellow nut, 3 hose outlets with yellow c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L124 | neighbors=[hydrant()] | lang=en
- "towncity_town_street_rationale_136": "commercial dumpster: tapered body, rim, two lids (one propped open on a trash ba" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L136 | neighbors=[dumpster()] | lang=pt
- "towncity_town_street_rationale_159": "heap of bin bags + two cardboard boxes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L159 | neighbors=[trash_bags()] | lang=en
- "towncity_town_street_rationale_170": "3 stacked shipping pallets (deck boards over stringers) + a box on top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L170 | neighbors=[pallets()] | lang=pt
- "towncity_town_street_rationale_180": "alley wall services (stands against a wall whose face is at z = 0, pieces toward" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L180 | neighbors=[wall_pipes()] | lang=en
- "towncity_town_street_rationale_193": "tree: flared trunk with roots, 4 limbs, 6 overlapping smooth leaf masses as one" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L193 | neighbors=[street_tree()] | lang=en
- "towncity_town_street_rationale_233": "low stone-edged bed with a row of leaf clumps and flowers in alternating colours" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L233 | neighbors=[flower_bed()] | lang=en
- "towncity_town_street_rationale_248": "the street tree pit alone (stone kerb + iron grate + trunk ring): the realistic" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L248 | neighbors=[street_grate()] | lang=en
- "towncity_town_street_rationale_44": "mast-arm signal: base + yellow pole, arm over the road along +X, two 3-lens head" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L44 | neighbors=[traffic_light()] | lang=en
- "towncity_town_street_rationale_72": "park bench: cast-iron scroll ends (profile prism), 4 seat slats + 3 back slats," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L72 | neighbors=[bench()] | lang=en
- "towncity_town_street_rationale_8": "town lantern post: two-step octagonal plinth, tapered shaft with collars, scroll" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L8 | neighbors=[street_lamp()] | lang=en
- "towncity_town_street_rationale_91": "stone planter box: plinth, panelled body, coping, soil, layered shrub + flowers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L91 | neighbors=[planter()] | lang=en
- "towncity_town_vehicles_rationale_102": "city bus: lofted box body, raked windscreen, window band with pillars, two doors" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L102 | neighbors=[bus()] | lang=en
- "towncity_town_vehicles_rationale_136": "carriage / cab section loft: rounded roof shoulders, raked nose at the front whe" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L136 | neighbors=[_car_shell()] | lang=en
- "towncity_town_vehicles_rationale_164": "commuter train car: lofted shell (teal skirt, yellow belt stripe, cream upper, g" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L164 | neighbors=[train_car()] | lang=en
- "towncity_town_vehicles_rationale_195": "one track segment along Z: ballast bed, 12 sleepers, two rails with chairs" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L195 | neighbors=[track_seg()] | lang=en
- "towncity_town_vehicles_rationale_22": "lofted body: ring per section s (0 front .. 1 rear); belt_f(s) shoulder height," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L22 | neighbors=[body_shell()] | lang=it
- "towncity_town_vehicles_rationale_35": "face colours: rocker + underside dark metal, glass above the belt (except near-f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L35 | neighbors=[body_shader()] | lang=en
- "towncity_town_vehicles_rationale_54": "stylised car: lofted body + greenhouse, wheels with hubs, grille, head/tail ligh" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L54 | neighbors=[car()] | lang=en
- "transitions_build_transitions_capture": "capture()" | kind=code-symbol | source=assets/characters/transitions/build_transitions.py:L6 | neighbors=[build_transitions.py] | lang=en
- "transitions_v2_build_transitions_capture": "capture()" | kind=code-symbol | source=assets/characters/transitions-v2/build_transitions.py:L7 | neighbors=[build_transitions.py] | lang=en
- "transitions_verify_transition_endpoints_diff": "diff()" | kind=code-symbol | source=assets/characters/transitions/verify_transition_endpoints.py:L7 | neighbors=[verify_transition_endpoints.py] | lang=en
- "transitions_verify_transition_endpoints_pose": "pose()" | kind=code-symbol | source=assets/characters/transitions/verify_transition_endpoints.py:L5 | neighbors=[verify_transition_endpoints.py] | lang=en
- "triangle_enginefactoryvk_cleardepthstencil": "ClearDepthStencil()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L72 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_clearrendertarget": "ClearRenderTarget()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L71 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_commitshaderresources": "CommitShaderResources()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L69 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_creategraphicspipelinestate": "CreateGraphicsPipelineState()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L57 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_createsampler": "CreateSampler()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L56 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_createshader": "CreateShader()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L54 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_createshaderresourcebinding": "CreateShaderResourceBinding()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L39 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_createtexture": "CreateTexture()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L55 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_diligent": "Diligent()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L6 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_draw": "Draw()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L74 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_getdepthbufferdsv": "GetDepthBufferDSV()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L63 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_if": "if()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L52 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_release": "Release()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L33 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_set": "Set()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L28 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_setpipelinestate": "SetPipelineState()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L73 | neighbors=[EngineFactoryVk.h] | lang=en
- "triangle_enginefactoryvk_setrendertargets": "SetRenderTargets()" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L70 | neighbors=[EngineFactoryVk.h] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-196.json

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
