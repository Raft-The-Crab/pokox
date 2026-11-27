# Node Description Batch 89 of 209

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

- "unit_parser_test_randomized_input": "randomized_input()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L99 | neighbors=[parser_test.cpp, main(), check()]
- "unit_parser_test_stress": "stress()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L122 | neighbors=[parser_test.cpp, main(), check()]
- "unit_parser_test_tree": "tree()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L15 | neighbors=[parser_test.cpp, cases(), check()]
- "unit_party_book_test": "party_book_test.cpp" | kind=code-symbol | source=server/matchmaker/tests/unit/party_book_test.cpp:L1 | neighbors=[b925296 Finishes BAK tasks., check(), main()]
- "unit_pkb_schema_test": "pkb_schema_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/pkb_schema_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, check(), main()]
- "unit_pokomesh_test_main": "main()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L49 | neighbors=[pokomesh_test.cpp, make_pmes(), write()]
- "unit_pokomesh_test_put32": "put32()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L17 | neighbors=[pokomesh_test.cpp, make_pmes(), putf()]
- "unit_pokomesh_test_putf": "putf()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L20 | neighbors=[pokomesh_test.cpp, make_pmes(), put32()]
- "unit_projection_gate_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/projection_gate_test.cpp:L27 | neighbors=[projection_gate_test.cpp, check(), same_generic()]
- "unit_reconnect_test": "reconnect_test.cpp" | kind=code-symbol | source=server/matchmaker/tests/unit/reconnect_test.cpp:L1 | neighbors=[b925296 Finishes BAK tasks., check(), main()]
- "unit_replay_ring_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/replay_ring_test.cpp:L29 | neighbors=[replay_ring_test.cpp, check(), same_tick()]
- "unit_replay_ring_test_same_tick": "same_tick()" | kind=code-symbol | source=server/authority/tests/unit/replay_ring_test.cpp:L20 | neighbors=[replay_ring_test.cpp, main(), same_event()]
- "unit_revocation_gate_test": "revocation_gate_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/revocation_gate_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, check(), main()]
- "unit_rule_evaluator_test": "rule_evaluator_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/rule_evaluator_test.cpp:L1 | neighbors=[6e2fe3a Created BAK-7 and other BAK tas…, check(), main()]
- "unit_sap_broadphase_test_box": "box()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L24 | neighbors=[sap_broadphase_test.cpp, lo(), main()]
- "unit_sap_broadphase_test_lo": "lo()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L21 | neighbors=[sap_broadphase_test.cpp, box(), main()]
- "unit_slot_registry_test_main": "main()" | kind=code-symbol | source=server/matchmaker/tests/unit/slot_registry_test.cpp:L29 | neighbors=[slot_registry_test.cpp, check(), mk()]
- "unit_solver_test_contact": "contact()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L38 | neighbors=[solver_test.cpp, fx(), main()]
- "unit_solver_test_statics": "statics()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L33 | neighbors=[solver_test.cpp, main(), body()]
- "unit_ssa_test_i32": "i32()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L13 | neighbors=[ssa_test.cpp, cases(), valid_module()]
- "unit_ssa_test_v": "v()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L14 | neighbors=[ssa_test.cpp, cases(), valid_module()]
- "unit_statement_test_depth_guard": "depth_guard()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L61 | neighbors=[statement_test.cpp, check(), main()]
- "unit_statement_test_dump": "dump()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L15 | neighbors=[statement_test.cpp, cases(), check()]
- "unit_statement_test_randomized_input": "randomized_input()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L70 | neighbors=[statement_test.cpp, main(), check()]
- "unit_stdlib_collections_test": "stdlib_collections_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_collections_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, is_error(), main()]
- "unit_stdlib_math_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L24 | neighbors=[stdlib_math_test.cpp, near(), near_vec()]
- "unit_stdlib_math_test_near": "near()" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L20 | neighbors=[stdlib_math_test.cpp, main(), near_vec()]
- "unit_stdlib_math_test_near_vec": "near_vec()" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L21 | neighbors=[stdlib_math_test.cpp, main(), near()]
- "unit_stress_test_bytecode_limits": "bytecode_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L40 | neighbors=[stress_test.cpp, check(), main()]
- "unit_stress_test_lexer_limits": "lexer_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L23 | neighbors=[stress_test.cpp, check(), main()]
- "unit_stress_test_package_limits": "package_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L87 | neighbors=[stress_test.cpp, main(), check()]
- "unit_stress_test_program_limits": "program_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L31 | neighbors=[stress_test.cpp, main(), check()]
- "unit_stress_test_scheduler_limits": "scheduler_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L72 | neighbors=[stress_test.cpp, main(), check()]
- "unit_stress_test_values_limits": "values_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L52 | neighbors=[stress_test.cpp, main(), check()]
- "unit_swapchain_frame_loop_test": "swapchain_frame_loop_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/swapchain_frame_loop_test.cpp:L1 | neighbors=[2960ac1 Android Vulkan clear: no fence …, 9eeb3ff Merge pull request #2 from Raft…, main()]
- "unit_test_declaration_golden": "test_declaration_golden.py" | kind=code-symbol | source=mute/tests/unit/test_declaration_golden.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_evaluator_golden": "test_evaluator_golden.py" | kind=code-symbol | source=mute/tests/unit/test_evaluator_golden.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_g1_replay": "test_g1_replay.py" | kind=code-symbol | source=mute/tests/unit/test_g1_replay.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_golden": "test_golden.py" | kind=code-symbol | source=mute/tests/unit/test_golden.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_math_bits": "test_math_bits.py" | kind=code-symbol | source=mute/tests/unit/test_math_bits.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-088.json

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
