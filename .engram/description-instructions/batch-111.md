# Node Description Batch 112 of 208

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
- "eggplots_egg_props_rationale_862": "backdrop red barn (seen from across the lake): stone plinth, red board walls wit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L862 | neighbors=[barn(), Palette] | lang=en
- "eggplots_egg_props_rationale_899": "backdrop windmill: tapered octagonal tower (cream, honey trim), red cap, 4 latti" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L899 | neighbors=[windmill(), Palette] | lang=en
- "eggplots_egg_props_reeds": "reeds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L936 | neighbors=[egg_props.py, sh()] | lang=en
- "eggplots_egg_props_silo": "silo()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L890 | neighbors=[egg_props.py, sh()] | lang=en
- "eggplots_sheet": "sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "evaluator_evaluator_floatenvironment": "FloatEnvironment" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L92 | neighbors=[evaluator.cpp, .FloatEnvironment()] | lang=en
- "evaluator_evaluator_literal_float": "literal_float()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L162 | neighbors=[evaluator.cpp, fail()] | lang=en
- "examples_axolotl_gill_base": "gill_base()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L30 | neighbors=[axolotl.py, build()] | lang=en
- "examples_axolotl_happy": "happy()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L137 | neighbors=[axolotl.py, gills()] | lang=en
- "examples_axolotl_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L108 | neighbors=[axolotl.py, gills()] | lang=en
- "examples_axolotl_swim": "swim()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L126 | neighbors=[axolotl.py, gills()] | lang=en
- "examples_axolotl_unit": "_unit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L26 | neighbors=[axolotl.py, build()] | lang=en
- "examples_axolotl_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L116 | neighbors=[axolotl.py, gills()] | lang=en
- "examples_gridfinity_d110_bin_rationale_1": "Gridfinity 3x2 cradle bin for the Orico D110 label printer.  The hand-rolled ori" | kind=entity | source=.agents/skills/cad-skill-main/examples/gridfinity_d110_bin.py:L1 | neighbors=[GridfinityBin, gridfinity_d110_bin.py] | lang=en
- "examples_mx_master3_bin_3x3_rationale_1": "Gridfinity 3x3 diagonal cradle bin for the Logitech MX Master 3.  Showcases the" | kind=entity | source=.agents/skills/cad-skill-main/examples/mx_master3_bin_3x3.py:L1 | neighbors=[GridfinityBin, mx_master3_bin_3x3.py] | lang=en
- "extensions_superpowers_pitoolmapping": "piToolMapping()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L83 | neighbors=[superpowers.ts, getBootstrapContent()] | lang=en
- "extensions_superpowers_stripfrontmatter": "stripFrontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L78 | neighbors=[superpowers.ts, getBootstrapContent()] | lang=en
- "fakes_basicplatformdebug": "BasicPlatformDebug.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/BasicPlatformDebug.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "fakes_refcntautoptr_refcntautoptr": "RefCntAutoPtr" | kind=code-symbol | source=engine/rhi/tests/fakes/RefCntAutoPtr.hpp:L4 | neighbors=[RefCntAutoPtr.hpp, .RefCntAutoPtr()] | lang=en
- "fishcenter_fish_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L514 | neighbors=[fish_map.py, stations()] | lang=en
- "fishcenter_fish_map_bay_key": "bay_key()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L456 | neighbors=[fish_map.py, rails_flush()] | lang=en
- "fishcenter_fish_map_halfang": "halfang()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L511 | neighbors=[fish_map.py, edges()] | lang=en
- "fishcenter_fish_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L153 | neighbors=[fish_map.py, _inside_one()] | lang=en
- "fishcenter_fish_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L87 | neighbors=[fish_map.py, place()] | lang=en
- "fishcenter_fish_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L701 | neighbors=[fish_map.py, free()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-111.json

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
