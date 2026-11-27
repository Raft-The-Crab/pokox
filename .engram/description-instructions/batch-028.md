# Node Description Batch 29 of 207

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

- "plusspeed_plus_props_v4_plinth": "plinth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L59 | neighbors=[plus_props_v4.py, egg_hatchery(), pixel_art(), podium_board(), rebirth_portal(), sneaker_shop()]
- "plusspeed_plus_props_v4_raster": "raster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L38 | neighbors=[plus_props_v4.py, egg_rows(), medal_rows(), portal_rows(), fn(x, y) -> char, x/y in -1..1 (y up); …, stopwatch_rows()]
- "program_program_fail": "fail()" | kind=code-symbol | source=mute/src/program/program.cpp:L20 | neighbors=[program.cpp, Depth(), prepare_globals(), run_program_reference(), run_stateful_program(), run_stateful_program_bytecode()]
- "refmatch_compare_subject_mask": "subject_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L146 | neighbors=[compare.py, mask_at_native(), Foreground mask.      Prefers an exact …, background_fit_mask(), flood_background_mask(), significant_components()]
- "refmatch_overlay": "overlay.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), _overlay(), _panel(), Side-by-side diagnostic sheet.  Metrics…]
- "refmatch_palette_report_compare_to_render": "compare_to_render()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L122 | neighbors=[palette_report.py, delta_e(), extract(), hex_to_rgb(), main(), For each named palette role, find the n…]
- "refmatch_palette_report_extract": "extract()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L74 | neighbors=[palette_report.py, compare_to_render(), hex_of(), kmeans(), subject_pixels(), main()]
- "scripts_auto_retopo": "auto_retopo.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_all(), _ctx(), run(), Make a low-poly retopo copy of a dense …]
- "scripts_bake_maps_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L139 | neighbors=[bake_maps.py, _curvature_from_normal(), _restore(), _set_device(), _signal_override(), _target_node()]
- "scripts_compare": "compare.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bbox(), concept_mask(), main(), Overlay a render's silhouette on a conc…]
- "scripts_export_asset_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L118 | neighbors=[export_asset.py, _animated(), _coerce(), _export(), _gather(), glb_summary()]
- "scripts_generate_report_render_finding_card": "render_finding_card()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L175 | neighbors=[generate_report.py, main(), Renders a detailed finding card in Mark…, clean_severity(), format_code_link(), strip_emojis()]
- "scripts_groom_groom": "groom()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L76 | neighbors=[groom.py, _assets(), curve_stats(), hair_material(), _modifier(), run()]
- "scripts_orchestrator_candidate_project_roots": "_candidate_project_roots()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L145 | neighbors=[orchestrator.py, load_app_plugin_aliases(), load_custom_gradle_versions(), load_gradle_properties(), load_version_catalog(), Returns target_dir and its parent direc…]
- "scripts_orchestrator_determine_primary_identity": "determine_primary_identity()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L530 | neighbors=[orchestrator.py, extract_dotnet_android_details(), extract_manifest_details(), _resolve_to_int(), main(), Heuristically determines the primary ap…]
- "scripts_orchestrator_load_app_plugin_aliases": "load_app_plugin_aliases()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L226 | neighbors=[orchestrator.py, _candidate_project_roots(), _strip_inline_comment(), main(), parse_application_modules(), Returns version-catalog plugin aliases …]
- "scripts_orchestrator_parse_application_modules": "parse_application_modules()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L431 | neighbors=[orchestrator.py, main(), _build_app_plugin_alias_pattern(), load_app_plugin_aliases(), _resolve_to_int(), Identifies distinct application modules…]
- "scripts_orchestrator_write_agent_prompts": "write_agent_prompts()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L843 | neighbors=[orchestrator.py, main(), Generates surgical prompt files for wor…, _load_json_file(), _read_text_file(), _write_json_file()]
- "scripts_post": "post.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, ffmpeg(), main(), outline(), Post-process renders from studlib.py: b…]
- "scripts_render_batch": "render_batch.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _frames(), _gpu(), run(), Render stills/animations with quality p…]
- "scripts_rigify_build_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L148 | neighbors=[rigify_build.py, _ensure_rigify(), _fit(), game_skeleton(), _generate(), _remove_face()]
- "scripts_scanner_get_scanner_config": "get_scanner_config()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L36 | neighbors=[scanner.py, collect_target_files(), get_supported_extensions(), _identify_semantic_files(), perform_scan(), Loads the scanner configuration from sc…]
- "scripts_scanner_get_supported_extensions": "get_supported_extensions()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L55 | neighbors=[scanner.py, collect_target_files(), get_scanner_config(), _identify_semantic_files(), Returns a tuple of supported file exten…, _scan_single_file()]
- "scripts_sculpt_ops": "sculpt_ops.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-sculpting/scripts/sculpt_ops.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply(), _ctx(), run(), Headless-safe sculpt preparation and pr…]
- "scripts_sim_setup_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L82 | neighbors=[sim_setup.py, _asset_group(), _ctx(), _num(), _set_inputs(), _volume()]
- "scripts_smart_material_g_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L51 | neighbors=[build_group(), _G, .math(), .mix(), .mrange(), .noise()]
- "scripts_smart_material_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L275 | neighbors=[smart_material.py, _apply_mat(), build_group(), curvature_attribute(), _lin(), _remove_mat()]
- "scripts_template_engine_ifnode": "IfNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L72 | neighbors=[template_engine.py, compile_template(), .__init__(), .render(), Node, Represents conditional block logic (IF,…]
- "scripts_template_engine_textnode": "TextNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L46 | neighbors=[template_engine.py, compile_template(), Represents raw static text blocks., Node, .__init__(), .render()]
- "scripts_template_engine_varnode": "VarNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L56 | neighbors=[template_engine.py, compile_template(), Represents dynamic variable interpolati…, Node, .__init__(), .render()]
- "scripts_toon_setup_g_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L48 | neighbors=[build_group(), _G, .math(), .mix(), .step(), .vmath()]
- "scripts_track_camera": "track_camera.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _clip_area(), run(), _solve(), Automatic camera solve from footage: de…]
- "scripts_turntable_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L83 | neighbors=[turntable.py, _area(), _backdrop(), _bounds(), _clear(), _fcurves()]
- "scripts_uv_pack": "uv_pack.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _collapsed_ratio(), run(), _seams_from_sharp(), Unwrap + pack UVs with production defau…]
- "semantic_fold": "fold.cpp" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…, eval_binary(), eval_compare(), eval_unary(), fold_constants(), int_scalar()]
- "skyrise_sky_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L111 | neighbors=[sky_map.py, look(), micro_detail(), rim_dress(), spawn_island(), zone_island()]
- "skyrise_sky_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L44 | neighbors=[sky_map.py, bridge_ends(), island_at(), Hm(), island_mesh(), path_track()]
- "skyrise_sky_map_island_mesh": "island_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L128 | neighbors=[sky_map.py, build(), H(), place(), rim(), sub()]
- "skyrise_sky_map_winding_path": "winding_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L181 | neighbors=[sky_map.py, stepping-stone path from the entry brid…, island_at(), place(), reserve(), zone_island()]
- "skyrise_sky_props_trophy": "trophy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L466 | neighbors=[sky_props.py, HERO: giant golden trophy on a tiered m…, gem(), lathe(), sphere(), torus()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-028.json

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
