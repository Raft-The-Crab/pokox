# Node Description Batch 146 of 207

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

- "vfxkit_evidence_outputs": "outputs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L71 | neighbors=[evidence.py, write_build()]
- "vfxkit_evidence_portable": "portable()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L46 | neighbors=[evidence.py, inputs()]
- "vfxkit_evidence_prepared": "prepared()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L33 | neighbors=[evidence.py, inputs()]
- "vfxkit_evidence_stage_snapshot": "stage_snapshot()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L131 | neighbors=[evidence.py, capture_issues()]
- "vfxkit_evidence_template_issues": "template_issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L143 | neighbors=[evidence.py, capture_issues()]
- "vfxkit_examples_listing": "listing()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L48 | neighbors=[examples.py, catalog()]
- "vfxkit_examples_textures": "textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L41 | neighbors=[examples.py, add()]
- "vfxkit_handoff_handoff": "handoff()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/handoff.py:L25 | neighbors=[handoff.py, reviewer_skill()]
- "vfxkit_library_describe": "describe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L57 | neighbors=[library.py, partial()]
- "vfxkit_library_forget_helpers": "_forget_helpers()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L35 | neighbors=[library.py, load()]
- "vfxkit_library_get": "get()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L90 | neighbors=[library.py, load()]
- "vfxkit_lint_colours": "colours()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L61 | neighbors=[lint.py, lint()]
- "vfxkit_main": "__main__.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/__main__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "vfxkit_ownership_digest": "digest()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L18 | neighbors=[ownership.py, owned()]
- "vfxkit_ownership_same_name": "same_name()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L66 | neighbors=[ownership.py, name_key()]
- "vfxkit_paths_full_mode_platform": "full_mode_platform()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L35 | neighbors=[paths.py, Where build and render (EffekseerCore t…]
- "vfxkit_paths_godot": "godot()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L54 | neighbors=[paths.py, Godot 4 executable: GODOT, then `godot`…]
- "vfxkit_paths_initialized": "initialized()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L21 | neighbors=[paths.py, `vfx init` has run here: a vfx/ folder …]
- "vfxkit_paths_setup_command": "setup_command()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L46 | neighbors=[paths.py, How to run setup on this system, as a c…]
- "vfxkit_primitives_beam_inputs": "beam_inputs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L417 | neighbors=[primitives.py, Default inputs of a beam recipe (effect…]
- "vfxkit_primitives_budget": "budget()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L314 | neighbors=[primitives.py, life_max()]
- "vfxkit_primitives_contrast_pair": "contrast_pair()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L370 | neighbors=[primitives.py, One fixed sprite plus a matching Blend …]
- "vfxkit_primitives_effect": "effect()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L273 | neighbors=[primitives.py, impact (0..1) and light drive the lab's…]
- "vfxkit_primitives_is_path": "is_path()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L15 | neighbors=[primitives.py, A texture already resolved to a file pa…]
- "vfxkit_primitives_sustain": "sustain()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L361 | neighbors=[primitives.py, Projectile emitter: one instance every …]
- "vfxkit_reference_analyse": "analyse()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L32 | neighbors=[reference.py, import_clip()]
- "vfxkit_reference_checked_id": "checked_id()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L13 | neighbors=[reference.py, read()]
- "vfxkit_review_frame_state": "frame_state()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L87 | neighbors=[review.py, capture()]
- "vfxkit_review_overview": "overview()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L328 | neighbors=[review.py, Library pages from the last capture: on…]
- "vfxkit_review_sample_plan": "sample_plan()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L79 | neighbors=[review.py, capture()]
- "vfxkit_review_sheet": "sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L307 | neighbors=[review.py, capture()]
- "vfxkit_scale_factors": "factors()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L165 | neighbors=[scale.py, (world, time, budget) of a built recipe…]
- "vfxkit_sequence_lab_capture": "_lab_capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L262 | neighbors=[sequence.py, capture()]
- "vfxkit_sequence_rubric": "rubric()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L58 | neighbors=[sequence.py, criteria()]
- "vfxkit_textures_inspect_all": "inspect_all()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L204 | neighbors=[textures.py, inspect()]
- "vfxkit_unity_periodic": "_periodic()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L56 | neighbors=[unity.py, textures()]
- "vfxkit_unity_sheet": "_sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L91 | neighbors=[unity.py, textures()]
- "vfxkit_video_eval": "_eval()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L279 | neighbors=[video.py, grade()]
- "vfxkit_video_ffmpeg": "_ffmpeg()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L37 | neighbors=[video.py, _decode()]
- "vfxkit_video_parse_frames": "_parse_frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L135 | neighbors=[video.py, flipbook()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-145.json

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
