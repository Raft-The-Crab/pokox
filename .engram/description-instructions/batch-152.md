# Node Description Batch 153 of 207

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

- "brick_abyssal_angler_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L25 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L67 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_patches": "patches()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L88 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_rationale_296": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L296 | neighbors=[build()]
- "brick_abyssal_angler_brick_rim": "rim()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L127 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L34 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_side_row": "side_row()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L152 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L39 | neighbors=[abyssal_angler_brick.py]
- "brick_arcane_train_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L219 | neighbors=[arcane_train_brick.py]
- "brick_arcane_train_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L34 | neighbors=[arcane_train_brick.py]
- "brick_arcane_train_brick_cyly": "cyly()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L39 | neighbors=[arcane_train_brick.py]
- "brick_arcane_train_brick_cylz": "cylz()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L37 | neighbors=[arcane_train_brick.py]
- "brick_arcane_train_brick_dome": "dome()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L43 | neighbors=[arcane_train_brick.py]
- "brick_arcane_train_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L24 | neighbors=[arcane_train_brick.py]
- "brick_arcane_train_brick_rationale_172": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L172 | neighbors=[build()]
- "brick_arcane_train_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L220 | neighbors=[arcane_train_brick.py]
- "brick_bone_hydra_brick_bez": "bez()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L139 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L48 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L230 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L24 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_l2w": "L2W_()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L522 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L41 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L46 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_t": "T_()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L527 | neighbors=[bone_hydra_brick.py]
- "brick_bone_hydra_brick_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L196 | neighbors=[bone_hydra_brick.py]
- "brick_ember_dragon_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L45 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_dil": "_dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L290 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_h": "h_()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L456 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L25 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L61 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_prof": "prof()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L120 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_proft": "profT()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L128 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L38 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L43 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_unrec": "unrec()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L33 | neighbors=[ember_dragon_brick.py]
- "brick_ember_dragon_brick_w": "_w()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L205 | neighbors=[ember_dragon_brick.py]
- "brick_frost_mammoth_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L38 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_col4": "col4()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L52 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_hashv": "hashv()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L55 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L22 | neighbors=[frost_mammoth_brick.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-152.json

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
