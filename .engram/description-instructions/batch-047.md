# Node Description Batch 48 of 208

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

- "creaturelab_lab_props_shell": "_shell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1811 | neighbors=[lab_props.py, catch_ball(), one thick shell -> (outer, inner): oute…, lerp()]
- "creaturelab_lab_props_sliding_doors": "sliding_doors()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L990 | neighbors=[lab_props.py, automatic sliding doors for the south e…, rbox(), .add()]
- "creaturelab_lab_props_snake_plant": "snake_plant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1436 | neighbors=[lab_props.py, tall snake plant: square pot, 11 uprigh…, rbox(), .add()]
- "creaturelab_lab_props_sphere_decal": "sphere_decal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1801 | neighbors=[lab_props.py, catch_ball(), a raised inlay that hugs a sphere of ra…, _dense()]
- "creaturelab_lab_props_tree": "tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1038 | neighbors=[lab_props.py, rounded park tree: flared birch trunk s…, leaf_ball(), .add()]
- "creaturelab_lab_props_wait_bench": "wait_bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L320 | neighbors=[lab_props.py, waiting bench: steel loop legs, cushion…, rbox(), .add()]
- "creaturelab_lab_props_water_cooler": "water_cooler()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1765 | neighbors=[lab_props.py, water cooler: white cabinet with a sky …, rbox(), .add()]
- "creaturelab_lab_props_whiteboard": "whiteboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L691 | neighbors=[lab_props.py, rolling whiteboard: two T legs on caste…, rbox(), .add()]
- "debug_vulkan_diagnostics_since": "since()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L19 | neighbors=[vulkan_diagnostics.cpp, messages(), totals(), stop()]
- "device_opengles_clear_renderer_initialize_impl": "initialize_impl()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L49 | neighbors=[opengles_clear_renderer.cpp, initialize(), shutdown(), initialize_window()]
- "device_opengles_clear_renderer_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L149 | neighbors=[opengles_clear_renderer.cpp, initialize_impl(), OpenGLClearESRenderer(), shutdown_checked()]
- "device_poko_jni_write_line": "write_line()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L34 | neighbors=[poko_jni.cpp, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, run_probe()]
- "device_vulkan_clear_android_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L331 | neighbors=[vulkan_clear_android.cpp, initialize(), shutdown_checked(), VulkanClearAndroidRenderer()]
- "device_vulkan_clear_renderer_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L185 | neighbors=[vulkan_clear_renderer.cpp, Impl(), initialize(), shutdown_checked()]
- "dunedesert_dune_map_add_owner": "add_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L215 | neighbors=[dune_map.py, free(), place(), static()]
- "dunedesert_dune_map_fit": "fit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L249 | neighbors=[dune_map.py, fit_bad(), place(), raise the prop in 0.25 steps (its base …]
- "dunedesert_dune_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L276 | neighbors=[dune_map.py, build(), H(), static()]
- "dunedesert_dune_map_on_path": "on_path()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L108 | neighbors=[dune_map.py, fragments(), nature(), pl_d()]
- "dunedesert_dune_map_pl_d": "pl_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L56 | neighbors=[dune_map.py, H(), on_path(), _seg_d()]
- "dunedesert_dune_map_ring": "ring()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L68 | neighbors=[dune_map.py, H(), nature(), frame: high dune ridges on a ring r ~43…]
- "dunedesert_dune_props_crate": "crate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L550 | neighbors=[dune_props.py, cargo_pile(), plank crate: bevelled body with plank g…, trader_tent()]
- "dunedesert_dune_props_outcrop": "outcrop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L858 | neighbors=[dune_props.py, lerp(), V(), sandstone outcrop: two or three wind-cu…]
- "dunedesert_dune_props_rug_spread": "rug_spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L703 | neighbors=[dune_props.py, rest corner: a big patterned rug (borde…, uvsphere(), V()]
- "dunedesert_dune_props_ruin_wall": "ruin_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L284 | neighbors=[dune_props.py, broken wall of real bevelled blocks wit…, block_wall(), sun_relief()]
- "dunedesert_dune_props_sand_drift": "sand_drift()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L897 | neighbors=[dune_props.py, smooth sand drift banked against ruins …, uvsphere(), V()]
- "dunedesert_dune_props_spawn_dais": "spawn_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L435 | neighbors=[dune_props.py, spawn: round three-step sandstone dais …, disc(), frustum()]
- "dunedesert_dune_props_sun_astrolabe": "sun_astrolabe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L488 | neighbors=[dune_props.py, UPGRADE station: octagonal stepped plin…, frustum(), sun_relief()]
- "dunedesert_dune_props_waystone": "waystone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L422 | neighbors=[dune_props.py, path marker: weathered standing stone w…, frustum(), sun_relief()]
- "dunedesert_gen_trees_with_palms_bark_birch": "bark_birch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L86 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp()]
- "dunedesert_gen_trees_with_palms_bark_oak": "bark_oak()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L71 | neighbors=[gen_trees_with_palms.py, fft_noise(), normal_from_height(), ramp()]
- "dunedesert_gen_trees_with_palms_canvas_leaf": ".leaf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L153 | neighbors=[Canvas, .grid(), .over(), leaf_atlas()]
- "dunedesert_gen_trees_with_palms_contact_sheet": "contact_sheet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1152 | neighbors=[gen_trees_with_palms.py, load_px(), resize(), main()]
- "dunedesert_gen_trees_with_palms_img": "_img()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1203 | neighbors=[gen_trees_with_palms.py, get_materials(), save_png(), paint + save the texture, or (maps) loa…]
- "dunedesert_gen_trees_with_palms_tree_env": ".env()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L357 | neighbors=[card_quads(), <1 inside the lumpy crown envelope., Tree, .children_of()]
- "effekseer_ai_authoring_code": "_code()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L37 | neighbors=[authoring.py, _number(), .bind(), validate_layer()]
- "effekseer_ai_authoring_layerbuilder_color": ".color()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L133 | neighbors=[LayerBuilder, .advanced(), .rand(), .scalar()]
- "effekseer_ai_authoring_layerbuilder_rand": ".rand()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L124 | neighbors=[LayerBuilder, .color(), .uv(), .vector()]
- "effekseer_ai_authoring_layerbuilder_vector": ".vector()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L129 | neighbors=[LayerBuilder, .advanced(), .rand(), .scalar()]
- "effekseer_ai_authoring_number": "_number()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L33 | neighbors=[authoring.py, _code(), .bind(), _term()]
- "effekseer_ai_authoring_term": "_term()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L34 | neighbors=[authoring.py, A bind component: a number, an equation…, _number(), validate_layer()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-047.json

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
