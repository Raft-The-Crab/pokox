# Node Description Batch 88 of 207

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
- "vfxkit_review_compare_sheet": "compare_sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L299 | neighbors=[review.py, capture(), Previous strip above the new one, label…]
- "vfxkit_review_diff": "diff()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L272 | neighbors=[review.py, capture(), What this round changed, by flag kind (…]
- "vfxkit_review_dump_metrics": "dump_metrics()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L262 | neighbors=[review.py, capture(), Tracked baseline: one line per field an…]
- "vfxkit_review_front_app": "front_app()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L38 | neighbors=[review.py, (pid, bundle path) of the frontmost mac…, run_windowed()]
- "vfxkit_review_metrics": "metrics()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L190 | neighbors=[review.py, capture(), Per-frame change energy, brightness lay…]
- "vfxkit_review_record": "record()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L284 | neighbors=[review.py, capture(), Append one line per review to history/<…]
- "vfxkit_scaffold_download": "download()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L43 | neighbors=[scaffold.py, initialize(), A verified copy of `url` at `target`: d…]
- "vfxkit_scaffold_initialize": "initialize()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L62 | neighbors=[scaffold.py, download(), toolchain_lock()]
- "vfxkit_scaffold_toolchain_lock": "toolchain_lock()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L32 | neighbors=[scaffold.py, initialize(), Serialise downloads into the shared EFF…]
- "vfxkit_scale_frames": "_frames()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L63 | neighbors=[scale.py, _map(), _time()]
- "vfxkit_scale_life": "_life()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L67 | neighbors=[scale.py, _map(), _time()]
- "vfxkit_scale_profile": "profile()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L34 | neighbors=[scale.py, apply(), Normalise `scale` ('kaiju', a number fo…]
- "vfxkit_sequence_length": "length()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L140 | neighbors=[sequence.py, Seconds until the last step's effect is…, validate()]
- "vfxkit_sequence_now": "_now()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L284 | neighbors=[sequence.py, capture(), submit()]
- "vfxkit_texture_audit_audit": "audit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/texture_audit.py:L31 | neighbors=[texture_audit.py, cell_report(), content()]
- "vfxkit_texture_audit_cell_report": "cell_report()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/texture_audit.py:L17 | neighbors=[texture_audit.py, audit(), content()]
- "vfxkit_texture_audit_content": "content()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/texture_audit.py:L12 | neighbors=[texture_audit.py, audit(), cell_report()]
- "vfxkit_textures_helix": "helix()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L125 | neighbors=[textures.py, _sample(), Wrap a horizontal ribbon strip (white s…]
- "vfxkit_textures_inspect": "inspect()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L171 | neighbors=[textures.py, inspect_all(), Measure a texture so recipes can use nu…]
- "vfxkit_textures_speed_streaks": "speed_streaks()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L115 | neighbors=[textures.py, masks(), Tileable vertical dashes of uneven leng…]
- "vfxkit_textures_worley": "worley()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L23 | neighbors=[textures.py, masks(), Tileable cellular noise: 0 at feature p…]
- "vfxkit_unity_bottom_inset": "bottom_inset()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L238 | neighbors=[unity.py, export(), How far the drawn shape stays above eac…]
- "vfxkit_unity_inner_gradient": "_inner_gradient()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L48 | neighbors=[unity.py, Binary shape -> interior gradient (an a…, textures()]
- "vfxkit_unity_polar": "_polar()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L77 | neighbors=[unity.py, _blob(), textures()]
- "vfxkit_unity_save": "_save()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L34 | neighbors=[unity.py, _mask(), textures()]
- "vfxkit_video_key": "_key()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L114 | neighbors=[video.py, flipbook(), Black -> alpha. The median of a thin bo…]
- "vfxkit_workflow_file_hash": "file_hash()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L31 | neighbors=[workflow.py, snapshot(), unchanged()]
- "vfxkit_workflow_snapshot": "snapshot()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/workflow.py:L54 | neighbors=[workflow.py, file_hash(), relative()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-087.json

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
