# Node Description Batch 161 of 208

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

- "candyland_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/hooks_lua.py:L5 | neighbors=[hooks_lua.py] | lang=en
- "canyonbazaar_canyon_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L568 | neighbors=[canyon_map.py] | lang=en
- "canyonbazaar_canyon_map_rationale_167": "local prop point -> world (Roblox), same yaw convention as place()" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L167 | neighbors=[world()] | lang=en
- "canyonbazaar_canyon_map_rationale_171": "yaw that turns a prop's -Z front to look along (dx, dz)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L171 | neighbors=[yaw_face()] | lang=en
- "canyonbazaar_canyon_map_rationale_39": "walkable ledge width (studs) per wall: wide under the relic kiosk (east, z -60)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L39 | neighbors=[shelf1()] | lang=en
- "canyonbazaar_canyon_map_rationale_90": "spawn -> temple door sightline x at z (kept clear of tall dressing)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L90 | neighbors=[sight_x()] | lang=en
- "canyonbazaar_canyon_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L576 | neighbors=[canyon_map.py] | lang=en
- "canyonbazaar_canyon_props_dry_grass": "dry_grass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L442 | neighbors=[canyon_props.py] | lang=en
- "canyonbazaar_canyon_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L44 | neighbors=[canyon_props.py] | lang=en
- "cavemap_cave_map_rationale_237": "inner shell height above (x, z) by raycast up from the floor (Roblox y)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L237 | neighbors=[ceil_y()] | lang=en
- "cavemap_cave_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L792 | neighbors=[cave_map.py] | lang=en
- "cavemap_cave_ores_rationale_102": "pick resting with its head on the ground and the haft leaning on the heap" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L102 | neighbors=[pickaxe()] | lang=en
- "cavemap_cave_ores_rationale_112": "heap of broken ore: graded angular host lumps with metallic seams and set-in ore" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L112 | neighbors=[ore_pile()] | lang=en
- "cavemap_cave_ores_rationale_136": "v2 load: lumps packed into the tub mouth (heaped in the middle), seams + set-in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L136 | neighbors=[cart_load()] | lang=en
- "cavemap_cave_ores_rationale_17": "angular broken-rock lump: a hull of few points (big flat fracture faces), slight" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L17 | neighbors=[_lump()] | lang=en
- "cavemap_cave_ores_rationale_26": "the heap's hidden-gap filler: a lumpy dome of broken rock with ore-seam faces (b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L26 | neighbors=[mound()] | lang=en
- "cavemap_cave_ores_rationale_48": "one ore lump: host rock faces + metallic ore-seam faces (noise) + blocky ore cry" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L48 | neighbors=[ore_lump()] | lang=en
- "cavemap_cave_ores_rationale_77": "crystal cluster: n banded crystals fanning from one root, tallest at the centre" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L77 | neighbors=[druse()] | lang=en
- "cavemap_cave_ores_rationale_87": "square-mouth shovel: dished steel blade + socket, ash shaft, D grip; foot = blad" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L87 | neighbors=[shovel()] | lang=en
- "cavemap_cave_paint_block": "block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_paint.py:L14 | neighbors=[cave_paint.py] | lang=en
- "cavemap_cave_props_flat": "flat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L48 | neighbors=[cave_props.py] | lang=en
- "cavemap_cave_props_rationale_79": "low-frequency noise displacement along vertex normals (organic surfaces)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L79 | neighbors=[jitter()] | lang=en
- "cavemap_cave_props_rock_dim": "rock_dim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L198 | neighbors=[cave_props.py] | lang=en
- "cavemap_cave_props2_plank": "plank()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L7 | neighbors=[cave_props2.py] | lang=en
- "cavemap_cave_props2_rationale_106": "ore heaped in the tub (cave_ores replaces this with the v2 load)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L106 | neighbors=[cart_load()] | lang=en
- "cavemap_cave_props2_rationale_115": "square chamfered post on a cairn footing, crossarm with angle brace, hanging lan" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L115 | neighbors=[mine_lantern_post()] | lang=en
- "cavemap_cave_props2_rationale_128": "3-storey mining scaffold against a wall (back = +Z): round posts, plank decks wi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L128 | neighbors=[scaffold()] | lang=pt
- "cavemap_cave_props2_rationale_13": "hanging oil lantern: ring hook, vented cap, 4 cage bars round a GLOWING glass, b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L13 | neighbors=[oil_lantern()] | lang=pt
- "cavemap_cave_props2_rationale_163": "chasm rope bridge (span along Z): end post pairs with rope wraps and stakes, irr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L163 | neighbors=[rope_bridge()] | lang=en
- "cavemap_cave_props2_rationale_188": "low boardwalk to the islet (span along Z): log piles with iron bands, stringers," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L188 | neighbors=[plank_bridge()] | lang=en
- "cavemap_cave_props2_rationale_204": "stack of 3 braced crates (frame battens + diagonal brace on the faces) with a pi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L204 | neighbors=[crates()] | lang=en
- "cavemap_cave_props2_rationale_220": "three staved barrels (bulged lathe, iron hoops, lid), one lying on its side" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L220 | neighbors=[barrels()] | lang=en
- "cavemap_cave_props2_rationale_231": "heap of broken ore with glowing crystal chunks and a shovel stuck in it" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L231 | neighbors=[ore_pile()] | lang=en
- "cavemap_cave_props2_rationale_24": "tunnel timber set: two splayed round posts on footing stones, a cap log, knee br" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L24 | neighbors=[mine_frame()] | lang=pt
- "cavemap_cave_props2_rationale_244": "timber rack with hung pickaxes and shovels, a coil of rope and a lantern" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L244 | neighbors=[tool_rack()] | lang=en
- "cavemap_cave_props2_rationale_46": "6-stud track: two I-profile rails on 3 bevelled sleepers with spike heads, on a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L46 | neighbors=[rail_seg()] | lang=en
- "cavemap_cave_props2_rationale_60": "end-of-track stop: two posts with back struts, a cross beam with iron bumper pad" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L60 | neighbors=[rail_buffer()] | lang=en
- "cavemap_cave_props2_rationale_80": "riveted tub on a timber chassis, 4 flanged wheels on axles, couplers, rolled rim" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L80 | neighbors=[mine_cart()] | lang=pt
- "cavemap_cave_props3_rationale_133": "A-frame canvas tent: ridge log on X-poles, two canvas slopes sagging between the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L133 | neighbors=[camp_tent()] | lang=en
- "cavemap_cave_props3_rationale_15": "overlapping board-and-batten shed roof falling to the front, with a fascia board" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L15 | neighbors=[shed_roof()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-160.json

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
