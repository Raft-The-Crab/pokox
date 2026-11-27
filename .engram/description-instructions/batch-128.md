# Node Description Batch 129 of 209

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

- "scripts_pro_lib_hull": "hull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L132 | neighbors=[pro_lib.py, rock()]
- "scripts_pro_lib_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L27 | neighbors=[pro_lib.py, .__call__()]
- "scripts_pro_lib_nz": "nz()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L30 | neighbors=[pro_lib.py, .__call__()]
- "scripts_pro_lib_out_add": ".add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L373 | neighbors=[Out, .g()]
- "scripts_pro_lib_palette_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L37 | neighbors=[Palette, ramps: {name: (dark, mid, light)} in co…]
- "scripts_pro_lib_r2b": "r2b()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L20 | neighbors=[pro_lib.py, render()]
- "scripts_pro_lib_ribbon": "ribbon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L246 | neighbors=[pro_lib.py, a flat strip on the ground following pt…]
- "scripts_pro_lib_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L28 | neighbors=[pro_lib.py, clamp()]
- "scripts_pro_lib_spike": "spike()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L190 | neighbors=[pro_lib.py, a crystal / spire: prism up to h * shou…]
- "scripts_pro_lib_strip_surface": "strip_surface()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L283 | neighbors=[pro_lib.py, a surface between a front curve z = zf(…]
- "scripts_pro_lib_xf": "xf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L111 | neighbors=[pro_lib.py, rot = (pitch about X, yaw about Y, roll…]
- "scripts_qa_check_islands": "_islands()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L109 | neighbors=[qa_check.py, run()]
- "scripts_qa_check_point_in_tri": "_point_in_tri()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L126 | neighbors=[qa_check.py, run()]
- "scripts_qa_check_result": "_result()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L417 | neighbors=[qa_check.py, run()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-128.json

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
