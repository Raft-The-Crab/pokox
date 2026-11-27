# Node Description Batch 193 of 207

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

- "tests_test_safety_test_references_match_non_ascii_names_in_any_case": "test_references_match_non_ascii_names_in_any_case()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L355 | neighbors=[test_safety.py]
- "tests_test_safety_test_removal_refuses_paths_that_resolve_outside_the_workspace": "test_removal_refuses_paths_that_resolve_outside_the_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L159 | neighbors=[test_safety.py]
- "tests_test_safety_test_resource_names_compare_in_unicode_normal_form": "test_resource_names_compare_in_unicode_normal_form()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L390 | neighbors=[test_safety.py]
- "tests_test_safety_test_resource_names_ignore_case": "test_resource_names_ignore_case()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L325 | neighbors=[test_safety.py]
- "tests_test_safety_test_same_named_resources_with_different_content_are_rejected": "test_same_named_resources_with_different_content_are_rejected()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L171 | neighbors=[test_safety.py]
- "tests_test_safety_test_setup_locks_with_the_kernel_not_a_lock_directory": "test_setup_locks_with_the_kernel_not_a_lock_directory()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L294 | neighbors=[test_safety.py]
- "tests_test_safety_test_setup_pins_every_archive_it_downloads": "test_setup_pins_every_archive_it_downloads()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L212 | neighbors=[test_safety.py]
- "tests_test_safety_test_setup_without_a_new_enough_python_stops_clearly_and_drops_a_stale_env": "test_setup_without_a_new_enough_python_stops_clearly_and_drops_a_stale_env()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L416 | neighbors=[test_safety.py]
- "tests_test_safety_test_slash_set_bulge_matches_the_shipped_crescent": "test_slash_set_bulge_matches_the_shipped_crescent()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L85 | neighbors=[test_safety.py]
- "tests_test_scale_beam_rationale_1": "World scale, game-driven bind equations, beams, charge chains and soft particles" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L1 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_beam_cross_section_is_full_strength_along_its_length": "test_beam_cross_section_is_full_strength_along_its_length()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L279 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_beam_layers_are_held_axial_strips_bound_to_length_and_power": "test_beam_layers_are_held_axial_strips_bound_to_length_and_power()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L162 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_bind_components_and_equations_are_validated": "test_bind_components_and_equations_are_validated()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L115 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_bind_equations_and_input_defaults_survive_core_save_open": "test_bind_equations_and_input_defaults_survive_core_save_open()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L139 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_charge_chain_aims_each_arc_at_the_next_anchor_and_lights_in_order": "test_charge_chain_aims_each_arc_at_the_next_anchor_and_lights_in_order()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L197 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_lab_scales_its_stage_and_stages_beams": "test_lab_scales_its_stage_and_stages_beams()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L268 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_lint_rejects_bind_conflicts_and_missing_input_defaults": "test_lint_rejects_bind_conflicts_and_missing_input_defaults()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L125 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_review_tolerances_stretch_with_scaled_time_and_skip_beam_contact": "test_review_tolerances_stretch_with_scaled_time_and_skip_beam_contact()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L245 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_scale_converts_space_on_top_level_layers_and_time_everywhere": "test_scale_converts_space_on_top_level_layers_and_time_everywhere()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L32 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_scale_gives_unsized_layers_a_node_scale_and_keeps_bind_equations_in_world_units": "test_scale_gives_unsized_layers_a_node_scale_and_keeps_bind_equations_in_world_…" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L66 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_scale_profiles_numbers_and_dicts": "test_scale_profiles_numbers_and_dicts()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L19 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_scaled_life_rounds_down_so_layers_stay_inside_the_stretched_duration": "test_scaled_life_rounds_down_so_layers_stay_inside_the_stretched_duration()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L76 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_shipped_kaiju_examples_are_scaled_and_record_their_profile": "test_shipped_kaiju_examples_are_scaled_and_record_their_profile()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L106 | neighbors=[test_scale_beam.py]
- "tests_test_scale_beam_test_soft_must_be_a_positive_distance_and_warns_when_it_swallows_the_card": "test_soft_must_be_a_positive_distance_and_warns_when_it_swallows_the_card()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L231 | neighbors=[test_scale_beam.py]
- "tests_test_scene_test_collection_exporter_snippet": "test_collection_exporter_snippet()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_scene.py:L27 | neighbors=[test_scene.py]
- "tests_test_scene_test_scene_audit_flags_and_fixes": "test_scene_audit_flags_and_fixes()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_scene.py:L8 | neighbors=[test_scene.py]
- "tests_test_sculpt_test_sculpt_ops_chain": "test_sculpt_ops_chain()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_sculpt.py:L5 | neighbors=[test_sculpt.py]
- "tests_test_sequence_rationale_1": "Sequences (combos), the blockout gate, screen feedback and the stylized hard-edg" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L1 | neighbors=[test_sequence.py]
- "tests_test_sequence_test_lab_and_runtime_play_sequences_and_screen_feedback": "test_lab_and_runtime_play_sequences_and_screen_feedback()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L152 | neighbors=[test_sequence.py]
- "tests_test_sequence_test_new_masks_tile_and_helix_wraps_a_strip": "test_new_masks_tile_and_helix_wraps_a_strip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L120 | neighbors=[test_sequence.py]
- "tests_test_sequence_test_stylized_primitives_compile_to_known_fields": "test_stylized_primitives_compile_to_known_fields()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L138 | neighbors=[test_sequence.py]
- "tests_test_simulation_test_rigid_body_drop_and_keys": "test_rigid_body_drop_and_keys()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_simulation.py:L12 | neighbors=[test_simulation.py]
- "tests_test_stl_to_3mf_test_convert_happy_path": "test_convert_happy_path()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_stl_to_3mf.py:L11 | neighbors=[test_stl_to_3mf.py]
- "tests_test_stl_to_3mf_test_convert_missing_file": "test_convert_missing_file()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_stl_to_3mf.py:L20 | neighbors=[test_stl_to_3mf.py]
- "tests_test_texturing_rationale_8": "1 m block with a 0.5 m step on top (convex outer edges + one concave inner edge)" | kind=entity | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L8 | neighbors=[_stepped_block()]
- "tests_test_texturing_test_decal_conforms_without_zfighting": "test_decal_conforms_without_zfighting()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L84 | neighbors=[test_texturing.py]
- "tests_test_tools_test_ablation_corrupt_json_exits_2": "test_ablation_corrupt_json_exits_2()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L87 | neighbors=[test_tools.py]
- "tests_test_tools_test_flat_interior_with_seam_fails": "test_flat_interior_with_seam_fails()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L99 | neighbors=[test_tools.py]
- "tests_test_tools_test_flat_tile_is_seamless": "test_flat_tile_is_seamless()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L93 | neighbors=[test_tools.py]
- "tests_test_tools_test_hex_to_rgb_shorthand": "test_hex_to_rgb_shorthand()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L107 | neighbors=[test_tools.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-192.json

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
