# Node Description Batch 193 of 209

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

- "tests_test_geonodes_test_reference_recipes_build_and_evaluate": "test_reference_recipes_build_and_evaluate()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L63 | neighbors=[test_geonodes.py] | lang=en
- "tests_test_geonodes_test_repeat_zone": "test_repeat_zone()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_geonodes.py:L48 | neighbors=[test_geonodes.py] | lang=en
- "tests_test_golden_goldenharnesstests_setup": ".setUp()" | kind=code-symbol | source=tools/testutils/harness/tests/test_golden.py:L18 | neighbors=[GoldenHarnessTests] | lang=en
- "tests_test_gridfinity_test_bad_notch_side_raises": "test_bad_notch_side_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L183 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_compartments_only_once": "test_compartments_only_once()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L171 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_cylinder_pocket_tilt_limits": "test_cylinder_pocket_tilt_limits()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L94 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_notch_offset_past_wall_raises": "test_notch_offset_past_wall_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L112 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_oversized_cylinder_pocket_raises": "test_oversized_cylinder_pocket_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L88 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_oversized_pocket_raises": "test_oversized_pocket_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L147 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_pocket_radii_exceed_size_raises": "test_pocket_radii_exceed_size_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L189 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_polygon_needs_three_points": "test_polygon_needs_three_points()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L195 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_screws_need_thick_floor": "test_screws_need_thick_floor()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L177 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_thin_divider_raises": "test_thin_divider_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L159 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_too_deep_pocket_raises": "test_too_deep_pocket_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L153 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_too_many_compartments_raises": "test_too_many_compartments_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L165 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_gridfinity_test_zero_grid_raises": "test_zero_grid_raises()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L201 | neighbors=[test_gridfinity.py] | lang=en
- "tests_test_materials_test_presets_and_srgb_color_override": "test_presets_and_srgb_color_override()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_materials.py:L33 | neighbors=[test_materials.py] | lang=en
- "tests_test_mating_test_overlap_zero_when_apart": "test_overlap_zero_when_apart()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mating.py:L20 | neighbors=[test_mating.py] | lang=en
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
