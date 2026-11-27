# Node Description Batch 138 of 208

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

- "tests_test_run_wrapper_test_step_discovered": "test_step_discovered()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L64 | neighbors=[test_run_wrapper.py, run()]
- "tests_test_run_wrapper_test_strict_empty_fails": "test_strict_empty_fails()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L39 | neighbors=[test_run_wrapper.py, run()]
- "tests_test_run_wrapper_test_strict_watertight": "test_strict_watertight()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L32 | neighbors=[test_run_wrapper.py, run()]
- "tests_test_safety_test_a_broken_source_only_blocks_itself": "test_a_broken_source_only_blocks_itself()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L50 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_a_build_mirrors_only_its_own_resources": "test_a_build_mirrors_only_its_own_resources()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L339 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_a_build_never_replaces_a_resource_another_built_effect_uses": "test_a_build_never_replaces_a_resource_another_built_effect_uses()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L220 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_a_full_build_of_an_empty_library_refuses_before_touching_anything": "test_a_full_build_of_an_empty_library_refuses_before_touching_anything()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L42 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_a_full_build_prunes_only_effects_it_built": "test_a_full_build_prunes_only_effects_it_built()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L93 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_conflicts_protect_hand_made_effects_without_a_recipe": "test_conflicts_protect_hand_made_effects_without_a_recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L274 | neighbors=[test_safety.py, conflict_setup()]
- "tests_test_safety_test_conflicts_protect_owned_effects_unless_they_are_rebuilt_or_removed": "test_conflicts_protect_owned_effects_unless_they_are_rebuilt_or_removed()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L265 | neighbors=[test_safety.py, conflict_setup()]
- "tests_test_safety_test_doctor_uses_the_same_ownership_rules": "test_doctor_uses_the_same_ownership_rules()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L285 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_helpers_never_shadow_built_in_modules": "test_helpers_never_shadow_built_in_modules()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L194 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_init_fills_missing_math_textures_without_replacing_edited_ones": "test_init_fills_missing_math_textures_without_replacing_edited_ones()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L183 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_init_never_writes_through_a_link_that_leads_outside": "test_init_never_writes_through_a_link_that_leads_outside()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L376 | neighbors=[test_safety.py, game()]
- "tests_test_safety_test_project_files_never_shadow_modules": "test_project_files_never_shadow_modules()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L63 | neighbors=[test_safety.py, game()]
- "tests_test_scale_beam_test_beam_recipe_lints_with_hold_and_needs_a_release": "test_beam_recipe_lints_with_hold_and_needs_a_release()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L183 | neighbors=[test_scale_beam.py, recipe_with()]
- "tests_test_scale_beam_test_lint_counts_repeatedly_emitted_painted_shapes_as_restruck": "test_lint_counts_repeatedly_emitted_painted_shapes_as_restruck()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L220 | neighbors=[test_scale_beam.py, recipe_with()]
- "tests_test_scale_beam_test_lint_scales_its_craft_limits_with_the_recipe": "test_lint_scales_its_craft_limits_with_the_recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L89 | neighbors=[test_scale_beam.py, recipe_with()]
- "tests_test_scale_beam_test_scale_character_is_a_no_op_and_records_nothing": "test_scale_character_is_a_no_op_and_records_nothing()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L83 | neighbors=[test_scale_beam.py, recipe_with()]
- "tests_test_simulation_test_classic_cloth_drapes_on_collider": "test_classic_cloth_drapes_on_collider()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_simulation.py:L22 | neighbors=[test_simulation.py, _grid()]
- "tests_test_simulation_test_gn_cloth_52_asset": "test_gn_cloth_52_asset()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_simulation.py:L31 | neighbors=[test_simulation.py, _grid()]
- "tests_test_texturing_test_smart_material_bakes_to_texture": "test_smart_material_bakes_to_texture()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L65 | neighbors=[test_texturing.py, _stepped_block()]
- "tests_test_texturing_test_smart_material_curvature_and_roundtrip": "test_smart_material_curvature_and_roundtrip()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L34 | neighbors=[test_texturing.py, _stepped_block()]
- "tests_test_tools_test_ablation_verdicts": "test_ablation_verdicts()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L73 | neighbors=[test_tools.py, _write_ablation()]
- "tests_test_tools_write_ablation": "_write_ablation()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L62 | neighbors=[test_tools.py, test_ablation_verdicts()]
- "tests_test_video_clip": "clip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L21 | neighbors=[test_video.py, 48 frames at 24 fps: black, a warm disc…]
- "tests_test_video_png": "_png()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_video.py:L17 | neighbors=[test_video.py, test_vse_edit_crossfade_title_audio_mp4…]
- "tests_test_video_test_track_camera_solves_in_ui_session": "test_track_camera_solves_in_ui_session()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_video.py:L124 | neighbors=[test_video.py, _footage()]
- "tests_test_video_test_unity_export_writes_the_grid_sidecar_and_stays_inside_the_project": "test_unity_export_writes_the_grid_sidecar_and_stays_inside_the_project()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L112 | neighbors=[test_video.py, fake_unity()]
- "tests_test_video_test_unity_force_keeps_meta_guids": "test_unity_force_keeps_meta_guids()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L154 | neighbors=[test_video.py, fake_unity()]
- "tests_test_video_test_unity_install_copies_the_package_and_draws_its_textures": "test_unity_install_copies_the_package_and_draws_its_textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L92 | neighbors=[test_video.py, fake_unity()]
- "tests_test_video_test_vse_edit_crossfade_title_audio_mp4": "test_vse_edit_crossfade_title_audio_mp4()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_video.py:L27 | neighbors=[test_video.py, _png()]
- "tests_test_weather_instances": "_instances()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_weather.py:L6 | neighbors=[test_weather.py, test_precipitation_loops_and_stops_on_g…]
- "tests_test_weather_test_precipitation_loops_and_stops_on_ground": "test_precipitation_loops_and_stops_on_ground()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_weather.py:L14 | neighbors=[test_weather.py, _instances()]
- "tests_test_workflow_isolated": "isolated()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L45 | neighbors=[test_workflow.py, Point the workspace-relative modules at…]
- "tests_test_workflow_test_build_and_render_reject_changed_sources_assets_outputs_and_templates": "test_build_and_render_reject_changed_sources_assets_outputs_and_templates()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L115 | neighbors=[test_workflow.py, captured()]
- "tests_test_workflow_test_evidence_is_stored_in_the_workspace_work_folder": "test_evidence_is_stored_in_the_workspace_work_folder()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L102 | neighbors=[test_workflow.py, captured()]
- "tests_test_workflow_test_reference_compare_requires_exact_fresh_render_frames": "test_reference_compare_requires_exact_fresh_render_frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L230 | neighbors=[test_workflow.py, captured()]
- "tests_test_workflow_test_review_handoff_refuses_a_missing_or_stale_capture": "test_review_handoff_refuses_a_missing_or_stale_capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L310 | neighbors=[test_workflow.py, captured()]
- "texture_tex_to_maps_load_gray": "load_gray()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L30 | neighbors=[tex_to_maps.py, process()]

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
