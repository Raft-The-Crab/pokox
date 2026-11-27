# Node Description Batch 111 of 208

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

- "effekseer_ai_models_assign_procedural_model": "assign_procedural_model()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/models.py:L21 | neighbors=[models.py, model_schema()] | lang=en
- "effekseer_ai_models_model_schema": "model_schema()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/models.py:L4 | neighbors=[models.py, assign_procedural_model()] | lang=en
- "effekseer_ai_session_effectsession_as_python": "._as_python()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L373 | neighbors=[EffectSession, .property_get()] | lang=en
- "effekseer_ai_session_effectsession_export": ".export()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L286 | neighbors=[EffectSession, Export the current document as a runtim…] | lang=en
- "effekseer_ai_session_effectsession_is_exported_property": "._is_exported_property()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L175 | neighbors=[EffectSession, .property_set()] | lang=en
- "effekseer_ai_session_effectsession_new_curve_key": "._new_curve_key()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L245 | neighbors=[EffectSession, .curve_set_keys()] | lang=en
- "effekseer_ai_session_effectsession_node_list": ".node_list()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L66 | neighbors=[EffectSession, List every non-root node currently know…] | lang=en
- "effekseer_ai_session_effectsession_post_init": ".__post_init__()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L20 | neighbors=[EffectSession, ._index_existing_nodes()] | lang=en
- "eggplots_egg_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L68 | neighbors=[egg_map.py, place()] | lang=en
- "eggplots_egg_map_inset_top": "inset_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L108 | neighbors=[egg_map.py, hardscape()] | lang=en
- "eggplots_egg_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L63 | neighbors=[egg_map.py, place()] | lang=en
- "eggplots_egg_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L367 | neighbors=[egg_map.py, free()] | lang=en
- "eggplots_egg_map_rationale_117": "lane: a stone slab (kerbed, chamfer into the lawn) carrying 4-stud pavers in a r" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L117 | neighbors=[hardscape(), MB] | lang=en
- "eggplots_egg_map_rationale_162": "island lawn + lake bank + hills: fine grid near the island, coarse on the hills;" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L162 | neighbors=[ground(), MB] | lang=en
- "eggplots_egg_map_rationale_298": "point on the island superellipse at parameter angle t, scaled by k" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L298 | neighbors=[isle_point(), MB] | lang=en
- "eggplots_egg_map_rationale_89": "height of the BUILT ground mesh (the coarse hill grid departs from H by several" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L89 | neighbors=[Hg(), MB] | lang=en
- "eggplots_egg_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L27 | neighbors=[egg_map.py, hardscape()] | lang=en
- "eggplots_egg_map_t": "T()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L159 | neighbors=[egg_map.py, hardscape()] | lang=en
- "eggplots_egg_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L822 | neighbors=[egg_props.py, sh()] | lang=en
- "eggplots_egg_props_lily_pads": "lily_pads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L928 | neighbors=[egg_props.py, sh()] | lang=en
- "eggplots_egg_props_merge_prop": "merge_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L64 | neighbors=[egg_props.py, hay_stack()] | lang=en
- "eggplots_egg_props_rationale_137": "chunky low-poly nest: a fat torus rim with a dished floor, straw wisps poking ou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L137 | neighbors=[straw_nest(), Palette] | lang=pt
- "eggplots_egg_props_rationale_148": "post-top egg knob: accent collar + cream egg with an accent band" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L148 | neighbors=[egg_finial(), Palette] | lang=en
- "eggplots_egg_props_rationale_153": "square post with a stone footing (extends below ground) and a chamfered top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L153 | neighbors=[post(), Palette] | lang=en
- "eggplots_egg_props_rationale_161": "incubator slot: octagon stone plinth with an accent ring + four gem studs, honey" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L161 | neighbors=[nest_pedestal(), Palette] | lang=en
- "eggplots_egg_props_rationale_177": "picket fence segment along +X (0..L), front -Z: a slim honey post with an accent" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L177 | neighbors=[fence_run(), Palette] | lang=en
- "eggplots_egg_props_rationale_198": "the closing post of a fence run" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L198 | neighbors=[fence_post(), Palette] | lang=en
- "eggplots_egg_props_rationale_205": "yard entrance (the laser / force-gate spot, opening W): two stone-footed pillars" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L205 | neighbors=[gate_frame(), Palette] | lang=en
- "eggplots_egg_props_rationale_234": "owner board: two honey posts, accent frame, BLANK cream face toward -Z (GUI), a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L234 | neighbors=[owner_sign(), Palette] | lang=pt
- "eggplots_egg_props_rationale_250": "cash collect pad: octagon stone ring, accent rim with a glow ring, cream disc wi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L250 | neighbors=[collect_pad(), Palette] | lang=en
- "eggplots_egg_props_rationale_263": "the yard: chamfered stone footing + accent kerb, straw-cream ground, a paved sto" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L263 | neighbors=[plot_slab(), Palette] | lang=en
- "eggplots_egg_props_rationale_297": "the nest-coop (the plot's base building): stone plinth, cream plaster walls with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L297 | neighbors=[coop(), Palette] | lang=en
- "eggplots_egg_props_rationale_385": "square hay bale: chamfered straw block, two twine bands, straw tufts on top" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L385 | neighbors=[hay_bale(), Palette] | lang=en
- "eggplots_egg_props_rationale_396": "three bales stacked (2 + 1), a pitchfork-free story pile" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L396 | neighbors=[hay_stack(), Palette] | lang=pt
- "eggplots_egg_props_rationale_403": "grain trough: honey plank trough on splayed legs, grain heap inside, small egg-c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L403 | neighbors=[feed_trough(), Palette] | lang=en
- "eggplots_egg_props_rationale_422": "half-barrel planter: honey staves with iron hoops, soil, low-poly tulips" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L422 | neighbors=[flower_tub(), Palette] | lang=en
- "eggplots_egg_props_rationale_438": "egg conveyor segment along -Z (z 0..-L): stone feet, honey side boards with an a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L438 | neighbors=[conveyor_seg(), Palette] | lang=en
- "eggplots_egg_props_rationale_471": "lane lamp: stone base, honey post with an iron arm, an egg-shaped glowing lanter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L471 | neighbors=[lane_lamp(), Palette] | lang=en
- "eggplots_egg_props_rationale_486": "giant painted egg (lane / plaza decor) on a straw nest on a stone plinth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L486 | neighbors=[deco_egg(), Palette] | lang=pt
- "eggplots_egg_props_rationale_497": "humped plank footbridge over the belt (along X): stone abutments on the walkways" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L497 | neighbors=[foot_bridge(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-110.json

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
