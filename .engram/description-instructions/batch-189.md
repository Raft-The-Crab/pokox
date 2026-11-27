# Node Description Batch 190 of 208

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

- "sugarworks_sugar_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L33 | neighbors=[sugar_map.py] | lang=en
- "sugarworks_sugar_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L252 | neighbors=[sugar_map.py] | lang=en
- "sugarworks_sugar_props_candy_corn": "candy_corn()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L408 | neighbors=[sugar_props.py] | lang=en
- "sugarworks_sugar_props_candy_crate": "candy_crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L276 | neighbors=[sugar_props.py] | lang=en
- "sugarworks_sugar_props_rationale_193": "button on a squat base with a price board on a post behind it (board faces -Z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L193 | neighbors=[buy_button()] | lang=pt
- "sugarworks_sugar_props_rock_cliff": "rock_cliff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L349 | neighbors=[sugar_props.py] | lang=en
- "systematic_debugging_condition_based_waiting_example_waitforevent": "waitForEvent()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L20 | neighbors=[condition-based-waiting-example.ts] | lang=en
- "systematic_debugging_condition_based_waiting_example_waitforeventcount": "waitForEventCount()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L60 | neighbors=[condition-based-waiting-example.ts] | lang=en
- "systematic_debugging_condition_based_waiting_example_waitforeventmatch": "waitForEventMatch()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L111 | neighbors=[condition-based-waiting-example.ts] | lang=en
- "targets_android_std_shim_bit_cast": "bit_cast()" | kind=code-symbol | source=tools/targets/android_std_shim.hpp:L20 | neighbors=[android_std_shim.hpp] | lang=en
- "targets_android_std_shim_from_chars": "from_chars()" | kind=code-symbol | source=tools/targets/android_std_shim.hpp:L33 | neighbors=[android_std_shim.hpp] | lang=en
- "tests_conftest_can_symlink": "_can_symlink()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L50 | neighbors=[conftest.py] | lang=en
- "tests_conftest_rationale_1": "Shared test setup for the effekseer-vfx skill.  vfxkit.paths computes the projec" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L1 | neighbors=[conftest.py] | lang=en
- "tests_conftest_rationale_13": "Generate a watertight 10mm cube STL on demand." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L13 | neighbors=[tmp_stl()] | lang=pt
- "tests_conftest_rationale_28": "CadQuery script that writes a watertight cube next to itself." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L28 | neighbors=[good_script()] | lang=en
- "tests_conftest_rationale_41": "CadQuery script that writes both an STL and a STEP next to itself." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L41 | neighbors=[step_script()] | lang=en
- "tests_conftest_rationale_55": "CadQuery script that raises (fillet radius too large)." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L55 | neighbors=[bad_script()] | lang=en
- "tests_conftest_rationale_66": "Script that exits 0 without writing any STL." | kind=entity | source=.agents/skills/cad-skill-main/tests/conftest.py:L66 | neighbors=[empty_script()] | lang=en
- "tests_conftest_rationale_69": "Environment for running `python -m vfxkit` in a subprocess with the scripts fold" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L69 | neighbors=[cli_env()] | lang=en
- "tests_conftest_rationale_79": "The shared temporary game project whose vfx/src holds the sixteen examples." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L79 | neighbors=[project()] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-189.json

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
