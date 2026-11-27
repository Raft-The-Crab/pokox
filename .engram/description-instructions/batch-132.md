# Node Description Batch 133 of 207

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

- "sugarworks_sugar_props_rationale_356": "pipe from the collector's side (origin) down to the cash pad 18 studs along -Z," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L356 | neighbors=[Palette, coin_chute()] | lang=en
- "sugarworks_sugar_props_rationale_366": "flat lemon/choc hazard stripe band along X, flush on the slab" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L366 | neighbors=[Palette, hazard()] | lang=en
- "sugarworks_sugar_props_rationale_373": "painted mint walkway along Z, cream edge dashes (lifted .02 off the slab: no cop" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L373 | neighbors=[Palette, walkway()] | lang=en
- "sugarworks_sugar_props_rationale_381": "pallet with tied sugar sacks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L381 | neighbors=[Palette, candy_sacks()] | lang=en
- "sugarworks_sugar_props_rationale_391": "three-tier chocolate fountain: pink bowls, chocolate pouring between them, pool" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L391 | neighbors=[Palette, choc_fountain()] | lang=en
- "sugarworks_sugar_props_rationale_419": "flat peppermint swirl stepping disc" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L419 | neighbors=[Palette, peppermint()] | lang=en
- "sugarworks_sugar_props_rationale_49": "candy-cane tube: alternating colour segments along a polyline" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L49 | neighbors=[Palette, stripes()] | lang=pt
- "sugarworks_sugar_props_rationale_62": "the plot slab: tiled concrete, pink border, chamfered edge; top at y 1.2" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L62 | neighbors=[Palette, plot_base()] | lang=en
- "sugarworks_sugar_props_rationale_72": "low cream wall + pink cap + team-colour glow strip between two posts (posts = fe" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L72 | neighbors=[Palette, fence()] | lang=en
- "sugarworks_sugar_props_rationale_82": "one fence post: cream pillar + pink gumdrop cap" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L82 | neighbors=[Palette, fence_post()] | lang=en
- "sugarworks_sugar_props_rationale_89": "owner gate: two striped pillars with gumdrop tops, sign board, glowing claim pad" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L89 | neighbors=[Palette, gate()] | lang=en
- "sugarworks_sugar_props_slot_marker": "slot_marker()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L210 | neighbors=[sugar_props.py, empty build slot: four lemon corner bra…] | lang=en
- "sugarworks_sugar_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L283 | neighbors=[sugar_props.py, torus()] | lang=en
- "sugarworks_sugar_props_walkway": "walkway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L372 | neighbors=[sugar_props.py, painted mint walkway along Z, cream edg…] | lang=en
- "sugarworks_sugar_props_wrapper_bin": "wrapper_bin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L427 | neighbors=[sugar_props.py, dome()] | lang=en
- "superpowers_main_index": "index.js" | kind=code-symbol | source=.agents/skills/superpowers-main/index.js:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "surfaceholder": "SurfaceHolder" | kind=code-symbol | neighbors=[PokoActivity.java, PokoActivity] | lang=en
- "surfaceview": "SurfaceView" | kind=code-symbol | neighbors=[PokoActivity.java, PokoActivity] | lang=en
- "targets_run_dual_target_tests_android_tools": "android_tools()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L156 | neighbors=[run_dual_target_tests.py, android_leg()] | lang=en
- "targets_run_dual_target_tests_main": "main()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L365 | neighbors=[run_dual_target_tests.py, now()] | lang=en
- "targets_run_dual_target_tests_msvc_tools": "msvc_tools()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L126 | neighbors=[run_dual_target_tests.py, windows_leg()] | lang=en
- "targets_run_dual_target_tests_write_log": "write_log()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L91 | neighbors=[run_dual_target_tests.py, run_command()] | lang=en
- "tests_conftest_bad_script": "bad_script()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/conftest.py:L54 | neighbors=[conftest.py, CadQuery script that raises (fillet rad…] | lang=en
- "tests_conftest_cli_env": "cli_env()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L68 | neighbors=[conftest.py, Environment for running `python -m vfxk…] | lang=en
- "tests_conftest_empty_script": "empty_script()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/conftest.py:L65 | neighbors=[conftest.py, Script that exits 0 without writing any…] | lang=en
- "tests_conftest_good_script": "good_script()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/conftest.py:L27 | neighbors=[conftest.py, CadQuery script that writes a watertigh…] | lang=en
- "tests_conftest_project": "project()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L78 | neighbors=[conftest.py, The shared temporary game project whose…] | lang=en
- "tests_conftest_step_script": "step_script()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/conftest.py:L40 | neighbors=[conftest.py, CadQuery script that writes both an STL…] | lang=en
- "tests_conftest_tmp_stl": "tmp_stl()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/conftest.py:L12 | neighbors=[conftest.py, Generate a watertight 10mm cube STL on …] | lang=en
- "tests_fixtures_unwrap": "unwrap()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L56 | neighbors=[fixtures.py, Smart-project UVs so bake/texel tests h…] | lang=en
- "tests_flags_contract": "flags_contract.cpp" | kind=code-symbol | source=engine/foundation/tests/flags_contract.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()] | lang=en
- "tests_run_all_fresh": "fresh()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L32 | neighbors=[run_all.py, main()] | lang=en
- "tests_run_all_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L49 | neighbors=[run_all.py, fresh()] | lang=en
- "tests_run_all_skill_module": "skill_module()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/run_all.py:L22 | neighbors=[run_all.py, Import skills/<skill>/scripts/<script>.…] | lang=en
- "tests_test_agent_loop_test_lint_accepts_a_cel_contact_and_a_restruck_painted_shape": "test_lint_accepts_a_cel_contact_and_a_restruck_painted_shape()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L65 | neighbors=[test_agent_loop.py, recipe()] | lang=en
- "tests_test_agent_loop_test_lint_passes_the_library_and_reports_each_hard_rule": "test_lint_passes_the_library_and_reports_each_hard_rule()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L49 | neighbors=[test_agent_loop.py, recipe()] | lang=en
- "tests_test_agent_loop_test_lint_warns_about_craft_problems": "test_lint_warns_about_craft_problems()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L78 | neighbors=[test_agent_loop.py, recipe()] | lang=en
- "tests_test_agent_loop_test_review_metrics_accept_a_well_formed_effect": "test_review_metrics_accept_a_well_formed_effect()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L112 | neighbors=[test_agent_loop.py, frames()] | lang=en
- "tests_test_agent_loop_test_review_metrics_do_not_flag_known_false_positives": "test_review_metrics_do_not_flag_known_false_positives()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L159 | neighbors=[test_agent_loop.py, frames()] | lang=en
- "tests_test_agent_loop_test_review_metrics_flag_off_peak_flash_flat_colour_and_wrong_direction": "test_review_metrics_flag_off_peak_flash_flat_colour_and_wrong_direction()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L129 | neighbors=[test_agent_loop.py, frames()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-132.json

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
