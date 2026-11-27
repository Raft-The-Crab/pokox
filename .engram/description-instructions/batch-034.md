# Node Description Batch 35 of 208

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

- "dunedesert_dune_props_grid_quad": "grid_quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L70 | neighbors=[dune_props.py, lerp(), flat top split into ~cell faces (the at…, ruin_house(), step_pyramid()]
- "dunedesert_dune_props_obelisk_stump": "obelisk_stump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L406 | neighbors=[dune_props.py, merge_into(), plinth(), _shaft(), sun_relief()]
- "dunedesert_dune_props_plinth": "plinth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L129 | neighbors=[dune_props.py, obelisk(), obelisk_stump(), quest_stele(), SHARED BASE: stepped sandstone plinth, …]
- "dunedesert_dune_props_quest_stele": "quest_stele()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L459 | neighbors=[dune_props.py, frustum(), plinth(), sun_relief(), QUEST stand: tall carved tablet on the …]
- "dunedesert_dune_props_rolled_rug": "rolled_rug()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L566 | neighbors=[dune_props.py, cargo_pile(), lerp(), sleep_tent(), trader_tent()]
- "dunedesert_dune_props_ruin_house": "ruin_house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L301 | neighbors=[dune_props.py, corner of a roofless house: two block w…, block_wall(), grid_quad(), merge_into()]
- "dunedesert_dune_props_sack": "sack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L560 | neighbors=[dune_props.py, cargo_pile(), uvsphere(), V(), trader_tent()]
- "dunedesert_dune_props_sheet": "sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L527 | neighbors=[dune_props.py, camel(), a cloth sheet over a parametric surface…, sleep_tent(), trader_tent()]
- "dunedesert_dune_props_treasure_mound": "treasure_mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L813 | neighbors=[dune_props.py, DIG SPOT anchors: tier 1 a low sand mou…, uvsphere(), V(), waystone_body()]
- "dunedesert_dune_props_wyrm_rib": "wyrm_rib()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L939 | neighbors=[dune_props.py, one segment of the wyrm's spine lying b…, lerp(), uvsphere(), V()]
- "dunedesert_dune_props_wyrm_skull": "wyrm_skull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L908 | neighbors=[dune_props.py, giant sand-wyrm skull lying jaw-open in…, lerp(), uvsphere(), V()]
- "dunedesert_dune_props_zig_band": "zig_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L105 | neighbors=[dune_props.py, pylon_gate(), raised zigzag band between two rails (c…, step_pyramid(), sunken_temple()]
- "dunedesert_gen_trees_with_palms_bark_fir": "bark_fir()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L100 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp(), fir / spruce: scaly grey-brown plates w…]
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
