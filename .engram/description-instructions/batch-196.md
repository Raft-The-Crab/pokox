# Node Description Batch 197 of 209

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
- "tools_generate_math_reference_bits": "bits()" | kind=code-symbol | source=mute/tools/generate_math_reference.py:L18 | neighbors=[generate_math_reference.py] | lang=en
- "tools_math_determinism_object": "_object()" | kind=code-symbol | source=mute/tools/math_determinism.py:L20 | neighbors=[math_determinism.py] | lang=en
- "tools_pkb_schema_draft_main": "main()" | kind=code-symbol | source=mute/tools/pkb_schema_draft.cpp:L12 | neighbors=[pkb_schema_draft.cpp] | lang=en
- "tools_program_bytecode_probe_main": "main()" | kind=code-symbol | source=mute/tools/program_bytecode_probe.cpp:L7 | neighbors=[program_bytecode_probe.cpp] | lang=en
- "tools_readme_hero_rationale_1": "Contact-sheet hero for the README. One loop: a render closing on its reference." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L1 | neighbors=[readme_hero.py] | lang=en
- "tools_readme_hero_rationale_42": "A small standing silhouette. Parameters are the things a bad first pass gets wro" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L42 | neighbors=[figure()] | lang=en
- "tools_run_tests_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/run_tests.py:L15 | neighbors=[run_tests.py] | lang=en
- "tools_state_determinism_probe_main": "main()" | kind=code-symbol | source=mute/tools/state_determinism_probe.cpp:L6 | neighbors=[state_determinism_probe.cpp] | lang=en
- "tools_validate_skills_print_report": "print_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L278 | neighbors=[validate_skills.py] | lang=en
- "tools_validate_skills_rationale_1": "Validate the gamedev skills library.  Checks the things that silently rot in a s" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L1 | neighbors=[validate_skills.py] | lang=en
- "tools_validate_skills_rationale_108": "Collect T-nn ids from the knowledge base.      Accepts either layout: the worksp" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L108 | neighbors=[collect_tech_ids()] | lang=en
- "tools_validate_skills_rationale_136": "Warnings when the COVERAGE.md summary table disagrees with its matrices.      Sk" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L136 | neighbors=[check_coverage()] | lang=en
- "tools_validate_skills_rationale_31": "Minimal YAML front-matter reader: enough for flat scalars and the     '>' folded" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L31 | neighbors=[parse_frontmatter()] | lang=en
- "tools_validate_skills_rationale_47": "Script names a SKILL.md or reference may mention (any skill's scripts, repo tool" | kind=entity | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L47 | neighbors=[known_py()] | lang=pt
- "tools_validate_skills_rationale_85": "Locate SKILL.md files, accepting either layout.      `root/.agents/skills/` is t" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L85 | neighbors=[find_skills()] | lang=en
- "towncity_city_paint_install": "install()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L200 | neighbors=[city_paint.py] | lang=en
- "towncity_city_paint_rationale_131": "polygon (list of Vector) clipped to lo <= f(p) <= hi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L131 | neighbors=[clip()] | lang=en
- "towncity_city_paint_rationale_27": "periodic FFT noise h x w in [-1, 1], feature frequency ~f per period" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L27 | neighbors=[pnoise()] | lang=en
- "towncity_city_paint_rationale_35": "1 inside a joint of half-width w (d = distance to the joint line in px), soft ed" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L35 | neighbors=[edge()] | lang=en
- "towncity_city_paint_rationale_46": "one periodic WP x HP tile at base shade s0 -> rgb" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L46 | neighbors=[tile()] | lang=en
- "towncity_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/hooks_lua.py:L5 | neighbors=[hooks_lua.py] | lang=en
- "towncity_town_landmarks_rationale_10": "box whose top is inset (mansard / hip roof / plinth taper)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L10 | neighbors=[frustum()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-196.json

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
