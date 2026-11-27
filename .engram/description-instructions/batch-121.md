# Node Description Batch 122 of 209

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

- "onsenvillage_onsen_map_rationale_246": "distant peaks far behind the saddle (pale violet with snow caps) + low ridges at" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L246 | neighbors=[horizon(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_264": "stream + front pool surface: 4-stud cells kept only where the ground dips below" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L264 | neighbors=[water(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_283": "each terrace = running-bond flagstone top (inset stones, cream) + ashlar riser o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L283 | neighbors=[terraces(), MB] | lang=pt
- "onsenvillage_onsen_map_rationale_327": "flagstone path on the front bank from the bridge foot toward the camera, ragged" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L327 | neighbors=[bank_path(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_347": "SIGNATURE: railing bays along a terrace lip with gaps at stairs / bridge; stone" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L347 | neighbors=[rail_run(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_410": "clusters of 2-4 at the stairs and bridge; deliberately NOT mirrored (props break" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L410 | neighbors=[stories(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_492": "preview-only steam volumes over the hot water (Roblox: ParticleEmitters at these" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L492 | neighbors=[steam(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_61": "one height function for ground mesh AND placement (terrace tops are flat; risers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L61 | neighbors=[H(), MB] | lang=en
- "onsenvillage_onsen_map_rationale_91": "auto-grounded props (y None) are fitted against everything built so far (see fit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L91 | neighbors=[place(), MB] | lang=en
- "onsenvillage_onsen_map_terrace_at": "terrace_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L40 | neighbors=[onsen_map.py, H()] | lang=en
- "onsenvillage_onsen_map_top": "_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L155 | neighbors=[onsen_map.py, fit_bad()] | lang=en
- "onsenvillage_onsen_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L717 | neighbors=[onsen_props.py, thick cedar bench: two planks, cross ba…] | lang=en
- "onsenvillage_onsen_props_crates": "crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L695 | neighbors=[onsen_props.py, stack: slatted cedar crates with corner…] | lang=en
- "onsenvillage_onsen_props_fern_tuft": "fern_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L877 | neighbors=[onsen_props.py, low clump of sage fronds for wall feet …] | lang=en
- "onsenvillage_onsen_props_koi_pond": "koi_pond()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L449 | neighbors=[onsen_props.py, small round stone pond: dressed rim, wa…] | lang=en
- "onsenvillage_onsen_props_planter": "planter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L516 | neighbors=[onsen_props.py, stone trough planter (hollow, soil insi…] | lang=en
- "onsenvillage_onsen_props_pool_outline": "pool_outline()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L397 | neighbors=[onsen_props.py, hot_pool()] | lang=en
- "onsenvillage_onsen_props_rationale_105": "rectangular hip roof over a hw x hd (half sizes) wall box: ridge along X, ridge" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L105 | neighbors=[hip_roof(), Palette] | lang=pt
- "onsenvillage_onsen_props_rationale_119": "pent roof around a storey (pagoda tiers, inn skirts): from the eave down to the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L119 | neighbors=[skirt_roof(), Palette] | lang=en
- "onsenvillage_onsen_props_rationale_126": "wall panel L long (x -L/2..L/2), H high, th thick, holes [(x0, x1, y0, y1)] cut" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_props.py:L126 | neighbors=[holed_wall(), Palette] | lang=es
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
