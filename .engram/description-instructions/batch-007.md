# Node Description Batch 8 of 208

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

- "fishcenter_fish_props_pole": "pole()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L53 | neighbors=[fish_props.py, bait_shop(), drying_rack(), hut_body(), lerp(), quest_board()]
- "lexer_lexer": "lexer.cpp" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, decode(), digit(), digit_for(), is_continue(), is_start()]
- "medievalbattle_battle_props_gatehouse": "gatehouse()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L398 | neighbors=[battle_props.py, ash_sh(), ashlar(), ell_outline(), heater_shield(), in_arch()]
- "medievalbattle_battle_props_heater_shield": "heater_shield()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L241 | neighbors=[battle_props.py, battle_debris(), curtain_wall(), gatehouse(), lathe(), T()]
- "net_crypto_aead": "crypto_aead.hpp" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, aead_open(), aead_seal(), chacha20_block(), chacha20_xor(), consttime_equal()]
- "passes_imgui_demo": "imgui_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Exception, build_demo_window(), composite(), ensure_gpu_timer(), feed_imgui_event()]
- "petsim_pet_map_crystal": "crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L516 | neighbors=[pet_map.py, build(), breakables(), face(), fence_ring(), free()]
- "pi_test_pi_extension": "test-pi-extension.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, __dirname, emit(), extensionPath, firstHandler()]
- "plugins_superpowers": "superpowers.js" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bootstrapCache, _cacheChildSession(), _childSessionCache, __dirname]
- "plusspeed_plus_props_v3_shop_stall": "shop_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L111 | neighbors=[plus_props_v3.py, SPEED SHOP: platform with a ramp, panel…, barrel(), bulbs_frame(), chamfer_block(), cyl_v()]
- "scripts_smart_material": "smart_material.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_mat(), build_group(), curvature_attribute(), _G]
- "scripts_surface_weather": "surface_weather.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_mat(), build_group(), _G, _remove_mat()]
- "scripts_template_engine": "template_engine.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, compile_template(), EachNode, get_nested_val(), IfNode]
- "src_logging": "logging.cpp" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, critical(), debug(), emit(), error(), info()]
- "src_solver": "solver.cpp" | kind=code-symbol | source=engine/physics/src/solver.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, add_contact(), begin_step(), clear()]
- "tests_fixtures": "fixtures.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, cube(), detached_part(), mesh_object(), plane()]
- "tests_test_examples": "test_examples.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, example_ids(), test_catalog_lists_every_shipped_exampl…, test_each_example_source_loads_and_matc…, test_example_show_accepts_pair_and_sing…]
- "tests_test_qa_qa": "_qa()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L9 | neighbors=[test_qa.py, test_clean_cube_passes(), test_detects_floating_parts_and_objects…, test_detects_inverted_and_inconsistent_…, test_detects_zfighting_between_objects_…, test_enclosed_part_is_not_floating()]
- "tests_test_tools": "test_tools.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_ablation_corrupt_json_exits_2(), test_ablation_verdicts(), test_flat_interior_with_seam_fails(), test_flat_tile_is_seamless()]
- "unit_capability_test": "capability_test.cpp" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 952997e Audit MUT-01-55 and harden veri…, ceiling(), check(), def(), i32()]
- "unit_evaluator_test": "evaluator_test.cpp" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, bindings(), cases(), check(), deep(), error_case()]
- "unit_input_snapshot_test": "input_snapshot_test.cpp" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, button(), gamepad_axis(), gamepad_button(), key(), main()]
- "unit_lower_test": "lower_test.cpp" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L1 | neighbors=[2c0194b Add assignments and loop-carrie…, 4cead55 Add MUT-27 bytecode verificatio…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 90b7d79 Add for-range lowering to Mute …, 952997e Audit MUT-01-55 and harden veri…, cases()]
- "vfxkit_build": "build.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), check_output_dirs(), check_resource_conflicts(), check_targets()]
- "vfxkit_ownership": "ownership.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, digest(), guard(), inside(), may_use()]
- "vfxkit_scale": "scale.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, apply(), factors(), _frames(), _layers()]
- "vfxkit_sequence_capture": "capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L199 | neighbors=[sequence.py, _frame_number(), _lab_capture(), _now(), path(), read()]
- "vfxkit_unity_textures": "textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L99 | neighbors=[unity.py, install(), Write every texture the package's share…, _blob(), _inner_gradient(), _mask()]
- "vm_values_object": "object()" | kind=code-symbol | source=mute/src/vm/values.cpp:L12 | neighbors=[values.cpp, as_string(), copy_impl(), free_slot(), get_index(), length()]
- "voidrealm_void_map_bridges": "bridges()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L225 | neighbors=[void_map.py, anchor(), edge_pt(), face(), H(), inner()]
- "voidrealm_void_map_dressing": "dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L333 | neighbors=[void_map.py, build(), clip_frac(), face(), free(), island_of()]
- "voidrealm_void_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L78 | neighbors=[void_map.py, bridges(), dressing(), foot(), H(), kit()]
- "warehouse_wh_struct": "wh_struct.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, crane_bridge(), crane_trolley(), dock_door(), high_bay()]
- "candyland_candy_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L530 | neighbors=[candy_map.py, anchor(), dist_castle(), face(), free(), H()]
- "candyland_candy_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L105 | neighbors=[candy_map.py, build(), drape_strip(), ground(), castle_h(), dist_castle()]
- "candyland_candy_props_bakery_oven": "bakery_oven()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L417 | neighbors=[candy_props.py, ball(), drip_ring(), lathe(), MS(), round_prof()]
- "candyland_candy_props_cupcake_fountain": "cupcake_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L282 | neighbors=[candy_props.py, ball(), cupcake_liner(), drip_ring(), lathe(), MS()]
- "candyland_candy_props_egg_machine": "egg_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L482 | neighbors=[candy_props.py, ball(), candy_egg(), lathe(), MS(), round_prof()]
- "candyland_candy_props_striped_tube": "striped_tube()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L149 | neighbors=[candy_props.py, bakery_oven(), candy_cane(), candy_castle(), candy_lamp(), cotton_candy_tree()]
- "candyland_candy_props_sweet_shop": "sweet_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L343 | neighbors=[candy_props.py, SWEET SHOP: gingerbread cottage, chocol…, ball(), gable_roof_bars(), lathe(), MS()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-007.json

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
