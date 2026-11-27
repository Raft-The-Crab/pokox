# Node Description Batch 71 of 208

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

- "hermes_test_plugin_testlayoutresolution_test_flat_layout_resolves_nested_skills": ".test_flat_layout_resolves_nested_skills()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L148 | neighbors=[TestLayoutResolution, ._load_from(), ._stage()]
- "identity_sign_in_accountstore": "AccountStore" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L20 | neighbors=[sign_in.hpp, .AccountStore(), InMemoryAccountStore]
- "identity_velocity": "velocity.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/velocity.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, haversine_km(), LoginVelocityService]
- "imgui_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/RefCntAutoPtr.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, RefCntAutoPtr, c7a411f Fix MUT-01-20 audit defects in …]
- "input_action_map_define_action": "define_action()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L89 | neighbors=[action_map.cpp, decode(), find()]
- "input_action_map_get16": "get16()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L28 | neighbors=[action_map.cpp, decode(), read_bytes()]
- "input_action_map_get32": "get32()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L32 | neighbors=[action_map.cpp, decode(), read_bytes()]
- "input_action_map_get8": "get8()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L25 | neighbors=[action_map.cpp, decode(), read_bytes()]
- "input_action_map_hash": "hash()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L294 | neighbors=[action_map.cpp, put32(), put8()]
- "input_action_map_put16": "put16()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L13 | neighbors=[action_map.cpp, encode(), put8()]
- "input_action_map_sign_of": "sign_of()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L41 | neighbors=[action_map.cpp, bindings_conflict(), read_binding()]
- "input_device_router_connect": "connect()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L14 | neighbors=[device_router.cpp, find_native(), slot_in_use()]
- "input_input_snapshot_append": "append()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L265 | neighbors=[input_snapshot.cpp, valid_event(), decode()]
- "input_input_snapshot_apply": "apply()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L139 | neighbors=[input_snapshot.cpp, gamepad_connected(), touch_display_connected()]
- "input_input_snapshot_at": "at()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L273 | neighbors=[input_snapshot.cpp, next(), snapshot_hash()]
- "input_input_snapshot_get16": "get16()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L40 | neighbors=[input_snapshot.cpp, decode(), read_bytes()]
- "input_input_snapshot_get32": "get32()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L44 | neighbors=[input_snapshot.cpp, decode(), read_bytes()]
- "input_input_snapshot_get64": "get64()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L50 | neighbors=[input_snapshot.cpp, decode(), read_bytes()]
- "input_input_snapshot_get8": "get8()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L37 | neighbors=[input_snapshot.cpp, decode(), read_bytes()]
- "integration_config_file_test_put_arr": "put_arr()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L40 | neighbors=[config_file_test.cpp, head(), test_decoder()]
- "integration_config_file_test_put_b": "put_b()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L37 | neighbors=[config_file_test.cpp, head(), test_decoder()]
- "integration_config_file_test_put_n": "put_n()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L35 | neighbors=[config_file_test.cpp, head(), test_decoder()]
- "integration_config_file_test_write_file": "write_file()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L56 | neighbors=[config_file_test.cpp, test_config(), test_resolve()]
- "integration_config_logging_guard_real_test": "config_logging_guard_real_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/config_logging_guard_real_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "integration_logging_file_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L23 | neighbors=[logging_file_test.cpp, count_stamps(), read_file()]
- "integration_public_header_compat": "public_header_compat.cpp" | kind=code-symbol | source=engine/rhi/tests/integration/public_header_compat.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "integration_sdl_platform_test": "sdl_platform_test.cpp" | kind=code-symbol | source=engine/platform/tests/integration/sdl_platform_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_cube_fixed_view_x11": "test_cube_fixed_view_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_fixed_view_x11.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_cube_golden_unit_decode": "decode()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L14 | neighbors=[test_cube_golden_unit.py, .test_reference_is_full_cube_with_three…, .test_roundtrip_and_multiple_deflate_bl…]
- "integration_test_directional_light_x11": "test_directional_light_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_directional_light_x11.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_imgui_inputs": "test_imgui_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_inputs.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Check the real ImGui demo rejects bad S…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_triangle_inputs": "test_triangle_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_inputs.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Check the real demo rejects bad SPIR-V …, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_version_versionintegrationtests_test_real_binary_tracks_git_state": ".test_real_binary_tracks_git_state()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L55 | neighbors=[VersionIntegrationTests, command(), copy_sources()]
- "lexer_unicode_xid": "unicode_xid.hpp" | kind=code-symbol | source=mute/src/lexer/unicode_xid.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, contains(), c7a411f Fix MUT-01-20 audit defects in …]
- "medievalbattle_battle_map_base": "base()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L77 | neighbors=[battle_map.py, keep_w(), H()]
- "medievalbattle_battle_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L158 | neighbors=[battle_map.py, cull_hidden(), look()]
- "medievalbattle_battle_map_grid_mesh": "grid_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L186 | neighbors=[battle_map.py, sub(), ground()]
- "medievalbattle_battle_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L119 | neighbors=[battle_map.py, cull_hidden(), place()]
- "medievalbattle_battle_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L50 | neighbors=[battle_map.py, road_d(), trench_drop()]
- "medievalbattle_battle_props_bough_skirt": "bough_skirt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1452 | neighbors=[battle_props.py, pine(), one fir whorl: a star skirt (2n rim poi…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-070.json

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
