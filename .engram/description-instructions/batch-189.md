# Node Description Batch 190 of 209

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

- "src_vfx_projectile_poison_rationale_1": "VFX_Projectile_Poison: Lobbed venom glob; paired with VFX_Poison_Cloud on arriva" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Poison.py:L1 | neighbors=[VFX_Projectile_Poison.py]
- "src_vfx_projectile_poison_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Poison.py:L9 | neighbors=[VFX_Projectile_Poison.py]
- "src_vfx_shield_dome_rationale_1": "VFX_Shield_Dome: Shield dome on the caster: raise, hold, then break into fragmen" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Shield_Dome.py:L1 | neighbors=[VFX_Shield_Dome.py]
- "src_vfx_shield_dome_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Shield_Dome.py:L9 | neighbors=[VFX_Shield_Dome.py]
- "src_vfx_slash_fire_rationale_1": "VFX_Slash_Fire: Fire sword slash played on the target (melee).  Example from the" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Slash_Fire.py:L1 | neighbors=[VFX_Slash_Fire.py]
- "src_vfx_slash_fire_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Slash_Fire.py:L9 | neighbors=[VFX_Slash_Fire.py]
- "src_visual_solver_remove_body": "remove_body()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L142 | neighbors=[visual_solver.cpp]
- "state_state_round": "round()" | kind=code-symbol | source=mute/src/state/state.cpp:L14 | neighbors=[state.cpp]
- "stdlib_events_clear_phase": "clear_phase()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L33 | neighbors=[events.cpp]
- "stdlib_events_dispatch": "dispatch()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L51 | neighbors=[events.cpp]
- "stdlib_events_emit": "emit()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L42 | neighbors=[events.cpp]
- "stdlib_events_name": "name()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L99 | neighbors=[events.cpp]
- "stdlib_events_subscribe": "subscribe()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L17 | neighbors=[events.cpp]
- "stdlib_events_subscriptions": "subscriptions()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L71 | neighbors=[events.cpp]
- "stdlib_events_unsubscribe": "unsubscribe()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L25 | neighbors=[events.cpp]
- "stdlib_stdlib_collections_contains": "contains()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L61 | neighbors=[stdlib_collections.cpp]
- "stdlib_stdlib_collections_dump": "dump()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L77 | neighbors=[stdlib_collections.cpp]
- "stdlib_stdlib_collections_get": "get()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L21 | neighbors=[stdlib_collections.cpp]
- "stdlib_stdlib_collections_insert": "insert()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L49 | neighbors=[stdlib_collections.cpp]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-189.json

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
