# Node Description Batch 51 of 207

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

- "medievalbattle_battle_props_rubble": "rubble()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1423 | neighbors=[battle_props.py, a heap of fallen ashlar blocks and brok…, stone(), T()]
- "medievalbattle_battle_props_scorch": "scorch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1563 | neighbors=[battle_props.py, shallow scorched impact scar (modelled,…, lathe(), T()]
- "medievalbattle_battle_props_shot_stone": "shot_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1019 | neighbors=[battle_props.py, ammo_pile(), dressed round trebuchet shot: smooth la…, lathe()]
- "medievalbattle_battle_props_truss": "truss()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L738 | neighbors=[battle_props.py, charred roof truss across the nave: tie…, ruined_chapel(), bar()]
- "medievalbattle_battle_props_wall_stair": "wall_stair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L533 | neighbors=[battle_props.py, stone stair climbing along +X from the …, course_wall(), T()]
- "migrations_0001_accounts_games": "0001_accounts_games.sql" | kind=code-symbol | source=backend/storage/postgres/migrations/0001_accounts_games.sql:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, assets, games, users]
- "moonclean_moon_map_crater_ok": "_crater_ok()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L88 | neighbors=[moon_map.py, adiff(), zone_of(), the crater prop's skirt (1.8 R) must st…]
- "moonclean_moon_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L180 | neighbors=[moon_map.py, crater_ramp(), hub(), zone()]
- "moonclean_moon_map_lip_rails": "lip_rails()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L393 | neighbors=[moon_map.py, adiff(), polar(), rail_ring()]
- "moonclean_moon_map_pock_at": "pock_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L210 | neighbors=[moon_map.py, crater_at(), H(), (q, depth) of the nearest pock / crater…]
- "moonclean_moon_map_ramp_half_len": "ramp_half_len()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L35 | neighbors=[moon_map.py, crater_ramp(), on_ramp(), ramp_w()]
- "moonclean_moon_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L162 | neighbors=[moon_map.py, scatter(), Hm(), zone()]
- "moonclean_moon_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L19 | neighbors=[moon_map.py, ground(), hub_deck(), place()]
- "moonclean_moon_props_airlock_gate": "airlock_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L446 | neighbors=[moon_props.py, beacon_post(), torus(), priced zone gate at the head of each cr…]
- "moonclean_moon_props_crater": "crater()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L643 | neighbors=[moon_props.py, lathe(), rock(), modelled impact crater for R = 1 (place…]
- "moonclean_moon_props_fuel_tanks": "fuel_tanks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L579 | neighbors=[moon_props.py, lathe(), torus(), 3 horizontal tanks on cradles (2 bottom…]
- "moonclean_moon_props_launch_tower": "launch_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L413 | neighbors=[moon_props.py, beam(), lathe(), umbilical tower beside the rocket (rock…]
- "moonclean_moon_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L46 | neighbors=[moon_props.py, dust_exchange(), lunar_lander(), station_base()]
- "moonclean_moon_props_satellite_wreck": "satellite_wreck()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L562 | neighbors=[moon_props.py, crashed satellite half-buried: foil bus…, beam(), dish()]
- "moonclean_moon_props_wheel": "wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L531 | neighbors=[moon_props.py, moon_rover(), beam(), torus()]
- "mute_action_map": "action_map.hpp" | kind=code-symbol | source=mute/include/poko/mute/action_map.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, ActionFrame, ActionMap, ActionSampler]
- "mute_device_router": "device_router.hpp" | kind=code-symbol | source=mute/include/poko/mute/device_router.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, DeviceRouter, gamepad_device_code(), touch_device_code()]
- "mute_parser": "parser.hpp" | kind=code-symbol | source=mute/include/poko/mute/parser.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Ast, ExpressionParser, to_arithmetic()]
- "mute_scheduler": "scheduler.hpp" | kind=code-symbol | source=mute/include/poko/mute/scheduler.hpp:L1 | neighbors=[0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, 435b4d3 Add MUT-23 cooperative async sc…, Scheduler]
- "mute_stdlib_math": "stdlib_math.hpp" | kind=code-symbol | source=mute/include/poko/mute/stdlib_math.hpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 952997e Audit MUT-01-55 and harden veri…, SimClock, XorShift128Plus]
- "mute_stdlib_physics": "stdlib_physics.hpp" | kind=code-symbol | source=mute/include/poko/mute/stdlib_physics.hpp:L1 | neighbors=[0d85dce Merge pull request #6 from Raft…, 1aefb72 MUT-42: physics hostcall bounda…, 2680d0e Pushed an update., 7eabc2d Merge pull request #8 from Raft…]
- "net_crypto_aead_store64_le": "store64_le()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L44 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), store32_le()]
- "net_cube_sync": "cube_sync.hpp" | kind=code-symbol | source=server/net/include/poko/net/cube_sync.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, cube_schema(), CubePeer, exchange_over_udp()]
- "net_ws_transport_ws_roundtrip": "ws_roundtrip()" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L109 | neighbors=[ws_transport.hpp, ws_decode(), ws_encode_client(), ws_encode_server()]
- "oaktrees_gen_trees_bark_birch": "bark_birch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L86 | neighbors=[gen_trees.py, fft_noise(), normal_from_height(), ramp()]
- "oaktrees_gen_trees_bark_oak": "bark_oak()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L71 | neighbors=[gen_trees.py, fft_noise(), normal_from_height(), ramp()]
- "oaktrees_gen_trees_canvas_leaf": ".leaf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L153 | neighbors=[Canvas, .grid(), .over(), leaf_atlas()]
- "oaktrees_gen_trees_contact_sheet": "contact_sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L926 | neighbors=[gen_trees.py, load_px(), resize(), main()]
- "oaktrees_gen_trees_img": "_img()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L976 | neighbors=[gen_trees.py, get_materials(), save_png(), paint + save the texture, or (maps) loa…]
- "oaktrees_gen_trees_tree_env": ".env()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L357 | neighbors=[card_quads(), <1 inside the lumpy crown envelope., Tree, .children_of()]
- "onsenvillage_onsen_map_add_owner": "add_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L137 | neighbors=[onsen_map.py, free(), place(), static()]
- "onsenvillage_onsen_map_bank_path": "bank_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L326 | neighbors=[onsen_map.py, H(), static(), flagstone path on the front bank from t…]
- "onsenvillage_onsen_map_fit_bad": "fit_bad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L162 | neighbors=[onsen_map.py, fit(), _inside_one(), _top()]
- "onsenvillage_onsen_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L245 | neighbors=[onsen_map.py, build(), static(), distant peaks far behind the saddle (pa…]
- "onsenvillage_onsen_map_mirror": "mirror()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L116 | neighbors=[onsen_map.py, place(), the village is mirrored about x = 0: we…, village()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-050.json

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
