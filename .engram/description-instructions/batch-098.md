# Node Description Batch 99 of 209

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
- "brick_tyrant_rex_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L352 | neighbors=[tyrant_rex_brick.py, B()]
- "brick_tyrant_rex_brick_tooth": "tooth()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L203 | neighbors=[tyrant_rex_brick.py, put()]
- "brick_venom_widow_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L256 | neighbors=[venom_widow_brick.py, render_all()]
- "brick_venom_widow_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L45 | neighbors=[venom_widow_brick.py, cap()]
- "brick_venom_widow_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L202 | neighbors=[venom_widow_brick.py, build()]
- "brick_venom_widow_brick_hourglass": "hourglass()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L80 | neighbors=[venom_widow_brick.py, put()]
- "brick_venom_widow_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L201 | neighbors=[venom_widow_brick.py, build()]
- "brick_venom_widow_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L50 | neighbors=[venom_widow_brick.py, band()]
- "brick_venom_widow_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L257 | neighbors=[venom_widow_brick.py, B()]
- "brick_venom_widow_brick_unit": "unit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L152 | neighbors=[venom_widow_brick.py, spikes()]
- "brick_venom_widow_brick_zsurf": "zsurf()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L113 | neighbors=[venom_widow_brick.py, eye()]
- "brick_volcano_tortoise_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L375 | neighbors=[volcano_tortoise_brick.py, render_all()]
- "brick_volcano_tortoise_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L319 | neighbors=[volcano_tortoise_brick.py, build()]
- "brick_volcano_tortoise_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L318 | neighbors=[volcano_tortoise_brick.py, build()]
- "brick_volcano_tortoise_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L376 | neighbors=[volcano_tortoise_brick.py, B()]
- "brick_war_mech_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L366 | neighbors=[war_mech_brick.py, render_all()]
- "brick_war_mech_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L52 | neighbors=[war_mech_brick.py, pipe()]
- "brick_war_mech_brick_cell": "cell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L71 | neighbors=[war_mech_brick.py, rivets()]

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
