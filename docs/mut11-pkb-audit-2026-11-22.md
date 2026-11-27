# MUT-11 and `.pkB` progress audit — 2026-11-22

## Outcome

The current i32 Mute subset supports persistent `@state` variables, transactional tick execution and declaration-order xxHash64 seed-zero state hashes. The MUT-11 seed criterion—two runs have identical hashes—passes locally for 10,000 ticks, including source and `MUTP` bytecode execution. This is not completion of full Mute state, replay persistence, native target verification or G1/G2.

The `.pkB` work is deliberately a **non-authoritative unsigned schema preview**, not a `.pkB` generator or validator. It emits deterministic CBOR containing the current declared state field names and i32 type. It provides no authority policies or security guarantees and must not be used for publication or request validation.

## State behavior

- `@state var name:i32=integer;` declarations precede functions, require explicit types and literal initializers and are limited to 256. Duplicate names and invalid initializers are rejected. Local variables and parameters shadow state names under the existing scope/mutability rules.
- `run_stateful_program` and `run_stateful_program_bytecode` operate on host-owned `ProgramState`. Initialization and successful changes commit together; parse errors, traps, budget exhaustion or a schema mismatch leave the input state unchanged. Schema matching checks field count, declaration order and names, not source identity; no migration is performed.
- `run_program` and `run_program_bytecode` remain fresh-state calls. The debug ImGui console retains a state context only for `@state` submissions and has a Reset state button. Arithmetic, print and stateless functions leave it alone.
- State values are serialized in declaration order as little-endian i32 for xxHash64 seed zero. The initial hash deliberately excludes field names, program identity, tick and session. It is non-cryptographic and is **not** the authority's projected hash. Only i32 state is supported. Initialization, parsing, compiling, state copying and hashing are not charged against the semantic VM budget, so this is not a production sandbox.
- The independently generated hash vectors include lengths 0 through 1,024 bytes, seed zero and a nonzero seed, and a signed-value state golden. Tests cover mutable state, recursion, shadowing, source/bytecode parity, state order, 256-field limit, schema mismatch, corrupted host state, budget and divide-by-zero rollback, and first-tick failure.

## Schema preview and `.pkB` boundary

`make_pkb_schema_draft(source)` and `poko_mute_pkb_schema_draft <source> > draft.cbor` emit canonical CBOR describing syntactically valid initial state declarations. The preview is tagged `poko.pkb.schema-draft`, is unsigned, has no `PKB1` header, and lacks IDs, replication declarations, quantization, authority policies, rules, capabilities, game identity, package hashes, migrations and signatures. No field is implicitly `Trusted`, `Validated`, or `ServerOwned`; fields are not assumed replicated. Neither source inspection nor the preview is a complete compiler or verifier.

Its canonical bytes were compared with independent `cbor2` 5.6.5 output for both a two-field golden and a 25-field example with Unicode and longer names. CLI tests check rejection and absence of output on malformed/oversized sources. The authority contract has since landed: BAK-05 loads the .pkB schema into `PkbAuthority` (validation, policies, projected-hash packing), BAK-06 runs fixed-cost assert rules over proposals, and BAK-07 gates the projected hash and sequence window. Remaining future work is the Worker-side serving layer and the signing/identity flow described in `docs/plan/05-pkb-validation.md`.

## Evidence

- Linux GCC strict warning build: 63/63 tests passed; AddressSanitizer/UBSan: 63/63 passed.
- Software Vulkan/Xvfb suite: 86/86 passed. A separate synthetic X11 interaction typed an `@state` program twice and observed 1 then 2; Reset state restored the first result, with zero reported graphics errors/warnings. An initial screenshot comparison included the newly visible scrollbar and was corrected to compare just the output text region; this was a test-harness issue, not evidence that the first run passed.
- 10,000 successive hashes from `mute/tools/state_determinism_probe.cpp` matched on GCC x64, Zig/Clang x64 and Zig/Clang ARM64 Linux under QEMU; the SHA-256 of each 10,000-line hash trace is `314e04b003f446b0f670a86fb0162a665d13ba4c5d6a8daf15370fff9f8a202a`. The state unit executable also passed under emulated ARM64.
- The state and preview tool cross-compiled to a Windows x64 PE using Zig/Clang. It was not run on Windows and is not an MSVC build. Physical Android, Windows/MSVC, supported devices, a full realistic G1 replay, G2 and hosted CI are not verified.
- Existing toolchain caveat: Zig 0.13's libc++ lacks the floating-point `from_chars` overload used by the evaluator; the cross-build used Zig 0.15.2. Graph extraction skips unsupported file types and reported a partial parse at an existing preprocessor conditional in `imgui_demo.cpp`; the graphics compiler and tests passed. Existing graphics dependency CMake deprecation warnings and intermittent X11 image-capture behavior remain.

## Follow-up

MUT-12 is next: an explicit, bounded, versioned state save/load and replay contract with round-trip and malformed-input tests. The hash representation alone is not a replay file. Production `.pkB` work must follow its dependencies and must not pretend the unsigned preview is a security artifact.
