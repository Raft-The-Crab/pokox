# Node Description Batch 139 of 207

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "towncity_town_props_rationale_76": "flat rectangular frame ring in the XY plane, centred, inner w x h, bar width t," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L76 | neighbors=[Palette, ring_frame()]
- "towncity_town_street_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L71 | neighbors=[town_street.py, park bench: cast-iron scroll ends (prof…]
- "towncity_town_street_dumpster": "dumpster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L135 | neighbors=[town_street.py, commercial dumpster: tapered body, rim,…]
- "towncity_town_street_flower_bed": "flower_bed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L232 | neighbors=[town_street.py, low stone-edged bed with a row of leaf …]
- "towncity_town_street_hydrant": "hydrant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L123 | neighbors=[town_street.py, fire hydrant: lathed red body, bonnet +…]
- "towncity_town_street_litter_bin": "litter_bin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L110 | neighbors=[town_street.py, municipal bin: base, ribbed teal body, …]
- "towncity_town_street_pallets": "pallets()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L169 | neighbors=[town_street.py, 3 stacked shipping pallets (deck boards…]
- "towncity_town_street_planter": "planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L90 | neighbors=[town_street.py, stone planter box: plinth, panelled bod…]
- "towncity_town_street_street_grate": "street_grate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L247 | neighbors=[town_street.py, the street tree pit alone (stone kerb +…]
- "towncity_town_street_street_lamp": "street_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L7 | neighbors=[town_street.py, town lantern post: two-step octagonal p…]
- "towncity_town_street_street_tree": "street_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L192 | neighbors=[town_street.py, tree: flared trunk with roots, 4 limbs,…]
- "towncity_town_street_traffic_light": "traffic_light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L43 | neighbors=[town_street.py, mast-arm signal: base + yellow pole, ar…]
- "towncity_town_street_trash_bags": "trash_bags()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L158 | neighbors=[town_street.py, heap of bin bags + two cardboard boxes]
- "towncity_town_street_wall_pipes": "wall_pipes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L179 | neighbors=[town_street.py, alley wall services (stands against a w…]
- "towncity_town_vehicles_taxi": "taxi()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L94 | neighbors=[town_vehicles.py, car()]
- "towncity_town_vehicles_track_seg": "track_seg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L194 | neighbors=[town_vehicles.py, one track segment along Z: ballast bed,…]
- "towncity_town_vehicles_train_shader": "_train_shader()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L148 | neighbors=[town_vehicles.py, train_car()]
- "transitions_build_transitions": "build_transitions.py" | kind=code-symbol | source=assets/characters/transitions/build_transitions.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, capture()]
- "transitions_v2_build_transitions": "build_transitions.py" | kind=code-symbol | source=assets/characters/transitions-v2/build_transitions.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, capture()]
- "triangle_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/RefCntAutoPtr.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, RefCntAutoPtr]
- "triangle_refcntautoptr_refcntautoptr": "RefCntAutoPtr" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/RefCntAutoPtr.hpp:L5 | neighbors=[RefCntAutoPtr.hpp, .RefCntAutoPtr()]
- "unit_action_map_test_apply_events": "apply_events()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L47 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_key": "key()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L19 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_mouse_button": "mouse_button()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L22 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_pad_axis": "pad_axis()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L31 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_pad_button": "pad_button()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L28 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_touch": "touch()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L34 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_wheel": "wheel()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L25 | neighbors=[action_map_test.cpp, main()]
- "unit_action_map_test_wheel_up": "wheel_up()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L40 | neighbors=[action_map_test.cpp, game_map()]
- "unit_asset_allocation_test": "asset_allocation_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/asset_allocation_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_asset_store_test_counting_loader": "counting_loader()" | kind=code-symbol | source=engine/resource/tests/unit/asset_store_test.cpp:L21 | neighbors=[asset_store_test.cpp, main()]
- "unit_asset_store_test_main": "main()" | kind=code-symbol | source=engine/resource/tests/unit/asset_store_test.cpp:L29 | neighbors=[asset_store_test.cpp, counting_loader()]
- "unit_bench_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L15 | neighbors=[bench_test.cpp, bench()]
- "unit_bench_test_i32": "i32()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L16 | neighbors=[bench_test.cpp, compile()]
- "unit_bench_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L88 | neighbors=[bench_test.cpp, cases()]
- "unit_bit_buffer_test": "bit_buffer_test.cpp" | kind=code-symbol | source=server/net/tests/unit/bit_buffer_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_build_tool_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/build_tool_test.cpp:L28 | neighbors=[build_tool_test.cpp, read()]
- "unit_build_tool_test_read": "read()" | kind=code-symbol | source=mute/tests/unit/build_tool_test.cpp:L18 | neighbors=[build_tool_test.cpp, main()]
- "unit_camera_test_near": "near()" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L12 | neighbors=[camera_test.cpp, main()]
- "unit_camera_test_transform": "transform()" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L13 | neighbors=[camera_test.cpp, main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-138.json

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
