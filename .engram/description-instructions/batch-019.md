# Node Description Batch 20 of 207

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
- "examples_arctic_fox": "arctic_fox.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), idle(), pounce(), wag()]
- "examples_bunny": "bunny.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, big_jump(), build(), ear_wiggle(), hop()]
- "examples_duck": "duck.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), flap(), idle(), quack()]
- "examples_owl": "owl.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), flap(), head_turn(), idle()]
- "examples_penguin": "penguin.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), flap(), idle(), slide()]
- "examples_red_panda": "red_panda.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), idle(), pounce(), wag()]
- "fishcenter_fish_props_aquarium_dome": "aquarium_dome()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1200 | neighbors=[fish_props.py, brain_coral(), coral_branch(), fish(), _merge_prop(), sign_board()]
- "fishcenter_fish_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L552 | neighbors=[fish_props.py, bait_shop(), lerp(), barrels(), fish_market(), motor_boat()]
- "fishcenter_fish_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L525 | neighbors=[fish_props.py, fish(), local(), crate_stack(), fish_market(), quest_board()]
- "fishcenter_fish_props_welcome_arch": "welcome_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1081 | neighbors=[fish_props.py, WELCOME ARCH on the spawn axis: two las…, ball(), fish(), lash(), pole()]
- "foundation_fixed": "fixed.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, cos(), divide(), Fixed, sin(), sine_lookup()]
- "foundation_vec3f": "vec3f.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, cross(), dot(), length(), lengthSquared(), normalized()]
- "hermes_plugin_init": "__init__.py" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _build_bootstrap(), _frontmatter_value(), register(), _skills_dir()]
- "hermes_test_bootstrap": "test_bootstrap.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bootstrap(), _load(), TestBootstrapContent, TestSkillsDirResolution]
- "hermes_test_bootstrap_load": "_load()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L18 | neighbors=[test_bootstrap.py, _bootstrap(), .test_tool_mapping_sourced_from_referen…, .test_repo_layout_resolves(), .test_no_frontmatter_returns_trimmed_co…, .test_strips_surrounding_whitespace_fro…]

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
