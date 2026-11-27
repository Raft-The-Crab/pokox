# Node Description Batch 130 of 207

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "skyrise_sky_props_rationale_66": "faceted octahedron-ish gem standing on its tip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L66 | neighbors=[Palette, gem()]
- "skyrise_sky_props_rationale_71": "underside of a floating island: rings from the rim inward/down to a tip, strata" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L71 | neighbors=[Palette, island_under()]
- "skyrise_sky_props_snow_tree": "snow_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L410 | neighbors=[sky_props.py, lathe()]
- "src_asset_store_assethandle": "AssetHandle()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L254 | neighbors=[asset_store.cpp, release()]
- "src_asset_store_is_loading": "is_loading()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L195 | neighbors=[asset_store.cpp, load_state()]
- "src_asset_store_load_state": "load_state()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L170 | neighbors=[asset_store.cpp, is_loading()]
- "src_asset_store_release": "release()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L257 | neighbors=[asset_store.cpp, AssetHandle()]
- "src_camera_look_at": "look_at()" | kind=code-symbol | source=engine/render/src/camera.cpp:L22 | neighbors=[camera.cpp, view_proj()]
- "src_camera_multiply": "multiply()" | kind=code-symbol | source=engine/render/src/camera.cpp:L40 | neighbors=[camera.cpp, view_proj()]
- "src_camera_perspective": "perspective()" | kind=code-symbol | source=engine/render/src/camera.cpp:L11 | neighbors=[camera.cpp, view_proj()]
- "src_cbor_half_to_double": "half_to_double()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L82 | neighbors=[cbor.cpp, decode_item()]
- "src_cbor_read_argument": "read_argument()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L73 | neighbors=[cbor.cpp, decode_item()]
- "src_cbor_valid_utf8": "valid_utf8()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L44 | neighbors=[cbor.cpp, decode_item()]
- "src_character_controller_append_shape_raws": "append_shape_raws()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L96 | neighbors=[character_controller.cpp, touch_key()]
- "src_character_controller_planar": "planar()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L29 | neighbors=[character_controller.cpp, update()]
- "src_compose_pair": "pair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L16 | neighbors=[compose.py, pill()]
- "src_compose_pill": "pill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L11 | neighbors=[compose.py, pair()]
- "src_config_collect_unknown": "collect_unknown()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L82 | neighbors=[config.cpp, load_file()]
- "src_config_fail": "fail()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L14 | neighbors=[config.cpp, load_file()]
- "src_config_parse_level": "parse_level()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L70 | neighbors=[config.cpp, load_file()]
- "src_config_resolve": "resolve()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L172 | neighbors=[config.cpp, load_file()]
- "src_convex_shape": "convex_shape.cpp" | kind=code-symbol | source=engine/physics/src/convex_shape.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, support()]
- "src_frame_stats_cpu_ms": "cpu_ms()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L38 | neighbors=[frame_stats.cpp, window_mean()]
- "src_frame_stats_fps": "fps()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L31 | neighbors=[frame_stats.cpp, window_mean()]
- "src_frame_stats_gpu_ms": "gpu_ms()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L43 | neighbors=[frame_stats.cpp, window_mean()]
- "src_gallery_flat": "flat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L37 | neighbors=[gallery.py, ground()]
- "src_gallery_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L43 | neighbors=[gallery.py, flat()]
- "src_haze": "haze.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/haze.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "src_ktx2_fail": "fail()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L32 | neighbors=[ktx2.cpp, load_ktx2()]
- "src_ktx2_in_bounds": "in_bounds()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L38 | neighbors=[ktx2.cpp, load_ktx2()]
- "src_logging_critical": "critical()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L105 | neighbors=[logging.cpp, emit()]
- "src_logging_debug": "debug()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L101 | neighbors=[logging.cpp, emit()]
- "src_logging_error": "error()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L104 | neighbors=[logging.cpp, emit()]
- "src_logging_info": "info()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L102 | neighbors=[logging.cpp, emit()]
- "src_logging_init": "init()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L66 | neighbors=[logging.cpp, to_spdlog()]
- "src_logging_trace": "trace()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L100 | neighbors=[logging.cpp, emit()]
- "src_logging_warn": "warn()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L103 | neighbors=[logging.cpp, emit()]
- "src_loop_alpha": "alpha()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L55 | neighbors=[loop.cpp, valid_limits()]
- "src_loop_fixedsteploop": "FixedStepLoop()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L18 | neighbors=[loop.cpp, to_ns()]
- "src_main": "main.cpp" | kind=code-symbol | source=engine/foundation/src/main.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, main()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-129.json

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
