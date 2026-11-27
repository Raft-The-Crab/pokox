# Node Description Batch 18 of 207

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

- "valleylake_valley_props_blossom_tree": "blossom_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L289 | neighbors=[valley_props.py, clump(), flat(), leaf_cluster(), limb(), .add()]
- "valleylake_valley_props_boulder": "boulder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L148 | neighbors=[valley_props.py, moss_cap(), rim_shade(), rounded_mass(), RS(), .add()]
- "valleylake_valley_props_dock": "dock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L678 | neighbors=[valley_props.py, barrel(), crate(), flat(), paper_lantern(), .add()]
- "valleylake_valley_props_leaf_mass": "leaf_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L894 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), clump(), .add(), V()]
- "valleylake_valley_props_limb": "limb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L237 | neighbors=[valley_props.py, blossom_tree(), broadleaf(), gnarled_tree(), lerp(), .add()]
- "valleylake_valley_props_paper_lantern": "paper_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L630 | neighbors=[valley_props.py, dock(), lantern_rope(), market_stall(), flat(), .add()]
- "valleylake_valley_props_rounded_mass": "rounded_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L64 | neighbors=[valley_props.py, boulder(), footing(), pillowy rounded-box mass: a subdivided …, rock_steps(), stone_stair()]
- "valleylake_valley_props_skel": "Skel" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L862 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), node list [(pos, radius)] + edges; help…, Palette, .add()]
- "vfxkit_build_build": "build()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L90 | neighbors=[build.py, check_output_dirs(), check_resource_conflicts(), check_targets(), eid(), owned()]
- "vfxkit_evidence_capture_issues": "capture_issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L190 | neighbors=[evidence.py, build_issues(), dependencies(), read_build(), stage_snapshot(), template_issues()]
- "vfxkit_evidence_store": "store()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L23 | neighbors=[evidence.py, latest(), read_build(), read_capture(), submit(), verify()]
- "vfxkit_lint_lint": "lint()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L105 | neighbors=[lint.py, colours(), documented_textures(), hot(), release_frames(), screen_errors()]
- "vfxkit_primitives_beam": "beam()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L433 | neighbors=[primitives.py, _beam_strip(), fade(), radial_sparks(), ramp(), smoke()]
- "vfxkit_sequence_frame_number": "_frame_number()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L155 | neighbors=[sequence.py, capture(), concept_compare(), handoff(), paintover(), sheet_around_steps()]
- "vfxkit_sequence_read": "read()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L47 | neighbors=[sequence.py, capture(), concept_compare(), handoff(), issues(), paintover()]
- "vfxkit_sequence_submit": "submit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L368 | neighbors=[sequence.py, criteria(), _frame_number(), gate_path(), issues(), _now()]
- "voidrealm_void_props_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L551 | neighbors=[void_props.py, spawn platform: big round stepped dais,…, annulus(), chamfer_box(), FS(), rune_circle()]
- "warehouse_fitlib": "fitlib.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, add_owner(), fit(), fit_bad(), _inb()]
- "whispering_grove_forest_props_campfire": "campfire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L392 | neighbors=[forest_props.py, at(), blob(), flame_tongue(), Prop, .add()]
- "whispering_grove_forest_props_log": "log()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L264 | neighbors=[forest_props.py, at(), blob(), mushroom(), Prop, .add()]
- "whispering_grove_forest_props_mushroom": "mushroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L229 | neighbors=[forest_props.py, log(), at(), Prop, .add(), .gadd()]
- "window_sdl_platform": "sdl_platform.cpp" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, create_window(), destroy_window(), get_window_size(), initialize(), poll_event()]
- "work_test_uv_overlap_overlaptests": "OverlapTests" | kind=code-symbol | source=assets/characters/work/test_uv_overlap.py:L5 | neighbors=[test_uv_overlap.py, .test_bounding_boxes_overlap_but_triang…, .test_edge_and_point_contact_are_not_ov…, .test_identical_cross_mesh_triangles_ar…, .test_invalid_values_rejected(), .test_outside_atlas_and_degenerate()]
- "animation_v2_build_refined": "build_refined.py" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L1 | neighbors=[ease(), foot(), interp(), loc(), rot(), Generate separate R6 clips from untouch…]
- "brainstorm_server_branding_test_test": "test()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L110 | neighbors=[branding.test.js, assertBrandedWithLogo(), assertFramedLogoSupportsDarkTheme(), assertFramedScreenUsesBrandHeader(), assertHeaderAvoidsNarrowOverlap(), assertLogoKeepsTransparentBackground()]
- "brick_bone_hydra_brick_head": "head()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L263 | neighbors=[bone_hydra_brick.py, dil(), J2L(), newid(), put(), sl_of()]
- "brick_lich_king_brick_shift": "shift()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/lich_king_brick.py:L55 | neighbors=[lich_king_brick.py, back_layer(), cube_dil(), dil(), ero(), front_face()]
- "brick_props_brick_grass_base": "grass_base()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L46 | neighbors=[props_brick.py, bush(), oak(), pine(), mossy ground disc with stepped edge + a…, rocks()]
- "bytecode_bytecode_disassemble_bytecode": "disassemble_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L191 | neighbors=[bytecode.cpp, assemble_bytecode(), branch(), branch_offset(), long_offset(), mnemonic()]
- "cad_skill_main_gridfinity_gridfinitybin_compartment_solids": "._compartment_solids()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L569 | neighbors=[GridfinityBin, .build(), ._compartment_size(), ._label_shelf(), ._scoop(), _rounded_rect()]
- "cad_skill_main_gridfinity_gridfinitybin_validate": "._validate()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L321 | neighbors=[GridfinityBin, .build(), ._check_depth(), ._check_wall_clearance(), ._compartment_size(), ._cylinder_drop()]
- "cad_skill_main_mesh_io": "mesh_io.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L1 | neighbors=[bed_fit(), estimate_mass(), load_mesh(), parse_bed(), Pure trimesh STL loading with validatio…, 2680d0e Pushed an update.]
- "cad_skill_main_preview_render_multi_view": "render_multi_view()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L361 | neighbors=[preview.py, main(), Render 6-view technical preview in a 3x…, _build_scene(), _get_font(), _info_lines()]
- "cad_skill_main_run_cadquery_model": "run_cadquery_model.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L1 | neighbors=[_append_stderr(), main(), _new_files_by_ext(), _process_stls(), _sibling(), 2680d0e Pushed an update.]
- "candyland_candy_props_drawbridge": "drawbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L729 | neighbors=[candy_props.py, ball(), lathe(), MS(), round_prof(), striped_tube()]
- "candyland_candy_props_drip": "drip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L181 | neighbors=[candy_props.py, donut_arch(), lathe(), drip_ring(), giant_cone(), icing_cap()]
- "candyland_candy_props_giant_cone": "giant_cone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1146 | neighbors=[candy_props.py, drip(), lathe(), soft(), waffle_lathe(), waffle_shade()]
- "candyland_candy_props_icing_cap": "icing_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L752 | neighbors=[candy_props.py, choco_falls(), gumdrop_mountain(), bell_r(), drip(), lathe()]
- "candyland_candy_props_piping": "piping()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L211 | neighbors=[candy_props.py, candy_castle(), cone_tower(), icing piping along a polyline: beaded (…, sign_plate(), spawn_cookie()]
- "candyland_candy_props_sugar": "sugar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L50 | neighbors=[candy_props.py, bakery_oven(), choco_falls(), gumdrop_bush(), gumdrop_mountain(), sugar-coated: height gradient plus fine…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-017.json

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
