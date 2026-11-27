# Node Description Batch 185 of 209

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
- "scripts_template_engine_rationale_28": "Resolves nested dot-notation keys from context (e.g., app.info.package)." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L28 | neighbors=[get_nested_val()] | lang=en
- "scripts_template_engine_rationale_40": "Base class for all Abstract Syntax Tree (AST) node elements." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L40 | neighbors=[Node] | lang=en
- "scripts_template_engine_rationale_47": "Represents raw static text blocks." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L47 | neighbors=[TextNode] | lang=en
- "scripts_template_engine_rationale_57": "Represents dynamic variable interpolation with literal fallbacks." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L57 | neighbors=[VarNode] | lang=en
- "scripts_template_engine_rationale_73": "Represents conditional block logic (IF, IF_ALL, IF_ANY)." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L73 | neighbors=[IfNode] | lang=en
- "scripts_template_engine_rationale_95": "Helper to strip leading/trailing whitespace from first/last TextNodes." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L95 | neighbors=[strip_nodes()] | lang=en
- "scripts_template_engine_textnode_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L49 | neighbors=[TextNode] | lang=en
- "scripts_template_engine_textnode_render": ".render()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L52 | neighbors=[TextNode] | lang=en
- "scripts_template_engine_varnode_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L59 | neighbors=[VarNode] | lang=en
- "scripts_terrain_rationale_1": "Game-ready terrain: noise (fbm, ridged mountains, rolling hills) or a heightmap" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L1 | neighbors=[terrain.py] | lang=pt
- "scripts_terrain_rationale_59": "Thermal erosion: material above the talus angle slides to lower neighbours (4-ne" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L59 | neighbors=[_erode()] | lang=en
- "scripts_texel_density_rationale_1": "Measure (and optionally set) texel density in px/m for objects' active UV map." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L1 | neighbors=[texel_density.py] | lang=en
- "scripts_texel_density_rationale_22": "UV islands as lists of faces (connected through shared UV coords)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L22 | neighbors=[_islands()] | lang=en
- "scripts_toon_setup_g_init": ".__init__()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L36 | neighbors=[_G] | lang=en
- "scripts_toon_setup_rationale_1": "Reversible toon/cel look: banded shading, shadow tint, rim, hard specular, inver" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L1 | neighbors=[toon_setup.py] | lang=en
- "scripts_toon_setup_rationale_169": "Light Direction = the sun's local +Z in world space (the sun shines along -Z)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L169 | neighbors=[_drive_light()] | lang=en
- "scripts_toon_setup_rationale_228": "NPR_OutlineNormal corner color: position-averaged normal in tangent space, packe" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L228 | neighbors=[smooth_outline_normals()] | lang=en
- "scripts_trace_ref_quant": "quant()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/trace_ref.py:L36 | neighbors=[trace_ref.py] | lang=en
- "scripts_track_camera_rationale_1": "Automatic camera solve from footage: detect features at the start and end of the" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L1 | neighbors=[track_camera.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-184.json

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
