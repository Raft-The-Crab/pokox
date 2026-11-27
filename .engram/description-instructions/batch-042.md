# Node Description Batch 43 of 208

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

- "vfxkit_evidence_write_capture": "write_capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L175 | neighbors=[evidence.py, dependencies(), now(), read_build(), store()]
- "vfxkit_filelock": "filelock.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/filelock.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, acquire(), release(), Exclusive, blocking, cross-process file…]
- "vfxkit_handoff": "handoff.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/handoff.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, handoff(), reviewer_skill(), Everything an independent reviewer need…]
- "vfxkit_library_load": "load()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L41 | neighbors=[library.py, get(), library(), _forget_helpers(), partial()]
- "vfxkit_library_partial": "partial()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L66 | neighbors=[library.py, describe(), load(), sources(), Recipes for `ids` must load; the rest a…]
- "vfxkit_lint_features": "features()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L92 | neighbors=[lint.py, compare_elements(), look(), moves(), stem()]
- "vfxkit_lint_lint_library": "lint_library()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L212 | neighbors=[lint.py, compare_elements(), documented_textures(), lint(), Lint `recipes`; element differences are…]
- "vfxkit_ownership_owned": "owned()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L23 | neighbors=[ownership.py, digest(), valid_id(), Built by this skill, so a full build ma…, unmanaged()]
- "vfxkit_primitives_hard_edge": "hard_edge()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L522 | neighbors=[primitives.py, Read a greyscale mask as a crisp toon s…, spike_crown(), spiral_ribbons(), stylized_pair()]
- "vfxkit_primitives_life_max": "life_max()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L301 | neighbors=[primitives.py, budget(), lifetime(), mesh(), spike_crown()]
- "vfxkit_primitives_radial_sparks": "radial_sparks()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L43 | neighbors=[primitives.py, beam(), sprite(), Motion-aligned streaks thrown from a sp…, spark_burst()]
- "vfxkit_primitives_smoke": "smoke()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L138 | neighbors=[primitives.py, beam(), Alpha-blended puffs that grow and slow …, fade(), sprite()]
- "vfxkit_primitives_spike_crown": "spike_crown()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L561 | neighbors=[primitives.py, Jagged dark spikes erupting round a bea…, hard_edge(), life_max(), mesh()]
- "vfxkit_reference_read": "read()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/reference.py:L19 | neighbors=[reference.py, compare(), frames(), import_clip(), checked_id()]
- "vfxkit_scale_time": "_time()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L72 | neighbors=[scale.py, _layers(), _frames(), _life(), _map()]
- "vfxkit_sequence_paintover": "paintover()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L403 | neighbors=[sequence.py, _frame_number(), latest(), read(), Pick a captured key frame and write the…]
- "vfxkit_sequence_path": "path()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L39 | neighbors=[sequence.py, capture(), issues(), sequence_id(), read()]
- "vfxkit_sequence_strip": "strip()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L160 | neighbors=[sequence.py, capture(), Time-labelled tiles of the whole sequen…, _frame_number(), submit()]
- "vfxkit_textures_swirl": "swirl()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L83 | neighbors=[textures.py, masks(), Tileable vortex noise: streaky noise wo…, _sample(), spectral()]
- "vfxkit_unity_blob": "_blob()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L83 | neighbors=[unity.py, _polar(), _tile_noise(), A soft-edged irregular puff: radius wob…, textures()]
- "vfxkit_video_in_project": "_in_project()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L60 | neighbors=[video.py, first_frame(), A relative path that starts with vfx/ i…, _resolve_output(), _resolve_sheet()]
- "vfxkit_video_png": "_png()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L55 | neighbors=[video.py, first_frame(), Append .png unless it is already there:…, _resolve_output(), _resolve_sheet()]
- "vfxkit_video_portable": "_portable()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L82 | neighbors=[video.py, flipbook(), grade(), Project-relative when inside the projec…, timeline()]
- "vfxkit_video_resolve_sheet": "_resolve_sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L73 | neighbors=[video.py, grade(), A sheet given as a path, a project path…, _in_project(), _png()]
- "vfxkit_video_timeline": "timeline()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L143 | neighbors=[video.py, Every `step`-th frame (24 fps numbering…, _decode(), _portable(), _report_dir()]
- "vm_debugger_finish": "finish()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L6 | neighbors=[debugger.cpp, pc(), result(), run(), step()]
- "vm_debugger_pc": "pc()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L54 | neighbors=[debugger.cpp, finish(), run(), stack(), step()]
- "vm_debugger_run": "run()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L41 | neighbors=[debugger.cpp, finish(), has_breakpoint(), pc(), step()]
- "vm_hostcall": "hostcall.cpp" | kind=code-symbol | source=mute/src/vm/hostcall.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, add(), find(), host_type(), unauthorized_hostcalls()]
- "vm_values_make_array": "make_array()" | kind=code-symbol | source=mute/src/vm/values.cpp:L69 | neighbors=[values.cpp, copy_impl(), alloc(), handle_for(), object()]
- "voidrealm_void_map_build_paths": "build_paths()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L196 | neighbors=[void_map.py, build(), H(), reserve(), static()]
- "voidrealm_void_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L112 | neighbors=[void_map.py, dressing(), look(), ring_scatter(), validate()]
- "voidrealm_void_map_island_of": "island_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L51 | neighbors=[void_map.py, dressing(), H(), Rfun(), void_debris()]
- "voidrealm_void_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L119 | neighbors=[void_map.py, bridges(), build_paths(), island(), sub()]
- "voidrealm_void_props_disc": "disc()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L80 | neighbors=[void_props.py, lift_pad(), rift_gate(), rune_circle(), void_arch()]
- "voidrealm_void_props_heart_crystal": "heart_crystal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L150 | neighbors=[void_props.py, annulus(), crystal_cluster(), FS(), the big crystal on the Starwatch shard:…]
- "voidrealm_void_props_rail_segment": "rail_segment()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L320 | neighbors=[void_props.py, chamfer_box(), FS(), V(), low balustrade: two square posts with d…]
- "voidrealm_void_props_rubble": "rubble()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L280 | neighbors=[void_props.py, chamfer_box(), FS(), shaft(), shard_rock()]
- "warehouse_kitlib_sub_add": ".add()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L48 | neighbors=[B(), CY(), Sub, .emit(), T()]
- "warehouse_wh_map_mesh_obj": "mesh_obj()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L73 | neighbors=[wh_map.py, floors(), sub(), roof(), walls()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-042.json

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
