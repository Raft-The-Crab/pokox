# Node Description Batch 79 of 209

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

- "refmatch_compare_quad_basis": "_quad_basis()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L53 | neighbors=[compare.py, background_fit_mask(), Normalized quadratic basis over the ima…]
- "refmatch_measure_sheet_subject_mask": "subject_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L26 | neighbors=[measure_sheet.py, auto_front(), main()]
- "refmatch_overlay_build": "build()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L44 | neighbors=[overlay.py, _overlay(), _panel()]
- "refmatch_palette_report_delta_e": "delta_e()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L88 | neighbors=[palette_report.py, compare_to_render(), CIE76 delta-E. Above ~12 is a clearly d…]
- "refmatch_palette_report_subject_pixels": "subject_pixels()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L45 | neighbors=[palette_report.py, extract(), Subject pixels of an image, segmented a…]
- "resource_ktx2": "ktx2.hpp" | kind=code-symbol | source=engine/resource/include/poko/resource/ktx2.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "resource_pokomesh": "pokomesh.hpp" | kind=code-symbol | source=engine/resource/include/poko/resource/pokomesh.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "rhi_vulkan_clear_renderer": "vulkan_clear_renderer.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/vulkan_clear_renderer.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "rhi_vulkan_diagnostics": "vulkan_diagnostics.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/vulkan_diagnostics.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "scripts_analyze_main": "main()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L251 | neighbors=[analyze.py, analyze(), Entry point for CLI execution.]
- "scripts_analyze_rule_origin": "rule_origin()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L8 | neighbors=[analyze.py, describe_rule(), Returns the file, line and Maven coordi…]
- "scripts_auto_retopo_apply_all": "_apply_all()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L27 | neighbors=[auto_retopo.py, _ctx(), run()]
- "scripts_auto_retopo_ctx": "_ctx()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L22 | neighbors=[auto_retopo.py, _apply_all(), run()]
- "scripts_auto_retopo_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L33 | neighbors=[auto_retopo.py, _apply_all(), _ctx()]
- "scripts_bake_action_assign": "_assign()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L37 | neighbors=[bake_action.py, _root_motion(), run()]
- "scripts_bake_action_root_motion": "_root_motion()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L52 | neighbors=[bake_action.py, _assign(), run()]
- "scripts_bake_maps_signal_override": "_signal_override()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L55 | neighbors=[bake_maps.py, Route a per-material signal into an Emi…, run()]
- "scripts_bake_maps_target_node": "_target_node()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L97 | neighbors=[bake_maps.py, Ensure every low material has an active…, run()]
- "scripts_bind_mesh_cleanup": "cleanup()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L79 | neighbors=[bind_mesh.py, _ctx(), run()]
- "scripts_bind_mesh_ctx": "_ctx()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L22 | neighbors=[bind_mesh.py, cleanup(), _proxy_weights()]
- "scripts_bind_mesh_height": "_height()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L66 | neighbors=[bind_mesh.py, _heat_scale(), run()]
- "scripts_bind_mesh_parent": "_parent()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L33 | neighbors=[bind_mesh.py, _proxy_weights(), run()]
- "scripts_bld_grid_blob": ".blob()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L45 | neighbors=[Grid, .fshape(), leafy clump / boulder: ellipsoid with a…]
- "scripts_bld_grid_box": ".box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L28 | neighbors=[Grid, _c(), ._sl()]
- "scripts_bld_grid_fcut": ".fcut()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L37 | neighbors=[Grid, ._sl(), .window()]
- "scripts_bld_grid_trace": ".trace()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L53 | neighbors=[Grid, .fshape(), extrude a traced reference map (scripts…]
- "scripts_blocks_blockprop_b": ".b()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L26 | neighbors=[BlockProp, Block, rotm()]
- "scripts_blocks_rgb_of": "rgb_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L47 | neighbors=[blocks.py, mesh_blocks(), write_rbxmx()]
- "scripts_bpyx_argv": "argv()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L19 | neighbors=[_bpyx.py, cli(), Arguments after '--' (Blender ignores t…]
- "scripts_bpyx_emit": "emit()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L35 | neighbors=[_bpyx.py, cli(), Print compact JSON on one marked line (…]
- "scripts_brick_rig_greedy2d": "_greedy2d()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L59 | neighbors=[brick_rig.py, _quads(), K: 2D int keys (-1 = none). Returns rec…]
- "scripts_brick_rig_limb": "limb()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L45 | neighbors=[brick_rig.py, assign(), overrides that split `mask` (e.g. one t…]
- "scripts_brick_rig_verify": "verify()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L200 | neighbors=[brick_rig.py, export(), fresh session: import the GLB, check bo…]
- "scripts_build_pbr_material_classify": "classify()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L61 | neighbors=[build_pbr_material.py, _find_textures(), Map type from filename tokens, scanning…]
- "scripts_build_pbr_material_find_textures": "_find_textures()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L72 | neighbors=[build_pbr_material.py, classify(), run()]
- "scripts_compare_main": "main()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L25 | neighbors=[compare.py, bbox(), concept_mask()]
- "scripts_convert_pb_to_json_convert_pb_to_json": "convert_pb_to_json()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L11 | neighbors=[convert_pb_to_json.py, main(), Reads an R8 BlastRadiusContainer protob…]
- "scripts_convert_pb_to_json_main": "main()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L56 | neighbors=[convert_pb_to_json.py, convert_pb_to_json(), Entry point for CLI execution.]
- "scripts_decal_gaps": "_gaps()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L43 | neighbors=[decal.py, World distance to the target at every e…, run()]
- "scripts_export_asset_animated": "_animated()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L110 | neighbors=[export_asset.py, True if exporting o could carry animati…, run()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-078.json

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
