# Node Description Batch 91 of 207

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

- "authority_pkb_schema_pkbauthority": "PkbAuthority" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L224 | neighbors=[pkb_schema.hpp, .PkbAuthority()]
- "authority_session": "session.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/session.hpp:L1 | neighbors=[SessionAuthority, 6568dc9 Update from ML AI Code]
- "authority_session_sessionauthority": "SessionAuthority" | kind=code-symbol | source=server/authority/include/poko/authority/session.hpp:L62 | neighbors=[session.hpp, .SessionAuthority()]
- "bin_trace_processor_run_perfetto_prebuilt": "run_perfetto_prebuilt()" | kind=code-symbol | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L301 | neighbors=[trace_processor, get_perfetto_prebuilt()]
- "blender_character_blockout_report": "report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L253 | neighbors=[character_blockout.py, Print measured bounds so the comparison…]
- "blender_explorer_build_fresh_col": "_fresh_col()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L33 | neighbors=[explorer_build.py, build_explorer()]
- "blender_explorer_build_mats": "_mats()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L43 | neighbors=[explorer_build.py, build_explorer()]
- "blender_explorer_build_rationale_1": "Explorer character — pass 2: garments, equipment, hair.  Builds on the blockout." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L1 | neighbors=[explorer_build.py, Dim]
- "blender_explorer_common_rounded_box": "rounded_box()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L164 | neighbors=[explorer_common.py, assign()]
- "blender_render_compare_views_area": "_area()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L36 | neighbors=[render_compare_views.py, setup_lighting()]
- "blender_render_compare_views_ensure_world": "_ensure_world()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L23 | neighbors=[render_compare_views.py, setup_lighting()]
- "blender_render_compare_views_setup_render": "setup_render()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L132 | neighbors=[render_compare_views.py, render_turnaround()]
- "blender_validate_scene_tri_count": "tri_count()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L60 | neighbors=[validate_scene.py, validate()]
- "brainstorm_server_auth_test_cleanup": "cleanup()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L36 | neighbors=[auth.test.js, runTests()]
- "brainstorm_server_auth_test_runbootstrapscript": "runBootstrapScript()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L88 | neighbors=[auth.test.js, assert]
- "brainstorm_server_auth_test_sleep": "sleep()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L40 | neighbors=[auth.test.js, runTests()]
- "brainstorm_server_auth_test_startserver": "startServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L76 | neighbors=[auth.test.js, runTests()]
- "brainstorm_server_auth_test_waitforserver": "waitForServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L97 | neighbors=[auth.test.js, runTests()]
- "brainstorm_server_auth_test_websocket": "WebSocket" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L17 | neighbors=[auth.test.js, wsConnect()]
- "brainstorm_server_auth_test_wsconnect": "wsConnect()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L59 | neighbors=[auth.test.js, WebSocket]
- "brainstorm_server_branding_test_assertbrandedfallbacktext": "assertBrandedFallbackText()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L157 | neighbors=[branding.test.js, assert]
- "brainstorm_server_branding_test_asserttelemetryimage": "assertTelemetryImage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L164 | neighbors=[branding.test.js, assert]
- "brainstorm_server_branding_test_main": "main()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L242 | neighbors=[branding.test.js, test()]
- "brainstorm_server_branding_test_sleep": "sleep()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L25 | neighbors=[branding.test.js, withServer()]
- "brainstorm_server_branding_test_waitforserver": "waitForServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L42 | neighbors=[branding.test.js, withServer()]
- "brainstorm_server_server_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L16 | neighbors=[server.test.js, serverStartedMessage()]
- "brainstorm_server_server_test_cleanup": "cleanup()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L27 | neighbors=[server.test.js, runTests()]
- "brainstorm_server_server_test_ensuresymlinkworks": "ensureSymlinkWorks()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L116 | neighbors=[server.test.js, skip()]
- "brainstorm_server_server_test_startserver": "startServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L65 | neighbors=[server.test.js, runTests()]
- "brainstorm_server_server_test_waitfor": "waitFor()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L42 | neighbors=[server.test.js, sleep()]
- "brainstorm_server_server_test_waitforserver": "waitForServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L71 | neighbors=[server.test.js, runTests()]
- "brick_abyssal_angler_brick_b": "B()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L347 | neighbors=[abyssal_angler_brick.py, render_all()]
- "brick_abyssal_angler_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L43 | neighbors=[abyssal_angler_brick.py, chain()]
- "brick_abyssal_angler_brick_cell": "cell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L62 | neighbors=[abyssal_angler_brick.py, ix()]
- "brick_abyssal_angler_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L48 | neighbors=[abyssal_angler_brick.py, cap()]
- "brick_abyssal_angler_brick_exposed": "exposed()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L289 | neighbors=[abyssal_angler_brick.py, build()]
- "brick_abyssal_angler_brick_front_z": "front_z()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L53 | neighbors=[abyssal_angler_brick.py, ix()]
- "brick_abyssal_angler_brick_lin": "lin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L288 | neighbors=[abyssal_angler_brick.py, build()]
- "brick_abyssal_angler_brick_lip_cell": "lip_cell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L119 | neighbors=[abyssal_angler_brick.py, ix()]
- "brick_abyssal_angler_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L32 | neighbors=[abyssal_angler_brick.py, tooth()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-090.json

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
