# Node Description Batch 47 of 207

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

- "commit:repo:github.com/Raft-The-Crab/pokox@3faf30f053a8221c2ceada68a0bf48ef4f0c1cf6": "3faf30f Character controller: value-keyed touch memo for the cast path" | kind=Commit | source=git | neighbors=[038387e Character controller: value-key…, main, 5acf433 Character controller: fix corru…, character_controller.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@510655313c402807d3acdf94b0449314e27274e4": "5106553 MUT-42: physics hostcall implementation" | kind=Commit | source=git | neighbors=[0d85dce Merge pull request #6 from Raft…, main, 78dbd1e Merge pull request #7 from Raft…, stdlib_physics.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@5acf4338aa740565f209dfedd33775883e9f114b": "5acf433 Character controller: fix corrupted push of touch memo" | kind=Commit | source=git | neighbors=[3faf30f Character controller: value-key…, main, 2be6ccd Character controller: fix missi…, character_controller.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@668ca7213c228415b3f0a5203cc399d8f6bc67e0": "668ca72 Wait for X11 console input readiness before measuring" | kind=Commit | source=git | neighbors=[main, fc4604e Record CI billing block and X11…, test_mute_console_x11.py, 9f1db23 Record CI fix and green run evi…]
- "commit:repo:github.com/Raft-The-Crab/pokox@8246f8b010a828516116ab1d896a8e1735378983": "8246f8b Character controller: fix header corruption from previous push" | kind=Commit | source=git | neighbors=[2be6ccd Character controller: fix missi…, main, 81d94fb Merge pull request #5 from Raft…, character_controller.hpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@8e05db15e1ce451b0efb13ee623800ec899bfcb6": "8e05db1 Character controller: conservative bounding-sphere prune before GJK/EPA" | kind=Commit | source=git | neighbors=[main, 60f3d98 Merge pull request #3 from Raft…, character_controller.cpp, ba75e97 Update FUNDING.yml with additio…]
- "commit:repo:github.com/Raft-The-Crab/pokox@9b779908f74a3c15fd09c1a51ac72d0e35ee3d05": "9b77990 Android GLES probe: no data race or dangling capture in the Vulkan work…" | kind=Commit | source=git | neighbors=[60d8044 Mute crypto hostcalls: fail exp…, main, 87beff4 Sim solver: reject self/duplica…, opengles_native_activity.cpp]
- "commit:repo:github.com/Raft-The-Crab/pokox@ba75e978011efd64936438b831a64db5d9b05a37": "ba75e97 Update FUNDING.yml with additional sponsorship options" | kind=Commit | source=git | neighbors=[main, 60f3d98 Merge pull request #3 from Raft…, 8e05db1 Character controller: conservat…, e04375a Run tests]
- "commit:repo:github.com/Raft-The-Crab/pokox@d6139c3d93d51c626c0226ae8bf5cf2ab8159f33": "d6139c3 Fix X11 test click helper argument" | kind=Commit | source=git | neighbors=[main, 9f1db23 Record CI fix and green run evi…, test_mute_console_x11.py, e624dc7 Click console input before each…]
- "commit:repo:github.com/Raft-The-Crab/pokox@e624dc71af773ab4687d4a78842503a755f5ea29": "e624dc7 Click console input before each X11 interaction" | kind=Commit | source=git | neighbors=[6d9948d Re-resolve X11 demo window duri…, main, d6139c3 Fix X11 test click helper argum…, test_mute_console_x11.py]
- "creaturelab_lab_map_ground": "ground()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L238 | neighbors=[lab_map.py, build(), static(), lawn grid: 3-stud cells near the buildi…]
- "creaturelab_lab_map_inset_top": "inset_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L87 | neighbors=[lab_map.py, hardscape(), polar_tiles(), wing_floor()]
- "creaturelab_lab_map_sub": "sub()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L23 | neighbors=[lab_map.py, place(), set_roof(), static()]
- "creaturelab_lab_props_blossom_tree": "blossom_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1491 | neighbors=[lab_props.py, ball(), .add(), small ornamental tree: smooth trunk, ro…]
- "creaturelab_lab_props_dock_cables": "dock_cables()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1645 | neighbors=[lab_props.py, rbox(), .add(), Storage story: cable runs across the fl…]
- "creaturelab_lab_props_flower_bed": "flower_bed()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1227 | neighbors=[lab_props.py, ball(), .add(), low flower clumps in a soft oval: round…]
- "creaturelab_lab_props_garden_wall": "garden_wall()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1522 | neighbors=[lab_props.py, rbox(), .add(), low garden boundary wall: white rendere…]
- "creaturelab_lab_props_hall_ceiling": "hall_ceiling()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1316 | neighbors=[lab_props.py, lerp(), .add(), coffered ceiling hung under the dome (n…]
- "creaturelab_lab_props_hedge": "hedge()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1218 | neighbors=[lab_props.py, rbox(), .add(), clipped hedge segment: rounded box mass…]
- "creaturelab_lab_props_lamp_post": "lamp_post()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1100 | neighbors=[lab_props.py, capsule(), .add(), plaza lamp: round foot, slim white post…]
- "creaturelab_lab_props_lily_pads": "lily_pads()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1532 | neighbors=[lab_props.py, ball(), .add(), floating lily pads (notched discs) with…]
- "creaturelab_lab_props_pc_terminal": "pc_terminal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L442 | neighbors=[lab_props.py, rbox(), .add(), storage terminal: rounded pedestal, ang…]
- "creaturelab_lab_props_potted_tree": "potted_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1129 | neighbors=[lab_props.py, leaf_ball(), .add(), indoor potted tree: tall white pot with…]
- "creaturelab_lab_props_rope_line": "rope_line()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1661 | neighbors=[lab_props.py, queue rope line: n steel stanchions wit…, ball(), .add()]
- "creaturelab_lab_props_round_tree": "round_tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1469 | neighbors=[lab_props.py, outdoor rounded park tree in the same l…, ball(), .add()]
- "creaturelab_lab_props_shell": "_shell()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1811 | neighbors=[lab_props.py, catch_ball(), one thick shell -> (outer, inner): oute…, lerp()]
- "creaturelab_lab_props_sliding_doors": "sliding_doors()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L990 | neighbors=[lab_props.py, automatic sliding doors for the south e…, rbox(), .add()]
- "creaturelab_lab_props_snake_plant": "snake_plant()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1436 | neighbors=[lab_props.py, tall snake plant: square pot, 11 uprigh…, rbox(), .add()]
- "creaturelab_lab_props_sphere_decal": "sphere_decal()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1801 | neighbors=[lab_props.py, catch_ball(), a raised inlay that hugs a sphere of ra…, _dense()]
- "creaturelab_lab_props_tree": "tree()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1038 | neighbors=[lab_props.py, rounded park tree: flared birch trunk s…, leaf_ball(), .add()]
- "creaturelab_lab_props_wait_bench": "wait_bench()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L320 | neighbors=[lab_props.py, waiting bench: steel loop legs, cushion…, rbox(), .add()]
- "creaturelab_lab_props_water_cooler": "water_cooler()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1765 | neighbors=[lab_props.py, water cooler: white cabinet with a sky …, rbox(), .add()]
- "creaturelab_lab_props_whiteboard": "whiteboard()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L691 | neighbors=[lab_props.py, rolling whiteboard: two T legs on caste…, rbox(), .add()]
- "debug_vulkan_diagnostics_since": "since()" | kind=code-symbol | source=engine/rhi/src/debug/vulkan_diagnostics.cpp:L19 | neighbors=[vulkan_diagnostics.cpp, messages(), totals(), stop()]
- "device_opengles_clear_renderer_initialize_impl": "initialize_impl()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L49 | neighbors=[opengles_clear_renderer.cpp, initialize(), shutdown(), initialize_window()]
- "device_opengles_clear_renderer_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/opengles_clear_renderer.cpp:L149 | neighbors=[opengles_clear_renderer.cpp, initialize_impl(), OpenGLClearESRenderer(), shutdown_checked()]
- "device_poko_jni_write_line": "write_line()" | kind=code-symbol | source=engine/rhi/src/device/poko_jni.cpp:L34 | neighbors=[poko_jni.cpp, Java_com_poko_glesclear_PokoActivity_na…, Java_com_poko_glesclear_PokoActivity_na…, run_probe()]
- "device_vulkan_clear_android_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_android.cpp:L331 | neighbors=[vulkan_clear_android.cpp, initialize(), shutdown_checked(), VulkanClearAndroidRenderer()]
- "device_vulkan_clear_renderer_shutdown": "shutdown()" | kind=code-symbol | source=engine/rhi/src/device/vulkan_clear_renderer.cpp:L185 | neighbors=[vulkan_clear_renderer.cpp, Impl(), initialize(), shutdown_checked()]
- "dunedesert_dune_map_add_owner": "add_owner()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/dunedesert/dune_map.py:L215 | neighbors=[dune_map.py, free(), place(), static()]

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-046.json

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
