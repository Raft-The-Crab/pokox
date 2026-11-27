# Node Description Batch 76 of 208

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
LANGUAGE: each entry has a `lang=` marker giving the language of its source.
Write that entry's description in EXACTLY that language. Do not translate to
a single common language — match each node's source language individually.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "petsim_pet_map_ribbon_mesh": "ribbon_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L229 | neighbors=[pet_map.py, path_meshes(), H()] | lang=en
- "petsim_pet_map_rim_points": "rim_points()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L322 | neighbors=[pet_map.py, isle_R(), scatter()] | lang=en
- "petsim_pet_props_cotton_tree": "cotton_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L755 | neighbors=[pet_props.py, bubble_crown(), candy tree: candy-striped trunk (stripe…] | lang=en
- "petsim_pet_props_egg_prof": "egg_prof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L139 | neighbors=[pet_props.py, egg(), egg_r()] | lang=en
- "petsim_pet_props_gumdrops": "gumdrops()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L933 | neighbors=[pet_props.py, soft(), 3-4 sugar-dusted gumdrops in candy colo…] | lang=en
- "petsim_pet_props_puff_bush": "puff_bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L793 | neighbors=[pet_props.py, ell(), soft()] | lang=en
- "petsim_pet_props_star_poly": "star_poly()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L116 | neighbors=[pet_props.py, egg(), star()] | lang=en
- "petsim_pet_props_stump": "stump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L877 | neighbors=[pet_props.py, flat(), soft()] | lang=en
- "physics_soft_body": "soft_body.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/soft_body.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, ClothGrid, SoftBody] | lang=en
- "pkb_pkb_draft_head": "head()" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L6 | neighbors=[pkb_draft.cpp, make_pkb_schema_draft(), text()] | lang=en
- "pkb_pkb_draft_make_pkb_schema_draft": "make_pkb_schema_draft()" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L15 | neighbors=[pkb_draft.cpp, head(), text()] | lang=en
- "pkb_pkb_draft_text": "text()" | kind=code-symbol | source=mute/src/pkb/pkb_draft.cpp:L13 | neighbors=[pkb_draft.cpp, make_pkb_schema_draft(), head()] | lang=en
- "plugins_superpowers_extractandstripfrontmatter": "extractAndStripFrontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L34 | neighbors=[superpowers.js, getBootstrapContent(), setup()] | lang=en
- "plusspeed_plus_map_grp": "grp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L18 | neighbors=[plus_map.py, blk(), place()] | lang=en
- "plusspeed_plus_map_kerb_x": "kerb_x()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L64 | neighbors=[plus_map.py, hub(), blk()] | lang=en
- "plusspeed_plus_map_rationale_100": "v4 stadium hub: striped infield inside an oval running track, stations face in f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L100 | neighbors=[hub(), Block, BlockProp] | lang=en
- "plusspeed_plus_map_rationale_40": "stepped canyon: tier n is a row of 24-wide blocks with a 2-stud cap, each tier t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L40 | neighbors=[walls(), Block, BlockProp] | lang=en
- "plusspeed_plus_map_rationale_58": "race kerb along Z: alternating colour/white blocks proud of the cap edge, wedge" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L58 | neighbors=[kerb_z(), Block, BlockProp] | lang=en
- "plusspeed_plus_map_rationale_71": "running-track oval: red lane band, white inner/outer lines and 2 lane lines" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L71 | neighbors=[oval_track(), Block, BlockProp] | lang=en
- "plusspeed_plus_map_rationale_89": "put theme props on cap tops (centre of the 24-wide cap), skipping some for rhyth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L89 | neighbors=[dress_caps(), Block, BlockProp] | lang=en
- "plusspeed_plus_map_sky": "sky()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L209 | neighbors=[plus_map.py, blk(), place()] | lang=en
- "plusspeed_plus_props_lamp_pillar": "lamp_pillar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L211 | neighbors=[plus_props.py, the stacked-cube lamp pillar from the r…, zone_gate()] | lang=en
- "plusspeed_plus_props_rationale_212": "the stacked-cube lamp pillar from the reference game" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L212 | neighbors=[lamp_pillar(), BlockProp, Palette] | lang=en
- "plusspeed_plus_props_rationale_223": "two lamp pillars at the track edges, a top beam with a sign board (name / price" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L223 | neighbors=[zone_gate(), BlockProp, Palette] | lang=en
- "plusspeed_plus_props_rationale_326": "START / FINISH arch: two chunky towers, a deep beam with a black/white checker b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L326 | neighbors=[big_arch(), BlockProp, Palette] | lang=pt
- "plusspeed_plus_props_rationale_343": "finish hero: 1-2-3 podium with a giant blocky trophy on the top step" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L343 | neighbors=[trophy(), BlockProp, Palette] | lang=en
- "plusspeed_plus_props_v3_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L83 | neighbors=[plus_props_v3.py, cyl_v(), shop_stall()] | lang=en
- "plusspeed_plus_props_v3_framed_panel": "framed_panel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L52 | neighbors=[plus_props_v3.py, hatchery(), shop_stall()] | lang=en
- "plusspeed_plus_props_v3_gable": "gable()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L37 | neighbors=[plus_props_v3.py, gable roof along X: two wedges back to …, shop_stall()] | lang=en
- "plusspeed_plus_props_v3_potion": "potion()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L70 | neighbors=[plus_props_v3.py, cyl_v(), shop_stall()] | lang=en
- "plusspeed_plus_props_v4_egg_rows": "egg_rows()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L101 | neighbors=[plus_props_v4.py, egg_hatchery(), raster()] | lang=en
- "plusspeed_plus_props_v4_hoarding": "hoarding()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L239 | neighbors=[plus_props_v4.py, medal_rows(), pixel_art()] | lang=en
- "plusspeed_plus_props_v4_medal_pad": "medal_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L177 | neighbors=[plus_props_v4.py, medal_rows(), pixel_art()] | lang=en
- "plusspeed_plus_props_v4_portal_rows": "portal_rows()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L132 | neighbors=[plus_props_v4.py, raster(), rebirth_portal()] | lang=en
- "plusspeed_plus_props_v4_sneaker_shop": "sneaker_shop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L86 | neighbors=[plus_props_v4.py, pixel_art(), plinth()] | lang=en
- "plusspeed_plus_props_v4_start_gate": "start_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L208 | neighbors=[plus_props_v4.py, pixel_art(), stopwatch_rows()] | lang=en
- "plusspeed_plus_props_v4_stopwatch_rows": "stopwatch_rows()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L190 | neighbors=[plus_props_v4.py, start_gate(), raster()] | lang=en
- "plusspeed_plus_props_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L222 | neighbors=[plus_props.py, two lamp pillars at the track edges, a …, lamp_pillar()] | lang=en
- "preserved_preserve_r6": "preserve_r6.py" | kind=code-symbol | source=assets/characters/preserved/preserve_r6.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, Preservation-first R6 export. Never ove…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "preserved_preview_face_glb": "preview_face_glb.py" | kind=code-symbol | source=assets/characters/preserved/preview_face_glb.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, point_at(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-075.json

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
