# Node Description Batch 34 of 208

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

- "cavemap_cave_props_stalactite": "stalactite()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L210 | neighbors=[cave_props.py, hanging dripstone cluster: one long rin…, drip_profile(), jitter(), V()]
- "cavemap_cave_props2_blob": "blob()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L9 | neighbors=[cave_props2.py, cart_load(), mine_frame(), mine_lantern_post(), ore_pile()]
- "cavemap_cave_props2_ore_pile": "ore_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L230 | neighbors=[cave_props2.py, blob(), logp(), W(), heap of broken ore with glowing crystal…]
- "cavemap_cave_props2_scaffold": "scaffold()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L127 | neighbors=[cave_props2.py, 3-storey mining scaffold against a wall…, logp(), oil_lantern(), W()]
- "cavemap_cave_props2_tool_rack": "tool_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L243 | neighbors=[cave_props2.py, timber rack with hung pickaxes and shov…, logp(), oil_lantern(), W()]
- "commit:repo:github.com/Raft-The-Crab/pokox@038387e13db5b21f18a460c9f541bd9c4d327133": "038387e Character controller: value-keyed touch memo for the cast path" | kind=Commit | source=git | neighbors=[main, 0be87b9 Merge pull request #4 from Raft…, 3faf30f Character controller: value-key…, character_controller.hpp, 60f3d98 Merge pull request #3 from Raft…]
- "commit:repo:github.com/Raft-The-Crab/pokox@0be87b96189a4b41dbc4f691cd5b9d2edac2fd9f": "0be87b9 Merge pull request #4 from Raft-The-Crab/feat/character-touch-memo" | kind=Commit | source=git | neighbors=[038387e Character controller: value-key…, main, 81d94fb Merge pull request #5 from Raft…, character_controller.hpp, 60f3d98 Merge pull request #3 from Raft…]
- "commit:repo:github.com/Raft-The-Crab/pokox@2d012032e21f854f0f614800c7a5c62d11b6eaab": "2d01203 Final MUT-01..30 audit: stress test, emit trampoline fix, consolidate m…" | kind=Commit | source=git | neighbors=[main, 952997e Audit MUT-01-55 and harden veri…, emit.cpp, stress_test.cpp, e499073 Add MUT-29 dead-code eliminatio…]
- "commit:repo:github.com/Raft-The-Crab/pokox@5eb3f501c79e04cd57a4c426626396e6111d04b6": "5eb3f50 Mute det_pow: integer-exponent binary exponentiation, no libm" | kind=Commit | source=git | neighbors=[06cfbe9 Narrowphase: local pair frame +…, main, 2960ac1 Android Vulkan clear: no fence …, stdlib_math.cpp, stdlib_math_test.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@6d9948d0015b04b7937fb017fee17c133eddbb4b": "6d9948d Re-resolve X11 demo window during console interaction tests" | kind=Commit | source=git | neighbors=[main, e624dc7 Click console input before each…, test_mute_console_x11.py, test_mute_state_console_x11.py, cb2a354 Re-assert window focus in X11 c…]
- "commit:repo:github.com/Raft-The-Crab/pokox@90b7d79139e8d104bab7d8234dd19409c1d23d0b": "90b7d79 Add for-range lowering to Mute and restore MUT-26 progress doc" | kind=Commit | source=git | neighbors=[807b9d3 Refresh graph after lowering as…, main, 4cead55 Add MUT-27 bytecode verificatio…, lower.cpp, lower_test.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@cb2a354ea05a5ef8d3a9025c5a45a01f584db50e": "cb2a354 Re-assert window focus in X11 console interaction tests" | kind=Commit | source=git | neighbors=[main, 6d9948d Re-resolve X11 demo window duri…, test_mute_console_x11.py, test_mute_state_console_x11.py, f4a6ac4 Allowlist known validation-laye…]
- "creaturelab_lab_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L39 | neighbors=[lab_map.py, garden_paths(), horizon(), place(), pond()]
- "creaturelab_lab_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L454 | neighbors=[lab_map.py, build(), H(), static(), distant scenery: soft rounded hills in …]
- "creaturelab_lab_map_pol": "pol()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L33 | neighbors=[lab_map.py, exterior(), hall_floor(), polar_tiles(), stations()]
- "creaturelab_lab_props_art_frame": "art_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1733 | neighbors=[lab_props.py, rbox(), .add(), upright(), framed poster with an abstract landscap…]
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
- "dunedesert_dune_map_dig_spots": "dig_spots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L467 | neighbors=[dune_map.py, build(), anchor(), place(), reserve()]
- "dunedesert_dune_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L301 | neighbors=[dune_map.py, build(), H(), static(), distant tiered mesas + buttes far outsi…]
- "dunedesert_dune_map_paving": "paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L322 | neighbors=[dune_map.py, build(), H(), static(), worn flagstone slabs over the city + th…]
- "dunedesert_dune_paint": "dune_paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _hex(), paint_block(), remap()]
- "dunedesert_dune_props_block_wall": "block_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L114 | neighbors=[dune_props.py, wall of REAL bevelled blocks through th…, ruin_house(), ruin_wall(), sunken_temple()]
- "dunedesert_dune_props_camel": "camel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L655 | neighbors=[dune_props.py, sheet(), uvsphere(), V(), stylised camel (smooth hide): ellipsoid…]
- "dunedesert_dune_props_column": "column()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L137 | neighbors=[dune_props.py, column_set(), square base + torus, drummed 10-sided s…, step_pyramid(), sunken_temple()]

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
