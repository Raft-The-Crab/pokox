# Node Description Batch 122 of 207

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

- "physics_convex_shape": "convex_shape.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/convex_shape.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, ConvexShape] | lang=en
- "physics_convex_shape_convexshape": "ConvexShape" | kind=code-symbol | source=engine/physics/include/poko/physics/convex_shape.hpp:L30 | neighbors=[convex_shape.hpp, .ConvexShape()] | lang=en
- "physics_sap_broadphase": "sap_broadphase.hpp" | kind=code-symbol | source=engine/physics/include/poko/physics/sap_broadphase.hpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, SapBroadphase] | lang=en
- "plugins_superpowers_cachechildsession": "_cacheChildSession()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L171 | neighbors=[superpowers.js, isChildSession()] | lang=en
- "plugins_superpowers_getbootstrapcontent": "getBootstrapContent()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L122 | neighbors=[superpowers.js, extractAndStripFrontmatter()] | lang=en
- "plugins_superpowers_ischildsession": "isChildSession()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L182 | neighbors=[superpowers.js, _cacheChildSession()] | lang=en
- "plugins_superpowers_setup": "setup()" | kind=code-symbol | source=.agents/skills/superpowers-main/.opencode/plugins/superpowers.js:L295 | neighbors=[superpowers.js, extractAndStripFrontmatter()] | lang=en
- "plusspeed_plus_props_big_arch": "big_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L325 | neighbors=[plus_props.py, START / FINISH arch: two chunky towers,…] | lang=en
- "plusspeed_plus_props_fix_rationale_98": "finish hero: 1-2-3 podium + a giant cylinder-built trophy (base, stem, flared cu" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L98 | neighbors=[trophy(), BlockProp] | lang=pt
- "plusspeed_plus_props_fix_trophy": "trophy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_fix.py:L97 | neighbors=[plus_props_fix.py, finish hero: 1-2-3 podium + a giant cyl…] | lang=en
- "plusspeed_plus_props_trophy": "trophy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props.py:L342 | neighbors=[plus_props.py, finish hero: 1-2-3 podium with a giant …] | lang=en
- "plusspeed_plus_props_v3_gift": "gift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L77 | neighbors=[plus_props_v3.py, shop_stall()] | lang=en
- "plusspeed_plus_props_v3_rationale_10": "block whose top edges are chamfered with 4 wedges (reads bevelled, not a raw cub" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L10 | neighbors=[chamfer_block(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_112": "SPEED SHOP: platform with a ramp, panelled counter, back wall with shelves of sp" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L112 | neighbors=[shop_stall(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_160": "EGG HATCHERY: tiered round base with rims, glass dome over a big spotted egg on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L160 | neighbors=[hatchery(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_197": "REBIRTH portal: 8-sided stepped dais with rune ring, a standing ring portal (tan" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L197 | neighbors=[rebirth_altar(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_21": "8-sided column from two overlapping blocks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L21 | neighbors=[octo(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_220": "wins pad: stepped round base with a gold rim, glowing ring and centre emblem, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L220 | neighbors=[wins_pad(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_30": "n blocks laid tangent around a circle (plane 'xy' = vertical ring facing Z, 'xz'" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L30 | neighbors=[ring(), BlockProp] | lang=pt
- "plusspeed_plus_props_v3_rationale_38": "gable roof along X: two wedges back to back + ridge trim" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L38 | neighbors=[gable(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_rationale_45": "marquee light bulbs around a sign" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L45 | neighbors=[bulbs_frame(), BlockProp] | lang=pt
- "plusspeed_plus_props_v3_rationale_91": "street lantern pillar: chamfered stepped plinth, 8-sided banded column, capital," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L91 | neighbors=[lamp_pillar(), BlockProp] | lang=en
- "plusspeed_plus_props_v3_speed_shoe": "speed_shoe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L59 | neighbors=[plus_props_v3.py, shop_stall()] | lang=en
- "plusspeed_plus_props_v3_treadmill": "treadmill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v3.py:L239 | neighbors=[plus_props_v3.py, chamfer_block()] | lang=en
- "plusspeed_plus_props_v4_kerb_lip": "kerb_lip()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L47 | neighbors=[plus_props_v4.py, alternating colour / white kerb blocks …] | lang=en
- "plusspeed_plus_props_v4_podium_board": "podium_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L225 | neighbors=[plus_props_v4.py, plinth()] | lang=en
- "plusspeed_plus_props_v4_rationale_18": "rows[0] is the top row. Art is centred on X at pos, bottom at pos.y, front face" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L18 | neighbors=[pixel_art(), BlockProp] | lang=en
- "plusspeed_plus_props_v4_rationale_39": "fn(x, y) -> char, x/y in -1..1 (y up); returns rows top->bottom" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L39 | neighbors=[raster(), BlockProp] | lang=es
- "plusspeed_plus_props_v4_rationale_48": "alternating colour / white kerb blocks with a wedge bevel on the outer edge; gro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_props_v4.py:L48 | neighbors=[kerb_lip(), BlockProp] | lang=en
- "preserved_preserve_r6": "preserve_r6.py" | kind=code-symbol | source=assets/characters/preserved/preserve_r6.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Preservation-first R6 export. Never ove…] | lang=en
- "preserved_preview_face_glb": "preview_face_glb.py" | kind=code-symbol | source=assets/characters/preserved/preview_face_glb.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, point_at()] | lang=en
- "preserved_verify_preservation_capture": "capture()" | kind=code-symbol | source=assets/characters/preserved/verify_preservation.py:L12 | neighbors=[verify_preservation.py, floats()] | lang=en
- "preserved_verify_preservation_floats": "floats()" | kind=code-symbol | source=assets/characters/preserved/verify_preservation.py:L8 | neighbors=[verify_preservation.py, capture()] | lang=en
- "preserved_verify_roundtrip": "verify_roundtrip.py" | kind=code-symbol | source=assets/characters/preserved/verify_roundtrip.py:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Read-only Blender GLB round-trip check.…] | lang=en
- "program_program_compile_program_bytecode": "compile_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L342 | neighbors=[program.cpp, prepare_globals()] | lang=en
- "program_program_depth": "Depth()" | kind=code-symbol | source=mute/src/program/program.cpp:L25 | neighbors=[program.cpp, fail()] | lang=en
- "program_program_inspect_program_state_schema": "inspect_program_state_schema()" | kind=code-symbol | source=mute/src/program/program.cpp:L334 | neighbors=[program.cpp, prepare_globals()] | lang=en
- "program_program_parser": "Parser" | kind=code-symbol | source=mute/src/program/program.cpp:L50 | neighbors=[program.cpp, .Parser()] | lang=en
- "program_program_run_program": "run_program()" | kind=code-symbol | source=mute/src/program/program.cpp:L331 | neighbors=[program.cpp, run_stateful_program()] | lang=en
- "program_program_run_program_bytecode": "run_program_bytecode()" | kind=code-symbol | source=mute/src/program/program.cpp:L356 | neighbors=[program.cpp, run_stateful_program_bytecode()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-121.json

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
