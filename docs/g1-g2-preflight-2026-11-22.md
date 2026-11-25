# Post-MUT audit fixes and G1/G2 preflight

## Current gate status

**Historical 2026-11-22 status; superseded by the owner decision recorded in
`mut13-v1-scope-matrix.md` on 2026-11-25.** Linux x64 was removed as a gate
target and remains a build/CI environment only. G1 and G2 now require
Windows x64 and physical Android arm64. The 2026-11-25 gate run accepted G1
from the approved scenario and two-target evidence; G2 remains open pending
the canonical ENG-60→63 physics chain.

At the time below, G1 and G2 were open: the work was preparation, not formal
gate acceptance. G1 then named Windows x64, Android ARM64 and Linux x64; the
local sample used a fixed stateful counter/sum, not a full recorded-input
simulation or cross-platform product replay. G2 required deterministic
simulation physics on x64/arm64; the planned fixed-point simulation physics
was not yet implemented in this seed. Hosted CI, physical targets,
Windows/MSVC, Android and required platform tests were not verified.

## Audit fixes

1. `compile_program_bytecode` now validates each declared initial i32 state literal via the same `prepare_globals` path used by initial execution and schema inspection. The source-backed `MUTP` decoder validates initializers after compiling and before accepting canonical bytes, so legacy snapshots with invalid initializers are rejected as invalid bytecode. Valid v1 encodings remain unchanged; this is not a general type checker or verifier. New regressions cover upper/lower valid boundaries, overflow, wrong literal type, compile/run diagnostic parity, and a previously accepted wire snapshot with an invalid initializer.
2. Added opt-in `POKO_MUTE_X11_INTERACTION_TESTS` to register both existing synthetic console tests with CTest. It requires Linux, testing, the debug ImGui demo, Python Xlib and Pillow, and a supplied X11 display; tests run serially. Linux CI is configured to install pinned Python packages, enable the ImGui/Vulkan demo and these tests, and install software-Vulkan/validation-layer dependencies. The configuration has not been run on hosted CI; if it fails there, investigate rather than claiming completion. This is software/synthetic interaction, not physical/IME proof.
3. Linux CI now enables `POKO_MUTE_EXHAUSTIVE_TESTS`; the test remains opt-in for normal local builds. The original 655,360-case exhaustive integer test is included in the local strict test run.

## Evidence

- Strict GCC warnings-as-errors: 65/65 tests passed, including 655,360 exhaustive signed and unsigned 8-bit cases.
- ASan/UBSan with leak detection: 64/64 tests passed.
- Software Vulkan/Xvfb: 87/87 non-interaction tests and 2/2 newly registered interaction tests passed in separate CTest runs.
- Two Linux x64 runs and an ARM64 Linux QEMU run produced identical 10,000-line fixed-sample traces. The raw LF trace SHA-256 is `314e04b003f446b0f670a86fb0162a665d13ba4c5d6a8daf15370fff9f8a202a`. This is neither native Windows/Android evidence nor a full recorded-input G1 replay.
- A Windows x64 Zig/Clang executable was cross-compiled for the fixed-sample preflight; it has not run on Windows and is not an MSVC build.
- Hosted CI and real-device tests remain unverified. Third-party Diligent CMake deprecation warnings remain.

## Windows laptop run (2026-11-22, MSYS2 UCRT64 MinGW g++ 16.2)

- `mute/src/` was reorganized into per-module subfolders (`lexer`, `parser`, `evaluator`, `math`, `program`, `bytecode`, `vm`, `state`, `pkb`, `console`); CMake source lists, the lexer test include dir, the imgui console source, `tools/version` path copies, `generate_unicode_xid.py` and `test_unicode_generator.py` were updated. Public headers remain flat.
- Dependency-free MinGW Release configure/build succeeded; **64/64 CTest passed**, including all 21 mute tests and `version_integration`.
- Native Windows x64 `state_determinism_probe` 10,000-tick run: LF-normalized trace SHA-256 `314e04b003f446b0f670a86fb0162a665d13ba4c5d6a8daf15370fff9f8a202a`, identical to the recorded Linux x64 and emulated ARM64 traces. This is native Windows fixed-sample evidence only — not a recorded-input G1 replay, not MSVC, not Android.
- Fixed a real Windows/MinGW defect found by the run: `FloatEnvironment` relied on `feholdexcept`, which does not mask SSE exceptions under MinGW-w64, so an unmasked-overflow host environment crashed evaluation with SIGFPE. `FloatEnvironment` now also saves/masks/restores MXCSR on SSE targets. `mute_evaluator_unit` passes; no behavior change on platforms where `feholdexcept` already covers SSE.
- G1/G2 remain open: recorded-input replay on Windows x64, Android arm64 and Linux x64, MSVC leg, hosted CI and the unimplemented fixed-point sim physics are still required.

