# Node Description Batch 52 of 209

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

- "input_input_snapshot_touch_display_connected": "touch_display_connected()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L120 | neighbors=[input_snapshot.cpp, apply(), touch_down(), touch_position()]
- "integration_config_file_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L291 | neighbors=[config_file_test.cpp, test_config(), test_decoder(), test_resolve()]
- "integration_config_file_test_put_bool": "put_bool()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L38 | neighbors=[config_file_test.cpp, test_config(), test_decoder(), test_resolve()]
- "integration_config_logging_guard_real_test": "config_logging_guard_real_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/config_logging_guard_real_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_cube_golden_canonical_png": "canonical_png()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L30 | neighbors=[cube_golden.py, png_chunk(), RGB8 PNG with filter 0 and explicit unc…, run()]
- "integration_public_header_compat": "public_header_compat.cpp" | kind=code-symbol | source=engine/rhi/tests/integration/public_header_compat.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_sdl_platform_test": "sdl_platform_test.cpp" | kind=code-symbol | source=engine/platform/tests/integration/sdl_platform_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_cube_fixed_view_x11": "test_cube_fixed_view_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_fixed_view_x11.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_directional_light_x11": "test_directional_light_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_directional_light_x11.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_imgui_inputs": "test_imgui_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_imgui_inputs.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Check the real ImGui demo rejects bad S…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_triangle_inputs": "test_triangle_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_inputs.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Check the real demo rejects bad SPIR-V …, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "lexer_unicode_xid": "unicode_xid.hpp" | kind=code-symbol | source=mute/src/lexer/unicode_xid.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, contains(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "math_deterministic_math_calculate": "calculate()" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L18 | neighbors=[deterministic_math.cpp, supported(), deterministic_cos(), deterministic_sin()]
- "medievalbattle_battle_map_channels": "channels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L38 | neighbors=[battle_map.py, fordw(), H(), [(centre x, half width, bed y)] of the …]
- "medievalbattle_battle_map_cull_hidden": "cull_hidden()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L108 | neighbors=[battle_map.py, free(), kit(), drop faces buried inside the prop's own…]
- "medievalbattle_battle_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L198 | neighbors=[battle_map.py, build(), grid_mesh(), sub()]
- "medievalbattle_battle_map_keep_w": "keep_w()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L74 | neighbors=[battle_map.py, base(), ground_shade(), H()]
- "medievalbattle_battle_map_trench_drop": "trench_drop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L54 | neighbors=[battle_map.py, ground_shade(), H(), seg_d()]
- "medievalbattle_battle_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L261 | neighbors=[battle_map.py, build(), 4-stud water grid kept only where water…, sub()]
- "medievalbattle_battle_map_yw": "Yw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L35 | neighbors=[battle_map.py, centre(), field(), keep()]
- "medievalbattle_battle_props_add_into": "add_into()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L230 | neighbors=[battle_props.py, bridge_tower(), donjon(), slit_cutter()]
- "medievalbattle_battle_props_ammo_pile": "ammo_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1025 | neighbors=[battle_props.py, shot_stone(), T(), trebuchet shot: round stones stacked on…]
- "medievalbattle_battle_props_ashlar_ring": "ashlar_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L121 | neighbors=[battle_props.py, donjon_top(), ashlar on a cylinder of radius R (flat …, tower_body()]
- "medievalbattle_battle_props_broadleaf": "broadleaf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1498 | neighbors=[battle_props.py, log(), T(), field oak: flared, slightly twisted tru…]
- "medievalbattle_battle_props_drystone_wall": "drystone_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1398 | neighbors=[battle_props.py, rough_stone(), T(), low field wall of tightly stacked rough…]
- "medievalbattle_battle_props_flame": "flame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1204 | neighbors=[battle_props.py, brazier(), campfire(), T()]
- "medievalbattle_battle_props_in_arch": "in_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L361 | neighbors=[battle_props.py, gatehouse(), sundered_bridge(), tower_face()]
- "medievalbattle_battle_props_rot_mb": "rot_mb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L964 | neighbors=[battle_props.py, broken_cart(), ladder(), pew()]
- "medievalbattle_battle_props_rubble": "rubble()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1423 | neighbors=[battle_props.py, a heap of fallen ashlar blocks and brok…, stone(), T()]
- "medievalbattle_battle_props_scorch": "scorch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1563 | neighbors=[battle_props.py, shallow scorched impact scar (modelled,…, lathe(), T()]
- "medievalbattle_battle_props_shot_stone": "shot_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1019 | neighbors=[battle_props.py, ammo_pile(), dressed round trebuchet shot: smooth la…, lathe()]
- "medievalbattle_battle_props_truss": "truss()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L738 | neighbors=[battle_props.py, charred roof truss across the nave: tie…, ruined_chapel(), bar()]
- "medievalbattle_battle_props_wall_stair": "wall_stair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L533 | neighbors=[battle_props.py, stone stair climbing along +X from the …, course_wall(), T()]
- "mesh_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/RefCntAutoPtr.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, RefCntAutoPtr, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "migrations_0001_accounts_games": "0001_accounts_games.sql" | kind=code-symbol | source=backend/storage/postgres/migrations/0001_accounts_games.sql:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, assets, games, users]
- "moonclean_moon_map_crater_ok": "_crater_ok()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L88 | neighbors=[moon_map.py, adiff(), zone_of(), the crater prop's skirt (1.8 R) must st…]
- "moonclean_moon_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L180 | neighbors=[moon_map.py, crater_ramp(), hub(), zone()]
- "moonclean_moon_map_lip_rails": "lip_rails()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L393 | neighbors=[moon_map.py, adiff(), polar(), rail_ring()]
- "moonclean_moon_map_pock_at": "pock_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L210 | neighbors=[moon_map.py, crater_at(), H(), (q, depth) of the nearest pock / crater…]
- "moonclean_moon_map_ramp_half_len": "ramp_half_len()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L35 | neighbors=[moon_map.py, crater_ramp(), on_ramp(), ramp_w()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-051.json

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
