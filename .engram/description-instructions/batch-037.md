# Node Description Batch 38 of 209

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

- "oaktrees_gen_trees_branch_length": ".length()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L343 | neighbors=[Branch, card_quads(), conifer_cards(), .children_of(), .laterals()]
- "oaktrees_gen_trees_canvas_finish": ".finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L186 | neighbors=[Canvas, normal_from_height(), leaf_atlas(), needle_atlas(), twig_atlas()]
- "oaktrees_gen_trees_conifer_cards": "conifer_cards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L619 | neighbors=[gen_trees.py, .at(), .length(), rand_unit(), needle-spray cards along every branch /…]
- "oaktrees_gen_trees_get_materials": "get_materials()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L991 | neighbors=[gen_trees.py, _img(), material(), make_tree(), Trunk / Branches / Leaves materials for…]
- "oaktrees_gen_trees_needle_atlas": "needle_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L210 | neighbors=[gen_trees.py, Canvas, .capsule_path(), .finish(), 4 x 4 fir sprays: a central twig with p…]
- "oaktrees_gen_trees_normal_from_height": "normal_from_height()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L42 | neighbors=[gen_trees.py, bark_birch(), bark_fir(), bark_oak(), .finish()]
- "oaktrees_gen_trees_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L66 | neighbors=[gen_trees.py, bark_birch(), bark_fir(), bark_oak(), t array -> colour from [(pos, (r,g,b)),…]
- "oaktrees_gen_trees_rand_unit": "rand_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L346 | neighbors=[gen_trees.py, card_quads(), conifer_cards(), .grow(), .grow_roots()]
- "oaktrees_gen_trees_tree_build_conifer": ".build_conifer()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L450 | neighbors=[Tree, .build(), .at(), .grow(), .laterals()]
- "oaktrees_gen_trees_tree_grow_roots": ".grow_roots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L426 | neighbors=[surface roots: leave the trunk foot out…, Tree, .build(), Branch, rand_unit()]
- "onsenvillage_onsen_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L119 | neighbors=[onsen_map.py, add_owner(), look(), nature(), steam()]
- "onsenvillage_onsen_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L194 | neighbors=[onsen_map.py, build(), mountains(), static(), stage ground (smooth: banks, stream bed…]
- "onsenvillage_onsen_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L120 | neighbors=[onsen_map.py, build(), nature(), stories(), village()]
- "onsenvillage_onsen_map_stories": "stories()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L409 | neighbors=[onsen_map.py, build(), clusters of 2-4 at the stairs and bridg…, place(), reserve()]
- "onsenvillage_onsen_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L263 | neighbors=[onsen_map.py, build(), stream + front pool surface: 4-stud cel…, H(), static()]
- "onsenvillage_onsen_props_balcony": "balcony()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L176 | neighbors=[onsen_props.py, giboshi(), lerp(), house(), deck on brackets along a wall at z (sid…]
- "onsenvillage_onsen_props_skirt_roof": "skirt_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L118 | neighbors=[onsen_props.py, house(), pagoda(), pent roof around a storey (pagoda tiers…, flared_roof()]
- "passes_triangle_demo": "triangle_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/triangle_demo.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Exception, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "petsim_pet_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L194 | neighbors=[pet_map.py, crystal(), egg_stand(), hub(), link()]
- "petsim_pet_map_frame": "frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L537 | neighbors=[pet_map.py, build(), place(), seg_d(), clouds + rocks on the lagoon round the …]
- "petsim_pet_map_isle_mesh": "isle_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L59 | neighbors=[pet_map.py, build(), isle_R(), top_y(), polar top (dome) + rounded icing should…]
- "petsim_pet_map_path": "path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L217 | neighbors=[pet_map.py, build(), hub(), catmull(), zone()]
- "petsim_pet_map_plaza": "plaza()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L255 | neighbors=[pet_map.py, hub(), H(), static(), polar tile disc: rings of soft tiles al…]
- "petsim_pet_map_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L48 | neighbors=[pet_map.py, H(), isle_mesh(), isle_R(), polar()]
- "petsim_pet_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1032 | neighbors=[pet_props.py, ell(), rbox(), soft(), chubby rounded bench: two soft seat sla…]
- "petsim_pet_props_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L682 | neighbors=[pet_props.py, ell(), rbox(), soft(), rounded treasure chest: plank body, dom…]
- "petsim_pet_props_giant_donut": "giant_donut()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L943 | neighbors=[pet_props.py, flat(), pill(), soft(), pink-frosted donut lying tilted on the …]
- "petsim_pet_props_gift_box": "gift_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L702 | neighbors=[pet_props.py, ell(), rbox(), soft(), chubby present: soft box, crossing ribb…]
- "petsim_pet_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L837 | neighbors=[pet_props.py, ell(), flat(), soft(), chubby toadstool: bulgy stem, domed cap…]
- "petsim_pet_props_picnic_set": "picnic_set()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L854 | neighbors=[pet_props.py, ell(), puff(), soft(), checkered blanket (cells alternate red …]
- "petsim_pet_props_rainbow_arch": "rainbow_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L335 | neighbors=[pet_props.py, puff(), soft(), star(), 6 chunky pastel bands on a half circle,…]
- "petsim_pet_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L618 | neighbors=[pet_props.py, round spawn dais: two soft tiers, mint …, paw(), rcyl(), soft()]
- "petsim_pet_props_trade_pad": "trade_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L519 | neighbors=[pet_props.py, flat trade circle: cream disc with a pa…, arc_pts(), rcyl(), soft()]
- "physics_visual_solver": "visual_solver.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, VisualSolver, VisualWorld]
- "plusspeed_plus_props_v3_lamp_pillar": "lamp_pillar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L90 | neighbors=[plus_props_v3.py, chamfer_block(), cyl_v(), octo(), street lantern pillar: chamfered steppe…]
- "plusspeed_plus_props_v3_octo": "octo()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L20 | neighbors=[plus_props_v3.py, hatchery(), lamp_pillar(), 8-sided column from two overlapping blo…, shop_stall()]
- "plusspeed_plus_props_v3_rebirth_altar": "rebirth_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L196 | neighbors=[plus_props_v3.py, REBIRTH portal: 8-sided stepped dais wi…, chamfer_block(), cyl_v(), ring()]
- "plusspeed_plus_props_v3_ring": "ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L29 | neighbors=[plus_props_v3.py, hatchery(), n blocks laid tangent around a circle (…, rebirth_altar(), wins_pad()]
- "preserved_verify_preservation": "verify_preservation.py" | kind=code-symbol | source=assets/characters/preserved/verify_preservation.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, capture(), floats(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "program_program_run_stateful_program": "run_stateful_program()" | kind=code-symbol | source=mute/src/program/program.cpp:L321 | neighbors=[program.cpp, run_program(), commit_globals(), fail(), prepare_globals()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-037.json

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
