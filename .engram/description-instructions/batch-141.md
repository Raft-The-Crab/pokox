# Node Description Batch 142 of 207

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

- "unit_lower_test_i32t": "i32t()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L12 | neighbors=[lower_test.cpp, run_source()]
- "unit_lower_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L130 | neighbors=[lower_test.cpp, cases()]
- "unit_narrowphase_test_aabb": "aabb()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L22 | neighbors=[narrowphase_test.cpp, main()]
- "unit_narrowphase_test_sphere": "sphere()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L18 | neighbors=[narrowphase_test.cpp, main()]
- "unit_narrowphase_test_todv": "todv()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L35 | neighbors=[narrowphase_test.cpp, tod()]
- "unit_narrowphase_test_v3": "v3()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L29 | neighbors=[narrowphase_test.cpp, main()]
- "unit_optimize_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L12 | neighbors=[optimize_test.cpp, cases()]
- "unit_optimize_test_count_instrs": "count_instrs()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L39 | neighbors=[optimize_test.cpp, cases()]
- "unit_optimize_test_count_op": "count_op()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L36 | neighbors=[optimize_test.cpp, cases()]
- "unit_optimize_test_i32t": "i32t()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L13 | neighbors=[optimize_test.cpp, lower_src()]
- "unit_optimize_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L109 | neighbors=[optimize_test.cpp, cases()]
- "unit_optimize_test_val": "val()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L35 | neighbors=[optimize_test.cpp, cases()]
- "unit_package_test_expect_error": "expect_error()" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L24 | neighbors=[package_test.cpp, cases()]
- "unit_package_test_expect_ok": "expect_ok()" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L12 | neighbors=[package_test.cpp, cases()]
- "unit_package_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L137 | neighbors=[package_test.cpp, cases()]
- "unit_parser_dump": "parser_dump.cpp" | kind=code-symbol | source=mute/tests/unit/parser_dump.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_parser_test_parse_error": "parse_error()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L34 | neighbors=[parser_test.cpp, cases()]
- "unit_pkb_schema_test_check": "check()" | kind=code-symbol | source=server/authority/tests/unit/pkb_schema_test.cpp:L18 | neighbors=[pkb_schema_test.cpp, main()]
- "unit_pkb_schema_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/pkb_schema_test.cpp:L23 | neighbors=[pkb_schema_test.cpp, check()]
- "unit_pokomesh_test_write": "write()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L43 | neighbors=[pokomesh_test.cpp, main()]
- "unit_program_test": "program_test.cpp" | kind=code-symbol | source=mute/tests/unit/program_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_revocation_gate_test_check": "check()" | kind=code-symbol | source=server/identity/tests/unit/revocation_gate_test.cpp:L16 | neighbors=[revocation_gate_test.cpp, main()]
- "unit_revocation_gate_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/revocation_gate_test.cpp:L21 | neighbors=[revocation_gate_test.cpp, check()]
- "unit_sap_broadphase_test_sorted_pairs": "sorted_pairs()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L28 | neighbors=[sap_broadphase_test.cpp, main()]
- "unit_scheduler_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L8 | neighbors=[scheduler_test.cpp, cases()]
- "unit_scheduler_test_fin": "fin()" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L9 | neighbors=[scheduler_test.cpp, cases()]
- "unit_scheduler_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L103 | neighbors=[scheduler_test.cpp, cases()]
- "unit_sdl_platform_faults_push": "push()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L22 | neighbors=[sdl_platform_faults.cpp, main()]
- "unit_sdl_platform_faults_sdl_initsubsystem": "SDL_InitSubSystem()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L28 | neighbors=[sdl_platform_faults.cpp, main()]
- "unit_sdl_platform_faults_sdl_quitsubsystem": "SDL_QuitSubSystem()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L34 | neighbors=[sdl_platform_faults.cpp, main()]
- "unit_semantic_dump": "semantic_dump.cpp" | kind=code-symbol | source=mute/tests/unit/semantic_dump.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "unit_semantic_test_error": "error()" | kind=code-symbol | source=mute/tests/unit/semantic_test.cpp:L22 | neighbors=[semantic_test.cpp, cases()]
- "unit_semantic_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/semantic_test.cpp:L51 | neighbors=[semantic_test.cpp, cases()]
- "unit_semantic_test_ok": "ok()" | kind=code-symbol | source=mute/tests/unit/semantic_test.cpp:L12 | neighbors=[semantic_test.cpp, cases()]
- "unit_session_test": "session_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/session_test.cpp:L1 | neighbors=[6568dc9 Update from ML AI Code, main()]
- "unit_sign_in_test": "sign_in_test.cpp" | kind=code-symbol | source=server/identity/tests/unit/sign_in_test.cpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, main()]
- "unit_soft_body_test": "soft_body_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/soft_body_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, main()]
- "unit_solver_test_tod": "tod()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L27 | neighbors=[solver_test.cpp, main()]
- "unit_solver_test_v3": "v3()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L19 | neighbors=[solver_test.cpp, main()]
- "unit_ssa_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L8 | neighbors=[ssa_test.cpp, cases()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-141.json

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
