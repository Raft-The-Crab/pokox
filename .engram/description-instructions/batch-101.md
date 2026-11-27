# Node Description Batch 102 of 208

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

- "canyonbazaar_canyon_props_rationale_525": "spawn plaza fountain: octagonal sandstone basin with a teal-tiled band, a carved" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L525 | neighbors=[spawn_fountain(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_56": "a cloth stretched flat over a frame: corners at (x0|x1, z0|z1), height y0 at z0" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L56 | neighbors=[cloth_sheet(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_561": "SELL station: a wide trader pavilion on the shared dais: six posts, two stretche" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L561 | neighbors=[trader_pavilion(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_598": "UPGRADE station: a sandstone forge hearth with glowing coals, a hooded terracott" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L598 | neighbors=[forge_station(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_641": "QUEST station: a timber notice board under a small stretched teal cloth, three b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L641 | neighbors=[quest_board(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_669": "RELIC / PET station on the ledge: a small domed kiosk on four horseshoe arches (" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L669 | neighbors=[relic_kiosk(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_702": "temple brazier: fluted sandstone pedestal, a brass bowl on three claw legs, a he" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L702 | neighbors=[brazier(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_717": "horseshoe-arch gate over the street: ashlar piers with chamfered plinths, a poin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L717 | neighbors=[market_gate(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_756": "HERO: Temple of the Setting Sun, a rock-cut facade standing in a rectangular nic" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L756 | neighbors=[sun_temple(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_85": "pierced brass lantern: domed cap with a finial + ring, six ribs round a glowing" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L85 | neighbors=[brass_lantern(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_99": "terracotta jar (amphora / squat jar / long-necked) with a painted band and a rim" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L99 | neighbors=[pot(), Palette] | lang=en
- "canyonbazaar_canyon_props_rope_bridge": "rope_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L481 | neighbors=[canyon_props.py, rope bridge spanning along Z from z = -…] | lang=en
- "canyonbazaar_canyon_props_rug_rack": "rug_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L245 | neighbors=[canyon_props.py, story cluster: timber rack with three p…] | lang=en
- "canyonbazaar_canyon_props_scrub": "scrub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L414 | neighbors=[canyon_props.py, dry desert shrub: low, dense: a dozen s…] | lang=en
- "canyonbazaar_canyon_props_spawn_fountain": "spawn_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L524 | neighbors=[canyon_props.py, spawn plaza fountain: octagonal sandsto…] | lang=en
- "canyonbazaar_canyon_props_spice_sacks": "spice_sacks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L228 | neighbors=[canyon_props.py, story cluster: five open spice sacks wi…] | lang=en
- "canyonbazaar_closeup": "closeup.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/closeup.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "canyonbazaar_grid": "grid.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/grid.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-101.json

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
