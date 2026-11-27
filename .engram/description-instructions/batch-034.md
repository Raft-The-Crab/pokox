# Node Description Batch 35 of 207

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

- "dunedesert_gen_trees_with_palms_bark_palm": "bark_palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L858 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp(), leaf-scar rings (rows) with interlockin…]
- "dunedesert_gen_trees_with_palms_branch_length": ".length()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L343 | neighbors=[Branch, card_quads(), conifer_cards(), .children_of(), .laterals()]
- "dunedesert_gen_trees_with_palms_conifer_cards": "conifer_cards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L619 | neighbors=[gen_trees_with_palms.py, .at(), .length(), rand_unit(), needle-spray cards along every branch /…]
- "dunedesert_gen_trees_with_palms_frond_atlas": "frond_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L875 | neighbors=[gen_trees_with_palms.py, Canvas, .capsule_path(), .finish(), 4 x 4 pinnate fronds: rachis up the cel…]
- "dunedesert_gen_trees_with_palms_get_materials": "get_materials()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1218 | neighbors=[gen_trees_with_palms.py, _img(), material(), make_tree(), Trunk / Branches / Leaves materials for…]
- "dunedesert_gen_trees_with_palms_needle_atlas": "needle_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L210 | neighbors=[gen_trees_with_palms.py, Canvas, .capsule_path(), .finish(), 4 x 4 fir sprays: a central twig with p…]
- "dunedesert_gen_trees_with_palms_palm_twig_atlas": "palm_twig_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L906 | neighbors=[gen_trees_with_palms.py, Canvas, .capsule_path(), .finish(), cells 0, 1: dry brown hanging fronds; c…]
- "dunedesert_gen_trees_with_palms_rand_unit": "rand_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L346 | neighbors=[gen_trees_with_palms.py, card_quads(), conifer_cards(), .grow(), .grow_roots()]
- "dunedesert_gen_trees_with_palms_tree_build_conifer": ".build_conifer()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L450 | neighbors=[Tree, .build(), .at(), .grow(), .laterals()]
- "dunedesert_gen_trees_with_palms_tree_grow_roots": ".grow_roots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L426 | neighbors=[surface roots: leave the trunk foot out…, Tree, .build(), Branch, rand_unit()]
- "effekseer_ai_authoring_compile_effect": "compile_effect()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L381 | neighbors=[authoring.py, LayerBuilder, .layer(), validate_layer(), Build a fresh document from a JSON reci…]
- "effekseer_ai_models": "models.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/models.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, assign_procedural_model(), model_schema(), Create Core procedural meshes with vali…]
- "effekseer_ai_runtime_load_core": "load_core()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L43 | neighbors=[runtime.py, export_binary(), editor_bin_directory(), runtime_config_path(), Load and return the official static ``E…]
- "effekseer_ai_session_effectsession_import_image": ".import_image()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L263 | neighbors=[EffectSession, ._copy_resource(), ._object_at_path(), .property_set(), Copy an image beside the effect and opt…]
- "effekseer_ai_session_effectsession_property_parent": "._property_parent()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L329 | neighbors=[EffectSession, ._object_at_path(), .property_get(), ._node(), .property_set()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-034.json

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
