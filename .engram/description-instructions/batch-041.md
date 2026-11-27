# Node Description Batch 42 of 209

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

- "transitions_verify_transition_endpoints": "verify_transition_endpoints.py" | kind=code-symbol | source=assets/characters/transitions/verify_transition_endpoints.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, diff(), pose(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_asset_store_test": "asset_store_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/asset_store_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, counting_loader(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_byo_registration_test": "byo_registration_test.cpp" | kind=code-symbol | source=server/matchmaker/tests/unit/byo_registration_test.cpp:L1 | neighbors=[b925296 Finishes BAK tasks., check(), key(), main(), req()]
- "unit_bytecode_vm_test": "bytecode_vm_test.cpp" | kind=code-symbol | source=mute/tests/unit/bytecode_vm_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_capability_test_narrowed_module": "narrowed_module()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L38 | neighbors=[capability_test.cpp, main(), i32(), pv(), v()]
- "unit_clear_backend_selection": "clear_backend_selection.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/clear_backend_selection.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Fake(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_config_allocation_test": "config_allocation_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/config_allocation_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, allocate_or_throw(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_console_test": "console_test.cpp" | kind=code-symbol | source=mute/tests/unit/console_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), write(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_emit_test_arith_module": "arith_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L18 | neighbors=[emit_test.cpp, i32(), v(), cases(), position_cases()]
- "unit_emit_test_calls_module": "calls_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L28 | neighbors=[emit_test.cpp, i32(), pv(), v(), cases()]
- "unit_emit_test_hostcall_module": "hostcall_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L47 | neighbors=[emit_test.cpp, cases(), i32(), pv(), v()]
- "unit_emit_test_pv": "pv()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L16 | neighbors=[emit_test.cpp, calls_module(), cases(), hostcall_module(), select_module()]
- "unit_evaluator_i8_exhaustive": "evaluator_i8_exhaustive.cpp" | kind=code-symbol | source=mute/tests/unit/evaluator_i8_exhaustive.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, check(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_evaluator_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L41 | neighbors=[evaluator_test.cpp, error_case(), signed_case(), unsigned_case(), main()]
- "unit_evaluator_test_eval": "eval()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L19 | neighbors=[evaluator_test.cpp, error_case(), floating(), signed_case(), unsigned_case()]
- "unit_evaluator_test_floating": "floating()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L80 | neighbors=[evaluator_test.cpp, check(), error_case(), eval(), main()]
- "unit_evaluator_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L213 | neighbors=[evaluator_test.cpp, bindings(), cases(), deep(), floating()]
- "unit_fixed_test": "fixed_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 69287a0 Land ENG-60-65 deterministic si…, fx(), isqrt_ref(), main()]
- "unit_flags_contract": "flags_contract.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/flags_contract.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_frame_stats_test": "frame_stats_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/frame_stats_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), near(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_hostcall_test": "hostcall_test.cpp" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, check(), def(), main(), run_err()]
- "unit_i_platform_contract": "i_platform_contract.cpp" | kind=code-symbol | source=engine/platform/tests/unit/i_platform_contract.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), TestPlatform, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_ktx2_test_main": "main()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L60 | neighbors=[ktx2_test.cpp, make_ktx2(), set32(), set64(), write()]
- "unit_limits_test": "limits_test.cpp" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, check(), compile_recursion(), main(), run_recursion()]
- "unit_lower_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L69 | neighbors=[lower_test.cpp, check(), run_module(), run_source(), main()]
- "unit_narrowphase_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L38 | neighbors=[narrowphase_test.cpp, aabb(), sphere(), tod(), v3()]
- "unit_optimize_test_module_of": "module_of()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L24 | neighbors=[optimize_test.cpp, cases(), lower_src(), run_base(), run_opt()]
- "unit_package_test": "package_test.cpp" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L1 | neighbors=[c7e951a Add MUT-21 package, import and …, cases(), expect_error(), expect_ok(), main()]
- "unit_parser_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L40 | neighbors=[parser_test.cpp, check(), parse_error(), tree(), main()]
- "unit_parser_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L12 | neighbors=[parser_test.cpp, cases(), randomized_input(), stress(), tree()]
- "unit_replay_ring_test": "replay_ring_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/replay_ring_test.cpp:L1 | neighbors=[6e2fe3a Created BAK-7 and other BAK tas…, check(), main(), same_event(), same_tick()]
- "unit_sap_broadphase_test": "sap_broadphase_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, box(), lo(), main(), sorted_pairs()]
- "unit_scheduler_test": "scheduler_test.cpp" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L1 | neighbors=[435b4d3 Add MUT-23 cooperative async sc…, cases(), check(), fin(), main()]
- "unit_state_snapshot_test": "state_snapshot_test.cpp" | kind=code-symbol | source=mute/tests/unit/state_snapshot_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, checksum(), main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_statement_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L36 | neighbors=[statement_test.cpp, check(), dump(), error(), main()]
- "unit_statement_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L12 | neighbors=[statement_test.cpp, cases(), depth_guard(), dump(), randomized_input()]
- "unit_stdlib_physics_test": "stdlib_physics_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L1 | neighbors=[2680d0e Pushed an update., 7eabc2d Merge pull request #8 from Raft…, box_at(), main(), test_physics_hostcalls()]
- "unit_test_math_determinism_tracetests_write": ".write()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L20 | neighbors=[TraceTests, .check_invalid(), .test_corpus_corruption_rejected(), .test_match_is_only_agreement(), .test_same_target_is_not_cross_platform…]
- "unit_test_parser_reference": "test_parser_reference.py" | kind=code-symbol | source=mute/tests/unit/test_parser_reference.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, expression(), reference(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_verify_desktop": "test_verify_desktop.py" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, EvidenceTests, Evidence handling tests, not real SDK o…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-041.json

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
