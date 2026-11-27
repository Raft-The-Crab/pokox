# Node Description Batch 119 of 207

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

- "onsenvillage_onsen_props_rationale_138": "cut window: timber frame round the hole, sill, recessed shoji lattice with a war" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L138 | neighbors=[window(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_154": "cut doorway: heavy posts + lintel, a sliding lattice door half open, warm lit in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L154 | neighbors=[doorway(), Palette] | lang=nl
- "onsenvillage_onsen_props_rationale_177": "deck on brackets along a wall at z (side = -1 front), cedar rail with giboshi po" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L177 | neighbors=[balcony(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_200": "SHARED BASE: sand-ashlar plinth (block faces) with a chamfered cap course, sunk" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L200 | neighbors=[plinth(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_209": "dark cedar framing: corner posts, extra posts, a head beam (nageshi) and sill al" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L209 | neighbors=[frame_storey(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_224": "four plaster walls of one storey with cut openings; returns the x positions of w" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L224 | neighbors=[storey_walls(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_245": "chouchin: glowing ribbed paper body with dark wood top + bottom rings and a hang" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L245 | neighbors=[paper_lantern(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_258": "village house / inn: ashlar plinth, plaster storeys with cut windows + door, ced" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L258 | neighbors=[house(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_283": "open market front: back + side walls, a wide opening with a counter, shelves of" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L283 | neighbors=[shopfront(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_315": "HERO: five-tier bathhouse pagoda. Stepped ashlar platform + veranda, five storey" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L315 | neighbors=[pagoda(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_375": "open bath shelter over a pool: round cedar columns on stone bases, tie beams, br" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L375 | neighbors=[bath_pavilion(), Palette] | lang=pt
- "onsenvillage_onsen_props_rationale_406": "steaming rock pool: raised ashlar-and-boulder rim, cut-stone curb, milky water," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L406 | neighbors=[hot_pool(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_450": "small round stone pond: dressed rim, water, three koi, lily pads, a moss boulder" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L450 | neighbors=[koi_pond(), Palette] | lang=pt
- "onsenvillage_onsen_props_rationale_475": "the closing post at the end of a railing run (bays carry only their left post, s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L475 | neighbors=[railing_post(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_479": "SIGNATURE: cedar railing bay with giboshi-capped posts, top + mid rails, slim ba" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L479 | neighbors=[railing(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_49": "Asian glazed roof: a lofted surface from the eave polygon `outer` (corners [(x," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L49 | neighbors=[flared_roof(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_493": "stone lantern (kasuga-style): hex stepped base, bulged shaft, hex platform, fire" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L493 | neighbors=[toro(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_517": "stone trough planter (hollow, soil inside) with cloud-pruned sage shrubs and a f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L517 | neighbors=[planter(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_547": "stone stair: bevelled sand treads with tone variation and a nosing shadow, ashla" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L547 | neighbors=[stair_flight(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_571": "arched cedar footbridge: plank deck on curved stringers, giboshi-capped rail pos" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L571 | neighbors=[footbridge(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_609": "drying rack: two cedar uprights with feet, three poles, folded towels draped ove" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L609 | neighbors=[towel_rack(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_633": "yatai cart: two spoked wheels, cedar counter cabin with a plank top, small persi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L633 | neighbors=[noodle_stall(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_668": "sake cask: straw-wrapped body, rope bands, lid; lying casks rest on their side" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L668 | neighbors=[taru(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_682": "cluster: cedar pallet, three standing casks, one on top, one lying in a chock, a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L682 | neighbors=[sake_barrels(), Palette] | lang=pt
- "onsenvillage_onsen_props_rationale_696": "stack: slatted cedar crates with corner battens, a rope-tied sack pile and a bas" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L696 | neighbors=[crates(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_718": "thick cedar bench: two planks, cross battens, iron bolts, carved stone feet" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L718 | neighbors=[bench(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_728": "two-wheeled hand cart: plank bed with side boards, long handles, spoked wheels," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L728 | neighbors=[hand_cart(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_746": "cedar lamp post with a crossarm and a hanging paper lantern, stone footing" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L746 | neighbors=[paper_lantern_post(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_757": "shrine gate: two cedar columns on stone bases, double lintel (kasagi with upswep" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L757 | neighbors=[torii(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_780": "Japanese black pine: thick leaning trunk with a kink, horizontal limbs ending in" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L780 | neighbors=[jp_pine(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_807": "broadleaf in the garden style: flared forked trunk, 5 boughs, a dense rounded cr" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L807 | neighbors=[cloud_tree(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_835": "mountain cedar for the backdrop: straight trunk, stacked drooping sage skirts (n" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L835 | neighbors=[cedar(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_852": "tall framing crag: 4-5 overlapping tapered rock columns of different heights (on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L852 | neighbors=[crag(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_878": "low clump of sage fronds for wall feet and banks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L878 | neighbors=[fern_tuft(), Palette] | lang=en
- "onsenvillage_onsen_props_stair_flight": "stair_flight()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L546 | neighbors=[onsen_props.py, stone stair: bevelled sand treads with …] | lang=en
- "onsenvillage_onsen_props_torii": "torii()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L756 | neighbors=[onsen_props.py, shrine gate: two cedar columns on stone…] | lang=en
- "package_build_tool_after_token": "after_token()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L39 | neighbors=[build_tool.cpp, declared_identity()] | lang=en
- "package_build_tool_name": "name()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L141 | neighbors=[build_tool.cpp, build_project()] | lang=en
- "package_build_tool_next_quoted": "next_quoted()" | kind=code-symbol | source=mute/src/package/build_tool.cpp:L43 | neighbors=[build_tool.cpp, declared_identity()] | lang=en
- "package_package_inner_position": "inner_position()" | kind=code-symbol | source=mute/src/package/package.cpp:L21 | neighbors=[package.cpp, resolve_packages()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-118.json

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
