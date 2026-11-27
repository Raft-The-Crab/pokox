# Node Description Batch 57 of 208

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

- "texture_tile_seam_check_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L133 | neighbors=[tile_seam_check.py, assess(), print_report(), write_tile_sheet()]
- "texture_uv_density_group_stats": "group_stats()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L82 | neighbors=[uv_density.py, tri_area_3d(), tri_area_uv(), report()]
- "texture_uv_density_report": "report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L108 | neighbors=[uv_density.py, main(), group_stats(), parse_obj()]
- "tools_readme_hero_frame": "frame()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L91 | neighbors=[readme_hero.py, font(), mask(), main()]
- "tools_sync_shared": "sync_shared.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/sync_shared.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main(), targets()]
- "tools_trigger_check": "trigger_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/trigger_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main(), toks()]
- "towncity_city_paint_block": "block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L101 | neighbors=[city_paint.py, atlas(), paint_glass(), tile()]
- "towncity_city_paint_edge": "edge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L34 | neighbors=[city_paint.py, clip(), 1 inside a joint of half-width w (d = d…, tile()]
- "towncity_city_paint_paint_glass": "paint_glass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L93 | neighbors=[city_paint.py, block(), clip(), ramp()]
- "towncity_city_paint_remap": "remap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L149 | neighbors=[city_paint.py, area(), axes_of(), clip()]
- "towncity_town_landmarks_arch_open": "arch_open()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L58 | neighbors=[town_landmarks.py, clock_tower(), an arched opening framed with voussoirs…, train_station()]
- "towncity_town_landmarks_bank": "bank()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L481 | neighbors=[town_landmarks.py, column(), pediment(), bank: temple front on a stepped podium,…]
- "towncity_town_landmarks_clock_face": "clock_face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L45 | neighbors=[town_landmarks.py, clock_tower(), clock: cream dial, gold bezel, 12 tick …, train_station()]
- "towncity_town_landmarks_column": "column()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L19 | neighbors=[town_landmarks.py, bank(), classical column: square plinth, torus …, town_hall()]
- "towncity_town_landmarks_pediment": "pediment()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L27 | neighbors=[town_landmarks.py, bank(), triangular pediment: raking cornices + …, town_hall()]
- "towncity_town_map_anchor_local": "anchor_local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L99 | neighbors=[town_map.py, anchor(), rot(), sign_anchor()]
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
- "transitions_verify_transition_endpoints": "verify_transition_endpoints.py" | kind=code-symbol | source=assets/characters/transitions/verify_transition_endpoints.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, diff(), pose(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_asset_store_test": "asset_store_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/asset_store_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, counting_loader(), main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_bytecode_vm_test": "bytecode_vm_test.cpp" | kind=code-symbol | source=mute/tests/unit/bytecode_vm_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_clear_backend_selection": "clear_backend_selection.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/clear_backend_selection.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Fake(), main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_config_allocation_test": "config_allocation_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/config_allocation_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, allocate_or_throw(), main(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_console_test": "console_test.cpp" | kind=code-symbol | source=mute/tests/unit/console_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), write(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_crypto_aead_test": "crypto_aead_test.cpp" | kind=code-symbol | source=server/net/tests/unit/crypto_aead_test.cpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, hex(), hex_eq(), main()]
- "unit_debugger_test_arith": "arith()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L13 | neighbors=[debugger_test.cpp, imm(), pay(), cases()]
- "unit_debugger_test_divzero": "divzero()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L17 | neighbors=[debugger_test.cpp, cases(), imm(), pay()]
- "unit_debugger_test_imm": "imm()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L10 | neighbors=[debugger_test.cpp, arith(), cases(), divzero()]
- "unit_debugger_test_pay": "pay()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L9 | neighbors=[debugger_test.cpp, arith(), cases(), divzero()]
- "unit_declaration_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L38 | neighbors=[declaration_test.cpp, error(), tree(), main()]
- "unit_declaration_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L12 | neighbors=[declaration_test.cpp, depth_guard(), randomized_input(), tree()]
- "unit_declaration_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/declaration_test.cpp:L90 | neighbors=[declaration_test.cpp, cases(), depth_guard(), randomized_input()]

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
