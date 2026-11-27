# Node Description Batch 55 of 208

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

- "scripts_retarget_auto_map": "auto_map()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L71 | neighbors=[retarget.py, _parts(), _split(), run()]
- "scripts_retarget_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L90 | neighbors=[retarget.py, auto_map(), _parts(), _rot()]
- "scripts_retarget_split": "_split()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L41 | neighbors=[retarget.py, auto_map(), _parts(), mixamorig:LeftUpLeg' -> ('upleg', 'L');…]
- "scripts_roblox_export_r_pos": "r_pos()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L116 | neighbors=[roblox_export.py, at(), big_part(), look()]
- "scripts_roblox_materials_resolve": "resolve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L67 | neighbors=[roblox_materials.py, preview(), material for palette ramp `col` on obje…, mat_for()]
- "scripts_scanner_collect_target_files": "collect_target_files()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L60 | neighbors=[scanner.py, get_scanner_config(), get_supported_extensions(), Performs a single master walk to catego…]
- "scripts_scanner_perform_scan": "perform_scan()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L228 | neighbors=[scanner.py, get_scanner_config(), _identify_semantic_files(), Orchestrates the parallel scanning of i…]
- "scripts_scatter_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L146 | neighbors=[scatter.py, build_tree(), _instances(), _layer_coll()]
- "scripts_scene_mood_fog": "_fog()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L260 | neighbors=[scene_mood.py, _math(), Box volume around scene + camera. Densi…, run()]
- "scripts_shapekeys_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L58 | neighbors=[shapekeys.py, _co(), _get(), _keys()]
- "scripts_smart_material_apply_mat": "_apply_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L222 | neighbors=[smart_material.py, _image_node(), _src(), run()]
- "scripts_studlib_limb": "limb()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L147 | neighbors=[studlib.py, box(), frame(), Box from point a to point c (w x d cros…]
- "scripts_studlib_wedge": "wedge()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L99 | neighbors=[studlib.py, ramp(), Ramp (Roblox WedgePart): full height at…, _emit()]
- "scripts_surface_weather_g_link": ".link()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L35 | neighbors=[build_group(), _G, .set(), _snow_tree()]
- "scripts_surface_weather_g_math": ".math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L50 | neighbors=[build_group(), _G, .n(), _snow_tree()]
- "scripts_surface_weather_vertex_mask": "_vertex_mask()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L298 | neighbors=[surface_weather.py, Color attribute ENV_Weather (R puddle, …, run(), .noise()]
- "scripts_template_engine_parserframe": "_ParserFrame" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L153 | neighbors=[template_engine.py, compile_template(), .__init__(), Helper class representing an active sta…]
- "scripts_texel_density_measure": "_measure()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L52 | neighbors=[texel_density.py, _islands(), _uv_area(), run()]
- "scripts_toon_setup_g_math": ".math()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L54 | neighbors=[build_group(), _G, .n(), .step()]
- "scripts_toon_setup_g_step": ".step()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L66 | neighbors=[build_group(), _G, .math(), .n()]
- "scripts_toon_setup_lin": "_lin()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L31 | neighbors=[toon_setup.py, _line_art(), _outline_material(), run()]
- "scripts_toon_setup_line_art": "_line_art()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L261 | neighbors=[toon_setup.py, .link(), _lin(), run()]
- "scripts_verify_desktop_main": "main()" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L61 | neighbors=[verify_desktop.py, classify(), parse_runtime(), run_step()]
- "shared_bpyx_cli": "cli()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L46 | neighbors=[_bpyx.py, argv(), emit(), CLI entry: parse args after '--', run, …]
- "skyrise_sky_map_paving": "paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L167 | neighbors=[sky_map.py, sub(), spawn_island(), summit()]
- "skyrise_sky_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L118 | neighbors=[sky_map.py, micro_detail(), Hm(), zone_island()]
- "skyrise_sky_models_lumpy": "lumpy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L9 | neighbors=[sky_models.py, island_under(), puffy_tree(), icosphere with noise displacement: chun…]
- "skyrise_sky_models_puffy_tree": "puffy_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L22 | neighbors=[sky_models.py, blossom_tree(), lumpy(), trunk that forks into 2-3 limbs, root f…]
- "skyrise_sky_models2_planks": "planks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L15 | neighbors=[sky_models2.py, n separate bevelled planks side by side…, sell_pad(), upgrade_stand()]
- "skyrise_sky_models2_sell_pad": "sell_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L189 | neighbors=[sky_models2.py, sell booth: glowing sell circle in fron…, coin(), planks()]
- "skyrise_sky_models2_upgrade_stand": "upgrade_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L216 | neighbors=[sky_models2.py, upgrade shop: planked counter with gold…, bottle(), planks()]
- "skyrise_sky_models4_blade": "blade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L9 | neighbors=[sky_models4.py, grass_tuft(), one grass blade: thin tapered wedge (4 …, wildflowers()]
- "skyrise_sky_models4_grass_tuft": "grass_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L23 | neighbors=[sky_models4.py, dune_grass(), blade(), modelled blade cluster, dark at the roo…]
- "skyrise_sky_models4_wildflowers": "wildflowers()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L40 | neighbors=[sky_models4.py, small flower clump: stems + 5-petal sta…, blade(), star()]
- "skyrise_sky_props_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L355 | neighbors=[sky_props.py, gem(), sphere(), treasure chest, lid open (back +Z hinge…]
- "skyrise_sky_props_island_under": "island_under()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L70 | neighbors=[sky_props.py, lathe(), sphere(), underside of a floating island: rings f…]
- "skyrise_sky_props_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L198 | neighbors=[sky_props.py, zone gate: two banded stone pillars, ar…, gem(), torus()]
- "src_camera_view_proj": "view_proj()" | kind=code-symbol | source=engine/render/src/camera.cpp:L61 | neighbors=[camera.cpp, look_at(), multiply(), perspective()]
- "src_character_controller_deepest_contact": "deepest_contact()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L152 | neighbors=[character_controller.cpp, shape_bound(), spheres_disjoint(), update()]
- "src_character_controller_shape_bound": "shape_bound()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L52 | neighbors=[character_controller.cpp, deepest_contact(), touches_uncached(), update()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-054.json

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
