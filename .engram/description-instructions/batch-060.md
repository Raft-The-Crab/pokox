# Node Description Batch 61 of 207

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

- "whispering_grove_forest_props_rationale_111": "door outline in the XY plane, open at the bottom: left foot -> up -> semicircle" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L111 | neighbors=[MB, Palette, Sh, arch_outline()] | lang=en
- "whispering_grove_forest_props_rationale_117": "solid stone frame between the inner outline and one t wider, extruded z0..z1 (z1" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L117 | neighbors=[MB, Palette, Sh, arch_frame()] | lang=en
- "whispering_grove_forest_props_rationale_158": "the dark passage behind the frame: walls + floor only, faces pointing inward" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L158 | neighbors=[MB, Palette, Sh, arch_tunnel()] | lang=en
- "whispering_grove_forest_props_rationale_206": "one modelled fern frond: a serrated, thickened strip arching up then down" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L206 | neighbors=[MB, Palette, Sh, frond()] | lang=pt
- "whispering_grove_forest_props_rationale_35": "one kit prop: a solid mesh on the palette + optional glow meshes (Neon in Roblox" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L35 | neighbors=[MB, Palette, Sh, Prop] | lang=en
- "whispering_grove_forest_props_rationale_413": "a licking flame: a tapering tube that sways and twists to a point" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L413 | neighbors=[MB, Palette, Sh, flame_tongue()] | lang=en
- "whispering_grove_forest_props_rationale_642": "kit meshes: <Prop> (solid) + <Prop>_Glow_<key>. Origin = bottom centre (prop bui" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L642 | neighbors=[MB, Palette, Sh, to_kit()] | lang=en
- "whispering_grove_forest_props_stump": "stump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L283 | neighbors=[forest_props.py, Prop, .add(), S()] | lang=en
- "whispering_grove_forest_props_to_kit": "to_kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/whispering_grove/forest_props.py:L641 | neighbors=[forest_props.py, kit meshes: <Prop> (solid) + <Prop>_Glo…, materials(), mesh_from()] | lang=en
- "window_sdl_platform_sdlplatform": "~SdlPlatform()" | kind=code-symbol | source=engine/platform/src/window/sdl_platform.cpp:L10 | neighbors=[sdl_platform.cpp, IPlatform, .SdlPlatform(), shutdown()] | lang=en
- "writing_skills_render_graphs_main": "main()" | kind=code-symbol | source=.agents/skills/superpowers-main/skills/writing-skills/render-graphs.js:L84 | neighbors=[render-graphs.js, combineGraphs(), extractDotBlocks(), renderToSvg()] | lang=en
- "animation_v2_build_refined_ease": "ease()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L9 | neighbors=[build_refined.py, foot(), interp()] | lang=en
- "animation_v2_build_refined_foot": "foot()" | kind=code-symbol | source=assets/characters/animation-v2/build_refined.py:L16 | neighbors=[build_refined.py, ease(), Continuous velocity at footfall and toe…] | lang=en
- "animation_v2_check_model_structure": "check_model_structure.py" | kind=code-symbol | source=assets/characters/animation-v2/check_model_structure.py:L1 | neighbors=[capture(), floats(), c7a411f Fix MUT-01-20 audit defects in …] | lang=en
- "bin_trace_processor_download_or_get_cached": "download_or_get_cached()" | kind=code-symbol | source=.agents/skills/skills-main/profilers/android-profiler/references/perfetto/bin/trace_processor:L213 | neighbors=[trace_processor, get_perfetto_prebuilt(), Downloads a prebuilt or returns a cache…] | lang=en
- "blender_explorer_build_build_explorer": "build_explorer()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_build.py:L61 | neighbors=[explorer_build.py, _fresh_col(), _mats()] | lang=en
- "blender_explorer_common_cylinder": "cylinder()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L188 | neighbors=[explorer_common.py, assign(), Cylinder built at the origin, then plac…] | lang=en
- "blender_explorer_common_loft": "loft()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L125 | neighbors=[explorer_common.py, assign(), Build a tube from a list of (center Vec…] | lang=en
- "blender_explorer_common_shell_from": "shell_from()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/explorer_common.py:L102 | neighbors=[explorer_common.py, Duplicate meshes then scale about a piv…, assign()] | lang=en
- "blender_render_compare_views_scene_bounds": "_scene_bounds()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L54 | neighbors=[render_compare_views.py, World bounds from evaluated vertices: b…, setup_camera()] | lang=en
- "blender_render_compare_views_setup_camera": "setup_camera()" | kind=code-symbol | source=.agents/skills/ForgeSkills-main/tools/blender/render_compare_views.py:L81 | neighbors=[render_compare_views.py, render_turnaround(), _scene_bounds()] | lang=en
- "brainstorm_server_auth_test_assert": "assert" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L20 | neighbors=[auth.test.js, runBootstrapScript(), serverStartedMessage()] | lang=en
- "brainstorm_server_auth_test_assertstartedonexpectedport": "assertStartedOnExpectedPort()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L116 | neighbors=[auth.test.js, serverStartedMessage(), runTests()] | lang=en
- "brainstorm_server_auth_test_serverstartedmessage": "serverStartedMessage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/auth.test.js:L110 | neighbors=[auth.test.js, assertStartedOnExpectedPort(), assert] | lang=en
- "brainstorm_server_branding_test_assertbrandedwithlogo": "assertBrandedWithLogo()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L122 | neighbors=[branding.test.js, assert, test()] | lang=en
- "brainstorm_server_branding_test_assertframedlogosupportsdarktheme": "assertFramedLogoSupportsDarkTheme()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L208 | neighbors=[branding.test.js, assert, test()] | lang=en
- "brainstorm_server_branding_test_assertframedscreenusesbrandheader": "assertFramedScreenUsesBrandHeader()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L215 | neighbors=[branding.test.js, assert, test()] | lang=en
- "brainstorm_server_branding_test_assertheaderavoidsnarrowoverlap": "assertHeaderAvoidsNarrowOverlap()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L227 | neighbors=[branding.test.js, assert, test()] | lang=en
- "brainstorm_server_branding_test_assertlogokeepstransparentbackground": "assertLogoKeepsTransparentBackground()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L173 | neighbors=[branding.test.js, assert, test()] | lang=en
- "brainstorm_server_branding_test_cleanup": "cleanup()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L19 | neighbors=[branding.test.js, startServer(), withServer()] | lang=en
- "brainstorm_server_branding_test_startserver": "startServer()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/branding.test.js:L29 | neighbors=[branding.test.js, cleanup(), withServer()] | lang=en
- "brainstorm_server_server_test_assertstartedonexpectedport": "assertStartedOnExpectedPort()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L106 | neighbors=[server.test.js, serverStartedMessage(), runTests()] | lang=en
- "brainstorm_server_server_test_serverstartedmessage": "serverStartedMessage()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L100 | neighbors=[server.test.js, assertStartedOnExpectedPort(), assert] | lang=en
- "brainstorm_server_server_test_skip": "skip()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L96 | neighbors=[server.test.js, ensureSymlinkWorks(), SkipTest] | lang=en
- "brainstorm_server_server_test_skiptest": "SkipTest" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L89 | neighbors=[server.test.js, skip(), .constructor()] | lang=en
- "brainstorm_server_server_test_sleep": "sleep()" | kind=code-symbol | source=.agents/skills/superpowers-main/tests/brainstorm-server/server.test.js:L33 | neighbors=[server.test.js, runTests(), waitFor()] | lang=en
- "brick_bone_hydra_brick_build": "build()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L420 | neighbors=[bone_hydra_brick.py, exposed(), lin()] | lang=en
- "brick_bone_hydra_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L75 | neighbors=[bone_hydra_brick.py, dspike(), head()] | lang=en
- "brick_bone_hydra_brick_nrm": "nrm()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L66 | neighbors=[bone_hydra_brick.py, dspike(), tail_at()] | lang=en
- "brick_bone_hydra_brick_oell": "oell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/bone_hydra_brick.py:L61 | neighbors=[bone_hydra_brick.py, full(), sl_of()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-060.json

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
