# Node Description Batch 195 of 207

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

- "tools_generate_math_reference_bits": "bits()" | kind=code-symbol | source=mute/tools/generate_math_reference.py:L18 | neighbors=[generate_math_reference.py] | lang=en
- "tools_generate_unicode_xid": "generate_unicode_xid.py" | kind=code-symbol | source=mute/tools/generate_unicode_xid.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "tools_math_determinism_object": "_object()" | kind=code-symbol | source=mute/tools/math_determinism.py:L20 | neighbors=[math_determinism.py] | lang=en
- "tools_pkb_schema_draft_main": "main()" | kind=code-symbol | source=mute/tools/pkb_schema_draft.cpp:L12 | neighbors=[pkb_schema_draft.cpp] | lang=en
- "tools_program_bytecode_probe_main": "main()" | kind=code-symbol | source=mute/tools/program_bytecode_probe.cpp:L7 | neighbors=[program_bytecode_probe.cpp] | lang=en
- "tools_readme_hero_rationale_1": "Contact-sheet hero for the README. One loop: a render closing on its reference." | kind=entity | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L1 | neighbors=[readme_hero.py] | lang=en
- "tools_readme_hero_rationale_42": "A small standing silhouette. Parameters are the things a bad first pass gets wro" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L42 | neighbors=[figure()] | lang=en
- "tools_run_tests_main": "main()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/run_tests.py:L15 | neighbors=[run_tests.py] | lang=en
- "tools_state_determinism_probe_main": "main()" | kind=code-symbol | source=mute/tools/state_determinism_probe.cpp:L6 | neighbors=[state_determinism_probe.cpp] | lang=en
- "tools_validate_skills_print_report": "print_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L278 | neighbors=[validate_skills.py] | lang=en
- "tools_validate_skills_rationale_1": "Validate the gamedev skills library.  Checks the things that silently rot in a s" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L1 | neighbors=[validate_skills.py] | lang=en
- "tools_validate_skills_rationale_108": "Collect T-nn ids from the knowledge base.      Accepts either layout: the worksp" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L108 | neighbors=[collect_tech_ids()] | lang=en
- "tools_validate_skills_rationale_136": "Warnings when the COVERAGE.md summary table disagrees with its matrices.      Sk" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L136 | neighbors=[check_coverage()] | lang=en
- "tools_validate_skills_rationale_31": "Minimal YAML front-matter reader: enough for flat scalars and the     '>' folded" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L31 | neighbors=[parse_frontmatter()] | lang=en
- "tools_validate_skills_rationale_47": "Script names a SKILL.md or reference may mention (any skill's scripts, repo tool" | kind=entity | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L47 | neighbors=[known_py()] | lang=pt
- "tools_validate_skills_rationale_85": "Locate SKILL.md files, accepting either layout.      `root/.agents/skills/` is t" | kind=entity | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L85 | neighbors=[find_skills()] | lang=en
- "towncity_city_paint_install": "install()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L200 | neighbors=[city_paint.py] | lang=en
- "towncity_city_paint_rationale_131": "polygon (list of Vector) clipped to lo <= f(p) <= hi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L131 | neighbors=[clip()] | lang=en
- "towncity_city_paint_rationale_27": "periodic FFT noise h x w in [-1, 1], feature frequency ~f per period" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L27 | neighbors=[pnoise()] | lang=en
- "towncity_city_paint_rationale_35": "1 inside a joint of half-width w (d = distance to the joint line in px), soft ed" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L35 | neighbors=[edge()] | lang=en
- "towncity_city_paint_rationale_46": "one periodic WP x HP tile at base shade s0 -> rgb" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L46 | neighbors=[tile()] | lang=en
- "towncity_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/hooks_lua.py:L5 | neighbors=[hooks_lua.py] | lang=en
- "towncity_town_landmarks_rationale_10": "box whose top is inset (mansard / hip roof / plinth taper)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L10 | neighbors=[frustum()] | lang=en
- "towncity_town_landmarks_rationale_242": "copy a temp Prop's solid mesh into P turned by yaw (keeps UVs)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L242 | neighbors=[_merge()] | lang=en
- "towncity_town_landmarks_rationale_28": "triangular pediment: raking cornices + tympanum + round emblem (no text)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L28 | neighbors=[pediment()] | lang=en
- "towncity_town_map_road_at": "road_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L41 | neighbors=[town_map.py] | lang=en
- "towncity_town_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L565 | neighbors=[town_map.py] | lang=en
- "towncity_town_props_fl": "fl()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L49 | neighbors=[town_props.py] | lang=en
- "towncity_town_props_sh": "sh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L51 | neighbors=[town_props.py] | lang=en
- "towncity_town_street_hedge": "hedge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L223 | neighbors=[town_street.py] | lang=en
- "towncity_town_street_hood": "_hood()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L33 | neighbors=[town_street.py] | lang=en
- "towncity_town_street_rationale_111": "municipal bin: base, ribbed teal body, yellow band, dome lid with a dark mouth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L111 | neighbors=[litter_bin()] | lang=en
- "towncity_town_street_rationale_124": "fire hydrant: lathed red body, bonnet + yellow nut, 3 hose outlets with yellow c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L124 | neighbors=[hydrant()] | lang=en
- "towncity_town_street_rationale_136": "commercial dumpster: tapered body, rim, two lids (one propped open on a trash ba" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L136 | neighbors=[dumpster()] | lang=pt
- "towncity_town_street_rationale_159": "heap of bin bags + two cardboard boxes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L159 | neighbors=[trash_bags()] | lang=en
- "towncity_town_street_rationale_170": "3 stacked shipping pallets (deck boards over stringers) + a box on top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L170 | neighbors=[pallets()] | lang=pt
- "towncity_town_street_rationale_180": "alley wall services (stands against a wall whose face is at z = 0, pieces toward" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L180 | neighbors=[wall_pipes()] | lang=en
- "towncity_town_street_rationale_193": "tree: flared trunk with roots, 4 limbs, 6 overlapping smooth leaf masses as one" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L193 | neighbors=[street_tree()] | lang=en
- "towncity_town_street_rationale_233": "low stone-edged bed with a row of leaf clumps and flowers in alternating colours" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L233 | neighbors=[flower_bed()] | lang=en
- "towncity_town_street_rationale_248": "the street tree pit alone (stone kerb + iron grate + trunk ring): the realistic" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_street.py:L248 | neighbors=[street_grate()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-194.json

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
