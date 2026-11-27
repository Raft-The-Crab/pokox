# Node Description Batch 20 of 209

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
- "creaturelab_lab_props_leaf_ball": "leaf_ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1030 | neighbors=[lab_props.py, bush(), .add(), long_planter(), potted_tree(), chunky stylised leaf mass: a blob + a f…] | lang=en
- "creaturelab_lab_props_leaf_cluster": "leaf_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1373 | neighbors=[lab_props.py, fig_tree(), hanging_planter(), ball(), .add(), clustered round leaves: n small smooth …] | lang=en
- "creaturelab_lab_props_leaf_mass": "leaf_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2041 | neighbors=[lab_props.py, clump(), leaf_sh(), .add(), olive_tree(), park_tree()] | lang=en
- "creaturelab_lab_props_leaf_poly": "leaf_poly()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L100 | neighbors=[lab_props.py, catch_ball(), emblem(), evo_chamber(), med_shelf(), plush()] | lang=en
- "creaturelab_lab_props_plush": "plush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1562 | neighbors=[lab_props.py, heal_corner(), ball(), leaf_poly(), .add(), upright()] | lang=en
- "creaturelab_lab_props_pot_plant": "pot_plant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L253 | neighbors=[lab_props.py, heal_counter(), lerp(), .add(), small round pot + leafy sprouts (used o…, rest_nook()] | lang=en
- "creaturelab_lab_props_round_bush": "round_bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1510 | neighbors=[lab_props.py, smooth round shrub: soft leaf mound wit…, ball(), leaf_cluster(), .add(), round_planter()] | lang=en
- "creaturelab_lab_props_supply_boxes": "supply_boxes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1610 | neighbors=[lab_props.py, Shop story: stacked supply cartons (cre…, capsule(), emblem(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_wall_shelf_lab": "wall_shelf_lab()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1254 | neighbors=[lab_props.py, lab wall shelving: steel frame, binders…, bottle(), pot_plant(), rbox(), shelf_frame()] | lang=en
- "creaturelab_lab_props_welcome_sign": "welcome_sign()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1151 | neighbors=[lab_props.py, entry monolith on the path: rounded whi…, emblem_badge(), merge_prop(), rbox(), round_bush()] | lang=en
- "device_opengles_clear_backend": "opengles_clear_backend.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_backend.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, clear_and_present(), initialize(), OpenGLESClearBackend, shutdown(), 52dbcb9 Surface graphics warnings in X1…] | lang=en
- "device_opengles_clear_demo": "opengles_clear_demo.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, FailingPrimaryBackend, linear_to_srgb_byte(), main(), report_pixel(), 52dbcb9 Surface graphics warnings in X1…] | lang=en
- "device_vulkan_imgui_pass": "vulkan_imgui_pass.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, draw(), Impl(), VulkanDiagnostics, VulkanImGuiPass(), 52dbcb9 Surface graphics warnings in X1…] | lang=en
- "dunedesert_dune_map_fragments": "fragments()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L519 | neighbors=[dune_map.py, build(), free(), on_path(), place(), reserve()] | lang=en
- "dunedesert_dune_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L166 | neighbors=[dune_map.py, add_owner(), build_solid(), fragments(), look(), nature()] | lang=en
- "dunedesert_dune_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L167 | neighbors=[dune_map.py, build(), dig_spots(), fragments(), nature(), set_pieces()] | lang=en
- "dunedesert_dune_map_set_pieces": "set_pieces()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L357 | neighbors=[dune_map.py, build(), anchor(), face(), place(), reserve()] | lang=en
- "dunedesert_dune_map_waystones": "waystones()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L448 | neighbors=[dune_map.py, build(), path markers every ~30 studs along each…, face(), free(), place()] | lang=en
- "dunedesert_dune_props_colossus_head": "colossus_head()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L971 | neighbors=[dune_props.py, disc(), smooth(), sun_relief(), uvsphere(), V()] | lang=en
- "dunedesert_dune_props_disc": "disc()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L87 | neighbors=[dune_props.py, colossus_head(), a disc on the plane facing -Z (thicknes…, _shaft(), spawn_dais(), step_pyramid()] | lang=en
- "dunedesert_dune_props_merge_into": "merge_into()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L63 | neighbors=[dune_props.py, obelisk(), obelisk_fallen(), obelisk_stump(), merge a temporary Prop's solid (+ glow)…, ruin_house()] | lang=en
- "dunedesert_dune_props_step_pyramid": "step_pyramid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L169 | neighbors=[dune_props.py, HERO: six-tier gilded step pyramid (ash…, column(), disc(), grid_quad(), sun_relief()] | lang=en
- "dunedesert_gen_trees_with_palms_branch_at": ".at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L336 | neighbors=[Branch, card_quads(), conifer_cards(), .build(), .build_conifer(), .children_of()] | lang=en
- "dunedesert_gen_trees_with_palms_canvas_finish": ".finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L186 | neighbors=[Canvas, normal_from_height(), frond_atlas(), leaf_atlas(), needle_atlas(), palm_twig_atlas()] | lang=en
- "dunedesert_gen_trees_with_palms_fft_noise": "fft_noise()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L33 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), leaf_atlas()] | lang=en
- "dunedesert_gen_trees_with_palms_tree_build": ".build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L411 | neighbors=[make_tree(), Tree, .at(), .build_conifer(), .children_of(), .grow()] | lang=en
- "dunedesert_gen_trees_with_palms_tree_grow": ".grow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L365 | neighbors=[Tree, .build(), .build_conifer(), .children_of(), Branch, rand_unit()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-019.json

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
