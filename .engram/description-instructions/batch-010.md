# Node Description Batch 11 of 209

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

- "commit:repo:github.com/Raft-The-Crab/pokox@4cead55894b2108428ac5afe169253bd4ffc026b": "4cead55 Add MUT-27 bytecode verification and MUT-28 constant folding" | kind=Commit | source=git | neighbors=[main, bytecode.cpp, e499073 Add MUT-29 dead-code eliminatio…, fold.hpp, fold.cpp, lower.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@6e2fe3a353df4f43947f16d27ab99b1f80c103ee": "6e2fe3a Created BAK-7 and other BAK tasks" | kind=Commit | source=git | neighbors=[6568dc9 Update from ML AI Code, pkb_schema.hpp, projection_gate.hpp, replay_ring.hpp, rule_evaluator.hpp, main]
- "creaturelab_lab_props_fiddle_fig": "fiddle_fig()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1990 | neighbors=[lab_props.py, leaf_card(), leaf_sh(), pot(), Skel, .add()]
- "creaturelab_lab_props_park_tree": "park_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2068 | neighbors=[lab_props.py, blossom_park(), leaf_mass(), lerp(), Skel, .add()]
- "device_opengles_native_activity": "opengles_native_activity.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_native_activity.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, 9b77990 Android GLES probe: no data rac…, 9eeb3ff Merge pull request #2 from Raft…, f4a6ac4 Allowlist known validation-laye…, android_main(), on_app_cmd()]
- "device_vulkan_triangle_pass": "vulkan_triangle_pass.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, draw(), draw_and_present(), Impl(), set_texture(), set_texture_mips()]
- "dunedesert_dune_props_sunken_temple": "sunken_temple()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L1040 | neighbors=[dune_props.py, HERO / DUNGEON PORTAL: a columned templ…, block_wall(), column(), frustum(), merge_into()]
- "dunedesert_gen_trees_with_palms_tree": "Tree" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L350 | neighbors=[gen_trees_with_palms.py, make_tree(), .build(), .build_conifer(), .children_of(), .env()]
- "evaluator_evaluator_unary": "unary()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L170 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), is_float(), is_unsigned(), magnitude()]
- "examples_axolotl": "axolotl.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), gill_base(), gills(), happy()]
- "fishcenter_fish_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L100 | neighbors=[fish_map.py, edges(), nature(), add_owner(), fit(), kit()]
- "fishcenter_fish_props_bait_shop": "bait_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L837 | neighbors=[fish_props.py, bait_bucket(), ball(), barrel(), lerp(), loft()]
- "fishcenter_fish_props_fish": "fish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L85 | neighbors=[fish_props.py, aquarium_dome(), cooler(), crate(), drying_rack(), ball()]
- "fishcenter_fish_props_lash": "lash()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L68 | neighbors=[fish_props.py, drying_rack(), hammock_palms(), hut_body(), quest_board(), rope lashing: two thin hoops round a po…]
- "fishcenter_fish_props_rod_shop": "rod_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L813 | neighbors=[fish_props.py, ROD SHOP (coral red): bamboo hut, woven…, awning(), barrel(), hook_icon(), hut_body()]
- "framegraph_frame_graph": "frame_graph.cpp" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, add_pass(), build_plan(), clear(), compile(), execute()]
- "input_device_router": "device_router.cpp" | kind=code-symbol | source=mute/src/input/device_router.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, clear(), connect(), disconnect(), find(), find_native()]
- "integration_cube_golden": "cube_golden.py" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, canonical_png(), main(), png_chunk(), run()]
- "medievalbattle_battle_props_ash_sh": "ash_sh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L146 | neighbors=[battle_props.py, curtain_wall(), donjon_face(), donjon_top(), gatehouse(), parapet_front()]
- "medievalbattle_battle_props_donjon_face": "donjon_face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L441 | neighbors=[battle_props.py, donjon(), ash_sh(), ashlar(), parapet_front(), T()]
- "medievalbattle_battle_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L41 | neighbors=[battle_props.py, battering_ram(), bridge_tower(), dead_tree(), ladder(), pine()]
- "medievalbattle_battle_props_parapet_front": "parapet_front()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L385 | neighbors=[battle_props.py, donjon_face(), gatehouse(), ash_sh(), ashlar(), corbels()]
- "moonclean_moon_map_crater_ramp": "crater_ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L366 | neighbors=[moon_map.py, build(), face(), Hm(), place(), polar()]
- "mute_input_snapshot": "input_snapshot.hpp" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, gamepad_control(), gamepad_slot(), InputReplay, InputTimeline, pack_device_code()]
- "oaktrees_gen_trees_tree": "Tree" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L350 | neighbors=[gen_trees.py, make_tree(), .build(), .build_conifer(), .children_of(), .env()]
- "onsenvillage_onsen_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L511 | neighbors=[onsen_map.py, ground(), horizon(), nature(), reserve(), steam()]
- "package_build_tool": "build_tool.cpp" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, after_token(), build_project(), declared_identity(), name(), next_quoted()]
- "parser_declaration": "declaration.cpp" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, decl_fail(), decl_quoted(), DeclarationParser, Depth(), dump_declaration_ast()]
- "petsim_pet_map_fence_ring": "fence_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L306 | neighbors=[pet_map.py, candy(), crystal(), edge_pt(), H(), isle_R()]
- "petsim_pet_props_rbox": "rbox()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L90 | neighbors=[pet_props.py, bench(), bridge(), chest(), fence(), gift_box()]
- "plusspeed_plus_props_fix": "plus_props_fix.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, big_arch(), candy_cane(), lava_rock(), palm()]
- "refmatch_measure_sheet": "measure_sheet.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, auto_front(), load(), main(), palette()]
- "scripts_bake_maps": "bake_maps.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _blur(), _curvature_from_normal(), _restore(), run()]
- "scripts_brick_rig": "brick_rig.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, assign(), _dilate6(), export(), _greedy2d()]
- "scripts_gn_builder": "gn_builder.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-geometry-nodes/scripts/gn_builder.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, apply(), build(), describe(), _layout()]
- "scripts_helper": "helper.js" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/brainstorming/scripts/helper.js:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, connect(), nextReconnectDelay(), reloadAfterRecovery(), sendEvent()]
- "scripts_rigify_build": "rigify_build.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rigify_build.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bounds(), _ensure_rigify(), _fit(), game_skeleton()]
- "scripts_smart_material_g": "_G" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L38 | neighbors=[smart_material.py, build_group(), .__init__(), .link(), .math(), .mix()]
- "scripts_terrain": "terrain.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _erode(), _heightmap(), _material(), _noise_field()]
- "scripts_toon_setup_g": "_G" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L35 | neighbors=[toon_setup.py, build_group(), .__init__(), .link(), .math(), .mix()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-010.json

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
