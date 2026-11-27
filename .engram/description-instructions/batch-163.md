# Node Description Batch 164 of 209

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

- "device_fallback_clear_backends_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_backends.cpp:L29 | neighbors=[fallback_clear_backends.cpp]
- "device_fallback_clear_backends_vulkanclearbackend_vulkanclearbackend": ".VulkanClearBackend()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/fallback_clear_backends.hpp:L12 | neighbors=[VulkanClearBackend]
- "device_fallback_clear_demo_main": "main()" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_demo.cpp:L14 | neighbors=[fallback_clear_demo.cpp]
- "device_opengl_clear_renderer_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L105 | neighbors=[opengl_clear_renderer.cpp]
- "device_opengl_clear_renderer_openglclearrenderer_openglclearrenderer": ".OpenGLClearRenderer()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/opengl_clear_renderer.hpp:L15 | neighbors=[OpenGLClearRenderer()]
- "device_opengl_clear_renderer_sdlplatform": "SdlPlatform" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/opengl_clear_renderer.hpp:L5 | neighbors=[opengl_clear_renderer.cpp]
- "device_opengles_clear_backend_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_backend.cpp:L7 | neighbors=[opengles_clear_backend.cpp]
- "device_opengles_clear_backend_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_backend.cpp:L3 | neighbors=[opengles_clear_backend.cpp]
- "device_opengles_clear_backend_openglesclearbackend_openglesclearbackend": ".OpenGLESClearBackend()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/opengles_clear_backend.hpp:L14 | neighbors=[OpenGLESClearBackend]
- "device_opengles_clear_backend_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_backend.cpp:L10 | neighbors=[opengles_clear_backend.cpp]
- "device_opengles_clear_renderer_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L114 | neighbors=[opengles_clear_renderer.cpp]
- "device_opengles_clear_renderer_clear_and_verify": "clear_and_verify()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L124 | neighbors=[opengles_clear_renderer.cpp]
- "device_opengles_clear_renderer_framebuffer_is_srgb": "framebuffer_is_srgb()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L167 | neighbors=[opengles_clear_renderer.cpp]
- "device_opengles_clear_renderer_openglclearesrenderer_openglclearesrenderer": ".OpenGLClearESRenderer()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/opengles_clear_renderer.hpp:L14 | neighbors=[OpenGLClearESRenderer()]
- "device_opengles_clear_renderer_read_center_pixel": "read_center_pixel()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L140 | neighbors=[opengles_clear_renderer.cpp]
- "device_opengles_native_activity_on_app_cmd": "on_app_cmd()" | kind=code-symbol | source=engine/rhi/src/device/opengles_native_activity.cpp:L180 | neighbors=[opengles_native_activity.cpp]
- "device_poko_jni_java_com_poko_glesclear_pokoactivity_nativesurfacedestroyed": "Java_com_poko_glesclear_PokoActivity_nativeSurfaceDestroyed()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L131 | neighbors=[poko_jni.cpp]
- "device_read_spirv_read_spirv": "read_spirv()" | kind=code-symbol | source=engine/rhi/src/device/read_spirv.hpp:L10 | neighbors=[read_spirv.hpp]
- "device_swapchain_frame_loop_run_swapchain_frame": "run_swapchain_frame()" | kind=code-symbol | source=engine/rhi/src/device/swapchain_frame_loop.hpp:L45 | neighbors=[swapchain_frame_loop.hpp]
- "device_vulkan_clear_android_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L226 | neighbors=[vulkan_clear_android.cpp]
- "device_vulkan_clear_android_destroy_swapchain_resources": "destroy_swapchain_resources()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L147 | neighbors=[vulkan_clear_android.cpp]
- "device_vulkan_clear_android_vulkanclearandroidrenderer_vulkanclearandroidrenderer": ".VulkanClearAndroidRenderer()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_clear_android.hpp:L13 | neighbors=[VulkanClearAndroidRenderer()]
- "device_vulkan_clear_demo_main": "main()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_demo.cpp:L16 | neighbors=[vulkan_clear_demo.cpp]
- "device_vulkan_clear_renderer_sdlplatform": "SdlPlatform" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_clear_renderer.hpp:L7 | neighbors=[vulkan_clear_renderer.cpp]
- "device_vulkan_clear_renderer_vulkanclearrenderer_vulkanclearrenderer": ".VulkanClearRenderer()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_clear_renderer.hpp:L30 | neighbors=[VulkanClearRenderer()]
- "device_vulkan_imgui_pass_draw": "draw()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L341 | neighbors=[vulkan_imgui_pass.cpp]
- "device_vulkan_imgui_pass_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L34 | neighbors=[vulkan_imgui_pass.cpp]
- "device_vulkan_imgui_pass_vulkandiagnostics": "VulkanDiagnostics" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_imgui_pass.hpp:L7 | neighbors=[vulkan_imgui_pass.cpp]
- "device_vulkan_imgui_pass_vulkanimguipass_vulkanimguipass": ".VulkanImGuiPass()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_imgui_pass.hpp:L24 | neighbors=[VulkanImGuiPass()]
- "device_vulkan_mesh_pass_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L39 | neighbors=[vulkan_mesh_pass.cpp]
- "device_vulkan_mesh_pass_set_light_direction": "set_light_direction()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L196 | neighbors=[vulkan_mesh_pass.cpp]
- "device_vulkan_mesh_pass_set_mesh": "set_mesh()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L204 | neighbors=[vulkan_mesh_pass.cpp]
- "device_vulkan_mesh_pass_set_view_proj": "set_view_proj()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L199 | neighbors=[vulkan_mesh_pass.cpp]
- "device_vulkan_mesh_pass_vulkandiagnostics": "VulkanDiagnostics" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_mesh_pass.hpp:L10 | neighbors=[vulkan_mesh_pass.cpp]
- "device_vulkan_mesh_pass_vulkanmeshpass_vulkanmeshpass": ".VulkanMeshPass()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_mesh_pass.hpp:L28 | neighbors=[VulkanMeshPass()]
- "device_vulkan_triangle_pass_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L42 | neighbors=[vulkan_triangle_pass.cpp]
- "device_vulkan_triangle_pass_vulkandiagnostics": "VulkanDiagnostics" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_triangle_pass.hpp:L7 | neighbors=[vulkan_triangle_pass.cpp]
- "device_vulkan_triangle_pass_vulkantrianglepass_vulkantrianglepass": ".VulkanTrianglePass()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_triangle_pass.hpp:L17 | neighbors=[VulkanTrianglePass()]
- "docref_rfc_6455": "RFC-6455" | kind=entity | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L51 | neighbors=[ws-protocol.test.js]
- "dunedesert_dune_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L125 | neighbors=[dune_map.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-163.json

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
