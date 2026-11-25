# Mute

Mute language, compiler, runtime, standard library and associated tools. MUT-01 has a C++20 lexer, MUT-02 has an arithmetic-expression parser and owned AST, and MUT-03 has an initial arithmetic evaluator. A limited register VM now executes the existing program subset; the full language, production compiler and sandbox are not implemented.

## Lexer

`poko_mute_lexer` is built by default without graphics or external libraries. Include `poko/mute/lexer.hpp` and call `poko::mute::lex(source)`. The result is either tokens or one diagnostic; it owns no references to the source. Tokens carry original byte offsets and 1-based line/Unicode-scalar column positions. CRLF is counted as one newline (bare CR is also treated as a newline); original bytes are not rewritten. `end` is the final token. An initial BOM and malformed UTF-8 are rejected, including inside comments. Identifier tables use vendored Unicode 15.1 XID_Start and XID_Continue. In accordance with the current specification, `_` is not an identifier start.

Strings are returned as one raw token: braces, nested quotes and comments in interpolations are balanced, but expressions are **not** tokenized, parsed, type-checked or evaluated. The initial implementation recognizes `\\`, `\"`, `\n`, `\r`, `\t`, `\0`, `\{`, `\}` escapes; unknown escapes are rejected. String text cannot contain an unescaped physical newline. `//` and non-nesting `/* ... */` are discarded; `///` is a token. Numeric tokens recognize decimal, `0x`, `0b`, and `0o` integers and dotted decimal floats, with `i8/i16/i32/i64/u8/u16/u32/u64` and `f32/f64` suffixes respectively. Exponents, separators and float suffixes on undotted numbers are not currently supported. Range and dot are separate from numbers unless a dot is followed by a decimal digit. Numeric range checks and default types belong to later stages.

The [initial lexical contract](LEXICAL-CONTRACT.md) records exact choices where the specification is silent. Additional syntax, lexer recovery and full language conformance are not claimed. The MUT-01 token-golden criterion passes locally; formal gate acceptance remains pending hosted and target-platform verification. See [progress and test evidence](../docs/mut01-progress.md), the [Mute specification](../docs/plan/04-mute.md) and [work queue](../docs/plan/02-work-queue.md).

Unicode 15.1 `DerivedCoreProperties.txt` and the Unicode license are in `data/unicode/`. Regenerate or check the deterministic pinned tables with `python3 mute/tools/generate_unicode_xid.py` or `--check` from the repository root.

## Arithmetic parser

`poko_mute_parser` builds on the lexer and parses one arithmetic expression into an owned AST. Its exact grammar, precedence, error behavior, source spans and deterministic dump are documented in [ARITHMETIC-PARSER.md](ARITHMETIC-PARSER.md). The AST-golden acceptance criterion passes locally; hosted/target-platform gates remain open. Evaluation is MUT-03, not part of this parser.

## Arithmetic evaluator

`poko_mute_evaluator` evaluates the arithmetic AST with checked integer operations and guarded floating-point operations. [ARITHMETIC-EVALUATOR.md](ARITHMETIC-EVALUATOR.md) documents supported types, explicit limitations and resource requirements. The [MUT-01–03 audit](../docs/mut01-mut03-audit-2026-11-22.md) records the safety fix and remaining gates.

The MUT-03 follow-up adds floating remainder, a configurable source-byte limit and read-only host numeric bindings; see [evaluator contract](ARITHMETIC-EVALUATOR.md) and [follow-up audit](../docs/mut01-mut03-followup-audit-2026-11-22.md). These are not a full language VM or sandbox.

## Debug console

The optional debug ImGui demo offers a single-entry console for arithmetic and initial programs. See [MUT-04 progress](../docs/mut04-progress.md) for build steps, limitations and validation. Program inputs use the initial register VM; arithmetic-only inputs and the top-level print bridge retain their earlier paths. This is not the full engine console or a production sandbox.

## Debug print hostcall

The demo accepts a limited top-level `print(...)` call and displays a bounded log. See [MUT-05 progress](../docs/mut05-progress.md) for exact syntax, build steps and limitations.

## Initial functions and locals

`poko_mute_program` provides a bounded i32/bool program subset with local variables and recursion, compiled to an internal register VM. See [MUT-06 progress](../docs/mut06-progress.md) for syntax, limits, integration and missing language features.

## Initial branching and loops

The program VM supports an initial bool/i32 control-flow subset and bounded `while` execution. See [MUT-07 progress](../docs/mut07-progress.md) and the [MUT-01–07 audit](../docs/mut01-mut07-audit-2026-11-22.md) for semantics, limits and remaining gates.

## Initial register VM, math and bytecode

`run_program` compiles the supported program subset into an internal register instruction stream. Arithmetic operations dispatch through the checked i32 register machine; the previous tree-walk implementation remains a differential-test oracle. The debug console uses this path for `fn` programs. The complete current subset instruction stream can round-trip via the source-backed `MUTP` snapshot APIs in `program.hpp`, with a canonical listing and source recompile validation; it is separate from the low-level `MUTB` codec. The full Mute ISA, independent verifier, production compiler and sandbox remain future work.

`poko_mute_math` exposes binary64 `deterministic_sin` and `deterministic_cos`, based on pinned, locally adapted musl/fdlibm kernels. They are host C++ APIs, not yet exposed in Mute source. The wrapper checks its floating-point environment. See the [completion audit](../docs/mut08-mut10-completion-audit-2026-11-22.md), [math provenance](third_party/musl_math/README.md) and [experimental bytecode contract](BYTECODE-EXPERIMENT.md). G1 and ENG-02 have two-target evidence; G2 remains deferred to ENG-60→63.

## v1 standard API core

MUT-51–54 add host-side deterministic math/vector/RNG, tick-only time, UTF-8 strings, bounded ordered collections, fixed SHA-256/HMAC/detached verify, and deterministic lifecycle/game event dispatch. See [V1-API.md](V1-API.md) for the exact surface and approved deferrals. These APIs do not use wall clocks, files, network or entropy.

## Local build tool

MUT-55 adds `poko_mute_build`: a local manifest/lock validator and build-plan printer. See [BUILD-TOOL.md](BUILD-TOOL.md). Registry, fetch and publishing remain deferred by the approved v1 matrix.

## State and schema preview

The initial `@state var name:i32=literal;` subset persists through host-owned `ProgramState` ticks, commits only on successful execution, and hashes declaration-order i32 values with xxHash64 seed zero. The debug console can retain and reset this state. See [state contract](STATE.md) and [MUT-11 audit](../docs/mut11-pkb-audit-2026-11-22.md). The experimental MUT-12 [state snapshot](STATE-SNAPSHOT.md) supports save/load for this subset; full replay and target-device gates remain open.

The [unsigned schema preview](PKB-SCHEMA-DRAFT.md) is canonical CBOR derived from state declarations; it is **not** a `.pkB`, an authority policy or a publishable contract.
