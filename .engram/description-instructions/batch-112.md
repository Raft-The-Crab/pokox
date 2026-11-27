# Node Description Batch 113 of 208

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

- "fishcenter_fish_map_rationale_101": "auto-grounded props (y None) are fitted against everything built so far (see fit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L101 | neighbors=[place(), MB] | lang=en
- "fishcenter_fish_map_rationale_203": "plank / slab from a top quad [(x, z) x4] at height y, thickness th" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L203 | neighbors=[prism(), MB] | lang=en
- "fishcenter_fish_map_rationale_229": "plank deck in a pad-local frame: planks along local x (across the walk), gaps, t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L229 | neighbors=[deck_rect(), MB] | lang=en
- "fishcenter_fish_map_rationale_251": "the ring boardwalk: radial planks (across the walk), stringers along both edges" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L251 | neighbors=[ring_deck(), MB] | lang=en
- "fishcenter_fish_map_rationale_270": "central coral-stone platform: polar flagstones (inset), coping course, ashlar fo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L270 | neighbors=[platform(), MB] | lang=en
- "fishcenter_fish_map_rationale_300": "compass-rose inlay in the spawn plaza deck: 8-point star of teal / yellow planks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L300 | neighbors=[compass(), MB] | lang=en
- "fishcenter_fish_map_rationale_340": "seabed + islets in one grid: fine inside the reef, coarse to the horizon; colour" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L340 | neighbors=[ground(), MB] | lang=en
- "fishcenter_fish_map_rationale_377": "organic grass mounds sitting IN each islet top: irregular rounded outline, rim t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L377 | neighbors=[islet_grass(), MB] | lang=en
- "fishcenter_fish_map_rationale_38": "pad-local (lx tangential, lz radial outward from the pad centre rc) -> world (x," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L38 | neighbors=[lp(), MB] | lang=en
- "fishcenter_fish_map_rationale_410": "tropical volcanic islands in 3 overlapping depth layers. Each = a wide sand / ro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L410 | neighbors=[horizon(), MB] | lang=en
- "fishcenter_fish_map_rationale_462": "straight run a->b (x, z) with gaps [(s0, s1)] in studs along it: bays ~6 long, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L462 | neighbors=[rail_line(), MB] | lang=en
- "fishcenter_fish_map_rationale_475": "arc run from angle a0 to a1 (degrees, increasing): chord bays + an end post" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L475 | neighbors=[rail_arc(), MB] | lang=en
- "fishcenter_fish_map_rationale_484": "place every collected run: each bay carries the post at its start, a post closes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L484 | neighbors=[rails_flush(), MB] | lang=en
- "fishcenter_fish_map_rationale_504": "full circle at radius r minus angular gaps [(centre, half width deg)]" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L504 | neighbors=[arc_with_gaps(), MB] | lang=en
- "fishcenter_fish_map_rationale_67": "seabed / islets; out at the world edge it rises to +1 so the sea plane's border" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L67 | neighbors=[H(), MB] | lang=en
- "fishcenter_fish_map_rationale_71": "the natural depth profile (deep blue past the reef): only the seabed COLOUR stil" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L71 | neighbors=[H_raw(), MB] | lang=en
- "fishcenter_fish_map_top": "_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L163 | neighbors=[fish_map.py, fit_bad()] | lang=en
- "fishcenter_fish_props_buoy_stack": "buoy_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L609 | neighbors=[fish_props.py, trap floats and a coiled rope: stacked …] | lang=en
- "fishcenter_fish_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L514 | neighbors=[fish_props.py, flat-bottomed cumulus for the horizon (…] | lang=en
- "fishcenter_fish_props_crate_stack": "crate_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L545 | neighbors=[fish_props.py, crate()] | lang=en
- "fishcenter_fish_props_lifebuoy_stand": "lifebuoy_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L311 | neighbors=[fish_props.py, ball()] | lang=en
- "fishcenter_fish_props_rationale_1013": "QUEST BOARD: two bamboo posts with lashings, framed cork panel with blank pinned" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1013 | neighbors=[quest_board(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1054": "AQUARIUM INDEX wall: plank backboard on teak posts, 3 x 4 oval plaques each with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1054 | neighbors=[fish_index_wall(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1082": "WELCOME ARCH on the spawn axis: two lashed triple-bamboo pillars on coral plinth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1082 | neighbors=[welcome_arch(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1112": "hollow lofted boat hull: U sections closed by the sheer line (solid), sharp bow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1112 | neighbors=[boat_hull(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1137": "hull shading: bottom colour below the waterline, a stripe band under the sheer l" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1137 | neighbors=[paint_hull(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1149": "rowboat (white, teal stripe, red bottom): hollow hull, gunwale rail, 2 thwarts," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1149 | neighbors=[skiff(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1167": "small fishing boat (sun yellow, white stripe, teal bottom): hull, canvas sun roo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1167 | neighbors=[motor_boat(), Palette] | lang=en
- "fishcenter_fish_props_rationale_118": "closed rectangle loop with nx points on the X sides and nz_ on the Z sides, side" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L118 | neighbors=[ring_rect(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1201": "glass dome aquarium: coral-stone ashlar drum with a teal cap course, glass hemis" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1201 | neighbors=[aquarium_dome(), Palette] | lang=en
- "fishcenter_fish_props_rationale_1283": "the lighthouse rising out of the dome: coral plinth, tapered tower in red / whit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1283 | neighbors=[lighthouse(), Palette] | lang=en
- "fishcenter_fish_props_rationale_131": "one layer of thatch: outer surface from ringA (eave, fringed) up to ringB, a thi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L131 | neighbors=[thatch_band(), Palette] | lang=en
- "fishcenter_fish_props_rationale_160": "hip roof of `layers` overlapping fringed thatch bands; ridge bundle along X with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L160 | neighbors=[thatch_hip(), Palette] | lang=en
- "fishcenter_fish_props_rationale_193": "woven palm-mat infill between posts: strips 0.55 tall, alternating tone and dept" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L193 | neighbors=[mat_cell(), Palette] | lang=en
- "fishcenter_fish_props_rationale_201": "wall panel L long, H high (local x -L/2..L/2), holes [(x0, x1, y0, y1)] left ope" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L201 | neighbors=[woven_wall(), Palette] | lang=es
- "fishcenter_fish_props_rationale_220": "deck platform: planks along `along` with gaps, a dark skirt beam round it" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L220 | neighbors=[plank_floor(), Palette] | lang=en
- "fishcenter_fish_props_rationale_237": "striped canvas awning off a wall at z (front = -Z): slopes out `depth`, down `dr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L237 | neighbors=[awning(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_256": "BLANK carved sign board for a GUI label (no text): teak frame, light plank face," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L256 | neighbors=[sign_board(), Palette] | lang=en
- "fishcenter_fish_props_rationale_266": "teak rail post with the signature cap: a teal glass float in a rope net on a col" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L266 | neighbors=[rail_post(), Palette] | lang=en
- "fishcenter_fish_props_rationale_280": "SIGNATURE edge module: post at -L/2, two rope swags to +L/2 (next bay's post), s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L280 | neighbors=[rail_bay(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-112.json

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
