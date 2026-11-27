# Node Description Batch 168 of 209

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

- "extensions_superpowers_skillsdir": "skillsDir" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L11 | neighbors=[superpowers.ts] | lang=en
- "extensions_superpowers_superpowerspiextension": "superpowersPiExtension()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L16 | neighbors=[superpowers.ts] | lang=en
- "fakes_enginefactoryopengl_diligent": "Diligent()" | kind=code-symbol | source=engine/rhi/tests/fakes/EngineFactoryOpenGL.h:L4 | neighbors=[EngineFactoryOpenGL.h] | lang=en
- "fakes_enginefactoryopengl_ienginefactory": "IEngineFactory()" | kind=code-symbol | source=engine/rhi/tests/fakes/EngineFactoryOpenGL.h:L6 | neighbors=[EngineFactoryOpenGL.h] | lang=en
- "fakes_enginefactoryvk_diligent": "Diligent()" | kind=code-symbol | source=engine/rhi/tests/fakes/EngineFactoryVk.h:L7 | neighbors=[EngineFactoryVk.h] | lang=en
- "fakes_refcntautoptr_refcntautoptr_refcntautoptr": ".RefCntAutoPtr()" | kind=code-symbol | source=engine/rhi/tests/fakes/RefCntAutoPtr.hpp:L6 | neighbors=[RefCntAutoPtr] | lang=en
- "fishcenter_fish_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L92 | neighbors=[fish_map.py] | lang=en
- "fishcenter_fish_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L745 | neighbors=[fish_map.py] | lang=en
- "fishcenter_fish_map_rationale_55": "<= 1 inside an islet's ellipse (smallest over all islets)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L55 | neighbors=[islet_e()] | lang=en
- "fishcenter_fish_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L760 | neighbors=[fish_map.py] | lang=en
- "fishcenter_fish_props_rationale_515": "flat-bottomed cumulus for the horizon (SmoothPlastic white)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L515 | neighbors=[cloud()] | lang=en
- "fishcenter_fish_props_rationale_710": "two palms with a striped hammock slung between them on ropes (a resting story)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L710 | neighbors=[hammock_palms()] | lang=pt
- "foundation_cbor_member": "Member()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/cbor.hpp:L51 | neighbors=[cbor.hpp] | lang=en
- "foundation_config_logging_logguard_logguard": ".LogGuard()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/config_logging.hpp:L17 | neighbors=[LogGuard] | lang=en
- "foundation_duration_query_state_begin": "begin()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/duration_query_state.hpp:L9 | neighbors=[duration_query_state.hpp] | lang=en
- "foundation_duration_query_state_durationquerystate": "DurationQueryState" | kind=code-symbol | source=engine/foundation/include/poko/foundation/duration_query_state.hpp:L6 | neighbors=[duration_query_state.hpp] | lang=en
- "foundation_duration_query_state_end": "end()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/duration_query_state.hpp:L16 | neighbors=[duration_query_state.hpp] | lang=en
- "foundation_duration_query_state_poll": "poll()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/duration_query_state.hpp:L23 | neighbors=[duration_query_state.hpp] | lang=en
- "foundation_fixed_divide": "divide()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L123 | neighbors=[fixed.hpp] | lang=en
- "foundation_fixed_fixed_fixed": ".Fixed()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L39 | neighbors=[Fixed] | lang=en
- "foundation_fixed_sqrt": "sqrt()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L143 | neighbors=[fixed.hpp] | lang=en
- "foundation_fixed_vec_cross": "cross()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L137 | neighbors=[fixed_vec.hpp] | lang=en
- "foundation_fixed_vec_fixedvec3": "FixedVec3()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L24 | neighbors=[fixed_vec.hpp] | lang=en
- "foundation_fixed_vec_max": "max()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L81 | neighbors=[fixed_vec.hpp] | lang=en
- "foundation_fixed_vec_min": "min()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L77 | neighbors=[fixed_vec.hpp] | lang=en
- "foundation_frame_stats_framestats": "FrameStats" | kind=code-symbol | source=engine/foundation/include/poko/foundation/frame_stats.hpp:L13 | neighbors=[frame_stats.hpp] | lang=en
- "foundation_loop_fixedsteploop": "FixedStepLoop" | kind=code-symbol | source=engine/foundation/include/poko/foundation/loop.hpp:L27 | neighbors=[loop.hpp] | lang=en
- "foundation_vec3f_cross": "cross()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L59 | neighbors=[vec3f.hpp] | lang=en
- "foundation_vec3f_vec3f": "Vec3f()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L17 | neighbors=[vec3f.hpp] | lang=en
- "framegraph_frame_graph_add_pass": "add_pass()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L21 | neighbors=[frame_graph.cpp] | lang=en
- "framegraph_frame_graph_clear": "clear()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L26 | neighbors=[frame_graph.cpp] | lang=en
- "framegraph_frame_graph_framegraph_framegraph": ".FrameGraph()" | kind=code-symbol | source=engine/render/include/poko/render/framegraph/frame_graph.hpp:L48 | neighbors=[FrameGraph] | lang=en
- "framegraph_frame_graph_import_resource": "import_resource()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L16 | neighbors=[frame_graph.cpp] | lang=en
- "frostpeak_frost_kit_sheet_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_kit_sheet.py:L43 | neighbors=[frost_kit_sheet.py] | lang=en
- "frostpeak_frost_map_canopy_shade": "canopy_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L176 | neighbors=[frost_map.py] | lang=en
- "frostpeak_frost_map_chaikin": "chaikin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L24 | neighbors=[frost_map.py] | lang=en
- "frostpeak_frost_map_horizon_d": "horizon_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L162 | neighbors=[frost_map.py] | lang=en
- "frostpeak_frost_map_rationale_154": "yaw that turns a building's +Z front (its door) toward (tx, tz)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L154 | neighbors=[front_to()] | lang=en
- "frostpeak_frost_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L337 | neighbors=[frost_map.py] | lang=en
- "frostpeak_frost_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L162 | neighbors=[frost_props.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-167.json

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