## G1 replay scenario v0 (2026-11-22, Windows x64 leg only)

- `mute/tests/fixtures/g1-replay.mute` is a candidate recorded-input scenario: five `@state` i32 fields driven by a bounded deterministic mixer (all arithmetic kept far below i32 overflow because Mute integer ops are checked), exercising branches and a bounded `while` loop per tick. The Mute subset has no input hostcall, so inputs are modeled inside the program; the scenario still needs owner agreement before it is "the" G1 scenario.
- `mute/tools/g1_replay_probe.cpp` runs a fixture for N ticks and prints `tick value hash` per line. It is now a CMake target (`poko_mute_g1_replay_probe`) with CTest `mute_g1_replay`, which runs `mute/tests/unit/test_g1_replay.py`: the LF-normalized 10,000-tick trace SHA-256 must equal `a274e74d…ad68` on every platform that runs it — Windows x64 and Android arm64 already verified identical; Linux x64 will be checked by CI. Windows x64 native run (MinGW g++ 16.2, Release libs): 10,000 ticks, exit 0, LF trace SHA-256 `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68`. This is the Windows leg candidate only.
- Android arm64 leg: `g1_replay_probe` cross-compiled with NDK r25 clang 11 (`aarch64-linux-android30`, `-static-libstdc++`, C++2a plus a probe-build-only shim for missing `std::bit_cast`/float `std::from_chars` — repo sources unchanged) and run on a physical Xiaomi 24117RN76G (tanzanite, arm64) via adb. 10,000 ticks, exit 0, LF trace SHA-256 `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68` — **byte-identical to the Windows x64 trace**.
- Android arm64 unit suite: nine Mute test binaries (state, program, evaluator, snapshot, bytecode VM, parser, lexer, deterministic math, lexer contract) cross-compiled the same way and run on-device — **9/9 pass**. An earlier `evaluator_test` failure was a manual-build artifact (missing `POKO_MUTE_FP_FLAGS_CONFIGURED=1` and FP hardening flags that CMake injects), not a bionic fenv defect; with the correct flags it passes. Android `std::from_chars` float shim needed one fix: bionic `strtof` sets ERANGE for representable subnormals, so the shim only reports `result_out_of_range` on true overflow/underflow-to-zero.
- Linux x64 leg could not run on this machine (no WSL distro, no Docker). G1 remains open until the scenario is agreed and the Linux x64 trace also matches tick-for-tick.

## Outstanding work

- Host CI must actually run successfully, including vcpkg, shader tools, software Vulkan/XTest and the exhaustive test; older intermittent X11 image capture failures and graphics dependency CMake deprecation warnings are not claimed fixed.
- A Windows x64 development preflight executable was cross-compiled with Zig/Clang and has **not** been run on Windows. It exercises the fixed sample only. Native Windows/MSVC and physical Android ARM64 evidence remain required.
- Define and implement the agreed complete 10,000-tick input/replay scenario and execute it on the required real targets. Pin compiler/runtime and all relevant inputs; compare every tick, not just a final hash. A matching synthetic hash trace alone does not close G1.
- Implement the planned fixed-point deterministic simulation physics and run the prescribed cross-architecture replay; the current Mute-only example does not exercise physics and cannot close G2.
- The final audit is preserved in `mut01-mut12-final-audit-2026-11-22.md` as a historical record; this note explains what changed afterwards. No other subsystem or scope is claimed complete.
