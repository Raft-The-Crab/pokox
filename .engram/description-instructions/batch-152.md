# Node Description Batch 153 of 208

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

- "authority_projection_gate_projectiongate_projectiongate": ".ProjectionGate()" | kind=code-symbol | source=server/authority/include/poko/authority/projection_gate.hpp:L55 | neighbors=[ProjectionGate] | lang=en
- "authority_replay_ring_decode_replay": "decode_replay()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L232 | neighbors=[replay_ring.hpp] | lang=en
- "authority_replay_ring_fixedtables": "FixedTables()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L170 | neighbors=[replay_ring.hpp] | lang=en
- "authority_replay_ring_replayring": "ReplayRing" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L48 | neighbors=[replay_ring.hpp] | lang=en
- "authority_rule_evaluator_ruleevaluator": "RuleEvaluator" | kind=code-symbol | source=server/authority/include/poko/authority/rule_evaluator.hpp:L261 | neighbors=[rule_evaluator.hpp] | lang=en
- "authority_rule_evaluator_ruleparser_ruleparser": ".RuleParser()" | kind=code-symbol | source=server/authority/include/poko/authority/rule_evaluator.hpp:L77 | neighbors=[RuleParser] | lang=en
- "authority_session_sessionauthority_sessionauthority": ".SessionAuthority()" | kind=code-symbol | source=server/authority/include/poko/authority/session.hpp:L64 | neighbors=[SessionAuthority] | lang=en
- "bin_trace_processor_rationale_214": "Downloads a prebuilt or returns a cached version    The first time this is invok" | kind=entity | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L214 | neighbors=[download_or_get_cached()] | lang=en
- "bin_trace_processor_rationale_260": "Downloads the prebuilt, if necessary, and returns its path on disk." | kind=entity | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L260 | neighbors=[get_perfetto_prebuilt()] | lang=en
- "blender_character_blockout_purge_scene": "purge_scene()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L64 | neighbors=[character_blockout.py] | lang=en
- "blender_character_blockout_rationale_1": "Parametric human blockout from measured sheet fractions.  Every dimension is a f" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L1 | neighbors=[character_blockout.py] | lang=en
- "blender_character_blockout_rationale_254": "Print measured bounds so the comparison step has numbers, not vibes." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L254 | neighbors=[report()] | lang=en
- "blender_character_blockout_rationale_90": "Tapered capsule from p0 to p1 with radii r0/r1. Deterministic geometry." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L90 | neighbors=[capsule()] | lang=en
- "blender_character_blockout_shade_smooth": "shade_smooth()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L175 | neighbors=[character_blockout.py] | lang=en
- "blender_explorer_common_dim_init": ".__init__()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L51 | neighbors=[Dim] | lang=en
- "blender_explorer_common_dim_w": ".w()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L57 | neighbors=[Dim] | lang=en
- "blender_explorer_common_dim_z": ".z()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L54 | neighbors=[Dim] | lang=en
- "blender_explorer_common_link_to": "link_to()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L95 | neighbors=[explorer_common.py] | lang=en
- "blender_explorer_common_mat": "mat()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L63 | neighbors=[explorer_common.py] | lang=en
- "blender_explorer_common_rationale_1": "Explorer character — pass 2: garments, equipment, hair, materials.  Reads the me" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L1 | neighbors=[explorer_common.py] | lang=en
- "blender_explorer_common_rationale_104": "Duplicate meshes then scale about a pivot — cheap garment offset." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L104 | neighbors=[shell_from()] | lang=pt
- "blender_explorer_common_rationale_126": "Build a tube from a list of (center Vector, radius_x, radius_y, sides).      Rin" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L126 | neighbors=[loft()] | lang=en
- "blender_explorer_common_rationale_190": "Cylinder built at the origin, then placed. Never translate verts first.      Tra" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L190 | neighbors=[cylinder()] | lang=en
- "blender_explorer_common_solid_render": "solid_render()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L222 | neighbors=[explorer_common.py] | lang=en
- "blender_render_compare_views_rationale_1": "Fixed-camera turnaround renders for reference comparison.  Sets one camera + a n" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L1 | neighbors=[render_compare_views.py] | lang=en
- "blender_render_compare_views_rationale_108": "Three-point rig scaled to subject height.      Energies scale with height square" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L108 | neighbors=[setup_lighting()] | lang=en
- "blender_render_compare_views_rationale_55": "World bounds from evaluated vertices: bound_box is stale after mesh edits." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L55 | neighbors=[_scene_bounds()] | lang=en
- "blender_validate_scene_print_report": "print_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L153 | neighbors=[validate_scene.py] | lang=en
- "blender_validate_scene_rationale_1": "Automated scene validation gate.  Catches the two defect classes that silently r" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L1 | neighbors=[validate_scene.py] | lang=en
- "blender_validate_scene_rationale_113": "Measured landmark heights, for proportion drift checks." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L113 | neighbors=[landmarks()] | lang=en
- "blender_validate_scene_rationale_29": "World-space bounds computed from evaluated vertices.      ob.bound_box is a cach" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L29 | neighbors=[scene_bounds()] | lang=en
- "blender_validate_scene_rationale_69": "Objects whose bounds break the envelope on the horizontal axes." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L69 | neighbors=[find_strays()] | lang=en
- "blender_validate_scene_rationale_93": "Objects floating away from the body mass - the sideways-cylinder signature." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L93 | neighbors=[find_isolated()] | lang=en
- "brainstorm_server_auth_test_assertsecurityheaders": "assertSecurityHeaders()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L82 | neighbors=[auth.test.js] | lang=en
- "brainstorm_server_auth_test_content_dir": "CONTENT_DIR" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L25 | neighbors=[auth.test.js] | lang=en
- "brainstorm_server_auth_test_expected_security_headers": "EXPECTED_SECURITY_HEADERS" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L28 | neighbors=[auth.test.js] | lang=en
- "brainstorm_server_auth_test_fs": "fs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L18 | neighbors=[auth.test.js] | lang=en
- "brainstorm_server_auth_test_get": "get()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L45 | neighbors=[auth.test.js] | lang=en
- "brainstorm_server_auth_test_http": "http" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L16 | neighbors=[auth.test.js] | lang=en
- "brainstorm_server_auth_test_path": "path" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L19 | neighbors=[auth.test.js] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-152.json

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
