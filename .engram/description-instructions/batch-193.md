# Node Description Batch 194 of 209

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

- "tests_test_package_test_library_get_rejects_unknown_ids_and_reloads_helpers": "test_library_get_rejects_unknown_ids_and_reloads_helpers()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L188 | neighbors=[test_package.py]
- "tests_test_package_test_library_load_rejects_id_file_mismatch_and_missing_recipe": "test_library_load_rejects_id_file_mismatch_and_missing_recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L169 | neighbors=[test_package.py]
- "tests_test_package_test_paths_follow_vfx_project_and_toolchain_environment": "test_paths_follow_vfx_project_and_toolchain_environment()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L232 | neighbors=[test_package.py]
- "tests_test_package_test_setup_ps1_rejects_unknown_options_before_touching_anything": "test_setup_ps1_rejects_unknown_options_before_touching_anything()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L71 | neighbors=[test_package.py]
- "tests_test_package_test_workflow_relative_absolute_round_trip_for_project_skill_and_toolchain_paths": "test_workflow_relative_absolute_round_trip_for_project_skill_and_toolchain_path…" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L210 | neighbors=[test_package.py]
- "tests_test_pipeline_rationale_1": "Layer compiler, Core round trips, texture processing, recipe primitives and the" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L1 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_advanced_layer_features_survive_core_roundtrip": "test_advanced_layer_features_survive_core_roundtrip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L113 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_batch_convert_report_script_shard": "test_batch_convert_report_script_shard()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_pipeline.py:L8 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_core_roundtrip_preserves_timing_curves_seed_and_model": "test_core_roundtrip_preserves_timing_curves_seed_and_model()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L15 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_curve_tangent_data_roundtrips_and_invalid_edit_preserves_keys": "test_curve_tangent_data_roundtrips_and_invalid_edit_preserves_keys()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L158 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_cutoff_curves_become_easings_that_keep_hold_and_tear": "test_cutoff_curves_become_easings_that_keep_hold_and_tear()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L373 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_decal_resolves_extra_textures_and_accepts_overrides": "test_decal_resolves_extra_textures_and_accepts_overrides()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L411 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_discovery_excludes_import_only_legacy_fields_and_enums_are_validated": "test_discovery_excludes_import_only_legacy_fields_and_enums_are_validated()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L43 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_easing_cutoff_survives_core_roundtrip": "test_easing_cutoff_survives_core_roundtrip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L389 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_every_effect_declares_how_a_game_delivers_it": "test_every_effect_declares_how_a_game_delivers_it()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L252 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_flipbook_sheet_keeps_cells_in_place_and_feathers_their_borders": "test_flipbook_sheet_keeps_cells_in_place_and_feathers_their_borders()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L193 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_library_recipes_are_valid_without_core_or_assets": "test_library_recipes_are_valid_without_core_or_assets()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L228 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_lifetime_and_budget_follow_children_and_random_life": "test_lifetime_and_budget_follow_children_and_random_life()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L308 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_manifest_matches_assets_and_particle_lifetimes": "test_manifest_matches_assets_and_particle_lifetimes()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L208 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_procedural_noise_is_tileable_and_distortion_maps_are_opaque": "test_procedural_noise_is_tileable_and_distortion_maps_are_opaque()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L317 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_reference_primitives_break_shapes_and_decay_to_smoke": "test_reference_primitives_break_shapes_and_decay_to_smoke()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L284 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_repeated_compile_is_idempotent_and_changes_do_not_accumulate": "test_repeated_compile_is_idempotent_and_changes_do_not_accumulate()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L59 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_scaffold_creates_workspace_and_preserves_existing_data": "test_scaffold_creates_workspace_and_preserves_existing_data()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L334 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_scaffold_syncs_character_models": "test_scaffold_syncs_character_models()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L357 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_shell_fragment_surface_limits_survive_core_save_open": "test_shell_fragment_surface_limits_survive_core_save_open()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L73 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_sustained_layers_live_until_release_and_budget_by_overlap": "test_sustained_layers_live_until_release_and_budget_by_overlap()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L272 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_texture_processing_preserves_original_and_straight_alpha": "test_texture_processing_preserves_original_and_straight_alpha()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L175 | neighbors=[test_pipeline.py]
- "tests_test_pipeline_test_value_pair_fixed_geometry_and_alpha_curve_survive_core_roundtrip": "test_value_pair_fixed_geometry_and_alpha_curve_survive_core_roundtrip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_pipeline.py:L92 | neighbors=[test_pipeline.py]
- "tests_test_privacy_rationale_1": "The published package carries no personal, machine-specific or secret data, in t" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L1 | neighbors=[test_privacy.py]
- "tests_test_privacy_rationale_105": "Names of JPEG segments beyond pixel data (JFIF header, tables, frame and scan ar" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L105 | neighbors=[jpeg_metadata()]
- "tests_test_privacy_rationale_83": "Names of PNG chunks beyond pixel data (or a problem with the file's structure)." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L83 | neighbors=[png_metadata()]
- "tests_test_qa_test_material_and_texture_delivery_checks": "test_material_and_texture_delivery_checks()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L137 | neighbors=[test_qa.py]
- "tests_test_qa_test_review_shots_renders_sheet": "test_review_shots_renders_sheet()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L120 | neighbors=[test_qa.py]
- "tests_test_rendering_test_lookdev_turntable_and_studio": "test_lookdev_turntable_and_studio()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rendering.py:L30 | neighbors=[test_rendering.py]
- "tests_test_retopo_uv_test_auto_retopo_methods": "test_auto_retopo_methods()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_retopo_uv.py:L30 | neighbors=[test_retopo_uv.py]
- "tests_test_retopo_uv_test_auto_retopo_quadriflow_voxel_first": "test_auto_retopo_quadriflow_voxel_first()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_retopo_uv.py:L43 | neighbors=[test_retopo_uv.py]
- "tests_test_retopo_uv_test_decimate_drops_shape_keys_instead_of_failing": "test_decimate_drops_shape_keys_instead_of_failing()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_retopo_uv.py:L73 | neighbors=[test_retopo_uv.py]
- "tests_test_retopo_uv_test_uv_pack_and_texel_density_set": "test_uv_pack_and_texel_density_set()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_retopo_uv.py:L6 | neighbors=[test_retopo_uv.py]
- "tests_test_retopo_uv_test_uv_pack_warns_without_seams": "test_uv_pack_warns_without_seams()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_retopo_uv.py:L22 | neighbors=[test_retopo_uv.py]
- "tests_test_rigging_rationale_55": "Issue #11: >= 4000 verts makes the symmetry sample step > 1 (bpy collections rej" | kind=entity | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L55 | neighbors=[test_rig_check_dense_mesh()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-193.json

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
