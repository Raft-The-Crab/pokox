# Node Description Batch 205 of 207

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

- "vm_register_vm_run_register_vm": "run_register_vm()" | kind=code-symbol | source=mute/src/vm/register_vm.cpp:L4 | neighbors=[register_vm.cpp] | lang=en
- "vm_scheduler_spawn": "spawn()" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L8 | neighbors=[scheduler.cpp] | lang=en
- "vm_scheduler_state": "state()" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L28 | neighbors=[scheduler.cpp] | lang=en
- "vm_values_make_bool": "make_bool()" | kind=code-symbol | source=mute/src/vm/values.cpp:L6 | neighbors=[values.cpp] | lang=en
- "vm_vm_core_depthguard": "DepthGuard()" | kind=code-symbol | source=mute/src/vm/vm_core.hpp:L67 | neighbors=[vm_core.hpp] | lang=en
- "vm_vm_core_result": "result()" | kind=code-symbol | source=mute/src/vm/vm_core.cpp:L42 | neighbors=[vm_core.hpp] | lang=en
- "voidrealm_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/hooks_lua.py:L4 | neighbors=[hooks_lua.py] | lang=en
- "voidrealm_void_map_rationale_131": "underside depth (fraction of R) at ring t (0 = rim, 1 = tip)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L131 | neighbors=[keel_profile()] | lang=en
- "voidrealm_void_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L514 | neighbors=[void_map.py] | lang=en
- "voidrealm_void_paint_block": "block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_paint.py:L13 | neighbors=[void_paint.py] | lang=en
- "voidrealm_void_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L43 | neighbors=[void_props.py] | lang=en
- "warehouse_fitlib_add_owner": "add_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L11 | neighbors=[fitlib.py] | lang=en
- "warehouse_kitlib_rationale_109": "one single-sided quad: axis 'y' = facing +y at height off (w along x, h along z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L109 | neighbors=[quad()] | lang=es
- "warehouse_kitlib_rationale_132": "per-face colour from fn(centre, normal) -> (ramp, value)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L132 | neighbors=[SF()] | lang=en
- "warehouse_kitlib_rationale_139": "delete downward faces lying on y (sits on the floor / another surface)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L139 | neighbors=[drop_bottom()] | lang=en
- "warehouse_kitlib_rbox": "rbox()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L105 | neighbors=[kitlib.py] | lang=en
- "warehouse_kitlib_sub_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L47 | neighbors=[Sub] | lang=en
- "warehouse_tricount_n": "n()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/tricount.py:L4 | neighbors=[tricount.py] | lang=en
- "warehouse_wh_equip_bollard": "bollard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L266 | neighbors=[wh_equip.py] | lang=en
- "warehouse_wh_equip_rationale_115": "1000 l IBC: steel pallet base, white HDPE tank, galvanised tube cage, filler cap" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L115 | neighbors=[ibc_tote()] | lang=en
- "warehouse_wh_equip_rationale_136": "steel weld-mesh stillage cage with corner posts / feet; optionally full of carto" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L136 | neighbors=[mesh_stillage()] | lang=en
- "warehouse_wh_equip_rationale_165": "gravity roller conveyor: side channels, rollers, legs with cross braces + feet," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L165 | neighbors=[conveyor()] | lang=en
- "warehouse_wh_equip_rationale_17": "steel mezzanine: SHS columns, main beams + C joists, chipboard deck, fascia, han" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L17 | neighbors=[mezzanine()] | lang=en
- "warehouse_wh_equip_rationale_185": "steel packing bench: worktop, undershelf with cartons, upright frame with a ligh" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L185 | neighbors=[packing_bench()] | lang=en
- "warehouse_wh_equip_rationale_209": "turntable pallet wrapper: low base + rotating disc, mast with film carriage, con" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L209 | neighbors=[stretch_wrapper()] | lang=en
- "warehouse_wh_equip_rationale_225": "wall-mounted forklift battery charger with a cable + plug hanging on a hook (wal" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L225 | neighbors=[charger_unit()] | lang=pt
- "warehouse_wh_equip_rationale_236": "fire point (wall prop): hose-reel cabinet, two extinguishers on brackets, a blan" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L236 | neighbors=[fire_point()] | lang=pt
- "warehouse_wh_equip_rationale_251": "yellow polymer-style traffic barrier: posts with black-band caps, two rails (ped" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L251 | neighbors=[safety_barrier()] | lang=en
- "warehouse_wh_equip_rationale_7": "handrail along a straight line a->b on a deck: posts, top rail, knee rail, kick" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L7 | neighbors=[rail_run()] | lang=pt
- "warehouse_wh_equip_rationale_77": "modular mezzanine office: framed white panels, a ribbon of glazing with half-dra" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_equip.py:L77 | neighbors=[site_office()] | lang=en
- "warehouse_wh_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L330 | neighbors=[wh_map.py] | lang=en
- "warehouse_wh_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L345 | neighbors=[wh_map.py] | lang=en
- "warehouse_wh_props_rationale_105": "blue plastic stacking crates with hand-hole recesses" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L105 | neighbors=[load_crates()] | lang=en
- "warehouse_wh_props_rationale_12": "EUR-style pallet: top deck boards, 3 block rows, stringers, bottom boards. lite" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L12 | neighbors=[pallet_sub()] | lang=en
- "warehouse_wh_props_rationale_127": "a stack of empty pallets, slightly misaligned" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L127 | neighbors=[pallet_stack()] | lang=en
- "warehouse_wh_props_rationale_136": "one rack frame: two perforated posts (z0 aisle side, z1 flue side), base plates," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L136 | neighbors=[upright_frame()] | lang=en
- "warehouse_wh_props_rationale_152": "two step beams at level y between uprights x0..x1: front (zf, aisle side) + back" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L152 | neighbors=[beam_pair()] | lang=es
- "warehouse_wh_props_rationale_166": "one 9-stud bay of selective pallet racking, local front (aisle) = -z. double = b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L166 | neighbors=[rack_bay()] | lang=en
- "warehouse_wh_props_rationale_190": "the last upright frames of a row + yellow end-of-aisle frame protectors (frame=F" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L190 | neighbors=[rack_end()] | lang=en
- "warehouse_wh_props_rationale_32": "one cardboard carton: box with a tape strip over the top and a blank paper label" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L32 | neighbors=[carton()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-204.json

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
