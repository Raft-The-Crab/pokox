# Node Description Batch 98 of 207

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

- "candyland_candy_props_rationale_483": "PET / EGG MACHINE: sugar-glass dome over a cotton-candy nest of three decorated" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L483 | neighbors=[egg_machine(), Palette] | lang=en
- "candyland_candy_props_rationale_51": "sugar-coated: height gradient plus fine per-vertex sparkle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L51 | neighbors=[sugar(), Palette] | lang=fr
- "candyland_candy_props_rationale_517": "flat lollipop swirl: two interleaved Archimedean spiral ribbons (true spiral ban" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L517 | neighbors=[swirl_disc(), Palette] | lang=en
- "candyland_candy_props_rationale_55": "flip faces so normals point away from the vertical axis (lathe shells) / out of" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L55 | neighbors=[orient(), Palette] | lang=en
- "candyland_candy_props_rationale_550": "QUEST STAND: wafer-cookie kiosk under a cupcake-liner umbrella topped with a che" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L550 | neighbors=[quest_stand(), Palette] | lang=pt
- "candyland_candy_props_rationale_590": "TELEPORT: giant gumball machine. Stepped glossy pedestal, cherry body with a gol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L590 | neighbors=[gumball_machine(), Palette] | lang=en
- "candyland_candy_props_rationale_638": "ice-cream-cone tower: waffle shaft, icing collar, big scoop with drips, upturned" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L638 | neighbors=[cone_tower(), Palette] | lang=en
- "candyland_candy_props_rationale_65": "revolve a profile [(r, y)] (bottom -> top, solid on the left of travel) round th" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L65 | neighbors=[lathe(), Palette] | lang=en
- "candyland_candy_props_rationale_662": "HERO: gingerbread-and-frosting castle. Square curtain wall (gumdrop merlons, pip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L662 | neighbors=[candy_castle(), Palette] | lang=en
- "candyland_candy_props_rationale_730": "gingerbread plank drawbridge (lowered) along Z with licorice chains; origin = ca" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L730 | neighbors=[drawbridge(), Palette] | lang=en
- "candyland_candy_props_rationale_753": "icing poured over a bell top: follows the bell surface, scalloped lower edge (wa" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L753 | neighbors=[icing_cap(), Palette] | lang=en
- "candyland_candy_props_rationale_771": "HERO: Fudge Falls. A grape gumdrop mountain (sugar sparkle, icing cap + drips) w" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L771 | neighbors=[choco_falls(), Palette] | lang=pt
- "candyland_candy_props_rationale_846": "waffle-cone bridge along Z: an arched waffle deck between two giant waffle cones" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L846 | neighbors=[waffle_bridge(), Palette] | lang=en
- "candyland_candy_props_rationale_897": "biscuit bridge along Z: shortbread rounds overlapping on an arched chocolate spi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L897 | neighbors=[biscuit_bridge(), Palette] | lang=en
- "candyland_candy_props_rationale_937": "giant glazed donut standing on edge over the path, half sunk; glaze cap with dri" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L937 | neighbors=[donut_arch(), Palette] | lang=en
- "candyland_candy_props_rationale_97": "profile of a cylinder with rounded top (and bottom) edges, radius rr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L97 | neighbors=[round_prof(), Palette] | lang=en
- "candyland_candy_props_rationale_972": "candy-cane 'tree': helical-striped cane with a hook, planted in a sugar mound; s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L972 | neighbors=[candy_cane(), Palette] | lang=en
- "candyland_candy_props_rationale_990": "swirl lollipop on a bent stick, disc tilted to face the path (-Z), plus a smalle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L990 | neighbors=[lollipop_tree(), Palette] | lang=en
- "candyland_candy_props_ring_pts": "ring_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L223 | neighbors=[candy_props.py, cone_tower()] | lang=en
- "candyland_candy_props_roblox_materials": "roblox_materials()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1189 | neighbors=[candy_props.py, palette column -> Enum.Material name, f…] | lang=en
- "candyland_candy_props_waf": "WAF()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L269 | neighbors=[candy_props.py, shade for waffle_lathe: ridges light, p…] | lang=en
- "canyonbazaar_canyon_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L128 | neighbors=[canyon_map.py, place()] | lang=en
- "canyonbazaar_canyon_map_hook": "hook()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L327 | neighbors=[canyon_map.py, set_pieces()] | lang=en
- "canyonbazaar_canyon_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L123 | neighbors=[canyon_map.py, place()] | lang=en
- "canyonbazaar_canyon_map_levels": "levels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L44 | neighbors=[canyon_map.py, wall()] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-097.json

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
