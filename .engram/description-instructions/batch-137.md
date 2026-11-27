# Node Description Batch 138 of 209

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

- "tests_test_materials_img": "_img()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_materials.py:L6 | neighbors=[test_materials.py, test_texture_set_autowire_orm_dx_normal…]
- "tests_test_materials_test_texture_set_autowire_orm_dx_normal": "test_texture_set_autowire_orm_dx_normal()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_materials.py:L16 | neighbors=[test_materials.py, _img()]
- "tests_test_mating_rationale_8": "A 20 mm block sitting in a U socket whose opening is `gap` wide." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_mating.py:L8 | neighbors=[MatingError, _socket()]
- "tests_test_mating_test_collision_fails": "test_collision_fails()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L28 | neighbors=[test_mating.py, _socket()]
- "tests_test_mating_test_good_fit_passes": "test_good_fit_passes()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L24 | neighbors=[test_mating.py, _socket()]
- "tests_test_mating_test_loose_fit_fails": "test_loose_fit_fails()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L33 | neighbors=[test_mating.py, _socket()]
- "tests_test_mating_test_unheld_axis_reported": "test_unheld_axis_reported()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L38 | neighbors=[test_mating.py, _socket()]
- "tests_test_mesh_io_test_load_mesh_no_pyrender_import": "test_load_mesh_no_pyrender_import()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L24 | neighbors=[test_mesh_io.py, mesh_io must not pull in pyrender (it's…]
- "tests_test_package_system_python": "system_python()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L22 | neighbors=[test_package.py, test_doctor_runs_through_the_wrapper_on…]
- "tests_test_package_test_a_fresh_project_lints_a_recipe_that_uses_primitive_default_textures": "test_a_fresh_project_lints_a_recipe_that_uses_primitive_default_textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L264 | neighbors=[test_package.py, vfx()]
- "tests_test_package_test_cli_init_examples_and_lint_in_a_fresh_project": "test_cli_init_examples_and_lint_in_a_fresh_project()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L99 | neighbors=[test_package.py, vfx()]
- "tests_test_package_test_doctor_reports_an_initialised_workspace": "test_doctor_reports_an_initialised_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L88 | neighbors=[test_package.py, vfx()]
- "tests_test_package_test_doctor_runs_through_the_wrapper_on_a_bare_system_python": "test_doctor_runs_through_the_wrapper_on_a_bare_system_python()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L30 | neighbors=[test_package.py, system_python()]
- "tests_test_package_test_effect_verify_reports_missing_evidence_and_fails": "test_effect_verify_reports_missing_evidence_and_fails()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L159 | neighbors=[test_package.py, vfx()]
- "tests_test_package_test_examples_add_does_not_overwrite_without_force": "test_examples_add_does_not_overwrite_without_force()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L122 | neighbors=[test_package.py, vfx()]
- "tests_test_package_test_examples_list_and_show_without_a_workspace": "test_examples_list_and_show_without_a_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L141 | neighbors=[test_package.py, vfx()]
- "tests_test_package_test_rubric_and_layer_schema_commands": "test_rubric_and_layer_schema_commands()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L152 | neighbors=[test_package.py, vfx()]
- "tests_test_privacy_attribution_allowed": "attribution_allowed()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L55 | neighbors=[test_privacy.py, text_hits()]
- "tests_test_privacy_files": "files()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L42 | neighbors=[test_privacy.py, test_no_file_in_the_package_leaks_perso…]
- "tests_test_privacy_publisher_allowed": "publisher_allowed()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L48 | neighbors=[test_privacy.py, text_hits()]
- "tests_test_privacy_test_maintainer_private_terms_when_configured": "test_maintainer_private_terms_when_configured()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L163 | neighbors=[test_privacy.py, private_terms()]
- "tests_test_qa_test_clean_cube_passes": "test_clean_cube_passes()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L13 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_detects_floating_parts_and_objects": "test_detects_floating_parts_and_objects()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L41 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_detects_inverted_and_inconsistent_normals_and_back_to_back": "test_detects_inverted_and_inconsistent_normals_and_back_to_back()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L63 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_detects_zfighting_between_objects_and_within_mesh": "test_detects_zfighting_between_objects_and_within_mesh()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L22 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_enclosed_part_is_not_floating": "test_enclosed_part_is_not_floating()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L56 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_mirrored_object_is_not_inside_out_and_empty_mesh_is_flagged": "test_mirrored_object_is_not_inside_out_and_empty_mesh_is_flagged()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L172 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_roblox_profile_flags_open_mesh_and_ngons": "test_roblox_profile_flags_open_mesh_and_ngons()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L112 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_slightly_offset_coplanar_is_zfighting_but_far_is_not": "test_slightly_offset_coplanar_is_zfighting_but_far_is_not()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L31 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_small_part_far_from_origin_is_not_inside_out": "test_small_part_far_from_origin_is_not_inside_out()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L86 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_stacked_uvs_are_overlap_and_stay_cheap": "test_stacked_uvs_are_overlap_and_stay_cheap()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L94 | neighbors=[test_qa.py, _qa()]
- "tests_test_qa_test_touching_parts_are_not_floating": "test_touching_parts_are_not_floating()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L48 | neighbors=[test_qa.py, _qa()]
- "tests_test_rendering_camera": "_camera()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rendering.py:L8 | neighbors=[test_rendering.py, test_render_stills_cycles_eevee_workben…]
- "tests_test_rendering_test_render_stills_cycles_eevee_workbench": "test_render_stills_cycles_eevee_workbench()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rendering.py:L16 | neighbors=[test_rendering.py, _camera()]
- "tests_test_rigging_test_bind_tiny_and_huge_rigs_get_real_weights": "test_bind_tiny_and_huge_rigs_get_real_weights()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L73 | neighbors=[test_rigging.py, Bone heat fails at mm/km world sizes (a…]
- "tests_test_rigging_test_rig_check_dense_mesh": "test_rig_check_dense_mesh()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L54 | neighbors=[test_rigging.py, Issue #11: >= 4000 verts makes the symm…]
- "tests_test_rigging_test_rigify_pipeline_bind_check_stress": "test_rigify_pipeline_bind_check_stress()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L20 | neighbors=[test_rigging.py, _humanoid_mesh()]
- "tests_test_run_wrapper_test_bad_script_traceback": "test_bad_script_traceback()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L46 | neighbors=[test_run_wrapper.py, run()]
- "tests_test_run_wrapper_test_bed_empty_string_is_usage_error": "test_bed_empty_string_is_usage_error()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L114 | neighbors=[test_run_wrapper.py, run()]
- "tests_test_run_wrapper_test_bed_fits": "test_bed_fits()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L82 | neighbors=[test_run_wrapper.py, run()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-137.json

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
