# Node Description Batch 186 of 209

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

- "scripts_turntable_rationale_1": "Look-dev scene in one call: framed camera, light rig (studio 3-point / HDRI / bo" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L1 | neighbors=[turntable.py] | lang=en
- "scripts_uv_pack_rationale_1": "Unwrap + pack UVs with production defaults; optional seams-from-sharp and lightm" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L1 | neighbors=[uv_pack.py] | lang=en
- "scripts_uv_pack_rationale_39": "Fraction of faces whose UV area is ~0 (failed unwrap)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L39 | neighbors=[_collapsed_ratio()] | lang=en
- "scripts_verify_desktop_rationale_1": "Collect real desktop build/run evidence. Never automatically accept ENG-03." | kind=entity | source=engine/rhi/scripts/verify_desktop.py:L1 | neighbors=[verify_desktop.py] | lang=en
- "scripts_vse_edit_rationale_1": "Assemble a video edit in the Video Sequencer headless: movies (with their audio)" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L1 | neighbors=[vse_edit.py] | lang=en
- "scripts_vse_edit_rationale_32": "Sorted frame files for a folder or a # pattern, else None." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L32 | neighbors=[_frames()] | lang=pt
- "semantic_determinism_analyze_determinism": "analyze_determinism()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L116 | neighbors=[determinism.cpp] | lang=en
- "semantic_determinism_analyzer_analyzer": ".Analyzer()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L29 | neighbors=[Analyzer] | lang=en
- "semantic_determinism_builtin": "builtin()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L18 | neighbors=[determinism.cpp] | lang=en
- "semantic_determinism_is_capability": "is_capability()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L9 | neighbors=[determinism.cpp] | lang=en
- "semantic_determinism_last_segment": "last_segment()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L22 | neighbors=[determinism.cpp] | lang=en
- "semantic_determinism_program_capability_mask": "program_capability_mask()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L118 | neighbors=[determinism.cpp] | lang=en
- "semantic_emit_source_pcs": "source_pcs()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L274 | neighbors=[emit.cpp] | lang=en
- "semantic_emit_source_position": "source_position()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L263 | neighbors=[emit.cpp] | lang=en
- "semantic_lower_bin_detail": "bin_detail()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L63 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_boolt": "boolt()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L10 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_cmp_detail": "cmp_detail()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L71 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_i32t": "i32t()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L9 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_is_arith": "is_arith()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L82 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_is_cmp": "is_cmp()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L79 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_lowerer_lowerer": ".Lowerer()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L91 | neighbors=[Lowerer] | lang=en
- "semantic_lower_pv": "pv()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L13 | neighbors=[lower.cpp] | lang=en
- "semantic_lower_v": "v()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L12 | neighbors=[lower.cpp] | lang=en
- "semantic_optimize_simplify_control_flow": "simplify_control_flow()" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L42 | neighbors=[optimize.cpp] | lang=en
- "semantic_semantic_analyze": "analyze()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L419 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_analyzer_analyzer": ".Analyzer()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L409 | neighbors=[Analyzer] | lang=en
- "semantic_semantic_generic_arity": "generic_arity()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L63 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_generic_tag": "generic_tag()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L68 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_is_assign_op": "is_assign_op()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L60 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_scalar": "scalar()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L49 | neighbors=[semantic.cpp] | lang=en
- "semantic_semantic_type_name": "type_name()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L35 | neighbors=[semantic.cpp] | lang=en
- "semantic_ssa_dump_ir": "dump_ir()" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L196 | neighbors=[ssa.cpp] | lang=en
- "semantic_ssa_name": "name()" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L211 | neighbors=[ssa.cpp] | lang=en
- "sh": "Sh" | kind=code-symbol | neighbors=[ShAng] | lang=en
- "shared_bpyx_default": "_default()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L24 | neighbors=[_bpyx.py] | lang=en
- "shared_bpyx_rationale_1": "_bpyx - tiny shared helpers for blender-agent-skills scripts (Blender 5.2 LTS+," | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L1 | neighbors=[_bpyx.py] | lang=en
- "shared_bpyx_rationale_100": "First node of `type_` (e.g. 'BSDF_PRINCIPLED'). Names are localized - never look" | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L100 | neighbors=[node()] | lang=en
- "shared_bpyx_rationale_105": "Valid identifiers of an enum property (works on types or instances)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L105 | neighbors=[enum_ids()] | lang=en
- "shared_bpyx_rationale_110": "Assign an enum; on failure raise listing valid values (dynamic enums under-repor" | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L110 | neighbors=[set_enum()] | lang=en
- "shared_bpyx_rationale_118": "Triangle count (evaluated = with modifiers)." | kind=entity | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L118 | neighbors=[mesh_tris()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-185.json

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
