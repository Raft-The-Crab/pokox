# Node Description Batch 74 of 208

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

- "moonclean_moon_props_ice_crystal": "ice_crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L516 | neighbors=[moon_props.py, rock(), ice cluster: 5-7 hex spikes leaning out…] | lang=en
- "moonclean_moon_props_jump_pad": "jump_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L474 | neighbors=[moon_props.py, torus(), low-gravity launcher: vented steel skir…] | lang=en
- "moonclean_moon_props_meteor_chunk": "meteor_chunk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L723 | neighbors=[moon_props.py, rock(), small glowing meteor fragment to collec…] | lang=en
- "moonclean_moon_props_meteorite": "meteorite()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L501 | neighbors=[moon_props.py, rock(), split meteorite: two dark halves around…] | lang=en
- "moonclean_moon_props_moon_rock": "moon_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L488 | neighbors=[moon_props.py, rock(), faceted boulder sunk into a regolith sk…] | lang=en
- "moonclean_moon_props_rationale_102": "round port window: steel frame ring + rivets + glowing pane set back; faces -Z b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L102 | neighbors=[port(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_107": "signature: white octagonal post, steel collar, amber glow cap" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L107 | neighbors=[beacon_post(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_115": "post at x=0 + a sagging cable to the next post (x = L, not included): chain thes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L115 | neighbors=[beacon_rail(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_125": "hex landing pad on 4 splayed lander legs; chevron rim; corner beacons. Adds into" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L125 | neighbors=[station_base(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_154": "SELL: a gold-foil intake hopper on the base, ribbed vacuum hose to a nozzle, glo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L154 | neighbors=[dust_exchange(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_199": "vacuum backpack: twin tanks, frame, dust window, hose loop + nozzle (hangs on a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L199 | neighbors=[vac_pack(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_211": "SHOP: curved white locker wall with 3 vacuum packs on hooks, central holo pedest" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L211 | neighbors=[gear_locker(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_244": "REBIRTH: scorched capsule on its heat shield, port windows, RCS quads, glowing o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L244 | neighbors=[reentry_pod(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_270": "PETS: console with a screen, 3 cryo cages (ring + ribs) holding alien eggs with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L270 | neighbors=[egg_incubator(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_299": "gold-foil descent stage on 4 legs with dish feet, faceted ascent cabin, triangul" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L299 | neighbors=[lunar_lander(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_355": "three-stage rocket on a launch mount: roll-pattern checker, orange bands, foil i" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L355 | neighbors=[moon_rocket(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_414": "umbilical tower beside the rocket (rocket axis at x = -14): 4-leg truss, X braci" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L414 | neighbors=[launch_tower(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_447": "priced zone gate at the head of each crater ramp: two hex pylons with chevron st" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L447 | neighbors=[airlock_gate(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_475": "low-gravity launcher: vented steel skirt, white deck, 3 glow rings + up-chevron" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L475 | neighbors=[jump_pad(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_489": "faceted boulder sunk into a regolith skirt, with a small chipped pit; 2 satellit" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L489 | neighbors=[moon_rock(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_49": "revolve [(r, y), ...] (bottom -> top) around Y; r == 0 collapses to a point" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L49 | neighbors=[lathe(), Palette, Sh] | lang=es
- "moonclean_moon_props_rationale_502": "split meteorite: two dark halves around a glowing molten core, in a raised impac" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L502 | neighbors=[meteorite(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_517": "ice cluster: 5-7 hex spikes leaning out from a frost-crusted rock, glowing cores" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L517 | neighbors=[ice_crystal(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_540": "abandoned lunar rover: tube chassis, 4 wire wheels with fenders, 2 seats, consol" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L540 | neighbors=[moon_rover(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_563": "crashed satellite half-buried: foil bus, one bent solar wing (cells + frame), ti" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L563 | neighbors=[satellite_wreck(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_580": "3 horizontal tanks on cradles (2 bottom, 1 on top), orange end caps, pipe manifo" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L580 | neighbors=[fuel_tanks(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_593": "hub floodlight mast: tripod foot, tapered pole, ring catwalk, 4-lamp head, red t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L593 | neighbors=[floodlight(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_611": "hub antenna: big dish on a yoke, turret drum, foil base, feed horn on 3 struts" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L611 | neighbors=[comms_dish(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_631": "stack of 3 white supply crates with orange corner caps and foil straps + a cylin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L631 | neighbors=[supply_crates(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_644": "modelled impact crater for R = 1 (place with s = R): smooth 36-sided lathe, rais" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L644 | neighbors=[crater(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_672": "sweepable dust drift: low lumpy pancake, lighter than the ground, rippled rings" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L672 | neighbors=[dust_patch(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_706": "space junk to haul: bent hull panel, snapped pipe, gear, bolts, broken box - bui" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L706 | neighbors=[junk_heap(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_724": "small glowing meteor fragment to collect: dark shell with molten seams, scorch d" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L724 | neighbors=[meteor_chunk(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_733": "collectable ice: 3 short glowing shards on a frost puddle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L733 | neighbors=[ice_shards(), Palette, Sh] | lang=pt
- "moonclean_moon_props_rationale_743": "Earth for the sky: faceted sphere, oceans / continents / cloud + polar caps by n" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L743 | neighbors=[earth(), Palette, Sh] | lang=en
- "moonclean_moon_props_rationale_80": "parabolic dish opening up (+Y), thickness t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L80 | neighbors=[dish(), Palette, Sh] | lang=es
- "moonclean_moon_props_rivets": "rivets()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L96 | neighbors=[moon_props.py, dust_exchange(), moon_rocket()] | lang=en
- "moonclean_moon_props_supply_crates": "supply_crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L630 | neighbors=[moon_props.py, stack of 3 white supply crates with ora…, torus()] | lang=en
- "musl_math_floor": "floor.cpp" | kind=code-symbol | source=mute/third_party/musl_math/floor.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, floor_value(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "musl_math_rem_pio2": "__rem_pio2.cpp" | kind=code-symbol | source=mute/third_party/musl_math/__rem_pio2.cpp:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, rem_pio2(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en

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
