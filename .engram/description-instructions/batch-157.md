# Node Description Batch 158 of 207

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

- "cad_skill_main_mating_rationale_1": "Fit checks for printed parts that go together (lids, joints, segments).  A previ" | kind=entity | source=.agents/skills/cad-skill-main/mating.py:L1 | neighbors=[mating.py] | lang=en
- "cad_skill_main_mating_rationale_22": "Volume in mm^3 shared by two CadQuery Workplanes (0 when apart)." | kind=entity | source=.agents/skills/cad-skill-main/mating.py:L22 | neighbors=[overlap()] | lang=en
- "cad_skill_main_mating_rationale_29": "Raise MatingError unless `moving` fits `fixed` with play only up to     `clearan" | kind=entity | source=.agents/skills/cad-skill-main/mating.py:L29 | neighbors=[check_mating()] | lang=en
- "cad_skill_main_mesh_io_rationale_1": "Pure trimesh STL loading with validation guards.  Kept separate from preview.py" | kind=entity | source=.agents/skills/cad-skill-main/mesh_io.py:L1 | neighbors=[mesh_io.py] | lang=en
- "cad_skill_main_mesh_io_rationale_120": "Approximate printed mass in grams (default: PLA, 2 walls, 15% infill).      A sl" | kind=entity | source=.agents/skills/cad-skill-main/mesh_io.py:L120 | neighbors=[estimate_mass()] | lang=en
- "cad_skill_main_mesh_io_rationale_14": "Load an STL file via trimesh.      Raises ValueError if the file cannot be parse" | kind=entity | source=.agents/skills/cad-skill-main/mesh_io.py:L14 | neighbors=[load_mesh()] | lang=en
- "cad_skill_main_mesh_io_rationale_70": "Turn a printer name, \"WxDxH\" or a single \"N\" (cube) into (x, y, z) mm.      Rais" | kind=entity | source=.agents/skills/cad-skill-main/mesh_io.py:L70 | neighbors=[parse_bed()] | lang=pt
- "cad_skill_main_mesh_io_rationale_95": "Check a part's bounding box against a build volume.      The part may be rotated" | kind=entity | source=.agents/skills/cad-skill-main/mesh_io.py:L95 | neighbors=[bed_fit()] | lang=pt
- "cad_skill_main_outline_from_scan_rationale_1": "Extract a 2D pocket outline from a 3D scan of an object.  Produces the max cross" | kind=entity | source=.agents/skills/cad-skill-main/outline_from_scan.py:L1 | neighbors=[outline_from_scan.py] | lang=en
- "cad_skill_main_outline_from_scan_rationale_31": "PCA-align in XY, center on the origin, floor to Z=0, scale." | kind=entity | source=.agents/skills/cad-skill-main/outline_from_scan.py:L31 | neighbors=[align_and_scale()] | lang=en
- "cad_skill_main_outline_from_scan_rationale_46": "Union of horizontal sections from Z=step/2 up to zmax." | kind=entity | source=.agents/skills/cad-skill-main/outline_from_scan.py:L46 | neighbors=[max_section_outline()] | lang=en
- "cad_skill_main_outline_from_scan_rationale_65": "Angle (deg) minimizing the bounding square of poly + clearance." | kind=entity | source=.agents/skills/cad-skill-main/outline_from_scan.py:L65 | neighbors=[rotate_min_square()] | lang=en
- "cad_skill_main_preview_rationale_150": "Create a pyrender scene containing the mesh, lights, and optionally ground." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L150 | neighbors=[_build_scene()] | lang=en
- "cad_skill_main_preview_rationale_220": "Overlay edge lines detected from the depth buffer onto the color image." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L220 | neighbors=[_add_edges()] | lang=en
- "cad_skill_main_preview_rationale_257": "Render one frame from an existing scene.      Adds a camera, renders, then remov" | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L257 | neighbors=[_render_frame()] | lang=en
- "cad_skill_main_preview_rationale_285": "Render the mesh from a specific angle. Returns a PIL Image." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L285 | neighbors=[render_view()] | lang=en
- "cad_skill_main_preview_rationale_298": "Try to load a nice sans-serif font, falling back to PIL default." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L298 | neighbors=[_get_font()] | lang=en
- "cad_skill_main_preview_rationale_315": "cat_flap_cover.stl\" -> \"Cat Flap Cover\"." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L315 | neighbors=[title_from_path()] | lang=en
- "cad_skill_main_preview_rationale_320": "Two-line footer with dimensions, volume, triangle count, and status." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L320 | neighbors=[_info_lines()] | lang=en
- "cad_skill_main_preview_rationale_339": "Render a single isometric view with title and footer." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L339 | neighbors=[render_single()] | lang=en
- "cad_skill_main_preview_rationale_362": "Render 6-view technical preview in a 3x2 grid.      Views: isometric, front, rig" | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L362 | neighbors=[render_multi_view()] | lang=en
- "cad_skill_main_preview_rationale_39": "Build a camera-pose matrix from elevation and azimuth (degrees).      Convention" | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L39 | neighbors=[_rotation_matrix()] | lang=en
- "cad_skill_main_preview_rationale_79": "Pick a human-friendly grid spacing that gives ~8-12 lines." | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L79 | neighbors=[_nice_spacing()] | lang=en
- "cad_skill_main_preview_rationale_88": "Create a ground-plane grid mesh at the bottom of the object.      Returns (groun" | kind=entity | source=.agents/skills/cad-skill-main/preview.py:L88 | neighbors=[_build_grid()] | lang=en
- "cad_skill_main_run_cadquery_model_rationale_63": "Return {ext: [paths]} in script_dir matching each *.{ext}     (case-insensitive)" | kind=entity | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L63 | neighbors=[_new_files_by_ext()] | lang=en
- "cad_skill_main_run_cadquery_model_rationale_94": "Load each STL once and optionally render a preview + check watertightness." | kind=entity | source=.agents/skills/cad-skill-main/run_cadquery_model.py:L94 | neighbors=[_process_stls()] | lang=en
- "callback": "Callback" | kind=code-symbol | neighbors=[PokoActivity] | lang=en
- "candyland_candy_map_foot": "foot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L122 | neighbors=[candy_map.py] | lang=en
- "candyland_candy_map_rationale_478": "cotton-candy cloud ring beyond the mountains (soft subdivided puffs, pastel)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L478 | neighbors=[horizon()] | lang=en
- "candyland_candy_map_rationale_68": "Chaikin corner cutting (keeps the ends)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L68 | neighbors=[smooth_pl()] | lang=en
- "candyland_candy_map_rationale_83": "0 on trails / plazas, 1 away from them (hills fade out near them)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L83 | neighbors=[path_mask()] | lang=en
- "candyland_candy_map_shot": "shot()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_map.py:L687 | neighbors=[candy_map.py] | lang=en
- "candyland_candy_props_rationale_146": "torus in the XZ plane (ring axis = Y)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L146 | neighbors=[torus()] | lang=en
- "candyland_candy_props_rationale_196": "one rod sprinkle (open-ended 5-sided rod, 10 tris)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L196 | neighbors=[sprinkle()] | lang=en
- "candyland_candy_props_rationale_200": "sprinkles lying on a surface: list of (point, normal)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L200 | neighbors=[sprinkles_on()] | lang=en
- "candyland_candy_props_rationale_270": "shade for waffle_lathe: ridges light, pockets darker (same column)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L270 | neighbors=[WAF()] | lang=en
- "candyland_candy_props_rationale_472": "decorated egg: lathe egg with horizontal colour bands (bands from cols)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L472 | neighbors=[candy_egg()] | lang=en
- "candyland_candy_props_rationale_748": "gumdrop bell radius at height y (0..Hh)" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L748 | neighbors=[bell_r()] | lang=es
- "candyland_candy_props_two_tone": "two_tone()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L277 | neighbors=[candy_props.py] | lang=en
- "candyland_candy_props_waffle": "waffle()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/candyland/candy_props.py:L262 | neighbors=[candy_props.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-157.json

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
