# Node Description Batch 82 of 207

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

- "tests_run_all_requires_gpu": "requires_gpu()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L43 | neighbors=[run_all.py, Skip when BAS_SKIP_GPU=1 (CI runners wi…, Skip]
- "tests_run_all_skip": "Skip" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L39 | neighbors=[run_all.py, requires_gpu(), Exception]
- "tests_test_addon": "test_addon.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_addon.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_template_validates_builds_and_regi…]
- "tests_test_animation_walk": "_walk()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_animation.py:L8 | neighbors=[test_animation.py, Keyframe the hips ('spine', child of ro…, test_bake_to_copy_with_root_motion_and_…]
- "tests_test_atmosphere_render": "_render()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_atmosphere.py:L13 | neighbors=[test_atmosphere.py, _mean_luma(), test_night_renders_darker_than_noon()]
- "tests_test_baking_pixels": "_pixels()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_baking.py:L9 | neighbors=[test_baking.py, test_high_to_low_bake_normal_ao_curv_or…, test_self_bake_procedural_roughness()]
- "tests_test_core_test_snippet_docs_across_skills": "test_snippet_docs_across_skills()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L35 | neighbors=[test_core.py, Any reference doc tagged '(runs standal…, _run_md_blocks()]
- "tests_test_examples_example_ids": "example_ids()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L12 | neighbors=[test_examples.py, test_catalog_lists_every_shipped_exampl…, test_lint_of_all_examples_has_no_errors…]
- "tests_test_facial": "test_facial.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_facial.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_arkit_split_mirror_drivers_report()]
- "tests_test_golden": "test_golden.py" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, GoldenHarnessTests, run()]
- "tests_test_golden_goldenharnesstests_test_update_creates_and_replaces_only_when_explicit": ".test_update_creates_and_replaces_only_when_explicit()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L75 | neighbors=[GoldenHarnessTests, .pair(), run()]
- "tests_test_gridfinity_rationale_124": "Rebuild the published D110 cradle; dimensions must match." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L124 | neighbors=[GridfinityBin, GridfinityError, test_d110_regression()]
- "tests_test_gridfinity_rationale_25": "B-rep volume, no tessellation round-trip." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L25 | neighbors=[GridfinityBin, GridfinityError, _volume()]
- "tests_test_gridfinity_rationale_41": "1x1, 2U, no lip: exact box height, flat top." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L41 | neighbors=[GridfinityBin, GridfinityError, test_minimal_bin_no_lip()]
- "tests_test_gridfinity_rationale_49": "2x1, 3U with lip and base holes." | kind=entity | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L49 | neighbors=[GridfinityBin, GridfinityError, test_bin_with_lip_magnets_screws()]
- "tests_test_gridfinity_test_d110_regression": "test_d110_regression()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L123 | neighbors=[test_gridfinity.py, Rebuild the published D110 cradle; dime…, _mesh()]
- "tests_test_gridfinity_test_finger_notch_removes_material": "test_finger_notch_removes_material()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L103 | neighbors=[test_gridfinity.py, _mesh(), _volume()]
- "tests_test_gridfinity_test_polygon_pocket_with_clearance_and_cylinder_well": "test_polygon_pocket_with_clearance_and_cylinder_well()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L74 | neighbors=[test_gridfinity.py, _assert_footprint(), _mesh()]
- "tests_test_hair_head": "_head()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_hair.py:L7 | neighbors=[test_hair.py, test_groom_attached_masked_with_assets(), test_hair_cards_and_atlas()]
- "tests_test_npr_clusters": "_clusters()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L24 | neighbors=[test_npr.py, _bands(), Distinct flat colors (8-bit rounding sp…]
- "tests_test_npr_scene": "_scene()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L9 | neighbors=[test_npr.py, test_toon_hull_bands_lineart_roundtrip(), test_toon_scene_lighting_eevee()]
- "tests_test_npr_test_toon_hull_bands_lineart_roundtrip": "test_toon_hull_bands_lineart_roundtrip()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L52 | neighbors=[test_npr.py, _bands(), _scene()]
- "tests_test_npr_test_toon_scene_lighting_eevee": "test_toon_scene_lighting_eevee()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L83 | neighbors=[test_npr.py, _bands(), _scene()]
- "tests_test_privacy_jpeg_metadata": "jpeg_metadata()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L104 | neighbors=[test_privacy.py, file_hits(), Names of JPEG segments beyond pixel dat…]
- "tests_test_privacy_private_terms": "private_terms()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L61 | neighbors=[test_privacy.py, test_maintainer_private_terms_when_conf…, test_no_file_in_the_package_leaks_perso…]
- "tests_test_privacy_test_scanner_catches_each_kind_of_leak_and_respects_the_allowlists": "test_scanner_catches_each_kind_of_leak_and_respects_the_allowlists()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L137 | neighbors=[test_privacy.py, png_metadata(), text_hits()]
- "tests_test_rigging_humanoid_mesh": "_humanoid_mesh()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rigging.py:L8 | neighbors=[test_rigging.py, Crude closed humanoid (torso, head, arm…, test_rigify_pipeline_bind_check_stress()]
- "tests_test_run_wrapper_test_json_shape_keys": "test_json_shape_keys()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L53 | neighbors=[test_run_wrapper.py, All documented keys must be present in …, run()]
- "tests_test_run_wrapper_test_strict_and_bed_report_both_problems": "test_strict_and_bed_report_both_problems()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_run_wrapper.py:L122 | neighbors=[test_run_wrapper.py, A non-watertight part that is also too …, run()]
- "tests_test_safety_conflict_setup": "conflict_setup()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L247 | neighbors=[test_safety.py, test_conflicts_protect_hand_made_effect…, test_conflicts_protect_owned_effects_un…]
- "tests_test_sculpt": "test_sculpt.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_sculpt.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_sculpt_ops_chain()]
- "tests_test_sequence_test_a_blockout_sequence_needs_blockout_effects": "test_a_blockout_sequence_needs_blockout_effects()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L80 | neighbors=[test_sequence.py, vfx(), workspace()]
- "tests_test_sequence_test_blockout_lint_holds_recipes_to_math_textures": "test_blockout_lint_holds_recipes_to_math_textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L43 | neighbors=[test_sequence.py, vfx(), workspace()]
- "tests_test_sequence_test_detail_needs_the_blockout_gate_and_steal_lists": "test_detail_needs_the_blockout_gate_and_steal_lists()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L62 | neighbors=[test_sequence.py, vfx(), workspace()]
- "tests_test_sequence_test_game_frames_become_evidence_and_a_blockout_ship_opens_the_gate": "test_game_frames_become_evidence_and_a_blockout_ship_opens_the_gate()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L89 | neighbors=[test_sequence.py, vfx(), workspace()]
- "tests_test_sequence_test_screen_feedback_is_validated": "test_screen_feedback_is_validated()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L52 | neighbors=[test_sequence.py, vfx(), workspace()]
- "tests_test_simulation_grid": "_grid()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_simulation.py:L7 | neighbors=[test_simulation.py, test_classic_cloth_drapes_on_collider(), test_gn_cloth_52_asset()]
- "tests_test_video_footage": "_footage()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_video.py:L79 | neighbors=[test_video.py, 40 frames of a textured set seen by a d…, test_track_camera_solves_in_ui_session()]
- "tests_test_video_test_unity_commands_need_no_workspace": "test_unity_commands_need_no_workspace()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L130 | neighbors=[test_video.py, Runs without a vfx/ workspace and print…, fake_unity()]
- "tests_test_workflow_test_completion_requires_brief_review_and_overview_instead_of_no_flags": "test_completion_requires_brief_review_and_overview_instead_of_no_flags()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L154 | neighbors=[test_workflow.py, captured(), report()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-081.json

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
