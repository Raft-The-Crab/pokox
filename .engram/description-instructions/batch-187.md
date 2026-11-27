# Node Description Batch 188 of 209

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

- "skyrise_sky_models4_pebbles": "pebbles()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L32 | neighbors=[sky_models4.py]
- "skyrise_sky_models4_rationale_10": "one grass blade: thin tapered wedge (4 verts, 4 tris) leaning outward, tip bent" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L10 | neighbors=[blade()]
- "skyrise_sky_models4_rationale_114": "bridge from z=0 to z=-L rising by `rise`.     wood: irregular planks with nail h" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L114 | neighbors=[bridge()]
- "skyrise_sky_models4_rationale_182": "low tiered fountain: octagonal stone basin with a lip, water surface, gold trim," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L182 | neighbors=[plaza_fountain()]
- "skyrise_sky_models4_rationale_24": "modelled blade cluster, dark at the root, light at the tips" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L24 | neighbors=[grass_tuft()]
- "skyrise_sky_models4_rationale_41": "small flower clump: stems + 5-petal star heads + gold centres, one or two colour" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L41 | neighbors=[wildflowers()]
- "skyrise_sky_models4_rationale_52": "two or three toadstools: lathe stems, red caps with white spots" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L52 | neighbors=[mushrooms()]
- "skyrise_sky_models4_rationale_69": "twiggy desert shrub: forked twigs from a root knot" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L69 | neighbors=[dry_shrub()]
- "skyrise_sky_models4_snow_mound": "snow_mound()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models4.py:L80 | neighbors=[sky_models4.py]
- "skyrise_sky_props_basalt_rocks": "basalt_rocks()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L419 | neighbors=[sky_props.py]
- "skyrise_sky_props_charred_tree": "charred_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L439 | neighbors=[sky_props.py]
- "skyrise_sky_props_lava_pool": "lava_pool()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L428 | neighbors=[sky_props.py]
- "skyrise_sky_props_leaderboard": "leaderboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L294 | neighbors=[sky_props.py]
- "skyrise_sky_props_mesa_rock": "mesa_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L392 | neighbors=[sky_props.py]
- "skyrise_sky_props_path_stone": "path_stone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L152 | neighbors=[sky_props.py]
- "skyrise_sky_props_rationale_250": "sell station: glowing pad with a giant coin on a stand behind it (front -Z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L250 | neighbors=[sell_pad()]
- "skyrise_sky_props_rationale_509": "glowing zig-zag crack in the ground (flat, walk-over)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L509 | neighbors=[lava_crack()]
- "skyrise_sky_props_signpost": "signpost()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L457 | neighbors=[sky_props.py]
- "src_asset_store_acquire": "acquire()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L199 | neighbors=[asset_store.cpp]
- "src_asset_store_assetstore": "AssetStore()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L95 | neighbors=[asset_store.cpp]
- "src_asset_store_key": "key()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L304 | neighbors=[asset_store.cpp]
- "src_asset_store_last_error": "last_error()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L189 | neighbors=[asset_store.cpp]
- "src_asset_store_load_count": "load_count()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L103 | neighbors=[asset_store.cpp]
- "src_asset_store_payload": "payload()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L306 | neighbors=[asset_store.cpp]
- "src_asset_store_poll_async": "poll_async()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L139 | neighbors=[asset_store.cpp]
- "src_asset_store_request_async": "request_async()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L106 | neighbors=[asset_store.cpp]
- "src_asset_store_resident_count": "resident_count()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L100 | neighbors=[asset_store.cpp]
- "src_asset_store_state": "State()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L46 | neighbors=[asset_store.cpp]
- "src_asset_store_unload_count": "unload_count()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L104 | neighbors=[asset_store.cpp]
- "src_camera_orbit": "orbit()" | kind=code-symbol | source=engine/render/src/camera.cpp:L52 | neighbors=[camera.cpp]
- "src_camera_zoom": "zoom()" | kind=code-symbol | source=engine/render/src/camera.cpp:L56 | neighbors=[camera.cpp]
- "src_compose_axes": "axes()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L72 | neighbors=[compose.py]
- "src_convex_shape_support": "support()" | kind=code-symbol | source=engine/physics/src/convex_shape.cpp:L5 | neighbors=[convex_shape.cpp]
- "src_frame_stats_record_cpu": "record_cpu()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L16 | neighbors=[frame_stats.cpp]
- "src_frame_stats_record_gpu": "record_gpu()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L24 | neighbors=[frame_stats.cpp]
- "src_gallery_drum": "drum()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L54 | neighbors=[gallery.py]
- "src_gallery_put": "put()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L29 | neighbors=[gallery.py]
- "src_gallery_ring_gate": "ring_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L94 | neighbors=[gallery.py]
- "src_gallery_scene_reset": "scene_reset()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L15 | neighbors=[gallery.py]
- "src_gallery_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L46 | neighbors=[gallery.py]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-187.json

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
