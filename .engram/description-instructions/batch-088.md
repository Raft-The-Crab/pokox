# Node Description Batch 89 of 208

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

- "valleylake_valley_map_slabs": "slabs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L479 | neighbors=[valley_map.py, build_profile(), slab boundaries round the ring for tier…]
- "valleylake_valley_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L27 | neighbors=[valley_map.py, place(), static()]
- "valleylake_valley_map_surface_y": "surface_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L200 | neighbors=[valley_map.py, place_soft(), top surface under (x, z) by raycast ont…]
- "valleylake_valley_props_quad": "quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L450 | neighbors=[valley_props.py, flat rectangle in XY facing -Z (lattice…, timber_wall()]
- "valleylake_valley_props_rs": "RS()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L132 | neighbors=[valley_props.py, boulder(), waterfall()]
- "vfxkit_briefs_timeline": "timeline()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L17 | neighbors=[briefs.py, Absolute first/last births, including p…, validate()]
- "vfxkit_build_check_output_dirs": "check_output_dirs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L19 | neighbors=[build.py, build(), Every folder init or a build writes int…]
- "vfxkit_build_check_targets": "check_targets()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L27 | neighbors=[build.py, build(), No file a build is about to write may b…]
- "vfxkit_build_eid": "eid()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L17 | neighbors=[build.py, build(), check_resource_conflicts()]
- "vfxkit_build_owned": "owned()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L15 | neighbors=[build.py, build(), check_resource_conflicts()]
- "vfxkit_build_removable": "removable()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L34 | neighbors=[build.py, build(), The outputs of one owned effect, refusi…]
- "vfxkit_build_resource_inputs": "resource_inputs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L45 | neighbors=[build.py, build(), {resource base name: source file} for e…]
- "vfxkit_build_resource_names": "resource_names()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L64 | neighbors=[build.py, check_resource_conflicts(), Resource names a built effect uses, fro…]
- "vfxkit_cli_main": "main()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/cli.py:L369 | neighbors=[cli.py, parser(), run()]
- "vfxkit_cli_recipes_for": "recipes_for()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/cli.py:L145 | neighbors=[cli.py, (selected, context, unloaded): with --i…, run()]
- "vfxkit_cli_run": "run()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/cli.py:L156 | neighbors=[cli.py, main(), recipes_for()]
- "vfxkit_doctor_doctor": "doctor()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/doctor.py:L40 | neighbors=[doctor.py, setup_python(), version()]
- "vfxkit_doctor_setup_python": "setup_python()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/doctor.py:L19 | neighbors=[doctor.py, doctor(), What setup.sh (setup.ps1 on Windows) wo…]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-088.json

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
