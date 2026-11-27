# Node Description Batch 19 of 208

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
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "bytecode_bytecode_disassemble_bytecode": "disassemble_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L191 | neighbors=[bytecode.cpp, assemble_bytecode(), branch(), branch_offset(), long_offset(), mnemonic()] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_compartment_solids": "._compartment_solids()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L569 | neighbors=[GridfinityBin, .build(), ._compartment_size(), ._label_shelf(), ._scoop(), _rounded_rect()] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_validate": "._validate()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L321 | neighbors=[GridfinityBin, .build(), ._check_depth(), ._check_wall_clearance(), ._compartment_size(), ._cylinder_drop()] | lang=en
- "cad_skill_main_mesh_io": "mesh_io.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L1 | neighbors=[bed_fit(), estimate_mass(), load_mesh(), parse_bed(), Pure trimesh STL loading with validatio…, 2680d0e Pushed an update.] | lang=en
- "cad_skill_main_preview_render_multi_view": "render_multi_view()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L361 | neighbors=[preview.py, main(), Render 6-view technical preview in a 3x…, _build_scene(), _get_font(), _info_lines()] | lang=en
- "cad_skill_main_run_cadquery_model": "run_cadquery_model.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L1 | neighbors=[_append_stderr(), main(), _new_files_by_ext(), _process_stls(), _sibling(), 2680d0e Pushed an update.] | lang=en
- "candyland_candy_props_drawbridge": "drawbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L729 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), striped_tube()] | lang=en
- "candyland_candy_props_drip": "drip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L181 | neighbors=[candy_props.py, donut_arch(), lathe(), drip_ring(), giant_cone(), icing_cap()] | lang=en
- "candyland_candy_props_giant_cone": "giant_cone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1146 | neighbors=[candy_props.py, drip(), lathe(), soft(), waffle_lathe(), waffle_shade()] | lang=en
- "candyland_candy_props_icing_cap": "icing_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L752 | neighbors=[candy_props.py, choco_falls(), gumdrop_mountain(), bell_r(), drip(), lathe()] | lang=en
- "candyland_candy_props_piping": "piping()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L211 | neighbors=[candy_props.py, candy_castle(), cone_tower(), icing piping along a polyline: beaded (…, sign_plate(), spawn_cookie()] | lang=en
- "candyland_candy_props_sugar": "sugar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L50 | neighbors=[candy_props.py, bakery_oven(), choco_falls(), gumdrop_bush(), gumdrop_mountain(), sugar-coated: height gradient plus fine…] | lang=en
- "candyland_candy_props_waffle_lathe": "waffle_lathe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L265 | neighbors=[candy_props.py, candy_castle(), cone_tower(), giant_cone(), waffle grid: diagonal diamond pattern b…, waffle_bridge()] | lang=en
- "canyonbazaar_canyon_map_on_paving": "on_paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L111 | neighbors=[canyon_map.py, ground(), H(), nature(), main_w(), path_x()] | lang=en
- "canyonbazaar_canyon_map_stories": "stories()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L429 | neighbors=[canyon_map.py, build(), cx(), free(), hw(), place()] | lang=en
- "canyonbazaar_canyon_props_cloth_sheet": "cloth_sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L55 | neighbors=[canyon_props.py, lerp(), quest_board(), a cloth stretched flat over a frame: co…, shade_sail(), stall()] | lang=en
- "canyonbazaar_canyon_props_dais": "dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L47 | neighbors=[canyon_props.py, forge_station(), quest_board(), SHARED BASE: two-course sandstone dais …, relic_kiosk(), stall()] | lang=en
- "canyonbazaar_canyon_props_pot": "pot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L98 | neighbors=[canyon_props.py, goods_pots(), pottery_cluster(), terracotta jar (amphora / squat jar / l…, relic_kiosk(), stall()] | lang=en
- "canyonbazaar_canyon_props_stall": "stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L125 | neighbors=[canyon_props.py, market stall: sandstone step, four palm…, cloth_sheet(), dais(), fruit_pile(), goods_pots()] | lang=en
- "cavemap_cave_map_light": "light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L205 | neighbors=[cave_map.py, clusters(), crystals(), fungi(), landmarks(), mine_sets()] | lang=en
- "cavemap_cave_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L196 | neighbors=[cave_map.py, crust(), floor(), rails(), shell(), sub()] | lang=en
- "cavemap_cave_map_under_lake": "under_lake()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L713 | neighbors=[cave_map.py, build(), anchor(), H(), islet_d(), light()] | lang=en
- "cavemap_cave_map_worms": "worms()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L555 | neighbors=[cave_map.py, build(), glow-worm colonies on the vault + tunne…, ceil_y(), in_hole(), place()] | lang=en
- "cavemap_cave_ores_ore_pile": "ore_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L111 | neighbors=[cave_ores.py, druse(), mound(), ore_lump(), pickaxe(), shovel()] | lang=en
- "cavemap_cave_props_dot": "dot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L74 | neighbors=[cave_props.py, glow_vine(), mushroom(), nodules(), cheap lens / bead (glow spots, bulbs, n…, rim_shade()] | lang=en
- "cavemap_cave_props_mound": "mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L384 | neighbors=[cave_props.py, glowshroom_cluster(), glowshroom_giant(), nodules(), strata_mass(), V()] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@037434c96b1f109b9a8c68b9c9c968643264cf69": "037434c Add MUT-24 determinism and capability analysis" | kind=Commit | source=git | neighbors=[main, 9759537 Refresh graph after MUT-24 dete…, test_version.py, determinism.hpp, determinism.cpp, determinism_test.cpp] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@0621f1d9634ff7026856841b3d084079e7704dfc": "0621f1d Merge pull request #1 from Raft-The-Crab/fix/review-2026-11-26" | kind=Commit | source=git | neighbors=[main, 9eeb3ff Merge pull request #2 from Raft…, scheduler.hpp, values.hpp, optimize.cpp, 34ca6de Fix GCC/Clang build: add <algor…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@34ca6dead03c8b7003d0e1008c36ace5a41b73e9": "34ca6de Fix GCC/Clang build: add <algorithm>, drop nested-Limits default args" | kind=Commit | source=git | neighbors=[main, 0621f1d Merge pull request #1 from Raft…, 06cfbe9 Narrowphase: local pair frame +…, scheduler.hpp, values.hpp, optimize.cpp] | lang=nl
- "commit:repo:github.com/Raft-The-Crab/pokox@435b4d3795807acb854251c1f3d3fea2269693e7": "435b4d3 Add MUT-23 cooperative async scheduler runtime" | kind=Commit | source=git | neighbors=[main, 716dc6c Refresh graph after MUT-23 sche…, test_version.py, scheduler.hpp, scheduler_test.cpp, scheduler.cpp] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@60f3d982ea68b48dc96a7f3bb785c5ca5bbfd2f0": "60f3d98 Merge pull request #3 from Raft-The-Crab/fix/review-low-2026-11-26" | kind=Commit | source=git | neighbors=[main, 038387e Character controller: value-key…, 0be87b9 Merge pull request #4 from Raft…, 2680d0e Pushed an update., character_controller.cpp, 8e05db1 Character controller: conservat…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@c7e951a603a1d2069cbcea5f6be819a320119caf": "c7e951a Add MUT-21 package, import and lockfile resolution" | kind=Commit | source=git | neighbors=[main, 080a665 Refresh graph after MUT-21 pack…, test_version.py, package.hpp, package.cpp, package_test.cpp] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@e685cdf2707716b300e6fe3c419217fc7daa7f8b": "e685cdf Add MUT-22 aggregate VM value and lifetime runtime" | kind=Commit | source=git | neighbors=[080a665 Refresh graph after MUT-21 pack…, main, 69e798f Refresh graph after MUT-22 valu…, test_version.py, values.hpp, values_test.cpp] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@fd66d0d92fad2495ce44f6d992beb276c1c5cec7": "fd66d0d Add MUT-25 typed SSA IR and verifier" | kind=Commit | source=git | neighbors=[9759537 Refresh graph after MUT-24 dete…, main, 13dbd75 Refresh graph after MUT-25 SSA …, test_version.py, ssa.hpp, ssa.cpp] | lang=en
- "creaturelab_lab_map_hall_floor": "hall_floor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L118 | neighbors=[lab_map.py, build(), pol(), polar_tiles(), sh_val(), static()] | lang=en
- "creaturelab_lab_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L62 | neighbors=[lab_map.py, exterior(), foot(), H(), kit(), sub()] | lang=en
- "creaturelab_lab_map_stations": "stations()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L282 | neighbors=[lab_map.py, build(), anchor(), face_in(), place(), pol()] | lang=en
- "creaturelab_lab_map_wing_floor": "wing_floor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L151 | neighbors=[lab_map.py, build(), lab wing floor: slab, 3-stud square til…, in_wing(), inset_top(), sh_val()] | lang=en
- "creaturelab_lab_props_evo_chamber": "evo_chamber()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L553 | neighbors=[lab_props.py, ball(), leaf_poly(), merge_prop(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_lab_wing": "lab_wing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L909 | neighbors=[lab_props.py, arc_wall(), merge_prop(), rbox(), ring_seg(), .add()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-018.json

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
