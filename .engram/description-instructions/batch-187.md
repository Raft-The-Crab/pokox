# Node Description Batch 188 of 207

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
Write every description in Portuguese (pt). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "stdlib_stdlib_collections_key_less": "key_less()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L16 | neighbors=[stdlib_collections.cpp]
- "stdlib_stdlib_collections_name": "name()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L104 | neighbors=[stdlib_collections.cpp]
- "stdlib_stdlib_collections_set": "set()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L25 | neighbors=[stdlib_collections.cpp]
- "stdlib_stdlib_crypto_crypto_hostcall_defs": "crypto_hostcall_defs()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L141 | neighbors=[stdlib_crypto.cpp]
- "stdlib_stdlib_crypto_from_hex": "from_hex()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L123 | neighbors=[stdlib_crypto.cpp]
- "stdlib_stdlib_crypto_to_hex": "to_hex()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L112 | neighbors=[stdlib_crypto.cpp]
- "stdlib_stdlib_math_advance": "advance()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L168 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_det_clamp": "det_clamp()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L26 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_det_floor": "det_floor()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L24 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_det_pow": "det_pow()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L38 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_det_round": "det_round()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L25 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_from_state": "from_state()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L157 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_mat4_identity": "mat4_identity()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L96 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_mat4_multiply": "mat4_multiply()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L97 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_mat4_transform_point": "mat4_transform_point()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L108 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_quat_multiply": "quat_multiply()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L121 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_simclock": "SimClock()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L165 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_time_hostcall_defs": "time_hostcall_defs()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L170 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_vec2_add": "vec2_add()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L55 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_vec2_scale": "vec2_scale()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L57 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_vec2_sub": "vec2_sub()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L56 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_vec3_sub": "vec3_sub()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L69 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_vec4_add": "vec4_add()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L86 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_math_vec4_scale": "vec4_scale()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L87 | neighbors=[stdlib_math.cpp]
- "stdlib_stdlib_string_byte_length": "byte_length()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L56 | neighbors=[stdlib_string.cpp]
- "stdlib_stdlib_string_compare_bytes": "compare_bytes()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L92 | neighbors=[stdlib_string.cpp]
- "stdlib_stdlib_string_find_bytes": "find_bytes()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L98 | neighbors=[stdlib_string.cpp]
- "stdlib_stdlib_string_name": "name()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L113 | neighbors=[stdlib_string.cpp]
- "sugarworks_sugar_kit_sheet_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_kit_sheet.py:L44 | neighbors=[sugar_kit_sheet.py]
- "sugarworks_sugar_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L33 | neighbors=[sugar_map.py]
- "sugarworks_sugar_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L252 | neighbors=[sugar_map.py]
- "sugarworks_sugar_props_candy_corn": "candy_corn()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L408 | neighbors=[sugar_props.py]
- "sugarworks_sugar_props_candy_crate": "candy_crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L276 | neighbors=[sugar_props.py]
- "sugarworks_sugar_props_rationale_193": "button on a squat base with a price board on a post behind it (board faces -Z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L193 | neighbors=[buy_button()]
- "sugarworks_sugar_props_rock_cliff": "rock_cliff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L349 | neighbors=[sugar_props.py]
- "systematic_debugging_condition_based_waiting_example_waitforevent": "waitForEvent()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L20 | neighbors=[condition-based-waiting-example.ts]
- "systematic_debugging_condition_based_waiting_example_waitforeventcount": "waitForEventCount()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L60 | neighbors=[condition-based-waiting-example.ts]
- "systematic_debugging_condition_based_waiting_example_waitforeventmatch": "waitForEventMatch()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L111 | neighbors=[condition-based-waiting-example.ts]
- "targets_android_std_shim_bit_cast": "bit_cast()" | kind=code-symbol | source=tools/targets/android_std_shim.hpp:L20 | neighbors=[android_std_shim.hpp]
- "targets_android_std_shim_from_chars": "from_chars()" | kind=code-symbol | source=tools/targets/android_std_shim.hpp:L33 | neighbors=[android_std_shim.hpp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-187.json

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
