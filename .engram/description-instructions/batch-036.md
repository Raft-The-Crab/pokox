# Node Description Batch 37 of 209

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

- "input_input_snapshot_hash": "hash()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L236 | neighbors=[input_snapshot.cpp, put16(), put32(), put64(), put8()]
- "input_input_snapshot_put64": "put64()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L18 | neighbors=[input_snapshot.cpp, encode(), hash(), put8(), snapshot_hash()]
- "input_input_snapshot_read_bytes": "read_bytes()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L31 | neighbors=[input_snapshot.cpp, get16(), get32(), get64(), get8()]
- "input_input_snapshot_snapshot_hash": "snapshot_hash()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L321 | neighbors=[input_snapshot.cpp, at(), put32(), put64(), put_event()]
- "integration_config_file_test_put_kv": "put_kv()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L55 | neighbors=[config_file_test.cpp, put_t(), test_config(), test_decoder(), test_resolve()]
- "integration_config_file_test_put_map": "put_map()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L41 | neighbors=[config_file_test.cpp, head(), test_config(), test_decoder(), test_resolve()]
- "integration_config_file_test_put_t": "put_t()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L36 | neighbors=[config_file_test.cpp, put_kv(), head(), test_config(), test_decoder()]
- "integration_config_file_test_put_u": "put_u()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L34 | neighbors=[config_file_test.cpp, head(), test_config(), test_decoder(), test_resolve()]
- "integration_test_cube_x11_smoke": "test_cube_x11_smoke.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_x11_smoke.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, find_window(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_imgui_toggle_x11": "test_imgui_toggle_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_toggle_x11.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, find_window(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_uniform_x11_visual": "test_uniform_x11_visual.py" | kind=code-symbol | source=engine/render/tests/integration/test_uniform_x11_visual.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, find_window(), pixel(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_word_reservations": "test_word_reservations.py" | kind=code-symbol | source=backend/storage/d1/tests/integration/test_word_reservations.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, ReservationMigrationTests, SQLite-level tests for the D1 word-rese…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "medievalbattle_battle_map_courtyard": "courtyard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L284 | neighbors=[battle_map.py, sub(), X(), keep(), flagstone courtyard inside a keep (stat…]
- "medievalbattle_battle_map_ground_shade": "ground_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L164 | neighbors=[battle_map.py, keep_w(), road_d(), trench_drop(), column per face (grass / road dirt / fo…]
- "medievalbattle_battle_map_road_d": "road_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L67 | neighbors=[battle_map.py, ground_shade(), H(), on_road(), seg_d()]
- "medievalbattle_battle_props_buttress": "buttress()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L717 | neighbors=[battle_props.py, merge(), stone(), stepped buttress in canonical orientati…, ruined_chapel()]
- "medievalbattle_battle_props_dead_tree": "dead_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1529 | neighbors=[battle_props.py, lerp(), log(), T(), charred, leafless tree: forked trunk, s…]
- "medievalbattle_battle_props_palisade": "palisade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L883 | neighbors=[battle_props.py, log(), sag(), T(), SIGNATURE: sharpened log stakes (bark b…]
- "medievalbattle_battle_props_pew": "pew()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L729 | neighbors=[battle_props.py, merge(), rot_mb(), T(), ruined_chapel()]
- "medievalbattle_battle_props_slit_frame": "slit_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L218 | neighbors=[battle_props.py, dressed frame round a CUT arrow slit (f…, T(), tower_body(), tower_face()]
- "medievalbattle_battle_props_tent": "tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1154 | neighbors=[battle_props.py, ridge tent (door at -Z): sagging canvas…, log(), T(), torus()]
- "migrations_0002_ledger_balances": "0002_ledger_balances.sql" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, balances, games, ledger_entries, share_entries]
- "moonclean_moon_map_on_ramp": "on_ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L185 | neighbors=[moon_map.py, adiff(), ramp_half_len(), scatter(), zone()]
- "moonclean_moon_map_peak": "peak()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L474 | neighbors=[moon_map.py, build(), adiff(), place(), rail_ring()]
- "moonclean_moon_props_comms_dish": "comms_dish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L610 | neighbors=[moon_props.py, beam(), dish(), torus(), hub antenna: big dish on a yoke, turret…]
- "moonclean_moon_props_egg_incubator": "egg_incubator()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L269 | neighbors=[moon_props.py, egg(), station_base(), torus(), PETS: console with a screen, 3 cryo cag…]
- "moonclean_moon_props_floodlight": "floodlight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L592 | neighbors=[moon_props.py, beam(), lathe(), torus(), hub floodlight mast: tripod foot, taper…]
- "moonclean_moon_props_port": "port()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L101 | neighbors=[moon_props.py, moon_rocket(), torus(), round port window: steel frame ring + r…, reentry_pod()]
- "moonclean_moon_props_vac_pack": "vac_pack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L198 | neighbors=[moon_props.py, gear_locker(), vacuum backpack: twin tanks, frame, dus…, lathe(), torus()]
- "musl_math_cos": "cos.cpp" | kind=code-symbol | source=mute/third_party/musl_math/cos.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, cosine(), kernel_cos(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "musl_math_sin": "sin.cpp" | kind=code-symbol | source=mute/third_party/musl_math/sin.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, kernel_sin(), sine(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_bytecode": "bytecode.hpp" | kind=code-symbol | source=mute/include/poko/mute/bytecode.hpp:L1 | neighbors=[85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_declaration": "declaration.hpp" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, DeclarationAst, DeclarationParser, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "mute_statement": "statement.hpp" | kind=code-symbol | source=mute/include/poko/mute/statement.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, StatementAst, StatementParser, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "namedtuple": "NamedTuple" | kind=code-symbol | neighbors=[_Compartments, _CylinderPocket, _Notch, _Pocket, _PolygonPocket]
- "net_crypto_aead_chacha20_xor": "chacha20_xor()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L81 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), chacha20_block(), store32_le()]
- "net_crypto_aead_poly1305_mac": "poly1305_mac()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L93 | neighbors=[crypto_aead.hpp, aead_open(), aead_seal(), load32_le(), store32_le()]
- "net_delta": "delta.hpp" | kind=code-symbol | source=server/net/include/poko/net/delta.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, decode_delta(), DeltaSchema, encode_delta(), ResendWindow]
- "net_ws_transport": "ws_transport.hpp" | kind=code-symbol | source=server/net/include/poko/net/ws_transport.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, ws_decode(), ws_encode_client(), ws_encode_server(), ws_roundtrip()]
- "oaktrees_gen_trees_bark_fir": "bark_fir()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L100 | neighbors=[gen_trees.py, fft_noise(), normal_from_height(), ramp(), fir / spruce: scaly grey-brown plates w…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-036.json

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
