# Node Description Batch 74 of 209

Engram is running in assistant/skill mode (no API key). You are the host
assistant (Claude Code / Codex / Gemini CLI). Read the prompt below and write
your JSON answer to the answer file.

## Prompt

You are documenting nodes in a knowledge graph.
For each entry below, write ONE concise factual plain-language sentence
describing what it is or does. Use only the provided context.
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

- "medievalbattle_battle_props_rationale_1155": "ridge tent (door at -Z): sagging canvas with a team hem band, closed back, front" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1155 | neighbors=[tent(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1212": "stone ring, crossed charred logs, flames, tripod with an iron pot on a chain, lo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1212 | neighbors=[campfire(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_122": "ashlar on a cylinder of radius R (flat chord blocks, random lengths per course);" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L122 | neighbors=[ashlar_ring(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1237": "iron brazier: three curled legs, riveted bowl, glowing coals and flames" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1237 | neighbors=[brazier(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1253": "plank crate: core + slat boards + iron corner brackets" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1253 | neighbors=[crate(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1277": "two crates, a barrel pair, tied sacks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1277 | neighbors=[supply_pile(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_1290": "stacked straw bales with twine bands and loose straw" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1290 | neighbors=[hay_bales(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1305": "two-wheeled cart slumped on a snapped wheel: plank bed, side stakes, shafts down" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1305 | neighbors=[broken_cart(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_1327": "A-frame rack: five spears, three swords, two team shields leaning at its foot" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1327 | neighbors=[weapon_rack(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1349": "straw dummy on a post and crossbar, twine bands, sack head, a team shield on its" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1349 | neighbors=[training_dummy(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_1362": "siege ladder leaning back by lean degrees (top toward +Z): two rails, lashed run" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1362 | neighbors=[ladder(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1373": "small battlefield litter: a dropped team shield, a dented helm, a snapped spear," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1373 | neighbors=[battle_debris(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_1389": "a field stone: a box with jittered corners and a few extra points, hulled (tight" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1389 | neighbors=[rough_stone(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_1399": "low field wall of tightly stacked rough stones (3 courses, battered), upright co" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1399 | neighbors=[drystone_wall(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1424": "a heap of fallen ashlar blocks and broken stone" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1424 | neighbors=[rubble(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1453": "one fir whorl: a star skirt (2n rim points: drooping bough tips + raised notches" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1453 | neighbors=[bough_skirt(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_147": "per-block tone from the block centre hash, mortar darker, a little grime low dow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L147 | neighbors=[ash_sh(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1474": "fir in four forms (tall spire / full / squat broad / young): tapering trunk with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1474 | neighbors=[pine(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1499": "field oak: flared, slightly twisted trunk forking into 4-5 boughs (each with a s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1499 | neighbors=[broadleaf(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1530": "charred, leafless tree: forked trunk, snapped top, crooked branches and twigs" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1530 | neighbors=[dead_tree(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1564": "shallow scorched impact scar (modelled, smooth 32-sided), char centre, scattered" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1564 | neighbors=[scorch(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_1586": "courtyard well: ring of ashlar blocks with a coping ring, oak posts, a little sl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1586 | neighbors=[well(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_163": "a wall of real stone blocks from (x, z) a to b: top(t) = top height at distance" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L163 | neighbors=[course_wall(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_200": "crenellation along X centred at x = 0, merlons with cut arrow slits (every other" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L200 | neighbors=[merlon_row(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_211": "stepped corbel blocks along X under a projecting parapet, projecting from z0 by" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L211 | neighbors=[corbels(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_219": "dressed frame round a CUT arrow slit (front = -Z before yaw): jambs, lintel, sil" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L219 | neighbors=[slit_frame(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_227": "add an arrow-slit cutter box (front = -Z before yaw, from 0.3 out to depth in) i" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L227 | neighbors=[slit_cutter(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_236": "move a temp Prop built in canonical orientation (front face at -Z) into P, turne" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L236 | neighbors=[merge(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_242": "painted heater shield facing -Z before yaw: oak backing rim, painted field, chev" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L242 | neighbors=[heater_shield(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_267": "wall segment along X (outside = -Z): battered plinth, ashlar both faces, corbell" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L267 | neighbors=[curtain_wall(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_293": "round tower: battered base, ashlar drum with CUT arrow slits, corbel ring, crene" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L293 | neighbors=[tower_body(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_353": "closed solid of an outline (XY) from z0 to z1; y0 extends the feet down" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L353 | neighbors=[outline_prism(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_367": "wedge stones round an arch (face plane at z, half proud), bigger keystone, jamb" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L367 | neighbors=[voussoirs(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_386": "corbelled crenellated parapet on a front face at z = -d (canonical), wall-walk a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L386 | neighbors=[parapet_front(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_399": "the keep gate (outside = -Z): ashlar block with a CUT arched passage, voussoirs," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L399 | neighbors=[gatehouse(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_44": "roll (Z) first, then pitch (X), then yaw (Y, +yaw turns the -Z front toward -X)," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L44 | neighbors=[T(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_442": "one face of the donjon in canonical orientation (face plane z = -hw): ashlar wit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L442 | neighbors=[donjon_face(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_470": "the great keep tower (front = -Z faces the courtyard): battered plinth, ashlar," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L470 | neighbors=[donjon(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_509": "the donjon's crown (separate kit piece, same origin): corbelled parapets with sh" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L509 | neighbors=[donjon_top(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_53": "bm built along +X from 0..L (Y up): rotate X onto b - a (Y stays as up as possib" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L53 | neighbors=[frame_to(), Palette, Sh] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-073.json

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
