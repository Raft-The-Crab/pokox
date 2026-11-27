# Node Description Batch 126 of 207

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

- "scripts_qa_check_uv_stats": "_uv_stats()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L133 | neighbors=[qa_check.py, run()]
- "scripts_render_batch_frames": "_frames()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L56 | neighbors=[render_batch.py, run()]
- "scripts_render_batch_gpu": "_gpu()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L36 | neighbors=[render_batch.py, run()]
- "scripts_retarget_rot": "_rot()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L86 | neighbors=[retarget.py, run()]
- "scripts_review_shots_bounds": "_bounds()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/review_shots.py:L27 | neighbors=[review_shots.py, run()]
- "scripts_review_shots_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/review_shots.py:L35 | neighbors=[review_shots.py, _bounds()]
- "scripts_rig_check_mirror": "_mirror()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rig_check.py:L43 | neighbors=[rig_check.py, run()]
- "scripts_rig_check_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rig_check.py:L52 | neighbors=[rig_check.py, _mirror()]
- "scripts_rigify_build_bounds": "_bounds()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L36 | neighbors=[rigify_build.py, _fit()]
- "scripts_rigify_build_remove_face": "_remove_face()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L58 | neighbors=[rigify_build.py, run()]
- "scripts_roblox_export_at": "at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L755 | neighbors=[roblox_export.py, r_pos()]
- "scripts_roblox_export_base_of": "base_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L119 | neighbors=[roblox_export.py, clean_name()]
- "scripts_roblox_export_collision_of": "collision_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L109 | neighbors=[roblox_export.py, _owner()]
- "scripts_roblox_export_export": "export()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L209 | neighbors=[roblox_export.py, material_split()]
- "scripts_roblox_export_face_rgb": "_face_rgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L159 | neighbors=[roblox_export.py, material_split()]
- "scripts_roblox_export_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L367 | neighbors=[roblox_export.py, r_pos()]
- "scripts_roblox_export_mat_color": "mat_color()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L134 | neighbors=[roblox_export.py, glow colour (sRGB 0-255) from an emissi…]
- "scripts_roblox_export_owner": "_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L696 | neighbors=[roblox_export.py, collision_of()]
- "scripts_roblox_export_split_faces": "split_faces()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L269 | neighbors=[roblox_export.py, faces -> chunks under SPLIT_TRIS / SPLI…]
- "scripts_roblox_materials_column_of": "column_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L35 | neighbors=[roblox_materials.py, preview()]
- "scripts_roblox_materials_variant": "_variant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L39 | neighbors=[roblox_materials.py, preview()]
- "scripts_run_in_blender_find_blender": "find_blender()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/run_in_blender.py:L29 | neighbors=[run_in_blender.py, main()]
- "scripts_run_in_blender_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/run_in_blender.py:L48 | neighbors=[run_in_blender.py, find_blender()]
- "scripts_scatter_instances": "_instances()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L140 | neighbors=[scatter.py, run()]
- "scripts_scatter_layer_coll": "_layer_coll()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L231 | neighbors=[scatter.py, run()]
- "scripts_scene_audit_apply_rot_scale": "_apply_rot_scale()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-scene-setup/scripts/scene_audit.py:L24 | neighbors=[scene_audit.py, run()]
- "scripts_scene_audit_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-scene-setup/scripts/scene_audit.py:L35 | neighbors=[scene_audit.py, _apply_rot_scale()]
- "scripts_scene_mood_clear": "_clear()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L105 | neighbors=[scene_mood.py, run()]
- "scripts_scene_mood_coll": "_coll()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L118 | neighbors=[scene_mood.py, run()]
- "scripts_scene_mood_fog_box": "_fog_box()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L238 | neighbors=[scene_mood.py, run()]
- "scripts_scene_mood_grade": "_grade()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L292 | neighbors=[scene_mood.py, run()]
- "scripts_scene_mood_light": "_light()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L127 | neighbors=[scene_mood.py, run()]
- "scripts_scene_mood_mix_rgb": "_mix_rgb()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L161 | neighbors=[scene_mood.py, _world()]
- "scripts_scene_mood_norm": "_norm()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L143 | neighbors=[scene_mood.py, run()]
- "scripts_scene_mood_scene_bounds": "_scene_bounds()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L94 | neighbors=[scene_mood.py, run()]
- "scripts_shapekeys_co": "_co()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L45 | neighbors=[shapekeys.py, run()]
- "scripts_shapekeys_get": "_get()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L51 | neighbors=[shapekeys.py, run()]
- "scripts_shapekeys_keys": "_keys()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L39 | neighbors=[shapekeys.py, run()]
- "scripts_sim_setup_asset_group": "_asset_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L50 | neighbors=[sim_setup.py, run()]
- "scripts_sim_setup_ctx": "_ctx()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L36 | neighbors=[sim_setup.py, run()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-125.json

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
