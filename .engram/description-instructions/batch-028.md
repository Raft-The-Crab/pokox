# Node Description Batch 29 of 209

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

- "oaktrees_gen_trees_card_quads": "card_quads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L549 | neighbors=[gen_trees.py, .at(), .length(), rand_unit(), .env(), Leaf-cluster cards (folded, 4 tris) or …]
- "oaktrees_gen_trees_fft_noise": "fft_noise()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L33 | neighbors=[gen_trees.py, bark_birch(), bark_fir(), bark_oak(), leaf_atlas(), Periodic (tileable) gaussian-filtered n…]
- "oaktrees_gen_trees_leaf_atlas": "leaf_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L270 | neighbors=[gen_trees.py, Canvas, .capsule_path(), .finish(), .leaf(), fft_noise()]
- "oaktrees_gen_trees_main": "main()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L1038 | neighbors=[gen_trees.py, contact_sheet(), export_glb(), make_tree(), render_turntable(), setup_scene()]
- "oaktrees_gen_trees_tree_children_of": ".children_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L380 | neighbors=[Tree, .build(), .at(), .length(), .env(), .grow()]
- "oaktrees_gen_trees_tree_laterals": ".laterals()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L474 | neighbors=[paired side sprays in the (roughly hori…, Tree, .build_conifer(), .at(), .length(), .grow()]
- "onsenvillage_onsen_map_village": "village()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L358 | neighbors=[onsen_map.py, build(), mirror(), place(), rail_run(), reserve()]
- "onsenvillage_onsen_props_flared_roof": "flared_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L47 | neighbors=[onsen_props.py, hip_roof(), pagoda(), Asian glazed roof: a lofted surface fro…, skirt_roof(), toro()]
- "onsenvillage_onsen_props_hip_roof": "hip_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L104 | neighbors=[onsen_props.py, bath_pavilion(), flared_roof(), house(), noodle_stall(), rectangular hip roof over a hw x hd (ha…]
- "opencode_test_hook_registration": "test-hook-registration.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-hook-registration.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, captureHooks(), event(), pluginURL, session()]
- "petsim_pet_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L202 | neighbors=[pet_map.py, breakables(), egg_stand(), hub(), link(), zone_bounds()]
- "petsim_pet_map_edge_pt": "edge_pt()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L281 | neighbors=[pet_map.py, build(), isle_R(), fence_ring(), hub(), link()]
- "petsim_pet_map_isle_at": "isle_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L43 | neighbors=[pet_map.py, breakables(), H(), isle_R(), polar(), place_soft()]
- "petsim_pet_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L178 | neighbors=[pet_map.py, build(), clip_fail(), isle_at(), place(), unplace()]
- "petsim_pet_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L453 | neighbors=[pet_map.py, candy(), crystal(), meadow(), egg_stand(), path()]
- "petsim_pet_map_zone_bounds": "zone_bounds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L375 | neighbors=[pet_map.py, candy(), crystal(), hub(), meadow(), anchor()]
- "petsim_pet_props_egg_stand": "egg_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L566 | neighbors=[pet_props.py, egg(), puff(), rcyl(), soft(), fluted cake pedestal with a glowing rin…]
- "petsim_pet_props_fence": "fence()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1005 | neighbors=[pet_props.py, ell(), rbox(), rcyl(), soft(), chunky rail fence segment from x = 0 to…]
- "petsim_pet_props_lollipop": "lollipop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L892 | neighbors=[pet_props.py, ell(), flat(), rcyl(), soft(), giant swirl lollipop: two interleaved c…]
- "petsim_pet_props_paw": "paw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L127 | neighbors=[pet_props.py, ell(), soft(), paw-print icon: palm pad + 4 toe beans,…, spawn_pad(), zone_gate()]
- "petsim_pet_props_pet_shop": "pet_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L357 | neighbors=[pet_props.py, ell(), pill(), rcyl(), soft(), open-front kiosk: round dais, curved ba…]
- "petsim_pet_props_pet_statue": "pet_statue()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L323 | neighbors=[pet_props.py, ell(), puff(), puffpaw(), soft(), the Puffpaw statue + its quilted cushio…]
- "petsim_pet_props_star": "star()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L119 | neighbors=[pet_props.py, rainbow_arch(), a chunky star standing upright facing -…, star_poly(), star_lamp(), upgrade_machine()]
- "petsim_pet_props_trade_booth": "trade_booth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L486 | neighbors=[pet_props.py, round trade table with a big scalloped …, ell(), rbox(), rcyl(), soft()]
- "petsim_pet_props_vsh": "vsh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L47 | neighbors=[pet_props.py, bridge(), coin_pile(), flat(), pet_fountain(), soft()]
- "pkb_pkb_draft": "pkb_draft.cpp" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, head(), make_pkb_schema_draft(), text(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "plusspeed_plus_map_dress_caps": "dress_caps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L88 | neighbors=[plus_map.py, place(), finish(), hub(), put theme props on cap tops (centre of …, zone()]
- "plusspeed_plus_map_finish": "finish()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L192 | neighbors=[plus_map.py, blk(), dress_caps(), floor(), place(), walls()]
- "plusspeed_plus_map_zone": "zone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L160 | neighbors=[plus_map.py, blk(), dress_caps(), floor(), place(), walls()]
- "plusspeed_plus_props_v4_plinth": "plinth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L59 | neighbors=[plus_props_v4.py, egg_hatchery(), pixel_art(), podium_board(), rebirth_portal(), sneaker_shop()]
- "plusspeed_plus_props_v4_raster": "raster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L38 | neighbors=[plus_props_v4.py, egg_rows(), medal_rows(), portal_rows(), fn(x, y) -> char, x/y in -1..1 (y up); …, stopwatch_rows()]
- "program_program_fail": "fail()" | kind=code-symbol | source=mute/src/program/program.cpp:L20 | neighbors=[program.cpp, Depth(), prepare_globals(), run_program_reference(), run_stateful_program(), run_stateful_program_bytecode()]
- "refmatch_compare_subject_mask": "subject_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L146 | neighbors=[compare.py, mask_at_native(), Foreground mask.      Prefers an exact …, background_fit_mask(), flood_background_mask(), significant_components()]
- "refmatch_overlay": "overlay.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/overlay.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, build(), _overlay(), _panel(), Side-by-side diagnostic sheet.  Metrics…]
- "refmatch_palette_report_compare_to_render": "compare_to_render()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L122 | neighbors=[palette_report.py, delta_e(), extract(), hex_to_rgb(), main(), For each named palette role, find the n…]
- "refmatch_palette_report_extract": "extract()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/palette_report.py:L74 | neighbors=[palette_report.py, compare_to_render(), hex_of(), kmeans(), subject_pixels(), main()]
- "resource_asset_store": "asset_store.hpp" | kind=code-symbol | source=engine/resource/include/poko/resource/asset_store.hpp:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, AssetHandle, AssetStore, typed(), 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …]
- "scripts_auto_retopo": "auto_retopo.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/auto_retopo.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_all(), _ctx(), run(), Make a low-poly retopo copy of a dense …]
- "scripts_bake_maps_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-texture-baking/scripts/bake_maps.py:L139 | neighbors=[bake_maps.py, _curvature_from_normal(), _restore(), _set_device(), _signal_override(), _target_node()]
- "scripts_compare": "compare.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/compare.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bbox(), concept_mask(), main(), Overlay a render's silhouette on a conc…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-028.json

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
