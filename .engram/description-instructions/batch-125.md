# Node Description Batch 126 of 209

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

- "plusspeed_plus_props_v3_rationale_45": "marquee light bulbs around a sign" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L45 | neighbors=[bulbs_frame(), BlockProp] | lang=pt
- "plusspeed_plus_props_v3_rationale_91": "street lantern pillar: chamfered stepped plinth, 8-sided banded column, capital," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L91 | neighbors=[lamp_pillar(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_speed_shoe": "speed_shoe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L59 | neighbors=[plus_props_v3.py, shop_stall()] | lang=en
- "plusspeed_plus_props_v3_treadmill": "treadmill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L239 | neighbors=[plus_props_v3.py, chamfer_block()] | lang=en
- "plusspeed_plus_props_v4_kerb_lip": "kerb_lip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L47 | neighbors=[plus_props_v4.py, alternating colour / white kerb blocks …] | lang=en
- "plusspeed_plus_props_v4_podium_board": "podium_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L225 | neighbors=[plus_props_v4.py, plinth()] | lang=en
- "plusspeed_plus_props_v4_rationale_18": "rows[0] is the top row. Art is centred on X at pos, bottom at pos.y, front face" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L18 | neighbors=[pixel_art(), BlockProp] | lang=en
- "plusspeed_plus_props_v4_rationale_39": "fn(x, y) -> char, x/y in -1..1 (y up); returns rows top->bottom" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L39 | neighbors=[raster(), BlockProp] | lang=es
- "plusspeed_plus_props_v4_rationale_48": "alternating colour / white kerb blocks with a wedge bevel on the outer edge; gro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L48 | neighbors=[kerb_lip(), BlockProp] | lang=en
- "preserved_verify_preservation_capture": "capture()" | kind=code-symbol | source=assets/characters/preserved/verify_preservation.py:L12 | neighbors=[verify_preservation.py, floats()] | lang=en
- "preserved_verify_preservation_floats": "floats()" | kind=code-symbol | source=assets/characters/preserved/verify_preservation.py:L8 | neighbors=[verify_preservation.py, capture()] | lang=en
- "program_program_compile_program_bytecode": "compile_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L342 | neighbors=[program.cpp, prepare_globals()] | lang=en
- "program_program_depth": "Depth()" | kind=code-symbol | source=mute/src/program/program.cpp:L25 | neighbors=[program.cpp, fail()] | lang=en
- "program_program_inspect_program_state_schema": "inspect_program_state_schema()" | kind=code-symbol | source=mute/src/program/program.cpp:L334 | neighbors=[program.cpp, prepare_globals()] | lang=en
- "program_program_parser": "Parser" | kind=code-symbol | source=mute/src/program/program.cpp:L50 | neighbors=[program.cpp, .Parser()] | lang=en
- "program_program_run_program": "run_program()" | kind=code-symbol | source=mute/src/program/program.cpp:L331 | neighbors=[program.cpp, run_stateful_program()] | lang=en
- "program_program_run_program_bytecode": "run_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L356 | neighbors=[program.cpp, run_stateful_program_bytecode()] | lang=en
- "program_program_runner": "Runner" | kind=code-symbol | source=mute/src/program/program.cpp:L166 | neighbors=[program.cpp, .Runner()] | lang=en
- "refmatch_compare_band_errors": "band_errors()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L256 | neighbors=[compare.py, evaluate()] | lang=en
- "refmatch_compare_gaussian_kernel": "_gaussian_kernel()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L355 | neighbors=[compare.py, ssim()] | lang=en
- "refmatch_compare_hex": "_hex()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L334 | neighbors=[compare.py, palette_report()] | lang=en
- "refmatch_compare_hist_correlation": "hist_correlation()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L349 | neighbors=[compare.py, evaluate()] | lang=en
- "refmatch_compare_kmeans": "_kmeans()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L282 | neighbors=[compare.py, palette_report()] | lang=en
- "refmatch_compare_luminance_histogram": "luminance_histogram()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L338 | neighbors=[compare.py, evaluate()] | lang=en
- "refmatch_compare_silhouette_iou": "silhouette_iou()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L225 | neighbors=[compare.py, evaluate()] | lang=en
- "refmatch_compare_srgb_to_lab": "_srgb_to_lab()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L300 | neighbors=[compare.py, palette_report()] | lang=en
- "refmatch_measure_sheet_load": "load()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L22 | neighbors=[measure_sheet.py, main()] | lang=en
- "refmatch_measure_sheet_palette": "palette()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L94 | neighbors=[measure_sheet.py, main()] | lang=en
- "refmatch_measure_sheet_save_crop": "save_crop()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L44 | neighbors=[measure_sheet.py, main()] | lang=en
- "refmatch_measure_sheet_tight": "tight()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L37 | neighbors=[measure_sheet.py, main()] | lang=en
- "refmatch_overlay_overlay": "_overlay()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L32 | neighbors=[overlay.py, build()] | lang=en
- "refmatch_overlay_panel": "_panel()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L20 | neighbors=[overlay.py, build()] | lang=en
- "refmatch_palette_report_hex_of": "hex_of()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L34 | neighbors=[palette_report.py, extract()] | lang=en
- "refmatch_palette_report_hex_to_rgb": "hex_to_rgb()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L38 | neighbors=[palette_report.py, compare_to_render()] | lang=en
- "refmatch_palette_report_kmeans": "kmeans()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L57 | neighbors=[palette_report.py, extract()] | lang=en
- "refmatch_palette_report_load_palette": "load_palette()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L97 | neighbors=[palette_report.py, main()] | lang=en
- "refmatch_palette_report_print_rows": "print_rows()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L144 | neighbors=[palette_report.py, main()] | lang=en
- "render_camera_orbitcamera": "OrbitCamera" | kind=code-symbol | source=engine/render/include/poko/render/camera.hpp:L10 | neighbors=[camera.hpp, .OrbitCamera()] | lang=en
- "resource_asset_store_assethandle": "AssetHandle" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L24 | neighbors=[asset_store.hpp, .AssetHandle()] | lang=en
- "resource_asset_store_assetstore": "AssetStore" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L26 | neighbors=[asset_store.hpp, .AssetStore()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-125.json

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
