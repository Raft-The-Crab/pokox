# Node Description Batch 120 of 209

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

- "medievalbattle_battle_map_rationale_262": "4-stud water grid kept only where water shows: a cell needs a corner below the s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L262 | neighbors=[water(), MB] | lang=pt
- "medievalbattle_battle_map_rationale_39": "[(centre x, half width, bed y)] of the river at z" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L39 | neighbors=[channels(), MB] | lang=en
- "medievalbattle_battle_map_tree_pick": "tree_pick()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L419 | neighbors=[battle_map.py, scatter()] | lang=en
- "medievalbattle_battle_map_wet": "wet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L160 | neighbors=[battle_map.py, H()] | lang=en
- "medievalbattle_battle_props_boulder": "boulder()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1436 | neighbors=[battle_props.py, T()] | lang=en
- "medievalbattle_battle_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1549 | neighbors=[battle_props.py, T()] | lang=en
- "medievalbattle_battle_props_duckboard": "duckboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L943 | neighbors=[battle_props.py, T()] | lang=en
- "medievalbattle_battle_props_grass_tuft": "grass_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L1556 | neighbors=[battle_props.py, T()] | lang=en
- "medievalbattle_battle_props_round_tower": "round_tower()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L341 | neighbors=[battle_props.py, tower_body()] | lang=en
- "medievalbattle_closeup": "closeup.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/closeup.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "mesh_refcntautoptr_refcntautoptr": "RefCntAutoPtr" | kind=code-symbol | source=engine/rhi/tests/fakes/mesh/RefCntAutoPtr.hpp:L5 | neighbors=[RefCntAutoPtr.hpp, .RefCntAutoPtr()] | lang=en
- "migrations_0001_accounts_games_assets": "assets" | kind=code-symbol | source=backend/storage/postgres/migrations/0001_accounts_games.sql:L22 | neighbors=[0001_accounts_games.sql, games] | lang=en
- "migrations_0001_accounts_games_users": "users" | kind=code-symbol | source=backend/storage/postgres/migrations/0001_accounts_games.sql:L5 | neighbors=[0001_accounts_games.sql, games] | lang=en
- "migrations_0002_ledger_balances_games": "games" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L29 | neighbors=[0002_ledger_balances.sql, share_entries] | lang=en
- "migrations_0002_ledger_balances_share_entries": "share_entries" | kind=code-symbol | source=backend/storage/postgres/migrations/0002_ledger_balances.sql:L26 | neighbors=[0002_ledger_balances.sql, games] | lang=en
- "moonclean_moon_map_near_riser": "near_riser()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L191 | neighbors=[moon_map.py, scatter()] | lang=en
- "moonclean_moon_map_radial_samples": "radial_samples()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L194 | neighbors=[moon_map.py, ground()] | lang=en
- "moonclean_moon_map_rationale_154": "height of the built ground MESH (coarser than H): props sit on what players see" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L154 | neighbors=[Hm(), MB] | lang=en
- "moonclean_moon_map_rationale_166": "highest mesh point under a prop's footprint: low flat props sit on it so no bump" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L166 | neighbors=[top_of(), MB] | lang=en
- "moonclean_moon_map_rationale_211": "(q, depth) of the nearest pock / crater under (x, z), q = dist / radius; None ou" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L211 | neighbors=[pock_at(), MB] | lang=en
- "moonclean_moon_map_rationale_315": "the signature beacon rail along a lip: posts every `step`, cable to the next; ga" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L315 | neighbors=[rail_ring(), MB] | lang=en
- "moonclean_moon_map_rationale_336": "modelled crater props on every pock / crater (the ground only carries a shallow" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L336 | neighbors=[craters(), MB] | lang=en
- "moonclean_moon_map_rationale_367": "airlock gate at the head of ramp k (k = 0 is the free zone-1 entry), rails down" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L367 | neighbors=[crater_ramp(), MB] | lang=en
- "moonclean_moon_map_rationale_400": "mess=True (low dust / junk / meteor pieces): only on calm ground, sat on the mes" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L400 | neighbors=[scatter(), MB] | lang=en
- "moonclean_moon_map_rationale_75": "crater height before ramps / sub-craters" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L75 | neighbors=[profile(), MB] | lang=en
- "moonclean_moon_map_rationale_89": "the crater prop's skirt (1.8 R) must stay on its shelf, off the trodden path and" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L89 | neighbors=[_crater_ok(), MB] | lang=en
- "moonclean_moon_map_rationale_97": "weight 0..1 of ramp k at (r, a) and the ramp height there" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L97 | neighbors=[ramp_w(), MB] | lang=en
- "moonclean_moon_props_dust_pile": "dust_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L694 | neighbors=[moon_props.py, sweepable heap: stacked mounds + a spar…] | lang=en
- "moonclean_moon_props_earth": "earth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L742 | neighbors=[moon_props.py, Earth for the sky: faceted sphere, ocea…] | lang=en
- "moonclean_moon_props_ice_shards": "ice_shards()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L732 | neighbors=[moon_props.py, collectable ice: 3 short glowing shards…] | lang=en
- "moonclean_moon_props_junk_heap": "junk_heap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L705 | neighbors=[moon_props.py, space junk to haul: bent hull panel, sn…] | lang=en
- "mute_action_map_actionsampler": "ActionSampler" | kind=code-symbol | source=mute/include/poko/mute/action_map.hpp:L144 | neighbors=[action_map.hpp, .ActionSampler()] | lang=en
- "mute_console_consolelog": "ConsoleLog" | kind=code-symbol | source=mute/include/poko/mute/console.hpp:L33 | neighbors=[console.hpp, .ConsoleLog()] | lang=en
- "mute_debugger_vmdebugger": "VmDebugger" | kind=code-symbol | source=mute/include/poko/mute/debugger.hpp:L36 | neighbors=[debugger.hpp, .VmDebugger()] | lang=en
- "mute_declaration_declarationast": "DeclarationAst" | kind=code-symbol | source=mute/include/poko/mute/declaration.hpp:L44 | neighbors=[declaration.hpp, .DeclarationAst()] | lang=en
- "mute_determinism": "determinism.hpp" | kind=code-symbol | source=mute/include/poko/mute/determinism.hpp:L1 | neighbors=[037434c Add MUT-24 determinism and capa…, 952997e Audit MUT-01-55 and harden veri…] | lang=en
- "mute_emit": "emit.hpp" | kind=code-symbol | source=mute/include/poko/mute/emit.hpp:L1 | neighbors=[335e0dc Add MUT-26 IR-to-bytecode emitt…, 952997e Audit MUT-01-55 and harden veri…] | lang=en
- "mute_events": "events.hpp" | kind=code-symbol | source=mute/include/poko/mute/events.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, EventBus] | lang=en
- "mute_input_snapshot_gamepad_control": "gamepad_control()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L59 | neighbors=[input_snapshot.hpp, touch_id()] | lang=en
- "mute_input_snapshot_gamepad_slot": "gamepad_slot()" | kind=code-symbol | source=mute/include/poko/mute/input_snapshot.hpp:L56 | neighbors=[input_snapshot.hpp, touch_display()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-119.json

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
