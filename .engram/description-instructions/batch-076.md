# Node Description Batch 77 of 207

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
- "scripts_precipitation_t_sock": ".sock()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L45 | neighbors=[_T, .n(), .out()]
- "scripts_pro_lib_clamp": "clamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L26 | neighbors=[pro_lib.py, .__call__(), smooth()]
- "scripts_pro_lib_clip_half": "clip_half()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L319 | neighbors=[pro_lib.py, keep the side of the bisector of s-o cl…, voronoi_cells()]
- "scripts_pro_lib_clip_rect": "clip_rect()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L332 | neighbors=[pro_lib.py, clip_fn(), voronoi_cells()]
- "scripts_pro_lib_frames": "frames()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L208 | neighbors=[pro_lib.py, parallel-transport frames along a polyl…, tube()]
- "scripts_pro_lib_hexrgb": "hexrgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L23 | neighbors=[pro_lib.py, .g(), .image()]
- "scripts_pro_lib_make_obj": "make_obj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L415 | neighbors=[pro_lib.py, .build(), mesh in Blender space, origin = bbox ce…]
- "scripts_pro_lib_palette_image": ".image()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L43 | neighbors=[Palette, hexrgb(), .material()]
- "scripts_pro_lib_palette_material": ".material()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L56 | neighbors=[.build(), Palette, .image()]
- "scripts_pro_lib_palette_u": ".u()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L42 | neighbors=[.gadd(), Palette, .__call__()]
- "scripts_pro_lib_render": "render()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L469 | neighbors=[pro_lib.py, loc / tgt in Roblox space, r2b()]
- "scripts_pro_lib_rock": "rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L158 | neighbors=[pro_lib.py, hull(), rock_pts()]
- "scripts_pro_lib_rock_pts": "rock_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L141 | neighbors=[pro_lib.py, points on a lumpy ellipsoid (radii r = …, rock()]
- "scripts_pro_lib_split": "split()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L390 | neighbors=[pro_lib.py, .build(), MB]
- "scripts_pro_lib_tube": "tube()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L222 | neighbors=[pro_lib.py, swept polygon along pts; radii scalar o…, frames()]
- "scripts_qa_check_feeds": "_feeds()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L42 | neighbors=[qa_check.py, _material_issues(), (node type, input name) pairs a socket …]
- "scripts_qa_check_mesh_world": "_mesh_world()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L93 | neighbors=[qa_check.py, bmesh of the (evaluated) object in worl…, run()]
- "scripts_render_batch_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L69 | neighbors=[render_batch.py, _frames(), _gpu()]
- "scripts_render_plan": "render_plan.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/render_plan.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arg()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-076.json

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
