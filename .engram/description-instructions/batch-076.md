# Node Description Batch 77 of 208

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

- "preserved_verify_roundtrip": "verify_roundtrip.py" | kind=code-symbol | source=assets/characters/preserved/verify_roundtrip.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Read-only Blender GLB round-trip check.…, c7a411f Fix MUT-01-20 audit defects in …]
- "program_program_commit_globals": "commit_globals()" | kind=code-symbol | source=mute/src/program/program.cpp:L313 | neighbors=[program.cpp, run_stateful_program(), run_stateful_program_bytecode()]
- "program_program_run_program_reference": "run_program_reference()" | kind=code-symbol | source=mute/src/program/program.cpp:L377 | neighbors=[program.cpp, fail(), prepare_globals()]
- "refmatch_compare_conv_sep": "_conv_sep()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L362 | neighbors=[compare.py, Separable convolution, same size out. H…, ssim()]
- "refmatch_compare_load_alpha": "load_alpha()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L403 | neighbors=[compare.py, evaluate(), Read alpha if the file has one. A trans…]
- "refmatch_compare_load_rgb": "load_rgb()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L46 | neighbors=[compare.py, evaluate(), letterbox()]
- "refmatch_compare_quad_basis": "_quad_basis()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L53 | neighbors=[compare.py, background_fit_mask(), Normalized quadratic basis over the ima…]
- "refmatch_measure_sheet_subject_mask": "subject_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L26 | neighbors=[measure_sheet.py, auto_front(), main()]
- "refmatch_overlay_build": "build()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L44 | neighbors=[overlay.py, _overlay(), _panel()]
- "refmatch_palette_report_delta_e": "delta_e()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L88 | neighbors=[palette_report.py, compare_to_render(), CIE76 delta-E. Above ~12 is a clearly d…]
- "refmatch_palette_report_subject_pixels": "subject_pixels()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L45 | neighbors=[palette_report.py, extract(), Subject pixels of an image, segmented a…]
- "render_camera": "camera.hpp" | kind=code-symbol | source=engine/render/include/poko/render/camera.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, OrbitCamera, c7a411f Fix MUT-01-20 audit defects in …]
- "rhi_directional_light": "directional_light.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/directional_light.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, DirectionalLight, c7a411f Fix MUT-01-20 audit defects in …]
- "schema_0001_word_reservations": "0001_word_reservations.sql" | kind=code-symbol | source=backend/storage/d1/schema/0001_word_reservations.sql:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, word_reservations, c7a411f Fix MUT-01-20 audit defects in …]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-076.json

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
