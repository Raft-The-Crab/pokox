# Node Description Batch 42 of 207

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

- "valleylake_valley_map_foot_need": "foot_need()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L463 | neighbors=[valley_map.py, build_profile(), polar(), rim_r(), minimum foot offset per sample so every…]
- "valleylake_valley_map_paths": "paths()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L284 | neighbors=[valley_map.py, build(), H(), static(), dirt paths = draped ribbons 0.12 over t…]
- "valleylake_valley_map_polar": "polar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L431 | neighbors=[valley_map.py, foot_need(), ground(), rim_r(), prof()]
- "valleylake_valley_map_rope_lines": "rope_lines()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L726 | neighbors=[valley_map.py, build(), lantern rope lines: tall poles in a cha…, place(), reserve()]
- "valleylake_valley_map_terrace": "terrace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L705 | neighbors=[valley_map.py, build(), NE terrace: stone retaining walls (8-st…, place(), reserve()]
- "valleylake_valley_map_terrace_walls": "terrace_walls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L713 | neighbors=[valley_map.py, build(), retaining walls along the terrace's sou…, place(), stream_d()]
- "valleylake_valley_map_wlevel": "wlevel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L109 | neighbors=[valley_map.py, H(), stream water level at a centreline poin…, water(), H0()]
- "valleylake_valley_props_bark": "bark()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L878 | neighbors=[valley_props.py, .add(), broadleaf(), gnarled_tree(), bark grooves (noise stretched along the…]
- "valleylake_valley_props_clump": "clump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L190 | neighbors=[valley_props.py, blossom_tree(), leaf_cluster(), leaf_mass(), waterfall()]
- "valleylake_valley_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L574 | neighbors=[valley_props.py, .add(), crates(), dock(), market_stall()]
- "valleylake_valley_props_footbridge": "footbridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L721 | neighbors=[valley_props.py, flat(), .add(), V(), small arched plank bridge over the stre…]
- "valleylake_valley_props_lantern_post": "lantern_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L662 | neighbors=[valley_props.py, flat(), .add(), V(), low wooden lantern post for the shore p…]
- "valleylake_valley_props_lantern_rope": "lantern_rope()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L651 | neighbors=[valley_props.py, flat(), paper_lantern(), .add(), rope span along +X from x 0 (left arm t…]
- "valleylake_valley_props_lerp": "lerp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L43 | neighbors=[valley_props.py, gnarled_tree(), limb(), merged_crown(), .grow()]
- "valleylake_valley_props_merged_crown": "merged_crown()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L1039 | neighbors=[valley_props.py, broadleaf(), leaf_mass(), lerp(), tip masses pulled toward one crown heig…]
- "valleylake_valley_props_rock_steps": "rock_steps()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L820 | neighbors=[valley_props.py, rounded stepping stones across the stre…, rounded_mass(), .add(), V()]
- "valleylake_valley_props_roots": "roots()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L929 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), buttress roots gripping the ground: sta…, .add()]
- "valleylake_valley_props_rope_pole": "rope_pole()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L640 | neighbors=[valley_props.py, tall timber pole with a cross arm + str…, flat(), .add(), V()]
- "valleylake_valley_props_stone_stair": "stone_stair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L765 | neighbors=[valley_props.py, stone flight up the retaining wall (fro…, rounded_mass(), .add(), V()]
- "valleylake_valley_props_stone_wall": "stone_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L740 | neighbors=[valley_props.py, retaining wall module (front = -Z): cou…, rounded_mass(), .add(), V()]
- "vfxkit_evidence_inputs": "inputs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L56 | neighbors=[evidence.py, build_issues(), portable(), prepared(), write_build()]
- "vfxkit_evidence_latest": "latest()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L245 | neighbors=[evidence.py, context(), read_capture(), store(), verify()]
- "vfxkit_evidence_read_build": "read_build()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L107 | neighbors=[evidence.py, build_issues(), capture_issues(), store(), write_capture()]
- "vfxkit_evidence_submit": "submit()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L215 | neighbors=[evidence.py, capture_issues(), now(), read_capture(), store()]
- "vfxkit_evidence_write_build": "write_build()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L77 | neighbors=[evidence.py, inputs(), now(), outputs(), store()]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-041.json

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
