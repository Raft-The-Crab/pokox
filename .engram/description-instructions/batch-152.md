# Node Description Batch 153 of 209

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
- "whispering_grove_forest_props_shift": "shift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L279 | neighbors=[forest_props.py, log()]
- "window_i_platform_iplatform": "IPlatform" | kind=code-symbol | source=engine/platform/include/poko/platform/window/i_platform.hpp:L66 | neighbors=[i_platform.hpp, .IPlatform()]
- "window_sdl_platform_destroy_window": "destroy_window()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L65 | neighbors=[sdl_platform.cpp, shutdown()]
- "window_sdl_platform_get_window_size": "get_window_size()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L76 | neighbors=[sdl_platform.cpp, poll_event()]
- "window_sdl_platform_poll_event": "poll_event()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L88 | neighbors=[sdl_platform.cpp, get_window_size()]
- "work_uv_overlap_cross": "_cross()" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L14 | neighbors=[uv_overlap.py, intersection_area()]
- "work_uv_overlap_signed_area": "_signed_area()" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L18 | neighbors=[uv_overlap.py, intersection_area()]
- "writing_skills_render_graphs_combinegraphs": "combineGraphs()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L51 | neighbors=[render-graphs.js, main()]
- "writing_skills_render_graphs_extractdotblocks": "extractDotBlocks()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L20 | neighbors=[render-graphs.js, main()]
- "writing_skills_render_graphs_rendertosvg": "renderToSvg()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L70 | neighbors=[render-graphs.js, main()]
- "addon_template_init_rationale_1": "My Tool - Blender extension template (4.2+ extension format, verified on 5.3)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/__init__.py:L1 | neighbors=[__init__.py]
- "addon_template_init_register": "register()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/__init__.py:L14 | neighbors=[__init__.py]
- "addon_template_init_unregister": "unregister()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/__init__.py:L21 | neighbors=[__init__.py]
- "addon_template_operators_mytool_ot_offset_selected_poll": ".poll()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L20 | neighbors=[MYTOOL_OT_offset_selected]
- "addon_template_operators_mytool_pg_settings": "MYTOOL_PG_settings" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L5 | neighbors=[operators.py]
- "addon_template_operators_rationale_11": "Move selected objects along an axis" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L11 | neighbors=[MYTOOL_OT_offset_selected]
- "addon_template_ui_menu_func": "menu_func()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L29 | neighbors=[ui.py]
- "addon_template_ui_mytool_ap_preferences_draw": ".draw()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L25 | neighbors=[MYTOOL_AP_preferences]
- "addon_template_ui_mytool_pt_main_draw": ".draw()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L11 | neighbors=[MYTOOL_PT_main]
- "animation_build_animations_foot": "foot()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L13 | neighbors=[build_animations.py]
- "animation_build_animations_loc": "loc()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L36 | neighbors=[build_animations.py]
- "animation_build_animations_rot": "rot()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L34 | neighbors=[build_animations.py]
- "animation_v2_build_refined_loc": "loc()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L44 | neighbors=[build_refined.py]
- "animation_v2_build_refined_rationale_1": "Generate separate R6 clips from untouched full adapted bases. Requires Blender 5" | kind=entity | source=assets/characters/animation-v2/build_refined.py:L1 | neighbors=[build_refined.py]
- "animation_v2_build_refined_rationale_17": "Continuous velocity at footfall and toe-off; -Y movement during stance." | kind=entity | source=assets/characters/animation-v2/build_refined.py:L17 | neighbors=[foot()]
- "animation_v2_build_refined_rot": "rot()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L42 | neighbors=[build_refined.py]
- "animation_v2_check_gait_rationale_1": "Quarter-frame ground and stance-target diagnostics for editable rigs." | kind=entity | source=assets/characters/animation-v2/check_gait.py:L1 | neighbors=[check_gait.py]
- "animation_v2_validate_refined_rationale_1": "Checks sampled positions after reopening each clip. Does not certify artistry." | kind=entity | source=assets/characters/animation-v2/validate_refined.py:L1 | neighbors=[validate_refined.py]
- "assertionerror": "AssertionError" | kind=code-symbol | neighbors=[MatingError]
- "authority_pkb_schema_pkbauthority_pkbauthority": ".PkbAuthority()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L226 | neighbors=[PkbAuthority]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-152.json

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
