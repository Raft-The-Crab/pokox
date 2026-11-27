# Node Description Batch 60 of 208

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

- "vfxkit_ownership_unmanaged": "unmanaged()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L45 | neighbors=[ownership.py, Effect files this skill did not build: …, owned(), valid_id()]
- "vfxkit_primitives_beam_strip": "_beam_strip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L428 | neighbors=[primitives.py, beam(), held(), sprite()]
- "vfxkit_primitives_billow": "billow()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L167 | neighbors=[primitives.py, ramp(), sprite(), Painted flipbook billow played once ove…]
- "vfxkit_primitives_charge_chain": "charge_chain()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L488 | neighbors=[primitives.py, _aim(), sprite(), Electric arcs that light up along a cha…]
- "vfxkit_primitives_debris": "debris()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L122 | neighbors=[primitives.py, spray(), sprite(), Dark tumbling rock chunks thrown along …]
- "vfxkit_primitives_flame": "flame()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L148 | neighbors=[primitives.py, ramp(), sprite(), Fire tongues without a drawn flame: the…]
- "vfxkit_primitives_lifetime": "lifetime()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L304 | neighbors=[primitives.py, life_max(), Latest frame at which this layer or any…, swing()]
- "vfxkit_primitives_shell_fragments": "shell_fragments()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L247 | neighbors=[primitives.py, Six partial spherical sheets separate a…, mesh(), ramp()]
- "vfxkit_primitives_shock_ring": "shock_ring()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L72 | neighbors=[primitives.py, Expanding wave: the node scale eases ou…, fade(), tilted_ring()]
- "vfxkit_primitives_slash_arc": "slash_arc()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L78 | neighbors=[primitives.py, Swept crescent: the head races round th…, tex(), slash_set()]
- "vfxkit_primitives_slash_set": "slash_set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L334 | neighbors=[primitives.py, Wide dim afterimage + saturated body + …, slash_arc(), sprite()]
- "vfxkit_primitives_spiral_ribbons": "spiral_ribbons()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L553 | neighbors=[primitives.py, Ribbons that spiral round a pillar: a d…, hard_edge(), mesh()]
- "vfxkit_primitives_wisps": "wisps()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L90 | neighbors=[primitives.py, Broken energy strokes: `count` partial …, fade(), tex()]
- "vfxkit_reference_import_clip": "import_clip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L73 | neighbors=[reference.py, analyse(), read(), tiles()]
- "vfxkit_reference_tiles": "tiles()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L55 | neighbors=[reference.py, compare(), frames(), import_clip()]
- "vfxkit_review_run_windowed": "run_windowed()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L52 | neighbors=[review.py, capture(), Run a windowed Godot capture without ta…, front_app()]
- "vfxkit_scale_apply": "apply()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L150 | neighbors=[scale.py, _layers(), profile(), The effect entry converted to the world…]
- "vfxkit_scale_layers": "_layers()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L141 | neighbors=[scale.py, apply(), _space(), _time()]
- "vfxkit_scale_space": "_space()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L87 | neighbors=[scale.py, _layers(), Scale lengths by s and convert per-fram…, _map()]
- "vfxkit_sequence_concept_compare": "concept_compare()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L441 | neighbors=[sequence.py, _frame_number(), latest(), read()]
- "vfxkit_sequence_criteria": "criteria()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L62 | neighbors=[sequence.py, rubric(), handoff(), submit()]
- "vfxkit_sequence_gate_path": "gate_path()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L43 | neighbors=[sequence.py, sequence_id(), submit(), validate()]
- "vfxkit_sequence_recipe_hashes": "recipe_hashes()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L66 | neighbors=[sequence.py, capture(), issues(), The compiled recipe snapshot of every e…]
- "vfxkit_sequence_sequence_id": "sequence_id()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L33 | neighbors=[sequence.py, gate_path(), latest(), path()]
- "vfxkit_sequence_sheet_around_steps": "sheet_around_steps()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L237 | neighbors=[sequence.py, capture(), For each step: the frames at its start,…, _frame_number()]
- "vfxkit_sequence_store": "store()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L54 | neighbors=[sequence.py, capture(), latest(), submit()]
- "vfxkit_textures_flame_band": "flame_band()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L99 | neighbors=[textures.py, spectral(), masks(), Band of flame tongues along U (tileable…]
- "vfxkit_textures_procedural": "procedural()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L138 | neighbors=[textures.py, masks(), spectral(), Write the math textures to textures/pro…]
- "vfxkit_textures_sample": "_sample()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L77 | neighbors=[textures.py, helix(), Bilinear lookup with wrap-around, so wa…, swirl()]
- "vfxkit_unity_export": "export()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L208 | neighbors=[unity.py, bottom_inset(), _project(), Copy one processed sheet into the Unity…]
- "vfxkit_unity_install": "install()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L180 | neighbors=[unity.py, _project(), textures(), Copy the package into Packages/ (Unity …]
- "vfxkit_unity_mask": "_mask()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L43 | neighbors=[unity.py, _save(), Greyscale distance mask in alpha (impor…, textures()]
- "vfxkit_unity_project": "_project()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L26 | neighbors=[unity.py, export(), install(), textures()]
- "vfxkit_unity_tile_noise": "_tile_noise()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L62 | neighbors=[unity.py, _blob(), Tileable value noise in 0-1: random lat…, textures()]
- "vfxkit_video_decode": "_decode()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L44 | neighbors=[video.py, _ffmpeg(), flipbook(), timeline()]
- "vfxkit_video_first_frame": "first_frame()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L387 | neighbors=[video.py, _in_project(), _png(), Crop a generated element image on black…]
- "vfxkit_video_record": "record()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L94 | neighbors=[video.py, flipbook(), grade(), Upsert one texture's provenance into vf…]
- "vfxkit_video_report_dir": "_report_dir()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L89 | neighbors=[video.py, flipbook(), grade(), timeline()]
- "vfxkit_video_sheet": "_sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L128 | neighbors=[video.py, flipbook(), grade(), The sheet over a mid blue-grey: keyed e…]
- "vm_debugger_step": "step()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L34 | neighbors=[debugger.cpp, run(), finish(), pc()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-059.json

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
