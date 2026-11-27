# Node Description Batch 177 of 207

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
- "scripts_brick_rig_rationale_1": "Rig + Roblox export for the BRICK pipeline (always run it: every brick model shi" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L1 | neighbors=[brick_rig.py] | lang=en
- "scripts_brick_rig_rationale_201": "fresh session: import the GLB, check bones + rigid weights, pose, render rest +" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L201 | neighbors=[verify()] | lang=en
- "scripts_brick_rig_rationale_30": "int label per voxel (index into RIG, -1 = empty)." | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L30 | neighbors=[assign()] | lang=it
- "scripts_brick_rig_rationale_46": "overrides that split `mask` (e.g. one tentacle) between its own bones only, by n" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L46 | neighbors=[limb()] | lang=en
- "scripts_brick_rig_rationale_60": "K: 2D int keys (-1 = none). Returns rectangles (i, j, di, dj, key) covering ever" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L60 | neighbors=[_greedy2d()] | lang=en
- "scripts_brick_rig_rationale_75": "greedy quads of the exposed faces of cells with keys >= 0, exposure tested again" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L75 | neighbors=[_quads()] | lang=en
- "scripts_brick_sheet_key": "key()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_sheet.py:L9 | neighbors=[brick_sheet.py] | lang=en
- "scripts_brick_sheet_rationale_1": "Contact sheet of the brick pipeline's *_fx.png renders (3 per row, 450 px tiles," | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/brick_sheet.py:L1 | neighbors=[brick_sheet.py] | lang=en
- "scripts_build_pbr_material_rationale_1": "Build a correct metal/rough PBR material from texture files or a measured preset" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L1 | neighbors=[build_pbr_material.py] | lang=pt
- "scripts_build_pbr_material_rationale_62": "Map type from filename tokens, scanning from the end (suffixes win)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L62 | neighbors=[classify()] | lang=en
- "scripts_compare_rationale_1": "Overlay a render's silhouette on a concept view to check proportions 1:1. py com" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L1 | neighbors=[compare.py] | lang=pt
- "scripts_convert_pb_to_json_rationale_1": "Converts R8 keep radius protobuf files into JSON format." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L1 | neighbors=[convert_pb_to_json.py] | lang=en
- "scripts_convert_pb_to_json_rationale_12": "Reads an R8 BlastRadiusContainer protobuf and writes it as JSON." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L12 | neighbors=[convert_pb_to_json()] | lang=en
- "scripts_convert_pb_to_json_rationale_57": "Entry point for CLI execution." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L57 | neighbors=[main()] | lang=en
- "scripts_decal_rationale_1": "Mesh decal that conforms to a surface without z-fighting: a subdivided plane pla" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L1 | neighbors=[decal.py] | lang=en
- "scripts_decal_rationale_44": "World distance to the target at every evaluated triangle's centroid and corners-" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L44 | neighbors=[_gaps()] | lang=en
- "scripts_env_report_rationale_1": "Report Blender version, engines, GPU, add-ons, units and scene stats as JSON.  U" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L1 | neighbors=[env_report.py] | lang=en
- "scripts_export_asset_rationale_1": "Export objects/collections with engine presets, then verify the file.  Presets:" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L1 | neighbors=[export_asset.py] | lang=en
- "scripts_export_asset_rationale_111": "True if exporting o could carry animation (keys, NLA, drivers, constraints, shap" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L111 | neighbors=[_animated()] | lang=pt
- "scripts_export_asset_rationale_62": "Parse the JSON chunk of a .glb (no import needed)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L62 | neighbors=[glb_summary()] | lang=en
- "scripts_garment_rationale_1": "Game clothing from a body: extract a region as a garment shell (ease offset + th" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L1 | neighbors=[garment.py] | lang=pt

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-176.json

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
