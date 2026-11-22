# MUT-01–12: MUT-12 implementation and three audit passes

## Scope and outcome

MUT-12's initial i32-subset save/load criterion is implemented: a bounded, versioned `MUTS` state snapshot supports memory and binary-file round trips, validates the source/schema, and can resume execution. It is **not** a complete replay system. Three successive reviews were performed over MUT-01–12: (1) language and task behavior, (2) malformed-input/resource/security boundaries, and (3) build, integration, layout and reproducibility. They are targeted engineering reviews by the same agent, not independent third-party audits or proof of zero defects. Earlier task findings remain applicable where noted below.

### MUT-12 contract

`mute/STATE-SNAPSHOT.md` specifies format, exact-source binding, checksum, limits, host responsibilities and migration restrictions. Snapshots preserve i32 state values and declaration ordering, not inputs, external world, VM execution, tick numbers, hostcall outcomes, RNG state or a runtime/compiler build ID. State has no source provenance: save trusts the caller to supply the source that produced it. Restore demands identical bytes, but the caller must also pin the compiler/runtime separately. Source and state are embedded in clear text. No automatic migrations, stable long-term format promise, storage implementation, signing, authority or protection of stored bytes is provided. xxHash detects accidental corruption, not forgery. `MUTS`, `MUTP`, `MUTB` and the unsigned schema preview are distinct; none is a production `.pkB`.

## Audit 1 — Task behavior and feature coverage

Reviewed queue acceptance, contracts, source/VM paths, and tests for every seed task. Results are for the current implementation subset, not full language conformance.

| Task | Review and remaining boundary |
|---|---|
| MUT-01 | UTF-8 lexer and Unicode XID table/goldens present. Initial lexical choices and unsupported syntax remain documented. |
| MUT-02 | Owned arithmetic AST, precedence, locations and golden/reference tests present. It is not the full grammar. |
| MUT-03 | Checked arithmetic, floating handling and evaluator tests present; general cross-device float determinism is not established. |
| MUT-04 | Debug ImGui console dispatches to the appropriate prototype paths; no general production console. |
| MUT-05 | Top-level print bridge and bounded log exist; it is not a general VM hostcall. Interpolation remains unsupported. |
| MUT-06 | Functions, local scope, recursion and error/limit paths are tested in the i32 program subset. |
| MUT-07 | Branch/while, short-circuiting and runaway budget tests present. `break`/`continue` and static checking are not implemented. |
| MUT-08 | Register program VM and retained tree-walk differential oracle are exercised; full compiler and sandbox remain later work. |
| MUT-09 | Pinned host sin/cos and vector/accuracy tests exist; not yet callable from Mute source or proven on all release targets. |
| MUT-10 | Low-level `MUTB` and source-backed `MUTP` binary/text round trips, branches and invalid encodings are tested; neither is the final production ISA verifier. |
| MUT-11 | Transactional state, i32 declarations, schema checks and ordered hash are exercised, including rollback and 10,000 ticks. Hash omits schema, identity and tick; it is not authority authentication. |
| MUT-12 | New memory and disk round trip, exact-source check, signed values, empty/maximum field counts and continued execution tests cover current i32 state. Full replay and migration remain open. |

## Audit 2 — Inputs, safety and edge cases

