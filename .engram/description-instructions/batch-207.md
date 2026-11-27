# Node Description Batch 208 of 208

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "window_sdl_platform_sdlplatform_sdlplatform": ".SdlPlatform()" | kind=code-symbol | source=engine/platform/include/poko/platform/window/sdl_platform.hpp:L15 | neighbors=[~SdlPlatform()]
- "window_sdl_window_demo_main": "main()" | kind=code-symbol | source=engine/platform/src/window/sdl_window_demo.cpp:L8 | neighbors=[sdl_window_demo.cpp]
- "work_adapt_blockyr6_rationale_1": "Adapt BlockyR6 for PokoX (same two fixes as BoyR6, different bone names).  Run:" | kind=entity | source=assets/characters/work/adapt_blockyr6.py:L1 | neighbors=[adapt_blockyr6.py]
- "work_adapt_blockyr6_world_point": "world_point()" | kind=code-symbol | source=assets/characters/work/adapt_blockyr6.py:L53 | neighbors=[adapt_blockyr6.py]
- "work_adapt_boyr6_bone_world_point": "bone_world_point()" | kind=code-symbol | source=assets/characters/work/adapt_boyr6.py:L86 | neighbors=[adapt_boyr6.py]
- "work_adapt_boyr6_rationale_1": "Adapt BoyR6 for PokoX.  Fixes:   1. Head shading: collapse the dead customFaces" | kind=entity | source=assets/characters/work/adapt_boyr6.py:L1 | neighbors=[adapt_boyr6.py]
- "work_mcp_client_rationale_1": "Minimal client for the BlenderMCP TCP socket at 127.0.0.1:9876." | kind=entity | source=assets/characters/work/mcp_client.py:L1 | neighbors=[mcp_client.py]
- "work_mcp_client_send": "send()" | kind=code-symbol | source=assets/characters/work/mcp_client.py:L9 | neighbors=[mcp_client.py]
- "work_test_uv_overlap_overlaptests_test_bounding_boxes_overlap_but_triangles_do_not": ".test_bounding_boxes_overlap_but_triangles_do_not()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L23 | neighbors=[OverlapTests]
- "work_test_uv_overlap_overlaptests_test_edge_and_point_contact_are_not_overlap": ".test_edge_and_point_contact_are_not_overlap()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L18 | neighbors=[OverlapTests]
- "work_test_uv_overlap_overlaptests_test_identical_cross_mesh_triangles_are_detected": ".test_identical_cross_mesh_triangles_are_detected()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L6 | neighbors=[OverlapTests]
- "work_test_uv_overlap_overlaptests_test_invalid_values_rejected": ".test_invalid_values_rejected()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L37 | neighbors=[OverlapTests]
- "work_test_uv_overlap_overlaptests_test_outside_atlas_and_degenerate": ".test_outside_atlas_and_degenerate()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L32 | neighbors=[OverlapTests]
- "work_test_uv_overlap_overlaptests_test_partial_overlap_with_opposite_winding": ".test_partial_overlap_with_opposite_winding()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L12 | neighbors=[OverlapTests]
- "work_test_uv_overlap_overlaptests_test_same_mesh_is_not_counted": ".test_same_mesh_is_not_counted()" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L28 | neighbors=[OverlapTests]
- "work_test_uv_overlap_rationale_1": "Regression tests independent of Blender: python test_uv_overlap.py." | kind=entity | source=assets/characters/work/test_uv_overlap.py:L1 | neighbors=[test_uv_overlap.py]
- "work_trace_face_dump_tree": "dump_tree()" | kind=code-symbol | source=assets/characters/work/trace_face.py:L3 | neighbors=[trace_face.py]
- "work_uv_overlap_rationale_1": "Test positive-area overlap between triangles belonging to different meshes.  Sha" | kind=entity | source=assets/characters/work/uv_overlap.py:L1 | neighbors=[uv_overlap.py]
- "work_uv_overlap_rationale_23": "Return the UV area common to two triangles, independent of winding." | kind=entity | source=assets/characters/work/uv_overlap.py:L23 | neighbors=[intersection_area()]
- "work_uv_overlap_rationale_47": "Input: iterable of (mesh_name, triangle of three (u,v) pairs).      Returns coun" | kind=entity | source=assets/characters/work/uv_overlap.py:L47 | neighbors=[find_cross_mesh_overlaps()]
- "work_validate_production_rationale_1": "Validate the opened R6 .blend. Run with Blender background mode.  Example: blend" | kind=entity | source=assets/characters/work/validate_production.py:L1 | neighbors=[validate_production.py]
- "work_verify_attachment_motion_rationale_1": "Headless attachment smoke test. Does not save any changes to the .blend.  Run: b" | kind=entity | source=assets/characters/work/verify_attachment_motion.py:L1 | neighbors=[verify_attachment_motion.py]
- "work_verify_attachments_nearest_surface": "nearest_surface()" | kind=code-symbol | source=assets/characters/work/verify_attachments.py:L7 | neighbors=[verify_attachments.py]
- "work_verify_attachments2_bbox_dist": "bbox_dist()" | kind=code-symbol | source=assets/characters/work/verify_attachments2.py:L7 | neighbors=[verify_attachments2.py]
- "work_verify_final_attachments_rationale_1": "Definitive attachment connectivity: rotate each ancestor about X, Y and Z. A cor" | kind=entity | source=assets/characters/work/verify_final_attachments.py:L1 | neighbors=[verify_final_attachments.py]
- "writing_skills_render_graphs_extractgraphbody": "extractGraphBody()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L38 | neighbors=[render-graphs.js]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-207.json

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
