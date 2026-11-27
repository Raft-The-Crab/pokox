# Node Description Batch 125 of 209

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

- "petsim_pet_props_rationale_619": "round spawn dais: two soft tiers, mint rim, a big paw-print inlay. Walkable (pre" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L619 | neighbors=[spawn_pad(), Palette] | lang=pt
- "petsim_pet_props_rationale_628": "humped chunky bridge along -Z (start z = 0 .. end z = -L), deck rises by `rise`;" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L628 | neighbors=[bridge(), Palette] | lang=en
- "petsim_pet_props_rationale_669": "low gold mound with a short coin stack and loose coins leaning on it" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L669 | neighbors=[coin_pile(), Palette] | lang=en
- "petsim_pet_props_rationale_683": "rounded treasure chest: plank body, domed lid, metal bands + lock (gold = tier 3" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L683 | neighbors=[chest(), Palette] | lang=en
- "petsim_pet_props_rationale_703": "chubby present: soft box, crossing ribbon bands, a two-loop bow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L703 | neighbors=[gift_box(), Palette] | lang=pt
- "petsim_pet_props_rationale_71": "soft cloud / crown: a sphere pushed out by smooth lobes, flattened underneath (s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L71 | neighbors=[puff(), Palette] | lang=en
- "petsim_pet_props_rationale_730": "chibi puffball crown: a core ball + n round bubbles on a fibonacci spiral over i" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L730 | neighbors=[bubble_crown(), Palette] | lang=pt
- "petsim_pet_props_rationale_743": "lollipop / puffball tree: curved tapered trunk with a root flare, one big smooth" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L743 | neighbors=[puff_tree(), Palette] | lang=en
- "petsim_pet_props_rationale_756": "candy tree: candy-striped trunk (stripe faces alternate), two-tone cotton-candy" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L756 | neighbors=[cotton_tree(), Palette] | lang=en
- "petsim_pet_props_rationale_778": "dream tree: pale twisty trunk, lilac puff crown with glowing crystal points poki" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L778 | neighbors=[crystal_tree(), Palette] | lang=en
- "petsim_pet_props_rationale_810": "5-7 chibi daisies: thin stem, leaf, scalloped petal disc, round centre" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L810 | neighbors=[flower_patch(), Palette] | lang=en
- "petsim_pet_props_rationale_838": "chubby toadstool: bulgy stem, domed cap with white spots, ring skirt" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L838 | neighbors=[mushroom(), Palette] | lang=en
- "petsim_pet_props_rationale_855": "checkered blanket (cells alternate red / cream), a wicker basket with a handle," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L855 | neighbors=[picnic_set(), Palette] | lang=pt
- "petsim_pet_props_rationale_893": "giant swirl lollipop: two interleaved coiled candy ropes (pink + cream) form the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L893 | neighbors=[lollipop(), Palette] | lang=en
- "petsim_pet_props_rationale_934": "3-4 sugar-dusted gumdrops in candy colours" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L934 | neighbors=[gumdrops(), Palette] | lang=en
- "petsim_pet_props_rationale_944": "pink-frosted donut lying tilted on the grass with sprinkles" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L944 | neighbors=[giant_donut(), Palette] | lang=en
- "petsim_pet_props_rationale_970": "big crystal cluster: soft rock base, 3-5 tall glowing points" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L970 | neighbors=[crystal_spire(), Palette] | lang=en
- "petsim_pet_props_rationale_983": "lilac curled post (a hook at the top) holding a glowing star lantern" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L983 | neighbors=[star_lamp(), Palette] | lang=pt
- "petsim_sheet": "sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "physics_character_controller_charactercontroller": "CharacterController" | kind=code-symbol | source=engine/physics/include/poko/physics/character_controller.hpp:L83 | neighbors=[character_controller.hpp, .CharacterController()] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-124.json

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
