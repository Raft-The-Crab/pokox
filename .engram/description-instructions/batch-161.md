# Node Description Batch 162 of 207

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

- "device_vulkan_triangle_pass_vulkandiagnostics": "VulkanDiagnostics" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_triangle_pass.hpp:L7 | neighbors=[vulkan_triangle_pass.cpp] | lang=en
- "device_vulkan_triangle_pass_vulkantrianglepass_vulkantrianglepass": ".VulkanTrianglePass()" | kind=code-symbol | source=engine/rhi/include/poko/rhi/device/vulkan_triangle_pass.hpp:L17 | neighbors=[VulkanTrianglePass()] | lang=en
- "docref_rfc_6455": "RFC-6455" | kind=entity | source=.agents/skills/superpowers-main/tests/brainstorm-server/ws-protocol.test.js:L51 | neighbors=[ws-protocol.test.js] | lang=en
- "dunedesert_dune_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L125 | neighbors=[dune_map.py] | lang=en
- "dunedesert_dune_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L588 | neighbors=[dune_map.py] | lang=en
- "dunedesert_dune_paint_remap": "remap()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_paint.py:L68 | neighbors=[dune_paint.py] | lang=en
- "dunedesert_dune_props_rationale_792": "flat disc split into rings / sectors of ~cell (atlas-friendly)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L792 | neighbors=[grid_disc()] | lang=en
- "dunedesert_dune_props_rationale_83": "battered block: base w0 x d0 at y0 -> top w1 x d1 at y1 (x / z full sizes)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L83 | neighbors=[frustum()] | lang=es
- "dunedesert_dune_props_rationale_88": "a disc on the plane facing -Z (thickness d toward -Z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_props.py:L88 | neighbors=[disc()] | lang=en
- "dunedesert_gen_trees_with_palms_arg": "arg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L17 | neighbors=[gen_trees_with_palms.py] | lang=en
- "dunedesert_gen_trees_with_palms_basis_card": "basis_card()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L541 | neighbors=[gen_trees_with_palms.py] | lang=en
- "dunedesert_gen_trees_with_palms_branch_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L332 | neighbors=[Branch] | lang=en
- "dunedesert_gen_trees_with_palms_canvas_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L116 | neighbors=[Canvas] | lang=en
- "dunedesert_gen_trees_with_palms_grade": "_grade()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1197 | neighbors=[gen_trees_with_palms.py] | lang=en
- "dunedesert_gen_trees_with_palms_lv": "LV()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L735 | neighbors=[gen_trees_with_palms.py] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_1": "Realistic alpha-card trees for Roblox (Trunk / Branches / Leaves MeshParts + Sur" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1 | neighbors=[gen_trees_with_palms.py] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_101": "fir / spruce: scaly grey-brown plates with reddish fresh bark in the cracks, fai" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L101 | neighbors=[bark_fir()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_115": "RGBA + height painter; shapes composited 'over' with soft edges." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L115 | neighbors=[Canvas] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_1204": "paint + save the texture, or (maps) load it from roblox/textures when it already" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1204 | neighbors=[_img()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_1219": "Trunk / Branches / Leaves materials for a texture style (cached per style)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1219 | neighbors=[get_materials()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_1251": "build one species into coll: [<prefix><name>_Trunk, _Branches, _Leaves] (shared" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L1251 | neighbors=[make_tree()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_132": "Tapered stroke along pts (px), clipped to the cell rect clip=(x0,x1,y0,y1)." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L132 | neighbors=[.capsule_path()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_211": "4 x 4 fir sprays: a central twig with paired laterals (frond widest near the bas" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L211 | neighbors=[needle_atlas()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_34": "Periodic (tileable) gaussian-filtered noise, fx / fy = feature frequency in cycl" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L34 | neighbors=[fft_noise()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_358": "<1 inside the lumpy crown envelope." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L358 | neighbors=[.env()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_427": "surface roots: leave the trunk foot outward and down, then snake along the groun" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L427 | neighbors=[.grow_roots()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_475": "paired side sprays in the (roughly horizontal) plane of the branch, shorter towa" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L475 | neighbors=[.laterals()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_550": "Leaf-cluster cards (folded, 4 tris) or crossed twig cards (2 x 2 tris)." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L550 | neighbors=[card_quads()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_620": "needle-spray cards along every branch / lateral: most lie in the spray plane (no" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L620 | neighbors=[conifer_cards()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_67": "t array -> colour from [(pos, (r,g,b)), ...]." | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L67 | neighbors=[ramp()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_859": "leaf-scar rings (rows) with interlocking diamond boot stubs between them, grey-b" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L859 | neighbors=[bark_palm()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_876": "4 x 4 pinnate fronds: rachis up the cell centre, ~30 leaflet pairs angled toward" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L876 | neighbors=[frond_atlas()] | lang=en
- "dunedesert_gen_trees_with_palms_rationale_907": "cells 0, 1: dry brown hanging fronds; cells 2, 3: date clusters (strands of oran" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L907 | neighbors=[palm_twig_atlas()] | lang=en
- "dunedesert_gen_trees_with_palms_tree_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/gen_trees_with_palms.py:L351 | neighbors=[Tree] | lang=en
- "dunedesert_hooks_lua_lua_attrs": "lua_attrs()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/hooks_lua.py:L4 | neighbors=[hooks_lua.py] | lang=en
- "effekseer_ai_authoring_layerbuilder_init": ".__init__()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L108 | neighbors=[LayerBuilder] | lang=en
- "effekseer_ai_authoring_layerbuilder_set": ".set()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/authoring.py:L114 | neighbors=[LayerBuilder] | lang=en
- "effekseer_ai_cli_compile": "_compile()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L118 | neighbors=[cli.py] | lang=en
- "effekseer_ai_cli_new": "_new()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L22 | neighbors=[cli.py] | lang=en
- "effekseer_ai_cli_texture_process": "_texture_process()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/effekseer_ai/cli.py:L124 | neighbors=[cli.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-161.json

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
