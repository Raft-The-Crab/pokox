# Node Description Batch 17 of 209

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

- "moonclean_moon_props_reentry_pod": "reentry_pod()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L243 | neighbors=[moon_props.py, REBIRTH: scorched capsule on its heat s…, beam(), lathe(), port(), ShAng]
- "onsenvillage_onsen_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L121 | neighbors=[onsen_map.py, bank_path(), ground(), horizon(), add_owner(), sub()]
- "onsenvillage_onsen_props_giboshi": "giboshi()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L168 | neighbors=[onsen_props.py, balcony(), footbridge(), pagoda(), paper_lantern_post(), rail_post()]
- "onsenvillage_onsen_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L43 | neighbors=[onsen_props.py, balcony(), bucket(), cedar(), cloud_tree(), crag()]
- "onsenvillage_onsen_props_pagoda": "pagoda()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L314 | neighbors=[onsen_props.py, flared_roof(), giboshi(), paper_lantern(), plinth(), skirt_roof()]
- "onsenvillage_onsen_props_paper_lantern": "paper_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L244 | neighbors=[onsen_props.py, bath_pavilion(), house(), noodle_stall(), pagoda(), paper_lantern_post()]
- "onsenvillage_onsen_props_storey_walls": "storey_walls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L223 | neighbors=[onsen_props.py, house(), pagoda(), four plaster walls of one storey with c…, doorway(), frame_storey()]
- "package_package": "package.cpp" | kind=code-symbol | source=mute/src/package/package.cpp:L1 | neighbors=[5edd00c Fix MUT-21/22 audit defects in …, c7e951a Add MUT-21 package, import and …, dump_lockfile(), inner_position(), name(), parse_import_spec()]
- "petsim_pet_map_path_d": "path_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L219 | neighbors=[pet_map.py, breakables(), candy(), crystal(), hub(), meadow()]
- "petsim_pet_props_egg": "egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L154 | neighbors=[pet_props.py, egg_prof(), ell(), lift(), soft(), star_poly()]
- "petsim_pet_props_pill": "pill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L100 | neighbors=[pet_props.py, giant_donut(), pet_shop(), puffpaw(), capsule from a to b (rounded ends), star_lamp()]
- "physics_character_controller": "character_controller.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/character_controller.hpp:L1 | neighbors=[038387e Character controller: value-key…, 0be87b9 Merge pull request #4 from Raft…, 2680d0e Pushed an update., 2be6ccd Character controller: fix missi…, 69287a0 Land ENG-60-65 deterministic si…, 81d94fb Merge pull request #5 from Raft…]
- "plusspeed_plus_map_hub": "hub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L99 | neighbors=[plus_map.py, blk(), dress_caps(), kerb_x(), oval_track(), place()]
- "plusspeed_plus_props_v3_cyl_v": "cyl_v()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L26 | neighbors=[plus_props_v3.py, barrel(), hatchery(), lamp_pillar(), potion(), rebirth_altar()]
- "plusspeed_plus_props_v3_hatchery": "hatchery()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L159 | neighbors=[plus_props_v3.py, bulbs_frame(), chamfer_block(), cyl_v(), framed_panel(), octo()]
- "scripts_bake_action": "bake_action.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _assign(), list_actions(), _mute(), _root_motion()]
- "scripts_batch_process": "batch_process.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, gather(), inventory(), load(), _module()]
- "scripts_build_pbr_material": "build_pbr_material.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, classify(), _find_textures(), _gltf_output_group(), run()]
- "scripts_garment_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L201 | neighbors=[garment.py, _drape(), _hide_body(), penetration(), _region(), _shell()]
- "scripts_generate_report_main": "main()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L668 | neighbors=[generate_report.py, aggregate_findings(), load_json(), render_finding_card(), render_table(), run_scraper()]
- "scripts_kit_check": "kit_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _fix(), _on_grid(), _pivot_target(), run()]
- "scripts_lightning": "lightning.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bolt_points(), _clear(), _curve(), _envelope()]
- "scripts_loop_check": "loop_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _check(), _diff(), _poses(), run()]
- "scripts_precipitation_build_tree": "build_tree()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L102 | neighbors=[precipitation.py, _iface(), _T, .math(), .n(), .out()]
- "scripts_retarget": "retarget.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, auto_map(), _parts(), _rot(), run()]
- "scripts_roblox_materials": "roblox_materials.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, column_of(), mat_for(), preview(), resolve()]
- "scripts_scanner": "scanner.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, collect_target_files(), get_scanner_config(), get_supported_extensions(), _identify_semantic_files()]
- "scripts_scatter": "scatter.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_tree(), _instances(), _layer_coll(), _on()]
- "scripts_template_engine_compile_template": "compile_template()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L162 | neighbors=[template_engine.py, EachNode, IfNode, _ParserFrame, TextNode, VarNode]
- "semantic_ssa": "ssa.cpp" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L1 | neighbors=[2c0194b Add assignments and loop-carrie…, 4cead55 Add MUT-27 bytecode verificatio…, 952997e Audit MUT-01-55 and harden veri…, fd66d0d Add MUT-25 typed SSA IR and ver…, dump_ir(), is_terminator()]
- "skyrise_sky_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L112 | neighbors=[sky_map.py, build(), micro_detail(), rim_dress(), spawn_island(), summit()]
- "skyrise_sky_map_spawn_island": "spawn_island()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L224 | neighbors=[sky_map.py, build(), face(), free(), paving(), place()]
- "skyrise_sky_map_summit": "summit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L352 | neighbors=[sky_map.py, build(), face(), island_at(), on_bridge_line(), paving()]
- "skyrise_sky_models3": "sky_models3.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bush(), charred_tree(), lamp_post(), lava_pool()]
- "skyrise_sky_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L61 | neighbors=[sky_props.py, egg_shrine(), flower_bed(), sell_pad(), spawn_pad(), teleport_pad()]
- "src_logging_emit": "emit()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L33 | neighbors=[logging.cpp, critical(), debug(), error(), info(), to_spdlog()]
- "src_narrowphase_epa_penetration": "epa_penetration()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L349 | neighbors=[narrowphase.cpp, collide_local(), cso_support(), face_barycentric(), face_normal(), orient_out()]
- "src_visual_solver_step": "step()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L412 | neighbors=[visual_solver.cpp, add_contact(), begin_step(), collide_visual(), find_body(), integrate()]
- "state_state_snapshot": "state_snapshot.cpp" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, append_le(), load_state_snapshot(), read_le(), save_state_snapshot(), schema_for()]
- "targets_run_dual_target_tests_android_leg": "android_leg()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L293 | neighbors=[run_dual_target_tests.py, adb_shell(), android_compile(), android_tools(), normalize_lf(), now()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-016.json

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
