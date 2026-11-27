# Node Description Batch 132 of 208

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

- "skyrise_sky_props_rationale_159": "bridge from z=0 to z=-L, rising by `rise`: planks (wood) or slabs (stone) with p" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L159 | neighbors=[Palette, bridge()] | lang=en
- "skyrise_sky_props_rationale_199": "zone gate: two banded stone pillars, arched crest with the zone gem, glowing bar" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L199 | neighbors=[Palette, zone_gate()] | lang=en
- "skyrise_sky_props_rationale_227": "egg hatch station: tiered round podium, giant spotted egg on a cushion, four cry" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L227 | neighbors=[Palette, egg_shrine()] | lang=pt
- "skyrise_sky_props_rationale_266": "upgrade booth: counter, striped awning, posts, big glowing up-arrow sign (front" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L266 | neighbors=[Palette, upgrade_stand()] | lang=en
- "skyrise_sky_props_rationale_316": "simulator puffy tree: curved trunk + 3-6 smooth round canopy balls" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L316 | neighbors=[Palette, puffy_tree()] | lang=en
- "skyrise_sky_props_rationale_356": "treasure chest, lid open (back +Z hinge), coins + a gem inside" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L356 | neighbors=[Palette, chest()] | lang=pt
- "skyrise_sky_props_rationale_40": "revolve [(r, y), ...] (bottom -> top) around Y; caps where r == 0 collapse to a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L40 | neighbors=[Palette, lathe()] | lang=es
- "skyrise_sky_props_rationale_467": "HERO: giant golden trophy on a tiered marble pedestal; cup with handles, crown +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L467 | neighbors=[Palette, trophy()] | lang=en
- "skyrise_sky_props_rationale_66": "faceted octahedron-ish gem standing on its tip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L66 | neighbors=[Palette, gem()] | lang=en
- "skyrise_sky_props_rationale_71": "underside of a floating island: rings from the rim inward/down to a tip, strata" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L71 | neighbors=[Palette, island_under()] | lang=en
- "skyrise_sky_props_snow_tree": "snow_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L410 | neighbors=[sky_props.py, lathe()] | lang=en
- "src_asset_store_assethandle": "AssetHandle()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L254 | neighbors=[asset_store.cpp, release()] | lang=en
- "src_asset_store_is_loading": "is_loading()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L195 | neighbors=[asset_store.cpp, load_state()] | lang=en
- "src_asset_store_load_state": "load_state()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L170 | neighbors=[asset_store.cpp, is_loading()] | lang=en
- "src_asset_store_release": "release()" | kind=code-symbol | source=engine/resource/src/asset_store.cpp:L257 | neighbors=[asset_store.cpp, AssetHandle()] | lang=en
- "src_camera_look_at": "look_at()" | kind=code-symbol | source=engine/render/src/camera.cpp:L22 | neighbors=[camera.cpp, view_proj()] | lang=en
- "src_camera_multiply": "multiply()" | kind=code-symbol | source=engine/render/src/camera.cpp:L40 | neighbors=[camera.cpp, view_proj()] | lang=en
- "src_camera_perspective": "perspective()" | kind=code-symbol | source=engine/render/src/camera.cpp:L11 | neighbors=[camera.cpp, view_proj()] | lang=en
- "src_cbor_half_to_double": "half_to_double()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L82 | neighbors=[cbor.cpp, decode_item()] | lang=en
- "src_cbor_read_argument": "read_argument()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L73 | neighbors=[cbor.cpp, decode_item()] | lang=en
- "src_cbor_valid_utf8": "valid_utf8()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L44 | neighbors=[cbor.cpp, decode_item()] | lang=en
- "src_character_controller_append_shape_raws": "append_shape_raws()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L96 | neighbors=[character_controller.cpp, touch_key()] | lang=en
- "src_character_controller_planar": "planar()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L29 | neighbors=[character_controller.cpp, update()] | lang=en
- "src_compose_pair": "pair()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L16 | neighbors=[compose.py, pill()] | lang=en
- "src_compose_pill": "pill()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L11 | neighbors=[compose.py, pair()] | lang=en
- "src_config_collect_unknown": "collect_unknown()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L82 | neighbors=[config.cpp, load_file()] | lang=en
- "src_config_fail": "fail()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L14 | neighbors=[config.cpp, load_file()] | lang=en
- "src_config_parse_level": "parse_level()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L70 | neighbors=[config.cpp, load_file()] | lang=en
- "src_config_resolve": "resolve()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L172 | neighbors=[config.cpp, load_file()] | lang=en
- "src_convex_shape": "convex_shape.cpp" | kind=code-symbol | source=engine/physics/src/convex_shape.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, support()] | lang=en
- "src_frame_stats_cpu_ms": "cpu_ms()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L38 | neighbors=[frame_stats.cpp, window_mean()] | lang=en
- "src_frame_stats_fps": "fps()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L31 | neighbors=[frame_stats.cpp, window_mean()] | lang=en
- "src_frame_stats_gpu_ms": "gpu_ms()" | kind=code-symbol | source=engine/foundation/src/frame_stats.cpp:L43 | neighbors=[frame_stats.cpp, window_mean()] | lang=en
- "src_gallery_flat": "flat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L37 | neighbors=[gallery.py, ground()] | lang=en
- "src_gallery_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/gallery.py:L43 | neighbors=[gallery.py, flat()] | lang=en
- "src_haze": "haze.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/haze.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "src_ktx2_fail": "fail()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L32 | neighbors=[ktx2.cpp, load_ktx2()] | lang=en
- "src_ktx2_in_bounds": "in_bounds()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L38 | neighbors=[ktx2.cpp, load_ktx2()] | lang=en
- "src_logging_critical": "critical()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L105 | neighbors=[logging.cpp, emit()] | lang=en
- "src_logging_debug": "debug()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L101 | neighbors=[logging.cpp, emit()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-131.json

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
