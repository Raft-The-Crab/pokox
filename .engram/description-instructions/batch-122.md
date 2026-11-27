# Node Description Batch 123 of 208

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

- "petsim_pet_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L149 | neighbors=[pet_map.py, place_soft()] | lang=en
- "petsim_pet_props_arc_pts": "arc_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L113 | neighbors=[pet_props.py, trade_pad()] | lang=en
- "petsim_pet_props_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L910 | neighbors=[pet_props.py, hooked cane, red / cream diagonal strip…] | lang=en
- "petsim_pet_props_disc_up": "disc_up()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L124 | neighbors=[pet_props.py, rcyl()] | lang=en
- "petsim_pet_props_egg_r": "egg_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L147 | neighbors=[pet_props.py, egg_prof()] | lang=en
- "petsim_pet_props_lift": "lift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L136 | neighbors=[pet_props.py, egg()] | lang=en
- "petsim_pet_props_mascot_test": "mascot_test()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1061 | neighbors=[pet_props.py, puffpaw()] | lang=en
- "petsim_pet_props_rationale_1006": "chunky rail fence segment from x = 0 to x = L: one fat post with a ball cap at x" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1006 | neighbors=[fence(), Palette] | lang=en
- "petsim_pet_props_rationale_1022": "chibi lamp: bulgy base, slim post with a candy ring, round glowing lantern under" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1022 | neighbors=[lamp_post(), Palette] | lang=en
- "petsim_pet_props_rationale_1033": "chubby rounded bench: two soft seat slats + back slat on stubby round legs. Fron" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1033 | neighbors=[bench(), Palette] | lang=en
- "petsim_pet_props_rationale_1044": "frame cloud floating on the lagoon: 4-6 overlapping puffs merged, flat bottom" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1044 | neighbors=[cloud(), Palette] | lang=en
- "petsim_pet_props_rationale_120": "a chunky star standing upright facing -Z, centred at the origin, rounded front e" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L120 | neighbors=[star(), Palette] | lang=en
- "petsim_pet_props_rationale_128": "paw-print icon: palm pad + 4 toe beans, built flat then stood up facing -Z (pitc" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L128 | neighbors=[paw(), Palette] | lang=en
- "petsim_pet_props_rationale_155": "smooth lathe egg + decoration: 'spots', 'stars', 'zig', 'swirl', 'gems', 'flower" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L155 | neighbors=[egg(), Palette] | lang=en
- "petsim_pet_props_rationale_204": "the mascot: chubby sitting creature, huge head, tall round ears, big eyes with h" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L204 | neighbors=[puffpaw(), Palette] | lang=en
- "petsim_pet_props_rationale_272": "hub hero: 3-tier pastel fountain (scalloped basin, water, mid bowl with a pale w" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L272 | neighbors=[pet_fountain(), Palette] | lang=en
- "petsim_pet_props_rationale_324": "the Puffpaw statue + its quilted cushion: a separate MeshPart sharing the founta" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L324 | neighbors=[pet_statue(), Palette] | lang=en
- "petsim_pet_props_rationale_336": "6 chunky pastel bands on a half circle, standing on two big cloud feet, sparkle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L336 | neighbors=[rainbow_arch(), Palette] | lang=pt
- "petsim_pet_props_rationale_358": "open-front kiosk: round dais, curved back wall with toy shelves, 4 chubby pillar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L358 | neighbors=[pet_shop(), Palette] | lang=en
- "petsim_pet_props_rationale_452": "giant gumball machine: rounded red drum base (coin plate, glowing up-chevron, ch" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L452 | neighbors=[upgrade_machine(), Palette] | lang=en
- "petsim_pet_props_rationale_487": "round trade table with a big scalloped two-tone umbrella and two chubby stools." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L487 | neighbors=[trade_booth(), Palette] | lang=en
- "petsim_pet_props_rationale_52": "height gradient a->b between y0..y1 plus a lit side toward SUN (needs the shape" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L52 | neighbors=[soft(), Palette] | lang=es
- "petsim_pet_props_rationale_520": "flat trade circle: cream disc with a pastel rim and two glowing curved swap arro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L520 | neighbors=[trade_pad(), Palette] | lang=en
- "petsim_pet_props_rationale_535": "blank board in a chunky rounded frame on two candy posts, a crown icon on top. F" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L535 | neighbors=[leaderboard(), Palette] | lang=pt
- "petsim_pet_props_rationale_567": "fluted cake pedestal with a glowing ring under a giant decorated egg; 3 little s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L567 | neighbors=[egg_stand(), Palette] | lang=pt
- "petsim_pet_props_rationale_585": "toll arch: two chubby stacked pillars with paw-ball finials, a rounded arch beam" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L585 | neighbors=[zone_gate(), Palette] | lang=en
- "petsim_pet_props_rationale_619": "round spawn dais: two soft tiers, mint rim, a big paw-print inlay. Walkable (pre" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L619 | neighbors=[spawn_pad(), Palette] | lang=pt
- "petsim_pet_props_rationale_628": "humped chunky bridge along -Z (start z = 0 .. end z = -L), deck rises by `rise`;" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L628 | neighbors=[bridge(), Palette] | lang=en
- "petsim_pet_props_rationale_669": "low gold mound with a short coin stack and loose coins leaning on it" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L669 | neighbors=[coin_pile(), Palette] | lang=en
- "petsim_pet_props_rationale_683": "rounded treasure chest: plank body, domed lid, metal bands + lock (gold = tier 3" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L683 | neighbors=[chest(), Palette] | lang=en
- "petsim_pet_props_rationale_703": "chubby present: soft box, crossing ribbon bands, a two-loop bow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L703 | neighbors=[gift_box(), Palette] | lang=pt
- "petsim_pet_props_rationale_71": "soft cloud / crown: a sphere pushed out by smooth lobes, flattened underneath (s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L71 | neighbors=[puff(), Palette] | lang=en
- "petsim_pet_props_rationale_730": "chibi puffball crown: a core ball + n round bubbles on a fibonacci spiral over i" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L730 | neighbors=[bubble_crown(), Palette] | lang=pt
- "petsim_pet_props_rationale_743": "lollipop / puffball tree: curved tapered trunk with a root flare, one big smooth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L743 | neighbors=[puff_tree(), Palette] | lang=en
- "petsim_pet_props_rationale_756": "candy tree: candy-striped trunk (stripe faces alternate), two-tone cotton-candy" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L756 | neighbors=[cotton_tree(), Palette] | lang=en
- "petsim_pet_props_rationale_778": "dream tree: pale twisty trunk, lilac puff crown with glowing crystal points poki" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L778 | neighbors=[crystal_tree(), Palette] | lang=en
- "petsim_pet_props_rationale_810": "5-7 chibi daisies: thin stem, leaf, scalloped petal disc, round centre" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L810 | neighbors=[flower_patch(), Palette] | lang=en
- "petsim_pet_props_rationale_838": "chubby toadstool: bulgy stem, domed cap with white spots, ring skirt" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L838 | neighbors=[mushroom(), Palette] | lang=en
- "petsim_pet_props_rationale_855": "checkered blanket (cells alternate red / cream), a wicker basket with a handle," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L855 | neighbors=[picnic_set(), Palette] | lang=pt
- "petsim_pet_props_rationale_893": "giant swirl lollipop: two interleaved coiled candy ropes (pink + cream) form the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L893 | neighbors=[lollipop(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-122.json

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
