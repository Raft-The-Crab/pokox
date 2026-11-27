# Node Description Batch 68 of 207

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

- "evaluator_evaluator_integer_suffix": "integer_suffix()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L59 | neighbors=[evaluator.cpp, evaluate_arithmetic(), literal_integer()]
- "evaluator_evaluator_is_float": "is_float()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L44 | neighbors=[evaluator.cpp, evaluate_arithmetic(), unary()]
- "evaluator_evaluator_magnitude": "magnitude()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L57 | neighbors=[evaluator.cpp, signed_binary(), unary()]
- "evaluator_evaluator_negative": "negative()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L58 | neighbors=[evaluator.cpp, signed_binary(), unary()]
- "evaluator_evaluator_suffix_length": "suffix_length()" | kind=code-symbol | source=mute/src/evaluator/evaluator.cpp:L64 | neighbors=[evaluator.cpp, literal_integer(), width()]
- "examples_axolotl_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/axolotl.py:L43 | neighbors=[axolotl.py, gill_base(), _unit()]
- "examples_cat_flap_cover": "cat_flap_cover.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/examples/cat_flap_cover.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Cover plate for the hole left by a remo…]
- "examples_desk_cable_tray": "desk_cable_tray.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/examples/desk_cable_tray.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Under-desk cable tray, built from ident…]
- "examples_gridfinity_d110_bin": "gridfinity_d110_bin.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/examples/gridfinity_d110_bin.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, Gridfinity 3x2 cradle bin for the Orico…]
- "extensions_superpowers_getbootstrapcontent": "getBootstrapContent()" | kind=code-symbol | source=.agents/skills/superpowers-main/.pi/extensions/superpowers.ts:L54 | neighbors=[superpowers.ts, piToolMapping(), stripFrontmatter()]
- "fakes_enginefactoryopengl": "EngineFactoryOpenGL.h" | kind=code-symbol | source=engine/rhi/tests/fakes/EngineFactoryOpenGL.h:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Diligent(), IEngineFactory()]
- "fishcenter_fish_map_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L188 | neighbors=[fish_map.py, fit_bad(), place()]
- "fishcenter_fish_map_inside_one": "_inside_one()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L154 | neighbors=[fish_map.py, fit_bad(), _inb()]
- "fishcenter_fish_map_lp_y": "lp_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L646 | neighbors=[fish_map.py, lp(), stations()]
- "fishcenter_fish_map_rail_line": "rail_line()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L461 | neighbors=[fish_map.py, edges(), straight run a->b (x, z) with gaps [(s0…]
- "fishcenter_fish_map_spoke": "spoke()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L295 | neighbors=[fish_map.py, hardscape(), deck_rect()]
- "fishcenter_fish_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L23 | neighbors=[fish_map.py, place(), static()]
- "fishcenter_fish_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L369 | neighbors=[fish_map.py, build(), static()]
- "fishcenter_fish_props_bait_bucket": "bait_bucket()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L758 | neighbors=[fish_props.py, bait_shop(), metal bait bucket with handle, worms (r…]
- "fishcenter_fish_props_barrels": "barrels()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L562 | neighbors=[fish_props.py, barrel(), rope()]
- "fishcenter_fish_props_bench": "bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L634 | neighbors=[fish_props.py, ball(), driftwood bench: two slab seat planks o…]
- "fishcenter_fish_props_brain_coral": "brain_coral()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L468 | neighbors=[fish_props.py, aquarium_dome(), brain coral: squashed dome with wavy me…]
- "fishcenter_fish_props_cooler": "cooler()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L621 | neighbors=[fish_props.py, fish(), fish cooler: rounded box body, white li…]
- "fishcenter_fish_props_coral_branch": "coral_branch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L450 | neighbors=[fish_props.py, aquarium_dome(), staghorn coral: forking tapered branche…]
- "fishcenter_fish_props_fern": "_fern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L404 | neighbors=[fish_props.py, grass_tuft(), palm_planter()]
- "fishcenter_fish_props_grass_tuft": "grass_tuft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L440 | neighbors=[fish_props.py, _fern(), low tropical grass + fern tuft: arching…]
- "fishcenter_fish_props_hook_icon": "hook_icon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L801 | neighbors=[fish_props.py, big brass fish hook (shape icon, no tex…, rod_shop()]
- "fishcenter_fish_props_local": "local()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L215 | neighbors=[fish_props.py, crate(), woven_wall()]
- "fishcenter_fish_props_marker_buoy": "marker_buoy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L744 | neighbors=[fish_props.py, ball(), fishing-spot marker: floating striped b…]
- "fishcenter_fish_props_mat_cell": "mat_cell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L192 | neighbors=[fish_props.py, woven palm-mat infill between posts: st…, woven_wall()]
- "fishcenter_fish_props_rail_post": "rail_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L265 | neighbors=[fish_props.py, _post(), teak rail post with the signature cap: …]
- "foundation_fixed_sine_lookup": "sine_lookup()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed.hpp:L306 | neighbors=[fixed.hpp, cos(), sin()]
- "foundation_fixed_vec_dot": "dot()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L131 | neighbors=[fixed_vec.hpp, saturate_raw64(), lengthSquared()]
- "foundation_fixed_vec_isqrt_u64": "isqrt_u64()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L98 | neighbors=[fixed_vec.hpp, length(), normalized()]
- "foundation_fixed_vec_normalized": "normalized()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L160 | neighbors=[fixed_vec.hpp, isqrt_u64(), raw_length_sq()]
- "foundation_fixed_vec_raw_length_sq": "raw_length_sq()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L116 | neighbors=[fixed_vec.hpp, length(), normalized()]
- "foundation_fixed_vec_saturate_raw64": "saturate_raw64()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/fixed_vec.hpp:L91 | neighbors=[fixed_vec.hpp, dot(), length()]
- "foundation_vec3f_dot": "dot()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L56 | neighbors=[vec3f.hpp, length(), lengthSquared()]
- "foundation_vec3f_length": "length()" | kind=code-symbol | source=engine/foundation/include/poko/foundation/vec3f.hpp:L63 | neighbors=[vec3f.hpp, dot(), normalized()]
- "framegraph_frame_graph_build_plan": "build_plan()" | kind=code-symbol | source=engine/render/src/framegraph/frame_graph.cpp:L31 | neighbors=[frame_graph.cpp, compile(), execute()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-067.json

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
