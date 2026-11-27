# Node Description Batch 82 of 209

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

- "scripts_sculpt_ops_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-sculpting/scripts/sculpt_ops.py:L36 | neighbors=[sculpt_ops.py, _apply(), _ctx()]
- "scripts_smart_material_curvature_attribute": "curvature_attribute()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L158 | neighbors=[smart_material.py, TX_Curvature point attribute: 0.5 flat,…, run()]
- "scripts_smart_material_g_link": ".link()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L42 | neighbors=[build_group(), _G, .set()]
- "scripts_smart_material_g_math": ".math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L57 | neighbors=[build_group(), _G, .n()]
- "scripts_smart_material_g_mix": ".mix()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L69 | neighbors=[build_group(), _G, .n()]
- "scripts_smart_material_g_mrange": ".mrange()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L63 | neighbors=[build_group(), _G, .n()]
- "scripts_smart_material_g_noise": ".noise()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L77 | neighbors=[build_group(), _G, .n()]
- "scripts_smart_material_lin": "_lin()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L33 | neighbors=[smart_material.py, sRGB 0-1 -> linear (Blender color socke…, run()]
- "scripts_stress_poses_find": "_find()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L42 | neighbors=[stress_poses.py, _side(), run()]
- "scripts_stress_poses_rotate": "_rotate()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L56 | neighbors=[stress_poses.py, Rotate a pose bone about a WORLD axis t…, run()]
- "scripts_stress_poses_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L77 | neighbors=[stress_poses.py, _find(), _rotate()]
- "scripts_studlib_cyl": "cyl()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L109 | neighbors=[studlib.py, _emit(), Cylinder from point a to point b, radiu…]
- "scripts_studlib_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L25 | neighbors=[studlib.py, box(), _emit()]
- "scripts_studlib_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L122 | neighbors=[studlib.py, wedge(), Wedge by ranges; the slope rises toward…]
- "scripts_studlib_spike": "spike()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L152 | neighbors=[studlib.py, Tapering spike/horn: 3 boxes 1 / .66 / …, box()]
- "scripts_studlib_stack": "stack()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L158 | neighbors=[studlib.py, Stepped dome/egg: rows = [(half_width_f…, span()]
- "scripts_studlib_sym": "sym()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L134 | neighbors=[studlib.py, Mirrored pair. Use '%' in the bone name…, span()]
- "scripts_surface_weather_apply_mat": "_apply_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L194 | neighbors=[surface_weather.py, _src(), run()]
- "scripts_surface_weather_g_mix": ".mix()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L62 | neighbors=[build_group(), _G, .n()]
- "scripts_surface_weather_g_mrange": ".mrange()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L56 | neighbors=[build_group(), _G, .n()]
- "scripts_template_engine_eachnode_render": ".render()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L128 | neighbors=[EachNode, ._render_children(), get_nested_val()]
- "scripts_template_engine_eachnode_render_children": "._render_children()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L121 | neighbors=[EachNode, .render(), Helper to render nested children under …]
- "scripts_template_engine_render_template": "render_template()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L232 | neighbors=[template_engine.py, Renders a markdown template with high p…, compile_template()]
- "scripts_template_engine_strip_nodes": "strip_nodes()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L94 | neighbors=[template_engine.py, .__init__(), Helper to strip leading/trailing whites…]
- "scripts_terrain_erode": "_erode()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L58 | neighbors=[terrain.py, Thermal erosion: material above the tal…, run()]
- "scripts_texel_density_islands": "_islands()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L21 | neighbors=[texel_density.py, _measure(), UV islands as lists of faces (connected…]
- "scripts_toon_setup_apply_mat": "_apply_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L182 | neighbors=[toon_setup.py, _drive_light(), run()]
- "scripts_toon_setup_drive_light": "_drive_light()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L168 | neighbors=[toon_setup.py, _apply_mat(), Light Direction = the sun's local +Z in…]
- "scripts_toon_setup_g_mix": ".mix()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L73 | neighbors=[build_group(), _G, .n()]
- "scripts_toon_setup_g_vmath": ".vmath()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L60 | neighbors=[build_group(), _G, .n()]
- "scripts_toon_setup_key_light": "_key_light()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L156 | neighbors=[toon_setup.py, .link(), run()]
- "scripts_toon_setup_outline_material": "_outline_material()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L139 | neighbors=[toon_setup.py, _lin(), run()]
- "scripts_toon_setup_smooth_outline_normals": "smooth_outline_normals()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L227 | neighbors=[toon_setup.py, NPR_OutlineNormal corner color: positio…, run()]
- "scripts_trace_ref": "trace_ref.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/trace_ref.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, quant()]
- "scripts_track_camera_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L38 | neighbors=[track_camera.py, _clip_area(), _solve()]
- "scripts_uv_pack_collapsed_ratio": "_collapsed_ratio()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L38 | neighbors=[uv_pack.py, Fraction of faces whose UV area is ~0 (…, run()]
- "scripts_uv_pack_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L49 | neighbors=[uv_pack.py, _collapsed_ratio(), _seams_from_sharp()]
- "scripts_vse_edit_add_clip": "_add_clip()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L43 | neighbors=[vse_edit.py, _frames(), run()]
- "scripts_vse_edit_frames": "_frames()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L31 | neighbors=[vse_edit.py, _add_clip(), Sorted frame files for a folder or a # …]
- "scripts_vse_edit_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L84 | neighbors=[vse_edit.py, _add_clip(), _output()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-081.json

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
