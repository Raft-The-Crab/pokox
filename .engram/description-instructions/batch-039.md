# Node Description Batch 40 of 207

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

- "src_vfx_kaiju_explosion": "VFX_Kaiju_Explosion.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Explosion.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Kaiju_Explosion: a photographic, bu…]
- "src_vfx_magic_charge": "VFX_Magic_Charge.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Magic_Charge.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Magic_Charge: Arcane charge on the …]
- "src_vfx_poison_cloud": "VFX_Poison_Cloud.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Poison_Cloud.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Poison_Cloud: Poison splash and lin…]
- "src_vfx_projectile_dark": "VFX_Projectile_Dark.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Dark.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Projectile_Dark: Shadow orb project…]
- "src_vfx_projectile_fire": "VFX_Projectile_Fire.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Fire.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Projectile_Fire: Fireball projectil…]
- "src_vfx_projectile_ice": "VFX_Projectile_Ice.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Ice.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Projectile_Ice: Ice lance projectil…]
- "src_vfx_projectile_poison": "VFX_Projectile_Poison.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Poison.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Projectile_Poison: Lobbed venom glo…]
- "src_vfx_shield_dome": "VFX_Shield_Dome.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Shield_Dome.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Shield_Dome: Shield dome on the cas…]
- "src_vfx_slash_fire": "VFX_Slash_Fire.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Slash_Fire.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Slash_Fire: Fire sword slash played…]
- "src_visual_solver_collide_visual": "collide_visual()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L325 | neighbors=[visual_solver.cpp, collide_box_box(), collide_sphere_box(), collide_sphere_sphere(), step()]
- "src_visual_solver_solve": "solve()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L176 | neighbors=[visual_solver.cpp, clampf(), clear(), tangent_basis(), step()]
- "state_state_xxhash64": "xxhash64()" | kind=code-symbol | source=mute/src/state/state.cpp:L17 | neighbors=[state.cpp, hash_state(), merge(), read32(), read64()]
- "stdlib_stdlib_math_det_sqrt": "det_sqrt()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L23 | neighbors=[stdlib_math.cpp, quat_normalize(), vec2_normalize(), vec3_normalize(), vec4_normalize()]
- "stdlib_stdlib_math_quat_rotate": "quat_rotate()" | kind=code-symbol | source=mute/src/stdlib/stdlib_math.cpp:L128 | neighbors=[stdlib_math.cpp, quat_normalize(), vec3_add(), vec3_cross(), vec3_scale()]
- "sugarworks_sugar_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L41 | neighbors=[sugar_map.py, build(), kit(), sub(), plot()]
- "sugarworks_sugar_map_plot": "plot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L64 | neighbors=[sugar_map.py, build(), face(), local(), place()]
- "sugarworks_sugar_props_collector": "collector()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L163 | neighbors=[sugar_props.py, stripes(), subdiv_line(), torus(), chocolate melting vat: drum with cream …]
- "sugarworks_sugar_props_dome": "dome()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L36 | neighbors=[sugar_props.py, exchange(), gumdrop_bush(), lollipop_tree(), wrapper_bin()]
- "sugarworks_sugar_props_gate": "gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L88 | neighbors=[sugar_props.py, stripes(), subdiv_line(), torus(), owner gate: two striped pillars with gu…]
- "sugarworks_sugar_props_subdiv_line": "subdiv_line()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L53 | neighbors=[sugar_props.py, candy_lamp(), collector(), exchange(), gate()]
- "systematic_debugging_condition_based_waiting_example": "condition-based-waiting-example.ts" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/systematic-debugging/condition-based-waiting-example.ts:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, waitForEvent(), waitForEventCount(), waitForEventMatch()]
- "tests_test_baking": "test_baking.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_baking.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _pixels(), test_high_to_low_bake_normal_ao_curv_or…, test_self_bake_procedural_roughness()]
- "tests_test_gridfinity_assert_footprint": "_assert_footprint()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L29 | neighbors=[test_gridfinity.py, test_bin_with_lip_magnets_screws(), test_compartments_scoop_label(), test_minimal_bin_no_lip(), test_polygon_pocket_with_clearance_and_…]
- "tests_test_gridfinity_test_bin_with_lip_magnets_screws": "test_bin_with_lip_magnets_screws()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L48 | neighbors=[test_gridfinity.py, 2x1, 3U with lip and base holes., _assert_footprint(), _mesh(), _volume()]
- "tests_test_gridfinity_volume": "_volume()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L24 | neighbors=[test_gridfinity.py, B-rep volume, no tessellation round-tri…, test_bin_with_lip_magnets_screws(), test_compartments_scoop_label(), test_finger_notch_removes_material()]
- "tests_test_hair": "test_hair.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_hair.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _head(), test_groom_attached_masked_with_assets(), test_hair_cards_and_atlas()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-039.json

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
