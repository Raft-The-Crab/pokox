# Node Description Batch 187 of 207

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

- "src_vfx_heal_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Heal.py:L9 | neighbors=[VFX_Heal.py] | lang=en
- "src_vfx_hit_heavy_rationale_1": "VFX_Hit_Heavy: Heavy melee hit: the blow lands on the target in place.  Example" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Hit_Heavy.py:L1 | neighbors=[VFX_Hit_Heavy.py] | lang=en
- "src_vfx_hit_heavy_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Hit_Heavy.py:L9 | neighbors=[VFX_Hit_Heavy.py] | lang=en
- "src_vfx_ice_spikes_rationale_1": "VFX_Ice_Spikes: Ground ice eruption played where VFX_Projectile_Ice arrives.  Ex" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Ice_Spikes.py:L1 | neighbors=[VFX_Ice_Spikes.py] | lang=en
- "src_vfx_ice_spikes_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Ice_Spikes.py:L9 | neighbors=[VFX_Ice_Spikes.py] | lang=en
- "src_vfx_kaiju_atomic_beam_rationale_1": "VFX_Kaiju_Atomic_Beam: a sustained atomic breath that the game aims and sweeps (" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Beam.py:L1 | neighbors=[VFX_Kaiju_Atomic_Beam.py] | lang=en
- "src_vfx_kaiju_atomic_beam_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Beam.py:L9 | neighbors=[VFX_Kaiju_Atomic_Beam.py] | lang=en
- "src_vfx_kaiju_atomic_charge_rationale_1": "VFX_Kaiju_Atomic_Charge: dorsal plates light up from the tail to the head before" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Charge.py:L1 | neighbors=[VFX_Kaiju_Atomic_Charge.py] | lang=en
- "src_vfx_kaiju_atomic_charge_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Charge.py:L15 | neighbors=[VFX_Kaiju_Atomic_Charge.py] | lang=en
- "src_vfx_kaiju_explosion_rationale_1": "VFX_Kaiju_Explosion: a photographic, building-sized fuel explosion for a kaiju b" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Explosion.py:L1 | neighbors=[VFX_Kaiju_Explosion.py] | lang=pt
- "src_vfx_kaiju_explosion_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Explosion.py:L19 | neighbors=[VFX_Kaiju_Explosion.py] | lang=en
- "src_vfx_magic_charge_rationale_1": "VFX_Magic_Charge: Arcane charge on the caster: a long inward build, then one rel" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Magic_Charge.py:L1 | neighbors=[VFX_Magic_Charge.py] | lang=en
- "src_vfx_magic_charge_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Magic_Charge.py:L9 | neighbors=[VFX_Magic_Charge.py] | lang=en
- "src_vfx_poison_cloud_rationale_1": "VFX_Poison_Cloud: Poison splash and lingering cloud played where VFX_Projectile_" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Poison_Cloud.py:L1 | neighbors=[VFX_Poison_Cloud.py] | lang=en
- "src_vfx_poison_cloud_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Poison_Cloud.py:L9 | neighbors=[VFX_Poison_Cloud.py] | lang=en
- "src_vfx_projectile_dark_rationale_1": "VFX_Projectile_Dark: Shadow orb projectile; paired with VFX_Dark_Vortex on arriv" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Dark.py:L1 | neighbors=[VFX_Projectile_Dark.py] | lang=en
- "src_vfx_projectile_dark_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Dark.py:L9 | neighbors=[VFX_Projectile_Dark.py] | lang=en
- "src_vfx_projectile_fire_rationale_1": "VFX_Projectile_Fire: Fireball projectile; paired with VFX_Fire_Explosion on arri" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Fire.py:L1 | neighbors=[VFX_Projectile_Fire.py] | lang=en
- "src_vfx_projectile_fire_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Fire.py:L9 | neighbors=[VFX_Projectile_Fire.py] | lang=en
- "src_vfx_projectile_ice_rationale_1": "VFX_Projectile_Ice: Ice lance projectile; paired with VFX_Ice_Spikes on arrival." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Ice.py:L1 | neighbors=[VFX_Projectile_Ice.py] | lang=en
- "src_vfx_projectile_ice_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Ice.py:L9 | neighbors=[VFX_Projectile_Ice.py] | lang=en
- "src_vfx_projectile_poison_rationale_1": "VFX_Projectile_Poison: Lobbed venom glob; paired with VFX_Poison_Cloud on arriva" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Poison.py:L1 | neighbors=[VFX_Projectile_Poison.py] | lang=en
- "src_vfx_projectile_poison_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Projectile_Poison.py:L9 | neighbors=[VFX_Projectile_Poison.py] | lang=en
- "src_vfx_shield_dome_rationale_1": "VFX_Shield_Dome: Shield dome on the caster: raise, hold, then break into fragmen" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Shield_Dome.py:L1 | neighbors=[VFX_Shield_Dome.py] | lang=en
- "src_vfx_shield_dome_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Shield_Dome.py:L9 | neighbors=[VFX_Shield_Dome.py] | lang=en
- "src_vfx_slash_fire_rationale_1": "VFX_Slash_Fire: Fire sword slash played on the target (melee).  Example from the" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Slash_Fire.py:L1 | neighbors=[VFX_Slash_Fire.py] | lang=en
- "src_vfx_slash_fire_recipe": "recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Slash_Fire.py:L9 | neighbors=[VFX_Slash_Fire.py] | lang=en
- "src_visual_solver_remove_body": "remove_body()" | kind=code-symbol | source=engine/physics/src/visual_solver.cpp:L142 | neighbors=[visual_solver.cpp] | lang=en
- "state_state_round": "round()" | kind=code-symbol | source=mute/src/state/state.cpp:L14 | neighbors=[state.cpp] | lang=en
- "stdlib_events_clear_phase": "clear_phase()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L33 | neighbors=[events.cpp] | lang=en
- "stdlib_events_dispatch": "dispatch()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L51 | neighbors=[events.cpp] | lang=en
- "stdlib_events_emit": "emit()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L42 | neighbors=[events.cpp] | lang=en
- "stdlib_events_name": "name()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L99 | neighbors=[events.cpp] | lang=en
- "stdlib_events_subscribe": "subscribe()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L17 | neighbors=[events.cpp] | lang=en
- "stdlib_events_subscriptions": "subscriptions()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L71 | neighbors=[events.cpp] | lang=en
- "stdlib_events_unsubscribe": "unsubscribe()" | kind=code-symbol | source=mute/src/stdlib/events.cpp:L25 | neighbors=[events.cpp] | lang=en
- "stdlib_stdlib_collections_contains": "contains()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L61 | neighbors=[stdlib_collections.cpp] | lang=en
- "stdlib_stdlib_collections_dump": "dump()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L77 | neighbors=[stdlib_collections.cpp] | lang=en
- "stdlib_stdlib_collections_get": "get()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L21 | neighbors=[stdlib_collections.cpp] | lang=en
- "stdlib_stdlib_collections_insert": "insert()" | kind=code-symbol | source=mute/src/stdlib/stdlib_collections.cpp:L49 | neighbors=[stdlib_collections.cpp] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-186.json

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
