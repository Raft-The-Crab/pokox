# Node Description Batch 72 of 207

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

- "medievalbattle_battle_props_rationale_884": "SIGNATURE: sharpened log stakes (bark body, fresh-cut tips), leaning out to -Z," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L884 | neighbors=[palisade(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_910": "cheval de frise: a squared log run through with crossed stakes sharpened both en" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L910 | neighbors=[cheval(), Palette, Sh] | lang=nl
- "medievalbattle_battle_props_rationale_928": "trench revetment: stakes with woven withies (in-and-out wicker), a capping log;" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L928 | neighbors=[wattle(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_952": "spoked wheel: hub with iron cap, spokes, felloe ring, iron tyre; axis 'x', 'z' o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L952 | neighbors=[wheel(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_969": "counterweight trebuchet, cocked (throws toward -Z): skid frame on wheels, braced" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L969 | neighbors=[trebuchet(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rough_stone": "rough_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1388 | neighbors=[battle_props.py, drystone_wall(), a field stone: a box with jittered corn…] | lang=en
- "medievalbattle_battle_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L40 | neighbors=[battle_props.py, course_wall(), ruined_chapel()] | lang=en
- "medievalbattle_battle_props_wattle": "wattle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L927 | neighbors=[battle_props.py, trench revetment: stakes with woven wit…, log()] | lang=en
- "migrations_0001_accounts_games_games": "games" | kind=code-symbol | source=backend/storage/postgres/migrations/0001_accounts_games.sql:L14 | neighbors=[0001_accounts_games.sql, assets, users] | lang=en
- "migrations_0003_cases_audit": "0003_cases_audit.sql" | kind=code-symbol | source=backend/storage/postgres/migrations/0003_cases_audit.sql:L1 | neighbors=[1dac49d Created NET-01 to NET-09, Start…, audit_log, cases] | lang=en
- "moonclean_moon_map_crater_at": "crater_at()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L202 | neighbors=[moon_map.py, pock_at(), H()] | lang=en
- "moonclean_moon_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L144 | neighbors=[moon_map.py, place(), top_of()] | lang=en
- "moonclean_moon_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L182 | neighbors=[moon_map.py, scatter(), zone()] | lang=en
- "moonclean_moon_map_ground_shade": "ground_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L223 | neighbors=[moon_map.py, ramp_w(), zone_of()] | lang=en
- "moonclean_moon_map_hub_deck": "hub_deck()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L294 | neighbors=[moon_map.py, build(), sub()] | lang=en
- "moonclean_moon_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L139 | neighbors=[moon_map.py, place(), top_of()] | lang=en
- "moonclean_moon_map_profile": "profile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L74 | neighbors=[moon_map.py, H(), crater height before ramps / sub-craters] | lang=en
- "moonclean_moon_map_sky": "sky()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L482 | neighbors=[moon_map.py, build(), place()] | lang=en
- "moonclean_moon_props_beacon_rail": "beacon_rail()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L114 | neighbors=[moon_props.py, beacon_post(), post at x=0 + a sagging cable to the ne…] | lang=en
- "moonclean_moon_props_dust_patch": "dust_patch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L671 | neighbors=[moon_props.py, rock(), sweepable dust drift: low lumpy pancake…] | lang=en
- "moonclean_moon_props_egg": "egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L75 | neighbors=[moon_props.py, lathe(), egg_incubator()] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-071.json

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
