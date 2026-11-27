# Node Description Batch 78 of 207

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

- "scripts_rigify_build_ensure_rigify": "_ensure_rigify()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L31 | neighbors=[rigify_build.py, _generate(), run()]
- "scripts_rigify_build_fit": "_fit()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L44 | neighbors=[rigify_build.py, _bounds(), run()]
- "scripts_rigify_build_game_skeleton": "game_skeleton()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L82 | neighbors=[rigify_build.py, root + DEF bones with DEF-only parentin…, run()]
- "scripts_rigify_build_generate": "_generate()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L72 | neighbors=[rigify_build.py, _ensure_rigify(), run()]
- "scripts_roblox_export_cast": "cast()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L715 | neighbors=[roblox_export.py, inside(), first hit along d whose owner passes ok…]
- "scripts_roblox_export_clean_name": "clean_name()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L118 | neighbors=[roblox_export.py, base_of(), big_part()]
- "scripts_roblox_export_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L729 | neighbors=[roblox_export.py, cast(), inside ONE solid: >= 5 of 6 axis rays f…]
- "scripts_roblox_export_newobj": "newobj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L150 | neighbors=[roblox_export.py, material_split(), object with exactly `name` (the MeshPar…]
- "scripts_roblox_export_palette_rgb": "palette_rgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L292 | neighbors=[roblox_export.py, big_part(), average palette colour under a face (fo…]
- "scripts_roblox_materials_mat_for": "mat_for()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L65 | neighbors=[roblox_materials.py, resolve(), write_map()]
- "scripts_roblox_materials_write_map": "write_map()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L91 | neighbors=[roblox_materials.py, material_map.json for the exporter: pal…, mat_for()]
- "scripts_scanner_scan_single_file": "_scan_single_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L178 | neighbors=[scanner.py, Internal worker to scan a single file f…, get_supported_extensions()]
- "scripts_scatter_build_tree": "build_tree()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L34 | neighbors=[scatter.py, _on(), run()]
- "scripts_scatter_on": "_on()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L29 | neighbors=[scatter.py, build_tree(), Enabled socket by name: Random Value ke…]
- "scripts_scene_mood_lerp_table": "_lerp_table()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L75 | neighbors=[scene_mood.py, run(), _world()]
- "scripts_scene_mood_lum": "lum()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L84 | neighbors=[scene_mood.py, run(), _world()]
- "scripts_scene_mood_math": "_math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L148 | neighbors=[scene_mood.py, _fog(), _world()]
- "scripts_scene_mood_sun_dir": "_sun_dir()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L88 | neighbors=[scene_mood.py, Direction TO the light. heading 0 = +Y,…, run()]
- "scripts_scene_mood_transmittance": "_transmittance()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L246 | neighbors=[scene_mood.py, Fraction of key/sky light reaching subj…, run()]
- "scripts_sculpt_ops_apply": "_apply()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-sculpting/scripts/sculpt_ops.py:L29 | neighbors=[sculpt_ops.py, _ctx(), run()]
- "scripts_sculpt_ops_ctx": "_ctx()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-sculpting/scripts/sculpt_ops.py:L24 | neighbors=[sculpt_ops.py, _apply(), run()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-077.json

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
