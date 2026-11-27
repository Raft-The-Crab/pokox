# Node Description Batch 18 of 209

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
- "unit_emit_test_position_cases": "position_cases()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L209 | neighbors=[emit_test.cpp, main(), arith_module(), check(), compile_source(), i32()]
- "unit_emit_test_v": "v()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L15 | neighbors=[emit_test.cpp, arith_module(), calls_module(), cases(), hostcall_module(), position_cases()]
- "unit_fixed_vec_test": "fixed_vec_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 9eeb3ff Merge pull request #2 from Raft…, len_d(), main(), naive_dot(), naive_in_range()]
- "unit_fold_test": "fold_test.cpp" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…, cases(), check(), count_op(), i32t(), main()]
- "unit_imgui_pass_faults": "imgui_pass_faults.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, FakeShader(), GetEngineFactoryVk(), main(), reset(), write_spirv()]
- "unit_lexer_test": "lexer_test.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, check(), error(), main(), test_cases(), unicode_conformance()]
- "unit_pokomesh_test": "pokomesh_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), make_pmes(), put32(), putf(), write()]
- "unit_ssa_test": "ssa_test.cpp" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L1 | neighbors=[fd66d0d Add MUT-25 typed SSA IR and ver…, cases(), check(), has(), i32(), main()]
- "unit_stress_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L20 | neighbors=[stress_test.cpp, bytecode_limits(), lexer_limits(), package_limits(), pipeline_limits(), program_limits()]
- "unit_stress_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L123 | neighbors=[stress_test.cpp, bytecode_limits(), lexer_limits(), package_limits(), pipeline_limits(), program_limits()]
- "unit_vulkan_mesh_pass_test": "vulkan_mesh_pass_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, draw_and_present(), main(), messages(), VulkanClearRenderer(), VulkanDiagnostics()]
- "unit_worker_auth_test": "worker_auth_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, check(), fake_rsa_verify(), main(), make_token(), sample_ticket()]
- "valleylake_valley_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L228 | neighbors=[valley_map.py, build(), cliffs(), nature(), rope_lines(), shore()]
- "valleylake_valley_props_blossom_tree": "blossom_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L289 | neighbors=[valley_props.py, clump(), flat(), leaf_cluster(), limb(), .add()]
- "valleylake_valley_props_boulder": "boulder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L148 | neighbors=[valley_props.py, moss_cap(), rim_shade(), rounded_mass(), RS(), .add()]
- "valleylake_valley_props_dock": "dock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L678 | neighbors=[valley_props.py, barrel(), crate(), flat(), paper_lantern(), .add()]
- "valleylake_valley_props_leaf_mass": "leaf_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L894 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), clump(), .add(), V()]
- "valleylake_valley_props_limb": "limb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L237 | neighbors=[valley_props.py, blossom_tree(), broadleaf(), gnarled_tree(), lerp(), .add()]
- "valleylake_valley_props_paper_lantern": "paper_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L630 | neighbors=[valley_props.py, dock(), lantern_rope(), market_stall(), flat(), .add()]
- "valleylake_valley_props_rounded_mass": "rounded_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L64 | neighbors=[valley_props.py, boulder(), footing(), pillowy rounded-box mass: a subdivided …, rock_steps(), stone_stair()]
- "valleylake_valley_props_skel": "Skel" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L862 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), node list [(pos, radius)] + edges; help…, Palette, .add()]
- "vfxkit_build_build": "build()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L90 | neighbors=[build.py, check_output_dirs(), check_resource_conflicts(), check_targets(), eid(), owned()]
- "vfxkit_evidence_capture_issues": "capture_issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L190 | neighbors=[evidence.py, build_issues(), dependencies(), read_build(), stage_snapshot(), template_issues()]
- "vfxkit_evidence_store": "store()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L23 | neighbors=[evidence.py, latest(), read_build(), read_capture(), submit(), verify()]
- "vfxkit_lint_lint": "lint()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L105 | neighbors=[lint.py, colours(), documented_textures(), hot(), release_frames(), screen_errors()]
- "vfxkit_primitives_beam": "beam()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L433 | neighbors=[primitives.py, _beam_strip(), fade(), radial_sparks(), ramp(), smoke()]
- "vfxkit_sequence_frame_number": "_frame_number()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L155 | neighbors=[sequence.py, capture(), concept_compare(), handoff(), paintover(), sheet_around_steps()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-017.json

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
