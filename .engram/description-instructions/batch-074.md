# Node Description Batch 75 of 209

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

- "medievalbattle_battle_props_rationale_534": "stone stair climbing along +X from the courtyard to the wall-walk (the wall is a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L534 | neighbors=[wall_stair(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_550": "4-span stone bridge along X (abutments at +-40, ramps to +-54) over a river bed" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L550 | neighbors=[sundered_bridge(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_645": "square gate tower on the central pier (14 x 16, origin = deck level): CUT arched" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L645 | neighbors=[bridge_tower(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_718": "stepped buttress in canonical orientation (wall face at z = 0, buttress out to -" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L718 | neighbors=[buttress(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_72": "revolve [(r, y), ...] (bottom -> top) around Y; r == 0 collapses to a point" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L72 | neighbors=[lathe(), Palette, Sh] | lang=es
- "medievalbattle_battle_props_rationale_739": "charred roof truss across the nave: tie beam, principal rafters, king post, stru" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L739 | neighbors=[truss(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_752": "roofless gothic chapel (door at -Z): real block walls with cut lancets, a gable" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L752 | neighbors=[ruined_chapel(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_829": "timber trestle footbridge along X, deck 1.2 above its ends' ground, bents into t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L829 | neighbors=[footbridge(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_860": "3 tilted headstones on mounds, a makeshift oak cross with a dented helm, a sword" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L860 | neighbors=[gravestones(), Palette, Sh] | lang=pt
- "medievalbattle_battle_props_rationale_884": "SIGNATURE: sharpened log stakes (bark body, fresh-cut tips), leaning out to -Z," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L884 | neighbors=[palisade(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_910": "cheval de frise: a squared log run through with crossed stakes sharpened both en" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L910 | neighbors=[cheval(), Palette, Sh] | lang=nl
- "medievalbattle_battle_props_rationale_928": "trench revetment: stakes with woven withies (in-and-out wicker), a capping log;" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L928 | neighbors=[wattle(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_952": "spoked wheel: hub with iron cap, spokes, felloe ring, iron tyre; axis 'x', 'z' o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L952 | neighbors=[wheel(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rationale_969": "counterweight trebuchet, cocked (throws toward -Z): skid frame on wheels, braced" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L969 | neighbors=[trebuchet(), Palette, Sh] | lang=en
- "medievalbattle_battle_props_rough_stone": "rough_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1388 | neighbors=[battle_props.py, drystone_wall(), a field stone: a box with jittered corn…] | lang=en
- "medievalbattle_battle_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L40 | neighbors=[battle_props.py, course_wall(), ruined_chapel()] | lang=en
- "medievalbattle_battle_props_wattle": "wattle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L927 | neighbors=[battle_props.py, trench revetment: stakes with woven wit…, log()] | lang=en
- "mesh_buffer": "Buffer.h" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/Buffer.h:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "mesh_inputlayout": "InputLayout.h" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/InputLayout.h:L1 | neighbors=[f4a6ac4 Allowlist known validation-laye…, 52dbcb9 Surface graphics warnings in X1…, c7a411f Fix MUT-01-20 audit defects in …] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-074.json

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
