# Node Description Batch 48 of 207

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

- "dunedesert_dune_map_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L249 | neighbors=[dune_map.py, fit_bad(), place(), raise the prop in 0.25 steps (its base …]
- "dunedesert_dune_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L276 | neighbors=[dune_map.py, build(), H(), static()]
- "dunedesert_dune_map_on_path": "on_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L108 | neighbors=[dune_map.py, fragments(), nature(), pl_d()]
- "dunedesert_dune_map_pl_d": "pl_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L56 | neighbors=[dune_map.py, H(), on_path(), _seg_d()]
- "dunedesert_dune_map_ring": "ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L68 | neighbors=[dune_map.py, H(), nature(), frame: high dune ridges on a ring r ~43…]
- "dunedesert_dune_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L550 | neighbors=[dune_props.py, cargo_pile(), plank crate: bevelled body with plank g…, trader_tent()]
- "dunedesert_dune_props_outcrop": "outcrop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L858 | neighbors=[dune_props.py, lerp(), V(), sandstone outcrop: two or three wind-cu…]
- "dunedesert_dune_props_rug_spread": "rug_spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L703 | neighbors=[dune_props.py, rest corner: a big patterned rug (borde…, uvsphere(), V()]
- "dunedesert_dune_props_ruin_wall": "ruin_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L284 | neighbors=[dune_props.py, broken wall of real bevelled blocks wit…, block_wall(), sun_relief()]
- "dunedesert_dune_props_sand_drift": "sand_drift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L897 | neighbors=[dune_props.py, smooth sand drift banked against ruins …, uvsphere(), V()]
- "dunedesert_dune_props_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L435 | neighbors=[dune_props.py, spawn: round three-step sandstone dais …, disc(), frustum()]
- "dunedesert_dune_props_sun_astrolabe": "sun_astrolabe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L488 | neighbors=[dune_props.py, UPGRADE station: octagonal stepped plin…, frustum(), sun_relief()]
- "dunedesert_dune_props_waystone": "waystone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L422 | neighbors=[dune_props.py, path marker: weathered standing stone w…, frustum(), sun_relief()]
- "dunedesert_gen_trees_with_palms_bark_birch": "bark_birch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L86 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp()]
- "dunedesert_gen_trees_with_palms_bark_oak": "bark_oak()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L71 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp()]
- "dunedesert_gen_trees_with_palms_canvas_leaf": ".leaf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L153 | neighbors=[Canvas, .grid(), .over(), leaf_atlas()]
- "dunedesert_gen_trees_with_palms_contact_sheet": "contact_sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1152 | neighbors=[gen_trees_with_palms.py, load_px(), resize(), main()]
- "dunedesert_gen_trees_with_palms_img": "_img()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1203 | neighbors=[gen_trees_with_palms.py, get_materials(), save_png(), paint + save the texture, or (maps) loa…]
- "dunedesert_gen_trees_with_palms_tree_env": ".env()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L357 | neighbors=[card_quads(), <1 inside the lumpy crown envelope., Tree, .children_of()]
- "effekseer_ai_authoring_code": "_code()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L37 | neighbors=[authoring.py, _number(), .bind(), validate_layer()]
- "effekseer_ai_authoring_layerbuilder_color": ".color()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L133 | neighbors=[LayerBuilder, .advanced(), .rand(), .scalar()]
- "effekseer_ai_authoring_layerbuilder_rand": ".rand()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L124 | neighbors=[LayerBuilder, .color(), .uv(), .vector()]
- "effekseer_ai_authoring_layerbuilder_vector": ".vector()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L129 | neighbors=[LayerBuilder, .advanced(), .rand(), .scalar()]
- "effekseer_ai_authoring_number": "_number()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L33 | neighbors=[authoring.py, _code(), .bind(), _term()]
- "effekseer_ai_authoring_term": "_term()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L34 | neighbors=[authoring.py, A bind component: a number, an equation…, _number(), validate_layer()]
- "effekseer_ai_preview": "preview.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/preview.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, preview_effects(), Render through the official Godot plugi…]
- "effekseer_ai_resources": "resources.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/resources.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, process_texture(), Preserve original generated masks and p…]
- "effekseer_ai_session": "session.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, EffectSession, The minimal effect-document lifecycle b…]
- "effekseer_ai_session_effectsession_copy_resource": "._copy_resource()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L308 | neighbors=[EffectSession, .import_image(), .import_model(), Copy an approved asset to this effect's…]
- "effekseer_ai_session_effectsession_curve_set_keys": ".curve_set_keys()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L220 | neighbors=[EffectSession, ._new_curve_key(), ._object_at_path(), Replace scalar FCurve keys using Core's…]
- "effekseer_ai_session_effectsession_import_model": ".import_model()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L276 | neighbors=[EffectSession, ._copy_resource(), ._object_at_path(), Copy a model into ``resources/`` and bi…]
- "effekseer_ai_session_effectsession_index_existing_nodes": "._index_existing_nodes()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L294 | neighbors=[EffectSession, .move_node(), .__post_init__(), .remove_node()]
- "effekseer_ai_session_effectsession_move_node": ".move_node()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L93 | neighbors=[EffectSession, ._index_existing_nodes(), ._node(), Move a node and return its new structur…]
- "effekseer_ai_session_effectsession_property_get": ".property_get()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L107 | neighbors=[EffectSession, ._as_python(), ._property_parent(), Read a public Core member without invok…]
- "effekseer_ai_session_effectsession_property_list": ".property_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L132 | neighbors=[EffectSession, ._node(), .settings_list(), Discover editable leaf paths without wa…]
- "effekseer_ai_session_effectsession_remove_node": ".remove_node()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L84 | neighbors=[EffectSession, ._index_existing_nodes(), ._node(), Remove a node and its descendants from …]
- "eggplots_egg_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L103 | neighbors=[egg_map.py, lane(), plot(), spawn_area()]
- "eggplots_egg_map_hg": "Hg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L88 | neighbors=[egg_map.py, H(), place(), height of the BUILT ground mesh (the co…]
- "eggplots_egg_map_isle_point": "isle_point()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L297 | neighbors=[egg_map.py, dressing(), ground(), point on the island superellipse at par…]
- "eggplots_egg_map_plot": "plot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L210 | neighbors=[egg_map.py, build(), anchor(), to_world()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-047.json

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
