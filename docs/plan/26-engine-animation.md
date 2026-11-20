# 26 — Engine animation

## Skeleton

A skeleton is a hierarchy of joints with a bind pose stored as local transforms. Joints have stable string IDs interned at load. Skin weights are stored per vertex with up to four influences, normalized at import. Skeleton data lives in PokoMesh and is shared by all meshes using it.

## Animation clips

PokoAnim stores tracks as quantized keyframes with delta encoding. Position tracks use 16-bit quantization in local bounds, rotation tracks use octahedral encoding, scale tracks use 12-bit. Keyframe times are fixed-point tick indices, not wall-clock seconds, so playback is deterministic when the animation affects validated state. Clips carry named event markers that Mute can subscribe to through `@on(AnimEvent)`.

## State machine

An animation state machine is data: states reference clips, transitions declare conditions and blend durations, and parameters are typed values supplied by Mute. States and transitions are authored in Studio as a graph, stored in `.pk`, and compiled into a flat table for runtime. No script execution inside the machine.

| Parameter type | Use |
|---|---|
| bool | Enter a state |
| f32 fixed | Blend thresholds, speed |
| int | Variant selection |

Transitions are evaluated once per sim tick when the animation drives validated state, or per frame when it is cosmetic. The mode is declared per state machine in `.meta`.

## Blend trees

AA feature. A blend tree combines multiple clips by a parameter with 1D or 2D weighting, or additive layers with masks. Output is sampled into a scratch pose buffer. Blend trees are data-only and compile to the same flat table as state machines.

## Skinning

GPU skinning in the vertex shader using a bone matrix texture. The RHI allocates one matrix buffer per skeleton instance, updated once per frame from the evaluated pose. Software skinning exists only for debug and for the authority when animation affects validated state; the sim path uses fixed-point joint transforms from a reduced skeleton.

## IK

AAA partial. FABRIK for limb chains and CCD for look-at. Chain length capped at four joints. IK targets are entity handles or fixed offsets. IK output for cosmetic limbs is visual-only; IK that writes a validated transform must use the fixed-point sim path and is limited to one chain per entity.

## Procedural animation

Procedural layers add noise-driven offsets to joints from sim time and a seeded RNG. They cannot move an entity's root or change a validated transform. Aim and look-at layers for characters are `Validated` and use the sim path so the authority can reproduce the pose.

## Animation events

Named markers in clips emit events at fixed tick indices. Mute subscribes with `@on(AnimEvent)` and receives `{clipWord, marker, tick, entity}`. Events from cosmetic animations are `Trusted`; events from sim animations are `Validated` with a sequence number. A missed event due to a dropped frame is replayed from the tick log, not skipped.

## Retargeting

AA feature. Retargeting maps one skeleton to another by joint-name correspondence with documented limitations. Missing joints fall back to the parent transform. Retarget data is stored as a `.meta` setting, not baked clips, so the same clip works across character types.

## Streaming

Clips and skeletons load through the resource system like any other asset. A state machine can run with a missing clip by holding the last pose for up to 2 seconds, then falling back to the bind pose with a warning. Missing clips never crash or freeze the frame.

## Determinism boundary

If an animation drives a validated transform, it uses fixed tick indices, fixed-point joint transforms and the sim path. A developer marking such a state machine cosmetic gets a `.pkB` policy error. Cosmetic animation is free to use float interpolation and any visual feature.

## Debug features

Skeleton overlay with joint names, current state and transition conditions, parameter values, pose diff against bind pose, clip timeline with event markers, and a toggle between sim and visual pose to expose desync. All available in ImGui and Studio.

## Limits

Joints 128 per skeleton, influences 4 per vertex, clips 512 per game, blend tree depth 8, IK chain length 4, sim-animated entities 128 per slot.
