# Node Description Batch 44 of 207

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

- "whispering_grove_forest_props_signpost": "signpost()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L441 | neighbors=[forest_props.py, at(), Prop, .add(), S()]
- "whispering_grove_forest_props_stepping_stones": "stepping_stones()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L592 | neighbors=[forest_props.py, at(), Prop, .add(), S()]
- "whispering_grove_forest_props_tent": "tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L367 | neighbors=[forest_props.py, at(), Prop, .add(), S()]
- "work_uv_overlap_intersection_area": "intersection_area()" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L22 | neighbors=[uv_overlap.py, find_cross_mesh_overlaps(), _cross(), _signed_area(), Return the UV area common to two triang…]
- "addon_template_operators": "operators.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-addon-development/assets/addon_template/operators.py:L1 | neighbors=[MYTOOL_OT_offset_selected, MYTOOL_PG_settings, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "authority_pkb_schema": "pkb_schema.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/pkb_schema.hpp:L1 | neighbors=[is_protected_domain(), load_pkb_schema(), PkbAuthority, 6568dc9 Update from ML AI Code]
- "bin_trace_processor_get_perfetto_prebuilt": "get_perfetto_prebuilt()" | kind=code-symbol | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L259 | neighbors=[trace_processor, download_or_get_cached(), Downloads the prebuilt, if necessary, a…, run_perfetto_prebuilt()]
- "blender_character_blockout_box": "box()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L134 | neighbors=[character_blockout.py, get_collection(), link(), build()]
- "blender_character_blockout_sphere": "sphere()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L159 | neighbors=[character_blockout.py, build(), get_collection(), link()]
- "blender_render_compare_views_render_turnaround": "render_turnaround()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L161 | neighbors=[render_compare_views.py, setup_camera(), setup_lighting(), setup_render()]
- "blender_validate_scene_find_isolated": "find_isolated()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L92 | neighbors=[validate_scene.py, scene_bounds(), Objects floating away from the body mas…, validate()]
- "blender_validate_scene_find_strays": "find_strays()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L68 | neighbors=[validate_scene.py, scene_bounds(), Objects whose bounds break the envelope…, validate()]
- "blender_validate_scene_landmarks": "landmarks()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L112 | neighbors=[validate_scene.py, scene_bounds(), Measured landmark heights, for proporti…, validate()]
- "brainstorm_server_lifecycle_test": "lifecycle.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/lifecycle.test.js:L1 | neighbors=[2680d0e Pushed an update., 72b9ac7 Merge branch 'main' into mini-c…, 7eabc2d Merge pull request #8 from Raft…, e77fa31 Add new skills and asset packs …]
- "brick_abyssal_angler_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L295 | neighbors=[abyssal_angler_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_arcane_train_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/arcane_train_brick.py:L171 | neighbors=[arcane_train_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_bone_hydra_brick_cap": "cap()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L50 | neighbors=[bone_hydra_brick.py, full(), sl_of(), chain()]
- "brick_bone_hydra_brick_obox": "obox()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L78 | neighbors=[bone_hydra_brick.py, dspike(), full(), sl_of()]
- "brick_frost_mammoth_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/frost_mammoth_brick.py:L246 | neighbors=[frost_mammoth_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_kraken_brick_tentacle": "tentacle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_brick.py:L102 | neighbors=[kraken_brick.py, catmull(), ix(), newid()]
- "brick_lich_king_brick_chain": "chain()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L51 | neighbors=[lich_king_brick.py, cap(), flames(), sleeve()]
- "brick_lich_king_brick_ci": "ci()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L73 | neighbors=[lich_king_brick.py, band_edge(), stamp(), surfz()]
- "brick_lich_king_brick_flames": "flames()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L372 | neighbors=[lich_king_brick.py, cap(), chain(), glow()]
- "brick_living_armor_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L382 | neighbors=[living_armor_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_living_armor_brick_flame": "flame()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/living_armor_brick.py:L258 | neighbors=[living_armor_brick.py, put(), ring(), tuft()]
- "brick_mimic_chest_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/mimic_chest_brick.py:L351 | neighbors=[mimic_chest_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_props_brick_scifi_pistol": "scifi_pistol()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L392 | neighbors=[props_brick.py, white + silver sci-fi pistol, muzzle up…, poly(), stroke()]
- "brick_props_brick_stroke": "stroke()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L326 | neighbors=[props_brick.py, thick polyline (bow limbs, strings, tho…, scifi_pistol(), thorn_bow()]
- "brick_props_brick_thorn_bow": "thorn_bow()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L341 | neighbors=[props_brick.py, dark thorn bow (R=8): limbs curling bac…, poly(), stroke()]
- "brick_props_brick_trunk": "trunk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L28 | neighbors=[props_brick.py, oak(), pine(), tapered trunk: radius r0 at the base ->…]
- "brick_scarecrow_king_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L435 | neighbors=[scarecrow_king_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_scarecrow_king_brick_chaind": "chaind()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L60 | neighbors=[scarecrow_king_brick.py, axd(), chain(), capd()]
- "brick_scarecrow_king_brick_patch": "patch()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L139 | neighbors=[scarecrow_king_brick.py, bx(), newid(), put()]
- "brick_scarecrow_king_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L43 | neighbors=[scarecrow_king_brick.py, patch(), strand(), wood()]
- "brick_scarecrow_king_brick_strand": "strand()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scarecrow_king_brick.py:L182 | neighbors=[scarecrow_king_brick.py, chain(), put(), tuft()]
- "brick_scorpion_king_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L222 | neighbors=[scorpion_king_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_scorpion_king_brick_seg": "seg()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/scorpion_king_brick.py:L108 | neighbors=[scorpion_king_brick.py, cap(), newid(), put()]
- "brick_storm_griffin_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/storm_griffin_brick.py:L400 | neighbors=[storm_griffin_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_swamp_croc_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L245 | neighbors=[swamp_croc_brick.py, exposed(), lin(), exposed brick faces as flat quads; UVs …]
- "brick_swamp_croc_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/swamp_croc_brick.py:L47 | neighbors=[swamp_croc_brick.py, leg(), pyramid(), strand()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-043.json

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
