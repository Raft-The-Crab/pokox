# Node Description Batch 22 of 207

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

- "scripts_analyze": "analyze.py" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyze(), describe_rule(), main(), rule_origin()]
- "scripts_bind_mesh_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L88 | neighbors=[bind_mesh.py, cleanup(), _heat_scale(), _height(), _parent(), _proxy_weights()]
- "scripts_decal": "decal.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _gaps(), _grid(), _material(), run()]
- "scripts_generate_report_aggregate_findings": "aggregate_findings()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L249 | neighbors=[generate_report.py, clean_severity(), load_json(), parse_boolean(), parse_disclosure_status(), main()]
- "scripts_play_store_scraper_playstoredatasafetyparser": "PlayStoreDataSafetyParser" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L139 | neighbors=[play_store_scraper.py, extract_data_safety(), .handle_data(), .handle_endtag(), .handle_starttag(), .__init__()]
- "scripts_play_store_scraper_playstoremetadataparser": "PlayStoreMetadataParser" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L57 | neighbors=[play_store_scraper.py, extract_metadata(), .handle_data(), .handle_endtag(), .handle_starttag(), .__init__()]
- "scripts_pro_lib_out": "Out" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L363 | neighbors=[pro_lib.py, .add(), .build(), .g(), .gadd(), .__init__()]
- "scripts_qa_check_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L178 | neighbors=[qa_check.py, _islands(), _material_issues(), _mesh_world(), _point_in_tri(), _result()]
- "scripts_scene_mood_world": "_world()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L174 | neighbors=[scene_mood.py, Build ENV_World. Returns horizontal amb…, run(), _lerp_table(), lum(), _math()]
- "scripts_shapekeys": "shapekeys.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-facial-shapekeys/scripts/shapekeys.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _co(), _get(), _keys(), run()]
- "scripts_stress_poses": "stress_poses.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/stress_poses.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _find(), _rotate(), run(), _side()]
- "scripts_surface_weather_g_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L44 | neighbors=[build_group(), _G, .math(), .mix(), .mrange(), .noise()]
- "scripts_surface_weather_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L317 | neighbors=[surface_weather.py, _apply_mat(), build_group(), _remove_mat(), _snow_material(), _snow_tree()]
- "scripts_surface_weather_snow_tree": "_snow_tree()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L246 | neighbors=[surface_weather.py, run(), _G, .link(), .math(), .n()]
- "scripts_template_engine_eachnode": "EachNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L114 | neighbors=[template_engine.py, compile_template(), .__init__(), .render(), ._render_children(), Node]
- "scripts_template_engine_node": "Node" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L39 | neighbors=[template_engine.py, EachNode, IfNode, .render(), Base class for all Abstract Syntax Tree…, TextNode]
- "scripts_terrain_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L157 | neighbors=[terrain.py, _erode(), _heightmap(), _material(), _noise_field(), _save_png16()]
- "scripts_texel_density": "texel_density.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _islands(), _measure(), run(), _uv_area()]
- "scripts_verify_desktop": "verify_desktop.py" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …, classify(), main(), parse_runtime(), run_step()]
- "scripts_vse_edit": "vse_edit.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _add_clip(), _frames(), _output(), run()]
- "semantic_emit_emit_bytecode": "emit_bytecode()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L36 | neighbors=[emit.cpp, alu(), br16(), br32(), is_terminator_pub(), mk()]
- "semantic_optimize": "optimize.cpp" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L1 | neighbors=[0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, e499073 Add MUT-29 dead-code eliminatio…, eliminate_dead_code(), is_pure(), is_terminator()]
- "skyrise_sky_map_on_bridge_line": "on_bridge_line()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L121 | neighbors=[sky_map.py, micro_detail(), segd(), rim_dress(), sky_dressing(), summit()]
- "skyrise_sky_map_rim": "rim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L33 | neighbors=[sky_map.py, bridge_ends(), island_at(), island_mesh(), micro_detail(), rim_dress()]
- "src_camera": "camera.cpp" | kind=code-symbol | source=engine/render/src/camera.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, look_at(), multiply(), orbit(), perspective(), view_proj()]
- "src_frame_stats": "frame_stats.cpp" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, cpu_ms(), fps(), gpu_ms(), record_cpu(), record_gpu()]
- "src_narrowphase_collide": "collide()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L672 | neighbors=[narrowphase.cpp, aabb_of(), collide_local(), local_extent(), local_shape(), to_world()]
- "src_pokomesh": "pokomesh.cpp" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, fail(), finite_vec3(), load_pokomesh(), parse_pokomesh(), read_f32()]
- "state_state": "state.cpp" | kind=code-symbol | source=mute/src/state/state.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, hash_state(), merge(), read32(), read64(), round()]
- "stdlib_stdlib_physics": "stdlib_physics.cpp" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L1 | neighbors=[2680d0e Pushed an update., 5106553 MUT-42: physics hostcall implem…, 78dbd1e Merge pull request #7 from Raft…, fixed_from_raw(), physics_hostcall_defs(), physics_raycast()]
- "sugarworks_sugar_props_exchange": "exchange()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L293 | neighbors=[sugar_props.py, dome(), sphere(), stripes(), subdiv_line(), torus()]
- "tests_fixtures_mesh_object": "mesh_object()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L7 | neighbors=[fixtures.py, cube(), detached_part(), plane(), simple_character(), uv_sphere()]
- "tests_test_atmosphere": "test_atmosphere.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _mean_luma(), _render(), test_fog_density_from_visibility_and_mo…, test_night_renders_darker_than_noon()]
- "tests_test_gridfinity_mesh": "_mesh()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L17 | neighbors=[test_gridfinity.py, test_bin_with_lip_magnets_screws(), test_compartments_scoop_label(), test_d110_regression(), test_finger_notch_removes_material(), test_minimal_bin_no_lip()]
- "tests_test_retopo_uv": "test_retopo_uv.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_retopo_uv.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_auto_retopo_methods(), test_auto_retopo_quadriflow_voxel_first…, test_decimate_drops_shape_keys_instead_…, test_uv_pack_and_texel_density_set()]
- "tests_test_rigging": "test_rigging.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _humanoid_mesh(), test_bind_tiny_and_huge_rigs_get_real_w…, test_proxy_bind_and_fix(), test_rig_check_dense_mesh()]
- "tests_test_sequence_vfx": "vfx()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L13 | neighbors=[test_sequence.py, test_a_blockout_sequence_needs_blockout…, test_blockout_lint_holds_recipes_to_mat…, test_detail_needs_the_blockout_gate_and…, test_game_frames_become_evidence_and_a_…, test_screen_feedback_is_validated()]
- "tests_test_sequence_workspace": "workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L28 | neighbors=[test_sequence.py, test_a_blockout_sequence_needs_blockout…, test_blockout_lint_holds_recipes_to_mat…, test_detail_needs_the_blockout_gate_and…, test_game_frames_become_evidence_and_a_…, test_screen_feedback_is_validated()]
- "tests_test_weather": "test_weather.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_weather.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _instances(), test_lightning_keys_strokes_and_bolt(), test_precipitation_loops_and_stops_on_g…, test_snow_geometry_and_vertex_mask()]
- "tools_math_determinism": "math_determinism.py" | kind=code-symbol | source=mute/tools/math_determinism.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, compare(), load_corpus(), load_trace(), main(), _object()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-021.json

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
