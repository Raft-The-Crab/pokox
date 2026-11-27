# Node Description Batch 159 of 208

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

- "brick_war_mech_brick_sph": "sph()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_mech_brick.py:L40 | neighbors=[war_mech_brick.py] | lang=en
- "brick_war_rhino_brick_box": "box()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L39 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_col4": "col4()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L50 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_fold_z": "fold_z()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L71 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_hx": "hx()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L24 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_newid": "newid()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L55 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_put": "put()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L29 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_rationale_186": "exposed brick faces as flat quads; UVs = brick coords / 4 so the 4x4 stud tile p" | kind=entity | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L186 | neighbors=[build()] | lang=en
- "brick_war_rhino_brick_sd_ell": "sd_ell()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L32 | neighbors=[war_rhino_brick.py] | lang=en
- "brick_war_rhino_brick_smin": "smin()" | kind=code-symbol | source=.agents/skills/Voxel Pack/stud/examples/brick/war_rhino_brick.py:L37 | neighbors=[war_rhino_brick.py] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_init": ".__init__()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L193 | neighbors=[GridfinityBin] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_nominal_h": ".nominal_h()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L221 | neighbors=[GridfinityBin] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_outer_d": ".outer_d()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L217 | neighbors=[GridfinityBin] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_outer_w": ".outer_w()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L213 | neighbors=[GridfinityBin] | lang=en
- "cad_skill_main_gridfinity_gridfinitybin_total_h": ".total_h()" | kind=code-symbol | source=.agents/skills/cad-skill-main/gridfinity.py:L225 | neighbors=[GridfinityBin] | lang=en
- "cad_skill_main_gridfinity_rationale_1": "Gridfinity bin generator for CadQuery.  Vendored module: copy this file next to" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L1 | neighbors=[gridfinity.py] | lang=en
- "cad_skill_main_gridfinity_rationale_107": "Normalize scalar / 2-tuple / 4-tuple corner radii.      Order: (+X+Y, -X+Y, -X-Y" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L107 | neighbors=[_corner_radii()] | lang=es
- "cad_skill_main_gridfinity_rationale_123": "Draw a closed rounded-rect wire with per-corner radii on `workplane`.      `radi" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L123 | neighbors=[_rounded_rect()] | lang=en
- "cad_skill_main_gridfinity_rationale_149": "Collect the solids of several workplanes/solids into one Compound.      Booleans" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L149 | neighbors=[_compound()] | lang=en
- "cad_skill_main_gridfinity_rationale_163": "Combine cutter workplanes into one safe boolean tool.      Disjoint cutters ride" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L163 | neighbors=[_fused()] | lang=en
- "cad_skill_main_gridfinity_rationale_187": "Builder for a spec-compatible Gridfinity bin.      Create the bin, add features," | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L187 | neighbors=[GridfinityBin] | lang=en
- "cad_skill_main_gridfinity_rationale_230": "Z of the interior floor: base profile plus solid floor." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L230 | neighbors=[.floor_z()] | lang=en
- "cad_skill_main_gridfinity_rationale_235": "Deepest cavity possible from the top of the bin." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L235 | neighbors=[.max_depth()] | lang=en
- "cad_skill_main_gridfinity_rationale_243": "Rounded-rect cavity cut from the top rim down `depth` mm.          `corner_r`: s" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L243 | neighbors=[.add_pocket()] | lang=en
- "cad_skill_main_gridfinity_rationale_254": "Cavity with an arbitrary closed outline (list of (x, y) mm).          `clearance" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L254 | neighbors=[.add_polygon_pocket()] | lang=en
- "cad_skill_main_gridfinity_rationale_266": "Round cavity cut from the top rim down `depth` mm.          Useful for finger we" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L266 | neighbors=[.add_cylinder_pocket()] | lang=en
- "cad_skill_main_gridfinity_rationale_293": "Classic divided storage interior: cols x rows compartments.          Optional `s" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L293 | neighbors=[.add_compartments()] | lang=en
- "cad_skill_main_gridfinity_rationale_307": "U-shaped scallop cut into one side wall from the top rim.          `side` is one" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L307 | neighbors=[.add_finger_notch()] | lang=en
- "cad_skill_main_gridfinity_rationale_412": "Feature footprint must leave MIN_WALL of outer wall." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L412 | neighbors=[._check_wall_clearance()] | lang=en
- "cad_skill_main_gridfinity_rationale_439": "Validate and build; returns a cq.Workplane, bottom at Z=0." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L439 | neighbors=[.build()] | lang=en
- "cad_skill_main_gridfinity_rationale_475": "Per-cell base profile: taper, riser, taper (45 degrees).          The sketch fil" | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L475 | neighbors=[._base_cells()] | lang=en
- "cad_skill_main_gridfinity_rationale_510": "Stacking lip: the mirrored base profile lofted around the rim." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L510 | neighbors=[._lip_cut()] | lang=en
- "cad_skill_main_gridfinity_rationale_538": "Vertical span of the bore's cylindrical part." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L538 | neighbors=[._cylinder_drop()] | lang=en
- "cad_skill_main_gridfinity_rationale_570": "Cutters (cavities) and additions (scoops, label shelves)." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L570 | neighbors=[._compartment_solids()] | lang=en
- "cad_skill_main_gridfinity_rationale_597": "Concave quarter-round ramp along a compartment's front floor edge." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L597 | neighbors=[._scoop()] | lang=pt
- "cad_skill_main_gridfinity_rationale_610": "45-degree triangular label shelf hanging from a back wall." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L610 | neighbors=[._label_shelf()] | lang=en
- "cad_skill_main_gridfinity_rationale_64": "Raised when a bin configuration cannot produce valid geometry." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L64 | neighbors=[GridfinityError] | lang=pt
- "cad_skill_main_gridfinity_rationale_645": "Magnet bores and/or screw holes, 4 per cell on a 26mm square." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L645 | neighbors=[._base_hole_cutter()] | lang=en
- "cad_skill_main_gridfinity_rationale_661": "One-paragraph description of the built dimensions." | kind=entity | source=.agents/skills/cad-skill-main/gridfinity.py:L661 | neighbors=[.summary()] | lang=en
- "cad_skill_main_mating_rationale_1": "Fit checks for printed parts that go together (lids, joints, segments).  A previ" | kind=entity | source=.agents/skills/cad-skill-main/mating.py:L1 | neighbors=[mating.py] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-158.json

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
