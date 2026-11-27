# Node Description Batch 191 of 207

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
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "tests_test_mesh_io_rationale_25": "mesh_io must not pull in pyrender (it's the whole point of the split)." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L25 | neighbors=[test_load_mesh_no_pyrender_import()] | lang=en
- "tests_test_mesh_io_test_bed_fit_allows_rotation_and_reports_overflow": "test_bed_fit_allows_rotation_and_reports_overflow()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L44 | neighbors=[test_mesh_io.py] | lang=en
- "tests_test_mesh_io_test_estimate_mass_hollow_less_than_solid": "test_estimate_mass_hollow_less_than_solid()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L56 | neighbors=[test_mesh_io.py] | lang=en
- "tests_test_mesh_io_test_load_mesh_empty_file": "test_load_mesh_empty_file()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L17 | neighbors=[test_mesh_io.py] | lang=en
- "tests_test_mesh_io_test_load_mesh_missing_file": "test_load_mesh_missing_file()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L12 | neighbors=[test_mesh_io.py] | lang=en
- "tests_test_mesh_io_test_load_mesh_valid": "test_load_mesh_valid()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L5 | neighbors=[test_mesh_io.py] | lang=en
- "tests_test_mesh_io_test_parse_bed_forms": "test_parse_bed_forms()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L30 | neighbors=[test_mesh_io.py] | lang=en
- "tests_test_modeling_test_apply_keeps_shape_keys_and_handles_multi_user": "test_apply_keeps_shape_keys_and_handles_multi_user()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_modeling.py:L38 | neighbors=[test_modeling.py] | lang=en
- "tests_test_modeling_test_hardsurface_snippet_attributes": "test_hardsurface_snippet_attributes()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_modeling.py:L26 | neighbors=[test_modeling.py] | lang=en
- "tests_test_modeling_test_midpoly_stack_with_boolean_and_apply": "test_midpoly_stack_with_boolean_and_apply()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_modeling.py:L6 | neighbors=[test_modeling.py] | lang=en
- "tests_test_modeling_test_subd_preset_adds_smooth_by_angle": "test_subd_preset_adds_smooth_by_angle()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_modeling.py:L19 | neighbors=[test_modeling.py] | lang=en
- "tests_test_npr_rationale_25": "Distinct flat colors (8-bit rounding splits a band into near-identical values)." | kind=entity | source=.agents/skills/blender-skills-main/tests/test_npr.py:L25 | neighbors=[_clusters()] | lang=pt
- "tests_test_npr_test_remove_restores_slots_on_unmaterialed_object": "test_remove_restores_slots_on_unmaterialed_object()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L94 | neighbors=[test_npr.py] | lang=en
- "tests_test_optimization_test_lods_halve_and_cleanup": "test_lods_halve_and_cleanup()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_optimization.py:L6 | neighbors=[test_optimization.py] | lang=en
- "tests_test_optimization_test_mesh_stats_budget": "test_mesh_stats_budget()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_optimization.py:L14 | neighbors=[test_optimization.py] | lang=en
- "tests_test_package_rationale_1": "Contracts specific to the self-contained skill package: CLI, workspace layout, r" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L1 | neighbors=[test_package.py] | lang=en
- "tests_test_package_rationale_15": "Run the CLI with the test interpreter; returns (exit code, parsed JSON stdout)." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L15 | neighbors=[vfx()] | lang=en
- "tests_test_package_test_doctor_runs_through_vfx_cmd_on_a_bare_system_python": "test_doctor_runs_through_vfx_cmd_on_a_bare_system_python()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L53 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_effect_ids_are_validated_before_touching_files": "test_effect_ids_are_validated_before_touching_files()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L244 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_help_lists_commands_without_dependencies": "test_help_lists_commands_without_dependencies()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L94 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_init_installs_starter_textures_without_overwriting_or_duplicating_prompts": "test_init_installs_starter_textures_without_overwriting_or_duplicating_prompts()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L274 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_launchers_keep_the_line_endings_their_shells_need": "test_launchers_keep_the_line_endings_their_shells_need()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L79 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_library_get_rejects_unknown_ids_and_reloads_helpers": "test_library_get_rejects_unknown_ids_and_reloads_helpers()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L188 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_library_load_rejects_id_file_mismatch_and_missing_recipe": "test_library_load_rejects_id_file_mismatch_and_missing_recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L169 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_paths_follow_vfx_project_and_toolchain_environment": "test_paths_follow_vfx_project_and_toolchain_environment()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L232 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_setup_ps1_rejects_unknown_options_before_touching_anything": "test_setup_ps1_rejects_unknown_options_before_touching_anything()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L71 | neighbors=[test_package.py] | lang=en
- "tests_test_package_test_workflow_relative_absolute_round_trip_for_project_skill_and_toolchain_paths": "test_workflow_relative_absolute_round_trip_for_project_skill_and_toolchain_path…" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L210 | neighbors=[test_package.py] | lang=en
- "tests_test_pipeline_rationale_1": "Layer compiler, Core round trips, texture processing, recipe primitives and the" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L1 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_advanced_layer_features_survive_core_roundtrip": "test_advanced_layer_features_survive_core_roundtrip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L113 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_batch_convert_report_script_shard": "test_batch_convert_report_script_shard()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_pipeline.py:L8 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_core_roundtrip_preserves_timing_curves_seed_and_model": "test_core_roundtrip_preserves_timing_curves_seed_and_model()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L15 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_curve_tangent_data_roundtrips_and_invalid_edit_preserves_keys": "test_curve_tangent_data_roundtrips_and_invalid_edit_preserves_keys()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L158 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_cutoff_curves_become_easings_that_keep_hold_and_tear": "test_cutoff_curves_become_easings_that_keep_hold_and_tear()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L373 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_decal_resolves_extra_textures_and_accepts_overrides": "test_decal_resolves_extra_textures_and_accepts_overrides()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L411 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_discovery_excludes_import_only_legacy_fields_and_enums_are_validated": "test_discovery_excludes_import_only_legacy_fields_and_enums_are_validated()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L43 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_easing_cutoff_survives_core_roundtrip": "test_easing_cutoff_survives_core_roundtrip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L389 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_every_effect_declares_how_a_game_delivers_it": "test_every_effect_declares_how_a_game_delivers_it()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L252 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_flipbook_sheet_keeps_cells_in_place_and_feathers_their_borders": "test_flipbook_sheet_keeps_cells_in_place_and_feathers_their_borders()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L193 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_library_recipes_are_valid_without_core_or_assets": "test_library_recipes_are_valid_without_core_or_assets()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L228 | neighbors=[test_pipeline.py] | lang=en
- "tests_test_pipeline_test_lifetime_and_budget_follow_children_and_random_life": "test_lifetime_and_budget_follow_children_and_random_life()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L308 | neighbors=[test_pipeline.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-190.json

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
