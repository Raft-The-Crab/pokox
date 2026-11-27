# Node Description Batch 33 of 208

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
- "candyland_candy_map_h0": "H0()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L88 | neighbors=[candy_map.py, H(), bump(), path_mask(), frosting land before the river / castle…]
- "candyland_candy_map_river": "river()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L385 | neighbors=[candy_map.py, chocolate river surface (glossy, streak…, H(), mesh_obj(), resample()]
- "candyland_candy_props_bell_r": "bell_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L747 | neighbors=[candy_props.py, choco_falls(), gumdrop_mountain(), icing_cap(), gumdrop bell radius at height y (0..Hh)]
- "candyland_candy_props_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L971 | neighbors=[candy_props.py, MS(), soft(), striped_tube(), candy-cane 'tree': helical-striped cane…]
- "candyland_candy_props_cotton_candy_tree": "cotton_candy_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1007 | neighbors=[candy_props.py, MS(), soft(), striped_tube(), cotton-candy tree: twisting pretzel tru…]
- "candyland_candy_props_donut_arch": "donut_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L936 | neighbors=[candy_props.py, drip(), soft(), sprinkles_on(), giant glazed donut standing on edge ove…]
- "candyland_candy_props_waffle_shade": "waffle_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L633 | neighbors=[candy_props.py, candy_castle(), cone_tower(), giant_cone(), waffle_bridge()]
- "canyonbazaar_canyon_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L161 | neighbors=[canyon_map.py, look(), nature(), stories(), under_wall()]
- "canyonbazaar_canyon_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L175 | neighbors=[canyon_map.py, build(), H(), on_paving(), static()]
- "canyonbazaar_canyon_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L224 | neighbors=[canyon_map.py, build(), H(), static(), distant buttes and mesas all round (fla…]
- "canyonbazaar_canyon_map_hw": "hw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L33 | neighbors=[canyon_map.py, nature(), set_pieces(), stories(), tdist()]
- "canyonbazaar_canyon_map_path_x": "path_x()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L93 | neighbors=[canyon_map.py, on_paving(), cx(), paving(), main path centre: follows the canyon, s…]
- "canyonbazaar_canyon_map_paving": "paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L255 | neighbors=[canyon_map.py, build(), path_x(), static(), _stones()]
- "canyonbazaar_canyon_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L162 | neighbors=[canyon_map.py, build(), nature(), set_pieces(), stories()]
- "canyonbazaar_canyon_map_under_wall": "under_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L137 | neighbors=[canyon_map.py, place(), True where the built cliff mesh (vertic…, free(), H()]
- "canyonbazaar_canyon_map_wall": "wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L48 | neighbors=[canyon_map.py, H(), stepped mesa profile at t studs past th…, levels(), shelf1()]
- "canyonbazaar_canyon_props_relic_kiosk": "relic_kiosk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_props.py:L668 | neighbors=[canyon_props.py, RELIC / PET station on the ledge: a sma…, dais(), pot(), sign_board()]
- "cavemap_cave_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L201 | neighbors=[cave_map.py, build(), landmarks(), rails(), under_lake()]
- "cavemap_cave_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L724 | neighbors=[cave_map.py, free(), H(), sky_at(), wd()]
- "cavemap_cave_map_sky_at": "sky_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L32 | neighbors=[cave_map.py, build(), landmarks(), look(), shapes()]
- "cavemap_cave_ores_cart_load": "cart_load()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L135 | neighbors=[cave_ores.py, druse(), mound(), ore_lump(), v2 load: lumps packed into the tub mout…]
- "cavemap_cave_ores_ore_lump": "ore_lump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L47 | neighbors=[cave_ores.py, cart_load(), _lump(), ore_pile(), one ore lump: host rock faces + metalli…]
- "cavemap_cave_props_jitter": "jitter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L78 | neighbors=[cave_props.py, geode(), low-frequency noise displacement along …, stalactite(), stalagmite()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-032.json

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
