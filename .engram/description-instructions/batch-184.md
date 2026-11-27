# Node Description Batch 185 of 207

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
- "skyrise_sky_models4_pebbles": "pebbles()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L32 | neighbors=[sky_models4.py] | lang=en
- "skyrise_sky_models4_rationale_10": "one grass blade: thin tapered wedge (4 verts, 4 tris) leaning outward, tip bent" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L10 | neighbors=[blade()] | lang=en
- "skyrise_sky_models4_rationale_114": "bridge from z=0 to z=-L rising by `rise`.     wood: irregular planks with nail h" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L114 | neighbors=[bridge()] | lang=en
- "skyrise_sky_models4_rationale_182": "low tiered fountain: octagonal stone basin with a lip, water surface, gold trim," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L182 | neighbors=[plaza_fountain()] | lang=en
- "skyrise_sky_models4_rationale_24": "modelled blade cluster, dark at the root, light at the tips" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L24 | neighbors=[grass_tuft()] | lang=en
- "skyrise_sky_models4_rationale_41": "small flower clump: stems + 5-petal star heads + gold centres, one or two colour" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L41 | neighbors=[wildflowers()] | lang=en
- "skyrise_sky_models4_rationale_52": "two or three toadstools: lathe stems, red caps with white spots" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L52 | neighbors=[mushrooms()] | lang=en
- "skyrise_sky_models4_rationale_69": "twiggy desert shrub: forked twigs from a root knot" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L69 | neighbors=[dry_shrub()] | lang=en
- "skyrise_sky_models4_snow_mound": "snow_mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L80 | neighbors=[sky_models4.py] | lang=en
- "skyrise_sky_props_basalt_rocks": "basalt_rocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L419 | neighbors=[sky_props.py] | lang=en
- "skyrise_sky_props_charred_tree": "charred_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L439 | neighbors=[sky_props.py] | lang=en
- "skyrise_sky_props_lava_pool": "lava_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L428 | neighbors=[sky_props.py] | lang=en
- "skyrise_sky_props_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L294 | neighbors=[sky_props.py] | lang=en
- "skyrise_sky_props_mesa_rock": "mesa_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L392 | neighbors=[sky_props.py] | lang=en
- "skyrise_sky_props_path_stone": "path_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L152 | neighbors=[sky_props.py] | lang=en
- "skyrise_sky_props_rationale_250": "sell station: glowing pad with a giant coin on a stand behind it (front -Z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L250 | neighbors=[sell_pad()] | lang=en
- "skyrise_sky_props_rationale_509": "glowing zig-zag crack in the ground (flat, walk-over)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L509 | neighbors=[lava_crack()] | lang=en
- "skyrise_sky_props_signpost": "signpost()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L457 | neighbors=[sky_props.py] | lang=en
- "src_asset_store_acquire": "acquire()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L199 | neighbors=[asset_store.cpp] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-184.json

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
