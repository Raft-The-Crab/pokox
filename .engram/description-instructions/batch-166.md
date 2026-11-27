# Node Description Batch 167 of 207

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

- "imgui_enginefactoryvk_ienginefactory": "IEngineFactory()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L124 | neighbors=[EngineFactoryVk.h]
- "imgui_enginefactoryvk_rtvformats": "RTVFormats()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L58 | neighbors=[EngineFactoryVk.h]
- "imgui_refcntautoptr_refcntautoptr_refcntautoptr": ".RefCntAutoPtr()" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/RefCntAutoPtr.hpp:L9 | neighbors=[RefCntAutoPtr]
- "include_build_flags": "build_flags.hpp" | kind=code-symbol | source=engine/foundation/include/build_flags.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "input_action_map_name": "name()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L337 | neighbors=[action_map.cpp]
- "input_device_router_clear": "clear()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L103 | neighbors=[device_router.cpp]
- "input_device_router_disconnect": "disconnect()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L47 | neighbors=[device_router.cpp]
- "input_device_router_find": "find()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L62 | neighbors=[device_router.cpp]
- "input_device_router_name": "name()" | kind=code-symbol | source=mute/src/input/device_router.cpp:L107 | neighbors=[device_router.cpp]
- "input_input_snapshot_button_down": "button_down()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L99 | neighbors=[input_snapshot.cpp]
- "input_input_snapshot_key_down": "key_down()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L95 | neighbors=[input_snapshot.cpp]
- "input_input_snapshot_name": "name()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L342 | neighbors=[input_snapshot.cpp]
- "integration_config_logging_guard_real_test_main": "main()" | kind=code-symbol | source=engine/foundation/tests/integration/config_logging_guard_real_test.cpp:L10 | neighbors=[config_logging_guard_real_test.cpp]
- "integration_cube_golden_rationale_31": "RGB8 PNG with filter 0 and explicit uncompressed DEFLATE blocks." | kind=entity | source=engine/render/tests/integration/cube_golden.py:L31 | neighbors=[canonical_png()]
- "integration_cube_golden_x11_init": ".__init__()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L58 | neighbors=[X11]
- "integration_cube_golden_ximage": "XImage" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L48 | neighbors=[cube_golden.py]
- "integration_dependency_smoke": "dependency_smoke.cpp" | kind=code-symbol | source=engine/foundation/tests/integration/dependency_smoke.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "integration_public_header_compat_main": "main()" | kind=code-symbol | source=engine/rhi/tests/integration/public_header_compat.cpp:L13 | neighbors=[public_header_compat.cpp]
- "integration_sdl_platform_test_main": "main()" | kind=code-symbol | source=engine/platform/tests/integration/sdl_platform_test.cpp:L14 | neighbors=[sdl_platform_test.cpp]
- "integration_test_cube_fixed_view_x11_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_fixed_view_x11.py:L13 | neighbors=[test_cube_fixed_view_x11.py]
- "integration_test_cube_golden_unit_goldenencodertests_test_actual_cannot_replace_reference_or_be_a_symlink": ".test_actual_cannot_replace_reference_or_be_a_symlink()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L62 | neighbors=[GoldenEncoderTests]
- "integration_test_cube_golden_unit_goldenencodertests_test_bad_inputs": ".test_bad_inputs()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L57 | neighbors=[GoldenEncoderTests]
- "integration_test_cube_golden_unit_goldenencodertests_test_capture_cannot_replace_shipped_reference": ".test_capture_cannot_replace_shipped_reference()" | kind=code-symbol | source=engine/render/tests/integration/test_cube_golden_unit.py:L91 | neighbors=[GoldenEncoderTests]
- "integration_test_cube_light_inputs": "test_cube_light_inputs.py" | kind=code-symbol | source=engine/render/tests/integration/test_cube_light_inputs.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "integration_test_directional_light_x11_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_directional_light_x11.py:L17 | neighbors=[test_directional_light_x11.py]
- "integration_test_imgui_inputs_rationale_1": "Check the real ImGui demo rejects bad SPIR-V before initializing a window." | kind=entity | source=engine/render/tests/integration/test_imgui_inputs.py:L1 | neighbors=[test_imgui_inputs.py]
- "integration_test_mute_console_x11_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_mute_console_x11.py:L20 | neighbors=[test_mute_console_x11.py]
- "integration_test_mute_state_console_x11_main": "main()" | kind=code-symbol | source=engine/render/tests/integration/test_mute_state_console_x11.py:L15 | neighbors=[test_mute_state_console_x11.py]
- "integration_test_shader_pipeline_check_spirv": "check_spirv()" | kind=code-symbol | source=engine/render/tests/integration/test_shader_pipeline.py:L24 | neighbors=[test_shader_pipeline.py]
- "integration_test_shader_pipeline_rationale_1": "Exercise the real host compiler and CMake shader rule in an isolated build." | kind=entity | source=engine/render/tests/integration/test_shader_pipeline.py:L1 | neighbors=[test_shader_pipeline.py]
- "integration_test_shader_pipeline_run": "run()" | kind=code-symbol | source=engine/render/tests/integration/test_shader_pipeline.py:L17 | neighbors=[test_shader_pipeline.py]
- "integration_test_shader_pipeline_update_shader": "update_shader()" | kind=code-symbol | source=engine/render/tests/integration/test_shader_pipeline.py:L70 | neighbors=[test_shader_pipeline.py]
- "integration_test_triangle_inputs_rationale_1": "Check the real demo rejects bad SPIR-V before initializing a window." | kind=entity | source=engine/render/tests/integration/test_triangle_inputs.py:L1 | neighbors=[test_triangle_inputs.py]
- "integration_test_triangle_x11_visual_find_window": "find_window()" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_x11_visual.py:L39 | neighbors=[test_triangle_x11_visual.py]
- "integration_test_triangle_x11_visual_green": "green()" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_x11_visual.py:L90 | neighbors=[test_triangle_x11_visual.py]
- "integration_test_triangle_x11_visual_pixel": "pixel()" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_x11_visual.py:L80 | neighbors=[test_triangle_x11_visual.py]
- "integration_test_triangle_x11_visual_red": "red()" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_x11_visual.py:L89 | neighbors=[test_triangle_x11_visual.py]
- "integration_test_uniform_x11_visual_find_window": "find_window()" | kind=code-symbol | source=engine/render/tests/integration/test_uniform_x11_visual.py:L40 | neighbors=[test_uniform_x11_visual.py]
- "integration_test_uniform_x11_visual_pixel": "pixel()" | kind=code-symbol | source=engine/render/tests/integration/test_uniform_x11_visual.py:L80 | neighbors=[test_uniform_x11_visual.py]
- "integration_test_word_reservations_rationale_1": "SQLite-level tests for the D1 word-reservation migration." | kind=entity | source=backend/storage/d1/tests/integration/test_word_reservations.py:L1 | neighbors=[test_word_reservations.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-166.json

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
