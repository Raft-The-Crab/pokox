# Node Description Batch 94 of 209

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

- "whispering_grove_forest_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L94 | neighbors=[forest_map.py, build(), sub()]
- "whispering_grove_forest_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L417 | neighbors=[forest_map.py, sub(), distant faceted mountains + a dark fore…]
- "whispering_grove_forest_map_plaza": "plaza()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L125 | neighbors=[forest_map.py, build(), sub()]
- "whispering_grove_forest_props_arch_cap": "arch_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L169 | neighbors=[forest_props.py, arch_outline(), elder_tree()]
- "whispering_grove_forest_props_bool_diff": "bool_diff()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L142 | neighbors=[forest_props.py, elder_tree(), exact boolean A - B through a throwaway…]
- "whispering_grove_forest_props_fern": "fern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L223 | neighbors=[forest_props.py, frond(), Prop]
- "whispering_grove_forest_props_flame_tongue": "flame_tongue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L412 | neighbors=[forest_props.py, campfire(), a licking flame: a tapering tube that s…]
- "whispering_grove_kit_sheet": "kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "window_sdl_platform_shutdown": "shutdown()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L19 | neighbors=[sdl_platform.cpp, ~SdlPlatform(), destroy_window()]
- "work_constraint_check": "constraint_check.py" | kind=code-symbol | source=assets/characters/work/constraint_check.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_final_check": "final_check.py" | kind=code-symbol | source=assets/characters/work/final_check.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_list_images": "list_images.py" | kind=code-symbol | source=assets/characters/work/list_images.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_load_live": "load_live.py" | kind=code-symbol | source=assets/characters/work/load_live.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_load_live_blocky": "load_live_blocky.py" | kind=code-symbol | source=assets/characters/work/load_live_blocky.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_uv_overlap_find_cross_mesh_overlaps": "find_cross_mesh_overlaps()" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L46 | neighbors=[uv_overlap.py, intersection_area(), Input: iterable of (mesh_name, triangle…]
- "work_verify_attachments3": "verify_attachments3.py" | kind=code-symbol | source=assets/characters/work/verify_attachments3.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_attachments4": "verify_attachments4.py" | kind=code-symbol | source=assets/characters/work/verify_attachments4.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_boyr6": "verify_boyr6.py" | kind=code-symbol | source=assets/characters/work/verify_boyr6.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_boyr6_file": "verify_boyr6_file.py" | kind=code-symbol | source=assets/characters/work/verify_boyr6_file.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "work_verify_final": "verify_final.py" | kind=code-symbol | source=assets/characters/work/verify_final.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "activity": "Activity" | kind=code-symbol | neighbors=[PokoActivity.java, PokoActivity]
- "addon_template_operators_mytool_ot_offset_selected_execute": ".execute()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L28 | neighbors=[MYTOOL_OT_offset_selected, .invoke()]
- "addon_template_operators_mytool_ot_offset_selected_invoke": ".invoke()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L23 | neighbors=[MYTOOL_OT_offset_selected, .execute()]
- "addon_template_ui_mytool_ap_preferences": "MYTOOL_AP_preferences" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L20 | neighbors=[ui.py, .draw()]
- "addon_template_ui_mytool_pt_main": "MYTOOL_PT_main" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L4 | neighbors=[ui.py, .draw()]
- "animation_build_animations_interp": "interp()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L8 | neighbors=[build_animations.py, smooth()]
- "animation_build_animations_smooth": "smooth()" | kind=code-symbol | source=assets/characters/animation/build_animations.py:L6 | neighbors=[build_animations.py, interp()]
- "animation_v2_build_refined_interp": "interp()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L11 | neighbors=[build_refined.py, ease()]
- "animation_v2_check_model_structure_capture": "capture()" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L9 | neighbors=[check_model_structure.py, floats()]
- "animation_v2_check_model_structure_floats": "floats()" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L5 | neighbors=[check_model_structure.py, capture()]
- "authority_pkb_schema_is_protected_domain": "is_protected_domain()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L78 | neighbors=[pkb_schema.hpp, load_pkb_schema()]
- "authority_pkb_schema_load_pkb_schema": "load_pkb_schema()" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L92 | neighbors=[pkb_schema.hpp, is_protected_domain()]
- "authority_pkb_schema_pkbauthority": "PkbAuthority" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L224 | neighbors=[pkb_schema.hpp, .PkbAuthority()]
- "authority_projection_gate": "projection_gate.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/projection_gate.hpp:L1 | neighbors=[ProjectionGate, 6e2fe3a Created BAK-7 and other BAK tas…]
- "authority_projection_gate_projectiongate": "ProjectionGate" | kind=code-symbol | source=server/authority/include/poko/authority/projection_gate.hpp:L34 | neighbors=[projection_gate.hpp, .ProjectionGate()]
- "authority_replay_ring_cbor_bool": "cbor_bool()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L102 | neighbors=[replay_ring.hpp, encode_replay()]
- "authority_replay_ring_emit_litlen": "emit_litlen()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L168 | neighbors=[replay_ring.hpp, encode_replay()]
- "authority_rule_evaluator_ruleparser": "RuleParser" | kind=code-symbol | source=server/authority/include/poko/authority/rule_evaluator.hpp:L75 | neighbors=[rule_evaluator.hpp, .RuleParser()]
- "authority_session": "session.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/session.hpp:L1 | neighbors=[SessionAuthority, 6568dc9 Update from ML AI Code]
- "authority_session_sessionauthority": "SessionAuthority" | kind=code-symbol | source=server/authority/include/poko/authority/session.hpp:L62 | neighbors=[session.hpp, .SessionAuthority()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-093.json

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
