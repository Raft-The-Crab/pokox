# Node Description Batch 138 of 207

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

- "towncity_town_landmarks_rationale_351": "platform segment along Z (track side = +X): raised deck with stone edge + yellow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L351 | neighbors=[MB, platform_canopy()] | lang=en
- "towncity_town_landmarks_rationale_382": "town square fountain: 8-sided basin (panelled cream wall, overhanging coping, in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L382 | neighbors=[MB, fountain()] | lang=en
- "towncity_town_landmarks_rationale_423": "job board kiosk: timber frame on stone feet, shingled gable roof, a BLANK cork b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L423 | neighbors=[MB, job_board()] | lang=pt
- "towncity_town_landmarks_rationale_456": "bus shelter: steel frame, glass back + end panels, curved roof, slatted bench, B" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L456 | neighbors=[MB, bus_stop()] | lang=en
- "towncity_town_landmarks_rationale_46": "clock: cream dial, gold bezel, 12 tick marks (no numerals), two hands, centre bo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L46 | neighbors=[MB, clock_face()] | lang=en
- "towncity_town_landmarks_rationale_482": "bank: temple front on a stepped podium, 4 columns, pediment with a coin emblem," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L482 | neighbors=[MB, bank()] | lang=pt
- "towncity_town_landmarks_rationale_519": "car dealer: open-front display hall (no glass so the cars read), steel portal fr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L519 | neighbors=[MB, car_showroom()] | lang=en
- "towncity_town_landmarks_rationale_555": "cheap frame tower for the skyline ring: glass core + per-floor bands (or piers)," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L555 | neighbors=[MB, skyline()] | lang=en
- "towncity_town_landmarks_rationale_59": "an arched opening framed with voussoirs: the wall around it must be built by the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L59 | neighbors=[MB, arch_open()] | lang=en
- "towncity_town_landmarks_rationale_86": "civic hall on a podium: brick wings with arched + tall windows, cream rusticated" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L86 | neighbors=[MB, town_hall()] | lang=en
- "towncity_town_landmarks_t_point": "T_point()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L238 | neighbors=[town_landmarks.py, clock_tower()] | lang=en
- "towncity_town_map_bkit": "bkit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L216 | neighbors=[town_map.py, row()] | lang=en
- "towncity_town_map_check_rects": "check_rects()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L241 | neighbors=[town_map.py, build()] | lang=en
- "towncity_town_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L68 | neighbors=[town_map.py, place()] | lang=en
- "towncity_town_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L530 | neighbors=[town_map.py, free()] | lang=en
- "towncity_town_map_rationale_120": "crosswalk stripes across a road: stripes run along `along` ('x' = stripes parall" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L120 | neighbors=[MB, zebra()] | lang=pt
- "towncity_town_map_rationale_165": "boulevard median: raised planted strip with cream curb, breaks at the avenues an" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L165 | neighbors=[MB, median()] | lang=en
- "towncity_town_map_rationale_176": "Town Square: plaza paving rings round the fountain, 4 raised lawns with stone ed" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L176 | neighbors=[MB, square()] | lang=en
- "towncity_town_map_rationale_196": "rail corridor: two tracks along Z behind the station + buffers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L196 | neighbors=[MB, railway()] | lang=en
- "towncity_town_map_rationale_222": "lay buildings side by side from `start` (a point on the frontage line = back edg" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L222 | neighbors=[MB, row()] | lang=en
- "towncity_town_map_rationale_363": "polylines (x, z, along-dir, out-dir) on the sidewalks at 3.5 studs from the curb" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L363 | neighbors=[MB, sidewalk_lines()] | lang=en
- "towncity_town_map_rationale_453": "back alley z ~141..184 between the shop row and the south row: dumpsters, bags," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L453 | neighbors=[MB, alley()] | lang=en
- "towncity_town_map_rationale_467": "parked cars along curbs + a few cars in the lanes, the bus at its stop, taxis at" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L467 | neighbors=[MB, traffic()] | lang=en
- "towncity_town_map_rationale_49": "block rectangles (x0, x1, z0, z1) at curb height = everything that is not road" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L49 | neighbors=[MB, blocks()] | lang=en
- "towncity_town_map_rationale_86": "local (x, y, z) of a prop turned by yaw -> world offset" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L86 | neighbors=[MB, rot()] | lang=en
- "towncity_town_props_blob": "blob()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L73 | neighbors=[town_props.py, flower_box()] | lang=en
- "towncity_town_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L46 | neighbors=[town_props.py, fire_escape()] | lang=en
- "towncity_town_props_rationale_101": "a single quad facing -Z at depth z" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L101 | neighbors=[Palette, front_quad()] | lang=pt
- "towncity_town_props_rationale_105": "front wall layer (outer face at zf, WALL_T thick, back face dropped) with rectan" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L105 | neighbors=[Palette, holed_front()] | lang=en
- "towncity_town_props_rationale_120": "rooftop / wall AC: cream casing on feet, fan grille ring + hub on top, side louv" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L120 | neighbors=[Palette, ac_unit()] | lang=en
- "towncity_town_props_rationale_130": "classic timber rooftop water tank on a steel stand: staves, iron hoops, conical" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L130 | neighbors=[Palette, water_tank()] | lang=pt
- "towncity_town_props_rationale_156": "stair bulkhead: small box room with a door, coping, vent pipe" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L156 | neighbors=[Palette, roof_shed()] | lang=en
- "towncity_town_props_rationale_177": "a flower head: one 5-petal star face + a centre face, facing n (default: up, tip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L177 | neighbors=[Palette, flower()] | lang=pt
- "towncity_town_props_rationale_199": "dressing for ONE opening in a front wall whose outer face is at z = zf (front =" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L199 | neighbors=[Palette, window_unit()] | lang=en
- "towncity_town_props_rationale_248": "flat 'decal' window on a plain side / back wall: glass quad + frame ring set 0.0" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L248 | neighbors=[Palette, deco_window()] | lang=pt
- "towncity_town_props_rationale_265": "ground floor front: pilasters, bulkhead panels, display windows with mullions, r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L265 | neighbors=[Palette, shopfront()] | lang=en
- "towncity_town_props_rationale_313": "sloped striped awning (accent / cream stripes), side cheeks, scalloped valance," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L313 | neighbors=[Palette, awning_band()] | lang=en
- "towncity_town_props_rationale_341": "front facade at z = -d/2. Returns Prop with .sign (centre, size) for the blank f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L341 | neighbors=[Palette, building()] | lang=en
- "towncity_town_props_rationale_464": "iron fire escape on the back wall (+Z): landing per floor at each window pair, r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L464 | neighbors=[Palette, fire_escape()] | lang=en
- "towncity_town_props_rationale_54": "axis box between the given bounds; drop = faces to delete ('+x', '-x', '+y', '-y" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L54 | neighbors=[Palette, slab()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-137.json

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
