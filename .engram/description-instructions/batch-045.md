# Node Description Batch 46 of 207

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

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
- "cavemap_cave_props_glowshroom_cluster": "glowshroom_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L414 | neighbors=[cave_props.py, mound(), mushroom(), a knee-high cluster: 6-8 small mushroom…]
- "cavemap_cave_props_glowshroom_giant": "glowshroom_giant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L398 | neighbors=[cave_props.py, mound(), mushroom(), three giant cave mushrooms (16 / 11 / 7…]
- "cavemap_cave_props_nodules": "nodules()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L391 | neighbors=[cave_props.py, mound(), dot(), shroom_patch()]
- "cavemap_cave_props_rs": "RS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L58 | neighbors=[cave_props.py, crystal_spray(), geode(), rock_layered()]
- "cavemap_cave_props_shroom_patch": "shroom_patch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L425 | neighbors=[cave_props.py, tiny scatter: thin-stalked glowing bell…, nodules(), V()]
- "cavemap_cave_props_stalagmite": "stalagmite()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L255 | neighbors=[cave_props.py, grounded dripstone: flared, plate-ringe…, jitter(), V()]
- "cavemap_cave_props2_cart_load": "cart_load()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L105 | neighbors=[cave_props2.py, blob(), mine_cart(), ore heaped in the tub (cave_ores replac…]
- "cavemap_cave_props2_crates": "crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L203 | neighbors=[cave_props2.py, logp(), W(), stack of 3 braced crates (frame battens…]
- "cavemap_cave_props2_plank_bridge": "plank_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L187 | neighbors=[cave_props2.py, logp(), W(), low boardwalk to the islet (span along …]
- "cavemap_cave_props2_rail_buffer": "rail_buffer()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L59 | neighbors=[cave_props2.py, logp(), W(), end-of-track stop: two posts with back …]
- "cavemap_cave_props2_rope_bridge": "rope_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L162 | neighbors=[cave_props2.py, chasm rope bridge (span along Z): end p…, logp(), W()]
- "cavemap_cave_props3_boards": "boards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L6 | neighbors=[cave_props3.py, mine_shop(), quest_board(), a wall of vertical boards between x0..x…]
- "cavemap_cave_props3_mine_shop": "mine_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L25 | neighbors=[cave_props3.py, boards(), shed_roof(), ORE EXCHANGE: a timber mine-office shed…]
- "commit:repo:github.com/Raft-The-Crab/pokox@1aefb72a961c694946723dc6e1295bf6eb79dbed": "1aefb72 MUT-42: physics hostcall boundary (header)" | kind=Commit | source=git | neighbors=[main, 0d85dce Merge pull request #6 from Raft…, stdlib_physics.hpp, e77fa31 Add new skills and asset packs …]
- "commit:repo:github.com/Raft-The-Crab/pokox@2be6ccd764c29da253fae889e9ec51dbb41cbf88": "2be6ccd Character controller: fix missing trailing newline" | kind=Commit | source=git | neighbors=[main, 8246f8b Character controller: fix heade…, character_controller.hpp, 5acf433 Character controller: fix corru…]

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
