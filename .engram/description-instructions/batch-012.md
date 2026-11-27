# Node Description Batch 13 of 207

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

- "medievalbattle_battle_props_voussoirs": "voussoirs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L366 | neighbors=[battle_props.py, donjon_face(), gatehouse(), wedge stones round an arch (face plane …, ruined_chapel(), sundered_bridge()]
- "medievalbattle_battle_props_well": "well()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1585 | neighbors=[battle_props.py, courtyard well: ring of ashlar blocks w…, bar(), barrel(), lathe(), log()]
- "medievalbattle_battle_props_wheel": "wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L951 | neighbors=[battle_props.py, battering_ram(), broken_cart(), mantlet(), spoked wheel: hub with iron cap, spokes…, trebuchet()]
- "moonclean_moon_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L325 | neighbors=[moon_map.py, crater_ramp(), craters(), ground(), hub(), hub_deck()]
- "moonclean_moon_map_hm": "Hm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L153 | neighbors=[moon_map.py, crater_ramp(), craters(), H(), place(), height of the built ground MESH (coarse…]
- "moonclean_moon_props_moon_rocket": "moon_rocket()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L354 | neighbors=[moon_props.py, beacon_post(), beam(), lathe(), port(), rivets()]
- "moonclean_moon_props_shang": "ShAng" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L85 | neighbors=[moon_props.py, moon_rocket(), two-colour checker by face angle around…, reentry_pod(), .__call__(), .__init__()]
- "moonclean_moon_props_station_base": "station_base()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L124 | neighbors=[moon_props.py, dust_exchange(), egg_incubator(), gear_locker(), hex landing pad on 4 splayed lander leg…, reentry_pod()]
- "oaktrees_gen_trees_make_tree": "make_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1022 | neighbors=[gen_trees.py, main(), get_materials(), make_object(), Tree, .build()]
- "onsenvillage_onsen_props_house": "house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L257 | neighbors=[onsen_props.py, balcony(), hip_roof(), paper_lantern(), plinth(), shopfront()]
- "parser_parser": "parser.cpp" | kind=code-symbol | source=mute/src/parser/parser.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, dump_ast(), expr_op(), ExpressionParser, is_assign_op(), name()]
- "parser_statement": "statement.cpp" | kind=code-symbol | source=mute/src/parser/statement.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Depth(), dump_statement_ast(), LoopScope(), name(), parse_statements()]
- "petsim_pet_map_egg_stand": "egg_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L367 | neighbors=[pet_map.py, anchor(), face(), H(), local(), place()]
- "petsim_pet_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L192 | neighbors=[pet_map.py, breakables(), build_solid(), candy(), crystal(), hub()]
- "petsim_pet_map_isle_r": "isle_R()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L37 | neighbors=[pet_map.py, breakables(), edge_pt(), fence_ring(), isle_at(), isle_mesh()]
- "petsim_pet_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L193 | neighbors=[pet_map.py, breakables(), candy(), crystal(), egg_stand(), hub()]
- "petsim_pet_props_puffpaw": "puffpaw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L203 | neighbors=[pet_props.py, mascot_test(), pet_statue(), ell(), flat(), pill()]
- "petsim_pet_props_upgrade_machine": "upgrade_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L451 | neighbors=[pet_props.py, giant gumball machine: rounded red drum…, ell(), flat(), pill(), rbox()]
- "petsim_pet_props_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L584 | neighbors=[pet_props.py, toll arch: two chubby stacked pillars w…, ell(), flat(), paw(), pill()]
- "plusspeed_plus_props_v4_pixel_art": "pixel_art()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L17 | neighbors=[plus_props_v4.py, egg_hatchery(), hoarding(), medal_pad(), plinth(), rows[0] is the top row. Art is centred …]
- "scripts_export_asset": "export_asset.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _animated(), _coerce(), _export(), _gather()]
- "scripts_play_store_scraper": "play_store_scraper.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, extract_data_safety(), extract_metadata(), fetch_html(), load_taxonomy()]
- "scripts_precipitation": "precipitation.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_tree(), _camera_box(), _iface(), _material()]
- "scripts_precipitation_t": "_T" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L38 | neighbors=[precipitation.py, build_tree(), Minimal node-graph helper: n(type, inpu…, .__init__(), .math(), .n()]
- "scripts_sim_setup": "sim_setup.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _asset_group(), _ctx(), _num(), run()]
- "scripts_smart_material_build_group": "build_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L86 | neighbors=[smart_material.py, _G, .link(), .math(), .mix(), .mrange()]
- "scripts_surface_weather_build_group": "build_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L79 | neighbors=[surface_weather.py, _G, .link(), .math(), .mix(), .mrange()]
- "scripts_toon_setup_build_group": "build_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L81 | neighbors=[toon_setup.py, _G, .link(), .math(), .mix(), .n()]
- "scripts_toon_setup_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L282 | neighbors=[toon_setup.py, _apply_mat(), build_group(), _key_light(), _lin(), _line_art()]
- "scripts_turntable": "turntable.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _area(), _backdrop(), _bounds(), _clear()]
- "skyrise_sky_models": "sky_models.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bevel_box(), blossom_tree(), island_under(), lumpy()]
- "src_character_controller_update": "update()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L206 | neighbors=[character_controller.cpp, capsule_at(), cast_fraction(), deepest_contact(), planar(), shape_bound()]
- "src_config_load_file": "load_file()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L100 | neighbors=[config.cpp, collect_unknown(), fail(), find_key(), parse_level(), read_bool()]
- "src_gallery": "gallery.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, drum(), flat(), ground(), put()]
- "src_loop": "loop.cpp" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, advance(), alpha(), backlog_seconds(), FixedStepLoop(), reset_backlog()]
- "tests_test_mesh_io": "test_mesh_io.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_bed_fit_allows_rotation_and_report…, test_estimate_mass_hollow_less_than_sol…, test_load_mesh_empty_file(), test_load_mesh_missing_file()]
- "tests_test_package_vfx": "vfx()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L14 | neighbors=[test_package.py, Run the CLI with the test interpreter; …, test_a_fresh_project_lints_a_recipe_tha…, test_cli_init_examples_and_lint_in_a_fr…, test_doctor_reports_an_initialised_work…, test_effect_verify_reports_missing_evid…]
- "texture_tex_to_maps_process": "process()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L106 | neighbors=[tex_to_maps.py, main(), derive_ao(), derive_normal(), derive_roughness(), high_pass()]
- "texture_tile_seam_check": "tile_seam_check.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, assess(), boundary_metrics(), load_gray(), main()]
- "towncity_town_map_landmarks": "landmarks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L284 | neighbors=[town_map.py, build(), anchor(), face(), place(), reserve()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-012.json

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
