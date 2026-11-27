# Node Description Batch 179 of 207

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
- "scripts_orchestrator_rationale_844": "Generates surgical prompt files for worker agents and infers activation." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L844 | neighbors=[write_agent_prompts()] | lang=en
- "scripts_play_store_scraper_playstoredatasafetyparser_handle_data": ".handle_data()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L156 | neighbors=[PlayStoreDataSafetyParser] | lang=en
- "scripts_play_store_scraper_playstoredatasafetyparser_handle_endtag": ".handle_endtag()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L152 | neighbors=[PlayStoreDataSafetyParser] | lang=en
- "scripts_play_store_scraper_playstoredatasafetyparser_handle_starttag": ".handle_starttag()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L148 | neighbors=[PlayStoreDataSafetyParser] | lang=en
- "scripts_play_store_scraper_playstoredatasafetyparser_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L142 | neighbors=[PlayStoreDataSafetyParser] | lang=en
- "scripts_play_store_scraper_playstoremetadataparser_handle_data": ".handle_data()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L125 | neighbors=[PlayStoreMetadataParser] | lang=en
- "scripts_play_store_scraper_playstoremetadataparser_handle_endtag": ".handle_endtag()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L109 | neighbors=[PlayStoreMetadataParser] | lang=en
- "scripts_play_store_scraper_playstoremetadataparser_handle_starttag": ".handle_starttag()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L78 | neighbors=[PlayStoreMetadataParser] | lang=en
- "scripts_play_store_scraper_playstoremetadataparser_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L60 | neighbors=[PlayStoreMetadataParser] | lang=en
- "scripts_play_store_scraper_rationale_140": "Extracts visible text content from HTML structurally." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L140 | neighbors=[PlayStoreDataSafetyParser] | lang=en
- "scripts_play_store_scraper_rationale_164": "Loads the valid data safety taxonomy from policies.json." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L164 | neighbors=[load_taxonomy()] | lang=en
- "scripts_play_store_scraper_rationale_189": "Extracts all metadata into a clean dictionary." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L189 | neighbors=[extract_metadata()] | lang=pt
- "scripts_play_store_scraper_rationale_244": "Extracts Data Safety information structurally." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L244 | neighbors=[extract_data_safety()] | lang=en
- "scripts_play_store_scraper_rationale_29": "Fetches HTML content from a URL with a realistic User-Agent." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L29 | neighbors=[fetch_html()] | lang=en
- "scripts_play_store_scraper_rationale_385": "Scrapes app metadata and Data Safety info for a given package." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L385 | neighbors=[scrape_app_details()] | lang=en
- "scripts_play_store_scraper_rationale_58": "Parses core app metadata from Play Store HTML." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L58 | neighbors=[PlayStoreMetadataParser] | lang=en
- "scripts_post_glow_fx": "fx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post_glow.py:L10 | neighbors=[post_glow.py] | lang=en
- "scripts_post_glow_rationale_1": "Preview post: single black silhouette outline + Neon-style glow bloom. py post_g" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/post_glow.py:L1 | neighbors=[post_glow.py] | lang=en
- "scripts_post_rationale_1": "Post-process renders from studlib.py: black SILHOUETTE outline (like a Roblox Hi" | kind=entity | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L1 | neighbors=[post.py] | lang=en
- "scripts_precipitation_rationale_1": "Rain, snow, dust, ash or embers as a seamlessly looping Geometry Nodes system (n" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L1 | neighbors=[precipitation.py] | lang=pt
- "scripts_precipitation_rationale_252": "World AABB of the camera's near frustum (0..distance) over the frame range." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L252 | neighbors=[_camera_box()] | lang=en

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
