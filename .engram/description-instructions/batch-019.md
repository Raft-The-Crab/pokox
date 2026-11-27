# Node Description Batch 20 of 208

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

- "creaturelab_lab_props_leaf_ball": "leaf_ball()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1030 | neighbors=[lab_props.py, bush(), .add(), long_planter(), potted_tree(), chunky stylised leaf mass: a blob + a f…]
- "creaturelab_lab_props_leaf_cluster": "leaf_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1373 | neighbors=[lab_props.py, fig_tree(), hanging_planter(), ball(), .add(), clustered round leaves: n small smooth …]
- "creaturelab_lab_props_leaf_mass": "leaf_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2041 | neighbors=[lab_props.py, clump(), leaf_sh(), .add(), olive_tree(), park_tree()]
- "creaturelab_lab_props_leaf_poly": "leaf_poly()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L100 | neighbors=[lab_props.py, catch_ball(), emblem(), evo_chamber(), med_shelf(), plush()]
- "creaturelab_lab_props_plush": "plush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1562 | neighbors=[lab_props.py, heal_corner(), ball(), leaf_poly(), .add(), upright()]
- "creaturelab_lab_props_pot_plant": "pot_plant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L253 | neighbors=[lab_props.py, heal_counter(), lerp(), .add(), small round pot + leafy sprouts (used o…, rest_nook()]
- "creaturelab_lab_props_round_bush": "round_bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1510 | neighbors=[lab_props.py, smooth round shrub: soft leaf mound wit…, ball(), leaf_cluster(), .add(), round_planter()]
- "creaturelab_lab_props_supply_boxes": "supply_boxes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1610 | neighbors=[lab_props.py, Shop story: stacked supply cartons (cre…, capsule(), emblem(), rbox(), .add()]
- "creaturelab_lab_props_wall_shelf_lab": "wall_shelf_lab()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1254 | neighbors=[lab_props.py, lab wall shelving: steel frame, binders…, bottle(), pot_plant(), rbox(), shelf_frame()]
- "creaturelab_lab_props_welcome_sign": "welcome_sign()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1151 | neighbors=[lab_props.py, entry monolith on the path: rounded whi…, emblem_badge(), merge_prop(), rbox(), round_bush()]
- "device_clear_backend_selection": "clear_backend_selection.cpp" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, clear_and_present(), ClearBackend, ClearBackendSelection(), shutdown(), start()]
- "device_fallback_clear_backends": "fallback_clear_backends.cpp" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_backends.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, clear_and_present(), initialize(), OpenGLClearBackend, shutdown(), VulkanClearBackend]
- "device_poko_jni": "poko_jni.cpp" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, run_probe(), write_line()]
- "dunedesert_dune_map_fragments": "fragments()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L519 | neighbors=[dune_map.py, build(), free(), on_path(), place(), reserve()]
- "dunedesert_dune_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L166 | neighbors=[dune_map.py, add_owner(), build_solid(), fragments(), look(), nature()]
- "dunedesert_dune_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L167 | neighbors=[dune_map.py, build(), dig_spots(), fragments(), nature(), set_pieces()]
- "dunedesert_dune_map_set_pieces": "set_pieces()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L357 | neighbors=[dune_map.py, build(), anchor(), face(), place(), reserve()]
- "dunedesert_dune_map_waystones": "waystones()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L448 | neighbors=[dune_map.py, build(), path markers every ~30 studs along each…, face(), free(), place()]
- "dunedesert_dune_props_colossus_head": "colossus_head()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L971 | neighbors=[dune_props.py, disc(), smooth(), sun_relief(), uvsphere(), V()]
- "dunedesert_dune_props_disc": "disc()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L87 | neighbors=[dune_props.py, colossus_head(), a disc on the plane facing -Z (thicknes…, _shaft(), spawn_dais(), step_pyramid()]
- "dunedesert_dune_props_merge_into": "merge_into()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L63 | neighbors=[dune_props.py, obelisk(), obelisk_fallen(), obelisk_stump(), merge a temporary Prop's solid (+ glow)…, ruin_house()]
- "dunedesert_dune_props_step_pyramid": "step_pyramid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L169 | neighbors=[dune_props.py, HERO: six-tier gilded step pyramid (ash…, column(), disc(), grid_quad(), sun_relief()]
- "dunedesert_gen_trees_with_palms_branch_at": ".at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L336 | neighbors=[Branch, card_quads(), conifer_cards(), .build(), .build_conifer(), .children_of()]
- "dunedesert_gen_trees_with_palms_canvas_finish": ".finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L186 | neighbors=[Canvas, normal_from_height(), frond_atlas(), leaf_atlas(), needle_atlas(), palm_twig_atlas()]
- "dunedesert_gen_trees_with_palms_fft_noise": "fft_noise()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L33 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), leaf_atlas()]
- "dunedesert_gen_trees_with_palms_tree_build": ".build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L411 | neighbors=[make_tree(), Tree, .at(), .build_conifer(), .children_of(), .grow()]
- "dunedesert_gen_trees_with_palms_tree_grow": ".grow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L365 | neighbors=[Tree, .build(), .build_conifer(), .children_of(), Branch, rand_unit()]
- "effekseer_ai_authoring_layerbuilder_advanced": ".advanced()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L171 | neighbors=[LayerBuilder, cutoff_easing(), .color(), .uv(), .vector(), .layer()]
- "effekseer_ai_authoring_layerbuilder_layer": ".layer()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L252 | neighbors=[compile_effect(), LayerBuilder, .advanced(), .bind(), .curve(), .uv()]
- "effekseer_ai_authoring_validate_layer": "validate_layer()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L49 | neighbors=[authoring.py, compile_effect(), .layer(), List problems the compiler would otherw…, _code(), _term()]
- "effekseer_ai_runtime": "runtime.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, editor_bin_directory(), export_binary(), load_core(), runtime_config_path()]
- "eggplots_egg_map_dressing": "dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L302 | neighbors=[egg_map.py, build(), free(), isle_d(), isle_point(), place()]
- "eggplots_egg_map_hardscape": "hardscape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L116 | neighbors=[egg_map.py, build(), inset_top(), sh_val(), static(), T()]
- "eggplots_egg_props_egg_shop": "egg_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L706 | neighbors=[egg_props.py, egg(), rbox(), sh(), stall(), straw_nest()]
- "eggplots_egg_props_hatchery": "hatchery()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L520 | neighbors=[egg_props.py, egg_finial(), egg_profile(), rbox(), sh(), straw_nest()]
- "eggplots_egg_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L49 | neighbors=[egg_props.py, egg(), egg_slice(), foot_bridge(), gate_frame(), plot_slab()]
- "eggplots_egg_props_owner_sign": "owner_sign()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L233 | neighbors=[egg_props.py, egg_finial(), post(), rbox(), sh(), upright()]
- "eggplots_egg_props_post": "post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L152 | neighbors=[egg_props.py, egg_drain(), fence_post(), owner_sign(), rbox(), sh()]
- "eggplots_egg_props_upright": "upright()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L59 | neighbors=[egg_props.py, barn(), coop(), fence_run(), owner_sign(), 2D poly [(x, up)] standing upright faci…]
- "evaluator_evaluator_width": "width()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L45 | neighbors=[evaluator.cpp, evaluate_arithmetic(), materialize(), signed_binary(), suffix_length(), unary()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-019.json

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
