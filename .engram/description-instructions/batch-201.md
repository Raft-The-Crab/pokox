# Node Description Batch 202 of 209

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

- "unit_vulkan_clear_faults_sdl_quitsubsystem": "SDL_QuitSubSystem()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_clear_faults.cpp:L59 | neighbors=[vulkan_clear_faults.cpp]
- "unit_vulkan_diagnostics_filter_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_diagnostics_filter_test.cpp:L5 | neighbors=[vulkan_diagnostics_filter_test.cpp]
- "unit_vulkan_mesh_pass_test_draw_and_present": "draw_and_present()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L18 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_main": "main()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L23 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_messages": "messages()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L14 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_vulkanclearrenderer": "VulkanClearRenderer()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L16 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_mesh_pass_test_vulkandiagnostics": "VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_mesh_pass_test.cpp:L12 | neighbors=[vulkan_mesh_pass_test.cpp]
- "unit_vulkan_triangle_pass_test_messages": "messages()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L14 | neighbors=[vulkan_triangle_pass_test.cpp]
- "unit_vulkan_triangle_pass_test_vulkanclearrenderer": "VulkanClearRenderer()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L16 | neighbors=[vulkan_triangle_pass_test.cpp]
- "unit_vulkan_triangle_pass_test_vulkandiagnostics": "VulkanDiagnostics()" | kind=code-symbol | source=engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp:L12 | neighbors=[vulkan_triangle_pass_test.cpp]
- "unit_worker_auth_test_fake_rsa_verify": "fake_rsa_verify()" | kind=code-symbol | source=server/identity/tests/unit/worker_auth_test.cpp:L24 | neighbors=[worker_auth_test.cpp]
- "unit_ws_transport_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/ws_transport_test.cpp:L15 | neighbors=[ws_transport_test.cpp]
- "unit_xor_fec_test_main": "main()" | kind=code-symbol | source=server/net/tests/unit/xor_fec_test.cpp:L12 | neighbors=[xor_fec_test.cpp]
- "valleylake_paint_rationale_112": "palette UVs (u column, v shade) -> atlas UVs, in place on an MB (Roblox-space ve" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L112 | neighbors=[remap()]
- "valleylake_paint_rationale_132": "patch the grove machinery: atlas instead of the strip, UV remap in mesh_from" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L132 | neighbors=[install()]
- "valleylake_paint_rationale_22": "periodic FFT noise in [-1, 1]; aniso > 1 stretches features along x (brush strok" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L22 | neighbors=[fnoise()]
- "valleylake_paint_rationale_31": "leaf / dab stamps: (value field, rim-highlight field) both periodic, rotated poi" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L31 | neighbors=[stamps()]
- "valleylake_paint_rationale_96": "the 1024 px atlas image for a pro_lib Palette (column order = pal.names)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/paint.py:L96 | neighbors=[atlas()]
- "valleylake_valley_map_rationale_428": "point on the rim superellipse at angle th (+ extra studs outward)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L428 | neighbors=[rim_point()]
- "valleylake_valley_map_rationale_54": "signed distance-ish to the shore (negative = in the water)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L54 | neighbors=[lake_d()]
- "valleylake_valley_map_rationale_559": "True if no cliff rises above y (default: the floor) within r + CLEAR of (x, z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L559 | neighbors=[cliff_clear()]
- "valleylake_valley_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L955 | neighbors=[valley_map.py]
- "valleylake_valley_map_write_materials": "write_materials()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_map.py:L951 | neighbors=[valley_map.py]
- "valleylake_valley_props_rationale_348": "blade clump: thin bent blades fanning out (no alpha cards)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L348 | neighbors=[grass_tuft()]
- "valleylake_valley_props_rationale_451": "flat rectangle in XY facing -Z (lattice ribs: only ever seen from the front)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L451 | neighbors=[quad()]
- "valleylake_valley_props_rationale_506": "veranda deck along a wall (z = wall line, side -1 = in front, -Z)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L506 | neighbors=[engawa()]
- "valleylake_valley_props_rationale_821": "rounded stepping stones across the stream (small, flat-topped, moss edges)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L821 | neighbors=[rock_steps()]
- "valleylake_valley_props_skel_init": ".__init__()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L864 | neighbors=[Skel]
- "valueerror": "ValueError" | kind=code-symbol | neighbors=[GridfinityError]
- "vfxkit_briefs_keyframes": "keyframes()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L114 | neighbors=[briefs.py]
- "vfxkit_briefs_rationale_1": "Design briefs (vfx/briefs/<ID>.json) live outside the strict Effekseer layer sch" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L1 | neighbors=[briefs.py]
- "vfxkit_briefs_rationale_18": "Absolute first/last births, including parent emission intervals and random life." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L18 | neighbors=[timeline()]
- "vfxkit_briefs_read": "read()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L12 | neighbors=[briefs.py]
- "vfxkit_build_rationale_1": "Compile recipes through EffekseerCore into .efkefc sources, .efk runtime exports" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L1 | neighbors=[build.py]
- "vfxkit_build_rationale_20": "Every folder init or a build writes into or deletes from must really be inside v" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L20 | neighbors=[check_output_dirs()]
- "vfxkit_build_rationale_28": "No file a build is about to write may be a link that leads outside vfx/ (writes" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L28 | neighbors=[check_targets()]
- "vfxkit_build_rationale_35": "The outputs of one owned effect, refusing anything that resolves outside vfx/ (a" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L35 | neighbors=[removable()]
- "vfxkit_build_rationale_46": "{resource base name: source file} for every texture and model the recipes import" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L46 | neighbors=[resource_inputs()]
- "vfxkit_build_rationale_65": "Resource names a built effect uses, from its compiled recipe snapshot; None when" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L65 | neighbors=[resource_names()]
- "vfxkit_build_rationale_72": "Refuse to replace a resources/ file with different content while another effect" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/build.py:L72 | neighbors=[check_resource_conflicts()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-201.json

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
