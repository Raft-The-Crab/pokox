# Node Description Batch 123 of 207

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

- "program_program_runner": "Runner" | kind=code-symbol | source=mute/src/program/program.cpp:L166 | neighbors=[program.cpp, .Runner()]
- "refmatch_compare_band_errors": "band_errors()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L256 | neighbors=[compare.py, evaluate()]
- "refmatch_compare_gaussian_kernel": "_gaussian_kernel()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L355 | neighbors=[compare.py, ssim()]
- "refmatch_compare_hex": "_hex()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L334 | neighbors=[compare.py, palette_report()]
- "refmatch_compare_hist_correlation": "hist_correlation()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L349 | neighbors=[compare.py, evaluate()]
- "refmatch_compare_kmeans": "_kmeans()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L282 | neighbors=[compare.py, palette_report()]
- "refmatch_compare_luminance_histogram": "luminance_histogram()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L338 | neighbors=[compare.py, evaluate()]
- "refmatch_compare_silhouette_iou": "silhouette_iou()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L225 | neighbors=[compare.py, evaluate()]
- "refmatch_compare_srgb_to_lab": "_srgb_to_lab()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L300 | neighbors=[compare.py, palette_report()]
- "refmatch_measure_sheet_load": "load()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L22 | neighbors=[measure_sheet.py, main()]
- "refmatch_measure_sheet_palette": "palette()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L94 | neighbors=[measure_sheet.py, main()]
- "refmatch_measure_sheet_save_crop": "save_crop()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L44 | neighbors=[measure_sheet.py, main()]
- "refmatch_measure_sheet_tight": "tight()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L37 | neighbors=[measure_sheet.py, main()]
- "refmatch_overlay_overlay": "_overlay()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L32 | neighbors=[overlay.py, build()]
- "refmatch_overlay_panel": "_panel()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L20 | neighbors=[overlay.py, build()]
- "refmatch_palette_report_hex_of": "hex_of()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L34 | neighbors=[palette_report.py, extract()]
- "refmatch_palette_report_hex_to_rgb": "hex_to_rgb()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L38 | neighbors=[palette_report.py, compare_to_render()]
- "refmatch_palette_report_kmeans": "kmeans()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L57 | neighbors=[palette_report.py, extract()]
- "refmatch_palette_report_load_palette": "load_palette()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L97 | neighbors=[palette_report.py, main()]
- "refmatch_palette_report_print_rows": "print_rows()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L144 | neighbors=[palette_report.py, main()]
- "render_camera": "camera.hpp" | kind=code-symbol | source=engine/render/include/poko/render/camera.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, OrbitCamera]
- "render_camera_orbitcamera": "OrbitCamera" | kind=code-symbol | source=engine/render/include/poko/render/camera.hpp:L10 | neighbors=[camera.hpp, .OrbitCamera()]
- "resource_asset_store_assethandle": "AssetHandle" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L24 | neighbors=[asset_store.hpp, .AssetHandle()]
- "resource_asset_store_assetstore": "AssetStore" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L26 | neighbors=[asset_store.hpp, .AssetStore()]
- "rhi_directional_light": "directional_light.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/directional_light.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, DirectionalLight]
- "schema_0001_word_reservations": "0001_word_reservations.sql" | kind=code-symbol | source=backend/storage/d1/schema/0001_word_reservations.sql:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, word_reservations]
- "scripts_annotate_plan_font": "font()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/annotate_plan.py:L10 | neighbors=[annotate_plan.py, main()]
- "scripts_annotate_plan_main": "main()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/annotate_plan.py:L17 | neighbors=[annotate_plan.py, font()]
- "scripts_apply_stack_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hardsurface-modeling/scripts/apply_stack.py:L32 | neighbors=[apply_stack.py, _smooth_faces()]
- "scripts_apply_stack_smooth_faces": "_smooth_faces()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hardsurface-modeling/scripts/apply_stack.py:L26 | neighbors=[apply_stack.py, run()]
- "scripts_bake_action_list_actions": "list_actions()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L26 | neighbors=[bake_action.py, run()]
- "scripts_bake_action_mute": "_mute()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L46 | neighbors=[bake_action.py, run()]
- "scripts_bake_maps_blur": "_blur()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L116 | neighbors=[bake_maps.py, _curvature_from_normal()]
- "scripts_bake_maps_restore": "_restore()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L90 | neighbors=[bake_maps.py, run()]
- "scripts_bake_maps_set_device": "_set_device()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L32 | neighbors=[bake_maps.py, run()]
- "scripts_batch_process_gather": "gather()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L47 | neighbors=[batch_process.py, run()]
- "scripts_batch_process_inventory": "inventory()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L69 | neighbors=[batch_process.py, run()]
- "scripts_batch_process_load": "load()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L60 | neighbors=[batch_process.py, run()]
- "scripts_batch_process_module": "_module()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L89 | neighbors=[batch_process.py, run()]
- "scripts_bind_mesh_unweighted": "unweighted()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L27 | neighbors=[bind_mesh.py, run()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-122.json

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
