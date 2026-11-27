# Node Description Batch 163 of 209

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

- "cavemap_cave_props3_rationale_164": "stone ring, teepee logs, flame tongues + embers (glow), a spit on Y-sticks with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L164 | neighbors=[campfire_pit()] | lang=en
- "cavemap_cave_props3_rationale_185": "notice board: two posts on stone feet, plank board with a frame, a little shingl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L185 | neighbors=[quest_board()] | lang=pt
- "cavemap_cave_props3_rationale_205": "split-log bench on two chunk feet" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L205 | neighbors=[log_seat()] | lang=en
- "cavemap_cave_props3_rationale_214": "DEEP-DIVE ELEVATOR: timber headframe (two leaning A-frames with ties + braces) c" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L214 | neighbors=[deep_lift()] | lang=en
- "cavemap_cave_props3_rationale_26": "ORE EXCHANGE: a timber mine-office shed on a plank deck with log sills: board wa" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L26 | neighbors=[mine_shop()] | lang=pt
- "cavemap_cave_props3_rationale_269": "SPORE BREWERY: a stone hearth under a fat iron cauldron of glowing brew, small f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L269 | neighbors=[brew_station()] | lang=pt
- "cavemap_cave_props3_rationale_298": "spawn platform: layered round stone plinth (sloped lip, walkable), slab ring on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L298 | neighbors=[spawn_dais()] | lang=en
- "cavemap_cave_props3_rationale_318": "waterfall from a ceiling crack (origin = bottom centre at the lake surface, wall" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L318 | neighbors=[cave_falls()] | lang=en
- "cavemap_cave_props3_rationale_354": "shallow puddle on the floor: a flat irregular water film with a lit rim + a few" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L354 | neighbors=[glow_puddle()] | lang=pt
- "cavemap_cave_props3_rationale_365": "glow-worm colony on the vault (origin at the top, hangs): fine silk threads of d" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L365 | neighbors=[glow_worms()] | lang=en
- "cavemap_cave_props3_rationale_376": "ring round the top of the sun shaft (origin = ring centre at the rim height): la" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L376 | neighbors=[skylight_lip()] | lang=en
- "cavemap_cave_props3_rationale_392": "THE GLOWROOT (hero): an ancient root mass that grew down from the vault to the l" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L392 | neighbors=[glowroot()] | lang=en
- "cavemap_cave_props3_rationale_7": "a wall of vertical boards between x0..x1 (y0..y1) at depth z, rotated by yaw abo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L7 | neighbors=[boards()] | lang=en
- "cavemap_cave_props3_rationale_79": "CRYSTAL FORGE: an ashlar beehive kiln with a glowing arched mouth and a banded s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L79 | neighbors=[crystal_forge()] | lang=en
- "cavemap_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/hooks_lua.py:L6 | neighbors=[hooks_lua.py] | lang=en
- "cavemap_palette_sheet_rgb": "rgb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/palette_sheet.py:L9 | neighbors=[palette_sheet.py] | lang=en
- "cavemap_post_export_kind": "kind()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/post_export.py:L11 | neighbors=[post_export.py] | lang=en
- "console_console_clear": "clear()" | kind=code-symbol | source=mute/src/console/console.cpp:L193 | neighbors=[console.cpp] | lang=en
- "console_console_console_input_full": "console_input_full()" | kind=code-symbol | source=mute/src/console/console.cpp:L117 | neighbors=[console.cpp] | lang=en
- "creaturelab_lab_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L577 | neighbors=[lab_map.py] | lang=en
- "creaturelab_lab_map_material_skin": "material_skin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L615 | neighbors=[lab_map.py] | lang=en
- "creaturelab_lab_props_loft": "loft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L59 | neighbors=[lab_props.py] | lang=en
- "creaturelab_lab_props_rationale_1031": "chunky stylised leaf mass: a blob + a few smaller blobs around (canopy, bush)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1031 | neighbors=[leaf_ball()] | lang=pt
- "creaturelab_lab_props_rationale_1141": "low wide pot with arching fern fronds (both sides modelled)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1141 | neighbors=[potted_fern()] | lang=en
- "creaturelab_lab_props_rationale_1245": "flat-bottomed cumulus for the sky (SmoothPlastic white)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1245 | neighbors=[cloud()] | lang=en
- "creaturelab_lab_props_rationale_1766": "water cooler: white cabinet with a sky front, upturned blue water bottle (glass)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1766 | neighbors=[water_cooler()] | lang=en
- "creaturelab_lab_props_rationale_254": "small round pot + leafy sprouts (used on counters, desks)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L254 | neighbors=[pot_plant()] | lang=en
- "creaturelab_lab_props_rationale_471": "two curved arrows chasing each other in a circle (trade icon, a shape)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L471 | neighbors=[swap_icon()] | lang=pt
- "creaturelab_lab_props_rationale_737": "the portal between the hall and the lab wing (fits an 18 wide x 17 tall opening)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L737 | neighbors=[lab_archway()] | lang=en
- "creaturelab_lab_props_skel_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1940 | neighbors=[Skel] | lang=en
- "debug_vulkan_diagnostics_capture": "capture()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L22 | neighbors=[vulkan_diagnostics.cpp] | lang=en
- "debug_vulkan_diagnostics_filter_is_environment_layer_version_warning": "is_environment_layer_version_warning()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics_filter.cpp:L4 | neighbors=[vulkan_diagnostics_filter.cpp] | lang=en
- "debug_vulkan_diagnostics_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L51 | neighbors=[vulkan_diagnostics.cpp] | lang=en
- "debug_vulkan_diagnostics_vulkandiagnostics_vulkandiagnostics": ".VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/debug/vulkan_diagnostics.hpp:L15 | neighbors=[VulkanDiagnostics()] | lang=en
- "device_clear_backend_selection_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L39 | neighbors=[clear_backend_selection.cpp] | lang=en
- "device_clear_backend_selection_clearbackend_clearbackend": ".ClearBackend()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/clear_backend_selection.hpp:L12 | neighbors=[ClearBackend] | lang=en
- "device_clear_backend_selection_clearbackendselection_clearbackendselection": ".ClearBackendSelection()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/clear_backend_selection.hpp:L35 | neighbors=[ClearBackendSelection()] | lang=en
- "device_fallback_clear_backends_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_backends.cpp:L24 | neighbors=[fallback_clear_backends.cpp] | lang=en
- "device_fallback_clear_backends_initialize": "initialize()" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_backends.cpp:L6 | neighbors=[fallback_clear_backends.cpp] | lang=en
- "device_fallback_clear_backends_openglclearbackend_openglclearbackend": ".OpenGLClearBackend()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/fallback_clear_backends.hpp:L30 | neighbors=[OpenGLClearBackend] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-162.json

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
