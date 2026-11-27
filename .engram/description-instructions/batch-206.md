# Node Description Batch 207 of 208

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

- "warehouse_wh_props_rationale_57": "stretch-wrapped carton block: brown cartons seen through a milky film; banding s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L57 | neighbors=[load_wrapped()] | lang=pt
- "warehouse_wh_props_rationale_79": "steel 200 l drum: rolled rims + two rolling hoops" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L79 | neighbors=[drum_bm()] | lang=en
- "warehouse_wh_props_rationale_94": "pillowy bags in brick bond, 4 layers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L94 | neighbors=[load_sacks()] | lang=en
- "warehouse_wh_struct_rationale_10": "H-section column: base plate + anchor bolts + grout pad, cap plate, optional cra" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L10 | neighbors=[steel_column()] | lang=en
- "warehouse_wh_struct_rationale_133": "single steel fire door with frame, vision panel, push bar, closer (wall prop, in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L133 | neighbors=[personnel_door()] | lang=en
- "warehouse_wh_struct_rationale_148": "crane runway girder segment along x: I-beam 1.4 deep + square rail on top (rail" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L148 | neighbors=[runway_beam()] | lang=en
- "warehouse_wh_struct_rationale_157": "double-girder overhead travelling crane: box girders along z, end trucks on the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L157 | neighbors=[crane_bridge()] | lang=en
- "warehouse_wh_struct_rationale_188": "crab: frame, rope drum, gearbox + motor, two rope falls down to the hook block," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L188 | neighbors=[crane_trolley()] | lang=en
- "warehouse_wh_struct_rationale_227": "20 ft ISO box: corrugated side + end walls (trapezoid profile), top/bottom rails" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L227 | neighbors=[shipping_container()] | lang=en
- "warehouse_wh_struct_rationale_281": "roof-light: aluminium upstand frame + glazing bars round a translucent panel (gl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L281 | neighbors=[skylight()] | lang=pt
- "warehouse_wh_struct_rationale_36": "pitched lattice truss across the hall (along z), square-hollow chords + webs; si" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L36 | neighbors=[roof_truss()] | lang=en
- "warehouse_wh_struct_rationale_59": "LED high-bay 'UFO' lamp on a pendant rod: finned heat sink, driver, diffuser glo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L59 | neighbors=[high_bay()] | lang=pt
- "warehouse_wh_struct_rationale_74": "loading dock: insulated roller door (open / half / closed) in a 10 x 12 opening," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L74 | neighbors=[dock_door()] | lang=nl
- "warehouse_wh_veh_rationale_25": "electric counterbalance forklift: yellow body, rounded counterweight, overhead g" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L25 | neighbors=[forklift()] | lang=en
- "warehouse_wh_veh_rationale_7": "tyre + rim + hub nuts, axle along x, centre c, outer face toward side (+1 = +x)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L7 | neighbors=[wheel()] | lang=en
- "warehouse_wh_veh_rationale_92": "hand pallet truck: twin forks, pump body, tiller handle (forks toward -z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L92 | neighbors=[pallet_jack()] | lang=en
- "warehouse_wh_yard_rationale_12": "truck wheel: deep-sidewall tyre with tread blocks, dished steel disc with 6 hand" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L12 | neighbors=[truck_wheel()] | lang=en
- "warehouse_wh_yard_rationale_134": "cab-over tractor: high-roof raked cab with round front corners, wrap-round winds" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L134 | neighbors=[tractor_unit()] | lang=en
- "warehouse_wh_yard_rationale_224": "3D weld-mesh fence panel between two posts: vertical wires, double horizontals," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L224 | neighbors=[fence_panel()] | lang=en
- "warehouse_wh_yard_rationale_242": "galvanised tapered column on a bolted base, outreach arm, two LED floodlight hea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L242 | neighbors=[yard_light()] | lang=pt
- "warehouse_wh_yard_rationale_258": "1100 l steel trade-waste bin: tapered body, two lids, push handles, 4 castors" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L258 | neighbors=[yard_bin()] | lang=en
- "warehouse_wh_yard_rationale_286": "cast concrete stair from the yard up to the dock floor: steps with steel nosings" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L286 | neighbors=[dock_stair()] | lang=en
- "warehouse_wh_yard_rationale_37": "moulded wheel-arch liner over the top half of a tyre: a curved strip with a lip," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L37 | neighbors=[wheel_arch()] | lang=en
- "warehouse_wh_yard_rationale_49": "main + wide-angle mirrors: sculpted housings (body-colour backs, black rims) sta" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L49 | neighbors=[truck_mirrors()] | lang=en
- "warehouse_wh_yard_rationale_68": "13.6 m box semi-trailer: aluminium-panel body with post ribs, rear doors (open =" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L68 | neighbors=[box_trailer()] | lang=en
- "warehouse_wh_yard_traffic_cone": "traffic_cone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L272 | neighbors=[wh_yard.py] | lang=en
- "warehouse_wh_yard_wheel_chock": "wheel_chock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L279 | neighbors=[wh_yard.py] | lang=en
- "whispering_grove_forest_map_canopy_shade": "canopy_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L365 | neighbors=[forest_map.py] | lang=en
- "whispering_grove_forest_map_chaikin": "chaikin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L23 | neighbors=[forest_map.py] | lang=en
- "whispering_grove_forest_map_rationale_168": "yaw (deg) that turns a prop's -Z front toward (tx, tz)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L168 | neighbors=[face()] | lang=en
- "whispering_grove_forest_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L409 | neighbors=[forest_map.py] | lang=en
- "whispering_grove_forest_props_prop_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L36 | neighbors=[Prop] | lang=en
- "whispering_grove_forest_props_prop_tris": ".tris()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L43 | neighbors=[Prop] | lang=en
- "whispering_grove_forest_props_rationale_133": "closed solid of the door opening (boolean cutter)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L133 | neighbors=[arch_prism()] | lang=en
- "whispering_grove_forest_props_rationale_143": "exact boolean A - B through a throwaway modifier (background-safe)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L143 | neighbors=[bool_diff()] | lang=pt
- "whispering_grove_forest_props_rationale_59": "faceted canopy blobs with a height gradient (dark under, light on top)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L59 | neighbors=[leafy()] | lang=en
- "whispering_grove_kit_sheet_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/kit_sheet.py:L49 | neighbors=[kit_sheet.py] | lang=en
- "window_i_platform_iplatform_iplatform": ".IPlatform()" | kind=code-symbol | source=engine/platform/include/poko/platform/window/i_platform.hpp:L68 | neighbors=[IPlatform] | lang=en
- "window_sdl_platform_create_window": "create_window()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L27 | neighbors=[sdl_platform.cpp] | lang=en
- "window_sdl_platform_initialize": "initialize()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L12 | neighbors=[sdl_platform.cpp] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-206.json

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
