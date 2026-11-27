# Node Description Batch 56 of 209

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

- "scripts_orchestrator_extract_dotnet_android_details": "extract_dotnet_android_details()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L653 | neighbors=[orchestrator.py, determine_primary_identity(), _msbuild_property(), Finds the .NET MAUI / .NET for Android …]
- "scripts_orchestrator_extract_manifest_details": "extract_manifest_details()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L716 | neighbors=[orchestrator.py, determine_primary_identity(), main(), Parses AndroidManifest.xml for key poli…]
- "scripts_orchestrator_load_custom_gradle_versions": "load_custom_gradle_versions()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L286 | neighbors=[orchestrator.py, _candidate_project_roots(), main(), Loads versions from shared Gradle files…]
- "scripts_orchestrator_resolve_to_int": "_resolve_to_int()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1101 | neighbors=[orchestrator.py, determine_primary_identity(), parse_application_modules(), Recursively resolves a variable name to…]
- "scripts_orchestrator_write_json_file": "_write_json_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L380 | neighbors=[orchestrator.py, Safely writes a JSON file., run_scanner_direct(), write_agent_prompts()]
- "scripts_play_store_scraper_extract_data_safety": "extract_data_safety()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L243 | neighbors=[play_store_scraper.py, PlayStoreDataSafetyParser, Extracts Data Safety information struct…, scrape_app_details()]
- "scripts_play_store_scraper_extract_metadata": "extract_metadata()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L188 | neighbors=[play_store_scraper.py, PlayStoreMetadataParser, Extracts all metadata into a clean dict…, scrape_app_details()]
- "scripts_post_glow": "post_glow.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post_glow.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, fx(), Preview post: single black silhouette o…]
- "scripts_precipitation_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L273 | neighbors=[precipitation.py, build_tree(), _camera_box(), _material()]
- "scripts_pro_lib_bevel": "bevel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L121 | neighbors=[pro_lib.py, box(), cyl(), ngon_prism()]
- "scripts_pro_lib_cyl": "cyl()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L177 | neighbors=[pro_lib.py, bevel(), ngon_prism(), vertical prism / frustum from y0 to y0 …]
- "scripts_pro_lib_ngon_prism": "ngon_prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L161 | neighbors=[pro_lib.py, cyl(), bevel(), poly = [(x, z), ...] counter-clockwise …]
- "scripts_pro_lib_out_build": ".build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L380 | neighbors=[Out, make_obj(), .material(), split()]
- "scripts_pro_lib_out_gadd": ".gadd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L375 | neighbors=[Out, .g(), .u(), a glow piece: uv on the white strip]
- "scripts_pro_lib_voronoi_cells": "voronoi_cells()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L296 | neighbors=[pro_lib.py, jittered-grid Voronoi cells clipped to …, clip_half(), clip_rect()]
- "scripts_prop_studio": "prop_studio.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/prop_studio.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arg(), setup()]
- "scripts_qa_check_material_issues": "_material_issues()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L54 | neighbors=[qa_check.py, _feeds(), [(severity_is_error, message)] for slot…, run()]
- "scripts_retarget_auto_map": "auto_map()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L71 | neighbors=[retarget.py, _parts(), _split(), run()]
- "scripts_retarget_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L90 | neighbors=[retarget.py, auto_map(), _parts(), _rot()]
- "scripts_retarget_split": "_split()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L41 | neighbors=[retarget.py, auto_map(), _parts(), mixamorig:LeftUpLeg' -> ('upleg', 'L');…]
- "scripts_roblox_export_r_pos": "r_pos()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L116 | neighbors=[roblox_export.py, at(), big_part(), look()]
- "scripts_roblox_materials_resolve": "resolve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L67 | neighbors=[roblox_materials.py, preview(), material for palette ramp `col` on obje…, mat_for()]
- "scripts_scanner_collect_target_files": "collect_target_files()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L60 | neighbors=[scanner.py, get_scanner_config(), get_supported_extensions(), Performs a single master walk to catego…]
- "scripts_scanner_perform_scan": "perform_scan()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L228 | neighbors=[scanner.py, get_scanner_config(), _identify_semantic_files(), Orchestrates the parallel scanning of i…]
- "scripts_scatter_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L146 | neighbors=[scatter.py, build_tree(), _instances(), _layer_coll()]
- "scripts_scene_mood_fog": "_fog()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L260 | neighbors=[scene_mood.py, _math(), Box volume around scene + camera. Densi…, run()]
- "scripts_shapekeys_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L58 | neighbors=[shapekeys.py, _co(), _get(), _keys()]
- "scripts_smart_material_apply_mat": "_apply_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L222 | neighbors=[smart_material.py, _image_node(), _src(), run()]
- "scripts_studlib_limb": "limb()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L147 | neighbors=[studlib.py, box(), frame(), Box from point a to point c (w x d cros…]
- "scripts_studlib_wedge": "wedge()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L99 | neighbors=[studlib.py, ramp(), Ramp (Roblox WedgePart): full height at…, _emit()]
- "scripts_surface_weather_g_link": ".link()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L35 | neighbors=[build_group(), _G, .set(), _snow_tree()]
- "scripts_surface_weather_g_math": ".math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L50 | neighbors=[build_group(), _G, .n(), _snow_tree()]
- "scripts_surface_weather_vertex_mask": "_vertex_mask()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L298 | neighbors=[surface_weather.py, Color attribute ENV_Weather (R puddle, …, run(), .noise()]
- "scripts_template_engine_parserframe": "_ParserFrame" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L153 | neighbors=[template_engine.py, compile_template(), .__init__(), Helper class representing an active sta…]
- "scripts_texel_density_measure": "_measure()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L52 | neighbors=[texel_density.py, _islands(), _uv_area(), run()]
- "scripts_toon_setup_g_math": ".math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L54 | neighbors=[build_group(), _G, .n(), .step()]
- "scripts_toon_setup_g_step": ".step()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L66 | neighbors=[build_group(), _G, .math(), .n()]
- "scripts_toon_setup_lin": "_lin()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L31 | neighbors=[toon_setup.py, _line_art(), _outline_material(), run()]
- "scripts_toon_setup_line_art": "_line_art()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L261 | neighbors=[toon_setup.py, .link(), _lin(), run()]
- "scripts_verify_desktop_main": "main()" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L61 | neighbors=[verify_desktop.py, classify(), parse_runtime(), run_step()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-055.json

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
