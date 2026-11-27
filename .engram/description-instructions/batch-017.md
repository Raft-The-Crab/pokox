# Node Description Batch 18 of 208

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

- "unit_action_map_test_game_map": "game_map()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L51 | neighbors=[action_map_test.cpp, axis(), kb(), mouse(), pad(), tap()]
- "unit_debugger_test": "debugger_test.cpp" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, arith(), cases(), check(), divzero(), imm()]
- "unit_emit_test_position_cases": "position_cases()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L209 | neighbors=[emit_test.cpp, main(), arith_module(), check(), compile_source(), i32()]
- "unit_emit_test_v": "v()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L15 | neighbors=[emit_test.cpp, arith_module(), calls_module(), cases(), hostcall_module(), position_cases()]
- "unit_fixed_vec_test": "fixed_vec_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 9eeb3ff Merge pull request #2 from Raft…, len_d(), main(), naive_dot(), naive_in_range()]
- "unit_fold_test": "fold_test.cpp" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…, cases(), check(), count_op(), i32t(), main()]
- "unit_lexer_contract_test": "lexer_contract_test.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, check(), deterministic_streams(), diagnostic(), examples(), main()]
- "unit_ssa_test": "ssa_test.cpp" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L1 | neighbors=[fd66d0d Add MUT-25 typed SSA IR and ver…, cases(), check(), has(), i32(), main()]
- "unit_stress_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L20 | neighbors=[stress_test.cpp, bytecode_limits(), lexer_limits(), package_limits(), pipeline_limits(), program_limits()]
- "unit_stress_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L123 | neighbors=[stress_test.cpp, bytecode_limits(), lexer_limits(), package_limits(), pipeline_limits(), program_limits()]
- "unit_vulkan_triangle_pass_test": "vulkan_triangle_pass_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, draw_and_present(), main(), messages(), reset(), VulkanClearRenderer()]
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
- "vfxkit_sequence_read": "read()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L47 | neighbors=[sequence.py, capture(), concept_compare(), handoff(), issues(), paintover()]
- "vfxkit_sequence_submit": "submit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L368 | neighbors=[sequence.py, criteria(), _frame_number(), gate_path(), issues(), _now()]
- "voidrealm_void_props_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L551 | neighbors=[void_props.py, spawn platform: big round stepped dais,…, annulus(), chamfer_box(), FS(), rune_circle()]
- "warehouse_fitlib": "fitlib.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_owner(), fit(), fit_bad(), _inb()]
- "whispering_grove_forest_props_campfire": "campfire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L392 | neighbors=[forest_props.py, at(), blob(), flame_tongue(), Prop, .add()]
- "whispering_grove_forest_props_log": "log()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L264 | neighbors=[forest_props.py, at(), blob(), mushroom(), Prop, .add()]
- "whispering_grove_forest_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L229 | neighbors=[forest_props.py, log(), at(), Prop, .add(), .gadd()]
- "work_test_uv_overlap_overlaptests": "OverlapTests" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L5 | neighbors=[test_uv_overlap.py, .test_bounding_boxes_overlap_but_triang…, .test_edge_and_point_contact_are_not_ov…, .test_identical_cross_mesh_triangles_ar…, .test_invalid_values_rejected(), .test_outside_atlas_and_degenerate()]
- "animation_build_animations": "build_animations.py" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L1 | neighbors=[foot(), interp(), loc(), rot(), smooth(), 52dbcb9 Surface graphics warnings in X1…]
- "brainstorm_server_branding_test_test": "test()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L110 | neighbors=[branding.test.js, assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap(), assertLogoKeepsTransparentBackground()]
- "brick_bone_hydra_brick_head": "head()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L263 | neighbors=[bone_hydra_brick.py, dil(), J2L(), newid(), put(), sl_of()]
- "brick_lich_king_brick_shift": "shift()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L55 | neighbors=[lich_king_brick.py, back_layer(), cube_dil(), dil(), ero(), front_face()]
- "brick_props_brick_grass_base": "grass_base()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L46 | neighbors=[props_brick.py, bush(), oak(), pine(), mossy ground disc with stepped edge + a…, rocks()]

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
