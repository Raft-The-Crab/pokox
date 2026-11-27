# Node Description Batch 114 of 208

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
- "fishcenter_fish_props_rationale_731": "fish drying rack: two bamboo A-frames, a top pole, lines of hanging fish" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L731 | neighbors=[drying_rack(), Palette] | lang=en
- "fishcenter_fish_props_rationale_74": "quads between successive rings (lists of Vector, same count); closed = each ring" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L74 | neighbors=[loft(), Palette] | lang=en
- "fishcenter_fish_props_rationale_745": "fishing-spot marker: floating striped buoy body, cage top with a small lamp, cha" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L745 | neighbors=[marker_buoy(), Palette] | lang=en
- "fishcenter_fish_props_rationale_759": "metal bait bucket with handle, worms (red tubes) and shrimp curls inside" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L759 | neighbors=[bait_bucket(), Palette] | lang=en
- "fishcenter_fish_props_rationale_772": "stilt-resort hut: plank floor platform + front steps, thick bamboo corner + mid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L772 | neighbors=[hut_body(), Palette] | lang=en
- "fishcenter_fish_props_rationale_794": "propped top-hinged window shutter (woven), with a bamboo prop stick" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L794 | neighbors=[shutter(), Palette] | lang=en
- "fishcenter_fish_props_rationale_802": "big brass fish hook (shape icon, no text): eye, shank, bend, point + barb" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L802 | neighbors=[hook_icon(), Palette] | lang=en
- "fishcenter_fish_props_rationale_814": "ROD SHOP (coral red): bamboo hut, woven walls, hip thatch, red striped awning ov" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L814 | neighbors=[rod_shop(), Palette] | lang=en
- "fishcenter_fish_props_rationale_838": "BAIT SHOP (lime): round hut of upright bamboo staves, cone thatch (4 layers), cu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L838 | neighbors=[bait_shop(), Palette] | lang=en
- "fishcenter_fish_props_rationale_86": "a stylised fish along local +X (nose at +X): elliptical body (laterally flat), f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L86 | neighbors=[fish(), Palette] | lang=pt
- "fishcenter_fish_props_rationale_906": "FISH MARKET / SELL (sun yellow): open pavilion on 8 teak posts with stone feet," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L906 | neighbors=[fish_market(), Palette] | lang=en
- "fishcenter_fish_props_rationale_959": "steep A-frame thatch: ridge along Z, each side `layers` stepped slabs with a fri" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L959 | neighbors=[thatch_gable(), Palette] | lang=en
- "fishcenter_fish_props_rationale_991": "BOAT RENTAL (lagoon teal): bamboo hut with a two-tier hip roof, teal shutters +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L991 | neighbors=[boat_house(), Palette] | lang=en
- "fishcenter_fish_props_reef_rock": "reef_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L483 | neighbors=[fish_props.py, pale coral-stone rock: lumpy main mass,…] | lang=en
- "fishcenter_fish_props_ring_band": "ring_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L49 | neighbors=[fish_props.py, raised binding / hoop round a vertical …] | lang=en
- "fishcenter_fish_props_ring_circ": "ring_circ()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L128 | neighbors=[fish_props.py, thatch_cone()] | lang=en
- "fishcenter_fish_props_ring_rect": "ring_rect()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L117 | neighbors=[fish_props.py, closed rectangle loop with nx points on…] | lang=en
- "fishcenter_fish_props_rod_holder": "rod_holder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L674 | neighbors=[fish_props.py, fishing-spot rod holder: teak post with…] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-113.json

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
