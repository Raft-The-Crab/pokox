# Node Description Batch 14 of 208

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

- "src_character_controller_update": "update()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L206 | neighbors=[character_controller.cpp, capsule_at(), cast_fraction(), deepest_contact(), planar(), shape_bound()]
- "src_config_load_file": "load_file()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L100 | neighbors=[config.cpp, collect_unknown(), fail(), find_key(), parse_level(), read_bool()]
- "src_gallery": "gallery.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, drum(), flat(), ground(), put()]
- "src_loop": "loop.cpp" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, advance(), alpha(), backlog_seconds(), FixedStepLoop(), reset_backlog()]
- "tests_test_mesh_io": "test_mesh_io.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_bed_fit_allows_rotation_and_report…, test_estimate_mass_hollow_less_than_sol…, test_load_mesh_empty_file(), test_load_mesh_missing_file()]
- "tests_test_package_vfx": "vfx()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L14 | neighbors=[test_package.py, Run the CLI with the test interpreter; …, test_a_fresh_project_lints_a_recipe_tha…, test_cli_init_examples_and_lint_in_a_fr…, test_doctor_reports_an_initialised_work…, test_effect_verify_reports_missing_evid…]
- "texture_tex_to_maps_process": "process()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L106 | neighbors=[tex_to_maps.py, main(), derive_ao(), derive_normal(), derive_roughness(), high_pass()]
- "texture_tile_seam_check": "tile_seam_check.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, assess(), boundary_metrics(), load_gray(), main()]
- "towncity_town_map_landmarks": "landmarks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L284 | neighbors=[town_map.py, build(), anchor(), face(), place(), reserve()]
- "towncity_town_props_window_unit": "window_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L198 | neighbors=[town_props.py, building(), dressing for ONE opening in a front wal…, add(), flower_box(), front_quad()]
- "unit_bench_test": "bench_test.cpp" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, bench(), best_ns(), cases(), check(), compile()]
- "unit_character_controller_test": "character_controller_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, aabb(), fx(), main(), params(), tod()]
- "unit_declaration_test": "declaration_test.cpp" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, cases(), check(), depth_guard(), error(), main()]
- "unit_device_router_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L54 | neighbors=[device_router_test.cpp, apply_events(), connect(), disconnect(), pad_axis(), pad_button()]
- "unit_diff_test": "diff_test.cpp" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, cases(), check(), compile(), diff_case(), main()]
- "unit_emit_test_i32": "i32()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L14 | neighbors=[emit_test.cpp, arith_module(), calls_module(), cases(), compile_source(), hostcall_module()]
- "unit_ktx2_test": "ktx2_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), make_ktx2(), put32(), put64(), set32()]
- "unit_narrowphase_test": "narrowphase_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 69287a0 Land ENG-60-65 deterministic si…, 9eeb3ff Merge pull request #2 from Raft…, aabb(), main(), sphere()]
- "unit_parser_test": "parser_test.cpp" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, cases(), check(), main(), parse_error(), randomized_input()]
- "unit_statement_test": "statement_test.cpp" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, cases(), check(), depth_guard(), dump(), error()]
- "valleylake_valley_map_h0": "H0()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L89 | neighbors=[valley_map.py, H(), in_terr(), islet(), lake_d(), sand_w()]
- "valleylake_valley_props_house": "house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L517 | neighbors=[valley_props.py, engawa(), flat(), footing(), gable_roof(), .add()]
- "voidrealm_void_props_quest_stand": "quest_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L519 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), sign_plate()]
- "voidrealm_void_props_shop_kiosk": "shop_kiosk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L436 | neighbors=[void_props.py, Void Merchant: dais, stone counter with…, chamfer_box(), FS(), rune_glyph(), shaft()]
- "voidrealm_void_props_upgrade_altar": "upgrade_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L474 | neighbors=[void_props.py, Ascension Altar: round 3-step dais, fac…, annulus(), chamfer_box(), flame(), FS()]
- "warehouse_wh_props_pallet_load": "pallet_load()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L113 | neighbors=[wh_props.py, floor_pallet(), load_cartons(), load_crates(), load_drums(), load_sacks()]
- "whispering_grove_forest_props_blob": "blob()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L46 | neighbors=[forest_props.py, bush(), campfire(), elder_tree(), flower_patch(), leafy()]
- "whispering_grove_forest_props_prop_gadd": ".gadd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L39 | neighbors=[altar(), campfire(), crystal_cluster(), elder_tree(), lantern_post(), mushroom()]
- "window_sdl_platform": "sdl_platform.cpp" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, create_window(), destroy_window(), get_window_size(), initialize(), poll_event()]
- "animation_v2_build_refined": "build_refined.py" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L1 | neighbors=[ease(), foot(), interp(), loc(), rot(), Generate separate R6 clips from untouch…]
- "brainstorm_server_branding_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L9 | neighbors=[branding.test.js, assertBrandedFallbackText(), assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap()]
- "brainstorm_server_ws_protocol_test": "ws-protocol.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L1 | neighbors=[assert, crypto, path, runTests(), SERVER_PATH, RFC-6455]
- "brick_bone_hydra_brick_full": "full()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L39 | neighbors=[bone_hydra_brick.py, cap(), crack(), keep_main(), obox(), oell()]
- "brick_bone_hydra_brick_sl_of": "sl_of()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L36 | neighbors=[bone_hydra_brick.py, cap(), head(), obox(), oell(), rblock()]
- "cad_skill_main_outline_from_scan": "outline_from_scan.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L1 | neighbors=[align_and_scale(), main(), max_section_outline(), recentered(), rotate_min_square(), Extract a 2D pocket outline from a 3D s…]
- "candyland_candy_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L132 | neighbors=[candy_map.py, build(), add_owner(), fit(), kit(), sub()]
- "candyland_candy_props_candy_lamp": "candy_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1104 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), striped_tube()]
- "candyland_candy_props_choco_falls": "choco_falls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L770 | neighbors=[candy_props.py, bell_r(), icing_cap(), lathe(), soft(), sugar()]
- "candyland_candy_props_drip_ring": "drip_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L186 | neighbors=[candy_props.py, bakery_oven(), candy_castle(), cone_tower(), cupcake_fountain(), drip()]
- "candyland_candy_props_sign_plate": "sign_plate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L226 | neighbors=[candy_props.py, bakery_oven(), egg_machine(), gumball_machine(), quest_stand(), blank wafer sign: cream face in a beade…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-013.json

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
