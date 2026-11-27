# Node Description Batch 114 of 209

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

- "evaluator_evaluator_literal_float": "literal_float()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L162 | neighbors=[evaluator.cpp, fail()]
- "examples_axolotl_gill_base": "gill_base()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L30 | neighbors=[axolotl.py, build()]
- "examples_axolotl_happy": "happy()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L137 | neighbors=[axolotl.py, gills()]
- "examples_axolotl_idle": "idle()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L108 | neighbors=[axolotl.py, gills()]
- "examples_axolotl_swim": "swim()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L126 | neighbors=[axolotl.py, gills()]
- "examples_axolotl_unit": "_unit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L26 | neighbors=[axolotl.py, build()]
- "examples_axolotl_walk": "walk()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L116 | neighbors=[axolotl.py, gills()]
- "examples_gridfinity_d110_bin_rationale_1": "Gridfinity 3x2 cradle bin for the Orico D110 label printer.  The hand-rolled ori" | kind=entity | source=.agents/skills/cad-skill-main/examples/gridfinity_d110_bin.py:L1 | neighbors=[GridfinityBin, gridfinity_d110_bin.py]
- "examples_mx_master3_bin_3x3_rationale_1": "Gridfinity 3x3 diagonal cradle bin for the Logitech MX Master 3.  Showcases the" | kind=entity | source=.agents/skills/cad-skill-main/examples/mx_master3_bin_3x3.py:L1 | neighbors=[GridfinityBin, mx_master3_bin_3x3.py]
- "extensions_superpowers_pitoolmapping": "piToolMapping()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L83 | neighbors=[superpowers.ts, getBootstrapContent()]
- "extensions_superpowers_stripfrontmatter": "stripFrontmatter()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L78 | neighbors=[superpowers.ts, getBootstrapContent()]
- "fakes_refcntautoptr_refcntautoptr": "RefCntAutoPtr" | kind=code-symbol | source=engine/rhi/tests/fakes/RefCntAutoPtr.hpp:L4 | neighbors=[RefCntAutoPtr.hpp, .RefCntAutoPtr()]
- "fishcenter_fish_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L514 | neighbors=[fish_map.py, stations()]
- "fishcenter_fish_map_bay_key": "bay_key()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L456 | neighbors=[fish_map.py, rails_flush()]
- "fishcenter_fish_map_halfang": "halfang()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L511 | neighbors=[fish_map.py, edges()]
- "fishcenter_fish_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L153 | neighbors=[fish_map.py, _inside_one()]
- "fishcenter_fish_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L87 | neighbors=[fish_map.py, place()]
- "fishcenter_fish_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L701 | neighbors=[fish_map.py, free()]
- "fishcenter_fish_map_rationale_101": "auto-grounded props (y None) are fitted against everything built so far (see fit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L101 | neighbors=[place(), MB]
- "fishcenter_fish_map_rationale_203": "plank / slab from a top quad [(x, z) x4] at height y, thickness th" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L203 | neighbors=[prism(), MB]
- "fishcenter_fish_map_rationale_229": "plank deck in a pad-local frame: planks along local x (across the walk), gaps, t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L229 | neighbors=[deck_rect(), MB]
- "fishcenter_fish_map_rationale_251": "the ring boardwalk: radial planks (across the walk), stringers along both edges" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L251 | neighbors=[ring_deck(), MB]
- "fishcenter_fish_map_rationale_270": "central coral-stone platform: polar flagstones (inset), coping course, ashlar fo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L270 | neighbors=[platform(), MB]
- "fishcenter_fish_map_rationale_300": "compass-rose inlay in the spawn plaza deck: 8-point star of teal / yellow planks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L300 | neighbors=[compass(), MB]
- "fishcenter_fish_map_rationale_340": "seabed + islets in one grid: fine inside the reef, coarse to the horizon; colour" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L340 | neighbors=[ground(), MB]
- "fishcenter_fish_map_rationale_377": "organic grass mounds sitting IN each islet top: irregular rounded outline, rim t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L377 | neighbors=[islet_grass(), MB]
- "fishcenter_fish_map_rationale_38": "pad-local (lx tangential, lz radial outward from the pad centre rc) -> world (x," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L38 | neighbors=[lp(), MB]
- "fishcenter_fish_map_rationale_410": "tropical volcanic islands in 3 overlapping depth layers. Each = a wide sand / ro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L410 | neighbors=[horizon(), MB]
- "fishcenter_fish_map_rationale_462": "straight run a->b (x, z) with gaps [(s0, s1)] in studs along it: bays ~6 long, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L462 | neighbors=[rail_line(), MB]
- "fishcenter_fish_map_rationale_475": "arc run from angle a0 to a1 (degrees, increasing): chord bays + an end post" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L475 | neighbors=[rail_arc(), MB]
- "fishcenter_fish_map_rationale_484": "place every collected run: each bay carries the post at its start, a post closes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L484 | neighbors=[rails_flush(), MB]
- "fishcenter_fish_map_rationale_504": "full circle at radius r minus angular gaps [(centre, half width deg)]" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L504 | neighbors=[arc_with_gaps(), MB]
- "fishcenter_fish_map_rationale_67": "seabed / islets; out at the world edge it rises to +1 so the sea plane's border" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L67 | neighbors=[H(), MB]
- "fishcenter_fish_map_rationale_71": "the natural depth profile (deep blue past the reef): only the seabed COLOUR stil" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L71 | neighbors=[H_raw(), MB]
- "fishcenter_fish_map_top": "_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L163 | neighbors=[fish_map.py, fit_bad()]
- "fishcenter_fish_props_buoy_stack": "buoy_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L609 | neighbors=[fish_props.py, trap floats and a coiled rope: stacked …]
- "fishcenter_fish_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L514 | neighbors=[fish_props.py, flat-bottomed cumulus for the horizon (…]
- "fishcenter_fish_props_crate_stack": "crate_stack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L545 | neighbors=[fish_props.py, crate()]
- "fishcenter_fish_props_lifebuoy_stand": "lifebuoy_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L311 | neighbors=[fish_props.py, ball()]
- "fishcenter_fish_props_rationale_1013": "QUEST BOARD: two bamboo posts with lashings, framed cork panel with blank pinned" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L1013 | neighbors=[quest_board(), Palette]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-113.json

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
