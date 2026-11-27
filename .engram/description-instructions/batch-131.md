# Node Description Batch 132 of 207

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

- "stdlib_stdlib_math_splitmix64": "splitmix64()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L14 | neighbors=[stdlib_math.cpp, XorShift128Plus()]
- "stdlib_stdlib_math_vec2_dot": "vec2_dot()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L59 | neighbors=[stdlib_math.cpp, vec2_length_squared()]
- "stdlib_stdlib_math_vec2_lerp": "vec2_lerp()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L58 | neighbors=[stdlib_math.cpp, det_lerp()]
- "stdlib_stdlib_math_vec3_add": "vec3_add()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L68 | neighbors=[stdlib_math.cpp, quat_rotate()]
- "stdlib_stdlib_math_vec3_cross": "vec3_cross()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L71 | neighbors=[stdlib_math.cpp, quat_rotate()]
- "stdlib_stdlib_math_vec3_dot": "vec3_dot()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L77 | neighbors=[stdlib_math.cpp, vec3_length_squared()]
- "stdlib_stdlib_math_vec3_lerp": "vec3_lerp()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L74 | neighbors=[stdlib_math.cpp, det_lerp()]
- "stdlib_stdlib_math_vec3_scale": "vec3_scale()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L70 | neighbors=[stdlib_math.cpp, quat_rotate()]
- "stdlib_stdlib_math_vec4_dot": "vec4_dot()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L88 | neighbors=[stdlib_math.cpp, vec4_normalize()]
- "stdlib_stdlib_math_xorshift128plus": "XorShift128Plus()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L137 | neighbors=[stdlib_math.cpp, splitmix64()]
- "stdlib_stdlib_physics_fixed_from_raw": "fixed_from_raw()" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L12 | neighbors=[stdlib_physics.cpp, physics_hostcall_defs()]
- "stdlib_stdlib_physics_touching_at": "touching_at()" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L24 | neighbors=[stdlib_physics.cpp, physics_raycast()]
- "stdlib_stdlib_string_concat": "concat()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L82 | neighbors=[stdlib_string.cpp, valid_utf8()]
- "stdlib_stdlib_string_to_lower_ascii": "to_lower_ascii()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L105 | neighbors=[stdlib_string.cpp, valid_utf8()]
- "sugarworks_sugar_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L53 | neighbors=[sugar_map.py, look()]
- "sugarworks_sugar_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L100 | neighbors=[sugar_map.py, sub()]
- "sugarworks_sugar_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L237 | neighbors=[sugar_map.py, sub()]
- "sugarworks_sugar_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L37 | neighbors=[sugar_map.py, place()]
- "sugarworks_sugar_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L212 | neighbors=[sugar_map.py, free()]
- "sugarworks_sugar_map_on_hard": "on_hard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L54 | neighbors=[sugar_map.py, road / sidewalks / plots / plaza / apro…]
- "sugarworks_sugar_map_rationale_50": "plot-local (lx, lz) -> world; local -Z = the plot's road side" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L50 | neighbors=[MB, local()]
- "sugarworks_sugar_map_rationale_55": "road / sidewalks / plots / plaza / apron: no scatter there" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L55 | neighbors=[MB, on_hard()]
- "sugarworks_sugar_props_candy_sacks": "candy_sacks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L380 | neighbors=[sugar_props.py, pallet with tied sugar sacks]
- "sugarworks_sugar_props_cash_pad": "cash_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L183 | neighbors=[sugar_props.py, torus()]
- "sugarworks_sugar_props_choc_bench": "choc_bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L265 | neighbors=[sugar_props.py, chocolate-bar bench: segmented seat + b…]
- "sugarworks_sugar_props_dropper": "dropper()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L106 | neighbors=[sugar_props.py, starter dropper: steel legs, lemon hopp…]
- "sugarworks_sugar_props_fence": "fence()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L71 | neighbors=[sugar_props.py, low cream wall + pink cap + team-colour…]
- "sugarworks_sugar_props_fence_post": "fence_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L81 | neighbors=[sugar_props.py, one fence post: cream pillar + pink gum…]
- "sugarworks_sugar_props_gumdrop_bush": "gumdrop_bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L241 | neighbors=[sugar_props.py, dome()]
- "sugarworks_sugar_props_hazard": "hazard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L365 | neighbors=[sugar_props.py, flat lemon/choc hazard stripe band alon…]
- "sugarworks_sugar_props_peppermint": "peppermint()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L418 | neighbors=[sugar_props.py, flat peppermint swirl stepping disc]
- "sugarworks_sugar_props_plot_base": "plot_base()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L61 | neighbors=[sugar_props.py, the plot slab: tiled concrete, pink bor…]
- "sugarworks_sugar_props_rationale_107": "starter dropper: steel legs, lemon hopper with a funnel, candy jar on top, warni" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L107 | neighbors=[Palette, dropper()]
- "sugarworks_sugar_props_rationale_132": "belt segment along X: legs, dark belt with ribs, steel side rails, lemon chevron" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L132 | neighbors=[Palette, conveyor()]
- "sugarworks_sugar_props_rationale_152": "scanner arch over the belt: two steel pillars, grape crown, glowing ring + scan" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L152 | neighbors=[Palette, upgrader()]
- "sugarworks_sugar_props_rationale_164": "chocolate melting vat: drum with cream drip rim, glowing mouth facing -X, lollip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L164 | neighbors=[Palette, collector()]
- "sugarworks_sugar_props_rationale_211": "empty build slot: four lemon corner brackets + a dashed outline, flush on the sl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L211 | neighbors=[Palette, slot_marker()]
- "sugarworks_sugar_props_rationale_252": "candy-cane street lamp: striped post, hook over -Z, hanging lantern" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L252 | neighbors=[Palette, candy_lamp()]
- "sugarworks_sugar_props_rationale_266": "chocolate-bar bench: segmented seat + back, steel legs; sit side = -Z" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L266 | neighbors=[Palette, choc_bench()]
- "sugarworks_sugar_props_rationale_294": "HERO: the Candy Exchange - drum hall with pilasters and an arched entrance (-Z)," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L294 | neighbors=[Palette, exchange()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-131.json

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
