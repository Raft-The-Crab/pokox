# Node Description Batch 36 of 207

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

- "fishcenter_fish_props_rod": "rod()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L647 | neighbors=[fish_props.py, motor_boat(), fishing rod: cork grip, rod blank, guid…, rod_rack(), rod_shop()]
- "fishcenter_fish_props_rod_rack": "rod_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L657 | neighbors=[fish_props.py, A-frame rod rack: bamboo frame, slotted…, lash(), pole(), rod()]
- "fishcenter_fish_props_sea_stack": "sea_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L494 | neighbors=[fish_props.py, tall volcanic sea stack: stacked tilted…, lerp(), _merge_prop(), palm()]
- "fishcenter_fish_props_thatch_band": "thatch_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L130 | neighbors=[fish_props.py, one layer of thatch: outer surface from…, loft(), thatch_cone(), thatch_hip()]
- "fishcenter_fish_props_thatch_gable": "thatch_gable()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L958 | neighbors=[fish_props.py, boat_house(), steep A-frame thatch: ridge along Z, ea…, lash(), lerp()]
- "fishcenter_fish_props_woven_wall": "woven_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L200 | neighbors=[fish_props.py, hut_body(), wall panel L long, H high (local x -L/2…, local(), mat_cell()]
- "foundation_duration_query_state": "duration_query_state.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/duration_query_state.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, begin(), DurationQueryState, end(), poll()]
- "frostpeak_frost_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L18 | neighbors=[frost_map.py, ground(), horizon(), place(), square()]
- "gles_clear_pokoactivity": "PokoActivity.java" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Activity, PokoActivity, SurfaceHolder, SurfaceView]
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
- "integration_test_mute_state_console_x11": "test_mute_state_console_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_mute_state_console_x11.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 6d9948d Re-resolve X11 demo window duri…, c7a411f Fix MUT-01-20 audit defects in …, cb2a354 Re-assert window focus in X11 c…, main()]
- "integration_test_triangle_x11_visual": "test_triangle_x11_visual.py" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_x11_visual.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, find_window(), green(), pixel(), red()]
- "integration_x11_demo_smoke": "x11_demo_smoke.py" | kind=code-symbol | source=engine/platform/tests/integration/x11_demo_smoke.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, ClientData, ClientMessage, XEvent, Optional Linux/X11 host smoke test; not…]
- "math_deterministic_math": "deterministic_math.cpp" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, calculate(), deterministic_cos(), deterministic_sin(), supported()]
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
