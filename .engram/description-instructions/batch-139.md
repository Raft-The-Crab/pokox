# Node Description Batch 140 of 207

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

- "unit_capability_test_ceiling": "ceiling()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L28 | neighbors=[capability_test.cpp, main()]
- "unit_capability_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L16 | neighbors=[capability_test.cpp, main()]
- "unit_capability_test_def": "def()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L17 | neighbors=[capability_test.cpp, main()]
- "unit_capability_test_i32": "i32()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L33 | neighbors=[capability_test.cpp, narrowed_module()]
- "unit_capability_test_pv": "pv()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L35 | neighbors=[capability_test.cpp, narrowed_module()]
- "unit_capability_test_run_err": "run_err()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L22 | neighbors=[capability_test.cpp, main()]
- "unit_capability_test_run_narrowed": "run_narrowed()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L55 | neighbors=[capability_test.cpp, main()]
- "unit_capability_test_v": "v()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L34 | neighbors=[capability_test.cpp, narrowed_module()]
- "unit_character_controller_test_aabb": "aabb()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L31 | neighbors=[character_controller_test.cpp, main()]
- "unit_character_controller_test_fx": "fx()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L25 | neighbors=[character_controller_test.cpp, params()]
- "unit_check_fault_sensitivity": "check_fault_sensitivity.py" | kind=code-symbol | source=engine/platform/tests/unit/check_fault_sensitivity.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_check_framegraph_mutations": "check_framegraph_mutations.py" | kind=code-symbol | source=engine/render/tests/unit/check_framegraph_mutations.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Optional fault-sensitivity test; compil…]
- "unit_crypto_aead_test_hex": "hex()" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L24 | neighbors=[crypto_aead_test.cpp, main()]
- "unit_crypto_aead_test_hex_eq": "hex_eq()" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L16 | neighbors=[crypto_aead_test.cpp, main()]
- "unit_cube_sync_test": "cube_sync_test.cpp" | kind=code-symbol | source=server/net/tests/unit/cube_sync_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_debugger_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L8 | neighbors=[debugger_test.cpp, cases()]
- "unit_debugger_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L132 | neighbors=[debugger_test.cpp, cases()]
- "unit_declaration_dump": "declaration_dump.cpp" | kind=code-symbol | source=mute/tests/unit/declaration_dump.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_declaration_test_error": "error()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L31 | neighbors=[declaration_test.cpp, cases()]
- "unit_delta_test": "delta_test.cpp" | kind=code-symbol | source=server/net/tests/unit/delta_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main()]
- "unit_determinism_test_error": "error()" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L16 | neighbors=[determinism_test.cpp, cases()]
- "unit_determinism_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L54 | neighbors=[determinism_test.cpp, cases()]
- "unit_determinism_test_ok": "ok()" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L9 | neighbors=[determinism_test.cpp, cases()]
- "unit_deterministic_math_dump": "deterministic_math_dump.cpp" | kind=code-symbol | source=mute/tests/unit/deterministic_math_dump.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_deterministic_math_test": "deterministic_math_test.cpp" | kind=code-symbol | source=mute/tests/unit/deterministic_math_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_device_binding_test": "device_binding_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/device_binding_test.cpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, main()]
- "unit_device_router_test_apply_events": "apply_events()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L40 | neighbors=[device_router_test.cpp, main()]
- "unit_device_router_test_pos": "pos()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L43 | neighbors=[device_router_test.cpp, main()]
- "unit_device_router_test_run_timeline": "run_timeline()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L44 | neighbors=[device_router_test.cpp, main()]
- "unit_diff_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L142 | neighbors=[diff_test.cpp, cases()]
- "unit_diff_test_run": "run()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L50 | neighbors=[diff_test.cpp, diff_case()]
- "unit_diff_test_same_result": "same_result()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L55 | neighbors=[diff_test.cpp, diff_case()]
- "unit_diff_test_total_words": "total_words()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L44 | neighbors=[diff_test.cpp, cases()]
- "unit_directional_light_test": "directional_light_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/directional_light_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_duration_query_state_test": "duration_query_state_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/duration_query_state_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_evaluator_dump": "evaluator_dump.cpp" | kind=code-symbol | source=mute/tests/unit/evaluator_dump.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_evaluator_i8_exhaustive_check": "check()" | kind=code-symbol | source=mute/tests/unit/evaluator_i8_exhaustive.cpp:L7 | neighbors=[evaluator_i8_exhaustive.cpp, main()]
- "unit_evaluator_i8_exhaustive_main": "main()" | kind=code-symbol | source=mute/tests/unit/evaluator_i8_exhaustive.cpp:L30 | neighbors=[evaluator_i8_exhaustive.cpp, check()]
- "unit_events_test_configured": "configured()" | kind=code-symbol | source=mute/tests/unit/events_test.cpp:L25 | neighbors=[events_test.cpp, main()]
- "unit_events_test_event": "event()" | kind=code-symbol | source=mute/tests/unit/events_test.cpp:L15 | neighbors=[events_test.cpp, main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-139.json

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
