# Node Description Batch 14 of 209

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

- "scripts_precipitation": "precipitation.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build_tree(), _camera_box(), _iface(), _material()]
- "scripts_precipitation_t": "_T" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/precipitation.py:L38 | neighbors=[precipitation.py, build_tree(), Minimal node-graph helper: n(type, inpu…, .__init__(), .math(), .n()]
- "scripts_sim_setup": "sim_setup.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-simulation/scripts/sim_setup.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _asset_group(), _ctx(), _num(), run()]
- "scripts_smart_material_build_group": "build_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texturing/scripts/smart_material.py:L86 | neighbors=[smart_material.py, _G, .link(), .math(), .mix(), .mrange()]
- "scripts_surface_weather_build_group": "build_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L79 | neighbors=[surface_weather.py, _G, .link(), .math(), .mix(), .mrange()]
- "scripts_toon_setup_build_group": "build_group()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L81 | neighbors=[toon_setup.py, _G, .link(), .math(), .mix(), .n()]
- "scripts_toon_setup_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L282 | neighbors=[toon_setup.py, _apply_mat(), build_group(), _key_light(), _lin(), _line_art()]
- "scripts_turntable": "turntable.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _area(), _backdrop(), _bounds(), _clear()]
- "scripts_verify_desktop": "verify_desktop.py" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, f4a6ac4 Allowlist known validation-laye…, classify(), main(), parse_runtime(), run_step()]
- "skyrise_sky_models": "sky_models.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bevel_box(), blossom_tree(), island_under(), lumpy()]
- "src_camera": "camera.cpp" | kind=code-symbol | source=engine/render/src/camera.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, look_at(), multiply(), orbit(), perspective(), view_proj()]
- "src_character_controller_update": "update()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L206 | neighbors=[character_controller.cpp, capsule_at(), cast_fraction(), deepest_contact(), planar(), shape_bound()]
- "src_config_load_file": "load_file()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L100 | neighbors=[config.cpp, collect_unknown(), fail(), find_key(), parse_level(), read_bool()]
- "src_frame_stats": "frame_stats.cpp" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, cpu_ms(), fps(), gpu_ms(), record_cpu(), record_gpu()]
- "src_gallery": "gallery.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, drum(), flat(), ground(), put()]
- "src_loop": "loop.cpp" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, advance(), alpha(), backlog_seconds(), FixedStepLoop(), reset_backlog()]
- "src_pokomesh": "pokomesh.cpp" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, fail(), finite_vec3(), load_pokomesh(), parse_pokomesh(), read_f32()]
- "state_state": "state.cpp" | kind=code-symbol | source=mute/src/state/state.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, hash_state(), merge(), read32(), read64(), round()]
- "tests_test_mesh_io": "test_mesh_io.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_mesh_io.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_bed_fit_allows_rotation_and_report…, test_estimate_mass_hollow_less_than_sol…, test_load_mesh_empty_file(), test_load_mesh_missing_file()]
- "tests_test_package_vfx": "vfx()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_package.py:L14 | neighbors=[test_package.py, Run the CLI with the test interpreter; …, test_a_fresh_project_lints_a_recipe_tha…, test_cli_init_examples_and_lint_in_a_fr…, test_doctor_reports_an_initialised_work…, test_effect_verify_reports_missing_evid…]
- "texture_tex_to_maps_process": "process()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L106 | neighbors=[tex_to_maps.py, main(), derive_ao(), derive_normal(), derive_roughness(), high_pass()]
- "texture_tile_seam_check": "tile_seam_check.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, assess(), boundary_metrics(), load_gray(), main()]
- "tools_math_determinism": "math_determinism.py" | kind=code-symbol | source=mute/tools/math_determinism.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, compare(), load_corpus(), load_trace(), main(), _object()]
- "towncity_town_map_landmarks": "landmarks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L284 | neighbors=[town_map.py, build(), anchor(), face(), place(), reserve()]
- "towncity_town_props_window_unit": "window_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L198 | neighbors=[town_props.py, building(), dressing for ONE opening in a front wal…, add(), flower_box(), front_quad()]
- "unit_bench_test": "bench_test.cpp" | kind=code-symbol | source=mute/tests/unit/bench_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, bench(), best_ns(), cases(), check(), compile()]
- "unit_character_controller_test": "character_controller_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/character_controller_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, aabb(), fx(), main(), params(), tod()]
- "unit_device_router_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L54 | neighbors=[device_router_test.cpp, apply_events(), connect(), disconnect(), pad_axis(), pad_button()]
- "unit_diff_test": "diff_test.cpp" | kind=code-symbol | source=mute/tests/unit/diff_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, cases(), check(), compile(), diff_case(), main()]
- "unit_emit_test_i32": "i32()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L14 | neighbors=[emit_test.cpp, arith_module(), calls_module(), cases(), compile_source(), hostcall_module()]
- "unit_lexer_contract_test": "lexer_contract_test.cpp" | kind=code-symbol | source=mute/tests/unit/lexer_contract_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, check(), deterministic_streams(), diagnostic(), examples(), main()]
- "unit_narrowphase_test": "narrowphase_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L1 | neighbors=[06cfbe9 Narrowphase: local pair frame +…, 69287a0 Land ENG-60-65 deterministic si…, 9eeb3ff Merge pull request #2 from Raft…, aabb(), main(), sphere()]
- "unit_vulkan_triangle_pass_test": "vulkan_triangle_pass_test.cpp" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, draw_and_present(), main(), messages(), reset(), VulkanClearRenderer()]
- "valleylake_valley_map_h0": "H0()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L89 | neighbors=[valley_map.py, H(), in_terr(), islet(), lake_d(), sand_w()]
- "valleylake_valley_props_house": "house()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L517 | neighbors=[valley_props.py, engawa(), flat(), footing(), gable_roof(), .add()]
- "voidrealm_void_props_quest_stand": "quest_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L519 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), sign_plate()]
- "voidrealm_void_props_shop_kiosk": "shop_kiosk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L436 | neighbors=[void_props.py, Void Merchant: dais, stone counter with…, chamfer_box(), FS(), rune_glyph(), shaft()]
- "voidrealm_void_props_upgrade_altar": "upgrade_altar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L474 | neighbors=[void_props.py, Ascension Altar: round 3-step dais, fac…, annulus(), chamfer_box(), flame(), FS()]
- "warehouse_wh_props_pallet_load": "pallet_load()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L113 | neighbors=[wh_props.py, floor_pallet(), load_cartons(), load_crates(), load_drums(), load_sacks()]
- "whispering_grove_forest_props_blob": "blob()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L46 | neighbors=[forest_props.py, bush(), campfire(), elder_tree(), flower_patch(), leafy()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-013.json

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
