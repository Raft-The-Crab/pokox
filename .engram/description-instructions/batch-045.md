# Node Description Batch 46 of 208

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

- "cad_skill_main_mating_check_mating": "check_mating()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L27 | neighbors=[mating.py, MatingError, overlap(), Raise MatingError unless `moving` fits …]
- "cad_skill_main_mating_matingerror": "MatingError" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L17 | neighbors=[mating.py, check_mating(), AssertionError, A 20 mm block sitting in a U socket who…]
- "cad_skill_main_preview_build_grid": "_build_grid()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L87 | neighbors=[preview.py, _nice_spacing(), _build_scene(), Create a ground-plane grid mesh at the …]
- "cad_skill_main_preview_get_font": "_get_font()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L297 | neighbors=[preview.py, Try to load a nice sans-serif font, fal…, render_multi_view(), render_single()]
- "cad_skill_main_preview_info_lines": "_info_lines()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L319 | neighbors=[preview.py, Two-line footer with dimensions, volume…, render_multi_view(), render_single()]
- "cad_skill_main_preview_main": "main()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L435 | neighbors=[preview.py, render_multi_view(), render_single(), title_from_path()]
- "cad_skill_main_run_cadquery_model_main": "main()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L173 | neighbors=[run_cadquery_model.py, _append_stderr(), _new_files_by_ext(), _process_stls()]
- "cad_skill_main_run_cadquery_model_process_stls": "_process_stls()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L93 | neighbors=[run_cadquery_model.py, main(), _sibling(), Load each STL once and optionally rende…]
- "cad_skill_main_stl_to_3mf": "stl_to_3mf.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/stl_to_3mf.py:L1 | neighbors=[convert(), main(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "candyland_candy_map_add_owner": "add_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L205 | neighbors=[candy_map.py, free(), mesh_obj(), place()]
- "candyland_candy_map_drape_strip": "drape_strip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L294 | neighbors=[candy_map.py, H(), one board tile: the polyline section s0…, trails()]
- "candyland_candy_map_fit_bad": "fit_bad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L230 | neighbors=[candy_map.py, fit(), _inside_one(), _top()]
- "candyland_candy_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L270 | neighbors=[candy_map.py, axis_coords(), H(), mesh_obj()]
- "candyland_candy_map_icing_caps": "icing_caps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L432 | neighbors=[candy_map.py, H(), mesh_obj(), icing poured over the frosting hilltops…]
- "candyland_candy_map_path_mask": "path_mask()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L82 | neighbors=[candy_map.py, H0(), poly_d(), 0 on trails / plazas, 1 away from them …]
- "candyland_candy_map_resample": "resample()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L61 | neighbors=[candy_map.py, build(), river(), trails()]
- "candyland_candy_map_station": "station()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L182 | neighbors=[candy_map.py, anchor(), place(), to_world()]
- "candyland_candy_props_biscuit_bridge": "biscuit_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L896 | neighbors=[candy_props.py, lathe(), round_prof(), biscuit bridge along Z: shortbread roun…]
- "candyland_candy_props_candy_egg": "candy_egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L471 | neighbors=[candy_props.py, lathe(), egg_machine(), decorated egg: lathe egg with horizonta…]
- "candyland_candy_props_cupcake_liner": "cupcake_liner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L236 | neighbors=[candy_props.py, cupcake_fountain(), orient(), pleated paper liner: frustum whose radi…]
- "candyland_candy_props_gumdrop_bush": "gumdrop_bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1035 | neighbors=[candy_props.py, lathe(), sugar(), 3-5 sugar-coated gumdrops of different …]
- "candyland_candy_props_marshmallow": "marshmallow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1122 | neighbors=[candy_props.py, lathe(), round_prof(), stepping-stone marshmallow: rounded cyl…]
- "candyland_candy_props_swirl": "swirl()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L250 | neighbors=[candy_props.py, candy_castle(), cupcake_fountain(), soft-serve swirl: a tube coiling up and…]
- "candyland_candy_props_swirl_disc": "swirl_disc()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L516 | neighbors=[candy_props.py, egg_machine(), lollipop_tree(), flat lollipop swirl: two interleaved Ar…]
- "canyonbazaar_canyon_map_medallion": "medallion()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L300 | neighbors=[canyon_map.py, build(), static(), spawn medallion: an inlaid eight-point …]
- "canyonbazaar_canyon_map_shelf1": "shelf1()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L38 | neighbors=[canyon_map.py, nature(), walkable ledge width (studs) per wall: …, wall()]
- "canyonbazaar_canyon_map_sight_x": "sight_x()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L89 | neighbors=[canyon_map.py, nature(), spawn -> temple door sightline x at z (…, cx()]
- "canyonbazaar_canyon_props_forge_station": "forge_station()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L597 | neighbors=[canyon_props.py, dais(), sign_board(), UPGRADE station: a sandstone forge hear…]
- "canyonbazaar_canyon_props_pottery_cluster": "pottery_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L207 | neighbors=[canyon_props.py, crate(), pot(), story cluster: big jars, a toppled amph…]
- "cavemap_cave_map_build_dist": "build_dist()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L121 | neighbors=[cave_map.py, build(), air(), signed distance (studs) to the cave wal…]
- "cavemap_cave_map_bvh_of": "bvh_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L209 | neighbors=[cave_map.py, build_solid(), free(), shell()]
- "cavemap_cave_map_islet_d": "islet_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L85 | neighbors=[cave_map.py, H(), under_lake(), water()]
- "cavemap_cave_map_poly_d": "poly_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L83 | neighbors=[cave_map.py, path_d(), seg_d(), tunnel_d()]
- "cavemap_cave_map_put_rock": "put_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L396 | neighbors=[cave_map.py, H(), place(), rocks()]
- "cavemap_cave_map_remesh": "remesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L268 | neighbors=[cave_map.py, crust(), free(), shell()]
- "cavemap_cave_map_tunnel_d": "tunnel_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L86 | neighbors=[cave_map.py, mine_sets(), rocks(), poly_d()]
- "cavemap_cave_map_union_mesh": "union_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L261 | neighbors=[cave_map.py, crust(), shell(), free()]
- "cavemap_cave_ores_druse": "druse()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L76 | neighbors=[cave_ores.py, cart_load(), ore_pile(), crystal cluster: n banded crystals fann…]
- "cavemap_cave_ores_mound": "mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L25 | neighbors=[cave_ores.py, cart_load(), ore_pile(), the heap's hidden-gap filler: a lumpy d…]
- "cavemap_cave_props_crystal_shards": "crystal_shards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L322 | neighbors=[cave_props.py, add_crystal(), FS(), ground scatter: a pebble bed with 3-5 s…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-045.json

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
