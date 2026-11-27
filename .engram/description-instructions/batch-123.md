# Node Description Batch 124 of 207

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

- "scripts_bld_grid_cut": ".cut()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L31 | neighbors=[Grid, ._sl()] | lang=en
- "scripts_bld_grid_export": ".export()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L100 | neighbors=[Grid, _c()] | lang=en
- "scripts_bld_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L11 | neighbors=[bld.py, _c()] | lang=en
- "scripts_blocks_f": "_f()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L154 | neighbors=[blocks.py, write_rbxmx()] | lang=en
- "scripts_blocks_neon_mat": "neon_mat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L102 | neighbors=[blocks.py, mesh_blocks()] | lang=en
- "scripts_blocks_rationale_112": "palette material + procedural studs (one round stud per `studs` studs, on every" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L112 | neighbors=[stud_material(), MB] | lang=it
- "scripts_blocks_rationale_157": "groups: {folder name: [Block, ...]} in world space. Writes a Model with one Fold" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L157 | neighbors=[write_rbxmx(), MB] | lang=en
- "scripts_blocks_rationale_21": "(pitch about X, yaw about Y, roll about Z) degrees, same order as pro_lib.xf" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L21 | neighbors=[rotm(), MB] | lang=en
- "scripts_blocks_rationale_72": "one solid mesh (palette + studs) + one mesh per neon colour + one for transparen" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L72 | neighbors=[mesh_blocks(), MB] | lang=en
- "scripts_blocks_shape_bm": "shape_bm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L53 | neighbors=[blocks.py, mesh_blocks()] | lang=en
- "scripts_blocks_stud_material": "stud_material()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L111 | neighbors=[blocks.py, palette material + procedural studs (on…] | lang=en
- "scripts_bpyx_add_common": "add_common()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L62 | neighbors=[_bpyx.py, --objects / --save flags shared by most…] | lang=en
- "scripts_bpyx_enum_ids": "enum_ids()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L104 | neighbors=[_bpyx.py, Valid identifiers of an enum property (…] | lang=en
- "scripts_bpyx_mesh_tris": "mesh_tris()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L117 | neighbors=[_bpyx.py, Triangle count (evaluated = with modifi…] | lang=en
- "scripts_bpyx_node": "node()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L99 | neighbors=[_bpyx.py, First node of `type_` (e.g. 'BSDF_PRINC…] | lang=en
- "scripts_bpyx_object_mode": "object_mode()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L83 | neighbors=[_bpyx.py, Leave edit/sculpt/pose modes; most data…] | lang=en
- "scripts_bpyx_objects": "objects()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L71 | neighbors=[_bpyx.py, Resolve names -> objects. No names: sel…] | lang=en
- "scripts_bpyx_parser": "parser()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L41 | neighbors=[_bpyx.py, ArgumentParser whose help is the script…] | lang=en
- "scripts_bpyx_r": "r()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L132 | neighbors=[_bpyx.py, Round a float or a vector for compact J…] | lang=en
- "scripts_bpyx_select_only": "select_only()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L90 | neighbors=[_bpyx.py, Select exactly `objs` and make `active`…] | lang=en
- "scripts_bpyx_set_enum": "set_enum()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L109 | neighbors=[_bpyx.py, Assign an enum; on failure raise listin…] | lang=en
- "scripts_brick_rig_dilate6": "_dilate6()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L51 | neighbors=[brick_rig.py, export()] | lang=en
- "scripts_build_pbr_material_gltf_output_group": "_gltf_output_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L91 | neighbors=[build_pbr_material.py, run()] | lang=en
- "scripts_build_pbr_material_srgb_to_lin": "_srgb_to_lin()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L57 | neighbors=[build_pbr_material.py, run()] | lang=en
- "scripts_compare_bbox": "bbox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L20 | neighbors=[compare.py, main()] | lang=en
- "scripts_compare_concept_mask": "concept_mask()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L12 | neighbors=[compare.py, main()] | lang=en
- "scripts_contact_sheet": "contact_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/contact_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "scripts_decal_grid": "_grid()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L63 | neighbors=[decal.py, run()] | lang=en
- "scripts_decal_material": "_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L24 | neighbors=[decal.py, run()] | lang=en
- "scripts_env_report_gpu": "_gpu()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L17 | neighbors=[env_report.py, run()] | lang=en
- "scripts_env_report_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L27 | neighbors=[env_report.py, _gpu()] | lang=en
- "scripts_export_asset_coerce": "_coerce()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L101 | neighbors=[export_asset.py, run()] | lang=en
- "scripts_export_asset_export": "_export()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L93 | neighbors=[export_asset.py, run()] | lang=en
- "scripts_export_asset_gather": "_gather()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L79 | neighbors=[export_asset.py, run()] | lang=en
- "scripts_garment_region": "_region()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L29 | neighbors=[garment.py, run()] | lang=en
- "scripts_garment_transfer_weights": "_transfer_weights()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L65 | neighbors=[garment.py, run()] | lang=en
- "scripts_gn_builder_apply": "apply()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L152 | neighbors=[gn_builder.py, run()] | lang=en
- "scripts_gn_builder_parse_val": "_parse_val()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L167 | neighbors=[gn_builder.py, run()] | lang=en
- "scripts_gn_builder_sock": "_sock()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L67 | neighbors=[gn_builder.py, build()] | lang=en
- "scripts_groom_assets": "_assets()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L35 | neighbors=[groom.py, groom()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-123.json

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
