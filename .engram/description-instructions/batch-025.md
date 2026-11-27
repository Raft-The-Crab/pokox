# Node Description Batch 26 of 208

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

- "creaturelab_lab_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L36 | neighbors=[lab_map.py, garden_paths(), hall_floor(), hardscape(), pond(), wing_floor()]
- "creaturelab_lab_props_arc_wall": "arc_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L796 | neighbors=[lab_props.py, ring_seg(), .add(), lab_wing(), curved wall from angle a0..a1 split int…, rotunda()]
- "creaturelab_lab_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1055 | neighbors=[lab_props.py, ball(), leaf_ball(), rbox(), .add(), rounded bush with a few flower clusters…]
- "creaturelab_lab_props_capsule_shelf": "capsule_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L375 | neighbors=[lab_props.py, capsule(), rbox(), shelf_frame(), .add(), capsule gondola: four shelves of steppe…]
- "creaturelab_lab_props_entrance_canopy": "entrance_canopy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1010 | neighbors=[lab_props.py, emblem_badge(), rbox(), ring_seg(), .add(), curved canopy over the entrance (front …]
- "creaturelab_lab_props_fig_tree": "fig_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1397 | neighbors=[lab_props.py, leaf_cluster(), lerp(), pot(), .add(), indoor fiddle-leaf / round-leaf fig: ta…]
- "creaturelab_lab_props_hall_trim": "hall_trim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1286 | neighbors=[lab_props.py, adeg(), _gap(), ring_seg(), .add(), interior architecture of the hall (no c…]
- "creaturelab_lab_props_lab_archway": "lab_archway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L736 | neighbors=[lab_props.py, emblem_badge(), rbox(), .add(), upright(), the portal between the hall and the lab…]
- "creaturelab_lab_props_lab_table": "lab_table()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L620 | neighbors=[lab_props.py, rbox(), .add(), microscope_bench(), lab table: white top with a teal edge, …, workbench()]
- "creaturelab_lab_props_long_planter": "long_planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1084 | neighbors=[lab_props.py, ball(), leaf_ball(), rbox(), .add(), long planter box (white with a teal kic…]
- "creaturelab_lab_props_potion_shelf": "potion_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L391 | neighbors=[lab_props.py, bottle(), rbox(), shelf_frame(), .add(), potion shelf: flasks, spray tonics, via…]
- "creaturelab_lab_props_rest_nook": "rest_nook()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L765 | neighbors=[lab_props.py, little rest area for recovering creatur…, ball(), pot_plant(), rbox(), .add()]
- "creaturelab_lab_props_rotunda_roof": "rotunda_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L867 | neighbors=[lab_props.py, rotunda roof (no collision, hide it for…, rotunda(), lathe_open(), lerp(), .add()]
- "creaturelab_lab_props_shop_counter": "shop_counter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L339 | neighbors=[lab_props.py, mart counter: white body, coral front p…, capsule(), emblem(), rbox(), .add()]
- "creaturelab_lab_props_specimen_tank": "specimen_tank()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L523 | neighbors=[lab_props.py, specimen tank: steel base drum with a t…, ball(), egg(), rbox(), .add()]
- "creaturelab_lab_props_swap_icon": "swap_icon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L470 | neighbors=[lab_props.py, two curved arrows chasing each other in…, lerp(), .add(), upright(), trade_desk()]
- "creaturelab_lab_props_trophy_shelf": "trophy_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1673 | neighbors=[lab_props.py, Trade story: wall trophy shelf (two bir…, capsule(), rbox(), .add(), upright()]
- "creaturelab_lab_props_vending_machine": "vending_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1165 | neighbors=[lab_props.py, berry-juice vending machine: rounded wh…, bottle(), emblem(), rbox(), .add()]
- "creaturelab_lab_props_wall_capsules": "wall_capsules()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1749 | neighbors=[lab_props.py, wall-mounted capsule display: rounded w…, capsule(), emblem(), rbox(), .add()]
- "creaturelab_lab_props_wing_roof": "wing_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L947 | neighbors=[lab_props.py, lab wing roof (no collision; hide it fo…, rbox(), ring_seg(), .add(), upright()]
- "creaturelab_lab_props_workbench": "workbench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L636 | neighbors=[lab_props.py, lab workbench: table + test-tube rack w…, ball(), lab_table(), rbox(), .add()]
- "device_opengles_clear_backend": "opengles_clear_backend.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_backend.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, clear_and_present(), initialize(), OpenGLESClearBackend, shutdown(), c7a411f Fix MUT-01-20 audit defects in …]
- "device_opengles_clear_demo": "opengles_clear_demo.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_demo.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, FailingPrimaryBackend, linear_to_srgb_byte(), main(), report_pixel(), c7a411f Fix MUT-01-20 audit defects in …]
- "device_vulkan_imgui_pass": "vulkan_imgui_pass.cpp" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, draw(), Impl(), VulkanDiagnostics, VulkanImGuiPass(), c7a411f Fix MUT-01-20 audit defects in …]
- "dunedesert_dune_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L263 | neighbors=[dune_map.py, build(), build_solid(), clip_fail(), place(), unplace()]
- "dunedesert_dune_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L168 | neighbors=[dune_map.py, ground(), horizon(), paving(), add_owner(), sub()]
- "dunedesert_dune_props_cargo_pile": "cargo_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L744 | neighbors=[dune_props.py, crate(), jar(), rolled_rug(), sack(), caravan cargo: crates stacked, sacks, r…]
- "dunedesert_dune_props_obelisk": "obelisk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L380 | neighbors=[dune_props.py, frustum(), merge_into(), plinth(), _shaft(), standing obelisk on the stepped plinth:…]
- "dunedesert_dune_props_obelisk_fallen": "obelisk_fallen()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L389 | neighbors=[dune_props.py, frustum(), lerp(), merge_into(), _shaft(), toppled obelisk piece lying on its side…]
- "dunedesert_dune_props_pylon_gate": "pylon_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L236 | neighbors=[dune_props.py, frustum(), lerp(), sun_relief(), zig_band(), processional pylon gateway: two battere…]
- "dunedesert_dune_props_sleep_tent": "sleep_tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L632 | neighbors=[dune_props.py, A-frame nomad tent: ridge pole on two f…, lerp(), peg_rope(), rolled_rug(), sheet()]
- "dunedesert_gen_trees_with_palms_branch": "Branch" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L331 | neighbors=[gen_trees_with_palms.py, .at(), .__init__(), .length(), .grow(), .grow_roots()]
- "dunedesert_gen_trees_with_palms_card_quads": "card_quads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L549 | neighbors=[gen_trees_with_palms.py, .at(), .length(), rand_unit(), .env(), Leaf-cluster cards (folded, 4 tris) or …]
- "dunedesert_gen_trees_with_palms_leaf_atlas": "leaf_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L270 | neighbors=[gen_trees_with_palms.py, Canvas, .capsule_path(), .finish(), .leaf(), fft_noise()]
- "dunedesert_gen_trees_with_palms_main": "main()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1271 | neighbors=[gen_trees_with_palms.py, contact_sheet(), export_glb(), make_tree(), render_turntable(), setup_scene()]
- "dunedesert_gen_trees_with_palms_normal_from_height": "normal_from_height()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L42 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), .finish()]
- "dunedesert_gen_trees_with_palms_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L66 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), t array -> colour from [(pos, (r,g,b)),…]
- "dunedesert_gen_trees_with_palms_tree_children_of": ".children_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L380 | neighbors=[Tree, .build(), .at(), .length(), .env(), .grow()]
- "dunedesert_gen_trees_with_palms_tree_laterals": ".laterals()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L474 | neighbors=[paired side sprays in the (roughly hori…, Tree, .build_conifer(), .at(), .length(), .grow()]
- "effekseer_ai_authoring_layerbuilder_bind": ".bind()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L153 | neighbors=[LayerBuilder, _code(), .scalar(), _number(), .layer(), Fixed position/scale that a dynamic equ…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-025.json

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
