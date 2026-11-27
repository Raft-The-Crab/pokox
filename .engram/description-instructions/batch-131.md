# Node Description Batch 132 of 209

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

- "shared_bpyx_node": "node()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L99 | neighbors=[_bpyx.py, First node of `type_` (e.g. 'BSDF_PRINC…]
- "shared_bpyx_object_mode": "object_mode()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L83 | neighbors=[_bpyx.py, Leave edit/sculpt/pose modes; most data…]
- "shared_bpyx_objects": "objects()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L71 | neighbors=[_bpyx.py, Resolve names -> objects. No names: sel…]
- "shared_bpyx_parser": "parser()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L41 | neighbors=[_bpyx.py, ArgumentParser whose help is the script…]
- "shared_bpyx_r": "r()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L132 | neighbors=[_bpyx.py, Round a float or a vector for compact J…]
- "shared_bpyx_select_only": "select_only()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L90 | neighbors=[_bpyx.py, Select exactly `objs` and make `active`…]
- "shared_bpyx_set_enum": "set_enum()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L109 | neighbors=[_bpyx.py, Assign an enum; on failure raise listin…]
- "skyrise_sky_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L76 | neighbors=[sky_map.py, place()]
- "skyrise_sky_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L388 | neighbors=[sky_map.py, free()]
- "skyrise_sky_map_maker": "maker()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L268 | neighbors=[sky_map.py, zone_island()]
- "skyrise_sky_map_path_dist": "path_dist()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L125 | neighbors=[sky_map.py, micro_detail()]
- "skyrise_sky_map_rationale_182": "stepping-stone path from the entry bridge end through the island middle to the e" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L182 | neighbors=[MB, winding_path()]
- "skyrise_sky_map_rationale_244": "dress the outer ring of island i, keeping bridge heads, gates and stations clear" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L244 | neighbors=[MB, rim_dress()]
- "skyrise_sky_map_rationale_316": "trodden track under the stepping stones: overlapping irregular flat blobs follow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L316 | neighbors=[MB, path_track()]
- "skyrise_sky_map_rationale_333": "clumps of small ground detail: off paths, bridge heads, stations (free()), and t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L333 | neighbors=[MB, micro_detail()]
- "skyrise_sky_map_rationale_38": "index of the island whose rim (minus margin m) contains (x, z), else None" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L38 | neighbors=[MB, island_at()]
- "skyrise_sky_map_rationale_86": "height of the built island top MESH (what players stand on); H before the tops e" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L86 | neighbors=[MB, Hm()]
- "skyrise_sky_map_segd": "segd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L64 | neighbors=[sky_map.py, on_bridge_line()]
- "skyrise_sky_models_bevel_box": "bevel_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L18 | neighbors=[sky_models.py, zone_gate()]
- "skyrise_sky_models_blossom_tree": "blossom_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L72 | neighbors=[sky_models.py, puffy_tree()]
- "skyrise_sky_models_snow_tree": "snow_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L75 | neighbors=[sky_models.py, pine: 4 star tiers with drooping snow c…]
- "skyrise_sky_models2_basalt_rocks": "basalt_rocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L132 | neighbors=[sky_models2.py, hexagonal basalt columns of stepped hei…]
- "skyrise_sky_models2_bottle": "bottle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L12 | neighbors=[sky_models2.py, upgrade_stand()]
- "skyrise_sky_models2_crystal_node": "crystal_node()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L72 | neighbors=[sky_models2.py, 6-9 hexagonal crystals with pointed tip…]
- "skyrise_sky_models2_egg_shrine": "egg_shrine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L151 | neighbors=[sky_models2.py, egg hatch altar: 3-tier dais with gold …]
- "skyrise_sky_models2_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L253 | neighbors=[sky_models2.py, stone frame with side columns and a gem…]
- "skyrise_sky_models2_teleport_pad": "teleport_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L280 | neighbors=[sky_models2.py, stepped round platform with inlaid glow…]
- "skyrise_sky_models3_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L62 | neighbors=[sky_models3.py, lumpy faceted bush: 4-6 clumps, lighter…]
- "skyrise_sky_models3_charred_tree": "charred_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L43 | neighbors=[sky_models3.py, burnt tree: thick twisting trunk with 4…]
- "skyrise_sky_models3_lamp_post": "lamp_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L76 | neighbors=[sky_models3.py, iron street lantern: stepped stone base…]
- "skyrise_sky_models3_lava_pool": "lava_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L28 | neighbors=[sky_models3.py, molten pool: ring of basalt boulders, g…]
- "skyrise_sky_models3_mesa_rock": "mesa_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L8 | neighbors=[sky_models3.py, sandstone butte: 3 eroded faceted tiers…]
- "skyrise_sky_models3_signpost": "signpost()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models3.py:L92 | neighbors=[sky_models3.py, zone signpost: planked arrow board with…]
- "skyrise_sky_models4_bridge": "bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L113 | neighbors=[sky_models4.py, bridge from z=0 to z=-L rising by `rise…]
- "skyrise_sky_models4_dry_shrub": "dry_shrub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L68 | neighbors=[sky_models4.py, twiggy desert shrub: forked twigs from …]
- "skyrise_sky_models4_dune_grass": "dune_grass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L65 | neighbors=[sky_models4.py, grass_tuft()]
- "skyrise_sky_models4_mushrooms": "mushrooms()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L51 | neighbors=[sky_models4.py, two or three toadstools: lathe stems, r…]
- "skyrise_sky_models4_plaza_fountain": "plaza_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L181 | neighbors=[sky_models4.py, low tiered fountain: octagonal stone ba…]
- "skyrise_sky_models4_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L18 | neighbors=[sky_models4.py, wildflowers()]
- "skyrise_sky_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L449 | neighbors=[sky_props.py, sphere()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-131.json

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
