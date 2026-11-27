# Node Description Batch 115 of 209

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
- "fishcenter_fish_props_rationale_296": "bamboo torch: pole with nodes, lashings, woven cup, two-tongue flame. stilt > 0" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L296 | neighbors=[tiki_torch(), Palette] | lang=en
- "fishcenter_fish_props_rationale_324": "coconut palm: curved ringed trunk (silver-tan), flared foot, boot sheaths, cocon" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L324 | neighbors=[palm(), Palette] | lang=en
- "fishcenter_fish_props_rationale_382": "woven round planter (bamboo hoops) with a young palm and fern tufts" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L382 | neighbors=[palm_planter(), Palette] | lang=en
- "fishcenter_fish_props_rationale_395": "copy a built Prop's geometry into P (moved/scaled), keeping its per-face UVs" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L395 | neighbors=[_merge_prop(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_412": "elephant-ear clump: paddle leaves on arching stems (both sides) + a few red hibi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L412 | neighbors=[tropical_shrub(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_441": "low tropical grass + fern tuft: arching blades in two greens round a small leafy" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L441 | neighbors=[grass_tuft(), Palette] | lang=en
- "fishcenter_fish_props_rationale_451": "staghorn coral: forking tapered branches with rounded tips on a stone foot" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L451 | neighbors=[coral_branch(), Palette] | lang=en
- "fishcenter_fish_props_rationale_469": "brain coral: squashed dome with wavy meander ridges following its surface" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L469 | neighbors=[brain_coral(), Palette] | lang=en
- "fishcenter_fish_props_rationale_484": "pale coral-stone rock: lumpy main mass, a second lump, barnacle bumps, dark wet" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L484 | neighbors=[reef_rock(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_495": "tall volcanic sea stack: stacked tilted rock columns, grass caps, a palm tuft on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L495 | neighbors=[sea_stack(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_50": "raised binding / hoop round a vertical pole of radius r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L50 | neighbors=[ring_band(), Palette] | lang=en
- "fishcenter_fish_props_rationale_526": "slatted fish crate: corner posts, side slats with gaps, open top (fish on ice in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L526 | neighbors=[crate(), Palette] | lang=en
- "fishcenter_fish_props_rationale_54": "bamboo pole a->b with raised nodes every `nodes` studs" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L54 | neighbors=[pole(), Palette] | lang=en
- "fishcenter_fish_props_rationale_571": "heap of teal fishing net: lumpy mound with a rope mesh draped over its surface," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L571 | neighbors=[net_pile(), Palette] | lang=en
- "fishcenter_fish_props_rationale_610": "trap floats and a coiled rope: stacked red/yellow/white buoys" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L610 | neighbors=[buoy_stack(), Palette] | lang=en
- "fishcenter_fish_props_rationale_622": "fish cooler: rounded box body, white lid with hinge + latch, side handles, a tai" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L622 | neighbors=[cooler(), Palette] | lang=en
- "fishcenter_fish_props_rationale_635": "driftwood bench: two slab seat planks on X-legs with a stretcher, pegs" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L635 | neighbors=[bench(), Palette] | lang=en
- "fishcenter_fish_props_rationale_648": "fishing rod: cork grip, rod blank, guides, reel, line" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L648 | neighbors=[rod(), Palette] | lang=en
- "fishcenter_fish_props_rationale_658": "A-frame rod rack: bamboo frame, slotted top rail, rods leaning in slots, a bait" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L658 | neighbors=[rod_rack(), Palette] | lang=en
- "fishcenter_fish_props_rationale_675": "fishing-spot rod holder: teak post with a brass bracket of three tubes, rods ben" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L675 | neighbors=[rod_holder(), Palette] | lang=en
- "fishcenter_fish_props_rationale_69": "rope lashing: two thin hoops round a pole joint at c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L69 | neighbors=[lash(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_699": "palapa sun shade: teak pole on a stone foot, conical layered thatch, ring bindin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L699 | neighbors=[umbrella(), Palette] | lang=pt

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-114.json

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
