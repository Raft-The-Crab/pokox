# Node Description Batch 88 of 209

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

- "unit_crypto_aead_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L33 | neighbors=[crypto_aead_test.cpp, hex(), hex_eq()]
- "unit_declaration_test_depth_guard": "depth_guard()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L62 | neighbors=[declaration_test.cpp, check(), main()]
- "unit_declaration_test_randomized_input": "randomized_input()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L72 | neighbors=[declaration_test.cpp, main(), check()]
- "unit_declaration_test_tree": "tree()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L15 | neighbors=[declaration_test.cpp, cases(), check()]
- "unit_device_router_test_connect": "connect()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L21 | neighbors=[device_router_test.cpp, event(), main()]
- "unit_device_router_test_disconnect": "disconnect()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L24 | neighbors=[device_router_test.cpp, event(), main()]
- "unit_device_router_test_pad_axis": "pad_axis()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L31 | neighbors=[device_router_test.cpp, main(), event()]
- "unit_device_router_test_pad_button": "pad_button()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L27 | neighbors=[device_router_test.cpp, main(), event()]
- "unit_device_router_test_touch_tap": "touch_tap()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L35 | neighbors=[device_router_test.cpp, main(), event()]
- "unit_diff_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L13 | neighbors=[diff_test.cpp, cases(), diff_case()]
- "unit_diff_test_compile": "compile()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L19 | neighbors=[diff_test.cpp, cases(), diff_case()]
- "unit_emit_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L13 | neighbors=[emit_test.cpp, cases(), position_cases()]
- "unit_emit_test_compile_source": "compile_source()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L189 | neighbors=[emit_test.cpp, i32(), position_cases()]
- "unit_emit_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L299 | neighbors=[emit_test.cpp, cases(), position_cases()]
- "unit_evaluator_test_bindings": "bindings()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L136 | neighbors=[evaluator_test.cpp, check(), main()]
- "unit_evaluator_test_unsigned_case": "unsigned_case()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L31 | neighbors=[evaluator_test.cpp, cases(), eval()]
- "unit_events_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/events_test.cpp:L43 | neighbors=[events_test.cpp, configured(), event()]
- "unit_fixed_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_test.cpp:L46 | neighbors=[fixed_test.cpp, fx(), isqrt_ref()]
- "unit_fixed_vec_test_raw3": "raw3()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L27 | neighbors=[fixed_vec_test.cpp, main(), v3()]
- "unit_fixed_vec_test_v3": "v3()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L30 | neighbors=[fixed_vec_test.cpp, main(), raw3()]
- "unit_fold_test_i32t": "i32t()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L12 | neighbors=[fold_test.cpp, cases(), run_source()]
- "unit_fold_test_run_source": "run_source()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L15 | neighbors=[fold_test.cpp, cases(), i32t()]
- "unit_imgui_pass_faults_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L127 | neighbors=[imgui_pass_faults.cpp, reset(), write_spirv()]
- "unit_input_snapshot_test_button": "button()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L20 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_key": "key()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L17 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_motion": "motion()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L23 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_simple": "simple()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L39 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_input_snapshot_test_wheel": "wheel()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L26 | neighbors=[input_snapshot_test.cpp, main(), record_hashes()]
- "unit_jitter_buffer_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/jitter_buffer_test.cpp:L26 | neighbors=[jitter_buffer_test.cpp, next_rand(), true_x()]
- "unit_lexer_contract_test_deterministic_streams": "deterministic_streams()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L81 | neighbors=[lexer_contract_test.cpp, tokens(), main()]
- "unit_lexer_contract_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L100 | neighbors=[lexer_contract_test.cpp, deterministic_streams(), examples()]
- "unit_lexer_test_error": "error()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L16 | neighbors=[lexer_test.cpp, check(), test_cases()]
- "unit_lexer_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L85 | neighbors=[lexer_test.cpp, test_cases(), unicode_conformance()]
- "unit_lexer_test_unicode_conformance": "unicode_conformance()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L65 | neighbors=[lexer_test.cpp, main(), check()]
- "unit_loop_test": "loop_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/loop_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, main(), near()]
- "unit_lower_test_run_module": "run_module()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L58 | neighbors=[lower_test.cpp, cases(), compile_module()]
- "unit_lower_test_run_source": "run_source()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L15 | neighbors=[lower_test.cpp, cases(), i32t()]
- "unit_match_queue_test_main": "main()" | kind=code-symbol | source=server/matchmaker/tests/unit/match_queue_test.cpp:L27 | neighbors=[match_queue_test.cpp, check(), req()]
- "unit_narrowphase_test_tod": "tod()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L34 | neighbors=[narrowphase_test.cpp, main(), todv()]
- "unit_optimize_test_lower_src": "lower_src()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L15 | neighbors=[optimize_test.cpp, i32t(), module_of()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-087.json

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
