# Node Description Batch 183 of 207

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

- "scripts_template_engine_rationale_28": "Resolves nested dot-notation keys from context (e.g., app.info.package)." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L28 | neighbors=[get_nested_val()] | lang=en
- "scripts_template_engine_rationale_40": "Base class for all Abstract Syntax Tree (AST) node elements." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L40 | neighbors=[Node] | lang=en
- "scripts_template_engine_rationale_47": "Represents raw static text blocks." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L47 | neighbors=[TextNode] | lang=en
- "scripts_template_engine_rationale_57": "Represents dynamic variable interpolation with literal fallbacks." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L57 | neighbors=[VarNode] | lang=en
- "scripts_template_engine_rationale_73": "Represents conditional block logic (IF, IF_ALL, IF_ANY)." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L73 | neighbors=[IfNode] | lang=en
- "scripts_template_engine_rationale_95": "Helper to strip leading/trailing whitespace from first/last TextNodes." | kind=entity | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L95 | neighbors=[strip_nodes()] | lang=en
- "scripts_template_engine_textnode_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L49 | neighbors=[TextNode] | lang=en
- "scripts_template_engine_textnode_render": ".render()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L52 | neighbors=[TextNode] | lang=en
- "scripts_template_engine_varnode_init": ".__init__()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L59 | neighbors=[VarNode] | lang=en
- "scripts_terrain_rationale_1": "Game-ready terrain: noise (fbm, ridged mountains, rolling hills) or a heightmap" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L1 | neighbors=[terrain.py] | lang=pt
- "scripts_terrain_rationale_59": "Thermal erosion: material above the talus angle slides to lower neighbours (4-ne" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-environment-kits/scripts/terrain.py:L59 | neighbors=[_erode()] | lang=en
- "scripts_texel_density_rationale_1": "Measure (and optionally set) texel density in px/m for objects' active UV map." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L1 | neighbors=[texel_density.py] | lang=en
- "scripts_texel_density_rationale_22": "UV islands as lists of faces (connected through shared UV coords)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/texel_density.py:L22 | neighbors=[_islands()] | lang=en
- "scripts_toon_setup_g_init": ".__init__()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L36 | neighbors=[_G] | lang=en
- "scripts_toon_setup_rationale_1": "Reversible toon/cel look: banded shading, shadow tint, rim, hard specular, inver" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L1 | neighbors=[toon_setup.py] | lang=en
- "scripts_toon_setup_rationale_169": "Light Direction = the sun's local +Z in world space (the sun shines along -Z)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L169 | neighbors=[_drive_light()] | lang=en
- "scripts_toon_setup_rationale_228": "NPR_OutlineNormal corner color: position-averaged normal in tangent space, packe" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L228 | neighbors=[smooth_outline_normals()] | lang=en
- "scripts_trace_ref_quant": "quant()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/trace_ref.py:L36 | neighbors=[trace_ref.py] | lang=en
- "scripts_track_camera_rationale_1": "Automatic camera solve from footage: detect features at the start and end of the" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/track_camera.py:L1 | neighbors=[track_camera.py] | lang=en
- "scripts_turntable_rationale_1": "Look-dev scene in one call: framed camera, light rig (studio 3-point / HDRI / bo" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-lighting-lookdev/scripts/turntable.py:L1 | neighbors=[turntable.py] | lang=en
- "scripts_uv_pack_rationale_1": "Unwrap + pack UVs with production defaults; optional seams-from-sharp and lightm" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L1 | neighbors=[uv_pack.py] | lang=en
- "scripts_uv_pack_rationale_39": "Fraction of faces whose UV area is ~0 (failed unwrap)." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L39 | neighbors=[_collapsed_ratio()] | lang=en
- "scripts_verify_desktop_rationale_1": "Collect real desktop build/run evidence. Never automatically accept ENG-03." | kind=entity | source=engine/rhi/scripts/verify_desktop.py:L1 | neighbors=[verify_desktop.py] | lang=en
- "scripts_vse_edit_rationale_1": "Assemble a video edit in the Video Sequencer headless: movies (with their audio)" | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L1 | neighbors=[vse_edit.py] | lang=en
- "scripts_vse_edit_rationale_32": "Sorted frame files for a folder or a # pattern, else None." | kind=entity | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L32 | neighbors=[_frames()] | lang=pt
- "sdl3_sdl": "SDL.h" | kind=code-symbol | source=engine/platform/tests/fakes/SDL3/SDL.h:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "sdl3_sdl_main": "SDL_main.h" | kind=code-symbol | source=engine/rhi/tests/fakes/SDL3/SDL_main.h:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …] | lang=en
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-182.json

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
