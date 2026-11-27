# Node Description Batch 40 of 208

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

- "src_character_controller_cast_fraction": "cast_fraction()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L164 | neighbors=[character_controller.cpp, length_of(), touches(), translated(), update()]
- "src_character_controller_touches": "touches()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L126 | neighbors=[character_controller.cpp, cast_fraction(), touch_key(), touches_uncached(), update()]
- "src_compose": "compose.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, axes(), pair(), pill()]
- "src_config_find_key": "find_key()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L21 | neighbors=[config.cpp, load_file(), read_bool(), read_text(), read_u32()]
- "src_ktx2": "ktx2.cpp" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, fail(), in_bounds(), load_ktx2(), c7a411f Fix MUT-01-20 audit defects in …]
- "src_narrowphase_gjk_distance": "gjk_distance()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L219 | neighbors=[narrowphase.cpp, collide_local(), centroid(), closest_on_hull(), cso_support()]
- "src_sap_broadphase": "sap_broadphase.cpp" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, clear(), commit(), insert(), remove()]
- "src_vfx_dark_vortex": "VFX_Dark_Vortex.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Dark_Vortex.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Dark_Vortex: Dark impact played whe…]
- "src_vfx_fire_explosion": "VFX_Fire_Explosion.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Fire_Explosion.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Fire_Explosion: Fire impact played …]
- "src_vfx_heal": "VFX_Heal.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Heal.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Heal: Heal on the caster: no impact…]
- "src_vfx_hit_heavy": "VFX_Hit_Heavy.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Hit_Heavy.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Hit_Heavy: Heavy melee hit: the blo…]
- "src_vfx_ice_spikes": "VFX_Ice_Spikes.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Ice_Spikes.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Ice_Spikes: Ground ice eruption pla…]
- "src_vfx_kaiju_atomic_beam": "VFX_Kaiju_Atomic_Beam.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Beam.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Kaiju_Atomic_Beam: a sustained atom…]
- "src_vfx_kaiju_atomic_charge": "VFX_Kaiju_Atomic_Charge.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Charge.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Kaiju_Atomic_Charge: dorsal plates …]
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
