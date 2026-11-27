# Node Description Batch 39 of 207

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

- "scripts_pro_lib_out_g": ".g()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L368 | neighbors=[Out, .add(), hexrgb(), MB, .gadd()]
- "scripts_pro_lib_sh_call": ".__call__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/pro_lib.py:L72 | neighbors=[Sh, clamp(), lerp(), nz(), .u()]
- "scripts_retarget_parts": "_parts()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-animation/scripts/retarget.py:L56 | neighbors=[retarget.py, auto_map(), _split(), {(part, side): bone}, plus the spine ch…, run()]
- "scripts_review_shots": "review_shots.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/review_shots.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _bounds(), run(), Render a multi-angle review contact she…]
- "scripts_rig_check": "rig_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/rig_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _mirror(), run(), Validate a skeleton + its skinned meshe…]
- "scripts_roblox_export_big_part": "big_part()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L302 | neighbors=[roblox_export.py, clean_name(), palette_rgb(), r_pos(), low-poly oversize mesh (sea plane, skir…]
- "scripts_roblox_export_material_split": "material_split()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_export.py:L164 | neighbors=[roblox_export.py, export(), _face_rgb(), newobj(), materials mode: split every palette (so…]
- "scripts_roblox_materials_preview": "preview()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/roblox_materials.py:L76 | neighbors=[roblox_materials.py, column_of(), resolve(), _variant(), give every palette mesh one Blender mat…]
- "scripts_run_in_blender": "run_in_blender.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-core/scripts/run_in_blender.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, find_blender(), main(), _ver()]
- "scripts_scanner_identify_semantic_files": "_identify_semantic_files()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/scanner.py:L158 | neighbors=[scanner.py, get_scanner_config(), get_supported_extensions(), perform_scan(), Maps files to semantic categories based…]
- "scripts_scene_audit": "scene_audit.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-scene-setup/scripts/scene_audit.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _apply_rot_scale(), run(), Audit scene hygiene: units, transforms,…]
- "scripts_studlib_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L55 | neighbors=[studlib.py, lin(), limb(), span(), spike()]
- "scripts_studlib_emit": "_emit()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L88 | neighbors=[studlib.py, cyl(), lin(), add a custom solid (local unit coords) …, wedge()]
- "scripts_studlib_span": "span()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/scripts/studlib.py:L129 | neighbors=[studlib.py, Box by ranges: easy to make neighbours …, box(), stack(), sym()]
- "scripts_surface_weather_g_noise": ".noise()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L70 | neighbors=[build_group(), _G, .n(), _snow_tree(), _vertex_mask()]
- "scripts_template_engine_get_nested_val": "get_nested_val()" | kind=code-symbol | source=.agents/skills/skills-main/play/play-policy-insights/scripts/template_engine.py:L27 | neighbors=[template_engine.py, .render(), .render(), Resolves nested dot-notation keys from …, .render()]
- "scripts_toon_setup_g_link": ".link()" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-stylized-npr/scripts/toon_setup.py:L39 | neighbors=[build_group(), _G, .set(), _key_light(), _line_art()]
- "semantic_emit_mk": "mk()" | kind=code-symbol | source=mute/src/semantic/emit.cpp:L19 | neighbors=[emit.cpp, br16(), br32(), emit_bytecode(), mov()]
- "semantic_fold_fold_constants": "fold_constants()" | kind=code-symbol | source=mute/src/semantic/fold.cpp:L57 | neighbors=[fold.cpp, eval_binary(), eval_compare(), eval_unary(), int_scalar()]
- "semantic_lower_lower_module": "lower_module()" | kind=code-symbol | source=mute/src/semantic/lower.cpp:L534 | neighbors=[lower.cpp, convert_type(), lower_function_ex(), requires_mask(), unit_t()]
- "skyrise_sky_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L110 | neighbors=[sky_map.py, build(), spawn_island(), summit(), zone_island()]
- "skyrise_sky_map_hm": "Hm()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L85 | neighbors=[sky_map.py, H(), place(), height of the built island top MESH (wh…, spread()]
- "skyrise_sky_map_path_track": "path_track()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L315 | neighbors=[sky_map.py, build(), H(), sub(), trodden track under the stepping stones…]
- "skyrise_sky_map_sky_dressing": "sky_dressing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L367 | neighbors=[sky_map.py, build(), island_at(), on_bridge_line(), place()]
- "skyrise_sky_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L18 | neighbors=[sky_map.py, island_mesh(), path_track(), paving(), place()]
- "skyrise_sky_models2_coin": "coin()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_models2.py:L8 | neighbors=[sky_models2.py, chest(), coin_pile(), coin with a raised rim (lathe), lying f…, sell_pad()]
- "skyrise_sky_props_egg_shrine": "egg_shrine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L226 | neighbors=[sky_props.py, gem(), lathe(), torus(), egg hatch station: tiered round podium,…]
- "src_character_controller_cast_fraction": "cast_fraction()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L164 | neighbors=[character_controller.cpp, length_of(), touches(), translated(), update()]
- "src_character_controller_touches": "touches()" | kind=code-symbol | source=engine/physics/src/character_controller.cpp:L126 | neighbors=[character_controller.cpp, cast_fraction(), touch_key(), touches_uncached(), update()]
- "src_compose": "compose.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/references/images/src/compose.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, axes(), pair(), pill()]
- "src_config_find_key": "find_key()" | kind=code-symbol | source=engine/foundation/src/config.cpp:L21 | neighbors=[config.cpp, load_file(), read_bool(), read_text(), read_u32()]
- "src_narrowphase_gjk_distance": "gjk_distance()" | kind=code-symbol | source=engine/physics/src/narrowphase.cpp:L219 | neighbors=[narrowphase.cpp, collide_local(), centroid(), closest_on_hull(), cso_support()]
- "src_sap_broadphase": "sap_broadphase.cpp" | kind=code-symbol | source=engine/physics/src/sap_broadphase.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, clear(), commit(), insert(), remove()]
- "src_vfx_dark_vortex": "VFX_Dark_Vortex.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Dark_Vortex.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Dark_Vortex: Dark impact played whe…]
- "src_vfx_fire_explosion": "VFX_Fire_Explosion.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Fire_Explosion.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Fire_Explosion: Fire impact played …]
- "src_vfx_heal": "VFX_Heal.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Heal.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Heal: Heal on the caster: no impact…]
- "src_vfx_hit_heavy": "VFX_Hit_Heavy.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Hit_Heavy.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Hit_Heavy: Heavy melee hit: the blo…]
- "src_vfx_ice_spikes": "VFX_Ice_Spikes.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Ice_Spikes.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Ice_Spikes: Ground ice eruption pla…]
- "src_vfx_kaiju_atomic_beam": "VFX_Kaiju_Atomic_Beam.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Beam.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Kaiju_Atomic_Beam: a sustained atom…]
- "src_vfx_kaiju_atomic_charge": "VFX_Kaiju_Atomic_Charge.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/assets/examples/src/VFX_Kaiju_Atomic_Charge.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, recipe(), primitives.py, VFX_Kaiju_Atomic_Charge: dorsal plates …]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-038.json

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
