# Node Description Batch 50 of 207

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

- "frostpeak_frost_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L168 | neighbors=[frost_map.py, build(), free(), keepout()]
- "frostpeak_frost_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L157 | neighbors=[frost_map.py, build(), height range of the terrain over a foot…, H()]
- "godot_ablation_report_analyse": "analyse()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L64 | neighbors=[ablation_report.py, image_change(), view_baseline(), main()]
- "godot_ablation_report_image_change": "image_change()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L45 | neighbors=[ablation_report.py, analyse(), luminance(), view_baseline()]
- "godot_ablation_report_view_baseline": "view_baseline()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L53 | neighbors=[ablation_report.py, analyse(), Full-scene GPU ms and noise floors for …, image_change()]
- "harness_golden": "golden.py" | kind=code-symbol | source=tools/testutils/harness/golden.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, first_difference(), main(), update_golden()]
- "hermes_plugin_init_register": "register()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L93 | neighbors=[__init__.py, _build_bootstrap(), _frontmatter_value(), _skills_dir()]
- "hermes_test_bootstrap_teststripfrontmatter": "TestStripFrontmatter" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L29 | neighbors=[test_bootstrap.py, .test_no_frontmatter_returns_trimmed_co…, .test_strips_surrounding_whitespace_fro…, .test_strips_yaml_block()]
- "hermes_test_plugin_testlayoutresolution_load_from": "._load_from()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L132 | neighbors=[TestLayoutResolution, .test_clone_layout_resolves_sibling_ski…, .test_flat_layout_resolves_nested_skill…, .test_missing_skills_raises_loudly()]
- "hermes_test_plugin_testlayoutresolution_stage": "._stage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L118 | neighbors=[Copy the plugin module + a minimal skil…, TestLayoutResolution, .test_clone_layout_resolves_sibling_ski…, .test_flat_layout_resolves_nested_skill…]
- "hermes_test_plugin_testpluginregistration": "TestPluginRegistration" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L41 | neighbors=[test_plugin.py, .test_register_attaches_only_pre_llm_ca…, .test_register_registers_every_stock_sk…, .test_registered_skills_match_skill_dir…]
- "input_action_map_add_binding": "add_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L105 | neighbors=[action_map.cpp, bindings_conflict(), find(), validate_binding()]
- "input_action_map_encode": "encode()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L174 | neighbors=[action_map.cpp, put16(), put32(), put8()]
- "input_action_map_put32": "put32()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L16 | neighbors=[action_map.cpp, encode(), hash(), put8()]
- "input_action_map_read_bytes": "read_bytes()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L19 | neighbors=[action_map.cpp, get16(), get32(), get8()]
- "input_action_map_replace_binding": "replace_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L117 | neighbors=[action_map.cpp, bindings_conflict(), find(), validate_binding()]
- "input_input_snapshot_gamepad_connected": "gamepad_connected()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L103 | neighbors=[input_snapshot.cpp, apply(), gamepad_axis_value(), gamepad_button_down()]
- "input_input_snapshot_put16": "put16()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L12 | neighbors=[input_snapshot.cpp, hash(), put8(), put_event()]
- "input_input_snapshot_touch_display_connected": "touch_display_connected()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L120 | neighbors=[input_snapshot.cpp, apply(), touch_down(), touch_position()]
- "integration_config_file_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L291 | neighbors=[config_file_test.cpp, test_config(), test_decoder(), test_resolve()]
- "integration_config_file_test_put_bool": "put_bool()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L38 | neighbors=[config_file_test.cpp, test_config(), test_decoder(), test_resolve()]
- "integration_cube_golden_canonical_png": "canonical_png()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L30 | neighbors=[cube_golden.py, png_chunk(), RGB8 PNG with filter 0 and explicit unc…, run()]
- "integration_logging_file_test": "logging_file_test.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/logging_file_test.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, count_stamps(), main(), read_file()]
- "integration_test_cube_golden_unit": "test_cube_golden_unit.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, c7a411f Fix MUT-01-20 audit defects in …, decode(), GoldenEncoderTests]
- "math_deterministic_math_calculate": "calculate()" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L18 | neighbors=[deterministic_math.cpp, supported(), deterministic_cos(), deterministic_sin()]
- "medievalbattle_battle_map_channels": "channels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L38 | neighbors=[battle_map.py, fordw(), H(), [(centre x, half width, bed y)] of the …]
- "medievalbattle_battle_map_cull_hidden": "cull_hidden()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L108 | neighbors=[battle_map.py, free(), kit(), drop faces buried inside the prop's own…]
- "medievalbattle_battle_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L198 | neighbors=[battle_map.py, build(), grid_mesh(), sub()]
- "medievalbattle_battle_map_keep_w": "keep_w()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L74 | neighbors=[battle_map.py, base(), ground_shade(), H()]
- "medievalbattle_battle_map_trench_drop": "trench_drop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L54 | neighbors=[battle_map.py, ground_shade(), H(), seg_d()]
- "medievalbattle_battle_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L261 | neighbors=[battle_map.py, build(), 4-stud water grid kept only where water…, sub()]
- "medievalbattle_battle_map_yw": "Yw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L35 | neighbors=[battle_map.py, centre(), field(), keep()]
- "medievalbattle_battle_props_add_into": "add_into()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L230 | neighbors=[battle_props.py, bridge_tower(), donjon(), slit_cutter()]
- "medievalbattle_battle_props_ammo_pile": "ammo_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1025 | neighbors=[battle_props.py, shot_stone(), T(), trebuchet shot: round stones stacked on…]
- "medievalbattle_battle_props_ashlar_ring": "ashlar_ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L121 | neighbors=[battle_props.py, donjon_top(), ashlar on a cylinder of radius R (flat …, tower_body()]
- "medievalbattle_battle_props_broadleaf": "broadleaf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1498 | neighbors=[battle_props.py, log(), T(), field oak: flared, slightly twisted tru…]
- "medievalbattle_battle_props_drystone_wall": "drystone_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1398 | neighbors=[battle_props.py, rough_stone(), T(), low field wall of tightly stacked rough…]
- "medievalbattle_battle_props_flame": "flame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1204 | neighbors=[battle_props.py, brazier(), campfire(), T()]
- "medievalbattle_battle_props_in_arch": "in_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L361 | neighbors=[battle_props.py, gatehouse(), sundered_bridge(), tower_face()]
- "medievalbattle_battle_props_rot_mb": "rot_mb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L964 | neighbors=[battle_props.py, broken_cart(), ladder(), pew()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-049.json

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
