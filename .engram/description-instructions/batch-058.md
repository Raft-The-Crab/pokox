# Node Description Batch 59 of 208

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

- "unit_values_test_cases": "cases()" | kind=code-symbol | source=mute/tests/unit/values_test.cpp:L12 | neighbors=[values_test.cpp, check(), unwrap(), main()]
- "unit_visual_solver_test": "visual_solver_test.cpp" | kind=code-symbol | source=engine/physics/tests/unit/visual_solver_test.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, dyn_sphere(), main(), static_box()]
- "valleylake_paint_atlas": "atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L95 | neighbors=[paint.py, paint_block(), install(), the 1024 px atlas image for a pro_lib P…]
- "valleylake_paint_fnoise": "fnoise()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L21 | neighbors=[paint.py, cracks(), paint_block(), periodic FFT noise in [-1, 1]; aniso > …]
- "valleylake_valley_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L235 | neighbors=[valley_map.py, build(), shore(), stations_and_village()]
- "valleylake_valley_map_beach": "beach()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L310 | neighbors=[valley_map.py, static(), build(), the curving pale beach as a draped ring…]
- "valleylake_valley_map_ground_rock": "ground_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L441 | neighbors=[valley_map.py, H(), rock_dim(), put_rock()]
- "valleylake_valley_map_hero_yaw": "hero_yaw()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L806 | neighbors=[valley_map.py, kit(), yaw that swings the hero oak's leaning …, shore()]
- "valleylake_valley_map_in_terr": "in_terr()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L85 | neighbors=[valley_map.py, H0(), nature(), stations_and_village()]
- "valleylake_valley_map_poly_d": "poly_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L81 | neighbors=[valley_map.py, path_d(), seg_d(), stream_d()]
- "valleylake_valley_map_put_rock": "put_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L445 | neighbors=[valley_map.py, cliffs(), ground_rock(), place()]
- "valleylake_valley_map_stream_d": "stream_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L82 | neighbors=[valley_map.py, H0(), poly_d(), terrace_walls()]
- "valleylake_valley_props_basket": "basket()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L581 | neighbors=[valley_props.py, .add(), crates(), market_stall()]
- "valleylake_valley_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L333 | neighbors=[valley_props.py, flat(), leaf_cluster(), .add()]
- "valleylake_valley_props_crates": "crates()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L596 | neighbors=[valley_props.py, barrel(), basket(), crate()]
- "valleylake_valley_props_engawa": "engawa()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L505 | neighbors=[valley_props.py, .add(), house(), veranda deck along a wall (z = wall lin…]
- "valleylake_valley_props_flower_patch": "flower_patch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L361 | neighbors=[valley_props.py, flat(), .add(), V()]
- "valleylake_valley_props_grass_tuft": "grass_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L347 | neighbors=[valley_props.py, .add(), V(), blade clump: thin bent blades fanning o…]
- "valleylake_valley_props_lily_pads": "lily_pads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L377 | neighbors=[valley_props.py, flat(), .add(), V()]
- "valleylake_valley_props_moss_cap": "moss_cap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L93 | neighbors=[valley_props.py, boulder(), thick moss shell over the up-facing par…, waterfall()]
- "valleylake_valley_props_reeds": "reeds()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L395 | neighbors=[valley_props.py, flat(), .add(), V()]
- "valleylake_valley_props_rim_shade": "rim_shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L123 | neighbors=[valley_props.py, boulder(), per-vertex convexity -> painted rim hig…, waterfall()]
- "valleylake_valley_props_sign_stand": "sign_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L831 | neighbors=[valley_props.py, station sign: blank board (GUI goes on …, .add(), V()]
- "valleylake_valley_props_skin_mesh": "skin_mesh()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L844 | neighbors=[valley_props.py, broadleaf(), gnarled_tree(), branching skeleton -> one smooth closed…]
- "vfxkit_discover": "discover.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/discover.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, discover(), Dump every Core property path of a fres…]
- "vfxkit_evidence_context": "context()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L285 | neighbors=[evidence.py, build_issues(), current_recipe(), latest()]
- "vfxkit_evidence_current_recipe": "current_recipe()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L27 | neighbors=[evidence.py, build_issues(), context(), verify()]
- "vfxkit_evidence_dependencies": "dependencies()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L159 | neighbors=[evidence.py, capture_issues(), A staged impact can show its incoming p…, write_capture()]
- "vfxkit_evidence_now": "now()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L19 | neighbors=[evidence.py, submit(), write_build(), write_capture()]
- "vfxkit_evidence_read_capture": "read_capture()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L153 | neighbors=[evidence.py, latest(), store(), submit()]
- "vfxkit_examples_catalog": "catalog()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L17 | neighbors=[examples.py, ids(), listing(), show()]
- "vfxkit_examples_ids": "ids()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L21 | neighbors=[examples.py, add(), catalog(), show_any()]
- "vfxkit_examples_show": "show()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L87 | neighbors=[examples.py, Layer plan with absolute frames, so an …, catalog(), show_any()]
- "vfxkit_examples_show_any": "show_any()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L121 | neighbors=[examples.py, `show` for one effect, or for every eff…, ids(), show()]
- "vfxkit_finalize": "finalize.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/finalize.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, finalize(), Package current generated assets; never…]
- "vfxkit_library_library": "library()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/library.py:L61 | neighbors=[library.py, load(), sources(), Every recipe; any source that fails to …]
- "vfxkit_lint_compare_elements": "compare_elements()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L201 | neighbors=[lint.py, features(), lint_library(), Pairs in one category whose elements di…]
- "vfxkit_lint_look": "look()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L87 | neighbors=[lint.py, features(), stem(), What a layer draws: renderer plus its t…]
- "vfxkit_lint_stem": "stem()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/lint.py:L55 | neighbors=[lint.py, features(), lint(), look()]
- "vfxkit_ownership_name_key": "name_key()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/ownership.py:L60 | neighbors=[ownership.py, may_use(), Comparison key of a resource name: Unic…, same_name()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-058.json

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
