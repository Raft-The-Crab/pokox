# Node Description Batch 81 of 207

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

- "src_soft_body_create": "create()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L161 | neighbors=[soft_body.cpp, add_node(), add_spring()]
- "src_soft_body_create_lattice": "create_lattice()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L18 | neighbors=[soft_body.cpp, add_node(), add_spring()]
- "src_soft_body_step": "step()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L100 | neighbors=[soft_body.cpp, apply_acceleration(), clamp01()]
- "src_solver_clear": "clear()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L63 | neighbors=[solver.cpp, begin_step(), solve()]
- "src_solver_solve": "solve()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L87 | neighbors=[solver.cpp, clear(), tangent_basis()]
- "src_visual_solver_begin_step": "begin_step()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L164 | neighbors=[visual_solver.cpp, clear(), step()]
- "src_visual_solver_clampf": "clampf()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L44 | neighbors=[visual_solver.cpp, collide_sphere_box(), solve()]
- "src_visual_solver_clear": "clear()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L150 | neighbors=[visual_solver.cpp, begin_step(), solve()]
- "src_visual_solver_collide_sphere_box": "collide_sphere_box()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L67 | neighbors=[visual_solver.cpp, clampf(), collide_visual()]
- "src_visual_solver_find_body": "find_body()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L156 | neighbors=[visual_solver.cpp, add_body(), step()]
- "src_visual_solver_upsert_body": "upsert_body()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L133 | neighbors=[visual_solver.cpp, add_body(), step()]
- "state_state_snapshot_load_state_snapshot": "load_state_snapshot()" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L46 | neighbors=[state_snapshot.cpp, read_le(), schema_for()]
- "state_state_snapshot_save_state_snapshot": "save_state_snapshot()" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L30 | neighbors=[state_snapshot.cpp, append_le(), schema_for()]
- "state_state_snapshot_schema_for": "schema_for()" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L21 | neighbors=[state_snapshot.cpp, load_state_snapshot(), save_state_snapshot()]
- "stdlib_stdlib_crypto_compress": "compress()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L22 | neighbors=[stdlib_crypto.cpp, rotr(), sha256()]
- "stdlib_stdlib_math_det_lerp": "det_lerp()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L27 | neighbors=[stdlib_math.cpp, vec2_lerp(), vec3_lerp()]
- "stdlib_stdlib_math_quat_normalize": "quat_normalize()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L115 | neighbors=[stdlib_math.cpp, det_sqrt(), quat_rotate()]
- "stdlib_stdlib_math_vec2_length_squared": "vec2_length_squared()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L60 | neighbors=[stdlib_math.cpp, vec2_dot(), vec2_normalize()]
- "stdlib_stdlib_math_vec2_normalize": "vec2_normalize()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L61 | neighbors=[stdlib_math.cpp, det_sqrt(), vec2_length_squared()]
- "stdlib_stdlib_math_vec3_length_squared": "vec3_length_squared()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L78 | neighbors=[stdlib_math.cpp, vec3_dot(), vec3_normalize()]
- "stdlib_stdlib_math_vec3_normalize": "vec3_normalize()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L79 | neighbors=[stdlib_math.cpp, det_sqrt(), vec3_length_squared()]
- "stdlib_stdlib_math_vec4_normalize": "vec4_normalize()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L89 | neighbors=[stdlib_math.cpp, det_sqrt(), vec4_dot()]
- "stdlib_stdlib_physics_physics_hostcall_defs": "physics_hostcall_defs()" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L82 | neighbors=[stdlib_physics.cpp, fixed_from_raw(), physics_raycast()]
- "stdlib_stdlib_physics_physics_raycast": "physics_raycast()" | kind=code-symbol | source=mute/src/stdlib/stdlib_physics.cpp:L36 | neighbors=[stdlib_physics.cpp, physics_hostcall_defs(), touching_at()]
- "stdlib_stdlib_string_codepoint_count": "codepoint_count()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L58 | neighbors=[stdlib_string.cpp, decode(), valid_utf8()]
- "stdlib_stdlib_string_slice_codepoints": "slice_codepoints()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L66 | neighbors=[stdlib_string.cpp, decode(), valid_utf8()]
- "sugarworks_sugar_kit_sheet": "sugar_kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "sugarworks_sugar_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L48 | neighbors=[sugar_map.py, build(), plot()]
- "sugarworks_sugar_map_local": "local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L49 | neighbors=[sugar_map.py, plot(), plot-local (lx, lz) -> world; local -Z …]
- "sugarworks_sugar_props_buy_button": "buy_button()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L192 | neighbors=[sugar_props.py, torus(), button on a squat base with a price boa…]
- "sugarworks_sugar_props_coin_chute": "coin_chute()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L355 | neighbors=[sugar_props.py, torus(), pipe from the collector's side (origin)…]
- "sugarworks_sugar_props_conveyor": "conveyor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L131 | neighbors=[sugar_props.py, sphere(), belt segment along X: legs, dark belt w…]
- "sugarworks_sugar_props_lollipop_tree": "lollipop_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L224 | neighbors=[sugar_props.py, dome(), torus()]
- "sugarworks_sugar_props_upgrader": "upgrader()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L151 | neighbors=[sugar_props.py, scanner arch over the belt: two steel p…, torus()]
- "targets_android_std_shim": "android_std_shim.hpp" | kind=code-symbol | source=tools/targets/android_std_shim.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, bit_cast(), from_chars()]
- "targets_run_dual_target_tests_adb_shell": "adb_shell()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L220 | neighbors=[run_dual_target_tests.py, run_command(), android_leg()]
- "targets_run_dual_target_tests_normalize_lf": "normalize_lf()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L118 | neighbors=[run_dual_target_tests.py, android_leg(), windows_leg()]
- "tests_fixtures_plane": "plane()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L28 | neighbors=[fixtures.py, mesh_object(), zfight_pair()]
- "tests_fixtures_simple_character": "simple_character()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L88 | neighbors=[fixtures.py, Capsule-ish mesh + 3-bone chain armatur…, mesh_object()]
- "tests_fixtures_uv_sphere": "uv_sphere()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L23 | neighbors=[fixtures.py, street(), mesh_object()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-080.json

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
