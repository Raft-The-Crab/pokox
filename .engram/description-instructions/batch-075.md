# Node Description Batch 76 of 207

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "scripts_bind_mesh_ctx": "_ctx()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L22 | neighbors=[bind_mesh.py, cleanup(), _proxy_weights()]
- "scripts_bind_mesh_height": "_height()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L66 | neighbors=[bind_mesh.py, _heat_scale(), run()]
- "scripts_bind_mesh_parent": "_parent()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L33 | neighbors=[bind_mesh.py, _proxy_weights(), run()]
- "scripts_bld_grid_blob": ".blob()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L45 | neighbors=[Grid, .fshape(), leafy clump / boulder: ellipsoid with a…]
- "scripts_bld_grid_box": ".box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L28 | neighbors=[Grid, _c(), ._sl()]
- "scripts_bld_grid_fcut": ".fcut()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L37 | neighbors=[Grid, ._sl(), .window()]
- "scripts_bld_grid_trace": ".trace()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L53 | neighbors=[Grid, .fshape(), extrude a traced reference map (scripts…]
- "scripts_blocks_blockprop_b": ".b()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L26 | neighbors=[BlockProp, Block, rotm()]
- "scripts_blocks_rgb_of": "rgb_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L47 | neighbors=[blocks.py, mesh_blocks(), write_rbxmx()]
- "scripts_bpyx_argv": "argv()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L19 | neighbors=[_bpyx.py, cli(), Arguments after '--' (Blender ignores t…]
- "scripts_bpyx_emit": "emit()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L35 | neighbors=[_bpyx.py, cli(), Print compact JSON on one marked line (…]
- "scripts_brick_rig_greedy2d": "_greedy2d()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L59 | neighbors=[brick_rig.py, _quads(), K: 2D int keys (-1 = none). Returns rec…]
- "scripts_brick_rig_limb": "limb()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L45 | neighbors=[brick_rig.py, assign(), overrides that split `mask` (e.g. one t…]
- "scripts_brick_rig_verify": "verify()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L200 | neighbors=[brick_rig.py, export(), fresh session: import the GLB, check bo…]
- "scripts_build_pbr_material_classify": "classify()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L61 | neighbors=[build_pbr_material.py, _find_textures(), Map type from filename tokens, scanning…]
- "scripts_build_pbr_material_find_textures": "_find_textures()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L72 | neighbors=[build_pbr_material.py, classify(), run()]
- "scripts_compare_main": "main()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L25 | neighbors=[compare.py, bbox(), concept_mask()]
- "scripts_convert_pb_to_json_convert_pb_to_json": "convert_pb_to_json()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L11 | neighbors=[convert_pb_to_json.py, main(), Reads an R8 BlastRadiusContainer protob…]
- "scripts_convert_pb_to_json_main": "main()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L56 | neighbors=[convert_pb_to_json.py, convert_pb_to_json(), Entry point for CLI execution.]
- "scripts_decal_gaps": "_gaps()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L43 | neighbors=[decal.py, World distance to the target at every e…, run()]
- "scripts_export_asset_animated": "_animated()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L110 | neighbors=[export_asset.py, True if exporting o could carry animati…, run()]
- "scripts_export_asset_glb_summary": "glb_summary()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L61 | neighbors=[export_asset.py, Parse the JSON chunk of a .glb (no impo…, run()]
- "scripts_garment_drape": "_drape()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L99 | neighbors=[garment.py, Classic cloth: pin the top band, collid…, run()]
- "scripts_garment_hide_body": "_hide_body()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L83 | neighbors=[garment.py, Vertex group of body verts strictly ins…, run()]
- "scripts_garment_penetration": "penetration()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L170 | neighbors=[garment.py, Body verts (evaluated pose) poking thro…, run()]
- "scripts_garment_shell": "_shell()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L42 | neighbors=[garment.py, Copy the region's faces in world space …, run()]
- "scripts_garment_transfer_morphs": "transfer_morphs()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L131 | neighbors=[garment.py, Same-named garment shape key for every …, run()]
- "scripts_generate_report_format_code_link": "format_code_link()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L63 | neighbors=[generate_report.py, Formats file paths and line numbers int…, render_finding_card()]
- "scripts_generate_report_parse_boolean": "parse_boolean()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L130 | neighbors=[generate_report.py, aggregate_findings(), Safely converts boolean or sloppy strin…]
- "scripts_generate_report_parse_disclosure_status": "parse_disclosure_status()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L140 | neighbors=[generate_report.py, aggregate_findings(), Safely parses disclosure enums or visua…]
- "scripts_generate_report_render_table": "render_table()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L96 | neighbors=[generate_report.py, main(), Renders a Markdown table from a list of…]
- "scripts_generate_report_run_scraper": "run_scraper()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L38 | neighbors=[generate_report.py, main(), Invokes the Play Store scraper directly.]
- "scripts_gn_builder_describe": "describe()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L38 | neighbors=[gn_builder.py, Inputs/outputs (name, type, default) of…, run()]
- "scripts_gn_builder_layout": "_layout()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L134 | neighbors=[gn_builder.py, build(), Column layout by longest path from inpu…]
- "scripts_groom_curve_stats": "curve_stats()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L135 | neighbors=[groom.py, _evaluated(), groom()]
- "scripts_groom_evaluated": "_evaluated()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L124 | neighbors=[groom.py, build_cards(), curve_stats()]
- "scripts_groom_render_atlas": "render_atlas()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L210 | neighbors=[groom.py, Flat strand clumps (one per column) ren…, run()]
- "scripts_groom_spaced": "_spaced()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L150 | neighbors=[groom.py, build_cards(), Farthest-point sampling: k well-spread …]
- "scripts_helper_connect": "connect()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L77 | neighbors=[helper.js, setStatus(), websocketUrl()]
- "scripts_helper_sessionkey": "sessionKey()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L25 | neighbors=[helper.js, reloadAfterRecovery(), websocketUrl()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-075.json

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
