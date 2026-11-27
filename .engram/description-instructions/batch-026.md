# Node Description Batch 27 of 207

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

- "fishcenter_fish_props_merge_prop": "_merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L394 | neighbors=[fish_props.py, aquarium_dome(), hammock_palms(), palm_planter(), copy a built Prop's geometry into P (mo…, sea_stack()]
- "fishcenter_fish_props_palm_planter": "palm_planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L381 | neighbors=[fish_props.py, _fern(), lerp(), _merge_prop(), palm(), woven round planter (bamboo hoops) with…]
- "fishcenter_fish_props_sign_board": "sign_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L255 | neighbors=[fish_props.py, aquarium_dome(), fish_index_wall(), quest_board(), BLANK carved sign board for a GUI label…, ball()]
- "fishcenter_fish_props_skiff": "skiff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1148 | neighbors=[fish_props.py, rowboat (white, teal stripe, red bottom…, boat_hull(), lerp(), paint_hull(), rope()]
- "fishcenter_fish_props_thatch_cone": "thatch_cone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L180 | neighbors=[fish_props.py, bait_shop(), lerp(), ring_circ(), thatch_band(), umbrella()]
- "fishcenter_fish_props_thatch_hip": "thatch_hip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L159 | neighbors=[fish_props.py, fish_index_wall(), fish_market(), hip roof of `layers` overlapping fringe…, rod_shop(), thatch_band()]
- "frostpeak_frost_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L140 | neighbors=[frost_map.py, build(), foot(), H(), kit(), sub()]
- "hermes_test_plugin_fire_pre_llm": "_fire_pre_llm()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L27 | neighbors=[test_plugin.py, .test_first_turn_returns_bootstrap_cont…, .test_hook_tolerates_future_kwargs(), .test_later_turns_return_none(), .test_non_subagent_platforms_receive_bo…, .test_subagent_platform_skips_bootstrap…]
- "hermes_test_plugin_testbootstrapinjection": "TestBootstrapInjection" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L73 | neighbors=[test_plugin.py, .test_first_turn_returns_bootstrap_cont…, .test_hook_tolerates_future_kwargs(), .test_later_turns_return_none(), .test_non_subagent_platforms_receive_bo…, .test_subagent_platform_skips_bootstrap…]
- "hermes_test_plugin_testlayoutresolution": "TestLayoutResolution" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L117 | neighbors=[test_plugin.py, ._load_from(), ._stage(), .test_clone_layout_resolves_sibling_ski…, .test_flat_layout_resolves_nested_skill…, .test_missing_skills_raises_loudly()]
- "imgui_enginefactoryvk": "EngineFactoryVk.h" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Diligent(), GraphicsPipeline(), IDeviceObject(), IEngineFactory(), RTVFormats()]
- "input_action_map_validate_binding": "validate_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L49 | neighbors=[action_map.cpp, add_binding(), bindings_conflict(), decode(), replace_binding(), set_bindings()]
- "input_input_snapshot_decode": "decode()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L295 | neighbors=[input_snapshot.cpp, append(), get16(), get32(), get64(), get8()]
- "input_input_snapshot_put_event": "put_event()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L21 | neighbors=[input_snapshot.cpp, encode(), put16(), put32(), put8(), snapshot_hash()]
- "input_input_snapshot_put32": "put32()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L15 | neighbors=[input_snapshot.cpp, encode(), hash(), put8(), put_event(), snapshot_hash()]
- "integration_cube_golden_x11": "X11" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L57 | neighbors=[cube_golden.py, run(), .capture(), .close(), .find_window(), .__init__()]
- "integration_test_cube_golden_unit_goldenencodertests": "GoldenEncoderTests" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L50 | neighbors=[test_cube_golden_unit.py, .test_actual_cannot_replace_reference_o…, .test_bad_inputs(), .test_capture_cannot_replace_shipped_re…, .test_reference_is_full_cube_with_three…, .test_roundtrip_and_multiple_deflate_bl…]
- "integration_test_shader_pipeline": "test_shader_pipeline.py" | kind=code-symbol | source=engine/render/tests/integration/test_shader_pipeline.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …, check_spirv(), run(), update_shader(), Exercise the real host compiler and CMa…]
- "medievalbattle_battle_map_centre": "centre()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L338 | neighbors=[battle_map.py, build(), place(), reserve(), X(), Yw()]
- "medievalbattle_battle_map_hm": "Hm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L137 | neighbors=[battle_map.py, field(), H(), keep(), place(), height of the built ground MESH (4-stud…]
- "medievalbattle_battle_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L159 | neighbors=[battle_map.py, build(), centre(), field(), keep(), scatter()]
- "medievalbattle_battle_map_roads": "roads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L228 | neighbors=[battle_map.py, build(), roads as smooth ribbon meshes draped on…, H(), sub(), X()]
- "medievalbattle_battle_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1267 | neighbors=[battle_props.py, lathe(), T(), torus(), supply_pile(), well()]
- "medievalbattle_battle_props_brazier": "brazier()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1236 | neighbors=[battle_props.py, flame(), lathe(), T(), torus(), iron brazier: three curled legs, rivete…]
- "medievalbattle_battle_props_cheval": "cheval()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L909 | neighbors=[battle_props.py, frame_to(), log(), T(), torus(), cheval de frise: a squared log run thro…]
- "medievalbattle_battle_props_corbels": "corbels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L210 | neighbors=[battle_props.py, T(), curtain_wall(), parapet_front(), stepped corbel blocks along X under a p…, tower_face()]
- "medievalbattle_battle_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1252 | neighbors=[battle_props.py, broken_cart(), merge(), T(), plank crate: core + slat boards + iron …, supply_pile()]
- "medievalbattle_battle_props_ell_outline": "ell_outline()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L346 | neighbors=[battle_props.py, bridge_tower(), donjon(), gatehouse(), elliptical / segmental arch outline in …, sundered_bridge()]
- "medievalbattle_battle_props_frame_to": "frame_to()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L52 | neighbors=[battle_props.py, bar(), cheval(), bm built along +X from 0..L (Y up): rot…, trebuchet(), weapon_rack()]
- "medievalbattle_battle_props_gravestones": "gravestones()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L859 | neighbors=[battle_props.py, bar(), lathe(), T(), torus(), 3 tilted headstones on mounds, a makesh…]
- "medievalbattle_battle_props_mantlet": "mantlet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1131 | neighbors=[battle_props.py, bar(), log(), T(), wheel(), wheeled oak pavise: planks with a cut s…]
- "medievalbattle_battle_props_merlon_row": "merlon_row()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L199 | neighbors=[battle_props.py, curtain_wall(), T(), parapet_front(), crenellation along X centred at x = 0, …, tower_face()]
- "medievalbattle_battle_props_outline_prism": "outline_prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L352 | neighbors=[battle_props.py, bridge_tower(), donjon(), gatehouse(), closed solid of an outline (XY) from z0…, sundered_bridge()]
- "medievalbattle_battle_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1473 | neighbors=[battle_props.py, bough_skirt(), lerp(), log(), T(), fir in four forms (tall spire / full / …]
- "medievalbattle_battle_props_slit_cutter": "slit_cutter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L226 | neighbors=[battle_props.py, bridge_tower(), add an arrow-slit cutter box (front = -…, add_into(), T(), tower_body()]
- "medievalbattle_battle_props_supply_pile": "supply_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1276 | neighbors=[battle_props.py, two crates, a barrel pair, tied sacks, barrel(), crate(), T(), torus()]
- "moonclean_moon_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L250 | neighbors=[moon_map.py, build(), adiff(), H(), radial_samples(), sub()]
- "moonclean_moon_map_hub": "hub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L342 | neighbors=[moon_map.py, build(), adiff(), face(), place(), reserve()]
- "moonclean_moon_map_polar": "polar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L184 | neighbors=[moon_map.py, crater_ramp(), lip_rails(), rail_ring(), scatter(), zone()]
- "moonclean_moon_map_rail_ring": "rail_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L314 | neighbors=[moon_map.py, lip_rails(), peak(), place(), polar(), the signature beacon rail along a lip: …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-026.json

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
