# Node Description Batch 46 of 209

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

- "brick_scarecrow_king_brick_chaind": "chaind()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L60 | neighbors=[scarecrow_king_brick.py, axd(), chain(), capd()]
- "brick_scarecrow_king_brick_patch": "patch()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L139 | neighbors=[scarecrow_king_brick.py, bx(), newid(), put()]
- "brick_scarecrow_king_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L43 | neighbors=[scarecrow_king_brick.py, patch(), strand(), wood()]
- "brick_scarecrow_king_brick_strand": "strand()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L182 | neighbors=[scarecrow_king_brick.py, chain(), put(), tuft()]
- "brick_scorpion_king_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L222 | neighbors=[scorpion_king_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_scorpion_king_brick_seg": "seg()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L108 | neighbors=[scorpion_king_brick.py, cap(), newid(), put()]
- "brick_storm_griffin_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L400 | neighbors=[storm_griffin_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_swamp_croc_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L245 | neighbors=[swamp_croc_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_swamp_croc_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L47 | neighbors=[swamp_croc_brick.py, leg(), pyramid(), strand()]
- "brick_swamp_croc_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L30 | neighbors=[swamp_croc_brick.py, leg(), pyramid(), tooth()]
- "brick_swamp_croc_brick_pyramid": "pyramid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L82 | neighbors=[swamp_croc_brick.py, newid(), put(), top_at()]
- "brick_swamp_croc_brick_strand": "strand()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L102 | neighbors=[swamp_croc_brick.py, newid(), xi_of(), zi_of()]
- "brick_terrain_brick_cliff": "cliff()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L67 | neighbors=[terrain_brick.py, cliff_mask(), foot_rocks(), grass_cap()]
- "brick_terrain_brick_waterfall": "waterfall()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L75 | neighbors=[terrain_brick.py, cliff_mask(), foot_rocks(), grass_cap()]
- "brick_tyrant_rex_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L303 | neighbors=[tyrant_rex_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_tyrant_rex_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L30 | neighbors=[tyrant_rex_brick.py, hide(), pyramid(), tooth()]
- "brick_tyrant_rex_brick_pyramid": "pyramid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L247 | neighbors=[tyrant_rex_brick.py, colmax(), newid(), put()]
- "brick_venom_widow_brick_band": "band()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L159 | neighbors=[venom_widow_brick.py, cap(), newid(), put()]
- "brick_venom_widow_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L208 | neighbors=[venom_widow_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_venom_widow_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L39 | neighbors=[venom_widow_brick.py, band(), chain(), spikes()]
- "brick_venom_widow_brick_spikes": "spikes()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L153 | neighbors=[venom_widow_brick.py, cap(), put(), unit()]
- "brick_volcano_tortoise_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L325 | neighbors=[volcano_tortoise_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_war_mech_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L318 | neighbors=[war_mech_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_war_mech_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L33 | neighbors=[war_mech_brick.py, finger(), newid(), rivets()]
- "brick_war_rhino_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L185 | neighbors=[war_rhino_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "bytecode_bytecode_branch": "branch()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L27 | neighbors=[bytecode.cpp, assemble_bytecode(), disassemble_bytecode(), validate_bytecode()]
- "bytecode_bytecode_mnemonic": "mnemonic()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L11 | neighbors=[bytecode.cpp, assemble_bytecode(), disassemble_bytecode(), validate_bytecode()]
- "cad_skill_main_gridfinity_corner_radii": "_corner_radii()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L106 | neighbors=[gridfinity.py, GridfinityError, .add_pocket(), Normalize scalar / 2-tuple / 4-tuple co…]
- "cad_skill_main_gridfinity_gridfinitybin_add_compartments": ".add_compartments()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L291 | neighbors=[GridfinityBin, _Compartments, GridfinityError, Classic divided storage interior: cols …]
- "cad_skill_main_gridfinity_gridfinitybin_add_cylinder_pocket": ".add_cylinder_pocket()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L264 | neighbors=[GridfinityBin, _CylinderPocket, GridfinityError, Round cavity cut from the top rim down …]
- "cad_skill_main_gridfinity_gridfinitybin_add_pocket": ".add_pocket()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L241 | neighbors=[GridfinityBin, _corner_radii(), _Pocket, Rounded-rect cavity cut from the top ri…]
- "cad_skill_main_gridfinity_gridfinitybin_check_wall_clearance": "._check_wall_clearance()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L411 | neighbors=[GridfinityBin, GridfinityError, ._validate(), Feature footprint must leave MIN_WALL o…]
- "cad_skill_main_gridfinity_gridfinitybin_cylinder_drop": "._cylinder_drop()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L537 | neighbors=[GridfinityBin, ._cylinder_cut(), ._validate(), Vertical span of the bore's cylindrical…]
- "cad_skill_main_gridfinity_rounded_rect": "_rounded_rect()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L122 | neighbors=[gridfinity.py, ._compartment_solids(), ._pocket_cut(), Draw a closed rounded-rect wire with pe…]
- "cad_skill_main_mating_check_mating": "check_mating()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L27 | neighbors=[mating.py, MatingError, overlap(), Raise MatingError unless `moving` fits …]
- "cad_skill_main_mating_matingerror": "MatingError" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L17 | neighbors=[mating.py, check_mating(), AssertionError, A 20 mm block sitting in a U socket who…]
- "cad_skill_main_preview_build_grid": "_build_grid()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L87 | neighbors=[preview.py, _nice_spacing(), _build_scene(), Create a ground-plane grid mesh at the …]
- "cad_skill_main_preview_get_font": "_get_font()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L297 | neighbors=[preview.py, Try to load a nice sans-serif font, fal…, render_multi_view(), render_single()]
- "cad_skill_main_preview_info_lines": "_info_lines()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L319 | neighbors=[preview.py, Two-line footer with dimensions, volume…, render_multi_view(), render_single()]
- "cad_skill_main_preview_main": "main()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L435 | neighbors=[preview.py, render_multi_view(), render_single(), title_from_path()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-045.json

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
