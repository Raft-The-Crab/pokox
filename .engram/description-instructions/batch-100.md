# Node Description Batch 101 of 208

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

- "canyonbazaar_canyon_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L509 | neighbors=[canyon_map.py, free()] | lang=en
- "canyonbazaar_canyon_map_main_w": "main_w()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L97 | neighbors=[canyon_map.py, on_paving()] | lang=en
- "canyonbazaar_canyon_map_mouth": "mouth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L76 | neighbors=[canyon_map.py, H()] | lang=en
- "canyonbazaar_canyon_map_rationale_138": "True where the built cliff mesh (vertices jittered off H) overhangs the spot: a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L138 | neighbors=[under_wall(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_225": "distant buttes and mesas all round (flat tops, banded), well outside the playabl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L225 | neighbors=[horizon(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_244": "rows = [(left0, right0, left1, right1)] as Vectors; split each row into stones o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L244 | neighbors=[_stones(), MB] | lang=pt
- "canyonbazaar_canyon_map_rationale_301": "spawn medallion: an inlaid eight-point star of teal and saffron tiles in a cream" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L301 | neighbors=[medallion(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_406": "parapet niches along the canyon foot round the plaza + court, and along the lip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L406 | neighbors=[edge_rhythm(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_49": "stepped mesa profile at t studs past the floor edge: riser to the ledge (24), le" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L49 | neighbors=[wall(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_71": "(signed distance past the canyon floor edge, side): side +1 east wall, -1 west w" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L71 | neighbors=[tdist(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_79": "ONE height function for the ground mesh and all placement" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L79 | neighbors=[H(), MB] | lang=en
- "canyonbazaar_canyon_map_rationale_94": "main path centre: follows the canyon, swings east round the oasis pool" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L94 | neighbors=[path_x(), MB] | lang=en
- "canyonbazaar_canyon_map_seg_d2": "_seg_d2()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L107 | neighbors=[canyon_map.py, on_paving()] | lang=en
- "canyonbazaar_canyon_map_yaw_face": "yaw_face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L170 | neighbors=[canyon_map.py, yaw that turns a prop's -Z front to loo…] | lang=en
- "canyonbazaar_canyon_props_agave": "agave()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L426 | neighbors=[canyon_props.py, agave rosette: thick tapering leaves cu…] | lang=en
- "canyonbazaar_canyon_props_boulder": "boulder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L406 | neighbors=[canyon_props.py, layered sandstone boulder: a flat-bedde…] | lang=en
- "canyonbazaar_canyon_props_brazier": "brazier()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L701 | neighbors=[canyon_props.py, temple brazier: fluted sandstone pedest…] | lang=en
- "canyonbazaar_canyon_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L218 | neighbors=[canyon_props.py, pottery_cluster()] | lang=en
- "canyonbazaar_canyon_props_hoodoo": "hoodoo()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L389 | neighbors=[canyon_props.py, sandstone hoodoo: a broad banded column…] | lang=en
- "canyonbazaar_canyon_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L43 | neighbors=[canyon_props.py, cloth_sheet()] | lang=en
- "canyonbazaar_canyon_props_oasis_pool": "oasis_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L345 | neighbors=[canyon_props.py, oasis spring: an irregular pool, a ring…] | lang=en
- "canyonbazaar_canyon_props_palm": "palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L306 | neighbors=[canyon_props.py, date palm: curved ringed trunk, flared …] | lang=en
- "canyonbazaar_canyon_props_rationale_117": "wicker basket heaped with fruit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L117 | neighbors=[fruit_pile(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_126": "market stall: sandstone step, four palm-timber posts with braces, a striped shad" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L126 | neighbors=[stall(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_180": "street shade: two pairs of tall palm-timber posts on stone footings either side" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L180 | neighbors=[shade_sail(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_208": "story cluster: big jars, a toppled amphora, a stack of bowls, a crate" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L208 | neighbors=[pottery_cluster(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_229": "story cluster: five open spice sacks with rolled rims and heaped spice cones, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L229 | neighbors=[spice_sacks(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_246": "story cluster: timber rack with three patterned rugs hung over the pole, two rol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L246 | neighbors=[rug_rack(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_272": "SIGNATURE: low sandstone wall module (ashlar both faces, chamfered coping, end p" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L272 | neighbors=[parapet_niche(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_293": "street lantern: sandstone base, timber post with a scroll bracket arm, a hanging" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L293 | neighbors=[lantern_post(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_307": "date palm: curved ringed trunk, flared root boss, a crown of drooping pinnate fr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L307 | neighbors=[palm(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_346": "oasis spring: an irregular pool, a ring of cut sandstone curb stones, a lower in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L346 | neighbors=[oasis_pool(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_390": "sandstone hoodoo: a broad banded column (overlapping strata drums, alternating r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L390 | neighbors=[hoodoo(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_407": "layered sandstone boulder: a flat-bedded lower slab, a smaller upper stratum off" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L407 | neighbors=[boulder(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_415": "dry desert shrub: low, dense: a dozen small olive-grey leaf puffs on a twiggy wo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L415 | neighbors=[scrub(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_427": "agave rosette: thick tapering leaves curving up and out, a dark leaf tip each, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L427 | neighbors=[agave(), Palette] | lang=pt
- "canyonbazaar_canyon_props_rationale_453": "stair carved into the canyon wall: sandstone treads climbing toward -Z, a solid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L453 | neighbors=[carved_stair(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_48": "SHARED BASE: two-course sandstone dais (ashlar faces) with a chamfered cap, sunk" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L48 | neighbors=[dais(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_482": "rope bridge spanning along Z from z = -L/2 to +L/2 (deck y 0 at both ends, saggi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L482 | neighbors=[rope_bridge(), Palette] | lang=en
- "canyonbazaar_canyon_props_rationale_510": "BLANK sign: carved timber frame with a cream face (SurfaceGui goes here) and a c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L510 | neighbors=[sign_board(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-100.json

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
