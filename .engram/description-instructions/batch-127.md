# Node Description Batch 128 of 209

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

- "scripts_contact_sheet": "contact_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/contact_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "scripts_decal_grid": "_grid()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L63 | neighbors=[decal.py, run()]
- "scripts_decal_material": "_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L24 | neighbors=[decal.py, run()]
- "scripts_env_report_gpu": "_gpu()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L17 | neighbors=[env_report.py, run()]
- "scripts_env_report_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L27 | neighbors=[env_report.py, _gpu()]
- "scripts_export_asset_coerce": "_coerce()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L101 | neighbors=[export_asset.py, run()]
- "scripts_export_asset_export": "_export()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L93 | neighbors=[export_asset.py, run()]
- "scripts_export_asset_gather": "_gather()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L79 | neighbors=[export_asset.py, run()]
- "scripts_garment_region": "_region()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L29 | neighbors=[garment.py, run()]
- "scripts_garment_transfer_weights": "_transfer_weights()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L65 | neighbors=[garment.py, run()]
- "scripts_gn_builder_apply": "apply()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L152 | neighbors=[gn_builder.py, run()]
- "scripts_gn_builder_parse_val": "_parse_val()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L167 | neighbors=[gn_builder.py, run()]
- "scripts_gn_builder_sock": "_sock()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L67 | neighbors=[gn_builder.py, build()]
- "scripts_groom_assets": "_assets()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L35 | neighbors=[groom.py, groom()]
- "scripts_groom_card_material": "card_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L279 | neighbors=[groom.py, run()]
- "scripts_groom_hair_material": "hair_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L61 | neighbors=[groom.py, groom()]
- "scripts_groom_modifier": "_modifier()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L44 | neighbors=[groom.py, groom()]
- "scripts_helper_reloadafterrecovery": "reloadAfterRecovery()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L37 | neighbors=[helper.js, sessionKey()]
- "scripts_helper_setstatus": "setStatus()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L47 | neighbors=[helper.js, connect()]
- "scripts_kit_check_on_grid": "_on_grid()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L26 | neighbors=[kit_check.py, run()]
- "scripts_kit_check_texel_density": "_texel_density()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L37 | neighbors=[kit_check.py, run()]
- "scripts_lightning_clear": "_clear()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L25 | neighbors=[lightning.py, run()]
- "scripts_lightning_curve": "_curve()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L51 | neighbors=[lightning.py, run()]
- "scripts_loop_check_diff": "_diff()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L38 | neighbors=[loop_check.py, _check()]
- "scripts_loop_check_poses": "_poses()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L24 | neighbors=[loop_check.py, _check()]
- "scripts_loop_check_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L77 | neighbors=[loop_check.py, _check()]
- "scripts_make_lods_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/make_lods.py:L34 | neighbors=[make_lods.py, cleanup()]
- "scripts_mesh_stats_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/mesh_stats.py:L32 | neighbors=[mesh_stats.py, _vram()]
- "scripts_mesh_stats_vram": "_vram()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/mesh_stats.py:L26 | neighbors=[mesh_stats.py, run()]
- "scripts_orchestrator_write_text_file": "_write_text_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L389 | neighbors=[orchestrator.py, Safely writes a text file.]
- "scripts_play_store_scraper_load_taxonomy": "load_taxonomy()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L163 | neighbors=[play_store_scraper.py, Loads the valid data safety taxonomy fr…]
- "scripts_post_ffmpeg": "ffmpeg()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L49 | neighbors=[post.py, main()]
- "scripts_post_outline": "outline()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L8 | neighbors=[post.py, main()]
- "scripts_precipitation_iface": "_iface()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L93 | neighbors=[precipitation.py, build_tree()]
- "scripts_precipitation_material": "_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L233 | neighbors=[precipitation.py, run()]
- "scripts_precipitation_t_math": ".math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L68 | neighbors=[build_tree(), _T]
- "scripts_precipitation_t_vmath": ".vmath()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L80 | neighbors=[build_tree(), _T]
- "scripts_pro_lib_box": "box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L127 | neighbors=[pro_lib.py, bevel()]
- "scripts_pro_lib_clip_fn": "clip_fn()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L344 | neighbors=[pro_lib.py, clip_rect()]
- "scripts_pro_lib_grid": "grid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L265 | neighbors=[pro_lib.py, heightfield quad grid (Roblox space): y…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-127.json

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
