# Node Description Batch 105 of 207

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

- "debug_vulkan_diagnostics_start": "start()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L78 | neighbors=[vulkan_diagnostics.cpp, start_with_factory()]
- "debug_vulkan_diagnostics_stop": "stop()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L127 | neighbors=[vulkan_diagnostics.cpp, since()]
- "debug_vulkan_diagnostics_vulkandiagnostics": "VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L76 | neighbors=[vulkan_diagnostics.cpp, .VulkanDiagnostics()]
- "device_clear_backend_selection_clearbackend": "ClearBackend" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/clear_backend_selection.hpp:L10 | neighbors=[clear_backend_selection.cpp, .ClearBackend()]
- "device_clear_backend_selection_start": "start()" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L7 | neighbors=[clear_backend_selection.cpp, shutdown()]
- "device_fallback_clear_demo": "fallback_clear_demo.cpp" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_demo.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "device_opengl_clear_renderer_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L170 | neighbors=[opengl_clear_renderer.cpp, native_window()]
- "device_opengl_clear_renderer_default_framebuffer_is_srgb": "default_framebuffer_is_srgb()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L21 | neighbors=[opengl_clear_renderer.cpp, initialize()]
- "device_opengl_clear_renderer_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L200 | neighbors=[opengl_clear_renderer.cpp, OpenGLClearRenderer()]
- "device_opengles_clear_demo_failingprimarybackend": "FailingPrimaryBackend" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L25 | neighbors=[opengles_clear_demo.cpp, rhi::ClearBackend]
- "device_opengles_clear_demo_linear_to_srgb_byte": "linear_to_srgb_byte()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L18 | neighbors=[opengles_clear_demo.cpp, report_pixel()]
- "device_opengles_clear_demo_main": "main()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L55 | neighbors=[opengles_clear_demo.cpp, report_pixel()]
- "device_opengles_clear_renderer_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L36 | neighbors=[opengles_clear_renderer.cpp, initialize_impl()]
- "device_opengles_clear_renderer_initialize_window": "initialize_window()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L39 | neighbors=[opengles_clear_renderer.cpp, initialize_impl()]
- "device_opengles_clear_renderer_shutdown_checked": "shutdown_checked()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L162 | neighbors=[opengles_clear_renderer.cpp, shutdown()]
- "device_poko_jni_java_com_poko_glesclear_pokoactivity_nativeinit": "Java_com_poko_glesclear_PokoActivity_nativeInit()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L108 | neighbors=[poko_jni.cpp, write_line()]
- "device_read_spirv": "read_spirv.hpp" | kind=code-symbol | source=engine/rhi/src/device/read_spirv.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, read_spirv()]
- "device_vulkan_clear_android_make_device_objects": "make_device_objects()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L97 | neighbors=[vulkan_clear_android.cpp, initialize()]
- "device_vulkan_clear_android_make_instance": "make_instance()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L42 | neighbors=[vulkan_clear_android.cpp, initialize()]
- "device_vulkan_clear_android_make_surface": "make_surface()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L53 | neighbors=[vulkan_clear_android.cpp, initialize()]
- "device_vulkan_clear_android_make_swapchain": "make_swapchain()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L156 | neighbors=[vulkan_clear_android.cpp, initialize()]
- "device_vulkan_clear_android_pick_device": "pick_device()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L58 | neighbors=[vulkan_clear_android.cpp, initialize()]
- "device_vulkan_clear_android_pick_surface_format": "pick_surface_format()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L79 | neighbors=[vulkan_clear_android.cpp, initialize()]
- "device_vulkan_clear_android_shutdown_checked": "shutdown_checked()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L352 | neighbors=[vulkan_clear_android.cpp, shutdown()]
- "device_vulkan_clear_demo": "vulkan_clear_demo.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_demo.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]
- "device_vulkan_clear_renderer_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L123 | neighbors=[vulkan_clear_renderer.cpp, draw_and_present()]
- "device_vulkan_clear_renderer_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L50 | neighbors=[vulkan_clear_renderer.cpp, shutdown()]
- "device_vulkan_clear_renderer_shutdown_checked": "shutdown_checked()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L186 | neighbors=[vulkan_clear_renderer.cpp, shutdown()]
- "device_vulkan_clear_renderer_vulkanclearrenderer": "VulkanClearRenderer()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L65 | neighbors=[vulkan_clear_renderer.cpp, .VulkanClearRenderer()]
- "device_vulkan_imgui_pass_vulkanimguipass": "VulkanImGuiPass()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L338 | neighbors=[vulkan_imgui_pass.cpp, .VulkanImGuiPass()]
- "device_vulkan_mesh_pass_draw": "draw()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L238 | neighbors=[vulkan_mesh_pass.cpp, draw_and_present()]
- "device_vulkan_mesh_pass_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L230 | neighbors=[vulkan_mesh_pass.cpp, draw()]
- "device_vulkan_mesh_pass_vulkanmeshpass": "VulkanMeshPass()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L192 | neighbors=[vulkan_mesh_pass.cpp, .VulkanMeshPass()]
- "device_vulkan_triangle_pass_draw": "draw()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L212 | neighbors=[vulkan_triangle_pass.cpp, draw_and_present()]
- "device_vulkan_triangle_pass_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L200 | neighbors=[vulkan_triangle_pass.cpp, draw()]
- "device_vulkan_triangle_pass_set_texture": "set_texture()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L216 | neighbors=[vulkan_triangle_pass.cpp, set_texture_mips()]
- "device_vulkan_triangle_pass_set_texture_mips": "set_texture_mips()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L221 | neighbors=[vulkan_triangle_pass.cpp, set_texture()]
- "device_vulkan_triangle_pass_vulkantrianglepass": "VulkanTrianglePass()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L197 | neighbors=[vulkan_triangle_pass.cpp, .VulkanTrianglePass()]
- "dunedesert_dune_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L222 | neighbors=[dune_map.py, _inside_one()]
- "dunedesert_dune_map_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L192 | neighbors=[dune_map.py, clip_fail()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-104.json

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
