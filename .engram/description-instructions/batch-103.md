# Node Description Batch 104 of 208

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

- "cavemap_cave_props3_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L297 | neighbors=[cave_props3.py, spawn platform: layered round stone pli…] | lang=en
- "cavemap_grid": "grid.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/grid.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "cavemap_post": "post.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/post.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "clothing_test_append_actions": "test_append_actions.py" | kind=code-symbol | source=assets/characters/clothing/test_append_actions.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "clothing_validate_looks": "validate_looks.py" | kind=code-symbol | source=assets/characters/clothing/validate_looks.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "console_console_decode_string": "decode_string()" | kind=code-symbol | source=mute/src/console/console.cpp:L52 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "console_console_decode_utf8": "decode_utf8()" | kind=code-symbol | source=mute/src/console/console.cpp:L125 | neighbors=[console.cpp, append()] | lang=en
- "console_console_execute_console": "execute_console()" | kind=code-symbol | source=mute/src/console/console.cpp:L115 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "console_console_execute_console_stateful": "execute_console_stateful()" | kind=code-symbol | source=mute/src/console/console.cpp:L116 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "console_console_is_format_control": "is_format_control()" | kind=code-symbol | source=mute/src/console/console.cpp:L147 | neighbors=[console.cpp, append()] | lang=en
- "console_console_rebased": "rebased()" | kind=code-symbol | source=mute/src/console/console.cpp:L20 | neighbors=[console.cpp, numeric()] | lang=en
- "console_console_spelling": "spelling()" | kind=code-symbol | source=mute/src/console/console.cpp:L47 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "creaturelab_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "creaturelab_lab_map_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L399 | neighbors=[lab_map.py, garden_paths()] | lang=en
- "creaturelab_lab_map_ceil_y": "ceil_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L276 | neighbors=[lab_map.py, underside of the rotunda roof at radius…] | lang=en
- "creaturelab_lab_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L54 | neighbors=[lab_map.py, place()] | lang=en
- "creaturelab_lab_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L73 | neighbors=[lab_map.py, exterior()] | lang=en
- "creaturelab_lab_map_in_wing": "in_wing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L145 | neighbors=[lab_map.py, wing_floor()] | lang=en
- "creaturelab_lab_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L49 | neighbors=[lab_map.py, place()] | lang=en
- "creaturelab_lab_map_near_poly": "near_poly()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L408 | neighbors=[lab_map.py, path_free()] | lang=en
- "creaturelab_lab_map_rationale_119": "hall floor: slab, cream polar tiles, a teal ring band at r 30, a mint band round" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L119 | neighbors=[hall_floor(), MB] | lang=pt
- "creaturelab_lab_map_rationale_152": "lab wing floor: slab, 3-stud square tiles (white / cream checker), a mint border" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L152 | neighbors=[wing_floor(), MB] | lang=pt
- "creaturelab_lab_map_rationale_185": "forecourt terrace (half disc in front of the facade, radial pavers, white kerb +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L185 | neighbors=[hardscape(), MB] | lang=en
- "creaturelab_lab_map_rationale_239": "lawn grid: 3-stud cells near the building, coarse to the hills; holes under the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L239 | neighbors=[ground(), MB] | lang=en
- "creaturelab_lab_map_rationale_277": "underside of the rotunda roof at radius r (matches rotunda_roof's inner profile," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L277 | neighbors=[ceil_y(), MB] | lang=en
- "creaturelab_lab_map_rationale_417": "curving garden paths (ribbon pavers with mint edging) round the building, to the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L417 | neighbors=[garden_paths(), MB] | lang=en
- "creaturelab_lab_map_rationale_438": "pond: water disc (Glass) over the carved dish, a ring of smooth rim stones half" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L438 | neighbors=[pond(), MB] | lang=en
- "creaturelab_lab_map_rationale_455": "distant scenery: soft rounded hills in two layers beyond the lawn (cooler + ligh" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L455 | neighbors=[horizon(), MB] | lang=en
- "creaturelab_lab_map_rationale_96": "flat tiles in rings r0..r1 (ring width dr, tile length ~dl along the ring), each" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L96 | neighbors=[polar_tiles(), MB] | lang=en
- "creaturelab_lab_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L74 | neighbors=[lab_map.py, exterior()] | lang=en
- "creaturelab_lab_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L637 | neighbors=[lab_map.py, set_roof()] | lang=en
- "creaturelab_lab_props_ball_sh": "_ball_sh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1829 | neighbors=[lab_props.py, catch_ball()] | lang=en
- "creaturelab_lab_props_blossom_park": "blossom_park()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2097 | neighbors=[lab_props.py, park_tree()] | lang=en
- "creaturelab_lab_props_catch_ball_prop": "catch_ball_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1907 | neighbors=[lab_props.py, catch_ball()] | lang=en
- "creaturelab_lab_props_clump": "clump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1957 | neighbors=[lab_props.py, leaf_mass()] | lang=en
- "creaturelab_lab_props_gap": "_gap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1283 | neighbors=[lab_props.py, hall_trim()] | lang=en
- "creaturelab_lab_props_rationale_101": "lens-shaped leaf: length L along direction a (deg from +up, clockwise = +x), hal" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L101 | neighbors=[leaf_poly(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1011": "curved canopy over the entrance (front = -Z = outward when placed facing south):" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1011 | neighbors=[entrance_canopy(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1039": "rounded park tree: flared birch trunk splitting into two boughs, three-lobed chu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1039 | neighbors=[tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1056": "rounded bush with a few flower clusters (5-petal stars) on its top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1056 | neighbors=[bush(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-103.json

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
