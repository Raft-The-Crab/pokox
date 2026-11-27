# Node Description Batch 92 of 208

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
- "whispering_grove_forest_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L94 | neighbors=[forest_map.py, build(), sub()]
- "whispering_grove_forest_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L417 | neighbors=[forest_map.py, sub(), distant faceted mountains + a dark fore…]
- "whispering_grove_forest_map_plaza": "plaza()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L125 | neighbors=[forest_map.py, build(), sub()]
- "whispering_grove_forest_props_arch_cap": "arch_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L169 | neighbors=[forest_props.py, arch_outline(), elder_tree()]
- "whispering_grove_forest_props_bool_diff": "bool_diff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L142 | neighbors=[forest_props.py, elder_tree(), exact boolean A - B through a throwaway…]
- "whispering_grove_forest_props_fern": "fern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L223 | neighbors=[forest_props.py, frond(), Prop]
- "whispering_grove_forest_props_flame_tongue": "flame_tongue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L412 | neighbors=[forest_props.py, campfire(), a licking flame: a tapering tube that s…]
- "whispering_grove_kit_sheet": "kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "window_i_platform": "i_platform.hpp" | kind=code-symbol | source=engine/platform/include/poko/platform/window/i_platform.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, IPlatform, c7a411f Fix MUT-01-20 audit defects in …]
- "window_sdl_platform_shutdown": "shutdown()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L19 | neighbors=[sdl_platform.cpp, ~SdlPlatform(), destroy_window()]
- "window_sdl_window_demo": "sdl_window_demo.cpp" | kind=code-symbol | source=engine/platform/src/window/sdl_window_demo.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "work_trace_face": "trace_face.py" | kind=code-symbol | source=assets/characters/work/trace_face.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, dump_tree(), c7a411f Fix MUT-01-20 audit defects in …]
- "work_uv_overlap_find_cross_mesh_overlaps": "find_cross_mesh_overlaps()" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L46 | neighbors=[uv_overlap.py, intersection_area(), Input: iterable of (mesh_name, triangle…]
- "work_validate_production": "validate_production.py" | kind=code-symbol | source=assets/characters/work/validate_production.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Validate the opened R6 .blend. Run with…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachment_motion": "verify_attachment_motion.py" | kind=code-symbol | source=assets/characters/work/verify_attachment_motion.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Headless attachment smoke test. Does no…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachments": "verify_attachments.py" | kind=code-symbol | source=assets/characters/work/verify_attachments.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, nearest_surface(), c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachments2": "verify_attachments2.py" | kind=code-symbol | source=assets/characters/work/verify_attachments2.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, bbox_dist(), c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_final_attachments": "verify_final_attachments.py" | kind=code-symbol | source=assets/characters/work/verify_final_attachments.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Definitive attachment connectivity: rot…, c7a411f Fix MUT-01-20 audit defects in …]
- "activity": "Activity" | kind=code-symbol | neighbors=[PokoActivity.java, PokoActivity]
- "addon_template_operators_mytool_ot_offset_selected_execute": ".execute()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L28 | neighbors=[MYTOOL_OT_offset_selected, .invoke()]
- "addon_template_operators_mytool_ot_offset_selected_invoke": ".invoke()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L23 | neighbors=[MYTOOL_OT_offset_selected, .execute()]
- "addon_template_ui_mytool_ap_preferences": "MYTOOL_AP_preferences" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L20 | neighbors=[ui.py, .draw()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-091.json

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
