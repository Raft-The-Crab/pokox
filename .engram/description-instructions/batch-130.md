# Node Description Batch 131 of 208

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

- "shared_bpyx_set_enum": "set_enum()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L109 | neighbors=[_bpyx.py, Assign an enum; on failure raise listin…] | lang=en
- "skyrise_sky_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L76 | neighbors=[sky_map.py, place()] | lang=en
- "skyrise_sky_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L388 | neighbors=[sky_map.py, free()] | lang=en
- "skyrise_sky_map_maker": "maker()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L268 | neighbors=[sky_map.py, zone_island()] | lang=en
- "skyrise_sky_map_path_dist": "path_dist()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L125 | neighbors=[sky_map.py, micro_detail()] | lang=en
- "skyrise_sky_map_rationale_182": "stepping-stone path from the entry bridge end through the island middle to the e" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L182 | neighbors=[MB, winding_path()] | lang=en
- "skyrise_sky_map_rationale_244": "dress the outer ring of island i, keeping bridge heads, gates and stations clear" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L244 | neighbors=[MB, rim_dress()] | lang=en
- "skyrise_sky_map_rationale_316": "trodden track under the stepping stones: overlapping irregular flat blobs follow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L316 | neighbors=[MB, path_track()] | lang=en
- "skyrise_sky_map_rationale_333": "clumps of small ground detail: off paths, bridge heads, stations (free()), and t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L333 | neighbors=[MB, micro_detail()] | lang=en
- "skyrise_sky_map_rationale_38": "index of the island whose rim (minus margin m) contains (x, z), else None" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L38 | neighbors=[MB, island_at()] | lang=en
- "skyrise_sky_map_rationale_86": "height of the built island top MESH (what players stand on); H before the tops e" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L86 | neighbors=[MB, Hm()] | lang=en
- "skyrise_sky_map_segd": "segd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L64 | neighbors=[sky_map.py, on_bridge_line()] | lang=en
- "skyrise_sky_models_bevel_box": "bevel_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L18 | neighbors=[sky_models.py, zone_gate()] | lang=en
- "skyrise_sky_models_blossom_tree": "blossom_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L72 | neighbors=[sky_models.py, puffy_tree()] | lang=en
- "skyrise_sky_models_snow_tree": "snow_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L75 | neighbors=[sky_models.py, pine: 4 star tiers with drooping snow c…] | lang=en
- "skyrise_sky_models2_basalt_rocks": "basalt_rocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L132 | neighbors=[sky_models2.py, hexagonal basalt columns of stepped hei…] | lang=en
- "skyrise_sky_models2_bottle": "bottle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L12 | neighbors=[sky_models2.py, upgrade_stand()] | lang=en
- "skyrise_sky_models2_crystal_node": "crystal_node()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L72 | neighbors=[sky_models2.py, 6-9 hexagonal crystals with pointed tip…] | lang=en
- "skyrise_sky_models2_egg_shrine": "egg_shrine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L151 | neighbors=[sky_models2.py, egg hatch altar: 3-tier dais with gold …] | lang=en
- "skyrise_sky_models2_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L253 | neighbors=[sky_models2.py, stone frame with side columns and a gem…] | lang=en
- "skyrise_sky_models2_teleport_pad": "teleport_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L280 | neighbors=[sky_models2.py, stepped round platform with inlaid glow…] | lang=en
- "skyrise_sky_models3_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L62 | neighbors=[sky_models3.py, lumpy faceted bush: 4-6 clumps, lighter…] | lang=en
- "skyrise_sky_models3_charred_tree": "charred_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L43 | neighbors=[sky_models3.py, burnt tree: thick twisting trunk with 4…] | lang=en
- "skyrise_sky_models3_lamp_post": "lamp_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L76 | neighbors=[sky_models3.py, iron street lantern: stepped stone base…] | lang=en
- "skyrise_sky_models3_lava_pool": "lava_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L28 | neighbors=[sky_models3.py, molten pool: ring of basalt boulders, g…] | lang=en
- "skyrise_sky_models3_mesa_rock": "mesa_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L8 | neighbors=[sky_models3.py, sandstone butte: 3 eroded faceted tiers…] | lang=en
- "skyrise_sky_models3_signpost": "signpost()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L92 | neighbors=[sky_models3.py, zone signpost: planked arrow board with…] | lang=en
- "skyrise_sky_models4_bridge": "bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L113 | neighbors=[sky_models4.py, bridge from z=0 to z=-L rising by `rise…] | lang=en
- "skyrise_sky_models4_dry_shrub": "dry_shrub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L68 | neighbors=[sky_models4.py, twiggy desert shrub: forked twigs from …] | lang=en
- "skyrise_sky_models4_dune_grass": "dune_grass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L65 | neighbors=[sky_models4.py, grass_tuft()] | lang=en
- "skyrise_sky_models4_mushrooms": "mushrooms()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L51 | neighbors=[sky_models4.py, two or three toadstools: lathe stems, r…] | lang=en
- "skyrise_sky_models4_plaza_fountain": "plaza_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L181 | neighbors=[sky_models4.py, low tiered fountain: octagonal stone ba…] | lang=en
- "skyrise_sky_models4_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L18 | neighbors=[sky_models4.py, wildflowers()] | lang=en
- "skyrise_sky_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L449 | neighbors=[sky_props.py, sphere()] | lang=en
- "skyrise_sky_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L143 | neighbors=[sky_props.py, sphere()] | lang=en
- "skyrise_sky_props_crystal_node": "crystal_node()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L367 | neighbors=[sky_props.py, lathe()] | lang=en
- "skyrise_sky_props_ice_spike": "ice_spike()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L400 | neighbors=[sky_props.py, lathe()] | lang=en
- "skyrise_sky_props_lamp_post": "lamp_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L306 | neighbors=[sky_props.py, sphere()] | lang=en
- "skyrise_sky_props_lava_crack": "lava_crack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L508 | neighbors=[sky_props.py, glowing zig-zag crack in the ground (fl…] | lang=en
- "skyrise_sky_props_rationale_133": "small decorative sky rock: grass cap, rock cone, maybe a tiny tree" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L133 | neighbors=[Palette, floating_rock()] | lang=pt

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-130.json

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
