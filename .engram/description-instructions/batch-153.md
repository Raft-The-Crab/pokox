# Node Description Batch 154 of 207

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

- "brick_frost_mammoth_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L28 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_rationale_247": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L247 | neighbors=[build()]
- "brick_frost_mammoth_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L31 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L36 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_surf_z": "surf_z()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L138 | neighbors=[frost_mammoth_brick.py]
- "brick_frost_mammoth_brick_xidx": "xidx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L143 | neighbors=[frost_mammoth_brick.py]
- "brick_gate_brick_flame": "flame()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/gate_brick.py:L8 | neighbors=[gate_brick.py]
- "brick_kraken_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L40 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_front": "front()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L174 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L23 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_last": "last()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L227 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_paint_front": "paint_front()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L177 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L30 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L33 | neighbors=[kraken_brick.py]
- "brick_kraken_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L38 | neighbors=[kraken_brick.py]
- "brick_kraken_post_fit": "fit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_post.py:L48 | neighbors=[kraken_post.py]
- "brick_kraken_post_fx": "fx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_post.py:L13 | neighbors=[kraken_post.py]
- "brick_kraken_post_rationale_1": "Post pass for kraken.py (self-contained: copy kraken.py + kraken_post.py togethe" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_post.py:L1 | neighbors=[kraken_post.py]
- "brick_kraken_post_view": "view()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_post.py:L34 | neighbors=[kraken_post.py]
- "brick_lich_king_brick_axf": "AXF()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L320 | neighbors=[lich_king_brick.py]
- "brick_lich_king_brick_boxa": "boxa()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L44 | neighbors=[lich_king_brick.py]
- "brick_lich_king_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L24 | neighbors=[lich_king_brick.py]
- "brick_lich_king_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L77 | neighbors=[lich_king_brick.py]
- "brick_lich_king_brick_rob_pt": "rob_pt()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L550 | neighbors=[lich_king_brick.py]
- "brick_lich_king_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L37 | neighbors=[lich_king_brick.py]
- "brick_lich_king_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L42 | neighbors=[lich_king_brick.py]
- "brick_living_armor_brick_band": "band()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L95 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L45 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_boxa": "boxa()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L47 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_col4": "col4()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L58 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L23 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L94 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L63 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_rationale_383": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L383 | neighbors=[build()]
- "brick_living_armor_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L33 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_sd_ells": "sd_ellS()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L38 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L43 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_sup": "sup()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L73 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_tw": "tw()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L483 | neighbors=[living_armor_brick.py]
- "brick_living_armor_brick_twist": "twist()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L89 | neighbors=[living_armor_brick.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-153.json

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
