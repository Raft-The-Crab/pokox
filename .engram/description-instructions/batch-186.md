# Node Description Batch 187 of 209

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

- "shared_bpyx_rationale_133": "Round a float or a vector for compact JSON." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L133 | neighbors=[r()] | lang=pt
- "shared_bpyx_rationale_20": "Arguments after '--' (Blender ignores them)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L20 | neighbors=[argv()] | lang=en
- "shared_bpyx_rationale_36": "Print compact JSON on one marked line (parsed by run_in_blender.py)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L36 | neighbors=[emit()] | lang=en
- "shared_bpyx_rationale_42": "ArgumentParser whose help is the script docstring's first line." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L42 | neighbors=[parser()] | lang=en
- "shared_bpyx_rationale_47": "CLI entry: parse args after '--', run, emit JSON. Exit 1 on failure." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L47 | neighbors=[cli()] | lang=en
- "shared_bpyx_rationale_63": "--objects / --save flags shared by most scripts." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L63 | neighbors=[add_common()] | lang=en
- "shared_bpyx_rationale_72": "Resolve names -> objects. No names: selected of `types`, else all visible of `ty" | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L72 | neighbors=[objects()] | lang=en
- "shared_bpyx_rationale_84": "Leave edit/sculpt/pose modes; most data API work needs OBJECT mode." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L84 | neighbors=[object_mode()] | lang=en
- "shared_bpyx_rationale_91": "Select exactly `objs` and make `active` (default first) active." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L91 | neighbors=[select_only()] | lang=en
- "skyrise_sky_kit_sheet_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_kit_sheet.py:L45 | neighbors=[sky_kit_sheet.py] | lang=en
- "skyrise_sky_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L431 | neighbors=[sky_map.py] | lang=en
- "skyrise_sky_map_rationale_115": "widest horizontal reach of a kit prop (all parts)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L115 | neighbors=[ext()] | lang=en
- "skyrise_sky_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L415 | neighbors=[sky_map.py] | lang=en
- "skyrise_sky_models_rationale_10": "icosphere with noise displacement: chunky stylised foliage / cloud / rock lump" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L10 | neighbors=[lumpy()] | lang=en
- "skyrise_sky_models_rationale_110": "underside: 16 rings to a rough tip, noise-displaced (no big flat triangles), ter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L110 | neighbors=[island_under()] | lang=en
- "skyrise_sky_models_rationale_203": "carved stone gate: stepped plinths, octagonal banded shafts with capitals, a vou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L203 | neighbors=[zone_gate()] | lang=en
- "skyrise_sky_models_rationale_23": "trunk that forks into 2-3 limbs, root flares into the ground, chunky lumpy canop" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L23 | neighbors=[puffy_tree()] | lang=en
- "skyrise_sky_models_rationale_76": "pine: 4 star tiers with drooping snow caps, trunk, root collar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L76 | neighbors=[snow_tree()] | lang=en
- "skyrise_sky_models2_rationale_113": "ribbed saguaro: star-section body, two elbowed arms, flowers, pebbles" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L113 | neighbors=[cactus()] | lang=en
- "skyrise_sky_models2_rationale_133": "hexagonal basalt columns of stepped heights, lighter bevelled tops, glowing lava" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L133 | neighbors=[basalt_rocks()] | lang=en
- "skyrise_sky_models2_rationale_152": "egg hatch altar: 3-tier dais with gold inlay + front steps, golden claw cradle o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L152 | neighbors=[egg_shrine()] | lang=en
- "skyrise_sky_models2_rationale_16": "n separate bevelled planks side by side along x, alternating shade (reads as woo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L16 | neighbors=[planks()] | lang=en
- "skyrise_sky_models2_rationale_190": "sell booth: glowing sell circle in front, planked counter with gold trim, a gian" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L190 | neighbors=[sell_pad()] | lang=en
- "skyrise_sky_models2_rationale_217": "upgrade shop: planked counter with gold trim, back wall with shelves of glowing" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L217 | neighbors=[upgrade_stand()] | lang=en
- "skyrise_sky_models2_rationale_23": "a heap built only from coins (rings of tilted coins, smaller toward the top), tw" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L23 | neighbors=[coin_pile()] | lang=en
- "skyrise_sky_models2_rationale_254": "stone frame with side columns and a gem crown crest; screen with gold/silver/bro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L254 | neighbors=[leaderboard()] | lang=en
- "skyrise_sky_models2_rationale_281": "stepped round platform with inlaid glowing rune circles, two curved stone horns" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L281 | neighbors=[teleport_pad()] | lang=en
- "skyrise_sky_models2_rationale_40": "planked chest, curved lid held open, iron bands following the curve, corner caps" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L40 | neighbors=[chest()] | lang=en
- "skyrise_sky_models2_rationale_73": "6-9 hexagonal crystals with pointed tips radiating from a rock bed, a tall glowi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L73 | neighbors=[crystal_node()] | lang=en
- "skyrise_sky_models2_rationale_9": "coin with a raised rim (lathe), lying flat" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L9 | neighbors=[coin()] | lang=en
- "skyrise_sky_models2_rationale_98": "12-point star section swept along a straight segment a->b, domed cap" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L98 | neighbors=[_ribbed()] | lang=pt
- "skyrise_sky_models3_rationale_29": "molten pool: ring of basalt boulders, glowing surface with dark crust plates flo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L29 | neighbors=[lava_pool()] | lang=en
- "skyrise_sky_models3_rationale_44": "burnt tree: thick twisting trunk with 4 forked branches, glowing ember cracks, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L44 | neighbors=[charred_tree()] | lang=en
- "skyrise_sky_models3_rationale_63": "lumpy faceted bush: 4-6 clumps, lighter on top, with a few berries or flowers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L63 | neighbors=[bush()] | lang=en
- "skyrise_sky_models3_rationale_77": "iron street lantern: stepped stone base, fluted post with collars, curled bracke" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L77 | neighbors=[lamp_post()] | lang=en
- "skyrise_sky_models3_rationale_9": "sandstone butte: 3 eroded faceted tiers (lumpy hull rings, each narrower), darke" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L9 | neighbors=[mesa_rock()] | lang=en
- "skyrise_sky_models3_rationale_93": "zone signpost: planked arrow board with a gold border, the zone gem, a post with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L93 | neighbors=[signpost()] | lang=en
- "skyrise_sky_models4_ash_pile": "ash_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L96 | neighbors=[sky_models4.py] | lang=en
- "skyrise_sky_models4_ember_rocks": "ember_rocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L104 | neighbors=[sky_models4.py] | lang=en
- "skyrise_sky_models4_ice_shards": "ice_shards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L87 | neighbors=[sky_models4.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-186.json

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
