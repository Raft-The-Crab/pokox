# Node Description Batch 59 of 209

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

- "towncity_town_map_railway": "railway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L195 | neighbors=[town_map.py, build(), place(), rail corridor: two tracks along Z behin…]
- "towncity_town_map_rot": "rot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L85 | neighbors=[town_map.py, anchor_local(), landmarks(), local (x, y, z) of a prop turned by yaw…]
- "towncity_town_map_zebra": "zebra()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L119 | neighbors=[town_map.py, markings(), crosswalk stripes across a road: stripe…, flat()]
- "towncity_town_props_ac_unit": "ac_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L119 | neighbors=[town_props.py, add(), building(), rooftop / wall AC: cream casing on feet…]
- "towncity_town_props_antenna": "antenna()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L146 | neighbors=[town_props.py, add(), ball(), building()]
- "towncity_town_props_ball": "ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L70 | neighbors=[town_props.py, antenna(), building(), water_tank()]
- "towncity_town_props_roof_shed": "roof_shed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L155 | neighbors=[town_props.py, building(), stair bulkhead: small box room with a d…, add()]
- "towncity_town_vehicles_body_shader": "body_shader()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L34 | neighbors=[town_vehicles.py, bus(), car(), face colours: rocker + underside dark m…]
- "towncity_town_vehicles_smoothstep": "_smoothstep()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L9 | neighbors=[town_vehicles.py, bus(), car(), _car_shell()]
- "towncity_town_vehicles_train_car": "train_car()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L163 | neighbors=[town_vehicles.py, commuter train car: lofted shell (teal …, _car_shell(), _train_shader()]
- "transitions_build_transitions": "build_transitions.py" | kind=code-symbol | source=assets/characters/transitions/build_transitions.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, capture(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "transitions_v2_build_transitions": "build_transitions.py" | kind=code-symbol | source=assets/characters/transitions-v2/build_transitions.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, capture(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "triangle_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/RefCntAutoPtr.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, RefCntAutoPtr, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_allocator_test": "allocator_test.cpp" | kind=code-symbol | source=server/matchmaker/tests/unit/allocator_test.cpp:L1 | neighbors=[b925296 Finishes BAK tasks., check(), main(), ready_platform()]
- "unit_asset_allocation_test": "asset_allocation_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/asset_allocation_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_byo_registration_test_main": "main()" | kind=code-symbol | source=server/matchmaker/tests/unit/byo_registration_test.cpp:L32 | neighbors=[byo_registration_test.cpp, check(), key(), req()]
- "unit_check_fault_sensitivity": "check_fault_sensitivity.py" | kind=code-symbol | source=engine/platform/tests/unit/check_fault_sensitivity.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_check_framegraph_mutations": "check_framegraph_mutations.py" | kind=code-symbol | source=engine/render/tests/unit/check_framegraph_mutations.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Optional fault-sensitivity test; compil…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_crypto_aead_test": "crypto_aead_test.cpp" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, hex(), hex_eq(), main()]
- "unit_debugger_test_arith": "arith()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L13 | neighbors=[debugger_test.cpp, imm(), pay(), cases()]
- "unit_debugger_test_divzero": "divzero()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L17 | neighbors=[debugger_test.cpp, cases(), imm(), pay()]
- "unit_debugger_test_imm": "imm()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L10 | neighbors=[debugger_test.cpp, arith(), cases(), divzero()]
- "unit_debugger_test_pay": "pay()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L9 | neighbors=[debugger_test.cpp, arith(), cases(), divzero()]
- "unit_declaration_dump": "declaration_dump.cpp" | kind=code-symbol | source=mute/tests/unit/declaration_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_declaration_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L38 | neighbors=[declaration_test.cpp, error(), tree(), main()]
- "unit_declaration_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L12 | neighbors=[declaration_test.cpp, depth_guard(), randomized_input(), tree()]
- "unit_declaration_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L90 | neighbors=[declaration_test.cpp, cases(), depth_guard(), randomized_input()]
- "unit_determinism_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L25 | neighbors=[determinism_test.cpp, error(), ok(), main()]
- "unit_deterministic_math_dump": "deterministic_math_dump.cpp" | kind=code-symbol | source=mute/tests/unit/deterministic_math_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_deterministic_math_test": "deterministic_math_test.cpp" | kind=code-symbol | source=mute/tests/unit/deterministic_math_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_directional_light_test": "directional_light_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/directional_light_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_duration_query_state_test": "duration_query_state_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/duration_query_state_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_emit_test_wide_call_module": "wide_call_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L61 | neighbors=[emit_test.cpp, cases(), i32(), v()]
- "unit_evaluator_dump": "evaluator_dump.cpp" | kind=code-symbol | source=mute/tests/unit/evaluator_dump.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_evaluator_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L18 | neighbors=[evaluator_test.cpp, bindings(), deep(), floating()]
- "unit_evaluator_test_deep": "deep()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L195 | neighbors=[evaluator_test.cpp, check(), signed_case(), main()]
- "unit_evaluator_test_error_case": "error_case()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L37 | neighbors=[evaluator_test.cpp, cases(), eval(), floating()]
- "unit_evaluator_test_signed_case": "signed_case()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L25 | neighbors=[evaluator_test.cpp, cases(), deep(), eval()]
- "unit_events_test": "events_test.cpp" | kind=code-symbol | source=mute/tests/unit/events_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, configured(), event(), main()]
- "unit_frame_graph_test": "frame_graph_test.cpp" | kind=code-symbol | source=engine/render/tests/unit/frame_graph_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-058.json

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
