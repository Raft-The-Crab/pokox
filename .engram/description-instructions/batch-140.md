# Node Description Batch 141 of 207

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

- "unit_fixed_test_fx": "fx()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_test.cpp:L25 | neighbors=[fixed_test.cpp, main()]
- "unit_fixed_test_isqrt_ref": "isqrt_ref()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_test.cpp:L29 | neighbors=[fixed_test.cpp, main()]
- "unit_fixed_vec_test_len_d": "len_d()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L45 | neighbors=[fixed_vec_test.cpp, main()]
- "unit_fixed_vec_test_naive_dot": "naive_dot()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L36 | neighbors=[fixed_vec_test.cpp, main()]
- "unit_fixed_vec_test_naive_in_range": "naive_in_range()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L37 | neighbors=[fixed_vec_test.cpp, main()]
- "unit_fold_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L11 | neighbors=[fold_test.cpp, cases()]
- "unit_fold_test_count_op": "count_op()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L38 | neighbors=[fold_test.cpp, cases()]
- "unit_fold_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L94 | neighbors=[fold_test.cpp, cases()]
- "unit_fold_test_val": "val()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L37 | neighbors=[fold_test.cpp, cases()]
- "unit_frame_graph_test": "frame_graph_test.cpp" | kind=code-symbol | source=engine/render/tests/unit/frame_graph_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_frame_stats_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/frame_stats_test.cpp:L17 | neighbors=[frame_stats_test.cpp, near()]
- "unit_frame_stats_test_near": "near()" | kind=code-symbol | source=engine/foundation/tests/unit/frame_stats_test.cpp:L14 | neighbors=[frame_stats_test.cpp, main()]
- "unit_frame_test": "frame_test.cpp" | kind=code-symbol | source=server/net/tests/unit/frame_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_hostcall_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L14 | neighbors=[hostcall_test.cpp, main()]
- "unit_hostcall_test_def": "def()" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L15 | neighbors=[hostcall_test.cpp, main()]
- "unit_hostcall_test_run_err": "run_err()" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L20 | neighbors=[hostcall_test.cpp, main()]
- "unit_i_platform_contract_testplatform": "TestPlatform" | kind=code-symbol | source=engine/platform/tests/unit/i_platform_contract.cpp:L24 | neighbors=[i_platform_contract.cpp, IPlatform]
- "unit_imgui_pass_faults_reset": "reset()" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L22 | neighbors=[imgui_pass_faults.cpp, main()]
- "unit_imgui_pass_faults_write_spirv": "write_spirv()" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L119 | neighbors=[imgui_pass_faults.cpp, main()]
- "unit_input_snapshot_test_gamepad_axis": "gamepad_axis()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L32 | neighbors=[input_snapshot_test.cpp, main()]
- "unit_input_snapshot_test_gamepad_button": "gamepad_button()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L29 | neighbors=[input_snapshot_test.cpp, main()]
- "unit_input_snapshot_test_pos": "pos()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L40 | neighbors=[input_snapshot_test.cpp, main()]
- "unit_input_snapshot_test_touch": "touch()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L35 | neighbors=[input_snapshot_test.cpp, main()]
- "unit_jitter_buffer_test_next_rand": "next_rand()" | kind=code-symbol | source=server/net/tests/unit/jitter_buffer_test.cpp:L18 | neighbors=[jitter_buffer_test.cpp, main()]
- "unit_jitter_buffer_test_true_x": "true_x()" | kind=code-symbol | source=server/net/tests/unit/jitter_buffer_test.cpp:L23 | neighbors=[jitter_buffer_test.cpp, main()]
- "unit_ktx2_test_put32": "put32()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L14 | neighbors=[ktx2_test.cpp, make_ktx2()]
- "unit_ktx2_test_put64": "put64()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L17 | neighbors=[ktx2_test.cpp, make_ktx2()]
- "unit_ktx2_test_set32": "set32()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L20 | neighbors=[ktx2_test.cpp, main()]
- "unit_ktx2_test_set64": "set64()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L23 | neighbors=[ktx2_test.cpp, main()]
- "unit_ktx2_test_write": "write()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L55 | neighbors=[ktx2_test.cpp, main()]
- "unit_lexer_contract_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L13 | neighbors=[lexer_contract_test.cpp, tokens()]
- "unit_lexer_contract_test_diagnostic": "diagnostic()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L34 | neighbors=[lexer_contract_test.cpp, examples()]
- "unit_lexer_dump": "lexer_dump.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_dump.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_limits_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L17 | neighbors=[limits_test.cpp, main()]
- "unit_limits_test_compile_recursion": "compile_recursion()" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L20 | neighbors=[limits_test.cpp, main()]
- "unit_limits_test_run_recursion": "run_recursion()" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L36 | neighbors=[limits_test.cpp, main()]
- "unit_loop_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/loop_test.cpp:L17 | neighbors=[loop_test.cpp, near()]
- "unit_loop_test_near": "near()" | kind=code-symbol | source=engine/foundation/tests/unit/loop_test.cpp:L14 | neighbors=[loop_test.cpp, main()]
- "unit_lower_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L11 | neighbors=[lower_test.cpp, cases()]
- "unit_lower_test_compile_module": "compile_module()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L35 | neighbors=[lower_test.cpp, run_module()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-140.json

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
