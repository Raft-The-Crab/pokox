# Node Description Batch 191 of 208

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

- "tests_test_animation_rationale_9": "Keyframe the hips ('spine', child of root) moving dist metres toward -Y over 24" | kind=entity | source=.agents/skills/blender-skills-main/tests/test_animation.py:L9 | neighbors=[_walk()] | lang=en
- "tests_test_animation_test_loop_check_hitches_kink_dip_and_smooth_reversal": "test_loop_check_hitches_kink_dip_and_smooth_reversal()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L170 | neighbors=[test_animation.py] | lang=en
- "tests_test_animation_test_loop_check_pops_fix_and_root_motion": "test_loop_check_pops_fix_and_root_motion()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L149 | neighbors=[test_animation.py] | lang=en
- "tests_test_atmosphere_test_fog_density_from_visibility_and_moods": "test_fog_density_from_visibility_and_moods()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L50 | neighbors=[test_atmosphere.py] | lang=en
- "tests_test_atmosphere_test_time_presets_sun_color_and_balance": "test_time_presets_sun_color_and_balance()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L24 | neighbors=[test_atmosphere.py] | lang=en
- "tests_test_clothing_test_garment_morphs_and_drape": "test_garment_morphs_and_drape()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_clothing.py:L26 | neighbors=[test_clothing.py] | lang=en
- "tests_test_clothing_test_garment_weights_mask_and_pose": "test_garment_weights_mask_and_pose()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_clothing.py:L7 | neighbors=[test_clothing.py] | lang=en
- "tests_test_core_rationale_12": "Execute every ```python block of a reference doc on a fresh scene." | kind=entity | source=.agents/skills/blender-skills-main/tests/test_core.py:L12 | neighbors=[_run_md_blocks()] | lang=pt
- "tests_test_core_rationale_36": "Any reference doc tagged '(runs standalone)' must execute cleanly." | kind=entity | source=.agents/skills/blender-skills-main/tests/test_core.py:L36 | neighbors=[test_snippet_docs_across_skills()] | lang=en
- "tests_test_core_test_env_report": "test_env_report()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L29 | neighbors=[test_core.py] | lang=en
- "tests_test_effekseer_ai_rationale_1": "The vendored effekseer_ai bridge: portable CLI surface and an explicit, never-gu" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L1 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_effekseer_ai_rationale_31": "A public release must never probe a contributor's local disks." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L31 | neighbors=[test_editor_bin_directory_requires_an_e…] | lang=pt
- "tests_test_effekseer_ai_test_cli_exposes_only_the_portable_effect_bridge_commands": "test_cli_exposes_only_the_portable_effect_bridge_commands()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L9 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_effekseer_ai_test_cli_rejects_removed_recipe_commands": "test_cli_rejects_removed_recipe_commands()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L18 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_effekseer_ai_test_editor_bin_directory_rejects_a_directory_without_core": "test_editor_bin_directory_rejects_a_directory_without_core()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L38 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_effekseer_ai_test_editor_bin_directory_uses_a_configured_core_directory": "test_editor_bin_directory_uses_a_configured_core_directory()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L45 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_effekseer_ai_test_runtime_config_is_bundled": "test_runtime_config_is_bundled()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L54 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_effekseer_ai_test_vendored_package_has_no_protocol_server_and_keeps_its_license": "test_vendored_package_has_no_protocol_server_and_keeps_its_license()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_effekseer_ai.py:L24 | neighbors=[test_effekseer_ai.py] | lang=en
- "tests_test_environment_test_kit_check_flags_and_fixes": "test_kit_check_flags_and_fixes()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_environment.py:L70 | neighbors=[test_environment.py] | lang=en
- "tests_test_environment_test_terrain_attributes_flatten_and_engine_maps": "test_terrain_attributes_flatten_and_engine_maps()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_environment.py:L12 | neighbors=[test_environment.py] | lang=en
- "tests_test_examples_rationale_1": "Shipped example effects: complete, valid, self-consistent with their briefs and" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L1 | neighbors=[test_examples.py] | lang=en
- "tests_test_examples_test_each_example_source_loads_and_matches_its_brief": "test_each_example_source_loads_and_matches_its_brief()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L53 | neighbors=[test_examples.py] | lang=en
- "tests_test_examples_test_example_show_accepts_pair_and_single_names": "test_example_show_accepts_pair_and_single_names()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L44 | neighbors=[test_examples.py] | lang=en
- "tests_test_examples_test_example_show_gives_a_timeline_with_layer_roles_and_paired_projectiles": "test_example_show_gives_a_timeline_with_layer_roles_and_paired_projectiles()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L77 | neighbors=[test_examples.py] | lang=en
- "tests_test_examples_test_example_textures_are_installed_and_their_prompts_recorded": "test_example_textures_are_installed_and_their_prompts_recorded()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L102 | neighbors=[test_examples.py] | lang=en
- "tests_test_examples_test_loaded_examples_are_detached_copies": "test_loaded_examples_are_detached_copies()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L94 | neighbors=[test_examples.py] | lang=en
- "tests_test_examples_test_value_pair_preserves_geometry_and_rejects_unsynchronized_randomness": "test_value_pair_preserves_geometry_and_rejects_unsynchronized_randomness()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L112 | neighbors=[test_examples.py] | lang=en
- "tests_test_export_test_batch_export_at_origin": "test_batch_export_at_origin()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_export.py:L41 | neighbors=[test_export.py] | lang=en
- "tests_test_export_test_static_fbx_has_no_animation_take": "test_static_fbx_has_no_animation_take()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_export.py:L51 | neighbors=[test_export.py] | lang=en
- "tests_test_facial_test_arkit_split_mirror_drivers_report": "test_arkit_split_mirror_drivers_report()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_facial.py:L6 | neighbors=[test_facial.py] | lang=en
- "tests_test_geonodes_test_build_apply_set_inputs": "test_build_apply_set_inputs()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L36 | neighbors=[test_geonodes.py] | lang=en
- "tests_test_geonodes_test_describe": "test_describe()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L55 | neighbors=[test_geonodes.py] | lang=en
- "tests_test_geonodes_test_reference_recipes_build_and_evaluate": "test_reference_recipes_build_and_evaluate()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L63 | neighbors=[test_geonodes.py] | lang=en
- "tests_test_geonodes_test_repeat_zone": "test_repeat_zone()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L48 | neighbors=[test_geonodes.py] | lang=en
- "tests_test_golden_goldenharnesstests_setup": ".setUp()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L18 | neighbors=[GoldenHarnessTests] | lang=en
- "tests_test_gridfinity_test_bad_notch_side_raises": "test_bad_notch_side_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L183 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_compartments_only_once": "test_compartments_only_once()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L171 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_cylinder_pocket_tilt_limits": "test_cylinder_pocket_tilt_limits()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L94 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_notch_offset_past_wall_raises": "test_notch_offset_past_wall_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L112 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_oversized_cylinder_pocket_raises": "test_oversized_cylinder_pocket_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L88 | neighbors=[test_gridfinity.py] | lang=en

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
