# Node Description Batch 92 of 207

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "brick_abyssal_angler_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L348 | neighbors=[abyssal_angler_brick.py, B()]
- "brick_abyssal_angler_brick_side_x": "side_x()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L56 | neighbors=[abyssal_angler_brick.py, ix()]
- "brick_abyssal_angler_brick_tooth": "tooth()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L110 | neighbors=[abyssal_angler_brick.py, put()]
- "brick_abyssal_angler_brick_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L59 | neighbors=[abyssal_angler_brick.py, ix()]
- "brick_arcane_train_brick_disc_x": "disc_x()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L41 | neighbors=[arcane_train_brick.py, wheel()]
- "brick_arcane_train_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L165 | neighbors=[arcane_train_brick.py, build()]
- "brick_arcane_train_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L164 | neighbors=[arcane_train_brick.py, build()]
- "brick_arcane_train_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L30 | neighbors=[arcane_train_brick.py, put()]
- "brick_arcane_train_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L32 | neighbors=[arcane_train_brick.py, newid()]
- "brick_arcane_train_brick_wheel": "wheel()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L263 | neighbors=[arcane_train_brick.py, disc_x()]
- "brick_bone_hydra_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L467 | neighbors=[bone_hydra_brick.py, render_all()]
- "brick_bone_hydra_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L57 | neighbors=[bone_hydra_brick.py, cap()]
- "brick_bone_hydra_brick_chest_z": "chest_z()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L129 | neighbors=[bone_hydra_brick.py, on_chest()]
- "brick_bone_hydra_brick_crack": "crack()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L378 | neighbors=[bone_hydra_brick.py, full()]
- "brick_bone_hydra_brick_dil": "dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L67 | neighbors=[bone_hydra_brick.py, head()]
- "brick_bone_hydra_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L414 | neighbors=[bone_hydra_brick.py, build()]
- "brick_bone_hydra_brick_j2l": "J2L()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L529 | neighbors=[bone_hydra_brick.py, head()]
- "brick_bone_hydra_brick_keep_main": "keep_main()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L345 | neighbors=[bone_hydra_brick.py, full()]
- "brick_bone_hydra_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L413 | neighbors=[bone_hydra_brick.py, build()]
- "brick_bone_hydra_brick_on_chest": "on_chest()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L138 | neighbors=[bone_hydra_brick.py, chest_z()]
- "brick_bone_hydra_brick_tail_at": "tail_at()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L208 | neighbors=[bone_hydra_brick.py, nrm()]
- "brick_bone_hydra_brick_unrec": "unrec()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L31 | neighbors=[bone_hydra_brick.py, head()]
- "brick_ember_dragon_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L388 | neighbors=[ember_dragon_brick.py, render_all()]
- "brick_ember_dragon_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L57 | neighbors=[ember_dragon_brick.py, sd_chain()]
- "brick_ember_dragon_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L330 | neighbors=[ember_dragon_brick.py, build()]
- "brick_ember_dragon_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L329 | neighbors=[ember_dragon_brick.py, build()]
- "brick_ember_dragon_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L34 | neighbors=[ember_dragon_brick.py, tri()]
- "brick_ember_dragon_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L389 | neighbors=[ember_dragon_brick.py, B()]
- "brick_ember_dragon_brick_sd_cap": "sd_cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L47 | neighbors=[ember_dragon_brick.py, sd_chain()]
- "brick_ember_dragon_brick_top_at": "top_at()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L260 | neighbors=[ember_dragon_brick.py, xo()]
- "brick_ember_dragon_brick_tri": "tri()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L208 | neighbors=[ember_dragon_brick.py, put()]
- "brick_ember_dragon_brick_xo": "xo()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L75 | neighbors=[ember_dragon_brick.py, top_at()]
- "brick_frost_mammoth_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L294 | neighbors=[frost_mammoth_brick.py, render_all()]
- "brick_frost_mammoth_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L51 | neighbors=[frost_mammoth_brick.py, chain_t()]
- "brick_frost_mammoth_brick_chain_t": "chain_t()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L40 | neighbors=[frost_mammoth_brick.py, chain()]
- "brick_frost_mammoth_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L240 | neighbors=[frost_mammoth_brick.py, build()]
- "brick_frost_mammoth_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L239 | neighbors=[frost_mammoth_brick.py, build()]
- "brick_frost_mammoth_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L295 | neighbors=[frost_mammoth_brick.py, B()]
- "brick_kraken_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L357 | neighbors=[kraken_brick.py, render_all()]
- "brick_kraken_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L43 | neighbors=[kraken_brick.py, chain()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-091.json

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
