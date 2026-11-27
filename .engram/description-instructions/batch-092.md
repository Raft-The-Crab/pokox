# Node Description Batch 93 of 208

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

- "addon_template_ui_mytool_pt_main": "MYTOOL_PT_main" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L4 | neighbors=[ui.py, .draw()]
- "animation_build_animations_interp": "interp()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L8 | neighbors=[build_animations.py, smooth()]
- "animation_build_animations_smooth": "smooth()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L6 | neighbors=[build_animations.py, interp()]
- "animation_check_subframes": "check_subframes.py" | kind=code-symbol | source=assets/characters/animation/check_subframes.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "animation_v2_build_refined_interp": "interp()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L11 | neighbors=[build_refined.py, ease()]
- "animation_v2_check_model_structure_capture": "capture()" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L9 | neighbors=[check_model_structure.py, floats()]
- "animation_v2_check_model_structure_floats": "floats()" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L5 | neighbors=[check_model_structure.py, capture()]
- "animation_validate_animations": "validate_animations.py" | kind=code-symbol | source=assets/characters/animation/validate_animations.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "authority_pkb_schema_is_protected_domain": "is_protected_domain()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L78 | neighbors=[pkb_schema.hpp, load_pkb_schema()]
- "authority_pkb_schema_load_pkb_schema": "load_pkb_schema()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L92 | neighbors=[pkb_schema.hpp, is_protected_domain()]
- "authority_pkb_schema_pkbauthority": "PkbAuthority" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L224 | neighbors=[pkb_schema.hpp, .PkbAuthority()]
- "authority_projection_gate": "projection_gate.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/projection_gate.hpp:L1 | neighbors=[ProjectionGate, 6e2fe3a Created BAK-7 and other BAK tas…]
- "authority_projection_gate_projectiongate": "ProjectionGate" | kind=code-symbol | source=server/authority/include/poko/authority/projection_gate.hpp:L34 | neighbors=[projection_gate.hpp, .ProjectionGate()]
- "authority_replay_ring_cbor_bool": "cbor_bool()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L96 | neighbors=[replay_ring.hpp, encode_replay()]
- "authority_replay_ring_emit_litlen": "emit_litlen()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L162 | neighbors=[replay_ring.hpp, encode_replay()]
- "authority_rule_evaluator_ruleparser": "RuleParser" | kind=code-symbol | source=server/authority/include/poko/authority/rule_evaluator.hpp:L75 | neighbors=[rule_evaluator.hpp, .RuleParser()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-092.json

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
