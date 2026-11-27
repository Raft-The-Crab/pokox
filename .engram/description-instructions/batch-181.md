# Node Description Batch 182 of 209

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
- "scripts_precipitation_rationale_39": "Minimal node-graph helper: n(type, inputs..., **props) -> node; sockets by enabl" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L39 | neighbors=[_T] | lang=en
- "scripts_precipitation_t_init": ".__init__()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L41 | neighbors=[_T] | lang=en
- "scripts_pro_lib_b2r": "b2r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L21 | neighbors=[pro_lib.py] | lang=en
- "scripts_pro_lib_ccw": "ccw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L358 | neighbors=[pro_lib.py] | lang=en
- "scripts_pro_lib_clean": "clean()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L439 | neighbors=[pro_lib.py] | lang=en
- "scripts_pro_lib_mb_add": ".add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L95 | neighbors=[MB] | lang=en
- "scripts_pro_lib_mb_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L93 | neighbors=[MB] | lang=en
- "scripts_pro_lib_mb_merge": ".merge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L105 | neighbors=[MB] | lang=en
- "scripts_pro_lib_mb_tris": ".tris()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L108 | neighbors=[MB] | lang=en
- "scripts_pro_lib_out_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L365 | neighbors=[Out] | lang=en
- "scripts_pro_lib_preview_setup": "preview_setup()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L447 | neighbors=[pro_lib.py] | lang=en
- "scripts_pro_lib_rationale_112": "rot = (pitch about X, yaw about Y, roll about Z) in degrees" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L112 | neighbors=[xf()] | lang=en
- "scripts_pro_lib_rationale_142": "points on a lumpy ellipsoid (radii r = (rx, ry, rz)); flat = cut the bottom at -" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L142 | neighbors=[rock_pts()] | lang=en
- "scripts_pro_lib_rationale_162": "poly = [(x, z), ...] counter-clockwise seen from above (+Y); extruded y0..y1, to" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L162 | neighbors=[ngon_prism()] | lang=es
- "scripts_pro_lib_rationale_178": "vertical prism / frustum from y0 to y0 + h" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L178 | neighbors=[cyl()] | lang=en
- "scripts_pro_lib_rationale_191": "a crystal / spire: prism up to h * shoulder, then a pyramid tip" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L191 | neighbors=[spike()] | lang=pt
- "scripts_pro_lib_rationale_209": "parallel-transport frames along a polyline (Vectors)" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L209 | neighbors=[frames()] | lang=pt
- "scripts_pro_lib_rationale_223": "swept polygon along pts; radii scalar or list; rough = random ring radius jitter" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L223 | neighbors=[tube()] | lang=en
- "scripts_pro_lib_rationale_247": "a flat strip on the ground following pts (x, y, z); widths per point" | kind=entity | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L247 | neighbors=[ribbon()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-181.json

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
