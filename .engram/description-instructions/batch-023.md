# Node Description Batch 24 of 209

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

- "unit_character_controller_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L120 | neighbors=[character_controller_test.cpp, aabb(), params(), tod(), todv(), v3()]
- "unit_config_logging_guard_test": "config_logging_guard_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/config_logging_guard_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, info(), init(), main(), shutdown(), 52dbcb9 Surface graphics warnings in X1…]
- "unit_debugger_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L20 | neighbors=[debugger_test.cpp, arith(), check(), divzero(), imm(), pay()]
- "unit_fold_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L41 | neighbors=[fold_test.cpp, check(), count_op(), i32t(), run_source(), val()]
- "unit_input_snapshot_test_record_hashes": "record_hashes()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L43 | neighbors=[input_snapshot_test.cpp, main(), button(), key(), motion(), simple()]
- "unit_semantic_test": "semantic_test.cpp" | kind=code-symbol | source=mute/tests/unit/semantic_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, cases(), error(), main(), ok(), 52dbcb9 Surface graphics warnings in X1…]
- "unit_solver_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L49 | neighbors=[solver_test.cpp, body(), contact(), fx(), statics(), tod()]
- "unit_ssa_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L28 | neighbors=[ssa_test.cpp, check(), has(), i32(), v(), valid_module()]
- "unit_stdlib_math_test": "stdlib_math_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 5eb3f50 Mute det_pow: integer-exponent …, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, main(), near()]
- "unit_values_test": "values_test.cpp" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L1 | neighbors=[5edd00c Fix MUT-21/22 audit defects in …, 964ba8a Resolve MUT-22 values runtime l…, e685cdf Add MUT-22 aggregate VM value a…, cases(), check(), main()]
- "valleylake_valley_map_build_profile": "build_profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L490 | neighbors=[valley_map.py, build(), foot_need(), H(), rim_point(), rim_r()]
- "valleylake_valley_map_cliff_clear": "cliff_clear()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L558 | neighbors=[valley_map.py, H(), prof(), cliffs(), clip_fail(), nature()]
- "valleylake_valley_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L239 | neighbors=[valley_map.py, build(), H(), polar(), prof(), rim_s()]
- "valleylake_valley_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L206 | neighbors=[valley_map.py, build(), clip_fail(), place(), surface_y(), unplace()]
- "valleylake_valley_map_prof": "prof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L551 | neighbors=[valley_map.py, cliff_clear(), cliffs(), ground(), polar(), _prof_i()]
- "valleylake_valley_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L229 | neighbors=[valley_map.py, beach(), cliff_mesh(), ground(), paths(), sub()]
- "valleylake_valley_map_stations_and_village": "stations_and_village()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L661 | neighbors=[valley_map.py, build(), anchor(), face(), in_terr(), place()]
- "valleylake_valley_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L589 | neighbors=[valley_props.py, flat(), .add(), V(), crates(), dock()]
- "valleylake_valley_props_trunk": "trunk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L233 | neighbors=[valley_props.py, blossom_tree(), broadleaf(), gnarled_tree(), pine(), .add()]
- "vfxkit_briefs": "briefs.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, keyframes(), read(), timeline(), validate()]
- "vfxkit_cli": "cli.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/cli.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main(), parser(), recipes_for(), run()]
- "vfxkit_evidence_build_issues": "build_issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L112 | neighbors=[evidence.py, current_recipe(), inputs(), read_build(), capture_issues(), context()]
- "vfxkit_paths": "paths.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, full_mode_platform(), godot(), initialized(), setup_command()]
- "vfxkit_textures_masks": "masks()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L32 | neighbors=[textures.py, flame_band(), spectral(), speed_streaks(), swirl(), worley()]
- "vm_register_vm": "register_vm.cpp" | kind=code-symbol | source=mute/src/vm/register_vm.cpp:L1 | neighbors=[85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, run_register_module(), run_register_vm(), 52dbcb9 Surface graphics warnings in X1…]
- "voidrealm_void_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L58 | neighbors=[void_map.py, bridges(), build_paths(), island_of(), top_y(), place()]
- "voidrealm_void_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L113 | neighbors=[void_map.py, bridges(), build(), build_paths(), dressing(), ring_scatter()]
- "voidrealm_void_map_rfun": "Rfun()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L44 | neighbors=[void_map.py, dressing(), edge_pt(), island(), island_of(), ring_scatter()]
- "voidrealm_void_props_arena_rim": "arena_rim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L571 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), V()]
- "voidrealm_void_props_brazier": "brazier()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L334 | neighbors=[void_props.py, annulus(), chamfer_box(), flame(), FS(), V()]
- "voidrealm_void_props_crystal_cluster": "crystal_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L108 | neighbors=[void_props.py, FS(), shaft(), shard_rock(), V(), heart_crystal()]
- "voidrealm_void_props_crystal_lantern": "crystal_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L306 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), V()]
- "voidrealm_void_props_lift_pad": "lift_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L741 | neighbors=[void_props.py, annulus(), disc(), FS(), shaft(), V()]
- "voidrealm_void_props_shard_rock": "shard_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L98 | neighbors=[void_props.py, crystal_chips(), crystal_cluster(), float_shard(), angular obsidian chunk: hull of few poi…, rubble()]
- "voidrealm_void_props_station_dais": "station_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L419 | neighbors=[void_props.py, quest_stand(), shared station base: stepped octagonal …, rift_gate(), shop_kiosk(), annulus()]
- "voidrealm_void_props_void_arch": "void_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L245 | neighbors=[void_props.py, ruined gateway arch: two square piers w…, chamfer_box(), disc(), FS(), rune_glyph()]
- "warehouse_kitlib_sub": "Sub" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L45 | neighbors=[kitlib.py, a reusable sub-assembly emitted into pr…, Palette, .add(), .emit(), .gadd()]
- "whispering_grove_forest_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L151 | neighbors=[forest_map.py, build(), foot(), H(), kit(), sub()]
- "whispering_grove_forest_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L191 | neighbors=[forest_props.py, at(), blob(), leafy(), Prop, .add()]
- "whispering_grove_forest_props_quest_board": "quest_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L419 | neighbors=[forest_props.py, at(), blob(), Prop, .add(), .gadd()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-023.json

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
