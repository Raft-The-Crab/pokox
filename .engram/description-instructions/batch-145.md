# Node Description Batch 146 of 208

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

- "valleylake_paint_hex": "_hex()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L19 | neighbors=[paint.py, paint_block()] | lang=en
- "valleylake_paint_tri": "tri()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L109 | neighbors=[paint.py, remap()] | lang=en
- "valleylake_post": "post.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/post.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "valleylake_turntable": "turntable.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/turntable.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "valleylake_valley_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L133 | neighbors=[valley_map.py, place()] | lang=en
- "valleylake_valley_map_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L178 | neighbors=[valley_map.py, clip_fail()] | lang=en
- "valleylake_valley_map_islet": "islet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L65 | neighbors=[valley_map.py, H0()] | lang=en
- "valleylake_valley_map_rationale_110": "stream water level at a centreline point: 0.4 up the valley, dropping with the b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L110 | neighbors=[MB, wlevel()] | lang=en
- "valleylake_valley_map_rationale_113": "one height function: natural floor + the stream channel + the plunge pool basin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L113 | neighbors=[MB, H()] | lang=en
- "valleylake_valley_map_rationale_144": "solid props are placed at once; soft ones (foliage, same regex as the exporter's" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L144 | neighbors=[MB, place()] | lang=en
- "valleylake_valley_map_rationale_185": "True if a placed soft prop clips into solids (> 4%, the exporter allows 8) or fl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L185 | neighbors=[MB, clip_fail()] | lang=en
- "valleylake_valley_map_rationale_201": "top surface under (x, z) by raycast onto everything solid (rock tops, ground); N" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L201 | neighbors=[MB, surface_y()] | lang=en
- "valleylake_valley_map_rationale_207": "deferred foliage: try the asked spot, then up to 8 jittered spots nearby; keep t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L207 | neighbors=[MB, place_soft()] | lang=en
- "valleylake_valley_map_rationale_285": "dirt paths = draped ribbons 0.12 over the ground (3 verts across, ragged width)," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L285 | neighbors=[MB, paths()] | lang=en
- "valleylake_valley_map_rationale_311": "the curving pale beach as a draped ring mesh: smooth outer edge (the ground grid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L311 | neighbors=[MB, beach()] | lang=en
- "valleylake_valley_map_rationale_346": "lake = fan disc a little past the shore (hidden under the sand), stream ribbon a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L346 | neighbors=[MB, water()] | lang=en
- "valleylake_valley_map_rationale_393": "preview-only water look (the exported Lake_Water stays palette + Glass in Roblox" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L393 | neighbors=[MB, preview_water()] | lang=en
- "valleylake_valley_map_rationale_464": "minimum foot offset per sample so every reserved spot / path keeps CLEAR studs (" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L464 | neighbors=[MB, foot_need()] | lang=it
- "valleylake_valley_map_rationale_48": "shore radius around LAKE_C by angle (th = atan2(z, x)): big lobe toward the came" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L48 | neighbors=[MB, lake_R()] | lang=en
- "valleylake_valley_map_rationale_480": "slab boundaries round the ring for tier k: random arc lengths, each slab a round" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L480 | neighbors=[MB, slabs()] | lang=en
- "valleylake_valley_map_rationale_552": "cliff surface height at (x, z) (None = no cliff there: valley floor or past the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L552 | neighbors=[MB, prof()] | lang=en
- "valleylake_valley_map_rationale_70": "bowl coordinate: < 1 inside the rim; the waterfall cleft pushes the rim back" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L70 | neighbors=[MB, rim_s()] | lang=en
- "valleylake_valley_map_rationale_706": "NE terrace: stone retaining walls (8-stud modules) along its south and west face" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L706 | neighbors=[MB, terrace()] | lang=en
- "valleylake_valley_map_rationale_714": "retaining walls along the terrace's south and west faces, running until the clif" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L714 | neighbors=[MB, terrace_walls()] | lang=en
- "valleylake_valley_map_rationale_727": "lantern rope lines: tall poles in a chain, two ropes per span (from both arm tip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L727 | neighbors=[MB, rope_lines()] | lang=en
- "valleylake_valley_map_rationale_760": "dock off the west beach, footbridge over the stream, stepping stones, lily pads," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L760 | neighbors=[MB, shore()] | lang=en
- "valleylake_valley_map_rationale_807": "yaw that swings the hero oak's leaning crown (its leaves' centroid) toward (tx," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L807 | neighbors=[MB, hero_yaw()] | lang=en
- "valleylake_valley_map_rationale_90": "natural floor: lake bed, beach, grass floor, islet, NE terrace (no stream / pool" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L90 | neighbors=[MB, H0()] | lang=fr
- "valleylake_valley_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L76 | neighbors=[valley_map.py, poly_d()] | lang=en
- "valleylake_valley_map_stream_near": "stream_near()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L101 | neighbors=[valley_map.py, H()] | lang=en
- "valleylake_valley_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L163 | neighbors=[valley_map.py, place_soft()] | lang=en
- "valleylake_valley_props_canopy": "canopy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L230 | neighbors=[valley_props.py, leaf_cluster()] | lang=en
- "valleylake_valley_props_rationale_1008": "soft full conifer: tapered skinned trunk; per tier a dark smooth drooping core s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L1008 | neighbors=[Palette, pine()] | lang=en
- "valleylake_valley_props_rationale_1040": "tip masses pulled toward one crown height, bridged to their nearest neighbour, p" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L1040 | neighbors=[Palette, merged_crown()] | lang=en
- "valleylake_valley_props_rationale_1054": "stylised broadleaf: skinned trunk with a root flare forking into 3-4 limbs; one" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L1054 | neighbors=[Palette, broadleaf()] | lang=en
- "valleylake_valley_props_rationale_124": "per-vertex convexity -> painted rim highlight (convex top edges lighter) / crevi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L124 | neighbors=[Palette, rim_shade()] | lang=en
- "valleylake_valley_props_rationale_149": "one carved rounded rock: superellipsoid mass with soft-flattened cut planes (a f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L149 | neighbors=[Palette, boulder()] | lang=en
- "valleylake_valley_props_rationale_200": "one painted leaf clump: a dark core lobe + n leaf cards (pointed diamonds, singl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L200 | neighbors=[Palette, leaf_cluster()] | lang=pt
- "valleylake_valley_props_rationale_238": "curved branch from a to b, arching up" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L238 | neighbors=[Palette, limb()] | lang=en
- "valleylake_valley_props_rationale_244": "stylised broadleaf: thick tapered trunk forking into 3-4 arching limbs, each car" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L244 | neighbors=[Palette, broadleaf()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-145.json

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
