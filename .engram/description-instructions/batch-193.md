# Node Description Batch 194 of 207

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

- "tests_test_tools_test_letterbox_color_and_mask_align": "test_letterbox_color_and_mask_align()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L33 | neighbors=[test_tools.py] | lang=en
- "tests_test_tools_test_normalize_mask_wide_subject_not_squeezed": "test_normalize_mask_wide_subject_not_squeezed()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L52 | neighbors=[test_tools.py] | lang=en
- "tests_test_tools_test_uv_density_is_linear_px_per_m": "test_uv_density_is_linear_px_per_m()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L13 | neighbors=[test_tools.py] | lang=en
- "tests_test_tools_test_uv_density_scales_linearly_with_texel": "test_uv_density_scales_linearly_with_texel()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L25 | neighbors=[test_tools.py] | lang=en
- "tests_test_video_rationale_1": "Video-model flipbooks and the Unity pipeline, on a synthetic clip (a disc that g" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L1 | neighbors=[test_video.py] | lang=en
- "tests_test_video_rationale_131": "Runs without a vfx/ workspace and prints only what a cp1252 Windows console can" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L131 | neighbors=[test_unity_commands_need_no_workspace()] | lang=pt
- "tests_test_video_rationale_22": "48 frames at 24 fps: black, a warm disc grows to the middle of the clip, then sh" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L22 | neighbors=[clip()] | lang=en
- "tests_test_video_rationale_80": "40 frames of a textured set seen by a dollying 35 mm camera (Workbench, textured" | kind=entity | source=.agents/skills/blender-skills-main/tests/test_video.py:L80 | neighbors=[_footage()] | lang=en
- "tests_test_video_test_first_frame_puts_the_element_on_black_and_writes_a_black_last_frame": "test_first_frame_puts_the_element_on_black_and_writes_a_black_last_frame()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L65 | neighbors=[test_video.py] | lang=en
- "tests_test_video_test_flipbook_makes_a_gutter_sheet_and_records_the_prompt": "test_flipbook_makes_a_gutter_sheet_and_records_the_prompt()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L39 | neighbors=[test_video.py] | lang=en
- "tests_test_video_test_grade_fades_the_tail_and_lint_accepts_recorded_sheets": "test_grade_fades_the_tail_and_lint_accepts_recorded_sheets()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L53 | neighbors=[test_video.py] | lang=en
- "tests_test_video_test_help_prints_on_a_windows_console": "test_help_prints_on_a_windows_console()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L164 | neighbors=[test_video.py] | lang=en
- "tests_test_video_test_paths_names_and_bounds_from_review": "test_paths_names_and_bounds_from_review()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L140 | neighbors=[test_video.py] | lang=en
- "tests_test_video_test_video_body_plays_every_cell_once_or_stands_as_a_column": "test_video_body_plays_every_cell_once_or_stands_as_a_column()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L76 | neighbors=[test_video.py] | lang=en
- "tests_test_weather_test_lightning_keys_strokes_and_bolt": "test_lightning_keys_strokes_and_bolt()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_weather.py:L75 | neighbors=[test_weather.py] | lang=en
- "tests_test_weather_test_snow_geometry_and_vertex_mask": "test_snow_geometry_and_vertex_mask()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_weather.py:L57 | neighbors=[test_weather.py] | lang=en
- "tests_test_weather_test_surface_weather_roundtrip_restores_materials": "test_surface_weather_roundtrip_restores_materials()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_weather.py:L33 | neighbors=[test_weather.py] | lang=en
- "tests_test_workflow_lab": "lab()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L54 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_rationale_1": "Workflow contracts: no stale evidence, dropped key moments or unlabelled referen" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L1 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_rationale_46": "Point the workspace-relative modules at an empty project (ROOT) and its work/ st" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L46 | neighbors=[isolated()] | lang=en
- "tests_test_workflow_test_briefs_expand_child_births_and_validate_the_shipped_examples": "test_briefs_expand_child_births_and_validate_the_shipped_examples()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L16 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_test_flipbook_integer_fields_are_rejected_before_native_compilation": "test_flipbook_integer_fields_are_rejected_before_native_compilation()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L38 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_test_frame_plan_keeps_contact_and_flags_static_or_missing_capture": "test_frame_plan_keeps_contact_and_flags_static_or_missing_capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L181 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_test_project_lock_is_reentrant_within_a_process": "test_project_lock_is_reentrant_within_a_process()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L279 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_test_project_lock_serializes_two_independent_processes": "test_project_lock_serializes_two_independent_processes()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L249 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_test_reference_clock_and_real_ffmpeg_import": "test_reference_clock_and_real_ffmpeg_import()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L214 | neighbors=[test_workflow.py] | lang=en
- "tests_test_workflow_test_texture_checks_distinguish_intentional_blank_from_bad_grid": "test_texture_checks_distinguish_intentional_blank_from_bad_grid()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L197 | neighbors=[test_workflow.py] | lang=en
- "texture_tex_to_maps_rationale_1": "Derive PBR maps from a single albedo image.  Game textures usually arrive as one" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L1 | neighbors=[tex_to_maps.py] | lang=en
- "texture_tex_to_maps_rationale_38": "Box blur via integral image. O(1) per pixel regardless of radius.      A gaussia" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L38 | neighbors=[blur()] | lang=pt
- "texture_tex_to_maps_rationale_58": "Luminance minus its local mean: the detail that a normal map encodes." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L58 | neighbors=[high_pass()] | lang=en
- "texture_tex_to_maps_rationale_63": "Dark, matte surfaces read rougher; highlights read smoother.      The mapping is" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L63 | neighbors=[derive_roughness()] | lang=en
- "texture_tex_to_maps_rationale_74": "Sobel the high-pass band and encode as a tangent-space normal.      Scaling by `" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L74 | neighbors=[derive_normal()] | lang=en
- "texture_tex_to_maps_rationale_87": "Cavity estimate: pixels darker than their neighbourhood are occluded.      This" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L87 | neighbors=[derive_ao()] | lang=en
- "texture_tile_seam_check_rationale_1": "Detect visible seams in a tiling texture.  The test is not \"does it look OK when" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L1 | neighbors=[tile_seam_check.py] | lang=en
- "texture_tile_seam_check_rationale_105": "Tiled preview, so the seam can be looked at and not only measured." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L105 | neighbors=[write_tile_sheet()] | lang=en
- "texture_tile_seam_check_rationale_42": "Compare the wrap edge against every interior adjacent pair.      `percentile` an" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L42 | neighbors=[boundary_metrics()] | lang=en
- "texture_uv_density_rationale_1": "Measure texel density across the parts of a mesh.  Density is linear: texture pi" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L1 | neighbors=[uv_density.py] | lang=en
- "texture_uv_density_rationale_28": "Return groups -> list of (v_idx, vt_idx) triangles plus vertex positions.      O" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L28 | neighbors=[parse_obj()] | lang=en
- "tools_compare_math_cross_run": "run()" | kind=code-symbol | source=mute/tools/compare_math_cross.py:L24 | neighbors=[compare_math_cross.py] | lang=en
- "tools_g1_replay_probe_main": "main()" | kind=code-symbol | source=mute/tools/g1_replay_probe.cpp:L13 | neighbors=[g1_replay_probe.cpp] | lang=en

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
