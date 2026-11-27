# Node Description Batch 33 of 207

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

- "candyland_candy_map_h0": "H0()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L88 | neighbors=[candy_map.py, H(), bump(), path_mask(), frosting land before the river / castle…]
- "candyland_candy_map_river": "river()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L385 | neighbors=[candy_map.py, chocolate river surface (glossy, streak…, H(), mesh_obj(), resample()]
- "candyland_candy_props_bell_r": "bell_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L747 | neighbors=[candy_props.py, choco_falls(), gumdrop_mountain(), icing_cap(), gumdrop bell radius at height y (0..Hh)]
- "candyland_candy_props_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L971 | neighbors=[candy_props.py, MS(), soft(), striped_tube(), candy-cane 'tree': helical-striped cane…]
- "candyland_candy_props_cotton_candy_tree": "cotton_candy_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1007 | neighbors=[candy_props.py, MS(), soft(), striped_tube(), cotton-candy tree: twisting pretzel tru…]
- "candyland_candy_props_donut_arch": "donut_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L936 | neighbors=[candy_props.py, drip(), soft(), sprinkles_on(), giant glazed donut standing on edge ove…]
- "candyland_candy_props_waffle_shade": "waffle_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L633 | neighbors=[candy_props.py, candy_castle(), cone_tower(), giant_cone(), waffle_bridge()]
- "canyonbazaar_canyon_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L161 | neighbors=[canyon_map.py, look(), nature(), stories(), under_wall()]
- "canyonbazaar_canyon_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L175 | neighbors=[canyon_map.py, build(), H(), on_paving(), static()]
- "canyonbazaar_canyon_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L224 | neighbors=[canyon_map.py, build(), H(), static(), distant buttes and mesas all round (fla…]
- "canyonbazaar_canyon_map_hw": "hw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L33 | neighbors=[canyon_map.py, nature(), set_pieces(), stories(), tdist()]
- "canyonbazaar_canyon_map_path_x": "path_x()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L93 | neighbors=[canyon_map.py, on_paving(), cx(), paving(), main path centre: follows the canyon, s…]
- "canyonbazaar_canyon_map_paving": "paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L255 | neighbors=[canyon_map.py, build(), path_x(), static(), _stones()]
- "canyonbazaar_canyon_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L162 | neighbors=[canyon_map.py, build(), nature(), set_pieces(), stories()]
- "canyonbazaar_canyon_map_under_wall": "under_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L137 | neighbors=[canyon_map.py, place(), True where the built cliff mesh (vertic…, free(), H()]
- "canyonbazaar_canyon_map_wall": "wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L48 | neighbors=[canyon_map.py, H(), stepped mesa profile at t studs past th…, levels(), shelf1()]
- "canyonbazaar_canyon_props_relic_kiosk": "relic_kiosk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L668 | neighbors=[canyon_props.py, RELIC / PET station on the ledge: a sma…, dais(), pot(), sign_board()]
- "cavemap_cave_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L201 | neighbors=[cave_map.py, build(), landmarks(), rails(), under_lake()]
- "cavemap_cave_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L724 | neighbors=[cave_map.py, free(), H(), sky_at(), wd()]
- "cavemap_cave_map_sky_at": "sky_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L32 | neighbors=[cave_map.py, build(), landmarks(), look(), shapes()]
- "cavemap_cave_ores_cart_load": "cart_load()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L135 | neighbors=[cave_ores.py, druse(), mound(), ore_lump(), v2 load: lumps packed into the tub mout…]
- "cavemap_cave_ores_ore_lump": "ore_lump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L47 | neighbors=[cave_ores.py, cart_load(), _lump(), ore_pile(), one ore lump: host rock faces + metalli…]
- "cavemap_cave_props_jitter": "jitter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L78 | neighbors=[cave_props.py, geode(), low-frequency noise displacement along …, stalactite(), stalagmite()]
- "cavemap_cave_props_stalactite": "stalactite()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L210 | neighbors=[cave_props.py, hanging dripstone cluster: one long rin…, drip_profile(), jitter(), V()]
- "cavemap_cave_props2_blob": "blob()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L9 | neighbors=[cave_props2.py, cart_load(), mine_frame(), mine_lantern_post(), ore_pile()]
- "cavemap_cave_props2_ore_pile": "ore_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L230 | neighbors=[cave_props2.py, blob(), logp(), W(), heap of broken ore with glowing crystal…]
- "cavemap_cave_props2_scaffold": "scaffold()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L127 | neighbors=[cave_props2.py, 3-storey mining scaffold against a wall…, logp(), oil_lantern(), W()]
- "cavemap_cave_props2_tool_rack": "tool_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L243 | neighbors=[cave_props2.py, timber rack with hung pickaxes and shov…, logp(), oil_lantern(), W()]
- "commit:repo:github.com/Raft-The-Crab/pokox@038387e13db5b21f18a460c9f541bd9c4d327133": "038387e Character controller: value-keyed touch memo for the cast path" | kind=Commit | source=git | neighbors=[main, 0be87b9 Merge pull request #4 from Raft…, 3faf30f Character controller: value-key…, character_controller.hpp, 60f3d98 Merge pull request #3 from Raft…]
- "commit:repo:github.com/Raft-The-Crab/pokox@0be87b96189a4b41dbc4f691cd5b9d2edac2fd9f": "0be87b9 Merge pull request #4 from Raft-The-Crab/feat/character-touch-memo" | kind=Commit | source=git | neighbors=[038387e Character controller: value-key…, main, 81d94fb Merge pull request #5 from Raft…, character_controller.hpp, 60f3d98 Merge pull request #3 from Raft…]
- "commit:repo:github.com/Raft-The-Crab/pokox@2d012032e21f854f0f614800c7a5c62d11b6eaab": "2d01203 Final MUT-01..30 audit: stress test, emit trampoline fix, consolidate m…" | kind=Commit | source=git | neighbors=[main, 952997e Audit MUT-01-55 and harden veri…, emit.cpp, stress_test.cpp, e499073 Add MUT-29 dead-code eliminatio…]
- "commit:repo:github.com/Raft-The-Crab/pokox@52dbcb928ed5f7ea8b81a6f983c23971a2826f91": "52dbcb9 Surface graphics warnings in X11 test failure output" | kind=Commit | source=git | neighbors=[main, f4a6ac4 Allowlist known validation-laye…, test_mute_console_x11.py, test_mute_state_console_x11.py, c7a411f Fix MUT-01-20 audit defects in …]
- "commit:repo:github.com/Raft-The-Crab/pokox@5eb3f501c79e04cd57a4c426626396e6111d04b6": "5eb3f50 Mute det_pow: integer-exponent binary exponentiation, no libm" | kind=Commit | source=git | neighbors=[06cfbe9 Narrowphase: local pair frame +…, main, 2960ac1 Android Vulkan clear: no fence …, stdlib_math.cpp, stdlib_math_test.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@6d9948d0015b04b7937fb017fee17c133eddbb4b": "6d9948d Re-resolve X11 demo window during console interaction tests" | kind=Commit | source=git | neighbors=[main, e624dc7 Click console input before each…, test_mute_console_x11.py, test_mute_state_console_x11.py, cb2a354 Re-assert window focus in X11 c…]
- "commit:repo:github.com/Raft-The-Crab/pokox@90b7d79139e8d104bab7d8234dd19409c1d23d0b": "90b7d79 Add for-range lowering to Mute and restore MUT-26 progress doc" | kind=Commit | source=git | neighbors=[807b9d3 Refresh graph after lowering as…, main, 4cead55 Add MUT-27 bytecode verificatio…, lower.cpp, lower_test.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@cb2a354ea05a5ef8d3a9025c5a45a01f584db50e": "cb2a354 Re-assert window focus in X11 console interaction tests" | kind=Commit | source=git | neighbors=[main, 6d9948d Re-resolve X11 demo window duri…, test_mute_console_x11.py, test_mute_state_console_x11.py, f4a6ac4 Allowlist known validation-laye…]
- "creaturelab_lab_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L39 | neighbors=[lab_map.py, garden_paths(), horizon(), place(), pond()]
- "creaturelab_lab_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L454 | neighbors=[lab_map.py, build(), H(), static(), distant scenery: soft rounded hills in …]
- "creaturelab_lab_map_pol": "pol()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L33 | neighbors=[lab_map.py, exterior(), hall_floor(), polar_tiles(), stations()]
- "creaturelab_lab_props_art_frame": "art_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1733 | neighbors=[lab_props.py, rbox(), .add(), upright(), framed poster with an abstract landscap…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-032.json

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
