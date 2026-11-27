# Node Description Batch 151 of 209

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

- "voidrealm_void_props_rationale_199": "abstract rune inlay (never a letter): diamond / chevron / ring-dot, flat in XY f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L199 | neighbors=[Palette, rune_glyph()] | lang=en
- "voidrealm_void_props_rationale_210": "fluted void-stone column: stepped plinth, entasis shaft with 12 flutes, rune ban" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L210 | neighbors=[Palette, pillar()] | lang=en
- "voidrealm_void_props_rationale_246": "ruined gateway arch: two square piers with trim bands + rune inlays, a voussoir" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L246 | neighbors=[Palette, void_arch()] | lang=en
- "voidrealm_void_props_rationale_291": "flat ceremonial circle: pale trim ring set into dark stone, two broken glow ring" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L291 | neighbors=[Palette, rune_circle()] | lang=en
- "voidrealm_void_props_rationale_307": "stone lamp post: plinth, octagonal post with a trim collar, iron crown cage hold" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L307 | neighbors=[Palette, crystal_lantern()] | lang=en
- "voidrealm_void_props_rationale_321": "low balustrade: two square posts with diamond caps, a trim rail and a glow rune" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L321 | neighbors=[Palette, rail_segment()] | lang=en
- "voidrealm_void_props_rationale_335": "void brazier: three iron legs on a stone foot, a bevelled stone bowl, magenta vo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L335 | neighbors=[Palette, brazier()] | lang=pt
- "voidrealm_void_props_rationale_351": "root bulb + 5 curling tendrils (tapering tubes) with glowing bud tips and pods a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L351 | neighbors=[Palette, tendril()] | lang=en
- "voidrealm_void_props_rationale_375": "3-5 bulbous magenta pods on short stems, each split by glowing slits, fronds at" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L375 | neighbors=[Palette, spore_pods()] | lang=en
- "voidrealm_void_props_rationale_397": "ground cover: a low obsidian chip with 3-5 small crystals (painted + neon) pokin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L397 | neighbors=[Palette, crystal_chips()] | lang=en
- "voidrealm_void_props_rationale_409": "tuft of curling void-moss blades (teal) with glowing magenta tips" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L409 | neighbors=[Palette, void_grass()] | lang=en
- "voidrealm_void_props_rationale_420": "shared station base: stepped octagonal void-stone dais with a pale trim lip and" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L420 | neighbors=[Palette, station_dais()] | lang=en
- "voidrealm_void_props_rationale_429": "blank sign board for a GUI label (no text in the mesh): trim frame + dark face +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L429 | neighbors=[Palette, sign_plate()] | lang=en
- "voidrealm_void_props_rationale_437": "Void Merchant: dais, stone counter with trim, back shelf wall of wares, four cry" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L437 | neighbors=[Palette, shop_kiosk()] | lang=en
- "voidrealm_void_props_rationale_46": "per-vertex height gradient (dark low -> light high) + normal lift + noise" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L46 | neighbors=[Palette, V()] | lang=en
- "voidrealm_void_props_rationale_475": "Ascension Altar: round 3-step dais, faceted obelisk with a glowing rune channel," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L475 | neighbors=[Palette, upgrade_altar()] | lang=en
- "voidrealm_void_props_rationale_520": "Seer's Lectern: dais, curved stone screen with a blank board between two crystal" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L520 | neighbors=[Palette, quest_stand()] | lang=en
- "voidrealm_void_props_rationale_552": "spawn platform: big round stepped dais, rune circle inlay, four obelisk markers" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L552 | neighbors=[Palette, spawn_dais()] | lang=en
- "voidrealm_void_props_rationale_572": "arena edge: a ring of low stone wall segments with trim caps and glow rune strip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L572 | neighbors=[Palette, arena_rim()] | lang=en
- "voidrealm_void_props_rationale_591": "HERO 2 - the Rift Gate: octagonal stepped dais, a full ring of 18 void-stone vou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L591 | neighbors=[Palette, rift_gate()] | lang=en
- "voidrealm_void_props_rationale_63": "flat ring sector (r0..r1) from y0 to y1" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L63 | neighbors=[Palette, annulus()] | lang=en
- "voidrealm_void_props_rationale_645": "HERO 1 - the Singularity: a black core (r 22) wrapped by a thin white photon rin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L645 | neighbors=[Palette, singularity()] | lang=en
- "voidrealm_void_props_rationale_691": "rune bridge built along -Z from z=+L/2 (y -dy/2) to z=-L/2 (y +dy/2): bevelled p" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L691 | neighbors=[Palette, rune_bridge()] | lang=en
- "voidrealm_void_props_rationale_729": "floating stepping stone: flat paved top (walkable), faceted obsidian keel with a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L729 | neighbors=[Palette, step_stone()] | lang=en
- "voidrealm_void_props_rationale_742": "gravity lift pad: round 2-tier dais with 8 crystal teeth, a glowing cyan core di" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L742 | neighbors=[Palette, lift_pad()] | lang=en
- "voidrealm_void_props_rationale_759": "gravity lift column (glow only, walk-through): 6 thin streak bars on r 3 + rings" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L759 | neighbors=[Palette, lift_beam()] | lang=en
- "voidrealm_void_props_rationale_85": "a crystal: irregular hex prism from `base` to h*shoulder, then an off-centre fac" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L85 | neighbors=[Palette, shaft()] | lang=en
- "voidrealm_void_props_rationale_99": "angular obsidian chunk: hull of few points = big glassy facets" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L99 | neighbors=[Palette, shard_rock()] | lang=en
- "warehouse_fitlib_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L54 | neighbors=[fitlib.py, fit_bad()] | lang=en
- "warehouse_fitlib_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L19 | neighbors=[fitlib.py, _inside_one()] | lang=en
- "warehouse_fitlib_top": "_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L29 | neighbors=[fitlib.py, fit_bad()] | lang=en
- "warehouse_kitlib_b": "B()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L36 | neighbors=[kitlib.py, .add()] | lang=en
- "warehouse_kitlib_cy": "CY()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L38 | neighbors=[kitlib.py, .add()] | lang=en
- "warehouse_kitlib_drop_bottom": "drop_bottom()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L138 | neighbors=[kitlib.py, delete downward faces lying on y (sits …] | lang=en
- "warehouse_kitlib_glowbox": "glowbox()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L42 | neighbors=[kitlib.py, .gadd()] | lang=en
- "warehouse_kitlib_pol": "pol()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L100 | neighbors=[kitlib.py, V()] | lang=en
- "warehouse_kitlib_quad_top": "quad_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L118 | neighbors=[kitlib.py, quad()] | lang=en
- "warehouse_kitlib_rationale_121": "I / H section of length L along axis ('y' column, 'x' or 'z' beam), centred on t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L121 | neighbors=[Palette, ibeam()] | lang=en
- "warehouse_kitlib_rationale_46": "a reusable sub-assembly emitted into props with a chain of rotations then a tran" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L46 | neighbors=[Palette, Sub] | lang=pt
- "warehouse_kitlib_rationale_59": "revolve [(r, y)] round Y" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L59 | neighbors=[Palette, lathe()] | lang=es

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-150.json

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
