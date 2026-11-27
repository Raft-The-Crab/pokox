# Node Description Batch 174 of 208

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

- "opencode_test_session_bootstrap_compactedevent": "compactedEvent()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L154 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_empty": "empty" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L230 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_freshrootevent": "freshRootEvent" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L177 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_makeevent": "makeEvent()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L15 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_makeharness": "makeHarness()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L31 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_newpromptaftercheckpoint": "newPromptAfterCheckpoint" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L203 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_originalchild": "originalChild" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L184 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_originalretaineduserchild": "originalRetainedUserChild" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L226 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_pluginurl": "pluginURL" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L7 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_recoveredchild": "recoveredChild" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L197 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_reply": "reply()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L11 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_retainedcheckpoint": "retainedCheckpoint" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L212 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_retaineduser": "retainedUser" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L210 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_retaineduserchild": "retainedUserChild" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L224 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_rootevent": "rootEvent" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L166 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_session_bootstrap_unknownchild": "unknownChild" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-session-bootstrap.mjs:L194 | neighbors=[test-session-bootstrap.mjs]
- "opencode_test_skill_registration_added": "added" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L29 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_failures": "failures" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L26 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_fixtureroot": "fixtureRoot" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L144 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_frontmatterfixtures": "frontmatterFixtures" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L126 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_makectx": "makeCtx()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L193 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_pluginpath": "pluginPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L22 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_result": "result" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L174 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_skillsdir": "skillsDir" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L23 | neighbors=[test-skill-registration.mjs]
- "opencode_test_skill_registration_survived": "survived" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L83 | neighbors=[test-skill-registration.mjs]
- "package_package_dump_lockfile": "dump_lockfile()" | kind=code-symbol | source=mute/src/package/package.cpp:L223 | neighbors=[package.cpp]
- "package_package_name": "name()" | kind=code-symbol | source=mute/src/package/package.cpp:L234 | neighbors=[package.cpp]
- "parser_declaration_declarationparser_declarationparser": ".DeclarationParser()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L358 | neighbors=[DeclarationParser]
- "parser_declaration_name": "name()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L441 | neighbors=[declaration.cpp]
- "parser_declaration_parse_declarations": "parse_declarations()" | kind=code-symbol | source=mute/src/parser/declaration.cpp:L432 | neighbors=[declaration.cpp]
- "parser_parser_expr_op": "expr_op()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L33 | neighbors=[parser.cpp]
- "parser_parser_expressionparser_expressionparser": ".ExpressionParser()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L167 | neighbors=[ExpressionParser]
- "parser_parser_is_assign_op": "is_assign_op()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L67 | neighbors=[parser.cpp]
- "parser_parser_name": "name()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L357 | neighbors=[parser.cpp]
- "parser_parser_parse_arithmetic": "parse_arithmetic()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L345 | neighbors=[parser.cpp]
- "parser_statement_loopscope": "LoopScope()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L69 | neighbors=[statement.cpp]
- "parser_statement_name": "name()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L322 | neighbors=[statement.cpp]
- "parser_statement_parse_statements": "parse_statements()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L302 | neighbors=[statement.cpp]
- "parser_statement_statementparser_statementparser": ".StatementParser()" | kind=code-symbol | source=mute/src/parser/statement.cpp:L291 | neighbors=[StatementParser]
- "passes_imgui_demo_imguicontextguard": "ImGuiContextGuard()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L220 | neighbors=[imgui_demo.cpp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-173.json

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
