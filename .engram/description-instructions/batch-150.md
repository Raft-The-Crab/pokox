# Node Description Batch 151 of 208

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

- "warehouse_wh_equip_mesh_stillage": "mesh_stillage()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L135 | neighbors=[wh_equip.py, steel weld-mesh stillage cage with corn…]
- "warehouse_wh_equip_packing_bench": "packing_bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L184 | neighbors=[wh_equip.py, steel packing bench: worktop, undershel…]
- "warehouse_wh_equip_safety_barrier": "safety_barrier()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L250 | neighbors=[wh_equip.py, yellow polymer-style traffic barrier: p…]
- "warehouse_wh_equip_site_office": "site_office()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L76 | neighbors=[wh_equip.py, modular mezzanine office: framed white …]
- "warehouse_wh_equip_stretch_wrapper": "stretch_wrapper()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L208 | neighbors=[wh_equip.py, turntable pallet wrapper: low base + ro…]
- "warehouse_wh_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L64 | neighbors=[wh_map.py, build()]
- "warehouse_wh_map_rationale_118": "deck slabs on the truss top chords with skylight holes, liner rib lines undernea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L118 | neighbors=[MB, roof()]
- "warehouse_wh_map_rationale_159": "concrete slab (mottled grid), saw-cut joints, lane + bay markings; yard asphalt" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L159 | neighbors=[MB, floors()]
- "warehouse_wh_map_rationale_215": "bays running north from z RACK_S (yaw 90: local front -> -x / west, local +x ->" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L215 | neighbors=[MB, rack_row()]
- "warehouse_wh_map_rationale_36": "delete faces nobody sees: flat bottoms on the floor (y ~ 0 facing down), backs o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L36 | neighbors=[MB, cull()]
- "warehouse_wh_map_yaw_of": "yaw_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L67 | neighbors=[wh_map.py, build()]
- "warehouse_wh_props_floor_pallet": "floor_pallet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L123 | neighbors=[wh_props.py, pallet_load()]
- "warehouse_wh_real_light": "light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_real.py:L88 | neighbors=[wh_real.py, r2b()]
- "warehouse_wh_real_r2b": "r2b()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_real.py:L9 | neighbors=[wh_real.py, light()]
- "warehouse_wh_struct_crane_bridge": "crane_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L156 | neighbors=[wh_struct.py, double-girder overhead travelling crane…]
- "warehouse_wh_struct_crane_trolley": "crane_trolley()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L187 | neighbors=[wh_struct.py, crab: frame, rope drum, gearbox + motor…]
- "warehouse_wh_struct_dock_door": "dock_door()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L73 | neighbors=[wh_struct.py, loading dock: insulated roller door (op…]
- "warehouse_wh_struct_high_bay": "high_bay()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L58 | neighbors=[wh_struct.py, LED high-bay 'UFO' lamp on a pendant ro…]
- "warehouse_wh_struct_personnel_door": "personnel_door()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L132 | neighbors=[wh_struct.py, single steel fire door with frame, visi…]
- "warehouse_wh_struct_roof_truss": "roof_truss()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L35 | neighbors=[wh_struct.py, pitched lattice truss across the hall (…]
- "warehouse_wh_struct_runway_beam": "runway_beam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L147 | neighbors=[wh_struct.py, crane runway girder segment along x: I-…]
- "warehouse_wh_struct_shipping_container": "shipping_container()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L226 | neighbors=[wh_struct.py, 20 ft ISO box: corrugated side + end wa…]
- "warehouse_wh_struct_skylight": "skylight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L280 | neighbors=[wh_struct.py, roof-light: aluminium upstand frame + g…]
- "warehouse_wh_struct_steel_column": "steel_column()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L9 | neighbors=[wh_struct.py, H-section column: base plate + anchor b…]
- "warehouse_wh_yard_dock_stair": "dock_stair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L285 | neighbors=[wh_yard.py, cast concrete stair from the yard up to…]
- "warehouse_wh_yard_fence_panel": "fence_panel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L223 | neighbors=[wh_yard.py, 3D weld-mesh fence panel between two po…]
- "warehouse_wh_yard_yard_bin": "yard_bin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L257 | neighbors=[wh_yard.py, 1100 l steel trade-waste bin: tapered b…]
- "warehouse_wh_yard_yard_light": "yard_light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L241 | neighbors=[wh_yard.py, galvanised tapered column on a bolted b…]
- "whispering_grove_forest_map_camp_pts": "CAMP_PTS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L374 | neighbors=[forest_map.py, build()]
- "whispering_grove_forest_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L136 | neighbors=[forest_map.py, place()]
- "whispering_grove_forest_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L379 | neighbors=[forest_map.py, free()]
- "whispering_grove_forest_map_rationale_143": "footprint radius = widest point of the prop's geometry within 1 stud of its base" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L143 | neighbors=[MB, foot()]
- "whispering_grove_forest_map_rationale_152": "centre=True (soft foliage): sit on the ground at the origin, so a slope never bu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L152 | neighbors=[MB, place()]
- "whispering_grove_forest_map_rationale_172": "terrain height range over a footprint: big = a slope that would bury the prop's" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L172 | neighbors=[MB, spread()]
- "whispering_grove_forest_map_rationale_418": "distant faceted mountains + a dark forest-floor skirt so the map never ends in s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L418 | neighbors=[MB, horizon()]
- "whispering_grove_forest_map_rationale_54": "(signed distance past the path edge, path width) for the nearest path" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L54 | neighbors=[MB, path_info()]
- "whispering_grove_forest_props_curve": "curve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L54 | neighbors=[forest_props.py, oak()]
- "whispering_grove_forest_props_materials": "materials()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L610 | neighbors=[forest_props.py, to_kit()]
- "whispering_grove_forest_props_mesh_from": "mesh_from()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L628 | neighbors=[forest_props.py, to_kit()]
- "whispering_grove_forest_props_ring_pts": "ring_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L51 | neighbors=[forest_props.py, mushroom()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-150.json

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
