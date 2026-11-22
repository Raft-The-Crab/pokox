# Final audit — MUT-01 through MUT-12

## Outcome

The deterministic-core seed has working, tested **prototype subsets**, but this audit does not establish a complete Mute language, a production sandbox or passing release/determinism gates. One reproducible compile-versus-execution validation inconsistency and two automation-coverage gaps are recorded below. No project code or configuration was changed in this audit, and none of these findings is represented as fixed.

## Findings, in priority order

### 1. Medium — Bytecode compilation accepts an invalid state initializer

`mute/src/program.cpp:342–344` parses and compiles without `prepare_globals`, whereas `run_stateful_program` validates initializers at `:324–327` and snapshot schema inspection calls `prepare_globals` at `:334–336`. Reproduction:

```mute
@state var x:i32=2147483648;fn f()->i32{return x;}f()
```

Observed: `compile_program_bytecode` returns bytes, `run_program` returns `eval:literal_out_of_range`, and `save_state_snapshot` rejects the source. This is consistent with the prototype's lack of full static checking but is an actionable integration inconsistency: tooling must not regard successful bytecode emission as validation that a state declaration can initialize. No unsafe execution or security exploit is claimed from this observation.

**Recommended follow-up:** decide and document the compiler-validation contract; validate declaration initializers consistently during encoding (and maintain canonical decode behavior), then add compiler/run/snapshot regression tests. Consider format and diagnostic compatibility before changing the `MUTP` contract. Complete general name/type verification remains MUT-27 and related planned work.

### 2. Medium — Automated console interaction coverage is absent from normal CTest/CI

`engine/render/tests/integration/test_mute_console_x11.py` and `test_mute_state_console_x11.py` are not registered in `CMakeLists.txt` and are not directly invoked in `.github/workflows/ci.yml`; the workflow runs CTest. The separate console unit tests exist, but they do not replace the real window/input/output path. A manually executed synthetic state-console test is noted in Evidence, but future routine CI runs do not automatically reproduce it. Add an explicitly gated graphics/XTest job or registered integration tests with required X11/Python dependencies, robust startup and timeout handling; do not treat software-renderer results as physical-device coverage.

### 3. Low — Exhaustive arithmetic test is opt-in, absent from configured CI

`CMakeLists.txt:7,427–431` defaults `POKO_MUTE_EXHAUSTIVE_TESTS` to OFF; the current CI configurations do not enable it. It was independently rerun in this audit and passed, but standard test-suite counts do not include its 655,360 cases. Recommend a scheduled or dedicated job enabling the option, with a clear timeout and result reporting.

## Task-by-task audit

| Task | Current evidence and limitation |
|---|---|
| MUT-01 | UTF-8 lexer, Unicode table and token golden tests run; baseline lexer choices are not full language conformance. |
| MUT-02 | Arithmetic AST, precedence and ownership/golden/reference tests run; full grammar remains later work. |
| MUT-03 | Checked arithmetic tests plus the optional exhaustive i8/u8 test passed; complete cross-platform floating behavior is not established. |
| MUT-04 | Debug console and input-path unit tests run. Synthetic UI interaction is separate from normal CI; physical devices and IME remain unverified. |
| MUT-05 | Top-level print and bounded log exist; general VM print/hostcall support and security-grade Unicode-control sanitization are absent. |
| MUT-06 | Current i32 functions, locals and recursion are covered. This is a limited subset, not a complete type system. |
| MUT-07 | Branches, loops, short-circuiting and budget traps are exercised; `break`/`continue` and full static checks remain absent. |
| MUT-08 | Internal register execution is compared with the tree-walk oracle, and this audit added an external model comparison. Semantic steps do not bound compiler, allocation, host time or wall time. |
| MUT-09 | Pinned host sin/cos and sampled math tests exist; they are not exposed as a Mute language API and no physical-platform determinism proof is available. |
| MUT-10 | Low-level `MUTB` and source-backed `MUTP` round trips and malformed data have tests; successful emission is not complete semantic verification (finding 1). Neither is production `.pkB`. |
| MUT-11 | i32 state initialization, order/hash, transaction rollback and schema checks are tested. State hashes omit names, code identity and tick; no authentication or authority is provided. |
| MUT-12 | Bounded `MUTS` memory/file round trips, exact-source restore, checksum and continuation are tested. It is a snapshot, not a complete replay log; exact source, compiler/runtime version pinning, input history, file I/O, atomicity and security are host responsibilities. |

## Evidence and method

- Rebuilt and ran Linux/GCC strict `-Wall -Wextra -Wpedantic -Werror` suite: **64/64 passed**. This is an incremental build, not evidence about untested build configurations.
- Reran Linux ASan/UBSan suite with leak detection: **64/64 passed**.
- Reran configured software Vulkan/Xvfb test suite: **87/87 passed**; this is not a physical GPU or device result.
- Freshly built and ran the opt-in exhaustive 8-bit arithmetic test: **655,360 signed/unsigned operation cases passed**.
- Generated 300 seeded, bounded stateful programs and compared **9,000 ticks** against an independent integer model, source/`MUTP` execution, periodic `MUTS` restore, and zero-budget rollback. The audit-bundle `state-model.cpp` contains the finite test; it is not coverage-guided fuzzing or a proof.
- Reproduced finding 1 with audit-bundle `validation-probe.cpp` (compile success, run `literal_out_of_range`, snapshot rejected).
- The separately invoked XTest state-console interaction passed: state output 1, then 2, then 1 after reset, with 2,400 frames and zero reported graphics errors/warnings. The first attempt did not start because the local `Xvfb` executable was missing from PATH; after correcting PATH the test passed. This is synthetic X11/software rendering and does not establish native UI behavior.
- Existing prior ARM64 QEMU evidence is not a native Android result. This audit did not run Windows/MSVC, physical Android/ARM64, production target hardware, hosted CI, or the full G1 replay/G2 deterministic-physics gate. The known intermittent X11 screenshot `BadMatch`, graph extractor omissions and graphics dependency warnings cannot be declared resolved by these passes.

For the standalone probes, compile from the repository root with C++20, the `mute/include` include directory, and the built `poko_mute_program`, `poko_mute_evaluator`, `poko_mute_parser` and `poko_mute_lexer` libraries, in that order. The model test uses a fixed seed and bounded values; source files in the bundle are review artifacts, not additions to the CTest suite.

## Recommendation

Fix finding 1 and add regression coverage; integrate the manual and optional checks into a suitably provisioned CI lane. Keep G1/G2 and target-platform validation open. MUT-01–12 are the initial seed, not the end of the separately proposed MUT-13–59 v1 plan; continue only in accordance with the existing gate and dependency rules. This is a targeted audit, not an independent certification or a guarantee that no other defects exist.
