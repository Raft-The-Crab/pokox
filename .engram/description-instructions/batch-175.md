# Node Description Batch 176 of 208

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
- "plusspeed_plus_props_treadmill": "treadmill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L253 | neighbors=[plus_props.py]
- "plusspeed_plus_props_voxel_tree": "voxel_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L28 | neighbors=[plus_props.py]
- "plusspeed_plus_props_wins_pad": "wins_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L234 | neighbors=[plus_props.py]
- "preserved_preserve_r6_rationale_1": "Preservation-first R6 export. Never overwrites source or prior outputs.  Blender" | kind=entity | source=assets/characters/preserved/preserve_r6.py:L1 | neighbors=[preserve_r6.py]
- "preserved_preview_face_glb_point_at": "point_at()" | kind=code-symbol | source=assets/characters/preserved/preview_face_glb.py:L38 | neighbors=[preview_face_glb.py]
- "preserved_verify_roundtrip_rationale_1": "Read-only Blender GLB round-trip check. Run in a separate background process.  b" | kind=entity | source=assets/characters/preserved/verify_roundtrip.py:L1 | neighbors=[verify_roundtrip.py]
- "program_program_assemble_program_bytecode": "assemble_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L363 | neighbors=[program.cpp]
- "program_program_disassemble_program_bytecode": "disassemble_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L359 | neighbors=[program.cpp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-175.json

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
