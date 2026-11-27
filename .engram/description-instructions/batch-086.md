# Node Description Batch 87 of 209

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

- "tools_validate_skills_collect_tech_ids": "collect_tech_ids()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L107 | neighbors=[validate_skills.py, Collect T-nn ids from the knowledge bas…, validate()]
- "tools_validate_skills_find_skills": "find_skills()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L84 | neighbors=[validate_skills.py, Locate SKILL.md files, accepting either…, validate()]
- "tools_validate_skills_known_py": "known_py()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L46 | neighbors=[validate_skills.py, check_skill(), Script names a SKILL.md or reference ma…]
- "tools_validate_skills_parse_frontmatter": "parse_frontmatter()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L30 | neighbors=[validate_skills.py, Minimal YAML front-matter reader: enoug…, validate()]
- "towncity_city_paint_pnoise": "pnoise()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L26 | neighbors=[city_paint.py, periodic FFT noise h x w in [-1, 1], fe…, tile()]
- "towncity_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, lua_attrs()]
- "towncity_town_landmarks_cslab": "cslab()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L232 | neighbors=[town_landmarks.py, clock_tower(), corner block at corner (sx, sz) of a sq…]
- "towncity_town_landmarks_merge": "_merge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L241 | neighbors=[town_landmarks.py, clock_tower(), copy a temp Prop's solid mesh into P tu…]
- "towncity_town_landmarks_skyline": "skyline()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L554 | neighbors=[town_landmarks.py, cheap frame tower for the skyline ring:…, frustum()]
- "towncity_town_map_blocks": "blocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L48 | neighbors=[town_map.py, ground(), block rectangles (x0, x1, z0, z1) at cu…]
- "towncity_town_map_buildings": "buildings()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L255 | neighbors=[town_map.py, build(), row()]
- "towncity_town_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L89 | neighbors=[town_map.py, dressing(), look()]
- "towncity_town_map_near_intersection": "near_intersection()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L372 | neighbors=[town_map.py, dressing(), traffic()]
- "towncity_town_map_road_paths": "road_paths()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L502 | neighbors=[town_map.py, build(), anchor()]
- "towncity_town_map_sidewalk_lines": "sidewalk_lines()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L362 | neighbors=[town_map.py, dressing(), polylines (x, z, along-dir, out-dir) on…]
- "towncity_town_map_sign_anchor": "sign_anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L249 | neighbors=[town_map.py, landmarks(), anchor_local()]
- "towncity_town_map_skyline_ring": "skyline_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L348 | neighbors=[town_map.py, build(), place()]
- "towncity_town_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L26 | neighbors=[town_map.py, place(), static()]
- "towncity_town_props_quad": "quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L97 | neighbors=[town_props.py, front_quad(), window_unit()]
- "towncity_town_props_skylight": "skylight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L165 | neighbors=[town_props.py, building(), add()]
- "towncity_town_vehicles_loft_closed": "loft_closed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L12 | neighbors=[town_vehicles.py, body_shell(), _car_shell()]
- "towncity_town_vehicles_wheels": "wheels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L46 | neighbors=[town_vehicles.py, bus(), car()]
- "transitions_v2_check_subframes": "check_subframes.py" | kind=code-symbol | source=assets/characters/transitions-v2/check_subframes.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_action_map_test_axis": "axis()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L42 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_kb": "kb()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L38 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_mouse": "mouse()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L39 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_pad": "pad()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L41 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_tap": "tap()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L45 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_allocator_test_main": "main()" | kind=code-symbol | source=server/matchmaker/tests/unit/allocator_test.cpp:L26 | neighbors=[allocator_test.cpp, check(), ready_platform()]
- "unit_bench_test_best_ns": "best_ns()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L43 | neighbors=[bench_test.cpp, bench(), run()]
- "unit_bench_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L75 | neighbors=[bench_test.cpp, bench(), main()]
- "unit_bench_test_compile": "compile()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L18 | neighbors=[bench_test.cpp, bench(), i32()]
- "unit_bench_test_run": "run()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L38 | neighbors=[bench_test.cpp, bench(), best_ns()]
- "unit_build_tool_test": "build_tool_test.cpp" | kind=code-symbol | source=mute/tests/unit/build_tool_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, main(), read()]
- "unit_camera_test_main": "main()" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L22 | neighbors=[camera_test.cpp, near(), transform()]
- "unit_character_controller_test_params": "params()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L103 | neighbors=[character_controller_test.cpp, main(), fx()]
- "unit_character_controller_test_tod": "tod()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L28 | neighbors=[character_controller_test.cpp, main(), todv()]
- "unit_character_controller_test_todv": "todv()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L29 | neighbors=[character_controller_test.cpp, main(), tod()]
- "unit_character_controller_test_v3": "v3()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L20 | neighbors=[character_controller_test.cpp, main(), wedge()]
- "unit_character_controller_test_wedge": "wedge()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L42 | neighbors=[character_controller_test.cpp, main(), v3()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-086.json

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
