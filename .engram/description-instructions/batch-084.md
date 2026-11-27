# Node Description Batch 85 of 208

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

- "tools_math_determinism_read": "_read()" | kind=code-symbol | source=mute/tools/math_determinism.py:L29 | neighbors=[math_determinism.py, load_corpus(), load_trace()]
- "tools_mute_build": "mute_build.cpp" | kind=code-symbol | source=mute/tools/mute_build.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, main(), read_file()]
- "tools_pkb_schema_draft": "pkb_schema_draft.cpp" | kind=code-symbol | source=mute/tools/pkb_schema_draft.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "tools_program_bytecode_probe": "program_bytecode_probe.cpp" | kind=code-symbol | source=mute/tools/program_bytecode_probe.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "tools_readme_hero_figure": "figure()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L41 | neighbors=[readme_hero.py, mask(), A small standing silhouette. Parameters…]
- "tools_readme_hero_mask": "mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L85 | neighbors=[readme_hero.py, frame(), figure()]
- "tools_run_tests": "run_tests.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/run_tests.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main()]
- "tools_state_determinism_probe": "state_determinism_probe.cpp" | kind=code-symbol | source=mute/tools/state_determinism_probe.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "tools_validate_skills_check_coverage": "check_coverage()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L135 | neighbors=[validate_skills.py, Warnings when the COVERAGE.md summary t…, validate()]
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
- "transitions_build_transitions": "build_transitions.py" | kind=code-symbol | source=assets/characters/transitions/build_transitions.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, capture(), c7a411f Fix MUT-01-20 audit defects in …]
- "transitions_v2_build_transitions": "build_transitions.py" | kind=code-symbol | source=assets/characters/transitions-v2/build_transitions.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, capture(), c7a411f Fix MUT-01-20 audit defects in …]
- "triangle_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/triangle/RefCntAutoPtr.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, RefCntAutoPtr, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_action_map_test_axis": "axis()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L42 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_kb": "kb()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L38 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_mouse": "mouse()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L39 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_pad": "pad()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L41 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_action_map_test_tap": "tap()" | kind=code-symbol | source=mute/tests/unit/action_map_test.cpp:L45 | neighbors=[action_map_test.cpp, game_map(), main()]
- "unit_asset_allocation_test": "asset_allocation_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/asset_allocation_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-084.json

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
