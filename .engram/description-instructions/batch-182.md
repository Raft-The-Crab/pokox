# Node Description Batch 183 of 209

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

- "scripts_pro_lib_rationale_266": "heightfield quad grid (Roblox space): y = hfun(x, z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L266 | neighbors=[grid()] | lang=es
- "scripts_pro_lib_rationale_284": "a surface between a front curve z = zf(x) and a back curve zb(x) (quad strip ove" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L284 | neighbors=[strip_surface()] | lang=pt
- "scripts_pro_lib_rationale_297": "jittered-grid Voronoi cells clipped to the rectangle: list of (site, polygon[(x," | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L297 | neighbors=[voronoi_cells()] | lang=en
- "scripts_pro_lib_rationale_320": "keep the side of the bisector of s-o closer to s" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L320 | neighbors=[clip_half()] | lang=en
- "scripts_pro_lib_rationale_364": "named groups -> uploaded meshes. solid groups use the palette; glow groups carry" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L364 | neighbors=[Out] | lang=en
- "scripts_pro_lib_rationale_376": "a glow piece: uv on the white strip" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L376 | neighbors=[.gadd()] | lang=en
- "scripts_pro_lib_rationale_38": "ramps: {name: (dark, mid, light)} in column order (max 16). 'white' is always ad" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L38 | neighbors=[.__init__()] | lang=en
- "scripts_pro_lib_rationale_416": "mesh in Blender space, origin = bbox centre; returns the part record (Roblox spa" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L416 | neighbors=[make_obj()] | lang=en
- "scripts_pro_lib_rationale_470": "loc / tgt in Roblox space" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L470 | neighbors=[render()] | lang=en
- "scripts_pro_lib_rationale_66": "shade spec: col = palette column; facet: v = base + up * n.y + jitter (one value" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L66 | neighbors=[Sh] | lang=es
- "scripts_pro_lib_sh_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L68 | neighbors=[Sh] | lang=en
- "scripts_pro_lib_shrink": "shrink()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L354 | neighbors=[pro_lib.py] | lang=en
- "scripts_prop_studio_arg": "arg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/prop_studio.py:L8 | neighbors=[prop_studio.py] | lang=en
- "scripts_prop_studio_setup": "setup()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/prop_studio.py:L21 | neighbors=[prop_studio.py] | lang=en
- "scripts_qa_check_rationale_1": "Mesh/asset QA: z-fighting, detached parts, normals, topology, transforms, UVs, w" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L1 | neighbors=[qa_check.py] | lang=en
- "scripts_qa_check_rationale_43": "(node type, input name) pairs a socket reaches through up to `depth` nodes." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L43 | neighbors=[_feeds()] | lang=en
- "scripts_qa_check_rationale_55": "[(severity_is_error, message)] for slots, faces and image textures." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L55 | neighbors=[_material_issues()] | lang=en
- "scripts_qa_check_rationale_94": "bmesh of the (evaluated) object in world space, triangulated copy kept separatel" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L94 | neighbors=[_mesh_world()] | lang=en
- "scripts_render_batch_rationale_1": "Render stills/animations with quality presets, per-camera batches, any output fo" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L1 | neighbors=[render_batch.py] | lang=en
- "scripts_render_plan_arg": "arg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/render_plan.py:L9 | neighbors=[render_plan.py] | lang=en
- "scripts_retarget_rationale_1": "Retarget an animated skeleton (mocap/BVH/Mixamo/any rig) onto another rig, const" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L1 | neighbors=[retarget.py] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-182.json

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
