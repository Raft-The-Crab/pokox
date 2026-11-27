# Node Description Batch 182 of 207

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
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "scripts_scene_audit_rationale_1": "Audit scene hygiene: units, transforms, naming, collections, materials, images," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-scene-setup/scripts/scene_audit.py:L1 | neighbors=[scene_audit.py] | lang=en
- "scripts_scene_mood_rationale_1": "Time-of-day / mood environment in one call: physically measured sky + matching s" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L1 | neighbors=[scene_mood.py] | lang=en
- "scripts_scene_mood_rationale_175": "Build ENV_World. Returns horizontal ambient irradiance (luminance, scene units)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L175 | neighbors=[_world()] | lang=en
- "scripts_scene_mood_rationale_247": "Fraction of key/sky light reaching subject height through the fog (for exposure" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L247 | neighbors=[_transmittance()] | lang=en
- "scripts_scene_mood_rationale_261": "Box volume around scene + camera. Density = extinction from visibility (Koschmie" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L261 | neighbors=[_fog()] | lang=en
- "scripts_scene_mood_rationale_89": "Direction TO the light. heading 0 = +Y, 90 = +X (matches ShaderNodeTexSky.sun_ro" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L89 | neighbors=[_sun_dir()] | lang=en
- "scripts_sculpt_ops_rationale_1": "Headless-safe sculpt preparation and procedural \"sculpt\" ops (no Sculpt Mode - i" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-sculpting/scripts/sculpt_ops.py:L1 | neighbors=[sculpt_ops.py] | lang=en
- "scripts_shapekeys_rationale_1": "Shape-key toolkit for faces: create ARKit-52 / viseme sets, split symmetric keys" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L1 | neighbors=[shapekeys.py] | lang=en
- "scripts_sim_setup_rationale_1": "Set up and bake simulations: rigid bodies, classic cloth (presets), 5.2 node-bas" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L1 | neighbors=[sim_setup.py] | lang=en
- "scripts_smart_material_g_init": ".__init__()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L39 | neighbors=[_G] | lang=en
- "scripts_smart_material_rationale_1": "Reversible \"smart material\" layers on existing Principled materials: edge wear (" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L1 | neighbors=[smart_material.py] | lang=en
- "scripts_smart_material_rationale_159": "TX_Curvature point attribute: 0.5 flat, -> 1 convex, -> 0 concave.      Mean ele" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L159 | neighbors=[curvature_attribute()] | lang=en
- "scripts_smart_material_rationale_34": "sRGB 0-1 -> linear (Blender color sockets are linear)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L34 | neighbors=[_lin()] | lang=en
- "scripts_stress_poses_rationale_1": "Create a QA_Stress action with extreme poses to review deformation (elbows, knee" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L1 | neighbors=[stress_poses.py] | lang=en
- "scripts_stress_poses_rationale_57": "Rotate a pose bone about a WORLD axis through its head (rig-agnostic: ignores bo" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L57 | neighbors=[_rotate()] | lang=pt
- "scripts_studlib_export": "export()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L306 | neighbors=[studlib.py] | lang=en
- "scripts_studlib_m": "_m()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L182 | neighbors=[studlib.py] | lang=en
- "scripts_studlib_rationale_1": "Stud-voxel creature runner (headless Blender).  blender -b --factory-startup --p" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L1 | neighbors=[studlib.py] | lang=en
- "scripts_studlib_rationale_100": "Ramp (Roblox WedgePart): full height at local +y (back), sloping down to the bot" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L100 | neighbors=[wedge()] | lang=en
- "scripts_studlib_rationale_110": "Cylinder from point a to point b, radius r (Roblox Part.Shape Cylinder, axis = l" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L110 | neighbors=[cyl()] | lang=en
- "scripts_studlib_rationale_123": "Wedge by ranges; the slope rises toward `up` (back = +y, front = -y, left = +x," | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L123 | neighbors=[ramp()] | lang=en
- "scripts_studlib_rationale_130": "Box by ranges: easy to make neighbours touch without overlapping. Args are (y, x" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L130 | neighbors=[span()] | lang=en
- "scripts_studlib_rationale_135": "Mirrored pair. Use '%' in the bone name for sided bones: sym(..., 'wing.%')." | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L135 | neighbors=[sym()] | lang=en
- "scripts_studlib_rationale_140": "for sx, s in K.sides(): ... -> (1,'L'), (-1,'R')" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L140 | neighbors=[sides()] | lang=en
- "scripts_studlib_rationale_148": "Box from point a to point c (w x d cross-section). For tails, necks, tentacle se" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L148 | neighbors=[limb()] | lang=en
- "scripts_studlib_rationale_153": "Tapering spike/horn: 3 boxes 1 / .66 / .36 wide; tip key on the last one. Base w" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L153 | neighbors=[spike()] | lang=en
- "scripts_studlib_rationale_159": "Stepped dome/egg: rows = [(half_width_frac, height)] from bottom; each row narro" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L159 | neighbors=[stack()] | lang=en
- "scripts_studlib_rationale_89": "add a custom solid (local unit coords) transformed by Mw; same colour / glow / s" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L89 | neighbors=[_emit()] | lang=en
- "scripts_studlib_render_all": "render_all()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L233 | neighbors=[studlib.py] | lang=en
- "scripts_surface_weather_g_init": ".__init__()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L32 | neighbors=[_G] | lang=en
- "scripts_surface_weather_rationale_1": "Reversible weather layer on existing materials: wetness (porous darkening + wate" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L1 | neighbors=[surface_weather.py] | lang=en
- "scripts_surface_weather_rationale_299": "Color attribute ENV_Weather (R puddle, G snow, B wall/streak) for engine shaders" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L299 | neighbors=[_vertex_mask()] | lang=en
- "scripts_template_engine_ifnode_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L75 | neighbors=[IfNode] | lang=en
- "scripts_template_engine_node_render": ".render()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L42 | neighbors=[Node] | lang=en
- "scripts_template_engine_parserframe_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L156 | neighbors=[_ParserFrame] | lang=en
- "scripts_template_engine_rationale_115": "Represents standard iteration logic {{#EACH}} over lists/dicts." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L115 | neighbors=[EachNode] | lang=en
- "scripts_template_engine_rationale_122": "Helper to render nested children under a specific loop context." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L122 | neighbors=[._render_children()] | lang=en
- "scripts_template_engine_rationale_154": "Helper class representing an active stack frame in the compiler." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L154 | neighbors=[_ParserFrame] | lang=en
- "scripts_template_engine_rationale_163": "Parses template_str forward-only, building the AST Node tree." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L163 | neighbors=[compile_template()] | lang=en
- "scripts_template_engine_rationale_233": "Renders a markdown template with high performance and zero dependencies." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L233 | neighbors=[render_template()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-181.json

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
