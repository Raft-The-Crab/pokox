# Node Description Batch 38 of 207

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

- "petsim_pet_props_picnic_set": "picnic_set()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L854 | neighbors=[pet_props.py, ell(), puff(), soft(), checkered blanket (cells alternate red …]
- "petsim_pet_props_rainbow_arch": "rainbow_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L335 | neighbors=[pet_props.py, puff(), soft(), star(), 6 chunky pastel bands on a half circle,…]
- "petsim_pet_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L618 | neighbors=[pet_props.py, round spawn dais: two soft tiers, mint …, paw(), rcyl(), soft()]
- "petsim_pet_props_trade_pad": "trade_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L519 | neighbors=[pet_props.py, flat trade circle: cream disc with a pa…, arc_pts(), rcyl(), soft()]
- "physics_visual_solver": "visual_solver.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, VisualSolver, VisualWorld]
- "plusspeed_plus_props_v3_lamp_pillar": "lamp_pillar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L90 | neighbors=[plus_props_v3.py, chamfer_block(), cyl_v(), octo(), street lantern pillar: chamfered steppe…]
- "plusspeed_plus_props_v3_octo": "octo()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L20 | neighbors=[plus_props_v3.py, hatchery(), lamp_pillar(), 8-sided column from two overlapping blo…, shop_stall()]
- "plusspeed_plus_props_v3_rebirth_altar": "rebirth_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L196 | neighbors=[plus_props_v3.py, REBIRTH portal: 8-sided stepped dais wi…, chamfer_block(), cyl_v(), ring()]
- "plusspeed_plus_props_v3_ring": "ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L29 | neighbors=[plus_props_v3.py, hatchery(), n blocks laid tangent around a circle (…, rebirth_altar(), wins_pad()]
- "program_program_run_stateful_program": "run_stateful_program()" | kind=code-symbol | source=mute/src/program/program.cpp:L321 | neighbors=[program.cpp, run_program(), commit_globals(), fail(), prepare_globals()]
- "program_program_run_stateful_program_bytecode": "run_stateful_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L347 | neighbors=[program.cpp, run_program_bytecode(), commit_globals(), fail(), prepare_globals()]
- "refmatch_compare_background_fit_mask": "background_fit_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L61 | neighbors=[compare.py, _quad_basis(), significant_components(), Segment the subject by subtracting a fi…, subject_mask()]
- "refmatch_compare_letterbox": "letterbox()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L35 | neighbors=[compare.py, _fit_size(), load_rgb(), mask_at_native(), Resize a PIL image into size with aspec…]
- "refmatch_compare_mask_at_native": "mask_at_native()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L414 | neighbors=[compare.py, evaluate(), letterbox(), subject_mask(), Segment at the image's NATIVE resolutio…]
- "refmatch_compare_normalize_mask": "normalize_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L191 | neighbors=[compare.py, evaluate(), _fit_size(), tight_crop(), Crop to the tight subject box, then sca…]
- "refmatch_compare_palette_report": "palette_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L313 | neighbors=[compare.py, evaluate(), _hex(), _kmeans(), _srgb_to_lab()]
- "refmatch_compare_significant_components": "significant_components()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L161 | neighbors=[compare.py, background_fit_mask(), flood_background_mask(), Keep every connected component above a …, subject_mask()]
- "refmatch_palette_report_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L163 | neighbors=[palette_report.py, compare_to_render(), extract(), load_palette(), print_rows()]
- "scripts_apply_stack": "apply_stack.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hardsurface-modeling/scripts/apply_stack.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, run(), _smooth_faces(), Build (and optionally apply) a producti…]
- "scripts_bake_action_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L81 | neighbors=[bake_action.py, _assign(), list_actions(), _mute(), _root_motion()]
- "scripts_batch_process_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L97 | neighbors=[batch_process.py, gather(), inventory(), load(), _module()]
- "scripts_bld": "bld.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _c(), Grid, hx()]
- "scripts_bld_c": "_c()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L12 | neighbors=[bld.py, hx(), .box(), .export(), .fbox()]
- "scripts_bld_grid_sl": "._sl()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L24 | neighbors=[Grid, .box(), .cut(), .fbox(), .fcut()]
- "scripts_blocks_mesh_blocks": "mesh_blocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L71 | neighbors=[blocks.py, neon_mat(), rgb_of(), shape_bm(), one solid mesh (palette + studs) + one …]
- "scripts_blocks_rotm": "rotm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L20 | neighbors=[blocks.py, .b(), .put(), (pitch about X, yaw about Y, roll about…, transformed()]
- "scripts_brick_rig_export": "export()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L106 | neighbors=[brick_rig.py, assign(), _dilate6(), _quads(), verify()]
- "scripts_convert_pb_to_json": "convert_pb_to_json.py" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, convert_pb_to_json(), main(), Converts R8 keep radius protobuf files …]
- "scripts_env_report": "env_report.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _gpu(), run(), Report Blender version, engines, GPU, a…]
- "scripts_gn_builder_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L178 | neighbors=[gn_builder.py, apply(), build(), describe(), _parse_val()]
- "scripts_groom_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L294 | neighbors=[groom.py, build_cards(), card_material(), groom(), render_atlas()]
- "scripts_kit_check_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L68 | neighbors=[kit_check.py, _fix(), _on_grid(), _pivot_target(), _texel_density()]
- "scripts_lightning_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L85 | neighbors=[lightning.py, _bolt_points(), _clear(), _curve(), _envelope()]
- "scripts_loop_check_check": "_check()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L51 | neighbors=[loop_check.py, _diff(), _poses(), _w(), run()]
- "scripts_make_lods": "make_lods.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/make_lods.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, cleanup(), run(), Generate an LOD chain (<name>_LOD1..N) …]
- "scripts_mesh_stats": "mesh_stats.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/mesh_stats.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, run(), _vram(), Budget report: tris/verts per object, m…]
- "scripts_orchestrator_load_gradle_properties": "load_gradle_properties()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L157 | neighbors=[orchestrator.py, _candidate_project_roots(), _strip_inline_comment(), main(), Loads properties from gradle.properties…]
- "scripts_orchestrator_load_version_catalog": "load_version_catalog()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L180 | neighbors=[orchestrator.py, _candidate_project_roots(), _strip_inline_comment(), main(), Loads versions from gradle/libs.version…]
- "scripts_orchestrator_strip_inline_comment": "_strip_inline_comment()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L129 | neighbors=[orchestrator.py, load_app_plugin_aliases(), load_gradle_properties(), load_version_catalog(), Strips inline comments starting with '#…]
- "scripts_play_store_scraper_scrape_app_details": "scrape_app_details()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L384 | neighbors=[play_store_scraper.py, Scrapes app metadata and Data Safety in…, extract_data_safety(), extract_metadata(), fetch_html()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-037.json

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
