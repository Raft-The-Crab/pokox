# Node Description Batch 146 of 209

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

- "unit_session_test": "session_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/session_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, main()]
- "unit_sign_in_test": "sign_in_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/sign_in_test.cpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, main()]
- "unit_slot_registry_test_check": "check()" | kind=code-symbol | source=server/matchmaker/tests/unit/slot_registry_test.cpp:L14 | neighbors=[slot_registry_test.cpp, main()]
- "unit_slot_registry_test_mk": "mk()" | kind=code-symbol | source=server/matchmaker/tests/unit/slot_registry_test.cpp:L20 | neighbors=[slot_registry_test.cpp, main()]
- "unit_soft_body_test": "soft_body_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/soft_body_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, main()]
- "unit_solver_test_tod": "tod()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L27 | neighbors=[solver_test.cpp, main()]
- "unit_solver_test_v3": "v3()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L19 | neighbors=[solver_test.cpp, main()]
- "unit_ssa_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L8 | neighbors=[ssa_test.cpp, cases()]
- "unit_ssa_test_has": "has()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L9 | neighbors=[ssa_test.cpp, cases()]
- "unit_ssa_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L72 | neighbors=[ssa_test.cpp, cases()]
- "unit_state_snapshot_test_checksum": "checksum()" | kind=code-symbol | source=mute/tests/unit/state_snapshot_test.cpp:L15 | neighbors=[state_snapshot_test.cpp, main()]
- "unit_state_snapshot_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/state_snapshot_test.cpp:L20 | neighbors=[state_snapshot_test.cpp, checksum()]
- "unit_statement_test_error": "error()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L29 | neighbors=[statement_test.cpp, cases()]
- "unit_stdlib_collections_test_is_error": "is_error()" | kind=code-symbol | source=mute/tests/unit/stdlib_collections_test.cpp:L18 | neighbors=[stdlib_collections_test.cpp, main()]
- "unit_stdlib_collections_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_collections_test.cpp:L29 | neighbors=[stdlib_collections_test.cpp, is_error()]
- "unit_stdlib_crypto_test_digest_is": "digest_is()" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L18 | neighbors=[stdlib_crypto_test.cpp, main()]
- "unit_stdlib_crypto_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L24 | neighbors=[stdlib_crypto_test.cpp, digest_is()]
- "unit_stdlib_physics_test_box_at": "box_at()" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L23 | neighbors=[stdlib_physics_test.cpp, test_physics_hostcalls()]
- "unit_stdlib_physics_test_test_physics_hostcalls": "test_physics_hostcalls()" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L28 | neighbors=[stdlib_physics_test.cpp, box_at()]
- "unit_step_up_test": "step_up_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/step_up_test.cpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, main()]
- "unit_stress_test_i32t": "i32t()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L21 | neighbors=[stress_test.cpp, pipeline_limits()]
- "unit_test_math_determinism_tracetests_test_corpus_corruption_rejected": ".test_corpus_corruption_rejected()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L43 | neighbors=[TraceTests, .write()]
- "unit_test_math_determinism_tracetests_test_match_is_only_agreement": ".test_match_is_only_agreement()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L28 | neighbors=[TraceTests, .write()]
- "unit_test_math_determinism_tracetests_test_mismatch": ".test_mismatch()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L31 | neighbors=[TraceTests, .check_invalid()]
- "unit_test_math_determinism_tracetests_test_missing_extra_reordered_and_bad_bits": ".test_missing_extra_reordered_and_bad_bits()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L34 | neighbors=[TraceTests, .check_invalid()]
- "unit_test_math_determinism_tracetests_test_same_target_is_not_cross_platform": ".test_same_target_is_not_cross_platform()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L46 | neighbors=[TraceTests, .write()]
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
- "unit_wake_lock_test_check": "check()" | kind=code-symbol | source=server/matchmaker/tests/unit/wake_lock_test.cpp:L13 | neighbors=[wake_lock_test.cpp, main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-145.json

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
