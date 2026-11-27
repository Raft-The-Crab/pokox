# Node Description Batch 106 of 208

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
- "creaturelab_lab_props_rationale_340": "mart counter: white body, coral front panels, glass display case on the customer" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L340 | neighbors=[shop_counter(), Palette] | lang=en
- "creaturelab_lab_props_rationale_376": "capsule gondola: four shelves of stepped display risers, one tier per shelf (min" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L376 | neighbors=[capsule_shelf(), Palette] | lang=en
- "creaturelab_lab_props_rationale_392": "potion shelf: flasks, spray tonics, vials and berry jars in four colour runs, cr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L392 | neighbors=[potion_shelf(), Palette] | lang=en
- "creaturelab_lab_props_rationale_406": "tiered birch crate stand with three woven baskets heaped with berries (pink, gol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L406 | neighbors=[berry_baskets(), Palette] | lang=en
- "creaturelab_lab_props_rationale_423": "round three-tier display rack: steel pole, coral discs, boxed capsules on each t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L423 | neighbors=[display_rack(), Palette] | lang=en
- "creaturelab_lab_props_rationale_443": "storage terminal: rounded pedestal, angled neck, big framed screen (blank glow)," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L443 | neighbors=[pc_terminal(), Palette] | lang=en
- "creaturelab_lab_props_rationale_482": "trade / battle registration desk: white desk with sky panels, a raised arch with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L482 | neighbors=[trade_desk(), Palette] | lang=en
- "creaturelab_lab_props_rationale_524": "specimen tank: steel base drum with a teal band + front control panel, glass cyl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L524 | neighbors=[specimen_tank(), Palette] | lang=en
- "creaturelab_lab_props_rationale_554": "HERO: the Bloom Chamber (evolution / scan chamber). Two-step round dais with tea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L554 | neighbors=[evo_chamber(), Palette] | lang=en
- "creaturelab_lab_props_rationale_56": "rounded box (bevel with `seg` segments); r clamped to the smallest half size" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L56 | neighbors=[rbox(), Palette] | lang=en
- "creaturelab_lab_props_rationale_621": "lab table: white top with a teal edge, steel legs with feet, a stretcher, cream" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L621 | neighbors=[lab_table(), Palette] | lang=en
- "creaturelab_lab_props_rationale_637": "lab workbench: table + test-tube rack with coloured tubes, conical + round flask" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L637 | neighbors=[workbench(), Palette] | lang=en
- "creaturelab_lab_props_rationale_669": "small lab table with a modelled microscope (base, curved arm, stage with clips," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L669 | neighbors=[microscope_bench(), Palette] | lang=en
- "creaturelab_lab_props_rationale_69": "solid annular sector: radii r0..r1, heights y0..y1, angles a0..a1 (deg; x = cos," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L69 | neighbors=[ring_seg(), Palette] | lang=en
- "creaturelab_lab_props_rationale_692": "rolling whiteboard: two T legs on casters, aluminium frame, blank board, marker" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L692 | neighbors=[whiteboard(), Palette] | lang=en
- "creaturelab_lab_props_rationale_716": "starter-capsule table: round white pedestal table with a teal apron, three cushi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L716 | neighbors=[starter_table(), Palette] | lang=en
- "creaturelab_lab_props_rationale_754": "pendant lamp hung from the ceiling (origin = the ceiling point, hangs DOWN to -d" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L754 | neighbors=[pendant_lamp(), Palette] | lang=en
- "creaturelab_lab_props_rationale_766": "little rest area for recovering creatures: oval rug, two round cushion beds (tea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L766 | neighbors=[rest_nook(), Palette] | lang=en
- "creaturelab_lab_props_rationale_797": "curved wall from angle a0..a1 split into cells; holes = [(ha0, ha1, hy0, hy1)] s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L797 | neighbors=[arc_wall(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_808": "HERO shell: the care hall. Ring wall (inner r 44) with a curved glass facade rou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L808 | neighbors=[rotunda(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-105.json

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
