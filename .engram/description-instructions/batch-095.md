# Node Description Batch 96 of 208

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

- "brick_living_armor_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L376 | neighbors=[living_armor_brick.py, build()] | lang=en
- "brick_living_armor_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L375 | neighbors=[living_armor_brick.py, build()] | lang=en
- "brick_living_armor_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L431 | neighbors=[living_armor_brick.py, B()] | lang=en
- "brick_living_armor_brick_ring": "ring()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L273 | neighbors=[living_armor_brick.py, flame()] | lang=en
- "brick_living_armor_brick_shell": "shell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L64 | neighbors=[living_armor_brick.py, seam()] | lang=en
- "brick_living_armor_brick_tuft": "tuft()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L267 | neighbors=[living_armor_brick.py, flame()] | lang=en
- "brick_mimic_chest_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L399 | neighbors=[mimic_chest_brick.py, render_all()] | lang=en
- "brick_mimic_chest_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L345 | neighbors=[mimic_chest_brick.py, build()] | lang=en
- "brick_mimic_chest_brick_lid_to_body": "lid_to_body()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L65 | neighbors=[mimic_chest_brick.py, lid_to_world()] | lang=en
- "brick_mimic_chest_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L344 | neighbors=[mimic_chest_brick.py, build()] | lang=en
- "brick_mimic_chest_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L51 | neighbors=[mimic_chest_brick.py, fang()] | lang=en
- "brick_mimic_chest_brick_planks": "planks()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L80 | neighbors=[mimic_chest_brick.py, put()] | lang=en
- "brick_props_brick_branch": "branch()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L38 | neighbors=[props_brick.py, oak()] | lang=en
- "brick_props_brick_crimson_blade": "crimson_blade()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L183 | neighbors=[props_brick.py, sleek long sword after a user reference…] | lang=en
- "brick_props_brick_gym": "gym()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L154 | neighbors=[props_brick.py, strength-sim weight station: rubber mat…] | lang=en
- "brick_props_brick_rationale_155": "strength-sim weight station: rubber mat, flat bench, rack uprights with J-hooks," | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L155 | neighbors=[gym(), Grid] | lang=en
- "brick_props_brick_rationale_184": "sleek long sword after a user reference (R=12, ~29 studs): long thin blade with" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L184 | neighbors=[crimson_blade(), Grid] | lang=en
- "brick_props_brick_rationale_231": "crystal sword after a user reference (R=16, ~22 studs): broad faceted lilac-whit" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L231 | neighbors=[void_crystal_blade(), Grid] | lang=pt
- "brick_props_brick_rationale_29": "tapered trunk: radius r0 at the base -> r1 at the top, root flare at the bottom," | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L29 | neighbors=[trunk(), Grid] | lang=en
- "brick_props_brick_rationale_313": "side-profile polygon (x, y fine coords) extruded through |Z| < z: the way to dra" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L313 | neighbors=[poly(), Grid] | lang=en
- "brick_props_brick_rationale_327": "thick polyline (bow limbs, strings, thorns) through |Z| < z." | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L327 | neighbors=[stroke(), Grid] | lang=en
- "brick_props_brick_rationale_342": "dark thorn bow (R=8): limbs curling back with silver inlay, thorn spikes off the" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L342 | neighbors=[thorn_bow(), Grid] | lang=en
- "brick_props_brick_rationale_370": "silver + gold sniper rifle, muzzle up: barrel, black muzzle brake with a glow sl" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L370 | neighbors=[sniper(), Grid] | lang=en
- "brick_props_brick_rationale_393": "white + silver sci-fi pistol, muzzle up: stepped slide with a dark slot of glowi" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L393 | neighbors=[scifi_pistol(), Grid] | lang=en
- "brick_props_brick_rationale_409": "dark assault rifle, muzzle up: body with rail teeth, orange stripes, blue checke" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L409 | neighbors=[assault_rifle(), Grid] | lang=en
- "brick_props_brick_rationale_435": "weapon traced 1:1 from a user reference (refs/<name>.npz made by scripts/trace_r" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L435 | neighbors=[traced(), Grid] | lang=en
- "brick_props_brick_rationale_47": "mossy ground disc with stepped edge + a few grass tufts so the prop sits on the" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L47 | neighbors=[grass_base(), Grid] | lang=en
- "brick_props_brick_rocks": "rocks()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L88 | neighbors=[props_brick.py, grass_base()] | lang=en
- "brick_props_brick_traced": "traced()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L434 | neighbors=[props_brick.py, weapon traced 1:1 from a user reference…] | lang=en
- "brick_props_brick_void_crystal_blade": "void_crystal_blade()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L230 | neighbors=[props_brick.py, crystal sword after a user reference (R…] | lang=en
- "brick_props_brick_well": "well()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L97 | neighbors=[props_brick.py, grass_base()] | lang=en
- "brick_scarecrow_king_brick_axd": "axd()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L229 | neighbors=[scarecrow_king_brick.py, chaind()] | lang=en
- "brick_scarecrow_king_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L483 | neighbors=[scarecrow_king_brick.py, render_all()] | lang=en
- "brick_scarecrow_king_brick_bx": "bx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L53 | neighbors=[scarecrow_king_brick.py, patch()] | lang=en
- "brick_scarecrow_king_brick_capd": "capd()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L55 | neighbors=[scarecrow_king_brick.py, chaind()] | lang=en
- "brick_scarecrow_king_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L429 | neighbors=[scarecrow_king_brick.py, build()] | lang=en
- "brick_scarecrow_king_brick_fan": "fan()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L189 | neighbors=[scarecrow_king_brick.py, tuft()] | lang=en
- "brick_scarecrow_king_brick_frame": "frame()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L22 | neighbors=[scarecrow_king_brick.py, switch the coordinate arrays every shap…] | lang=en
- "brick_scarecrow_king_brick_h3": "h3()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L65 | neighbors=[scarecrow_king_brick.py, wood()] | lang=en
- "brick_scarecrow_king_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L428 | neighbors=[scarecrow_king_brick.py, build()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-095.json

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
