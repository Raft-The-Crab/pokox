# Node Description Batch 65 of 207

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

- "cavemap_cave_props3_quest_board": "quest_board()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L184 | neighbors=[cave_props3.py, boards(), notice board: two posts on stone feet, …] | lang=en
- "cavemap_cave_props3_shed_roof": "shed_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/cave_props3.py:L14 | neighbors=[cave_props3.py, mine_shop(), overlapping board-and-batten shed roof …] | lang=en
- "cavemap_hooks_lua": "hooks_lua.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/hooks_lua.py:L1 | neighbors=[lua_attrs(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "cavemap_palette_sheet": "palette_sheet.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/palette_sheet.py:L1 | neighbors=[rgb(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "cavemap_post_export": "post_export.py" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/cavemap/post_export.py:L1 | neighbors=[kind(), 2680d0e Pushed an update., e77fa31 Add new skills and asset packs …] | lang=en
- "clearbackend": "ClearBackend" | kind=code-symbol | neighbors=[OpenGLClearBackend, VulkanClearBackend, OpenGLESClearBackend] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@080a665a43f8021b82b26ff0124f5457feefea02": "080a665 Refresh graph after MUT-21 package resolver" | kind=Commit | source=git | neighbors=[main, e685cdf Add MUT-22 aggregate VM value a…, c7e951a Add MUT-21 package, import and …] | lang=pt
- "commit:repo:github.com/Raft-The-Crab/pokox@0ab64e551168f8acc9a1a4bd06290630700757ae": "0ab64e5 Refresh graph after lowering assignments/phis" | kind=Commit | source=git | neighbors=[main, 14e66c1 Add assignments and loop-carrie…, 2c0194b Add assignments and loop-carrie…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@13dbd75204f6997de20d6a8e44defeb4e4a2fba2": "13dbd75 Refresh graph after MUT-25 SSA IR" | kind=Commit | source=git | neighbors=[main, 335e0dc Add MUT-26 IR-to-bytecode emitt…, fd66d0d Add MUT-25 typed SSA IR and ver…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@14e66c1c921431938335ff8de7be27cca14760e3": "14e66c1 Add assignments and loop-carried phis to Mute lowering" | kind=Commit | source=git | neighbors=[0ab64e5 Refresh graph after lowering as…, main, 807b9d3 Refresh graph after lowering as…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@45151c3daa9e4abf995cd7dcac6ec859fa07637c": "45151c3 Refresh graph after MUT-26 emitter" | kind=Commit | source=git | neighbors=[335e0dc Add MUT-26 IR-to-bytecode emitt…, main, 85b7130 Close MUT-26 limits: AST-to-SSA…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@56f527149399959d8cfb6ad256efa717166e3464": "56f5271 Refresh graph after MUT-21/22 audit fixes" | kind=Commit | source=git | neighbors=[main, 964ba8a Resolve MUT-22 values runtime l…, 5edd00c Fix MUT-21/22 audit defects in …] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@69e798fccf8d916e746fb063555ff96693f36772": "69e798f Refresh graph after MUT-22 values runtime" | kind=Commit | source=git | neighbors=[main, 5edd00c Fix MUT-21/22 audit defects in …, e685cdf Add MUT-22 aggregate VM value a…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@716dc6c0363ad7a59454440af1a5606cc656b1d5": "716dc6c Refresh graph after MUT-23 scheduler" | kind=Commit | source=git | neighbors=[435b4d3 Add MUT-23 cooperative async sc…, main, 037434c Add MUT-24 determinism and capa…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@807b9d30c2d18e80397d9869312d64c829cacfbf": "807b9d3 Refresh graph after lowering assignments/phis" | kind=Commit | source=git | neighbors=[14e66c1 Add assignments and loop-carrie…, main, 90b7d79 Add for-range lowering to Mute …] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@94d15469b0a8a6342a366d49057df0c5ee76f74c": "94d1546 Updated markdowns." | kind=Commit | source=git | neighbors=[1dac49d Created NET-01 to NET-09, Start…, main, 6568dc9 Update from ML AI Code] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@97595370296038b36610809e376f29a3b90e679f": "9759537 Refresh graph after MUT-24 determinism analysis" | kind=Commit | source=git | neighbors=[037434c Add MUT-24 determinism and capa…, main, fd66d0d Add MUT-25 typed SSA IR and ver…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@9f1db236ec8e13698a5175419824a41e2e5266e7": "9f1db23 Record CI fix and green run evidence" | kind=Commit | source=git | neighbors=[main, 668ca72 Wait for X11 console input read…, d6139c3 Fix X11 test click helper argum…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@d14bc19be3490a321501bae30454f0ed852ca967": "d14bc19 Refresh graph after MUT-26 lowering" | kind=Commit | source=git | neighbors=[85b7130 Close MUT-26 limits: AST-to-SSA…, main, 2c0194b Add assignments and loop-carrie…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@dd14e7e63752ec67847380a4ba755b990cd1e9b3": "dd14e7e Refresh graph after MUT-22 limits fix" | kind=Commit | source=git | neighbors=[964ba8a Resolve MUT-22 values runtime l…, main, 435b4d3 Add MUT-23 cooperative async sc…] | lang=en
- "commit:repo:github.com/Raft-The-Crab/pokox@e04375a18955a4063ba2531b5e2af19713ec6c02": "e04375a Run tests" | kind=Commit | source=git | neighbors=[1c81e45 Update from ML AI Code, main, ba75e97 Update FUNDING.yml with additio…] | lang=pt
- "commit:repo:github.com/Raft-The-Crab/pokox@fc4604e3a06e0737a402b1f54dad07d0e348ea8c": "fc4604e Record CI billing block and X11 readiness fix" | kind=Commit | source=git | neighbors=[668ca72 Wait for X11 console input read…, main, c7e951a Add MUT-21 package, import and …] | lang=en
- "console_console_append": "append()" | kind=code-symbol | source=mute/src/console/console.cpp:L157 | neighbors=[console.cpp, decode_utf8(), is_format_control()] | lang=en
- "console_console_diagnostic": "diagnostic()" | kind=code-symbol | source=mute/src/console/console.cpp:L16 | neighbors=[console.cpp, execute_console_impl(), numeric()] | lang=en
- "console_console_evaluate_console": "evaluate_console()" | kind=code-symbol | source=mute/src/console/console.cpp:L71 | neighbors=[console.cpp, numeric(), execute_console_impl()] | lang=en
- "console_console_number": "number()" | kind=code-symbol | source=mute/src/console/console.cpp:L26 | neighbors=[console.cpp, execute_console_impl(), numeric()] | lang=en
- "creaturelab_lab_map_anchor": "anchor()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L83 | neighbors=[lab_map.py, exterior(), stations()] | lang=en
- "creaturelab_lab_map_face_in": "face_in()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L34 | neighbors=[lab_map.py, exterior(), stations()] | lang=en
- "creaturelab_lab_map_path_free": "path_free()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L472 | neighbors=[lab_map.py, exterior(), near_poly()] | lang=en
- "creaturelab_lab_map_path_z_y": "path_z_y()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L181 | neighbors=[lab_map.py, exterior(), hardscape()] | lang=en
- "creaturelab_lab_map_set_roof": "set_roof()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L634 | neighbors=[lab_map.py, sub(), shot()] | lang=en
- "creaturelab_lab_map_to_world": "to_world()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_map.py:L79 | neighbors=[lab_map.py, exterior(), stations()] | lang=en
- "creaturelab_lab_props_adeg": "adeg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L794 | neighbors=[lab_props.py, hall_trim(), rotunda()] | lang=en
- "creaturelab_lab_props_ball_lineup": "ball_lineup()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1912 | neighbors=[lab_props.py, catch_ball(), QA sheet prop: the four tiers in a row …] | lang=en
- "creaturelab_lab_props_bollard_light": "bollard_light()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1210 | neighbors=[lab_props.py, .add(), low path bollard: rounded white post, g…] | lang=en
- "creaturelab_lab_props_capsule_prop": "capsule_prop()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L138 | neighbors=[lab_props.py, capsule(), .add()] | lang=en
- "creaturelab_lab_props_cloud": "cloud()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1244 | neighbors=[lab_props.py, .add(), flat-bottomed cumulus for the sky (Smoo…] | lang=en
- "creaturelab_lab_props_dense": "_dense()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L1794 | neighbors=[lab_props.py, lerp(), sphere_decal()] | lang=en
- "creaturelab_lab_props_egg": "egg()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L517 | neighbors=[lab_props.py, .add(), specimen_tank()] | lang=en
- "creaturelab_lab_props_lathe_open": "lathe_open()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/creaturelab/lab_props.py:L860 | neighbors=[lab_props.py, lathe without the flat end caps (rings …, rotunda_roof()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-064.json

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
