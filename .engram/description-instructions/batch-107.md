# Node Description Batch 108 of 208

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
Write every description in English (en). Do not switch languages.
No marketing language.
Respond ONLY with a JSON object mapping each node id (as a string) to its
one-sentence description — no prose, no markdown fences.

- "device_vulkan_clear_renderer_clear_and_present": "clear_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L123 | neighbors=[vulkan_clear_renderer.cpp, draw_and_present()]
- "device_vulkan_clear_renderer_impl": "Impl()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L50 | neighbors=[vulkan_clear_renderer.cpp, shutdown()]
- "device_vulkan_clear_renderer_shutdown_checked": "shutdown_checked()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L186 | neighbors=[vulkan_clear_renderer.cpp, shutdown()]
- "device_vulkan_clear_renderer_vulkanclearrenderer": "VulkanClearRenderer()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L65 | neighbors=[vulkan_clear_renderer.cpp, .VulkanClearRenderer()]
- "device_vulkan_imgui_pass_vulkanimguipass": "VulkanImGuiPass()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_imgui_pass.cpp:L338 | neighbors=[vulkan_imgui_pass.cpp, .VulkanImGuiPass()]
- "device_vulkan_mesh_pass_draw": "draw()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L238 | neighbors=[vulkan_mesh_pass.cpp, draw_and_present()]
- "device_vulkan_mesh_pass_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L230 | neighbors=[vulkan_mesh_pass.cpp, draw()]
- "device_vulkan_mesh_pass_vulkanmeshpass": "VulkanMeshPass()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_mesh_pass.cpp:L192 | neighbors=[vulkan_mesh_pass.cpp, .VulkanMeshPass()]
- "device_vulkan_triangle_pass_draw": "draw()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L212 | neighbors=[vulkan_triangle_pass.cpp, draw_and_present()]
- "device_vulkan_triangle_pass_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L200 | neighbors=[vulkan_triangle_pass.cpp, draw()]
- "device_vulkan_triangle_pass_set_texture": "set_texture()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L216 | neighbors=[vulkan_triangle_pass.cpp, set_texture_mips()]
- "device_vulkan_triangle_pass_set_texture_mips": "set_texture_mips()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L221 | neighbors=[vulkan_triangle_pass.cpp, set_texture()]
- "device_vulkan_triangle_pass_vulkantrianglepass": "VulkanTrianglePass()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_triangle_pass.cpp:L197 | neighbors=[vulkan_triangle_pass.cpp, .VulkanTrianglePass()]
- "dunedesert_dune_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L222 | neighbors=[dune_map.py, _inside_one()]
- "dunedesert_dune_map_inside": "inside()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L192 | neighbors=[dune_map.py, clip_fail()]
- "dunedesert_dune_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L116 | neighbors=[dune_map.py, place()]
- "dunedesert_dune_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L546 | neighbors=[dune_map.py, free()]
- "dunedesert_dune_map_rationale_134": "auto-grounded hard props (y None) are fitted: raised / nudged until the exporter" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L134 | neighbors=[place(), MB]
- "dunedesert_dune_map_rationale_164": "foliage: deferred, placed last against a BVH of every solid (the exporter's hard" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L164 | neighbors=[soft(), MB]
- "dunedesert_dune_map_rationale_250": "raise the prop in 0.25 steps (its base stays bedded), then try nearby spots; Non" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L250 | neighbors=[fit(), MB]
- "dunedesert_dune_map_rationale_302": "distant tiered mesas + buttes far outside the frame ring (cheap prisms, rust str" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L302 | neighbors=[horizon(), MB]
- "dunedesert_dune_map_rationale_323": "worn flagstone slabs over the city + the avenue, missing where the sand has drif" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L323 | neighbors=[paving(), MB]
- "dunedesert_dune_map_rationale_449": "path markers every ~30 studs along each sand path, alternating sides" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L449 | neighbors=[waystones(), MB]
- "dunedesert_dune_map_rationale_520": "half-buried relics of the old kingdom between the points of interest: broken col" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L520 | neighbors=[fragments(), MB]
- "dunedesert_dune_map_rationale_59": "transverse dunes (crests ~N-S, wind from the west): gentle windward rise, steepe" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L59 | neighbors=[dunes(), MB]
- "dunedesert_dune_map_rationale_69": "frame: high dune ridges on a ring r ~430-560 round the city, lower beyond so the" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L69 | neighbors=[ring(), MB]
- "dunedesert_dune_map_rationale_75": "temple-local (lx across the trench, lz along it: -Z toward the city, facade at 0" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L75 | neighbors=[T_local(), MB]
- "dunedesert_dune_map_rationale_79": "ONE height function for the ground mesh and all placement" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L79 | neighbors=[H(), MB]
- "dunedesert_dune_map_seg_d": "_seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L52 | neighbors=[dune_map.py, pl_d()]
- "dunedesert_dune_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L160 | neighbors=[dune_map.py, place_soft()]
- "dunedesert_dune_map_world": "world()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L172 | neighbors=[dune_map.py, set_pieces()]
- "dunedesert_dune_paint_hex": "_hex()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L21 | neighbors=[dune_paint.py, paint_block()]
- "dunedesert_dune_paint_paint_block": "paint_block()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L24 | neighbors=[dune_paint.py, _hex()]
- "dunedesert_dune_props_rationale_1041": "HERO / DUNGEON PORTAL: a columned temple front sunk 12 studs into the dunes, rea" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L1041 | neighbors=[sunken_temple(), Palette]
- "dunedesert_dune_props_rationale_106": "raised zigzag band between two rails (centre c, length L along local x, facing -" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L106 | neighbors=[zig_band(), Palette]
- "dunedesert_dune_props_rationale_115": "wall of REAL bevelled blocks through the wall, running bond, broken top prof(x);" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L115 | neighbors=[block_wall(), Palette]
- "dunedesert_dune_props_rationale_130": "SHARED BASE: stepped sandstone plinth, a chamfered course per step, gold trim li" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L130 | neighbors=[plinth(), Palette]
- "dunedesert_dune_props_rationale_138": "square base + torus, drummed 10-sided shaft with entasis, flared bell capital +" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L138 | neighbors=[column(), Palette]
- "dunedesert_dune_props_rationale_170": "HERO: six-tier gilded step pyramid (ashlar faces, cornice lips, sun + chevron re" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L170 | neighbors=[step_pyramid(), Palette]
- "dunedesert_dune_props_rationale_237": "processional pylon gateway: two battered towers built in courses (each course a" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L237 | neighbors=[pylon_gate(), Palette]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-107.json

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
