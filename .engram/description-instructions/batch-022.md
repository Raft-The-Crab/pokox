# Node Description Batch 23 of 207

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

- "towncity_city_paint_clip": "clip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L130 | neighbors=[city_paint.py, edge(), paint_glass(), ramp(), polygon (list of Vector) clipped to lo …, remap()]
- "towncity_town_landmarks_clock_tower": "clock_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L170 | neighbors=[town_landmarks.py, arch_open(), clock_face(), cslab(), _merge(), T_point()]
- "towncity_town_map_flat": "flat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L105 | neighbors=[town_map.py, U(), ground(), markings(), median(), square()]
- "towncity_town_map_traffic": "traffic()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L466 | neighbors=[town_map.py, build(), parked cars along curbs + a few cars in…, anchor(), near_intersection(), place()]
- "towncity_town_props_deco_window": "deco_window()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L247 | neighbors=[town_props.py, building(), add(), front_quad(), ring_frame(), slab()]
- "towncity_town_props_fire_escape": "fire_escape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L463 | neighbors=[town_props.py, building(), add(), lerp(), slab(), V3()]
- "towncity_town_props_front_quad": "front_quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L100 | neighbors=[town_props.py, building(), deco_window(), quad(), a single quad facing -Z at depth z, shopfront()]
- "towncity_town_props_shopfront": "shopfront()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L264 | neighbors=[town_props.py, building(), ground floor front: pilasters, bulkhead…, add(), awning_band(), front_quad()]
- "towncity_town_props_slab": "slab()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L53 | neighbors=[town_props.py, building(), deco_window(), fire_escape(), holed_front(), axis box between the given bounds; drop…]
- "towncity_town_props_v3": "V3()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L47 | neighbors=[town_props.py, awning_band(), fire_escape(), flower(), flower_box(), ring_frame()]
- "towncity_town_vehicles_car": "car()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L53 | neighbors=[town_vehicles.py, body_shader(), body_shell(), _smoothstep(), taxi(), wheels()]
- "unit_capability_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L60 | neighbors=[capability_test.cpp, ceiling(), check(), def(), narrowed_module(), run_err()]
- "unit_character_controller_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L120 | neighbors=[character_controller_test.cpp, aabb(), params(), tod(), todv(), v3()]
- "unit_debugger_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/debugger_test.cpp:L20 | neighbors=[debugger_test.cpp, arith(), check(), divzero(), imm(), pay()]
- "unit_fold_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/fold_test.cpp:L41 | neighbors=[fold_test.cpp, check(), count_op(), i32t(), run_source(), val()]
- "unit_input_snapshot_test_record_hashes": "record_hashes()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L43 | neighbors=[input_snapshot_test.cpp, main(), button(), key(), motion(), simple()]
- "unit_lexer_contract_test": "lexer_contract_test.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, check(), deterministic_streams(), diagnostic(), examples(), main()]
- "unit_solver_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/solver_test.cpp:L49 | neighbors=[solver_test.cpp, body(), contact(), fx(), statics(), tod()]
- "unit_ssa_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/ssa_test.cpp:L28 | neighbors=[ssa_test.cpp, check(), has(), i32(), v(), valid_module()]
- "unit_stdlib_math_test": "stdlib_math_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 5eb3f50 Mute det_pow: integer-exponent …, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, main(), near()]
- "unit_values_test": "values_test.cpp" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L1 | neighbors=[5edd00c Fix MUT-21/22 audit defects in …, 964ba8a Resolve MUT-22 values runtime l…, e685cdf Add MUT-22 aggregate VM value a…, cases(), check(), main()]
- "unit_vulkan_triangle_pass_test": "vulkan_triangle_pass_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, draw_and_present(), main(), messages(), reset(), VulkanClearRenderer()]
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
- "voidrealm_void_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L58 | neighbors=[void_map.py, bridges(), build_paths(), island_of(), top_y(), place()]
- "voidrealm_void_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L113 | neighbors=[void_map.py, bridges(), build(), build_paths(), dressing(), ring_scatter()]
- "voidrealm_void_map_rfun": "Rfun()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L44 | neighbors=[void_map.py, dressing(), edge_pt(), island(), island_of(), ring_scatter()]
- "voidrealm_void_props_arena_rim": "arena_rim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L571 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), V()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-022.json

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
