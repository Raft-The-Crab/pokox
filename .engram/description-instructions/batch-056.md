# Node Description Batch 57 of 209

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

- "shared_bpyx_cli": "cli()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L46 | neighbors=[_bpyx.py, argv(), emit(), CLI entry: parse args after '--', run, …]
- "skyrise_sky_map_paving": "paving()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L167 | neighbors=[sky_map.py, sub(), spawn_island(), summit()]
- "skyrise_sky_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L118 | neighbors=[sky_map.py, micro_detail(), Hm(), zone_island()]
- "skyrise_sky_models_lumpy": "lumpy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L9 | neighbors=[sky_models.py, island_under(), puffy_tree(), icosphere with noise displacement: chun…]
- "skyrise_sky_models_puffy_tree": "puffy_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L22 | neighbors=[sky_models.py, blossom_tree(), lumpy(), trunk that forks into 2-3 limbs, root f…]
- "skyrise_sky_models2_planks": "planks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L15 | neighbors=[sky_models2.py, n separate bevelled planks side by side…, sell_pad(), upgrade_stand()]
- "skyrise_sky_models2_sell_pad": "sell_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L189 | neighbors=[sky_models2.py, sell booth: glowing sell circle in fron…, coin(), planks()]
- "skyrise_sky_models2_upgrade_stand": "upgrade_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L216 | neighbors=[sky_models2.py, upgrade shop: planked counter with gold…, bottle(), planks()]
- "skyrise_sky_models4_blade": "blade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L9 | neighbors=[sky_models4.py, grass_tuft(), one grass blade: thin tapered wedge (4 …, wildflowers()]
- "skyrise_sky_models4_grass_tuft": "grass_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L23 | neighbors=[sky_models4.py, dune_grass(), blade(), modelled blade cluster, dark at the roo…]
- "skyrise_sky_models4_wildflowers": "wildflowers()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L40 | neighbors=[sky_models4.py, small flower clump: stems + 5-petal sta…, blade(), star()]
- "skyrise_sky_props_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L355 | neighbors=[sky_props.py, gem(), sphere(), treasure chest, lid open (back +Z hinge…]
- "skyrise_sky_props_island_under": "island_under()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L70 | neighbors=[sky_props.py, lathe(), sphere(), underside of a floating island: rings f…]
- "skyrise_sky_props_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L198 | neighbors=[sky_props.py, zone gate: two banded stone pillars, ar…, gem(), torus()]
- "src_camera_view_proj": "view_proj()" | kind=code-symbol | source=engine/render/src/camera.cpp:L61 | neighbors=[camera.cpp, look_at(), multiply(), perspective()]
- "src_character_controller_deepest_contact": "deepest_contact()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L152 | neighbors=[character_controller.cpp, shape_bound(), spheres_disjoint(), update()]
- "src_character_controller_shape_bound": "shape_bound()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L52 | neighbors=[character_controller.cpp, deepest_contact(), touches_uncached(), update()]
- "src_character_controller_spheres_disjoint": "spheres_disjoint()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L67 | neighbors=[character_controller.cpp, deepest_contact(), touches_uncached(), update()]
- "src_character_controller_touches_uncached": "touches_uncached()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L74 | neighbors=[character_controller.cpp, touches(), shape_bound(), spheres_disjoint()]
- "src_frame_stats_window_mean": "window_mean()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L8 | neighbors=[frame_stats.cpp, cpu_ms(), fps(), gpu_ms()]
- "src_main": "main.cpp" | kind=code-symbol | source=engine/foundation/src/main.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, main(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "src_narrowphase_closest_triangle": "closest_triangle()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L86 | neighbors=[narrowphase.cpp, closest_on_hull(), closest_segment(), dist_sq_of()]
- "src_narrowphase_collide_local": "collide_local()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L701 | neighbors=[narrowphase.cpp, collide(), epa_penetration(), gjk_distance()]
- "src_soft_body_add_spring": "add_spring()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L82 | neighbors=[soft_body.cpp, clamp01(), create(), create_lattice()]
- "src_visual_solver_add_body": "add_body()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L346 | neighbors=[visual_solver.cpp, find_body(), upsert_body(), add_collider()]
- "stdlib_stdlib_crypto_hmac_sha256": "hmac_sha256()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L73 | neighbors=[stdlib_crypto.cpp, sha256(), sign_detached(), verify_detached()]
- "stdlib_stdlib_crypto_sha256": "sha256()" | kind=code-symbol | source=mute/src/stdlib/stdlib_crypto.cpp:L56 | neighbors=[stdlib_crypto.cpp, hmac_sha256(), append_u32_be(), compress()]
- "stdlib_stdlib_string_decode": "decode()" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L11 | neighbors=[stdlib_string.cpp, codepoint_count(), slice_codepoints(), valid_utf8()]
- "sugarworks_sugar_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L157 | neighbors=[sugar_map.py, face(), place(), plot()]
- "sugarworks_sugar_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_map.py:L18 | neighbors=[sugar_map.py, ground(), horizon(), place()]
- "sugarworks_sugar_props_candy_lamp": "candy_lamp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L251 | neighbors=[sugar_props.py, stripes(), subdiv_line(), candy-cane street lamp: striped post, h…]
- "sugarworks_sugar_props_choc_fountain": "choc_fountain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L390 | neighbors=[sugar_props.py, sphere(), torus(), three-tier chocolate fountain: pink bow…]
- "sugarworks_sugar_props_sphere": "sphere()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L41 | neighbors=[sugar_props.py, choc_fountain(), conveyor(), exchange()]
- "targets_run_dual_target_tests_android_compile": "android_compile()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L234 | neighbors=[run_dual_target_tests.py, run_command(), sha256(), android_leg()]
- "targets_run_dual_target_tests_now": "now()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L87 | neighbors=[run_dual_target_tests.py, android_leg(), main(), windows_leg()]
- "targets_run_dual_target_tests_sha256": "sha256()" | kind=code-symbol | source=tools/targets/run_dual_target_tests.py:L122 | neighbors=[run_dual_target_tests.py, android_compile(), android_leg(), windows_leg()]
- "tests_fixtures_cube": "cube()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L19 | neighbors=[fixtures.py, mesh_object(), detached_part(), street()]
- "tests_fixtures_detached_part": "detached_part()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L46 | neighbors=[fixtures.py, cube(), mesh_object(), A body with a floating island and a sep…]
- "tests_fixtures_street": "street()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L67 | neighbors=[fixtures.py, Ground slab (top at z=0), two buildings…, cube(), uv_sphere()]
- "tests_fixtures_zfight_pair": "zfight_pair()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L33 | neighbors=[fixtures.py, Two coplanar overlapping planes in diff…, mesh_object(), plane()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-056.json

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
