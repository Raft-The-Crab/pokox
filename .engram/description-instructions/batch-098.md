# Node Description Batch 99 of 208

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

- "cad_skill_main_mesh_io_estimate_mass": "estimate_mass()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L119 | neighbors=[mesh_io.py, Approximate printed mass in grams (defa…] | lang=en
- "cad_skill_main_mesh_io_load_mesh": "load_mesh()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L13 | neighbors=[mesh_io.py, Load an STL file via trimesh.      Rais…] | lang=en
- "cad_skill_main_mesh_io_parse_bed": "parse_bed()" | kind=code-symbol | source=.agents/skills/cad-skill-main/mesh_io.py:L69 | neighbors=[mesh_io.py, Turn a printer name, "WxDxH" or a singl…] | lang=en
- "cad_skill_main_outline_from_scan_recentered": "recentered()" | kind=code-symbol | source=.agents/skills/cad-skill-main/outline_from_scan.py:L77 | neighbors=[outline_from_scan.py, main()] | lang=en
- "cad_skill_main_run_cadquery_model_append_stderr": "_append_stderr()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L58 | neighbors=[run_cadquery_model.py, main()] | lang=en
- "cad_skill_main_run_cadquery_model_sibling": "_sibling()" | kind=code-symbol | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L54 | neighbors=[run_cadquery_model.py, _process_stls()] | lang=en
- "cad_skill_main_stl_to_3mf_convert": "convert()" | kind=code-symbol | source=.agents/skills/cad-skill-main/stl_to_3mf.py:L27 | neighbors=[stl_to_3mf.py, main()] | lang=en
- "cad_skill_main_stl_to_3mf_main": "main()" | kind=code-symbol | source=.agents/skills/cad-skill-main/stl_to_3mf.py:L40 | neighbors=[stl_to_3mf.py, convert()] | lang=en
- "candyland_candy_map_axis_coords": "axis_coords()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L261 | neighbors=[candy_map.py, ground()] | lang=en
- "candyland_candy_map_bump": "bump()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L81 | neighbors=[candy_map.py, H0()] | lang=en
- "candyland_candy_map_face": "face()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L163 | neighbors=[candy_map.py, build()] | lang=en
- "candyland_candy_map_inb": "_inb()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L213 | neighbors=[candy_map.py, _inside_one()] | lang=en
- "candyland_candy_map_kit": "kit()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L117 | neighbors=[candy_map.py, place()] | lang=en
- "candyland_candy_map_look": "look()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L662 | neighbors=[candy_map.py, free()] | lang=en
- "candyland_candy_map_moat": "moat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L420 | neighbors=[candy_map.py, mesh_obj()] | lang=en
- "candyland_candy_map_rationale_169": "trails, plazas, river, castle hill, falls: nothing scattered there" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L169 | neighbors=[on_hard(), MB] | lang=en
- "candyland_candy_map_rationale_295": "one board tile: the polyline section s0..s1 (arc length) across `width`, draped" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L295 | neighbors=[drape_strip(), MB] | lang=en
- "candyland_candy_map_rationale_329": "board-game tile runs (TILE long, 0.7 gaps) + sprinkles on them; round stop plaza" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L329 | neighbors=[trails(), MB] | lang=en
- "candyland_candy_map_rationale_386": "chocolate river surface (glossy, streaked) + graham-crumb banks" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L386 | neighbors=[river(), MB] | lang=en
- "candyland_candy_map_rationale_433": "icing poured over the frosting hilltops: a draped sheet with a thick rounded lip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L433 | neighbors=[icing_caps(), MB] | lang=en
- "candyland_candy_map_rationale_492": "deferred foliage: place, test against a BVH of every solid (the exporter's clip" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L492 | neighbors=[soft_pass(), MB] | lang=en
- "candyland_candy_map_rationale_89": "frosting land before the river / castle carve" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L89 | neighbors=[H0(), MB] | lang=en
- "candyland_candy_map_seg_d": "seg_d()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L55 | neighbors=[candy_map.py, poly_d()] | lang=en
- "candyland_candy_map_smooth_pl": "smooth_pl()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L67 | neighbors=[candy_map.py, Chaikin corner cutting (keeps the ends)] | lang=en
- "candyland_candy_map_top": "_top()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L223 | neighbors=[candy_map.py, fit_bad()] | lang=en
- "candyland_candy_map_unplace": "unplace()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L160 | neighbors=[candy_map.py, soft_pass()] | lang=en
- "candyland_candy_props_pmat": "_pmat()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1194 | neighbors=[candy_props.py, preview_mats()] | lang=en
- "candyland_candy_props_rationale_1008": "cotton-candy tree: twisting pretzel trunk with 3 limbs, each holding a fluffy ma" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1008 | neighbors=[cotton_candy_tree(), Palette] | lang=en
- "candyland_candy_props_rationale_1036": "3-5 sugar-coated gumdrops of different colours clustered on the ground (true gum" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1036 | neighbors=[gumdrop_bush(), Palette] | lang=en
- "candyland_candy_props_rationale_1046": "frame mountain: a huge sugar-coated gumdrop bell with an icing cap that follows" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1046 | neighbors=[gumdrop_mountain(), Palette] | lang=en
- "candyland_candy_props_rationale_1064": "a bean: tube along a gentle arc with rounded ends" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1064 | neighbors=[jelly_bean(), Palette] | lang=pt
- "candyland_candy_props_rationale_1073": "rock' scatter: a heap of 6-9 glossy jelly beans, some speckled" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1073 | neighbors=[jelly_beans(), Palette] | lang=en
- "candyland_candy_props_rationale_1084": "patch of fondant flowers: lime stems, 6 soft petals, gum centres" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1084 | neighbors=[candy_flower(), Palette] | lang=en
- "candyland_candy_props_rationale_1105": "path lamp: striped stick post, piped collar, glowing wrapped-candy lantern with" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1105 | neighbors=[candy_lamp(), Palette] | lang=en
- "candyland_candy_props_rationale_1123": "stepping-stone marshmallow: rounded cylinder, pink or white, slightly toasted to" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1123 | neighbors=[marshmallow(), Palette] | lang=en
- "candyland_candy_props_rationale_1129": "spawn medallion: giant sugar cookie with a crimped rim, a piped icing star and s" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1129 | neighbors=[spawn_cookie(), Palette] | lang=en
- "candyland_candy_props_rationale_113": "smooth lumpy ball: icosphere (sub 2 = 80, 3 = 320 tris) displaced by low-frequen" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L113 | neighbors=[soft(), Palette] | lang=en
- "candyland_candy_props_rationale_1147": "story prop: a toppled giant ice-cream cone, scoop slumped on the ground and melt" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1147 | neighbors=[giant_cone(), Palette] | lang=en
- "candyland_candy_props_rationale_1166": "3-4 big macarons stacked a little askew (crate-like set dressing near the statio" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1166 | neighbors=[macaron_stack(), Palette] | lang=en
- "candyland_candy_props_rationale_1190": "palette column -> Enum.Material name, for roblox_materials.write_map" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L1190 | neighbors=[roblox_materials(), Palette] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-098.json

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
