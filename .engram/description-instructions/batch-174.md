# Node Description Batch 175 of 207

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

- "plusspeed_plus_props_ice_crystal": "ice_crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L133 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_lava_rock": "lava_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L140 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L306 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_lollipop": "lollipop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L105 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_mesa": "mesa()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L97 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_mini_volcano": "mini_volcano()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L149 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_neon_sign": "neon_sign()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L169 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_palm": "palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L53 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L43 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_planet": "planet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L177 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_rebirth_altar": "rebirth_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L296 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_shop_stall": "shop_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L283 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_snowman": "snowman()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L124 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L317 | neighbors=[plus_props.py] | lang=en
- "plusspeed_plus_props_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L189 | neighbors=[plus_props.py] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-174.json

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
