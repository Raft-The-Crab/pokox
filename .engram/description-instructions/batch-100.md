# Node Description Batch 101 of 207

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

- "cavemap_cave_props_rationale_35": "per-vertex height gradient (a low -> b high) + normal lift + noise: soft painter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L35 | neighbors=[V(), Palette] | lang=pt
- "cavemap_cave_props_rationale_360": "one fungus: S-bent tapering stem with a skirt ring, painted cap, GLOWING gills u" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L360 | neighbors=[mushroom(), Palette] | lang=en
- "cavemap_cave_props_rationale_385": "mossy root mound; glowing spore nodules sit on its foot at ground level (one rin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L385 | neighbors=[mound(), Palette] | lang=en
- "cavemap_cave_props_rationale_399": "three giant cave mushrooms (16 / 11 / 7 tall) from one mossy root mound, caps le" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L399 | neighbors=[glowshroom_giant(), Palette] | lang=en
- "cavemap_cave_props_rationale_415": "a knee-high cluster: 6-8 small mushrooms of mixed cap shapes on a mossy hump" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L415 | neighbors=[glowshroom_cluster(), Palette] | lang=pt
- "cavemap_cave_props_rationale_426": "tiny scatter: thin-stalked glowing bell caps (all glow), ankle high" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L426 | neighbors=[shroom_patch(), Palette] | lang=en
- "cavemap_cave_props_rationale_439": "hanging glow-root: a small root knot under the ceiling, 2-4 twisting root strand" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L439 | neighbors=[glow_vine(), Palette] | lang=en
- "cavemap_cave_props_rationale_466": "flat rounded glowing stones for the lake bed: the turquoise 'glow from below' (N" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L466 | neighbors=[lake_glow(), Palette] | lang=en
- "cavemap_cave_props_rationale_51": "per-vertex convexity: > 0 convex edge (lit rim), < 0 crevice" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L51 | neighbors=[rim_shade(), Palette] | lang=en
- "cavemap_cave_props_rationale_75": "cheap lens / bead (glow spots, bulbs, nodules): ~4n triangles" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L75 | neighbors=[dot(), Palette] | lang=en
- "cavemap_cave_props_rationale_86": "rounded rock built from stacked BEDS: a subdivided cube pushed onto a superellip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L86 | neighbors=[strata_mass(), Palette] | lang=pt
- "cavemap_cave_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L30 | neighbors=[cave_props.py, strata_mass()] | lang=en
- "cavemap_cave_props2_barrels": "barrels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L219 | neighbors=[cave_props2.py, three staved barrels (bulged lathe, iro…] | lang=en
- "cavemap_cave_props2_wheel": "wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L73 | neighbors=[cave_props2.py, mine_cart()] | lang=en
- "cavemap_cave_props3_brew_station": "brew_station()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L268 | neighbors=[cave_props3.py, SPORE BREWERY: a stone hearth under a f…] | lang=en
- "cavemap_cave_props3_camp_tent": "camp_tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L132 | neighbors=[cave_props3.py, A-frame canvas tent: ridge log on X-pol…] | lang=en
- "cavemap_cave_props3_campfire_pit": "campfire_pit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L163 | neighbors=[cave_props3.py, stone ring, teepee logs, flame tongues …] | lang=en
- "cavemap_cave_props3_cave_falls": "cave_falls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L317 | neighbors=[cave_props3.py, waterfall from a ceiling crack (origin …] | lang=en
- "cavemap_cave_props3_crystal_forge": "crystal_forge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L78 | neighbors=[cave_props3.py, CRYSTAL FORGE: an ashlar beehive kiln w…] | lang=en
- "cavemap_cave_props3_deep_lift": "deep_lift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L213 | neighbors=[cave_props3.py, DEEP-DIVE ELEVATOR: timber headframe (t…] | lang=en
- "cavemap_cave_props3_glow_puddle": "glow_puddle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L353 | neighbors=[cave_props3.py, shallow puddle on the floor: a flat irr…] | lang=en
- "cavemap_cave_props3_glow_worms": "glow_worms()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L364 | neighbors=[cave_props3.py, glow-worm colony on the vault (origin a…] | lang=en
- "cavemap_cave_props3_glowroot_check": "glowroot_check()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L454 | neighbors=[cave_props3.py, glowroot()] | lang=en
- "cavemap_cave_props3_log_seat": "log_seat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L204 | neighbors=[cave_props3.py, split-log bench on two chunk feet] | lang=en
- "cavemap_cave_props3_skylight_lip": "skylight_lip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L375 | neighbors=[cave_props3.py, ring round the top of the sun shaft (or…] | lang=en
- "cavemap_cave_props3_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L297 | neighbors=[cave_props3.py, spawn platform: layered round stone pli…] | lang=en
- "cavemap_grid": "grid.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/grid.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "cavemap_post": "post.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/post.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "console_console_decode_string": "decode_string()" | kind=code-symbol | source=mute/src/console/console.cpp:L52 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "console_console_decode_utf8": "decode_utf8()" | kind=code-symbol | source=mute/src/console/console.cpp:L125 | neighbors=[console.cpp, append()] | lang=en
- "console_console_execute_console": "execute_console()" | kind=code-symbol | source=mute/src/console/console.cpp:L115 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "console_console_execute_console_stateful": "execute_console_stateful()" | kind=code-symbol | source=mute/src/console/console.cpp:L116 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "console_console_is_format_control": "is_format_control()" | kind=code-symbol | source=mute/src/console/console.cpp:L147 | neighbors=[console.cpp, append()] | lang=en
- "console_console_rebased": "rebased()" | kind=code-symbol | source=mute/src/console/console.cpp:L20 | neighbors=[console.cpp, numeric()] | lang=en
- "console_console_spelling": "spelling()" | kind=code-symbol | source=mute/src/console/console.cpp:L47 | neighbors=[console.cpp, execute_console_impl()] | lang=en
- "creaturelab_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "creaturelab_lab_map_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L399 | neighbors=[lab_map.py, garden_paths()] | lang=en
- "creaturelab_lab_map_ceil_y": "ceil_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L276 | neighbors=[lab_map.py, underside of the rotunda roof at radius…] | lang=en
- "creaturelab_lab_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L54 | neighbors=[lab_map.py, place()] | lang=en
- "creaturelab_lab_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L73 | neighbors=[lab_map.py, exterior()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-100.json

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
