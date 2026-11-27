# Node Description Batch 110 of 208

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

- "dunedesert_gen_trees_with_palms_palm_meshes": "palm_meshes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L939 | neighbors=[gen_trees_with_palms.py, make_tree()] | lang=en
- "dunedesert_gen_trees_with_palms_palmtree": "_PalmTree" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L936 | neighbors=[gen_trees_with_palms.py, make_tree()] | lang=en
- "dunedesert_gen_trees_with_palms_render_turntable": "render_turntable()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1122 | neighbors=[gen_trees_with_palms.py, main()] | lang=en
- "dunedesert_gen_trees_with_palms_resize": "resize()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1147 | neighbors=[gen_trees_with_palms.py, contact_sheet()] | lang=en
- "dunedesert_gen_trees_with_palms_save_png": "save_png()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L52 | neighbors=[gen_trees_with_palms.py, _img()] | lang=en
- "dunedesert_gen_trees_with_palms_setup_scene": "setup_scene()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1079 | neighbors=[gen_trees_with_palms.py, main()] | lang=en
- "dunedesert_gen_trees_with_palms_tri_count": "tri_count()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1119 | neighbors=[gen_trees_with_palms.py, make_tree()] | lang=en
- "dunedesert_gen_trees_with_palms_tube_mesh": "tube_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L498 | neighbors=[gen_trees_with_palms.py, make_tree()] | lang=en
- "dunedesert_sheet": "sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "effekseer_ai_authoring_layer_schema": "layer_schema()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L103 | neighbors=[authoring.py, Field names accepted by layer specs, fo…] | lang=en
- "effekseer_ai_authoring_rationale_1": "Reusable, discovered-property layer authoring. No GUI state is required." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L1 | neighbors=[authoring.py, EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_104": "Field names accepted by layer specs, for agents that want to check a recipe befo" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L104 | neighbors=[layer_schema(), EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_143": "Bind a texture slot and optionally scroll it; speeds are UV units per frame." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L143 | neighbors=[.uv(), EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_154": "Fixed position/scale that a dynamic equation recomputes every frame from the gam" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L154 | neighbors=[.bind(), EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_172": "Optional native features: dissolve, UV distortion, blend texture, fresnel, flipb" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L172 | neighbors=[.advanced(), EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_35": "A bind component: a number, an equation string, or [number, equation] meaning th" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L35 | neighbors=[_term(), EffectSession] | lang=pt
- "effekseer_ai_authoring_rationale_382": "Build a fresh document from a JSON recipe; repeat calls replace only that output" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L382 | neighbors=[compile_effect(), EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_50": "List problems the compiler would otherwise swallow: unknown or misspelt keys at" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L50 | neighbors=[validate_layer(), EffectSession] | lang=en
- "effekseer_ai_authoring_rationale_81": "{'start','end','easing'} equivalent of a cutoff curve [[percent_of_life, thresho" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L81 | neighbors=[cutoff_easing(), EffectSession] | lang=en
- "effekseer_ai_authoring_unknown": "_unknown()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L41 | neighbors=[authoring.py, validate_layer()] | lang=en
- "effekseer_ai_cli_curve_list": "_curve_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L107 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_curve_set": "_curve_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L111 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_emit": "_emit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L14 | neighbors=[cli.py, main()] | lang=en
- "effekseer_ai_cli_export": "_export()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L92 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_image_import": "_image_import()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L85 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_node_add": "_node_add()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L42 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_node_list": "_node_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L38 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_node_move": "_node_move()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L63 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_node_remove": "_node_remove()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L56 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_node_rename": "_node_rename()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L49 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_property_get": "_property_get()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L74 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_property_list": "_property_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L70 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_property_set": "_property_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L78 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_rationale_1": "Command-line operations for the portable EffekseerCore bridge." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L1 | neighbors=[cli.py, EffectSession] | lang=en
- "effekseer_ai_cli_rationale_130": "Build the CLI parser without accessing an Effekseer installation." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L130 | neighbors=[build_parser(), EffectSession] | lang=en
- "effekseer_ai_cli_save": "_save()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L32 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_settings_list": "_settings_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L96 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_settings_set": "_settings_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L100 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_cli_show": "_show()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L28 | neighbors=[cli.py, _open()] | lang=en
- "effekseer_ai_init_rationale_1": "Python access to the official Effekseer Core API (vendored from effekseer-ai, MI" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/__init__.py:L1 | neighbors=[__init__.py, EffectSession] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-109.json

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
