# Node Description Batch 34 of 207

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

- "creaturelab_lab_props_berry_baskets": "berry_baskets()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L405 | neighbors=[lab_props.py, ball(), rbox(), .add(), tiered birch crate stand with three wov…]
- "creaturelab_lab_props_capsule_statue": "capsule_statue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1188 | neighbors=[lab_props.py, capsule(), rbox(), .add(), plaza fountain: round two-step basin (w…]
- "creaturelab_lab_props_cradle": "cradle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L144 | neighbors=[lab_props.py, capsule(), .add(), heal_machine(), capsule cradle slot: steel cup, glowing…]
- "creaturelab_lab_props_display_rack": "display_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L422 | neighbors=[lab_props.py, capsule(), rbox(), .add(), round three-tier display rack: steel po…]
- "creaturelab_lab_props_ext_bench": "ext_bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1115 | neighbors=[lab_props.py, rbox(), .add(), upright(), park bench: white cast ends with round …]
- "creaturelab_lab_props_floor_mat": "floor_mat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1698 | neighbors=[lab_props.py, emblem(), rbox(), .add(), reception mat: rounded rectangle with a…]
- "creaturelab_lab_props_hanging_planter": "hanging_planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1450 | neighbors=[lab_props.py, ball(), leaf_cluster(), .add(), hanging planter (origin = ceiling point…]
- "creaturelab_lab_props_microscope_bench": "microscope_bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L668 | neighbors=[lab_props.py, lab_table(), rbox(), .add(), small lab table with a modelled microsc…]
- "creaturelab_lab_props_monstera": "monstera()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1413 | neighbors=[lab_props.py, lerp(), pot(), .add(), monstera in a footed pot: 7 big split l…]
- "creaturelab_lab_props_round_planter": "round_planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1068 | neighbors=[lab_props.py, round white planter with a mint band + …, merge_prop(), round_bush(), .add()]
- "creaturelab_lab_props_sale_stand": "sale_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1630 | neighbors=[lab_props.py, Shop story: A-frame sidewalk stand with…, capsule(), rbox(), .add()]
- "creaturelab_lab_props_skel_grow": ".grow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1945 | neighbors=[fiddle_fig(), park_tree(), Skel, lerp(), .add()]
- "creaturelab_lab_props_skin_mesh": "skin_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1922 | neighbors=[lab_props.py, fiddle_fig(), olive_tree(), park_tree(), branching skeleton -> one smooth trunk …]
- "creaturelab_lab_props_starter_table": "starter_table()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L715 | neighbors=[lab_props.py, starter-capsule table: round white pede…, capsule(), rbox(), .add()]
- "creaturelab_lab_props_topiary_hedge": "topiary_hedge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1501 | neighbors=[lab_props.py, clipped hedge with a smooth rounded pro…, ball(), rbox(), .add()]
- "creaturelab_lab_props_wing_trim": "wing_trim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1347 | neighbors=[lab_props.py, lab wing interior trim + ceiling beams …, rbox(), ring_seg(), .add()]
- "creaturelab_lab_props_wood_sh": "wood_sh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1952 | neighbors=[lab_props.py, fiddle_fig(), olive_tree(), park_tree(), lerp()]
- "device_opengles_clear_backend": "opengles_clear_backend.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_backend.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), initialize(), OpenGLESClearBackend, shutdown()]
- "device_opengles_clear_demo": "opengles_clear_demo.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, FailingPrimaryBackend, linear_to_srgb_byte(), main(), report_pixel()]
- "device_vulkan_imgui_pass": "vulkan_imgui_pass.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, draw(), Impl(), VulkanDiagnostics, VulkanImGuiPass()]
- "dunedesert_dune_map_dig_spots": "dig_spots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L467 | neighbors=[dune_map.py, build(), anchor(), place(), reserve()]
- "dunedesert_dune_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L301 | neighbors=[dune_map.py, build(), H(), static(), distant tiered mesas + buttes far outsi…]
- "dunedesert_dune_map_paving": "paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L322 | neighbors=[dune_map.py, build(), H(), static(), worn flagstone slabs over the city + th…]
- "dunedesert_dune_paint": "dune_paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _hex(), paint_block(), remap()]
- "dunedesert_dune_props_block_wall": "block_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L114 | neighbors=[dune_props.py, wall of REAL bevelled blocks through th…, ruin_house(), ruin_wall(), sunken_temple()]
- "dunedesert_dune_props_camel": "camel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L655 | neighbors=[dune_props.py, sheet(), uvsphere(), V(), stylised camel (smooth hide): ellipsoid…]
- "dunedesert_dune_props_column": "column()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L137 | neighbors=[dune_props.py, column_set(), square base + torus, drummed 10-sided s…, step_pyramid(), sunken_temple()]
- "dunedesert_dune_props_grid_quad": "grid_quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L70 | neighbors=[dune_props.py, lerp(), flat top split into ~cell faces (the at…, ruin_house(), step_pyramid()]
- "dunedesert_dune_props_obelisk_stump": "obelisk_stump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L406 | neighbors=[dune_props.py, merge_into(), plinth(), _shaft(), sun_relief()]
- "dunedesert_dune_props_plinth": "plinth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L129 | neighbors=[dune_props.py, obelisk(), obelisk_stump(), quest_stele(), SHARED BASE: stepped sandstone plinth, …]
- "dunedesert_dune_props_quest_stele": "quest_stele()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L459 | neighbors=[dune_props.py, frustum(), plinth(), sun_relief(), QUEST stand: tall carved tablet on the …]
- "dunedesert_dune_props_rolled_rug": "rolled_rug()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L566 | neighbors=[dune_props.py, cargo_pile(), lerp(), sleep_tent(), trader_tent()]
- "dunedesert_dune_props_ruin_house": "ruin_house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L301 | neighbors=[dune_props.py, corner of a roofless house: two block w…, block_wall(), grid_quad(), merge_into()]
- "dunedesert_dune_props_sack": "sack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L560 | neighbors=[dune_props.py, cargo_pile(), uvsphere(), V(), trader_tent()]
- "dunedesert_dune_props_sheet": "sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L527 | neighbors=[dune_props.py, camel(), a cloth sheet over a parametric surface…, sleep_tent(), trader_tent()]
- "dunedesert_dune_props_treasure_mound": "treasure_mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L813 | neighbors=[dune_props.py, DIG SPOT anchors: tier 1 a low sand mou…, uvsphere(), V(), waystone_body()]
- "dunedesert_dune_props_wyrm_rib": "wyrm_rib()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L939 | neighbors=[dune_props.py, one segment of the wyrm's spine lying b…, lerp(), uvsphere(), V()]
- "dunedesert_dune_props_wyrm_skull": "wyrm_skull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L908 | neighbors=[dune_props.py, giant sand-wyrm skull lying jaw-open in…, lerp(), uvsphere(), V()]
- "dunedesert_dune_props_zig_band": "zig_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L105 | neighbors=[dune_props.py, pylon_gate(), raised zigzag band between two rails (c…, step_pyramid(), sunken_temple()]
- "dunedesert_gen_trees_with_palms_bark_fir": "bark_fir()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L100 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp(), fir / spruce: scaly grey-brown plates w…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-033.json

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
