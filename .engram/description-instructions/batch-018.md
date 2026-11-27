# Node Description Batch 19 of 209

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

- "vfxkit_sequence_read": "read()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L47 | neighbors=[sequence.py, capture(), concept_compare(), handoff(), issues(), paintover()]
- "vfxkit_sequence_submit": "submit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L368 | neighbors=[sequence.py, criteria(), _frame_number(), gate_path(), issues(), _now()]
- "voidrealm_void_props_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L551 | neighbors=[void_props.py, spawn platform: big round stepped dais,…, annulus(), chamfer_box(), FS(), rune_circle()]
- "warehouse_fitlib": "fitlib.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_owner(), fit(), fit_bad(), _inb()]
- "whispering_grove_forest_props_campfire": "campfire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L392 | neighbors=[forest_props.py, at(), blob(), flame_tongue(), Prop, .add()]
- "whispering_grove_forest_props_log": "log()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L264 | neighbors=[forest_props.py, at(), blob(), mushroom(), Prop, .add()]
- "whispering_grove_forest_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L229 | neighbors=[forest_props.py, log(), at(), Prop, .add(), .gadd()]
- "work_test_uv_overlap_overlaptests": "OverlapTests" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L5 | neighbors=[test_uv_overlap.py, .test_bounding_boxes_overlap_but_triang…, .test_edge_and_point_contact_are_not_ov…, .test_identical_cross_mesh_triangles_ar…, .test_invalid_values_rejected(), .test_outside_atlas_and_degenerate()]
- "work_uv_overlap": "uv_overlap.py" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, _cross(), find_cross_mesh_overlaps(), intersection_area(), _signed_area(), Test positive-area overlap between tria…]
- "brainstorm_server_branding_test_test": "test()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L110 | neighbors=[branding.test.js, assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap(), assertLogoKeepsTransparentBackground()]
- "brick_bone_hydra_brick_head": "head()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L263 | neighbors=[bone_hydra_brick.py, dil(), J2L(), newid(), put(), sl_of()]
- "brick_lich_king_brick_shift": "shift()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L55 | neighbors=[lich_king_brick.py, back_layer(), cube_dil(), dil(), ero(), front_face()]
- "brick_props_brick_grass_base": "grass_base()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L46 | neighbors=[props_brick.py, bush(), oak(), pine(), mossy ground disc with stepped edge + a…, rocks()]
- "bytecode_bytecode_disassemble_bytecode": "disassemble_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L191 | neighbors=[bytecode.cpp, assemble_bytecode(), branch(), branch_offset(), long_offset(), mnemonic()]
- "cad_skill_main_gridfinity_gridfinitybin_compartment_solids": "._compartment_solids()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L569 | neighbors=[GridfinityBin, .build(), ._compartment_size(), ._label_shelf(), ._scoop(), _rounded_rect()]
- "cad_skill_main_gridfinity_gridfinitybin_validate": "._validate()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L321 | neighbors=[GridfinityBin, .build(), ._check_depth(), ._check_wall_clearance(), ._compartment_size(), ._cylinder_drop()]
- "cad_skill_main_mesh_io": "mesh_io.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L1 | neighbors=[bed_fit(), estimate_mass(), load_mesh(), parse_bed(), Pure trimesh STL loading with validatio…, 2680d0e Pushed an update.]
- "cad_skill_main_preview_render_multi_view": "render_multi_view()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L361 | neighbors=[preview.py, main(), Render 6-view technical preview in a 3x…, _build_scene(), _get_font(), _info_lines()]
- "cad_skill_main_run_cadquery_model": "run_cadquery_model.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L1 | neighbors=[_append_stderr(), main(), _new_files_by_ext(), _process_stls(), _sibling(), 2680d0e Pushed an update.]
- "candyland_candy_props_drawbridge": "drawbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L729 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), striped_tube()]
- "candyland_candy_props_drip": "drip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L181 | neighbors=[candy_props.py, donut_arch(), lathe(), drip_ring(), giant_cone(), icing_cap()]
- "candyland_candy_props_giant_cone": "giant_cone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1146 | neighbors=[candy_props.py, drip(), lathe(), soft(), waffle_lathe(), waffle_shade()]
- "candyland_candy_props_icing_cap": "icing_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L752 | neighbors=[candy_props.py, choco_falls(), gumdrop_mountain(), bell_r(), drip(), lathe()]
- "candyland_candy_props_piping": "piping()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L211 | neighbors=[candy_props.py, candy_castle(), cone_tower(), icing piping along a polyline: beaded (…, sign_plate(), spawn_cookie()]
- "candyland_candy_props_sugar": "sugar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L50 | neighbors=[candy_props.py, bakery_oven(), choco_falls(), gumdrop_bush(), gumdrop_mountain(), sugar-coated: height gradient plus fine…]
- "candyland_candy_props_waffle_lathe": "waffle_lathe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L265 | neighbors=[candy_props.py, candy_castle(), cone_tower(), giant_cone(), waffle grid: diagonal diamond pattern b…, waffle_bridge()]
- "canyonbazaar_canyon_map_on_paving": "on_paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L111 | neighbors=[canyon_map.py, ground(), H(), nature(), main_w(), path_x()]
- "canyonbazaar_canyon_map_stories": "stories()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L429 | neighbors=[canyon_map.py, build(), cx(), free(), hw(), place()]
- "canyonbazaar_canyon_props_cloth_sheet": "cloth_sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L55 | neighbors=[canyon_props.py, lerp(), quest_board(), a cloth stretched flat over a frame: co…, shade_sail(), stall()]
- "canyonbazaar_canyon_props_dais": "dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L47 | neighbors=[canyon_props.py, forge_station(), quest_board(), SHARED BASE: two-course sandstone dais …, relic_kiosk(), stall()]
- "canyonbazaar_canyon_props_pot": "pot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L98 | neighbors=[canyon_props.py, goods_pots(), pottery_cluster(), terracotta jar (amphora / squat jar / l…, relic_kiosk(), stall()]
- "canyonbazaar_canyon_props_stall": "stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L125 | neighbors=[canyon_props.py, market stall: sandstone step, four palm…, cloth_sheet(), dais(), fruit_pile(), goods_pots()]
- "cavemap_cave_map_light": "light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L205 | neighbors=[cave_map.py, clusters(), crystals(), fungi(), landmarks(), mine_sets()]
- "cavemap_cave_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L196 | neighbors=[cave_map.py, crust(), floor(), rails(), shell(), sub()]
- "cavemap_cave_map_under_lake": "under_lake()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L713 | neighbors=[cave_map.py, build(), anchor(), H(), islet_d(), light()]
- "cavemap_cave_map_worms": "worms()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L555 | neighbors=[cave_map.py, build(), glow-worm colonies on the vault + tunne…, ceil_y(), in_hole(), place()]
- "cavemap_cave_ores_ore_pile": "ore_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L111 | neighbors=[cave_ores.py, druse(), mound(), ore_lump(), pickaxe(), shovel()]
- "cavemap_cave_props_dot": "dot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L74 | neighbors=[cave_props.py, glow_vine(), mushroom(), nodules(), cheap lens / bead (glow spots, bulbs, n…, rim_shade()]
- "cavemap_cave_props_mound": "mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L384 | neighbors=[cave_props.py, glowshroom_cluster(), glowshroom_giant(), nodules(), strata_mass(), V()]
- "commit:repo:github.com/Raft-The-Crab/pokox@037434c96b1f109b9a8c68b9c9c968643264cf69": "037434c Add MUT-24 determinism and capability analysis" | kind=Commit | source=git | neighbors=[main, 9759537 Refresh graph after MUT-24 dete…, test_version.py, determinism.hpp, determinism.cpp, determinism_test.cpp]

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
