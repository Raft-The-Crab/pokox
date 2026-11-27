# Node Description Batch 79 of 207

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
- "semantic_emit_br16": "br16()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L22 | neighbors=[emit.cpp, mk(), emit_bytecode()]
- "semantic_emit_br32": "br32()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L28 | neighbors=[emit.cpp, mk(), emit_bytecode()]
- "semantic_emit_mov": "mov()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L20 | neighbors=[emit.cpp, emit_bytecode(), mk()]
- "semantic_lower_convert_type": "convert_type()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L17 | neighbors=[lower.cpp, unit_t(), lower_module()]
- "semantic_lower_lower_function_ex": "lower_function_ex()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L523 | neighbors=[lower.cpp, lower_function(), lower_module()]
- "semantic_lower_unit_t": "unit_t()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L11 | neighbors=[lower.cpp, convert_type(), lower_module()]
- "semantic_optimize_eliminate_dead_code": "eliminate_dead_code()" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L15 | neighbors=[optimize.cpp, is_pure(), is_terminator()]
- "semantic_semantic_numeric": "numeric()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L57 | neighbors=[semantic.cpp, is_float_scalar(), is_integer_scalar()]
- "shared_bpyx_argv": "argv()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L19 | neighbors=[_bpyx.py, cli(), Arguments after '--' (Blender ignores t…]
- "shared_bpyx_emit": "emit()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L35 | neighbors=[_bpyx.py, cli(), Print compact JSON on one marked line (…]
- "skyrise_sky_kit_sheet": "sky_kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "skyrise_sky_map_bridge_ends": "bridge_ends()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L55 | neighbors=[sky_map.py, H(), rim()]
- "skyrise_sky_map_ext": "ext()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L114 | neighbors=[sky_map.py, micro_detail(), widest horizontal reach of a kit prop (…]
- "skyrise_sky_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L71 | neighbors=[sky_map.py, micro_detail(), place()]
- "skyrise_sky_models_island_under": "island_under()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L109 | neighbors=[sky_models.py, lumpy(), underside: 16 rings to a rough tip, noi…]
- "skyrise_sky_models_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L202 | neighbors=[sky_models.py, carved stone gate: stepped plinths, oct…, bevel_box()]
- "skyrise_sky_models2_cactus": "cactus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L112 | neighbors=[sky_models2.py, _ribbed(), ribbed saguaro: star-section body, two …]
- "skyrise_sky_models2_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L39 | neighbors=[sky_models2.py, coin(), planked chest, curved lid held open, ir…]
- "skyrise_sky_models2_coin_pile": "coin_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L22 | neighbors=[sky_models2.py, coin(), a heap built only from coins (rings of …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-078.json

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
