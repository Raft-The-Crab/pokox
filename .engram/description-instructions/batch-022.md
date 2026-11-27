# Node Description Batch 23 of 208

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

- "src_narrowphase_collide": "collide()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L672 | neighbors=[narrowphase.cpp, aabb_of(), collide_local(), local_extent(), local_shape(), to_world()]
- "state_state_snapshot": "state_snapshot.cpp" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, append_le(), load_state_snapshot(), read_le(), save_state_snapshot(), schema_for()]
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
- "towncity_city_paint_clip": "clip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L130 | neighbors=[city_paint.py, edge(), paint_glass(), ramp(), polygon (list of Vector) clipped to lo …, remap()]
- "towncity_town_landmarks_clock_tower": "clock_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L170 | neighbors=[town_landmarks.py, arch_open(), clock_face(), cslab(), _merge(), T_point()]
- "towncity_town_map_flat": "flat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L105 | neighbors=[town_map.py, U(), ground(), markings(), median(), square()]
- "towncity_town_map_traffic": "traffic()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L466 | neighbors=[town_map.py, build(), parked cars along curbs + a few cars in…, anchor(), near_intersection(), place()]
- "towncity_town_props_deco_window": "deco_window()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L247 | neighbors=[town_props.py, building(), add(), front_quad(), ring_frame(), slab()]
- "towncity_town_props_fire_escape": "fire_escape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L463 | neighbors=[town_props.py, building(), add(), lerp(), slab(), V3()]
- "towncity_town_props_front_quad": "front_quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L100 | neighbors=[town_props.py, building(), deco_window(), quad(), a single quad facing -Z at depth z, shopfront()]
- "towncity_town_props_shopfront": "shopfront()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L264 | neighbors=[town_props.py, building(), ground floor front: pilasters, bulkhead…, add(), awning_band(), front_quad()]
- "towncity_town_props_slab": "slab()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L53 | neighbors=[town_props.py, building(), deco_window(), fire_escape(), holed_front(), axis box between the given bounds; drop…]
- "towncity_town_props_v3": "V3()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L47 | neighbors=[town_props.py, awning_band(), fire_escape(), flower(), flower_box(), ring_frame()]
- "towncity_town_vehicles_car": "car()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L53 | neighbors=[town_vehicles.py, body_shader(), body_shell(), _smoothstep(), taxi(), wheels()]
- "unit_capability_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L60 | neighbors=[capability_test.cpp, ceiling(), check(), def(), narrowed_module(), run_err()]
- "unit_character_controller_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L120 | neighbors=[character_controller_test.cpp, aabb(), params(), tod(), todv(), v3()]
- "unit_debugger_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L20 | neighbors=[debugger_test.cpp, arith(), check(), divzero(), imm(), pay()]
- "unit_fold_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L41 | neighbors=[fold_test.cpp, check(), count_op(), i32t(), run_source(), val()]
- "unit_imgui_pass_faults": "imgui_pass_faults.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, FakeShader(), GetEngineFactoryVk(), main(), reset(), write_spirv()]
- "unit_input_snapshot_test_record_hashes": "record_hashes()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L43 | neighbors=[input_snapshot_test.cpp, main(), button(), key(), motion(), simple()]
- "unit_lexer_test": "lexer_test.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, check(), error(), main(), test_cases(), unicode_conformance()]
- "unit_pokomesh_test": "pokomesh_test.cpp" | kind=code-symbol | source=engine/resource/tests/unit/pokomesh_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), make_pmes(), put32(), putf(), write()]
- "unit_solver_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L49 | neighbors=[solver_test.cpp, body(), contact(), fx(), statics(), tod()]
- "unit_ssa_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L28 | neighbors=[ssa_test.cpp, check(), has(), i32(), v(), valid_module()]
- "unit_stdlib_math_test": "stdlib_math_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 5eb3f50 Mute det_pow: integer-exponent …, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, main(), near()]
- "unit_values_test": "values_test.cpp" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L1 | neighbors=[5edd00c Fix MUT-21/22 audit defects in …, 964ba8a Resolve MUT-22 values runtime l…, e685cdf Add MUT-22 aggregate VM value a…, cases(), check(), main()]
- "unit_vulkan_mesh_pass_test": "vulkan_mesh_pass_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, draw_and_present(), main(), messages(), VulkanClearRenderer(), VulkanDiagnostics()]
- "valleylake_valley_map_build_profile": "build_profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L490 | neighbors=[valley_map.py, build(), foot_need(), H(), rim_point(), rim_r()]
- "valleylake_valley_map_cliff_clear": "cliff_clear()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L558 | neighbors=[valley_map.py, H(), prof(), cliffs(), clip_fail(), nature()]
- "valleylake_valley_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L239 | neighbors=[valley_map.py, build(), H(), polar(), prof(), rim_s()]
- "valleylake_valley_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L206 | neighbors=[valley_map.py, build(), clip_fail(), place(), surface_y(), unplace()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-022.json

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
