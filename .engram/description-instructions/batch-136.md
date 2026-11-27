# Node Description Batch 137 of 207

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

- "texture_uv_density_tri_area_uv": "tri_area_uv()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L78 | neighbors=[uv_density.py, group_stats()]
- "tools_compare_math_cross": "compare_math_cross.py" | kind=code-symbol | source=mute/tools/compare_math_cross.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, run()]
- "tools_g1_replay_probe": "g1_replay_probe.cpp" | kind=code-symbol | source=mute/tools/g1_replay_probe.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "tools_g2_replay_probe_bounds_of": "bounds_of()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L58 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_combine_friction": "combine_friction()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L112 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_combine_restitution": "combine_restitution()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L113 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_fx": "fx()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L35 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_shape_of": "shape_of()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L65 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_sim_body": "sim_body()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L77 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_state_hash": "state_hash()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L88 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_generate_math_reference": "generate_math_reference.py" | kind=code-symbol | source=mute/tools/generate_math_reference.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, bits()]
- "tools_mute_build_main": "main()" | kind=code-symbol | source=mute/tools/mute_build.cpp:L24 | neighbors=[mute_build.cpp, read_file()]
- "tools_mute_build_read_file": "read_file()" | kind=code-symbol | source=mute/tools/mute_build.cpp:L14 | neighbors=[mute_build.cpp, main()]
- "tools_pkb_schema_draft": "pkb_schema_draft.cpp" | kind=code-symbol | source=mute/tools/pkb_schema_draft.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "tools_program_bytecode_probe": "program_bytecode_probe.cpp" | kind=code-symbol | source=mute/tools/program_bytecode_probe.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "tools_readme_hero_font": "font()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L32 | neighbors=[readme_hero.py, frame()]
- "tools_readme_hero_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L143 | neighbors=[readme_hero.py, frame()]
- "tools_state_determinism_probe": "state_determinism_probe.cpp" | kind=code-symbol | source=mute/tools/state_determinism_probe.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "tools_sync_shared_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/sync_shared.py:L20 | neighbors=[sync_shared.py, targets()]
- "tools_sync_shared_targets": "targets()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/sync_shared.py:L14 | neighbors=[sync_shared.py, main()]
- "tools_trigger_check_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/trigger_check.py:L60 | neighbors=[trigger_check.py, toks()]
- "tools_trigger_check_toks": "toks()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/trigger_check.py:L56 | neighbors=[trigger_check.py, main()]
- "tools_validate_skills_frontmatter": "frontmatter()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L28 | neighbors=[validate_skills.py, check_skill()]
- "tools_validate_skills_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L110 | neighbors=[validate_skills.py, check_skill()]
- "tools_validate_skills_tokens": "tokens()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L24 | neighbors=[validate_skills.py, check_skill()]
- "towncity_city_paint_area": "area()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L144 | neighbors=[city_paint.py, remap()]
- "towncity_city_paint_atlas": "atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L112 | neighbors=[city_paint.py, block()]
- "towncity_city_paint_axes_of": "axes_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L124 | neighbors=[city_paint.py, remap()]
- "towncity_city_paint_hash2": "hash2()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L42 | neighbors=[city_paint.py, tile()]
- "towncity_city_paint_hex": "_hex()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L24 | neighbors=[city_paint.py, ramp()]
- "towncity_town_kit": "town_kit.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_kit.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "towncity_town_landmarks_bus_stop": "bus_stop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L455 | neighbors=[town_landmarks.py, bus shelter: steel frame, glass back + …]
- "towncity_town_landmarks_car_showroom": "car_showroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L518 | neighbors=[town_landmarks.py, car dealer: open-front display hall (no…]
- "towncity_town_landmarks_fountain": "fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L381 | neighbors=[town_landmarks.py, town square fountain: 8-sided basin (pa…]
- "towncity_town_landmarks_job_board": "job_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L422 | neighbors=[town_landmarks.py, job board kiosk: timber frame on stone …]
- "towncity_town_landmarks_platform_canopy": "platform_canopy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L350 | neighbors=[town_landmarks.py, platform segment along Z (track side = …]
- "towncity_town_landmarks_rationale_171": "tower standing on the town hall roof: brick shaft with cream quoins + bands, clo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L171 | neighbors=[MB, clock_tower()]
- "towncity_town_landmarks_rationale_20": "classical column: square plinth, torus base, fluted-look shaft (12 sides, slight" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L20 | neighbors=[MB, column()]
- "towncity_town_landmarks_rationale_233": "corner block at corner (sx, sz) of a square of half-size h: a x b deep into the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L233 | neighbors=[MB, cslab()]
- "towncity_town_landmarks_rationale_253": "brick head house: central great arched window with fan glazing over a walk-throu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L253 | neighbors=[MB, train_station()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-136.json

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
