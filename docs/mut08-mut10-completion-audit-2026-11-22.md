# MUT-08–10 completion audit — 2026-11-22

## Outcome and scope

The stated seed criteria now have implementations and local evidence for the **currently implemented Mute subset**: compiled register execution with matching existing-program behavior (MUT-08); pinned deterministic sine and cosine with x64/emulated ARM64 comparison (MUT-09); and binary and canonical-text bytecode round trips (MUT-10). The full Mute v1 language, production `.pkB` compiler, independent verifier, platform certification and G1/G2 remain separate work. This audit is not proof of no defects or a sandbox certification.

## MUT-08: program execution

`run_program` parses the existing bounded i32/bool functions-and-control-flow subset, compiles it into internal register instructions and executes them. The old evaluator is retained as a differential oracle and its arithmetic parser is still used for integer literals. Tests compare success values, diagnostics and source positions and budget boundaries across functions, recursion, scopes, short-circuiting, loops, dead paths and register pressure. Console programs use this path; arithmetic-only and the limited top-level print bridge retain their earlier paths. The semantic step budget does not cover compilation, allocations or host time; this is not a security sandbox.

## MUT-09: deterministic math

The host C++ `deterministic_sin` and `deterministic_cos` use pinned musl 1.2.5/fdlibm-derived local kernels, strict floating-point build flags, round-to-nearest and gradual-subnormal checks, and canonical non-finite output. The current Mute source subset has no float/mathematical host API; exposing the broader approved standard library remains later work.

The independently generated 312-case/624-result reference fixture passes a 2-ULP sampled tolerance. An earlier comparison of 20,348 inputs matched both functions bit-for-bit among x64 GCC, x64 Zig/Clang, ARM64 Linux under QEMU, and x64 sanitizer builds. This is sampled evidence, not a proof of global error bounds or native Windows/Android behavior. The 10,000-tick replay needs future state/hash infrastructure and actual target environments; G1/G2 are not closed.

## MUT-10: compiled-program and word-code round trips

`compile_program_bytecode`, `run_program_bytecode`, `disassemble_program_bytecode` and `assemble_program_bytecode` round-trip and execute the complete **current** i32/bool subset, including function calls, short-circuit logic and loops. `MUTP` snapshots retain source, function streams, internal instructions, source positions and text operands. Execution decodes the serialized instructions, after first recompiling the embedded source and requiring the exact canonical snapshot. This is deliberately restrictive until MUT-27: it incurs a compile per load, includes source, is not authenticated, and is neither a production verifier nor an untrusted-mod sandbox. The snapshot is not `.pkB` and does not promise long-term compatibility. Binary truncations, mutations, random malformed inputs, diagnostic and budget preservation, and canonical listing round trips are tested.

The separate low-level `MUTB` codec and register machine implement the chosen short/long branch scheme in `docs/plan/04-mute.md`. Short form is signed 16-bit `b:c` relative to the following word. Long form is a two-word `ext_prefix` pair with a signed little-endian 32-bit displacement relative to the end of the pair. Payloads are not branch targets and the pair costs one interpreter step. The compiler policy for the future word-ISA emitter is short when possible, long otherwise. Tests cover both directions beyond short range, branch boundaries, conditional outcomes, invalid extensions, truncated pairs, payload target rejection, out-of-range targets, and binary/text goldens. The current internal `MUTP` snapshot's signed 32-bit instruction-relative operands are a different format, not an implementation of the final word-ISA emitter. MUT-26 still owns full source/IR lowering to the word ISA and MUT-27 independent type, control-flow and capability verification.

## Verification

- Linux GCC strict `-Wall -Wextra -Wpedantic -Werror`: 61/61 tests passed.
- Linux ASan/UBSan: 61/61 tests passed.
- Software Vulkan/Xvfb graphics and console suite: 84/84 passed. This is software rendering and synthetic input, not a physical device.
- Program and low-level bytecode unit-test executables passed under QEMU ARM64 Linux using Zig/Clang 0.15.2. The `mute/tools/program_bytecode_probe.cpp` example executed to 78 and produced identical canonical bytes across GCC x64, Zig/Clang x64 and emulated ARM64 Linux; the SHA-256 of its hex output is `350f02d4ae9f1bd6f8f49da596b05ce2a5eeeeb8328e4d784de28551cd81bb59`.
- A Zig/Clang 0.15.2 cross-build linked an x64 Windows PE executable using the program VM and math sources; it was **not run** and is not a native MSVC build or determinism result.
- The older Zig 0.13 bundled libc++ cannot compile the existing floating-point `std::from_chars` evaluator path. Zig 0.15.2 compiled it successfully. This is a toolchain compatibility finding; do not infer support for an untested Android NDK or MSVC toolchain.

## Remaining gates and risks

Physical Android ARM64 and native Windows/MSVC builds and runtime checks remain outstanding. The source snapshot requires recompilation and cannot execute a program without its source. General print hostcalls, float values in the source VM, state/hash, full language and API support, production compiler/verifier and sandbox resource accounting are not implemented by these tasks. Existing X11 screenshot intermittency and graphics-dependency CMake deprecation warnings remain recorded. Graph extraction skips unsupported files. The next queue item is MUT-11 (`@state` and state hash), without treating the target-platform or phase gates as waived.
