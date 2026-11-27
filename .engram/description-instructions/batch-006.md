# Node Description Batch 7 of 207

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

- "gles_clear_pokoactivity_pokoactivity": "PokoActivity" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L11 | neighbors=[PokoActivity.java, Activity, Callback, .nativeInit(), .nativeSetSurface(), .nativeSurfaceDestroyed()]
- "hermes_test_plugin_load_plugin": "_load_plugin()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L20 | neighbors=[test_plugin.py, Re-import plugin module fresh., .test_first_turn_returns_bootstrap_cont…, .test_hook_tolerates_future_kwargs(), .test_later_turns_return_none(), .test_non_subagent_platforms_receive_bo…]
- "input_action_map_find": "find()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L83 | neighbors=[action_map.cpp, add_binding(), bindings(), clear_bindings(), contains(), define_action()]
- "moonclean_moon_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L169 | neighbors=[moon_map.py, crater_ramp(), craters(), hub(), peak(), foot()]
- "moonclean_moon_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L412 | neighbors=[moon_map.py, build(), face(), free(), Hm(), on_ramp()]
- "petsim_pet_map_link": "link()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L286 | neighbors=[pet_map.py, build(), anchor(), edge_pt(), face(), H()]
- "petsim_pet_props_puff": "puff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L70 | neighbors=[pet_props.py, cloud(), crystal_clump(), crystal_spire(), egg_stand(), pet_statue()]
- "refmatch_compare_evaluate": "evaluate()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L442 | neighbors=[compare.py, band_errors(), band_widths(), bbox_report(), hist_correlation(), load_alpha()]
- "refmatch_palette_report": "palette_report.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, compare_to_render(), delta_e(), extract(), hex_of()]
- "scripts_generate_report": "generate_report.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/generate_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, aggregate_findings(), clean_severity(), format_code_link(), load_json()]
- "scripts_orchestrator_main": "main()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/orchestrator.py:L1168 | neighbors=[orchestrator.py, determine_primary_identity(), extract_manifest_details(), _filter_by_flavor(), generate_triage_summary(), load_app_plugin_aliases()]
- "semantic_emit": "emit.cpp" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L1 | neighbors=[2d01203 Final MUT-01..30 audit: stress …, 335e0dc Add MUT-26 IR-to-bytecode emitt…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, alu(), br16()]
- "skyrise_sky_map_micro_detail": "micro_detail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L332 | neighbors=[sky_map.py, build(), ext(), free(), island_at(), kit()]
- "skyrise_sky_map_zone_island": "zone_island()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L277 | neighbors=[sky_map.py, build(), face(), free(), island_at(), maker()]
- "skyrise_sky_props_sphere": "sphere()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L58 | neighbors=[sky_props.py, bridge(), bush(), cactus(), chest(), cloud()]
- "stdlib_stdlib_crypto": "stdlib_crypto.cpp" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L1 | neighbors=[60d8044 Mute crypto hostcalls: fail exp…, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, append_u32_be(), compress(), crypto_hostcall_defs()]
- "tests_test_sequence": "test_sequence.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_sequence.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_a_blockout_sequence_needs_blockout…, test_blockout_lint_holds_recipes_to_mat…, test_detail_needs_the_blockout_gate_and…, test_game_frames_become_evidence_and_a_…]
- "texture_tex_to_maps": "tex_to_maps.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, blur(), derive_ao(), derive_normal(), derive_roughness()]
- "unit_optimize_test": "optimize_test.cpp" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L1 | neighbors=[e499073 Add MUT-29 dead-code eliminatio…, cases(), check(), count_instrs(), count_op(), i32t()]
- "vfxkit_workflow": "workflow.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, absolute(), digest(), effect_id(), file_hash()]
- "whispering_grove_forest_props_elder_tree": "elder_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L512 | neighbors=[forest_props.py, arch_cap(), arch_frame(), arch_prism(), arch_tunnel(), at()]
- "blender_character_blockout": "character_blockout.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L1 | neighbors=[box(), build(), capsule(), get_collection(), link(), purge_scene()]
- "blender_explorer_common": "explorer_common.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L1 | neighbors=[assign(), cylinder(), Dim, link_to(), loft(), mat()]
- "candyland_candy_props_soft": "soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L112 | neighbors=[candy_props.py, candy_cane(), candy_castle(), choco_falls(), cone_tower(), cotton_candy_tree()]
- "canyonbazaar_canyon_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L442 | neighbors=[canyon_map.py, build(), cx(), free(), H(), hw()]
- "cavemap_cave_map_clusters": "clusters()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L504 | neighbors=[cave_map.py, build(), free(), H(), in_hole(), lake_d()]
- "cavemap_cave_map_in_hole": "in_hole()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L87 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), floor(), fungi()]
- "cavemap_cave_map_rocks": "rocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L404 | neighbors=[cave_map.py, build(), layered rock masses along every wall fo…, free(), in_hole(), lake_d()]
- "cavemap_cave_props_v": "V()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L34 | neighbors=[cave_props.py, add_crystal(), flowstone_curtain(), geode(), glow_vine(), mound()]
- "cavemap_cave_props2_w": "W()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L10 | neighbors=[cave_props2.py, crates(), mine_cart(), mine_frame(), mine_lantern_post(), ore_pile()]
- "commit:repo:github.com/Raft-The-Crab/pokox@85b7130e02b055babd8c6b7c59480aab90c62e41": "85b7130 Close MUT-26 limits: AST-to-SSA lowering and load_imm literals" | kind=Commit | source=git | neighbors=[45151c3 Refresh graph after MUT-26 emit…, main, bytecode.cpp, d14bc19 Refresh graph after MUT-26 lowe…, test_version.py, bytecode.hpp]
- "creaturelab_lab_props_emblem": "emblem()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L110 | neighbors=[lab_props.py, leaf_poly(), .add(), upright(), emblem_badge(), floor_mat()]
- "dunedesert_dune_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L133 | neighbors=[dune_map.py, dig_spots(), fragments(), nature(), add_owner(), fit()]
- "dunedesert_dune_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L46 | neighbors=[dune_props.py, dry_shrub(), grid_quad(), obelisk_fallen(), outcrop(), pylon_gate()]
- "extensions_superpowers": "superpowers.ts" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bootstrapSkillPath, extensionDir, firstNonCompactionSummaryIndex(), getBootstrapContent()]
- "fishcenter_fish_props_pole": "pole()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L53 | neighbors=[fish_props.py, bait_shop(), drying_rack(), hut_body(), lerp(), quest_board()]
- "medievalbattle_battle_props_gatehouse": "gatehouse()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L398 | neighbors=[battle_props.py, ash_sh(), ashlar(), ell_outline(), heater_shield(), in_arch()]
- "medievalbattle_battle_props_heater_shield": "heater_shield()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L241 | neighbors=[battle_props.py, battle_debris(), curtain_wall(), gatehouse(), lathe(), T()]
- "net_crypto_aead": "crypto_aead.hpp" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, aead_open(), aead_seal(), chacha20_block(), chacha20_xor(), consttime_equal()]
- "petsim_pet_map_crystal": "crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L516 | neighbors=[pet_map.py, build(), breakables(), face(), fence_ring(), free()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-006.json

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
