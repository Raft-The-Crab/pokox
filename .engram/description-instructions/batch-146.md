# Node Description Batch 147 of 207

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

- "vfxkit_video_prompt_text": "_prompt_text()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L103 | neighbors=[video.py, flipbook()] | lang=en
- "vfxkit_video_ramp": "_ramp()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L268 | neighbors=[video.py, grade()] | lang=en
- "vfxkit_video_smoothstep": "_smoothstep()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L109 | neighbors=[video.py, grade()] | lang=en
- "vfxkit_workflow_absolute": "absolute()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L47 | neighbors=[workflow.py, unchanged()] | lang=en
- "vfxkit_workflow_relative": "relative()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L36 | neighbors=[workflow.py, snapshot()] | lang=en
- "vm_debugger_has_breakpoint": "has_breakpoint()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L29 | neighbors=[debugger.cpp, run()] | lang=en
- "vm_debugger_result": "result()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L58 | neighbors=[debugger.cpp, finish()] | lang=en
- "vm_debugger_stack": "stack()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L59 | neighbors=[debugger.cpp, pc()] | lang=en
- "vm_hostcall_host_type": "host_type()" | kind=code-symbol | source=mute/src/vm/hostcall.cpp:L5 | neighbors=[hostcall.cpp, add()] | lang=en
- "vm_hostcall_unauthorized_hostcalls": "unauthorized_hostcalls()" | kind=code-symbol | source=mute/src/vm/hostcall.cpp:L33 | neighbors=[hostcall.cpp, find()] | lang=en
- "vm_scheduler_cancel": "cancel()" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L15 | neighbors=[scheduler.cpp, find()] | lang=en
- "vm_scheduler_run": "run()" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L32 | neighbors=[scheduler.cpp, find()] | lang=en
- "vm_values_as_string": "as_string()" | kind=code-symbol | source=mute/src/vm/values.cpp:L128 | neighbors=[values.cpp, object()] | lang=en
- "vm_values_copy": "copy()" | kind=code-symbol | source=mute/src/vm/values.cpp:L139 | neighbors=[values.cpp, copy_impl()] | lang=en
- "vm_values_get_index": "get_index()" | kind=code-symbol | source=mute/src/vm/values.cpp:L81 | neighbors=[values.cpp, object()] | lang=en
- "vm_values_length": "length()" | kind=code-symbol | source=mute/src/vm/values.cpp:L133 | neighbors=[values.cpp, object()] | lang=en
- "vm_values_make_int": "make_int()" | kind=code-symbol | source=mute/src/vm/values.cpp:L5 | neighbors=[values.cpp, set_index()] | lang=en
- "vm_vm_core_step": "step()" | kind=code-symbol | source=mute/src/vm/vm_core.cpp:L47 | neighbors=[vm_core.hpp, fail()] | lang=en
- "vm_vm_core_vmcore": "VmCore" | kind=code-symbol | source=mute/src/vm/vm_core.hpp:L13 | neighbors=[vm_core.hpp, fail()] | lang=en
- "voidrealm_grid": "grid.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/grid.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "voidrealm_post": "post.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/post.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "voidrealm_void_map_ang": "ang()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L43 | neighbors=[void_map.py, stations()] | lang=en
- "voidrealm_void_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L70 | neighbors=[void_map.py, place()] | lang=en
- "voidrealm_void_map_inner": "inner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L220 | neighbors=[void_map.py, bridges()] | lang=en
- "voidrealm_void_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L451 | neighbors=[void_map.py, free()] | lang=en
- "voidrealm_void_map_lowz": "LOWZ()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L97 | neighbors=[void_map.py, place()] | lang=en
- "voidrealm_void_map_rationale_100": "share of a placed kit prop's body (above its lowest 15%) inside the solid in bvh" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L100 | neighbors=[MB, clip_frac()] | lang=en
- "voidrealm_void_map_rationale_115": "copy a prop part (Roblox-space MB) to its world placement, for walkable pieces k" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L115 | neighbors=[MB, placed_mb()] | lang=en
- "voidrealm_void_map_rationale_428": "intentional floaters: chips drifting near the shards and between them, far silho" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L428 | neighbors=[MB, void_debris()] | lang=en
- "voidrealm_void_map_rationale_79": "ground on the LOWEST footprint point (all footprint samples must be on the islan" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L79 | neighbors=[MB, place()] | lang=en
- "voidrealm_void_map_rim_chunk": "rim_chunk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L414 | neighbors=[void_map.py, dressing()] | lang=en
- "voidrealm_void_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L423 | neighbors=[void_map.py, void_debris()] | lang=en
- "voidrealm_void_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L42 | neighbors=[void_props.py, upgrade_altar()] | lang=en
- "voidrealm_void_props_rationale_109": "obsidian seat + big painted crystals leaning out + small painted + neon crystals" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L109 | neighbors=[Palette, crystal_cluster()] | lang=en
- "voidrealm_void_props_rationale_151": "the big crystal on the Starwatch shard: one huge cyan/violet column cluster on a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L151 | neighbors=[Palette, heart_crystal()] | lang=en
- "voidrealm_void_props_rationale_162": "broken-off island chip: a crust slab with a chipped lip, a two-tier faceted obsi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L162 | neighbors=[Palette, float_shard()] | lang=pt
- "voidrealm_void_props_rationale_187": "distant silhouette: a broken island chunk (wide flat top, keel tapering to one o" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L187 | neighbors=[Palette, far_rock()] | lang=pt
- "voidrealm_void_props_rationale_199": "abstract rune inlay (never a letter): diamond / chevron / ring-dot, flat in XY f" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L199 | neighbors=[Palette, rune_glyph()] | lang=en
- "voidrealm_void_props_rationale_210": "fluted void-stone column: stepped plinth, entasis shaft with 12 flutes, rune ban" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L210 | neighbors=[Palette, pillar()] | lang=en
- "voidrealm_void_props_rationale_246": "ruined gateway arch: two square piers with trim bands + rune inlays, a voussoir" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L246 | neighbors=[Palette, void_arch()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-146.json

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
