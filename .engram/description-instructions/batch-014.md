# Node Description Batch 15 of 209

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

- "whispering_grove_forest_props_prop_gadd": ".gadd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L39 | neighbors=[altar(), campfire(), crystal_cluster(), elder_tree(), lantern_post(), mushroom()]
- "animation_build_animations": "build_animations.py" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L1 | neighbors=[foot(), interp(), loc(), rot(), smooth(), f4a6ac4 Allowlist known validation-laye…]
- "brainstorm_server_branding_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L9 | neighbors=[branding.test.js, assertBrandedFallbackText(), assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap()]
- "brainstorm_server_ws_protocol_test": "ws-protocol.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L1 | neighbors=[assert, crypto, path, runTests(), SERVER_PATH, RFC-6455]
- "brick_bone_hydra_brick_full": "full()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L39 | neighbors=[bone_hydra_brick.py, cap(), crack(), keep_main(), obox(), oell()]
- "brick_bone_hydra_brick_sl_of": "sl_of()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L36 | neighbors=[bone_hydra_brick.py, cap(), head(), obox(), oell(), rblock()]
- "cad_skill_main_outline_from_scan": "outline_from_scan.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L1 | neighbors=[align_and_scale(), main(), max_section_outline(), recentered(), rotate_min_square(), Extract a 2D pocket outline from a 3D s…]
- "candyland_candy_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L132 | neighbors=[candy_map.py, build(), add_owner(), fit(), kit(), sub()]
- "candyland_candy_props_candy_lamp": "candy_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1104 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), striped_tube()]
- "candyland_candy_props_choco_falls": "choco_falls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L770 | neighbors=[candy_props.py, bell_r(), icing_cap(), lathe(), soft(), sugar()]
- "candyland_candy_props_drip_ring": "drip_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L186 | neighbors=[candy_props.py, bakery_oven(), candy_castle(), cone_tower(), cupcake_fountain(), drip()]
- "candyland_candy_props_sign_plate": "sign_plate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L226 | neighbors=[candy_props.py, bakery_oven(), egg_machine(), gumball_machine(), quest_stand(), blank wafer sign: cream face in a beade…]
- "canyonbazaar_canyon_map_cx": "cx()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L30 | neighbors=[canyon_map.py, dcx(), nature(), path_x(), set_pieces(), sight_x()]
- "canyonbazaar_canyon_props_brass_lantern": "brass_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L84 | neighbors=[canyon_props.py, carved_stair(), lantern_post(), market_gate(), parapet_niche(), quest_board()]
- "cavemap_cave_map_ceil_y": "ceil_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L236 | neighbors=[cave_map.py, H(), dripstone(), landmarks(), place_soft(), inner shell height above (x, z) by rayc…]
- "cavemap_cave_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L240 | neighbors=[cave_map.py, build(), ceil_y(), clip_fail(), in_hole(), place()]
- "cavemap_cave_props_add_crystal": "add_crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L158 | neighbors=[cave_props.py, crystal(), FS(), V(), crystal_shards(), crystal_spray()]
- "cavemap_cave_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L359 | neighbors=[cave_props.py, glowshroom_cluster(), glowshroom_giant(), cap_shape(), dot(), FS()]
- "cavemap_cave_props_rock_layered": "rock_layered()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L164 | neighbors=[cave_props.py, one carved, layered rock: strata_mass b…, add_crystal(), moss_cap(), rim_shade(), RS()]
- "commit:repo:github.com/Raft-The-Crab/pokox@06cfbe9e4fbffb81cc55daa10e2292b2984c85bb": "06cfbe9 Narrowphase: local pair frame + exact 64-bit FixedVec3 math" | kind=Commit | source=git | neighbors=[main, 5eb3f50 Mute det_pow: integer-exponent …, fixed_vec.hpp, character_controller.cpp, narrowphase.cpp, fixed_vec_test.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@335e0dc6982122cdac6a1533e9a23586dbdd7e7e": "335e0dc Add MUT-26 IR-to-bytecode emitter" | kind=Commit | source=git | neighbors=[13dbd75 Refresh graph after MUT-25 SSA …, main, 45151c3 Refresh graph after MUT-26 emit…, test_version.py, emit.hpp, ssa.hpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@5edd00c010ccde8d1111054e65d1f8e09dea4e1c": "5edd00c Fix MUT-21/22 audit defects in package resolver and values runtime" | kind=Commit | source=git | neighbors=[main, 56f5271 Refresh graph after MUT-21/22 a…, package.hpp, values.hpp, package.cpp, values_test.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@7eabc2dee71058f696096d33083f9a8fe7617a5b": "7eabc2d Merge pull request #8 from Raft-The-Crab/mini-code/b4d7e813-e93" | kind=Commit | source=git | neighbors=[72b9ac7 Merge branch 'main' into mini-c…, 78dbd1e Merge pull request #7 from Raft…, lifecycle.test.js, main, 981b52c Crated IDN-01 to IDN-04, stdlib_physics.hpp]
- "creaturelab_lab_map_hardscape": "hardscape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L184 | neighbors=[lab_map.py, build(), inset_top(), path_z_y(), polar_tiles(), sh_val()]
- "creaturelab_lab_props_emblem_badge": "emblem_badge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L124 | neighbors=[lab_props.py, emblem(), .add(), entrance_canopy(), heal_machine(), lab_archway()]
- "creaturelab_lab_props_heal_corner": "heal_corner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1575 | neighbors=[lab_props.py, ball(), merge_prop(), plush(), rbox(), .add()]
- "creaturelab_lab_props_heal_counter": "heal_counter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L213 | neighbors=[lab_props.py, ball(), emblem(), lerp(), pot_plant(), rbox()]
- "creaturelab_lab_props_heal_machine": "heal_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L152 | neighbors=[lab_props.py, ball(), cradle(), emblem_badge(), rbox(), .add()]
- "creaturelab_lab_props_med_shelf": "med_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L297 | neighbors=[lab_props.py, bottle(), leaf_poly(), rbox(), shelf_frame(), .add()]
- "creaturelab_lab_props_merge_prop": "merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L85 | neighbors=[lab_props.py, evo_chamber(), heal_corner(), lab_wing(), copy a built Prop's geometry into P (mo…, rotunda()]
- "creaturelab_lab_props_olive_tree": "olive_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2022 | neighbors=[lab_props.py, leaf_mass(), pot(), Skel, .add(), skin_mesh()]
- "creaturelab_lab_props_pot": "pot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1385 | neighbors=[lab_props.py, fiddle_fig(), fig_tree(), monstera(), olive_tree(), rbox()]
- "creaturelab_lab_props_shelf_frame": "shelf_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L284 | neighbors=[lab_props.py, capsule_shelf(), med_shelf(), potion_shelf(), open shelving: side panels, back panel,…, rbox()]
- "creaturelab_lab_props_skel": "Skel" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1939 | neighbors=[lab_props.py, fiddle_fig(), olive_tree(), park_tree(), .add(), .grow()]
- "creaturelab_lab_props_trade_desk": "trade_desk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L481 | neighbors=[lab_props.py, trade / battle registration desk: white…, ball(), capsule(), rbox(), .add()]
- "device_clear_backend_selection": "clear_backend_selection.cpp" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, clear_and_present(), ClearBackend, ClearBackendSelection(), shutdown(), start()]
- "device_fallback_clear_backends": "fallback_clear_backends.cpp" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_backends.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, clear_and_present(), initialize(), OpenGLClearBackend, shutdown(), VulkanClearBackend]
- "device_poko_jni": "poko_jni.cpp" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, run_probe(), write_line()]
- "device_vulkan_clear_android_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L213 | neighbors=[vulkan_clear_android.cpp, make_device_objects(), make_instance(), make_surface(), make_swapchain(), pick_device()]
- "dunedesert_dune_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L473 | neighbors=[dune_map.py, build(), free(), on_path(), place(), reserve()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-014.json

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
