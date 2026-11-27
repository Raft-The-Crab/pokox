# Node Description Batch 31 of 209

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
- "unit_camera_test": "camera_test.cpp" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), near(), transform(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_determinism_test": "determinism_test.cpp" | kind=code-symbol | source=mute/tests/unit/determinism_test.cpp:L1 | neighbors=[037434c Add MUT-24 determinism and capa…, 952997e Audit MUT-01-55 and harden veri…, cases(), error(), main(), ok()]
- "unit_device_router_test_event": "event()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L18 | neighbors=[device_router_test.cpp, connect(), disconnect(), pad_axis(), pad_button(), touch_tap()]
- "unit_diff_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L85 | neighbors=[diff_test.cpp, check(), compile(), diff_case(), total_words(), main()]
- "unit_diff_test_diff_case": "diff_case()" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L66 | neighbors=[diff_test.cpp, cases(), check(), compile(), run(), same_result()]
- "unit_emit_test_select_module": "select_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L70 | neighbors=[emit_test.cpp, cases(), position_cases(), i32(), pv(), v()]
- "unit_fixed_vec_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_vec_test.cpp:L51 | neighbors=[fixed_vec_test.cpp, len_d(), naive_dot(), naive_in_range(), raw3(), v3()]
- "unit_run_seed_checks": "run_seed_checks.py" | kind=code-symbol | source=engine/rhi/tests/unit/run_seed_checks.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, run(), Portable GCC/Clang-compatible seed chec…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_stdlib_crypto_test": "stdlib_crypto_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L1 | neighbors=[60d8044 Mute crypto hostcalls: fail exp…, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, bytes(), digest_is(), main()]
- "valleylake_paint_paint_block": "paint_block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L50 | neighbors=[paint.py, atlas(), cracks(), fnoise(), _hex(), stamps()]
- "valleylake_valley_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L227 | neighbors=[valley_map.py, build_solid(), cliffs(), look(), nature(), shore()]
- "valleylake_valley_map_lake_d": "lake_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L53 | neighbors=[valley_map.py, H0(), lake_R(), nature(), preview_water(), signed distance-ish to the shore (negat…]
- "valleylake_valley_map_lake_r": "lake_R()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L47 | neighbors=[valley_map.py, lake_d(), lake_poly(), nature(), shore radius around LAKE_C by angle (th…, shore()]
- "valleylake_valley_map_rim_point": "rim_point()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L427 | neighbors=[valley_map.py, build_profile(), cliff_mesh(), cliffs(), point on the rim superellipse at angle …, rim_r()]
- "valleylake_valley_map_rim_r": "rim_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L424 | neighbors=[valley_map.py, build_profile(), cliffs(), foot_need(), polar(), rim_point()]
- "valleylake_valley_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L345 | neighbors=[valley_map.py, build(), lake = fan disc a little past the shore…, lake_poly(), static(), wlevel()]
- "valleylake_valley_props_footing": "footing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L492 | neighbors=[valley_props.py, rounded_mass(), .add(), V(), house(), rounded fieldstone footing course under…]
- "valleylake_valley_props_gable_roof": "gable_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L406 | neighbors=[valley_props.py, .add(), V(), house(), market_stall(), straight gable roof (ridge along X): tw…]
- "valleylake_valley_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L264 | neighbors=[valley_props.py, .add(), trunk(), V(), soft full conifer: tapered skinned trun…, tall stylised pine: straight trunk, 8 t…]
- "valleylake_valley_props_skel_grow": ".grow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L869 | neighbors=[broadleaf(), gnarled_tree(), limb from node `parent` along d (curvin…, Skel, lerp(), .add()]
- "valleylake_valley_props_timber_wall": "timber_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L457 | neighbors=[valley_props.py, house(), wall in XY facing -Z: dark timber posts…, flat(), quad(), .add()]
- "vfxkit_build_check_resource_conflicts": "check_resource_conflicts()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L71 | neighbors=[build.py, build(), eid(), owned(), resource_names(), Refuse to replace a resources/ file wit…]
- "vfxkit_doctor": "doctor.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/doctor.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, doctor(), setup_python(), version(), What this machine can do right now. Sta…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-030.json

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
