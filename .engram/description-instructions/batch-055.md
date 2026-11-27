# Node Description Batch 56 of 207

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

- "tests_fixtures_street": "street()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L67 | neighbors=[fixtures.py, Ground slab (top at z=0), two buildings…, cube(), uv_sphere()]
- "tests_fixtures_zfight_pair": "zfight_pair()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/fixtures.py:L33 | neighbors=[fixtures.py, Two coplanar overlapping planes in diff…, mesh_object(), plane()]
- "tests_test_agent_loop_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_agent_loop.py:L41 | neighbors=[test_agent_loop.py, test_lint_accepts_a_cel_contact_and_a_r…, test_lint_passes_the_library_and_report…, test_lint_warns_about_craft_problems()]
- "tests_test_clothing": "test_clothing.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_clothing.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_garment_morphs_and_drape(), test_garment_weights_mask_and_pose()]
- "tests_test_core_run_md_blocks": "_run_md_blocks()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_core.py:L11 | neighbors=[test_core.py, Execute every ```python block of a refe…, test_bpy_patterns_snippets_run(), test_snippet_docs_across_skills()]
- "tests_test_gridfinity_test_compartments_scoop_label": "test_compartments_scoop_label()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L62 | neighbors=[test_gridfinity.py, _assert_footprint(), _mesh(), _volume()]
- "tests_test_gridfinity_test_minimal_bin_no_lip": "test_minimal_bin_no_lip()" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_gridfinity.py:L40 | neighbors=[test_gridfinity.py, 1x1, 2U, no lip: exact box height, flat…, _assert_footprint(), _mesh()]
- "tests_test_npr_bands": "_bands()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_npr.py:L38 | neighbors=[test_npr.py, _clusters(), test_toon_hull_bands_lineart_roundtrip(), test_toon_scene_lighting_eevee()]
- "tests_test_optimization": "test_optimization.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_optimization.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_lods_halve_and_cleanup(), test_mesh_stats_budget()]
- "tests_test_privacy_png_metadata": "png_metadata()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L82 | neighbors=[test_privacy.py, file_hits(), Names of PNG chunks beyond pixel data (…, test_scanner_catches_each_kind_of_leak_…]
- "tests_test_privacy_test_no_file_in_the_package_leaks_personal_machine_or_secret_data": "test_no_file_in_the_package_leaks_personal_machine_or_secret_data()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_privacy.py:L154 | neighbors=[test_privacy.py, file_hits(), files(), private_terms()]
- "tests_test_scene": "test_scene.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_scene.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_collection_exporter_snippet(), test_scene_audit_flags_and_fixes()]
- "tests_test_stl_to_3mf": "test_stl_to_3mf.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/tests/test_stl_to_3mf.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, test_convert_happy_path(), test_convert_missing_file()]
- "tests_test_texturing_stepped_block": "_stepped_block()" | kind=code-symbol | source=.agents/skills/blender-skills-main/tests/test_texturing.py:L7 | neighbors=[test_texturing.py, 1 m block with a 0.5 m step on top (con…, test_smart_material_bakes_to_texture(), test_smart_material_curvature_and_round…]
- "tests_test_workflow_report": "report()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/tests/test_workflow.py:L97 | neighbors=[test_workflow.py, test_completion_requires_brief_review_a…, test_independent_report_binds_images_sc…, test_review_handoff_gives_a_reviewer_ev…]
- "texture_tex_to_maps_blur": "blur()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L37 | neighbors=[tex_to_maps.py, derive_ao(), high_pass(), Box blur via integral image. O(1) per p…]
- "texture_tex_to_maps_derive_ao": "derive_ao()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L86 | neighbors=[tex_to_maps.py, blur(), process(), Cavity estimate: pixels darker than the…]
- "texture_tex_to_maps_high_pass": "high_pass()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tex_to_maps.py:L57 | neighbors=[tex_to_maps.py, blur(), process(), Luminance minus its local mean: the det…]
- "texture_tile_seam_check_assess": "assess()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L73 | neighbors=[tile_seam_check.py, boundary_metrics(), load_gray(), main()]
- "texture_tile_seam_check_main": "main()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/tile_seam_check.py:L133 | neighbors=[tile_seam_check.py, assess(), print_report(), write_tile_sheet()]
- "texture_uv_density_group_stats": "group_stats()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L82 | neighbors=[uv_density.py, tri_area_3d(), tri_area_uv(), report()]
- "texture_uv_density_report": "report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/texture/uv_density.py:L108 | neighbors=[uv_density.py, main(), group_stats(), parse_obj()]
- "tools_readme_hero_frame": "frame()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/readme_hero.py:L91 | neighbors=[readme_hero.py, font(), mask(), main()]
- "tools_sync_shared": "sync_shared.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/sync_shared.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main(), targets()]
- "tools_trigger_check": "trigger_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/tools/trigger_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main(), toks()]
- "towncity_city_paint_block": "block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L101 | neighbors=[city_paint.py, atlas(), paint_glass(), tile()]
- "towncity_city_paint_edge": "edge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L34 | neighbors=[city_paint.py, clip(), 1 inside a joint of half-width w (d = d…, tile()]
- "towncity_city_paint_paint_glass": "paint_glass()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L93 | neighbors=[city_paint.py, block(), clip(), ramp()]
- "towncity_city_paint_remap": "remap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/city_paint.py:L149 | neighbors=[city_paint.py, area(), axes_of(), clip()]
- "towncity_town_landmarks_arch_open": "arch_open()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L58 | neighbors=[town_landmarks.py, clock_tower(), an arched opening framed with voussoirs…, train_station()]
- "towncity_town_landmarks_bank": "bank()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L481 | neighbors=[town_landmarks.py, column(), pediment(), bank: temple front on a stepped podium,…]
- "towncity_town_landmarks_clock_face": "clock_face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L45 | neighbors=[town_landmarks.py, clock_tower(), clock: cream dial, gold bezel, 12 tick …, train_station()]
- "towncity_town_landmarks_column": "column()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L19 | neighbors=[town_landmarks.py, bank(), classical column: square plinth, torus …, town_hall()]
- "towncity_town_landmarks_pediment": "pediment()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_landmarks.py:L27 | neighbors=[town_landmarks.py, bank(), triangular pediment: raking cornices + …, town_hall()]
- "towncity_town_map_anchor_local": "anchor_local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L99 | neighbors=[town_map.py, anchor(), rot(), sign_anchor()]
- "towncity_town_map_railway": "railway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L195 | neighbors=[town_map.py, build(), place(), rail corridor: two tracks along Z behin…]
- "towncity_town_map_rot": "rot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L85 | neighbors=[town_map.py, anchor_local(), landmarks(), local (x, y, z) of a prop turned by yaw…]
- "towncity_town_map_zebra": "zebra()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_map.py:L119 | neighbors=[town_map.py, markings(), crosswalk stripes across a road: stripe…, flat()]
- "towncity_town_props_ac_unit": "ac_unit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L119 | neighbors=[town_props.py, add(), building(), rooftop / wall AC: cream casing on feet…]
- "towncity_town_props_antenna": "antenna()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/towncity/town_props.py:L146 | neighbors=[town_props.py, add(), ball(), building()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-055.json

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
