# Node Description Batch 109 of 208

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

- "dunedesert_dune_props_rationale_285": "broken wall of real bevelled blocks with a ragged top; optional doorway with a l" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L285 | neighbors=[ruin_wall(), Palette] | lang=en
- "dunedesert_dune_props_rationale_302": "corner of a roofless house: two block walls meeting at a pier, a doorway, a wind" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L302 | neighbors=[ruin_house(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_322": "free-standing broken arch: block piers, round arch of voussoirs with a gold keys" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L322 | neighbors=[ruin_arch(), Palette] | lang=en
- "dunedesert_dune_props_rationale_343": "kind 0 standing column, 1 broken column (jagged top), 2 broken stub + fallen dru" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L343 | neighbors=[column_set(), Palette] | lang=en
- "dunedesert_dune_props_rationale_357": "square tapered shaft (w0 at 0 .. w1 at H) cut at y0..y1, in drums, relief column" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L357 | neighbors=[_shaft(), Palette] | lang=es
- "dunedesert_dune_props_rationale_381": "standing obelisk on the stepped plinth: drummed tapered shaft, relief columns on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L381 | neighbors=[obelisk(), Palette] | lang=en
- "dunedesert_dune_props_rationale_390": "toppled obelisk piece lying on its side along x: 'top' (with pyramidion) or 'mid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L390 | neighbors=[obelisk_fallen(), Palette] | lang=en
- "dunedesert_dune_props_rationale_423": "path marker: weathered standing stone with a carved sun disc on its front, a gol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L423 | neighbors=[waystone(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_436": "spawn: round three-step sandstone dais (r 13.4) with a gold sun mosaic (disc, 16" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L436 | neighbors=[spawn_dais(), Palette] | lang=en
- "dunedesert_dune_props_rationale_460": "QUEST stand: tall carved tablet on the plinth with three BLANK recessed panels (" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L460 | neighbors=[quest_stele(), Palette] | lang=en
- "dunedesert_dune_props_rationale_489": "UPGRADE station: octagonal stepped plinth, carved pedestal with gold claws holdi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L489 | neighbors=[sun_astrolabe(), Palette] | lang=en
- "dunedesert_dune_props_rationale_50": "soft per-loop shade: height ramp + vertex-normal lift + low-frequency noise" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L50 | neighbors=[V(), Palette] | lang=en
- "dunedesert_dune_props_rationale_528": "a cloth sheet over a parametric surface fn(u, v) -> Vector (u, v in 0..1), solid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L528 | neighbors=[sheet(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_551": "plank crate: bevelled body with plank grooves (thin proud boards), corner straps" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L551 | neighbors=[crate(), Palette] | lang=en
- "dunedesert_dune_props_rationale_577": "SHOP: caravan trader's tent: 6 poles, a long low roof of indigo + cream bands st" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L577 | neighbors=[trader_tent(), Palette] | lang=en
- "dunedesert_dune_props_rationale_633": "A-frame nomad tent: ridge pole on two forked posts, two cloth slopes with sag +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L633 | neighbors=[sleep_tent(), Palette] | lang=en
- "dunedesert_dune_props_rationale_64": "merge a temporary Prop's solid (+ glow) into P, optionally mapping every vertex" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L64 | neighbors=[merge_into(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_656": "stylised camel (smooth hide): ellipsoid body + single hump, S-curved neck, long" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L656 | neighbors=[camel(), Palette] | lang=en
- "dunedesert_dune_props_rationale_704": "rest corner: a big patterned rug (border, field, medallion), three cushions, a b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L704 | neighbors=[rug_spread(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_71": "flat top split into ~cell faces (the atlas squeezes a face that spans more than" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L71 | neighbors=[grid_quad(), Palette] | lang=en
- "dunedesert_dune_props_rationale_721": "stone ring, crossed logs, flame glow, a three-legged tripod with a hanging pot," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L721 | neighbors=[campfire(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_745": "caravan cargo: crates stacked, sacks, rolled rugs, two water jars and a saddle b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L745 | neighbors=[cargo_pile(), Palette] | lang=en
- "dunedesert_dune_props_rationale_755": "oasis: a round pool (r 10) with a turquoise water disc set below a rim of cut sa" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L755 | neighbors=[oasis_pool(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_814": "DIG SPOT anchors: tier 1 a low sand mound with a cracked jar and a marker stick," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L814 | neighbors=[treasure_mound(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_859": "sandstone outcrop: two or three wind-cut rock masses, layered (darker bands low," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L859 | neighbors=[outcrop(), Palette] | lang=en
- "dunedesert_dune_props_rationale_872": "desert scrub: a woody tangle of forking twigs from one root crown with small dus" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L872 | neighbors=[dry_shrub(), Palette] | lang=en
- "dunedesert_dune_props_rationale_884": "tuft of tall pale dune grass: tapered folded blades arching out of a tight crown" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L884 | neighbors=[dune_grass(), Palette] | lang=en
- "dunedesert_dune_props_rationale_898": "smooth sand drift banked against ruins (no collision): a long soft lump, steep l" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L898 | neighbors=[sand_drift(), Palette] | lang=pt
- "dunedesert_dune_props_rationale_909": "giant sand-wyrm skull lying jaw-open in the sand: long ridged cranium with deep" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L909 | neighbors=[wyrm_skull(), Palette] | lang=en
- "dunedesert_dune_props_rationale_93": "SIGNATURE: raised sun disc + ray wedges on a plane facing -Z, turned by yaw and" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L93 | neighbors=[sun_relief(), Palette] | lang=en
- "dunedesert_dune_props_rationale_940": "one segment of the wyrm's spine lying belly-down: the vertebra (with a spinous p" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L940 | neighbors=[wyrm_rib(), Palette] | lang=en
- "dunedesert_dune_props_rationale_960": "wind-cut sandstone stack: 3-5 rounded slabs piled and offset (each narrower), da" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L960 | neighbors=[rock_stack(), Palette] | lang=en
- "dunedesert_dune_props_rationale_972": "HERO: giant half-buried stone head of a sun-king (face sculpted by displacement" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L972 | neighbors=[colossus_head(), Palette] | lang=en
- "dunedesert_dune_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L47 | neighbors=[dune_props.py, colossus_head()] | lang=en
- "dunedesert_dune_props_spike_flame": "spike_flame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L740 | neighbors=[dune_props.py, campfire()] | lang=en
- "dunedesert_dune_props_waystone_body": "waystone_body()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L854 | neighbors=[dune_props.py, treasure_mound()] | lang=en
- "dunedesert_gen_trees_with_palms_export_glb": "export_glb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1169 | neighbors=[gen_trees_with_palms.py, main()] | lang=en
- "dunedesert_gen_trees_with_palms_load_px": "load_px()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1140 | neighbors=[gen_trees_with_palms.py, contact_sheet()] | lang=en
- "dunedesert_gen_trees_with_palms_make_object": "make_object()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L694 | neighbors=[gen_trees_with_palms.py, make_tree()] | lang=en
- "dunedesert_gen_trees_with_palms_material": "material()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L710 | neighbors=[gen_trees_with_palms.py, get_materials()] | lang=en

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
