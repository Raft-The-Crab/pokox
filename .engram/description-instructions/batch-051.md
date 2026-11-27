# Node Description Batch 52 of 208

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

- "mute_bytecode": "bytecode.hpp" | kind=code-symbol | source=mute/include/poko/mute/bytecode.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_declaration": "declaration.hpp" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, DeclarationAst, DeclarationParser, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_device_router": "device_router.hpp" | kind=code-symbol | source=mute/include/poko/mute/device_router.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, DeviceRouter, gamepad_device_code(), touch_device_code()]
- "mute_scheduler": "scheduler.hpp" | kind=code-symbol | source=mute/include/poko/mute/scheduler.hpp:L1 | neighbors=[0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, 435b4d3 Add MUT-23 cooperative async sc…, Scheduler]
- "mute_statement": "statement.hpp" | kind=code-symbol | source=mute/include/poko/mute/statement.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, StatementAst, StatementParser, c7a411f Fix MUT-01-20 audit defects in …]
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
- "onsenvillage_onsen_map_mountains": "mountains()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L45 | neighbors=[onsen_map.py, ground(), H(), nature()]
- "onsenvillage_onsen_map_rail_run": "rail_run()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L346 | neighbors=[onsen_map.py, place(), SIGNATURE: railing bays along a terrace…, village()]
- "onsenvillage_onsen_map_steam": "steam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L491 | neighbors=[onsen_map.py, build(), preview-only steam volumes over the hot…, free()]
- "onsenvillage_onsen_map_terraces": "terraces()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L282 | neighbors=[onsen_map.py, build(), each terrace = running-bond flagstone t…, static()]
- "onsenvillage_onsen_props_bath_pavilion": "bath_pavilion()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L374 | neighbors=[onsen_props.py, hip_roof(), paper_lantern(), open bath shelter over a pool: round ce…]
- "onsenvillage_onsen_props_bucket": "bucket()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L600 | neighbors=[onsen_props.py, lerp(), sake_barrels(), towel_rack()]
- "onsenvillage_onsen_props_frame_storey": "frame_storey()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L208 | neighbors=[onsen_props.py, dark cedar framing: corner posts, extra…, shopfront(), storey_walls()]
- "onsenvillage_onsen_props_holed_wall": "holed_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L125 | neighbors=[onsen_props.py, wall panel L long (x -L/2..L/2), H high…, shopfront(), storey_walls()]
- "onsenvillage_onsen_props_hot_pool": "hot_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L405 | neighbors=[onsen_props.py, lerp(), pool_outline(), steaming rock pool: raised ashlar-and-b…]
- "onsenvillage_onsen_props_noodle_stall": "noodle_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L632 | neighbors=[onsen_props.py, hip_roof(), paper_lantern(), yatai cart: two spoked wheels, cedar co…]
- "onsenvillage_onsen_props_paper_lantern_post": "paper_lantern_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L745 | neighbors=[onsen_props.py, giboshi(), paper_lantern(), cedar lamp post with a crossarm and a h…]
- "onsenvillage_onsen_props_plinth": "plinth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L199 | neighbors=[onsen_props.py, house(), pagoda(), SHARED BASE: sand-ashlar plinth (block …]
- "onsenvillage_onsen_props_rail_post": "rail_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L469 | neighbors=[onsen_props.py, giboshi(), railing(), railing_post()]
- "onsenvillage_onsen_props_sake_barrels": "sake_barrels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L681 | neighbors=[onsen_props.py, cluster: cedar pallet, three standing c…, bucket(), taru()]
- "onsenvillage_onsen_props_taru": "taru()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L667 | neighbors=[onsen_props.py, hand_cart(), sake cask: straw-wrapped body, rope ban…, sake_barrels()]
- "onsenvillage_onsen_props_towel_rack": "towel_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L608 | neighbors=[onsen_props.py, drying rack: two cedar uprights with fe…, bucket(), giboshi()]
- "onsenvillage_onsen_props_window": "window()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L137 | neighbors=[onsen_props.py, cut window: timber frame round the hole…, shopfront(), storey_walls()]
- "package_build_tool_declared_identity": "declared_identity()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L97 | neighbors=[build_tool.cpp, build_project(), after_token(), next_quoted()]
- "package_build_tool_parse_manifest": "parse_manifest()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L53 | neighbors=[build_tool.cpp, quoted(), string_array(), trim()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-051.json

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
