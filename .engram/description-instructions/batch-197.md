# Node Description Batch 198 of 207

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
For an entity node (any other kind — e.g. a person, place, event, object),
describe what the entity is and its role, grounded in its type, its
relations (neighbors) and the provided citations/evidence — e.g.
"Lady Carfax, a wealthy heiress who disappears en route to Lausanne.".
Ground entity descriptions in the citations/evidence when present; do not
speculate beyond the context, so a node with no supporting context may be
left out of the reply.
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "unit_parser_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/parser_dump.cpp:L12 | neighbors=[parser_dump.cpp] | lang=en
- "unit_program_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/program_test.cpp:L13 | neighbors=[program_test.cpp] | lang=en
- "unit_run_seed_checks_rationale_1": "Portable GCC/Clang-compatible seed checks. These do NOT use real SDL/Diligent/GP" | kind=entity | source=engine/rhi/tests/unit/run_seed_checks.py:L1 | neighbors=[run_seed_checks.py] | lang=pt
- "unit_run_seed_checks_run": "run()" | kind=code-symbol | source=engine/rhi/tests/unit/run_seed_checks.py:L34 | neighbors=[run_seed_checks.py] | lang=en
- "unit_sdl_platform_faults_sdl_createwindow": "SDL_CreateWindow()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L35 | neighbors=[sdl_platform_faults.cpp] | lang=en
- "unit_sdl_platform_faults_sdl_destroywindow": "SDL_DestroyWindow()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L43 | neighbors=[sdl_platform_faults.cpp] | lang=en
- "unit_sdl_platform_faults_sdl_getwindowid": "SDL_GetWindowID()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L53 | neighbors=[sdl_platform_faults.cpp] | lang=en
- "unit_sdl_platform_faults_sdl_getwindowsize": "SDL_GetWindowSize()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L54 | neighbors=[sdl_platform_faults.cpp] | lang=en
- "unit_sdl_platform_faults_sdl_getwindowsizeinpixels": "SDL_GetWindowSizeInPixels()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L58 | neighbors=[sdl_platform_faults.cpp] | lang=en
- "unit_sdl_platform_faults_sdl_pollevent": "SDL_PollEvent()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L48 | neighbors=[sdl_platform_faults.cpp] | lang=en
- "unit_semantic_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/semantic_dump.cpp:L12 | neighbors=[semantic_dump.cpp] | lang=en
- "unit_session_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/session_test.cpp:L13 | neighbors=[session_test.cpp] | lang=en
- "unit_sign_in_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/sign_in_test.cpp:L10 | neighbors=[sign_in_test.cpp] | lang=en
- "unit_soft_body_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/soft_body_test.cpp:L17 | neighbors=[soft_body_test.cpp] | lang=en
- "unit_state_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/state_test.cpp:L11 | neighbors=[state_test.cpp] | lang=en
- "unit_statement_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/statement_dump.cpp:L12 | neighbors=[statement_dump.cpp] | lang=en
- "unit_stdlib_crypto_test_bytes": "bytes()" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L17 | neighbors=[stdlib_crypto_test.cpp] | lang=en
- "unit_stdlib_physics_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L177 | neighbors=[stdlib_physics_test.cpp] | lang=en
- "unit_step_up_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/step_up_test.cpp:L11 | neighbors=[step_up_test.cpp] | lang=en
- "unit_swapchain_frame_loop_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/swapchain_frame_loop_test.cpp:L71 | neighbors=[swapchain_frame_loop_test.cpp] | lang=en
- "unit_test_declaration_golden": "test_declaration_golden.py" | kind=code-symbol | source=mute/tests/unit/test_declaration_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_evaluator_golden": "test_evaluator_golden.py" | kind=code-symbol | source=mute/tests/unit/test_evaluator_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_evaluator_reference_make": "make()" | kind=code-symbol | source=mute/tests/unit/test_evaluator_reference.py:L9 | neighbors=[test_evaluator_reference.py] | lang=en
- "unit_test_g1_replay": "test_g1_replay.py" | kind=code-symbol | source=mute/tests/unit/test_g1_replay.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_golden": "test_golden.py" | kind=code-symbol | source=mute/tests/unit/test_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_math_accuracy_ordered": "ordered()" | kind=code-symbol | source=mute/tests/unit/test_math_accuracy.py:L6 | neighbors=[test_math_accuracy.py] | lang=en
- "unit_test_math_bits": "test_math_bits.py" | kind=code-symbol | source=mute/tests/unit/test_math_bits.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_math_determinism_tracetests_setup": ".setUp()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L13 | neighbors=[TraceTests] | lang=en
- "unit_test_math_determinism_tracetests_test_duplicate_json_keys_rejected": ".test_duplicate_json_keys_rejected()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L48 | neighbors=[TraceTests] | lang=en
- "unit_test_math_determinism_tracetests_test_overlong_file_rejected": ".test_overlong_file_rejected()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L51 | neighbors=[TraceTests] | lang=en
- "unit_test_parser_golden": "test_parser_golden.py" | kind=code-symbol | source=mute/tests/unit/test_parser_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_parser_reference_expression": "expression()" | kind=code-symbol | source=mute/tests/unit/test_parser_reference.py:L10 | neighbors=[test_parser_reference.py] | lang=en
- "unit_test_parser_reference_reference": "reference()" | kind=code-symbol | source=mute/tests/unit/test_parser_reference.py:L19 | neighbors=[test_parser_reference.py] | lang=en
- "unit_test_pkb_draft_cli_rationale_1": "Check schema preview CLI independently of project source files." | kind=entity | source=mute/tests/unit/test_pkb_draft_cli.py:L1 | neighbors=[test_pkb_draft_cli.py] | lang=en
- "unit_test_semantic_golden": "test_semantic_golden.py" | kind=code-symbol | source=mute/tests/unit/test_semantic_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_statement_golden": "test_statement_golden.py" | kind=code-symbol | source=mute/tests/unit/test_statement_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "unit_test_unicode_generator_run": "run()" | kind=code-symbol | source=mute/tests/unit/test_unicode_generator.py:L21 | neighbors=[test_unicode_generator.py] | lang=en
- "unit_test_verify_desktop_evidencetests_test_bad_summaries": ".test_bad_summaries()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L23 | neighbors=[EvidenceTests] | lang=en
- "unit_test_verify_desktop_evidencetests_test_missing_executable": ".test_missing_executable()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L42 | neighbors=[EvidenceTests] | lang=en
- "unit_test_verify_desktop_evidencetests_test_never_auto_accept": ".test_never_auto_accept()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L27 | neighbors=[EvidenceTests] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-197.json

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
