# MUT-13 — Mute v1 scope and API matrix (DRAFT for owner review)

**Status: draft proposal, not approved.** MUT-13's done-when is an
*owner-approved* versioned matrix. This document is the proposed matrix;
each row needs an explicit owner decision (include / defer / change) before
MUT-14 may start. Nothing here waives G1/G2, the existing gates, or the
security/authority model in `04-mute.md` and `30-mute-v1-completion.md`.

## 1. Language feature matrix (proposed v1 decisions)

| Area | Spec (`04-mute.md`) | Proposed v1 decision | Rationale / testable criterion |
|---|---|---|---|
| Scalar types | bool, i8–i64, u8–u64, f32/f64, string | **Include** all listed scalars | Already partially exercised; per-type goldens required |
| `option`/`result`, `?` | some/none, ok/err | **Include** | Core error model; needs parser+VM+typecheck tests |
| `array<T>`, `map<K,V>` (ordered B-tree), tuple | composites | **Include** | Determinism requires ordered map; B-tree only |
| `struct`, `enum` | value types | **Include** | Aggregate VM work is MUT-22 |
| Engine types vec/mat/quat/entity/asset/ui.Node/body | engine | **Defer engine handles to API phase**; math value types include | Handles are capabilities; land with MUT-42–48 |
| `let`/`var`, no subtyping except never | immutability | **Include** | Already in seed subset |
| Control flow if/while/for..in/loop/match/guard/break/continue/return | full set | **Include all** | `break`/`continue`/`match`/`guard`/`for`/`loop` are new work (MUT-15) |
| `async`/`await`/`spawn`/channels | cooperative concurrency | **Include cooperative subset only**: await, spawn FIFO, no shared-memory races; **defer channels** unless owner wants them v1 | MUT-23; determinism requires FIFO replay |
| Unicode XID identifiers, UTF-8, interpolation `{expr}` | lexical | **Include**; interpolation compile-time resolved | Lexer mostly done (MUT-01) |
| Attributes @state @on @every @replicate @rpc @clientOnly @authorityOnly @validate @deprecated @doc | listed | **Include @state/@on/@every/@replicate/@validate/@deprecated/@doc; defer @rpc/@clientOnly/@authorityOnly decision to networking tasks (MUT-49)** | Capability/authority split needs NET gates |
| Capabilities Net/Physics/Storage/Ui/Asset/Crypto/Log/Time/Replicate/Spawn + attenuation | sandbox | **Include framework; per-module enablement follows API matrix (§3)** | MUT-24 analysis; tokens never in @state/network/.pkB |
| Traps 0x01–0x10 | listed | **Include all defined codes** | Each needs a triggering test |
| Limits (1M instr/tick, 64MB heap, depth 64, 256 regs, etc.) | listed | **Include as v1 defaults; owner may adjust numbers** | Budget accounting policy must be decided (§5) |
| Bytecode ISA 32-bit words, short/long branches | decided in 04-mute | **Include as decided** | MUT-26 lowering; MUTB codec exists |
| Memory model (registers, tick arena, RC heap, entity handles) | listed | **Include** | MUT-22 lifetimes; stale-handle trap 0x08 |
| Determinism contract (IEEE-754, no wall clock, seeded RNG, FIFO async, xxHash64 state, 10k-tick replay) | listed | **Include — non-negotiable** | G1/G2 gates unchanged |
| Compiler passes through .pkB + verify | listed | **Include** | MUT-25–27; .pkB is the production format, MUTB/MUTP are not |
| Mute Library (mute.toml/lock, publishing, 85/15) | listed | **Defer publishing/registry to post-v1 unless owner overrides**; manifest+lockfile format include | Needs backend/legal gates |

## 2. Device and platform matrix (proposed)

| Target | Role | Proposed v1 requirement |
|---|---|---|
| Windows x64 | product target | required: build, tests, G1 replay leg |
| Android arm64 | product target | required: build, tests, G1 replay leg, real-device evidence (not emulator-only) |
| Linux x64 | determinism/test target | required: GCC + ASan/UBSan legs, golden tests |
| Input modalities | — | keyboard/mouse required everywhere; gamepad required on Windows+Android; touch required on Android only |
| OS versions | — | owner to pin: propose Windows 10/11 x64, Android API 26+ arm64-v8a |

## 3. Game-facing API matrix (proposed v1 contract)

Per `30-mute-v1-completion.md` table; each row needs owner sign-off on
inclusion and exact signatures land with MUT-41–54.

| Domain | Proposed v1 | Deferred candidates |
|---|---|---|
| Input/keybinds | tick snapshots, named actions, kbm+gamepad(+touch on Android) | touch gestures beyond tap |
| UI | nodes, state bindings, events, toast | decorators beyond spec list |
| Physics/character | raycast, overlap, approved body ops; deterministic sim vs cosmetic split | ragdoll/soft-body |
| World/scene/camera | stable entity queries, transforms, camera controls, stale-handle errors | streaming |
| Assets/audio/animation | load/prefetch/release/metadata, approved audio, animation params/events | procedural audio |
| Networking/storage | approved messaging/replication + namespaced storage w/ authority rules | player-to-player arbitrary RPC beyond approved set |
| Stdlib | deterministic math/time/RNG, strings, collections, crypto (sha256/hmac/sign/verify) | compression, regex |
| Events/lifecycle | subscriptions, startup/teardown, deterministic ordering | signal debouncing policies |

Raw device events are local/cosmetic; only tick-snapshot or authority-
validated data enters replay. This matches the existing authority model.

## 4. Compatibility matrix (proposed)

| Question | Proposed v1 answer |
|---|---|
| Luau/Roblox source compatibility | **None.** Mute is its own language; no parity claim |
| Roblox API parity | **None.** API names/signatures are Poko's own |
| `.pkB` package format | New signed format; `MUTB`/`MUTP`/`MUTS` are internal/test formats, never shipped as `.pkB` |
| Bytecode versioning | `muteVersion` semver-by-word in manifest; decoder rejects unknown versions |
| State snapshot format | `MUTS` stays internal; versioned, no migration promise beyond v1 |

## 5. Decisions that need explicit owner answers

1. **Budget accounting under optimization** (blocks MUT-31): charge stable
   semantic cost, or define versioned budget differences between optimized
   and unoptimized builds? Proposal: semantic-cost accounting so traps fire
   identically.
2. **Channels in v1?** Include or defer (§1).
3. **@rpc/@clientOnly/@authorityOnly** attribute semantics now or with
   networking tasks?
4. **Publishing/registry/85-15** in v1 or deferred?
5. **OS version floors** and exact Android device list for the device matrix.
6. **Limit numbers** — accept spec defaults?
7. **Any spec feature to drop or add** beyond this matrix.

## 6. Testable criteria this matrix implies

- Every "include" row maps to ≥1 positive and ≥1 negative test before its
  MUT task closes; goldens for parser/typechecker where applicable.
- G1: identical 10,000-tick state hash on Windows x64, Android arm64
  (real device), Linux x64. G2: deterministic physics sim unchanged.
- Optimized vs unoptimized builds must produce identical observable
  behavior under the approved budget policy (MUT-31).
- Capability violations fail at compile time with source locations;
  traps fire with documented codes.
- No wall-clock/env/address nondeterminism: seeded replay only.

## 7. Explicit deferrals (proposed)

Channels (pending §5.2), Mute Library publishing/registry, Luau/Roblox
compatibility of any kind, world streaming, procedural audio, touch
gestures beyond tap, `.pkB` signing infrastructure beyond the manifest
format, and any feature not listed as "include" above.
