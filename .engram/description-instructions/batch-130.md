# Node Description Batch 131 of 209

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "scripts_toon_setup_g_set": ".set()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L42 | neighbors=[_G, .link()]
- "scripts_toon_setup_remove_mat": "_remove_mat()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L213 | neighbors=[toon_setup.py, run()]
- "scripts_track_camera_clip_area": "_clip_area()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L23 | neighbors=[track_camera.py, run()]
- "scripts_track_camera_solve": "_solve()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L31 | neighbors=[track_camera.py, run()]
- "scripts_turntable_area": "_area()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L43 | neighbors=[turntable.py, run()]
- "scripts_turntable_backdrop": "_backdrop()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L54 | neighbors=[turntable.py, run()]
- "scripts_turntable_bounds": "_bounds()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L24 | neighbors=[turntable.py, run()]
- "scripts_turntable_clear": "_clear()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L32 | neighbors=[turntable.py, run()]
- "scripts_turntable_fcurves": "_fcurves()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L162 | neighbors=[turntable.py, run()]
- "scripts_uv_pack_seams_from_sharp": "_seams_from_sharp()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L23 | neighbors=[uv_pack.py, run()]
- "scripts_verify_desktop_classify": "classify()" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L28 | neighbors=[verify_desktop.py, main()]
- "scripts_verify_desktop_parse_runtime": "parse_runtime()" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L17 | neighbors=[verify_desktop.py, main()]
- "scripts_verify_desktop_run_step": "run_step()" | kind=code-symbol | source=engine/rhi/scripts/verify_desktop.py:L32 | neighbors=[verify_desktop.py, main()]
- "scripts_vse_edit_output": "_output()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L68 | neighbors=[vse_edit.py, run()]
- "semantic_determinism_analyzer": "Analyzer" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L27 | neighbors=[determinism.cpp, .Analyzer()]
- "semantic_determinism_dump_determinism": "dump_determinism()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L136 | neighbors=[determinism.cpp, name()]
- "semantic_determinism_name": "name()" | kind=code-symbol | source=mute/src/semantic/determinism.cpp:L131 | neighbors=[determinism.cpp, dump_determinism()]
- "semantic_emit_alu": "alu()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L9 | neighbors=[emit.cpp, emit_bytecode()]
- "semantic_emit_is_terminator_pub": "is_terminator_pub()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L8 | neighbors=[emit.cpp, emit_bytecode()]
- "semantic_fold_eval_binary": "eval_binary()" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L18 | neighbors=[fold.cpp, fold_constants()]
- "semantic_fold_eval_compare": "eval_compare()" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L43 | neighbors=[fold.cpp, fold_constants()]
- "semantic_fold_eval_unary": "eval_unary()" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L36 | neighbors=[fold.cpp, fold_constants()]
- "semantic_fold_int_scalar": "int_scalar()" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L10 | neighbors=[fold.cpp, fold_constants()]
- "semantic_lower_lower_function": "lower_function()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L518 | neighbors=[lower.cpp, lower_function_ex()]
- "semantic_lower_lowerer": "Lowerer" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L89 | neighbors=[lower.cpp, .Lowerer()]
- "semantic_lower_requires_mask": "requires_mask()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L44 | neighbors=[lower.cpp, lower_module()]
- "semantic_optimize_is_pure": "is_pure()" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L11 | neighbors=[optimize.cpp, eliminate_dead_code()]
- "semantic_optimize_is_terminator": "is_terminator()" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L8 | neighbors=[optimize.cpp, eliminate_dead_code()]
- "semantic_semantic_accepts": "accepts()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L18 | neighbors=[semantic.cpp, same_type()]
- "semantic_semantic_analyzer": "Analyzer" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L86 | neighbors=[semantic.cpp, .Analyzer()]
- "semantic_semantic_dump_semantic": "dump_semantic()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L428 | neighbors=[semantic.cpp, name()]
- "semantic_semantic_is_float_scalar": "is_float_scalar()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L54 | neighbors=[semantic.cpp, numeric()]
- "semantic_semantic_is_integer_scalar": "is_integer_scalar()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L50 | neighbors=[semantic.cpp, numeric()]
- "semantic_semantic_name": "name()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L420 | neighbors=[semantic.cpp, dump_semantic()]
- "semantic_semantic_same_type": "same_type()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L13 | neighbors=[semantic.cpp, accepts()]
- "semantic_ssa_is_terminator": "is_terminator()" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L9 | neighbors=[ssa.cpp, verify()]
- "semantic_ssa_verify": "verify()" | kind=code-symbol | source=mute/src/semantic/ssa.cpp:L12 | neighbors=[ssa.cpp, is_terminator()]
- "shared_bpyx_add_common": "add_common()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L62 | neighbors=[_bpyx.py, --objects / --save flags shared by most…]
- "shared_bpyx_enum_ids": "enum_ids()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L104 | neighbors=[_bpyx.py, Valid identifiers of an enum property (…]
- "shared_bpyx_mesh_tris": "mesh_tris()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L117 | neighbors=[_bpyx.py, Triangle count (evaluated = with modifi…]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-130.json

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
