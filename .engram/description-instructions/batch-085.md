# Node Description Batch 86 of 208

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

- "unit_bench_test_best_ns": "best_ns()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L43 | neighbors=[bench_test.cpp, bench(), run()]
- "unit_bench_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L75 | neighbors=[bench_test.cpp, bench(), main()]
- "unit_bench_test_compile": "compile()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L18 | neighbors=[bench_test.cpp, bench(), i32()]
- "unit_bench_test_run": "run()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L38 | neighbors=[bench_test.cpp, bench(), best_ns()]
- "unit_build_tool_test": "build_tool_test.cpp" | kind=code-symbol | source=mute/tests/unit/build_tool_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, main(), read()]
- "unit_camera_test_main": "main()" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L22 | neighbors=[camera_test.cpp, near(), transform()]
- "unit_character_controller_test_params": "params()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L103 | neighbors=[character_controller_test.cpp, main(), fx()]
- "unit_character_controller_test_tod": "tod()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L28 | neighbors=[character_controller_test.cpp, main(), todv()]
- "unit_character_controller_test_todv": "todv()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L29 | neighbors=[character_controller_test.cpp, main(), tod()]
- "unit_character_controller_test_v3": "v3()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L20 | neighbors=[character_controller_test.cpp, main(), wedge()]
- "unit_character_controller_test_wedge": "wedge()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L42 | neighbors=[character_controller_test.cpp, main(), v3()]
- "unit_check_fault_sensitivity": "check_fault_sensitivity.py" | kind=code-symbol | source=engine/platform/tests/unit/check_fault_sensitivity.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_check_framegraph_mutations": "check_framegraph_mutations.py" | kind=code-symbol | source=engine/render/tests/unit/check_framegraph_mutations.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Optional fault-sensitivity test; compil…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_crypto_aead_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L33 | neighbors=[crypto_aead_test.cpp, hex(), hex_eq()]
- "unit_declaration_dump": "declaration_dump.cpp" | kind=code-symbol | source=mute/tests/unit/declaration_dump.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_declaration_test_depth_guard": "depth_guard()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L62 | neighbors=[declaration_test.cpp, check(), main()]
- "unit_declaration_test_randomized_input": "randomized_input()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L72 | neighbors=[declaration_test.cpp, main(), check()]
- "unit_declaration_test_tree": "tree()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L15 | neighbors=[declaration_test.cpp, cases(), check()]
- "unit_deterministic_math_dump": "deterministic_math_dump.cpp" | kind=code-symbol | source=mute/tests/unit/deterministic_math_dump.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_deterministic_math_test": "deterministic_math_test.cpp" | kind=code-symbol | source=mute/tests/unit/deterministic_math_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_device_router_test_connect": "connect()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L21 | neighbors=[device_router_test.cpp, event(), main()]
- "unit_device_router_test_disconnect": "disconnect()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L24 | neighbors=[device_router_test.cpp, event(), main()]
- "unit_device_router_test_pad_axis": "pad_axis()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L31 | neighbors=[device_router_test.cpp, main(), event()]
- "unit_device_router_test_pad_button": "pad_button()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L27 | neighbors=[device_router_test.cpp, main(), event()]
- "unit_device_router_test_touch_tap": "touch_tap()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L35 | neighbors=[device_router_test.cpp, main(), event()]
- "unit_diff_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L13 | neighbors=[diff_test.cpp, cases(), diff_case()]
- "unit_diff_test_compile": "compile()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L19 | neighbors=[diff_test.cpp, cases(), diff_case()]
- "unit_directional_light_test": "directional_light_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/directional_light_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_duration_query_state_test": "duration_query_state_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/duration_query_state_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_emit_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L13 | neighbors=[emit_test.cpp, cases(), position_cases()]
- "unit_emit_test_compile_source": "compile_source()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L189 | neighbors=[emit_test.cpp, i32(), position_cases()]
- "unit_emit_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L299 | neighbors=[emit_test.cpp, cases(), position_cases()]
- "unit_evaluator_dump": "evaluator_dump.cpp" | kind=code-symbol | source=mute/tests/unit/evaluator_dump.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_evaluator_test_bindings": "bindings()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L136 | neighbors=[evaluator_test.cpp, check(), main()]
- "unit_evaluator_test_unsigned_case": "unsigned_case()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L31 | neighbors=[evaluator_test.cpp, cases(), eval()]
- "unit_events_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/events_test.cpp:L43 | neighbors=[events_test.cpp, configured(), event()]
- "unit_fixed_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_test.cpp:L46 | neighbors=[fixed_test.cpp, fx(), isqrt_ref()]
- "unit_fixed_vec_test_raw3": "raw3()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L27 | neighbors=[fixed_vec_test.cpp, main(), v3()]
- "unit_fixed_vec_test_v3": "v3()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L30 | neighbors=[fixed_vec_test.cpp, main(), raw3()]
- "unit_fold_test_i32t": "i32t()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L12 | neighbors=[fold_test.cpp, cases(), run_source()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-085.json

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
