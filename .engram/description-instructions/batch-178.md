# Node Description Batch 179 of 209

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

- "scripts_analyze_rationale_252": "Entry point for CLI execution." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L252 | neighbors=[main()] | lang=en
- "scripts_analyze_rationale_39": "Returns a rule's source text, origin, and whether the app can edit it." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L39 | neighbors=[describe_rule()] | lang=en
- "scripts_analyze_rationale_71": "Computes R8 optimization scores and rule impacts from keep radius JSON." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L71 | neighbors=[analyze()] | lang=en
- "scripts_analyze_rationale_9": "Returns the file, line and Maven coordinate a keep rule comes from." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L9 | neighbors=[rule_origin()] | lang=en
- "scripts_apply_stack_rationale_1": "Build (and optionally apply) a production hard-surface modifier stack.  Presets:" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-hardsurface-modeling/scripts/apply_stack.py:L1 | neighbors=[apply_stack.py] | lang=en
- "scripts_auto_retopo_rationale_1": "Make a low-poly retopo copy of a dense mesh (sculpt/scan/AI-generated) at a tria" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L1 | neighbors=[auto_retopo.py] | lang=pt
- "scripts_bake_action_rationale_1": "Bake animation clips from a control rig onto an export skeleton (visual keying)," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L1 | neighbors=[bake_action.py] | lang=en
- "scripts_bake_maps_rationale_1": "Bake texture maps with Cycles: high->low (selected-to-active) or self-bake proce" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L1 | neighbors=[bake_maps.py] | lang=en
- "scripts_bake_maps_rationale_123": "Divergence of the tangent normal field: convex > 0.5 (white), concave < 0.5 (dar" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L123 | neighbors=[_curvature_from_normal()] | lang=en
- "scripts_bake_maps_rationale_56": "Route a per-material signal into an Emission shader. Returns an undo list." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L56 | neighbors=[_signal_override()] | lang=en
- "scripts_bake_maps_rationale_98": "Ensure every low material has an active Image node pointing at img." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L98 | neighbors=[_target_node()] | lang=en
- "scripts_batch_process_rationale_1": "Batch over many files in one Blender process: convert formats, inventory report," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L1 | neighbors=[batch_process.py] | lang=en
- "scripts_bind_mesh_rationale_1": "Skin meshes to an armature with robust automatic weights, then clean them for en" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L1 | neighbors=[bind_mesh.py] | lang=en
- "scripts_bind_mesh_rationale_72": "Factor that brings the rig to ~1.8 m for bone heat; 1.0 when already 0.5-20 m ta" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L72 | neighbors=[_heat_scale()] | lang=en
- "scripts_bld_grid_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L19 | neighbors=[Grid] | lang=en
- "scripts_bld_rationale_41": "organic shape in fine bricks: fn(x, y, z) -> bool mask, x/z centred, y up (fine" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L41 | neighbors=[.fshape()] | lang=es
- "scripts_bld_rationale_46": "leafy clump / boulder: ellipsoid with a lumpy surface (no smooth sphere)." | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L46 | neighbors=[.blob()] | lang=en
- "scripts_bld_rationale_54": "extrude a traced reference map (scripts/trace_ref.py) in fine bricks: 1 cell = 1" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L54 | neighbors=[.trace()] | lang=en
- "scripts_bld_rationale_90": "front-facing window in fine bricks; zf = fine z of the wall's outer layer. Pane" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L90 | neighbors=[.window()] | lang=en
- "scripts_blocks_block_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L17 | neighbors=[Block] | lang=en
- "scripts_blocks_blockprop_count": ".count()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L35 | neighbors=[BlockProp] | lang=en
- "scripts_blocks_blockprop_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L25 | neighbors=[BlockProp] | lang=en
- "scripts_blocks_clear_material": "clear_material()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L145 | neighbors=[blocks.py] | lang=en
- "scripts_blocks_rationale_30": "nest another BlockProp (e.g. a lamp on a gate)" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L30 | neighbors=[.put()] | lang=pt
- "scripts_blocks_rationale_38": "world-space copies of a prop's blocks (uniform scale s scales sizes and offsets)" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L38 | neighbors=[transformed()] | lang=en
- "scripts_bpyx_default": "_default()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L24 | neighbors=[_bpyx.py] | lang=en
- "scripts_bpyx_rationale_1": "_bpyx - tiny shared helpers for blender-agent-skills scripts (Blender 5.2 LTS+," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L1 | neighbors=[_bpyx.py] | lang=en
- "scripts_bpyx_rationale_100": "First node of `type_` (e.g. 'BSDF_PRINCIPLED'). Names are localized - never look" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L100 | neighbors=[node()] | lang=en
- "scripts_bpyx_rationale_105": "Valid identifiers of an enum property (works on types or instances)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L105 | neighbors=[enum_ids()] | lang=en
- "scripts_bpyx_rationale_110": "Assign an enum; on failure raise listing valid values (dynamic enums under-repor" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L110 | neighbors=[set_enum()] | lang=en
- "scripts_bpyx_rationale_118": "Triangle count (evaluated = with modifiers)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L118 | neighbors=[mesh_tris()] | lang=en
- "scripts_bpyx_rationale_133": "Round a float or a vector for compact JSON." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L133 | neighbors=[r()] | lang=pt
- "scripts_bpyx_rationale_20": "Arguments after '--' (Blender ignores them)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L20 | neighbors=[argv()] | lang=en
- "scripts_bpyx_rationale_36": "Print compact JSON on one marked line (parsed by run_in_blender.py)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L36 | neighbors=[emit()] | lang=en
- "scripts_bpyx_rationale_42": "ArgumentParser whose help is the script docstring's first line." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L42 | neighbors=[parser()] | lang=en
- "scripts_bpyx_rationale_47": "CLI entry: parse args after '--', run, emit JSON. Exit 1 on failure." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L47 | neighbors=[cli()] | lang=en
- "scripts_bpyx_rationale_63": "--objects / --save flags shared by most scripts." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L63 | neighbors=[add_common()] | lang=en
- "scripts_bpyx_rationale_72": "Resolve names -> objects. No names: selected of `types`, else all visible of `ty" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L72 | neighbors=[objects()] | lang=en
- "scripts_bpyx_rationale_84": "Leave edit/sculpt/pose modes; most data API work needs OBJECT mode." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L84 | neighbors=[object_mode()] | lang=en
- "scripts_bpyx_rationale_91": "Select exactly `objs` and make `active` (default first) active." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L91 | neighbors=[select_only()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-178.json

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
