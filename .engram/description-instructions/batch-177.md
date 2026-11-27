# Node Description Batch 178 of 207

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

- "scripts_garment_rationale_100": "Classic cloth: pin the top band, collide with the body, settle `frames`, apply t" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L100 | neighbors=[_drape()] | lang=en
- "scripts_garment_rationale_132": "Same-named garment shape key for every body shape key (Surface Deform bound at r" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L132 | neighbors=[transfer_morphs()] | lang=en
- "scripts_garment_rationale_171": "Body verts (evaluated pose) poking through: casting along the body normal, the g" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L171 | neighbors=[penetration()] | lang=en
- "scripts_garment_rationale_43": "Copy the region's faces in world space and push them out along the vertex normal" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L43 | neighbors=[_shell()] | lang=en
- "scripts_garment_rationale_84": "Vertex group of body verts strictly inside the covered region (shrunk `inset` ri" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L84 | neighbors=[_hide_body()] | lang=en
- "scripts_generate_report_rationale_131": "Safely converts boolean or sloppy string yes/no/true/false." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L131 | neighbors=[parse_boolean()] | lang=en
- "scripts_generate_report_rationale_141": "Safely parses disclosure enums or visual yes/no." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L141 | neighbors=[parse_disclosure_status()] | lang=en
- "scripts_generate_report_rationale_155": "Robustly cleans severity strings by removing quotes, asterisks,   emojis, and wh" | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L155 | neighbors=[clean_severity()] | lang=en
- "scripts_generate_report_rationale_176": "Renders a detailed finding card in Markdown." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L176 | neighbors=[render_finding_card()] | lang=en
- "scripts_generate_report_rationale_239": "Loads JSON from a file if it exists." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L239 | neighbors=[load_json()] | lang=en
- "scripts_generate_report_rationale_250": "Consolidates audit findings from workers.    Produces a unified report data obje" | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L250 | neighbors=[aggregate_findings()] | lang=en
- "scripts_generate_report_rationale_39": "Invokes the Play Store scraper directly." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L39 | neighbors=[run_scraper()] | lang=en
- "scripts_generate_report_rationale_57": "Removes emoji characters from a string." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L57 | neighbors=[strip_emojis()] | lang=en
- "scripts_generate_report_rationale_64": "Formats file paths and line numbers into Markdown links." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L64 | neighbors=[format_code_link()] | lang=en
- "scripts_generate_report_rationale_669": "Main entry point for report generation." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L669 | neighbors=[main()] | lang=en
- "scripts_generate_report_rationale_99": "Renders a Markdown table from a list of dictionaries." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L99 | neighbors=[render_table()] | lang=en
- "scripts_gn_builder_rationale_1": "Build node trees (Geometry Nodes, shader, compositor) from a compact JSON spec," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L1 | neighbors=[gn_builder.py] | lang=en
- "scripts_gn_builder_rationale_135": "Column layout by longest path from inputs (readable trees for humans)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L135 | neighbors=[_layout()] | lang=en
- "scripts_gn_builder_rationale_39": "Inputs/outputs (name, type, default) of node types, from a throwaway tree." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L39 | neighbors=[describe()] | lang=en
- "scripts_groom_rationale_1": "Groom hair curves on a surface with Blender's bundled hair node assets, and turn" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L1 | neighbors=[groom.py] | lang=en
- "scripts_groom_rationale_151": "Farthest-point sampling: k well-spread curve indices." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L151 | neighbors=[_spaced()] | lang=en
- "scripts_groom_rationale_211": "Flat strand clumps (one per column) rendered orthographically: BC+alpha, root-ti" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-hair-grooming/scripts/groom.py:L211 | neighbors=[render_atlas()] | lang=it
- "scripts_helper_nextreconnectdelay": "nextReconnectDelay()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L7 | neighbors=[helper.js] | lang=en
- "scripts_helper_sendevent": "sendEvent()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L120 | neighbors=[helper.js] | lang=en
- "scripts_helper_showtombstone": "showTombstone()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L62 | neighbors=[helper.js] | lang=en
- "scripts_keep_radius_pb2_rationale_1": "Generated protocol buffer code for keep_radius.proto." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/keep_radius_pb2.py:L1 | neighbors=[keep_radius_pb2.py] | lang=en
- "scripts_kit_check_rationale_1": "Validate modular kit pieces so they snap together: applied transforms, footprint" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L1 | neighbors=[kit_check.py] | lang=en
- "scripts_kit_check_rationale_54": "Apply rotation+scale, then move the origin to the pivot without moving the geome" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/kit_check.py:L54 | neighbors=[_fix()] | lang=en
- "scripts_kit_sheet_template_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/kit_sheet_template.py:L43 | neighbors=[kit_sheet_template.py] | lang=en
- "scripts_lightning_rationale_1": "Storm lightning: keyed multi-stroke flashes (a real strike is 3-4 return strokes" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L1 | neighbors=[lightning.py] | lang=en
- "scripts_lightning_rationale_39": "Midpoint displacement between top and bottom; returns a list of Vectors." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L39 | neighbors=[_bolt_points()] | lang=en
- "scripts_lightning_rationale_70": "{frame: intensity 0..1}. Each stroke: peak, 20% next frame, gone after ~3 frames" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/lightning.py:L70 | neighbors=[_envelope()] | lang=en
- "scripts_loop_check_rationale_1": "Check that a cycle loops: the pose at the last frame equals the first (no pop)," | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L1 | neighbors=[loop_check.py] | lang=en
- "scripts_loop_check_rationale_44": "Signed angular velocity a -> b (deg, as a vector) so direction reversals are vis" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/loop_check.py:L44 | neighbors=[_w()] | lang=pt
- "scripts_make_lods_rationale_1": "Generate an LOD chain (<name>_LOD1..N) with Decimate, preserving UV seams/normal" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/make_lods.py:L1 | neighbors=[make_lods.py] | lang=en
- "scripts_make_lods_rationale_21": "Merge by distance, dissolve degenerate, delete loose. Returns removed vert count" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/make_lods.py:L21 | neighbors=[cleanup()] | lang=en
- "scripts_mesh_stats_rationale_1": "Budget report: tris/verts per object, materials (draw calls), textures + VRAM, v" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-game-optimization/scripts/mesh_stats.py:L1 | neighbors=[mesh_stats.py] | lang=it
- "scripts_orchestrator_rationale_1001": "Aggregates and chunks findings for the Critic." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1001 | neighbors=[run_aggregation()] | lang=en
- "scripts_orchestrator_rationale_1102": "Recursively resolves a variable name to an integer value." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1102 | neighbors=[_resolve_to_int()] | lang=en
- "scripts_orchestrator_rationale_1169": "Deterministic context-gathering tool for the Reviewer skill." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1169 | neighbors=[main()] | lang=en

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
