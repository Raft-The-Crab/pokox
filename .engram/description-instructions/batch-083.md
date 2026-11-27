# Node Description Batch 84 of 208

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
- "tests_test_workflow_test_independent_report_binds_images_scores_and_observed_frames": "test_independent_report_binds_images_scores_and_observed_frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L136 | neighbors=[test_workflow.py, captured(), report()]
- "tests_test_workflow_test_review_handoff_gives_a_reviewer_everything_and_submits_its_report": "test_review_handoff_gives_a_reviewer_everything_and_submits_its_report()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L291 | neighbors=[test_workflow.py, captured(), report()]
- "texture_tex_to_maps_derive_normal": "derive_normal()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L73 | neighbors=[tex_to_maps.py, process(), Sobel the high-pass band and encode as …]
- "texture_tex_to_maps_derive_roughness": "derive_roughness()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L62 | neighbors=[tex_to_maps.py, process(), Dark, matte surfaces read rougher; high…]
- "texture_tile_seam_check_boundary_metrics": "boundary_metrics()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L41 | neighbors=[tile_seam_check.py, assess(), Compare the wrap edge against every int…]
- "texture_tile_seam_check_write_tile_sheet": "write_tile_sheet()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L104 | neighbors=[tile_seam_check.py, main(), Tiled preview, so the seam can be looke…]
- "texture_uv_density_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L184 | neighbors=[uv_density.py, print_report(), report()]
- "texture_uv_density_parse_obj": "parse_obj()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L27 | neighbors=[uv_density.py, Return groups -> list of (v_idx, vt_idx…, report()]
- "tools_compare_math_cross": "compare_math_cross.py" | kind=code-symbol | source=mute/tools/compare_math_cross.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, run(), c7a411f Fix MUT-01-20 audit defects in …]
- "tools_g1_replay_probe": "g1_replay_probe.cpp" | kind=code-symbol | source=mute/tools/g1_replay_probe.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "tools_generate_math_reference": "generate_math_reference.py" | kind=code-symbol | source=mute/tools/generate_math_reference.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, bits(), c7a411f Fix MUT-01-20 audit defects in …]
- "tools_math_determinism_compare": "compare()" | kind=code-symbol | source=mute/tools/math_determinism.py:L78 | neighbors=[math_determinism.py, load_trace(), main()]
- "tools_math_determinism_load_corpus": "load_corpus()" | kind=code-symbol | source=mute/tools/math_determinism.py:L37 | neighbors=[math_determinism.py, _read(), main()]
- "tools_math_determinism_load_trace": "load_trace()" | kind=code-symbol | source=mute/tools/math_determinism.py:L56 | neighbors=[math_determinism.py, compare(), _read()]
- "tools_math_determinism_main": "main()" | kind=code-symbol | source=mute/tools/math_determinism.py:L90 | neighbors=[math_determinism.py, compare(), load_corpus()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-083.json

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
