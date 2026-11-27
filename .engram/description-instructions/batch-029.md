# Node Description Batch 30 of 208

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

- "scripts_scanner_get_scanner_config": "get_scanner_config()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L36 | neighbors=[scanner.py, collect_target_files(), get_supported_extensions(), _identify_semantic_files(), perform_scan(), Loads the scanner configuration from sc…]
- "scripts_scanner_get_supported_extensions": "get_supported_extensions()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L55 | neighbors=[scanner.py, collect_target_files(), get_scanner_config(), _identify_semantic_files(), Returns a tuple of supported file exten…, _scan_single_file()]
- "scripts_sculpt_ops": "sculpt_ops.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-sculpting/scripts/sculpt_ops.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply(), _ctx(), run(), Headless-safe sculpt preparation and pr…]
- "scripts_sim_setup_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L82 | neighbors=[sim_setup.py, _asset_group(), _ctx(), _num(), _set_inputs(), _volume()]
- "scripts_smart_material_g_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L51 | neighbors=[build_group(), _G, .math(), .mix(), .mrange(), .noise()]
- "scripts_smart_material_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L275 | neighbors=[smart_material.py, _apply_mat(), build_group(), curvature_attribute(), _lin(), _remove_mat()]
- "scripts_template_engine_ifnode": "IfNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L72 | neighbors=[template_engine.py, compile_template(), .__init__(), .render(), Node, Represents conditional block logic (IF,…]
- "scripts_template_engine_textnode": "TextNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L46 | neighbors=[template_engine.py, compile_template(), Represents raw static text blocks., Node, .__init__(), .render()]
- "scripts_template_engine_varnode": "VarNode" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L56 | neighbors=[template_engine.py, compile_template(), Represents dynamic variable interpolati…, Node, .__init__(), .render()]
- "scripts_toon_setup_g_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L48 | neighbors=[build_group(), _G, .math(), .mix(), .step(), .vmath()]
- "scripts_track_camera": "track_camera.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _clip_area(), run(), _solve(), Automatic camera solve from footage: de…]
- "scripts_turntable_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L83 | neighbors=[turntable.py, _area(), _backdrop(), _bounds(), _clear(), _fcurves()]
- "scripts_uv_pack": "uv_pack.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _collapsed_ratio(), run(), _seams_from_sharp(), Unwrap + pack UVs with production defau…]
- "semantic_fold": "fold.cpp" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L1 | neighbors=[4cead55 Add MUT-27 bytecode verificatio…, eval_binary(), eval_compare(), eval_unary(), fold_constants(), int_scalar()]
- "skyrise_sky_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L111 | neighbors=[sky_map.py, look(), micro_detail(), rim_dress(), spawn_island(), zone_island()]
- "skyrise_sky_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L44 | neighbors=[sky_map.py, bridge_ends(), island_at(), Hm(), island_mesh(), path_track()]
- "skyrise_sky_map_island_mesh": "island_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L128 | neighbors=[sky_map.py, build(), H(), place(), rim(), sub()]
- "skyrise_sky_map_winding_path": "winding_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L181 | neighbors=[sky_map.py, stepping-stone path from the entry brid…, island_at(), place(), reserve(), zone_island()]
- "skyrise_sky_props_trophy": "trophy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L466 | neighbors=[sky_props.py, HERO: giant golden trophy on a tiered m…, gem(), lathe(), sphere(), torus()]
- "src_cbor_decode_item": "decode_item()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L94 | neighbors=[cbor.cpp, decode(), fail(), half_to_double(), read_argument(), valid_utf8()]
- "src_narrowphase_closest_on_hull": "closest_on_hull()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L168 | neighbors=[narrowphase.cpp, closest_segment(), closest_triangle(), dist_sq_of(), origin_in_tetra(), gjk_distance()]
- "src_pokomesh_parse_pokomesh": "parse_pokomesh()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L44 | neighbors=[pokomesh.cpp, load_pokomesh(), fail(), finite_vec3(), read_f32(), read_u32()]
- "stdlib_stdlib_string_valid_utf8": "valid_utf8()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L46 | neighbors=[stdlib_string.cpp, codepoint_count(), concat(), slice_codepoints(), to_lower_ascii(), decode()]
- "sugarworks_sugar_props_stripes": "stripes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L48 | neighbors=[sugar_props.py, candy_lamp(), collector(), exchange(), gate(), candy-cane tube: alternating colour seg…]
- "targets_run_dual_target_tests_run_command": "run_command()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L96 | neighbors=[run_dual_target_tests.py, adb_shell(), android_compile(), android_leg(), write_log(), windows_leg()]
- "targets_run_dual_target_tests_windows_leg": "windows_leg()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L173 | neighbors=[run_dual_target_tests.py, msvc_tools(), normalize_lf(), now(), run_command(), sha256()]
- "tests_test_agent_loop_frames": "frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L101 | neighbors=[test_agent_loop.py, plan: {frame: [(box, colour), ...]} wit…, test_review_metrics_accept_a_well_forme…, test_review_metrics_do_not_flag_known_f…, test_review_metrics_flag_off_peak_flash…, test_short_effect_with_an_empty_second_…]
- "tests_test_core": "test_core.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _run_md_blocks(), test_bpy_patterns_snippets_run(), test_env_report(), test_snippet_docs_across_skills()]
- "tests_test_environment": "test_environment.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_environment.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_kit_check_flags_and_fixes(), test_scatter_respects_slope_height_and_…, test_terrain_attributes_flatten_and_eng…, _trees()]
- "tests_test_export": "test_export.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_export.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _reimport_dims(), test_all_presets_roundtrip_scale(), test_batch_export_at_origin(), test_static_fbx_has_no_animation_take()]
- "tests_test_geonodes": "test_geonodes.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_build_apply_set_inputs(), test_describe(), test_reference_recipes_build_and_evalua…, test_repeat_zone()]
- "tests_test_golden_run": "run()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L12 | neighbors=[test_golden.py, .pair(), .test_incomplete_arguments_are_errors(), .test_update_creates_and_replaces_only_…, .test_update_missing_actual_preserves_e…, .test_update_same_path_refused()]
- "tests_test_mating_socket": "_socket()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L7 | neighbors=[test_mating.py, A 20 mm block sitting in a U socket who…, test_collision_fails(), test_good_fit_passes(), test_loose_fit_fails(), test_unheld_axis_reported()]
- "tests_test_modeling": "test_modeling.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_modeling.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_apply_keeps_shape_keys_and_handles…, test_hardsurface_snippet_attributes(), test_midpoly_stack_with_boolean_and_app…, test_subd_preset_adds_smooth_by_angle()]
- "tests_test_simulation": "test_simulation.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_simulation.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _grid(), test_classic_cloth_drapes_on_collider(), test_gn_cloth_52_asset(), test_rigid_body_drop_and_keys()]
- "tests_test_texturing": "test_texturing.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _stepped_block(), test_decal_conforms_without_zfighting(), test_smart_material_bakes_to_texture(), test_smart_material_curvature_and_round…]
- "towncity_town_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L96 | neighbors=[town_map.py, anchor_local(), build(), landmarks(), road_paths(), traffic()]
- "towncity_town_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L107 | neighbors=[town_map.py, build(), blocks(), flat(), static(), U()]
- "towncity_town_map_median": "median()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L164 | neighbors=[town_map.py, build(), flat(), static(), U(), boulevard median: raised planted strip …]
- "towncity_town_map_square": "square()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L175 | neighbors=[town_map.py, build(), Town Square: plaza paving rings round t…, flat(), static(), U()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-029.json

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
