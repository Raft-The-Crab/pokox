# Node Description Batch 124 of 209

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

- "passes_imgui_demo_feed_imgui_event": "feed_imgui_event()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L137 | neighbors=[imgui_demo.cpp, imgui_key()] | lang=en
- "passes_imgui_demo_imgui_key": "imgui_key()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L113 | neighbors=[imgui_demo.cpp, feed_imgui_event()] | lang=en
- "passes_imgui_demo_update_imgui_io": "update_imgui_io()" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L82 | neighbors=[imgui_demo.cpp, main()] | lang=en
- "petsim_pet_map_catmull": "catmull()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L208 | neighbors=[pet_map.py, path()] | lang=en
- "petsim_pet_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L122 | neighbors=[pet_map.py, place()] | lang=en
- "petsim_pet_map_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L161 | neighbors=[pet_map.py, clip_fail()] | lang=en
- "petsim_pet_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L117 | neighbors=[pet_map.py, place()] | lang=en
- "petsim_pet_map_rationale_256": "polar tile disc: rings of soft tiles alternating cream / pink, inset grout, a sk" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L256 | neighbors=[plaza(), MB] | lang=en
- "petsim_pet_map_rationale_330": "items = [(key, fn, scale_range)], n tries; keeps clear of paths + reserved spots" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L330 | neighbors=[scatter(), MB] | lang=en
- "petsim_pet_map_rationale_341": "clusters of 3-5 breakables off the paths; tier rises with distance from the zone" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L341 | neighbors=[breakables(), MB] | lang=en
- "petsim_pet_map_rationale_538": "clouds + rocks on the lagoon round the chain (outside every island, off the brid" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L538 | neighbors=[frame(), MB] | lang=en
- "petsim_pet_map_rationale_60": "polar top (dome) + rounded icing shoulder + sponge cliff down into the lagoon. C" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L60 | neighbors=[isle_mesh(), MB] | lang=en
- "petsim_pet_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L556 | neighbors=[pet_map.py, frame()] | lang=en
- "petsim_pet_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L651 | neighbors=[pet_map.py, link()] | lang=en
- "petsim_pet_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L149 | neighbors=[pet_map.py, place_soft()] | lang=en
- "petsim_pet_props_arc_pts": "arc_pts()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L113 | neighbors=[pet_props.py, trade_pad()] | lang=en
- "petsim_pet_props_candy_cane": "candy_cane()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L910 | neighbors=[pet_props.py, hooked cane, red / cream diagonal strip…] | lang=en
- "petsim_pet_props_disc_up": "disc_up()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L124 | neighbors=[pet_props.py, rcyl()] | lang=en
- "petsim_pet_props_egg_r": "egg_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L147 | neighbors=[pet_props.py, egg_prof()] | lang=en
- "petsim_pet_props_lift": "lift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L136 | neighbors=[pet_props.py, egg()] | lang=en
- "petsim_pet_props_mascot_test": "mascot_test()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1061 | neighbors=[pet_props.py, puffpaw()] | lang=en
- "petsim_pet_props_rationale_1006": "chunky rail fence segment from x = 0 to x = L: one fat post with a ball cap at x" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1006 | neighbors=[fence(), Palette] | lang=en
- "petsim_pet_props_rationale_1022": "chibi lamp: bulgy base, slim post with a candy ring, round glowing lantern under" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1022 | neighbors=[lamp_post(), Palette] | lang=en
- "petsim_pet_props_rationale_1033": "chubby rounded bench: two soft seat slats + back slat on stubby round legs. Fron" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1033 | neighbors=[bench(), Palette] | lang=en
- "petsim_pet_props_rationale_1044": "frame cloud floating on the lagoon: 4-6 overlapping puffs merged, flat bottom" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L1044 | neighbors=[cloud(), Palette] | lang=en
- "petsim_pet_props_rationale_120": "a chunky star standing upright facing -Z, centred at the origin, rounded front e" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L120 | neighbors=[star(), Palette] | lang=en
- "petsim_pet_props_rationale_128": "paw-print icon: palm pad + 4 toe beans, built flat then stood up facing -Z (pitc" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L128 | neighbors=[paw(), Palette] | lang=en
- "petsim_pet_props_rationale_155": "smooth lathe egg + decoration: 'spots', 'stars', 'zig', 'swirl', 'gems', 'flower" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L155 | neighbors=[egg(), Palette] | lang=en
- "petsim_pet_props_rationale_204": "the mascot: chubby sitting creature, huge head, tall round ears, big eyes with h" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L204 | neighbors=[puffpaw(), Palette] | lang=en
- "petsim_pet_props_rationale_272": "hub hero: 3-tier pastel fountain (scalloped basin, water, mid bowl with a pale w" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L272 | neighbors=[pet_fountain(), Palette] | lang=en
- "petsim_pet_props_rationale_324": "the Puffpaw statue + its quilted cushion: a separate MeshPart sharing the founta" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L324 | neighbors=[pet_statue(), Palette] | lang=en
- "petsim_pet_props_rationale_336": "6 chunky pastel bands on a half circle, standing on two big cloud feet, sparkle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L336 | neighbors=[rainbow_arch(), Palette] | lang=pt
- "petsim_pet_props_rationale_358": "open-front kiosk: round dais, curved back wall with toy shelves, 4 chubby pillar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L358 | neighbors=[pet_shop(), Palette] | lang=en
- "petsim_pet_props_rationale_452": "giant gumball machine: rounded red drum base (coin plate, glowing up-chevron, ch" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L452 | neighbors=[upgrade_machine(), Palette] | lang=en
- "petsim_pet_props_rationale_487": "round trade table with a big scalloped two-tone umbrella and two chubby stools." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L487 | neighbors=[trade_booth(), Palette] | lang=en
- "petsim_pet_props_rationale_52": "height gradient a->b between y0..y1 plus a lit side toward SUN (needs the shape" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L52 | neighbors=[soft(), Palette] | lang=es
- "petsim_pet_props_rationale_520": "flat trade circle: cream disc with a pastel rim and two glowing curved swap arro" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L520 | neighbors=[trade_pad(), Palette] | lang=en
- "petsim_pet_props_rationale_535": "blank board in a chunky rounded frame on two candy posts, a crown icon on top. F" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L535 | neighbors=[leaderboard(), Palette] | lang=pt
- "petsim_pet_props_rationale_567": "fluted cake pedestal with a glowing ring under a giant decorated egg; 3 little s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L567 | neighbors=[egg_stand(), Palette] | lang=pt
- "petsim_pet_props_rationale_585": "toll arch: two chubby stacked pillars with paw-ball finials, a rounded arch beam" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_props.py:L585 | neighbors=[zone_gate(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-123.json

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
