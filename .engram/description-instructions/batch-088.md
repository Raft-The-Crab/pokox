# Node Description Batch 89 of 207

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

- "vfxkit_workflow_unchanged": "unchanged()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L58 | neighbors=[workflow.py, absolute(), file_hash()]
- "vm_hostcall_add": "add()" | kind=code-symbol | source=mute/src/vm/hostcall.cpp:L10 | neighbors=[hostcall.cpp, find(), host_type()]
- "vm_hostcall_find": "find()" | kind=code-symbol | source=mute/src/vm/hostcall.cpp:L28 | neighbors=[hostcall.cpp, add(), unauthorized_hostcalls()]
- "vm_scheduler_find": "find()" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L4 | neighbors=[scheduler.cpp, cancel(), run()]
- "vm_values_handle_for": "handle_for()" | kind=code-symbol | source=mute/src/vm/values.cpp:L8 | neighbors=[values.cpp, make_array(), make_string()]
- "vm_values_promote": "promote()" | kind=code-symbol | source=mute/src/vm/values.cpp:L203 | neighbors=[values.cpp, object(), set_index()]
- "vm_values_reaches": "reaches()" | kind=code-symbol | source=mute/src/vm/values.cpp:L91 | neighbors=[values.cpp, object(), set_index()]
- "vm_values_reset_tick": "reset_tick()" | kind=code-symbol | source=mute/src/vm/values.cpp:L181 | neighbors=[values.cpp, free_slot(), object()]
- "vm_vm_core_fail": "fail()" | kind=code-symbol | source=mute/src/vm/vm_core.cpp:L38 | neighbors=[vm_core.hpp, step(), VmCore]
- "voidrealm_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, lua_attrs()]
- "voidrealm_void_map_clip_frac": "clip_frac()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L99 | neighbors=[void_map.py, dressing(), share of a placed kit prop's body (abov…]
- "voidrealm_void_map_edge_pt": "edge_pt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L215 | neighbors=[void_map.py, bridges(), Rfun()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-088.json

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
