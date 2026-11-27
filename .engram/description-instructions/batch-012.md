# Node Description Batch 13 of 208

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

- "framegraph_frame_graph": "frame_graph.cpp" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, add_pass(), build_plan(), clear(), compile(), execute()]
- "integration_cube_golden": "cube_golden.py" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, canonical_png(), main(), png_chunk(), run()]
- "lexer_lexer_lex": "lex()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L94 | neighbors=[lexer.cpp, decode(), digit(), digit_for(), is_continue(), is_start()]
- "medievalbattle_battle_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L471 | neighbors=[battle_map.py, centre(), field(), ground(), keep(), reserve()]
- "medievalbattle_battle_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L146 | neighbors=[battle_map.py, centre(), field(), keep(), foot(), Hm()]
- "medievalbattle_battle_props_broken_cart": "broken_cart()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1304 | neighbors=[battle_props.py, bar(), crate(), log(), merge(), rot_mb()]
- "medievalbattle_battle_props_curtain_wall": "curtain_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L266 | neighbors=[battle_props.py, ash_sh(), ashlar(), corbels(), heater_shield(), merlon_row()]
- "medievalbattle_battle_props_donjon": "donjon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L469 | neighbors=[battle_props.py, add_into(), course_wall(), donjon_face(), ell_outline(), merge()]
- "medievalbattle_battle_props_siege_tower": "siege_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1039 | neighbors=[battle_props.py, tapered timber assault tower on six sol…, bar(), heater_shield(), lerp(), merge()]
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
- "parser_declaration": "declaration.cpp" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, decl_fail(), decl_quoted(), DeclarationParser, Depth(), dump_declaration_ast()]
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
- "src_cbor": "cbor.cpp" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 52dbcb9 Surface graphics warnings in X1…, decode(), decode_item(), fail(), half_to_double()]

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
