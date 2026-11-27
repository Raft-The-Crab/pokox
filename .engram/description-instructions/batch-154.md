# Node Description Batch 155 of 209

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

- "brainstorm_server_auth_test_server_path": "SERVER_PATH" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L22 | neighbors=[auth.test.js]
- "brainstorm_server_auth_test_spawn": "{ spawn }" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L15 | neighbors=[auth.test.js]
- "brainstorm_server_branding_test_createpackagedserverfixture": "createPackagedServerFixture()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L77 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_fetchhtml": "fetchHtml()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L60 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_fs": "fs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L7 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_http": "http" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L6 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_path": "path" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L8 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_repo_root": "REPO_ROOT" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L11 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_server_path": "SERVER_PATH" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L12 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_spawn": "{ spawn }" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L5 | neighbors=[branding.test.js]
- "brainstorm_server_branding_test_writefragment": "writeFragment()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L71 | neighbors=[branding.test.js]
- "brainstorm_server_browser_launcher_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/browser-launcher.test.js:L1 | neighbors=[browser-launcher.test.js]
- "brainstorm_server_browser_launcher_test_browserlauncherforplatform": "{\n  browserLauncherForPlatform\n}" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/browser-launcher.test.js:L2 | neighbors=[browser-launcher.test.js]
- "brainstorm_server_browser_launcher_test_test": "test()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/browser-launcher.test.js:L9 | neighbors=[browser-launcher.test.js]
- "brainstorm_server_helper_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L9 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_fs": "fs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L10 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_helper": "HELPER" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L13 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_makeenv": "makeEnv()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L87 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_moduleshim": "moduleShim" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L20 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_path": "path" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L11 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_src": "src" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L15 | neighbors=[helper.test.js]
- "brainstorm_server_helper_test_test": "test()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L25 | neighbors=[helper.test.js]
- "brainstorm_server_server_test_content_dir": "CONTENT_DIR" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L21 | neighbors=[server.test.js]
- "brainstorm_server_server_test_fetch": "fetch()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L50 | neighbors=[server.test.js]
- "brainstorm_server_server_test_fs": "fs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L14 | neighbors=[server.test.js]
- "brainstorm_server_server_test_http": "http" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L12 | neighbors=[server.test.js]
- "brainstorm_server_server_test_path": "path" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L15 | neighbors=[server.test.js]
- "brainstorm_server_server_test_server_path": "SERVER_PATH" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L18 | neighbors=[server.test.js]
- "brainstorm_server_server_test_skiptest_constructor": ".constructor()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L90 | neighbors=[SkipTest]
- "brainstorm_server_server_test_spawn": "{ spawn }" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L11 | neighbors=[server.test.js]
- "brainstorm_server_server_test_state_dir": "STATE_DIR" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L22 | neighbors=[server.test.js]
- "brainstorm_server_server_test_websocket": "WebSocket" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L13 | neighbors=[server.test.js]
- "brainstorm_server_ws_protocol_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L14 | neighbors=[ws-protocol.test.js]
- "brainstorm_server_ws_protocol_test_crypto": "crypto" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L15 | neighbors=[ws-protocol.test.js]
- "brainstorm_server_ws_protocol_test_path": "path" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L16 | neighbors=[ws-protocol.test.js]
- "brainstorm_server_ws_protocol_test_runtests": "runTests()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L31 | neighbors=[ws-protocol.test.js]
- "brainstorm_server_ws_protocol_test_server_path": "SERVER_PATH" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L19 | neighbors=[ws-protocol.test.js]
- "brick_abyssal_angler_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L41 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_grow": "grow()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L414 | neighbors=[abyssal_angler_brick.py]
- "brick_abyssal_angler_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L25 | neighbors=[abyssal_angler_brick.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-154.json

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
