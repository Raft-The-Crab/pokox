# Node Description Batch 10 of 209

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

- "scripts_bind_mesh": "bind_mesh.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, cleanup(), _ctx(), _heat_scale(), _height()]
- "scripts_blocks_block": "Block" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L15 | neighbors=[v4 stadium hub: striped infield inside …, stepped canyon: tier n is a row of 24-w…, race kerb along Z: alternating colour/w…, running-track oval: red lane band, whit…, put theme props on cap tops (centre of …, blocks.py]
- "scripts_garment": "garment.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _drape(), _hide_body(), penetration(), _region()]
- "scripts_qa_check": "qa_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _feeds(), _islands(), _material_issues(), _mesh_world()]
- "scripts_surface_weather_g": "_G" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L31 | neighbors=[surface_weather.py, build_group(), .__init__(), .link(), .math(), .mix()]
- "skyrise_sky_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L199 | neighbors=[sky_map.py, face(), island_mesh(), micro_detail(), path_track(), place()]
- "skyrise_sky_props_lathe": "lathe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L39 | neighbors=[sky_props.py, cactus(), crystal_node(), egg_shrine(), gem(), ice_spike()]
- "src_soft_body": "soft_body.cpp" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, add_node(), add_spring(), apply_acceleration(), clamp01(), collide_plane_y()]
- "stdlib_stdlib_string": "stdlib_string.cpp" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, byte_length(), codepoint_count(), compare_bytes(), concat(), decode()]
- "sugarworks_sugar_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L44 | neighbors=[sugar_props.py, buy_button(), cash_pad(), choc_fountain(), coin_chute(), collector()]
- "tests_conftest": "conftest.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/conftest.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bad_script(), _can_symlink(), cli_env(), empty_script()]
- "tests_test_safety_game": "game()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_safety.py:L13 | neighbors=[test_safety.py, test_a_broken_source_only_blocks_itself…, test_a_build_mirrors_only_its_own_resou…, test_a_build_never_replaces_a_resource_…, test_a_full_build_of_an_empty_library_r…, test_a_full_build_prunes_only_effects_i…]
- "tools_g2_replay_probe": "g2_replay_probe.cpp" | kind=code-symbol | source=engine/physics/tools/g2_replay_probe.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, bounds_of(), combine_friction(), combine_restitution()]
- "towncity_town_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L76 | neighbors=[town_map.py, alley(), dressing(), landmarks(), kit(), sub()]
- "unit_device_router_test": "device_router_test.cpp" | kind=code-symbol | source=mute/tests/unit/device_router_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, apply_events(), connect(), disconnect(), event(), main()]
- "unit_emit_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L90 | neighbors=[emit_test.cpp, arith_module(), calls_module(), check(), hostcall_module(), i32()]
- "unit_input_snapshot_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/input_snapshot_test.cpp:L63 | neighbors=[input_snapshot_test.cpp, button(), gamepad_axis(), gamepad_button(), key(), motion()]
- "unit_stress_test": "stress_test.cpp" | kind=code-symbol | source=mute/tests/unit/stress_test.cpp:L1 | neighbors=[2d01203 Final MUT-01..30 audit: stress …, bytecode_limits(), check(), i32t(), lexer_limits(), main()]
- "unit_test_math_determinism_tracetests": "TraceTests" | kind=code-symbol | source=mute/tests/unit/test_math_determinism.py:L12 | neighbors=[test_math_determinism.py, .check_invalid(), .setUp(), .test_corpus_corruption_rejected(), .test_duplicate_json_keys_rejected(), .test_match_is_only_agreement()]
- "valleylake_paint": "paint.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, atlas(), cracks(), fnoise(), _hex()]
- "valleylake_valley_map_nature": "nature()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L822 | neighbors=[valley_map.py, build(), cliff_clear(), free(), in_terr(), lake_d()]
- "valleylake_valley_map_shore": "shore()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L759 | neighbors=[valley_map.py, build(), dock off the west beach, footbridge ove…, anchor(), face(), free()]
- "valleylake_valley_props_waterfall": "waterfall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L779 | neighbors=[valley_props.py, HERO: a broad curved sheet spilling off…, clump(), flat(), moss_cap(), rim_shade()]
- "vfxkit_library": "library.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, describe(), _forget_helpers(), get(), HelperFinder]
- "vfxkit_primitives_mesh": "mesh()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L217 | neighbors=[primitives.py, column(), crystal(), life_max(), tex(), Procedural Sphere/Cone/Cylinder shell, …]
- "vfxkit_reference": "reference.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, analyse(), checked_id(), compare(), effect_time()]
- "vfxkit_video_flipbook": "flipbook()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L167 | neighbors=[video.py, _decode(), _key(), _parse_frames(), _portable(), _prompt_text()]
- "vfxkit_video_grade": "grade()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L284 | neighbors=[video.py, _eval(), _portable(), _ramp(), record(), _report_dir()]
- "voidrealm_void_map_stations": "stations()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L254 | neighbors=[void_map.py, build(), anchor(), ang(), face(), H()]
- "authority_replay_ring": "replay_ring.hpp" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L1 | neighbors=[cbor_bool(), cbor_head(), cbor_text(), cbor_uint(), decode_replay(), emit_litlen()]
- "blender_render_compare_views": "render_compare_views.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L1 | neighbors=[_area(), _ensure_world(), render_turnaround(), _scene_bounds(), setup_camera(), setup_lighting()]
- "blender_validate_scene": "validate_scene.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L1 | neighbors=[find_isolated(), find_strays(), landmarks(), print_report(), scene_bounds(), tri_count()]
- "brainstorm_server_helper_test": "helper.test.js" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/helper.test.js:L1 | neighbors=[assert, fs, HELPER, makeEnv(), moduleShim, path]
- "candyland_candy_props_quest_stand": "quest_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L549 | neighbors=[candy_props.py, ball(), drip_ring(), lathe(), MS(), round_prof()]
- "canyonbazaar_canyon_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/canyonbazaar/canyon_map.py:L503 | neighbors=[canyon_map.py, edge_rhythm(), ground(), horizon(), medallion(), nature()]
- "cavemap_cave_map_path_d": "path_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L100 | neighbors=[cave_map.py, clusters(), crystals(), dripstone(), fungi(), H()]
- "cavemap_cave_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L190 | neighbors=[cave_map.py, build(), clusters(), crystals(), dripstone(), fungi()]
- "cavemap_cave_map_vines": "vines()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_map.py:L587 | neighbors=[cave_map.py, build(), glow-root vines hanging from the vault …, ceil_y(), free(), H()]
- "cavemap_cave_ores": "cave_ores.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_ores.py:L1 | neighbors=[cart_load(), druse(), _lump(), mound(), ore_lump(), ore_pile()]
- "commit:repo:github.com/Raft-The-Crab/pokox@1c81e45b51593286d3d388efbe3965f6bfd2a939": "1c81e45 Update from ML AI Code" | kind=Commit | source=git | neighbors=[main, e04375a Run tests, config_file_test.cpp, stdlib_math.hpp, cbor.cpp, stdlib_math.cpp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-009.json

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
