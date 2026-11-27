# Node Description Batch 4 of 209

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

- "brick_scorpion_king_brick": "scorpion_king_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L1 | neighbors=[B(), b3(), ball(), box(), build(), cap()]
- "integration_test_version": "test_version.py" | kind=code-symbol | source=tools/version/tests/integration/test_version.py:L1 | neighbors=[037434c Add MUT-24 determinism and capa…, 1dac49d Created NET-01 to NET-09, Start…, 335e0dc Add MUT-26 IR-to-bytecode emitt…, 435b4d3 Add MUT-23 cooperative async sc…, 6568dc9 Update from ML AI Code, 85b7130 Close MUT-26 limits: AST-to-SSA…]
- "medievalbattle_battle_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L90 | neighbors=[battle_props.py, barrel(), battering_ram(), battle_debris(), brazier(), bridge_tower()]
- "semantic_lower": "lower.cpp" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L1 | neighbors=[2c0194b Add assignments and loop-carrie…, 4cead55 Add MUT-27 bytecode verificatio…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 90b7d79 Add for-range lowering to Mute …, 952997e Audit MUT-01-55 and harden veri…, bin_detail()]
- "src_visual_solver": "visual_solver.cpp" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, add_body(), add_collider(), add_contact()]
- "towncity_town_landmarks": "town_landmarks.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arch_open(), bank(), bus_stop(), car_showroom()]
- "warehouse_kitlib": "kitlib.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, B(), CY(), drop_bottom(), glowbox()]
- "cavemap_cave_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L104 | neighbors=[cave_map.py, build(), ceil_y(), clusters(), crystals(), dripstone()]
- "cavemap_cave_props3": "cave_props3.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L1 | neighbors=[boards(), brew_station(), camp_tent(), campfire_pit(), cave_falls(), crystal_forge()]
- "plusspeed_plus_props_v3": "plus_props_v3.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, barrel(), bulbs_frame(), chamfer_block(), cyl_v()]
- "scripts_scene_mood": "scene_mood.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-time-of-day/scripts/scene_mood.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _clear(), _coll(), _fog(), _fog_box()]
- "tests_test_agent_loop": "test_agent_loop.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, frames(), recipe(), test_library_recipes_use_only_known_fie…, test_lint_accepts_a_cel_contact_and_a_r…]
- "tests_test_video": "test_video.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, clip(), fake_unity(), _footage(), _png()]
- "valleylake_valley_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L982 | neighbors=[valley_map.py, anchor(), beach(), build_profile(), build_solid(), cliffs()]
- "warehouse_wh_map": "wh_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, anchor(), build(), bx(), cull()]
- "brick_frost_mammoth_brick": "frost_mammoth_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L1 | neighbors=[B(), box(), build(), chain(), chain_t(), col4()]
- "cavemap_cave_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L167 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), fungi(), landmarks()]
- "console_console": "console.cpp" | kind=code-symbol | source=mute/src/console/console.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, append(), clear(), console_input_full(), decode_string(), decode_utf8()]
- "medievalbattle_battle_props_bar": "bar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L62 | neighbors=[battle_props.py, frame_to(), battering_ram(), bridge_tower(), broken_cart(), footbridge()]
- "medievalbattle_battle_props_lathe": "lathe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L71 | neighbors=[battle_props.py, barrel(), battering_ram(), battle_debris(), brazier(), bridge_tower()]
- "opencode_test_bootstrap_caching": "test-bootstrap-caching.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-bootstrap-caching.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, afterFirst, afterSecond, assertMappingConstants(), assertMissingBootstrap()]
- "program_program": "program.cpp" | kind=code-symbol | source=mute/src/program/program.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, assemble_program_bytecode(), commit_globals(), compile_program_bytecode(), Depth(), disassemble_program_bytecode()]
- "src_asset_store": "asset_store.cpp" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, acquire(), AssetHandle(), AssetStore(), is_loading(), key()]
- "voidrealm_void_props_annulus": "annulus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L62 | neighbors=[void_props.py, arena_rim(), brazier(), crystal_lantern(), heart_crystal(), lift_beam()]
- "voidrealm_void_props_shaft": "shaft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L84 | neighbors=[void_props.py, arena_rim(), crystal_chips(), crystal_cluster(), crystal_lantern(), far_rock()]
- "brick_volcano_tortoise_brick": "volcano_tortoise_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/volcano_tortoise_brick.py:L1 | neighbors=[B(), box(), build(), cell(), exposed(), hashv()]
- "brick_war_rhino_brick": "war_rhino_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L1 | neighbors=[B(), box(), build(), cap(), chain(), col4()]
- "commit:repo:github.com/Raft-The-Crab/pokox@b9252961ac5ea183ce76d49fe506c154e3548640": "b925296 Finishes BAK tasks." | kind=Commit | source=git | neighbors=[6e2fe3a Created BAK-7 and other BAK tas…, main, test_version.py, allocator.hpp, byo_registration.hpp, match_queue.hpp]
- "device_vulkan_clear_android": "vulkan_clear_android.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L1 | neighbors=[2960ac1 Android Vulkan clear: no fence …, 9eeb3ff Merge pull request #2 from Raft…, f4a6ac4 Allowlist known validation-laye…, clear_and_present(), destroy_swapchain_resources(), initialize()]
- "effekseer_ai_cli_open": "_open()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L18 | neighbors=[cli.py, _curve_list(), _curve_set(), _export(), _image_import(), _node_add()]
- "moonclean_moon_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L67 | neighbors=[moon_props.py, airlock_gate(), comms_dish(), dust_exchange(), egg_incubator(), floodlight()]
- "petsim_pet_map_hub": "hub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L380 | neighbors=[pet_map.py, build(), anchor(), edge_pt(), egg_stand(), face()]
- "plusspeed_plus_map": "plus_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, blk(), dress_caps(), finish(), floor()]
- "plusspeed_plus_props_v4": "plus_props_v4.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, egg_hatchery(), egg_rows(), hoarding(), kerb_lip()]
- "scripts_bpyx": "_bpyx.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/_bpyx.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_common(), argv(), cli(), _default()]
- "semantic_semantic": "semantic.cpp" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, accepts(), analyze(), Analyzer, dump_semantic(), generic_arity()]
- "shared_bpyx": "_bpyx.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_common(), argv(), cli(), _default()]
- "towncity_town_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L589 | neighbors=[town_map.py, alley(), anchor(), buildings(), check_rects(), dressing()]
- "towncity_town_props_building": "building()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L337 | neighbors=[town_props.py, ac_unit(), add(), antenna(), ball(), deco_window()]
- "towncity_town_street": "town_street.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bench(), dumpster(), flower_bed(), hedge()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-003.json

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
