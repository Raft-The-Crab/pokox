# Node Description Batch 54 of 208

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

- "scripts_analyze_describe_rule": "describe_rule()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L38 | neighbors=[analyze.py, analyze(), rule_origin(), Returns a rule's source text, origin, a…]
- "scripts_annotate_plan": "annotate_plan.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/annotate_plan.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, font(), main()]
- "scripts_bake_maps_curvature_from_normal": "_curvature_from_normal()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L122 | neighbors=[bake_maps.py, _blur(), Divergence of the tangent normal field:…, run()]
- "scripts_bind_mesh_heat_scale": "_heat_scale()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L71 | neighbors=[bind_mesh.py, _height(), Factor that brings the rig to ~1.8 m fo…, run()]
- "scripts_bind_mesh_proxy_weights": "_proxy_weights()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L38 | neighbors=[bind_mesh.py, _ctx(), _parent(), run()]
- "scripts_bld_grid_fbox": ".fbox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L34 | neighbors=[Grid, _c(), ._sl(), .window()]
- "scripts_bld_grid_fshape": ".fshape()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L40 | neighbors=[Grid, .blob(), .trace(), organic shape in fine bricks: fn(x, y, …]
- "scripts_bld_grid_window": ".window()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L89 | neighbors=[Grid, .fbox(), .fcut(), front-facing window in fine bricks; zf …]
- "scripts_blocks_blockprop_put": ".put()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L29 | neighbors=[BlockProp, Block, rotm(), nest another BlockProp (e.g. a lamp on …]
- "scripts_blocks_transformed": "transformed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L37 | neighbors=[blocks.py, world-space copies of a prop's blocks (…, Block, rotm()]
- "scripts_blocks_write_rbxmx": "write_rbxmx()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L156 | neighbors=[blocks.py, groups: {folder name: [Block, ...]} in …, _f(), rgb_of()]
- "scripts_bpyx_cli": "cli()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L46 | neighbors=[_bpyx.py, argv(), emit(), CLI entry: parse args after '--', run, …]
- "scripts_brick_rig_assign": "assign()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L29 | neighbors=[brick_rig.py, export(), limb(), int label per voxel (index into RIG, -1…]
- "scripts_brick_rig_quads": "_quads()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L74 | neighbors=[brick_rig.py, export(), _greedy2d(), greedy quads of the exposed faces of ce…]
- "scripts_brick_sheet": "brick_sheet.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, key(), Contact sheet of the brick pipeline's *…]
- "scripts_build_pbr_material_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L102 | neighbors=[build_pbr_material.py, _find_textures(), _gltf_output_group(), _srgb_to_lin()]
- "scripts_decal_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L72 | neighbors=[decal.py, _gaps(), _grid(), _material()]
- "scripts_generate_report_clean_severity": "clean_severity()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L154 | neighbors=[generate_report.py, aggregate_findings(), Robustly cleans severity strings by rem…, render_finding_card()]
- "scripts_generate_report_load_json": "load_json()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L238 | neighbors=[generate_report.py, aggregate_findings(), main(), Loads JSON from a file if it exists.]
- "scripts_generate_report_strip_emojis": "strip_emojis()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L56 | neighbors=[generate_report.py, main(), Removes emoji characters from a string., render_finding_card()]
- "scripts_gn_builder_build": "build()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L80 | neighbors=[gn_builder.py, _layout(), _sock(), run()]
- "scripts_groom_build_cards": "build_cards()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L162 | neighbors=[groom.py, _evaluated(), _spaced(), run()]
- "scripts_kit_check_fix": "_fix()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L53 | neighbors=[kit_check.py, _pivot_target(), Apply rotation+scale, then move the ori…, run()]
- "scripts_orchestrator_extract_dotnet_android_details": "extract_dotnet_android_details()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L653 | neighbors=[orchestrator.py, determine_primary_identity(), _msbuild_property(), Finds the .NET MAUI / .NET for Android …]
- "scripts_orchestrator_extract_manifest_details": "extract_manifest_details()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L716 | neighbors=[orchestrator.py, determine_primary_identity(), main(), Parses AndroidManifest.xml for key poli…]
- "scripts_orchestrator_load_custom_gradle_versions": "load_custom_gradle_versions()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L286 | neighbors=[orchestrator.py, _candidate_project_roots(), main(), Loads versions from shared Gradle files…]
- "scripts_orchestrator_resolve_to_int": "_resolve_to_int()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1101 | neighbors=[orchestrator.py, determine_primary_identity(), parse_application_modules(), Recursively resolves a variable name to…]
- "scripts_orchestrator_write_json_file": "_write_json_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L380 | neighbors=[orchestrator.py, Safely writes a JSON file., run_scanner_direct(), write_agent_prompts()]
- "scripts_play_store_scraper_extract_data_safety": "extract_data_safety()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L243 | neighbors=[play_store_scraper.py, PlayStoreDataSafetyParser, Extracts Data Safety information struct…, scrape_app_details()]
- "scripts_play_store_scraper_extract_metadata": "extract_metadata()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L188 | neighbors=[play_store_scraper.py, PlayStoreMetadataParser, Extracts all metadata into a clean dict…, scrape_app_details()]
- "scripts_post_glow": "post_glow.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post_glow.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, fx(), Preview post: single black silhouette o…]
- "scripts_precipitation_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L273 | neighbors=[precipitation.py, build_tree(), _camera_box(), _material()]
- "scripts_pro_lib_bevel": "bevel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L121 | neighbors=[pro_lib.py, box(), cyl(), ngon_prism()]
- "scripts_pro_lib_cyl": "cyl()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L177 | neighbors=[pro_lib.py, bevel(), ngon_prism(), vertical prism / frustum from y0 to y0 …]
- "scripts_pro_lib_ngon_prism": "ngon_prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L161 | neighbors=[pro_lib.py, cyl(), bevel(), poly = [(x, z), ...] counter-clockwise …]
- "scripts_pro_lib_out_build": ".build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L380 | neighbors=[Out, make_obj(), .material(), split()]
- "scripts_pro_lib_out_gadd": ".gadd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L375 | neighbors=[Out, .g(), .u(), a glow piece: uv on the white strip]
- "scripts_pro_lib_voronoi_cells": "voronoi_cells()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L296 | neighbors=[pro_lib.py, jittered-grid Voronoi cells clipped to …, clip_half(), clip_rect()]
- "scripts_prop_studio": "prop_studio.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/prop_studio.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arg(), setup()]
- "scripts_qa_check_material_issues": "_material_issues()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L54 | neighbors=[qa_check.py, _feeds(), [(severity_is_error, message)] for slot…, run()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-053.json

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
