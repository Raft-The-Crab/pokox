# Node Description Batch 30 of 207

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

- "src_cbor_decode_item": "decode_item()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L94 | neighbors=[cbor.cpp, decode(), fail(), half_to_double(), read_argument(), valid_utf8()]
- "src_narrowphase_closest_on_hull": "closest_on_hull()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L168 | neighbors=[narrowphase.cpp, closest_segment(), closest_triangle(), dist_sq_of(), origin_in_tetra(), gjk_distance()]
- "src_pokomesh_parse_pokomesh": "parse_pokomesh()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L44 | neighbors=[pokomesh.cpp, load_pokomesh(), fail(), finite_vec3(), read_f32(), read_u32()]
- "state_state_snapshot": "state_snapshot.cpp" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, append_le(), load_state_snapshot(), read_le(), save_state_snapshot(), schema_for()]
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
- "towncity_town_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L91 | neighbors=[town_map.py, ground(), markings(), median(), square(), sub()]
- "towncity_town_props_flower_box": "flower_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L188 | neighbors=[town_props.py, add(), blob(), flower(), V3(), window_unit()]
- "towncity_town_props_ring_frame": "ring_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L75 | neighbors=[town_props.py, building(), deco_window(), flat rectangular frame ring in the XY p…, V3(), window_unit()]
- "towncity_town_vehicles_bus": "bus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L101 | neighbors=[town_vehicles.py, body_shader(), body_shell(), _smoothstep(), wheels(), city bus: lofted box body, raked windsc…]
- "unit_bench_test_bench": "bench()" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L59 | neighbors=[bench_test.cpp, best_ns(), check(), compile(), run(), cases()]
- "unit_determinism_test": "determinism_test.cpp" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L1 | neighbors=[037434c Add MUT-24 determinism and capa…, 952997e Audit MUT-01-55 and harden veri…, cases(), error(), main(), ok()]
- "unit_device_router_test_event": "event()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L18 | neighbors=[device_router_test.cpp, connect(), disconnect(), pad_axis(), pad_button(), touch_tap()]
- "unit_diff_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L85 | neighbors=[diff_test.cpp, check(), compile(), diff_case(), total_words(), main()]
- "unit_diff_test_diff_case": "diff_case()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L66 | neighbors=[diff_test.cpp, cases(), check(), compile(), run(), same_result()]
- "unit_emit_test_select_module": "select_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L70 | neighbors=[emit_test.cpp, cases(), position_cases(), i32(), pv(), v()]
- "unit_fixed_vec_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L51 | neighbors=[fixed_vec_test.cpp, len_d(), naive_dot(), naive_in_range(), raw3(), v3()]
- "unit_imgui_pass_faults": "imgui_pass_faults.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, FakeShader(), GetEngineFactoryVk(), main(), reset(), write_spirv()]
- "unit_lexer_test": "lexer_test.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, check(), error(), main(), test_cases(), unicode_conformance()]
- "unit_pokomesh_test": "pokomesh_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main(), make_pmes(), put32(), putf(), write()]
- "unit_stdlib_crypto_test": "stdlib_crypto_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L1 | neighbors=[60d8044 Mute crypto hostcalls: fail exp…, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, bytes(), digest_is(), main()]
- "unit_vulkan_mesh_pass_test": "vulkan_mesh_pass_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, draw_and_present(), main(), messages(), VulkanClearRenderer(), VulkanDiagnostics()]
- "valleylake_paint_paint_block": "paint_block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L50 | neighbors=[paint.py, atlas(), cracks(), fnoise(), _hex(), stamps()]
- "valleylake_valley_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L227 | neighbors=[valley_map.py, build_solid(), cliffs(), look(), nature(), shore()]

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
