# Node Description Batch 17 of 208

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

- "scripts_batch_process": "batch_process.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, gather(), inventory(), load(), _module()]
- "scripts_build_pbr_material": "build_pbr_material.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, classify(), _find_textures(), _gltf_output_group(), run()]
- "scripts_garment_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L201 | neighbors=[garment.py, _drape(), _hide_body(), penetration(), _region(), _shell()]
- "scripts_generate_report_main": "main()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L668 | neighbors=[generate_report.py, aggregate_findings(), load_json(), render_finding_card(), render_table(), run_scraper()]
- "scripts_kit_check": "kit_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _fix(), _on_grid(), _pivot_target(), run()]
- "scripts_lightning": "lightning.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bolt_points(), _clear(), _curve(), _envelope()]
- "scripts_loop_check": "loop_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _check(), _diff(), _poses(), run()]
- "scripts_precipitation_build_tree": "build_tree()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L102 | neighbors=[precipitation.py, _iface(), _T, .math(), .n(), .out()]
- "scripts_retarget": "retarget.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, auto_map(), _parts(), _rot(), run()]
- "scripts_roblox_materials": "roblox_materials.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, column_of(), mat_for(), preview(), resolve()]
- "scripts_scanner": "scanner.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, collect_target_files(), get_scanner_config(), get_supported_extensions(), _identify_semantic_files()]
- "scripts_scatter": "scatter.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_tree(), _instances(), _layer_coll(), _on()]
- "scripts_template_engine_compile_template": "compile_template()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L162 | neighbors=[template_engine.py, EachNode, IfNode, _ParserFrame, TextNode, VarNode]
- "scripts_verify_desktop": "verify_desktop.py" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, classify(), main(), parse_runtime(), run_step()]
- "semantic_ssa": "ssa.cpp" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L1 | neighbors=[2c0194b Add assignments and loop-carrie…, 4cead55 Add MUT-27 bytecode verificatio…, 952997e Audit MUT-01-55 and harden veri…, fd66d0d Add MUT-25 typed SSA IR and ver…, dump_ir(), is_terminator()]
- "skyrise_sky_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L112 | neighbors=[sky_map.py, build(), micro_detail(), rim_dress(), spawn_island(), summit()]
- "skyrise_sky_map_spawn_island": "spawn_island()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L224 | neighbors=[sky_map.py, build(), face(), free(), paving(), place()]
- "skyrise_sky_map_summit": "summit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L352 | neighbors=[sky_map.py, build(), face(), island_at(), on_bridge_line(), paving()]
- "skyrise_sky_models3": "sky_models3.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bush(), charred_tree(), lamp_post(), lava_pool()]
- "skyrise_sky_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L61 | neighbors=[sky_props.py, egg_shrine(), flower_bed(), sell_pad(), spawn_pad(), teleport_pad()]
- "src_camera": "camera.cpp" | kind=code-symbol | source=engine/render/src/camera.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, look_at(), multiply(), orbit(), perspective(), view_proj()]
- "src_frame_stats": "frame_stats.cpp" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, cpu_ms(), fps(), gpu_ms(), record_cpu(), record_gpu()]
- "src_logging_emit": "emit()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L33 | neighbors=[logging.cpp, critical(), debug(), error(), info(), to_spdlog()]
- "src_narrowphase_epa_penetration": "epa_penetration()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L349 | neighbors=[narrowphase.cpp, collide_local(), cso_support(), face_barycentric(), face_normal(), orient_out()]
- "src_pokomesh": "pokomesh.cpp" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, fail(), finite_vec3(), load_pokomesh(), parse_pokomesh(), read_f32()]
- "src_visual_solver_step": "step()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L412 | neighbors=[visual_solver.cpp, add_contact(), begin_step(), collide_visual(), find_body(), integrate()]
- "state_state": "state.cpp" | kind=code-symbol | source=mute/src/state/state.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, hash_state(), merge(), read32(), read64(), round()]
- "targets_run_dual_target_tests_android_leg": "android_leg()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L293 | neighbors=[run_dual_target_tests.py, adb_shell(), android_compile(), android_tools(), normalize_lf(), now()]
- "tests_run_all": "run_all.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, fresh(), main(), requires_gpu(), skill_module()]
- "tests_test_animation": "test_animation.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _rig(), test_bake_to_copy_with_root_motion_and_…, test_loop_check_hitches_kink_dip_and_sm…, test_loop_check_pops_fix_and_root_motio…]
- "tests_test_mating": "test_mating.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _socket(), test_collision_fails(), test_good_fit_passes(), test_loose_fit_fails()]
- "tests_test_npr": "test_npr.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bands(), _clusters(), _scene(), test_remove_restores_slots_on_unmateria…]
- "tests_test_workflow_captured": "captured()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L82 | neighbors=[test_workflow.py, test_build_and_render_reject_changed_so…, test_completion_requires_brief_review_a…, test_evidence_is_stored_in_the_workspac…, test_independent_report_binds_images_sc…, test_reference_compare_requires_exact_f…]
- "tools_g2_replay_probe_main": "main()" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L117 | neighbors=[g2_replay_probe.cpp, bounds_of(), combine_friction(), combine_restitution(), fx(), shape_of()]
- "tools_math_determinism": "math_determinism.py" | kind=code-symbol | source=mute/tools/math_determinism.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, compare(), load_corpus(), load_trace(), main(), _object()]
- "tools_readme_hero": "readme_hero.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, figure(), font(), frame(), main()]
- "towncity_city_paint_tile": "tile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L45 | neighbors=[city_paint.py, block(), one periodic WP x HP tile at base shade…, clip(), edge(), hash2()]
- "towncity_town_map_dressing": "dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L378 | neighbors=[town_map.py, build(), face(), free(), near_intersection(), place()]
- "towncity_town_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L90 | neighbors=[town_map.py, alley(), build(), dressing(), landmarks(), row()]
- "towncity_town_map_row": "row()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L221 | neighbors=[town_map.py, buildings(), landmarks(), lay buildings side by side from `start`…, bkit(), face()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-016.json

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
