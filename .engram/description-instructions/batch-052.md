# Node Description Batch 53 of 208

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

- "package_build_tool_quoted": "quoted()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L16 | neighbors=[build_tool.cpp, parse_manifest(), trim(), string_array()]
- "package_build_tool_string_array": "string_array()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L22 | neighbors=[build_tool.cpp, parse_manifest(), quoted(), trim()]
- "package_build_tool_trim": "trim()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L11 | neighbors=[build_tool.cpp, parse_manifest(), quoted(), string_array()]
- "package_package_resolve_packages": "resolve_packages()" | kind=code-symbol | source=mute/src/package/package.cpp:L51 | neighbors=[package.cpp, inner_position(), parse_import_spec(), unquote()]
- "passes_triangle_demo": "triangle_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/triangle_demo.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Exception, main(), c7a411f Fix MUT-01-20 audit defects in …]
- "petsim_pet_map_local": "local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L195 | neighbors=[pet_map.py, egg_stand(), hub(), link()]
- "petsim_pet_map_path_meshes": "path_meshes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L246 | neighbors=[pet_map.py, build(), ribbon_mesh(), static()]
- "petsim_pet_map_polar": "polar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L40 | neighbors=[pet_map.py, breakables(), isle_at(), top_y()]
- "petsim_pet_map_sea": "sea()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L561 | neighbors=[pet_map.py, build(), isle_R(), static()]
- "petsim_pet_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L22 | neighbors=[pet_map.py, place(), static(), link()]
- "petsim_pet_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1043 | neighbors=[pet_props.py, puff(), soft(), frame cloud floating on the lagoon: 4-6…]
- "petsim_pet_props_coin_pile": "coin_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L668 | neighbors=[pet_props.py, flat(), vsh(), low gold mound with a short coin stack …]
- "petsim_pet_props_crystal_clump": "crystal_clump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L713 | neighbors=[pet_props.py, puff(), soft(), lilac rock base with 4-5 glowing hex cr…]
- "petsim_pet_props_crystal_spire": "crystal_spire()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L969 | neighbors=[pet_props.py, puff(), soft(), big crystal cluster: soft rock base, 3-…]
- "petsim_pet_props_crystal_tree": "crystal_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L777 | neighbors=[pet_props.py, bubble_crown(), soft(), dream tree: pale twisty trunk, lilac pu…]
- "petsim_pet_props_flower_patch": "flower_patch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L809 | neighbors=[pet_props.py, ell(), flat(), 5-7 chibi daisies: thin stem, leaf, sca…]
- "petsim_pet_props_glow_shroom": "glow_shroom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L993 | neighbors=[pet_props.py, ell(), soft(), trio of round-capped glow mushrooms (cy…]
- "petsim_pet_props_grass_tuft": "grass_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L827 | neighbors=[pet_props.py, ell(), soft(), chunky clover tuft: 3 rounded leaf blob…]
- "petsim_pet_props_lamp_post": "lamp_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1021 | neighbors=[pet_props.py, ell(), soft(), chibi lamp: bulgy base, slim post with …]
- "petsim_pet_props_puff_tree": "puff_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L742 | neighbors=[pet_props.py, bubble_crown(), soft(), lollipop / puffball tree: curved tapere…]
- "petsim_pet_props_sea_rock": "sea_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1054 | neighbors=[pet_props.py, rounded lagoon rock with a little grass…, puff(), soft()]
- "petsim_pet_props_soft_rock": "soft_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L885 | neighbors=[pet_props.py, smooth pebble boulder (squashed soft lu…, puff(), soft()]
- "physics_solver": "solver.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/solver.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, 87beff4 Sim solver: reject self/duplica…, 9eeb3ff Merge pull request #2 from Raft…, SequentialImpulseSolver]
- "plusspeed_plus_map_floor": "floor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L82 | neighbors=[plus_map.py, finish(), blk(), zone()]
- "plusspeed_plus_map_kerb_z": "kerb_z()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L57 | neighbors=[plus_map.py, blk(), race kerb along Z: alternating colour/w…, walls()]
- "plusspeed_plus_map_oval_track": "oval_track()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L70 | neighbors=[plus_map.py, hub(), blk(), running-track oval: red lane band, whit…]
- "plusspeed_plus_props_v3_bulbs_frame": "bulbs_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L44 | neighbors=[plus_props_v3.py, hatchery(), marquee light bulbs around a sign, shop_stall()]
- "plusspeed_plus_props_v3_wins_pad": "wins_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L219 | neighbors=[plus_props_v3.py, wins pad: stepped round base with a gol…, cyl_v(), ring()]
- "plusspeed_plus_props_v4_egg_hatchery": "egg_hatchery()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L117 | neighbors=[plus_props_v4.py, egg_rows(), pixel_art(), plinth()]
- "plusspeed_plus_props_v4_medal_rows": "medal_rows()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L162 | neighbors=[plus_props_v4.py, hoarding(), medal_pad(), raster()]
- "plusspeed_plus_props_v4_rebirth_portal": "rebirth_portal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L150 | neighbors=[plus_props_v4.py, pixel_art(), plinth(), portal_rows()]
- "preserved_verify_preservation": "verify_preservation.py" | kind=code-symbol | source=assets/characters/preserved/verify_preservation.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, capture(), floats(), c7a411f Fix MUT-01-20 audit defects in …]
- "refmatch_compare_band_widths": "band_widths()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L231 | neighbors=[compare.py, tight_crop(), evaluate(), Width of the subject at N bands, normal…]
- "refmatch_compare_bbox_report": "bbox_report()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L260 | neighbors=[compare.py, tight_crop(), evaluate(), Compare subject aspect ratio (width / h…]
- "refmatch_compare_fit_size": "_fit_size()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L29 | neighbors=[compare.py, letterbox(), normalize_mask(), Isotropic scale of (w, h) so the whole …]
- "refmatch_compare_flood_background_mask": "flood_background_mask()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L96 | neighbors=[compare.py, significant_components(), Segment by flood-filling the backdrop f…, subject_mask()]
- "refmatch_compare_ssim": "ssim()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L380 | neighbors=[compare.py, evaluate(), _conv_sep(), _gaussian_kernel()]
- "refmatch_compare_tight_crop": "tight_crop()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/compare.py:L216 | neighbors=[compare.py, band_widths(), bbox_report(), normalize_mask()]
- "refmatch_measure_sheet_auto_front": "auto_front()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/refmatch/measure_sheet.py:L62 | neighbors=[measure_sheet.py, subject_mask(), main(), Find the tallest narrow subject column …]
- "scripts_analyze_analyze": "analyze()" | kind=code-symbol | source=.agents/skills/skills-main/performance/r8-analyzer/scripts/analyze.py:L70 | neighbors=[analyze.py, describe_rule(), main(), Computes R8 optimization scores and rul…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-052.json

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
