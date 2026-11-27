# Node Description Batch 110 of 209

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

- "dunedesert_dune_map_rationale_323": "worn flagstone slabs over the city + the avenue, missing where the sand has drif" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L323 | neighbors=[paving(), MB] | lang=en
- "dunedesert_dune_map_rationale_449": "path markers every ~30 studs along each sand path, alternating sides" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L449 | neighbors=[waystones(), MB] | lang=en
- "dunedesert_dune_map_rationale_520": "half-buried relics of the old kingdom between the points of interest: broken col" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L520 | neighbors=[fragments(), MB] | lang=en
- "dunedesert_dune_map_rationale_59": "transverse dunes (crests ~N-S, wind from the west): gentle windward rise, steepe" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L59 | neighbors=[dunes(), MB] | lang=en
- "dunedesert_dune_map_rationale_69": "frame: high dune ridges on a ring r ~430-560 round the city, lower beyond so the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L69 | neighbors=[ring(), MB] | lang=en
- "dunedesert_dune_map_rationale_75": "temple-local (lx across the trench, lz along it: -Z toward the city, facade at 0" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L75 | neighbors=[T_local(), MB] | lang=en
- "dunedesert_dune_map_rationale_79": "ONE height function for the ground mesh and all placement" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L79 | neighbors=[H(), MB] | lang=en
- "dunedesert_dune_map_seg_d": "_seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L52 | neighbors=[dune_map.py, pl_d()] | lang=en
- "dunedesert_dune_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L160 | neighbors=[dune_map.py, place_soft()] | lang=en
- "dunedesert_dune_map_world": "world()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L172 | neighbors=[dune_map.py, set_pieces()] | lang=en
- "dunedesert_dune_paint_hex": "_hex()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L21 | neighbors=[dune_paint.py, paint_block()] | lang=en
- "dunedesert_dune_paint_paint_block": "paint_block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L24 | neighbors=[dune_paint.py, _hex()] | lang=en
- "dunedesert_dune_props_rationale_1041": "HERO / DUNGEON PORTAL: a columned temple front sunk 12 studs into the dunes, rea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L1041 | neighbors=[sunken_temple(), Palette] | lang=en
- "dunedesert_dune_props_rationale_106": "raised zigzag band between two rails (centre c, length L along local x, facing -" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L106 | neighbors=[zig_band(), Palette] | lang=en
- "dunedesert_dune_props_rationale_115": "wall of REAL bevelled blocks through the wall, running bond, broken top prof(x);" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L115 | neighbors=[block_wall(), Palette] | lang=en
- "dunedesert_dune_props_rationale_130": "SHARED BASE: stepped sandstone plinth, a chamfered course per step, gold trim li" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L130 | neighbors=[plinth(), Palette] | lang=en
- "dunedesert_dune_props_rationale_138": "square base + torus, drummed 10-sided shaft with entasis, flared bell capital +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L138 | neighbors=[column(), Palette] | lang=en
- "dunedesert_dune_props_rationale_170": "HERO: six-tier gilded step pyramid (ashlar faces, cornice lips, sun + chevron re" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L170 | neighbors=[step_pyramid(), Palette] | lang=en
- "dunedesert_dune_props_rationale_237": "processional pylon gateway: two battered towers built in courses (each course a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L237 | neighbors=[pylon_gate(), Palette] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-109.json

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
