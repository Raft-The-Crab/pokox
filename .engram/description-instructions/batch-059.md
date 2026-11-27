# Node Description Batch 60 of 207

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

- "vfxkit_unity_tile_noise": "_tile_noise()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/unity.py:L62 | neighbors=[unity.py, _blob(), Tileable value noise in 0-1: random lat…, textures()]
- "vfxkit_video_decode": "_decode()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L44 | neighbors=[video.py, _ffmpeg(), flipbook(), timeline()]
- "vfxkit_video_first_frame": "first_frame()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L387 | neighbors=[video.py, _in_project(), _png(), Crop a generated element image on black…]
- "vfxkit_video_record": "record()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L94 | neighbors=[video.py, flipbook(), grade(), Upsert one texture's provenance into vf…]
- "vfxkit_video_report_dir": "_report_dir()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L89 | neighbors=[video.py, flipbook(), grade(), timeline()]
- "vfxkit_video_sheet": "_sheet()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/video.py:L128 | neighbors=[video.py, flipbook(), grade(), The sheet over a mid blue-grey: keyed e…]
- "vm_debugger_step": "step()" | kind=code-symbol | source=mute/src/vm/debugger.cpp:L34 | neighbors=[debugger.cpp, run(), finish(), pc()]
- "vm_values_alloc": "alloc()" | kind=code-symbol | source=mute/src/vm/values.cpp:L44 | neighbors=[values.cpp, free_slot(), make_array(), make_string()]
- "vm_values_make_string": "make_string()" | kind=code-symbol | source=mute/src/vm/values.cpp:L60 | neighbors=[values.cpp, copy_impl(), alloc(), handle_for()]
- "vm_values_release": "release()" | kind=code-symbol | source=mute/src/vm/values.cpp:L173 | neighbors=[values.cpp, copy_impl(), free_slot(), object()]
- "voidrealm_void_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L124 | neighbors=[void_map.py, bridges(), build(), stations()]
- "voidrealm_void_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L111 | neighbors=[void_map.py, bridges(), dressing(), stations()]
- "voidrealm_void_map_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L56 | neighbors=[void_map.py, H(), island(), stations()]
- "voidrealm_void_props_far_rock": "far_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L186 | neighbors=[void_props.py, FS(), shaft(), distant silhouette: a broken island chu…]
- "voidrealm_void_props_spore_pods": "spore_pods()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L374 | neighbors=[void_props.py, 3-5 bulbous magenta pods on short stems…, FS(), V()]
- "voidrealm_void_props_tendril": "tendril()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L350 | neighbors=[void_props.py, root bulb + 5 curling tendrils (taperin…, FS(), V()]
- "warehouse_fitlib_fit_bad": "fit_bad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L36 | neighbors=[fitlib.py, fit(), _inside_one(), _top()]
- "warehouse_kitlib_ibeam": "ibeam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L120 | neighbors=[kitlib.py, prism_x(), prism_z(), I / H section of length L along axis ('…]
- "warehouse_kitlib_quad": "quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L108 | neighbors=[kitlib.py, V(), quad_top(), one single-sided quad: axis 'y' = facin…]
- "warehouse_kitlib_v": "V()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L35 | neighbors=[kitlib.py, pol(), quad(), ring_tube()]
- "warehouse_wh_map_bx": "bx()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L76 | neighbors=[wh_map.py, shade(), roof(), walls()]
- "warehouse_wh_map_floors": "floors()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L158 | neighbors=[wh_map.py, mesh_obj(), shade(), concrete slab (mottled grid), saw-cut j…]
- "warehouse_wh_map_rack_row": "rack_row()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L214 | neighbors=[wh_map.py, build(), place(), bays running north from z RACK_S (yaw 9…]
- "warehouse_wh_map_shade": "shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L71 | neighbors=[wh_map.py, bx(), floors(), walls()]
- "warehouse_wh_map_walls": "walls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L81 | neighbors=[wh_map.py, bx(), mesh_obj(), shade()]
- "warehouse_wh_props_pallet_sub": "pallet_sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L11 | neighbors=[wh_props.py, pallet_load(), pallet_stack(), EUR-style pallet: top deck boards, 3 bl…]
- "warehouse_wh_props_upright_frame": "upright_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L135 | neighbors=[wh_props.py, rack_bay(), rack_end(), one rack frame: two perforated posts (z…]
- "warehouse_wh_real": "wh_real.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_real.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, light(), r2b()]
- "warehouse_wh_veh_wheel": "wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L6 | neighbors=[wh_veh.py, forklift(), pallet_jack(), tyre + rim + hub nuts, axle along x, ce…]
- "warehouse_wh_yard_axle_set": "axle_set()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L8 | neighbors=[wh_yard.py, truck_wheel(), box_trailer(), tractor_unit()]
- "warehouse_wh_yard_truck_wheel": "truck_wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L11 | neighbors=[wh_yard.py, axle_set(), truck wheel: deep-sidewall tyre with tr…, tractor_unit()]
- "whispering_grove_forest_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L177 | neighbors=[forest_map.py, build(), look(), scatter()]
- "whispering_grove_forest_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L180 | neighbors=[forest_map.py, build(), free(), keepout()]
- "whispering_grove_forest_map_segd": "segd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L43 | neighbors=[forest_map.py, build(), path_info(), stream_d()]
- "whispering_grove_forest_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L171 | neighbors=[forest_map.py, build(), terrain height range over a footprint: …, H()]
- "whispering_grove_forest_props_arch_frame": "arch_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L116 | neighbors=[forest_props.py, arch_outline(), elder_tree(), solid stone frame between the inner out…]
- "whispering_grove_forest_props_arch_prism": "arch_prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L132 | neighbors=[forest_props.py, arch_outline(), elder_tree(), closed solid of the door opening (boole…]
- "whispering_grove_forest_props_arch_tunnel": "arch_tunnel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L157 | neighbors=[forest_props.py, arch_outline(), elder_tree(), the dark passage behind the frame: wall…]
- "whispering_grove_forest_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L356 | neighbors=[forest_props.py, Prop, .add(), S()]
- "whispering_grove_forest_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L85 | neighbors=[forest_props.py, Prop, .add(), S()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-059.json

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
