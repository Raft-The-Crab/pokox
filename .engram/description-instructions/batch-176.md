# Node Description Batch 177 of 209

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

- "plugins_superpowers_childsessioncache": "_childSessionCache" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L169 | neighbors=[superpowers.js]
- "plugins_superpowers_dirname": "__dirname" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L23 | neighbors=[superpowers.js]
- "plugins_superpowers_superpowersplugin": "SuperpowersPlugin()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L224 | neighbors=[superpowers.js]
- "plugins_superpowers_superpowersskillsdir": "superpowersSkillsDir" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L26 | neighbors=[superpowers.js]
- "plusspeed_plus_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L223 | neighbors=[plus_map.py]
- "plusspeed_plus_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L247 | neighbors=[plus_map.py]
- "plusspeed_plus_props_asteroid": "asteroid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L183 | neighbors=[plus_props.py]
- "plusspeed_plus_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L68 | neighbors=[plus_props.py]
- "plusspeed_plus_props_cactus": "cactus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L86 | neighbors=[plus_props.py]
- "plusspeed_plus_props_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L112 | neighbors=[plus_props.py]
- "plusspeed_plus_props_city_tower": "city_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L158 | neighbors=[plus_props.py]
- "plusspeed_plus_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L193 | neighbors=[plus_props.py]
- "plusspeed_plus_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L199 | neighbors=[plus_props.py]
- "plusspeed_plus_props_dist_board": "dist_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L246 | neighbors=[plus_props.py]
- "plusspeed_plus_props_fence": "fence()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L204 | neighbors=[plus_props.py]
- "plusspeed_plus_props_fix_big_arch": "big_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L78 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_fix_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L53 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_fix_lava_rock": "lava_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L33 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_fix_palm": "palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L16 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_fix_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L6 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_fix_planet": "planet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L45 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_fix_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L62 | neighbors=[plus_props_fix.py]
- "plusspeed_plus_props_flowers": "flowers()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L77 | neighbors=[plus_props.py]
- "plusspeed_plus_props_gumdrop": "gumdrop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L119 | neighbors=[plus_props.py]
- "plusspeed_plus_props_hatchery": "hatchery()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L265 | neighbors=[plus_props.py]
- "plusspeed_plus_props_ice_crystal": "ice_crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L133 | neighbors=[plus_props.py]
- "plusspeed_plus_props_lava_rock": "lava_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L140 | neighbors=[plus_props.py]
- "plusspeed_plus_props_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L306 | neighbors=[plus_props.py]
- "plusspeed_plus_props_lollipop": "lollipop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L105 | neighbors=[plus_props.py]
- "plusspeed_plus_props_mesa": "mesa()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L97 | neighbors=[plus_props.py]
- "plusspeed_plus_props_mini_volcano": "mini_volcano()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L149 | neighbors=[plus_props.py]
- "plusspeed_plus_props_neon_sign": "neon_sign()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L169 | neighbors=[plus_props.py]
- "plusspeed_plus_props_palm": "palm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L53 | neighbors=[plus_props.py]
- "plusspeed_plus_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L43 | neighbors=[plus_props.py]
- "plusspeed_plus_props_planet": "planet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L177 | neighbors=[plus_props.py]
- "plusspeed_plus_props_rebirth_altar": "rebirth_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L296 | neighbors=[plus_props.py]
- "plusspeed_plus_props_shop_stall": "shop_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L283 | neighbors=[plus_props.py]
- "plusspeed_plus_props_snowman": "snowman()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L124 | neighbors=[plus_props.py]
- "plusspeed_plus_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L317 | neighbors=[plus_props.py]
- "plusspeed_plus_props_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L189 | neighbors=[plus_props.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-176.json

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
