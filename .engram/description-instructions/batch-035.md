# Node Description Batch 36 of 209

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

- "eggplots_egg_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L161 | neighbors=[egg_map.py, build(), isle_point(), static(), island lawn + lake bank + hills: fine g…]
- "eggplots_egg_map_lane": "lane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L249 | neighbors=[egg_map.py, build(), anchor(), place(), reserve()]
- "eggplots_egg_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L94 | neighbors=[egg_map.py, build(), dressing(), lane(), spawn_area()]
- "eggplots_egg_props_barn": "barn()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L861 | neighbors=[egg_props.py, rbox(), sh(), upright(), backdrop red barn (seen from across the…]
- "eggplots_egg_props_deco_egg": "deco_egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L485 | neighbors=[egg_props.py, egg(), sh(), straw_nest(), giant painted egg (lane / plaza decor) …]
- "eggplots_egg_props_feed_trough": "feed_trough()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L402 | neighbors=[egg_props.py, egg(), rbox(), sh(), grain trough: honey plank trough on spl…]
- "eggplots_egg_props_fence_run": "fence_run()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L176 | neighbors=[egg_props.py, rbox(), sh(), upright(), picket fence segment along +X (0..L), f…]
- "eggplots_egg_props_hay_bale": "hay_bale()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L384 | neighbors=[egg_props.py, rbox(), sh(), hay_stack(), square hay bale: chamfered straw block,…]
- "eggplots_egg_props_nest_statue": "nest_statue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L776 | neighbors=[egg_props.py, egg(), sh(), straw_nest(), spawn centrepiece: round stone plinth w…]
- "eggplots_egg_props_plot_slab": "plot_slab()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L262 | neighbors=[egg_props.py, lerp(), rbox(), sh(), the yard: chamfered stone footing + acc…]
- "eggplots_egg_props_windmill": "windmill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L898 | neighbors=[egg_props.py, backdrop windmill: tapered octagonal to…, lerp(), rbox(), sh()]
- "evaluator_evaluator_literal_integer": "literal_integer()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L68 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), integer_suffix(), suffix_length()]
- "evaluator_evaluator_unsigned_binary": "unsigned_binary()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L188 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), unsigned_max(), width()]
- "examples_axolotl_gills": "gills()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L100 | neighbors=[axolotl.py, happy(), idle(), swim(), walk()]
- "exception": "Exception" | kind=code-symbol | neighbors=[cube_demo.cpp, imgui_demo.cpp, triangle_demo.cpp, Skip, sdl_platform_faults.cpp]
- "fakes_enginefactoryopengl": "EngineFactoryOpenGL.h" | kind=code-symbol | source=engine/rhi/tests/fakes/EngineFactoryOpenGL.h:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Diligent(), IEngineFactory(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "fishcenter_fish_map_beam": "beam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L222 | neighbors=[fish_map.py, prism(), sh_val(), deck_rect(), ring_deck()]
- "fishcenter_fish_map_compass": "compass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L299 | neighbors=[fish_map.py, pos(), sh_val(), hardscape(), compass-rose inlay in the spawn plaza d…]
- "fishcenter_fish_map_outward": "outward()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L35 | neighbors=[fish_map.py, islet_e(), islet_grass(), lp(), nature()]
- "fishcenter_fish_map_platform": "platform()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L269 | neighbors=[fish_map.py, hardscape(), pos(), sh_val(), central coral-stone platform: polar fla…]
- "fishcenter_fish_map_prism": "prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L202 | neighbors=[fish_map.py, beam(), deck_rect(), plank / slab from a top quad [(x, z) x4…, ring_deck()]
- "fishcenter_fish_map_rails_flush": "rails_flush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L483 | neighbors=[fish_map.py, edges(), bay_key(), place(), place every collected run: each bay car…]
- "fishcenter_fish_props_awning": "awning()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L236 | neighbors=[fish_props.py, loft(), fish_market(), striped canvas awning off a wall at z (…, rod_shop()]
- "fishcenter_fish_props_boat_house": "boat_house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L990 | neighbors=[fish_props.py, hut_body(), shutter(), thatch_gable(), BOAT RENTAL (lagoon teal): bamboo hut w…]
- "fishcenter_fish_props_boat_hull": "boat_hull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1111 | neighbors=[fish_props.py, lerp(), motor_boat(), hollow lofted boat hull: U sections clo…, skiff()]
- "fishcenter_fish_props_fish_index_wall": "fish_index_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1053 | neighbors=[fish_props.py, fish(), sign_board(), thatch_hip(), AQUARIUM INDEX wall: plank backboard on…]
- "fishcenter_fish_props_rod": "rod()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L647 | neighbors=[fish_props.py, motor_boat(), fishing rod: cork grip, rod blank, guid…, rod_rack(), rod_shop()]
- "fishcenter_fish_props_rod_rack": "rod_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L657 | neighbors=[fish_props.py, A-frame rod rack: bamboo frame, slotted…, lash(), pole(), rod()]
- "fishcenter_fish_props_sea_stack": "sea_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L494 | neighbors=[fish_props.py, tall volcanic sea stack: stacked tilted…, lerp(), _merge_prop(), palm()]
- "fishcenter_fish_props_thatch_band": "thatch_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L130 | neighbors=[fish_props.py, one layer of thatch: outer surface from…, loft(), thatch_cone(), thatch_hip()]
- "fishcenter_fish_props_thatch_gable": "thatch_gable()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L958 | neighbors=[fish_props.py, boat_house(), steep A-frame thatch: ridge along Z, ea…, lash(), lerp()]
- "fishcenter_fish_props_woven_wall": "woven_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L200 | neighbors=[fish_props.py, hut_body(), wall panel L long, H high (local x -L/2…, local(), mat_cell()]
- "frostpeak_frost_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L18 | neighbors=[frost_map.py, ground(), horizon(), place(), square()]
- "hermes_test_plugin_testskilldescriptions": "TestSkillDescriptions" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L164 | neighbors=[test_plugin.py, Hermes builds its skill catalogue from …, .test_descriptions_match_the_skill_fron…, .test_every_stock_skill_registers_a_des…, .test_frontmatter_value_parsing()]
- "identity_sign_in": "sign_in.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/sign_in.hpp:L1 | neighbors=[981b52c Crated IDN-01 to IDN-04, AccountStore, format_user_id(), InMemoryAccountStore, SignInService]
- "identity_worker_auth": "worker_auth.hpp" | kind=code-symbol | source=server/identity/include/poko/identity/worker_auth.hpp:L1 | neighbors=[6568dc9 Update from ML AI Code, base64url_decode(), base64url_encode(), FirebaseTokenVerifier, SessionTickets]
- "input_action_map_put8": "put8()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L12 | neighbors=[action_map.cpp, encode(), hash(), put16(), put32()]
- "input_action_map_read_binding": "read_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L237 | neighbors=[action_map.cpp, clamp_i32(), read_digital(), sign_of(), sample()]
- "input_action_map_set_bindings": "set_bindings()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L130 | neighbors=[action_map.cpp, decode(), bindings_conflict(), find(), validate_binding()]
- "input_input_snapshot_encode": "encode()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L282 | neighbors=[input_snapshot.cpp, put32(), put64(), put8(), put_event()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-035.json

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
