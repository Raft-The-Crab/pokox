# Node Description Batch 178 of 209

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

- "plusspeed_plus_props_treadmill": "treadmill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L253 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_voxel_tree": "voxel_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L28 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_wins_pad": "wins_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L234 | neighbors=[plus_props.py] | lang=en
- "preserved_preserve_r6_rationale_1": "Preservation-first R6 export. Never overwrites source or prior outputs.  Blender" | kind=entity | source=assets/characters/preserved/preserve_r6.py:L1 | neighbors=[preserve_r6.py] | lang=en
- "preserved_preview_face_glb_point_at": "point_at()" | kind=code-symbol | source=assets/characters/preserved/preview_face_glb.py:L38 | neighbors=[preview_face_glb.py] | lang=en
- "preserved_verify_roundtrip_rationale_1": "Read-only Blender GLB round-trip check. Run in a separate background process.  b" | kind=entity | source=assets/characters/preserved/verify_roundtrip.py:L1 | neighbors=[verify_roundtrip.py] | lang=en
- "program_program_assemble_program_bytecode": "assemble_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L363 | neighbors=[program.cpp] | lang=en
- "program_program_disassemble_program_bytecode": "disassemble_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L359 | neighbors=[program.cpp] | lang=en
- "program_program_parser_parser": ".Parser()" | kind=code-symbol | source=mute/src/program/program.cpp:L52 | neighbors=[Parser] | lang=en
- "program_program_runner_runner": ".Runner()" | kind=code-symbol | source=mute/src/program/program.cpp:L168 | neighbors=[Runner] | lang=en
- "refmatch_compare_print_report": "print_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L508 | neighbors=[compare.py] | lang=en
- "refmatch_compare_rationale_1": "Reference comparison metrics.  Computes the numbers the reconstruction skill req" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L1 | neighbors=[compare.py] | lang=en
- "refmatch_compare_rationale_148": "Foreground mask.      Prefers an exact alpha channel when supplied (a transparen" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L148 | neighbors=[subject_mask()] | lang=en
- "refmatch_compare_rationale_162": "Keep every connected component above a size threshold (not just the largest)." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L162 | neighbors=[significant_components()] | lang=en
- "refmatch_compare_rationale_192": "Crop to the tight subject box, then scale to fit and center.      Resizing strai" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L192 | neighbors=[normalize_mask()] | lang=en
- "refmatch_compare_rationale_232": "Width of the subject at N bands, normalized by the subject's own max width." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L232 | neighbors=[band_widths()] | lang=en
- "refmatch_compare_rationale_261": "Compare subject aspect ratio (width / height), not absolute pixels.      Compari" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L261 | neighbors=[bbox_report()] | lang=en
- "refmatch_compare_rationale_30": "Isotropic scale of (w, h) so the whole image fits inside size." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L30 | neighbors=[_fit_size()] | lang=en
- "refmatch_compare_rationale_36": "Resize a PIL image into size with aspect intact, centered on black padding." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L36 | neighbors=[letterbox()] | lang=en
- "refmatch_compare_rationale_363": "Separable convolution, same size out. Horizontal then vertical pass." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L363 | neighbors=[_conv_sep()] | lang=en
- "refmatch_compare_rationale_404": "Read alpha if the file has one. A transparent render is ground truth." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L404 | neighbors=[load_alpha()] | lang=en
- "refmatch_compare_rationale_415": "Segment at the image's NATIVE resolution, then resample with aspect intact." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L415 | neighbors=[mask_at_native()] | lang=en
- "refmatch_compare_rationale_54": "Normalized quadratic basis over the image plane: [1, x, y, x^2, xy, y^2]." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L54 | neighbors=[_quad_basis()] | lang=es
- "refmatch_compare_rationale_62": "Segment the subject by subtracting a fitted backdrop surface.      A single medi" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L62 | neighbors=[background_fit_mask()] | lang=en
- "refmatch_compare_rationale_97": "Segment by flood-filling the backdrop from the borders.      Thresholding agains" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L97 | neighbors=[flood_background_mask()] | lang=en
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
- "rhi_clearbackend": "rhi::ClearBackend" | kind=code-symbol | neighbors=[FailingPrimaryBackend] | lang=en
- "rhi_directional_light_directionallight": "DirectionalLight" | kind=code-symbol | source=engine/rhi/include/poko/rhi/directional_light.hpp:L8 | neighbors=[directional_light.hpp] | lang=en
- "schema_0001_word_reservations_word_reservations": "word_reservations" | kind=code-symbol | source=backend/storage/d1/schema/0001_word_reservations.sql:L3 | neighbors=[0001_word_reservations.sql] | lang=en
- "scripts_analyze_rationale_1": "Analyzes R8 keep rule radius JSON output and computes optimization scores." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L1 | neighbors=[analyze.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-177.json

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
