# Node Description Batch 181 of 207

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

- "scripts_retarget_rationale_42": "mixamorig:LeftUpLeg' -> ('upleg', 'L'); 'DEF-upper_arm.L' -> ('upperarm', 'L')." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L42 | neighbors=[_split()] | lang=en
- "scripts_retarget_rationale_57": "{(part, side): bone}, plus the spine chain (hips -> neck order)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L57 | neighbors=[_parts()] | lang=en
- "scripts_review_shots_rationale_1": "Render a multi-angle review contact sheet (headless-safe Workbench) for visual Q" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/review_shots.py:L1 | neighbors=[review_shots.py] | lang=en
- "scripts_rig_check_rationale_1": "Validate a skeleton + its skinned meshes for animation/engine export; optional s" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rig_check.py:L1 | neighbors=[rig_check.py] | lang=en
- "scripts_rigify_build_rationale_1": "Rigify pipeline: add + fit metarig, generate control rig, build an engine-ready" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L1 | neighbors=[rigify_build.py] | lang=en
- "scripts_rigify_build_rationale_83": "root + DEF bones with DEF-only parenting, constrained to the control rig." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L83 | neighbors=[game_skeleton()] | lang=en
- "scripts_roblox_export_add": "_add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L703 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_any_ok": "any_ok()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L740 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_arg": "arg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L19 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_bbox": "bbox()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L142 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_bounds": "bounds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L747 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_fail": "fail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L753 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_glow_of": "glow_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L120 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_lrgb": "lrgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L404 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_lua_rgb": "lua_rgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L397 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_near": "near()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L725 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_num": "num()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L408 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_pts_of": "pts_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L742 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_rationale_135": "glow colour (sRGB 0-255) from an emission material" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L135 | neighbors=[mat_color()] | lang=en
- "scripts_roblox_export_rationale_151": "object with exactly `name` (the MeshPart name in Roblox): move any existing hold" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L151 | neighbors=[newobj()] | lang=en
- "scripts_roblox_export_rationale_165": "materials mode: split every palette (solid) object into one object per (Roblox m" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L165 | neighbors=[material_split()] | lang=it
- "scripts_roblox_export_rationale_270": "faces -> chunks under SPLIT_TRIS / SPLIT_EXTENT (median cut on the longest axis" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L270 | neighbors=[split_faces()] | lang=en
- "scripts_roblox_export_rationale_293": "average palette colour under a face (for oversize faces turned into Parts)" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L293 | neighbors=[palette_rgb()] | lang=en
- "scripts_roblox_export_rationale_303": "low-poly oversize mesh (sea plane, skirt slab) -> Parts tiled under the 2048-stu" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L303 | neighbors=[big_part()] | lang=en
- "scripts_roblox_export_rationale_716": "first hit along d whose owner passes ok(owner index); other owners' faces are st" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L716 | neighbors=[cast()] | lang=en
- "scripts_roblox_export_rationale_730": "inside ONE solid: >= 5 of 6 axis rays first hit a back face of the same owner (o" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L730 | neighbors=[inside()] | lang=en
- "scripts_roblox_export_solid_ok": "solid_ok()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L738 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_export_tris_of": "tris_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L141 | neighbors=[roblox_export.py] | lang=en
- "scripts_roblox_materials_rationale_68": "material for palette ramp `col` on object/mesh `name`: per-prop overrides ({pref" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L68 | neighbors=[resolve()] | lang=en
- "scripts_roblox_materials_rationale_77": "give every palette mesh one Blender material slot per Roblox material (by palett" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L77 | neighbors=[preview()] | lang=en
- "scripts_roblox_materials_rationale_92": "material_map.json for the exporter: palette column index -> Roblox material, + p" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L92 | neighbors=[write_map()] | lang=en
- "scripts_run_in_blender_ver": "_ver()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/run_in_blender.py:L24 | neighbors=[run_in_blender.py] | lang=en
- "scripts_scanner_rationale_159": "Maps files to semantic categories based on filename patterns." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L159 | neighbors=[_identify_semantic_files()] | lang=en
- "scripts_scanner_rationale_179": "Internal worker to scan a single file for all signal categories." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L179 | neighbors=[_scan_single_file()] | lang=en
- "scripts_scanner_rationale_229": "Orchestrates the parallel scanning of identified files." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L229 | neighbors=[perform_scan()] | lang=en
- "scripts_scanner_rationale_37": "Loads the scanner configuration from scanner_config.json with caching." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L37 | neighbors=[get_scanner_config()] | lang=en
- "scripts_scanner_rationale_56": "Returns a tuple of supported file extensions from config." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L56 | neighbors=[get_supported_extensions()] | lang=en
- "scripts_scanner_rationale_61": "Performs a single master walk to categorize files." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L61 | neighbors=[collect_target_files()] | lang=en
- "scripts_scatter_rationale_1": "Biome scatter with Geometry Nodes: Poisson-disk instances of a collection on a s" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L1 | neighbors=[scatter.py] | lang=en
- "scripts_scatter_rationale_30": "Enabled socket by name: Random Value keeps one hidden Min/Max/Value per data typ" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L30 | neighbors=[_on()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-180.json

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
