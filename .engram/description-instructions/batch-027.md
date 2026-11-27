# Node Description Batch 28 of 209

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

- "integration_cube_golden_x11": "X11" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L57 | neighbors=[cube_golden.py, run(), .capture(), .close(), .find_window(), .__init__()]
- "integration_logging_file_test": "logging_file_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, count_stamps(), main(), read_file(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_cube_golden_unit": "test_cube_golden_unit.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, decode(), GoldenEncoderTests, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_cube_golden_unit_goldenencodertests": "GoldenEncoderTests" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L50 | neighbors=[test_cube_golden_unit.py, .test_actual_cannot_replace_reference_o…, .test_bad_inputs(), .test_capture_cannot_replace_shipped_re…, .test_reference_is_full_cube_with_three…, .test_roundtrip_and_multiple_deflate_bl…]
- "integration_test_mute_state_console_x11": "test_mute_state_console_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_mute_state_console_x11.py:L1 | neighbors=[6d9948d Re-resolve X11 demo window duri…, cb2a354 Re-assert window focus in X11 c…, f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
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
- "moonclean_moon_map_ramp_w": "ramp_w()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L96 | neighbors=[moon_map.py, ground_shade(), H(), adiff(), ramp_half_len(), weight 0..1 of ramp k at (r, a) and the…]
- "moonclean_moon_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L183 | neighbors=[moon_map.py, crater_ramp(), craters(), hub(), scatter(), zone()]
- "moonclean_moon_map_zone_of": "zone_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L126 | neighbors=[moon_map.py, _crater_ok(), craters(), ground_shade(), H(), zone()]
- "moonclean_moon_props_gear_locker": "gear_locker()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L210 | neighbors=[moon_props.py, lathe(), station_base(), torus(), vac_pack(), SHOP: curved white locker wall with 3 v…]
- "moonclean_moon_props_moon_rover": "moon_rover()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L539 | neighbors=[moon_props.py, beam(), dish(), torus(), wheel(), abandoned lunar rover: tube chassis, 4 …]
- "mute_parser": "parser.hpp" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Ast, ExpressionParser, to_arithmetic(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_values": "values.hpp" | kind=code-symbol | source=mute/include/poko/mute/values.hpp:L1 | neighbors=[0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, 5edd00c Fix MUT-21/22 audit defects in …, 964ba8a Resolve MUT-22 values runtime l…, e685cdf Add MUT-22 aggregate VM value a…, AggregateStore]
- "net_bit_buffer": "bit_buffer.hpp" | kind=code-symbol | source=server/net/include/poko/net/bit_buffer.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, BitBuffer, get_array(), get_delta(), put_array(), put_delta()]
- "net_crypto_aead_aead_seal": "aead_seal()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L219 | neighbors=[crypto_aead.hpp, chacha20_block(), chacha20_xor(), poly1305_mac(), store32_le(), store64_le()]
- "net_crypto_aead_chacha20_block": "chacha20_block()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L58 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), load32_le(), qr(), chacha20_xor()]
- "net_crypto_aead_store32_le": "store32_le()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L37 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), chacha20_xor(), poly1305_mac(), store64_le()]
- "oaktrees_gen_trees_branch": "Branch" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L331 | neighbors=[gen_trees.py, .at(), .__init__(), .length(), .grow(), .grow_roots()]
- "oaktrees_gen_trees_canvas_capsule_path": ".capsule_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L131 | neighbors=[Canvas, .grid(), .over(), leaf_atlas(), needle_atlas(), Tapered stroke along pts (px), clipped …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-027.json

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
