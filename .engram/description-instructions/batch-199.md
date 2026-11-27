# Node Description Batch 200 of 209

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
Write every description in Portuguese (pt). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "unit_imgui_pass_faults_fakeshader": "FakeShader()" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L38 | neighbors=[imgui_pass_faults.cpp]
- "unit_imgui_pass_faults_getenginefactoryvk": "GetEngineFactoryVk()" | kind=code-symbol | source=engine/rhi/tests/unit/imgui_pass_faults.cpp:L26 | neighbors=[imgui_pass_faults.cpp]
- "unit_lexer_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/lexer_dump.cpp:L12 | neighbors=[lexer_dump.cpp]
- "unit_opengl_clear_faults_bind": "bind()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L24 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_get_attachment": "get_attachment()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L25 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_get_error": "get_error()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L26 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_get_int": "get_int()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L23 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_getenginefactoryopengl": "GetEngineFactoryOpenGL()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L70 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L75 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_createcontext": "SDL_GL_CreateContext()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L29 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_destroycontext": "SDL_GL_DestroyContext()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L34 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_getprocaddress": "SDL_GL_GetProcAddress()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L41 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_loadlibrary": "SDL_GL_LoadLibrary()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L35 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_makecurrent": "SDL_GL_MakeCurrent()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L33 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_setattribute": "SDL_GL_SetAttribute()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L28 | neighbors=[opengl_clear_faults.cpp]
- "unit_opengl_clear_faults_sdl_gl_unloadlibrary": "SDL_GL_UnloadLibrary()" | kind=code-symbol | source=engine/rhi/tests/unit/opengl_clear_faults.cpp:L40 | neighbors=[opengl_clear_faults.cpp]
- "unit_parser_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/parser_dump.cpp:L12 | neighbors=[parser_dump.cpp]
- "unit_program_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/program_test.cpp:L13 | neighbors=[program_test.cpp]
- "unit_run_seed_checks_rationale_1": "Portable GCC/Clang-compatible seed checks. These do NOT use real SDL/Diligent/GP" | kind=entity | source=engine/rhi/tests/unit/run_seed_checks.py:L1 | neighbors=[run_seed_checks.py]
- "unit_run_seed_checks_run": "run()" | kind=code-symbol | source=engine/rhi/tests/unit/run_seed_checks.py:L34 | neighbors=[run_seed_checks.py]
- "unit_sdl_platform_faults_sdl_createwindow": "SDL_CreateWindow()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L35 | neighbors=[sdl_platform_faults.cpp]
- "unit_sdl_platform_faults_sdl_destroywindow": "SDL_DestroyWindow()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L43 | neighbors=[sdl_platform_faults.cpp]
- "unit_sdl_platform_faults_sdl_getwindowid": "SDL_GetWindowID()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L53 | neighbors=[sdl_platform_faults.cpp]
- "unit_sdl_platform_faults_sdl_getwindowsize": "SDL_GetWindowSize()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L54 | neighbors=[sdl_platform_faults.cpp]
- "unit_sdl_platform_faults_sdl_getwindowsizeinpixels": "SDL_GetWindowSizeInPixels()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L58 | neighbors=[sdl_platform_faults.cpp]
- "unit_sdl_platform_faults_sdl_pollevent": "SDL_PollEvent()" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L48 | neighbors=[sdl_platform_faults.cpp]
- "unit_semantic_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/semantic_dump.cpp:L12 | neighbors=[semantic_dump.cpp]
- "unit_session_test_main": "main()" | kind=code-symbol | source=server/authority/tests/unit/session_test.cpp:L13 | neighbors=[session_test.cpp]
- "unit_sign_in_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/sign_in_test.cpp:L10 | neighbors=[sign_in_test.cpp]
- "unit_soft_body_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/soft_body_test.cpp:L17 | neighbors=[soft_body_test.cpp]
- "unit_state_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/state_test.cpp:L11 | neighbors=[state_test.cpp]
- "unit_statement_dump_main": "main()" | kind=code-symbol | source=mute/tests/unit/statement_dump.cpp:L12 | neighbors=[statement_dump.cpp]
- "unit_stdlib_crypto_test_bytes": "bytes()" | kind=code-symbol | source=mute/tests/unit/stdlib_crypto_test.cpp:L17 | neighbors=[stdlib_crypto_test.cpp]
- "unit_stdlib_physics_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/stdlib_physics_test.cpp:L177 | neighbors=[stdlib_physics_test.cpp]
- "unit_step_up_test_main": "main()" | kind=code-symbol | source=server/identity/tests/unit/step_up_test.cpp:L11 | neighbors=[step_up_test.cpp]
- "unit_swapchain_frame_loop_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/swapchain_frame_loop_test.cpp:L71 | neighbors=[swapchain_frame_loop_test.cpp]
- "unit_test_evaluator_reference_make": "make()" | kind=code-symbol | source=mute/tests/unit/test_evaluator_reference.py:L9 | neighbors=[test_evaluator_reference.py]
- "unit_test_math_accuracy_ordered": "ordered()" | kind=code-symbol | source=mute/tests/unit/test_math_accuracy.py:L6 | neighbors=[test_math_accuracy.py]
- "unit_test_math_determinism_tracetests_setup": ".setUp()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L13 | neighbors=[TraceTests]
- "unit_test_math_determinism_tracetests_test_duplicate_json_keys_rejected": ".test_duplicate_json_keys_rejected()" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L48 | neighbors=[TraceTests]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-199.json

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
