# Node Description Batch 112 of 209

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

- "effekseer_ai_cli_curve_set": "_curve_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L111 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_emit": "_emit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L14 | neighbors=[cli.py, main()]
- "effekseer_ai_cli_export": "_export()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L92 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_image_import": "_image_import()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L85 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_node_add": "_node_add()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L42 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_node_list": "_node_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L38 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_node_move": "_node_move()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L63 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_node_remove": "_node_remove()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L56 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_node_rename": "_node_rename()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L49 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_property_get": "_property_get()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L74 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_property_list": "_property_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L70 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_property_set": "_property_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L78 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_rationale_1": "Command-line operations for the portable EffekseerCore bridge." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L1 | neighbors=[cli.py, EffectSession]
- "effekseer_ai_cli_rationale_130": "Build the CLI parser without accessing an Effekseer installation." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L130 | neighbors=[build_parser(), EffectSession]
- "effekseer_ai_cli_save": "_save()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L32 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_settings_list": "_settings_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L96 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_settings_set": "_settings_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L100 | neighbors=[cli.py, _open()]
- "effekseer_ai_cli_show": "_show()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L28 | neighbors=[cli.py, _open()]
- "effekseer_ai_init_rationale_1": "Python access to the official Effekseer Core API (vendored from effekseer-ai, MI" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/__init__.py:L1 | neighbors=[__init__.py, EffectSession]
- "effekseer_ai_models_assign_procedural_model": "assign_procedural_model()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/models.py:L21 | neighbors=[models.py, model_schema()]
- "effekseer_ai_models_model_schema": "model_schema()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/models.py:L4 | neighbors=[models.py, assign_procedural_model()]
- "effekseer_ai_session_effectsession_as_python": "._as_python()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L373 | neighbors=[EffectSession, .property_get()]
- "effekseer_ai_session_effectsession_export": ".export()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L286 | neighbors=[EffectSession, Export the current document as a runtim…]
- "effekseer_ai_session_effectsession_is_exported_property": "._is_exported_property()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L175 | neighbors=[EffectSession, .property_set()]
- "effekseer_ai_session_effectsession_new_curve_key": "._new_curve_key()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L245 | neighbors=[EffectSession, .curve_set_keys()]
- "effekseer_ai_session_effectsession_node_list": ".node_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L66 | neighbors=[EffectSession, List every non-root node currently know…]
- "effekseer_ai_session_effectsession_post_init": ".__post_init__()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L20 | neighbors=[EffectSession, ._index_existing_nodes()]
- "eggplots_egg_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L68 | neighbors=[egg_map.py, place()]
- "eggplots_egg_map_inset_top": "inset_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L108 | neighbors=[egg_map.py, hardscape()]
- "eggplots_egg_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L63 | neighbors=[egg_map.py, place()]
- "eggplots_egg_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L367 | neighbors=[egg_map.py, free()]
- "eggplots_egg_map_rationale_117": "lane: a stone slab (kerbed, chamfer into the lawn) carrying 4-stud pavers in a r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L117 | neighbors=[hardscape(), MB]
- "eggplots_egg_map_rationale_162": "island lawn + lake bank + hills: fine grid near the island, coarse on the hills;" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L162 | neighbors=[ground(), MB]
- "eggplots_egg_map_rationale_298": "point on the island superellipse at parameter angle t, scaled by k" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L298 | neighbors=[isle_point(), MB]
- "eggplots_egg_map_rationale_89": "height of the BUILT ground mesh (the coarse hill grid departs from H by several" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L89 | neighbors=[Hg(), MB]
- "eggplots_egg_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L27 | neighbors=[egg_map.py, hardscape()]
- "eggplots_egg_map_t": "T()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L159 | neighbors=[egg_map.py, hardscape()]
- "eggplots_egg_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L822 | neighbors=[egg_props.py, sh()]
- "eggplots_egg_props_lily_pads": "lily_pads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L928 | neighbors=[egg_props.py, sh()]
- "eggplots_egg_props_merge_prop": "merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L64 | neighbors=[egg_props.py, hay_stack()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-111.json

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
