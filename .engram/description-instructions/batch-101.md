# Node Description Batch 102 of 207

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
- "creaturelab_lab_props_rationale_1069": "round white planter with a mint band + a raised cream lip, soil, a bush in the m" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1069 | neighbors=[round_planter(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1085": "long planter box (white with a teal kick + cream coping) with a row of clipped r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1085 | neighbors=[long_planter(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1101": "plaza lamp: round foot, slim white post with a mint collar, curved arm, glass la" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1101 | neighbors=[lamp_post(), Palette] | lang=en
- "creaturelab_lab_props_rationale_111": "the Bloom Paw: rounded paw pad (soft heart-ish blob) + three leaf toes fanned ab" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L111 | neighbors=[emblem(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1116": "park bench: white cast ends with round feet, birch slats (seat + back), mint arm" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1116 | neighbors=[ext_bench(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1130": "indoor potted tree: tall white pot with a coloured band and foot, slim trunk, tw" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1130 | neighbors=[potted_tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1152": "entry monolith on the path: rounded white slab on a teal plinth, the Bloom Paw b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1152 | neighbors=[welcome_sign(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1166": "berry-juice vending machine: rounded white cabinet, coloured side panels, glass" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1166 | neighbors=[vending_machine(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1189": "plaza fountain: round two-step basin (white with a teal coping + mint water), a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1189 | neighbors=[capsule_statue(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_1211": "low path bollard: rounded white post, glowing ring band, teal cap" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1211 | neighbors=[bollard_light(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1219": "clipped hedge segment: rounded box mass with lumps, on a dark soil strip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1219 | neighbors=[hedge(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1228": "low flower clumps in a soft oval: rounded leafy mounds with 5-petal flowers on s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1228 | neighbors=[flower_bed(), Palette] | lang=en
- "creaturelab_lab_props_rationale_125": "round badge facing -Z: white disc (back face at pos), coloured rim ring, the Blo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L125 | neighbors=[emblem_badge(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1255": "lab wall shelving: steel frame, binders in rows (coloured spines, no text), samp" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1255 | neighbors=[wall_shelf_lab(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1278": "underside of the rotunda roof at radius r (same profile as rotunda_roof's inner" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1278 | neighbors=[roof_in_y(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1287": "interior architecture of the hall (no collision, the walls behind collide): pila" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1287 | neighbors=[hall_trim(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1317": "coffered ceiling hung under the dome (no collision): 16 radial ribs from the ocu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1317 | neighbors=[hall_ceiling(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-101.json

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
