# Node Description Batch 145 of 208

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

- "unit_stdlib_crypto_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L24 | neighbors=[stdlib_crypto_test.cpp, digest_is()]
- "unit_stdlib_physics_test_box_at": "box_at()" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L23 | neighbors=[stdlib_physics_test.cpp, test_physics_hostcalls()]
- "unit_stdlib_physics_test_test_physics_hostcalls": "test_physics_hostcalls()" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L28 | neighbors=[stdlib_physics_test.cpp, box_at()]
- "unit_step_up_test": "step_up_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/step_up_test.cpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, main()]
- "unit_stress_test_i32t": "i32t()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L21 | neighbors=[stress_test.cpp, pipeline_limits()]
- "unit_test_declaration_golden": "test_declaration_golden.py" | kind=code-symbol | source=mute/tests/unit/test_declaration_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_evaluator_golden": "test_evaluator_golden.py" | kind=code-symbol | source=mute/tests/unit/test_evaluator_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_g1_replay": "test_g1_replay.py" | kind=code-symbol | source=mute/tests/unit/test_g1_replay.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_golden": "test_golden.py" | kind=code-symbol | source=mute/tests/unit/test_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_math_bits": "test_math_bits.py" | kind=code-symbol | source=mute/tests/unit/test_math_bits.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_math_determinism_tracetests_test_corpus_corruption_rejected": ".test_corpus_corruption_rejected()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L43 | neighbors=[TraceTests, .write()]
- "unit_test_math_determinism_tracetests_test_match_is_only_agreement": ".test_match_is_only_agreement()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L28 | neighbors=[TraceTests, .write()]
- "unit_test_math_determinism_tracetests_test_mismatch": ".test_mismatch()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L31 | neighbors=[TraceTests, .check_invalid()]
- "unit_test_math_determinism_tracetests_test_missing_extra_reordered_and_bad_bits": ".test_missing_extra_reordered_and_bad_bits()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L34 | neighbors=[TraceTests, .check_invalid()]
- "unit_test_math_determinism_tracetests_test_same_target_is_not_cross_platform": ".test_same_target_is_not_cross_platform()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L46 | neighbors=[TraceTests, .write()]
- "unit_test_parser_golden": "test_parser_golden.py" | kind=code-symbol | source=mute/tests/unit/test_parser_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_semantic_golden": "test_semantic_golden.py" | kind=code-symbol | source=mute/tests/unit/test_semantic_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_statement_golden": "test_statement_golden.py" | kind=code-symbol | source=mute/tests/unit/test_statement_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_test_verify_desktop_evidencetests_test_failed_configure_preserved": ".test_failed_configure_preserved()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L61 | neighbors=[EvidenceTests, .simulate()]
- "unit_test_verify_desktop_evidencetests_test_nonzero_runtime_cannot_pass": ".test_nonzero_runtime_cannot_pass()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L68 | neighbors=[EvidenceTests, .simulate()]
- "unit_test_verify_desktop_evidencetests_test_simulated_success_keeps_gate_open": ".test_simulated_success_keeps_gate_open()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L54 | neighbors=[EvidenceTests, .simulate()]
- "unit_udp_echo_test": "udp_echo_test.cpp" | kind=code-symbol | source=server/net/tests/unit/udp_echo_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_values_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L7 | neighbors=[values_test.cpp, cases()]
- "unit_values_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L103 | neighbors=[values_test.cpp, cases()]
- "unit_values_test_unwrap": "unwrap()" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L8 | neighbors=[values_test.cpp, cases()]
- "unit_velocity_test": "velocity_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/velocity_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_visual_solver_test_dyn_sphere": "dyn_sphere()" | kind=code-symbol | source=engine/physics/tests/unit/visual_solver_test.cpp:L25 | neighbors=[visual_solver_test.cpp, main()]
- "unit_visual_solver_test_static_box": "static_box()" | kind=code-symbol | source=engine/physics/tests/unit/visual_solver_test.cpp:L37 | neighbors=[visual_solver_test.cpp, main()]
- "unit_vulkan_diagnostics_filter_test": "vulkan_diagnostics_filter_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_diagnostics_filter_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main()]
- "unit_vulkan_triangle_pass_test_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L18 | neighbors=[vulkan_triangle_pass_test.cpp, main()]
- "unit_vulkan_triangle_pass_test_reset": "reset()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L23 | neighbors=[vulkan_triangle_pass_test.cpp, main()]
- "unit_worker_auth_test_check": "check()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L17 | neighbors=[worker_auth_test.cpp, main()]
- "unit_worker_auth_test_sample_ticket": "sample_ticket()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L58 | neighbors=[worker_auth_test.cpp, main()]
- "unit_worker_auth_test_sign_input": "sign_input()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L33 | neighbors=[worker_auth_test.cpp, make_token()]
- "unit_worker_auth_test_test_key": "test_key()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L49 | neighbors=[worker_auth_test.cpp, main()]
- "unit_ws_transport_test": "ws_transport_test.cpp" | kind=code-symbol | source=server/net/tests/unit/ws_transport_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_xor_fec_test": "xor_fec_test.cpp" | kind=code-symbol | source=server/net/tests/unit/xor_fec_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "valleylake_compare": "compare.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/compare.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "valleylake_grid": "grid.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/grid.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "valleylake_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-144.json

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
