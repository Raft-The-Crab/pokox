# Node Description Batch 179 of 208

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

- "scripts_build_pbr_material_rationale_1": "Build a correct metal/rough PBR material from texture files or a measured preset" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L1 | neighbors=[build_pbr_material.py] | lang=pt
- "scripts_build_pbr_material_rationale_62": "Map type from filename tokens, scanning from the end (suffixes win)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-pbr-materials/scripts/build_pbr_material.py:L62 | neighbors=[classify()] | lang=en
- "scripts_compare_rationale_1": "Overlay a render's silhouette on a concept view to check proportions 1:1. py com" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L1 | neighbors=[compare.py] | lang=pt
- "scripts_convert_pb_to_json_rationale_1": "Converts R8 keep radius protobuf files into JSON format." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L1 | neighbors=[convert_pb_to_json.py] | lang=en
- "scripts_convert_pb_to_json_rationale_12": "Reads an R8 BlastRadiusContainer protobuf and writes it as JSON." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L12 | neighbors=[convert_pb_to_json()] | lang=en
- "scripts_convert_pb_to_json_rationale_57": "Entry point for CLI execution." | kind=entity | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/convert_pb_to_json.py:L57 | neighbors=[main()] | lang=en
- "scripts_decal_rationale_1": "Mesh decal that conforms to a surface without z-fighting: a subdivided plane pla" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L1 | neighbors=[decal.py] | lang=en
- "scripts_decal_rationale_44": "World distance to the target at every evaluated triangle's centroid and corners-" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/decal.py:L44 | neighbors=[_gaps()] | lang=en
- "scripts_env_report_rationale_1": "Report Blender version, engines, GPU, add-ons, units and scene stats as JSON.  U" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/env_report.py:L1 | neighbors=[env_report.py] | lang=en
- "scripts_export_asset_rationale_1": "Export objects/collections with engine presets, then verify the file.  Presets:" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L1 | neighbors=[export_asset.py] | lang=en
- "scripts_export_asset_rationale_111": "True if exporting o could carry animation (keys, NLA, drivers, constraints, shap" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L111 | neighbors=[_animated()] | lang=pt
- "scripts_export_asset_rationale_62": "Parse the JSON chunk of a .glb (no import needed)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-export-pipelines/scripts/export_asset.py:L62 | neighbors=[glb_summary()] | lang=en
- "scripts_garment_rationale_1": "Game clothing from a body: extract a region as a garment shell (ease offset + th" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L1 | neighbors=[garment.py] | lang=pt
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-178.json

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
