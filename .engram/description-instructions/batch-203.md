# Node Description Batch 204 of 209

Engram is running in assistant/skill mode (no API key). You are the host
assistant (Claude Code / Codex / Gemini CLI). Read the prompt below and write
your JSON answer to the answer file.

## Prompt

You are documenting nodes in a knowledge graph.
For each entry below, write ONE concise factual plain-language sentence
describing what it is or does. Use only the provided context.
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

- "vfxkit_paths_rationale_22": "`vfx init` has run here: a vfx/ folder that merely exists (another tool's output" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L22 | neighbors=[initialized()] | lang=en
- "vfxkit_paths_rationale_36": "Where build and render (EffekseerCore through .NET, the Effekseer Godot plugin)" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L36 | neighbors=[full_mode_platform()] | lang=en
- "vfxkit_paths_rationale_47": "How to run setup on this system, as a command an agent can run from the project." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L47 | neighbors=[setup_command()] | lang=en
- "vfxkit_paths_rationale_55": "Godot 4 executable: GODOT, then `godot` (or `godot4`) on PATH, then the standard" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/paths.py:L55 | neighbors=[godot()] | lang=en
- "vfxkit_primitives_rationale_1": "Composable layer primitives for effect recipes: `from vfxkit.primitives import *" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L1 | neighbors=[primitives.py] | lang=en
- "vfxkit_primitives_rationale_102": "Emissive-to-smoke afterimage: the same stroke, alpha-blended grey, a few frames" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L102 | neighbors=[decay()] | lang=en
- "vfxkit_primitives_rationale_112": "A very long, very thin accent line (aspect > 40:1) that shoots out to full lengt" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L112 | neighbors=[slice_line()] | lang=en
- "vfxkit_primitives_rationale_118": "Directional burst: particles fly to a random point in the world-space box `end`" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L118 | neighbors=[spray()] | lang=en
- "vfxkit_primitives_rationale_123": "Dark tumbling rock chunks thrown along `end` (see spray): value contrast against" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L123 | neighbors=[debris()] | lang=en
- "vfxkit_primitives_rationale_130": "A band lying in a tilted 3D plane (accretion disk, orbiting rune ring): an ellip" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L130 | neighbors=[orbit_band()] | lang=en
- "vfxkit_primitives_rationale_139": "Alpha-blended puffs that grow and slow down. The default painted flipbook billow" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L139 | neighbors=[smoke()] | lang=en
- "vfxkit_primitives_rationale_149": "Fire tongues without a drawn flame: the painted turbulent explosion flipbook gro" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L149 | neighbors=[flame()] | lang=en
- "vfxkit_primitives_rationale_16": "A texture already resolved to a file path (tex() returns native paths: backslash" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L16 | neighbors=[is_path()] | lang=pt
- "vfxkit_primitives_rationale_162": "Colour over life as a gradient: ramp((0,white),(30,orange),(100,red)) -> color_c" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L162 | neighbors=[ramp()] | lang=pt
- "vfxkit_primitives_rationale_168": "Painted flipbook billow played once over the particle's life: the shape itself r" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L168 | neighbors=[billow()] | lang=en
- "vfxkit_primitives_rationale_174": "A video-model flipbook (`vfx video-flipbook` + `vfx video-grade`) as the effect'" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L174 | neighbors=[video_body()] | lang=en
- "vfxkit_primitives_rationale_197": "Screen-space refraction (BackDistortion): bends whatever is behind it, the cue t" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L197 | neighbors=[heat_haze()] | lang=en
- "vfxkit_primitives_rationale_202": "Refractive shockwave: an expanding ring that pushes the background outward inste" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L202 | neighbors=[distortion_ring()] | lang=en
- "vfxkit_primitives_rationale_207": "Flat ground-plane sprite (rune, crack, scorch); depth-tested so characters stand" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L207 | neighbors=[decal()] | lang=en
- "vfxkit_primitives_rationale_214": "Upright camera-facing sprite that grows from its base." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L214 | neighbors=[standing()] | lang=en
- "vfxkit_primitives_rationale_218": "Procedural Sphere/Cone/Cylinder shell, usually textured with a scrolling gradien" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L218 | neighbors=[mesh()] | lang=en
- "vfxkit_primitives_rationale_233": "Faceted ice/arcane crystal: a six-sided cone mesh with a cellular texture and br" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L233 | neighbors=[crystal()] | lang=en
- "vfxkit_primitives_rationale_240": "3D shock bubble: a sphere whose fresnel rim is the only visible part, expanding" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L240 | neighbors=[shell()] | lang=en
- "vfxkit_primitives_rationale_248": "Six partial spherical sheets separate at expiry; geometry supplies gaps without" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L248 | neighbors=[shell_fragments()] | lang=en
- "vfxkit_primitives_rationale_263": "Shockwave ring lying in a 3D plane (ground, or across the line of a hit): an ell" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L263 | neighbors=[tilted_ring()] | lang=en
- "vfxkit_primitives_rationale_267": "Volumetric light shaft: streaks scroll up a cylinder, a static gradient fades th" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L267 | neighbors=[column()] | lang=pt
- "vfxkit_primitives_rationale_275": "impact (0..1) and light drive the lab's flash and camera kick at peak; they are" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L275 | neighbors=[effect()] | lang=en
- "vfxkit_primitives_rationale_30": "Soft light bloom behind a shape: pops fast, then swells slightly while fading." | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L30 | neighbors=[glow()] | lang=pt
- "vfxkit_primitives_rationale_305": "Latest frame at which this layer or any child can still be alive.   `infinite` l" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L305 | neighbors=[lifetime()] | lang=en
- "vfxkit_primitives_rationale_335": "Wide dim afterimage + saturated body + thin white-hot edge: one blade read at th" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L335 | neighbors=[slash_set()] | lang=en
- "vfxkit_primitives_rationale_34": "Dark alpha backing behind an additive core: peaks a frame or two after the white" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L34 | neighbors=[shadow()] | lang=en
- "vfxkit_primitives_rationale_362": "Projectile emitter: one instance every `interval` frames until the game releases" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L362 | neighbors=[sustain()] | lang=en
- "vfxkit_primitives_rationale_366": "Turn a blade's layers into a 3D swing plane: a pivot at the anchor yaws (and pit" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L366 | neighbors=[swing()] | lang=pt
- "vfxkit_primitives_rationale_371": "One fixed sprite plus a matching Blend underlay; rejects independently randomize" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L371 | neighbors=[contrast_pair()] | lang=en
- "vfxkit_primitives_rationale_40": "One- to five-frame anamorphic star at the contact frame; sells the hit more than" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L40 | neighbors=[flash()] | lang=en
- "vfxkit_primitives_rationale_418": "Default inputs of a beam recipe (effect(..., inputs=beam_inputs(8))): what the e" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L418 | neighbors=[beam_inputs()] | lang=en
- "vfxkit_primitives_rationale_423": "Sustained cross-fade: a new instance every `interval` frames, each fading in and" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L423 | neighbors=[held()] | lang=en
- "vfxkit_primitives_rationale_434": "Sustained energy beam along local +Y from the effect's origin to a point @In0 aw" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L434 | neighbors=[beam()] | lang=en
- "vfxkit_primitives_rationale_44": "Motion-aligned streaks thrown from a sphere; eased travel makes them burst fast," | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L44 | neighbors=[radial_sparks()] | lang=en
- "vfxkit_primitives_rationale_484": "Velocity that points a DirectionalBillboard sprite from start toward end without" | kind=entity | source=.agents/skills/effekseer-vfx-skill-main/skills/effekseer-vfx/scripts/vfxkit/primitives.py:L484 | neighbors=[_aim()] | lang=en

## Instructions

Write a single JSON object mapping each node id to a one-sentence description
to: /vercel/sandbox/repo/.engram/description-instructions/batch-203.json

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
