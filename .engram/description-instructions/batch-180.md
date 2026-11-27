# Node Description Batch 181 of 209

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
- "scripts_orchestrator_rationale_130": "Strips inline comments starting with '#' while preserving quotes." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L130 | neighbors=[_strip_inline_comment()] | lang=en
- "scripts_orchestrator_rationale_146": "Returns target_dir and its parent directory (for submodule scans)." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L146 | neighbors=[_candidate_project_roots()] | lang=en
- "scripts_orchestrator_rationale_158": "Loads properties from gradle.properties and local.properties." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L158 | neighbors=[load_gradle_properties()] | lang=en
- "scripts_orchestrator_rationale_181": "Loads versions from gradle/libs.versions.toml if it exists." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L181 | neighbors=[load_version_catalog()] | lang=en
- "scripts_orchestrator_rationale_227": "Returns version-catalog plugin aliases that map to com.android.application.    S" | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L227 | neighbors=[load_app_plugin_aliases()] | lang=en
- "scripts_orchestrator_rationale_275": "Builds a regex matching `alias(...)` for any of the given catalog paths." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L275 | neighbors=[_build_app_plugin_alias_pattern()] | lang=en
- "scripts_orchestrator_rationale_287": "Loads versions from shared Gradle files and project configuration." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L287 | neighbors=[load_custom_gradle_versions()] | lang=en
- "scripts_orchestrator_rationale_359": "Safely loads a JSON file." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L359 | neighbors=[_load_json_file()] | lang=pt
- "scripts_orchestrator_rationale_370": "Safely reads a text file." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L370 | neighbors=[_read_text_file()] | lang=pt
- "scripts_orchestrator_rationale_381": "Safely writes a JSON file." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L381 | neighbors=[_write_json_file()] | lang=pt
- "scripts_orchestrator_rationale_390": "Safely writes a text file." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L390 | neighbors=[_write_text_file()] | lang=pt
- "scripts_orchestrator_rationale_399": "Recursively filters lists and dicts based on flavor path segments." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L399 | neighbors=[_filter_by_flavor()] | lang=en
- "scripts_orchestrator_rationale_439": "Identifies distinct application modules in the project." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L439 | neighbors=[parse_application_modules()] | lang=en
- "scripts_orchestrator_rationale_539": "Heuristically determines the primary app ID and target SDK." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L539 | neighbors=[determine_primary_identity()] | lang=en
- "scripts_orchestrator_rationale_646": "Reads a single MSBuild property value out of a project file." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L646 | neighbors=[_msbuild_property()] | lang=pt
- "scripts_orchestrator_rationale_654": "Finds the .NET MAUI / .NET for Android project and reads its identity.    A .NET" | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L654 | neighbors=[extract_dotnet_android_details()] | lang=en
- "scripts_orchestrator_rationale_717": "Parses AndroidManifest.xml for key policy signals." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L717 | neighbors=[extract_manifest_details()] | lang=en
- "scripts_orchestrator_rationale_809": "Generates a high-level summary of the audit landscape." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L809 | neighbors=[generate_triage_summary()] | lang=en
- "scripts_orchestrator_rationale_832": "Invokes the scanner directly using the provided inventory." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L832 | neighbors=[run_scanner_direct()] | lang=en

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
