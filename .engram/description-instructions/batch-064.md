# Node Description Batch 65 of 208

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

- "candyland_candy_props_closed_torus": "closed_torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L124 | neighbors=[candy_props.py, explicitly closed torus grid (no seam).…, torus()]
- "candyland_candy_props_gable_roof_bars": "gable_roof_bars()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L330 | neighbors=[candy_props.py, roof of chocolate-bar tiles on both slo…, sweet_shop()]
- "candyland_candy_props_jelly_bean": "jelly_bean()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1063 | neighbors=[candy_props.py, jelly_beans(), a bean: tube along a gentle arc with ro…]
- "candyland_candy_props_jelly_beans": "jelly_beans()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1072 | neighbors=[candy_props.py, jelly_bean(), rock' scatter: a heap of 6-9 glossy jel…]
- "candyland_candy_props_macaron_stack": "macaron_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1165 | neighbors=[candy_props.py, lathe(), 3-4 big macarons stacked a little askew…]
- "candyland_candy_props_orient": "orient()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L54 | neighbors=[candy_props.py, cupcake_liner(), flip faces so normals point away from t…]
- "candyland_candy_props_preview_mats": "preview_mats()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1210 | neighbors=[candy_props.py, _pmat(), assign each face of a palette mesh the …]
- "candyland_candy_props_sprinkle": "sprinkle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L195 | neighbors=[candy_props.py, one rod sprinkle (open-ended 5-sided ro…, sprinkles_on()]
- "candyland_candy_studio": "candy_studio.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_studio.py:L1 | neighbors=[_wrapped(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "candyland_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/hooks_lua.py:L1 | neighbors=[lua_attrs(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "canyonbazaar_canyon_map_dcx": "dcx()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L31 | neighbors=[canyon_map.py, cx(), set_pieces()]
- "canyonbazaar_canyon_map_edge_rhythm": "edge_rhythm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L405 | neighbors=[canyon_map.py, build(), parapet niches along the canyon foot ro…]
- "canyonbazaar_canyon_map_stones": "_stones()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L243 | neighbors=[canyon_map.py, paving(), rows = [(left0, right0, left1, right1)]…]
- "canyonbazaar_canyon_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L22 | neighbors=[canyon_map.py, place(), static()]
- "canyonbazaar_canyon_map_world": "world()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L166 | neighbors=[canyon_map.py, local prop point -> world (Roblox), sam…, set_pieces()]
- "canyonbazaar_canyon_props_carved_stair": "carved_stair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L452 | neighbors=[canyon_props.py, brass_lantern(), stair carved into the canyon wall: sand…]
- "canyonbazaar_canyon_props_fruit_pile": "fruit_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L116 | neighbors=[canyon_props.py, wicker basket heaped with fruit, stall()]
- "canyonbazaar_canyon_props_goods_pots": "goods_pots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L110 | neighbors=[canyon_props.py, pot(), stall()]
- "canyonbazaar_canyon_props_lantern_post": "lantern_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L292 | neighbors=[canyon_props.py, brass_lantern(), street lantern: sandstone base, timber …]
- "canyonbazaar_canyon_props_market_gate": "market_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L716 | neighbors=[canyon_props.py, brass_lantern(), horseshoe-arch gate over the street: as…]
- "canyonbazaar_canyon_props_parapet_niche": "parapet_niche()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L271 | neighbors=[canyon_props.py, brass_lantern(), SIGNATURE: low sandstone wall module (a…]
- "canyonbazaar_canyon_props_shade_sail": "shade_sail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L179 | neighbors=[canyon_props.py, street shade: two pairs of tall palm-ti…, cloth_sheet()]
- "canyonbazaar_canyon_props_sun_temple": "sun_temple()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L755 | neighbors=[canyon_props.py, HERO: Temple of the Setting Sun, a rock…, brass_lantern()]
- "cavemap_cave_map_build_solid": "build_solid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L214 | neighbors=[cave_map.py, build(), bvh_of()]
- "cavemap_cave_map_clip_fail": "clip_fail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L223 | neighbors=[cave_map.py, inside(), place_soft()]
- "cavemap_cave_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L188 | neighbors=[cave_map.py, landmarks(), mine_sets()]
- "cavemap_cave_map_placed_mb": "placed_mb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L191 | neighbors=[cave_map.py, rails(), copy a prop part (Roblox-space MB) to i…]
- "cavemap_cave_map_shapes": "shapes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L56 | neighbors=[cave_map.py, list of ellipsoids (centre, radii) whos…, sky_at()]
- "cavemap_cave_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L23 | neighbors=[cave_map.py, place(), static()]
- "cavemap_cave_map_validate": "validate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L838 | neighbors=[cave_map.py, build(), free()]
- "cavemap_cave_ores_lump": "_lump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L16 | neighbors=[cave_ores.py, ore_lump(), angular broken-rock lump: a hull of few…]
- "cavemap_cave_ores_pickaxe": "pickaxe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L101 | neighbors=[cave_ores.py, ore_pile(), pick resting with its head on the groun…]
- "cavemap_cave_ores_shovel": "shovel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L86 | neighbors=[cave_ores.py, ore_pile(), square-mouth shovel: dished steel blade…]
- "cavemap_cave_paint": "cave_paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_paint.py:L1 | neighbors=[block(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "cavemap_cave_props_crystal": "crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L135 | neighbors=[cave_props.py, add_crystal(), banded crystal column: chamfered octago…]
- "cavemap_cave_props_drip_profile": "drip_profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L201 | neighbors=[cave_props.py, stalactite lathe profile (r, y) from th…, stalactite()]
- "cavemap_cave_props_flowstone_curtain": "flowstone_curtain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L226 | neighbors=[cave_props.py, V(), flowstone drapery hanging from the ceil…]
- "cavemap_cave_props_lake_glow": "lake_glow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L465 | neighbors=[cave_props.py, strata_mass(), flat rounded glowing stones for the lak…]
- "cavemap_cave_props_moss_cap": "moss_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L112 | neighbors=[cave_props.py, thick moss shell over the up-facing par…, rock_layered()]
- "cavemap_cave_props2_rail_seg": "rail_seg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L45 | neighbors=[cave_props2.py, W(), 6-stud track: two I-profile rails on 3 …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-064.json

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
