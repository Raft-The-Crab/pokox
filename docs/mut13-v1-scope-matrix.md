# MUT-13 — Mute v1 scope and API matrix (APPROVED)

**Status: approved by owner.** This is the frozen v1 contract for MUT-14
and later tasks. Changes require a new owner decision recorded here. G1/G2,
the existing gates, and the security/authority model in `04-mute.md` and
`30-mute-v1-completion.md` remain in force.

**Owner decision, 2026-11-25:** Linux x64 is not a product or determinism
target. It was used as a build/test environment and remains useful as an
optional CI lane, but G1/G2 acceptance requires only Windows x64 and a
physical Android arm64 device. The candidate `mute/tests/fixtures/g1-replay.mute`
is approved as the G1 scenario. G2 remains open until the canonical physics
task chain (ENG-60→63) is implemented and verified; no shortcut probe was
accepted. G1 was accepted on 2026-11-25 from the byte-identical two-target
10,000-tick evidence in `two-target-gate-evidence-2026-11-25.md`.

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
| Windows x64 | product target | required: native MSVC build, tests, G1/G2 legs |
| Android arm64 | product target | required: native arm64 build, tests, G1/G2 legs, real-device evidence (not emulator-only) |
| Linux x64 | build/CI environment only | optional: build/sanitizer/golden checks; not a gate target |
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

## 5. Decisions — APPROVED by owner

Approved as recommended on 2026-11-23.

1. **Budget accounting under optimization → semantic-cost accounting.**
   Charge a stable semantic cost per source-level operation, not per VM
   instruction, so optimized and unoptimized builds fire identical traps.
   Rationale: deterministic engines (rollback netcode, input-log replay)
   require bit-identical simulation across builds; WASM fuel metering
   (e.g. Aether's per-instruction fuel) is single-build determinism and
   would let an optimizer silently move a budget trap. The audit already
   flagged this: "do not claim identical budget behavior merely because the
   final value matches." Semantic cost is the only policy compatible with
   MUT-31's differential requirement. *Owner action: approve or pick
   versioned budget differences instead.*
2. **Channels → defer past v1.** `await`/`spawn` in FIFO order covers the
   spec's cooperative model; channels add a second ordering/cancellation
   semantic. Luau's coroutine ecosystem shows the failure modes of
   underspecified scheduling (resume-vs-wrap error swallowing, dead-thread
   reuse, scheduler-owned resumes). One concurrency primitive with crisp
   semantics beats two vague ones. *Owner action: confirm deferral or
   promote channels to v1 scope.*
3. **@rpc/@clientOnly/@authorityOnly → recognized but inactive in v1.**
   Their semantics depend on the networking/authority model (NET gates,
   MUT-49). Shipping half-defined authority attributes would create
   unverifiable security claims. Parser may accept and reject use until
   MUT-49 defines them. *Owner action: confirm or pull semantics forward.*
4. **Publishing/registry/85-15 revenue share → defer post-v1.** Requires
   backend, ledger and legal infrastructure that does not exist yet
   (`docs/legal/` are drafts). `mute.toml`/`mute.lock` manifest format is
   included so packages are representable. *Owner action: confirm.*
5. **OS floors → Windows 10 x64 (1607+) / 11; Android minSdk 26,
   targetSdk 35+.** Google Play has required targetSdk 35 since
   Aug 31 2025 (extension to Nov 1 2025); UE 5.7 ships min install SDK 26,
   Godot 3.6.2 uses minsdk 21 — 26 is the modern middle ground and matches
   64-bit ARM-only baseline. Pin the concrete device list at MUT-57.
   *Owner action: confirm or adjust.*
6. **Limit numbers → accept spec defaults for v1.** 1M instructions/tick,
   64 MB heap/script, 256 MB/game, depth 64, 256 registers, 1,000
   scripts, 50 dependencies, 1,000 hostcalls/tick are consistent with
   comparable sandboxes (WASM runtimes meter ~512 MB; script budgets in
   engine sandboxes run single-digit ms/tick). Tune with MUT-32
   benchmarks, not guesses. *Owner action: confirm or supply numbers.*
7. **Luau/Roblox compatibility → none, confirmed.** Luau is a Lua 5.1
   derivative whose sandbox trades features for safety; its type system,
   scheduler and API surface share nothing enforceable with Mute's
   typed/capability model. Source or API "compatibility" would import
   Luau's constraints without its ecosystem. *Owner action: confirm the
   no-parity stance.*

## 6. Testable criteria this matrix implies

- Every "include" row maps to ≥1 positive and ≥1 negative test before its
  MUT task closes; goldens for parser/typechecker where applicable.
- G1: byte-identical 10,000-tick trace on Windows x64 and Android arm64
  (real device). G2 remains the canonical deterministic sim-physics gate
  across those two targets, to be met through ENG-60→63. Linux x64 is not
  a gate target.
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
