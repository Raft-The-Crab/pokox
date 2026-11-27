# Node Description Batch 98 of 208

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
- "brick_war_mech_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L312 | neighbors=[war_mech_brick.py, build()]
- "brick_war_mech_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L311 | neighbors=[war_mech_brick.py, build()]
- "brick_war_mech_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L32 | neighbors=[war_mech_brick.py, put()]
- "brick_war_mech_brick_obox": "obox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L46 | neighbors=[war_mech_brick.py, finger()]
- "brick_war_mech_brick_pipe": "pipe()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L58 | neighbors=[war_mech_brick.py, cap()]
- "brick_war_mech_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L367 | neighbors=[war_mech_brick.py, B()]
- "brick_war_rhino_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L233 | neighbors=[war_rhino_brick.py, render_all()]
- "brick_war_rhino_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L41 | neighbors=[war_rhino_brick.py, chain()]
- "brick_war_rhino_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L46 | neighbors=[war_rhino_brick.py, cap()]
- "brick_war_rhino_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L179 | neighbors=[war_rhino_brick.py, build()]
- "brick_war_rhino_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L178 | neighbors=[war_rhino_brick.py, build()]
- "brick_war_rhino_brick_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L234 | neighbors=[war_rhino_brick.py, B()]
- "bytecode_bytecode_decode_bytecode": "decode_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L106 | neighbors=[bytecode.cpp, validate_bytecode()]
- "bytecode_bytecode_encode_bytecode": "encode_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L97 | neighbors=[bytecode.cpp, validate_bytecode()]
- "bytecode_bytecode_long_payload": "long_payload()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L33 | neighbors=[bytecode.cpp, assemble_bytecode()]
- "cad_skill_main_gridfinity_gridfinitybin_body": "._body()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L499 | neighbors=[GridfinityBin, .build()]
- "cad_skill_main_gridfinity_gridfinitybin_floor_z": ".floor_z()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L229 | neighbors=[GridfinityBin, Z of the interior floor: base profile p…]
- "cad_skill_main_gridfinity_gridfinitybin_max_depth": ".max_depth()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L234 | neighbors=[GridfinityBin, Deepest cavity possible from the top of…]
- "cad_skill_main_gridfinity_gridfinitybin_notch_cut": "._notch_cut()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L620 | neighbors=[GridfinityBin, .build()]
- "cad_skill_main_gridfinity_gridfinitybin_polygon_cut": "._polygon_cut()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L530 | neighbors=[GridfinityBin, .build()]
- "cad_skill_main_gridfinity_gridfinitybin_summary": ".summary()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L660 | neighbors=[GridfinityBin, One-paragraph description of the built …]
- "cad_skill_main_mesh_io_bed_fit": "bed_fit()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L94 | neighbors=[mesh_io.py, Check a part's bounding box against a b…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-097.json

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
