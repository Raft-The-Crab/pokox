# Node Description Batch 99 of 207

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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-098.json

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
