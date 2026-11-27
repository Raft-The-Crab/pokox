# Node Description Batch 9 of 207

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

- "creaturelab_lab_props_ring_seg": "ring_seg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L68 | neighbors=[lab_props.py, arc_wall(), catch_ball(), entrance_canopy(), hall_trim(), lab_wing()]
- "debug_vulkan_diagnostics": "vulkan_diagnostics.cpp" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, f4a6ac4 Allowlist known validation-laye…, capture(), Impl(), messages(), since()]
- "device_opengles_clear_renderer": "opengles_clear_renderer.cpp" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), clear_and_verify(), framebuffer_is_srgb(), initialize(), initialize_impl()]
- "dunedesert_dune_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L538 | neighbors=[dune_map.py, dig_spots(), fragments(), ground(), horizon(), nature()]
- "dunedesert_dune_props_frustum": "frustum()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L82 | neighbors=[dune_props.py, obelisk(), obelisk_fallen(), pylon_gate(), quest_stele(), battered block: base w0 x d0 at y0 -> t…]
- "dunedesert_dune_props_trader_tent": "trader_tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L576 | neighbors=[dune_props.py, SHOP: caravan trader's tent: 6 poles, a…, crate(), jar(), lerp(), peg_rope()]
- "dunedesert_dune_props_uvsphere": "uvsphere()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L522 | neighbors=[dune_props.py, camel(), colossus_head(), rug_spread(), sack(), sand_drift()]
- "dunedesert_gen_trees_with_palms_make_tree": "make_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1250 | neighbors=[gen_trees_with_palms.py, main(), get_materials(), make_object(), palm_meshes(), _PalmTree]
- "fishcenter_fish_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L694 | neighbors=[fish_map.py, edges(), ground(), hardscape(), horizon(), islet_grass()]
- "fishcenter_fish_map_pos": "pos()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L34 | neighbors=[fish_map.py, build(), compass(), horizon(), islet_e(), islet_grass()]
- "fishcenter_fish_props_rope": "rope()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L65 | neighbors=[fish_props.py, bait_shop(), barrels(), drying_rack(), fish_market(), hammock_palms()]
- "frostpeak_frost_props": "frost_props.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/frostpeak/frost_props.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, bench(), cabin(), fishing_hut(), frost_spire()]
- "lexer_lexer": "lexer.cpp" | kind=code-symbol | source=mute/src/lexer/lexer.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, decode(), digit(), digit_for(), is_continue(), is_start()]
- "medievalbattle_battle_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_map.py:L89 | neighbors=[battle_map.py, base(), channels(), isle_y(), keep_w(), road_d()]
- "medievalbattle_battle_props_merge": "merge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L235 | neighbors=[battle_props.py, bridge_tower(), broken_cart(), buttress(), crate(), donjon()]
- "medievalbattle_battle_props_tower_body": "tower_body()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L292 | neighbors=[battle_props.py, gatehouse(), round tower: battered base, ashlar drum…, round_tower(), ash_sh(), ashlar_ring()]
- "medievalbattle_battle_props_tower_face": "tower_face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L625 | neighbors=[battle_props.py, bridge_tower(), one face of the bridge tower in canonic…, ash_sh(), ashlar(), corbels()]
- "medievalbattle_battle_props_trebuchet": "trebuchet()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/medievalbattle/battle_props.py:L968 | neighbors=[battle_props.py, counterweight trebuchet, cocked (throws…, bar(), frame_to(), lathe(), lerp()]
- "moonclean_moon_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_map.py:L399 | neighbors=[moon_map.py, mess=True (low dust / junk / meteor pie…, free(), near_riser(), on_ramp(), place()]
- "moonclean_moon_props_beam": "beam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/moonclean/moon_props.py:L72 | neighbors=[moon_props.py, comms_dish(), dust_exchange(), floodlight(), launch_tower(), lunar_lander()]
- "oaktrees_gen_trees_canvas": "Canvas" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/oaktrees/gen_trees.py:L114 | neighbors=[gen_trees.py, .capsule_path(), .finish(), .grid(), .__init__(), .leaf()]
- "onsenvillage_onsen_map_place": "place()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/onsenvillage/onsen_map.py:L90 | neighbors=[onsen_map.py, mirror(), nature(), add_owner(), fit(), kit()]
- "opencode_test_skill_registration": "test-skill-registration.mjs" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/opencode/test-skill-registration.mjs:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, added, failures, fixtureRoot, frontmatterFixtures]
- "passes_imgui_demo": "imgui_demo.cpp" | kind=code-symbol | source=engine/render/src/passes/imgui_demo.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Exception, build_demo_window(), composite(), ensure_gpu_timer(), feed_imgui_event()]
- "petsim_pet_map_candy": "candy()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L496 | neighbors=[pet_map.py, build(), breakables(), fence_ring(), free(), path_d()]
- "petsim_pet_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L51 | neighbors=[pet_map.py, breakables(), egg_stand(), fence_ring(), isle_at(), top_y()]
- "petsim_pet_map_meadow": "meadow()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L474 | neighbors=[pet_map.py, build(), breakables(), fence_ring(), free(), path_d()]
- "petsim_pet_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/petsim/pet_map.py:L329 | neighbors=[pet_map.py, candy(), crystal(), hub(), meadow(), items = [(key, fn, scale_range)], n tri…]
- "plusspeed_plus_map_blk": "blk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/plusspeed/plus_map.py:L19 | neighbors=[plus_map.py, grp(), finish(), floor(), hub(), kerb_x()]
- "scripts_bind_mesh": "bind_mesh.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-character-rigging/scripts/bind_mesh.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, cleanup(), _ctx(), _heat_scale(), _height()]
- "scripts_blocks_block": "Block" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/scripts/blocks.py:L15 | neighbors=[v4 stadium hub: striped infield inside …, stepped canyon: tier n is a row of 24-w…, race kerb along Z: alternating colour/w…, running-track oval: red lane band, whit…, put theme props on cap tops (centre of …, blocks.py]
- "scripts_garment": "garment.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-clothing/scripts/garment.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _drape(), _hide_body(), penetration(), _region()]
- "scripts_qa_check": "qa_check.py" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-asset-qa/scripts/qa_check.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, _feeds(), _islands(), _material_issues(), _mesh_world()]
- "scripts_surface_weather_g": "_G" | kind=code-symbol | source=.agents/skills/blender-skills-main/skills/blender-weather-fx/scripts/surface_weather.py:L31 | neighbors=[surface_weather.py, build_group(), .__init__(), .link(), .math(), .mix()]
- "skyrise_sky_map_build": "build()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_map.py:L199 | neighbors=[sky_map.py, face(), island_mesh(), micro_detail(), path_track(), place()]
- "skyrise_sky_props_lathe": "lathe()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/skyrise/sky_props.py:L39 | neighbors=[sky_props.py, cactus(), crystal_node(), egg_shrine(), gem(), ice_spike()]
- "src_logging": "logging.cpp" | kind=code-symbol | source=engine/foundation/src/logging.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, critical(), debug(), emit(), error(), info()]
- "src_soft_body": "soft_body.cpp" | kind=code-symbol | source=engine/physics/src/soft_body.cpp:L1 | neighbors=[69287a0 Land ENG-60-65 deterministic si…, add_node(), add_spring(), apply_acceleration(), clamp01(), collide_plane_y()]
- "stdlib_stdlib_string": "stdlib_string.cpp" | kind=code-symbol | source=mute/src/stdlib/stdlib_string.cpp:L1 | neighbors=[952997e Audit MUT-01-55 and harden veri…, byte_length(), codepoint_count(), compare_bytes(), concat(), decode()]
- "sugarworks_sugar_props_torus": "torus()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/sugarworks/sugar_props.py:L44 | neighbors=[sugar_props.py, buy_button(), cash_pad(), choc_fountain(), coin_chute(), collector()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-008.json

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
