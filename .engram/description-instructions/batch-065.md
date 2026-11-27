# Node Description Batch 66 of 209

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

- "brick_swamp_croc_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L40 | neighbors=[swamp_croc_brick.py, cap(), leg()]
- "brick_swamp_croc_brick_top_at": "top_at()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L57 | neighbors=[swamp_croc_brick.py, pyramid(), prof()]
- "brick_terrain_brick_cliff_mask": "cliff_mask()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L28 | neighbors=[terrain_brick.py, cliff(), waterfall()]
- "brick_terrain_brick_foot_rocks": "foot_rocks()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L60 | neighbors=[terrain_brick.py, cliff(), waterfall()]
- "brick_terrain_brick_grass_cap": "grass_cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L46 | neighbors=[terrain_brick.py, cliff(), waterfall()]
- "brick_tower_brick": "tower_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tower_brick.py:L1 | neighbors=[flame(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "brick_venom_widow_brick_eye": "eye()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L116 | neighbors=[venom_widow_brick.py, put(), zsurf()]
- "brick_war_mech_brick_finger": "finger()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L248 | neighbors=[war_mech_brick.py, obox(), put()]
- "brick_war_mech_brick_rivets": "rivets()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L76 | neighbors=[war_mech_brick.py, cell(), put()]
- "bytecode_bytecode_branch_offset": "branch_offset()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L38 | neighbors=[bytecode.cpp, disassemble_bytecode(), validate_bytecode()]
- "bytecode_bytecode_long_offset": "long_offset()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L28 | neighbors=[bytecode.cpp, disassemble_bytecode(), validate_bytecode()]
- "cad_skill_main_gridfinity_compartments": "_Compartments" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L81 | neighbors=[gridfinity.py, NamedTuple, .add_compartments()]
- "cad_skill_main_gridfinity_cylinderpocket": "_CylinderPocket" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L90 | neighbors=[gridfinity.py, NamedTuple, .add_cylinder_pocket()]
- "cad_skill_main_gridfinity_gridfinitybin_add_finger_notch": ".add_finger_notch()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L305 | neighbors=[GridfinityBin, _Notch, U-shaped scallop cut into one side wall…]
- "cad_skill_main_gridfinity_gridfinitybin_add_polygon_pocket": ".add_polygon_pocket()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L253 | neighbors=[GridfinityBin, _PolygonPocket, Cavity with an arbitrary closed outline…]
- "cad_skill_main_gridfinity_gridfinitybin_cell_centers": "._cell_centers()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L469 | neighbors=[GridfinityBin, ._base_cells(), ._base_hole_cutter()]
- "cad_skill_main_gridfinity_gridfinitybin_check_depth": "._check_depth()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L421 | neighbors=[GridfinityBin, GridfinityError, ._validate()]
- "cad_skill_main_gridfinity_gridfinitybin_compartment_size": "._compartment_size()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L427 | neighbors=[GridfinityBin, ._compartment_solids(), ._validate()]
- "cad_skill_main_gridfinity_gridfinitybin_cylinder_cut": "._cylinder_cut()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L541 | neighbors=[GridfinityBin, .build(), ._cylinder_drop()]
- "cad_skill_main_gridfinity_gridfinitybin_label_shelf": "._label_shelf()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L609 | neighbors=[GridfinityBin, ._compartment_solids(), 45-degree triangular label shelf hangin…]
- "cad_skill_main_gridfinity_gridfinitybin_lip_cut": "._lip_cut()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L509 | neighbors=[GridfinityBin, .build(), Stacking lip: the mirrored base profile…]
- "cad_skill_main_gridfinity_gridfinitybin_pocket_cut": "._pocket_cut()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L525 | neighbors=[GridfinityBin, .build(), _rounded_rect()]
- "cad_skill_main_gridfinity_gridfinitybin_scoop": "._scoop()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L596 | neighbors=[GridfinityBin, ._compartment_solids(), Concave quarter-round ramp along a comp…]
- "cad_skill_main_gridfinity_notch": "_Notch" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L99 | neighbors=[gridfinity.py, .add_finger_notch(), NamedTuple]
- "cad_skill_main_gridfinity_pocket": "_Pocket" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L67 | neighbors=[gridfinity.py, .add_pocket(), NamedTuple]
- "cad_skill_main_gridfinity_polygonpocket": "_PolygonPocket" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L75 | neighbors=[gridfinity.py, .add_polygon_pocket(), NamedTuple]
- "cad_skill_main_mating_overlap": "overlap()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L21 | neighbors=[mating.py, check_mating(), Volume in mm^3 shared by two CadQuery W…]
- "cad_skill_main_outline_from_scan_align_and_scale": "align_and_scale()" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L30 | neighbors=[outline_from_scan.py, main(), PCA-align in XY, center on the origin, …]
- "cad_skill_main_outline_from_scan_max_section_outline": "max_section_outline()" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L45 | neighbors=[outline_from_scan.py, main(), Union of horizontal sections from Z=ste…]
- "cad_skill_main_outline_from_scan_rotate_min_square": "rotate_min_square()" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L64 | neighbors=[outline_from_scan.py, main(), Angle (deg) minimizing the bounding squ…]
- "cad_skill_main_preview_add_edges": "_add_edges()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L219 | neighbors=[preview.py, Overlay edge lines detected from the de…, _render_frame()]
- "cad_skill_main_preview_nice_spacing": "_nice_spacing()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L78 | neighbors=[preview.py, _build_grid(), Pick a human-friendly grid spacing that…]
- "cad_skill_main_preview_rotation_matrix": "_rotation_matrix()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L38 | neighbors=[preview.py, Build a camera-pose matrix from elevati…, _render_frame()]
- "cad_skill_main_preview_title_from_path": "title_from_path()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L314 | neighbors=[preview.py, main(), cat_flap_cover.stl" -> "Cat Flap Cover".]
- "cad_skill_main_run_cadquery_model_new_files_by_ext": "_new_files_by_ext()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L62 | neighbors=[run_cadquery_model.py, main(), Return {ext: [paths]} in script_dir mat…]
- "candyland_candy_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L179 | neighbors=[candy_map.py, build(), station()]
- "candyland_candy_map_castle_h": "castle_h()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L97 | neighbors=[candy_map.py, dist_castle(), H()]
- "candyland_candy_map_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L248 | neighbors=[candy_map.py, fit_bad(), place()]
- "candyland_candy_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L477 | neighbors=[candy_map.py, mesh_obj(), cotton-candy cloud ring beyond the moun…]
- "candyland_candy_map_inside_one": "_inside_one()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L214 | neighbors=[candy_map.py, fit_bad(), _inb()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-065.json

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
