# Node Description Batch 166 of 208

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

- "evaluator_evaluator_name": "name()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L336 | neighbors=[evaluator.cpp]
- "evaluator_evaluator_supported_float": "supported_float()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L141 | neighbors=[evaluator.cpp]
- "examples_arctic_fox_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L26 | neighbors=[arctic_fox.py]
- "examples_arctic_fox_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L86 | neighbors=[arctic_fox.py]
- "examples_arctic_fox_pounce": "pounce()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L104 | neighbors=[arctic_fox.py]
- "examples_arctic_fox_wag": "wag()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L117 | neighbors=[arctic_fox.py]
- "examples_arctic_fox_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L94 | neighbors=[arctic_fox.py]
- "examples_bunny_big_jump": "big_jump()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L119 | neighbors=[bunny.py]
- "examples_bunny_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L26 | neighbors=[bunny.py]
- "examples_bunny_ear_wiggle": "ear_wiggle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L132 | neighbors=[bunny.py]
- "examples_bunny_hop": "hop()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L108 | neighbors=[bunny.py]
- "examples_bunny_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L99 | neighbors=[bunny.py]
- "examples_cat_flap_cover_rationale_1": "Cover plate for the hole left by a removed Cat Mate 4-way cat flap.  Sticks on w" | kind=entity | source=.agents/skills/cad-skill-main/examples/cat_flap_cover.py:L1 | neighbors=[cat_flap_cover.py]
- "examples_desk_cable_tray_rationale_1": "Under-desk cable tray, built from identical segments.  A 400 mm tray does not fi" | kind=entity | source=.agents/skills/cad-skill-main/examples/desk_cable_tray.py:L1 | neighbors=[desk_cable_tray.py]
- "examples_duck_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L25 | neighbors=[duck.py]
- "examples_duck_flap": "flap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L102 | neighbors=[duck.py]
- "examples_duck_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L80 | neighbors=[duck.py]
- "examples_duck_quack": "quack()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L94 | neighbors=[duck.py]
- "examples_duck_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L86 | neighbors=[duck.py]
- "examples_mx_master3_bin_3x3_rot": "_rot()" | kind=code-symbol | source=.agents/skills/cad-skill-main/examples/mx_master3_bin_3x3.py:L77 | neighbors=[mx_master3_bin_3x3.py]
- "examples_owl_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L25 | neighbors=[owl.py]
- "examples_owl_flap": "flap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L118 | neighbors=[owl.py]
- "examples_owl_head_turn": "head_turn()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L124 | neighbors=[owl.py]
- "examples_owl_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L103 | neighbors=[owl.py]
- "examples_owl_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L110 | neighbors=[owl.py]
- "examples_penguin_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L26 | neighbors=[penguin.py]
- "examples_penguin_flap": "flap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L128 | neighbors=[penguin.py]
- "examples_penguin_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L99 | neighbors=[penguin.py]
- "examples_penguin_slide": "slide()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L115 | neighbors=[penguin.py]
- "examples_penguin_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L106 | neighbors=[penguin.py]
- "examples_red_panda_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L28 | neighbors=[red_panda.py]
- "examples_red_panda_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L107 | neighbors=[red_panda.py]
- "examples_red_panda_pounce": "pounce()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L125 | neighbors=[red_panda.py]
- "examples_red_panda_wag": "wag()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L138 | neighbors=[red_panda.py]
- "examples_red_panda_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L115 | neighbors=[red_panda.py]
- "extensions_superpowers_bootstrapskillpath": "bootstrapSkillPath" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L12 | neighbors=[superpowers.ts]
- "extensions_superpowers_extensiondir": "extensionDir" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L9 | neighbors=[superpowers.ts]
- "extensions_superpowers_firstnoncompactionsummaryindex": "firstNonCompactionSummaryIndex()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L110 | neighbors=[superpowers.ts]
- "extensions_superpowers_messagecontainsbootstrap": "messageContainsBootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L95 | neighbors=[superpowers.ts]
- "extensions_superpowers_packageroot": "packageRoot" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L10 | neighbors=[superpowers.ts]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-165.json

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
