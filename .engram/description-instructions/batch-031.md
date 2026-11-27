# Node Description Batch 32 of 207

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
- "work_uv_overlap": "uv_overlap.py" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, _cross(), find_cross_mesh_overlaps(), intersection_area(), _signed_area(), Test positive-area overlap between tria…]
- "addon_template_init": "__init__.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/__init__.py:L1 | neighbors=[register(), unregister(), My Tool - Blender extension template (4…, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "addon_template_operators_mytool_ot_offset_selected": "MYTOOL_OT_offset_selected" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L10 | neighbors=[operators.py, .execute(), .invoke(), .poll(), Move selected objects along an axis]
- "addon_template_ui": "ui.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/ui.py:L1 | neighbors=[menu_func(), MYTOOL_AP_preferences, MYTOOL_PT_main, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "bin_trace_processor": "trace_processor" | kind=code-symbol | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L1 | neighbors=[download_or_get_cached(), get_perfetto_prebuilt(), run_perfetto_prebuilt(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "blender_character_blockout_build": "build()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L184 | neighbors=[character_blockout.py, box(), capsule(), get_collection(), sphere()]
- "blender_character_blockout_capsule": "capsule()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L89 | neighbors=[character_blockout.py, build(), get_collection(), link(), Tapered capsule from p0 to p1 with radi…]
- "blender_character_blockout_link": "link()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L82 | neighbors=[character_blockout.py, box(), capsule(), get_collection(), sphere()]
- "blender_explorer_common_assign": "assign()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L87 | neighbors=[explorer_common.py, cylinder(), loft(), rounded_box(), shell_from()]
- "blender_explorer_common_dim": "Dim" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L50 | neighbors=[Explorer character — pass 2: garments, …, explorer_common.py, .__init__(), .w(), .z()]
- "blender_render_compare_views_setup_lighting": "setup_lighting()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L107 | neighbors=[render_compare_views.py, Three-point rig scaled to subject heigh…, render_turnaround(), _area(), _ensure_world()]
- "brainstorm_server_branding_test_withserver": "withServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L92 | neighbors=[branding.test.js, cleanup(), sleep(), startServer(), waitForServer()]
- "brainstorm_server_browser_launcher_test": "browser-launcher.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/browser-launcher.test.js:L1 | neighbors=[assert, {
  browserLauncherForPlatform
}, test(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "brick_bone_hydra_brick_dspike": "dspike()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L188 | neighbors=[bone_hydra_brick.py, newid(), nrm(), obox(), put()]
- "brick_props_brick_oak": "oak()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L55 | neighbors=[props_brick.py, branch(), grass_base(), leaf_col(), trunk()]
- "brick_swamp_croc_brick_leg": "leg()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L135 | neighbors=[swamp_croc_brick.py, box(), chain(), newid(), put()]
- "brick_venom_widow_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/venom_widow_brick.py:L29 | neighbors=[venom_widow_brick.py, band(), eye(), hourglass(), spikes()]
- "cad_skill_main_gridfinity_compound": "_compound()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L148 | neighbors=[gridfinity.py, _fused(), ._base_cells(), .build(), Collect the solids of several workplane…]
- "cad_skill_main_gridfinity_fused": "_fused()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L162 | neighbors=[gridfinity.py, _compound(), ._base_hole_cutter(), .build(), Combine cutter workplanes into one safe…]
- "cad_skill_main_gridfinity_gridfinitybin_base_cells": "._base_cells()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L474 | neighbors=[GridfinityBin, _compound(), ._cell_centers(), .build(), Per-cell base profile: taper, riser, ta…]
- "cad_skill_main_gridfinity_gridfinitybin_base_hole_cutter": "._base_hole_cutter()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L644 | neighbors=[GridfinityBin, _fused(), ._cell_centers(), .build(), Magnet bores and/or screw holes, 4 per …]
- "cad_skill_main_outline_from_scan_main": "main()" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L82 | neighbors=[outline_from_scan.py, align_and_scale(), max_section_outline(), recentered(), rotate_min_square()]
- "cad_skill_main_preview_build_scene": "_build_scene()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L149 | neighbors=[preview.py, _build_grid(), Create a pyrender scene containing the …, render_multi_view(), render_view()]
- "cad_skill_main_preview_render_view": "render_view()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L284 | neighbors=[preview.py, Render the mesh from a specific angle. …, render_single(), _build_scene(), _render_frame()]
- "candyland_candy_map_dist_castle": "dist_castle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L78 | neighbors=[candy_map.py, build(), castle_h(), H(), on_hard()]
- "candyland_candy_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L167 | neighbors=[candy_map.py, add_owner(), build(), look(), soft_pass()]

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
