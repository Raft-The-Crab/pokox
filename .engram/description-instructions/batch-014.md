# Node Description Batch 15 of 207

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

- "creaturelab_lab_props_heal_machine": "heal_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L152 | neighbors=[lab_props.py, ball(), cradle(), emblem_badge(), rbox(), .add()]
- "creaturelab_lab_props_med_shelf": "med_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L297 | neighbors=[lab_props.py, bottle(), leaf_poly(), rbox(), shelf_frame(), .add()]
- "creaturelab_lab_props_merge_prop": "merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L85 | neighbors=[lab_props.py, evo_chamber(), heal_corner(), lab_wing(), copy a built Prop's geometry into P (mo…, rotunda()]
- "creaturelab_lab_props_olive_tree": "olive_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L2022 | neighbors=[lab_props.py, leaf_mass(), pot(), Skel, .add(), skin_mesh()]
- "creaturelab_lab_props_pot": "pot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1385 | neighbors=[lab_props.py, fiddle_fig(), fig_tree(), monstera(), olive_tree(), rbox()]
- "creaturelab_lab_props_shelf_frame": "shelf_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L284 | neighbors=[lab_props.py, capsule_shelf(), med_shelf(), potion_shelf(), open shelving: side panels, back panel,…, rbox()]
- "creaturelab_lab_props_skel": "Skel" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1939 | neighbors=[lab_props.py, fiddle_fig(), olive_tree(), park_tree(), .add(), .grow()]
- "creaturelab_lab_props_trade_desk": "trade_desk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L481 | neighbors=[lab_props.py, trade / battle registration desk: white…, ball(), capsule(), rbox(), .add()]
- "device_opengles_native_activity": "opengles_native_activity.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_native_activity.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, 9b77990 Android GLES probe: no data rac…, 9eeb3ff Merge pull request #2 from Raft…, c7a411f Fix MUT-01-20 audit defects in …, android_main(), on_app_cmd()]
- "device_vulkan_clear_android_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L213 | neighbors=[vulkan_clear_android.cpp, make_device_objects(), make_instance(), make_surface(), make_swapchain(), pick_device()]
- "device_vulkan_triangle_pass": "vulkan_triangle_pass.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, draw(), draw_and_present(), Impl(), set_texture(), set_texture_mips()]
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
- "fishcenter_fish_props_hut_body": "hut_body()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L771 | neighbors=[fish_props.py, boat_house(), lash(), plank_floor(), pole(), woven_wall()]
- "fishcenter_fish_props_motor_boat": "motor_boat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1166 | neighbors=[fish_props.py, barrel(), boat_hull(), lerp(), paint_hull(), rod()]
- "fishcenter_fish_props_palm": "palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L323 | neighbors=[fish_props.py, hammock_palms(), ball(), lerp(), smooth(), palm_planter()]
- "fishcenter_fish_props_quest_board": "quest_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1012 | neighbors=[fish_props.py, ball(), crate(), lash(), pole(), rope()]
- "framegraph_frame_graph": "frame_graph.cpp" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, add_pass(), build_plan(), clear(), compile(), execute()]
- "godot_ablation_report": "ablation_report.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyse(), image_change(), luminance(), main()]
- "hermes_test_bootstrap_bootstrap": "_bootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L24 | neighbors=[test_bootstrap.py, _load(), .test_contains_using_superpowers_body(), .test_frontmatter_stripped(), .test_marker_and_wrapper(), .test_skill_view_guidance_present()]
- "hermes_test_plugin": "test_plugin.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _fire_pre_llm(), _load_plugin(), TestBootstrapInjection, TestLayoutResolution]
- "input_action_map_bindings_conflict": "bindings_conflict()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L75 | neighbors=[action_map.cpp, add_binding(), is_axis_device(), sign_of(), validate_binding(), conflicts()]
- "integration_config_file_test_head": "head()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L20 | neighbors=[config_file_test.cpp, put_arr(), put_b(), put_map(), put_n(), put_t()]
- "integration_config_file_test_test_config": "test_config()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L170 | neighbors=[config_file_test.cpp, main(), put_bool(), put_kv(), put_map(), put_t()]
- "integration_cube_golden": "cube_golden.py" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …, canonical_png(), main(), png_chunk(), run()]
- "integration_test_mute_console_x11": "test_mute_console_x11.py" | kind=code-symbol | source=engine/render/tests/integration/test_mute_console_x11.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 668ca72 Wait for X11 console input read…, 6d9948d Re-resolve X11 demo window duri…, c7a411f Fix MUT-01-20 audit defects in …, cb2a354 Re-assert window focus in X11 c…, d6139c3 Fix X11 test click helper argum…]

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
