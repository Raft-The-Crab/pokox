# Node Description Batch 107 of 209

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
- "creaturelab_lab_props_rationale_1699": "reception mat: rounded rectangle with a mint border and the Bloom Paw woven in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1699 | neighbors=[floor_mat(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1710": "round rug: three concentric bands, a scalloped edge" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1710 | neighbors=[round_rug(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_1721": "wall clock with a BLANK face (no numerals): rim ring, 12 tick dots, two hands, c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1721 | neighbors=[wall_clock(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1734": "framed poster with an abstract landscape (no text): hills, a sun disc, a little" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1734 | neighbors=[art_frame(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1750": "wall-mounted capsule display: rounded white case with a glass front, three capsu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1750 | neighbors=[wall_capsules(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1802": "a raised inlay that hugs a sphere of radius R (centre origin): poly in tangent-p" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1802 | neighbors=[sphere_decal(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1812": "one thick shell -> (outer, inner): outer cap lat 90 -> g with a bevelled rolled" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1812 | neighbors=[_shell(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1845": "the catch ball, resting on c (bottom), diameter 1.2 * s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1845 | neighbors=[catch_ball(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1913": "QA sheet prop: the four tiers in a row + an open one" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1913 | neighbors=[ball_lineup(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1923": "branching skeleton -> one smooth trunk mesh via Blender's Skin + Subdivision mod" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1923 | neighbors=[skin_mesh(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1966": "one leaf: rounded card (base, two shoulders, rounded tip) with a raised centre c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1966 | neighbors=[leaf_card(), Palette] | lang=en
- "creaturelab_lab_props_rationale_1991": "fiddle-leaf fig: tapered pot, slender Skin trunk with 3-4 branches, ~55 large gl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1991 | neighbors=[fiddle_fig(), Palette] | lang=en
- "creaturelab_lab_props_rationale_2023": "olive / ficus: footed pot, three thin stems braided round each other (twisting S" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2023 | neighbors=[olive_tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_2042": "canopy mass: dark displaced core + many leaf cards at random spots (gaussian dir" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2042 | neighbors=[leaf_mass(), Palette] | lang=en
- "creaturelab_lab_props_rationale_2069": "rounded park tree: Skin trunk (flared base, 4 roots dipping into the lawn, 3-4 l" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2069 | neighbors=[park_tree(), Palette] | lang=en
- "creaturelab_lab_props_rationale_214": "curved nurse desk (convex to the front): cream top with a rounded nose, mint fro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L214 | neighbors=[heal_counter(), Palette] | lang=en
- "creaturelab_lab_props_rationale_265": "kind 0 round flask (cork), 1 spray bottle (trigger head), 2 tall vial, 3 jar wit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L265 | neighbors=[bottle(), Palette] | lang=en
- "creaturelab_lab_props_rationale_285": "open shelving: side panels, back panel, kick base, `rows` shelf heights; crown c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L285 | neighbors=[shelf_frame(), Palette] | lang=en
- "creaturelab_lab_props_rationale_298": "medical wall cabinet: open upper shelves with flasks, spray bottles, vials, jars" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L298 | neighbors=[med_shelf(), Palette] | lang=en
- "creaturelab_lab_props_rationale_321": "waiting bench: steel loop legs, cushioned seat + back in teal, white arm rests w" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L321 | neighbors=[wait_bench(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-106.json

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
