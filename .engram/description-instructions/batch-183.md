# Node Description Batch 184 of 207

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

- "semantic_lower_is_cmp": "is_cmp()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L79 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_lowerer_lowerer": ".Lowerer()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L91 | neighbors=[Lowerer] | lang=en
- "semantic_lower_pv": "pv()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L13 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_v": "v()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L12 | neighbors=[lower.cpp] | lang=en
- "semantic_optimize_simplify_control_flow": "simplify_control_flow()" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L42 | neighbors=[optimize.cpp] | lang=en
- "semantic_semantic_analyze": "analyze()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L419 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_analyzer_analyzer": ".Analyzer()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L409 | neighbors=[Analyzer] | lang=en
- "semantic_semantic_generic_arity": "generic_arity()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L63 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_generic_tag": "generic_tag()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L68 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_is_assign_op": "is_assign_op()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L60 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_scalar": "scalar()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L49 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_type_name": "type_name()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L35 | neighbors=[semantic.cpp] | lang=en
- "semantic_ssa_dump_ir": "dump_ir()" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L196 | neighbors=[ssa.cpp] | lang=en
- "semantic_ssa_name": "name()" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L211 | neighbors=[ssa.cpp] | lang=en
- "sh": "Sh" | kind=code-symbol | neighbors=[ShAng] | lang=en
- "shared_bpyx_default": "_default()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L24 | neighbors=[_bpyx.py] | lang=en
- "shared_bpyx_rationale_1": "_bpyx - tiny shared helpers for blender-agent-skills scripts (Blender 5.2 LTS+," | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L1 | neighbors=[_bpyx.py] | lang=en
- "shared_bpyx_rationale_100": "First node of `type_` (e.g. 'BSDF_PRINCIPLED'). Names are localized - never look" | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L100 | neighbors=[node()] | lang=en
- "shared_bpyx_rationale_105": "Valid identifiers of an enum property (works on types or instances)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L105 | neighbors=[enum_ids()] | lang=en
- "shared_bpyx_rationale_110": "Assign an enum; on failure raise listing valid values (dynamic enums under-repor" | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L110 | neighbors=[set_enum()] | lang=en
- "shared_bpyx_rationale_118": "Triangle count (evaluated = with modifiers)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L118 | neighbors=[mesh_tris()] | lang=en
- "shared_bpyx_rationale_133": "Round a float or a vector for compact JSON." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L133 | neighbors=[r()] | lang=pt
- "shared_bpyx_rationale_20": "Arguments after '--' (Blender ignores them)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L20 | neighbors=[argv()] | lang=en
- "shared_bpyx_rationale_36": "Print compact JSON on one marked line (parsed by run_in_blender.py)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L36 | neighbors=[emit()] | lang=en
- "shared_bpyx_rationale_42": "ArgumentParser whose help is the script docstring's first line." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L42 | neighbors=[parser()] | lang=en
- "shared_bpyx_rationale_47": "CLI entry: parse args after '--', run, emit JSON. Exit 1 on failure." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L47 | neighbors=[cli()] | lang=en
- "shared_bpyx_rationale_63": "--objects / --save flags shared by most scripts." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L63 | neighbors=[add_common()] | lang=en
- "shared_bpyx_rationale_72": "Resolve names -> objects. No names: selected of `types`, else all visible of `ty" | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L72 | neighbors=[objects()] | lang=en
- "shared_bpyx_rationale_84": "Leave edit/sculpt/pose modes; most data API work needs OBJECT mode." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L84 | neighbors=[object_mode()] | lang=en
- "shared_bpyx_rationale_91": "Select exactly `objs` and make `active` (default first) active." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L91 | neighbors=[select_only()] | lang=en
- "skyrise_sky_kit_sheet_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_kit_sheet.py:L45 | neighbors=[sky_kit_sheet.py] | lang=en
- "skyrise_sky_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L431 | neighbors=[sky_map.py] | lang=en
- "skyrise_sky_map_rationale_115": "widest horizontal reach of a kit prop (all parts)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L115 | neighbors=[ext()] | lang=en
- "skyrise_sky_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L415 | neighbors=[sky_map.py] | lang=en
- "skyrise_sky_models_rationale_10": "icosphere with noise displacement: chunky stylised foliage / cloud / rock lump" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L10 | neighbors=[lumpy()] | lang=en
- "skyrise_sky_models_rationale_110": "underside: 16 rings to a rough tip, noise-displaced (no big flat triangles), ter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L110 | neighbors=[island_under()] | lang=en
- "skyrise_sky_models_rationale_203": "carved stone gate: stepped plinths, octagonal banded shafts with capitals, a vou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L203 | neighbors=[zone_gate()] | lang=en
- "skyrise_sky_models_rationale_23": "trunk that forks into 2-3 limbs, root flares into the ground, chunky lumpy canop" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L23 | neighbors=[puffy_tree()] | lang=en
- "skyrise_sky_models_rationale_76": "pine: 4 star tiers with drooping snow caps, trunk, root collar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L76 | neighbors=[snow_tree()] | lang=en
- "skyrise_sky_models2_rationale_113": "ribbed saguaro: star-section body, two elbowed arms, flowers, pebbles" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L113 | neighbors=[cactus()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-183.json

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
