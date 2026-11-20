# 24 — Engine physics

## Two solvers, one contract

| Solver | Precision | Runs | Writes |
|---|---|---|---|
| Sim physics | Q16.16 fixed-point | Client and authority inside `.pkB` | Validated state only |
| Visual physics | f32 | Client only | Trusted cosmetic state only |

Mute `physics.raycast` and `physics.body` route to the sim solver when the target field policy is `Validated` or `ServerOwned`, and to the visual solver when it is `Trusted`. The compiler decides from the field policy; a developer cannot choose the wrong one by accident.

## Fixed-point arithmetic

Q16.16 stores a value in a signed 32-bit integer with 16 fractional bits. Addition and subtraction are plain integer ops. Multiplication uses 64-bit intermediate and shifts right 16 with round-toward-zero. Division promotes to 64-bit and checks for zero. Square root uses integer Newton iteration with a fixed iteration count and a documented error bound.

Trigonometry uses a lookup table of fixed size with linear interpolation, deterministic across all platforms. No libm call exists in the sim path. The determinism lint rejects a float literal in sim physics code.

Every fixed operation has a unit test with known inputs and exact expected outputs shared across x64 and arm64.

## Collision shapes

Sim supports sphere, AABB, oriented box, capsule and convex hull up to 64 vertices. Triangle meshes are supported for static geometry only through a precomputed BVH built at import time. Visual physics adds soft bodies and cloth.

## Broadphase

Sweep and prune on the X axis with axes re-sorted incrementally each tick. Bodies are inserted and removed through a deterministic command buffer. Pair generation is sorted by body index; the order of contacts fed to the solver is part of the determinism contract and must not depend on thread scheduling.

Parallel broadphase is allowed only if results are gathered into index order before the solver runs.

## Narrowphase

GJK for convex-convex distance, EPA for penetration depth when overlapping. Sphere and box have specialized fast paths. Contact manifolds carry up to four points, generated in a stable order by sorting on penetration depth then point index. Coincident contacts are merged with fixed tolerances. No epsilon value may depend on float rounding.

## Constraint solver

Sequential impulse with warm starting and Baumgarte stabilization. Iteration count is fixed and declared in `.pkB` limits, default 8 for sim and 12 for visual. Constraints are split into islands; islands are solved in island-id order. Within an island, constraints are sorted by body index. Split impulses are clamped with accumulated impulse caches that persist across ticks.

Restitution and friction use fixed-point coefficients. A sleeping body has zero velocity in the solver and wakes only on a deterministic contact event.

## Character controller

Kinematic capsule with ground detection by shape cast, step-up height, slope limit and a maximum depenetration distance. Movement is applied as a velocity target through the sim solver, not by directly setting position, so the `position_step` validation rule agrees with what the controller can physically produce. A direct position set outside the controller is rejected by the authority.

## Joints

A tier: fixed, hinge and distance joints with optional limits. AA adds spring and slider joints with motors. A joint stores its constraint rows in a stable order; motors use fixed-point target velocities. Breaking a joint requires an explicit impulse threshold declared by the developer and is a validated event.

## Queries

Raycasts and shape casts use the same broadphase and BVH as collision detection, so a query result matches what the solver sees. Results are sorted by distance then body index. Overlap queries return entity handles sorted by index. All query functions are deterministic and available to Mute through hostcalls.

## Soft body and cloth (AAA partial)

Mass-spring lattices with fixed spring constants and Verlet integration in the visual solver. Cloth is a grid constraint system with wind from sim time. Neither can affect validated state; a developer who tries to bind a soft-body vertex to a `ServerOwned` field gets a compile error. Soft body is the headline AAA physics feature and remains feature-flagged.

## Determinism rules

1. No float anywhere in sim code, including constants.
2. No libm, no SIMD, no atomics determining outcomes.
3. All iteration in index order.
4. All contacts and constraints sorted before solving.
5. Fixed iteration counts, no convergence-based early exit.
6. Island order determined by the lowest body index in the island.
7. A 10,000-tick replay produces identical state hashes on x64 and arm64.

G2 is the hard gate. If any rule is broken, stop before Slice B.

## Debug visualization

Collider wireframes, contact points and normals, island coloring, solver iteration count per body, broadphase pair counts and query rays. Sim and visual systems can be toggled independently so a desync is visible immediately.

## Limits

Sim bodies 512 per slot, contact points 4 per manifold, solver iterations 8 sim / 12 visual, convex hull vertices 64, joints 128, soft-body nodes 256 visual only.
