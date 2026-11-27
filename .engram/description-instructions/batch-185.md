# Node Description Batch 186 of 207

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

- "src_asset_store_assetstore": "AssetStore()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L95 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_key": "key()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L304 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_last_error": "last_error()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L189 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_load_count": "load_count()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L103 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_payload": "payload()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L306 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_poll_async": "poll_async()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L139 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_request_async": "request_async()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L106 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_resident_count": "resident_count()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L100 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_state": "State()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L46 | neighbors=[asset_store.cpp] | lang=en
- "src_asset_store_unload_count": "unload_count()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L104 | neighbors=[asset_store.cpp] | lang=en
- "src_camera_orbit": "orbit()" | kind=code-symbol | source=engine/render/src/camera.cpp:L52 | neighbors=[camera.cpp] | lang=en
- "src_camera_zoom": "zoom()" | kind=code-symbol | source=engine/render/src/camera.cpp:L56 | neighbors=[camera.cpp] | lang=en
- "src_compose_axes": "axes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L72 | neighbors=[compose.py] | lang=en
- "src_convex_shape_support": "support()" | kind=code-symbol | source=engine/physics/src/convex_shape.cpp:L5 | neighbors=[convex_shape.cpp] | lang=en
- "src_frame_stats_record_cpu": "record_cpu()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L16 | neighbors=[frame_stats.cpp] | lang=en
- "src_frame_stats_record_gpu": "record_gpu()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L24 | neighbors=[frame_stats.cpp] | lang=en
- "src_gallery_drum": "drum()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L54 | neighbors=[gallery.py] | lang=en
- "src_gallery_put": "put()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L29 | neighbors=[gallery.py] | lang=en
- "src_gallery_ring_gate": "ring_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L94 | neighbors=[gallery.py] | lang=en
- "src_gallery_scene_reset": "scene_reset()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L15 | neighbors=[gallery.py] | lang=en
- "src_gallery_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L46 | neighbors=[gallery.py] | lang=en
- "src_logging_shutdown": "shutdown()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L92 | neighbors=[logging.cpp] | lang=en
- "src_loop_backlog_seconds": "backlog_seconds()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L65 | neighbors=[loop.cpp] | lang=en
- "src_loop_reset_backlog": "reset_backlog()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L69 | neighbors=[loop.cpp] | lang=en
- "src_loop_step_seconds": "step_seconds()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L61 | neighbors=[loop.cpp] | lang=en
- "src_main_main": "main()" | kind=code-symbol | source=engine/foundation/src/main.cpp:L7 | neighbors=[main.cpp] | lang=en
- "src_sap_broadphase_remove": "remove()" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L11 | neighbors=[sap_broadphase.cpp] | lang=en
- "src_soft_body_collide_plane_y": "collide_plane_y()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L136 | neighbors=[soft_body.cpp] | lang=en
- "src_soft_body_collide_sphere": "collide_sphere()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L145 | neighbors=[soft_body.cpp] | lang=en
- "src_soft_body_pin_node": "pin_node()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L90 | neighbors=[soft_body.cpp] | lang=en
- "src_solver_add_contact": "add_contact()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L80 | neighbors=[solver.cpp] | lang=en
- "src_solver_find_body": "find_body()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L69 | neighbors=[solver.cpp] | lang=en
- "src_solver_integrate": "integrate()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L238 | neighbors=[solver.cpp] | lang=en
- "src_solver_remove_body": "remove_body()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L57 | neighbors=[solver.cpp] | lang=en
- "src_solver_upsert_body": "upsert_body()" | kind=code-symbol | source=engine/physics/src/solver.cpp:L50 | neighbors=[solver.cpp] | lang=en
- "src_vfx_dark_vortex_rationale_1": "VFX_Dark_Vortex: Dark impact played where VFX_Projectile_Dark arrives: a black h" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Dark_Vortex.py:L1 | neighbors=[VFX_Dark_Vortex.py] | lang=pt
- "src_vfx_dark_vortex_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Dark_Vortex.py:L9 | neighbors=[VFX_Dark_Vortex.py] | lang=en
- "src_vfx_fire_explosion_rationale_1": "VFX_Fire_Explosion: Fire impact played where VFX_Projectile_Fire arrives.  Examp" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Fire_Explosion.py:L1 | neighbors=[VFX_Fire_Explosion.py] | lang=en
- "src_vfx_fire_explosion_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Fire_Explosion.py:L9 | neighbors=[VFX_Fire_Explosion.py] | lang=en
- "src_vfx_heal_rationale_1": "VFX_Heal: Heal on the caster: no impact frame, a slow upward rise.  Example from" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Heal.py:L1 | neighbors=[VFX_Heal.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-185.json

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
