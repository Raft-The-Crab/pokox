# Node Description Batch 107 of 208

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

- "creaturelab_lab_props_rationale_86": "copy a built Prop's geometry into P (moved / scaled / turned), keeping UVs + glo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L86 | neighbors=[merge_prop(), Palette] | lang=pt
- "creaturelab_lab_props_rationale_861": "lathe without the flat end caps (rings stay open: roofs, eaves, collars over ope" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L861 | neighbors=[lathe_open(), Palette] | lang=en
- "creaturelab_lab_props_rationale_868": "rotunda roof (no collision, hide it for cutaways): mint shallow dome with white" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L868 | neighbors=[rotunda_roof(), Palette] | lang=en
- "creaturelab_lab_props_rationale_900": "plan polygon (x, z) of the lab wing interior: from (-hw, z0) to (-hw, zc), half" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L900 | neighbors=[wing_outline(), Palette] | lang=en
- "creaturelab_lab_props_rationale_910": "HERO shell: research wing walls: straight sides + half-round north end, tall win" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L910 | neighbors=[lab_wing(), Palette] | lang=en
- "creaturelab_lab_props_rationale_948": "lab wing roof (no collision; hide it for cutaways): flat white slab built in 1-s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L948 | neighbors=[wing_roof(), Palette] | lang=en
- "creaturelab_lab_props_rationale_96": "2D poly [(x, up)] standing upright facing -Z, extruded d toward the front (-Z) f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L96 | neighbors=[upright(), Palette] | lang=en
- "creaturelab_lab_props_rationale_991": "automatic sliding doors for the south entrance (14 wide x 13): steel header with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L991 | neighbors=[sliding_doors(), Palette] | lang=en
- "creaturelab_lab_props_reeds": "reeds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1546 | neighbors=[lab_props.py, .add()] | lang=en
- "creaturelab_lab_props_roof_in_y": "roof_in_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1277 | neighbors=[lab_props.py, underside of the rotunda roof at radius…] | lang=en
- "creaturelab_lab_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L46 | neighbors=[lab_props.py, heal_corner()] | lang=en
- "creaturelab_lab_props_stepping_stone": "stepping_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1556 | neighbors=[lab_props.py, .add()] | lang=en
- "creaturelab_lab_props_to_v": "to_v()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1628 | neighbors=[lab_props.py, supply_boxes()] | lang=en
- "creaturelab_lab_props_wing_outline": "wing_outline()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L899 | neighbors=[lab_props.py, plan polygon (x, z) of the lab wing int…] | lang=en
- "creaturelab_turntable": "turntable.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/turntable.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "debug_vulkan_diagnostics_filter": "vulkan_diagnostics_filter.cpp" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics_filter.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, is_environment_layer_version_warning()] | lang=en
- "debug_vulkan_diagnostics_messages": "messages()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L126 | neighbors=[vulkan_diagnostics.cpp, since()] | lang=en
- "debug_vulkan_diagnostics_start": "start()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L78 | neighbors=[vulkan_diagnostics.cpp, start_with_factory()] | lang=en
- "debug_vulkan_diagnostics_stop": "stop()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L127 | neighbors=[vulkan_diagnostics.cpp, since()] | lang=en
- "debug_vulkan_diagnostics_vulkandiagnostics": "VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L76 | neighbors=[vulkan_diagnostics.cpp, .VulkanDiagnostics()] | lang=en
- "device_clear_backend_selection_clearbackend": "ClearBackend" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/clear_backend_selection.hpp:L10 | neighbors=[clear_backend_selection.cpp, .ClearBackend()] | lang=en
- "device_clear_backend_selection_start": "start()" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L7 | neighbors=[clear_backend_selection.cpp, shutdown()] | lang=en
- "device_opengl_clear_renderer_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L170 | neighbors=[opengl_clear_renderer.cpp, native_window()] | lang=en
- "device_opengl_clear_renderer_default_framebuffer_is_srgb": "default_framebuffer_is_srgb()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L21 | neighbors=[opengl_clear_renderer.cpp, initialize()] | lang=en
- "device_opengl_clear_renderer_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/opengl_clear_renderer.cpp:L200 | neighbors=[opengl_clear_renderer.cpp, OpenGLClearRenderer()] | lang=en
- "device_opengles_clear_demo_failingprimarybackend": "FailingPrimaryBackend" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L25 | neighbors=[opengles_clear_demo.cpp, rhi::ClearBackend] | lang=en
- "device_opengles_clear_demo_linear_to_srgb_byte": "linear_to_srgb_byte()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L18 | neighbors=[opengles_clear_demo.cpp, report_pixel()] | lang=en
- "device_opengles_clear_demo_main": "main()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L55 | neighbors=[opengles_clear_demo.cpp, report_pixel()] | lang=en
- "device_opengles_clear_renderer_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L36 | neighbors=[opengles_clear_renderer.cpp, initialize_impl()] | lang=en
- "device_opengles_clear_renderer_initialize_window": "initialize_window()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L39 | neighbors=[opengles_clear_renderer.cpp, initialize_impl()] | lang=en
- "device_opengles_clear_renderer_shutdown_checked": "shutdown_checked()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L162 | neighbors=[opengles_clear_renderer.cpp, shutdown()] | lang=en
- "device_poko_jni_java_com_poko_glesclear_pokoactivity_nativeinit": "Java_com_poko_glesclear_PokoActivity_nativeInit()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L108 | neighbors=[poko_jni.cpp, write_line()] | lang=en
- "device_render_error": "render_error.hpp" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/render_error.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "device_vulkan_clear_android_make_device_objects": "make_device_objects()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L97 | neighbors=[vulkan_clear_android.cpp, initialize()] | lang=en
- "device_vulkan_clear_android_make_instance": "make_instance()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L42 | neighbors=[vulkan_clear_android.cpp, initialize()] | lang=en
- "device_vulkan_clear_android_make_surface": "make_surface()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L53 | neighbors=[vulkan_clear_android.cpp, initialize()] | lang=en
- "device_vulkan_clear_android_make_swapchain": "make_swapchain()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L156 | neighbors=[vulkan_clear_android.cpp, initialize()] | lang=en
- "device_vulkan_clear_android_pick_device": "pick_device()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L58 | neighbors=[vulkan_clear_android.cpp, initialize()] | lang=en
- "device_vulkan_clear_android_pick_surface_format": "pick_surface_format()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L79 | neighbors=[vulkan_clear_android.cpp, initialize()] | lang=en
- "device_vulkan_clear_android_shutdown_checked": "shutdown_checked()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L352 | neighbors=[vulkan_clear_android.cpp, shutdown()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-106.json

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
