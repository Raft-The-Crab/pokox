# Node Description Batch 80 of 209

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
- "scripts_helper_websocketurl": "websocketUrl()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L32 | neighbors=[helper.js, connect(), sessionKey()]
- "scripts_keep_radius_pb2": "keep_radius_pb2.py" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/keep_radius_pb2.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Generated protocol buffer code for keep…]
- "scripts_kit_check_pivot_target": "_pivot_target()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L30 | neighbors=[kit_check.py, _fix(), run()]
- "scripts_kit_sheet_template": "kit_sheet_template.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/kit_sheet_template.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "scripts_lightning_bolt_points": "_bolt_points()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L38 | neighbors=[lightning.py, Midpoint displacement between top and b…, run()]
- "scripts_lightning_envelope": "_envelope()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L69 | neighbors=[lightning.py, {frame: intensity 0..1}. Each stroke: p…, run()]
- "scripts_loop_check_w": "_w()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L43 | neighbors=[loop_check.py, _check(), Signed angular velocity a -> b (deg, as…]
- "scripts_make_lods_cleanup": "cleanup()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/make_lods.py:L20 | neighbors=[make_lods.py, Merge by distance, dissolve degenerate,…, run()]
- "scripts_orchestrator_build_app_plugin_alias_pattern": "_build_app_plugin_alias_pattern()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L274 | neighbors=[orchestrator.py, parse_application_modules(), Builds a regex matching `alias(...)` fo…]
- "scripts_orchestrator_filter_by_flavor": "_filter_by_flavor()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L398 | neighbors=[orchestrator.py, main(), Recursively filters lists and dicts bas…]
- "scripts_orchestrator_generate_triage_summary": "generate_triage_summary()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L808 | neighbors=[orchestrator.py, main(), Generates a high-level summary of the a…]
- "scripts_orchestrator_load_json_file": "_load_json_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L358 | neighbors=[orchestrator.py, Safely loads a JSON file., write_agent_prompts()]
- "scripts_orchestrator_msbuild_property": "_msbuild_property()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L645 | neighbors=[orchestrator.py, extract_dotnet_android_details(), Reads a single MSBuild property value o…]
- "scripts_orchestrator_read_text_file": "_read_text_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L369 | neighbors=[orchestrator.py, Safely reads a text file., write_agent_prompts()]
- "scripts_orchestrator_run_aggregation": "run_aggregation()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1000 | neighbors=[orchestrator.py, main(), Aggregates and chunks findings for the …]
- "scripts_orchestrator_run_scanner_direct": "run_scanner_direct()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L831 | neighbors=[orchestrator.py, Invokes the scanner directly using the …, _write_json_file()]
- "scripts_play_store_scraper_fetch_html": "fetch_html()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L28 | neighbors=[play_store_scraper.py, Fetches HTML content from a URL with a …, scrape_app_details()]
- "scripts_post_main": "main()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L16 | neighbors=[post.py, ffmpeg(), outline()]
- "scripts_precipitation_camera_box": "_camera_box()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L251 | neighbors=[precipitation.py, World AABB of the camera's near frustum…, run()]
- "scripts_precipitation_t_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L53 | neighbors=[build_tree(), _T, .sock()]
- "scripts_precipitation_t_out": ".out()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L65 | neighbors=[build_tree(), _T, .sock()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-079.json

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
