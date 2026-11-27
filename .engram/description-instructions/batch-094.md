# Node Description Batch 95 of 208

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
- "brick_kraken_brick_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L92 | neighbors=[kraken_brick.py, tentacle()]
- "brick_kraken_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L48 | neighbors=[kraken_brick.py, cap()]
- "brick_kraken_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L305 | neighbors=[kraken_brick.py, build()]
- "brick_kraken_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L304 | neighbors=[kraken_brick.py, build()]
- "brick_kraken_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L56 | neighbors=[kraken_brick.py, tentacle()]
- "brick_kraken_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L358 | neighbors=[kraken_brick.py, B()]
- "brick_kraken_brick_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L236 | neighbors=[kraken_brick.py, ix()]
- "brick_lich_king_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L486 | neighbors=[lich_king_brick.py, render_all()]
- "brick_lich_king_brick_back_layer": "back_layer()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L71 | neighbors=[lich_king_brick.py, shift()]
- "brick_lich_king_brick_band_edge": "band_edge()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L211 | neighbors=[lich_king_brick.py, ci()]
- "brick_lich_king_brick_cube_dil": "cube_dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L402 | neighbors=[lich_king_brick.py, shift()]
- "brick_lich_king_brick_dil": "dil()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L58 | neighbors=[lich_king_brick.py, shift()]
- "brick_lich_king_brick_ero": "ero()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L64 | neighbors=[lich_king_brick.py, shift()]
- "brick_lich_king_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L433 | neighbors=[lich_king_brick.py, build()]
- "brick_lich_king_brick_front_face": "front_face()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L72 | neighbors=[lich_king_brick.py, shift()]
- "brick_lich_king_brick_front_layer": "front_layer()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L70 | neighbors=[lich_king_brick.py, shift()]
- "brick_lich_king_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L432 | neighbors=[lich_king_brick.py, build()]
- "brick_lich_king_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L31 | neighbors=[lich_king_brick.py, links()]
- "brick_lich_king_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L487 | neighbors=[lich_king_brick.py, B()]
- "brick_lich_king_brick_rune": "rune()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L243 | neighbors=[lich_king_brick.py, glow()]
- "brick_lich_king_brick_sleeve": "sleeve()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L130 | neighbors=[lich_king_brick.py, chain()]
- "brick_lich_king_brick_stamp": "stamp()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L173 | neighbors=[lich_king_brick.py, ci()]
- "brick_living_armor_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L430 | neighbors=[living_armor_brick.py, render_all()]
- "brick_living_armor_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L49 | neighbors=[living_armor_brick.py, chain()]
- "brick_living_armor_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L54 | neighbors=[living_armor_brick.py, cap()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-094.json

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
