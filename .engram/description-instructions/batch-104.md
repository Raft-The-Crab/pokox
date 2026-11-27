# Node Description Batch 105 of 208

Engram is running in assistant/skill mode (no API key). You are the host
assistant (Claude Code / Codex / Gemini CLI). Read the prompt below and write
your JSON answer to the answer file.

## Prompt

You are documenting nodes in a knowledge graph.
For each entry below, write ONE concise factual plain-language sentence
describing what it is or does. Use only the provided context.
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
- "creaturelab_lab_props_rationale_134": "the capture ball wherever the kit places one (was the Gem Pod): LOD by size / ca" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L134 | neighbors=[capsule(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1348": "lab wing interior trim + ceiling beams (no collision): pilasters between the win" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1348 | neighbors=[wing_trim(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1374": "clustered round leaves: n small smooth ellipsoids scattered on a shell of radius" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1374 | neighbors=[leaf_cluster(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1386": "round planter pot: style 0 = tapered white with a colour band, 1 = cylinder with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1386 | neighbors=[pot(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1398": "indoor fiddle-leaf / round-leaf fig: tapered pot, slim trunk splitting in two, t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1398 | neighbors=[fig_tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1414": "monstera in a footed pot: 7 big split leaves (heart shape with side slits) on ar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1414 | neighbors=[monstera(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1437": "tall snake plant: square pot, 11 upright sword leaves (flattened tapered blades," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1437 | neighbors=[snake_plant(), Palette] | lang=en
- "creaturelab_lab_props_rationale_145": "capsule cradle slot: steel cup, glowing ring, capsule seated (used in the heal m" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L145 | neighbors=[cradle(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1451": "hanging planter (origin = ceiling point, hangs DOWN): three cords, a round bowl," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1451 | neighbors=[hanging_planter(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_1470": "outdoor rounded park tree in the same language: smooth tapered trunk with two bo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1470 | neighbors=[round_tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1492": "small ornamental tree: smooth trunk, round canopy in soft pink (berry ramp light" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1492 | neighbors=[blossom_tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1502": "clipped hedge with a smooth rounded profile on a low white kerb, plus two topiar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1502 | neighbors=[topiary_hedge(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_1511": "smooth round shrub: soft leaf mound with clustered leaves and small 5-petal flow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1511 | neighbors=[round_bush(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1523": "low garden boundary wall: white rendered wall with a teal coping and a mint plin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1523 | neighbors=[garden_wall(), Palette] | lang=en
- "creaturelab_lab_props_rationale_153": "the Restoration Bay: plinth, white console with a tilted cradle deck of 6 capsul" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L153 | neighbors=[heal_machine(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1533": "floating lily pads (notched discs) with two pink flowers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1533 | neighbors=[lily_pads(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1563": "creature plush toy (an original critter): round body, two leaf ears, stubby paws" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1563 | neighbors=[plush(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1576": "Heal story cluster: a big creature bed with a folded + a draped blanket, a plush" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1576 | neighbors=[heal_corner(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_1611": "Shop story: stacked supply cartons (cream with coral tape and a paw stamp), an o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1611 | neighbors=[supply_boxes(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1631": "Shop story: A-frame sidewalk stand with a blank coral board (GUI spot) and a wir" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1631 | neighbors=[sale_stand(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1646": "Storage story: cable runs across the floor under rubber cable covers to three gl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1646 | neighbors=[dock_cables(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1662": "queue rope line: n steel stanchions with weighted bases, sagging coloured ropes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1662 | neighbors=[rope_line(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1674": "Trade story: wall trophy shelf (two birch boards on teal brackets) with gold cup" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1674 | neighbors=[trophy_shelf(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-104.json

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
