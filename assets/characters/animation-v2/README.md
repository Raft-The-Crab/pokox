# R6 animation refinement (v2)

There are separate files for both `BoyR6` and `BlockyR6`, and exactly one active clip per file. These files were generated from the unchanged full `base/*_Adapted.blend` copies; the earlier `animation/` and `transitions/` files were not replaced. The original, adapted, preserved, face and clothing files are retained.

## Clips

| File suffix | Frames at 24 fps | Playback |
|---|---:|---|
| `_Idle_v2.blend` | 1–120 | loop; gentle breathing and weight shift |
| `_Walk_v2.blend` | 1–32 | loop; alternating feet, counter-swinging arms, pelvis/chest movement |
| `_Run_v2.blend` | 1–22 | loop; faster stride with a short flight phase, stronger arm swing and forward lean |
| `_Jump_v2.blend` | 1–44 | one-shot; windup, takeoff, airborne arc, landing and recovery |

Open a file in Blender and play its timeline. Each loop has a duplicate endpoint key immediately after the playback range, so frame 33, 23 or 121 matches frame 1. The clips use the original driven leg IK and foot-follow controls (`rigmeta3` properties `LLIK`, `RLIK`, `LLFF`, `RLFF` = 1); custom controls and face layer were not removed. Walk and run are in-place, with +Y forward. Approximate matching forward travel speeds are 1.025 Blender units/second for walk and 3.37 for run at 24 fps, based on stance-target motion. Real playback speed, turns, and terrain will require further tuning.

The v2 pass changes the previously misaligned arm/leg phasing; adds torso/pelvis counter-motion, heel/toe roll, asymmetric limb motion, airborne run time, and a more deliberate jump arc. It uses half-frame sampled keys for contact corrections. `refined_validation.json` compares loop endpoints and leg-floor heights every half frame. `gait_checks.json` samples quarter frames and reports a worst observed lower-leg point of about -0.008 Blender units (BlockyR6 Run), and no selected mid-stance sole samples above 0.06 units. These are limited numerical checks: they do not prove perfect foot locking, no clipping at every instant, good animation feel, or production readiness.

`docs/R6-v2-side-by-side.mp4` previews both models at 24 fps. It shows the first two seconds of idle and full walk/run/jump clips with hard cuts between clips; it does not demonstrate the separate transitions. Review the animation in Blender, including the side and rear views, before approving it.

## Transitions and combination with looks

`../transitions-v2/` has 12 additional one-shot clips (six per rig). They join Idle ↔ Walk, Walk ↔ Run and Idle ↔ Jump at the designated endpoints. Loop transitions use frame 1; Jump exit uses frame 44. They are not automatically played and are not phase-matched to arbitrary points in the loops. See the `transition_validation.json` and `quarter_frame_checks.json` reports. The older `transitions/` belong to the older clips and should not be used with v2.

To combine a clip with a face or outfit, open a new copy of a matching rig's face or clothing `.blend`, append the corresponding v2 action from its animation file (File → Append → Action), assign it to the matching armature in the Action Editor, enable all four `rigmeta3` IK/foot-follow properties listed above, and set the clip's fps and frame range. Save under a new name. The clips are editable Blender rig actions using constraints; non-Blender interchange requires baking evaluated deform-bone animation and checking the result. No engine is required for this work and no export or runtime test is claimed.

## Regeneration and verification

`build_refined.py` starts from the full adapted bases and refuses to overwrite a matching output. Run it only in an independent project copy prepared for new outputs. `validate_refined.py` and `check_gait.py` reopen the supplied clips and overwrite their JSON reports. The companion `transitions-v2/build_transitions.py` creates the transition copies; `transitions-v2/check_subframes.py` rewrites the quarter-frame report. Blender 5.2.1 was used.
