# Node Description Batch 205 of 208

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

- "vfxkit_textures_rationale_172": "Measure a texture so recipes can use numbers instead of eyeballed magic constant" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L172 | neighbors=[inspect()] | lang=en
- "vfxkit_textures_rationale_24": "Tileable cellular noise: 0 at feature points, 1 on cell borders." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L24 | neighbors=[worley()] | lang=en
- "vfxkit_textures_rationale_78": "Bilinear lookup with wrap-around, so warped fields stay tileable." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L78 | neighbors=[_sample()] | lang=en
- "vfxkit_textures_rationale_84": "Tileable vortex noise: streaky noise wound round a few periodic whirl centres (t" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L84 | neighbors=[swirl()] | lang=pt
- "vfxkit_unity_rationale_1": "Unity pipeline: the same flipbooks, played by a small URP runtime instead of Eff" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L1 | neighbors=[unity.py] | lang=en
- "vfxkit_unity_rationale_100": "Write every texture the package's shared materials and mesh shells sample. Deter" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L100 | neighbors=[textures()] | lang=en
- "vfxkit_unity_rationale_181": "Copy the package into Packages/ (Unity picks embedded packages up without editin" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L181 | neighbors=[install()] | lang=en
- "vfxkit_unity_rationale_209": "Copy one processed sheet into the Unity project with its grid sidecar." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L209 | neighbors=[export()] | lang=en
- "vfxkit_unity_rationale_239": "How far the drawn shape stays above each cell's bottom edge (fraction of the cel" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L239 | neighbors=[bottom_inset()] | lang=en
- "vfxkit_unity_rationale_44": "Greyscale distance mask in alpha (imported as linear data)." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L44 | neighbors=[_mask()] | lang=en
- "vfxkit_unity_rationale_49": "Binary shape -> interior gradient (an approximate distance field). A higher powe" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L49 | neighbors=[_inner_gradient()] | lang=en
- "vfxkit_unity_rationale_63": "Tileable value noise in 0-1: random lattices sampled with wrap-around, smoothly" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L63 | neighbors=[_tile_noise()] | lang=en
- "vfxkit_unity_rationale_84": "A soft-edged irregular puff: radius wobbles with angle, edge noise breaks the ou" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L84 | neighbors=[_blob()] | lang=en
- "vfxkit_video_rationale_1": "Video-model flipbooks: a generated clip on black becomes a straight-alpha sheet" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L1 | neighbors=[video.py] | lang=pt
- "vfxkit_video_rationale_115": "Black -> alpha. The median of a thin border ring is the frame's haze; it is subt" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L115 | neighbors=[_key()] | lang=en
- "vfxkit_video_rationale_129": "The sheet over a mid blue-grey: keyed edges, haze and dark rims are all visible" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L129 | neighbors=[_sheet()] | lang=en
- "vfxkit_video_rationale_144": "Every `step`-th frame (24 fps numbering, the same numbers `flipbook` takes) in a" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L144 | neighbors=[timeline()] | lang=en
- "vfxkit_video_rationale_169": "Decode -> key -> shared crop -> masked cells with transparent gutters -> one she" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L169 | neighbors=[flipbook()] | lang=en
- "vfxkit_video_rationale_287": "Re-colour a keyed sheet cell by cell (t = cell / last cell).      - `erode`/`ero" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L287 | neighbors=[grade()] | lang=en
- "vfxkit_video_rationale_388": "Crop a generated element image on black and place it on a pure black canvas of t" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L388 | neighbors=[first_frame()] | lang=en
- "vfxkit_video_rationale_56": "Append .png unless it is already there: names may contain dots (T_Hit.v2, T_Burs" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L56 | neighbors=[_png()] | lang=en
- "vfxkit_video_rationale_61": "A relative path that starts with vfx/ is project-relative; a bare name lands in" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L61 | neighbors=[_in_project()] | lang=en
- "vfxkit_video_rationale_69": "Bare names land in vfx/textures/processed/; every write must stay inside the pro" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L69 | neighbors=[_resolve_output()] | lang=en
- "vfxkit_video_rationale_74": "A sheet given as a path, a project path (vfx/...) or the bare name of a processe" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L74 | neighbors=[_resolve_sheet()] | lang=pt
- "vfxkit_video_rationale_83": "Project-relative when inside the project, else the file name only: the record is" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L83 | neighbors=[_portable()] | lang=en
- "vfxkit_video_rationale_95": "Upsert one texture's provenance into vfx/video_prompts.json (lint accepts textur" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L95 | neighbors=[record()] | lang=en
- "vfxkit_workflow_digest": "digest()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L27 | neighbors=[workflow.py] | lang=en
- "vfxkit_workflow_effect_id": "effect_id()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L21 | neighbors=[workflow.py] | lang=en
- "vfxkit_workflow_locked": "locked()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L101 | neighbors=[workflow.py] | lang=en
- "vfxkit_workflow_project_lock": "project_lock()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L80 | neighbors=[workflow.py] | lang=en
- "vfxkit_workflow_rationale_1": "Shared portable storage and a reentrant, cross-process workspace lock." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L1 | neighbors=[workflow.py] | lang=en
- "vfxkit_workflow_save_json": "save_json()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L62 | neighbors=[workflow.py] | lang=en
- "vm_debugger_add_breakpoint": "add_breakpoint()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L22 | neighbors=[debugger.cpp] | lang=en
- "vm_debugger_clear_breakpoints": "clear_breakpoints()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L32 | neighbors=[debugger.cpp] | lang=en
- "vm_debugger_finished": "finished()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L53 | neighbors=[debugger.cpp] | lang=en
- "vm_debugger_last_pc": "last_pc()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L55 | neighbors=[debugger.cpp] | lang=en
- "vm_debugger_remove_breakpoint": "remove_breakpoint()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L26 | neighbors=[debugger.cpp] | lang=en
- "vm_debugger_steps": "steps()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L56 | neighbors=[debugger.cpp] | lang=en
- "vm_debugger_vmdebugger": "VmDebugger()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L11 | neighbors=[debugger.cpp] | lang=en
- "vm_register_vm_run_register_module": "run_register_module()" | kind=code-symbol | source=mute/src/vm/register_vm.cpp:L9 | neighbors=[register_vm.cpp] | lang=en

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
