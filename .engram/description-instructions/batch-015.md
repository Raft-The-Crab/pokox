# Node Description Batch 16 of 207

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
- "parser_declaration": "declaration.cpp" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, decl_fail(), decl_quoted(), DeclarationParser, Depth(), dump_declaration_ast()]
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
