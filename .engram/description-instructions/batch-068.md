# Node Description Batch 69 of 209

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

- "creaturelab_lab_props_bollard_light": "bollard_light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1210 | neighbors=[lab_props.py, .add(), low path bollard: rounded white post, g…]
- "creaturelab_lab_props_capsule_prop": "capsule_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L138 | neighbors=[lab_props.py, capsule(), .add()]
- "creaturelab_lab_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1244 | neighbors=[lab_props.py, .add(), flat-bottomed cumulus for the sky (Smoo…]
- "creaturelab_lab_props_dense": "_dense()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1794 | neighbors=[lab_props.py, lerp(), sphere_decal()]
- "creaturelab_lab_props_egg": "egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L517 | neighbors=[lab_props.py, .add(), specimen_tank()]
- "creaturelab_lab_props_lathe_open": "lathe_open()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L860 | neighbors=[lab_props.py, lathe without the flat end caps (rings …, rotunda_roof()]
- "creaturelab_lab_props_leaf_card": "leaf_card()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1965 | neighbors=[lab_props.py, fiddle_fig(), one leaf: rounded card (base, two shoul…]
- "creaturelab_lab_props_leaf_sh": "leaf_sh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1980 | neighbors=[lab_props.py, fiddle_fig(), leaf_mass()]
- "creaturelab_lab_props_pendant_lamp": "pendant_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L753 | neighbors=[lab_props.py, .add(), pendant lamp hung from the ceiling (ori…]
- "creaturelab_lab_props_potted_fern": "potted_fern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1140 | neighbors=[lab_props.py, .add(), low wide pot with arching fern fronds (…]
- "creaturelab_lab_props_round_rug": "round_rug()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1709 | neighbors=[lab_props.py, round rug: three concentric bands, a sc…, .add()]
- "creaturelab_lab_props_wall_clock": "wall_clock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1720 | neighbors=[lab_props.py, wall clock with a BLANK face (no numera…, .add()]
- "debug_vulkan_diagnostics_start_with_factory": "start_with_factory()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L83 | neighbors=[vulkan_diagnostics.cpp, start(), totals()]
- "debug_vulkan_diagnostics_totals": "totals()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L18 | neighbors=[vulkan_diagnostics.cpp, since(), start_with_factory()]
- "device_clear_backend_selection_clearbackendselection": "ClearBackendSelection()" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L4 | neighbors=[clear_backend_selection.cpp, .ClearBackendSelection(), shutdown()]
- "device_clear_backend_selection_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L43 | neighbors=[clear_backend_selection.cpp, ClearBackendSelection(), start()]
- "device_fallback_clear_backends_openglclearbackend": "OpenGLClearBackend" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/fallback_clear_backends.hpp:L28 | neighbors=[fallback_clear_backends.cpp, ClearBackend, .OpenGLClearBackend()]
- "device_fallback_clear_backends_vulkanclearbackend": "VulkanClearBackend" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/fallback_clear_backends.hpp:L10 | neighbors=[fallback_clear_backends.cpp, ClearBackend, .VulkanClearBackend()]
- "device_opengl_clear_renderer_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L109 | neighbors=[opengl_clear_renderer.cpp, default_framebuffer_is_srgb(), native_window()]
- "device_opengl_clear_renderer_native_window": "native_window()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L52 | neighbors=[opengl_clear_renderer.cpp, clear_and_present(), initialize()]
- "device_opengl_clear_renderer_openglclearrenderer": "OpenGLClearRenderer()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L107 | neighbors=[opengl_clear_renderer.cpp, .OpenGLClearRenderer(), shutdown()]
- "device_opengles_clear_backend_openglesclearbackend": "OpenGLESClearBackend" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/opengles_clear_backend.hpp:L12 | neighbors=[opengles_clear_backend.cpp, ClearBackend, .OpenGLESClearBackend()]
- "device_opengles_clear_demo_report_pixel": "report_pixel()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L35 | neighbors=[opengles_clear_demo.cpp, main(), linear_to_srgb_byte()]
- "device_opengles_clear_renderer_openglclearesrenderer": "OpenGLClearESRenderer()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L34 | neighbors=[opengles_clear_renderer.cpp, .OpenGLClearESRenderer(), shutdown()]
- "device_opengles_native_activity_android_main": "android_main()" | kind=code-symbol | source=engine/rhi/src/device/opengles_native_activity.cpp:L206 | neighbors=[opengles_native_activity.cpp, run_frames(), write_result()]
- "device_opengles_native_activity_run_frames": "run_frames()" | kind=code-symbol | source=engine/rhi/src/device/opengles_native_activity.cpp:L50 | neighbors=[opengles_native_activity.cpp, android_main(), write_result()]
- "device_opengles_native_activity_write_result": "write_result()" | kind=code-symbol | source=engine/rhi/src/device/opengles_native_activity.cpp:L44 | neighbors=[opengles_native_activity.cpp, android_main(), run_frames()]
- "device_poko_jni_java_com_poko_glesclear_pokoactivity_nativesetsurface": "Java_com_poko_glesclear_PokoActivity_nativeSetSurface()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L117 | neighbors=[poko_jni.cpp, run_probe(), write_line()]
- "device_poko_jni_run_probe": "run_probe()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L40 | neighbors=[poko_jni.cpp, Java_com_poko_glesclear_PokoActivity_na…, write_line()]
- "device_render_error": "render_error.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/render_error.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "device_swapchain_frame_loop": "swapchain_frame_loop.hpp" | kind=code-symbol | source=engine/rhi/src/device/swapchain_frame_loop.hpp:L1 | neighbors=[2960ac1 Android Vulkan clear: no fence …, 9eeb3ff Merge pull request #2 from Raft…, run_swapchain_frame()]
- "device_vulkan_clear_android_vulkanclearandroidrenderer": "VulkanClearAndroidRenderer()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L211 | neighbors=[vulkan_clear_android.cpp, shutdown(), .VulkanClearAndroidRenderer()]
- "device_vulkan_clear_renderer_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L134 | neighbors=[vulkan_clear_renderer.cpp, clear_and_present(), native_window()]
- "device_vulkan_clear_renderer_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L67 | neighbors=[vulkan_clear_renderer.cpp, native_window(), shutdown()]
- "device_vulkan_clear_renderer_native_window": "native_window()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L12 | neighbors=[vulkan_clear_renderer.cpp, draw_and_present(), initialize()]
- "dunedesert_dune_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L176 | neighbors=[dune_map.py, dig_spots(), set_pieces()]
- "dunedesert_dune_map_build_solid": "build_solid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L184 | neighbors=[dune_map.py, free(), place_soft()]
- "dunedesert_dune_map_clip_fail": "clip_fail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L198 | neighbors=[dune_map.py, inside(), place_soft()]
- "dunedesert_dune_map_dunes": "dunes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L58 | neighbors=[dune_map.py, H(), transverse dunes (crests ~N-S, wind fro…]
- "dunedesert_dune_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L175 | neighbors=[dune_map.py, set_pieces(), waystones()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-068.json

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
