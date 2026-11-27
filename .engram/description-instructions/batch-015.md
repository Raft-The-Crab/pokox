# Node Description Batch 16 of 208

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

- "fishcenter_fish_props_hut_body": "hut_body()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L771 | neighbors=[fish_props.py, boat_house(), lash(), plank_floor(), pole(), woven_wall()]
- "fishcenter_fish_props_motor_boat": "motor_boat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1166 | neighbors=[fish_props.py, barrel(), boat_hull(), lerp(), paint_hull(), rod()]
- "fishcenter_fish_props_palm": "palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L323 | neighbors=[fish_props.py, hammock_palms(), ball(), lerp(), smooth(), palm_planter()]
- "fishcenter_fish_props_quest_board": "quest_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1012 | neighbors=[fish_props.py, ball(), crate(), lash(), pole(), rope()]
- "godot_ablation_report": "ablation_report.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyse(), image_change(), luminance(), main()]
- "hermes_test_bootstrap_bootstrap": "_bootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L24 | neighbors=[test_bootstrap.py, _load(), .test_contains_using_superpowers_body(), .test_frontmatter_stripped(), .test_marker_and_wrapper(), .test_skill_view_guidance_present()]
- "hermes_test_plugin": "test_plugin.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _fire_pre_llm(), _load_plugin(), TestBootstrapInjection, TestLayoutResolution]
- "input_action_map_bindings_conflict": "bindings_conflict()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L75 | neighbors=[action_map.cpp, add_binding(), is_axis_device(), sign_of(), validate_binding(), conflicts()]
- "integration_config_file_test_head": "head()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L20 | neighbors=[config_file_test.cpp, put_arr(), put_b(), put_map(), put_n(), put_t()]
- "integration_config_file_test_test_config": "test_config()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L170 | neighbors=[config_file_test.cpp, main(), put_bool(), put_kv(), put_map(), put_t()]
- "integration_test_mute_console_x11": "test_mute_console_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_mute_console_x11.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 668ca72 Wait for X11 console input read…, 6d9948d Re-resolve X11 demo window duri…, cb2a354 Re-assert window focus in X11 c…, d6139c3 Fix X11 test click helper argum…, e624dc7 Click console input before each…]
- "medievalbattle_battle_map_field": "field()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L382 | neighbors=[battle_map.py, build(), face(), Hm(), place(), reserve()]
- "medievalbattle_battle_map_keep": "keep()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L296 | neighbors=[battle_map.py, build(), courtyard(), Hm(), place(), reserve()]
- "medievalbattle_battle_props_ashlar": "ashlar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L103 | neighbors=[battle_props.py, curtain_wall(), donjon_face(), gatehouse(), parapet_front(), running-bond ashlar panel in the XY pla…]
- "medievalbattle_battle_props_battering_ram": "battering_ram()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1099 | neighbors=[battle_props.py, bar(), lathe(), lerp(), T(), torus()]
- "medievalbattle_battle_props_course_wall": "course_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L162 | neighbors=[battle_props.py, smooth(), T(), donjon(), a wall of real stone blocks from (x, z)…, ruined_chapel()]
- "medievalbattle_battle_props_donjon_top": "donjon_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L508 | neighbors=[battle_props.py, ash_sh(), ashlar_ring(), donjon_face(), lathe(), merge()]
- "medievalbattle_battle_props_ladder": "ladder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1361 | neighbors=[battle_props.py, bar(), lerp(), log(), rot_mb(), T()]
- "medievalbattle_battle_props_stone": "stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L157 | neighbors=[battle_props.py, buttress(), one real block (ruins, rubble, steps, q…, rubble(), ruined_chapel(), T()]
- "medievalbattle_battle_props_weapon_rack": "weapon_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1326 | neighbors=[battle_props.py, A-frame rack: five spears, three swords…, bar(), frame_to(), heater_shield(), lathe()]
- "moonclean_moon_map_adiff": "adiff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L60 | neighbors=[moon_map.py, _crater_ok(), ground(), hub(), lip_rails(), on_ramp()]
- "moonclean_moon_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L107 | neighbors=[moon_map.py, ground(), crater_at(), pock_at(), profile(), ramp_w()]
- "moonclean_moon_map_top_of": "top_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L165 | neighbors=[moon_map.py, crater_ramp(), highest mesh point under a prop's footp…, scatter(), foot(), Hm()]
- "moonclean_moon_props_dust_exchange": "dust_exchange()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L153 | neighbors=[moon_props.py, beam(), lathe(), lerp(), rivets(), station_base()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-015.json

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
