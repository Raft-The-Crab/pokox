# MUT-08–10 progress and integration audit — 2026-11-22

## Status

MUT-08–10 now have working **initial implementations**, not full production acceptance. The existing program subset runs through an internal register VM; the binary64 sin/cos port has local and emulated cross-architecture evidence; the low-level bytecode subset has encoder/decoder and disassembler/assembler round trips. The formal target-device, full-language, full-program bytecode and phase gates remain open. This audit is targeted, not proof of no defects or a sandbox security certification.

## MUT-08 — register execution of existing programs

`run_program` parses the existing bounded stateless i32/bool subset and compiles it to an internal register instruction stream with 256 value slots per frame, call frames, dynamic lexical scopes, conditionals, loops, short-circuit logic, source positions and semantic execution-budget checks. Function arguments spill into bounded call areas rather than exhausting registers. Integer arithmetic dispatches to the checked low-level register machine. The previous evaluator is retained as a differential-test oracle; integer literals still use the existing arithmetic literal parser/evaluator. Program inputs in the debug console use `run_program`. Arithmetic-only console expressions and the narrow top-level `print` bridge still use their existing separate paths; general print hostcalls inside functions remain unimplemented.

Differential tests compare values, error stage/code/location and budget boundaries against the old interpreter, including recursion, nested scopes, short-circuit errors, loops, oversized/dead expressions and deeply nested argument lists. The budget deliberately preserves the prior semantic node/loop accounting rather than counting each new internal instruction. Compilation, literal handling, allocations and host time are not charged by this budget; the VM is not a security sandbox. Full language syntax, type checker, heap, production capability enforcement and general VM hostcalls remain later work.

## MUT-09 — deterministic binary64 sin/cos

Pinned musl 1.2.5/fdlibm-derived kernels are locally adapted to C++20, with source and license notices in `mute/third_party/musl_math/`. The public C++ API `poko_mute_math` uses fixed coefficients and local range-reduction helpers, not platform `sin`/`cos`; `-fno-fast-math -ffp-contract=off` or MSVC `/fp:strict` is applied to the math target. The wrapper checks nearest-even and gradual subnormal support; infinity and NaN produce a canonical quiet NaN. FP exception flags may change. These host APIs are **not** callable from the current i32-only Mute source language.

A pinned corpus includes zeros, subnormals, large values and non-finite values. Local tests compare 624 outputs against 312 independently generated 500-digit mpmath references with a 2-ULP test tolerance; this is sampled evidence, not proof of a global error bound or correct rounding. Exact golden outputs are also checked. On Linux, GCC x64, Zig/Clang x64 and Zig/Clang ARM64 under QEMU matched **20,348 inputs for both sin and cos** bit-for-bit; the same corpus also matched under ASan/UBSan. ARM64 here is emulated Linux, not a physical Android device. Zig's bundled musl startup emitted a non-prototype deprecation warning. Reproduce the comparison with `mute/tools/compare_math_cross.py`; emulator and toolchain must be supplied independently. Native Windows/MSVC and Android/ARM64 tests, device floating-point environment behavior and 10,000-tick replay evidence remain open.

## MUT-10 — experimental low-level bytecode

The `MUTB` v1 codec uses 32-bit opcode/a/b/c words and an explicitly **signed 16-bit** `b:c` relative branch, because the earlier spec's 24 bits cannot fit those fields. The code validates subset opcodes, reserved operands, zero-register writes and branch bounds. Binary encode/decode and canonical disassemble/assemble/encode round trips pass, including branch boundaries, random streams, malformed input and truncation. The choice is provisional for this subset; it does not establish a stable full-language ABI, long-branch design, constant pool, hostcall encoding or production verifier.

The source-program VM uses a richer internal instruction stream containing borrowed source text and metadata. It is **not** encoded/decoded by `MUTB`; a source-program-to-bytecode-to-execution round trip is still missing. Final ISA approval and MUT-26 compiler/serialization work remain open. Do not persist the experimental format as `.pkB` or treat its shape validator as a capability/type/control-flow security verifier.

## Audit findings and remaining risks

- The version-integration test previously copied only the old source files; its fixture now includes the new VM, math sources and headers. An argument-register pressure case was fixed by spilling completed function arguments. The compiler emits depth traps only on executed paths, so a deeply nested unreachable expression does not fail eagerly.
- The public math API and low-level codec are separately testable but not yet a full Mute standard library or a production sandbox. `@state`, state hashing, serialization and the 10,000-tick replay are not implemented by this change.
- Existing parser/evaluator/console limits and inherited open issues remain, including synchronous UI work, potential allocation failures, the earlier intermittent X11 screenshot harness issue and lack of physical GPU/IME/target-device evidence. The graphics dependencies emit CMake deprecation warnings. The graph extractor skips unsupported files and is incomplete.
- No phase gate is waived. Do not claim native cross-platform determinism or declare the full Mute language finished from these local results.

## Validation

Final Linux GCC strict build: 61/61 tests passed; ASan/UBSan: 61/61 passed; software-Vulkan/Xvfb: 84/84 passed. The source archive is independently clean-built in the final handoff. Tests also cover local real-console interaction under Xvfb/software Vulkan: arithmetic and print, recursion yielding 120, loop yielding 55, and an infinite-loop budget trap. This is synthetic-input/software-renderer evidence, not a physical-device test.
