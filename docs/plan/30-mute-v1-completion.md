# 30 — Mute v1 completion plan

**Status: proposed, not implemented or approved.** This extends the canonical work queue with MUT-13–59. MUT-01–12 remain the deterministic-core seed, and their G1/G2 gates remain unchanged. MUT-13 is the explicit owner-review point for the v1 scope, API and compatibility matrix. MUT-08–10 now have substantial initial implementations, with source-program snapshot round trips implemented but real target evidence and the production compiler/verifier still open; current open infrastructure and platform gates are not waived by this plan.

## What “Mute v1 complete” would mean

MUT-59 is a later acceptance review, not an automatic consequence of MUT-12. It requires the owner-approved v1 contract, all required MUT-01–58 work, existing G1/G2, a passing target/platform and security matrix, a runnable representative game slice, documentation, and explicit acceptance of named deferrals. An optimized and unoptimized build must meet the approved observable-behavior and resource-accounting contract. A local test run alone does not close target-device or hosted CI gates. See `02-work-queue.md` for canonical task definitions and dependencies.

V1 means the **approved** subset of the language and APIs, not every conceivable feature or every Roblox service. The current project already specifies more than the seed implements; MUT-13 must identify any spec feature that is included, deferred, or changed and have the owner resolve disagreements. Do not silently weaken G1/G2 or the existing security/authority model.

## Language and compiler

- **MUT-14–23:** Expressions, statements, declarations, names, type checking, aggregate values, generics/traits, imports and cooperative scheduling. The v1 contract decides exact coverage, including `for`, `match`, `guard`, `break` and `continue` and the features already listed in `04-mute.md`.
- **MUT-24–27:** Capability/determinism checks, typed SSA intermediate representation, bytecode generation and bytecode verification. Preserve the existing numbered, whitelisted and typed hostcall design; do not expose arbitrary native calls.
- **MUT-28–32:** Separate, testable constant folding, dead-code elimination and control-flow simplification, followed by differential testing and reproducible benchmarking. Unsupported transformations stay disabled. No optimization should be claimed effective until measured.
- **MUT-33–34:** Source mappings, diagnostics, breakpoints, stepping and stack inspection. Debugging must not silently mutate validated simulation state.

### Optimizer safety contract

The design requires IEEE-754 behavior and state hashes to be preserved. The v1 contract must also specify what is observable: results, error/trap kind and ordering, hostcall ordering and side effects, source diagnostics, asynchronous scheduling and resource-exhaustion behavior. An optimization that removes or moves an operation must not hide an observable trap or side effect.

Instruction budgets are especially important: fewer VM instructions can change when a budget trap fires. MUT-13 must approve a coherent accounting policy—for example, charging stable semantic cost where equivalence is required, or explicitly defining versioned budget differences. Do not claim identical budget behavior merely because the final value matches. MUT-31 depends on MUT-37 so the actual quota behavior can be tested, and must compare optimized and unoptimized execution under that approved policy. Until a transformation meets those tests, it remains disabled for the affected case.

### Branch encoding decision

`04-mute.md` now resolves the former 24-bit-in-16-bit contradiction: short branches use signed 16-bit `b:c` displacements and long branches use an `ext_prefix` plus a signed 32-bit payload. MUTB implements and tests both. MUT-26 must lower the full language into this encoding; MUT-13 still reviews the broader language and compatibility contract.

## Proposed game-facing API coverage

The language and the engine APIs are separate. These APIs need real engine implementations and typed, capability-checked hostcalls; naming and exact signatures below are not a promise of Roblox compatibility.

| Domain | Planned tasks | Proposed v1 contract to review |
|---|---|---|
| Input and keybinds | MUT-38–40 | Tick snapshots; named actions; keyboard/mouse, gamepad and touch as appropriate to the approved device matrix; rebinding and persistence. Decide focus/UI capture, repeat, conflicts, disconnects, replay and validated input policy. |
| UI | MUT-41 | UI nodes, state bindings and events; typed errors and authority restrictions. |
| Physics and character | MUT-42 | Raycasts, overlaps, approved body/character operations, with deterministic sim versus cosmetic policy. |
| World, scene and camera | MUT-43–45 | Stable entity queries, approved scene commands/transforms, camera controls and stale-handle behavior. |
| Assets, audio, animation | MUT-46–48 | Asset lifetimes, approved audio controls, animation parameters and events; cosmetic effects must not mutate validated state. |
| Networking and storage | MUT-49–50 | Approved messaging/replication and namespaced storage with authority, permissions, errors and offline/conflict rules. |
| Standard library | MUT-51–53 | Deterministic math/time/RNG, approved strings and collections, and approved cryptographic operations. |
| Events and lifecycle | MUT-54 | Script subscriptions, startup/teardown and event ordering, respecting capability and determinism rules. |

Raw device events are not an authorization mechanism. The approved input design must say what is local/cosmetic, what enters tick snapshots or replay, and what the authority validates. Test keyboard/mouse, gamepad and touch where each is supported rather than assuming every device exists on every platform. Engine-level input or rendering alone does not prove a usable Mute API.

## Tooling, evidence and release

MUT-55 covers package/build workflow and API documentation; MUT-56 covers editor-facing diagnostics and contextual completion; MUT-57 covers conformance, security and platform evidence; MUT-58 covers a representative game slice. The initial target is Windows x64 and Android arm64 as product targets and Linux x64 as the existing determinism/test target. MUT-13 must approve the precise OS versions, devices, tools, input modalities and required tests. G1's 10,000-tick cross-platform replay and G2's physics determinism remain separate, non-negotiable existing gates.

For the slice, use a small agreed scenario that demonstrates input, UI, entities, physics, camera, assets, audio, animation, approved networking/storage, event handling and replay without bypassing authority or capability policies. Synthetic and mocked tests are useful but do not replace required device and backend tests. Release requires the documented evidence, not just screenshots.

## Dependencies and open decisions

- Tasks span existing waves. Numbers are IDs, **not** a blanket execution order; for example MUT-37 is a prerequisite of MUT-31. A later engine/backend prerequisite such as ENG-63, STU-06, NET-09 or GAME-05 must actually pass before its dependent Mute task can be accepted. Existing wave gates and the one-game-first project rule still apply.
- The proposed plan adds MUT-13–59 (47 entries including the final gate); with MUT-01–12 there are 59 listed Mute entries. No new entry is complete just because it was added.
- MUT-13 must settle exact v1 feature breadth, named APIs/signatures, input device support, optimization/budget semantics, debugger expectations, the bytecode encoding discrepancy and what, if any, Luau source/API compatibility is desired. No one-to-one Roblox parity, source compatibility, delivery date or performance target is currently approved.
- Mute currently has a limited compiled register program subset and debug console; the full compiler, optimizer, general VM hostcall integrations and game-facing APIs do not yet exist. Earlier cross-platform, security and determinism gaps remain open.
