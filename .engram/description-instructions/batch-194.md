# Node Description Batch 195 of 209

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

- "tests_test_rigging_rationale_74": "Bone heat fails at mm/km world sizes (all weight on one bone); bind_mesh binds a" | kind=entity | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L74 | neighbors=[test_bind_tiny_and_huge_rigs_get_real_w…] | lang=pt
- "tests_test_rigging_rationale_9": "Crude closed humanoid (torso, head, arms in T, legs) ~1.8 m, union of boxes (non" | kind=entity | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L9 | neighbors=[_humanoid_mesh()] | lang=en
- "tests_test_rigging_test_proxy_bind_and_fix": "test_proxy_bind_and_fix()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L45 | neighbors=[test_rigging.py] | lang=en
- "tests_test_run_wrapper_rationale_123": "A non-watertight part that is also too big gets both errors in one run." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L123 | neighbors=[test_strict_and_bed_report_both_problem…] | lang=en
- "tests_test_run_wrapper_rationale_54": "All documented keys must be present in every response." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L54 | neighbors=[test_json_shape_keys()] | lang=en
- "tests_test_safety_owned_workspace": "owned_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L129 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_rationale_1": "The skill never damages a project it was pointed at by mistake: no workspace sid" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L1 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_a_capture_that_never_draws_stops_early_with_the_reason": "test_a_capture_that_never_draws_stops_early_with_the_reason()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L441 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_a_vfx_folder_from_another_tool_is_not_a_workspace": "test_a_vfx_folder_from_another_tool_is_not_a_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L30 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_case_aliases_with_the_same_content_keep_every_spelling": "test_case_aliases_with_the_same_content_keep_every_spelling()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L365 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_commands_need_a_workspace_and_never_create_one": "test_commands_need_a_workspace_and_never_create_one()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L24 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_core_passthrough_needs_no_workspace": "test_core_passthrough_needs_no_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L78 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_each_skill_folder_carries_its_license_texts": "test_each_skill_folder_carries_its_license_texts()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L204 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_file_links_that_lead_outside_are_never_written": "test_file_links_that_lead_outside_are_never_written()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L311 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_json_stores_never_write_through_a_pre_placed_temporary_link": "test_json_stores_never_write_through_a_pre_placed_temporary_link()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L401 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_missing_output_folders_under_an_outside_link_are_refused": "test_missing_output_folders_under_an_outside_link_are_refused()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L301 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_output_folders_that_resolve_outside_the_workspace_are_refused": "test_output_folders_that_resolve_outside_the_workspace_are_refused()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L237 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_ownership_needs_the_marker_or_a_matching_receipt": "test_ownership_needs_the_marker_or_a_matching_receipt()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L138 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_references_match_non_ascii_names_in_any_case": "test_references_match_non_ascii_names_in_any_case()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L355 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_removal_refuses_paths_that_resolve_outside_the_workspace": "test_removal_refuses_paths_that_resolve_outside_the_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L159 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_resource_names_compare_in_unicode_normal_form": "test_resource_names_compare_in_unicode_normal_form()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L390 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_resource_names_ignore_case": "test_resource_names_ignore_case()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L325 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_same_named_resources_with_different_content_are_rejected": "test_same_named_resources_with_different_content_are_rejected()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L171 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_setup_locks_with_the_kernel_not_a_lock_directory": "test_setup_locks_with_the_kernel_not_a_lock_directory()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L294 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_setup_pins_every_archive_it_downloads": "test_setup_pins_every_archive_it_downloads()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L212 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_setup_without_a_new_enough_python_stops_clearly_and_drops_a_stale_env": "test_setup_without_a_new_enough_python_stops_clearly_and_drops_a_stale_env()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L416 | neighbors=[test_safety.py] | lang=en
- "tests_test_safety_test_slash_set_bulge_matches_the_shipped_crescent": "test_slash_set_bulge_matches_the_shipped_crescent()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L85 | neighbors=[test_safety.py] | lang=en
- "tests_test_scale_beam_rationale_1": "World scale, game-driven bind equations, beams, charge chains and soft particles" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L1 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_beam_cross_section_is_full_strength_along_its_length": "test_beam_cross_section_is_full_strength_along_its_length()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L279 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_beam_layers_are_held_axial_strips_bound_to_length_and_power": "test_beam_layers_are_held_axial_strips_bound_to_length_and_power()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L162 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_bind_components_and_equations_are_validated": "test_bind_components_and_equations_are_validated()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L115 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_bind_equations_and_input_defaults_survive_core_save_open": "test_bind_equations_and_input_defaults_survive_core_save_open()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L139 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_charge_chain_aims_each_arc_at_the_next_anchor_and_lights_in_order": "test_charge_chain_aims_each_arc_at_the_next_anchor_and_lights_in_order()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L197 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_lab_scales_its_stage_and_stages_beams": "test_lab_scales_its_stage_and_stages_beams()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L268 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_lint_rejects_bind_conflicts_and_missing_input_defaults": "test_lint_rejects_bind_conflicts_and_missing_input_defaults()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L125 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_review_tolerances_stretch_with_scaled_time_and_skip_beam_contact": "test_review_tolerances_stretch_with_scaled_time_and_skip_beam_contact()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L245 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_scale_converts_space_on_top_level_layers_and_time_everywhere": "test_scale_converts_space_on_top_level_layers_and_time_everywhere()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L32 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_scale_gives_unsized_layers_a_node_scale_and_keeps_bind_equations_in_world_units": "test_scale_gives_unsized_layers_a_node_scale_and_keeps_bind_equations_in_world_…" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L66 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_scale_profiles_numbers_and_dicts": "test_scale_profiles_numbers_and_dicts()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L19 | neighbors=[test_scale_beam.py] | lang=en
- "tests_test_scale_beam_test_scaled_life_rounds_down_so_layers_stay_inside_the_stretched_duration": "test_scaled_life_rounds_down_so_layers_stay_inside_the_stretched_duration()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L76 | neighbors=[test_scale_beam.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-194.json

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
