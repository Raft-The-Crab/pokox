# Node Description Batch 12 of 209

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

- "semantic_determinism": "determinism.cpp" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L1 | neighbors=[037434c Add MUT-24 determinism and capa…, 952997e Audit MUT-01-55 and harden veri…, analyze_determinism(), Analyzer, builtin(), dump_determinism()]
- "skyrise_sky_map_island_at": "island_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L37 | neighbors=[sky_map.py, H(), rim(), micro_detail(), index of the island whose rim (minus ma…, rim_dress()]
- "skyrise_sky_map_rim_dress": "rim_dress()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L243 | neighbors=[sky_map.py, dress the outer ring of island i, keepi…, free(), island_at(), on_bridge_line(), place()]
- "skyrise_sky_props_gem": "gem()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L65 | neighbors=[sky_props.py, chest(), coin_pile(), egg_shrine(), lathe(), faceted octahedron-ish gem standing on …]
- "src_cbor": "cbor.cpp" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, f4a6ac4 Allowlist known validation-laye…, decode(), decode_item(), fail(), half_to_double()]
- "stdlib_events": "events.cpp" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, clear_phase(), dispatch(), emit(), hash(), mix()]
- "tests_test_effekseer_ai": "test_effekseer_ai.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_cli_exposes_only_the_portable_effe…, test_cli_rejects_removed_recipe_command…, test_editor_bin_directory_rejects_a_dir…, test_editor_bin_directory_requires_an_e…]
- "tests_test_golden_goldenharnesstests_pair": ".pair()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L23 | neighbors=[GoldenHarnessTests, run(), .test_binary_match(), .test_binary_mismatch_does_not_update_r…, .test_chunk_boundary(), .test_different_lengths_and_empty_files…]
- "texture_uv_density": "uv_density.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, group_stats(), main(), parse_obj(), print_report()]
- "unit_declaration_test": "declaration_test.cpp" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, cases(), check(), depth_guard(), error(), main()]
- "unit_ktx2_test": "ktx2_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), make_ktx2(), put32(), put64(), set32()]
- "unit_optimize_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L60 | neighbors=[optimize_test.cpp, check(), count_instrs(), count_op(), module_of(), run_base()]
- "unit_parser_test": "parser_test.cpp" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, cases(), check(), main(), parse_error(), randomized_input()]
- "unit_solver_test": "solver_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, body(), contact(), fx()]
- "unit_statement_test": "statement_test.cpp" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, cases(), check(), depth_guard(), dump(), error()]
- "valleylake_valley_props_leaf_cluster": "leaf_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L199 | neighbors=[valley_props.py, blossom_tree(), broadleaf(), bush(), canopy(), gnarled_tree()]
- "valleylake_valley_props_market_stall": "market_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L605 | neighbors=[valley_props.py, barrel(), basket(), crate(), flat(), gable_roof()]
- "vfxkit_examples": "examples.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add(), catalog(), ids(), listing()]
- "vfxkit_review_capture": "capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L103 | neighbors=[review.py, compare_sheet(), diff(), dump_metrics(), frame_state(), metrics()]
- "voidrealm_void_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L621 | neighbors=[void_map.py, anchor(), bridges(), build_paths(), dressing(), island()]
- "voidrealm_void_props_rift_gate": "rift_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L590 | neighbors=[void_props.py, HERO 2 - the Rift Gate: octagonal stepp…, annulus(), chamfer_box(), disc(), FS()]
- "whispering_grove_forest_props_leafy": "leafy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L58 | neighbors=[forest_props.py, birch(), bush(), elder_tree(), at(), blob()]
- "window_sdl_platform": "sdl_platform.cpp" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, create_window(), destroy_window(), get_window_size(), initialize(), poll_event()]
- "animation_v2_build_refined": "build_refined.py" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L1 | neighbors=[ease(), foot(), interp(), loc(), rot(), Generate separate R6 clips from untouch…]
- "brick_terrain_brick": "terrain_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L1 | neighbors=[cliff(), cliff_mask(), foot_rocks(), grass_cap(), strata(), wall()]
- "bytecode_bytecode_validate_bytecode": "validate_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L42 | neighbors=[bytecode.cpp, assemble_bytecode(), decode_bytecode(), disassemble_bytecode(), encode_bytecode(), branch()]
- "candyland_candy_map_mesh_obj": "mesh_obj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L190 | neighbors=[candy_map.py, ground(), horizon(), icing_caps(), add_owner(), sub()]
- "candyland_candy_props_gumball_machine": "gumball_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L589 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), sign_plate()]
- "candyland_candy_props_waffle_bridge": "waffle_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L845 | neighbors=[candy_props.py, waffle-cone bridge along Z: an arched w…, ball(), lathe(), round_prof(), soft()]
- "canyonbazaar_canyon_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L146 | neighbors=[canyon_map.py, nature(), foot(), H(), kit(), sub()]
- "canyonbazaar_canyon_map_set_pieces": "set_pieces()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L330 | neighbors=[canyon_map.py, build(), cx(), dcx(), hook(), hw()]
- "cavemap_cave_map_lake_d": "lake_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L84 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), fungi(), H()]
- "cavemap_cave_map_rails": "rails()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L663 | neighbors=[cave_map.py, build(), anchor(), H(), place(), placed_mb()]
- "cavemap_cave_map_shell": "shell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L278 | neighbors=[cave_map.py, build(), inner cave surface: union of the air el…, bvh_of(), H(), in_hole()]
- "cavemap_cave_props_geode": "geode()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L277 | neighbors=[cave_props.py, add_crystal(), FS(), jitter(), rim_shade(), RS()]
- "commit:repo:github.com/Raft-The-Crab/pokox@87beff419123840b334804d9bd7582b2184e15ed": "87beff4 Sim solver: reject self/duplicate contacts, derive mass, clamp integrat…" | kind=Commit | source=git | neighbors=[main, 9eeb3ff Merge pull request #2 from Raft…, solver.hpp, visual_solver.hpp, solver.cpp, visual_solver.cpp]
- "console_console_execute_console_impl": "execute_console_impl()" | kind=code-symbol | source=mute/src/console/console.cpp:L77 | neighbors=[console.cpp, execute_console(), decode_string(), diagnostic(), evaluate_console(), number()]
- "creaturelab_lab_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L76 | neighbors=[lab_map.py, build(), ground(), hall_floor(), hardscape(), horizon()]
- "creaturelab_lab_props_bottle": "bottle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L264 | neighbors=[lab_props.py, ball(), rbox(), .add(), med_shelf(), potion_shelf()]
- "creaturelab_lab_props_rotunda": "rotunda()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L807 | neighbors=[lab_props.py, HERO shell: the care hall. Ring wall (i…, adeg(), arc_wall(), lerp(), merge_prop()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-011.json

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
