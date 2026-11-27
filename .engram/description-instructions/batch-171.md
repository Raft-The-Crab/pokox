# Node Description Batch 172 of 209

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "migrations_0002_ledger_balances_balances": "balances" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L20 | neighbors=[0002_ledger_balances.sql]
- "migrations_0002_ledger_balances_ledger_entries": "ledger_entries" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L4 | neighbors=[0002_ledger_balances.sql]
- "migrations_0003_cases_audit_audit_log": "audit_log" | kind=code-symbol | source=backend/storage/postgres/migrations/0003_cases_audit.sql:L12 | neighbors=[0003_cases_audit.sql]
- "migrations_0003_cases_audit_cases": "cases" | kind=code-symbol | source=backend/storage/postgres/migrations/0003_cases_audit.sql:L2 | neighbors=[0003_cases_audit.sql]
- "moonclean_moon_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L486 | neighbors=[moon_map.py]
- "moonclean_moon_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L516 | neighbors=[moon_map.py]
- "moonclean_moon_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L524 | neighbors=[moon_map.py]
- "moonclean_moon_map_tang_yaw": "tang_yaw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L181 | neighbors=[moon_map.py]
- "moonclean_moon_props_rationale_695": "sweepable heap: stacked mounds + a sparkle of dust-gem bits (glow)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L695 | neighbors=[dust_pile()]
- "moonclean_moon_props_rationale_86": "two-colour checker by face angle around Y (rocket roll pattern / foil wraps)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L86 | neighbors=[ShAng]
- "moonclean_moon_props_shang_call": ".__call__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L89 | neighbors=[ShAng]
- "moonclean_moon_props_shang_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L87 | neighbors=[ShAng]
- "moonclean_moon_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L43 | neighbors=[moon_props.py]
- "musl_math_cos_cosine": "cosine()" | kind=code-symbol | source=mute/third_party/musl_math/cos.cpp:L47 | neighbors=[cos.cpp]
- "musl_math_cos_kernel_cos": "kernel_cos()" | kind=code-symbol | source=mute/third_party/musl_math/__cos.cpp:L63 | neighbors=[cos.cpp]
- "musl_math_floor_floor_value": "floor_value()" | kind=code-symbol | source=mute/third_party/musl_math/floor.cpp:L12 | neighbors=[floor.cpp]
- "musl_math_rem_pio2_large_rem_pio2_large": "rem_pio2_large()" | kind=code-symbol | source=mute/third_party/musl_math/__rem_pio2_large.cpp:L275 | neighbors=[__rem_pio2_large.cpp]
- "musl_math_rem_pio2_rem_pio2": "rem_pio2()" | kind=code-symbol | source=mute/third_party/musl_math/__rem_pio2.cpp:L51 | neighbors=[__rem_pio2.cpp]
- "musl_math_scalbn_scalbn_value": "scalbn_value()" | kind=code-symbol | source=mute/third_party/musl_math/scalbn.cpp:L5 | neighbors=[scalbn.cpp]
- "musl_math_sin_kernel_sin": "kernel_sin()" | kind=code-symbol | source=mute/third_party/musl_math/__sin.cpp:L54 | neighbors=[sin.cpp]
- "musl_math_sin_sine": "sine()" | kind=code-symbol | source=mute/third_party/musl_math/sin.cpp:L47 | neighbors=[sin.cpp]
- "mute_action_map_actionframe": "ActionFrame" | kind=code-symbol | source=mute/include/poko/mute/action_map.hpp:L125 | neighbors=[action_map.hpp]
- "mute_action_map_actionmap": "ActionMap" | kind=code-symbol | source=mute/include/poko/mute/action_map.hpp:L77 | neighbors=[action_map.hpp]
- "mute_action_map_actionsampler_actionsampler": ".ActionSampler()" | kind=code-symbol | source=mute/include/poko/mute/action_map.hpp:L146 | neighbors=[ActionSampler]
- "mute_build_tool": "build_tool.hpp" | kind=code-symbol | source=mute/include/poko/mute/build_tool.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…]
- "mute_console_consolelog_consolelog": ".ConsoleLog()" | kind=code-symbol | source=mute/include/poko/mute/console.hpp:L35 | neighbors=[ConsoleLog]
- "mute_debugger_vmcore": "VmCore" | kind=code-symbol | source=mute/include/poko/mute/debugger.hpp:L34 | neighbors=[debugger.hpp]
- "mute_debugger_vmdebugger_vmdebugger": ".VmDebugger()" | kind=code-symbol | source=mute/include/poko/mute/debugger.hpp:L46 | neighbors=[VmDebugger]
- "mute_declaration_declarationast_declarationast": ".DeclarationAst()" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L46 | neighbors=[DeclarationAst]
- "mute_declaration_declarationparser": "DeclarationParser" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L18 | neighbors=[declaration.hpp]
- "mute_device_router_devicerouter": "DeviceRouter" | kind=code-symbol | source=mute/include/poko/mute/device_router.hpp:L33 | neighbors=[device_router.hpp]
- "mute_device_router_gamepad_device_code": "gamepad_device_code()" | kind=code-symbol | source=mute/include/poko/mute/device_router.hpp:L66 | neighbors=[device_router.hpp]
- "mute_device_router_touch_device_code": "touch_device_code()" | kind=code-symbol | source=mute/include/poko/mute/device_router.hpp:L69 | neighbors=[device_router.hpp]
- "mute_events_eventbus": "EventBus" | kind=code-symbol | source=mute/include/poko/mute/events.hpp:L35 | neighbors=[events.hpp]
- "mute_fold": "fold.hpp" | kind=code-symbol | source=mute/include/poko/mute/fold.hpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…]
- "mute_hostcall_capability_from_name": "capability_from_name()" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L48 | neighbors=[hostcall.hpp]
- "mute_hostcall_capability_name": "capability_name()" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L52 | neighbors=[hostcall.hpp]
- "mute_hostcall_effective_capabilities": "effective_capabilities()" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L96 | neighbors=[hostcall.hpp]
- "mute_hostcall_hostcalltable": "HostcallTable" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L78 | neighbors=[hostcall.hpp]
- "mute_input_snapshot_inputreplay_inputreplay": ".InputReplay()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L162 | neighbors=[InputReplay]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-171.json

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
