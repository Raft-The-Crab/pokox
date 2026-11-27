# Node Description Batch 5 of 207

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

- "petsim_pet_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L132 | neighbors=[pet_map.py, breakables(), candy(), crystal(), egg_stand(), fence_ring()]
- "program_program": "program.cpp" | kind=code-symbol | source=mute/src/program/program.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, assemble_program_bytecode(), commit_globals(), compile_program_bytecode(), Depth(), disassemble_program_bytecode()]
- "skyrise_sky_models2": "sky_models2.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, basalt_rocks(), bottle(), cactus(), chest()]
- "skyrise_sky_models4": "sky_models4.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, ash_pile(), blade(), bridge(), dry_shrub()]
- "src_asset_store": "asset_store.cpp" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, acquire(), AssetHandle(), AssetStore(), is_loading(), key()]
- "sugarworks_sugar_map": "sugar_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), face(), free(), ground()]
- "tests_test_privacy": "test_privacy.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L1 | neighbors=[2680d0e Pushed an update., 72b9ac7 Merge branch 'main' into mini-c…, 7eabc2d Merge pull request #8 from Raft…, e77fa31 Add new skills and asset packs …, attribution_allowed(), file_hits()]
- "tests_test_qa": "test_qa.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _qa(), test_clean_cube_passes(), test_detects_floating_parts_and_objects…, test_detects_inverted_and_inconsistent_…]
- "tests_test_run_wrapper": "test_run_wrapper.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, run(), test_bad_script_traceback(), test_bed_empty_string_is_usage_error(), test_bed_fits()]
- "towncity_city_paint": "city_paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, area(), atlas(), axes_of(), block()]
- "unit_action_map_test": "action_map_test.cpp" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, apply_events(), axis(), game_map(), kb(), key()]
- "unit_emit_test": "emit_test.cpp" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L1 | neighbors=[335e0dc Add MUT-26 IR-to-bytecode emitt…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, arith_module(), calls_module(), cases()]
- "vfxkit_lint": "lint.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, authoring.py, colours(), compare_elements(), documented_textures()]
- "vfxkit_unity": "unity.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _blob(), bottom_inset(), export(), _inner_gradient()]
- "cad_skill_main_preview": "preview.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L1 | neighbors=[_add_edges(), _build_grid(), _build_scene(), _get_font(), _info_lines(), main()]
- "candyland_candy_props_candy_castle": "candy_castle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L661 | neighbors=[candy_props.py, ball(), cone_tower(), drip_ring(), lathe(), MS()]
- "creaturelab_lab_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L45 | neighbors=[lab_props.py, _dense(), fig_tree(), hall_ceiling(), heal_counter(), monstera()]
- "device_vulkan_clear_android": "vulkan_clear_android.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L1 | neighbors=[2960ac1 Android Vulkan clear: no fence …, 9eeb3ff Merge pull request #2 from Raft…, c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), destroy_swapchain_resources(), initialize()]
- "dunedesert_dune_props_sun_relief": "sun_relief()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L92 | neighbors=[dune_props.py, colossus_head(), obelisk_stump(), pylon_gate(), quest_stele(), SIGNATURE: raised sun disc + ray wedges…]
- "evaluator_evaluator_evaluate_arithmetic": "evaluate_arithmetic()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L237 | neighbors=[evaluator.cpp, fail(), float_binary(), integer_suffix(), is_float(), is_unsigned()]
- "integration_config_file_test_test_decoder": "test_decoder()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L65 | neighbors=[config_file_test.cpp, main(), head(), put_arr(), put_b(), put_bool()]
- "medievalbattle_battle_props_bridge_tower": "bridge_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L644 | neighbors=[battle_props.py, add_into(), bar(), ell_outline(), h01(), lathe()]
- "medievalbattle_battle_props_sundered_bridge": "sundered_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L549 | neighbors=[battle_props.py, 4-span stone bridge along X (abutments …, ash_sh(), ashlar(), bar(), course_wall()]
- "petsim_pet_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L596 | neighbors=[pet_map.py, build_solid(), candy(), crystal(), edge_pt(), frame()]
- "semantic_semantic": "semantic.cpp" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, accepts(), analyze(), Analyzer, dump_semantic(), generic_arity()]
- "towncity_town_props_add": "add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L67 | neighbors=[town_props.py, ac_unit(), antenna(), awning_band(), building(), deco_window()]
- "unit_test_verify_desktop_evidencetests": "EvidenceTests" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L18 | neighbors=[test_verify_desktop.py, .simulate(), .test_bad_summaries(), .test_failed_configure_preserved(), .test_missing_executable(), .test_never_auto_accept()]
- "valleylake_valley_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L112 | neighbors=[valley_map.py, build(), build_profile(), cliff_clear(), cliffs(), ground()]
- "valleylake_valley_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L143 | neighbors=[valley_map.py, cliffs(), nature(), foot(), H(), kit()]
- "valleylake_valley_props_broadleaf": "broadleaf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L243 | neighbors=[valley_props.py, bark(), leaf_cluster(), leaf_mass(), limb(), merged_crown()]
- "valleylake_valley_props_gnarled_tree": "gnarled_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L306 | neighbors=[valley_props.py, bark(), leaf_cluster(), leaf_mass(), lerp(), limb()]
- "vfxkit_review": "review.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, capture(), compare_sheet(), diff(), dump_metrics()]
- "vm_debugger": "debugger.cpp" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, add_breakpoint(), clear_breakpoints(), finish(), finished(), has_breakpoint()]
- "voidrealm_void_props_chamfer_box": "chamfer_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L102 | neighbors=[void_props.py, arena_rim(), brazier(), crystal_lantern(), pillar(), quest_stand()]
- "bytecode_bytecode": "bytecode.cpp" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L1 | neighbors=[assemble_bytecode(), branch(), branch_offset(), decode_bytecode(), disassemble_bytecode(), encode_bytecode()]
- "cad_skill_main_gridfinity": "gridfinity.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L1 | neighbors=[_Compartments, _compound(), _corner_radii(), _CylinderPocket, _fused(), GridfinityBin]
- "cad_skill_main_gridfinity_gridfinitybin_build": ".build()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L438 | neighbors=[GridfinityBin, _compound(), _fused(), ._base_cells(), ._base_hole_cutter(), ._body()]
- "candyland_candy_props_ball": "ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L121 | neighbors=[candy_props.py, bakery_oven(), candy_castle(), candy_flower(), candy_lamp(), cone_tower()]
- "candyland_candy_props_ms": "MS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L38 | neighbors=[candy_props.py, bakery_oven(), candy_cane(), candy_castle(), candy_lamp(), cotton_candy_tree()]
- "cavemap_cave_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L189 | neighbors=[cave_map.py, bvh_of(), clusters(), crystals(), dripstone(), fungi()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-004.json

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
