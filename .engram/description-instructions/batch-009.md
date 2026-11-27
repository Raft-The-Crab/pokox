# Node Description Batch 10 of 207

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

- "tests_conftest": "conftest.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bad_script(), _can_symlink(), cli_env(), empty_script()]
- "tests_test_safety_game": "game()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L13 | neighbors=[test_safety.py, test_a_broken_source_only_blocks_itself…, test_a_build_mirrors_only_its_own_resou…, test_a_build_never_replaces_a_resource_…, test_a_full_build_of_an_empty_library_r…, test_a_full_build_prunes_only_effects_i…]
- "tools_g2_replay_probe": "g2_replay_probe.cpp" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, bounds_of(), combine_friction(), combine_restitution()]
- "towncity_town_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L76 | neighbors=[town_map.py, alley(), dressing(), landmarks(), kit(), sub()]
- "unit_device_router_test": "device_router_test.cpp" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, apply_events(), connect(), disconnect(), event(), main()]
- "unit_emit_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L90 | neighbors=[emit_test.cpp, arith_module(), calls_module(), check(), hostcall_module(), i32()]
- "unit_evaluator_test": "evaluator_test.cpp" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, bindings(), cases(), check(), deep(), error_case()]
- "unit_input_snapshot_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L63 | neighbors=[input_snapshot_test.cpp, button(), gamepad_axis(), gamepad_button(), key(), motion()]
- "unit_stress_test": "stress_test.cpp" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L1 | neighbors=[2d01203 Final MUT-01..30 audit: stress …, bytecode_limits(), check(), i32t(), lexer_limits(), main()]
- "unit_test_math_determinism_tracetests": "TraceTests" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L12 | neighbors=[test_math_determinism.py, .check_invalid(), .setUp(), .test_corpus_corruption_rejected(), .test_duplicate_json_keys_rejected(), .test_match_is_only_agreement()]
- "valleylake_paint": "paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, atlas(), cracks(), fnoise(), _hex()]
- "valleylake_valley_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L822 | neighbors=[valley_map.py, build(), cliff_clear(), free(), in_terr(), lake_d()]
- "valleylake_valley_map_shore": "shore()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L759 | neighbors=[valley_map.py, build(), dock off the west beach, footbridge ove…, anchor(), face(), free()]
- "valleylake_valley_props_waterfall": "waterfall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L779 | neighbors=[valley_props.py, HERO: a broad curved sheet spilling off…, clump(), flat(), moss_cap(), rim_shade()]
- "vfxkit_library": "library.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, describe(), _forget_helpers(), get(), HelperFinder]
- "vfxkit_primitives_mesh": "mesh()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L217 | neighbors=[primitives.py, column(), crystal(), life_max(), tex(), Procedural Sphere/Cone/Cylinder shell, …]
- "vfxkit_reference": "reference.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyse(), checked_id(), compare(), effect_time()]
- "vfxkit_video_flipbook": "flipbook()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L167 | neighbors=[video.py, _decode(), _key(), _parse_frames(), _portable(), _prompt_text()]
- "vfxkit_video_grade": "grade()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L284 | neighbors=[video.py, _eval(), _portable(), _ramp(), record(), _report_dir()]
- "voidrealm_void_map_stations": "stations()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L254 | neighbors=[void_map.py, build(), anchor(), ang(), face(), H()]
- "blender_render_compare_views": "render_compare_views.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L1 | neighbors=[_area(), _ensure_world(), render_turnaround(), _scene_bounds(), setup_camera(), setup_lighting()]
- "blender_validate_scene": "validate_scene.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L1 | neighbors=[find_isolated(), find_strays(), landmarks(), print_report(), scene_bounds(), tri_count()]
- "brainstorm_server_helper_test": "helper.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L1 | neighbors=[assert, fs, HELPER, makeEnv(), moduleShim, path]
- "candyland_candy_props_quest_stand": "quest_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L549 | neighbors=[candy_props.py, ball(), drip_ring(), lathe(), MS(), round_prof()]
- "canyonbazaar_canyon_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L503 | neighbors=[canyon_map.py, edge_rhythm(), ground(), horizon(), medallion(), nature()]
- "cavemap_cave_map_path_d": "path_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L100 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), fungi(), H()]
- "cavemap_cave_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L190 | neighbors=[cave_map.py, build(), clusters(), crystals(), dripstone(), fungi()]
- "cavemap_cave_map_vines": "vines()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L587 | neighbors=[cave_map.py, build(), glow-root vines hanging from the vault …, ceil_y(), free(), H()]
- "cavemap_cave_ores": "cave_ores.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L1 | neighbors=[cart_load(), druse(), _lump(), mound(), ore_lump(), ore_pile()]
- "commit:repo:github.com/Raft-The-Crab/pokox@1c81e45b51593286d3d388efbe3965f6bfd2a939": "1c81e45 Update from ML AI Code" | kind=Commit | source=git | neighbors=[main, e04375a Run tests, config_file_test.cpp, stdlib_math.hpp, cbor.cpp, stdlib_math.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@4cead55894b2108428ac5afe169253bd4ffc026b": "4cead55 Add MUT-27 bytecode verification and MUT-28 constant folding" | kind=Commit | source=git | neighbors=[main, bytecode.cpp, e499073 Add MUT-29 dead-code eliminatio…, fold.hpp, fold.cpp, lower.cpp]
- "creaturelab_lab_props_fiddle_fig": "fiddle_fig()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1990 | neighbors=[lab_props.py, leaf_card(), leaf_sh(), pot(), Skel, .add()]
- "creaturelab_lab_props_park_tree": "park_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2068 | neighbors=[lab_props.py, blossom_park(), leaf_mass(), lerp(), Skel, .add()]
- "device_vulkan_clear_renderer": "vulkan_clear_renderer.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), draw_and_present(), Impl(), initialize(), native_window()]
- "dunedesert_dune_props_sunken_temple": "sunken_temple()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L1040 | neighbors=[dune_props.py, HERO / DUNGEON PORTAL: a columned templ…, block_wall(), column(), frustum(), merge_into()]
- "dunedesert_gen_trees_with_palms_tree": "Tree" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L350 | neighbors=[gen_trees_with_palms.py, make_tree(), .build(), .build_conifer(), .children_of(), .env()]
- "evaluator_evaluator_unary": "unary()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L170 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), is_float(), is_unsigned(), magnitude()]
- "examples_axolotl": "axolotl.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), gill_base(), gills(), happy()]
- "fishcenter_fish_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L100 | neighbors=[fish_map.py, edges(), nature(), add_owner(), fit(), kit()]
- "fishcenter_fish_props_bait_shop": "bait_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L837 | neighbors=[fish_props.py, bait_bucket(), ball(), barrel(), lerp(), loft()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-009.json

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
