# Node Description Batch 100 of 209

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
- "cad_skill_main_mesh_io_estimate_mass": "estimate_mass()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L119 | neighbors=[mesh_io.py, Approximate printed mass in grams (defa…]
- "cad_skill_main_mesh_io_load_mesh": "load_mesh()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L13 | neighbors=[mesh_io.py, Load an STL file via trimesh.      Rais…]
- "cad_skill_main_mesh_io_parse_bed": "parse_bed()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L69 | neighbors=[mesh_io.py, Turn a printer name, "WxDxH" or a singl…]
- "cad_skill_main_outline_from_scan_recentered": "recentered()" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L77 | neighbors=[outline_from_scan.py, main()]
- "cad_skill_main_run_cadquery_model_append_stderr": "_append_stderr()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L58 | neighbors=[run_cadquery_model.py, main()]
- "cad_skill_main_run_cadquery_model_sibling": "_sibling()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L54 | neighbors=[run_cadquery_model.py, _process_stls()]
- "cad_skill_main_stl_to_3mf_convert": "convert()" | kind=code-symbol | source=.agents/skills/cad-skill-main/stl_to_3mf.py:L27 | neighbors=[stl_to_3mf.py, main()]
- "cad_skill_main_stl_to_3mf_main": "main()" | kind=code-symbol | source=.agents/skills/cad-skill-main/stl_to_3mf.py:L40 | neighbors=[stl_to_3mf.py, convert()]
- "candyland_candy_map_axis_coords": "axis_coords()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L261 | neighbors=[candy_map.py, ground()]
- "candyland_candy_map_bump": "bump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L81 | neighbors=[candy_map.py, H0()]
- "candyland_candy_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L163 | neighbors=[candy_map.py, build()]
- "candyland_candy_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L213 | neighbors=[candy_map.py, _inside_one()]
- "candyland_candy_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L117 | neighbors=[candy_map.py, place()]
- "candyland_candy_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L662 | neighbors=[candy_map.py, free()]
- "candyland_candy_map_moat": "moat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L420 | neighbors=[candy_map.py, mesh_obj()]
- "candyland_candy_map_rationale_169": "trails, plazas, river, castle hill, falls: nothing scattered there" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L169 | neighbors=[on_hard(), MB]
- "candyland_candy_map_rationale_295": "one board tile: the polyline section s0..s1 (arc length) across `width`, draped" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L295 | neighbors=[drape_strip(), MB]
- "candyland_candy_map_rationale_329": "board-game tile runs (TILE long, 0.7 gaps) + sprinkles on them; round stop plaza" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L329 | neighbors=[trails(), MB]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-099.json

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
