# Node Description Batch 158 of 208

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

- "brick_storm_griffin_brick_sd_ells": "sd_ells()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L43 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L48 | neighbors=[storm_griffin_brick.py]
- "brick_storm_griffin_brick_zdes": "zdes()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L225 | neighbors=[storm_griffin_brick.py]
- "brick_swamp_croc_brick_hsh": "hsh()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L48 | neighbors=[swamp_croc_brick.py]
- "brick_swamp_croc_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L24 | neighbors=[swamp_croc_brick.py]
- "brick_swamp_croc_brick_rationale_246": "exposed brick faces as flat quads; UVs = brick coords / 16 (one stud per 2x2 bri" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L246 | neighbors=[build()]
- "brick_swamp_croc_brick_sup": "sup()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L56 | neighbors=[swamp_croc_brick.py]
- "brick_terrain_brick_strata": "strata()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L24 | neighbors=[terrain_brick.py]
- "brick_tower_brick_flame": "flame()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tower_brick.py:L8 | neighbors=[tower_brick.py]
- "brick_tyrant_rex_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L40 | neighbors=[tyrant_rex_brick.py]
- "brick_tyrant_rex_brick_hsh": "hsh()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L56 | neighbors=[tyrant_rex_brick.py]
- "brick_tyrant_rex_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L24 | neighbors=[tyrant_rex_brick.py]
- "brick_tyrant_rex_brick_rationale_304": "exposed brick faces as flat quads; UVs = brick coords / 16 (one stud per 2x2 bri" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L304 | neighbors=[build()]
- "brick_tyrant_rex_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L33 | neighbors=[tyrant_rex_brick.py]
- "brick_tyrant_rex_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L38 | neighbors=[tyrant_rex_brick.py]
- "brick_tyrant_rex_brick_tsup": "tsup()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L85 | neighbors=[tyrant_rex_brick.py]
- "brick_venom_widow_brick_at": "at()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L167 | neighbors=[venom_widow_brick.py]
- "brick_venom_widow_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L23 | neighbors=[venom_widow_brick.py]
- "brick_venom_widow_brick_rationale_209": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L209 | neighbors=[build()]
- "brick_venom_widow_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L32 | neighbors=[venom_widow_brick.py]
- "brick_venom_widow_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L37 | neighbors=[venom_widow_brick.py]
- "brick_volcano_tortoise_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L44 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_cell": "cell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L178 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_hashv": "hashv()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L51 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_head_frame": "head_frame()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L63 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L25 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_prof": "prof()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L212 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L34 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_rationale_326": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L326 | neighbors=[build()]
- "brick_volcano_tortoise_brick_sd_cap": "sd_cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L46 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L37 | neighbors=[volcano_tortoise_brick.py]
- "brick_volcano_tortoise_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L42 | neighbors=[volcano_tortoise_brick.py]
- "brick_war_mech_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L37 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_carve": "carve()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L35 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_cylx": "cylx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L41 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_cyly": "cyly()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L44 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_cylz": "cylz()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L45 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_gear": "gear()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L62 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L24 | neighbors=[war_mech_brick.py]
- "brick_war_mech_brick_rationale_319": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L319 | neighbors=[build()]

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
