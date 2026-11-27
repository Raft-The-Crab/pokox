# Node Description Batch 22 of 208

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

- "oaktrees_gen_trees_branch_at": ".at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L336 | neighbors=[Branch, card_quads(), conifer_cards(), .build(), .build_conifer(), .children_of()]
- "oaktrees_gen_trees_tree_build": ".build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L411 | neighbors=[make_tree(), Tree, .at(), .build_conifer(), .children_of(), .grow()]
- "oaktrees_gen_trees_tree_grow": ".grow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L365 | neighbors=[Tree, .build(), .build_conifer(), .children_of(), Branch, rand_unit()]
- "onsenvillage_onsen_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L60 | neighbors=[onsen_map.py, bank_path(), mountains(), terrace_at(), nature(), one height function for ground mesh AND…]
- "onsenvillage_onsen_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L443 | neighbors=[onsen_map.py, build(), free(), H(), mountains(), place()]
- "onsenvillage_onsen_props_shopfront": "shopfront()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L282 | neighbors=[onsen_props.py, house(), open market front: back + side walls, a…, frame_storey(), holed_wall(), paper_lantern()]
- "petsim_pet_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L197 | neighbors=[pet_map.py, build(), path_meshes(), plaza(), sea(), link()]
- "petsim_pet_props_bridge": "bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L627 | neighbors=[pet_props.py, ell(), rbox(), rcyl(), soft(), vsh()]
- "petsim_pet_props_bubble_crown": "bubble_crown()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L729 | neighbors=[pet_props.py, ell(), soft(), cotton_tree(), crystal_tree(), puff_tree()]
- "petsim_pet_props_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L534 | neighbors=[pet_props.py, ell(), flat(), rbox(), rcyl(), soft()]
- "petsim_pet_props_pet_fountain": "pet_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L271 | neighbors=[pet_props.py, ell(), flat(), rcyl(), soft(), vsh()]
- "petsim_pet_props_star_lamp": "star_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L982 | neighbors=[pet_props.py, lilac curled post (a hook at the top) h…, ell(), flat(), pill(), soft()]
- "plusspeed_plus_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L21 | neighbors=[plus_map.py, dress_caps(), finish(), hub(), grp(), sky()]
- "plusspeed_plus_map_walls": "walls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L39 | neighbors=[plus_map.py, finish(), hub(), stepped canyon: tier n is a row of 24-w…, blk(), kerb_z()]
- "plusspeed_plus_props_v3_chamfer_block": "chamfer_block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L9 | neighbors=[plus_props_v3.py, hatchery(), lamp_pillar(), block whose top edges are chamfered wit…, rebirth_altar(), shop_stall()]
- "program_program_prepare_globals": "prepare_globals()" | kind=code-symbol | source=mute/src/program/program.cpp:L297 | neighbors=[program.cpp, compile_program_bytecode(), inspect_program_state_schema(), fail(), run_program_reference(), run_stateful_program()]
- "refmatch_measure_sheet_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L120 | neighbors=[measure_sheet.py, auto_front(), load(), palette(), save_crop(), subject_mask()]
- "scripts_analyze": "analyze.py" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyze(), describe_rule(), main(), rule_origin()]
- "scripts_bind_mesh_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L88 | neighbors=[bind_mesh.py, cleanup(), _heat_scale(), _height(), _parent(), _proxy_weights()]
- "scripts_decal": "decal.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _gaps(), _grid(), _material(), run()]
- "scripts_generate_report_aggregate_findings": "aggregate_findings()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L249 | neighbors=[generate_report.py, clean_severity(), load_json(), parse_boolean(), parse_disclosure_status(), main()]
- "scripts_play_store_scraper_playstoredatasafetyparser": "PlayStoreDataSafetyParser" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L139 | neighbors=[play_store_scraper.py, extract_data_safety(), .handle_data(), .handle_endtag(), .handle_starttag(), .__init__()]
- "scripts_play_store_scraper_playstoremetadataparser": "PlayStoreMetadataParser" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L57 | neighbors=[play_store_scraper.py, extract_metadata(), .handle_data(), .handle_endtag(), .handle_starttag(), .__init__()]
- "scripts_pro_lib_out": "Out" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L363 | neighbors=[pro_lib.py, .add(), .build(), .g(), .gadd(), .__init__()]
- "scripts_qa_check_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L178 | neighbors=[qa_check.py, _islands(), _material_issues(), _mesh_world(), _point_in_tri(), _result()]
- "scripts_scene_mood_world": "_world()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L174 | neighbors=[scene_mood.py, Build ENV_World. Returns horizontal amb…, run(), _lerp_table(), lum(), _math()]
- "scripts_shapekeys": "shapekeys.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _co(), _get(), _keys(), run()]
- "scripts_stress_poses": "stress_poses.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _find(), _rotate(), run(), _side()]
- "scripts_surface_weather_g_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L44 | neighbors=[build_group(), _G, .math(), .mix(), .mrange(), .noise()]
- "scripts_surface_weather_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L317 | neighbors=[surface_weather.py, _apply_mat(), build_group(), _remove_mat(), _snow_material(), _snow_tree()]
- "scripts_surface_weather_snow_tree": "_snow_tree()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L246 | neighbors=[surface_weather.py, run(), _G, .link(), .math(), .n()]
- "scripts_template_engine_eachnode": "EachNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L114 | neighbors=[template_engine.py, compile_template(), .__init__(), .render(), ._render_children(), Node]
- "scripts_template_engine_node": "Node" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L39 | neighbors=[template_engine.py, EachNode, IfNode, .render(), Base class for all Abstract Syntax Tree…, TextNode]
- "scripts_terrain_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L157 | neighbors=[terrain.py, _erode(), _heightmap(), _material(), _noise_field(), _save_png16()]
- "scripts_texel_density": "texel_density.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _islands(), _measure(), run(), _uv_area()]
- "scripts_vse_edit": "vse_edit.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _add_clip(), _frames(), _output(), run()]
- "semantic_emit_emit_bytecode": "emit_bytecode()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L36 | neighbors=[emit.cpp, alu(), br16(), br32(), is_terminator_pub(), mk()]
- "semantic_optimize": "optimize.cpp" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L1 | neighbors=[0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, e499073 Add MUT-29 dead-code eliminatio…, eliminate_dead_code(), is_pure(), is_terminator()]
- "skyrise_sky_map_on_bridge_line": "on_bridge_line()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L121 | neighbors=[sky_map.py, micro_detail(), segd(), rim_dress(), sky_dressing(), summit()]
- "skyrise_sky_map_rim": "rim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L33 | neighbors=[sky_map.py, bridge_ends(), island_at(), island_mesh(), micro_detail(), rim_dress()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-021.json

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
