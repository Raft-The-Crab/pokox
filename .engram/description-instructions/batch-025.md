# Node Description Batch 26 of 207

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

- "creaturelab_lab_props_swap_icon": "swap_icon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L470 | neighbors=[lab_props.py, two curved arrows chasing each other in…, lerp(), .add(), upright(), trade_desk()]
- "creaturelab_lab_props_trophy_shelf": "trophy_shelf()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1673 | neighbors=[lab_props.py, Trade story: wall trophy shelf (two bir…, capsule(), rbox(), .add(), upright()]
- "creaturelab_lab_props_vending_machine": "vending_machine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1165 | neighbors=[lab_props.py, berry-juice vending machine: rounded wh…, bottle(), emblem(), rbox(), .add()]
- "creaturelab_lab_props_wall_capsules": "wall_capsules()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1749 | neighbors=[lab_props.py, wall-mounted capsule display: rounded w…, capsule(), emblem(), rbox(), .add()]
- "creaturelab_lab_props_wing_roof": "wing_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L947 | neighbors=[lab_props.py, lab wing roof (no collision; hide it fo…, rbox(), ring_seg(), .add(), upright()]
- "creaturelab_lab_props_workbench": "workbench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L636 | neighbors=[lab_props.py, lab workbench: table + test-tube rack w…, ball(), lab_table(), rbox(), .add()]
- "device_clear_backend_selection": "clear_backend_selection.cpp" | kind=code-symbol | source=engine/rhi/src/device/clear_backend_selection.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), ClearBackend, ClearBackendSelection(), shutdown(), start()]
- "device_fallback_clear_backends": "fallback_clear_backends.cpp" | kind=code-symbol | source=engine/rhi/src/device/fallback_clear_backends.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, clear_and_present(), initialize(), OpenGLClearBackend, shutdown(), VulkanClearBackend]
- "device_poko_jni": "poko_jni.cpp" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L1 | neighbors=[c7a411f Fix MUT-01-20 audit defects in …, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, run_probe(), write_line()]
- "dunedesert_dune_map_place_soft": "place_soft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L263 | neighbors=[dune_map.py, build(), build_solid(), clip_fail(), place(), unplace()]
- "dunedesert_dune_map_static": "static()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L168 | neighbors=[dune_map.py, ground(), horizon(), paving(), add_owner(), sub()]
- "dunedesert_dune_props_cargo_pile": "cargo_pile()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L744 | neighbors=[dune_props.py, crate(), jar(), rolled_rug(), sack(), caravan cargo: crates stacked, sacks, r…]
- "dunedesert_dune_props_obelisk": "obelisk()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L380 | neighbors=[dune_props.py, frustum(), merge_into(), plinth(), _shaft(), standing obelisk on the stepped plinth:…]
- "dunedesert_dune_props_obelisk_fallen": "obelisk_fallen()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L389 | neighbors=[dune_props.py, frustum(), lerp(), merge_into(), _shaft(), toppled obelisk piece lying on its side…]
- "dunedesert_dune_props_pylon_gate": "pylon_gate()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L236 | neighbors=[dune_props.py, frustum(), lerp(), sun_relief(), zig_band(), processional pylon gateway: two battere…]
- "dunedesert_dune_props_sleep_tent": "sleep_tent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L632 | neighbors=[dune_props.py, A-frame nomad tent: ridge pole on two f…, lerp(), peg_rope(), rolled_rug(), sheet()]
- "dunedesert_gen_trees_with_palms_branch": "Branch" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L331 | neighbors=[gen_trees_with_palms.py, .at(), .__init__(), .length(), .grow(), .grow_roots()]
- "dunedesert_gen_trees_with_palms_card_quads": "card_quads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L549 | neighbors=[gen_trees_with_palms.py, .at(), .length(), rand_unit(), .env(), Leaf-cluster cards (folded, 4 tris) or …]
- "dunedesert_gen_trees_with_palms_leaf_atlas": "leaf_atlas()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L270 | neighbors=[gen_trees_with_palms.py, Canvas, .capsule_path(), .finish(), .leaf(), fft_noise()]
- "dunedesert_gen_trees_with_palms_main": "main()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1271 | neighbors=[gen_trees_with_palms.py, contact_sheet(), export_glb(), make_tree(), render_turntable(), setup_scene()]
- "dunedesert_gen_trees_with_palms_normal_from_height": "normal_from_height()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L42 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), .finish()]
- "dunedesert_gen_trees_with_palms_ramp": "ramp()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L66 | neighbors=[gen_trees_with_palms.py, bark_birch(), bark_fir(), bark_oak(), bark_palm(), t array -> colour from [(pos, (r,g,b)),…]
- "dunedesert_gen_trees_with_palms_tree_children_of": ".children_of()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L380 | neighbors=[Tree, .build(), .at(), .length(), .env(), .grow()]
- "dunedesert_gen_trees_with_palms_tree_laterals": ".laterals()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L474 | neighbors=[paired side sprays in the (roughly hori…, Tree, .build_conifer(), .at(), .length(), .grow()]
- "effekseer_ai_authoring_layerbuilder_bind": ".bind()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L153 | neighbors=[LayerBuilder, _code(), .scalar(), _number(), .layer(), Fixed position/scale that a dynamic equ…]
- "effekseer_ai_authoring_layerbuilder_scalar": ".scalar()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L123 | neighbors=[LayerBuilder, .bind(), .color(), .curve(), .uv(), .vector()]
- "effekseer_ai_authoring_layerbuilder_uv": ".uv()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L142 | neighbors=[LayerBuilder, .advanced(), .layer(), .rand(), .scalar(), Bind a texture slot and optionally scro…]
- "effekseer_ai_session_effectsession_object_at_path": "._object_at_path()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/session.py:L348 | neighbors=[EffectSession, .curve_keys(), .curve_set_keys(), .import_image(), .import_model(), ._property_parent()]
- "eggplots_egg_map_spawn_area": "spawn_area()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_map.py:L276 | neighbors=[egg_map.py, build(), anchor(), place(), reserve(), to_world()]
- "eggplots_egg_props_egg_drain": "egg_drain()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L647 | neighbors=[egg_props.py, egg_profile(), post(), rbox(), sh(), the drain at the south end: a low woven…]
- "eggplots_egg_props_foot_bridge": "foot_bridge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L496 | neighbors=[egg_props.py, egg_profile(), lerp(), rbox(), sh(), humped plank footbridge over the belt (…]
- "eggplots_egg_props_sell_stand": "sell_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L748 | neighbors=[egg_props.py, Sell stand: orange / cream awning, a ba…, egg(), rbox(), sh(), stall()]
- "eggplots_egg_props_upgrade_stand": "upgrade_stand()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/eggplots/egg_props.py:L722 | neighbors=[egg_props.py, Upgrades stand: teal / cream awning, a …, egg(), rbox(), sh(), stall()]
- "fishcenter_fish_map_h": "H()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L66 | neighbors=[fish_map.py, H_raw(), islet_grass(), nature(), piling(), seabed / islets; out at the world edge …]
- "fishcenter_fish_map_horizon": "horizon()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L409 | neighbors=[fish_map.py, build(), pos(), static(), tangent(), tropical volcanic islands in 3 overlapp…]
- "fishcenter_fish_map_islet_e": "islet_e()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L54 | neighbors=[fish_map.py, H_raw(), outward(), pos(), tangent(), <= 1 inside an islet's ellipse (smalles…]
- "fishcenter_fish_map_sh_val": "sh_val()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L213 | neighbors=[fish_map.py, beam(), compass(), deck_rect(), platform(), ring_deck()]
- "fishcenter_fish_map_tangent": "tangent()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_map.py:L36 | neighbors=[fish_map.py, horizon(), islet_e(), islet_grass(), lp(), nature()]
- "fishcenter_fish_props_drying_rack": "drying_rack()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L730 | neighbors=[fish_props.py, fish(), lash(), pole(), rope(), fish drying rack: two bamboo A-frames, …]
- "fishcenter_fish_props_loft": "loft()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/fishcenter/fish_props.py:L73 | neighbors=[fish_props.py, awning(), bait_shop(), hammock_palms(), quads between successive rings (lists o…, thatch_band()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-025.json

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
