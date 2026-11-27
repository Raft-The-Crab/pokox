# Node Description Batch 21 of 209

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

- "effekseer_ai_authoring_layerbuilder_advanced": ".advanced()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L171 | neighbors=[LayerBuilder, cutoff_easing(), .color(), .uv(), .vector(), .layer()]
- "effekseer_ai_authoring_layerbuilder_layer": ".layer()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L252 | neighbors=[compile_effect(), LayerBuilder, .advanced(), .bind(), .curve(), .uv()]
- "effekseer_ai_authoring_validate_layer": "validate_layer()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L49 | neighbors=[authoring.py, compile_effect(), .layer(), List problems the compiler would otherw…, _code(), _term()]
- "effekseer_ai_runtime": "runtime.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/runtime.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, editor_bin_directory(), export_binary(), load_core(), runtime_config_path()]
- "eggplots_egg_map_dressing": "dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L302 | neighbors=[egg_map.py, build(), free(), isle_d(), isle_point(), place()]
- "eggplots_egg_map_hardscape": "hardscape()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L116 | neighbors=[egg_map.py, build(), inset_top(), sh_val(), static(), T()]
- "eggplots_egg_props_egg_shop": "egg_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L706 | neighbors=[egg_props.py, egg(), rbox(), sh(), stall(), straw_nest()]
- "eggplots_egg_props_hatchery": "hatchery()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L520 | neighbors=[egg_props.py, egg_finial(), egg_profile(), rbox(), sh(), straw_nest()]
- "eggplots_egg_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L49 | neighbors=[egg_props.py, egg(), egg_slice(), foot_bridge(), gate_frame(), plot_slab()]
- "eggplots_egg_props_owner_sign": "owner_sign()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L233 | neighbors=[egg_props.py, egg_finial(), post(), rbox(), sh(), upright()]
- "eggplots_egg_props_post": "post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L152 | neighbors=[egg_props.py, egg_drain(), fence_post(), owner_sign(), rbox(), sh()]
- "eggplots_egg_props_upright": "upright()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L59 | neighbors=[egg_props.py, barn(), coop(), fence_run(), owner_sign(), 2D poly [(x, up)] standing upright faci…]
- "evaluator_evaluator_width": "width()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L45 | neighbors=[evaluator.cpp, evaluate_arithmetic(), materialize(), signed_binary(), suffix_length(), unary()]
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
- "foundation_duration_query_state": "duration_query_state.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/duration_query_state.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, begin(), DurationQueryState, end(), poll(), 52dbcb9 Surface graphics warnings in X1…]
- "foundation_fixed": "fixed.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, cos(), divide(), Fixed, sin(), sine_lookup()]
- "foundation_vec3f": "vec3f.hpp" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, cross(), dot(), length(), lengthSquared(), normalized()]
- "gles_clear_pokoactivity": "PokoActivity.java" | kind=code-symbol | source=engine/rhi/android/gles-clear/PokoActivity.java:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, Activity, PokoActivity, SurfaceHolder, SurfaceView, 52dbcb9 Surface graphics warnings in X1…]
- "hermes_plugin_init": "__init__.py" | kind=code-symbol | source=.agents/skills/superpowers-main/.hermes-plugin/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _build_bootstrap(), _frontmatter_value(), register(), _skills_dir()]
- "hermes_test_bootstrap": "test_bootstrap.py" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bootstrap(), _load(), TestBootstrapContent, TestSkillsDirResolution]
- "hermes_test_bootstrap_load": "_load()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L18 | neighbors=[test_bootstrap.py, _bootstrap(), .test_tool_mapping_sourced_from_referen…, .test_repo_layout_resolves(), .test_no_frontmatter_returns_trimmed_co…, .test_strips_surrounding_whitespace_fro…]
- "hermes_test_bootstrap_testbootstrapcontent": "TestBootstrapContent" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/hermes/test_bootstrap.py:L57 | neighbors=[test_bootstrap.py, .test_contains_using_superpowers_body(), .test_frontmatter_stripped(), .test_marker_and_wrapper(), .test_skill_view_guidance_present(), .test_tool_mapping_sourced_from_referen…]
- "input_action_map_decode": "decode()" | kind=code-symbol | source=mute/src/input/action_map.cpp:L194 | neighbors=[action_map.cpp, define_action(), get16(), get32(), get8(), set_bindings()]
- "input_input_snapshot_put8": "put8()" | kind=code-symbol | source=mute/src/input/input_snapshot.cpp:L11 | neighbors=[input_snapshot.cpp, encode(), hash(), put16(), put32(), put64()]
- "integration_config_file_test_test_resolve": "test_resolve()" | kind=code-symbol | source=engine/foundation/tests/integration/config_file_test.cpp:L255 | neighbors=[config_file_test.cpp, main(), put_bool(), put_kv(), put_map(), put_u()]
- "integration_cube_golden_run": "run()" | kind=code-symbol | source=engine/render/tests/integration/cube_golden.py:L134 | neighbors=[cube_golden.py, main(), canonical_png(), X11, .capture(), .close()]
- "integration_test_triangle_x11_visual": "test_triangle_x11_visual.py" | kind=code-symbol | source=engine/render/tests/integration/test_triangle_x11_visual.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, find_window(), green(), pixel(), red(), 52dbcb9 Surface graphics warnings in X1…]
- "integration_test_word_reservations_reservationmigrationtests": "ReservationMigrationTests" | kind=code-symbol | source=backend/storage/d1/tests/integration/test_word_reservations.py:L10 | neighbors=[test_word_reservations.py, .setUp(), .test_direct_reapplication_fails_instea…, .test_first_release_word_is_globally_re…, .test_game_reservations_have_independen…, .test_global_reservation_cannot_name_a_…]
- "integration_x11_demo_smoke": "x11_demo_smoke.py" | kind=code-symbol | source=engine/platform/tests/integration/x11_demo_smoke.py:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, ClientData, ClientMessage, XEvent, Optional Linux/X11 host smoke test; not…, 52dbcb9 Surface graphics warnings in X1…]
- "math_deterministic_math": "deterministic_math.cpp" | kind=code-symbol | source=mute/src/math/deterministic_math.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, calculate(), deterministic_cos(), deterministic_sin(), supported(), 52dbcb9 Surface graphics warnings in X1…]
- "medievalbattle_battle_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L426 | neighbors=[battle_map.py, build(), H(), place(), reserve(), tree_pick()]

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
