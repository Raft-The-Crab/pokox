# Node Description Batch 74 of 207

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

- "onsenvillage_onsen_map_inside_one": "_inside_one()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L146 | neighbors=[onsen_map.py, fit_bad(), _inb()]
- "onsenvillage_onsen_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L23 | neighbors=[onsen_map.py, place(), static()]
- "onsenvillage_onsen_props_cedar": "cedar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L834 | neighbors=[onsen_props.py, lerp(), mountain cedar for the backdrop: straig…]
- "onsenvillage_onsen_props_cloud_tree": "cloud_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L806 | neighbors=[onsen_props.py, lerp(), broadleaf in the garden style: flared f…]
- "onsenvillage_onsen_props_crag": "crag()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L851 | neighbors=[onsen_props.py, lerp(), tall framing crag: 4-5 overlapping tape…]
- "onsenvillage_onsen_props_doorway": "doorway()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L153 | neighbors=[onsen_props.py, cut doorway: heavy posts + lintel, a sl…, storey_walls()]
- "onsenvillage_onsen_props_footbridge": "footbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L570 | neighbors=[onsen_props.py, giboshi(), arched cedar footbridge: plank deck on …]
- "onsenvillage_onsen_props_hand_cart": "hand_cart()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L727 | neighbors=[onsen_props.py, taru(), two-wheeled hand cart: plank bed with s…]
- "onsenvillage_onsen_props_jp_pine": "jp_pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L779 | neighbors=[onsen_props.py, lerp(), Japanese black pine: thick leaning trun…]
- "onsenvillage_onsen_props_railing": "railing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L478 | neighbors=[onsen_props.py, rail_post(), SIGNATURE: cedar railing bay with gibos…]
- "onsenvillage_onsen_props_railing_post": "railing_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L474 | neighbors=[onsen_props.py, rail_post(), the closing post at the end of a railin…]
- "onsenvillage_onsen_props_toro": "toro()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L492 | neighbors=[onsen_props.py, stone lantern (kasuga-style): hex stepp…, flared_roof()]
- "package_build_tool_build_project": "build_project()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L103 | neighbors=[build_tool.cpp, declared_identity(), name()]
- "parser_parser_dump_ast": "dump_ast()" | kind=code-symbol | source=mute/src/parser/parser.cpp:L361 | neighbors=[parser.cpp, op_spelling(), quoted()]
- "passes_cube_demo_main": "main()" | kind=code-symbol | source=engine/render/src/passes/cube_demo.cpp:L72 | neighbors=[cube_demo.cpp, cube_indices(), cube_vertices()]
- "passes_imgui_demo_main": "main()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L226 | neighbors=[imgui_demo.cpp, build_demo_window(), update_imgui_io()]
- "passes_triangle_demo": "triangle_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/triangle_demo.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Exception, main()]
- "petsim_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/hooks_lua.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, lua_attrs()]
- "petsim_pet_map_build_solid": "build_solid()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L153 | neighbors=[pet_map.py, build(), free()]
- "petsim_pet_map_clip_fail": "clip_fail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L167 | neighbors=[pet_map.py, inside(), place_soft()]
- "petsim_pet_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L613 | neighbors=[pet_map.py, free(), link()]
- "petsim_pet_map_ribbon_mesh": "ribbon_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L229 | neighbors=[pet_map.py, path_meshes(), H()]
- "petsim_pet_map_rim_points": "rim_points()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L322 | neighbors=[pet_map.py, isle_R(), scatter()]
- "petsim_pet_props_cotton_tree": "cotton_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L755 | neighbors=[pet_props.py, bubble_crown(), candy tree: candy-striped trunk (stripe…]
- "petsim_pet_props_egg_prof": "egg_prof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L139 | neighbors=[pet_props.py, egg(), egg_r()]
- "petsim_pet_props_gumdrops": "gumdrops()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L933 | neighbors=[pet_props.py, soft(), 3-4 sugar-dusted gumdrops in candy colo…]
- "petsim_pet_props_puff_bush": "puff_bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L793 | neighbors=[pet_props.py, ell(), soft()]
- "petsim_pet_props_star_poly": "star_poly()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L116 | neighbors=[pet_props.py, egg(), star()]
- "petsim_pet_props_stump": "stump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L877 | neighbors=[pet_props.py, flat(), soft()]
- "physics_soft_body": "soft_body.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/soft_body.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, ClothGrid, SoftBody]
- "pkb_pkb_draft_head": "head()" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L6 | neighbors=[pkb_draft.cpp, make_pkb_schema_draft(), text()]
- "pkb_pkb_draft_make_pkb_schema_draft": "make_pkb_schema_draft()" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L15 | neighbors=[pkb_draft.cpp, head(), text()]
- "pkb_pkb_draft_text": "text()" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L13 | neighbors=[pkb_draft.cpp, make_pkb_schema_draft(), head()]
- "plugins_superpowers_extractandstripfrontmatter": "extractAndStripFrontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L34 | neighbors=[superpowers.js, getBootstrapContent(), setup()]
- "plusspeed_plus_map_grp": "grp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L18 | neighbors=[plus_map.py, blk(), place()]
- "plusspeed_plus_map_kerb_x": "kerb_x()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L64 | neighbors=[plus_map.py, hub(), blk()]
- "plusspeed_plus_map_rationale_100": "v4 stadium hub: striped infield inside an oval running track, stations face in f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L100 | neighbors=[hub(), Block, BlockProp]
- "plusspeed_plus_map_rationale_40": "stepped canyon: tier n is a row of 24-wide blocks with a 2-stud cap, each tier t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L40 | neighbors=[walls(), Block, BlockProp]
- "plusspeed_plus_map_rationale_58": "race kerb along Z: alternating colour/white blocks proud of the cap edge, wedge" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L58 | neighbors=[kerb_z(), Block, BlockProp]
- "plusspeed_plus_map_rationale_71": "running-track oval: red lane band, white inner/outer lines and 2 lane lines" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L71 | neighbors=[oval_track(), Block, BlockProp]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-073.json

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
