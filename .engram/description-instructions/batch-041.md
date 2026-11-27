# Node Description Batch 42 of 208

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

- "unit_package_test": "package_test.cpp" | kind=code-symbol | source=mute/tests/unit/package_test.cpp:L1 | neighbors=[c7e951a Add MUT-21 package, import and …, cases(), expect_error(), expect_ok(), main()]
- "unit_parser_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L40 | neighbors=[parser_test.cpp, check(), parse_error(), tree(), main()]
- "unit_parser_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/parser_test.cpp:L12 | neighbors=[parser_test.cpp, cases(), randomized_input(), stress(), tree()]
- "unit_replay_ring_test": "replay_ring_test.cpp" | kind=code-symbol | source=server/authority/tests/unit/replay_ring_test.cpp:L1 | neighbors=[6e2fe3a Created BAK-7 and other BAK tas…, check(), main(), same_event(), same_tick()]
- "unit_run_seed_checks": "run_seed_checks.py" | kind=code-symbol | source=engine/rhi/tests/unit/run_seed_checks.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, run(), Portable GCC/Clang-compatible seed chec…, c7a411f Fix MUT-01-20 audit defects in …]
- "unit_sap_broadphase_test": "sap_broadphase_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/sap_broadphase_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, box(), lo(), main(), sorted_pairs()]
- "unit_scheduler_test": "scheduler_test.cpp" | kind=code-symbol | source=mute/tests/unit/scheduler_test.cpp:L1 | neighbors=[435b4d3 Add MUT-23 cooperative async sc…, cases(), check(), fin(), main()]
- "unit_statement_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L36 | neighbors=[statement_test.cpp, check(), dump(), error(), main()]
- "unit_statement_test_check": "check()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L12 | neighbors=[statement_test.cpp, cases(), depth_guard(), dump(), randomized_input()]
- "unit_stdlib_physics_test": "stdlib_physics_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L1 | neighbors=[2680d0e Pushed an update., 7eabc2d Merge pull request #8 from Raft…, box_at(), main(), test_physics_hostcalls()]
- "unit_test_math_determinism_tracetests_write": ".write()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L20 | neighbors=[TraceTests, .check_invalid(), .test_corpus_corruption_rejected(), .test_match_is_only_agreement(), .test_same_target_is_not_cross_platform…]
- "unit_worker_auth_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L72 | neighbors=[worker_auth_test.cpp, check(), make_token(), sample_ticket(), test_key()]
- "valleylake_valley_map_cliff_mesh": "cliff_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L569 | neighbors=[valley_map.py, ledge_n(), rim_point(), static(), cliffs()]
- "valleylake_valley_map_clip_fail": "clip_fail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L184 | neighbors=[valley_map.py, cliff_clear(), inside(), place_soft(), True if a placed soft prop clips into s…]
- "valleylake_valley_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L226 | neighbors=[valley_map.py, build(), cliffs(), shore(), stations_and_village()]
- "valleylake_valley_map_foot_need": "foot_need()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L463 | neighbors=[valley_map.py, build_profile(), polar(), rim_r(), minimum foot offset per sample so every…]
- "valleylake_valley_map_paths": "paths()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L284 | neighbors=[valley_map.py, build(), H(), static(), dirt paths = draped ribbons 0.12 over t…]
- "valleylake_valley_map_polar": "polar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L431 | neighbors=[valley_map.py, foot_need(), ground(), rim_r(), prof()]
- "valleylake_valley_map_rope_lines": "rope_lines()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L726 | neighbors=[valley_map.py, build(), lantern rope lines: tall poles in a cha…, place(), reserve()]
- "valleylake_valley_map_terrace": "terrace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L705 | neighbors=[valley_map.py, build(), NE terrace: stone retaining walls (8-st…, place(), reserve()]
- "valleylake_valley_map_terrace_walls": "terrace_walls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L713 | neighbors=[valley_map.py, build(), retaining walls along the terrace's sou…, place(), stream_d()]
- "valleylake_valley_map_wlevel": "wlevel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L109 | neighbors=[valley_map.py, H(), stream water level at a centreline poin…, water(), H0()]
- "valleylake_valley_props_bark": "bark()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L878 | neighbors=[valley_props.py, .add(), broadleaf(), gnarled_tree(), bark grooves (noise stretched along the…]
- "valleylake_valley_props_clump": "clump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L190 | neighbors=[valley_props.py, blossom_tree(), leaf_cluster(), leaf_mass(), waterfall()]
- "valleylake_valley_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L574 | neighbors=[valley_props.py, .add(), crates(), dock(), market_stall()]
- "valleylake_valley_props_footbridge": "footbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L721 | neighbors=[valley_props.py, flat(), .add(), V(), small arched plank bridge over the stre…]
- "valleylake_valley_props_lantern_post": "lantern_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L662 | neighbors=[valley_props.py, flat(), .add(), V(), low wooden lantern post for the shore p…]
- "valleylake_valley_props_lantern_rope": "lantern_rope()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L651 | neighbors=[valley_props.py, flat(), paper_lantern(), .add(), rope span along +X from x 0 (left arm t…]
- "valleylake_valley_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L43 | neighbors=[valley_props.py, gnarled_tree(), limb(), merged_crown(), .grow()]
- "valleylake_valley_props_merged_crown": "merged_crown()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L1039 | neighbors=[valley_props.py, broadleaf(), leaf_mass(), lerp(), tip masses pulled toward one crown heig…]
- "valleylake_valley_props_rock_steps": "rock_steps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L820 | neighbors=[valley_props.py, rounded stepping stones across the stre…, rounded_mass(), .add(), V()]
- "valleylake_valley_props_roots": "roots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L929 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), buttress roots gripping the ground: sta…, .add()]
- "valleylake_valley_props_rope_pole": "rope_pole()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L640 | neighbors=[valley_props.py, tall timber pole with a cross arm + str…, flat(), .add(), V()]
- "valleylake_valley_props_stone_stair": "stone_stair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L765 | neighbors=[valley_props.py, stone flight up the retaining wall (fro…, rounded_mass(), .add(), V()]
- "valleylake_valley_props_stone_wall": "stone_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L740 | neighbors=[valley_props.py, retaining wall module (front = -Z): cou…, rounded_mass(), .add(), V()]
- "vfxkit_evidence_inputs": "inputs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L56 | neighbors=[evidence.py, build_issues(), portable(), prepared(), write_build()]
- "vfxkit_evidence_latest": "latest()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L245 | neighbors=[evidence.py, context(), read_capture(), store(), verify()]
- "vfxkit_evidence_read_build": "read_build()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L107 | neighbors=[evidence.py, build_issues(), capture_issues(), store(), write_capture()]
- "vfxkit_evidence_submit": "submit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L215 | neighbors=[evidence.py, capture_issues(), now(), read_capture(), store()]
- "vfxkit_evidence_write_build": "write_build()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L77 | neighbors=[evidence.py, inputs(), now(), outputs(), store()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-041.json

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
