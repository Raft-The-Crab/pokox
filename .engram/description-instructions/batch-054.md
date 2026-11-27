# Node Description Batch 55 of 209

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

- "plusspeed_plus_props_v4_egg_hatchery": "egg_hatchery()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L117 | neighbors=[plus_props_v4.py, egg_rows(), pixel_art(), plinth()]
- "plusspeed_plus_props_v4_medal_rows": "medal_rows()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L162 | neighbors=[plus_props_v4.py, hoarding(), medal_pad(), raster()]
- "plusspeed_plus_props_v4_rebirth_portal": "rebirth_portal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L150 | neighbors=[plus_props_v4.py, pixel_art(), plinth(), portal_rows()]
- "preserved_preserve_r6": "preserve_r6.py" | kind=code-symbol | source=assets/characters/preserved/preserve_r6.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Preservation-first R6 export. Never ove…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "preserved_preview_face_glb": "preview_face_glb.py" | kind=code-symbol | source=assets/characters/preserved/preview_face_glb.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, point_at(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "preserved_verify_roundtrip": "verify_roundtrip.py" | kind=code-symbol | source=assets/characters/preserved/verify_roundtrip.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Read-only Blender GLB round-trip check.…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "refmatch_compare_band_widths": "band_widths()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L231 | neighbors=[compare.py, tight_crop(), evaluate(), Width of the subject at N bands, normal…]
- "refmatch_compare_bbox_report": "bbox_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L260 | neighbors=[compare.py, tight_crop(), evaluate(), Compare subject aspect ratio (width / h…]
- "refmatch_compare_fit_size": "_fit_size()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L29 | neighbors=[compare.py, letterbox(), normalize_mask(), Isotropic scale of (w, h) so the whole …]
- "refmatch_compare_flood_background_mask": "flood_background_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L96 | neighbors=[compare.py, significant_components(), Segment by flood-filling the backdrop f…, subject_mask()]
- "refmatch_compare_ssim": "ssim()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L380 | neighbors=[compare.py, evaluate(), _conv_sep(), _gaussian_kernel()]
- "refmatch_compare_tight_crop": "tight_crop()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L216 | neighbors=[compare.py, band_widths(), bbox_report(), normalize_mask()]
- "refmatch_measure_sheet_auto_front": "auto_front()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L62 | neighbors=[measure_sheet.py, subject_mask(), main(), Find the tallest narrow subject column …]
- "render_camera": "camera.hpp" | kind=code-symbol | source=engine/render/include/poko/render/camera.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, OrbitCamera, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "rhi_directional_light": "directional_light.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/directional_light.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, DirectionalLight, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "schema_0001_word_reservations": "0001_word_reservations.sql" | kind=code-symbol | source=backend/storage/d1/schema/0001_word_reservations.sql:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, word_reservations, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "scripts_analyze_analyze": "analyze()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L70 | neighbors=[analyze.py, describe_rule(), main(), Computes R8 optimization scores and rul…]
- "scripts_analyze_describe_rule": "describe_rule()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L38 | neighbors=[analyze.py, analyze(), rule_origin(), Returns a rule's source text, origin, a…]
- "scripts_annotate_plan": "annotate_plan.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/annotate_plan.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, font(), main()]
- "scripts_bake_maps_curvature_from_normal": "_curvature_from_normal()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L122 | neighbors=[bake_maps.py, _blur(), Divergence of the tangent normal field:…, run()]
- "scripts_bind_mesh_heat_scale": "_heat_scale()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L71 | neighbors=[bind_mesh.py, _height(), Factor that brings the rig to ~1.8 m fo…, run()]
- "scripts_bind_mesh_proxy_weights": "_proxy_weights()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L38 | neighbors=[bind_mesh.py, _ctx(), _parent(), run()]
- "scripts_bld_grid_fbox": ".fbox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L34 | neighbors=[Grid, _c(), ._sl(), .window()]
- "scripts_bld_grid_fshape": ".fshape()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L40 | neighbors=[Grid, .blob(), .trace(), organic shape in fine bricks: fn(x, y, …]
- "scripts_bld_grid_window": ".window()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L89 | neighbors=[Grid, .fbox(), .fcut(), front-facing window in fine bricks; zf …]
- "scripts_blocks_blockprop_put": ".put()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L29 | neighbors=[BlockProp, Block, rotm(), nest another BlockProp (e.g. a lamp on …]
- "scripts_blocks_transformed": "transformed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L37 | neighbors=[blocks.py, world-space copies of a prop's blocks (…, Block, rotm()]
- "scripts_blocks_write_rbxmx": "write_rbxmx()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L156 | neighbors=[blocks.py, groups: {folder name: [Block, ...]} in …, _f(), rgb_of()]
- "scripts_bpyx_cli": "cli()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L46 | neighbors=[_bpyx.py, argv(), emit(), CLI entry: parse args after '--', run, …]
- "scripts_brick_rig_assign": "assign()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L29 | neighbors=[brick_rig.py, export(), limb(), int label per voxel (index into RIG, -1…]
- "scripts_brick_rig_quads": "_quads()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L74 | neighbors=[brick_rig.py, export(), _greedy2d(), greedy quads of the exposed faces of ce…]
- "scripts_brick_sheet": "brick_sheet.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, key(), Contact sheet of the brick pipeline's *…]
- "scripts_build_pbr_material_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L102 | neighbors=[build_pbr_material.py, _find_textures(), _gltf_output_group(), _srgb_to_lin()]
- "scripts_decal_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L72 | neighbors=[decal.py, _gaps(), _grid(), _material()]
- "scripts_generate_report_clean_severity": "clean_severity()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L154 | neighbors=[generate_report.py, aggregate_findings(), Robustly cleans severity strings by rem…, render_finding_card()]
- "scripts_generate_report_load_json": "load_json()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L238 | neighbors=[generate_report.py, aggregate_findings(), main(), Loads JSON from a file if it exists.]
- "scripts_generate_report_strip_emojis": "strip_emojis()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L56 | neighbors=[generate_report.py, main(), Removes emoji characters from a string., render_finding_card()]
- "scripts_gn_builder_build": "build()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L80 | neighbors=[gn_builder.py, _layout(), _sock(), run()]
- "scripts_groom_build_cards": "build_cards()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L162 | neighbors=[groom.py, _evaluated(), _spaced(), run()]
- "scripts_kit_check_fix": "_fix()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L53 | neighbors=[kit_check.py, _pivot_target(), Apply rotation+scale, then move the ori…, run()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-054.json

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
