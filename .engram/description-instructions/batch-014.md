# Node Description Batch 15 of 208

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
- "device_vulkan_clear_android_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L213 | neighbors=[vulkan_clear_android.cpp, make_device_objects(), make_instance(), make_surface(), make_swapchain(), pick_device()]
- "dunedesert_dune_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L473 | neighbors=[dune_map.py, build(), free(), on_path(), place(), reserve()]
- "dunedesert_gen_trees_with_palms_canvas_capsule_path": ".capsule_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L131 | neighbors=[Canvas, .grid(), .over(), frond_atlas(), leaf_atlas(), needle_atlas()]
- "effekseer_ai_session_effectsession_node": "._node()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L323 | neighbors=[EffectSession, .add_node(), .move_node(), .property_list(), ._property_parent(), .property_set()]
- "effekseer_ai_session_effectsession_property_set": ".property_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L112 | neighbors=[EffectSession, .import_image(), ._assign_value(), ._is_exported_property(), ._node(), ._property_parent()]
- "eggplots_egg_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L358 | neighbors=[egg_map.py, dressing(), ground(), hardscape(), lane(), plot()]
- "eggplots_egg_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L76 | neighbors=[egg_map.py, dressing(), lane(), foot(), Hg(), kit()]
- "eggplots_egg_props_gate_frame": "gate_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L204 | neighbors=[egg_props.py, egg(), egg_finial(), lerp(), rbox(), sh()]
- "eggplots_egg_props_stall": "stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L680 | neighbors=[egg_props.py, egg_shop(), market stand shell: stone footing, hone…, sell_stand(), rbox(), sh()]
- "evaluator_evaluator_materialize": "materialize()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L80 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), is_unsigned(), signed_max(), unsigned_max()]
- "evaluator_evaluator_signed_binary": "signed_binary()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L200 | neighbors=[evaluator.cpp, evaluate_arithmetic(), fail(), magnitude(), negative(), signed_max()]
- "fishcenter_fish_map_edges": "edges()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L518 | neighbors=[fish_map.py, build(), arc_with_gaps(), halfang(), lp(), place()]
- "fishcenter_fish_map_islet_grass": "islet_grass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L376 | neighbors=[fish_map.py, build(), H(), outward(), pos(), static()]
- "fishcenter_fish_map_ring_deck": "ring_deck()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L250 | neighbors=[fish_map.py, hardscape(), the ring boardwalk: radial planks (acro…, beam(), piling(), pos()]
- "fishcenter_fish_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L129 | neighbors=[fish_map.py, ground(), hardscape(), horizon(), islet_grass(), add_owner()]
- "fishcenter_fish_map_stations": "stations()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L563 | neighbors=[fish_map.py, build(), anchor(), lp(), lp_y(), place()]
- "fishcenter_fish_props_hammock_palms": "hammock_palms()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L709 | neighbors=[fish_props.py, lash(), lerp(), loft(), _merge_prop(), palm()]

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
