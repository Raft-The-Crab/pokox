# Node Description Batch 97 of 209

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

- "brick_kraken_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L304 | neighbors=[kraken_brick.py, build()] | lang=en
- "brick_kraken_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L56 | neighbors=[kraken_brick.py, tentacle()] | lang=en
- "brick_kraken_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L358 | neighbors=[kraken_brick.py, B()] | lang=en
- "brick_kraken_brick_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L236 | neighbors=[kraken_brick.py, ix()] | lang=en
- "brick_lich_king_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L486 | neighbors=[lich_king_brick.py, render_all()] | lang=en
- "brick_lich_king_brick_back_layer": "back_layer()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L71 | neighbors=[lich_king_brick.py, shift()] | lang=en
- "brick_lich_king_brick_band_edge": "band_edge()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L211 | neighbors=[lich_king_brick.py, ci()] | lang=en
- "brick_lich_king_brick_cube_dil": "cube_dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L402 | neighbors=[lich_king_brick.py, shift()] | lang=en
- "brick_lich_king_brick_dil": "dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L58 | neighbors=[lich_king_brick.py, shift()] | lang=en
- "brick_lich_king_brick_ero": "ero()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L64 | neighbors=[lich_king_brick.py, shift()] | lang=en
- "brick_lich_king_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L433 | neighbors=[lich_king_brick.py, build()] | lang=en
- "brick_lich_king_brick_front_face": "front_face()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L72 | neighbors=[lich_king_brick.py, shift()] | lang=en
- "brick_lich_king_brick_front_layer": "front_layer()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L70 | neighbors=[lich_king_brick.py, shift()] | lang=en
- "brick_lich_king_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L432 | neighbors=[lich_king_brick.py, build()] | lang=en
- "brick_lich_king_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L31 | neighbors=[lich_king_brick.py, links()] | lang=en
- "brick_lich_king_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L487 | neighbors=[lich_king_brick.py, B()] | lang=en
- "brick_lich_king_brick_rune": "rune()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L243 | neighbors=[lich_king_brick.py, glow()] | lang=en
- "brick_lich_king_brick_sleeve": "sleeve()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L130 | neighbors=[lich_king_brick.py, chain()] | lang=en
- "brick_lich_king_brick_stamp": "stamp()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L173 | neighbors=[lich_king_brick.py, ci()] | lang=en
- "brick_living_armor_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L430 | neighbors=[living_armor_brick.py, render_all()] | lang=en
- "brick_living_armor_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L49 | neighbors=[living_armor_brick.py, chain()] | lang=en
- "brick_living_armor_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L54 | neighbors=[living_armor_brick.py, cap()] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-096.json

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
