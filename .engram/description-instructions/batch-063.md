# Node Description Batch 64 of 209

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

- "whispering_grove_forest_props_to_kit": "to_kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L641 | neighbors=[forest_props.py, kit meshes: <Prop> (solid) + <Prop>_Glo…, materials(), mesh_from()]
- "window_i_platform": "i_platform.hpp" | kind=code-symbol | source=engine/platform/include/poko/platform/window/i_platform.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, IPlatform, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "window_sdl_platform_sdlplatform": "~SdlPlatform()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L10 | neighbors=[sdl_platform.cpp, IPlatform, .SdlPlatform(), shutdown()]
- "window_sdl_window_demo": "sdl_window_demo.cpp" | kind=code-symbol | source=engine/platform/src/window/sdl_window_demo.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_trace_face": "trace_face.py" | kind=code-symbol | source=assets/characters/work/trace_face.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, dump_tree(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_validate_production": "validate_production.py" | kind=code-symbol | source=assets/characters/work/validate_production.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Validate the opened R6 .blend. Run with…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachment_motion": "verify_attachment_motion.py" | kind=code-symbol | source=assets/characters/work/verify_attachment_motion.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Headless attachment smoke test. Does no…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachments": "verify_attachments.py" | kind=code-symbol | source=assets/characters/work/verify_attachments.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, nearest_surface(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachments2": "verify_attachments2.py" | kind=code-symbol | source=assets/characters/work/verify_attachments2.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, bbox_dist(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_final_attachments": "verify_final_attachments.py" | kind=code-symbol | source=assets/characters/work/verify_final_attachments.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Definitive attachment connectivity: rot…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "writing_skills_render_graphs_main": "main()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L84 | neighbors=[render-graphs.js, combineGraphs(), extractDotBlocks(), renderToSvg()]
- "animation_check_subframes": "check_subframes.py" | kind=code-symbol | source=assets/characters/animation/check_subframes.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "animation_v2_build_refined_ease": "ease()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L9 | neighbors=[build_refined.py, foot(), interp()]
- "animation_v2_build_refined_foot": "foot()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L16 | neighbors=[build_refined.py, ease(), Continuous velocity at footfall and toe…]
- "animation_validate_animations": "validate_animations.py" | kind=code-symbol | source=assets/characters/animation/validate_animations.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "authority_replay_ring_cbor_text": "cbor_text()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L101 | neighbors=[replay_ring.hpp, cbor_head(), encode_replay()]
- "authority_replay_ring_cbor_uint": "cbor_uint()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L100 | neighbors=[replay_ring.hpp, cbor_head(), encode_replay()]
- "authority_rule_evaluator": "rule_evaluator.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/rule_evaluator.hpp:L1 | neighbors=[RuleEvaluator, RuleParser, 6e2fe3a Created BAK-7 and other BAK tas…]
- "bin_trace_processor_download_or_get_cached": "download_or_get_cached()" | kind=code-symbol | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L213 | neighbors=[trace_processor, get_perfetto_prebuilt(), Downloads a prebuilt or returns a cache…]
- "blender_explorer_build_build_explorer": "build_explorer()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L61 | neighbors=[explorer_build.py, _fresh_col(), _mats()]
- "blender_explorer_common_cylinder": "cylinder()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L188 | neighbors=[explorer_common.py, assign(), Cylinder built at the origin, then plac…]
- "blender_explorer_common_loft": "loft()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L125 | neighbors=[explorer_common.py, assign(), Build a tube from a list of (center Vec…]
- "blender_explorer_common_shell_from": "shell_from()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L102 | neighbors=[explorer_common.py, Duplicate meshes then scale about a piv…, assign()]
- "blender_render_compare_views_scene_bounds": "_scene_bounds()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L54 | neighbors=[render_compare_views.py, World bounds from evaluated vertices: b…, setup_camera()]
- "blender_render_compare_views_setup_camera": "setup_camera()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L81 | neighbors=[render_compare_views.py, render_turnaround(), _scene_bounds()]
- "brainstorm_server_auth_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L20 | neighbors=[auth.test.js, runBootstrapScript(), serverStartedMessage()]
- "brainstorm_server_auth_test_assertstartedonexpectedport": "assertStartedOnExpectedPort()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L116 | neighbors=[auth.test.js, serverStartedMessage(), runTests()]
- "brainstorm_server_auth_test_serverstartedmessage": "serverStartedMessage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L110 | neighbors=[auth.test.js, assertStartedOnExpectedPort(), assert]
- "brainstorm_server_branding_test_assertbrandedwithlogo": "assertBrandedWithLogo()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L122 | neighbors=[branding.test.js, assert, test()]
- "brainstorm_server_branding_test_assertframedlogosupportsdarktheme": "assertFramedLogoSupportsDarkTheme()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L208 | neighbors=[branding.test.js, assert, test()]
- "brainstorm_server_branding_test_assertframedscreenusesbrandheader": "assertFramedScreenUsesBrandHeader()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L215 | neighbors=[branding.test.js, assert, test()]
- "brainstorm_server_branding_test_assertheaderavoidsnarrowoverlap": "assertHeaderAvoidsNarrowOverlap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L227 | neighbors=[branding.test.js, assert, test()]
- "brainstorm_server_branding_test_assertlogokeepstransparentbackground": "assertLogoKeepsTransparentBackground()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L173 | neighbors=[branding.test.js, assert, test()]
- "brainstorm_server_branding_test_cleanup": "cleanup()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L19 | neighbors=[branding.test.js, startServer(), withServer()]
- "brainstorm_server_branding_test_startserver": "startServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L29 | neighbors=[branding.test.js, cleanup(), withServer()]
- "brainstorm_server_server_test_assertstartedonexpectedport": "assertStartedOnExpectedPort()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L106 | neighbors=[server.test.js, serverStartedMessage(), runTests()]
- "brainstorm_server_server_test_serverstartedmessage": "serverStartedMessage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L100 | neighbors=[server.test.js, assertStartedOnExpectedPort(), assert]
- "brainstorm_server_server_test_skip": "skip()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L96 | neighbors=[server.test.js, ensureSymlinkWorks(), SkipTest]
- "brainstorm_server_server_test_skiptest": "SkipTest" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L89 | neighbors=[server.test.js, skip(), .constructor()]
- "brainstorm_server_server_test_sleep": "sleep()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L33 | neighbors=[server.test.js, runTests(), waitFor()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-063.json

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
