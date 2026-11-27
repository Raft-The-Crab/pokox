# Node Description Batch 27 of 209

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

- "dunedesert_dune_props_sleep_tent": "sleep_tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L632 | neighbors=[dune_props.py, A-frame nomad tent: ridge pole on two f…, lerp(), peg_rope(), rolled_rug(), sheet()]
- "dunedesert_gen_trees_with_palms_branch": "Branch" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L331 | neighbors=[gen_trees_with_palms.py, .at(), .__init__(), .length(), .grow(), .grow_roots()]
- "dunedesert_gen_trees_with_palms_card_quads": "card_quads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L549 | neighbors=[gen_trees_with_palms.py, .at(), .length(), rand_unit(), .env(), Leaf-cluster cards (folded, 4 tris) or …]
- "dunedesert_gen_trees_with_palms_leaf_atlas": "leaf_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L270 | neighbors=[gen_trees_with_palms.py, Canvas, .capsule_path(), .finish(), .leaf(), fft_noise()]
- "dunedesert_gen_trees_with_palms_main": "main()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1271 | neighbors=[gen_trees_with_palms.py, contact_sheet(), export_glb(), make_tree(), render_turntable(), setup_scene()]
- "dunedesert_gen_trees_with_palms_normal_from_height": "normal_from_height()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L42 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), .finish()]
- "dunedesert_gen_trees_with_palms_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L66 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), t array -> colour from [(pos, (r,g,b)),…]
- "dunedesert_gen_trees_with_palms_tree_children_of": ".children_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L380 | neighbors=[Tree, .build(), .at(), .length(), .env(), .grow()]
- "dunedesert_gen_trees_with_palms_tree_laterals": ".laterals()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L474 | neighbors=[paired side sprays in the (roughly hori…, Tree, .build_conifer(), .at(), .length(), .grow()]
- "effekseer_ai_authoring_layerbuilder_bind": ".bind()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L153 | neighbors=[LayerBuilder, _code(), .scalar(), _number(), .layer(), Fixed position/scale that a dynamic equ…]
- "effekseer_ai_authoring_layerbuilder_scalar": ".scalar()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L123 | neighbors=[LayerBuilder, .bind(), .color(), .curve(), .uv(), .vector()]
- "effekseer_ai_authoring_layerbuilder_uv": ".uv()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L142 | neighbors=[LayerBuilder, .advanced(), .layer(), .rand(), .scalar(), Bind a texture slot and optionally scro…]
- "effekseer_ai_session_effectsession_object_at_path": "._object_at_path()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L348 | neighbors=[EffectSession, .curve_keys(), .curve_set_keys(), .import_image(), .import_model(), ._property_parent()]
- "eggplots_egg_map_spawn_area": "spawn_area()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L276 | neighbors=[egg_map.py, build(), anchor(), place(), reserve(), to_world()]
- "eggplots_egg_props_egg_drain": "egg_drain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L647 | neighbors=[egg_props.py, egg_profile(), post(), rbox(), sh(), the drain at the south end: a low woven…]
- "eggplots_egg_props_foot_bridge": "foot_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L496 | neighbors=[egg_props.py, egg_profile(), lerp(), rbox(), sh(), humped plank footbridge over the belt (…]
- "eggplots_egg_props_sell_stand": "sell_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L748 | neighbors=[egg_props.py, Sell stand: orange / cream awning, a ba…, egg(), rbox(), sh(), stall()]
- "eggplots_egg_props_upgrade_stand": "upgrade_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L722 | neighbors=[egg_props.py, Upgrades stand: teal / cream awning, a …, egg(), rbox(), sh(), stall()]
- "fishcenter_fish_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L66 | neighbors=[fish_map.py, H_raw(), islet_grass(), nature(), piling(), seabed / islets; out at the world edge …]
- "fishcenter_fish_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L409 | neighbors=[fish_map.py, build(), pos(), static(), tangent(), tropical volcanic islands in 3 overlapp…]
- "fishcenter_fish_map_islet_e": "islet_e()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L54 | neighbors=[fish_map.py, H_raw(), outward(), pos(), tangent(), <= 1 inside an islet's ellipse (smalles…]
- "fishcenter_fish_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L213 | neighbors=[fish_map.py, beam(), compass(), deck_rect(), platform(), ring_deck()]
- "fishcenter_fish_map_tangent": "tangent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L36 | neighbors=[fish_map.py, horizon(), islet_e(), islet_grass(), lp(), nature()]
- "fishcenter_fish_props_drying_rack": "drying_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L730 | neighbors=[fish_props.py, fish(), lash(), pole(), rope(), fish drying rack: two bamboo A-frames, …]
- "fishcenter_fish_props_loft": "loft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L73 | neighbors=[fish_props.py, awning(), bait_shop(), hammock_palms(), quads between successive rings (lists o…, thatch_band()]
- "fishcenter_fish_props_merge_prop": "_merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L394 | neighbors=[fish_props.py, aquarium_dome(), hammock_palms(), palm_planter(), copy a built Prop's geometry into P (mo…, sea_stack()]
- "fishcenter_fish_props_palm_planter": "palm_planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L381 | neighbors=[fish_props.py, _fern(), lerp(), _merge_prop(), palm(), woven round planter (bamboo hoops) with…]
- "fishcenter_fish_props_sign_board": "sign_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L255 | neighbors=[fish_props.py, aquarium_dome(), fish_index_wall(), quest_board(), BLANK carved sign board for a GUI label…, ball()]
- "fishcenter_fish_props_skiff": "skiff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1148 | neighbors=[fish_props.py, rowboat (white, teal stripe, red bottom…, boat_hull(), lerp(), paint_hull(), rope()]
- "fishcenter_fish_props_thatch_cone": "thatch_cone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L180 | neighbors=[fish_props.py, bait_shop(), lerp(), ring_circ(), thatch_band(), umbrella()]
- "fishcenter_fish_props_thatch_hip": "thatch_hip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L159 | neighbors=[fish_props.py, fish_index_wall(), fish_market(), hip roof of `layers` overlapping fringe…, rod_shop(), thatch_band()]
- "frostpeak_frost_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L140 | neighbors=[frost_map.py, build(), foot(), H(), kit(), sub()]
- "harness_golden": "golden.py" | kind=code-symbol | source=tools/testutils/harness/golden.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, first_difference(), main(), update_golden(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "hermes_test_plugin_fire_pre_llm": "_fire_pre_llm()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L27 | neighbors=[test_plugin.py, .test_first_turn_returns_bootstrap_cont…, .test_hook_tolerates_future_kwargs(), .test_later_turns_return_none(), .test_non_subagent_platforms_receive_bo…, .test_subagent_platform_skips_bootstrap…]
- "hermes_test_plugin_testbootstrapinjection": "TestBootstrapInjection" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L73 | neighbors=[test_plugin.py, .test_first_turn_returns_bootstrap_cont…, .test_hook_tolerates_future_kwargs(), .test_later_turns_return_none(), .test_non_subagent_platforms_receive_bo…, .test_subagent_platform_skips_bootstrap…]
- "hermes_test_plugin_testlayoutresolution": "TestLayoutResolution" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L117 | neighbors=[test_plugin.py, ._load_from(), ._stage(), .test_clone_layout_resolves_sibling_ski…, .test_flat_layout_resolves_nested_skill…, .test_missing_skills_raises_loudly()]
- "input_action_map_validate_binding": "validate_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L49 | neighbors=[action_map.cpp, add_binding(), bindings_conflict(), decode(), replace_binding(), set_bindings()]
- "input_input_snapshot_decode": "decode()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L295 | neighbors=[input_snapshot.cpp, append(), get16(), get32(), get64(), get8()]
- "input_input_snapshot_put_event": "put_event()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L21 | neighbors=[input_snapshot.cpp, encode(), put16(), put32(), put8(), snapshot_hash()]
- "input_input_snapshot_put32": "put32()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L15 | neighbors=[input_snapshot.cpp, encode(), hash(), put8(), put_event(), snapshot_hash()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-026.json

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
