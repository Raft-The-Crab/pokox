# Node Description Batch 166 of 209

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

- "effekseer_ai_resources_rationale_1": "Preserve original generated masks and produce straight-alpha power-of-two sprite" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/resources.py:L1 | neighbors=[resources.py] | lang=en
- "effekseer_ai_runtime_rationale_1": "Load the official Effekseer Core assembly through Python.NET." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L1 | neighbors=[runtime.py] | lang=en
- "effekseer_ai_runtime_rationale_15": "Return the configured directory containing ``EffekseerCore.dll``.      A release" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L15 | neighbors=[editor_bin_directory()] | lang=en
- "effekseer_ai_runtime_rationale_36": "Return the bundled .NET runtime configuration file." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L36 | neighbors=[runtime_config_path()] | lang=en
- "effekseer_ai_runtime_rationale_44": "Load and return the official static ``Effekseer.Core`` type." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L44 | neighbors=[load_core()] | lang=en
- "effekseer_ai_runtime_rationale_67": "Export the current Core document as an Effekseer runtime ``.efk`` file." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L67 | neighbors=[export_binary()] | lang=en
- "effekseer_ai_session_effectsession_new": ".new()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L25 | neighbors=[EffectSession] | lang=en
- "effekseer_ai_session_effectsession_open": ".open()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L30 | neighbors=[EffectSession] | lang=en
- "effekseer_ai_session_effectsession_save": ".save()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L38 | neighbors=[EffectSession] | lang=en
- "effekseer_ai_session_effectsession_summary": ".summary()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L49 | neighbors=[EffectSession] | lang=en
- "effekseer_ai_session_rationale_1": "The minimal effect-document lifecycle backed by Effekseer Core." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L1 | neighbors=[session.py] | lang=en
- "effekseer_ai_session_rationale_108": "Read a public Core member without invoking arbitrary methods." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L108 | neighbors=[.property_get()] | lang=pt
- "effekseer_ai_session_rationale_113": "Write an editable Core value or a public writable property." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L113 | neighbors=[.property_set()] | lang=en
- "effekseer_ai_session_rationale_133": "Discover editable leaf paths without walking parent/tree references." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L133 | neighbors=[.property_list()] | lang=en
- "effekseer_ai_session_rationale_16": "A handle to the single Core document hosted by this Python process." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L16 | neighbors=[EffectSession] | lang=en
- "effekseer_ai_session_rationale_182": "Discover parameters grouped as they are in the editor's setting panels." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L182 | neighbors=[.settings_list()] | lang=en
- "effekseer_ai_session_rationale_197": "Set a batch of panel-relative editable fields." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L197 | neighbors=[.settings_set()] | lang=en
- "effekseer_ai_session_rationale_208": "Read a scalar curve as JSON-friendly keyframe data." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L208 | neighbors=[.curve_keys()] | lang=pt
- "effekseer_ai_session_rationale_221": "Replace scalar FCurve keys using Core's add/remove commands." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L221 | neighbors=[.curve_set_keys()] | lang=en
- "effekseer_ai_session_rationale_264": "Copy an image beside the effect and optionally bind its Core path." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L264 | neighbors=[.import_image()] | lang=en
- "effekseer_ai_session_rationale_277": "Copy a model into ``resources/`` and bind it through Core's path API." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L277 | neighbors=[.import_model()] | lang=en
- "effekseer_ai_session_rationale_287": "Export the current document as a runtime `.efk` file." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L287 | neighbors=[.export()] | lang=en
- "effekseer_ai_session_rationale_309": "Copy an approved asset to this effect's resource directory." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L309 | neighbors=[._copy_resource()] | lang=en
- "effekseer_ai_session_rationale_353": "Write scalar values through nested Core editable-value wrappers." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L353 | neighbors=[._assign_value()] | lang=en
- "effekseer_ai_session_rationale_57": "Add a Core node and return its AI-facing path." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L57 | neighbors=[.add_node()] | lang=en
- "effekseer_ai_session_rationale_67": "List every non-root node currently known to the session." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L67 | neighbors=[.node_list()] | lang=en
- "effekseer_ai_session_rationale_79": "Rename a node through its Core string value." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L79 | neighbors=[.rename_node()] | lang=pt
- "effekseer_ai_session_rationale_85": "Remove a node and its descendants from the current document." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L85 | neighbors=[.remove_node()] | lang=en
- "effekseer_ai_session_rationale_94": "Move a node and return its new structural path." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L94 | neighbors=[.move_node()] | lang=en
- "effekseer_ai_settings_rationale_1": "Names of node setting panels exposed by the Effekseer editor." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/settings.py:L1 | neighbors=[settings.py] | lang=en
- "eggplots_egg_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L411 | neighbors=[egg_map.py] | lang=en
- "eggplots_egg_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L416 | neighbors=[egg_map.py] | lang=en
- "eggplots_egg_props_boulder": "boulder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L847 | neighbors=[egg_props.py] | lang=en
- "eggplots_egg_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L921 | neighbors=[egg_props.py] | lang=en
- "eggplots_egg_props_rationale_463": "end cap block for the belt (roller drum + boards)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L463 | neighbors=[conveyor_end()] | lang=en
- "eggplots_egg_props_rationale_56": "bevelled box (low poly: 1 segment = a chamfer)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L56 | neighbors=[rbox()] | lang=pt
- "eggplots_egg_props_rationale_96": "the identity Egg: faceted lathe egg; optional painted zigzag band (band colour)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L96 | neighbors=[egg()] | lang=en
- "eggplots_egg_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L50 | neighbors=[egg_props.py] | lang=en
- "eggplots_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/hooks_lua.py:L4 | neighbors=[hooks_lua.py] | lang=en
- "evaluator_evaluator_floatenvironment_floatenvironment": ".FloatEnvironment()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L99 | neighbors=[FloatEnvironment] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-165.json

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