- MUT-01/02: malformed UTF-8, input limits, deep expressions, source ownership and parser/lexer goldens are tested. Lexer limits and the arithmetic parser do not guarantee complete language coverage.
- MUT-03: integer boundaries, division, float environment and exhaustive 8-bit operation tests cover known numeric hazards; allocation and platform library behavior remain outside semantic evaluation budgets.
- MUT-04/05: input capacity and callback behavior checked; the log escapes ASCII controls and backslashes but not Unicode bidi/format controls. It is not a security-grade sanitizer; UI execution is synchronous.
- MUT-06/07/08: lexical/parse/depth/step caps, local shadowing, control flow, recursion, VM/reference comparisons and randomized malformed source are tested. Step counters do not bound compilation, allocation, host work or wall time; diagnostics and name/type checking remain runtime/path-dependent. Do not execute untrusted code as a sandbox.
- MUT-09: floating-point environment checks and sample vectors are tested, not a formal global error bound.
- MUT-10: header, length, opcode, target, extended-branch, canonical listing, truncation and mutation tests protect the prototype codecs. `MUTP` recompiles source for exact canonical comparison, but this is not authentication or a general verifier.
- MUT-11/12: failed ticks leave state intact; loader returns a fresh state instead of mutating the caller. Snapshot tests cover every single-byte mutation and truncation of a sample, version/reserved bits, bad lengths/counts, trailing bytes, over-limit input, Unicode and 5,000 seeded random byte strings. The checksum can be deliberately recomputed after changing a value, and a regression confirms it is **not** a signature. No security certification or exhaustive fuzzing is claimed.
- Improvements made during this pass: independently generated wire golden added; source and field maximums, valid-checksum wrong schema, and exact byte identity covered. The initial new test failed to compile because it compared variants with non-comparable errors; the test was corrected and rerun. No claim is made that earlier code is defect-free.

## Audit 3 — Integration, layout and reproducibility

- Checked CMake target wiring and the isolated version-integration fixture; the new header/source had to be added to the fixture because the program library is built even with testing disabled. The new unit target is included in normal test builds.
- Files are placed alongside existing counterparts: public API under `mute/include/poko/mute/`, codec under `mute/src/`, and tests under `mute/tests/unit/`. Documentation and queue/layout updates are under existing locations. No directories were moved or removed.
- Updated an outdated README description that called program execution stateless and a state document that said persistence was still future work. Snapshot limitations are explicit instead of implying full replay.
- Continued execution compares 10,000 tick results and state hashes with periodic save/load against an uninterrupted run; the binary-file test uses an actual temporary file. This is one deterministic synthetic program, not the project-wide G1 log or a simulation/physics test.
- Test environment and final outcomes are recorded below. Graphics use software Vulkan/Xvfb; emulation is not a physical Android device. Windows/MSVC, real Android/ARM64, real GPUs, hosted CI, G1 10,000-tick three-platform replay and G2 deterministic physics remain open. The previous intermittent X11 screenshot `BadMatch`, graphics dependency deprecation warnings and incomplete graph extraction also remain open unless separately verified fixed.

## Evidence

- GCC/Linux strict warning-as-error build: 64/64 tests passed; no warning/error lines in this incremental build log.
- Linux ASan/UBSan with leak detection: 64/64 tests passed.
- SDL3/ImGui plus software Vulkan/Xvfb: 87/87 configured tests passed. This is not a physical GPU or native platform test.
- The complete snapshot unit executable, including the independent binary wire golden and 10,000-tick save/load comparison, passed on ARM64 Linux under QEMU using Zig/Clang 0.15.2. This is not native Android, Windows or hosted CI evidence.
- Reference bytes for the `x=-42` fixture were generated independently with Python `struct` and xxHash 3.5.0. The regular test has no Python xxHash dependency. Seeded random tests are finite and do not replace continuous coverage-guided fuzzing.
- The graph refresh succeeded, but skipped 157 unsupported files and warned that it is incomplete. The strict, sanitizer and graphics outcomes above do not establish zero warnings in dependencies or untested configurations.

## Follow-up and release status

The **original 12-task deterministic-core seed** has local subset evidence, not a completed Mute language or release gate. The plan extends to MUT-13–59 and owner-approved v1 scope, compiler, optimizer, verifier, sandbox and APIs remain unfinished. G1/G2 must pass on the required actual platforms before proceeding through the phase gate; G2 also needs deterministic simulation physics. The production `.pkB` and backend authority remain separate work. No task, safety certification or gate has been silently waived.
