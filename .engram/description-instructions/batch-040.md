# Node Description Batch 41 of 208

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

- "tests_test_materials": "test_materials.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_materials.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _img(), test_presets_and_srgb_color_override(), test_texture_set_autowire_orm_dx_normal…]
- "tests_test_privacy_file_hits": "file_hits()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L122 | neighbors=[test_privacy.py, jpeg_metadata(), png_metadata(), text_hits(), test_no_file_in_the_package_leaks_perso…]
- "tests_test_privacy_text_hits": "text_hits()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L69 | neighbors=[test_privacy.py, file_hits(), test_scanner_catches_each_kind_of_leak_…, attribution_allowed(), publisher_allowed()]
- "tests_test_rendering": "test_rendering.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_rendering.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _camera(), test_lookdev_turntable_and_studio(), test_render_stills_cycles_eevee_workben…]
- "tests_test_scale_beam_recipe_with": "recipe_with()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_scale_beam.py:L12 | neighbors=[test_scale_beam.py, test_beam_recipe_lints_with_hold_and_ne…, test_lint_counts_repeatedly_emitted_pai…, test_lint_scales_its_craft_limits_with_…, test_scale_character_is_a_no_op_and_rec…]
- "tests_test_video_fake_unity": "fake_unity()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_video.py:L86 | neighbors=[test_video.py, test_unity_commands_need_no_workspace(), test_unity_export_writes_the_grid_sidec…, test_unity_force_keeps_meta_guids(), test_unity_install_copies_the_package_a…]
- "tools_validate_skills_check_skill": "check_skill()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/validate_skills.py:L51 | neighbors=[validate_skills.py, frontmatter(), known_py(), tokens(), main()]
- "tools_validate_skills_validate": "validate()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/validate_skills.py:L171 | neighbors=[validate_skills.py, check_coverage(), collect_tech_ids(), find_skills(), parse_frontmatter()]
- "towncity_city_paint_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L38 | neighbors=[city_paint.py, paint_glass(), clip(), _hex(), tile()]
- "towncity_town_landmarks_frustum": "frustum()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L9 | neighbors=[town_landmarks.py, box whose top is inset (mansard / hip r…, skyline(), town_hall(), train_station()]
- "towncity_town_landmarks_town_hall": "town_hall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L85 | neighbors=[town_landmarks.py, civic hall on a podium: brick wings wit…, column(), frustum(), pediment()]
- "towncity_town_landmarks_train_station": "train_station()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L252 | neighbors=[town_landmarks.py, brick head house: central great arched …, arch_open(), clock_face(), frustum()]
- "towncity_town_map_alley": "alley()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L452 | neighbors=[town_map.py, place(), reserve(), build(), back alley z ~141..184 between the shop…]
- "towncity_town_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L84 | neighbors=[town_map.py, dressing(), landmarks(), row(), square_dressing()]
- "towncity_town_map_markings": "markings()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L128 | neighbors=[town_map.py, build(), flat(), static(), zebra()]
- "towncity_town_map_square_dressing": "square_dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L426 | neighbors=[town_map.py, build(), face(), place(), reserve()]
- "towncity_town_map_u": "U()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L104 | neighbors=[town_map.py, flat(), ground(), median(), square()]
- "towncity_town_props_awning_band": "awning_band()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L312 | neighbors=[town_props.py, add(), V3(), sloped striped awning (accent / cream s…, shopfront()]
- "towncity_town_props_flower": "flower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L176 | neighbors=[town_props.py, add(), V3(), flower_box(), a flower head: one 5-petal star face + …]
- "towncity_town_props_holed_front": "holed_front()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L104 | neighbors=[town_props.py, building(), add(), slab(), front wall layer (outer face at zf, WAL…]
- "towncity_town_props_water_tank": "water_tank()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L129 | neighbors=[town_props.py, building(), classic timber rooftop water tank on a …, add(), ball()]
- "towncity_town_vehicles_body_shell": "body_shell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L21 | neighbors=[town_vehicles.py, loft_closed(), bus(), car(), lofted body: ring per section s (0 fron…]
- "towncity_town_vehicles_car_shell": "_car_shell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_vehicles.py:L135 | neighbors=[town_vehicles.py, loft_closed(), _smoothstep(), carriage / cab section loft: rounded ro…, train_car()]
- "unit_camera_test": "camera_test.cpp" | kind=code-symbol | source=engine/render/tests/unit/camera_test.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, main(), near(), transform(), c7a411f Fix MUT-01-20 audit defects in …]
- "unit_capability_test_narrowed_module": "narrowed_module()" | kind=code-symbol | source=mute/tests/unit/capability_test.cpp:L38 | neighbors=[capability_test.cpp, main(), i32(), pv(), v()]
- "unit_emit_test_arith_module": "arith_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L18 | neighbors=[emit_test.cpp, i32(), v(), cases(), position_cases()]
- "unit_emit_test_calls_module": "calls_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L28 | neighbors=[emit_test.cpp, i32(), pv(), v(), cases()]
- "unit_emit_test_hostcall_module": "hostcall_module()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L47 | neighbors=[emit_test.cpp, cases(), i32(), pv(), v()]
- "unit_emit_test_pv": "pv()" | kind=code-symbol | source=mute/tests/unit/emit_test.cpp:L16 | neighbors=[emit_test.cpp, calls_module(), cases(), hostcall_module(), select_module()]
- "unit_evaluator_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L41 | neighbors=[evaluator_test.cpp, error_case(), signed_case(), unsigned_case(), main()]
- "unit_evaluator_test_eval": "eval()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L19 | neighbors=[evaluator_test.cpp, error_case(), floating(), signed_case(), unsigned_case()]
- "unit_evaluator_test_floating": "floating()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L80 | neighbors=[evaluator_test.cpp, check(), error_case(), eval(), main()]
- "unit_evaluator_test_main": "main()" | kind=code-symbol | source=mute/tests/unit/evaluator_test.cpp:L213 | neighbors=[evaluator_test.cpp, bindings(), cases(), deep(), floating()]
- "unit_fixed_test": "fixed_test.cpp" | kind=code-symbol | source=engine/foundation/tests/unit/fixed_test.cpp:L1 | neighbors=[1c81e45 Update from ML AI Code, 69287a0 Land ENG-60-65 deterministic si…, fx(), isqrt_ref(), main()]
- "unit_hostcall_test": "hostcall_test.cpp" | kind=code-symbol | source=mute/tests/unit/hostcall_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, check(), def(), main(), run_err()]
- "unit_ktx2_test_main": "main()" | kind=code-symbol | source=engine/resource/tests/unit/ktx2_test.cpp:L60 | neighbors=[ktx2_test.cpp, make_ktx2(), set32(), set64(), write()]
- "unit_limits_test": "limits_test.cpp" | kind=code-symbol | source=mute/tests/unit/limits_test.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, check(), compile_recursion(), main(), run_recursion()]
- "unit_lower_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/lower_test.cpp:L69 | neighbors=[lower_test.cpp, check(), run_module(), run_source(), main()]
- "unit_narrowphase_test_main": "main()" | kind=code-symbol | source=engine/physics/tests/unit/narrowphase_test.cpp:L38 | neighbors=[narrowphase_test.cpp, aabb(), sphere(), tod(), v3()]
- "unit_optimize_test_module_of": "module_of()" | kind=code-symbol | source=mute/tests/unit/optimize_test.cpp:L24 | neighbors=[optimize_test.cpp, cases(), lower_src(), run_base(), run_opt()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-040.json

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
