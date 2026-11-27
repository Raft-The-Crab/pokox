# Node Description Batch 13 of 209

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

- "dunedesert_dune_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L78 | neighbors=[dune_map.py, ground(), dunes(), pl_d(), ring(), T_local()]
- "dunedesert_dune_props_shaft": "_shaft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L356 | neighbors=[dune_props.py, obelisk(), obelisk_fallen(), obelisk_stump(), square tapered shaft (w0 at 0 .. w1 at …, disc()]
- "eggplots_egg_props_coop": "coop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L296 | neighbors=[egg_props.py, egg(), egg_finial(), egg_profile(), rbox(), sh()]
- "eggplots_egg_props_egg_finial": "egg_finial()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L147 | neighbors=[egg_props.py, coop(), egg(), sh(), fence_post(), gate_frame()]
- "eggplots_egg_props_egg_profile": "egg_profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L75 | neighbors=[egg_props.py, coop(), egg(), egg_drain(), egg_slice(), foot_bridge()]
- "eggplots_egg_props_straw_nest": "straw_nest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L136 | neighbors=[egg_props.py, coop(), deco_egg(), egg_shop(), gate_frame(), hatchery()]
- "evaluator_evaluator_fail": "fail()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L67 | neighbors=[evaluator.cpp, evaluate_arithmetic(), float_binary(), literal_float(), literal_integer(), materialize()]
- "fishcenter_fish_map_deck_rect": "deck_rect()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L228 | neighbors=[fish_map.py, beam(), lp(), piling(), prism(), sh_val()]
- "fishcenter_fish_map_hardscape": "hardscape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L318 | neighbors=[fish_map.py, build(), compass(), deck_rect(), lp(), platform()]
- "fishcenter_fish_map_lp": "lp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L37 | neighbors=[fish_map.py, deck_rect(), edges(), hardscape(), outward(), tangent()]
- "fishcenter_fish_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L651 | neighbors=[fish_map.py, build(), free(), H(), outward(), place()]
- "fishcenter_fish_props_fish_market": "fish_market()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L905 | neighbors=[fish_props.py, awning(), barrel(), crate(), fish(), plank_floor()]
- "integration_test_mute_console_x11": "test_mute_console_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_mute_console_x11.py:L1 | neighbors=[668ca72 Wait for X11 console input read…, 6d9948d Re-resolve X11 demo window duri…, cb2a354 Re-assert window focus in X11 c…, d6139c3 Fix X11 test click helper argum…, e624dc7 Click console input before each…, f4a6ac4 Allowlist known validation-laye…]
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
