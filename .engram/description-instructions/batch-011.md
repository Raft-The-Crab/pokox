# Node Description Batch 12 of 207

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

- "voidrealm_void_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L621 | neighbors=[void_map.py, anchor(), bridges(), build_paths(), dressing(), island()]
- "voidrealm_void_props_rift_gate": "rift_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L590 | neighbors=[void_props.py, HERO 2 - the Rift Gate: octagonal stepp…, annulus(), chamfer_box(), disc(), FS()]
- "whispering_grove_forest_props_leafy": "leafy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L58 | neighbors=[forest_props.py, birch(), bush(), elder_tree(), at(), blob()]
- "brick_terrain_brick": "terrain_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/terrain_brick.py:L1 | neighbors=[cliff(), cliff_mask(), foot_rocks(), grass_cap(), strata(), wall()]
- "bytecode_bytecode_validate_bytecode": "validate_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L42 | neighbors=[bytecode.cpp, assemble_bytecode(), decode_bytecode(), disassemble_bytecode(), encode_bytecode(), branch()]
- "candyland_candy_map_mesh_obj": "mesh_obj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L190 | neighbors=[candy_map.py, ground(), horizon(), icing_caps(), add_owner(), sub()]
- "candyland_candy_props_gumball_machine": "gumball_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L589 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), sign_plate()]
- "candyland_candy_props_waffle_bridge": "waffle_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L845 | neighbors=[candy_props.py, waffle-cone bridge along Z: an arched w…, ball(), lathe(), round_prof(), soft()]
- "canyonbazaar_canyon_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L146 | neighbors=[canyon_map.py, nature(), foot(), H(), kit(), sub()]
- "canyonbazaar_canyon_map_set_pieces": "set_pieces()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L330 | neighbors=[canyon_map.py, build(), cx(), dcx(), hook(), hw()]
- "cavemap_cave_map_lake_d": "lake_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L84 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), fungi(), H()]
- "cavemap_cave_map_rails": "rails()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L663 | neighbors=[cave_map.py, build(), anchor(), H(), place(), placed_mb()]
- "cavemap_cave_map_shell": "shell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L278 | neighbors=[cave_map.py, build(), inner cave surface: union of the air el…, bvh_of(), H(), in_hole()]
- "cavemap_cave_props_geode": "geode()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L277 | neighbors=[cave_props.py, add_crystal(), FS(), jitter(), rim_shade(), RS()]
- "commit:repo:github.com/Raft-The-Crab/pokox@87beff419123840b334804d9bd7582b2184e15ed": "87beff4 Sim solver: reject self/duplicate contacts, derive mass, clamp integrat…" | kind=Commit | source=git | neighbors=[main, 9eeb3ff Merge pull request #2 from Raft…, solver.hpp, visual_solver.hpp, solver.cpp, visual_solver.cpp]
- "console_console_execute_console_impl": "execute_console_impl()" | kind=code-symbol | source=mute/src/console/console.cpp:L77 | neighbors=[console.cpp, execute_console(), decode_string(), diagnostic(), evaluate_console(), number()]
- "creaturelab_lab_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L76 | neighbors=[lab_map.py, build(), ground(), hall_floor(), hardscape(), horizon()]
- "creaturelab_lab_props_bottle": "bottle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L264 | neighbors=[lab_props.py, ball(), rbox(), .add(), med_shelf(), potion_shelf()]
- "creaturelab_lab_props_rotunda": "rotunda()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L807 | neighbors=[lab_props.py, HERO shell: the care hall. Ring wall (i…, adeg(), arc_wall(), lerp(), merge_prop()]
- "device_opengl_clear_renderer": "opengl_clear_renderer.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), default_framebuffer_is_srgb(), Impl(), initialize(), native_window()]
- "device_vulkan_mesh_pass": "vulkan_mesh_pass.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, draw(), draw_and_present(), Impl(), set_light_direction(), set_mesh()]
- "dunedesert_dune_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L78 | neighbors=[dune_map.py, ground(), dunes(), pl_d(), ring(), T_local()]
- "dunedesert_dune_props_shaft": "_shaft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L356 | neighbors=[dune_props.py, obelisk(), obelisk_fallen(), obelisk_stump(), square tapered shaft (w0 at 0 .. w1 at …, disc()]
- "eggplots_egg_props_coop": "coop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L296 | neighbors=[egg_props.py, egg(), egg_finial(), egg_profile(), rbox(), sh()]
- "eggplots_egg_props_egg_finial": "egg_finial()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L147 | neighbors=[egg_props.py, coop(), egg(), sh(), fence_post(), gate_frame()]
- "eggplots_egg_props_egg_profile": "egg_profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L75 | neighbors=[egg_props.py, coop(), egg(), egg_drain(), egg_slice(), foot_bridge()]
- "eggplots_egg_props_straw_nest": "straw_nest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L136 | neighbors=[egg_props.py, coop(), deco_egg(), egg_shop(), gate_frame(), hatchery()]
- "evaluator_evaluator_fail": "fail()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L67 | neighbors=[evaluator.cpp, evaluate_arithmetic(), float_binary(), literal_float(), literal_integer(), materialize()]
- "fishcenter_fish_map_deck_rect": "deck_rect()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L228 | neighbors=[fish_map.py, beam(), lp(), piling(), prism(), sh_val()]
- "fishcenter_fish_map_hardscape": "hardscape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L318 | neighbors=[fish_map.py, build(), compass(), deck_rect(), lp(), platform()]
- "fishcenter_fish_map_lp": "lp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L37 | neighbors=[fish_map.py, deck_rect(), edges(), hardscape(), outward(), tangent()]
- "fishcenter_fish_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L651 | neighbors=[fish_map.py, build(), free(), H(), outward(), place()]
- "fishcenter_fish_props_fish_market": "fish_market()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L905 | neighbors=[fish_props.py, awning(), barrel(), crate(), fish(), plank_floor()]
- "lexer_lexer_lex": "lex()" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L94 | neighbors=[lexer.cpp, decode(), digit(), digit_for(), is_continue(), is_start()]
- "medievalbattle_battle_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L471 | neighbors=[battle_map.py, centre(), field(), ground(), keep(), reserve()]
- "medievalbattle_battle_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L146 | neighbors=[battle_map.py, centre(), field(), keep(), foot(), Hm()]
- "medievalbattle_battle_props_broken_cart": "broken_cart()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1304 | neighbors=[battle_props.py, bar(), crate(), log(), merge(), rot_mb()]
- "medievalbattle_battle_props_curtain_wall": "curtain_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L266 | neighbors=[battle_props.py, ash_sh(), ashlar(), corbels(), heater_shield(), merlon_row()]
- "medievalbattle_battle_props_donjon": "donjon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L469 | neighbors=[battle_props.py, add_into(), course_wall(), donjon_face(), ell_outline(), merge()]
- "medievalbattle_battle_props_siege_tower": "siege_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1039 | neighbors=[battle_props.py, tapered timber assault tower on six sol…, bar(), heater_shield(), lerp(), merge()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-011.json

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
