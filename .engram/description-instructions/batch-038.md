# Node Description Batch 39 of 208

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

- "scripts_convert_pb_to_json": "convert_pb_to_json.py" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, convert_pb_to_json(), main(), Converts R8 keep radius protobuf files …]
- "scripts_env_report": "env_report.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _gpu(), run(), Report Blender version, engines, GPU, a…]
- "scripts_gn_builder_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L178 | neighbors=[gn_builder.py, apply(), build(), describe(), _parse_val()]
- "scripts_groom_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L294 | neighbors=[groom.py, build_cards(), card_material(), groom(), render_atlas()]
- "scripts_kit_check_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L68 | neighbors=[kit_check.py, _fix(), _on_grid(), _pivot_target(), _texel_density()]
- "scripts_lightning_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L85 | neighbors=[lightning.py, _bolt_points(), _clear(), _curve(), _envelope()]
- "scripts_loop_check_check": "_check()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L51 | neighbors=[loop_check.py, _diff(), _poses(), _w(), run()]
- "scripts_make_lods": "make_lods.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/make_lods.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, cleanup(), run(), Generate an LOD chain (<name>_LOD1..N) …]
- "scripts_mesh_stats": "mesh_stats.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/mesh_stats.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, run(), _vram(), Budget report: tris/verts per object, m…]
- "scripts_orchestrator_load_gradle_properties": "load_gradle_properties()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L157 | neighbors=[orchestrator.py, _candidate_project_roots(), _strip_inline_comment(), main(), Loads properties from gradle.properties…]
- "scripts_orchestrator_load_version_catalog": "load_version_catalog()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L180 | neighbors=[orchestrator.py, _candidate_project_roots(), _strip_inline_comment(), main(), Loads versions from gradle/libs.version…]
- "scripts_orchestrator_strip_inline_comment": "_strip_inline_comment()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L129 | neighbors=[orchestrator.py, load_app_plugin_aliases(), load_gradle_properties(), load_version_catalog(), Strips inline comments starting with '#…]
- "scripts_play_store_scraper_scrape_app_details": "scrape_app_details()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L384 | neighbors=[play_store_scraper.py, Scrapes app metadata and Data Safety in…, extract_data_safety(), extract_metadata(), fetch_html()]
- "scripts_pro_lib_out_g": ".g()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L368 | neighbors=[Out, .add(), hexrgb(), MB, .gadd()]
- "scripts_pro_lib_sh_call": ".__call__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L72 | neighbors=[Sh, clamp(), lerp(), nz(), .u()]
- "scripts_retarget_parts": "_parts()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L56 | neighbors=[retarget.py, auto_map(), _split(), {(part, side): bone}, plus the spine ch…, run()]
- "scripts_review_shots": "review_shots.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/review_shots.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bounds(), run(), Render a multi-angle review contact she…]
- "scripts_rig_check": "rig_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rig_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _mirror(), run(), Validate a skeleton + its skinned meshe…]
- "scripts_roblox_export_big_part": "big_part()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L302 | neighbors=[roblox_export.py, clean_name(), palette_rgb(), r_pos(), low-poly oversize mesh (sea plane, skir…]
- "scripts_roblox_export_material_split": "material_split()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L164 | neighbors=[roblox_export.py, export(), _face_rgb(), newobj(), materials mode: split every palette (so…]
- "scripts_roblox_materials_preview": "preview()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L76 | neighbors=[roblox_materials.py, column_of(), resolve(), _variant(), give every palette mesh one Blender mat…]
- "scripts_run_in_blender": "run_in_blender.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/run_in_blender.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, find_blender(), main(), _ver()]
- "scripts_scanner_identify_semantic_files": "_identify_semantic_files()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L158 | neighbors=[scanner.py, get_scanner_config(), get_supported_extensions(), perform_scan(), Maps files to semantic categories based…]
- "scripts_scene_audit": "scene_audit.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-scene-setup/scripts/scene_audit.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_rot_scale(), run(), Audit scene hygiene: units, transforms,…]
- "scripts_studlib_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L55 | neighbors=[studlib.py, lin(), limb(), span(), spike()]
- "scripts_studlib_emit": "_emit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L88 | neighbors=[studlib.py, cyl(), lin(), add a custom solid (local unit coords) …, wedge()]
- "scripts_studlib_span": "span()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L129 | neighbors=[studlib.py, Box by ranges: easy to make neighbours …, box(), stack(), sym()]
- "scripts_surface_weather_g_noise": ".noise()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L70 | neighbors=[build_group(), _G, .n(), _snow_tree(), _vertex_mask()]
- "scripts_template_engine_get_nested_val": "get_nested_val()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L27 | neighbors=[template_engine.py, .render(), .render(), Resolves nested dot-notation keys from …, .render()]
- "scripts_toon_setup_g_link": ".link()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L39 | neighbors=[build_group(), _G, .set(), _key_light(), _line_art()]
- "semantic_emit_mk": "mk()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L19 | neighbors=[emit.cpp, br16(), br32(), emit_bytecode(), mov()]
- "semantic_fold_fold_constants": "fold_constants()" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L57 | neighbors=[fold.cpp, eval_binary(), eval_compare(), eval_unary(), int_scalar()]
- "semantic_lower_lower_module": "lower_module()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L534 | neighbors=[lower.cpp, convert_type(), lower_function_ex(), requires_mask(), unit_t()]
- "skyrise_sky_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L110 | neighbors=[sky_map.py, build(), spawn_island(), summit(), zone_island()]
- "skyrise_sky_map_hm": "Hm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L85 | neighbors=[sky_map.py, H(), place(), height of the built island top MESH (wh…, spread()]
- "skyrise_sky_map_path_track": "path_track()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L315 | neighbors=[sky_map.py, build(), H(), sub(), trodden track under the stepping stones…]
- "skyrise_sky_map_sky_dressing": "sky_dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L367 | neighbors=[sky_map.py, build(), island_at(), on_bridge_line(), place()]
- "skyrise_sky_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L18 | neighbors=[sky_map.py, island_mesh(), path_track(), paving(), place()]
- "skyrise_sky_models2_coin": "coin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L8 | neighbors=[sky_models2.py, chest(), coin_pile(), coin with a raised rim (lathe), lying f…, sell_pad()]
- "skyrise_sky_props_egg_shrine": "egg_shrine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L226 | neighbors=[sky_props.py, gem(), lathe(), torus(), egg hatch station: tiered round podium,…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-038.json

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
