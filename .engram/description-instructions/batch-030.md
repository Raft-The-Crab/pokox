# Node Description Batch 31 of 207

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

- "valleylake_valley_map_lake_d": "lake_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L53 | neighbors=[valley_map.py, H0(), lake_R(), nature(), preview_water(), signed distance-ish to the shore (negat…]
- "valleylake_valley_map_lake_r": "lake_R()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L47 | neighbors=[valley_map.py, lake_d(), lake_poly(), nature(), shore radius around LAKE_C by angle (th…, shore()]
- "valleylake_valley_map_rim_point": "rim_point()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L427 | neighbors=[valley_map.py, build_profile(), cliff_mesh(), cliffs(), point on the rim superellipse at angle …, rim_r()]
- "valleylake_valley_map_rim_r": "rim_r()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L424 | neighbors=[valley_map.py, build_profile(), cliffs(), foot_need(), polar(), rim_point()]
- "valleylake_valley_map_water": "water()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L345 | neighbors=[valley_map.py, build(), lake = fan disc a little past the shore…, lake_poly(), static(), wlevel()]
- "valleylake_valley_props_footing": "footing()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L492 | neighbors=[valley_props.py, rounded_mass(), .add(), V(), house(), rounded fieldstone footing course under…]
- "valleylake_valley_props_gable_roof": "gable_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L406 | neighbors=[valley_props.py, .add(), V(), house(), market_stall(), straight gable roof (ridge along X): tw…]
- "valleylake_valley_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L264 | neighbors=[valley_props.py, .add(), trunk(), V(), soft full conifer: tapered skinned trun…, tall stylised pine: straight trunk, 8 t…]
- "valleylake_valley_props_skel_grow": ".grow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L869 | neighbors=[broadleaf(), gnarled_tree(), limb from node `parent` along d (curvin…, Skel, lerp(), .add()]
- "valleylake_valley_props_timber_wall": "timber_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L457 | neighbors=[valley_props.py, house(), wall in XY facing -Z: dark timber posts…, flat(), quad(), .add()]
- "vfxkit_build_check_resource_conflicts": "check_resource_conflicts()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L71 | neighbors=[build.py, build(), eid(), owned(), resource_names(), Refuse to replace a resources/ file wit…]
- "vfxkit_doctor": "doctor.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/doctor.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, doctor(), setup_python(), version(), What this machine can do right now. Sta…]
- "vfxkit_evidence_verify": "verify()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L251 | neighbors=[evidence.py, build_issues(), capture_issues(), current_recipe(), latest(), store()]
- "vfxkit_primitives_fade": "fade()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L18 | neighbors=[primitives.py, beam(), decay(), shock_ring(), smoke(), wisps()]
- "vfxkit_primitives_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L161 | neighbors=[primitives.py, beam(), billow(), flame(), Colour over life as a gradient: ramp((0…, shell_fragments()]
- "vfxkit_primitives_tex": "tex()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L14 | neighbors=[primitives.py, mesh(), orbit_band(), slash_arc(), sprite(), wisps()]
- "vfxkit_scaffold": "scaffold.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scaffold.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, download(), initialize(), toolchain_lock(), Create or refresh the project's vfx/ wo…]
- "vfxkit_scale_map": "_map()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/scale.py:L56 | neighbors=[scale.py, _frames(), _life(), Apply f to a number, a [min, max] range…, _space(), _time()]
- "vfxkit_sequence_handoff": "handoff()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L309 | neighbors=[sequence.py, criteria(), _frame_number(), issues(), latest(), read()]
- "vfxkit_sequence_issues": "issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L296 | neighbors=[sequence.py, handoff(), path(), read(), recipe_hashes(), submit()]
- "vfxkit_sequence_latest": "latest()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L289 | neighbors=[sequence.py, concept_compare(), handoff(), sequence_id(), store(), paintover()]
- "vfxkit_sequence_validate": "validate()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/sequence.py:L76 | neighbors=[sequence.py, capture(), Structure, effects, stage gate, referen…, gate_path(), length(), read()]
- "vfxkit_texture_audit": "texture_audit.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/texture_audit.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, audit(), cell_report(), content(), Pixel observations grouped by texture r…]
- "vfxkit_textures_spectral": "spectral()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L14 | neighbors=[textures.py, flame_band(), masks(), procedural(), Seamlessly tileable 1/f noise in 0..1; …, swirl()]
- "vfxkit_video_resolve_output": "_resolve_output()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L68 | neighbors=[video.py, flipbook(), grade(), Bare names land in vfx/textures/process…, _in_project(), _png()]
- "vm_scheduler": "scheduler.cpp" | kind=code-symbol | source=mute/src/vm/scheduler.cpp:L1 | neighbors=[435b4d3 Add MUT-23 cooperative async sc…, cancel(), find(), run(), spawn(), state()]
- "vm_values_copy_impl": "copy_impl()" | kind=code-symbol | source=mute/src/vm/values.cpp:L142 | neighbors=[values.cpp, copy(), make_array(), make_string(), object(), release()]
- "vm_values_free_slot": "free_slot()" | kind=code-symbol | source=mute/src/vm/values.cpp:L23 | neighbors=[values.cpp, alloc(), object(), release(), reset_tick(), set_index()]
- "vm_values_set_index": "set_index()" | kind=code-symbol | source=mute/src/vm/values.cpp:L105 | neighbors=[values.cpp, free_slot(), make_int(), object(), promote(), reaches()]
- "vm_vm_core": "vm_core.hpp" | kind=code-symbol | source=mute/src/vm/vm_core.hpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, DepthGuard(), fail(), result(), step(), VmCore]
- "voidrealm_void_map_island": "island()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L133 | neighbors=[void_map.py, build(), keel_profile(), Rfun(), static(), top_y()]
- "voidrealm_void_map_ring_scatter": "ring_scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L322 | neighbors=[void_map.py, dressing(), free(), place(), reserve(), Rfun()]
- "voidrealm_void_map_void_debris": "void_debris()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L427 | neighbors=[void_map.py, build(), intentional floaters: chips drifting ne…, island_of(), place(), seg_d()]
- "voidrealm_void_props_crystal_chips": "crystal_chips()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L396 | neighbors=[void_props.py, FS(), shaft(), shard_rock(), V(), ground cover: a low obsidian chip with …]
- "voidrealm_void_props_float_shard": "float_shard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L161 | neighbors=[void_props.py, FS(), shaft(), shard_rock(), V(), broken-off island chip: a crust slab wi…]
- "voidrealm_void_props_pillar": "pillar()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L209 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), V(), fluted void-stone column: stepped plint…]
- "voidrealm_void_props_rune_bridge": "rune_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L690 | neighbors=[void_props.py, rune bridge built along -Z from z=+L/2 …, chamfer_box(), FS(), shaft(), V()]
- "voidrealm_void_props_rune_circle": "rune_circle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L290 | neighbors=[void_props.py, flat ceremonial circle: pale trim ring …, annulus(), disc(), FS(), spawn_dais()]
- "voidrealm_void_props_rune_glyph": "rune_glyph()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L198 | neighbors=[void_props.py, abstract rune inlay (never a letter): d…, rift_gate(), annulus(), shop_kiosk(), void_arch()]
- "voidrealm_void_props_sign_plate": "sign_plate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L428 | neighbors=[void_props.py, quest_stand(), blank sign board for a GUI label (no te…, shop_kiosk(), chamfer_box(), FS()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-030.json

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
