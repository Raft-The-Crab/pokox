# Node Description Batch 17 of 207

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

- "scripts_scanner": "scanner.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, collect_target_files(), get_scanner_config(), get_supported_extensions(), _identify_semantic_files()]
- "scripts_scatter": "scatter.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_tree(), _instances(), _layer_coll(), _on()]
- "scripts_template_engine_compile_template": "compile_template()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L162 | neighbors=[template_engine.py, EachNode, IfNode, _ParserFrame, TextNode, VarNode]
- "semantic_ssa": "ssa.cpp" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L1 | neighbors=[2c0194b Add assignments and loop-carrie…, 4cead55 Add MUT-27 bytecode verificatio…, 952997e Audit MUT-01-55 and harden veri…, fd66d0d Add MUT-25 typed SSA IR and ver…, dump_ir(), is_terminator()]
- "skyrise_sky_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L112 | neighbors=[sky_map.py, build(), micro_detail(), rim_dress(), spawn_island(), summit()]
- "skyrise_sky_map_spawn_island": "spawn_island()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L224 | neighbors=[sky_map.py, build(), face(), free(), paving(), place()]
- "skyrise_sky_map_summit": "summit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L352 | neighbors=[sky_map.py, build(), face(), island_at(), on_bridge_line(), paving()]
- "skyrise_sky_models3": "sky_models3.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bush(), charred_tree(), lamp_post(), lava_pool()]
- "skyrise_sky_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L61 | neighbors=[sky_props.py, egg_shrine(), flower_bed(), sell_pad(), spawn_pad(), teleport_pad()]
- "src_cbor": "cbor.cpp" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, c7a411f Fix MUT-01-20 audit defects in …, decode(), decode_item(), fail(), half_to_double()]
- "src_logging_emit": "emit()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L33 | neighbors=[logging.cpp, critical(), debug(), error(), info(), to_spdlog()]
- "src_narrowphase_epa_penetration": "epa_penetration()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L349 | neighbors=[narrowphase.cpp, collide_local(), cso_support(), face_barycentric(), face_normal(), orient_out()]
- "src_visual_solver_step": "step()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L412 | neighbors=[visual_solver.cpp, add_contact(), begin_step(), collide_visual(), find_body(), integrate()]
- "targets_run_dual_target_tests_android_leg": "android_leg()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L293 | neighbors=[run_dual_target_tests.py, adb_shell(), android_compile(), android_tools(), normalize_lf(), now()]
- "tests_run_all": "run_all.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, fresh(), main(), requires_gpu(), skill_module()]
- "tests_test_animation": "test_animation.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _rig(), test_bake_to_copy_with_root_motion_and_…, test_loop_check_hitches_kink_dip_and_sm…, test_loop_check_pops_fix_and_root_motio…]
- "tests_test_mating": "test_mating.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _socket(), test_collision_fails(), test_good_fit_passes(), test_loose_fit_fails()]
- "tests_test_npr": "test_npr.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bands(), _clusters(), _scene(), test_remove_restores_slots_on_unmateria…]
- "tests_test_workflow_captured": "captured()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L82 | neighbors=[test_workflow.py, test_build_and_render_reject_changed_so…, test_completion_requires_brief_review_a…, test_evidence_is_stored_in_the_workspac…, test_independent_report_binds_images_sc…, test_reference_compare_requires_exact_f…]
- "tools_g2_replay_probe_main": "main()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L117 | neighbors=[g2_replay_probe.cpp, bounds_of(), combine_friction(), combine_restitution(), fx(), shape_of()]
- "tools_readme_hero": "readme_hero.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, figure(), font(), frame(), main()]
- "towncity_city_paint_tile": "tile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L45 | neighbors=[city_paint.py, block(), one periodic WP x HP tile at base shade…, clip(), edge(), hash2()]
- "towncity_town_map_dressing": "dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L378 | neighbors=[town_map.py, build(), face(), free(), near_intersection(), place()]
- "towncity_town_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L90 | neighbors=[town_map.py, alley(), build(), dressing(), landmarks(), row()]
- "towncity_town_map_row": "row()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L221 | neighbors=[town_map.py, buildings(), landmarks(), lay buildings side by side from `start`…, bkit(), face()]
- "unit_action_map_test_game_map": "game_map()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L51 | neighbors=[action_map_test.cpp, axis(), kb(), mouse(), pad(), tap()]
- "unit_debugger_test": "debugger_test.cpp" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, arith(), cases(), check(), divzero(), imm()]
- "unit_declaration_test": "declaration_test.cpp" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, cases(), check(), depth_guard(), error(), main()]
- "unit_emit_test_position_cases": "position_cases()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L209 | neighbors=[emit_test.cpp, main(), arith_module(), check(), compile_source(), i32()]
- "unit_emit_test_v": "v()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L15 | neighbors=[emit_test.cpp, arith_module(), calls_module(), cases(), hostcall_module(), position_cases()]
- "unit_fixed_vec_test": "fixed_vec_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 9eeb3ff Merge pull request #2 from Raft…, len_d(), main(), naive_dot(), naive_in_range()]
- "unit_fold_test": "fold_test.cpp" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…, cases(), check(), count_op(), i32t(), main()]
- "unit_ktx2_test": "ktx2_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main(), make_ktx2(), put32(), put64(), set32()]
- "unit_parser_test": "parser_test.cpp" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, cases(), check(), main(), parse_error(), randomized_input()]
- "unit_ssa_test": "ssa_test.cpp" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L1 | neighbors=[fd66d0d Add MUT-25 typed SSA IR and ver…, cases(), check(), has(), i32(), main()]
- "unit_statement_test": "statement_test.cpp" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, cases(), check(), depth_guard(), dump(), error()]
- "unit_stress_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L20 | neighbors=[stress_test.cpp, bytecode_limits(), lexer_limits(), package_limits(), pipeline_limits(), program_limits()]
- "unit_stress_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L123 | neighbors=[stress_test.cpp, bytecode_limits(), lexer_limits(), package_limits(), pipeline_limits(), program_limits()]
- "unit_worker_auth_test": "worker_auth_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, check(), fake_rsa_verify(), main(), make_token(), sample_ticket()]
- "valleylake_valley_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L228 | neighbors=[valley_map.py, build(), cliffs(), nature(), rope_lines(), shore()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-016.json

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
