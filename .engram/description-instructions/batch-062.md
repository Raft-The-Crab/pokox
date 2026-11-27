# Node Description Batch 63 of 209

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

- "vm_values_make_string": "make_string()" | kind=code-symbol | source=mute/src/vm/values.cpp:L60 | neighbors=[values.cpp, copy_impl(), alloc(), handle_for()] | lang=en
- "vm_values_release": "release()" | kind=code-symbol | source=mute/src/vm/values.cpp:L173 | neighbors=[values.cpp, copy_impl(), free_slot(), object()] | lang=en
- "voidrealm_void_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L124 | neighbors=[void_map.py, bridges(), build(), stations()] | lang=en
- "voidrealm_void_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L111 | neighbors=[void_map.py, bridges(), dressing(), stations()] | lang=en
- "voidrealm_void_map_top_y": "top_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_map.py:L56 | neighbors=[void_map.py, H(), island(), stations()] | lang=en
- "voidrealm_void_props_far_rock": "far_rock()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L186 | neighbors=[void_props.py, FS(), shaft(), distant silhouette: a broken island chu…] | lang=en
- "voidrealm_void_props_spore_pods": "spore_pods()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L374 | neighbors=[void_props.py, 3-5 bulbous magenta pods on short stems…, FS(), V()] | lang=en
- "voidrealm_void_props_tendril": "tendril()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/voidrealm/void_props.py:L350 | neighbors=[void_props.py, root bulb + 5 curling tendrils (taperin…, FS(), V()] | lang=en
- "warehouse_fitlib_fit_bad": "fit_bad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/fitlib.py:L36 | neighbors=[fitlib.py, fit(), _inside_one(), _top()] | lang=en
- "warehouse_kitlib_ibeam": "ibeam()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L120 | neighbors=[kitlib.py, prism_x(), prism_z(), I / H section of length L along axis ('…] | lang=en
- "warehouse_kitlib_quad": "quad()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L108 | neighbors=[kitlib.py, V(), quad_top(), one single-sided quad: axis 'y' = facin…] | lang=en
- "warehouse_kitlib_v": "V()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/kitlib.py:L35 | neighbors=[kitlib.py, pol(), quad(), ring_tube()] | lang=en
- "warehouse_wh_map_bx": "bx()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L76 | neighbors=[wh_map.py, shade(), roof(), walls()] | lang=en
- "warehouse_wh_map_floors": "floors()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L158 | neighbors=[wh_map.py, mesh_obj(), shade(), concrete slab (mottled grid), saw-cut j…] | lang=en
- "warehouse_wh_map_rack_row": "rack_row()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L214 | neighbors=[wh_map.py, build(), place(), bays running north from z RACK_S (yaw 9…] | lang=en
- "warehouse_wh_map_shade": "shade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L71 | neighbors=[wh_map.py, bx(), floors(), walls()] | lang=en
- "warehouse_wh_map_walls": "walls()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_map.py:L81 | neighbors=[wh_map.py, bx(), mesh_obj(), shade()] | lang=en
- "warehouse_wh_props_pallet_sub": "pallet_sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L11 | neighbors=[wh_props.py, pallet_load(), pallet_stack(), EUR-style pallet: top deck boards, 3 bl…] | lang=en
- "warehouse_wh_props_upright_frame": "upright_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_props.py:L135 | neighbors=[wh_props.py, rack_bay(), rack_end(), one rack frame: two perforated posts (z…] | lang=en
- "warehouse_wh_real": "wh_real.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_real.py:L1 | neighbors=[2680d0e Pushed an update., e77fa31 Add new skills and asset packs …, light(), r2b()] | lang=en
- "warehouse_wh_veh_wheel": "wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_veh.py:L6 | neighbors=[wh_veh.py, forklift(), pallet_jack(), tyre + rim + hub nuts, axle along x, ce…] | lang=en
- "warehouse_wh_yard_axle_set": "axle_set()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L8 | neighbors=[wh_yard.py, truck_wheel(), box_trailer(), tractor_unit()] | lang=en
- "warehouse_wh_yard_truck_wheel": "truck_wheel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/warehouse/wh_yard.py:L11 | neighbors=[wh_yard.py, axle_set(), truck wheel: deep-sidewall tyre with tr…, tractor_unit()] | lang=en
- "whispering_grove_forest_map_free": "free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L177 | neighbors=[forest_map.py, build(), look(), scatter()] | lang=en
- "whispering_grove_forest_map_scatter": "scatter()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L180 | neighbors=[forest_map.py, build(), free(), keepout()] | lang=en
- "whispering_grove_forest_map_segd": "segd()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L43 | neighbors=[forest_map.py, build(), path_info(), stream_d()] | lang=en
- "whispering_grove_forest_map_spread": "spread()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_map.py:L171 | neighbors=[forest_map.py, build(), terrain height range over a footprint: …, H()] | lang=en
- "whispering_grove_forest_props_arch_frame": "arch_frame()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L116 | neighbors=[forest_props.py, arch_outline(), elder_tree(), solid stone frame between the inner out…] | lang=en
- "whispering_grove_forest_props_arch_prism": "arch_prism()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L132 | neighbors=[forest_props.py, arch_outline(), elder_tree(), closed solid of the door opening (boole…] | lang=en
- "whispering_grove_forest_props_arch_tunnel": "arch_tunnel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L157 | neighbors=[forest_props.py, arch_outline(), elder_tree(), the dark passage behind the frame: wall…] | lang=en
- "whispering_grove_forest_props_barrel": "barrel()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L356 | neighbors=[forest_props.py, Prop, .add(), S()] | lang=en
- "whispering_grove_forest_props_pine": "pine()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L85 | neighbors=[forest_props.py, Prop, .add(), S()] | lang=en
- "whispering_grove_forest_props_rationale_111": "door outline in the XY plane, open at the bottom: left foot -> up -> semicircle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L111 | neighbors=[MB, Palette, Sh, arch_outline()] | lang=en
- "whispering_grove_forest_props_rationale_117": "solid stone frame between the inner outline and one t wider, extruded z0..z1 (z1" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L117 | neighbors=[MB, Palette, Sh, arch_frame()] | lang=en
- "whispering_grove_forest_props_rationale_158": "the dark passage behind the frame: walls + floor only, faces pointing inward" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L158 | neighbors=[MB, Palette, Sh, arch_tunnel()] | lang=en
- "whispering_grove_forest_props_rationale_206": "one modelled fern frond: a serrated, thickened strip arching up then down" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L206 | neighbors=[MB, Palette, Sh, frond()] | lang=pt
- "whispering_grove_forest_props_rationale_35": "one kit prop: a solid mesh on the palette + optional glow meshes (Neon in Roblox" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L35 | neighbors=[MB, Palette, Sh, Prop] | lang=en
- "whispering_grove_forest_props_rationale_413": "a licking flame: a tapering tube that sways and twists to a point" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L413 | neighbors=[MB, Palette, Sh, flame_tongue()] | lang=en
- "whispering_grove_forest_props_rationale_642": "kit meshes: <Prop> (solid) + <Prop>_Glow_<key>. Origin = bottom centre (prop bui" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L642 | neighbors=[MB, Palette, Sh, to_kit()] | lang=en
- "whispering_grove_forest_props_stump": "stump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L283 | neighbors=[forest_props.py, Prop, .add(), S()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-062.json

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
