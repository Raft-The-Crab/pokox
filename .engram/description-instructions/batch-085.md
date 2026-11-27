# Node Description Batch 86 of 207

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

- "unit_statement_test_depth_guard": "depth_guard()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L61 | neighbors=[statement_test.cpp, check(), main()]
- "unit_statement_test_dump": "dump()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L15 | neighbors=[statement_test.cpp, cases(), check()]
- "unit_statement_test_randomized_input": "randomized_input()" | kind=code-symbol | source=mute/tests/unit/statement_test.cpp:L70 | neighbors=[statement_test.cpp, main(), check()]
- "unit_stdlib_collections_test": "stdlib_collections_test.cpp" | kind=code-symbol | source=mute/tests/unit/stdlib_collections_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, is_error(), main()]
- "unit_stdlib_math_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L24 | neighbors=[stdlib_math_test.cpp, near(), near_vec()]
- "unit_stdlib_math_test_near": "near()" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L20 | neighbors=[stdlib_math_test.cpp, main(), near_vec()]
- "unit_stdlib_math_test_near_vec": "near_vec()" | kind=code-symbol | source=mute/tests/unit/stdlib_math_test.cpp:L21 | neighbors=[stdlib_math_test.cpp, main(), near()]
- "unit_stress_test_bytecode_limits": "bytecode_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L40 | neighbors=[stress_test.cpp, check(), main()]
- "unit_stress_test_lexer_limits": "lexer_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L23 | neighbors=[stress_test.cpp, check(), main()]
- "unit_stress_test_package_limits": "package_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L87 | neighbors=[stress_test.cpp, main(), check()]
- "unit_stress_test_program_limits": "program_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L31 | neighbors=[stress_test.cpp, main(), check()]
- "unit_stress_test_scheduler_limits": "scheduler_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L72 | neighbors=[stress_test.cpp, main(), check()]
- "unit_stress_test_values_limits": "values_limits()" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L52 | neighbors=[stress_test.cpp, main(), check()]
- "unit_swapchain_frame_loop_test": "swapchain_frame_loop_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/swapchain_frame_loop_test.cpp:L1 | neighbors=[2960ac1 Android Vulkan clear: no fence …, 9eeb3ff Merge pull request #2 from Raft…, main()]
- "unit_test_parser_reference": "test_parser_reference.py" | kind=code-symbol | source=mute/tests/unit/test_parser_reference.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, expression(), reference()]
- "unit_test_verify_desktop": "test_verify_desktop.py" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, EvidenceTests, Evidence handling tests, not real SDK o…]
- "unit_visual_solver_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/visual_solver_test.cpp:L48 | neighbors=[visual_solver_test.cpp, dyn_sphere(), static_box()]
- "unit_vulkan_triangle_pass_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L24 | neighbors=[vulkan_triangle_pass_test.cpp, draw_and_present(), reset()]
- "unit_worker_auth_test_make_token": "make_token()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L38 | neighbors=[worker_auth_test.cpp, main(), sign_input()]
- "valleylake_paint_cracks": "cracks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L46 | neighbors=[paint.py, fnoise(), paint_block()]
- "valleylake_paint_install": "install()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L131 | neighbors=[paint.py, atlas(), patch the grove machinery: atlas instea…]
- "valleylake_paint_remap": "remap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L111 | neighbors=[paint.py, palette UVs (u column, v shade) -> atla…, tri()]
- "valleylake_paint_stamps": "stamps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L30 | neighbors=[paint.py, paint_block(), leaf / dab stamps: (value field, rim-hi…]
- "valleylake_valley_map_build_solid": "build_solid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L170 | neighbors=[valley_map.py, build(), free()]
- "valleylake_valley_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L125 | neighbors=[valley_map.py, hero_yaw(), place()]
- "valleylake_valley_map_lake_poly": "lake_poly()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L341 | neighbors=[valley_map.py, lake_R(), water()]
- "valleylake_valley_map_ledge_n": "ledge_n()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L550 | neighbors=[valley_map.py, cliff_mesh(), _prof_i()]
- "valleylake_valley_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L865 | neighbors=[valley_map.py, free(), H()]
- "valleylake_valley_map_path_d": "path_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L83 | neighbors=[valley_map.py, nature(), poly_d()]
- "valleylake_valley_map_preview_water": "preview_water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L392 | neighbors=[valley_map.py, lake_d(), preview-only water look (the exported L…]
- "valleylake_valley_map_prof_i": "_prof_i()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L536 | neighbors=[valley_map.py, prof(), ledge_n()]
- "valleylake_valley_map_rim_s": "rim_s()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L69 | neighbors=[valley_map.py, ground(), bowl coordinate: < 1 inside the rim; th…]
- "valleylake_valley_map_rock_dim": "rock_dim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L438 | neighbors=[valley_map.py, cliffs(), ground_rock()]
- "valleylake_valley_map_sand_w": "sand_w()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L58 | neighbors=[valley_map.py, H0(), nature()]
- "valleylake_valley_map_slabs": "slabs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L479 | neighbors=[valley_map.py, build_profile(), slab boundaries round the ring for tier…]
- "valleylake_valley_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L27 | neighbors=[valley_map.py, place(), static()]
- "valleylake_valley_map_surface_y": "surface_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L200 | neighbors=[valley_map.py, place_soft(), top surface under (x, z) by raycast ont…]
- "valleylake_valley_props_quad": "quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L450 | neighbors=[valley_props.py, flat rectangle in XY facing -Z (lattice…, timber_wall()]
- "valleylake_valley_props_rs": "RS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L132 | neighbors=[valley_props.py, boulder(), waterfall()]
- "vfxkit_briefs_timeline": "timeline()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L17 | neighbors=[briefs.py, Absolute first/last births, including p…, validate()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-085.json

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
