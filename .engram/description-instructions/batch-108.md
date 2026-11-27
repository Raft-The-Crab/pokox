# Node Description Batch 109 of 207

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

- "eggplots_egg_map_rationale_89": "height of the BUILT ground mesh (the coarse hill grid departs from H by several" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L89 | neighbors=[Hg(), MB] | lang=en
- "eggplots_egg_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L27 | neighbors=[egg_map.py, hardscape()] | lang=en
- "eggplots_egg_map_t": "T()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L159 | neighbors=[egg_map.py, hardscape()] | lang=en
- "eggplots_egg_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L822 | neighbors=[egg_props.py, sh()] | lang=en
- "eggplots_egg_props_lily_pads": "lily_pads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L928 | neighbors=[egg_props.py, sh()] | lang=en
- "eggplots_egg_props_merge_prop": "merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L64 | neighbors=[egg_props.py, hay_stack()] | lang=en
- "eggplots_egg_props_rationale_137": "chunky low-poly nest: a fat torus rim with a dished floor, straw wisps poking ou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L137 | neighbors=[straw_nest(), Palette] | lang=pt
- "eggplots_egg_props_rationale_148": "post-top egg knob: accent collar + cream egg with an accent band" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L148 | neighbors=[egg_finial(), Palette] | lang=en
- "eggplots_egg_props_rationale_153": "square post with a stone footing (extends below ground) and a chamfered top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L153 | neighbors=[post(), Palette] | lang=en
- "eggplots_egg_props_rationale_161": "incubator slot: octagon stone plinth with an accent ring + four gem studs, honey" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L161 | neighbors=[nest_pedestal(), Palette] | lang=en
- "eggplots_egg_props_rationale_177": "picket fence segment along +X (0..L), front -Z: a slim honey post with an accent" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L177 | neighbors=[fence_run(), Palette] | lang=en
- "eggplots_egg_props_rationale_198": "the closing post of a fence run" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L198 | neighbors=[fence_post(), Palette] | lang=en
- "eggplots_egg_props_rationale_205": "yard entrance (the laser / force-gate spot, opening W): two stone-footed pillars" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L205 | neighbors=[gate_frame(), Palette] | lang=en
- "eggplots_egg_props_rationale_234": "owner board: two honey posts, accent frame, BLANK cream face toward -Z (GUI), a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L234 | neighbors=[owner_sign(), Palette] | lang=pt
- "eggplots_egg_props_rationale_250": "cash collect pad: octagon stone ring, accent rim with a glow ring, cream disc wi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L250 | neighbors=[collect_pad(), Palette] | lang=en
- "eggplots_egg_props_rationale_263": "the yard: chamfered stone footing + accent kerb, straw-cream ground, a paved sto" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L263 | neighbors=[plot_slab(), Palette] | lang=en
- "eggplots_egg_props_rationale_297": "the nest-coop (the plot's base building): stone plinth, cream plaster walls with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L297 | neighbors=[coop(), Palette] | lang=en
- "eggplots_egg_props_rationale_385": "square hay bale: chamfered straw block, two twine bands, straw tufts on top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L385 | neighbors=[hay_bale(), Palette] | lang=en
- "eggplots_egg_props_rationale_396": "three bales stacked (2 + 1), a pitchfork-free story pile" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L396 | neighbors=[hay_stack(), Palette] | lang=pt
- "eggplots_egg_props_rationale_403": "grain trough: honey plank trough on splayed legs, grain heap inside, small egg-c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L403 | neighbors=[feed_trough(), Palette] | lang=en
- "eggplots_egg_props_rationale_422": "half-barrel planter: honey staves with iron hoops, soil, low-poly tulips" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L422 | neighbors=[flower_tub(), Palette] | lang=en
- "eggplots_egg_props_rationale_438": "egg conveyor segment along -Z (z 0..-L): stone feet, honey side boards with an a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L438 | neighbors=[conveyor_seg(), Palette] | lang=en
- "eggplots_egg_props_rationale_471": "lane lamp: stone base, honey post with an iron arm, an egg-shaped glowing lanter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L471 | neighbors=[lane_lamp(), Palette] | lang=en
- "eggplots_egg_props_rationale_486": "giant painted egg (lane / plaza decor) on a straw nest on a stone plinth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L486 | neighbors=[deco_egg(), Palette] | lang=pt
- "eggplots_egg_props_rationale_497": "humped plank footbridge over the belt (along X): stone abutments on the walkways" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L497 | neighbors=[foot_bridge(), Palette] | lang=en
- "eggplots_egg_props_rationale_521": "the egg dispenser at the north head of the lane. Concept: a giant cracked egg th" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L521 | neighbors=[hatchery(), Palette] | lang=en
- "eggplots_egg_props_rationale_60": "2D poly [(x, up)] standing upright facing -Z, extruded d toward the front (-Z) f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L60 | neighbors=[upright(), Palette] | lang=en
- "eggplots_egg_props_rationale_648": "the drain at the south end: a low woven basket ring (honey staves + cream wicker" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L648 | neighbors=[egg_drain(), Palette] | lang=en
- "eggplots_egg_props_rationale_670": "welcome path in the plot colour on the lane walkway in front of a gate: rounded" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L670 | neighbors=[gate_mat(), Palette] | lang=en
- "eggplots_egg_props_rationale_681": "market stand shell: stone footing, honey counter with a cream top, 4 posts, a st" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L681 | neighbors=[stall(), Palette] | lang=pt
- "eggplots_egg_props_rationale_707": "Egg Shop stand (buy): yellow / cream awning, egg cartons and painted eggs on the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L707 | neighbors=[egg_shop(), Palette] | lang=en
- "eggplots_egg_props_rationale_723": "Upgrades stand: teal / cream awning, a workbench counter with a vice-free incuba" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L723 | neighbors=[upgrade_stand(), Palette] | lang=pt
- "eggplots_egg_props_rationale_749": "Sell stand: orange / cream awning, a balance scale with egg on one pan and coins" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L749 | neighbors=[sell_stand(), Palette] | lang=en
- "eggplots_egg_props_rationale_76": "egg outline (r, y) bottom -> top: widest a little below the middle, narrower dom" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L76 | neighbors=[egg_profile(), Palette] | lang=en
- "eggplots_egg_props_rationale_777": "spawn centrepiece: round stone plinth with steps, a big straw nest holding three" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L777 | neighbors=[nest_statue(), Palette] | lang=en
- "eggplots_egg_props_rationale_801": "low-poly round tree: tapered faceted trunk with a root flare, 3-4 faceted canopy" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L801 | neighbors=[tree(), Palette] | lang=en
- "eggplots_egg_props_rationale_813": "low-poly cone tree: three stacked faceted cones, a short trunk" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L813 | neighbors=[pine(), Palette] | lang=pt
- "eggplots_egg_props_rationale_833": "ground flowers: a tuft of leaves + 5-7 little 5-petal flowers (decor, no collisi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L833 | neighbors=[flower_patch(), Palette] | lang=en
- "eggplots_egg_props_rationale_85": "a band of the egg between heights t0..t1 (fractions of H), radius x grow: painte" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L85 | neighbors=[egg_slice(), Palette] | lang=en
- "eggplots_egg_props_rationale_853": "island edge ranch fence: two round-topped honey posts, three split rails (cheap:" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L853 | neighbors=[ranch_fence(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-108.json

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
