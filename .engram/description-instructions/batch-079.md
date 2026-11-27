# Node Description Batch 80 of 207

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

- "skyrise_sky_models2_ribbed": "_ribbed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L97 | neighbors=[sky_models2.py, cactus(), 12-point star section swept along a str…]
- "skyrise_sky_props_bridge": "bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L158 | neighbors=[sky_props.py, sphere(), bridge from z=0 to z=-L, rising by `ris…]
- "skyrise_sky_props_cactus": "cactus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L379 | neighbors=[sky_props.py, lathe(), sphere()]
- "skyrise_sky_props_coin_pile": "coin_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L340 | neighbors=[sky_props.py, gem(), sphere()]
- "skyrise_sky_props_floating_rock": "floating_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L132 | neighbors=[sky_props.py, sphere(), small decorative sky rock: grass cap, r…]
- "skyrise_sky_props_flower_bed": "flower_bed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L329 | neighbors=[sky_props.py, sphere(), torus()]
- "skyrise_sky_props_puffy_tree": "puffy_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L315 | neighbors=[sky_props.py, sphere(), simulator puffy tree: curved trunk + 3-…]
- "skyrise_sky_props_sell_pad": "sell_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L249 | neighbors=[sky_props.py, sell station: glowing pad with a giant …, torus()]
- "skyrise_sky_props_spawn_pad": "spawn_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L498 | neighbors=[sky_props.py, lathe(), torus()]
- "skyrise_sky_props_teleport_pad": "teleport_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L282 | neighbors=[sky_props.py, gem(), torus()]
- "skyrise_sky_props_upgrade_stand": "upgrade_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L265 | neighbors=[sky_props.py, upgrade booth: counter, striped awning,…, gem()]
- "src_cbor_decode": "decode()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L196 | neighbors=[cbor.cpp, decode_item(), fail()]
- "src_cbor_fail": "fail()" | kind=code-symbol | source=engine/foundation/src/cbor.cpp:L68 | neighbors=[cbor.cpp, decode(), decode_item()]
- "src_character_controller_capsule_at": "capsule_at()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L144 | neighbors=[character_controller.cpp, resolve(), update()]
- "src_character_controller_length_of": "length_of()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L33 | neighbors=[character_controller.cpp, cast_fraction(), resolve()]
- "src_character_controller_resolve": "resolve()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L350 | neighbors=[character_controller.cpp, capsule_at(), length_of()]
- "src_character_controller_touch_key": "touch_key()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L107 | neighbors=[character_controller.cpp, append_shape_raws(), touches()]
- "src_character_controller_translated": "translated()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L37 | neighbors=[character_controller.cpp, cast_fraction(), update()]
- "src_config_read_bool": "read_bool()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L44 | neighbors=[config.cpp, load_file(), find_key()]
- "src_config_read_text": "read_text()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L57 | neighbors=[config.cpp, load_file(), find_key()]
- "src_config_read_u32": "read_u32()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L32 | neighbors=[config.cpp, load_file(), find_key()]
- "src_ktx2_load_ktx2": "load_ktx2()" | kind=code-symbol | source=engine/resource/src/ktx2.cpp:L43 | neighbors=[ktx2.cpp, fail(), in_bounds()]
- "src_logging_to_spdlog": "to_spdlog()" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L22 | neighbors=[logging.cpp, emit(), init()]
- "src_loop_advance": "advance()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L30 | neighbors=[loop.cpp, to_ns(), valid_limits()]
- "src_loop_to_ns": "to_ns()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L15 | neighbors=[loop.cpp, advance(), FixedStepLoop()]
- "src_loop_valid_limits": "valid_limits()" | kind=code-symbol | source=engine/foundation/src/loop.cpp:L24 | neighbors=[loop.cpp, advance(), alpha()]
- "src_narrowphase_closest_segment": "closest_segment()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L72 | neighbors=[narrowphase.cpp, closest_on_hull(), closest_triangle()]
- "src_narrowphase_cso_support": "cso_support()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L51 | neighbors=[narrowphase.cpp, epa_penetration(), gjk_distance()]
- "src_narrowphase_dist_sq_of": "dist_sq_of()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L69 | neighbors=[narrowphase.cpp, closest_on_hull(), closest_triangle()]
- "src_narrowphase_face_normal": "face_normal()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L285 | neighbors=[narrowphase.cpp, epa_penetration(), orient_out()]
- "src_narrowphase_orient_out": "orient_out()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L291 | neighbors=[narrowphase.cpp, epa_penetration(), face_normal()]
- "src_narrowphase_origin_in_tetra": "origin_in_tetra()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L139 | neighbors=[narrowphase.cpp, closest_on_hull(), epa_penetration()]
- "src_narrowphase_saturate_raw": "saturate_raw()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L647 | neighbors=[narrowphase.cpp, to_world(), widen_raw()]
- "src_narrowphase_to_world": "to_world()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L659 | neighbors=[narrowphase.cpp, collide(), saturate_raw()]
- "src_narrowphase_widen_raw": "widen_raw()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L655 | neighbors=[narrowphase.cpp, collide(), saturate_raw()]
- "src_pokomesh_fail": "fail()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L21 | neighbors=[pokomesh.cpp, load_pokomesh(), parse_pokomesh()]
- "src_pokomesh_load_pokomesh": "load_pokomesh()" | kind=code-symbol | source=engine/resource/src/pokomesh.cpp:L95 | neighbors=[pokomesh.cpp, fail(), parse_pokomesh()]
- "src_sap_broadphase_commit": "commit()" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L15 | neighbors=[sap_broadphase.cpp, clear(), insert()]
- "src_soft_body_add_node": "add_node()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L72 | neighbors=[soft_body.cpp, create(), create_lattice()]
- "src_soft_body_clamp01": "clamp01()" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L13 | neighbors=[soft_body.cpp, add_spring(), step()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-079.json

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
