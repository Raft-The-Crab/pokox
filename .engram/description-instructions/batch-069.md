# Node Description Batch 70 of 208

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
For an entity node (any other kind — e.g. a person, place, event, object),
describe what the entity is and its role, grounded in its type, its
relations (neighbors) and the provided citations/evidence — e.g.
"Lady Carfax, a wealthy heiress who disappears en route to Lausanne.".
Ground entity descriptions in the citations/evidence when present; do not
speculate beyond the context, so a node with no supporting context may be
left out of the reply.
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "foundation_fixed_vec_dot": "dot()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L131 | neighbors=[fixed_vec.hpp, saturate_raw64(), lengthSquared()] | lang=en
- "foundation_fixed_vec_isqrt_u64": "isqrt_u64()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L98 | neighbors=[fixed_vec.hpp, length(), normalized()] | lang=en
- "foundation_fixed_vec_normalized": "normalized()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L160 | neighbors=[fixed_vec.hpp, isqrt_u64(), raw_length_sq()] | lang=en
- "foundation_fixed_vec_raw_length_sq": "raw_length_sq()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L116 | neighbors=[fixed_vec.hpp, length(), normalized()] | lang=en
- "foundation_fixed_vec_saturate_raw64": "saturate_raw64()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L91 | neighbors=[fixed_vec.hpp, dot(), length()] | lang=en
- "foundation_frame_stats": "frame_stats.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/frame_stats.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, FrameStats, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "foundation_vec3f_dot": "dot()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L56 | neighbors=[vec3f.hpp, length(), lengthSquared()] | lang=en
- "foundation_vec3f_length": "length()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L63 | neighbors=[vec3f.hpp, dot(), normalized()] | lang=en
- "framegraph_frame_graph_build_plan": "build_plan()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L31 | neighbors=[frame_graph.cpp, compile(), execute()] | lang=en
- "frostpeak_frost_kit_sheet": "frost_kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()] | lang=en
- "frostpeak_frost_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L152 | neighbors=[frost_map.py, build(), front_to()] | lang=en
- "frostpeak_frost_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L132 | neighbors=[frost_map.py, build(), place()] | lang=en
- "frostpeak_frost_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L94 | neighbors=[frost_map.py, build(), sub()] | lang=en
- "frostpeak_frost_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L129 | neighbors=[frost_map.py, build(), place()] | lang=en
- "frostpeak_frost_map_square": "square()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L118 | neighbors=[frost_map.py, build(), sub()] | lang=en
- "frostpeak_frost_props_rationale_173": "village-square roll well: stone ring, timber A-frame + roof, rope + bucket, glow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L173 | neighbors=[roll_well(), Palette, Prop] | lang=en
- "frostpeak_frost_props_rationale_217": "ice-fishing shanty: board walls on skids, door + window, stovepipe, ridge-capped" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L217 | neighbors=[fishing_hut(), Palette, Prop] | lang=nl
- "frostpeak_frost_props_rationale_260": "hero: stone terrace + a 60-stud ice crystal spire with orbiting shards and a run" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L260 | neighbors=[frost_spire(), Palette, Prop] | lang=en
- "frostpeak_frost_props_rationale_35": "grove pine re-shaded: every up-facing tier face carries snow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L35 | neighbors=[snow_pine(), Palette, Prop] | lang=en
- "frostpeak_frost_props_rationale_47": "log cabin: stacked logs with crossed corners, the door gap is left IN the log co" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L47 | neighbors=[cabin(), Palette, Prop] | lang=en
- "fuzz_fuzz_bytecode": "fuzz_bytecode.cpp" | kind=code-symbol | source=fuzz/fuzz_bytecode.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, LLVMFuzzerTestOneInput(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "fuzz_fuzz_cbor": "fuzz_cbor.cpp" | kind=code-symbol | source=fuzz/fuzz_cbor.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, LLVMFuzzerTestOneInput(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "fuzz_fuzz_lexer": "fuzz_lexer.cpp" | kind=code-symbol | source=fuzz/fuzz_lexer.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, LLVMFuzzerTestOneInput(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "fuzz_fuzz_pokomesh": "fuzz_pokomesh.cpp" | kind=code-symbol | source=fuzz/fuzz_pokomesh.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, LLVMFuzzerTestOneInput(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "gles_clear_pokoactivity_pokoactivity_nativesetsurface": ".nativeSetSurface()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L17 | neighbors=[PokoActivity, .surfaceChanged(), .surfaceCreated()] | lang=en
- "gles_clear_pokoactivity_pokoactivity_nativesurfacedestroyed": ".nativeSurfaceDestroyed()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L18 | neighbors=[PokoActivity, .onDestroy(), .surfaceDestroyed()] | lang=en
- "harness_golden_first_difference": "first_difference()" | kind=code-symbol | source=tools/testutils/harness/golden.py:L16 | neighbors=[golden.py, main(), Return the first differing offset and s…] | lang=en
- "harness_golden_main": "main()" | kind=code-symbol | source=tools/testutils/harness/golden.py:L54 | neighbors=[golden.py, first_difference(), update_golden()] | lang=en
- "harness_golden_update_golden": "update_golden()" | kind=code-symbol | source=tools/testutils/harness/golden.py:L35 | neighbors=[golden.py, main(), Replace the reference atomically, only …] | lang=en
- "hermes_conftest": "conftest.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/conftest.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, mock_ctx()] | lang=en
- "hermes_plugin_init_build_bootstrap": "_build_bootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L59 | neighbors=[__init__.py, _strip_frontmatter(), register()] | lang=en
- "hermes_plugin_init_frontmatter_value": "_frontmatter_value()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L40 | neighbors=[__init__.py, Return a flat ``key: value`` scalar fro…, register()] | lang=en
- "hermes_plugin_init_skills_dir": "_skills_dir()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L8 | neighbors=[__init__.py, Locate the stock skills/ tree for eithe…, register()] | lang=en
- "hermes_test_bootstrap_testbootstrapcontent_test_tool_mapping_sourced_from_reference_file": ".test_tool_mapping_sourced_from_reference_file()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L75 | neighbors=[TestBootstrapContent, _bootstrap(), _load()] | lang=en
- "hermes_test_plugin_testbootstrapinjection_test_first_turn_returns_bootstrap_context": ".test_first_turn_returns_bootstrap_context()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L74 | neighbors=[TestBootstrapInjection, _fire_pre_llm(), _load_plugin()] | lang=en
- "hermes_test_plugin_testbootstrapinjection_test_hook_tolerates_future_kwargs": ".test_hook_tolerates_future_kwargs()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L108 | neighbors=[TestBootstrapInjection, _fire_pre_llm(), _load_plugin()] | lang=en
- "hermes_test_plugin_testbootstrapinjection_test_later_turns_return_none": ".test_later_turns_return_none()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L84 | neighbors=[TestBootstrapInjection, _fire_pre_llm(), _load_plugin()] | lang=en
- "hermes_test_plugin_testbootstrapinjection_test_non_subagent_platforms_receive_bootstrap": ".test_non_subagent_platforms_receive_bootstrap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L98 | neighbors=[TestBootstrapInjection, _fire_pre_llm(), _load_plugin()] | lang=en
- "hermes_test_plugin_testbootstrapinjection_test_subagent_platform_skips_bootstrap_on_first_turn": ".test_subagent_platform_skips_bootstrap_on_first_turn()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L90 | neighbors=[TestBootstrapInjection, _fire_pre_llm(), _load_plugin()] | lang=en
- "hermes_test_plugin_testlayoutresolution_test_clone_layout_resolves_sibling_skills": ".test_clone_layout_resolves_sibling_skills()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_plugin.py:L141 | neighbors=[TestLayoutResolution, ._load_from(), ._stage()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-069.json

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
