# Node Description Batch 104 of 209

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

- "cavemap_cave_map_air": "air()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L72 | neighbors=[cave_map.py, build_dist()] | lang=en
- "cavemap_cave_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L157 | neighbors=[cave_map.py, place()] | lang=en
- "cavemap_cave_map_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L217 | neighbors=[cave_map.py, clip_fail()] | lang=en
- "cavemap_cave_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L152 | neighbors=[cave_map.py, place()] | lang=en
- "cavemap_cave_map_rationale_105": "floor height: gentle cave earth, lake bed carved in, islet raised, nothing in th" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L105 | neighbors=[H(), MB] | lang=en
- "cavemap_cave_map_rationale_122": "signed distance (studs) to the cave wall at floor level: + inside the air, - ins" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L122 | neighbors=[build_dist(), MB] | lang=en
- "cavemap_cave_map_rationale_168": "solid props at once; soft ones (foliage / fungi / vines) deferred and placed aga" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L168 | neighbors=[place(), MB] | lang=en
- "cavemap_cave_map_rationale_192": "copy a prop part (Roblox-space MB) to its world placement (pieces built into sta" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L192 | neighbors=[placed_mb(), MB] | lang=en
- "cavemap_cave_map_rationale_279": "inner cave surface: union of the air ellipsoids, voxel-remeshed (3 studs), displ" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L279 | neighbors=[shell(), MB] | lang=en
- "cavemap_cave_map_rationale_330": "outer rock skin (coarse, normals OUT): closes the volume so the sun only enters" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L330 | neighbors=[crust(), MB] | lang=en
- "cavemap_cave_map_rationale_338": "walkable floor heightfield (3 studs) everywhere under the air + 6 studs into the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L338 | neighbors=[floor(), MB] | lang=en
- "cavemap_cave_map_rationale_405": "layered rock masses along every wall foot (big in the hall, small in tunnels), h" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L405 | neighbors=[rocks(), MB] | lang=en
- "cavemap_cave_map_rationale_433": "stalactites over the whole vault (never low over paths), flowstone curtains near" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L433 | neighbors=[dripstone(), MB] | lang=en
- "cavemap_cave_map_rationale_470": "geodes at chosen spots (glow by district: amber by the camp + forge, cyan round" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L470 | neighbors=[crystals(), MB] | lang=en
- "cavemap_cave_map_rationale_505": "story clusters on the open hall floor (no dead space between light pools): a min" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L505 | neighbors=[clusters(), MB] | lang=en
- "cavemap_cave_map_rationale_556": "glow-worm colonies on the vault + tunnel ceilings: faint teal specks so the ceil" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L556 | neighbors=[worms(), MB] | lang=en
- "cavemap_cave_map_rationale_567": "giant glowing mushrooms in the brew grotto and on the west hall floor, knee-high" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L567 | neighbors=[fungi(), MB] | lang=en
- "cavemap_cave_map_rationale_57": "list of ellipsoids (centre, radii) whose union is the cave air" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L57 | neighbors=[shapes(), MB] | lang=en
- "cavemap_cave_map_rationale_588": "glow-root vines hanging from the vault and tunnel ceilings (origin at the top, j" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L588 | neighbors=[vines(), MB] | lang=en
- "cavemap_cave_map_rationale_602": "hero, sun shaft lip, ceiling falls, spawn, the five stations + their dressing, b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L602 | neighbors=[landmarks(), MB] | lang=en
- "cavemap_cave_map_rationale_664": "track along the two rail lines (8-stud segments), buffers at the ends, carts on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L664 | neighbors=[rails(), MB] | lang=en
- "cavemap_cave_map_rationale_688": "timber sets every ~16 studs along each tunnel (never across the chasm), lantern" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L688 | neighbors=[mine_sets(), MB] | lang=en
- "cavemap_cave_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L78 | neighbors=[cave_map.py, poly_d()] | lang=en
- "cavemap_cave_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L185 | neighbors=[cave_map.py, place_soft()] | lang=en
- "cavemap_cave_palette": "cave_palette.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_palette.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "cavemap_cave_props_cap_shape": "cap_shape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L336 | neighbors=[cave_props.py, mushroom()] | lang=en
- "cavemap_cave_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L29 | neighbors=[cave_props.py, strata_mass()] | lang=en
- "cavemap_cave_props_rationale_113": "thick moss shell over the up-facing part of bm, closed by a drooping skirt" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L113 | neighbors=[moss_cap(), Palette] | lang=en
- "cavemap_cave_props_rationale_136": "banded crystal column: chamfered octagon prism, a narrow dark band, then a GLOW" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L136 | neighbors=[crystal(), Palette] | lang=pt
- "cavemap_cave_props_rationale_166": "one carved, layered rock: strata_mass bedded 26% below its origin, moss on the t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L166 | neighbors=[rock_layered(), Palette] | lang=en
- "cavemap_cave_props_rationale_202": "stalactite lathe profile (r, y) from the ceiling (y +.8, embedded) down to the t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L202 | neighbors=[drip_profile(), Palette] | lang=en
- "cavemap_cave_props_rationale_211": "hanging dripstone cluster: one long ringed spike + smaller ones off-centre, wet" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L211 | neighbors=[stalactite(), Palette] | lang=en
- "cavemap_cave_props_rationale_227": "flowstone drapery hanging from the ceiling: a folded sheet with a scalloped lowe" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L227 | neighbors=[flowstone_curtain(), Palette] | lang=en
- "cavemap_cave_props_rationale_256": "grounded dripstone: flared, plate-ringed column with a rounded wet cap, plus 1-3" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L256 | neighbors=[stalagmite(), Palette] | lang=en
- "cavemap_cave_props_rationale_278": "a cracked-open geode: a lumpy rock cup (outer layered rock, broken rim, inner wa" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L278 | neighbors=[geode(), Palette] | lang=pt
- "cavemap_cave_props_rationale_311": "wall-foot crystal spray: a layered rock knuckle with a fan of columns all leanin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L311 | neighbors=[crystal_spray(), Palette] | lang=en
- "cavemap_cave_props_rationale_323": "ground scatter: a pebble bed with 3-5 small glowing points" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L323 | neighbors=[crystal_shards(), Palette] | lang=en
- "cavemap_cave_props_rationale_35": "per-vertex height gradient (a low -> b high) + normal lift + noise: soft painter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L35 | neighbors=[V(), Palette] | lang=pt
- "cavemap_cave_props_rationale_360": "one fungus: S-bent tapering stem with a skirt ring, painted cap, GLOWING gills u" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L360 | neighbors=[mushroom(), Palette] | lang=en
- "cavemap_cave_props_rationale_385": "mossy root mound; glowing spore nodules sit on its foot at ground level (one rin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L385 | neighbors=[mound(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-103.json

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
