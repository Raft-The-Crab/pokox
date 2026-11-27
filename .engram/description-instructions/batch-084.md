# Node Description Batch 85 of 209

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
For an entity node (any other kind — e.g. a person, place, event, object),
describe what the entity is and its role, grounded in its type, its
relations (neighbors) and the provided citations/evidence — e.g.
"Lady Carfax, a wealthy heiress who disappears en route to Lausanne.".
Ground entity descriptions in the citations/evidence when present; do not
speculate beyond the context, so a node with no supporting context may be
left out of the reply.
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "stdlib_stdlib_math_vec3_length_squared": "vec3_length_squared()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L78 | neighbors=[stdlib_math.cpp, vec3_dot(), vec3_normalize()]
- "stdlib_stdlib_math_vec3_normalize": "vec3_normalize()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L79 | neighbors=[stdlib_math.cpp, det_sqrt(), vec3_length_squared()]
- "stdlib_stdlib_math_vec4_normalize": "vec4_normalize()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L89 | neighbors=[stdlib_math.cpp, det_sqrt(), vec4_dot()]
- "stdlib_stdlib_physics_physics_hostcall_defs": "physics_hostcall_defs()" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L82 | neighbors=[stdlib_physics.cpp, fixed_from_raw(), physics_raycast()]
- "stdlib_stdlib_physics_physics_raycast": "physics_raycast()" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L36 | neighbors=[stdlib_physics.cpp, physics_hostcall_defs(), touching_at()]
- "stdlib_stdlib_string_codepoint_count": "codepoint_count()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L58 | neighbors=[stdlib_string.cpp, decode(), valid_utf8()]
- "stdlib_stdlib_string_slice_codepoints": "slice_codepoints()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L66 | neighbors=[stdlib_string.cpp, decode(), valid_utf8()]
- "sugarworks_sugar_kit_sheet": "sugar_kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "sugarworks_sugar_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L48 | neighbors=[sugar_map.py, build(), plot()]
- "sugarworks_sugar_map_local": "local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L49 | neighbors=[sugar_map.py, plot(), plot-local (lx, lz) -> world; local -Z …]
- "sugarworks_sugar_props_buy_button": "buy_button()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L192 | neighbors=[sugar_props.py, torus(), button on a squat base with a price boa…]
- "sugarworks_sugar_props_coin_chute": "coin_chute()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L355 | neighbors=[sugar_props.py, torus(), pipe from the collector's side (origin)…]
- "sugarworks_sugar_props_conveyor": "conveyor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L131 | neighbors=[sugar_props.py, sphere(), belt segment along X: legs, dark belt w…]
- "sugarworks_sugar_props_lollipop_tree": "lollipop_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L224 | neighbors=[sugar_props.py, dome(), torus()]
- "sugarworks_sugar_props_upgrader": "upgrader()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L151 | neighbors=[sugar_props.py, scanner arch over the belt: two steel p…, torus()]
- "targets_android_std_shim": "android_std_shim.hpp" | kind=code-symbol | source=tools/targets/android_std_shim.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, bit_cast(), from_chars()]
- "targets_run_dual_target_tests_adb_shell": "adb_shell()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L220 | neighbors=[run_dual_target_tests.py, run_command(), android_leg()]
- "targets_run_dual_target_tests_normalize_lf": "normalize_lf()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L118 | neighbors=[run_dual_target_tests.py, android_leg(), windows_leg()]
- "tests_dependency_smoke": "dependency_smoke.cpp" | kind=code-symbol | source=engine/foundation/tests/dependency_smoke.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "tests_fixtures_plane": "plane()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L28 | neighbors=[fixtures.py, mesh_object(), zfight_pair()]
- "tests_fixtures_simple_character": "simple_character()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L88 | neighbors=[fixtures.py, Capsule-ish mesh + 3-bone chain armatur…, mesh_object()]
- "tests_fixtures_uv_sphere": "uv_sphere()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L23 | neighbors=[fixtures.py, street(), mesh_object()]
- "tests_run_all_requires_gpu": "requires_gpu()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L43 | neighbors=[run_all.py, Skip when BAS_SKIP_GPU=1 (CI runners wi…, Skip]
- "tests_run_all_skip": "Skip" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L39 | neighbors=[run_all.py, requires_gpu(), Exception]
- "tests_test_addon": "test_addon.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_addon.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_template_validates_builds_and_regi…]
- "tests_test_animation_walk": "_walk()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L8 | neighbors=[test_animation.py, Keyframe the hips ('spine', child of ro…, test_bake_to_copy_with_root_motion_and_…]
- "tests_test_atmosphere_render": "_render()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L13 | neighbors=[test_atmosphere.py, _mean_luma(), test_night_renders_darker_than_noon()]
- "tests_test_baking_pixels": "_pixels()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_baking.py:L9 | neighbors=[test_baking.py, test_high_to_low_bake_normal_ao_curv_or…, test_self_bake_procedural_roughness()]
- "tests_test_core_test_snippet_docs_across_skills": "test_snippet_docs_across_skills()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L35 | neighbors=[test_core.py, Any reference doc tagged '(runs standal…, _run_md_blocks()]
- "tests_test_examples_example_ids": "example_ids()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L12 | neighbors=[test_examples.py, test_catalog_lists_every_shipped_exampl…, test_lint_of_all_examples_has_no_errors…]
- "tests_test_facial": "test_facial.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_facial.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_arkit_split_mirror_drivers_report()]
- "tests_test_golden_goldenharnesstests_test_update_creates_and_replaces_only_when_explicit": ".test_update_creates_and_replaces_only_when_explicit()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L75 | neighbors=[GoldenHarnessTests, .pair(), run()]
- "tests_test_gridfinity_rationale_124": "Rebuild the published D110 cradle; dimensions must match." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L124 | neighbors=[GridfinityBin, GridfinityError, test_d110_regression()]
- "tests_test_gridfinity_rationale_25": "B-rep volume, no tessellation round-trip." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L25 | neighbors=[GridfinityBin, GridfinityError, _volume()]
- "tests_test_gridfinity_rationale_41": "1x1, 2U, no lip: exact box height, flat top." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L41 | neighbors=[GridfinityBin, GridfinityError, test_minimal_bin_no_lip()]
- "tests_test_gridfinity_rationale_49": "2x1, 3U with lip and base holes." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L49 | neighbors=[GridfinityBin, GridfinityError, test_bin_with_lip_magnets_screws()]
- "tests_test_gridfinity_test_d110_regression": "test_d110_regression()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L123 | neighbors=[test_gridfinity.py, Rebuild the published D110 cradle; dime…, _mesh()]
- "tests_test_gridfinity_test_finger_notch_removes_material": "test_finger_notch_removes_material()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L103 | neighbors=[test_gridfinity.py, _mesh(), _volume()]
- "tests_test_gridfinity_test_polygon_pocket_with_clearance_and_cylinder_well": "test_polygon_pocket_with_clearance_and_cylinder_well()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L74 | neighbors=[test_gridfinity.py, _assert_footprint(), _mesh()]
- "tests_test_hair_head": "_head()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_hair.py:L7 | neighbors=[test_hair.py, test_groom_attached_masked_with_assets(), test_hair_cards_and_atlas()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-084.json

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
