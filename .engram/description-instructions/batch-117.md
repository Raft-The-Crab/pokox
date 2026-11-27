# Node Description Batch 118 of 209

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

- "imgui_refcntautoptr_refcntautoptr": "RefCntAutoPtr" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/RefCntAutoPtr.hpp:L7 | neighbors=[RefCntAutoPtr.hpp, .RefCntAutoPtr()]
- "input_action_map_bindings": "bindings()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L154 | neighbors=[action_map.cpp, find()]
- "input_action_map_clamp_i32": "clamp_i32()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L42 | neighbors=[action_map.cpp, read_binding()]
- "input_action_map_clear_bindings": "clear_bindings()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L143 | neighbors=[action_map.cpp, find()]
- "input_action_map_conflicts": "conflicts()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L160 | neighbors=[action_map.cpp, bindings_conflict()]
- "input_action_map_contains": "contains()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L150 | neighbors=[action_map.cpp, find()]
- "input_action_map_held": "held()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L277 | neighbors=[action_map.cpp, find()]
- "input_action_map_is_axis_device": "is_axis_device()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L38 | neighbors=[action_map.cpp, bindings_conflict()]
- "input_action_map_pressed": "pressed()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L281 | neighbors=[action_map.cpp, find()]
- "input_action_map_read_digital": "read_digital()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L233 | neighbors=[action_map.cpp, read_binding()]
- "input_action_map_released": "released()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L285 | neighbors=[action_map.cpp, find()]
- "input_action_map_remove_action": "remove_action()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L98 | neighbors=[action_map.cpp, find()]
- "input_action_map_sample": "sample()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L312 | neighbors=[action_map.cpp, read_binding()]
- "input_action_map_value": "value()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L289 | neighbors=[action_map.cpp, find()]
- "input_device_router_find_native": "find_native()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L75 | neighbors=[device_router.cpp, connect()]
- "input_device_router_route_count": "route_count()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L84 | neighbors=[device_router.cpp, routes()]
- "input_device_router_routes": "routes()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L90 | neighbors=[device_router.cpp, route_count()]
- "input_device_router_slot_in_use": "slot_in_use()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L8 | neighbors=[device_router.cpp, connect()]
- "input_input_snapshot_gamepad_axis_value": "gamepad_axis_value()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L113 | neighbors=[input_snapshot.cpp, gamepad_connected()]
- "input_input_snapshot_gamepad_button_down": "gamepad_button_down()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L106 | neighbors=[input_snapshot.cpp, gamepad_connected()]
- "input_input_snapshot_next": "next()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L332 | neighbors=[input_snapshot.cpp, at()]
- "input_input_snapshot_touch_down": "touch_down()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L123 | neighbors=[input_snapshot.cpp, touch_display_connected()]
- "input_input_snapshot_touch_position": "touch_position()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L130 | neighbors=[input_snapshot.cpp, touch_display_connected()]
- "input_input_snapshot_valid_event": "valid_event()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L56 | neighbors=[input_snapshot.cpp, append()]
- "integration_config_file_test_put_double": "put_double()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L50 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_file_test_put_float": "put_float()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L45 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_file_test_put_half": "put_half()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L42 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_config_file_test_put_null": "put_null()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L39 | neighbors=[config_file_test.cpp, test_decoder()]
- "integration_cube_golden_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L222 | neighbors=[cube_golden.py, run()]
- "integration_cube_golden_png_chunk": "png_chunk()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L26 | neighbors=[cube_golden.py, canonical_png()]
- "integration_cube_golden_x11_capture": ".capture()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L108 | neighbors=[run(), X11]
- "integration_cube_golden_x11_close": ".close()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L83 | neighbors=[run(), X11]
- "integration_cube_golden_x11_find_window": ".find_window()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L86 | neighbors=[run(), X11]
- "integration_logging_file_test_count_stamps": "count_stamps()" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L15 | neighbors=[logging_file_test.cpp, main()]
- "integration_logging_file_test_read_file": "read_file()" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L11 | neighbors=[logging_file_test.cpp, main()]
- "integration_test_cube_golden_unit_goldenencodertests_test_reference_is_full_cube_with_three_lit_faces": ".test_reference_is_full_cube_with_three_lit_faces()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L101 | neighbors=[GoldenEncoderTests, decode()]
- "integration_test_cube_golden_unit_goldenencodertests_test_roundtrip_and_multiple_deflate_blocks": ".test_roundtrip_and_multiple_deflate_blocks()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L51 | neighbors=[GoldenEncoderTests, decode()]
- "integration_test_cube_x11_smoke_find_window": "find_window()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_x11_smoke.py:L17 | neighbors=[test_cube_x11_smoke.py, main()]
- "integration_test_cube_x11_smoke_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_x11_smoke.py:L31 | neighbors=[test_cube_x11_smoke.py, find_window()]
- "integration_test_imgui_toggle_x11_find_window": "find_window()" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_toggle_x11.py:L16 | neighbors=[test_imgui_toggle_x11.py, main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-117.json

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
