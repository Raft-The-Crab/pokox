# Node Description Batch 93 of 209

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

- "voidrealm_void_map_keel_profile": "keel_profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L130 | neighbors=[void_map.py, island(), underside depth (fraction of R) at ring…]
- "voidrealm_void_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L65 | neighbors=[void_map.py, dressing(), place()]
- "voidrealm_void_map_path": "path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L194 | neighbors=[void_map.py, bridges(), stations()]
- "voidrealm_void_map_placed_mb": "placed_mb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L114 | neighbors=[void_map.py, bridges(), copy a prop part (Roblox-space MB) to i…]
- "voidrealm_void_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L26 | neighbors=[void_map.py, place(), static()]
- "voidrealm_void_map_validate": "validate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L547 | neighbors=[void_map.py, build(), free()]
- "voidrealm_void_paint": "void_paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_paint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, block()]
- "voidrealm_void_props_flame": "flame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L104 | neighbors=[void_props.py, brazier(), upgrade_altar()]
- "voidrealm_void_props_lift_beam": "lift_beam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L758 | neighbors=[void_props.py, annulus(), gravity lift column (glow only, walk-th…]
- "voidrealm_void_props_void_grass": "void_grass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L408 | neighbors=[void_props.py, tuft of curling void-moss blades (teal)…, V()]
- "warehouse_fitlib_inside_one": "_inside_one()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L20 | neighbors=[fitlib.py, fit_bad(), _inb()]
- "warehouse_kitlib_lathe": "lathe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L58 | neighbors=[kitlib.py, revolve [(r, y)] round Y, sphere()]
- "warehouse_kitlib_prism_x": "prism_x()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L77 | neighbors=[kitlib.py, ibeam(), profile in the Z-Y plane [(z, y)], extr…]
- "warehouse_kitlib_prism_z": "prism_z()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L84 | neighbors=[kitlib.py, ibeam(), profile in the X-Y plane [(x, y)], extr…]
- "warehouse_kitlib_sub_emit": ".emit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L50 | neighbors=[Sub, .add(), .gadd()]
- "warehouse_kitlib_sub_gadd": ".gadd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L49 | neighbors=[glowbox(), Sub, .emit()]
- "warehouse_tricount": "tricount.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/tricount.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, n()]
- "warehouse_wh_equip_mezzanine": "mezzanine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L16 | neighbors=[wh_equip.py, rail_run(), steel mezzanine: SHS columns, main beam…]
- "warehouse_wh_equip_rail_run": "rail_run()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L6 | neighbors=[wh_equip.py, mezzanine(), handrail along a straight line a->b on …]
- "warehouse_wh_map_cull": "cull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L35 | neighbors=[wh_map.py, kit(), delete faces nobody sees: flat bottoms …]
- "warehouse_wh_map_deck_y": "deck_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L30 | neighbors=[wh_map.py, build(), roof()]
- "warehouse_wh_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L48 | neighbors=[wh_map.py, cull(), place()]
- "warehouse_wh_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L21 | neighbors=[wh_map.py, mesh_obj(), place()]
- "warehouse_wh_props_beam_pair": "beam_pair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L151 | neighbors=[wh_props.py, rack_bay(), two step beams at level y between uprig…]
- "warehouse_wh_props_carton": "carton()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L31 | neighbors=[wh_props.py, load_cartons(), one cardboard carton: box with a tape s…]
- "warehouse_wh_props_drum_bm": "drum_bm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L78 | neighbors=[wh_props.py, load_drums(), steel 200 l drum: rolled rims + two rol…]
- "warehouse_wh_props_load_cartons": "load_cartons()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L43 | neighbors=[wh_props.py, carton(), pallet_load()]
- "warehouse_wh_props_load_crates": "load_crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L104 | neighbors=[wh_props.py, pallet_load(), blue plastic stacking crates with hand-…]
- "warehouse_wh_props_load_drums": "load_drums()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L85 | neighbors=[wh_props.py, drum_bm(), pallet_load()]
- "warehouse_wh_props_load_sacks": "load_sacks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L93 | neighbors=[wh_props.py, pallet_load(), pillowy bags in brick bond, 4 layers]
- "warehouse_wh_props_load_wrapped": "load_wrapped()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L56 | neighbors=[wh_props.py, pallet_load(), stretch-wrapped carton block: brown car…]
- "warehouse_wh_props_pallet_stack": "pallet_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L126 | neighbors=[wh_props.py, pallet_sub(), a stack of empty pallets, slightly misa…]
- "warehouse_wh_props_rack_end": "rack_end()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L189 | neighbors=[wh_props.py, upright_frame(), the last upright frames of a row + yell…]
- "warehouse_wh_veh_forklift": "forklift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L24 | neighbors=[wh_veh.py, wheel(), electric counterbalance forklift: yello…]
- "warehouse_wh_veh_pallet_jack": "pallet_jack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L91 | neighbors=[wh_veh.py, wheel(), hand pallet truck: twin forks, pump bod…]
- "warehouse_wh_yard_box_trailer": "box_trailer()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L67 | neighbors=[wh_yard.py, axle_set(), 13.6 m box semi-trailer: aluminium-pane…]
- "warehouse_wh_yard_truck_mirrors": "truck_mirrors()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L48 | neighbors=[wh_yard.py, main + wide-angle mirrors: sculpted hou…, tractor_unit()]
- "warehouse_wh_yard_wheel_arch": "wheel_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L36 | neighbors=[wh_yard.py, moulded wheel-arch liner over the top h…, tractor_unit()]
- "whispering_grove_forest_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L167 | neighbors=[forest_map.py, build(), yaw (deg) that turns a prop's -Z front …]
- "whispering_grove_forest_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L142 | neighbors=[forest_map.py, place(), footprint radius = widest point of the …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-092.json

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
