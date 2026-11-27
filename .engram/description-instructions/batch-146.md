# Node Description Batch 147 of 208

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

- "valleylake_valley_props_rationale_265": "tall stylised pine: straight trunk, 8 tiers of separate drooping branch sprays (" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L265 | neighbors=[Palette, pine()] | lang=en
- "valleylake_valley_props_rationale_290": "the one cherry tree: dark crooked trunk with arching limbs, pink painted clumps," | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L290 | neighbors=[Palette, blossom_tree()] | lang=en
- "valleylake_valley_props_rationale_307": "HERO: the big leaning islet tree. Thick twisting trunk leaning out over the wate" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L307 | neighbors=[Palette, gnarled_tree()] | lang=en
- "valleylake_valley_props_rationale_407": "straight gable roof (ridge along X): two lofted tile slabs with a slight concave" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L407 | neighbors=[Palette, gable_roof()] | lang=en
- "valleylake_valley_props_rationale_458": "wall in XY facing -Z: dark timber posts + rails framing inset shoji panels (latt" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L458 | neighbors=[Palette, timber_wall()] | lang=en
- "valleylake_valley_props_rationale_48": "per-loop shade: height gradient y0..y1 (a -> b) + vertex-normal lift + low-freq" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L48 | neighbors=[Palette, V()] | lang=es
- "valleylake_valley_props_rationale_493": "rounded fieldstone footing course under a house (the shared base, echoes the roc" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L493 | neighbors=[Palette, footing()] | lang=en
- "valleylake_valley_props_rationale_518": "village houses. long = single storey longhouse 24 x 11, gable to the sides, fron" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L518 | neighbors=[Palette, house()] | lang=en
- "valleylake_valley_props_rationale_606": "open stall: 4 posts on stone pads, a small dark gable roof, counter with baskets" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L606 | neighbors=[Palette, market_stall()] | lang=en
- "valleylake_valley_props_rationale_631": "small red paper lantern: lathed ribbed body (red) + caps + a glow core inside" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L631 | neighbors=[Palette, paper_lantern()] | lang=pt
- "valleylake_valley_props_rationale_641": "tall timber pole with a cross arm + strut, rope cleats; lantern ropes hang from" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L641 | neighbors=[Palette, rope_pole()] | lang=en
- "valleylake_valley_props_rationale_65": "pillowy rounded-box mass: a subdivided cube pushed onto a superellipsoid |x|^n+|" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L65 | neighbors=[Palette, rounded_mass()] | lang=pt
- "valleylake_valley_props_rationale_652": "rope span along +X from x 0 (left arm tip) to L, catenary sag, with n small pape" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L652 | neighbors=[Palette, lantern_rope()] | lang=en
- "valleylake_valley_props_rationale_663": "low wooden lantern post for the shore path: post, small roof cap, a hanging pape" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L663 | neighbors=[Palette, lantern_post()] | lang=en
- "valleylake_valley_props_rationale_679": "L-shaped fishing dock: a 4-wide walkway (along -Z from the beach at z 0) with an" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L679 | neighbors=[Palette, dock()] | lang=en
- "valleylake_valley_props_rationale_722": "small arched plank bridge over the stream (span along Z, origin = centre at bank" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L722 | neighbors=[Palette, footbridge()] | lang=en
- "valleylake_valley_props_rationale_741": "retaining wall module (front = -Z): coursed rounded fieldstones (soft, echoes th" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L741 | neighbors=[Palette, stone_wall()] | lang=en
- "valleylake_valley_props_rationale_766": "stone flight up the retaining wall (front = -Z, climbs toward +Z), rounded cheek" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L766 | neighbors=[Palette, stone_stair()] | lang=en
- "valleylake_valley_props_rationale_780": "HERO: a broad curved sheet spilling off a mossy carved lip, bowing out and widen" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L780 | neighbors=[Palette, waterfall()] | lang=pt
- "valleylake_valley_props_rationale_832": "station sign: blank board (GUI goes on it, nothing written) in a timber frame on" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L832 | neighbors=[Palette, sign_stand()] | lang=en
- "valleylake_valley_props_rationale_845": "branching skeleton -> one smooth closed trunk mesh: Blender Skin modifier (smoot" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L845 | neighbors=[Palette, skin_mesh()] | lang=en
- "valleylake_valley_props_rationale_863": "node list [(pos, radius)] + edges; helpers to grow curved, tapering limbs" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L863 | neighbors=[Palette, Skel] | lang=en
- "valleylake_valley_props_rationale_870": "limb from node `parent` along d (curving by bend per step, wobbling), n segments" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L870 | neighbors=[Palette, .grow()] | lang=en
- "valleylake_valley_props_rationale_879": "bark grooves (noise stretched along the height = long vertical furrows) + shadin" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L879 | neighbors=[Palette, bark()] | lang=en
- "valleylake_valley_props_rationale_895": "one soft canopy mass: a displaced dark core blob + many small leaf cards at rand" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L895 | neighbors=[Palette, leaf_mass()] | lang=pt
- "valleylake_valley_props_rationale_930": "buttress roots gripping the ground: start high on the flare, run out low along t" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L930 | neighbors=[Palette, roots()] | lang=en
- "valleylake_valley_props_rationale_94": "thick moss shell over the up-facing part of `bm`: faces whose verts all face up" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L94 | neighbors=[Palette, moss_cap()] | lang=en
- "valleylake_valley_props_rationale_940": "HERO: the islet tree, rebuilt as a real tree. Skinned skeleton: thick flared bas" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L940 | neighbors=[Palette, gnarled_tree()] | lang=en
- "valleylake_valley_props_rationale_986": "stylised broadleaf (same method, lighter): skinned trunk with a root flare forki" | kind=entity | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L986 | neighbors=[Palette, broadleaf()] | lang=en
- "valleylake_valley_props_smooth": "smooth()" | kind=code-symbol | source=.agents/skills/Map Pack/map-builder/examples/valleylake/valley_props.py:L44 | neighbors=[valley_props.py, waterfall()] | lang=en
- "vfxkit_briefs_validate": "validate()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/briefs.py:L36 | neighbors=[briefs.py, timeline()] | lang=en
- "vfxkit_cli_parser": "parser()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/cli.py:L23 | neighbors=[cli.py, main()] | lang=en
- "vfxkit_doctor_version": "version()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/doctor.py:L12 | neighbors=[doctor.py, doctor()] | lang=en
- "vfxkit_evidence_outputs": "outputs()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L71 | neighbors=[evidence.py, write_build()] | lang=en
- "vfxkit_evidence_portable": "portable()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L46 | neighbors=[evidence.py, inputs()] | lang=en
- "vfxkit_evidence_prepared": "prepared()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L33 | neighbors=[evidence.py, inputs()] | lang=en
- "vfxkit_evidence_stage_snapshot": "stage_snapshot()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L131 | neighbors=[evidence.py, capture_issues()] | lang=en
- "vfxkit_evidence_template_issues": "template_issues()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/evidence.py:L143 | neighbors=[evidence.py, capture_issues()] | lang=en
- "vfxkit_examples_listing": "listing()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L48 | neighbors=[examples.py, catalog()] | lang=en
- "vfxkit_examples_textures": "textures()" | kind=code-symbol | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/examples.py:L41 | neighbors=[examples.py, add()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-146.json

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
