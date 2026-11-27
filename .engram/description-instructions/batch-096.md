# Node Description Batch 97 of 208

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

- "brick_scarecrow_king_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L72 | neighbors=[scarecrow_king_brick.py, patch()]
- "brick_scarecrow_king_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L484 | neighbors=[scarecrow_king_brick.py, B()]
- "brick_scorpion_king_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L270 | neighbors=[scorpion_king_brick.py, render_all()]
- "brick_scorpion_king_brick_ball": "ball()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L323 | neighbors=[scorpion_king_brick.py, sd_ell()]
- "brick_scorpion_king_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L44 | neighbors=[scorpion_king_brick.py, cap()]
- "brick_scorpion_king_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L216 | neighbors=[scorpion_king_brick.py, build()]
- "brick_scorpion_king_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L215 | neighbors=[scorpion_king_brick.py, build()]
- "brick_scorpion_king_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L52 | neighbors=[scorpion_king_brick.py, seg()]
- "brick_scorpion_king_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L271 | neighbors=[scorpion_king_brick.py, B()]
- "brick_shop_brick": "shop_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/shop_brick.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "brick_storm_griffin_brick_arm": "arm()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L321 | neighbors=[storm_griffin_brick.py, unit()]
- "brick_storm_griffin_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L451 | neighbors=[storm_griffin_brick.py, render_all()]
- "brick_storm_griffin_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L61 | neighbors=[storm_griffin_brick.py, chain_t()]
- "brick_storm_griffin_brick_chain_t": "chain_t()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L50 | neighbors=[storm_griffin_brick.py, chain()]
- "brick_storm_griffin_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L394 | neighbors=[storm_griffin_brick.py, build()]
- "brick_storm_griffin_brick_fdir": "fdir()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L324 | neighbors=[storm_griffin_brick.py, unit()]
- "brick_storm_griffin_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L393 | neighbors=[storm_griffin_brick.py, build()]
- "brick_storm_griffin_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L452 | neighbors=[storm_griffin_brick.py, B()]
- "brick_swamp_croc_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L293 | neighbors=[swamp_croc_brick.py, render_all()]
- "brick_swamp_croc_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L33 | neighbors=[swamp_croc_brick.py, leg()]
- "brick_swamp_croc_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L35 | neighbors=[swamp_croc_brick.py, chain()]
- "brick_swamp_croc_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L239 | neighbors=[swamp_croc_brick.py, build()]
- "brick_swamp_croc_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L238 | neighbors=[swamp_croc_brick.py, build()]
- "brick_swamp_croc_brick_prof": "prof()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L54 | neighbors=[swamp_croc_brick.py, top_at()]
- "brick_swamp_croc_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L294 | neighbors=[swamp_croc_brick.py, B()]
- "brick_swamp_croc_brick_tooth": "tooth()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L200 | neighbors=[swamp_croc_brick.py, put()]
- "brick_swamp_croc_brick_xi_of": "xi_of()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L100 | neighbors=[swamp_croc_brick.py, strand()]
- "brick_swamp_croc_brick_zi_of": "zi_of()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L101 | neighbors=[swamp_croc_brick.py, strand()]
- "brick_terrain_brick_rationale_101": "straight wall module (60 fine) or an L corner (arms +x and +z from a round turre" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L101 | neighbors=[wall(), Grid]
- "brick_terrain_brick_wall": "wall()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L100 | neighbors=[terrain_brick.py, straight wall module (60 fine) or an L …]
- "brick_tyrant_rex_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L351 | neighbors=[tyrant_rex_brick.py, render_all()]
- "brick_tyrant_rex_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L42 | neighbors=[tyrant_rex_brick.py, chain()]
- "brick_tyrant_rex_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L47 | neighbors=[tyrant_rex_brick.py, cap()]
- "brick_tyrant_rex_brick_colmax": "colmax()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L227 | neighbors=[tyrant_rex_brick.py, pyramid()]
- "brick_tyrant_rex_brick_edge": "edge()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L209 | neighbors=[tyrant_rex_brick.py, prof()]
- "brick_tyrant_rex_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L297 | neighbors=[tyrant_rex_brick.py, build()]
- "brick_tyrant_rex_brick_hide": "hide()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L60 | neighbors=[tyrant_rex_brick.py, put()]
- "brick_tyrant_rex_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L296 | neighbors=[tyrant_rex_brick.py, build()]
- "brick_tyrant_rex_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L55 | neighbors=[tyrant_rex_brick.py, pyramid()]
- "brick_tyrant_rex_brick_prof": "prof()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L51 | neighbors=[tyrant_rex_brick.py, edge()]

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
