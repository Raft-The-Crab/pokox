# Node Description Batch 32 of 208

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

- "vfxkit_video_resolve_output": "_resolve_output()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L68 | neighbors=[video.py, flipbook(), grade(), Bare names land in vfx/textures/process…, _in_project(), _png()]
- "vm_register_vm": "register_vm.cpp" | kind=code-symbol | source=mute/src/vm/register_vm.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 952997e Audit MUT-01-55 and harden veri…, run_register_module(), run_register_vm(), c7a411f Fix MUT-01-20 audit defects in …]
- "vm_scheduler": "scheduler.cpp" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L1 | neighbors=[435b4d3 Add MUT-23 cooperative async sc…, cancel(), find(), run(), spawn(), state()]
- "vm_values_copy_impl": "copy_impl()" | kind=code-symbol | source=mute/src/vm/values.cpp:L142 | neighbors=[values.cpp, copy(), make_array(), make_string(), object(), release()]
- "vm_values_free_slot": "free_slot()" | kind=code-symbol | source=mute/src/vm/values.cpp:L23 | neighbors=[values.cpp, alloc(), object(), release(), reset_tick(), set_index()]
- "vm_values_set_index": "set_index()" | kind=code-symbol | source=mute/src/vm/values.cpp:L105 | neighbors=[values.cpp, free_slot(), make_int(), object(), promote(), reaches()]
- "vm_vm_core": "vm_core.hpp" | kind=code-symbol | source=mute/src/vm/vm_core.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, DepthGuard(), fail(), result(), step(), VmCore]
- "voidrealm_void_map_island": "island()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L133 | neighbors=[void_map.py, build(), keel_profile(), Rfun(), static(), top_y()]
- "voidrealm_void_map_ring_scatter": "ring_scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L322 | neighbors=[void_map.py, dressing(), free(), place(), reserve(), Rfun()]
- "voidrealm_void_map_void_debris": "void_debris()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L427 | neighbors=[void_map.py, build(), intentional floaters: chips drifting ne…, island_of(), place(), seg_d()]
- "voidrealm_void_props_crystal_chips": "crystal_chips()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L396 | neighbors=[void_props.py, FS(), shaft(), shard_rock(), V(), ground cover: a low obsidian chip with …]
- "voidrealm_void_props_float_shard": "float_shard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L161 | neighbors=[void_props.py, FS(), shaft(), shard_rock(), V(), broken-off island chip: a crust slab wi…]
- "voidrealm_void_props_pillar": "pillar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L209 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), V(), fluted void-stone column: stepped plint…]
- "voidrealm_void_props_rune_bridge": "rune_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L690 | neighbors=[void_props.py, rune bridge built along -Z from z=+L/2 …, chamfer_box(), FS(), shaft(), V()]
- "voidrealm_void_props_rune_circle": "rune_circle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L290 | neighbors=[void_props.py, flat ceremonial circle: pale trim ring …, annulus(), disc(), FS(), spawn_dais()]
- "voidrealm_void_props_rune_glyph": "rune_glyph()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L198 | neighbors=[void_props.py, abstract rune inlay (never a letter): d…, rift_gate(), annulus(), shop_kiosk(), void_arch()]
- "voidrealm_void_props_sign_plate": "sign_plate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L428 | neighbors=[void_props.py, quest_stand(), blank sign board for a GUI label (no te…, shop_kiosk(), chamfer_box(), FS()]
- "voidrealm_void_props_singularity": "singularity()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L644 | neighbors=[void_props.py, HERO 1 - the Singularity: a black core …, annulus(), FS(), shaft(), shard_rock()]
- "voidrealm_void_props_step_stone": "step_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L728 | neighbors=[void_props.py, floating stepping stone: flat paved top…, annulus(), FS(), shaft(), V()]
- "warehouse_wh_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L229 | neighbors=[wh_map.py, anchor(), deck_y(), place(), rack_row(), yaw_of()]
- "warehouse_wh_yard_tractor_unit": "tractor_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L133 | neighbors=[wh_yard.py, cab-over tractor: high-roof raked cab w…, axle_set(), truck_mirrors(), truck_wheel(), wheel_arch()]
- "whispering_grove_forest_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L65 | neighbors=[forest_map.py, build(), path_info(), stream_d(), place(), spread()]
- "whispering_grove_forest_map_path_info": "path_info()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L53 | neighbors=[forest_map.py, build(), H(), keepout(), segd(), (signed distance past the path edge, pa…]
- "whispering_grove_forest_props_altar": "altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L473 | neighbors=[forest_props.py, at(), Prop, .add(), .gadd(), S()]
- "whispering_grove_forest_props_arch_outline": "arch_outline()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L110 | neighbors=[forest_props.py, arch_cap(), arch_frame(), arch_prism(), arch_tunnel(), door outline in the XY plane, open at t…]
- "whispering_grove_forest_props_birch": "birch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L175 | neighbors=[forest_props.py, at(), leafy(), Prop, .add(), S()]
- "whispering_grove_forest_props_crystal_cluster": "crystal_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L599 | neighbors=[forest_props.py, at(), Prop, .add(), .gadd(), S()]
- "whispering_grove_forest_props_flower_patch": "flower_patch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L294 | neighbors=[forest_props.py, at(), blob(), Prop, .add(), S()]
- "whispering_grove_forest_props_lantern_post": "lantern_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L320 | neighbors=[forest_props.py, at(), Prop, .add(), .gadd(), S()]
- "whispering_grove_forest_props_lily": "lily()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L578 | neighbors=[forest_props.py, at(), blob(), Prop, .add(), S()]
- "whispering_grove_forest_props_oak": "oak()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L65 | neighbors=[forest_props.py, curve(), leafy(), Prop, .add(), S()]
- "addon_template_init": "__init__.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/__init__.py:L1 | neighbors=[register(), unregister(), My Tool - Blender extension template (4…, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "addon_template_operators_mytool_ot_offset_selected": "MYTOOL_OT_offset_selected" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L10 | neighbors=[operators.py, .execute(), .invoke(), .poll(), Move selected objects along an axis]
- "addon_template_ui": "ui.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L1 | neighbors=[menu_func(), MYTOOL_AP_preferences, MYTOOL_PT_main, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "authority_pkb_schema": "pkb_schema.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L1 | neighbors=[is_protected_domain(), load_pkb_schema(), PkbAuthority, 6568dc9 Update from ML AI Code, 6e2fe3a Created BAK-7 and other BAK tas…]
- "bin_trace_processor": "trace_processor" | kind=code-symbol | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L1 | neighbors=[download_or_get_cached(), get_perfetto_prebuilt(), run_perfetto_prebuilt(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "blender_character_blockout_build": "build()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L184 | neighbors=[character_blockout.py, box(), capsule(), get_collection(), sphere()]
- "blender_character_blockout_capsule": "capsule()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L89 | neighbors=[character_blockout.py, build(), get_collection(), link(), Tapered capsule from p0 to p1 with radi…]
- "blender_character_blockout_link": "link()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L82 | neighbors=[character_blockout.py, box(), capsule(), get_collection(), sphere()]
- "blender_explorer_common_assign": "assign()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L87 | neighbors=[explorer_common.py, cylinder(), loft(), rounded_box(), shell_from()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-031.json

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
