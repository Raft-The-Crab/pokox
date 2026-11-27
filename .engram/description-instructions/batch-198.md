# Node Description Batch 199 of 207

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

- "unit_test_verify_desktop_evidencetests_test_process_failure": ".test_process_failure()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L35 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_evidencetests_test_process_success": ".test_process_success()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L30 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_evidencetests_test_process_timeout": ".test_process_timeout()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L38 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_evidencetests_test_refuse_nonfinite_timeouts": ".test_refuse_nonfinite_timeouts()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L79 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_evidencetests_test_refuse_old_output": ".test_refuse_old_output()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L74 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_evidencetests_test_summary": ".test_summary()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L19 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_evidencetests_test_warning_retained": ".test_warning_retained()" | kind=code-symbol | source=engine/rhi/tests/unit/test_verify_desktop.py:L21 | neighbors=[EvidenceTests]
- "unit_test_verify_desktop_rationale_1": "Evidence handling tests, not real SDK or GPU acceptance." | kind=entity | source=engine/rhi/tests/unit/test_verify_desktop.py:L1 | neighbors=[test_verify_desktop.py]
- "unit_udp_echo_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/udp_echo_test.cpp:L15 | neighbors=[udp_echo_test.cpp]
- "unit_velocity_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/velocity_test.cpp:L11 | neighbors=[velocity_test.cpp]
- "unit_vulkan_clear_faults_chain": "Chain()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L123 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_context": "Context()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L102 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_device": "Device()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L96 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_emit": "emit()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L37 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_foreign": "foreign()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L34 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_getenginefactoryvk": "GetEngineFactoryVk()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L167 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L176 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_previous": "previous()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L31 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_createwindow": "SDL_CreateWindow()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L60 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_delay": "SDL_Delay()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L92 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_destroywindow": "SDL_DestroyWindow()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L64 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getcurrentvideodriver": "SDL_GetCurrentVideoDriver()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L76 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_geterror": "SDL_GetError()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L91 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getnumberproperty": "SDL_GetNumberProperty()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L88 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getpointerproperty": "SDL_GetPointerProperty()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L78 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getwindowflags": "SDL_GetWindowFlags()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L75 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getwindowid": "SDL_GetWindowID()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L66 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getwindowproperties": "SDL_GetWindowProperties()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L77 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getwindowsize": "SDL_GetWindowSize()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L67 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_getwindowsizeinpixels": "SDL_GetWindowSizeInPixels()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L71 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_initsubsystem": "SDL_InitSubSystem()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L58 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_pollevent": "SDL_PollEvent()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L65 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_clear_faults_sdl_quitsubsystem": "SDL_QuitSubSystem()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L59 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_diagnostics_filter_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_diagnostics_filter_test.cpp:L5 | neighbors=[vulkan_diagnostics_filter_test.cpp]
- "unit_vulkan_mesh_pass_test_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L18 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L23 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_messages": "messages()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L14 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_vulkanclearrenderer": "VulkanClearRenderer()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L16 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_vulkandiagnostics": "VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L12 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_triangle_pass_test_messages": "messages()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L14 | neighbors=[vulkan_triangle_pass_test.cpp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-198.json

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
