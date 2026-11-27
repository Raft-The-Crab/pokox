# Node Description Batch 50 of 209

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
- "eggplots_egg_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L96 | neighbors=[egg_map.py, ground(), hardscape(), sub()]
- "eggplots_egg_props_conveyor_end": "conveyor_end()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L462 | neighbors=[egg_props.py, rbox(), sh(), end cap block for the belt (roller drum…]
- "eggplots_egg_props_conveyor_seg": "conveyor_seg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L437 | neighbors=[egg_props.py, rbox(), sh(), egg conveyor segment along -Z (z 0..-L)…]
- "eggplots_egg_props_egg_slice": "egg_slice()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L84 | neighbors=[egg_props.py, egg_profile(), lerp(), a band of the egg between heights t0..t…]
- "eggplots_egg_props_fence_post": "fence_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L197 | neighbors=[egg_props.py, egg_finial(), post(), the closing post of a fence run]
- "eggplots_egg_props_gate_mat": "gate_mat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L669 | neighbors=[egg_props.py, rbox(), sh(), welcome path in the plot colour on the …]
- "eggplots_egg_props_hay_stack": "hay_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L395 | neighbors=[egg_props.py, hay_bale(), merge_prop(), three bales stacked (2 + 1), a pitchfor…]
- "eggplots_egg_props_lane_lamp": "lane_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L470 | neighbors=[egg_props.py, egg_profile(), sh(), lane lamp: stone base, honey post with …]
- "eggplots_egg_props_nest_pedestal": "nest_pedestal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L160 | neighbors=[egg_props.py, sh(), straw_nest(), incubator slot: octagon stone plinth wi…]
- "eggplots_egg_props_ranch_fence": "ranch_fence()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L852 | neighbors=[egg_props.py, rbox(), sh(), island edge ranch fence: two round-topp…]
- "evaluator_evaluator_is_unsigned": "is_unsigned()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L43 | neighbors=[evaluator.cpp, evaluate_arithmetic(), materialize(), unary()]
- "evaluator_evaluator_signed_max": "signed_max()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L55 | neighbors=[evaluator.cpp, evaluate_arithmetic(), materialize(), signed_binary()]
- "evaluator_evaluator_signed_min": "signed_min()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L56 | neighbors=[evaluator.cpp, evaluate_arithmetic(), signed_binary(), unary()]
- "evaluator_evaluator_unsigned_max": "unsigned_max()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L54 | neighbors=[evaluator.cpp, evaluate_arithmetic(), materialize(), unsigned_binary()]
- "examples_mx_master3_bin_3x3": "mx_master3_bin_3x3.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/examples/mx_master3_bin_3x3.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _rot(), Gridfinity 3x3 diagonal cradle bin for …]
- "fakes_enginefactoryvk": "EngineFactoryVk.h" | kind=code-symbol | source=engine/rhi/tests/fakes/EngineFactoryVk.h:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Diligent(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "fakes_refcntautoptr": "RefCntAutoPtr.hpp" | kind=code-symbol | source=engine/rhi/tests/fakes/RefCntAutoPtr.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, RefCntAutoPtr, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "fishcenter_fish_map_add_owner": "add_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L145 | neighbors=[fish_map.py, free(), place(), static()]
- "fishcenter_fish_map_arc_with_gaps": "arc_with_gaps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L503 | neighbors=[fish_map.py, rail_arc(), edges(), full circle at radius r minus angular g…]
- "fishcenter_fish_map_fit_bad": "fit_bad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L170 | neighbors=[fish_map.py, fit(), _inside_one(), _top()]
- "fishcenter_fish_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L126 | neighbors=[fish_map.py, add_owner(), look(), nature()]
- "fishcenter_fish_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L339 | neighbors=[fish_map.py, build(), static(), seabed + islets in one grid: fine insid…]
- "fishcenter_fish_map_h_raw": "H_raw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L70 | neighbors=[fish_map.py, H(), islet_e(), the natural depth profile (deep blue pa…]
- "fishcenter_fish_map_piling": "piling()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L216 | neighbors=[fish_map.py, deck_rect(), H(), ring_deck()]
- "fishcenter_fish_map_rail_arc": "rail_arc()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L474 | neighbors=[fish_map.py, arc_with_gaps(), pos(), arc run from angle a0 to a1 (degrees, i…]
- "fishcenter_fish_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L127 | neighbors=[fish_map.py, build(), nature(), stations()]
- "fishcenter_fish_props_lighthouse": "lighthouse()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1282 | neighbors=[fish_props.py, ball(), lerp(), the lighthouse rising out of the dome: …]
- "fishcenter_fish_props_net_pile": "net_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L570 | neighbors=[fish_props.py, ball(), lerp(), heap of teal fishing net: lumpy mound w…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-049.json

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
