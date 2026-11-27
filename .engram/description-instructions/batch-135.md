# Node Description Batch 136 of 208

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

- "tests_run_all_skill_module": "skill_module()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L22 | neighbors=[run_all.py, Import skills/<skill>/scripts/<script>.…]
- "tests_test_agent_loop_test_lint_accepts_a_cel_contact_and_a_restruck_painted_shape": "test_lint_accepts_a_cel_contact_and_a_restruck_painted_shape()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L65 | neighbors=[test_agent_loop.py, recipe()]
- "tests_test_agent_loop_test_lint_passes_the_library_and_reports_each_hard_rule": "test_lint_passes_the_library_and_reports_each_hard_rule()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L49 | neighbors=[test_agent_loop.py, recipe()]
- "tests_test_agent_loop_test_lint_warns_about_craft_problems": "test_lint_warns_about_craft_problems()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L78 | neighbors=[test_agent_loop.py, recipe()]
- "tests_test_agent_loop_test_review_metrics_accept_a_well_formed_effect": "test_review_metrics_accept_a_well_formed_effect()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L112 | neighbors=[test_agent_loop.py, frames()]
- "tests_test_agent_loop_test_review_metrics_do_not_flag_known_false_positives": "test_review_metrics_do_not_flag_known_false_positives()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L159 | neighbors=[test_agent_loop.py, frames()]
- "tests_test_agent_loop_test_review_metrics_flag_off_peak_flash_flat_colour_and_wrong_direction": "test_review_metrics_flag_off_peak_flash_flat_colour_and_wrong_direction()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L129 | neighbors=[test_agent_loop.py, frames()]
- "tests_test_agent_loop_test_short_effect_with_an_empty_second_half_is_a_dead_tail": "test_short_effect_with_an_empty_second_half_is_a_dead_tail()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L148 | neighbors=[test_agent_loop.py, frames()]
- "tests_test_animation_rig": "_rig()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L82 | neighbors=[test_animation.py, test_retarget_mixamo_to_rigify_names()]
- "tests_test_animation_test_bake_to_copy_with_root_motion_and_export": "test_bake_to_copy_with_root_motion_and_export()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L25 | neighbors=[test_animation.py, _walk()]
- "tests_test_animation_test_retarget_mixamo_to_rigify_names": "test_retarget_mixamo_to_rigify_names()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L105 | neighbors=[test_animation.py, _rig()]
- "tests_test_atmosphere_mean_luma": "_mean_luma()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L6 | neighbors=[test_atmosphere.py, _render()]
- "tests_test_atmosphere_test_night_renders_darker_than_noon": "test_night_renders_darker_than_noon()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L40 | neighbors=[test_atmosphere.py, _render()]
- "tests_test_baking_test_high_to_low_bake_normal_ao_curv_orm_basecolor": "test_high_to_low_bake_normal_ao_curv_orm_basecolor()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_baking.py:L16 | neighbors=[test_baking.py, _pixels()]
- "tests_test_baking_test_self_bake_procedural_roughness": "test_self_bake_procedural_roughness()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_baking.py:L41 | neighbors=[test_baking.py, _pixels()]
- "tests_test_core_test_bpy_patterns_snippets_run": "test_bpy_patterns_snippets_run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L25 | neighbors=[test_core.py, _run_md_blocks()]
- "tests_test_effekseer_ai_test_editor_bin_directory_requires_an_explicit_configuration": "test_editor_bin_directory_requires_an_explicit_configuration()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L30 | neighbors=[test_effekseer_ai.py, A public release must never probe a con…]
- "tests_test_environment_test_scatter_respects_slope_height_and_realize": "test_scatter_respects_slope_height_and_realize()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_environment.py:L54 | neighbors=[test_environment.py, _trees()]
- "tests_test_environment_trees": "_trees()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_environment.py:L41 | neighbors=[test_environment.py, test_scatter_respects_slope_height_and_…]
- "tests_test_examples_test_catalog_lists_every_shipped_example_as_pairs_singles_and_sets": "test_catalog_lists_every_shipped_example_as_pairs_singles_and_sets()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L16 | neighbors=[test_examples.py, example_ids()]
- "tests_test_examples_test_lint_of_all_examples_has_no_errors": "test_lint_of_all_examples_has_no_errors()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L66 | neighbors=[test_examples.py, example_ids()]
- "tests_test_export_reimport_dims": "_reimport_dims()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_export.py:L8 | neighbors=[test_export.py, test_all_presets_roundtrip_scale()]
- "tests_test_export_test_all_presets_roundtrip_scale": "test_all_presets_roundtrip_scale()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_export.py:L22 | neighbors=[test_export.py, _reimport_dims()]
- "tests_test_golden_goldenharnesstests_test_binary_match": ".test_binary_match()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L26 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_binary_mismatch_does_not_update_reference": ".test_binary_mismatch_does_not_update_reference()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L33 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_chunk_boundary": ".test_chunk_boundary()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L62 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_different_lengths_and_empty_files": ".test_different_lengths_and_empty_files()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L53 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_incomplete_arguments_are_errors": ".test_incomplete_arguments_are_errors()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L103 | neighbors=[GoldenHarnessTests, run()]
- "tests_test_golden_goldenharnesstests_test_missing_file_is_error": ".test_missing_file_is_error()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L70 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_png_match": ".test_png_match()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L42 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_png_mismatch": ".test_png_mismatch()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L48 | neighbors=[GoldenHarnessTests, .pair()]
- "tests_test_golden_goldenharnesstests_test_update_missing_actual_preserves_existing_reference": ".test_update_missing_actual_preserves_existing_reference()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L96 | neighbors=[GoldenHarnessTests, run()]
- "tests_test_golden_goldenharnesstests_test_update_same_path_refused": ".test_update_same_path_refused()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L89 | neighbors=[GoldenHarnessTests, run()]
- "tests_test_hair_test_groom_attached_masked_with_assets": "test_groom_attached_masked_with_assets()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_hair.py:L15 | neighbors=[test_hair.py, _head()]
- "tests_test_hair_test_hair_cards_and_atlas": "test_hair_cards_and_atlas()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_hair.py:L29 | neighbors=[test_hair.py, _head()]
- "tests_test_materials_img": "_img()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_materials.py:L6 | neighbors=[test_materials.py, test_texture_set_autowire_orm_dx_normal…]
- "tests_test_materials_test_texture_set_autowire_orm_dx_normal": "test_texture_set_autowire_orm_dx_normal()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_materials.py:L16 | neighbors=[test_materials.py, _img()]
- "tests_test_mating_rationale_8": "A 20 mm block sitting in a U socket whose opening is `gap` wide." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_mating.py:L8 | neighbors=[MatingError, _socket()]
- "tests_test_mating_test_collision_fails": "test_collision_fails()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L28 | neighbors=[test_mating.py, _socket()]
- "tests_test_mating_test_good_fit_passes": "test_good_fit_passes()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L24 | neighbors=[test_mating.py, _socket()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-135.json

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
