# Node Description Batch 204 of 208

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

- "vfxkit_primitives_rationale_65": "Small round glints that drift: embers, frost, magic dust. Uniform random size ke" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L65 | neighbors=[motes()] | lang=en
- "vfxkit_primitives_rationale_73": "Expanding wave: the node scale eases out while the band thins from the inside." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L73 | neighbors=[shock_ring()] | lang=en
- "vfxkit_primitives_rationale_79": "Swept crescent: the head races round the arc, the tail follows, the band thins a" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L79 | neighbors=[slash_arc()] | lang=en
- "vfxkit_primitives_rationale_92": "Broken energy strokes: `count` partial arcs, each at its own random tilt, radius" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L92 | neighbors=[wisps()] | lang=en
- "vfxkit_primitives_walk": "walk()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L19 | neighbors=[primitives.py] | lang=en
- "vfxkit_reference_effect_time": "effect_time()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L26 | neighbors=[reference.py] | lang=en
- "vfxkit_reference_rationale_1": "Local reference clips, explicit time mapping and honest approximate pixel analys" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L1 | neighbors=[reference.py] | lang=en
- "vfxkit_review_rationale_1": "Motion review: render a clean frame sequence in Godot and tile it into one films" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L1 | neighbors=[review.py] | lang=en
- "vfxkit_review_rationale_191": "Per-frame change energy, brightness layering and motion from viewport pixel diff" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L191 | neighbors=[metrics()] | lang=en
- "vfxkit_review_rationale_263": "Tracked baseline: one line per field and per timeline frame, so it stays small a" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L263 | neighbors=[dump_metrics()] | lang=en
- "vfxkit_review_rationale_273": "What this round changed, by flag kind (text before the colon) and key timings." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L273 | neighbors=[diff()] | lang=en
- "vfxkit_review_rationale_285": "Append one line per review to history/<ID>.jsonl so later rounds (and agents) ca" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L285 | neighbors=[record()] | lang=en
- "vfxkit_review_rationale_300": "Previous strip above the new one, labelled, so one image shows whether the round" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L300 | neighbors=[compare_sheet()] | lang=en
- "vfxkit_review_rationale_329": "Library pages from the last capture: one row per effect, frames spread over its" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L329 | neighbors=[overview()] | lang=en
- "vfxkit_review_rationale_39": "(pid, bundle path) of the frontmost macOS app; (None, None) elsewhere." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L39 | neighbors=[front_app()] | lang=en
- "vfxkit_review_rationale_53": "Run a windowed Godot capture without taking the user's foreground: Godot activat" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/review.py:L53 | neighbors=[run_windowed()] | lang=en
- "vfxkit_scaffold_rationale_1": "Create or refresh the project's vfx/ workspace from the skill's Lab template and" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L1 | neighbors=[scaffold.py] | lang=en
- "vfxkit_scaffold_rationale_33": "Serialise downloads into the shared EFFEKSEER_VFX_HOME across projects and proce" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L33 | neighbors=[toolchain_lock()] | lang=en
- "vfxkit_scaffold_rationale_44": "A verified copy of `url` at `target`: downloaded to a private temporary file, ch" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L44 | neighbors=[download()] | lang=en
- "vfxkit_scale_rationale_1": "World scale: write a recipe at the Lab's character scale and build it for a much" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L1 | neighbors=[scale.py] | lang=en
- "vfxkit_scale_rationale_151": "The effect entry converted to the world of `scale`, with the profile recorded un" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L151 | neighbors=[apply()] | lang=en
- "vfxkit_scale_rationale_166": "(world, time, budget) of a built recipe; (1, 1, 1) at character scale." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L166 | neighbors=[factors()] | lang=en
- "vfxkit_scale_rationale_35": "Normalise `scale` ('kaiju', a number for world, or {'world','time','budget'}) to" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L35 | neighbors=[profile()] | lang=en
- "vfxkit_scale_rationale_57": "Apply f to a number, a [min, max] range or a list of those." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L57 | neighbors=[_map()] | lang=pt
- "vfxkit_scale_rationale_88": "Scale lengths by s and convert per-frame rates for the time stretch t. `top`: th" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L88 | neighbors=[_space()] | lang=en
- "vfxkit_sequence_rationale_1": "Sequences: several effects performed one after another by a character's animatio" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L1 | neighbors=[sequence.py] | lang=en
- "vfxkit_sequence_rationale_141": "Seconds until the last step's effect is over (beams count their hold), plus a sh" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L141 | neighbors=[length()] | lang=en
- "vfxkit_sequence_rationale_161": "Time-labelled tiles of the whole sequence; tiles where a step starts carry its e" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L161 | neighbors=[strip()] | lang=en
- "vfxkit_sequence_rationale_200": "Capture the sequence (Lab, or the game's own frames with frames_dir) and record" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L200 | neighbors=[capture()] | lang=en
- "vfxkit_sequence_rationale_238": "For each step: the frames at its start, +4, +10 and +20 (contact, body, exit), o" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L238 | neighbors=[sheet_around_steps()] | lang=en
- "vfxkit_sequence_rationale_404": "Pick a captured key frame and write the image-edit prompt that turns it into the" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L404 | neighbors=[paintover()] | lang=en
- "vfxkit_sequence_rationale_67": "The compiled recipe snapshot of every effect in the sequence: a capture is stale" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L67 | neighbors=[recipe_hashes()] | lang=en
- "vfxkit_sequence_rationale_77": "Structure, effects, stage gate, references and concept. Errors block review; war" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L77 | neighbors=[validate()] | lang=en
- "vfxkit_texture_audit_rationale_1": "Pixel observations grouped by texture role; stylistic warnings are not build fai" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/texture_audit.py:L1 | neighbors=[texture_audit.py] | lang=en
- "vfxkit_textures_rationale_1": "Deterministic math primitives: glows, rings, tileable noise, trails, distortion" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L1 | neighbors=[textures.py] | lang=en
- "vfxkit_textures_rationale_100": "Band of flame tongues along U (tileable left-right): solid at the bottom, sharp" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L100 | neighbors=[flame_band()] | lang=en
- "vfxkit_textures_rationale_116": "Tileable vertical dashes of uneven length and width: scrolled fast along a beam" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L116 | neighbors=[speed_streaks()] | lang=en
- "vfxkit_textures_rationale_126": "Wrap a horizontal ribbon strip (white shape on black, any aspect) into a tileabl" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L126 | neighbors=[helix()] | lang=pt
- "vfxkit_textures_rationale_139": "Write the math textures to textures/procedural and textures/processed. `missing_" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L139 | neighbors=[procedural()] | lang=en
- "vfxkit_textures_rationale_15": "Seamlessly tileable 1/f noise in 0..1; stretch>1 smears along that axis (y,x)." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L15 | neighbors=[spectral()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-203.json

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
