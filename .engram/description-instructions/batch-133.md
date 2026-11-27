# Node Description Batch 134 of 209

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

- "src_gallery_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L43 | neighbors=[gallery.py, flat()]
- "src_haze": "haze.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/haze.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "src_ktx2_fail": "fail()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L32 | neighbors=[ktx2.cpp, load_ktx2()]
- "src_ktx2_in_bounds": "in_bounds()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L38 | neighbors=[ktx2.cpp, load_ktx2()]
- "src_logging_critical": "critical()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L105 | neighbors=[logging.cpp, emit()]
- "src_logging_debug": "debug()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L101 | neighbors=[logging.cpp, emit()]
- "src_logging_error": "error()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L104 | neighbors=[logging.cpp, emit()]
- "src_logging_info": "info()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L102 | neighbors=[logging.cpp, emit()]
- "src_logging_init": "init()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L66 | neighbors=[logging.cpp, to_spdlog()]
- "src_logging_trace": "trace()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L100 | neighbors=[logging.cpp, emit()]
- "src_logging_warn": "warn()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L103 | neighbors=[logging.cpp, emit()]
- "src_loop_alpha": "alpha()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L55 | neighbors=[loop.cpp, valid_limits()]
- "src_loop_fixedsteploop": "FixedStepLoop()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L18 | neighbors=[loop.cpp, to_ns()]
- "src_narrowphase_aabb_of": "aabb_of()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L602 | neighbors=[narrowphase.cpp, collide()]
- "src_narrowphase_centroid": "centroid()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L34 | neighbors=[narrowphase.cpp, gjk_distance()]
- "src_narrowphase_face_barycentric": "face_barycentric()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L318 | neighbors=[narrowphase.cpp, epa_penetration()]
- "src_narrowphase_local_extent": "local_extent()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L622 | neighbors=[narrowphase.cpp, collide()]
- "src_narrowphase_local_shape": "local_shape()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L633 | neighbors=[narrowphase.cpp, collide()]
- "src_narrowphase_tetra_faces": "tetra_faces()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L301 | neighbors=[narrowphase.cpp, epa_penetration()]
- "src_pokomesh_finite_vec3": "finite_vec3()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L38 | neighbors=[pokomesh.cpp, parse_pokomesh()]
- "src_pokomesh_read_f32": "read_f32()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L32 | neighbors=[pokomesh.cpp, parse_pokomesh()]
- "src_pokomesh_read_u32": "read_u32()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L26 | neighbors=[pokomesh.cpp, parse_pokomesh()]
- "src_sap_broadphase_clear": "clear()" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L77 | neighbors=[sap_broadphase.cpp, commit()]
- "src_sap_broadphase_insert": "insert()" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L7 | neighbors=[sap_broadphase.cpp, commit()]
- "src_soft_body_apply_acceleration": "apply_acceleration()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L95 | neighbors=[soft_body.cpp, step()]
- "src_solver_begin_step": "begin_step()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L75 | neighbors=[solver.cpp, clear()]
- "src_solver_tangent_basis": "tangent_basis()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L26 | neighbors=[solver.cpp, solve()]
- "src_visual_solver_add_collider": "add_collider()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L385 | neighbors=[visual_solver.cpp, add_body()]
- "src_visual_solver_add_contact": "add_contact()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L169 | neighbors=[visual_solver.cpp, step()]
- "src_visual_solver_collide_box_box": "collide_box_box()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L104 | neighbors=[visual_solver.cpp, collide_visual()]
- "src_visual_solver_collide_sphere_sphere": "collide_sphere_sphere()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L48 | neighbors=[visual_solver.cpp, collide_visual()]
- "src_visual_solver_integrate": "integrate()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L318 | neighbors=[visual_solver.cpp, step()]
- "src_visual_solver_tangent_basis": "tangent_basis()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L19 | neighbors=[visual_solver.cpp, solve()]
- "state_state_hash_state": "hash_state()" | kind=code-symbol | source=mute/src/state/state.cpp:L30 | neighbors=[state.cpp, xxhash64()]
- "state_state_merge": "merge()" | kind=code-symbol | source=mute/src/state/state.cpp:L15 | neighbors=[state.cpp, xxhash64()]
- "state_state_read32": "read32()" | kind=code-symbol | source=mute/src/state/state.cpp:L11 | neighbors=[state.cpp, xxhash64()]
- "state_state_read64": "read64()" | kind=code-symbol | source=mute/src/state/state.cpp:L8 | neighbors=[state.cpp, xxhash64()]
- "state_state_snapshot_append_le": "append_le()" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L12 | neighbors=[state_snapshot.cpp, save_state_snapshot()]
- "state_state_snapshot_read_le": "read_le()" | kind=code-symbol | source=mute/src/state/state_snapshot.cpp:L15 | neighbors=[state_snapshot.cpp, load_state_snapshot()]
- "stdlib_events_hash": "hash()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L78 | neighbors=[events.cpp, mix()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-133.json

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
