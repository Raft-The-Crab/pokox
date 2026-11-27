# Node Description Batch 16 of 209

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
- "godot_ablation_report": "ablation_report.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyse(), image_change(), luminance(), main()]
- "hermes_test_bootstrap_bootstrap": "_bootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L24 | neighbors=[test_bootstrap.py, _load(), .test_contains_using_superpowers_body(), .test_frontmatter_stripped(), .test_marker_and_wrapper(), .test_skill_view_guidance_present()]
- "hermes_test_plugin": "test_plugin.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _fire_pre_llm(), _load_plugin(), TestBootstrapInjection, TestLayoutResolution]
- "imgui_enginefactoryvk": "EngineFactoryVk.h" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Diligent(), GraphicsPipeline(), IDeviceObject(), IEngineFactory(), RTVFormats()]
- "input_action_map_bindings_conflict": "bindings_conflict()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L75 | neighbors=[action_map.cpp, add_binding(), is_axis_device(), sign_of(), validate_binding(), conflicts()]
- "integration_config_file_test_head": "head()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L20 | neighbors=[config_file_test.cpp, put_arr(), put_b(), put_map(), put_n(), put_t()]
- "integration_config_file_test_test_config": "test_config()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L170 | neighbors=[config_file_test.cpp, main(), put_bool(), put_kv(), put_map(), put_t()]
- "integration_test_shader_pipeline": "test_shader_pipeline.py" | kind=code-symbol | source=engine/render/tests/integration/test_shader_pipeline.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, check_spirv(), run(), update_shader(), Exercise the real host compiler and CMa…]
- "medievalbattle_battle_map_field": "field()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L382 | neighbors=[battle_map.py, build(), face(), Hm(), place(), reserve()]
- "medievalbattle_battle_map_keep": "keep()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L296 | neighbors=[battle_map.py, build(), courtyard(), Hm(), place(), reserve()]
- "medievalbattle_battle_props_ashlar": "ashlar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L103 | neighbors=[battle_props.py, curtain_wall(), donjon_face(), gatehouse(), parapet_front(), running-bond ashlar panel in the XY pla…]
- "medievalbattle_battle_props_battering_ram": "battering_ram()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1099 | neighbors=[battle_props.py, bar(), lathe(), lerp(), T(), torus()]
- "medievalbattle_battle_props_course_wall": "course_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L162 | neighbors=[battle_props.py, smooth(), T(), donjon(), a wall of real stone blocks from (x, z)…, ruined_chapel()]
- "medievalbattle_battle_props_donjon_top": "donjon_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L508 | neighbors=[battle_props.py, ash_sh(), ashlar_ring(), donjon_face(), lathe(), merge()]
- "medievalbattle_battle_props_ladder": "ladder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1361 | neighbors=[battle_props.py, bar(), lerp(), log(), rot_mb(), T()]
- "medievalbattle_battle_props_stone": "stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L157 | neighbors=[battle_props.py, buttress(), one real block (ruins, rubble, steps, q…, rubble(), ruined_chapel(), T()]
- "medievalbattle_battle_props_weapon_rack": "weapon_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1326 | neighbors=[battle_props.py, A-frame rack: five spears, three swords…, bar(), frame_to(), heater_shield(), lathe()]
- "moonclean_moon_map_adiff": "adiff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L60 | neighbors=[moon_map.py, _crater_ok(), ground(), hub(), lip_rails(), on_ramp()]
- "moonclean_moon_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L107 | neighbors=[moon_map.py, ground(), crater_at(), pock_at(), profile(), ramp_w()]
- "moonclean_moon_map_top_of": "top_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L165 | neighbors=[moon_map.py, crater_ramp(), highest mesh point under a prop's footp…, scatter(), foot(), Hm()]
- "moonclean_moon_props_dust_exchange": "dust_exchange()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L153 | neighbors=[moon_props.py, beam(), lathe(), lerp(), rivets(), station_base()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-015.json

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
