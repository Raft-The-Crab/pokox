# Node Description Batch 87 of 208

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

- "unit_fold_test_run_source": "run_source()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L15 | neighbors=[fold_test.cpp, cases(), i32t()]
- "unit_frame_graph_test": "frame_graph_test.cpp" | kind=code-symbol | source=engine/render/tests/unit/frame_graph_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_imgui_pass_faults_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L127 | neighbors=[imgui_pass_faults.cpp, reset(), write_spirv()]
- "unit_input_snapshot_test_button": "button()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L20 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_key": "key()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L17 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_motion": "motion()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L23 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_simple": "simple()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L39 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_wheel": "wheel()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L26 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_jitter_buffer_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/jitter_buffer_test.cpp:L26 | neighbors=[jitter_buffer_test.cpp, next_rand(), true_x()]
- "unit_lexer_contract_test_deterministic_streams": "deterministic_streams()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L81 | neighbors=[lexer_contract_test.cpp, tokens(), main()]
- "unit_lexer_contract_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L100 | neighbors=[lexer_contract_test.cpp, deterministic_streams(), examples()]
- "unit_lexer_dump": "lexer_dump.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_dump.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_lexer_test_error": "error()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L16 | neighbors=[lexer_test.cpp, check(), test_cases()]
- "unit_lexer_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L85 | neighbors=[lexer_test.cpp, test_cases(), unicode_conformance()]
- "unit_lexer_test_unicode_conformance": "unicode_conformance()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L65 | neighbors=[lexer_test.cpp, main(), check()]
- "unit_loop_test": "loop_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/loop_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, main(), near()]
- "unit_lower_test_run_module": "run_module()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L58 | neighbors=[lower_test.cpp, cases(), compile_module()]
- "unit_lower_test_run_source": "run_source()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L15 | neighbors=[lower_test.cpp, cases(), i32t()]
- "unit_narrowphase_test_tod": "tod()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L34 | neighbors=[narrowphase_test.cpp, main(), todv()]
- "unit_optimize_test_lower_src": "lower_src()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L15 | neighbors=[optimize_test.cpp, i32t(), module_of()]
- "unit_parser_dump": "parser_dump.cpp" | kind=code-symbol | source=mute/tests/unit/parser_dump.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_parser_test_randomized_input": "randomized_input()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L99 | neighbors=[parser_test.cpp, main(), check()]
- "unit_parser_test_stress": "stress()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L122 | neighbors=[parser_test.cpp, main(), check()]
- "unit_parser_test_tree": "tree()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L15 | neighbors=[parser_test.cpp, cases(), check()]
- "unit_pkb_schema_test": "pkb_schema_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/pkb_schema_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, check(), main()]
- "unit_pokomesh_test_main": "main()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L49 | neighbors=[pokomesh_test.cpp, make_pmes(), write()]
- "unit_pokomesh_test_put32": "put32()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L17 | neighbors=[pokomesh_test.cpp, make_pmes(), putf()]
- "unit_pokomesh_test_putf": "putf()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L20 | neighbors=[pokomesh_test.cpp, make_pmes(), put32()]
- "unit_program_test": "program_test.cpp" | kind=code-symbol | source=mute/tests/unit/program_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_projection_gate_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/projection_gate_test.cpp:L27 | neighbors=[projection_gate_test.cpp, check(), same_generic()]
- "unit_replay_ring_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/replay_ring_test.cpp:L29 | neighbors=[replay_ring_test.cpp, check(), same_tick()]
- "unit_replay_ring_test_same_tick": "same_tick()" | kind=code-symbol | source=server/authority/tests/unit/replay_ring_test.cpp:L20 | neighbors=[replay_ring_test.cpp, main(), same_event()]
- "unit_revocation_gate_test": "revocation_gate_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/revocation_gate_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, check(), main()]
- "unit_rule_evaluator_test": "rule_evaluator_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/rule_evaluator_test.cpp:L1 | neighbors=[6e2fe3a Created BAK-7 and other BAK tas…, check(), main()]
- "unit_sap_broadphase_test_box": "box()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L24 | neighbors=[sap_broadphase_test.cpp, lo(), main()]
- "unit_sap_broadphase_test_lo": "lo()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L21 | neighbors=[sap_broadphase_test.cpp, box(), main()]
- "unit_semantic_dump": "semantic_dump.cpp" | kind=code-symbol | source=mute/tests/unit/semantic_dump.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_solver_test_contact": "contact()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L38 | neighbors=[solver_test.cpp, fx(), main()]
- "unit_solver_test_statics": "statics()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L33 | neighbors=[solver_test.cpp, main(), body()]
- "unit_ssa_test_i32": "i32()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L13 | neighbors=[ssa_test.cpp, cases(), valid_module()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-086.json

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
