# Node Description Batch 130 of 209

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
- "scripts_sim_setup_num": "_num()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L72 | neighbors=[sim_setup.py, run()]
- "scripts_sim_setup_set_inputs": "_set_inputs()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L62 | neighbors=[sim_setup.py, run()]
- "scripts_sim_setup_volume": "_volume()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L41 | neighbors=[sim_setup.py, run()]
- "scripts_smart_material_g_set": ".set()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L45 | neighbors=[_G, .link()]
- "scripts_smart_material_image_node": "_image_node()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L210 | neighbors=[smart_material.py, _apply_mat()]
- "scripts_smart_material_remove_mat": "_remove_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L254 | neighbors=[smart_material.py, run()]
- "scripts_smart_material_src": "_src()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L202 | neighbors=[smart_material.py, _apply_mat()]
- "scripts_stress_poses_side": "_side()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L33 | neighbors=[stress_poses.py, _find()]
- "scripts_studlib_apply": "apply()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L207 | neighbors=[studlib.py, make()]
- "scripts_studlib_frame": "frame()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L143 | neighbors=[studlib.py, limb()]
- "scripts_studlib_make": "make()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L217 | neighbors=[studlib.py, apply()]
- "scripts_studlib_sides": "sides()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L139 | neighbors=[studlib.py, for sx, s in K.sides(): ... -> (1,'L'),…]
- "scripts_surface_weather_g_set": ".set()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L38 | neighbors=[_G, .link()]
- "scripts_surface_weather_remove_mat": "_remove_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L225 | neighbors=[surface_weather.py, run()]
- "scripts_surface_weather_snow_material": "_snow_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L289 | neighbors=[surface_weather.py, run()]
- "scripts_surface_weather_src": "_src()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L186 | neighbors=[surface_weather.py, _apply_mat()]
- "scripts_template_engine_eachnode_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L117 | neighbors=[EachNode, strip_nodes()]
- "scripts_template_engine_ifnode_render": ".render()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L80 | neighbors=[IfNode, get_nested_val()]
- "scripts_template_engine_varnode_render": ".render()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L63 | neighbors=[VarNode, get_nested_val()]
- "scripts_terrain_heightmap": "_heightmap()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L46 | neighbors=[terrain.py, run()]
- "scripts_terrain_material": "_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L83 | neighbors=[terrain.py, run()]
- "scripts_terrain_noise_field": "_noise_field()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L29 | neighbors=[terrain.py, run()]
- "scripts_terrain_save_png16": "_save_png16()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L138 | neighbors=[terrain.py, run()]
- "scripts_terrain_slope_deg": "_slope_deg()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L78 | neighbors=[terrain.py, run()]
- "scripts_texel_density_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L73 | neighbors=[texel_density.py, _measure()]
- "scripts_texel_density_uv_area": "_uv_area()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L47 | neighbors=[texel_density.py, _measure()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-129.json

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
