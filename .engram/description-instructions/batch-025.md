# Node Description Batch 26 of 209

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

- "commit:repo:github.com/Raft-The-Crab/pokox@0d85dcef2111f35517cacef03be908066434a3af": "0d85dce Merge pull request #6 from Raft-The-Crab/mut-42-hostcalls" | kind=Commit | source=git | neighbors=[main, 5106553 MUT-42: physics hostcall implem…, 78dbd1e Merge pull request #7 from Raft…, stdlib_physics.hpp, 1aefb72 MUT-42: physics hostcall bounda…, e77fa31 Add new skills and asset packs …] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@2960ac16e14b8de385ded88996fd3124379035ed": "2960ac1 Android Vulkan clear: no fence deadlock on OUT_OF_DATE, bounded retry" | kind=Commit | source=git | neighbors=[main, 60d8044 Mute crypto hostcalls: fail exp…, swapchain_frame_loop.hpp, vulkan_clear_android.cpp, swapchain_frame_loop_test.cpp, 5eb3f50 Mute det_pow: integer-exponent …] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@2c0194b93a2d811c1501ffbddbc44750cf19ca26": "2c0194b Add assignments and loop-carried phis to Mute lowering" | kind=Commit | source=git | neighbors=[main, 0ab64e5 Refresh graph after lowering as…, lower.cpp, ssa.cpp, lower_test.cpp, d14bc19 Refresh graph after MUT-26 lowe…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@60d80443b688e7224b49ae23b252654c33c4985e": "60d8044 Mute crypto hostcalls: fail explicitly instead of returning 0" | kind=Commit | source=git | neighbors=[2960ac1 Android Vulkan clear: no fence …, main, 9b77990 Android GLES probe: no data rac…, hostcall.hpp, stdlib_crypto.cpp, stdlib_crypto_test.cpp] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@72b9ac76a5603e7de1fd094733b57f11dd912c93": "72b9ac7 Merge branch 'main' into mini-code/b4d7e813-e93" | kind=Commit | source=git | neighbors=[2680d0e Pushed an update., lifecycle.test.js, main, 7eabc2d Merge pull request #8 from Raft…, test_privacy.py, 78dbd1e Merge pull request #7 from Raft…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@78dbd1e7b25598542c80792396f338bf2a39d8e3": "78dbd1e Merge pull request #7 from Raft-The-Crab/mut-42-followup" | kind=Commit | source=git | neighbors=[0d85dce Merge pull request #6 from Raft…, 5106553 MUT-42: physics hostcall implem…, main, 72b9ac7 Merge branch 'main' into mini-c…, 7eabc2d Merge pull request #8 from Raft…, stdlib_physics.cpp] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@81d94fbe5af2af7d0de76109f1f9bd9e89b6c12d": "81d94fb Merge pull request #5 from Raft-The-Crab/feat/character-touch-memo" | kind=Commit | source=git | neighbors=[0be87b9 Merge pull request #4 from Raft…, main, e77fa31 Add new skills and asset packs …, character_controller.hpp, character_controller.cpp, 8246f8b Character controller: fix heade…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@964ba8a95a9b68b7e131152cff54e549d76d2fbd": "964ba8a Resolve MUT-22 values runtime limits: owned borrows, generation handles…" | kind=Commit | source=git | neighbors=[56f5271 Refresh graph after MUT-21/22 a…, main, dd14e7e Refresh graph after MUT-22 limi…, values.hpp, values_test.cpp, values.cpp] | lang=pt
- "commit:repo:github.com/Raft-The-Crab/pokox@e4990733c91648ee70fda02bb3594b915a86eee0": "e499073 Add MUT-29 dead-code elimination and MUT-30 control-flow simplification" | kind=Commit | source=git | neighbors=[4cead55 Add MUT-27 bytecode verificatio…, main, 2d01203 Final MUT-01..30 audit: stress …, optimize.hpp, optimize.cpp, optimize_test.cpp] | lang=en
- "console_console_numeric": "numeric()" | kind=code-symbol | source=mute/src/console/console.cpp:L38 | neighbors=[console.cpp, evaluate_console(), execute_console_impl(), diagnostic(), number(), rebased()] | lang=en
- "creaturelab_lab_map_garden_paths": "garden_paths()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L416 | neighbors=[lab_map.py, build(), catmull(), H(), sh_val(), curving garden paths (ribbon pavers wit…] | lang=en
- "creaturelab_lab_map_polar_tiles": "polar_tiles()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L95 | neighbors=[lab_map.py, hall_floor(), hardscape(), inset_top(), pol(), flat tiles in rings r0..r1 (ring width …] | lang=en
- "creaturelab_lab_map_pond": "pond()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L437 | neighbors=[lab_map.py, build(), H(), sh_val(), static(), pond: water disc (Glass) over the carve…] | lang=en
- "creaturelab_lab_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L36 | neighbors=[lab_map.py, garden_paths(), hall_floor(), hardscape(), pond(), wing_floor()] | lang=en
- "creaturelab_lab_props_arc_wall": "arc_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L796 | neighbors=[lab_props.py, ring_seg(), .add(), lab_wing(), curved wall from angle a0..a1 split int…, rotunda()] | lang=en
- "creaturelab_lab_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1055 | neighbors=[lab_props.py, ball(), leaf_ball(), rbox(), .add(), rounded bush with a few flower clusters…] | lang=en
- "creaturelab_lab_props_capsule_shelf": "capsule_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L375 | neighbors=[lab_props.py, capsule(), rbox(), shelf_frame(), .add(), capsule gondola: four shelves of steppe…] | lang=en
- "creaturelab_lab_props_entrance_canopy": "entrance_canopy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1010 | neighbors=[lab_props.py, emblem_badge(), rbox(), ring_seg(), .add(), curved canopy over the entrance (front …] | lang=en
- "creaturelab_lab_props_fig_tree": "fig_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1397 | neighbors=[lab_props.py, leaf_cluster(), lerp(), pot(), .add(), indoor fiddle-leaf / round-leaf fig: ta…] | lang=en
- "creaturelab_lab_props_hall_trim": "hall_trim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1286 | neighbors=[lab_props.py, adeg(), _gap(), ring_seg(), .add(), interior architecture of the hall (no c…] | lang=en
- "creaturelab_lab_props_lab_archway": "lab_archway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L736 | neighbors=[lab_props.py, emblem_badge(), rbox(), .add(), upright(), the portal between the hall and the lab…] | lang=en
- "creaturelab_lab_props_lab_table": "lab_table()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L620 | neighbors=[lab_props.py, rbox(), .add(), microscope_bench(), lab table: white top with a teal edge, …, workbench()] | lang=en
- "creaturelab_lab_props_long_planter": "long_planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1084 | neighbors=[lab_props.py, ball(), leaf_ball(), rbox(), .add(), long planter box (white with a teal kic…] | lang=en
- "creaturelab_lab_props_potion_shelf": "potion_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L391 | neighbors=[lab_props.py, bottle(), rbox(), shelf_frame(), .add(), potion shelf: flasks, spray tonics, via…] | lang=en
- "creaturelab_lab_props_rest_nook": "rest_nook()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L765 | neighbors=[lab_props.py, little rest area for recovering creatur…, ball(), pot_plant(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_rotunda_roof": "rotunda_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L867 | neighbors=[lab_props.py, rotunda roof (no collision, hide it for…, rotunda(), lathe_open(), lerp(), .add()] | lang=en
- "creaturelab_lab_props_shop_counter": "shop_counter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L339 | neighbors=[lab_props.py, mart counter: white body, coral front p…, capsule(), emblem(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_specimen_tank": "specimen_tank()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L523 | neighbors=[lab_props.py, specimen tank: steel base drum with a t…, ball(), egg(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_swap_icon": "swap_icon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L470 | neighbors=[lab_props.py, two curved arrows chasing each other in…, lerp(), .add(), upright(), trade_desk()] | lang=en
- "creaturelab_lab_props_trophy_shelf": "trophy_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1673 | neighbors=[lab_props.py, Trade story: wall trophy shelf (two bir…, capsule(), rbox(), .add(), upright()] | lang=en
- "creaturelab_lab_props_vending_machine": "vending_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1165 | neighbors=[lab_props.py, berry-juice vending machine: rounded wh…, bottle(), emblem(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_wall_capsules": "wall_capsules()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1749 | neighbors=[lab_props.py, wall-mounted capsule display: rounded w…, capsule(), emblem(), rbox(), .add()] | lang=en
- "creaturelab_lab_props_wing_roof": "wing_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L947 | neighbors=[lab_props.py, lab wing roof (no collision; hide it fo…, rbox(), ring_seg(), .add(), upright()] | lang=en
- "creaturelab_lab_props_workbench": "workbench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L636 | neighbors=[lab_props.py, lab workbench: table + test-tube rack w…, ball(), lab_table(), rbox(), .add()] | lang=en
- "dunedesert_dune_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L263 | neighbors=[dune_map.py, build(), build_solid(), clip_fail(), place(), unplace()] | lang=en
- "dunedesert_dune_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L168 | neighbors=[dune_map.py, ground(), horizon(), paving(), add_owner(), sub()] | lang=en
- "dunedesert_dune_props_cargo_pile": "cargo_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L744 | neighbors=[dune_props.py, crate(), jar(), rolled_rug(), sack(), caravan cargo: crates stacked, sacks, r…] | lang=en
- "dunedesert_dune_props_obelisk": "obelisk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L380 | neighbors=[dune_props.py, frustum(), merge_into(), plinth(), _shaft(), standing obelisk on the stepped plinth:…] | lang=en
- "dunedesert_dune_props_obelisk_fallen": "obelisk_fallen()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L389 | neighbors=[dune_props.py, frustum(), lerp(), merge_into(), _shaft(), toppled obelisk piece lying on its side…] | lang=en
- "dunedesert_dune_props_pylon_gate": "pylon_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L236 | neighbors=[dune_props.py, frustum(), lerp(), sun_relief(), zig_band(), processional pylon gateway: two battere…] | lang=en

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
