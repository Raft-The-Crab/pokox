# Node Description Batch 2 of 209

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

- "cad_skill_main_gridfinity_gridfinitybin": "GridfinityBin" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L186 | neighbors=[gridfinity.py, .add_compartments(), .add_cylinder_pocket(), .add_finger_notch(), .add_pocket(), .add_polygon_pocket()]
- "medievalbattle_battle_map": "battle_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, base(), build(), centre(), channels()]
- "towncity_town_map": "town_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, alley(), anchor(), anchor_local(), bkit()]
- "eggplots_egg_props_sh": "sh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L73 | neighbors=[egg_props.py, barn(), bench(), bush(), collect_pad(), conveyor_end()]
- "scripts_pro_lib": "pro_lib.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, b2r(), bevel(), box(), ccw()]
- "tests_test_safety": "test_safety.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, conflict_setup(), game(), owned_workspace(), test_a_broken_source_only_blocks_itself…]
- "valleylake_valley_props_skel_add": ".add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L865 | neighbors=[bark(), barrel(), basket(), blossom_tree(), boulder(), broadleaf()]
- "creaturelab_lab_map": "lab_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, anchor(), build(), catmull(), ceil_y()]
- "oaktrees_gen_trees": "gen_trees.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arg(), bark_birch(), bark_fir(), bark_oak()]
- "canyonbazaar_canyon_props": "canyon_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L1 | neighbors=[agave(), boulder(), brass_lantern(), brazier(), carved_stair(), cloth_sheet()]
- "plusspeed_plus_props": "plus_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, asteroid(), big_arch(), bush(), cactus()]
- "voidrealm_void_map": "void_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, anchor(), ang(), bridges(), build()]
- "skyrise_sky_props": "sky_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, basalt_rocks(), bridge(), bush(), cactus()]
- "input_action_map": "action_map.cpp" | kind=code-symbol | source=mute/src/input/action_map.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, add_binding(), bindings(), bindings_conflict(), clamp_i32(), clear_bindings()]
- "skyrise_sky_map": "sky_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bridge_ends(), build(), ext(), face()]
- "sugarworks_sugar_props": "sugar_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, buy_button(), candy_corn(), candy_crate(), candy_lamp()]
- "brick_lich_king_brick": "lich_king_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L1 | neighbors=[AXF(), B(), back_layer(), band_edge(), boxa(), build()]
- "cavemap_cave_props": "cave_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L1 | neighbors=[add_crystal(), cap_shape(), crystal(), crystal_shards(), crystal_spray(), dot()]
- "onsenvillage_onsen_map": "onsen_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_owner(), bank_path(), build(), fit()]
- "scripts_roblox_export": "roblox_export.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _add(), any_ok(), arg(), at()]
- "commit:repo:github.com/Raft-The-Crab/pokox@69287a036a051d0f93031b34082a98fa0c2c98ac": "69287a0 Land ENG-60-65 deterministic sim physics, character controller, and vis…" | kind=Commit | source=git | neighbors=[main, 0621f1d Merge pull request #1 from Raft…, 34ca6de Fix GCC/Clang build: add <algor…, build_flags.hpp, fixed.hpp, fixed_vec.hpp]
- "brick_scarecrow_king_brick": "scarecrow_king_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L1 | neighbors=[arc_d(), axd(), B(), build(), bx(), capd()]
- "refmatch_compare": "compare.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, background_fit_mask(), band_errors(), band_widths(), bbox_report()]
- "input_input_snapshot": "input_snapshot.cpp" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, append(), apply(), at(), button_down(), decode()]
- "scripts_blocks_blockprop": "BlockProp" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L24 | neighbors=[v4 stadium hub: striped infield inside …, stepped canyon: tier n is a row of 24-w…, race kerb along Z: alternating colour/w…, running-track oval: red lane band, whit…, put theme props on cap tops (centre of …, finish hero: 1-2-3 podium + a giant cyl…]
- "whispering_grove_forest_props_prop_add": ".add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L38 | neighbors=[altar(), barrel(), birch(), bridge(), bush(), campfire()]
- "brick_living_armor_brick": "living_armor_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L1 | neighbors=[B(), band(), box(), boxa(), build(), cap()]
- "eggplots_egg_map": "egg_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, anchor(), build(), dressing(), foot()]
- "valleylake_valley_props_v": "V()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L47 | neighbors=[valley_props.py, barrel(), boulder(), dock(), flower_patch(), footbridge()]
- "whispering_grove_forest_props_s": "S()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L32 | neighbors=[forest_props.py, altar(), barrel(), birch(), bridge(), bush()]
- "commit:repo:github.com/Raft-The-Crab/pokox@1dac49da67bdb14fca2c1f271eaedc53f32dbf86": "1dac49d Created NET-01 to NET-09, Started BAK-01" | kind=Commit | source=git | neighbors=[main, 94d1546 Updated markdowns., velocity.hpp, test_version.py, 0001_accounts_games.sql, 0002_ledger_balances.sql]
- "petsim_pet_props_ell": "ell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L64 | neighbors=[pet_props.py, bench(), bridge(), bubble_crown(), chest(), egg()]
- "towncity_town_props": "town_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, ac_unit(), add(), antenna(), awning_band()]
- "voidrealm_void_props_fs": "FS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L59 | neighbors=[void_props.py, arena_rim(), brazier(), crystal_chips(), crystal_cluster(), crystal_lantern()]
- "brainstorm_server_branding_test": "branding.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L1 | neighbors=[assert, assertBrandedFallbackText(), assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap()]
- "brick_abyssal_angler_brick": "abyssal_angler_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L1 | neighbors=[B(), box(), build(), cap(), cell(), chain()]
- "effekseer_ai_cli": "cli.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_parser(), _compile(), _curve_list(), _curve_set()]
- "frostpeak_frost_map": "frost_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), canopy_shade(), chaikin(), _drift()]
- "unit_vulkan_clear_faults": "vulkan_clear_faults.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Chain(), Context(), Device(), emit(), foreign()]
- "brick_ember_dragon_brick": "ember_dragon_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/ember_dragon_brick.py:L1 | neighbors=[B(), box(), build(), chain(), _dil(), exposed()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-001.json

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
