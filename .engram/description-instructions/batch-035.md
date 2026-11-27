# Node Description Batch 36 of 208

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

- "evaluator_evaluator_unsigned_binary": "unsigned_binary()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L188 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), unsigned_max(), width()]
- "examples_axolotl_gills": "gills()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L100 | neighbors=[axolotl.py, happy(), idle(), swim(), walk()]
- "exception": "Exception" | kind=code-symbol | neighbors=[cube_demo.cpp, imgui_demo.cpp, triangle_demo.cpp, Skip, sdl_platform_faults.cpp]
- "fishcenter_fish_map_beam": "beam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L222 | neighbors=[fish_map.py, prism(), sh_val(), deck_rect(), ring_deck()]
- "fishcenter_fish_map_compass": "compass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L299 | neighbors=[fish_map.py, pos(), sh_val(), hardscape(), compass-rose inlay in the spawn plaza d…]
- "fishcenter_fish_map_outward": "outward()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L35 | neighbors=[fish_map.py, islet_e(), islet_grass(), lp(), nature()]
- "fishcenter_fish_map_platform": "platform()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L269 | neighbors=[fish_map.py, hardscape(), pos(), sh_val(), central coral-stone platform: polar fla…]
- "fishcenter_fish_map_prism": "prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L202 | neighbors=[fish_map.py, beam(), deck_rect(), plank / slab from a top quad [(x, z) x4…, ring_deck()]
- "fishcenter_fish_map_rails_flush": "rails_flush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L483 | neighbors=[fish_map.py, edges(), bay_key(), place(), place every collected run: each bay car…]
- "fishcenter_fish_props_awning": "awning()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L236 | neighbors=[fish_props.py, loft(), fish_market(), striped canvas awning off a wall at z (…, rod_shop()]
- "fishcenter_fish_props_boat_house": "boat_house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L990 | neighbors=[fish_props.py, hut_body(), shutter(), thatch_gable(), BOAT RENTAL (lagoon teal): bamboo hut w…]
- "fishcenter_fish_props_boat_hull": "boat_hull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1111 | neighbors=[fish_props.py, lerp(), motor_boat(), hollow lofted boat hull: U sections clo…, skiff()]
- "fishcenter_fish_props_fish_index_wall": "fish_index_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1053 | neighbors=[fish_props.py, fish(), sign_board(), thatch_hip(), AQUARIUM INDEX wall: plank backboard on…]
- "fishcenter_fish_props_rod": "rod()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L647 | neighbors=[fish_props.py, motor_boat(), fishing rod: cork grip, rod blank, guid…, rod_rack(), rod_shop()]
- "fishcenter_fish_props_rod_rack": "rod_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L657 | neighbors=[fish_props.py, A-frame rod rack: bamboo frame, slotted…, lash(), pole(), rod()]
- "fishcenter_fish_props_sea_stack": "sea_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L494 | neighbors=[fish_props.py, tall volcanic sea stack: stacked tilted…, lerp(), _merge_prop(), palm()]
- "fishcenter_fish_props_thatch_band": "thatch_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L130 | neighbors=[fish_props.py, one layer of thatch: outer surface from…, loft(), thatch_cone(), thatch_hip()]
- "fishcenter_fish_props_thatch_gable": "thatch_gable()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L958 | neighbors=[fish_props.py, boat_house(), steep A-frame thatch: ridge along Z, ea…, lash(), lerp()]
- "fishcenter_fish_props_woven_wall": "woven_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L200 | neighbors=[fish_props.py, hut_body(), wall panel L long, H high (local x -L/2…, local(), mat_cell()]
- "frostpeak_frost_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L18 | neighbors=[frost_map.py, ground(), horizon(), place(), square()]
- "harness_golden": "golden.py" | kind=code-symbol | source=tools/testutils/harness/golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, first_difference(), main(), update_golden(), c7a411f Fix MUT-01-20 audit defects in …]
- "hermes_test_plugin_testskilldescriptions": "TestSkillDescriptions" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L164 | neighbors=[test_plugin.py, Hermes builds its skill catalogue from …, .test_descriptions_match_the_skill_fron…, .test_every_stock_skill_registers_a_des…, .test_frontmatter_value_parsing()]
- "identity_sign_in": "sign_in.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, AccountStore, format_user_id(), InMemoryAccountStore, SignInService]
- "identity_worker_auth": "worker_auth.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L1 | neighbors=[6568dc9 Update from ML AI Code, base64url_decode(), base64url_encode(), FirebaseTokenVerifier, SessionTickets]
- "input_action_map_put8": "put8()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L12 | neighbors=[action_map.cpp, encode(), hash(), put16(), put32()]
- "input_action_map_read_binding": "read_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L237 | neighbors=[action_map.cpp, clamp_i32(), read_digital(), sign_of(), sample()]
- "input_action_map_set_bindings": "set_bindings()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L130 | neighbors=[action_map.cpp, decode(), bindings_conflict(), find(), validate_binding()]
- "input_input_snapshot_encode": "encode()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L282 | neighbors=[input_snapshot.cpp, put32(), put64(), put8(), put_event()]
- "input_input_snapshot_hash": "hash()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L236 | neighbors=[input_snapshot.cpp, put16(), put32(), put64(), put8()]
- "input_input_snapshot_put64": "put64()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L18 | neighbors=[input_snapshot.cpp, encode(), hash(), put8(), snapshot_hash()]
- "input_input_snapshot_read_bytes": "read_bytes()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L31 | neighbors=[input_snapshot.cpp, get16(), get32(), get64(), get8()]
- "input_input_snapshot_snapshot_hash": "snapshot_hash()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L321 | neighbors=[input_snapshot.cpp, at(), put32(), put64(), put_event()]
- "integration_config_file_test_put_kv": "put_kv()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L55 | neighbors=[config_file_test.cpp, put_t(), test_config(), test_decoder(), test_resolve()]
- "integration_config_file_test_put_map": "put_map()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L41 | neighbors=[config_file_test.cpp, head(), test_config(), test_decoder(), test_resolve()]
- "integration_config_file_test_put_t": "put_t()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L36 | neighbors=[config_file_test.cpp, put_kv(), head(), test_config(), test_decoder()]
- "integration_config_file_test_put_u": "put_u()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L34 | neighbors=[config_file_test.cpp, head(), test_config(), test_decoder(), test_resolve()]
- "integration_logging_file_test": "logging_file_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, count_stamps(), main(), read_file(), c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_cube_golden_unit": "test_cube_golden_unit.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, decode(), GoldenEncoderTests, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_mute_state_console_x11": "test_mute_state_console_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_mute_state_console_x11.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 6d9948d Re-resolve X11 demo window duri…, cb2a354 Re-assert window focus in X11 c…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "medievalbattle_battle_map_courtyard": "courtyard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L284 | neighbors=[battle_map.py, sub(), X(), keep(), flagstone courtyard inside a keep (stat…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-035.json

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
