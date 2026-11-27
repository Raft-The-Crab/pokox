# Node Description Batch 115 of 208

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "fishcenter_fish_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L43 | neighbors=[fish_props.py, palm()]
- "fishcenter_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "foundation_config": "config.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/config.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "foundation_config_logging_logguard": "LogGuard" | kind=code-symbol | source=engine/foundation/include/poko/foundation/config_logging.hpp:L15 | neighbors=[config_logging.hpp, .LogGuard()]
- "foundation_fixed_cos": "cos()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L331 | neighbors=[fixed.hpp, sine_lookup()]
- "foundation_fixed_fixed": "Fixed" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L34 | neighbors=[fixed.hpp, .Fixed()]
- "foundation_fixed_sin": "sin()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L328 | neighbors=[fixed.hpp, sine_lookup()]
- "foundation_fixed_vec_lengthsquared": "lengthSquared()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L143 | neighbors=[fixed_vec.hpp, dot()]
- "foundation_logging": "logging.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/logging.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "foundation_loop": "loop.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/loop.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, FixedStepLoop]
- "foundation_vec3f_lengthsquared": "lengthSquared()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L64 | neighbors=[vec3f.hpp, dot()]
- "foundation_vec3f_normalized": "normalized()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L67 | neighbors=[vec3f.hpp, length()]
- "framegraph_frame_graph_compile": "compile()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L87 | neighbors=[frame_graph.cpp, build_plan()]
- "framegraph_frame_graph_execute": "execute()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L93 | neighbors=[frame_graph.cpp, build_plan()]
- "framegraph_frame_graph_framegraph": "FrameGraph" | kind=code-symbol | source=engine/render/include/poko/render/framegraph/frame_graph.hpp:L46 | neighbors=[frame_graph.cpp, .FrameGraph()]
- "frostpeak_frost_map_drift": "_drift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L297 | neighbors=[frost_map.py, build()]
- "frostpeak_frost_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L326 | neighbors=[frost_map.py, sub()]
- "frostpeak_frost_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L303 | neighbors=[frost_map.py, free()]
- "frostpeak_frost_map_nearest_path_pt": "nearest_path_pt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L60 | neighbors=[frost_map.py, build()]
- "frostpeak_frost_map_rationale_158": "height range of the terrain over a footprint of radius r: big = a slope that wou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L158 | neighbors=[spread(), MB]
- "frostpeak_frost_map_segd": "segd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_map.py:L44 | neighbors=[frost_map.py, path_info()]
- "frostpeak_frost_props_cabin": "cabin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L46 | neighbors=[frost_props.py, log cabin: stacked logs with crossed co…]
- "frostpeak_frost_props_fishing_hut": "fishing_hut()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L216 | neighbors=[frost_props.py, ice-fishing shanty: board walls on skid…]
- "frostpeak_frost_props_frost_spire": "frost_spire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L259 | neighbors=[frost_props.py, hero: stone terrace + a 60-stud ice cry…]
- "frostpeak_frost_props_roll_well": "roll_well()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L172 | neighbors=[frost_props.py, village-square roll well: stone ring, t…]
- "frostpeak_frost_props_snow_pine": "snow_pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L34 | neighbors=[frost_props.py, grove pine re-shaded: every up-facing t…]
- "gles_clear_pokoactivity_pokoactivity_nativeinit": ".nativeInit()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L16 | neighbors=[PokoActivity, .onCreate()]
- "gles_clear_pokoactivity_pokoactivity_oncreate": ".onCreate()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L20 | neighbors=[PokoActivity, .nativeInit()]
- "gles_clear_pokoactivity_pokoactivity_ondestroy": ".onDestroy()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L46 | neighbors=[PokoActivity, .nativeSurfaceDestroyed()]
- "gles_clear_pokoactivity_pokoactivity_surfacechanged": ".surfaceChanged()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L36 | neighbors=[PokoActivity, .nativeSetSurface()]
- "gles_clear_pokoactivity_pokoactivity_surfacecreated": ".surfaceCreated()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L29 | neighbors=[PokoActivity, .nativeSetSurface()]
- "gles_clear_pokoactivity_pokoactivity_surfacedestroyed": ".surfaceDestroyed()" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L41 | neighbors=[PokoActivity, .nativeSurfaceDestroyed()]
- "godot_ablation_report_luminance": "luminance()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L40 | neighbors=[ablation_report.py, image_change()]
- "godot_ablation_report_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/godot/ablation_report.py:L118 | neighbors=[ablation_report.py, analyse()]
- "hermes_init": "__init__.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "hermes_plugin_init_strip_frontmatter": "_strip_frontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L35 | neighbors=[__init__.py, _build_bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_contains_using_superpowers_body": ".test_contains_using_superpowers_body()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L64 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_frontmatter_stripped": ".test_frontmatter_stripped()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L71 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_marker_and_wrapper": ".test_marker_and_wrapper()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L58 | neighbors=[TestBootstrapContent, _bootstrap()]
- "hermes_test_bootstrap_testbootstrapcontent_test_skill_view_guidance_present": ".test_skill_view_guidance_present()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L88 | neighbors=[TestBootstrapContent, _bootstrap()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-114.json

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
