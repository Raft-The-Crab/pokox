# Node Description Batch 21 of 208

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

- "examples_arctic_fox": "arctic_fox.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/arctic_fox.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), idle(), pounce(), wag()]
- "examples_bunny": "bunny.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/bunny.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, big_jump(), build(), ear_wiggle(), hop()]
- "examples_duck": "duck.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/duck.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), flap(), idle(), quack()]
- "examples_owl": "owl.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/owl.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), flap(), head_turn(), idle()]
- "examples_penguin": "penguin.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/penguin.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), flap(), idle(), slide()]
- "examples_red_panda": "red_panda.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/red_panda.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), idle(), pounce(), wag()]
- "fishcenter_fish_props_aquarium_dome": "aquarium_dome()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1200 | neighbors=[fish_props.py, brain_coral(), coral_branch(), fish(), _merge_prop(), sign_board()]
- "fishcenter_fish_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L552 | neighbors=[fish_props.py, bait_shop(), lerp(), barrels(), fish_market(), motor_boat()]
- "fishcenter_fish_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L525 | neighbors=[fish_props.py, fish(), local(), crate_stack(), fish_market(), quest_board()]
- "fishcenter_fish_props_welcome_arch": "welcome_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1081 | neighbors=[fish_props.py, WELCOME ARCH on the spawn axis: two las…, ball(), fish(), lash(), pole()]
- "foundation_fixed": "fixed.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, cos(), divide(), Fixed, sin(), sine_lookup()]
- "foundation_vec3f": "vec3f.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, cross(), dot(), length(), lengthSquared(), normalized()]
- "hermes_plugin_init": "__init__.py" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _build_bootstrap(), _frontmatter_value(), register(), _skills_dir()]
- "hermes_test_bootstrap": "test_bootstrap.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bootstrap(), _load(), TestBootstrapContent, TestSkillsDirResolution]
- "hermes_test_bootstrap_load": "_load()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L18 | neighbors=[test_bootstrap.py, _bootstrap(), .test_tool_mapping_sourced_from_referen…, .test_repo_layout_resolves(), .test_no_frontmatter_returns_trimmed_co…, .test_strips_surrounding_whitespace_fro…]
- "hermes_test_bootstrap_testbootstrapcontent": "TestBootstrapContent" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L57 | neighbors=[test_bootstrap.py, .test_contains_using_superpowers_body(), .test_frontmatter_stripped(), .test_marker_and_wrapper(), .test_skill_view_guidance_present(), .test_tool_mapping_sourced_from_referen…]
- "imgui_enginefactoryvk": "EngineFactoryVk.h" | kind=code-symbol | source=engine/rhi/tests/fakes/imgui/EngineFactoryVk.h:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Diligent(), GraphicsPipeline(), IDeviceObject(), IEngineFactory(), RTVFormats()]
- "input_action_map_decode": "decode()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L194 | neighbors=[action_map.cpp, define_action(), get16(), get32(), get8(), set_bindings()]
- "input_input_snapshot_put8": "put8()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L11 | neighbors=[input_snapshot.cpp, encode(), hash(), put16(), put32(), put64()]
- "integration_config_file_test_test_resolve": "test_resolve()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L255 | neighbors=[config_file_test.cpp, main(), put_bool(), put_kv(), put_map(), put_u()]
- "integration_cube_golden_run": "run()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L134 | neighbors=[cube_golden.py, main(), canonical_png(), X11, .capture(), .close()]
- "integration_test_shader_pipeline": "test_shader_pipeline.py" | kind=code-symbol | source=engine/render/tests/integration/test_shader_pipeline.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, 952997e Audit MUT-01-55 and harden veri…, check_spirv(), run(), update_shader(), Exercise the real host compiler and CMa…]
- "integration_test_word_reservations_reservationmigrationtests": "ReservationMigrationTests" | kind=code-symbol | source=backend/storage/d1/tests/integration/test_word_reservations.py:L10 | neighbors=[test_word_reservations.py, .setUp(), .test_direct_reapplication_fails_instea…, .test_first_release_word_is_globally_re…, .test_game_reservations_have_independen…, .test_global_reservation_cannot_name_a_…]
- "medievalbattle_battle_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L426 | neighbors=[battle_map.py, build(), H(), place(), reserve(), tree_pick()]
- "medievalbattle_battle_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L20 | neighbors=[battle_map.py, courtyard(), grid_mesh(), ground(), place(), roads()]
- "medievalbattle_battle_map_x": "X()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L34 | neighbors=[battle_map.py, centre(), courtyard(), field(), keep(), roads()]
- "medievalbattle_battle_props_battle_debris": "battle_debris()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1372 | neighbors=[battle_props.py, heater_shield(), lathe(), log(), T(), torus()]
- "medievalbattle_battle_props_campfire": "campfire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1211 | neighbors=[battle_props.py, flame(), lathe(), log(), T(), torus()]
- "medievalbattle_battle_props_footbridge": "footbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L828 | neighbors=[battle_props.py, bar(), log(), sag(), T(), torus()]
- "medievalbattle_battle_props_sag": "sag()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L95 | neighbors=[battle_props.py, footbridge(), palisade(), lerp(), siege_tower(), sundered_bridge()]
- "medievalbattle_battle_props_training_dummy": "training_dummy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1348 | neighbors=[battle_props.py, straw dummy on a post and crossbar, twi…, bar(), heater_shield(), log(), T()]
- "moonclean_moon_map_craters": "craters()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L335 | neighbors=[moon_map.py, build(), Hm(), place(), reserve(), zone_of()]
- "moonclean_moon_props_beacon_post": "beacon_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L106 | neighbors=[moon_props.py, airlock_gate(), lathe(), beacon_rail(), moon_rocket(), signature: white octagonal post, steel …]
- "moonclean_moon_props_dish": "dish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L79 | neighbors=[moon_props.py, comms_dish(), lathe(), lunar_lander(), moon_rover(), parabolic dish opening up (+Y), thickne…]
- "moonclean_moon_props_lunar_lander": "lunar_lander()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L298 | neighbors=[moon_props.py, beam(), dish(), lathe(), lerp(), torus()]
- "moonclean_moon_props_rock": "rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L498 | neighbors=[moon_props.py, crater(), dust_patch(), ice_crystal(), meteor_chunk(), meteorite()]
- "mute_hostcall": "hostcall.hpp" | kind=code-symbol | source=mute/include/poko/mute/hostcall.hpp:L1 | neighbors=[60d8044 Mute crypto hostcalls: fail exp…, 952997e Audit MUT-01-55 and harden veri…, 9eeb3ff Merge pull request #2 from Raft…, capability_from_name(), capability_name(), effective_capabilities()]
- "net_crypto_aead_aead_open": "aead_open()" | kind=code-symbol | source=server/net/include/poko/net/crypto_aead.hpp:L246 | neighbors=[crypto_aead.hpp, chacha20_block(), chacha20_xor(), consttime_equal(), poly1305_mac(), store32_le()]
- "net_frame": "frame.hpp" | kind=code-symbol | source=server/net/include/poko/net/frame.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, constant_time_equal(), hmac_sha256(), pack_frame(), payload_bit_length(), Sha256]
- "net_xor_fec": "xor_fec.hpp" | kind=code-symbol | source=server/net/include/poko/net/xor_fec.hpp:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, attach_parity(), losses(), make_parity(), recover_loss(), rotated_group()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-020.json

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
