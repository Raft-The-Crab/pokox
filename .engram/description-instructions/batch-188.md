# Node Description Batch 189 of 207

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

- "tests_conftest_can_symlink": "_can_symlink()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L50 | neighbors=[conftest.py] | lang=en
- "tests_conftest_rationale_1": "Shared test setup for the effekseer-vfx skill.  vfxkit.paths computes the projec" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L1 | neighbors=[conftest.py] | lang=en
- "tests_conftest_rationale_13": "Generate a watertight 10mm cube STL on demand." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L13 | neighbors=[tmp_stl()] | lang=pt
- "tests_conftest_rationale_28": "CadQuery script that writes a watertight cube next to itself." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L28 | neighbors=[good_script()] | lang=en
- "tests_conftest_rationale_41": "CadQuery script that writes both an STL and a STEP next to itself." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L41 | neighbors=[step_script()] | lang=en
- "tests_conftest_rationale_55": "CadQuery script that raises (fillet radius too large)." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L55 | neighbors=[bad_script()] | lang=en
- "tests_conftest_rationale_66": "Script that exits 0 without writing any STL." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L66 | neighbors=[empty_script()] | lang=en
- "tests_conftest_rationale_69": "Environment for running `python -m vfxkit` in a subprocess with the scripts fold" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L69 | neighbors=[cli_env()] | lang=en
- "tests_conftest_rationale_79": "The shared temporary game project whose vfx/src holds the sixteen examples." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L79 | neighbors=[project()] | lang=en
- "tests_dependency_smoke": "dependency_smoke.cpp" | kind=code-symbol | source=engine/foundation/tests/dependency_smoke.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "tests_fixtures_rationale_1": "Procedural test fixtures (no binary .blend files in the repo)." | kind=entity | source=.agents/skills/blender-skills-main/tests/fixtures.py:L1 | neighbors=[fixtures.py] | lang=en
- "tests_fixtures_rationale_34": "Two coplanar overlapping planes in different objects + one inside a single mesh." | kind=entity | source=.agents/skills/blender-skills-main/tests/fixtures.py:L34 | neighbors=[zfight_pair()] | lang=en
- "tests_fixtures_rationale_47": "A body with a floating island and a separate floating object." | kind=entity | source=.agents/skills/blender-skills-main/tests/fixtures.py:L47 | neighbors=[detached_part()] | lang=pt
- "tests_fixtures_rationale_57": "Smart-project UVs so bake/texel tests have a UV map." | kind=entity | source=.agents/skills/blender-skills-main/tests/fixtures.py:L57 | neighbors=[unwrap()] | lang=pt
- "tests_fixtures_rationale_68": "Ground slab (top at z=0), two buildings, a grey sphere, each with a Principled m" | kind=entity | source=.agents/skills/blender-skills-main/tests/fixtures.py:L68 | neighbors=[street()] | lang=pt
- "tests_fixtures_rationale_89": "Capsule-ish mesh + 3-bone chain armature, auto-weighted. Returns (mesh, armature" | kind=entity | source=.agents/skills/blender-skills-main/tests/fixtures.py:L89 | neighbors=[simple_character()] | lang=en
- "tests_flags_contract_main": "main()" | kind=code-symbol | source=engine/foundation/tests/flags_contract.cpp:L7 | neighbors=[flags_contract.cpp] | lang=en
- "tests_run_all_rationale_1": "In-Blender test runner. Discovers tests/test_*.py, runs each test_* on a fresh e" | kind=entity | source=.agents/skills/blender-skills-main/tests/run_all.py:L1 | neighbors=[run_all.py] | lang=pt
- "tests_run_all_rationale_23": "Import skills/<skill>/scripts/<script>.py fresh (tests call run() directly)." | kind=entity | source=.agents/skills/blender-skills-main/tests/run_all.py:L23 | neighbors=[skill_module()] | lang=en
- "tests_run_all_rationale_44": "Skip when BAS_SKIP_GPU=1 (CI runners without GPU/EGL: EEVEE, Workbench renders)." | kind=entity | source=.agents/skills/blender-skills-main/tests/run_all.py:L44 | neighbors=[requires_gpu()] | lang=en
- "tests_test_addon_test_template_validates_builds_and_registers": "test_template_validates_builds_and_registers()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_addon.py:L11 | neighbors=[test_addon.py] | lang=en
- "tests_test_agent_loop_rationale_1": "Agent feedback loop: field validation, static lint, review metrics, iteration hi" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L1 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_rationale_102": "plan: {frame: [(box, colour), ...]} with boxes relative to the review crop." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L102 | neighbors=[frames()] | lang=en
- "tests_test_agent_loop_test_library_recipes_use_only_known_fields": "test_library_recipes_use_only_known_fields()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L33 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_test_metrics_baseline_is_compact_and_round_trips": "test_metrics_baseline_is_compact_and_round_trips()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L219 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_test_misspelt_and_nested_unknown_fields_are_rejected_with_suggestions": "test_misspelt_and_nested_unknown_fields_are_rejected_with_suggestions()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L15 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_test_review_metrics_flag_dead_tail_and_invisible_effects": "test_review_metrics_flag_dead_tail_and_invisible_effects()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L185 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_test_round_diff_history_and_comparison_sheet": "test_round_diff_history_and_comparison_sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L201 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_test_shipped_painted_textures_are_measurable_game_textures": "test_shipped_painted_textures_are_measurable_game_textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L243 | neighbors=[test_agent_loop.py] | lang=en
- "tests_test_agent_loop_test_texture_measurement_finds_crescent_bulge_and_clipping": "test_texture_measurement_finds_crescent_bulge_and_clipping()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L229 | neighbors=[test_agent_loop.py] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-188.json

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
