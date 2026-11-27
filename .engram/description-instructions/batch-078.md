# Node Description Batch 79 of 208

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "scripts_play_store_scraper_fetch_html": "fetch_html()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/play_store_scraper.py:L28 | neighbors=[play_store_scraper.py, Fetches HTML content from a URL with a …, scrape_app_details()]
- "scripts_post_main": "main()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/post.py:L16 | neighbors=[post.py, ffmpeg(), outline()]
- "scripts_precipitation_camera_box": "_camera_box()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L251 | neighbors=[precipitation.py, World AABB of the camera's near frustum…, run()]
- "scripts_precipitation_t_n": ".n()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L53 | neighbors=[build_tree(), _T, .sock()]
- "scripts_precipitation_t_out": ".out()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L65 | neighbors=[build_tree(), _T, .sock()]
- "scripts_precipitation_t_sock": ".sock()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L45 | neighbors=[_T, .n(), .out()]
- "scripts_pro_lib_clamp": "clamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L26 | neighbors=[pro_lib.py, .__call__(), smooth()]
- "scripts_pro_lib_clip_half": "clip_half()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L319 | neighbors=[pro_lib.py, keep the side of the bisector of s-o cl…, voronoi_cells()]
- "scripts_pro_lib_clip_rect": "clip_rect()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L332 | neighbors=[pro_lib.py, clip_fn(), voronoi_cells()]
- "scripts_pro_lib_frames": "frames()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L208 | neighbors=[pro_lib.py, parallel-transport frames along a polyl…, tube()]
- "scripts_pro_lib_hexrgb": "hexrgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L23 | neighbors=[pro_lib.py, .g(), .image()]
- "scripts_pro_lib_make_obj": "make_obj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L415 | neighbors=[pro_lib.py, .build(), mesh in Blender space, origin = bbox ce…]
- "scripts_pro_lib_palette_image": ".image()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L43 | neighbors=[Palette, hexrgb(), .material()]
- "scripts_pro_lib_palette_material": ".material()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L56 | neighbors=[.build(), Palette, .image()]
- "scripts_pro_lib_palette_u": ".u()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L42 | neighbors=[.gadd(), Palette, .__call__()]
- "scripts_pro_lib_render": "render()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L469 | neighbors=[pro_lib.py, loc / tgt in Roblox space, r2b()]
- "scripts_pro_lib_rock": "rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L158 | neighbors=[pro_lib.py, hull(), rock_pts()]
- "scripts_pro_lib_rock_pts": "rock_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L141 | neighbors=[pro_lib.py, points on a lumpy ellipsoid (radii r = …, rock()]
- "scripts_pro_lib_split": "split()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L390 | neighbors=[pro_lib.py, .build(), MB]
- "scripts_pro_lib_tube": "tube()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L222 | neighbors=[pro_lib.py, swept polygon along pts; radii scalar o…, frames()]
- "scripts_qa_check_feeds": "_feeds()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L42 | neighbors=[qa_check.py, _material_issues(), (node type, input name) pairs a socket …]
- "scripts_qa_check_mesh_world": "_mesh_world()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L93 | neighbors=[qa_check.py, bmesh of the (evaluated) object in worl…, run()]
- "scripts_render_batch_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-rendering/scripts/render_batch.py:L69 | neighbors=[render_batch.py, _frames(), _gpu()]
- "scripts_render_plan": "render_plan.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/render_plan.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arg()]
- "scripts_rigify_build_ensure_rigify": "_ensure_rigify()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L31 | neighbors=[rigify_build.py, _generate(), run()]
- "scripts_rigify_build_fit": "_fit()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L44 | neighbors=[rigify_build.py, _bounds(), run()]
- "scripts_rigify_build_game_skeleton": "game_skeleton()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L82 | neighbors=[rigify_build.py, root + DEF bones with DEF-only parentin…, run()]
- "scripts_rigify_build_generate": "_generate()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L72 | neighbors=[rigify_build.py, _ensure_rigify(), run()]
- "scripts_roblox_export_cast": "cast()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L715 | neighbors=[roblox_export.py, inside(), first hit along d whose owner passes ok…]
- "scripts_roblox_export_clean_name": "clean_name()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L118 | neighbors=[roblox_export.py, base_of(), big_part()]
- "scripts_roblox_export_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L729 | neighbors=[roblox_export.py, cast(), inside ONE solid: >= 5 of 6 axis rays f…]
- "scripts_roblox_export_newobj": "newobj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L150 | neighbors=[roblox_export.py, material_split(), object with exactly `name` (the MeshPar…]
- "scripts_roblox_export_palette_rgb": "palette_rgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L292 | neighbors=[roblox_export.py, big_part(), average palette colour under a face (fo…]
- "scripts_roblox_materials_mat_for": "mat_for()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L65 | neighbors=[roblox_materials.py, resolve(), write_map()]
- "scripts_roblox_materials_write_map": "write_map()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L91 | neighbors=[roblox_materials.py, material_map.json for the exporter: pal…, mat_for()]
- "scripts_scanner_scan_single_file": "_scan_single_file()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L178 | neighbors=[scanner.py, Internal worker to scan a single file f…, get_supported_extensions()]
- "scripts_scatter_build_tree": "build_tree()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L34 | neighbors=[scatter.py, _on(), run()]
- "scripts_scatter_on": "_on()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/scatter.py:L29 | neighbors=[scatter.py, build_tree(), Enabled socket by name: Random Value ke…]
- "scripts_scene_mood_lerp_table": "_lerp_table()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L75 | neighbors=[scene_mood.py, run(), _world()]
- "scripts_scene_mood_lum": "lum()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L84 | neighbors=[scene_mood.py, run(), _world()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-078.json

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
