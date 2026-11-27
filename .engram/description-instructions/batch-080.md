# Node Description Batch 81 of 208

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

- "scripts_uv_pack_collapsed_ratio": "_collapsed_ratio()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L38 | neighbors=[uv_pack.py, Fraction of faces whose UV area is ~0 (…, run()]
- "scripts_uv_pack_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-retopology-uv/scripts/uv_pack.py:L49 | neighbors=[uv_pack.py, _collapsed_ratio(), _seams_from_sharp()]
- "scripts_vse_edit_add_clip": "_add_clip()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L43 | neighbors=[vse_edit.py, _frames(), run()]
- "scripts_vse_edit_frames": "_frames()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L31 | neighbors=[vse_edit.py, _add_clip(), Sorted frame files for a folder or a # …]
- "scripts_vse_edit_run": "run()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-video-editing/scripts/vse_edit.py:L84 | neighbors=[vse_edit.py, _add_clip(), _output()]
- "semantic_emit_br16": "br16()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L22 | neighbors=[emit.cpp, mk(), emit_bytecode()]
- "semantic_emit_br32": "br32()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L28 | neighbors=[emit.cpp, mk(), emit_bytecode()]
- "semantic_emit_mov": "mov()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L20 | neighbors=[emit.cpp, emit_bytecode(), mk()]
- "semantic_lower_convert_type": "convert_type()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L17 | neighbors=[lower.cpp, unit_t(), lower_module()]
- "semantic_lower_lower_function_ex": "lower_function_ex()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L523 | neighbors=[lower.cpp, lower_function(), lower_module()]
- "semantic_lower_unit_t": "unit_t()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L11 | neighbors=[lower.cpp, convert_type(), lower_module()]
- "semantic_optimize_eliminate_dead_code": "eliminate_dead_code()" | kind=code-symbol | source=mute/src/semantic/optimize.cpp:L15 | neighbors=[optimize.cpp, is_pure(), is_terminator()]
- "semantic_semantic_numeric": "numeric()" | kind=code-symbol | source=mute/src/semantic/semantic.cpp:L57 | neighbors=[semantic.cpp, is_float_scalar(), is_integer_scalar()]
- "shared_bpyx_argv": "argv()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L19 | neighbors=[_bpyx.py, cli(), Arguments after '--' (Blender ignores t…]
- "shared_bpyx_emit": "emit()" | kind=code-symbol | source=.agents/skills/blender-skills-main/shared/_bpyx.py:L35 | neighbors=[_bpyx.py, cli(), Print compact JSON on one marked line (…]
- "skyrise_sky_kit_sheet": "sky_kit_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_kit_sheet.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, shot()]
- "skyrise_sky_map_bridge_ends": "bridge_ends()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L55 | neighbors=[sky_map.py, H(), rim()]
- "skyrise_sky_map_ext": "ext()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L114 | neighbors=[sky_map.py, micro_detail(), widest horizontal reach of a kit prop (…]
- "skyrise_sky_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L71 | neighbors=[sky_map.py, micro_detail(), place()]
- "skyrise_sky_models_island_under": "island_under()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L109 | neighbors=[sky_models.py, lumpy(), underside: 16 rings to a rough tip, noi…]
- "skyrise_sky_models_zone_gate": "zone_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models.py:L202 | neighbors=[sky_models.py, carved stone gate: stepped plinths, oct…, bevel_box()]
- "skyrise_sky_models2_cactus": "cactus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L112 | neighbors=[sky_models2.py, _ribbed(), ribbed saguaro: star-section body, two …]
- "skyrise_sky_models2_chest": "chest()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L39 | neighbors=[sky_models2.py, coin(), planked chest, curved lid held open, ir…]
- "skyrise_sky_models2_coin_pile": "coin_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L22 | neighbors=[sky_models2.py, coin(), a heap built only from coins (rings of …]
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

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-080.json

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
