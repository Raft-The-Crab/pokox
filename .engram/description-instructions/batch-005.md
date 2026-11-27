# Node Description Batch 6 of 207

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

- "cavemap_cave_map_landmarks": "landmarks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L601 | neighbors=[cave_map.py, build(), anchor(), ceil_y(), face(), free()]
- "cavemap_cave_map_wd": "wd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L142 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), floor(), fungi()]
- "dunedesert_dune_props_v": "V()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L49 | neighbors=[dune_props.py, camel(), colossus_head(), dune_grass(), outcrop(), soft per-loop shade: height ramp + vert…]
- "effekseer_ai_authoring_layerbuilder": "LayerBuilder" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L107 | neighbors=[authoring.py, compile_effect(), .advanced(), .bind(), .color(), .curve()]
- "eggplots_egg_props_egg": "egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L95 | neighbors=[egg_props.py, coop(), deco_egg(), egg_profile(), lerp(), sh()]
- "fishcenter_fish_props_ball": "ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L46 | neighbors=[fish_props.py, bait_shop(), bench(), fish(), lifebuoy_stand(), lighthouse()]
- "foundation_fixed_vec": "fixed_vec.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 69287a0 Land ENG-60-65 deterministic si…, 9eeb3ff Merge pull request #2 from Raft…, cross(), dot(), FixedVec3()]
- "frostpeak_frost_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L185 | neighbors=[frost_map.py, _drift(), face(), foot(), free(), front_to()]
- "medievalbattle_battle_props_ruined_chapel": "ruined_chapel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L751 | neighbors=[battle_props.py, roofless gothic chapel (door at -Z): re…, bar(), buttress(), course_wall(), lathe()]
- "petsim_pet_map_breakables": "breakables()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L340 | neighbors=[pet_map.py, anchor(), free(), H(), isle_at(), isle_R()]
- "petsim_pet_props_flat": "flat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L60 | neighbors=[pet_props.py, coin_pile(), vsh(), flower_patch(), giant_donut(), leaderboard()]
- "petsim_pet_props_rcyl": "rcyl()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L93 | neighbors=[pet_props.py, bridge(), disc_up(), egg_stand(), fence(), leaderboard()]
- "scripts_blocks": "blocks.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Block, BlockProp, clear_material(), _f()]
- "scripts_groom": "groom.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _assets(), build_cards(), card_material(), curve_stats()]
- "scripts_scene_mood_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L330 | neighbors=[scene_mood.py, _clear(), _coll(), _fog(), _fog_box(), _grade()]
- "scripts_toon_setup": "toon_setup.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_mat(), build_group(), _drive_light(), _G]
- "skyrise_sky_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L98 | neighbors=[sky_map.py, build(), island_mesh(), micro_detail(), foot(), Hm()]
- "stdlib_stdlib_collections": "stdlib_collections.cpp" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, contains(), dump(), erase(), get(), hash()]
- "targets_run_dual_target_tests": "run_dual_target_tests.py" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 952997e Audit MUT-01-55 and harden veri…, adb_shell(), android_compile(), android_leg(), android_tools()]
- "tests_test_golden_goldenharnesstests": "GoldenHarnessTests" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L17 | neighbors=[test_golden.py, .pair(), .setUp(), .test_binary_match(), .test_binary_mismatch_does_not_update_r…, .test_chunk_boundary()]
- "tests_test_run_wrapper_run": "run()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L14 | neighbors=[test_run_wrapper.py, test_bad_script_traceback(), test_bed_empty_string_is_usage_error(), test_bed_fits(), test_bed_too_small_fails(), test_bed_unknown_printer_is_usage_error…]
- "tools_validate_skills": "validate_skills.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, check_coverage(), check_skill(), collect_tech_ids(), find_skills()]
- "towncity_town_vehicles": "town_vehicles.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, body_shader(), body_shell(), bus(), car()]
- "unit_action_map_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L69 | neighbors=[action_map_test.cpp, apply_events(), axis(), game_map(), kb(), key()]
- "unit_opengl_clear_faults": "opengl_clear_faults.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, bind(), get_attachment(), get_error(), get_int(), GetEngineFactoryOpenGL()]
- "valleylake_valley_map_cliffs": "cliffs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L612 | neighbors=[valley_map.py, build(), cliff_clear(), cliff_mesh(), face(), free()]
- "vfxkit_textures": "textures.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, flame_band(), helix(), inspect(), inspect_all()]
- "warehouse_wh_equip": "wh_equip.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bollard(), charger_unit(), conveyor(), fire_point()]
- "warehouse_wh_yard": "wh_yard.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, axle_set(), box_trailer(), dock_stair(), fence_panel()]
- "whispering_grove_forest_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L190 | neighbors=[forest_map.py, CAMP_PTS(), face(), free(), ground(), H()]
- "cad_skill_main_gridfinity_gridfinityerror": "GridfinityError" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L63 | neighbors=[gridfinity.py, _corner_radii(), .add_compartments(), .add_cylinder_pocket(), ._check_depth(), ._check_wall_clearance()]
- "candyland_candy_props_cone_tower": "cone_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L637 | neighbors=[candy_props.py, candy_castle(), ball(), drip_ring(), lathe(), piping()]
- "candyland_candy_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L145 | neighbors=[candy_props.py, bakery_oven(), candy_castle(), candy_lamp(), choco_falls(), cone_tower()]
- "cavemap_cave_map_crystals": "crystals()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L469 | neighbors=[cave_map.py, build(), free(), H(), in_hole(), lake_d()]
- "cavemap_cave_map_dripstone": "dripstone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L432 | neighbors=[cave_map.py, build(), ceil_y(), free(), H(), in_hole()]
- "cavemap_cave_map_mine_sets": "mine_sets()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L687 | neighbors=[cave_map.py, build(), face(), free(), H(), in_hole()]
- "creaturelab_lab_props_catch_ball": "catch_ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1844 | neighbors=[lab_props.py, ball_lineup(), capsule(), ball(), _ball_sh(), leaf_poly()]
- "creaturelab_lab_props_upright": "upright()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L95 | neighbors=[lab_props.py, art_frame(), emblem(), ext_bench(), heal_machine(), lab_archway()]
- "dunedesert_gen_trees_with_palms_canvas": "Canvas" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L114 | neighbors=[gen_trees_with_palms.py, .capsule_path(), .finish(), .grid(), .__init__(), .leaf()]
- "effekseer_ai_authoring": "authoring.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _code(), compile_effect(), cutoff_easing(), layer_schema()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-005.json

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
