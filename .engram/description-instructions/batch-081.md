# Node Description Batch 82 of 208

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

- "src_character_controller_touch_key": "touch_key()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L107 | neighbors=[character_controller.cpp, append_shape_raws(), touches()]
- "src_character_controller_translated": "translated()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L37 | neighbors=[character_controller.cpp, cast_fraction(), update()]
- "src_config_read_bool": "read_bool()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L44 | neighbors=[config.cpp, load_file(), find_key()]
- "src_config_read_text": "read_text()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L57 | neighbors=[config.cpp, load_file(), find_key()]
- "src_config_read_u32": "read_u32()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L32 | neighbors=[config.cpp, load_file(), find_key()]
- "src_ktx2_load_ktx2": "load_ktx2()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L43 | neighbors=[ktx2.cpp, fail(), in_bounds()]
- "src_logging_to_spdlog": "to_spdlog()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L22 | neighbors=[logging.cpp, emit(), init()]
- "src_loop_advance": "advance()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L30 | neighbors=[loop.cpp, to_ns(), valid_limits()]
- "src_loop_to_ns": "to_ns()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L15 | neighbors=[loop.cpp, advance(), FixedStepLoop()]
- "src_loop_valid_limits": "valid_limits()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L24 | neighbors=[loop.cpp, advance(), alpha()]
- "src_main": "main.cpp" | kind=code-symbol | source=engine/foundation/src/main.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "src_narrowphase_closest_segment": "closest_segment()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L72 | neighbors=[narrowphase.cpp, closest_on_hull(), closest_triangle()]
- "src_narrowphase_cso_support": "cso_support()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L51 | neighbors=[narrowphase.cpp, epa_penetration(), gjk_distance()]
- "src_narrowphase_dist_sq_of": "dist_sq_of()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L69 | neighbors=[narrowphase.cpp, closest_on_hull(), closest_triangle()]
- "src_narrowphase_face_normal": "face_normal()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L285 | neighbors=[narrowphase.cpp, epa_penetration(), orient_out()]
- "src_narrowphase_orient_out": "orient_out()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L291 | neighbors=[narrowphase.cpp, epa_penetration(), face_normal()]
- "src_narrowphase_origin_in_tetra": "origin_in_tetra()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L139 | neighbors=[narrowphase.cpp, closest_on_hull(), epa_penetration()]
- "src_narrowphase_saturate_raw": "saturate_raw()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L647 | neighbors=[narrowphase.cpp, to_world(), widen_raw()]
- "src_narrowphase_to_world": "to_world()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L659 | neighbors=[narrowphase.cpp, collide(), saturate_raw()]
- "src_narrowphase_widen_raw": "widen_raw()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L655 | neighbors=[narrowphase.cpp, collide(), saturate_raw()]
- "src_pokomesh_fail": "fail()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L21 | neighbors=[pokomesh.cpp, load_pokomesh(), parse_pokomesh()]
- "src_pokomesh_load_pokomesh": "load_pokomesh()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L95 | neighbors=[pokomesh.cpp, fail(), parse_pokomesh()]
- "src_sap_broadphase_commit": "commit()" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L15 | neighbors=[sap_broadphase.cpp, clear(), insert()]
- "src_soft_body_add_node": "add_node()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L72 | neighbors=[soft_body.cpp, create(), create_lattice()]
- "src_soft_body_clamp01": "clamp01()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L13 | neighbors=[soft_body.cpp, add_spring(), step()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-081.json

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
