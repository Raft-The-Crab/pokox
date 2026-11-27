# Node Description Batch 56 of 208

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

- "src_character_controller_spheres_disjoint": "spheres_disjoint()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L67 | neighbors=[character_controller.cpp, deepest_contact(), touches_uncached(), update()]
- "src_character_controller_touches_uncached": "touches_uncached()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L74 | neighbors=[character_controller.cpp, touches(), shape_bound(), spheres_disjoint()]
- "src_frame_stats_window_mean": "window_mean()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L8 | neighbors=[frame_stats.cpp, cpu_ms(), fps(), gpu_ms()]
- "src_narrowphase_closest_triangle": "closest_triangle()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L86 | neighbors=[narrowphase.cpp, closest_on_hull(), closest_segment(), dist_sq_of()]
- "src_narrowphase_collide_local": "collide_local()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L701 | neighbors=[narrowphase.cpp, collide(), epa_penetration(), gjk_distance()]
- "src_soft_body_add_spring": "add_spring()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L82 | neighbors=[soft_body.cpp, clamp01(), create(), create_lattice()]
- "src_visual_solver_add_body": "add_body()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L346 | neighbors=[visual_solver.cpp, find_body(), upsert_body(), add_collider()]
- "stdlib_stdlib_crypto_hmac_sha256": "hmac_sha256()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L73 | neighbors=[stdlib_crypto.cpp, sha256(), sign_detached(), verify_detached()]
- "stdlib_stdlib_crypto_sha256": "sha256()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L56 | neighbors=[stdlib_crypto.cpp, hmac_sha256(), append_u32_be(), compress()]
- "stdlib_stdlib_string_decode": "decode()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L11 | neighbors=[stdlib_string.cpp, codepoint_count(), slice_codepoints(), valid_utf8()]
- "sugarworks_sugar_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L157 | neighbors=[sugar_map.py, face(), place(), plot()]
- "sugarworks_sugar_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L18 | neighbors=[sugar_map.py, ground(), horizon(), place()]
- "sugarworks_sugar_props_candy_lamp": "candy_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L251 | neighbors=[sugar_props.py, stripes(), subdiv_line(), candy-cane street lamp: striped post, h…]
- "sugarworks_sugar_props_choc_fountain": "choc_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L390 | neighbors=[sugar_props.py, sphere(), torus(), three-tier chocolate fountain: pink bow…]
- "sugarworks_sugar_props_sphere": "sphere()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L41 | neighbors=[sugar_props.py, choc_fountain(), conveyor(), exchange()]
- "targets_run_dual_target_tests_android_compile": "android_compile()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L234 | neighbors=[run_dual_target_tests.py, run_command(), sha256(), android_leg()]
- "targets_run_dual_target_tests_now": "now()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L87 | neighbors=[run_dual_target_tests.py, android_leg(), main(), windows_leg()]
- "targets_run_dual_target_tests_sha256": "sha256()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L122 | neighbors=[run_dual_target_tests.py, android_compile(), android_leg(), windows_leg()]
- "tests_fixtures_cube": "cube()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L19 | neighbors=[fixtures.py, mesh_object(), detached_part(), street()]
- "tests_fixtures_detached_part": "detached_part()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L46 | neighbors=[fixtures.py, cube(), mesh_object(), A body with a floating island and a sep…]
- "tests_fixtures_street": "street()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L67 | neighbors=[fixtures.py, Ground slab (top at z=0), two buildings…, cube(), uv_sphere()]
- "tests_fixtures_zfight_pair": "zfight_pair()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L33 | neighbors=[fixtures.py, Two coplanar overlapping planes in diff…, mesh_object(), plane()]
- "tests_test_agent_loop_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L41 | neighbors=[test_agent_loop.py, test_lint_accepts_a_cel_contact_and_a_r…, test_lint_passes_the_library_and_report…, test_lint_warns_about_craft_problems()]
- "tests_test_clothing": "test_clothing.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_clothing.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_garment_morphs_and_drape(), test_garment_weights_mask_and_pose()]
- "tests_test_core_run_md_blocks": "_run_md_blocks()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L11 | neighbors=[test_core.py, Execute every ```python block of a refe…, test_bpy_patterns_snippets_run(), test_snippet_docs_across_skills()]
- "tests_test_golden": "test_golden.py" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, GoldenHarnessTests, run(), c7a411f Fix MUT-01-20 audit defects in …]
- "tests_test_gridfinity_test_compartments_scoop_label": "test_compartments_scoop_label()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L62 | neighbors=[test_gridfinity.py, _assert_footprint(), _mesh(), _volume()]
- "tests_test_gridfinity_test_minimal_bin_no_lip": "test_minimal_bin_no_lip()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L40 | neighbors=[test_gridfinity.py, 1x1, 2U, no lip: exact box height, flat…, _assert_footprint(), _mesh()]
- "tests_test_npr_bands": "_bands()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L38 | neighbors=[test_npr.py, _clusters(), test_toon_hull_bands_lineart_roundtrip(), test_toon_scene_lighting_eevee()]
- "tests_test_optimization": "test_optimization.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_optimization.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_lods_halve_and_cleanup(), test_mesh_stats_budget()]
- "tests_test_privacy_png_metadata": "png_metadata()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L82 | neighbors=[test_privacy.py, file_hits(), Names of PNG chunks beyond pixel data (…, test_scanner_catches_each_kind_of_leak_…]
- "tests_test_privacy_test_no_file_in_the_package_leaks_personal_machine_or_secret_data": "test_no_file_in_the_package_leaks_personal_machine_or_secret_data()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L154 | neighbors=[test_privacy.py, file_hits(), files(), private_terms()]
- "tests_test_scene": "test_scene.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_scene.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_collection_exporter_snippet(), test_scene_audit_flags_and_fixes()]
- "tests_test_stl_to_3mf": "test_stl_to_3mf.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_stl_to_3mf.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_convert_happy_path(), test_convert_missing_file()]
- "tests_test_texturing_stepped_block": "_stepped_block()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L7 | neighbors=[test_texturing.py, 1 m block with a 0.5 m step on top (con…, test_smart_material_bakes_to_texture(), test_smart_material_curvature_and_round…]
- "tests_test_workflow_report": "report()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L97 | neighbors=[test_workflow.py, test_completion_requires_brief_review_a…, test_independent_report_binds_images_sc…, test_review_handoff_gives_a_reviewer_ev…]
- "texture_tex_to_maps_blur": "blur()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L37 | neighbors=[tex_to_maps.py, derive_ao(), high_pass(), Box blur via integral image. O(1) per p…]
- "texture_tex_to_maps_derive_ao": "derive_ao()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L86 | neighbors=[tex_to_maps.py, blur(), process(), Cavity estimate: pixels darker than the…]
- "texture_tex_to_maps_high_pass": "high_pass()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L57 | neighbors=[tex_to_maps.py, blur(), process(), Luminance minus its local mean: the det…]
- "texture_tile_seam_check_assess": "assess()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L73 | neighbors=[tile_seam_check.py, boundary_metrics(), load_gray(), main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-055.json

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
