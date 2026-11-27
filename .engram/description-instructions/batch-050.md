# Node Description Batch 51 of 209

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

- "fishcenter_fish_props_paint_hull": "paint_hull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1136 | neighbors=[fish_props.py, motor_boat(), hull shading: bottom colour below the w…, skiff()]
- "fishcenter_fish_props_plank_floor": "plank_floor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L219 | neighbors=[fish_props.py, fish_market(), hut_body(), deck platform: planks along `along` wit…]
- "fishcenter_fish_props_post": "_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L271 | neighbors=[fish_props.py, ball(), rail_bay(), rail_post()]
- "fishcenter_fish_props_rail_bay": "rail_bay()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L279 | neighbors=[fish_props.py, _post(), rope(), SIGNATURE edge module: post at -L/2, tw…]
- "fishcenter_fish_props_shutter": "shutter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L793 | neighbors=[fish_props.py, boat_house(), propped top-hinged window shutter (wove…, rod_shop()]
- "fishcenter_fish_props_tiki_torch": "tiki_torch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L295 | neighbors=[fish_props.py, bamboo torch: pole with nodes, lashings…, lash(), pole()]
- "fishcenter_fish_props_tropical_shrub": "tropical_shrub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L411 | neighbors=[fish_props.py, elephant-ear clump: paddle leaves on ar…, ball(), lerp()]
- "fishcenter_fish_props_umbrella": "umbrella()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L698 | neighbors=[fish_props.py, palapa sun shade: teak pole on a stone …, pole(), thatch_cone()]
- "foundation_build_flags": "build_flags.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/build_flags.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "foundation_cbor": "cbor.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/cbor.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Member(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "foundation_config_logging": "config_logging.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/config_logging.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, LogGuard, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "foundation_fixed_vec_length": "length()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L148 | neighbors=[fixed_vec.hpp, isqrt_u64(), raw_length_sq(), saturate_raw64()]
- "foundation_frame_stats": "frame_stats.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/frame_stats.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, FrameStats, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "frostpeak_frost_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L156 | neighbors=[frost_map.py, build(), look(), scatter()]
- "frostpeak_frost_map_front_to": "front_to()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L153 | neighbors=[frost_map.py, build(), face(), yaw that turns a building's +Z front (i…]
- "frostpeak_frost_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L68 | neighbors=[frost_map.py, path_info(), place(), spread()]
- "frostpeak_frost_map_keepout": "keepout()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L84 | neighbors=[frost_map.py, build(), path_info(), scatter()]
- "frostpeak_frost_map_path_info": "path_info()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L53 | neighbors=[frost_map.py, H(), keepout(), segd()]
- "frostpeak_frost_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L168 | neighbors=[frost_map.py, build(), free(), keepout()]
- "frostpeak_frost_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L157 | neighbors=[frost_map.py, build(), height range of the terrain over a foot…, H()]
- "fuzz_fuzz_bytecode": "fuzz_bytecode.cpp" | kind=code-symbol | source=fuzz/fuzz_bytecode.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, LLVMFuzzerTestOneInput(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "fuzz_fuzz_cbor": "fuzz_cbor.cpp" | kind=code-symbol | source=fuzz/fuzz_cbor.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, LLVMFuzzerTestOneInput(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "fuzz_fuzz_lexer": "fuzz_lexer.cpp" | kind=code-symbol | source=fuzz/fuzz_lexer.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, LLVMFuzzerTestOneInput(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "fuzz_fuzz_pokomesh": "fuzz_pokomesh.cpp" | kind=code-symbol | source=fuzz/fuzz_pokomesh.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, LLVMFuzzerTestOneInput(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "godot_ablation_report_analyse": "analyse()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L64 | neighbors=[ablation_report.py, image_change(), view_baseline(), main()]
- "godot_ablation_report_image_change": "image_change()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L45 | neighbors=[ablation_report.py, analyse(), luminance(), view_baseline()]
- "godot_ablation_report_view_baseline": "view_baseline()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L53 | neighbors=[ablation_report.py, analyse(), Full-scene GPU ms and noise floors for …, image_change()]
- "hermes_plugin_init_register": "register()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L93 | neighbors=[__init__.py, _build_bootstrap(), _frontmatter_value(), _skills_dir()]
- "hermes_test_bootstrap_teststripfrontmatter": "TestStripFrontmatter" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L29 | neighbors=[test_bootstrap.py, .test_no_frontmatter_returns_trimmed_co…, .test_strips_surrounding_whitespace_fro…, .test_strips_yaml_block()]
- "hermes_test_plugin_testlayoutresolution_load_from": "._load_from()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L132 | neighbors=[TestLayoutResolution, .test_clone_layout_resolves_sibling_ski…, .test_flat_layout_resolves_nested_skill…, .test_missing_skills_raises_loudly()]
- "hermes_test_plugin_testlayoutresolution_stage": "._stage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L118 | neighbors=[Copy the plugin module + a minimal skil…, TestLayoutResolution, .test_clone_layout_resolves_sibling_ski…, .test_flat_layout_resolves_nested_skill…]
- "hermes_test_plugin_testpluginregistration": "TestPluginRegistration" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L41 | neighbors=[test_plugin.py, .test_register_attaches_only_pre_llm_ca…, .test_register_registers_every_stock_sk…, .test_registered_skills_match_skill_dir…]
- "imgui_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/RefCntAutoPtr.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, RefCntAutoPtr, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "input_action_map_add_binding": "add_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L105 | neighbors=[action_map.cpp, bindings_conflict(), find(), validate_binding()]
- "input_action_map_encode": "encode()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L174 | neighbors=[action_map.cpp, put16(), put32(), put8()]
- "input_action_map_put32": "put32()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L16 | neighbors=[action_map.cpp, encode(), hash(), put8()]
- "input_action_map_read_bytes": "read_bytes()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L19 | neighbors=[action_map.cpp, get16(), get32(), get8()]
- "input_action_map_replace_binding": "replace_binding()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L117 | neighbors=[action_map.cpp, bindings_conflict(), find(), validate_binding()]
- "input_input_snapshot_gamepad_connected": "gamepad_connected()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L103 | neighbors=[input_snapshot.cpp, apply(), gamepad_axis_value(), gamepad_button_down()]
- "input_input_snapshot_put16": "put16()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L12 | neighbors=[input_snapshot.cpp, hash(), put8(), put_event()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-050.json

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
