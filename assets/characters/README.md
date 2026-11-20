# R6 preparation: file guide

**Latest animation pass:** see [`animation-v2/README.md`](animation-v2/README.md) for the revised BoyR6 and BlockyR6 clips and matching `transitions-v2/`. The `animation/` and `transitions/` sections below describe the retained earlier pass.

The source, earlier `_poko` adaptations, and preservation-first copies have not been deleted or overwritten. `base/BoyR6_Adapted.blend` and `base/BlockyR6_Adapted.blend` are exact copies of the preservation-first bases. They retain the original materials, separate `customFaces` UV layer, rig, helpers and the added provisional attachment points. The older `_poko` files simplify away the face UVs: use the bases in `base/` instead.

`preservation_baseline_check.json` records SHA-256 comparisons against the previous project archive for the original, legacy adapted and preserved model files.

## Animations — one file per clip, per rig

Open one file under `animation/`, select the armature and play its timeline at 24 fps. Every clip was created by reopening its rig's separate Adapted base; clips are not combined in one file. Each file retains the rig, meshes and attachments and contains one active, named action.

| Clip | Playback frames | Type |
|---|---:|---|
| Idle | 1–96 | Loop |
| Walk | 1–32 | Loop, in place |
| Run | 1–22 | Loop, in place |
| Jump | 1–41 | One shot; anticipation, takeoff, flight, landing, recovery |

The three looping clips have a duplicate of frame 1 keyed immediately after the playback range. +Y is the character's face/forward side in the source coordinate system. Walk and run are in-place: translate the character separately when previewing travel. See `docs/R6-animation-review.mp4` for a sampled 12-fps BoyR6 review; clips in that video are cut together, not blended. The clips use the existing driven leg IK and foot-follow controls; Blender constraints and drivers do not automatically become portable runtime animation. Bake and validate evaluated deform-bone motion when an export target is selected.

`animation/animation_validation.json` records the evaluated loop endpoint matrix differences, movement checks, and lowest leg mesh point at integer frames. All six looping endpoints matched; at integer frames the lowest evaluated leg-mesh point was no more than 0.0001 Blender units below zero. The separate half-frame checks found a worst minimum of about -0.0031. The floor used is Z=0. These are numerical smoke tests, not a guarantee of planted feet, seamless playback at every subframe, comfortable timing, or smooth blending between separate clips. The Boy source continues to emit its pre-existing finger-driver warnings. The animations are initial authored passes: review full playback, feet, deformation, timing, and clip-to-clip blends before calling them game-ready.

## Transition clips

`transitions/` holds separate, one-shot, nine-frame control-space transitions for Idle ↔ Walk, Walk ↔ Run and Idle ↔ Jump, for both models. Each has its own `.blend` and one active action; these are not combined with the main animations. They connect specified poses (frame 1 of each loop, frame 1 of Jump on entry, frame 41 on exit). `transition_validation.json` records endpoint matrix matches and sampled foot-floor checks. They do not automatically play between clips and are not proven smooth from arbitrary gait phases; inspect playback and foot sliding and choose phase-aware blending when assembling an animation system.

## Faces

`face-packs/` contains ten named PNG overlays and a Face Library blend for each rig. The library packs all ten images and selects `face_happy` as an example. To change it, open the head material, enter the `customFacesTex_RRS` group and select another `face_*` image in `Image Texture.001`. In the main material, `RRS-CCSwitcher` is set to 0 for the overlay; set it back to 1 for the original base face. The overlays include a neutral-gray cover for the source's baked smile, so they are tuned to this supplied neutral head color; recolored skin needs a matching cover or a different compositing approach. Faces are textures, not separate face meshes. See `docs/R6-faces-preview.png`.

## Starter clothing

`clothing/BoyR6/` and `clothing/BlockyR6/` each contain single-item `Shirt`, `TShirt` and `Pants` blend copies, plus `Shirt_Pants` and `TShirt_Pants` outfit copies. The clothing uses per-mesh PNG UV overlays, packed in each blend and also supplied as separate named PNGs. It is painted clothing, not modeled garments. Per-mesh materials preserve the source material and add an alpha mix; the source base and face layers are not overwritten. Inspect seams, fit and deformation in motion, particularly on the shoulders and waistband. See `docs/R6-clothing-preview.png`.

To use a clip with an outfit in Blender, open the outfit copy, **File → Append** the matching rig's action from the desired animation file (`Action` section), and assign it to the armature in the Action Editor. Set the `rigmeta3` bone custom properties `LLIK`, `RLIK`, `LLFF` and `RLFF` to 1, and set the scene's frame range and 24 fps as above. Save as a new file. To add a face, load a `face_*.png` into the head material's face group and set the switch to 0. Do not overwrite the bases.

## Validation and reproduction

- `animation/animation_subframe_check.json` samples the lowest leg point at half frames; this is not continuous collision or foot-sliding validation.
- `clothing/append_action_check.json` records append tests of Walk and Jump onto the shirt-and-pants outfit for both rigs; sampled pose matrices matched. This is not a test of all clips or clip-to-clip blending.
- `clothing/look_validation.json` verifies both face libraries contain 10 packed images, and the outfit blends contain their expected packed overlay nodes while retaining the head UV layers.
- `animation/build_animations.py` recreates the clips from `base/` and refuses to overwrite existing output files. Run on a separate project copy with no existing animation output files. `animation/validate_animations.py` reopens the clips and overwrites `animation_validation.json`; `clothing/validate_looks.py` similarly overwrites `look_validation.json`.
- Blender 5.2.1 was used. The tests and visual previews are Blender checks; no engine, live gameplay, action blending, or final interchange export was tested.
