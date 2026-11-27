# Node Description Batch 60 of 209

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

- "unit_hostcall_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L26 | neighbors=[hostcall_test.cpp, check(), def(), run_err()]
- "unit_jitter_buffer_test": "jitter_buffer_test.cpp" | kind=code-symbol | source=server/net/tests/unit/jitter_buffer_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main(), next_rand(), true_x()]
- "unit_ktx2_test_make_ktx2": "make_ktx2()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L28 | neighbors=[ktx2_test.cpp, main(), put32(), put64()]
- "unit_lexer_contract_test_examples": "examples()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L42 | neighbors=[lexer_contract_test.cpp, diagnostic(), tokens(), main()]
- "unit_lexer_contract_test_tokens": "tokens()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L17 | neighbors=[lexer_contract_test.cpp, deterministic_streams(), examples(), check()]
- "unit_lexer_dump": "lexer_dump.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_lexer_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L15 | neighbors=[lexer_test.cpp, error(), test_cases(), unicode_conformance()]
- "unit_lexer_test_test_cases": "test_cases()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L19 | neighbors=[lexer_test.cpp, main(), check(), error()]
- "unit_limits_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L42 | neighbors=[limits_test.cpp, check(), compile_recursion(), run_recursion()]
- "unit_match_queue_test": "match_queue_test.cpp" | kind=code-symbol | source=server/matchmaker/tests/unit/match_queue_test.cpp:L1 | neighbors=[b925296 Finishes BAK tasks., check(), main(), req()]
- "unit_optimize_test_run_base": "run_base()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L55 | neighbors=[optimize_test.cpp, cases(), module_of(), run_mod()]
- "unit_optimize_test_run_mod": "run_mod()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L29 | neighbors=[optimize_test.cpp, cases(), run_base(), run_opt()]
- "unit_optimize_test_run_opt": "run_opt()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L43 | neighbors=[optimize_test.cpp, cases(), module_of(), run_mod()]
- "unit_package_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L35 | neighbors=[package_test.cpp, expect_error(), expect_ok(), main()]
- "unit_parser_dump": "parser_dump.cpp" | kind=code-symbol | source=mute/tests/unit/parser_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_parser_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L142 | neighbors=[parser_test.cpp, cases(), randomized_input(), stress()]
- "unit_pokomesh_test_make_pmes": "make_pmes()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L28 | neighbors=[pokomesh_test.cpp, main(), put32(), putf()]
- "unit_program_test": "program_test.cpp" | kind=code-symbol | source=mute/tests/unit/program_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_projection_gate_test": "projection_gate_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/projection_gate_test.cpp:L1 | neighbors=[6e2fe3a Created BAK-7 and other BAK tas…, check(), main(), same_generic()]
- "unit_sap_broadphase_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L36 | neighbors=[sap_broadphase_test.cpp, box(), lo(), sorted_pairs()]
- "unit_scheduler_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L11 | neighbors=[scheduler_test.cpp, check(), fin(), main()]
- "unit_sdl_platform_faults_main": "main()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L66 | neighbors=[sdl_platform_faults.cpp, push(), SDL_InitSubSystem(), SDL_QuitSubSystem()]
- "unit_semantic_dump": "semantic_dump.cpp" | kind=code-symbol | source=mute/tests/unit/semantic_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_semantic_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/semantic_test.cpp:L31 | neighbors=[semantic_test.cpp, error(), ok(), main()]
- "unit_slot_registry_test": "slot_registry_test.cpp" | kind=code-symbol | source=server/matchmaker/tests/unit/slot_registry_test.cpp:L1 | neighbors=[b925296 Finishes BAK tasks., check(), main(), mk()]
- "unit_solver_test_body": "body()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L29 | neighbors=[solver_test.cpp, fx(), main(), statics()]
- "unit_solver_test_fx": "fx()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L24 | neighbors=[solver_test.cpp, body(), contact(), main()]
- "unit_ssa_test_valid_module": "valid_module()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L16 | neighbors=[ssa_test.cpp, cases(), i32(), v()]
- "unit_state_test": "state_test.cpp" | kind=code-symbol | source=mute/tests/unit/state_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_statement_dump": "statement_dump.cpp" | kind=code-symbol | source=mute/tests/unit/statement_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_statement_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L88 | neighbors=[statement_test.cpp, cases(), depth_guard(), randomized_input()]
- "unit_stress_test_pipeline_limits": "pipeline_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L106 | neighbors=[stress_test.cpp, main(), check(), i32t()]
- "unit_test_evaluator_reference": "test_evaluator_reference.py" | kind=code-symbol | source=mute/tests/unit/test_evaluator_reference.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, make(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_math_accuracy": "test_math_accuracy.py" | kind=code-symbol | source=mute/tests/unit/test_math_accuracy.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, ordered(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_math_determinism": "test_math_determinism.py" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, TraceTests, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_math_determinism_tracetests_check_invalid": ".check_invalid()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L24 | neighbors=[TraceTests, .write(), .test_mismatch(), .test_missing_extra_reordered_and_bad_b…]
- "unit_test_pkb_draft_cli": "test_pkb_draft_cli.py" | kind=code-symbol | source=mute/tests/unit/test_pkb_draft_cli.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Check schema preview CLI independently …, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_unicode_generator": "test_unicode_generator.py" | kind=code-symbol | source=mute/tests/unit/test_unicode_generator.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, run(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_verify_desktop_evidencetests_simulate": ".simulate()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L46 | neighbors=[EvidenceTests, .test_failed_configure_preserved(), .test_nonzero_runtime_cannot_pass(), .test_simulated_success_keeps_gate_open…]
- "unit_values_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L12 | neighbors=[values_test.cpp, check(), unwrap(), main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-059.json

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
