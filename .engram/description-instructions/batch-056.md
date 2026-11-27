# Node Description Batch 57 of 207

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

- "towncity_town_props_ball": "ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L70 | neighbors=[town_props.py, antenna(), building(), water_tank()]
- "towncity_town_props_roof_shed": "roof_shed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L155 | neighbors=[town_props.py, building(), stair bulkhead: small box room with a d…, add()]
- "towncity_town_vehicles_body_shader": "body_shader()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L34 | neighbors=[town_vehicles.py, bus(), car(), face colours: rocker + underside dark m…]
- "towncity_town_vehicles_smoothstep": "_smoothstep()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L9 | neighbors=[town_vehicles.py, bus(), car(), _car_shell()]
- "towncity_town_vehicles_train_car": "train_car()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L163 | neighbors=[town_vehicles.py, commuter train car: lofted shell (teal …, _car_shell(), _train_shader()]
- "unit_camera_test": "camera_test.cpp" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main(), near(), transform()]
- "unit_crypto_aead_test": "crypto_aead_test.cpp" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, hex(), hex_eq(), main()]
- "unit_debugger_test_arith": "arith()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L13 | neighbors=[debugger_test.cpp, imm(), pay(), cases()]
- "unit_debugger_test_divzero": "divzero()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L17 | neighbors=[debugger_test.cpp, cases(), imm(), pay()]
- "unit_debugger_test_imm": "imm()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L10 | neighbors=[debugger_test.cpp, arith(), cases(), divzero()]
- "unit_debugger_test_pay": "pay()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L9 | neighbors=[debugger_test.cpp, arith(), cases(), divzero()]
- "unit_declaration_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L38 | neighbors=[declaration_test.cpp, error(), tree(), main()]
- "unit_declaration_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L12 | neighbors=[declaration_test.cpp, depth_guard(), randomized_input(), tree()]
- "unit_declaration_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L90 | neighbors=[declaration_test.cpp, cases(), depth_guard(), randomized_input()]
- "unit_determinism_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L25 | neighbors=[determinism_test.cpp, error(), ok(), main()]
- "unit_emit_test_wide_call_module": "wide_call_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L61 | neighbors=[emit_test.cpp, cases(), i32(), v()]
- "unit_evaluator_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L18 | neighbors=[evaluator_test.cpp, bindings(), deep(), floating()]
- "unit_evaluator_test_deep": "deep()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L195 | neighbors=[evaluator_test.cpp, check(), signed_case(), main()]
- "unit_evaluator_test_error_case": "error_case()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L37 | neighbors=[evaluator_test.cpp, cases(), eval(), floating()]
- "unit_evaluator_test_signed_case": "signed_case()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L25 | neighbors=[evaluator_test.cpp, cases(), deep(), eval()]
- "unit_events_test": "events_test.cpp" | kind=code-symbol | source=mute/tests/unit/events_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, configured(), event(), main()]
- "unit_hostcall_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L26 | neighbors=[hostcall_test.cpp, check(), def(), run_err()]
- "unit_jitter_buffer_test": "jitter_buffer_test.cpp" | kind=code-symbol | source=server/net/tests/unit/jitter_buffer_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main(), next_rand(), true_x()]
- "unit_ktx2_test_make_ktx2": "make_ktx2()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L28 | neighbors=[ktx2_test.cpp, main(), put32(), put64()]
- "unit_lexer_contract_test_examples": "examples()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L42 | neighbors=[lexer_contract_test.cpp, diagnostic(), tokens(), main()]
- "unit_lexer_contract_test_tokens": "tokens()" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L17 | neighbors=[lexer_contract_test.cpp, deterministic_streams(), examples(), check()]
- "unit_lexer_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L15 | neighbors=[lexer_test.cpp, error(), test_cases(), unicode_conformance()]
- "unit_lexer_test_test_cases": "test_cases()" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L19 | neighbors=[lexer_test.cpp, main(), check(), error()]
- "unit_limits_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L42 | neighbors=[limits_test.cpp, check(), compile_recursion(), run_recursion()]
- "unit_optimize_test_run_base": "run_base()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L55 | neighbors=[optimize_test.cpp, cases(), module_of(), run_mod()]
- "unit_optimize_test_run_mod": "run_mod()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L29 | neighbors=[optimize_test.cpp, cases(), run_base(), run_opt()]
- "unit_optimize_test_run_opt": "run_opt()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L43 | neighbors=[optimize_test.cpp, cases(), module_of(), run_mod()]
- "unit_package_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L35 | neighbors=[package_test.cpp, expect_error(), expect_ok(), main()]
- "unit_parser_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L142 | neighbors=[parser_test.cpp, cases(), randomized_input(), stress()]
- "unit_pokomesh_test_make_pmes": "make_pmes()" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L28 | neighbors=[pokomesh_test.cpp, main(), put32(), putf()]
- "unit_run_seed_checks": "run_seed_checks.py" | kind=code-symbol | source=engine/rhi/tests/unit/run_seed_checks.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …, run(), Portable GCC/Clang-compatible seed chec…]
- "unit_sap_broadphase_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L36 | neighbors=[sap_broadphase_test.cpp, box(), lo(), sorted_pairs()]
- "unit_scheduler_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L11 | neighbors=[scheduler_test.cpp, check(), fin(), main()]
- "unit_sdl_platform_faults_main": "main()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L66 | neighbors=[sdl_platform_faults.cpp, push(), SDL_InitSubSystem(), SDL_QuitSubSystem()]
- "unit_semantic_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/semantic_test.cpp:L31 | neighbors=[semantic_test.cpp, error(), ok(), main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-056.json

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
