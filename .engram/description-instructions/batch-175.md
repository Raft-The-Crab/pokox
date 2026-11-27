# Node Description Batch 176 of 207

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

- "refmatch_measure_sheet_rationale_1": "Extract clean single-view reference panels from a concept sheet.  The sheet is a" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L1 | neighbors=[measure_sheet.py] | lang=en
- "refmatch_measure_sheet_rationale_63": "Find the tallest narrow subject column inside a region — the front view." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L63 | neighbors=[auto_front()] | lang=en
- "refmatch_overlay_rationale_1": "Side-by-side diagnostic sheet.  Metrics tell you the score. This tells you what" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L1 | neighbors=[overlay.py] | lang=en
- "refmatch_palette_report_rationale_1": "Palette extraction and delta-E comparison.  Two jobs:   1. Read a named palette" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L1 | neighbors=[palette_report.py] | lang=en
- "refmatch_palette_report_rationale_123": "For each named palette role, find the nearest render cluster and report delta-E." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L123 | neighbors=[compare_to_render()] | lang=en
- "refmatch_palette_report_rationale_46": "Subject pixels of an image, segmented at native resolution." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L46 | neighbors=[subject_pixels()] | lang=en
- "refmatch_palette_report_rationale_89": "CIE76 delta-E. Above ~12 is a clearly different color to most viewers." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L89 | neighbors=[delta_e()] | lang=en
- "render_camera_orbitcamera_orbitcamera": ".OrbitCamera()" | kind=code-symbol | source=engine/render/include/poko/render/camera.hpp:L12 | neighbors=[OrbitCamera] | lang=en
- "resource_asset_store_assethandle_assethandle": ".AssetHandle()" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L73 | neighbors=[AssetHandle] | lang=en
- "resource_asset_store_assetstore_assetstore": ".AssetStore()" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L30 | neighbors=[AssetStore] | lang=en
- "resource_asset_store_typed": "typed()" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L87 | neighbors=[asset_store.hpp] | lang=en
- "resource_ktx2": "ktx2.hpp" | kind=code-symbol | source=engine/resource/include/poko/resource/ktx2.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "resource_pokomesh": "pokomesh.hpp" | kind=code-symbol | source=engine/resource/include/poko/resource/pokomesh.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "rhi_clearbackend": "rhi::ClearBackend" | kind=code-symbol | neighbors=[FailingPrimaryBackend] | lang=en
- "rhi_directional_light_directionallight": "DirectionalLight" | kind=code-symbol | source=engine/rhi/include/poko/rhi/directional_light.hpp:L8 | neighbors=[directional_light.hpp] | lang=en
- "rhi_vulkan_clear_renderer": "vulkan_clear_renderer.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/vulkan_clear_renderer.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "rhi_vulkan_diagnostics": "vulkan_diagnostics.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/vulkan_diagnostics.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "schema_0001_word_reservations_word_reservations": "word_reservations" | kind=code-symbol | source=backend/storage/d1/schema/0001_word_reservations.sql:L3 | neighbors=[0001_word_reservations.sql] | lang=en
- "scripts_analyze_rationale_1": "Analyzes R8 keep rule radius JSON output and computes optimization scores." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L1 | neighbors=[analyze.py] | lang=en
- "scripts_analyze_rationale_252": "Entry point for CLI execution." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L252 | neighbors=[main()] | lang=en
- "scripts_analyze_rationale_39": "Returns a rule's source text, origin, and whether the app can edit it." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L39 | neighbors=[describe_rule()] | lang=en
- "scripts_analyze_rationale_71": "Computes R8 optimization scores and rule impacts from keep radius JSON." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L71 | neighbors=[analyze()] | lang=en
- "scripts_analyze_rationale_9": "Returns the file, line and Maven coordinate a keep rule comes from." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L9 | neighbors=[rule_origin()] | lang=en
- "scripts_apply_stack_rationale_1": "Build (and optionally apply) a production hard-surface modifier stack.  Presets:" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-hardsurface-modeling/scripts/apply_stack.py:L1 | neighbors=[apply_stack.py] | lang=en
- "scripts_auto_retopo_rationale_1": "Make a low-poly retopo copy of a dense mesh (sculpt/scan/AI-generated) at a tria" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L1 | neighbors=[auto_retopo.py] | lang=pt
- "scripts_bake_action_rationale_1": "Bake animation clips from a control rig onto an export skeleton (visual keying)," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L1 | neighbors=[bake_action.py] | lang=en
- "scripts_bake_maps_rationale_1": "Bake texture maps with Cycles: high->low (selected-to-active) or self-bake proce" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L1 | neighbors=[bake_maps.py] | lang=en
- "scripts_bake_maps_rationale_123": "Divergence of the tangent normal field: convex > 0.5 (white), concave < 0.5 (dar" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L123 | neighbors=[_curvature_from_normal()] | lang=en
- "scripts_bake_maps_rationale_56": "Route a per-material signal into an Emission shader. Returns an undo list." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L56 | neighbors=[_signal_override()] | lang=en
- "scripts_bake_maps_rationale_98": "Ensure every low material has an active Image node pointing at img." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L98 | neighbors=[_target_node()] | lang=en
- "scripts_batch_process_rationale_1": "Batch over many files in one Blender process: convert formats, inventory report," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L1 | neighbors=[batch_process.py] | lang=en
- "scripts_bind_mesh_rationale_1": "Skin meshes to an armature with robust automatic weights, then clean them for en" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L1 | neighbors=[bind_mesh.py] | lang=en
- "scripts_bind_mesh_rationale_72": "Factor that brings the rig to ~1.8 m for bone heat; 1.0 when already 0.5-20 m ta" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L72 | neighbors=[_heat_scale()] | lang=en
- "scripts_bld_grid_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L19 | neighbors=[Grid] | lang=en
- "scripts_bld_rationale_41": "organic shape in fine bricks: fn(x, y, z) -> bool mask, x/z centred, y up (fine" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L41 | neighbors=[.fshape()] | lang=es
- "scripts_bld_rationale_46": "leafy clump / boulder: ellipsoid with a lumpy surface (no smooth sphere)." | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L46 | neighbors=[.blob()] | lang=en
- "scripts_bld_rationale_54": "extrude a traced reference map (scripts/trace_ref.py) in fine bricks: 1 cell = 1" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L54 | neighbors=[.trace()] | lang=en
- "scripts_bld_rationale_90": "front-facing window in fine bricks; zf = fine z of the wall's outer layer. Pane" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L90 | neighbors=[.window()] | lang=en
- "scripts_blocks_block_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L17 | neighbors=[Block] | lang=en
- "scripts_blocks_blockprop_count": ".count()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L35 | neighbors=[BlockProp] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-175.json

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
