# Node Description Batch 202 of 208

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

- "vfxkit_examples_rationale_1": "Shipped example effects: four ranged pairs (projectile + impact), five single ef" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L1 | neighbors=[examples.py] | lang=en
- "vfxkit_examples_rationale_122": "`show` for one effect, or for every effect of a named example (a pair shows proj" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L122 | neighbors=[show_any()] | lang=en
- "vfxkit_examples_rationale_88": "Layer plan with absolute frames, so an example can be read as a timeline before" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L88 | neighbors=[show()] | lang=en
- "vfxkit_filelock_acquire": "acquire()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/filelock.py:L12 | neighbors=[filelock.py] | lang=en
- "vfxkit_filelock_rationale_1": "Exclusive, blocking, cross-process file locks on macOS, Linux and Windows. Stand" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/filelock.py:L1 | neighbors=[filelock.py] | lang=en
- "vfxkit_filelock_release": "release()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/filelock.py:L21 | neighbors=[filelock.py] | lang=en
- "vfxkit_finalize_finalize": "finalize()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/finalize.py:L7 | neighbors=[finalize.py] | lang=en
- "vfxkit_finalize_rationale_1": "Package current generated assets; never invent test/device verification results." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/finalize.py:L1 | neighbors=[finalize.py] | lang=en
- "vfxkit_handoff_rationale_1": "Everything an independent reviewer needs for one capture, as a prompt the author" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/handoff.py:L1 | neighbors=[handoff.py] | lang=en
- "vfxkit_handoff_rationale_19": "The vfx-review skill installed next to this one (both folders are installed side" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/handoff.py:L19 | neighbors=[reviewer_skill()] | lang=en
- "vfxkit_init_rationale_1": "effekseer-vfx toolchain: recipe primitives, lint, Core build, Godot review and e" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/__init__.py:L1 | neighbors=[__init__.py] | lang=en
- "vfxkit_library_helperfinder_find_spec": ".find_spec()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L21 | neighbors=[HelperFinder] | lang=en
- "vfxkit_library_rationale_1": "The project's effect library: one recipe source per effect in vfx/src/<ID>.py." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L1 | neighbors=[library.py] | lang=en
- "vfxkit_library_rationale_17": "Resolves `_name` helpers in vfx/src. It sits at the end of sys.meta_path and vfx" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L17 | neighbors=[HelperFinder] | lang=en
- "vfxkit_library_rationale_62": "Every recipe; any source that fails to load fails the call (full builds and full" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L62 | neighbors=[library()] | lang=en
- "vfxkit_library_rationale_67": "Recipes for `ids` must load; the rest are loaded best-effort as context for cros" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L67 | neighbors=[partial()] | lang=en
- "vfxkit_lint_rationale_1": "Static recipe checks. Needs neither EffekseerCore nor Godot, so it also runs in" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L1 | neighbors=[lint.py] | lang=en
- "vfxkit_lint_rationale_202": "Pairs in one category whose elements differ in fewer than MIN_DIFFERENCES featur" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L202 | neighbors=[compare_elements()] | lang=en
- "vfxkit_lint_rationale_213": "Lint `recipes`; element differences are judged against `context` (default: the r" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L213 | neighbors=[lint_library()] | lang=en
- "vfxkit_lint_rationale_28": "Screen feedback is game data (Vfx.gd emits it as screen_cue): keep it in the ran" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L28 | neighbors=[screen_errors()] | lang=en
- "vfxkit_lint_rationale_43": "Frames after the start at which the reference performance releases sustained lay" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L43 | neighbors=[release_frames()] | lang=en
- "vfxkit_lint_rationale_58": "White-hot: very bright and nearly unsaturated, so warm whites count and acid gre" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L58 | neighbors=[hot()] | lang=en
- "vfxkit_lint_rationale_68": "Coarse motion tags for the element-difference check." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L68 | neighbors=[moves()] | lang=en
- "vfxkit_lint_rationale_88": "What a layer draws: renderer plus its texture or procedural mesh shape." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L88 | neighbors=[look()] | lang=en
- "vfxkit_ownership_rationale_1": "Which effects and files in a workspace this skill built, so it only ever deletes" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L1 | neighbors=[ownership.py] | lang=en
- "vfxkit_ownership_rationale_24": "Built by this skill, so a full build may remove it once its source is gone." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L24 | neighbors=[owned()] | lang=en
- "vfxkit_ownership_rationale_46": "Effect files this skill did not build: unowned manifest entries and .efkefc file" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L46 | neighbors=[unmanaged()] | lang=en
- "vfxkit_ownership_rationale_61": "Comparison key of a resource name: Unicode NFC, then case folded. The default ma" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L61 | neighbors=[name_key()] | lang=en
- "vfxkit_ownership_rationale_71": "Whether an effect file (whose dependencies are not recorded) could reference res" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L71 | neighbors=[may_use()] | lang=en
- "vfxkit_ownership_rationale_89": "`path` (after resolving symlinks) lies within `folder`." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L89 | neighbors=[inside()] | lang=en
- "vfxkit_ownership_rationale_94": "Raise unless writing `path` stays inside `folder`: its parent resolves inside, a" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L94 | neighbors=[guard()] | lang=pt
- "vfxkit_paths_rationale_1": "Where the skill's own files live, where the toolchain is installed and which gam" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L1 | neighbors=[paths.py] | lang=en
- "vfxkit_paths_rationale_22": "`vfx init` has run here: a vfx/ folder that merely exists (another tool's output" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L22 | neighbors=[initialized()] | lang=en
- "vfxkit_paths_rationale_36": "Where build and render (EffekseerCore through .NET, the Effekseer Godot plugin)" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L36 | neighbors=[full_mode_platform()] | lang=en
- "vfxkit_paths_rationale_47": "How to run setup on this system, as a command an agent can run from the project." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L47 | neighbors=[setup_command()] | lang=en
- "vfxkit_paths_rationale_55": "Godot 4 executable: GODOT, then `godot` (or `godot4`) on PATH, then the standard" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L55 | neighbors=[godot()] | lang=en
- "vfxkit_primitives_rationale_1": "Composable layer primitives for effect recipes: `from vfxkit.primitives import *" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L1 | neighbors=[primitives.py] | lang=en
- "vfxkit_primitives_rationale_102": "Emissive-to-smoke afterimage: the same stroke, alpha-blended grey, a few frames" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L102 | neighbors=[decay()] | lang=en
- "vfxkit_primitives_rationale_112": "A very long, very thin accent line (aspect > 40:1) that shoots out to full lengt" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L112 | neighbors=[slice_line()] | lang=en
- "vfxkit_primitives_rationale_118": "Directional burst: particles fly to a random point in the world-space box `end`" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L118 | neighbors=[spray()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-201.json

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
