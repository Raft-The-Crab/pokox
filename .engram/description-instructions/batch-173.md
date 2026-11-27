# Node Description Batch 174 of 207

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

- "physics_visual_solver_visualsolver": "VisualSolver" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L61 | neighbors=[visual_solver.hpp]
- "physics_visual_solver_visualworld": "VisualWorld" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L106 | neighbors=[visual_solver.hpp]
- "pi_test_pi_extension_dirname": "__dirname" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L8 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_emit": "emit()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L39 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_extensionpath": "extensionPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L11 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_firsthandler": "firstHandler()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L31 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_loadextension": "loadExtension()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L18 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_packagejsonpath": "packageJsonPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L10 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_pitoolspath": "piToolsPath" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L12 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_readpackagejson": "readPackageJson()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L14 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_reporoot": "repoRoot" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L9 | neighbors=[test-pi-extension.mjs]
- "pi_test_pi_extension_textof": "textOf()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L45 | neighbors=[test-pi-extension.mjs]
- "platform_i_platform": "i_platform.hpp" | kind=code-symbol | source=engine/platform/include/poko/platform/i_platform.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "platform_sdl_platform": "sdl_platform.hpp" | kind=code-symbol | source=engine/platform/include/poko/platform/sdl_platform.hpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …]
- "plugins_superpowers_bootstrapcache": "_bootstrapCache" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L114 | neighbors=[superpowers.js]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-173.json

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
