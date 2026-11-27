# Node Description Batch 140 of 209

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

- "tests_test_workflow_test_build_and_render_reject_changed_sources_assets_outputs_and_templates": "test_build_and_render_reject_changed_sources_assets_outputs_and_templates()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L115 | neighbors=[test_workflow.py, captured()]
- "tests_test_workflow_test_evidence_is_stored_in_the_workspace_work_folder": "test_evidence_is_stored_in_the_workspace_work_folder()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L102 | neighbors=[test_workflow.py, captured()]
- "tests_test_workflow_test_reference_compare_requires_exact_fresh_render_frames": "test_reference_compare_requires_exact_fresh_render_frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L230 | neighbors=[test_workflow.py, captured()]
- "tests_test_workflow_test_review_handoff_refuses_a_missing_or_stale_capture": "test_review_handoff_refuses_a_missing_or_stale_capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L310 | neighbors=[test_workflow.py, captured()]
- "texture_tex_to_maps_load_gray": "load_gray()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L30 | neighbors=[tex_to_maps.py, process()]
- "texture_tex_to_maps_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L145 | neighbors=[tex_to_maps.py, process()]
- "texture_tex_to_maps_save_gray": "save_gray()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L98 | neighbors=[tex_to_maps.py, process()]
- "texture_tex_to_maps_save_rgb": "save_rgb()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L102 | neighbors=[tex_to_maps.py, process()]
- "texture_tile_seam_check_load_gray": "load_gray()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L35 | neighbors=[tile_seam_check.py, assess()]
- "texture_tile_seam_check_print_report": "print_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L115 | neighbors=[tile_seam_check.py, main()]
- "texture_uv_density_print_report": "print_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L166 | neighbors=[uv_density.py, main()]
- "texture_uv_density_tri_area_3d": "tri_area_3d()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L69 | neighbors=[uv_density.py, group_stats()]
- "texture_uv_density_tri_area_uv": "tri_area_uv()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L78 | neighbors=[uv_density.py, group_stats()]
- "tools_g2_replay_probe_bounds_of": "bounds_of()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L58 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_combine_friction": "combine_friction()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L112 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_combine_restitution": "combine_restitution()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L113 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_fx": "fx()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L35 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_shape_of": "shape_of()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L65 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_sim_body": "sim_body()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L77 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_g2_replay_probe_state_hash": "state_hash()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L88 | neighbors=[g2_replay_probe.cpp, main()]
- "tools_mute_build_main": "main()" | kind=code-symbol | source=mute/tools/mute_build.cpp:L24 | neighbors=[mute_build.cpp, read_file()]
- "tools_mute_build_read_file": "read_file()" | kind=code-symbol | source=mute/tools/mute_build.cpp:L14 | neighbors=[mute_build.cpp, main()]
- "tools_readme_hero_font": "font()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L32 | neighbors=[readme_hero.py, frame()]
- "tools_readme_hero_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L143 | neighbors=[readme_hero.py, frame()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-139.json

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
