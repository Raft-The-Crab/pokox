# Node Description Batch 62 of 207

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

- "brick_bone_hydra_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L32 | neighbors=[bone_hydra_brick.py, dspike(), head()]
- "brick_bone_hydra_brick_rblock": "rblock()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L83 | neighbors=[bone_hydra_brick.py, full(), sl_of()]
- "brick_bone_hydra_brick_rbox": "rbox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L87 | neighbors=[bone_hydra_brick.py, full(), sl_of()]
- "brick_bone_hydra_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L468 | neighbors=[bone_hydra_brick.py, B(), WL()]
- "brick_bone_hydra_brick_w": "W()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L95 | neighbors=[bone_hydra_brick.py, sl_of(), WL()]
- "brick_bone_hydra_brick_wl": "WL()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L162 | neighbors=[bone_hydra_brick.py, render_all(), W()]
- "brick_ember_dragon_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L335 | neighbors=[ember_dragon_brick.py, exposed(), lin()]
- "brick_ember_dragon_brick_sd_chain": "sd_chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L53 | neighbors=[ember_dragon_brick.py, chain(), sd_cap()]
- "brick_gate_brick": "gate_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/gate_brick.py:L1 | neighbors=[flame(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "brick_kraken_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L310 | neighbors=[kraken_brick.py, exposed(), lin()]
- "brick_kraken_brick_ix": "ix()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L52 | neighbors=[kraken_brick.py, tentacle(), top_y()]
- "brick_lich_king_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L439 | neighbors=[lich_king_brick.py, exposed(), lin()]
- "brick_lich_king_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L46 | neighbors=[lich_king_brick.py, chain(), flames()]
- "brick_lich_king_brick_glow": "glow()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L35 | neighbors=[lich_king_brick.py, flames(), rune()]
- "brick_lich_king_brick_links": "links()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L278 | neighbors=[lich_king_brick.py, put(), surfz()]
- "brick_lich_king_brick_surfz": "surfz()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L274 | neighbors=[lich_king_brick.py, links(), ci()]
- "brick_living_armor_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L30 | neighbors=[living_armor_brick.py, flame(), seam()]
- "brick_living_armor_brick_seam": "seam()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L279 | neighbors=[living_armor_brick.py, put(), shell()]
- "brick_mimic_chest_brick_body_to_world": "body_to_world()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L64 | neighbors=[mimic_chest_brick.py, lid_to_world(), render_all()]
- "brick_mimic_chest_brick_fang": "fang()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L243 | neighbors=[mimic_chest_brick.py, newid(), put()]
- "brick_mimic_chest_brick_lid_to_world": "lid_to_world()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L68 | neighbors=[mimic_chest_brick.py, body_to_world(), lid_to_body()]
- "brick_mimic_chest_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L34 | neighbors=[mimic_chest_brick.py, fang(), planks()]
- "brick_mimic_chest_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L400 | neighbors=[mimic_chest_brick.py, B(), body_to_world()]
- "brick_props_brick_assault_rifle": "assault_rifle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L408 | neighbors=[props_brick.py, poly(), dark assault rifle, muzzle up: body wit…]
- "brick_props_brick_bush": "bush()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L77 | neighbors=[props_brick.py, grass_base(), leaf_col()]
- "brick_props_brick_leaf_col": "leaf_col()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L20 | neighbors=[props_brick.py, bush(), oak()]
- "brick_props_brick_pine": "pine()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L64 | neighbors=[props_brick.py, grass_base(), trunk()]
- "brick_props_brick_sniper": "sniper()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L369 | neighbors=[props_brick.py, silver + gold sniper rifle, muzzle up: …, poly()]
- "brick_scarecrow_king_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L64 | neighbors=[scarecrow_king_brick.py, chaind(), strand()]
- "brick_scarecrow_king_brick_tuft": "tuft()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L184 | neighbors=[scarecrow_king_brick.py, fan(), strand()]
- "brick_scarecrow_king_brick_wood": "wood()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L73 | neighbors=[scarecrow_king_brick.py, h3(), put()]
- "brick_scorpion_king_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L38 | neighbors=[scorpion_king_brick.py, chain(), seg()]
- "brick_scorpion_king_brick_joint": "joint()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L111 | neighbors=[scorpion_king_brick.py, put(), sd_ell()]
- "brick_scorpion_king_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L28 | neighbors=[scorpion_king_brick.py, joint(), seg()]
- "brick_scorpion_king_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L31 | neighbors=[scorpion_king_brick.py, ball(), joint()]
- "brick_storm_griffin_brick_unit": "unit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L308 | neighbors=[storm_griffin_brick.py, arm(), fdir()]
- "brick_swamp_croc_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L40 | neighbors=[swamp_croc_brick.py, cap(), leg()]
- "brick_swamp_croc_brick_top_at": "top_at()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L57 | neighbors=[swamp_croc_brick.py, pyramid(), prof()]
- "brick_terrain_brick_cliff_mask": "cliff_mask()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L28 | neighbors=[terrain_brick.py, cliff(), waterfall()]
- "brick_terrain_brick_foot_rocks": "foot_rocks()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L60 | neighbors=[terrain_brick.py, cliff(), waterfall()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-061.json

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
