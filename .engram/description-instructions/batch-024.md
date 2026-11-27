# Node Description Batch 25 of 209

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

- "writing_skills_render_graphs": "render-graphs.js" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, combineGraphs(), extractDotBlocks(), extractGraphBody(), main()]
- "authority_replay_ring_encode_replay": "encode_replay()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L191 | neighbors=[replay_ring.hpp, cbor_bool(), cbor_head(), cbor_text(), cbor_uint(), emit_litlen()]
- "blender_character_blockout_get_collection": "get_collection()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L74 | neighbors=[character_blockout.py, box(), build(), capsule(), link(), sphere()]
- "blender_explorer_build": "explorer_build.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L1 | neighbors=[build_explorer(), _fresh_col(), _mats(), Explorer character — pass 2: garments, …, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "blender_validate_scene_scene_bounds": "scene_bounds()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L28 | neighbors=[validate_scene.py, find_isolated(), find_strays(), landmarks(), World-space bounds computed from evalua…, validate()]
- "blender_validate_scene_validate": "validate()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L128 | neighbors=[validate_scene.py, find_isolated(), find_strays(), landmarks(), scene_bounds(), tri_count()]
- "brainstorm_server_auth_test_runtests": "runTests()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L126 | neighbors=[auth.test.js, assertStartedOnExpectedPort(), cleanup(), sleep(), startServer(), waitForServer()]
- "brainstorm_server_server_test_runtests": "runTests()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L126 | neighbors=[server.test.js, assertStartedOnExpectedPort(), cleanup(), sleep(), startServer(), waitForServer()]
- "brick_abyssal_angler_brick_ix": "ix()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L52 | neighbors=[abyssal_angler_brick.py, cell(), front_z(), lip_cell(), side_x(), top_y()]
- "brick_kraken_post": "kraken_post.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_post.py:L1 | neighbors=[fit(), fx(), view(), Post pass for kraken.py (self-contained…, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "brick_props_brick_poly": "poly()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L312 | neighbors=[props_brick.py, assault_rifle(), side-profile polygon (x, y fine coords)…, scifi_pistol(), sniper(), thorn_bow()]
- "bytecode_bytecode_assemble_bytecode": "assemble_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L121 | neighbors=[bytecode.cpp, branch(), disassemble_bytecode(), long_payload(), mnemonic(), validate_bytecode()]
- "cad_skill_main_mating": "mating.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L1 | neighbors=[check_mating(), MatingError, overlap(), Fit checks for printed parts that go to…, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "cad_skill_main_preview_render_frame": "_render_frame()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L256 | neighbors=[preview.py, Render one frame from an existing scene…, _add_edges(), _rotation_matrix(), render_multi_view(), render_view()]
- "cad_skill_main_preview_render_single": "render_single()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L338 | neighbors=[preview.py, main(), Render a single isometric view with tit…, _get_font(), _info_lines(), render_view()]
- "candyland_candy_map_on_hard": "on_hard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L168 | neighbors=[candy_map.py, build(), dist_castle(), poly_d(), trails, plazas, river, castle hill, fal…, soft_pass()]
- "candyland_candy_map_poly_d": "poly_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L60 | neighbors=[candy_map.py, build(), H(), on_hard(), path_mask(), seg_d()]
- "candyland_candy_map_soft_pass": "soft_pass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L491 | neighbors=[candy_map.py, deferred foliage: place, test against a…, free(), on_hard(), place(), unplace()]
- "candyland_candy_map_trails": "trails()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L328 | neighbors=[candy_map.py, board-game tile runs (TILE long, 0.7 ga…, drape_strip(), H(), mesh_obj(), resample()]
- "candyland_candy_props_gumdrop_mountain": "gumdrop_mountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1045 | neighbors=[candy_props.py, bell_r(), icing_cap(), lathe(), sugar(), frame mountain: a huge sugar-coated gum…]
- "candyland_candy_props_lollipop_tree": "lollipop_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L989 | neighbors=[candy_props.py, ball(), MS(), soft(), swirl_disc(), swirl lollipop on a bent stick, disc ti…]
- "candyland_candy_props_spawn_cookie": "spawn_cookie()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1128 | neighbors=[candy_props.py, spawn medallion: giant sugar cookie wit…, lathe(), piping(), round_prof(), sprinkles_on()]
- "candyland_candy_props_sprinkles_on": "sprinkles_on()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L199 | neighbors=[candy_props.py, cupcake_fountain(), donut_arch(), sprinkles lying on a surface: list of (…, spawn_cookie(), sprinkle()]
- "canyonbazaar_canyon_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L163 | neighbors=[canyon_map.py, ground(), horizon(), medallion(), paving(), sub()]
- "canyonbazaar_canyon_map_tdist": "tdist()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L70 | neighbors=[canyon_map.py, H(), nature(), (signed distance past the canyon floor …, cx(), hw()]
- "canyonbazaar_canyon_props_quest_board": "quest_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L640 | neighbors=[canyon_props.py, brass_lantern(), cloth_sheet(), dais(), sign_board(), QUEST station: a timber notice board un…]
- "canyonbazaar_canyon_props_sign_board": "sign_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L509 | neighbors=[canyon_props.py, forge_station(), quest_board(), BLANK sign: carved timber frame with a …, relic_kiosk(), trader_pavilion()]
- "canyonbazaar_canyon_props_trader_pavilion": "trader_pavilion()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L560 | neighbors=[canyon_props.py, SELL station: a wide trader pavilion on…, cloth_sheet(), dais(), pot(), sign_board()]
- "cavemap_cave_map_crust": "crust()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L329 | neighbors=[cave_map.py, build(), remesh(), static(), union_mesh(), outer rock skin (coarse, normals OUT): …]
- "cavemap_cave_map_floor": "floor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L337 | neighbors=[cave_map.py, build(), in_hole(), static(), wd(), walkable floor heightfield (3 studs) ev…]
- "cavemap_cave_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L378 | neighbors=[cave_map.py, build(), islet_d(), lake_d(), static(), wd()]
- "cavemap_cave_map_wgrad": "wgrad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L146 | neighbors=[cave_map.py, crystals(), dripstone(), landmarks(), rocks(), wd()]
- "cavemap_cave_props_crystal_spray": "crystal_spray()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L310 | neighbors=[cave_props.py, add_crystal(), rim_shade(), RS(), strata_mass(), wall-foot crystal spray: a layered rock…]
- "cavemap_cave_props_fs": "FS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L47 | neighbors=[cave_props.py, add_crystal(), crystal_shards(), geode(), glow_vine(), mushroom()]
- "cavemap_cave_props_glow_vine": "glow_vine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L438 | neighbors=[cave_props.py, dot(), FS(), strata_mass(), V(), hanging glow-root: a small root knot un…]
- "cavemap_cave_props_rim_shade": "rim_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L50 | neighbors=[cave_props.py, crystal_spray(), geode(), per-vertex convexity: > 0 convex edge (…, dot(), rock_layered()]
- "cavemap_cave_props2_mine_cart": "mine_cart()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L79 | neighbors=[cave_props2.py, cart_load(), logp(), W(), wheel(), riveted tub on a timber chassis, 4 flan…]
- "cavemap_cave_props2_mine_frame": "mine_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L23 | neighbors=[cave_props2.py, blob(), logp(), oil_lantern(), W(), tunnel timber set: two splayed round po…]
- "cavemap_cave_props2_mine_lantern_post": "mine_lantern_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L114 | neighbors=[cave_props2.py, blob(), logp(), oil_lantern(), W(), square chamfered post on a cairn footin…]
- "cavemap_cave_props2_oil_lantern": "oil_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L12 | neighbors=[cave_props2.py, mine_frame(), mine_lantern_post(), hanging oil lantern: ring hook, vented …, scaffold(), tool_rack()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-024.json

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
