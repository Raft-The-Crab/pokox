# Node Description Batch 29 of 208

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

- "passes_cube_demo": "cube_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Exception, cube_indices(), cube_vertices(), main(), c7a411f Fix MUT-01-20 audit defects in …]
- "petsim_pet_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L202 | neighbors=[pet_map.py, breakables(), egg_stand(), hub(), link(), zone_bounds()]
- "petsim_pet_map_edge_pt": "edge_pt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L281 | neighbors=[pet_map.py, build(), isle_R(), fence_ring(), hub(), link()]
- "petsim_pet_map_isle_at": "isle_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L43 | neighbors=[pet_map.py, breakables(), H(), isle_R(), polar(), place_soft()]
- "petsim_pet_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L178 | neighbors=[pet_map.py, build(), clip_fail(), isle_at(), place(), unplace()]
- "petsim_pet_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L453 | neighbors=[pet_map.py, candy(), crystal(), meadow(), egg_stand(), path()]
- "petsim_pet_map_zone_bounds": "zone_bounds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L375 | neighbors=[pet_map.py, candy(), crystal(), hub(), meadow(), anchor()]
- "petsim_pet_props_egg_stand": "egg_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L566 | neighbors=[pet_props.py, egg(), puff(), rcyl(), soft(), fluted cake pedestal with a glowing rin…]
- "petsim_pet_props_fence": "fence()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1005 | neighbors=[pet_props.py, ell(), rbox(), rcyl(), soft(), chunky rail fence segment from x = 0 to…]
- "petsim_pet_props_lollipop": "lollipop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L892 | neighbors=[pet_props.py, ell(), flat(), rcyl(), soft(), giant swirl lollipop: two interleaved c…]
- "petsim_pet_props_paw": "paw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L127 | neighbors=[pet_props.py, ell(), soft(), paw-print icon: palm pad + 4 toe beans,…, spawn_pad(), zone_gate()]
- "petsim_pet_props_pet_shop": "pet_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L357 | neighbors=[pet_props.py, ell(), pill(), rcyl(), soft(), open-front kiosk: round dais, curved ba…]
- "petsim_pet_props_pet_statue": "pet_statue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L323 | neighbors=[pet_props.py, ell(), puff(), puffpaw(), soft(), the Puffpaw statue + its quilted cushio…]
- "petsim_pet_props_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L119 | neighbors=[pet_props.py, rainbow_arch(), a chunky star standing upright facing -…, star_poly(), star_lamp(), upgrade_machine()]
- "petsim_pet_props_trade_booth": "trade_booth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L486 | neighbors=[pet_props.py, round trade table with a big scalloped …, ell(), rbox(), rcyl(), soft()]
- "petsim_pet_props_vsh": "vsh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L47 | neighbors=[pet_props.py, bridge(), coin_pile(), flat(), pet_fountain(), soft()]
- "plusspeed_plus_map_dress_caps": "dress_caps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L88 | neighbors=[plus_map.py, place(), finish(), hub(), put theme props on cap tops (centre of …, zone()]
- "plusspeed_plus_map_finish": "finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L192 | neighbors=[plus_map.py, blk(), dress_caps(), floor(), place(), walls()]
- "plusspeed_plus_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L160 | neighbors=[plus_map.py, blk(), dress_caps(), floor(), place(), walls()]
- "plusspeed_plus_props_v4_plinth": "plinth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L59 | neighbors=[plus_props_v4.py, egg_hatchery(), pixel_art(), podium_board(), rebirth_portal(), sneaker_shop()]
- "plusspeed_plus_props_v4_raster": "raster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L38 | neighbors=[plus_props_v4.py, egg_rows(), medal_rows(), portal_rows(), fn(x, y) -> char, x/y in -1..1 (y up); …, stopwatch_rows()]
- "program_program_fail": "fail()" | kind=code-symbol | source=mute/src/program/program.cpp:L20 | neighbors=[program.cpp, Depth(), prepare_globals(), run_program_reference(), run_stateful_program(), run_stateful_program_bytecode()]
- "refmatch_compare_subject_mask": "subject_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L146 | neighbors=[compare.py, mask_at_native(), Foreground mask.      Prefers an exact …, background_fit_mask(), flood_background_mask(), significant_components()]
- "refmatch_overlay": "overlay.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), _overlay(), _panel(), Side-by-side diagnostic sheet.  Metrics…]
- "refmatch_palette_report_compare_to_render": "compare_to_render()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L122 | neighbors=[palette_report.py, delta_e(), extract(), hex_to_rgb(), main(), For each named palette role, find the n…]
- "refmatch_palette_report_extract": "extract()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L74 | neighbors=[palette_report.py, compare_to_render(), hex_of(), kmeans(), subject_pixels(), main()]
- "scripts_auto_retopo": "auto_retopo.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_all(), _ctx(), run(), Make a low-poly retopo copy of a dense …]
- "scripts_bake_maps_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L139 | neighbors=[bake_maps.py, _curvature_from_normal(), _restore(), _set_device(), _signal_override(), _target_node()]
- "scripts_compare": "compare.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bbox(), concept_mask(), main(), Overlay a render's silhouette on a conc…]
- "scripts_export_asset_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L118 | neighbors=[export_asset.py, _animated(), _coerce(), _export(), _gather(), glb_summary()]
- "scripts_generate_report_render_finding_card": "render_finding_card()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L175 | neighbors=[generate_report.py, main(), Renders a detailed finding card in Mark…, clean_severity(), format_code_link(), strip_emojis()]
- "scripts_groom_groom": "groom()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L76 | neighbors=[groom.py, _assets(), curve_stats(), hair_material(), _modifier(), run()]
- "scripts_orchestrator_candidate_project_roots": "_candidate_project_roots()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L145 | neighbors=[orchestrator.py, load_app_plugin_aliases(), load_custom_gradle_versions(), load_gradle_properties(), load_version_catalog(), Returns target_dir and its parent direc…]
- "scripts_orchestrator_determine_primary_identity": "determine_primary_identity()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L530 | neighbors=[orchestrator.py, extract_dotnet_android_details(), extract_manifest_details(), _resolve_to_int(), main(), Heuristically determines the primary ap…]
- "scripts_orchestrator_load_app_plugin_aliases": "load_app_plugin_aliases()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L226 | neighbors=[orchestrator.py, _candidate_project_roots(), _strip_inline_comment(), main(), parse_application_modules(), Returns version-catalog plugin aliases …]
- "scripts_orchestrator_parse_application_modules": "parse_application_modules()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L431 | neighbors=[orchestrator.py, main(), _build_app_plugin_alias_pattern(), load_app_plugin_aliases(), _resolve_to_int(), Identifies distinct application modules…]
- "scripts_orchestrator_write_agent_prompts": "write_agent_prompts()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L843 | neighbors=[orchestrator.py, main(), Generates surgical prompt files for wor…, _load_json_file(), _read_text_file(), _write_json_file()]
- "scripts_post": "post.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, ffmpeg(), main(), outline(), Post-process renders from studlib.py: b…]
- "scripts_render_batch": "render_batch.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _frames(), _gpu(), run(), Render stills/animations with quality p…]
- "scripts_rigify_build_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L148 | neighbors=[rigify_build.py, _ensure_rigify(), _fit(), game_skeleton(), _generate(), _remove_face()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-028.json

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
