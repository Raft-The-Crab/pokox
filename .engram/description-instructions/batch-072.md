# Node Description Batch 73 of 209

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
For an entity node (any other kind — e.g. a person, place, event, object),
describe what the entity is and its role, grounded in its type, its
relations (neighbors) and the provided citations/evidence — e.g.
"Lady Carfax, a wealthy heiress who disappears en route to Lausanne.".
Ground entity descriptions in the citations/evidence when present; do not
speculate beyond the context, so a node with no supporting context may be
left out of the reply.
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "input_action_map_define_action": "define_action()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L89 | neighbors=[action_map.cpp, decode(), find()] | lang=en
- "input_action_map_get16": "get16()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L28 | neighbors=[action_map.cpp, decode(), read_bytes()] | lang=en
- "input_action_map_get32": "get32()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L32 | neighbors=[action_map.cpp, decode(), read_bytes()] | lang=en
- "input_action_map_get8": "get8()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L25 | neighbors=[action_map.cpp, decode(), read_bytes()] | lang=en
- "input_action_map_hash": "hash()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L294 | neighbors=[action_map.cpp, put32(), put8()] | lang=en
- "input_action_map_put16": "put16()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L13 | neighbors=[action_map.cpp, encode(), put8()] | lang=en
- "input_action_map_sign_of": "sign_of()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L41 | neighbors=[action_map.cpp, bindings_conflict(), read_binding()] | lang=en
- "input_device_router_connect": "connect()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L14 | neighbors=[device_router.cpp, find_native(), slot_in_use()] | lang=en
- "input_input_snapshot_append": "append()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L265 | neighbors=[input_snapshot.cpp, valid_event(), decode()] | lang=en
- "input_input_snapshot_apply": "apply()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L139 | neighbors=[input_snapshot.cpp, gamepad_connected(), touch_display_connected()] | lang=en
- "input_input_snapshot_at": "at()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L273 | neighbors=[input_snapshot.cpp, next(), snapshot_hash()] | lang=en
- "input_input_snapshot_get16": "get16()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L40 | neighbors=[input_snapshot.cpp, decode(), read_bytes()] | lang=en
- "input_input_snapshot_get32": "get32()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L44 | neighbors=[input_snapshot.cpp, decode(), read_bytes()] | lang=en
- "input_input_snapshot_get64": "get64()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L50 | neighbors=[input_snapshot.cpp, decode(), read_bytes()] | lang=en
- "input_input_snapshot_get8": "get8()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L37 | neighbors=[input_snapshot.cpp, decode(), read_bytes()] | lang=en
- "integration_config_file_test_put_arr": "put_arr()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L40 | neighbors=[config_file_test.cpp, head(), test_decoder()] | lang=en
- "integration_config_file_test_put_b": "put_b()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L37 | neighbors=[config_file_test.cpp, head(), test_decoder()] | lang=en
- "integration_config_file_test_put_n": "put_n()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L35 | neighbors=[config_file_test.cpp, head(), test_decoder()] | lang=en
- "integration_config_file_test_write_file": "write_file()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L56 | neighbors=[config_file_test.cpp, test_config(), test_resolve()] | lang=en
- "integration_dependency_smoke": "dependency_smoke.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/dependency_smoke.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "integration_logging_file_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L23 | neighbors=[logging_file_test.cpp, count_stamps(), read_file()] | lang=en
- "integration_test_cube_golden_unit_decode": "decode()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L14 | neighbors=[test_cube_golden_unit.py, .test_reference_is_full_cube_with_three…, .test_roundtrip_and_multiple_deflate_bl…] | lang=en
- "integration_test_cube_light_inputs": "test_cube_light_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_light_inputs.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "integration_test_version_versionintegrationtests_test_real_binary_tracks_git_state": ".test_real_binary_tracks_git_state()" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L55 | neighbors=[VersionIntegrationTests, command(), copy_sources()] | lang=en
- "matchmaker_allocator": "allocator.hpp" | kind=code-symbol | source=server/matchmaker/include/poko/matchmaker/allocator.hpp:L1 | neighbors=[b925296 Finishes BAK tasks., Matchmaker, TicketSigner] | lang=en
- "medievalbattle_battle_map_base": "base()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L77 | neighbors=[battle_map.py, keep_w(), H()] | lang=en
- "medievalbattle_battle_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L158 | neighbors=[battle_map.py, cull_hidden(), look()] | lang=en
- "medievalbattle_battle_map_grid_mesh": "grid_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L186 | neighbors=[battle_map.py, sub(), ground()] | lang=en
- "medievalbattle_battle_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L119 | neighbors=[battle_map.py, cull_hidden(), place()] | lang=en
- "medievalbattle_battle_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L50 | neighbors=[battle_map.py, road_d(), trench_drop()] | lang=en
- "medievalbattle_battle_props_bough_skirt": "bough_skirt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1452 | neighbors=[battle_props.py, pine(), one fir whorl: a star skirt (2n rim poi…] | lang=en
- "medievalbattle_battle_props_h01": "h01()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L99 | neighbors=[battle_props.py, bridge_tower(), voussoirs()] | lang=en
- "medievalbattle_battle_props_hay_bales": "hay_bales()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1289 | neighbors=[battle_props.py, T(), stacked straw bales with twine bands an…] | lang=en
- "medievalbattle_battle_props_plinth_band": "plinth_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L260 | neighbors=[battle_props.py, curtain_wall(), T()] | lang=en
- "medievalbattle_battle_props_rationale_1020": "dressed round trebuchet shot: smooth lathe sphere, slightly irregular" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1020 | neighbors=[shot_stone(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1026": "trebuchet shot: round stones stacked on a plank pallet" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1026 | neighbors=[ammo_pile(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_104": "running-bond ashlar panel in the XY plane facing +Z: x -w/2..w/2, y 0..h. Each b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L104 | neighbors=[ashlar(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1040": "tapered timber assault tower on six solid wheels: cladding planks under nailed h" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1040 | neighbors=[siege_tower(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1100": "wheeled ram shed: post frame, gable roof of planks under overlapping hides, iron" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1100 | neighbors=[battering_ram(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1132": "wheeled oak pavise: planks with a cut sight slit, iron bands, painted team chevr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1132 | neighbors=[mantlet(), Palette, Sh] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-072.json

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
