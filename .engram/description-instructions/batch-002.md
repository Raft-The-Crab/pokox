# Node Description Batch 3 of 208

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

- "scripts_bld_grid": "Grid" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L18 | neighbors=[strength-sim weight station: rubber mat…, sleek long sword after a user reference…, crystal sword after a user reference (R…, tapered trunk: radius r0 at the base ->…, side-profile polygon (x, y fine coords)…, thick polyline (bow limbs, strings, tho…]
- "scripts_orchestrator": "orchestrator.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _build_app_plugin_alias_pattern(), _candidate_project_roots(), determine_primary_identity(), extract_dotnet_android_details()]
- "tests_test_pipeline": "test_pipeline.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_advanced_layer_features_survive_co…, test_batch_convert_report_script_shard(), test_core_roundtrip_preserves_timing_cu…, test_curve_tangent_data_roundtrips_and_…]
- "unit_vulkan_clear_faults": "vulkan_clear_faults.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Chain(), Context(), Device(), emit(), foreign()]
- "vfxkit_sequence": "sequence.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, capture(), concept_compare(), criteria(), _frame_number()]
- "brick_props_brick": "props_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L1 | neighbors=[assault_rifle(), branch(), bush(), cart(), crimson_blade(), fence()]
- "cavemap_cave_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L913 | neighbors=[cave_map.py, anchor(), build_dist(), build_solid(), clusters(), crust()]
- "commit:repo:github.com/Raft-The-Crab/pokox@9eeb3ff8317b7f27b0f3d86dc1e350fd400ed475": "9eeb3ff Merge pull request #2 from Raft-The-Crab/fix/review-2026-11-26" | kind=Commit | source=git | neighbors=[0621f1d Merge pull request #1 from Raft…, 87beff4 Sim solver: reject self/duplica…, main, 1c81e45 Update from ML AI Code, opengles_native_activity.cpp, swapchain_frame_loop.hpp]
- "creaturelab_lab_props_ball": "ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L52 | neighbors=[lab_props.py, berry_baskets(), blossom_tree(), bottle(), bush(), catch_ball()]
- "eggplots_egg_props_rbox": "rbox()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L55 | neighbors=[egg_props.py, barn(), bench(), conveyor_end(), conveyor_seg(), coop()]
- "evaluator_evaluator": "evaluator.cpp" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, evaluate_arithmetic(), fail(), float_binary(), FloatEnvironment, integer_suffix()]
- "mesh_enginefactoryvk": "EngineFactoryVk.h" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/EngineFactoryVk.h:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, ClearDepthStencil(), ClearRenderTarget(), CommitShaderResources(), CreateGraphicsPipelineState(), CreateSampler()]
- "src_narrowphase": "narrowphase.cpp" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 69287a0 Land ENG-60-65 deterministic si…, 9eeb3ff Merge pull request #2 from Raft…, aabb_of(), centroid(), closest_on_hull()]
- "tests_test_gridfinity": "test_gridfinity.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _assert_footprint(), _mesh(), test_bad_notch_side_raises(), test_bin_with_lip_magnets_screws()]
- "whispering_grove_forest_map": "forest_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), CAMP_PTS(), canopy_shade(), chaikin()]
- "brainstorm_server_server_test": "server.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L1 | neighbors=[assert, assertStartedOnExpectedPort(), cleanup(), CONTENT_DIR, ensureSymlinkWorks(), fetch()]
- "brick_mimic_chest_brick": "mimic_chest_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L1 | neighbors=[B(), body_to_world(), build(), cap(), cube(), _dil()]
- "brick_swamp_croc_brick": "swamp_croc_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L1 | neighbors=[B(), box(), build(), cap(), chain(), exposed()]
- "brick_tyrant_rex_brick": "tyrant_rex_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/tyrant_rex_brick.py:L1 | neighbors=[B(), box(), build(), cap(), chain(), colmax()]
- "brick_war_mech_brick": "war_mech_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L1 | neighbors=[B(), box(), build(), cap(), carve(), cell()]
- "src_character_controller": "character_controller.cpp" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 2680d0e Pushed an update., 3faf30f Character controller: value-key…, 5acf433 Character controller: fix corru…, 60f3d98 Merge pull request #3 from Raft…, 69287a0 Land ENG-60-65 deterministic si…]
- "tests_test_package": "test_package.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, system_python(), test_a_fresh_project_lints_a_recipe_tha…, test_cli_init_examples_and_lint_in_a_fr…, test_doctor_reports_an_initialised_work…]
- "vfxkit_evidence": "evidence.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_issues(), capture_issues(), context(), current_recipe()]
- "vfxkit_video": "video.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _decode(), _eval(), _ffmpeg(), first_frame()]
- "whispering_grove_forest_props_at": "at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L49 | neighbors=[forest_props.py, altar(), birch(), bridge(), bush(), campfire()]
- "brainstorm_server_auth_test": "auth.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L1 | neighbors=[assert, assertSecurityHeaders(), assertStartedOnExpectedPort(), cleanup(), CONTENT_DIR, EXPECTED_SECURITY_HEADERS]
- "brick_kraken_brick": "kraken_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L1 | neighbors=[B(), box(), build(), cap(), catmull(), chain()]
- "tests_test_scale_beam": "test_scale_beam.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe_with(), test_beam_cross_section_is_full_strengt…, test_beam_layers_are_held_axial_strips_…, test_beam_recipe_lints_with_hold_and_ne…]
- "triangle_enginefactoryvk": "EngineFactoryVk.h" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/EngineFactoryVk.h:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, ClearDepthStencil(), ClearRenderTarget(), CommitShaderResources(), CreateGraphicsPipelineState(), CreateSampler()]
- "vfxkit_primitives_sprite": "sprite()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L24 | neighbors=[primitives.py, beam(), _beam_strip(), billow(), charge_chain(), debris()]
- "voidrealm_void_props_v": "V()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L45 | neighbors=[void_props.py, arena_rim(), brazier(), crystal_chips(), crystal_cluster(), crystal_lantern()]
- "brick_venom_widow_brick": "venom_widow_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L1 | neighbors=[at(), B(), band(), build(), cap(), chain()]
- "cavemap_cave_props2": "cave_props2.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L1 | neighbors=[barrels(), blob(), cart_load(), crates(), logp(), mine_cart()]
- "integration_config_file_test": "config_file_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 52dbcb9 Surface graphics warnings in X1…, head(), main(), put_arr(), put_b()]
- "medievalbattle_battle_props_log": "log()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L68 | neighbors=[battle_props.py, battle_debris(), bridge_tower(), broadleaf(), broken_cart(), campfire()]
- "opencode_test_session_bootstrap": "test-session-bootstrap.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bootstrapCount(), checkpoint, childEvent, compactedEvent()]
- "scripts_studlib": "studlib.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, apply(), box(), cyl(), _emit()]
- "tests_test_workflow": "test_workflow.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, captured(), isolated(), lab(), report()]
- "vm_values": "values.cpp" | kind=code-symbol | source=mute/src/vm/values.cpp:L1 | neighbors=[5edd00c Fix MUT-21/22 audit defects in …, 964ba8a Resolve MUT-22 values runtime l…, e685cdf Add MUT-22 aggregate VM value a…, alloc(), as_string(), copy()]
- "brick_scorpion_king_brick": "scorpion_king_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L1 | neighbors=[B(), b3(), ball(), box(), build(), cap()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-002.json

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
