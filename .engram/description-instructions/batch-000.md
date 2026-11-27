# Node Description Batch 1 of 208

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

- "scripts_pro_lib_palette": "Palette" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L36 | neighbors=[cotton-candy tree: twisting pretzel tru…, 3-5 sugar-coated gumdrops of different …, frame mountain: a huge sugar-coated gum…, a bean: tube along a gentle arc with ro…, rock' scatter: a heap of 6-9 glossy jel…, patch of fondant flowers: lime stems, 6…]
- "commit:repo:github.com/Raft-The-Crab/pokox@2680d0e706ba1c80ef1e51f22aab399f4abb6d95": "2680d0e Pushed an update." | kind=Commit | source=git | neighbors=[__init__.py, operators.py, ui.py, trace_processor, character_blockout.py, explorer_build.py]
- "commit:repo:github.com/Raft-The-Crab/pokox@e77fa31f6e8f186ec776a897d3f5fdbc2435dc64": "e77fa31 Add new skills and asset packs to .agents/skills" | kind=Commit | source=git | neighbors=[81d94fb Merge pull request #5 from Raft…, __init__.py, operators.py, ui.py, trace_processor, character_blockout.py]
- "commit:repo:github.com/Raft-The-Crab/pokox@52dbcb928ed5f7ea8b81a6f983c23971a2826f91": "52dbcb9 Surface graphics warnings in X11 test failure output" | kind=Commit | source=git | neighbors=[build_animations.py, check_subframes.py, build_refined.py, check_gait.py, check_model_structure.py, validate_refined.py]
- "commit:repo:github.com/Raft-The-Crab/pokox@c7a411f85ed05ea2f272624b312ea07488b41542": "c7a411f Fix MUT-01-20 audit defects in Mute parsers" | kind=Commit | source=git | neighbors=[build_animations.py, check_subframes.py, build_refined.py, check_gait.py, check_model_structure.py, validate_refined.py]
- "scripts_pro_lib_mb": "MB" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L92 | neighbors=[trails, plazas, river, castle hill, fal…, one board tile: the polyline section s0…, board-game tile runs (TILE long, 0.7 ga…, chocolate river surface (glossy, streak…, icing poured over the frosting hilltops…, deferred foliage: place, test against a…]
- "creaturelab_lab_props": "lab_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, adeg(), arc_wall(), art_frame(), ball()]
- "scripts_pro_lib_sh": "Sh" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L65 | neighbors=[dressed round trebuchet shot: smooth la…, trebuchet shot: round stones stacked on…, running-bond ashlar panel in the XY pla…, tapered timber assault tower on six sol…, wheeled ram shed: post frame, gable roo…, wheeled oak pavise: planks with a cut s…]
- "creaturelab_lab_props_skel_add": ".add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1941 | neighbors=[arc_wall(), art_frame(), berry_baskets(), blossom_tree(), bollard_light(), bottle()]
- "medievalbattle_battle_props": "battle_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_into(), ammo_pile(), ash_sh(), ashlar()]
- "vfxkit_primitives": "primitives.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, VFX_Dark_Vortex.py, VFX_Fire_Explosion.py, VFX_Heal.py, VFX_Hit_Heavy.py]
- "branch:repo:github.com/Raft-The-Crab/pokox#main": "main" | kind=Branch | source=git | neighbors=[037434c Add MUT-24 determinism and capa…, 038387e Character controller: value-key…, 0621f1d Merge pull request #1 from Raft…, 06cfbe9 Narrowphase: local pair frame +…, 080a665 Refresh graph after MUT-21 pack…, 0ab64e5 Refresh graph after lowering as…]
- "fishcenter_fish_props": "fish_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, aquarium_dome(), awning(), bait_bucket(), bait_shop()]
- "commit:repo:github.com/Raft-The-Crab/pokox@952997ed27d559f4e6440bbb95d25bedb8a6d145": "952997e Audit MUT-01-55 and harden verification scripts" | kind=Commit | source=git | neighbors=[2d01203 Final MUT-01..30 audit: stress …, main, bytecode.cpp, 69287a0 Land ENG-60-65 deterministic si…, opengles_native_activity.cpp, loop.hpp]
- "valleylake_valley_map": "valley_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, anchor(), beach(), build(), build_profile()]
- "candyland_candy_props": "candy_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1 | neighbors=[bakery_oven(), ball(), bell_r(), biscuit_bridge(), candy_cane(), candy_castle()]
- "petsim_pet_props": "pet_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arc_pts(), bench(), bridge(), bubble_crown()]
- "medievalbattle_battle_props_t": "T()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L43 | neighbors=[battle_props.py, ammo_pile(), barrel(), battering_ram(), battle_debris(), boulder()]
- "cavemap_cave_map": "cave_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L1 | neighbors=[air(), anchor(), build(), build_dist(), build_solid(), bvh_of()]
- "dunedesert_dune_props": "dune_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, block_wall(), camel(), campfire(), cargo_pile()]
- "valleylake_valley_props": "valley_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bark(), barrel(), basket(), blossom_tree()]
- "eggplots_egg_props": "egg_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, barn(), bench(), boulder(), bush()]
- "creaturelab_lab_props_rbox": "rbox()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L55 | neighbors=[lab_props.py, art_frame(), berry_baskets(), bottle(), bush(), capsule_shelf()]
- "fishcenter_fish_map": "fish_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_owner(), anchor(), arc_with_gaps(), bay_key()]
- "onsenvillage_onsen_props": "onsen_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, balcony(), bath_pavilion(), bench(), boulder()]
- "petsim_pet_map": "pet_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, anchor(), breakables(), build(), build_solid()]
- "whispering_grove_forest_props": "forest_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, altar(), arch_cap(), arch_frame(), arch_outline()]
- "effekseer_ai_session_effectsession": "EffectSession" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L15 | neighbors=[LayerBuilder, Reusable, discovered-property layer aut…, Field names accepted by layer specs, fo…, Bind a texture slot and optionally scro…, Fixed position/scale that a dynamic equ…, Optional native features: dissolve, UV …]
- "moonclean_moon_props": "moon_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, airlock_gate(), beacon_post(), beacon_rail(), beam()]
- "stdlib_stdlib_math": "stdlib_math.cpp" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 5eb3f50 Mute det_pow: integer-exponent …, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, advance(), det_clamp()]
- "candyland_candy_map": "candy_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L1 | neighbors=[add_owner(), anchor(), axis_coords(), build(), bump(), castle_h()]
- "dunedesert_gen_trees_with_palms": "gen_trees_with_palms.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, arg(), bark_birch(), bark_fir(), bark_oak()]
- "moonclean_moon_map": "moon_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, adiff(), build(), crater_at(), _crater_ok()]
- "dunedesert_dune_map": "dune_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_owner(), anchor(), build(), build_solid()]
- "petsim_pet_props_soft": "soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L51 | neighbors=[pet_props.py, bench(), bridge(), bubble_crown(), chest(), cloud()]
- "voidrealm_void_props": "void_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, annulus(), arena_rim(), brazier(), chamfer_box()]
- "canyonbazaar_canyon_map": "canyon_map.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L1 | neighbors=[build(), cx(), dcx(), edge_rhythm(), foot(), free()]
- "whispering_grove_forest_props_prop": "Prop" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L34 | neighbors=[village-square roll well: stone ring, t…, ice-fishing shanty: board walls on skid…, hero: stone terrace + a 60-stud ice cry…, grove pine re-shaded: every up-facing t…, log cabin: stacked logs with crossed co…, forest_props.py]
- "brick_bone_hydra_brick": "bone_hydra_brick.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L1 | neighbors=[B(), bez(), box(), build(), cap(), catmull()]
- "cad_skill_main_gridfinity_gridfinitybin": "GridfinityBin" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L186 | neighbors=[gridfinity.py, .add_compartments(), .add_cylinder_pocket(), .add_finger_notch(), .add_pocket(), .add_polygon_pocket()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-000.json

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
