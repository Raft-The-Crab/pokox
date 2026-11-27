# Node Description Batch 90 of 207

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
- "window_sdl_platform_shutdown": "shutdown()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L19 | neighbors=[sdl_platform.cpp, ~SdlPlatform(), destroy_window()]
- "work_adapt_blockyr6": "adapt_blockyr6.py" | kind=code-symbol | source=assets/characters/work/adapt_blockyr6.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, world_point(), Adapt BlockyR6 for PokoX (same two fixe…]
- "work_adapt_boyr6": "adapt_boyr6.py" | kind=code-symbol | source=assets/characters/work/adapt_boyr6.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, bone_world_point(), Adapt BoyR6 for PokoX.  Fixes:   1. Hea…]
- "work_mcp_client": "mcp_client.py" | kind=code-symbol | source=assets/characters/work/mcp_client.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, send(), Minimal client for the BlenderMCP TCP s…]
- "work_test_uv_overlap": "test_uv_overlap.py" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, OverlapTests, Regression tests independent of Blender…]
- "work_uv_overlap_find_cross_mesh_overlaps": "find_cross_mesh_overlaps()" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L46 | neighbors=[uv_overlap.py, intersection_area(), Input: iterable of (mesh_name, triangle…]
- "activity": "Activity" | kind=code-symbol | neighbors=[PokoActivity.java, PokoActivity]
- "addon_template_operators_mytool_ot_offset_selected_execute": ".execute()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L28 | neighbors=[MYTOOL_OT_offset_selected, .invoke()]
- "addon_template_operators_mytool_ot_offset_selected_invoke": ".invoke()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L23 | neighbors=[MYTOOL_OT_offset_selected, .execute()]
- "addon_template_ui_mytool_ap_preferences": "MYTOOL_AP_preferences" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L20 | neighbors=[ui.py, .draw()]
- "addon_template_ui_mytool_pt_main": "MYTOOL_PT_main" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L4 | neighbors=[ui.py, .draw()]
- "animation_build_animations_interp": "interp()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L8 | neighbors=[build_animations.py, smooth()]
- "animation_build_animations_smooth": "smooth()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L6 | neighbors=[build_animations.py, interp()]
- "animation_v2_build_refined_interp": "interp()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L11 | neighbors=[build_refined.py, ease()]
- "animation_v2_check_gait": "check_gait.py" | kind=code-symbol | source=assets/characters/animation-v2/check_gait.py:L1 | neighbors=[Quarter-frame ground and stance-target …, c7a411f Fix MUT-01-20 audit defects in …]
- "animation_v2_check_model_structure_capture": "capture()" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L9 | neighbors=[check_model_structure.py, floats()]
- "animation_v2_check_model_structure_floats": "floats()" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L5 | neighbors=[check_model_structure.py, capture()]
- "animation_v2_validate_refined": "validate_refined.py" | kind=code-symbol | source=assets/characters/animation-v2/validate_refined.py:L1 | neighbors=[Checks sampled positions after reopenin…, c7a411f Fix MUT-01-20 audit defects in …]
- "authority_pkb_schema_is_protected_domain": "is_protected_domain()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L78 | neighbors=[pkb_schema.hpp, load_pkb_schema()]
- "authority_pkb_schema_load_pkb_schema": "load_pkb_schema()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L92 | neighbors=[pkb_schema.hpp, is_protected_domain()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-089.json

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
