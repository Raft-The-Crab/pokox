# Node Description Batch 38 of 208

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

- "petsim_pet_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L194 | neighbors=[pet_map.py, crystal(), egg_stand(), hub(), link()]
- "petsim_pet_map_frame": "frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L537 | neighbors=[pet_map.py, build(), place(), seg_d(), clouds + rocks on the lagoon round the …]
- "petsim_pet_map_isle_mesh": "isle_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L59 | neighbors=[pet_map.py, build(), isle_R(), top_y(), polar top (dome) + rounded icing should…]
- "petsim_pet_map_path": "path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L217 | neighbors=[pet_map.py, build(), hub(), catmull(), zone()]
- "petsim_pet_map_plaza": "plaza()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L255 | neighbors=[pet_map.py, hub(), H(), static(), polar tile disc: rings of soft tiles al…]
- "petsim_pet_map_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L48 | neighbors=[pet_map.py, H(), isle_mesh(), isle_R(), polar()]
- "petsim_pet_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1032 | neighbors=[pet_props.py, ell(), rbox(), soft(), chubby rounded bench: two soft seat sla…]
- "petsim_pet_props_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L682 | neighbors=[pet_props.py, ell(), rbox(), soft(), rounded treasure chest: plank body, dom…]
- "petsim_pet_props_giant_donut": "giant_donut()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L943 | neighbors=[pet_props.py, flat(), pill(), soft(), pink-frosted donut lying tilted on the …]
- "petsim_pet_props_gift_box": "gift_box()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L702 | neighbors=[pet_props.py, ell(), rbox(), soft(), chubby present: soft box, crossing ribb…]
- "petsim_pet_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L837 | neighbors=[pet_props.py, ell(), flat(), soft(), chubby toadstool: bulgy stem, domed cap…]
- "petsim_pet_props_picnic_set": "picnic_set()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L854 | neighbors=[pet_props.py, ell(), puff(), soft(), checkered blanket (cells alternate red …]
- "petsim_pet_props_rainbow_arch": "rainbow_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L335 | neighbors=[pet_props.py, puff(), soft(), star(), 6 chunky pastel bands on a half circle,…]
- "petsim_pet_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L618 | neighbors=[pet_props.py, round spawn dais: two soft tiers, mint …, paw(), rcyl(), soft()]
- "petsim_pet_props_trade_pad": "trade_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L519 | neighbors=[pet_props.py, flat trade circle: cream disc with a pa…, arc_pts(), rcyl(), soft()]
- "physics_visual_solver": "visual_solver.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/visual_solver.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, VisualSolver, VisualWorld]
- "pkb_pkb_draft": "pkb_draft.cpp" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, head(), make_pkb_schema_draft(), text(), c7a411f Fix MUT-01-20 audit defects in …]
- "plusspeed_plus_props_v3_lamp_pillar": "lamp_pillar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L90 | neighbors=[plus_props_v3.py, chamfer_block(), cyl_v(), octo(), street lantern pillar: chamfered steppe…]
- "plusspeed_plus_props_v3_octo": "octo()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L20 | neighbors=[plus_props_v3.py, hatchery(), lamp_pillar(), 8-sided column from two overlapping blo…, shop_stall()]
- "plusspeed_plus_props_v3_rebirth_altar": "rebirth_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L196 | neighbors=[plus_props_v3.py, REBIRTH portal: 8-sided stepped dais wi…, chamfer_block(), cyl_v(), ring()]
- "plusspeed_plus_props_v3_ring": "ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L29 | neighbors=[plus_props_v3.py, hatchery(), n blocks laid tangent around a circle (…, rebirth_altar(), wins_pad()]
- "program_program_run_stateful_program": "run_stateful_program()" | kind=code-symbol | source=mute/src/program/program.cpp:L321 | neighbors=[program.cpp, run_program(), commit_globals(), fail(), prepare_globals()]
- "program_program_run_stateful_program_bytecode": "run_stateful_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L347 | neighbors=[program.cpp, run_program_bytecode(), commit_globals(), fail(), prepare_globals()]
- "refmatch_compare_background_fit_mask": "background_fit_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L61 | neighbors=[compare.py, _quad_basis(), significant_components(), Segment the subject by subtracting a fi…, subject_mask()]
- "refmatch_compare_letterbox": "letterbox()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L35 | neighbors=[compare.py, _fit_size(), load_rgb(), mask_at_native(), Resize a PIL image into size with aspec…]
- "refmatch_compare_mask_at_native": "mask_at_native()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L414 | neighbors=[compare.py, evaluate(), letterbox(), subject_mask(), Segment at the image's NATIVE resolutio…]
- "refmatch_compare_normalize_mask": "normalize_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L191 | neighbors=[compare.py, evaluate(), _fit_size(), tight_crop(), Crop to the tight subject box, then sca…]
- "refmatch_compare_palette_report": "palette_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L313 | neighbors=[compare.py, evaluate(), _hex(), _kmeans(), _srgb_to_lab()]
- "refmatch_compare_significant_components": "significant_components()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L161 | neighbors=[compare.py, background_fit_mask(), flood_background_mask(), Keep every connected component above a …, subject_mask()]
- "refmatch_palette_report_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L163 | neighbors=[palette_report.py, compare_to_render(), extract(), load_palette(), print_rows()]
- "resource_asset_store": "asset_store.hpp" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, AssetHandle, AssetStore, typed(), c7a411f Fix MUT-01-20 audit defects in …]
- "scripts_apply_stack": "apply_stack.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-hardsurface-modeling/scripts/apply_stack.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, run(), _smooth_faces(), Build (and optionally apply) a producti…]
- "scripts_bake_action_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/bake_action.py:L81 | neighbors=[bake_action.py, _assign(), list_actions(), _mute(), _root_motion()]
- "scripts_batch_process_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-pipeline-automation/scripts/batch_process.py:L97 | neighbors=[batch_process.py, gather(), inventory(), load(), _module()]
- "scripts_bld": "bld.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _c(), Grid, hx()]
- "scripts_bld_c": "_c()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L12 | neighbors=[bld.py, hx(), .box(), .export(), .fbox()]
- "scripts_bld_grid_sl": "._sl()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/bld.py:L24 | neighbors=[Grid, .box(), .cut(), .fbox(), .fcut()]
- "scripts_blocks_mesh_blocks": "mesh_blocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L71 | neighbors=[blocks.py, neon_mat(), rgb_of(), shape_bm(), one solid mesh (palette + studs) + one …]
- "scripts_blocks_rotm": "rotm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L20 | neighbors=[blocks.py, .b(), .put(), (pitch about X, yaw about Y, roll about…, transformed()]
- "scripts_brick_rig_export": "export()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/brick_rig.py:L106 | neighbors=[brick_rig.py, assign(), _dilate6(), _quads(), verify()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-037.json

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
