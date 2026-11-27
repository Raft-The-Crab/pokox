# Node Description Batch 158 of 209

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "brick_mimic_chest_brick_cube": "cube()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L48 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_dil": "_dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L304 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L24 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_nb6": "nb6()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L54 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_rationale_352": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L352 | neighbors=[build()]
- "brick_mimic_chest_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L37 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_set_body": "set_body()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L69 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_set_lid": "set_lid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L72 | neighbors=[mimic_chest_brick.py]
- "brick_mimic_chest_brick_set_world": "set_world()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L76 | neighbors=[mimic_chest_brick.py]
- "brick_props_brick_cart": "cart()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L114 | neighbors=[props_brick.py]
- "brick_props_brick_fence": "fence()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L142 | neighbors=[props_brick.py]
- "brick_props_brick_lamp": "lamp()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L133 | neighbors=[props_brick.py]
- "brick_scarecrow_king_brick_arc_d": "arc_d()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L242 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_dil": "dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L378 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L35 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_mir": "mir()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L68 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_rationale_23": "switch the coordinate arrays every shape function reads: 'world', 'body' (lean)," | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L23 | neighbors=[frame()]
- "brick_scarecrow_king_brick_rationale_436": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L436 | neighbors=[build()]
- "brick_scarecrow_king_brick_ring": "ring()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L216 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L46 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L51 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_tobody": "tobody()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L30 | neighbors=[scarecrow_king_brick.py]
- "brick_scarecrow_king_brick_tw": "tw()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L534 | neighbors=[scarecrow_king_brick.py]
- "brick_scorpion_king_brick_b3": "b3()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L163 | neighbors=[scorpion_king_brick.py]
- "brick_scorpion_king_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L36 | neighbors=[scorpion_king_brick.py]
- "brick_scorpion_king_brick_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L143 | neighbors=[scorpion_king_brick.py]
- "brick_scorpion_king_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L23 | neighbors=[scorpion_king_brick.py]
- "brick_scorpion_king_brick_rationale_223": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L223 | neighbors=[build()]
- "brick_scorpion_king_brick_rbox": "rbox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L48 | neighbors=[scorpion_king_brick.py]
- "brick_storm_griffin_brick_bb": "bb()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L505 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_dil": "dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L233 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_front_z": "front_z()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L222 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_hashv": "hashv()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L62 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L27 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_lg": "lg()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L506 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_obb": "obb()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L297 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_pdist2": "pdist2()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L65 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L34 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_rationale_401": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L401 | neighbors=[build()]
- "brick_storm_griffin_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L38 | neighbors=[storm_griffin_brick.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-157.json

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
