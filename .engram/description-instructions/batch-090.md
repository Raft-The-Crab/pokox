# Node Description Batch 91 of 209

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

- "vfxkit_examples_add": "add()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L56 | neighbors=[examples.py, ids(), textures()]
- "vfxkit_handoff_reviewer_skill": "reviewer_skill()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/handoff.py:L18 | neighbors=[handoff.py, handoff(), The vfx-review skill installed next to …]
- "vfxkit_init": "__init__.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/__init__.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, effekseer-vfx toolchain: recipe primiti…]
- "vfxkit_library_helperfinder": "HelperFinder" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L16 | neighbors=[library.py, .find_spec(), Resolves `_name` helpers in vfx/src. It…]
- "vfxkit_library_sources": "sources()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L31 | neighbors=[library.py, library(), partial()]
- "vfxkit_lint_documented_textures": "documented_textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L47 | neighbors=[lint.py, lint(), lint_library()]
- "vfxkit_lint_hot": "hot()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L57 | neighbors=[lint.py, lint(), White-hot: very bright and nearly unsat…]
- "vfxkit_lint_moves": "moves()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L67 | neighbors=[lint.py, features(), Coarse motion tags for the element-diff…]
- "vfxkit_lint_release_frames": "release_frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L42 | neighbors=[lint.py, lint(), Frames after the start at which the ref…]
- "vfxkit_lint_screen_errors": "screen_errors()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L27 | neighbors=[lint.py, lint(), Screen feedback is game data (Vfx.gd em…]
- "vfxkit_ownership_guard": "guard()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L93 | neighbors=[ownership.py, inside(), Raise unless writing `path` stays insid…]
- "vfxkit_ownership_inside": "inside()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L88 | neighbors=[ownership.py, guard(), `path` (after resolving symlinks) lies …]
- "vfxkit_ownership_may_use": "may_use()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L70 | neighbors=[ownership.py, name_key(), Whether an effect file (whose dependenc…]
- "vfxkit_ownership_valid_id": "valid_id()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L14 | neighbors=[ownership.py, owned(), unmanaged()]
- "vfxkit_primitives_aim": "_aim()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L483 | neighbors=[primitives.py, charge_chain(), Velocity that points a DirectionalBillb…]
- "vfxkit_primitives_column": "column()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L266 | neighbors=[primitives.py, mesh(), Volumetric light shaft: streaks scroll …]
- "vfxkit_primitives_crystal": "crystal()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L232 | neighbors=[primitives.py, mesh(), Faceted ice/arcane crystal: a six-sided…]
- "vfxkit_primitives_decal": "decal()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L206 | neighbors=[primitives.py, sprite(), Flat ground-plane sprite (rune, crack, …]
- "vfxkit_primitives_decay": "decay()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L101 | neighbors=[primitives.py, fade(), Emissive-to-smoke afterimage: the same …]
- "vfxkit_primitives_distortion_ring": "distortion_ring()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L201 | neighbors=[primitives.py, sprite(), Refractive shockwave: an expanding ring…]
- "vfxkit_primitives_flash": "flash()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L39 | neighbors=[primitives.py, sprite(), One- to five-frame anamorphic star at t…]
- "vfxkit_primitives_glow": "glow()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L29 | neighbors=[primitives.py, sprite(), Soft light bloom behind a shape: pops f…]
- "vfxkit_primitives_heat_haze": "heat_haze()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L196 | neighbors=[primitives.py, sprite(), Screen-space refraction (BackDistortion…]
- "vfxkit_primitives_held": "held()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L422 | neighbors=[primitives.py, _beam_strip(), Sustained cross-fade: a new instance ev…]
- "vfxkit_primitives_motes": "motes()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L64 | neighbors=[primitives.py, sprite(), Small round glints that drift: embers, …]
- "vfxkit_primitives_orbit_band": "orbit_band()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L129 | neighbors=[primitives.py, tex(), A band lying in a tilted 3D plane (accr…]
- "vfxkit_primitives_shadow": "shadow()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L33 | neighbors=[primitives.py, Dark alpha backing behind an additive c…, sprite()]
- "vfxkit_primitives_shell": "shell()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L239 | neighbors=[primitives.py, 3D shock bubble: a sphere whose fresnel…, mesh()]
- "vfxkit_primitives_slice_line": "slice_line()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L111 | neighbors=[primitives.py, A very long, very thin accent line (asp…, sprite()]
- "vfxkit_primitives_spark_burst": "spark_burst()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L52 | neighbors=[primitives.py, Three spark tiers instead of one unifor…, radial_sparks()]
- "vfxkit_primitives_sparkle": "sparkle()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L570 | neighbors=[primitives.py, Four-point star glints (the star of a s…, sprite()]
- "vfxkit_primitives_speed_streaks": "speed_streaks()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L547 | neighbors=[primitives.py, Speed lives in the beam: hard-cut light…, mesh()]
- "vfxkit_primitives_spray": "spray()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L117 | neighbors=[primitives.py, debris(), Directional burst: particles fly to a r…]
- "vfxkit_primitives_standing": "standing()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L213 | neighbors=[primitives.py, Upright camera-facing sprite that grows…, sprite()]
- "vfxkit_primitives_stylized_pair": "stylized_pair()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L531 | neighbors=[primitives.py, [Blend ink silhouette slightly larger, …, hard_edge()]
- "vfxkit_primitives_swing": "swing()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L365 | neighbors=[primitives.py, Turn a blade's layers into a 3D swing p…, lifetime()]
- "vfxkit_primitives_tilted_ring": "tilted_ring()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L262 | neighbors=[primitives.py, Shockwave ring lying in a 3D plane (gro…, shock_ring()]
- "vfxkit_primitives_video_body": "video_body()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L173 | neighbors=[primitives.py, A video-model flipbook (`vfx video-flip…, sprite()]
- "vfxkit_reference_compare": "compare()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L134 | neighbors=[reference.py, read(), tiles()]
- "vfxkit_reference_frames": "frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L118 | neighbors=[reference.py, read(), tiles()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-090.json

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
