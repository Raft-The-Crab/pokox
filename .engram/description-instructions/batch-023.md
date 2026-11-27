# Node Description Batch 24 of 208

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

- "valleylake_valley_map_prof": "prof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L551 | neighbors=[valley_map.py, cliff_clear(), cliffs(), ground(), polar(), _prof_i()]
- "valleylake_valley_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L229 | neighbors=[valley_map.py, beach(), cliff_mesh(), ground(), paths(), sub()]
- "valleylake_valley_map_stations_and_village": "stations_and_village()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L661 | neighbors=[valley_map.py, build(), anchor(), face(), in_terr(), place()]
- "valleylake_valley_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L589 | neighbors=[valley_props.py, flat(), .add(), V(), crates(), dock()]
- "valleylake_valley_props_trunk": "trunk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L233 | neighbors=[valley_props.py, blossom_tree(), broadleaf(), gnarled_tree(), pine(), .add()]
- "vfxkit_briefs": "briefs.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, keyframes(), read(), timeline(), validate()]
- "vfxkit_cli": "cli.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/cli.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, main(), parser(), recipes_for(), run()]
- "vfxkit_evidence_build_issues": "build_issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L112 | neighbors=[evidence.py, current_recipe(), inputs(), read_build(), capture_issues(), context()]
- "vfxkit_paths": "paths.py" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, full_mode_platform(), godot(), initialized(), setup_command()]
- "vfxkit_textures_masks": "masks()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/textures.py:L32 | neighbors=[textures.py, flame_band(), spectral(), speed_streaks(), swirl(), worley()]
- "voidrealm_void_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L58 | neighbors=[void_map.py, bridges(), build_paths(), island_of(), top_y(), place()]
- "voidrealm_void_map_reserve": "reserve()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L113 | neighbors=[void_map.py, bridges(), build(), build_paths(), dressing(), ring_scatter()]
- "voidrealm_void_map_rfun": "Rfun()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L44 | neighbors=[void_map.py, dressing(), edge_pt(), island(), island_of(), ring_scatter()]
- "voidrealm_void_props_arena_rim": "arena_rim()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L571 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), V()]
- "voidrealm_void_props_brazier": "brazier()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L334 | neighbors=[void_props.py, annulus(), chamfer_box(), flame(), FS(), V()]
- "voidrealm_void_props_crystal_cluster": "crystal_cluster()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L108 | neighbors=[void_props.py, FS(), shaft(), shard_rock(), V(), heart_crystal()]
- "voidrealm_void_props_crystal_lantern": "crystal_lantern()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L306 | neighbors=[void_props.py, annulus(), chamfer_box(), FS(), shaft(), V()]
- "voidrealm_void_props_lift_pad": "lift_pad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L741 | neighbors=[void_props.py, annulus(), disc(), FS(), shaft(), V()]
- "voidrealm_void_props_shard_rock": "shard_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L98 | neighbors=[void_props.py, crystal_chips(), crystal_cluster(), float_shard(), angular obsidian chunk: hull of few poi…, rubble()]
- "voidrealm_void_props_station_dais": "station_dais()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L419 | neighbors=[void_props.py, quest_stand(), shared station base: stepped octagonal …, rift_gate(), shop_kiosk(), annulus()]
- "voidrealm_void_props_void_arch": "void_arch()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L245 | neighbors=[void_props.py, ruined gateway arch: two square piers w…, chamfer_box(), disc(), FS(), rune_glyph()]
- "warehouse_kitlib_sub": "Sub" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L45 | neighbors=[kitlib.py, a reusable sub-assembly emitted into pr…, Palette, .add(), .emit(), .gadd()]
- "whispering_grove_forest_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L151 | neighbors=[forest_map.py, build(), foot(), H(), kit(), sub()]
- "whispering_grove_forest_props_bush": "bush()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L191 | neighbors=[forest_props.py, at(), blob(), leafy(), Prop, .add()]
- "whispering_grove_forest_props_quest_board": "quest_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L419 | neighbors=[forest_props.py, at(), blob(), Prop, .add(), .gadd()]
- "work_uv_overlap": "uv_overlap.py" | kind=code-symbol | source=assets/characters/work/uv_overlap.py:L1 | neighbors=[52dbcb9 Surface graphics warnings in X1…, _cross(), find_cross_mesh_overlaps(), intersection_area(), _signed_area(), Test positive-area overlap between tria…]
- "writing_skills_render_graphs": "render-graphs.js" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, combineGraphs(), extractDotBlocks(), extractGraphBody(), main()]
- "authority_replay_ring_encode_replay": "encode_replay()" | kind=code-symbol | source=server/authority/include/poko/authority/replay_ring.hpp:L185 | neighbors=[replay_ring.hpp, cbor_bool(), cbor_head(), cbor_text(), cbor_uint(), emit_litlen()]
- "blender_character_blockout_get_collection": "get_collection()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/character_blockout.py:L74 | neighbors=[character_blockout.py, box(), build(), capsule(), link(), sphere()]
- "blender_explorer_build": "explorer_build.py" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L1 | neighbors=[build_explorer(), _fresh_col(), _mats(), Explorer character — pass 2: garments, …, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "blender_validate_scene_scene_bounds": "scene_bounds()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L28 | neighbors=[validate_scene.py, find_isolated(), find_strays(), landmarks(), World-space bounds computed from evalua…, validate()]
- "blender_validate_scene_validate": "validate()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/validate_scene.py:L128 | neighbors=[validate_scene.py, find_isolated(), find_strays(), landmarks(), scene_bounds(), tri_count()]
- "brainstorm_server_auth_test_runtests": "runTests()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L126 | neighbors=[auth.test.js, assertStartedOnExpectedPort(), cleanup(), sleep(), startServer(), waitForServer()]
- "brainstorm_server_server_test_runtests": "runTests()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L126 | neighbors=[server.test.js, assertStartedOnExpectedPort(), cleanup(), sleep(), startServer(), waitForServer()]
- "brick_abyssal_angler_brick_ix": "ix()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/abyssal_angler_brick.py:L52 | neighbors=[abyssal_angler_brick.py, cell(), front_z(), lip_cell(), side_x(), top_y()]
- "brick_kraken_post": "kraken_post.py" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/kraken_post.py:L1 | neighbors=[fit(), fx(), view(), Post pass for kraken.py (self-contained…, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "brick_props_brick_poly": "poly()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/props_brick.py:L312 | neighbors=[props_brick.py, assault_rifle(), side-profile polygon (x, y fine coords)…, scifi_pistol(), sniper(), thorn_bow()]
- "bytecode_bytecode_assemble_bytecode": "assemble_bytecode()" | kind=code-symbol | source=mute/src/bytecode/bytecode.cpp:L121 | neighbors=[bytecode.cpp, branch(), disassemble_bytecode(), long_payload(), mnemonic(), validate_bytecode()]
- "cad_skill_main_mating": "mating.py" | kind=code-symbol | source=.agents/skills/cad-skill-main/mating.py:L1 | neighbors=[check_mating(), MatingError, overlap(), Fit checks for printed parts that go to…, 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …]
- "cad_skill_main_preview_render_frame": "_render_frame()" | kind=code-symbol | source=.agents/skills/cad-skill-main/preview.py:L256 | neighbors=[preview.py, Render one frame from an existing scene…, _add_edges(), _rotation_matrix(), render_multi_view(), render_view()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-023.json

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
