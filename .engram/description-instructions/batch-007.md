# Node Description Batch 8 of 207

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

- "pi_test_pi_extension": "test-pi-extension.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/pi/test-pi-extension.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, __dirname, emit(), extensionPath, firstHandler()]
- "plugins_superpowers": "superpowers.js" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bootstrapCache, _cacheChildSession(), _childSessionCache, __dirname]
- "plusspeed_plus_props_v3_shop_stall": "shop_stall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L111 | neighbors=[plus_props_v3.py, SPEED SHOP: platform with a ramp, panel…, barrel(), bulbs_frame(), chamfer_block(), cyl_v()]
- "scripts_smart_material": "smart_material.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_mat(), build_group(), curvature_attribute(), _G]
- "scripts_surface_weather": "surface_weather.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_mat(), build_group(), _G, _remove_mat()]
- "scripts_template_engine": "template_engine.py" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, compile_template(), EachNode, get_nested_val(), IfNode]
- "src_solver": "solver.cpp" | kind=code-symbol | source=engine/physics/src/solver.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, add_contact(), begin_step(), clear()]
- "tests_fixtures": "fixtures.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, cube(), detached_part(), mesh_object(), plane()]
- "tests_test_examples": "test_examples.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_examples.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, example_ids(), test_catalog_lists_every_shipped_exampl…, test_each_example_source_loads_and_matc…, test_example_show_accepts_pair_and_sing…]
- "tests_test_qa_qa": "_qa()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_qa.py:L9 | neighbors=[test_qa.py, test_clean_cube_passes(), test_detects_floating_parts_and_objects…, test_detects_inverted_and_inconsistent_…, test_detects_zfighting_between_objects_…, test_enclosed_part_is_not_floating()]
- "tests_test_tools": "test_tools.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tests/test_tools.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_ablation_corrupt_json_exits_2(), test_ablation_verdicts(), test_flat_interior_with_seam_fails(), test_flat_tile_is_seamless()]
- "unit_capability_test": "capability_test.cpp" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 952997e Audit MUT-01-55 and harden veri…, ceiling(), check(), def(), i32()]
- "unit_input_snapshot_test": "input_snapshot_test.cpp" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, button(), gamepad_axis(), gamepad_button(), key(), main()]
- "unit_lower_test": "lower_test.cpp" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L1 | neighbors=[2c0194b Add assignments and loop-carrie…, 4cead55 Add MUT-27 bytecode verificatio…, 85b7130 Close MUT-26 limits: AST-to-SSA…, 90b7d79 Add for-range lowering to Mute …, 952997e Audit MUT-01-55 and harden veri…, cases()]
- "unit_sdl_platform_faults": "sdl_platform_faults.cpp" | kind=code-symbol | source=engine/platform/tests/unit/sdl_platform_faults.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Exception, main(), push(), SDL_CreateWindow(), SDL_DestroyWindow()]
- "vfxkit_build": "build.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), check_output_dirs(), check_resource_conflicts(), check_targets()]
- "vfxkit_ownership": "ownership.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, digest(), guard(), inside(), may_use()]
- "vfxkit_scale": "scale.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, apply(), factors(), _frames(), _layers()]
- "vfxkit_sequence_capture": "capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L199 | neighbors=[sequence.py, _frame_number(), _lab_capture(), _now(), path(), read()]
- "vfxkit_unity_textures": "textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L99 | neighbors=[unity.py, install(), Write every texture the package's share…, _blob(), _inner_gradient(), _mask()]
- "vm_values_object": "object()" | kind=code-symbol | source=mute/src/vm/values.cpp:L12 | neighbors=[values.cpp, as_string(), copy_impl(), free_slot(), get_index(), length()]
- "voidrealm_void_map_bridges": "bridges()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L225 | neighbors=[void_map.py, anchor(), edge_pt(), face(), H(), inner()]
- "voidrealm_void_map_dressing": "dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L333 | neighbors=[void_map.py, build(), clip_frac(), face(), free(), island_of()]
- "voidrealm_void_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L78 | neighbors=[void_map.py, bridges(), dressing(), foot(), H(), kit()]
- "warehouse_wh_struct": "wh_struct.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_struct.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, crane_bridge(), crane_trolley(), dock_door(), high_bay()]
- "candyland_candy_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L530 | neighbors=[candy_map.py, anchor(), dist_castle(), face(), free(), H()]
- "candyland_candy_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L105 | neighbors=[candy_map.py, build(), drape_strip(), ground(), castle_h(), dist_castle()]
- "candyland_candy_props_bakery_oven": "bakery_oven()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L417 | neighbors=[candy_props.py, ball(), drip_ring(), lathe(), MS(), round_prof()]
- "candyland_candy_props_cupcake_fountain": "cupcake_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L282 | neighbors=[candy_props.py, ball(), cupcake_liner(), drip_ring(), lathe(), MS()]
- "candyland_candy_props_egg_machine": "egg_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L482 | neighbors=[candy_props.py, ball(), candy_egg(), lathe(), MS(), round_prof()]
- "candyland_candy_props_striped_tube": "striped_tube()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L149 | neighbors=[candy_props.py, bakery_oven(), candy_cane(), candy_castle(), candy_lamp(), cotton_candy_tree()]
- "candyland_candy_props_sweet_shop": "sweet_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L343 | neighbors=[candy_props.py, SWEET SHOP: gingerbread cottage, chocol…, ball(), gable_roof_bars(), lathe(), MS()]
- "canyonbazaar_canyon_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L78 | neighbors=[canyon_map.py, ground(), mouth(), on_paving(), tdist(), wall()]
- "cavemap_cave_map_fungi": "fungi()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L566 | neighbors=[cave_map.py, build(), free(), in_hole(), lake_d(), light()]
- "cavemap_cave_props_strata_mass": "strata_mass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props.py:L85 | neighbors=[cave_props.py, crystal_spray(), geode(), glow_vine(), lake_glow(), mound()]
- "cavemap_cave_props2_logp": "logp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props2.py:L8 | neighbors=[cave_props2.py, crates(), mine_cart(), mine_frame(), mine_lantern_post(), ore_pile()]
- "commit:repo:github.com/Raft-The-Crab/pokox@6568dc953fff853264807a3c4242300ec826ce6e": "6568dc9 Update from ML AI Code" | kind=Commit | source=git | neighbors=[pkb_schema.hpp, session.hpp, main, revocation_gate.hpp, worker_auth.hpp, test_version.py]
- "commit:repo:github.com/Raft-The-Crab/pokox@981b52c0fa225f4845fc34ad2471fc9bce3ddb28": "981b52c Crated IDN-01 to IDN-04" | kind=Commit | source=git | neighbors=[7eabc2d Merge pull request #8 from Raft…, main, 1dac49d Created NET-01 to NET-09, Start…, account_record.hpp, device_binding.hpp, sign_in.hpp]
- "creaturelab_lab_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L570 | neighbors=[lab_map.py, exterior(), garden_paths(), ground(), hall_floor(), hardscape()]
- "creaturelab_lab_map_exterior": "exterior()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L477 | neighbors=[lab_map.py, build(), anchor(), face_in(), free(), path_free()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-007.json

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
