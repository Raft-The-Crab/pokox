# Two-target gate evidence — 2026-11-25

## Scope decision

Owner decision recorded in `mut13-v1-scope-matrix.md`: Linux x64 is a
build/CI environment, not a product or determinism target. G1 and G2 use
Windows x64 and a physical Android arm64 device. G2 was explicitly deferred;
this run does not claim physics acceptance and no shortcut G2 probe was
accepted.

## Environment

- Windows: this laptop, Windows 11 x64, MSVC 19.44 (`14.44.35207`), Ninja
  Debug build at `build-msvc/`.
- Android: Xiaomi `24117RN76G` (`tanzanite`), arm64, Android 16, API 36,
  connected via `C:\Android\platform-tools\adb.exe`.
- Android cross-compiler: NDK 22.1.7171670 (`aarch64-linux-android30`,
  clang++ with `--target=aarch64-linux-android30`), build-only shim
  `tools/targets/android_std_shim.hpp` for missing NDK libc++
  `std::bit_cast` and float `std::from_chars`.
- Runner: `tools/targets/run_dual_target_tests.py`.

## G1 — accepted evidence

`mute/tests/fixtures/g1-replay.mute` is the approved G1 scenario. The runner
executed the Windows and Android legs concurrently and compared the complete
10,000-tick trace, not just the final hash.

| Check | Result |
|---|---|
| Windows MSVC Debug full `ctest` | 98/98 passed |
| Android arm64 Mute unit binaries on device | 12/12 passed (state, program, evaluator, bytecode VM, snapshot, input snapshots, action map, device router, stdlib math, collections, crypto, events) |
| Windows G1 probe exit / lines | 0 / 10,000 |
| Android G1 probe exit / lines | 0 / 10,000 |
| Windows LF trace SHA-256 | `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68` |
| Android LF trace SHA-256 | `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68` |
| Byte-for-byte trace comparison | identical |
| Runner verdict | `all_tests_ok: true`, `G1: accepted-evidence` |

Artifacts:

- `artifacts/dual-target/gate-report.json`
- `artifacts/dual-target/g1-windows.trace`
- `artifacts/dual-target/g1-android.trace`
- `artifacts/dual-target/logs/`

A portability defect surfaced during the Android build:
`FixedStepLoop(Limits limits = {})` relied on a default member initializer in
a default argument, which NDK libc++ rejected. `loop.hpp`/`loop.cpp` now use
separate default and explicit constructors; the full Windows suite still
passes.

## MUT-40 — device routing on both targets

The final runner execution included `mute_device_unit` on Windows and the
NDK-built `device_router_test` on the Xiaomi arm64 device. It covers stable
lowest-free-slot gamepad/touch mapping, duplicate native handles,
connect/disconnect events, per-slot state clearing, slot-sensitive action
bindings, disconnect edges and byte-identical replay. Results:

- Windows full `ctest`: 98/98 after MUT-51–55; 92/92 at the MUT-40 point.
- Android Mute binaries: 12/12 after MUT-51–55; 8/8 at the MUT-40 point.
- ASan subset: 6/6 after MUT-51–55; 3/3 at the MUT-40 point.
- G1 trace comparison remained byte-identical after the MUT-40 state-hash
  extension.

No native SDL/AGDK device adapter is bundled here; hosts still translate
native events to the MUT-38 event format. Device-map disk persistence and
gestures beyond tap stay deferred.

## MUT-51–55 — stdlib core on both targets

The final dual-target execution also cross-compiled and ran
`stdlib_math_test`, `stdlib_collections_test`, `stdlib_crypto_test` and
`events_test` on the Xiaomi arm64 device. `build_tool_test` and `mute_build_cli`
ran on Windows with the pinned `mut55_sample` fixture.

- Windows full `ctest`: **98/98**, including `version_integration`.
- Android Mute binaries: **12/12**, including the four new stdlib/event tests.
- ASan stdlib/events/build-tool/determinism subset: **6/6**.
- Runner verdict: `all_tests_ok: true`; G1 traces remain byte-identical.
- Contracts: `mute/V1-API.md` and `mute/BUILD-TOOL.md`.

MUT-53 v1 `sign`/`verify` is an HMAC-SHA256 detached tag scheme. Asymmetric
publisher signatures remain outside the Mute sandbox API.

## Final audit — 2026-11-26

Scope: MUT-01–MUT-40 and MUT-51–MUT-55. MUT-41–MUT-50 were skipped by owner
instruction; no gate acceptance was performed. Windows laptop and the physical
Xiaomi `24117RN76G` were both connected.

### Results

- Windows Debug MSVC `ctest`: **98/98**, including `version_integration`,
  golden harnesses, desktop-evidence handling and G1 replay.
- Windows MSVC full ASan `ctest`: **98/98** after adding `/EHsc` and keeping
  `ASAN_OPTIONS=detect_leaks=0` (MSVC ASan does not support leak detection).
- Dual-target runner: **12/12** Android Mute binaries, byte-identical 10,000-tick
  G1 traces, `all_tests_ok: true`, `G1: accepted-evidence`.
- Optional GCC/Clang mutation scripts: explicit **SKIP** on this MSVC host;
  they require `c++`, which is not installed here.
- No product behavior changed. No MUT-41–MUT-50 work was added.

### Issues found and fixed in existing scripts

- Full ASan initially produced **93/98**; five RHI fault tests failed because
  the ASan script omitted `/EHsc`. `tools/msvc/msvcasan.bat` and
  `tools/msvc/msvc-debug.bat` now pass `/EHsc`, allow toolchain overrides,
  keep leak detection off on MSVC, and require `--no-tests=error`.
- `msvc-debug.bat` had invalid `if errorlevel1` syntax; fixed. `msvcasan.bat`
  built but never ran tests; it now runs the full suite.
- Optional mutation scripts crashed with `FileNotFoundError` when no GCC/Clang
  compiler was present; both now print an explicit SKIP and exit cleanly.
- `run_dual_target_tests.py` had several report/trust defects: uncaught missing
  tool errors, single-leg runs always failing, skipped CTest counting as pass,
  stale artifacts, missing remote exit codes, silent Android tests passing
  without PASS markers, G1 hash tied to a stale tick constant, emulator not
  rejected, missing `cat` status, and hardcoded toolchain paths. All fixed in
  the existing runner. Tool paths now honor `POKO_*` environment overrides.
- `test_version.py` parsed arguments at import, hardcoded a 105-file mirror of
  the CMake source list, and had no subprocess timeout. It now parses args in
  `main`, copies `engine`, `mute` and `tools/version/cmake` from one place, and
  uses a 900-second command timeout.
- `verify_desktop.py` could crash before writing a report if a hashed source
  was missing and accepted graphics warnings. Both fixed; missing hashes are
  recorded as `null`, warnings fail the evidence run.
- `cube_golden.py` pinned exact llvmpipe/LLVM/driver versions; it now requires
  only the llvmpipe software adapter.
- Shader-pipeline and cube-golden unit scripts silently skipped Windows checks;
  they now print explicit `SKIP:` lines.
- `android_std_shim.hpp` float `from_chars` shims are now guarded for newer
  NDKs; the runner pins NDK r22.
- Stale evidence table counts were corrected to 98/98 and 12/12.

## ENG-02 — platform evidence

### Windows 11

The dependency-free MSVC build has `POKO_WITH_SDL_PLATFORM=OFF`, so a real
SDL3 window check was built explicitly using the vendored SDL3 3.4.20 headers
and DLL. An MSVC import library was generated from the DLL exports into
`artifacts/sdl-msvc/SDL3.lib`; `sdl_platform.cpp` and
`sdl_platform_test.cpp` were compiled with MSVC and linked against it.

Result:

```text
SDL windows driver: create/resize/close translation/quit/teardown passed
SDL repeat-initialize and destructor-only cleanup passed
EXIT=0
```

This exercises the real Windows SDL3 `windows` video driver, not the fake SDL
doubles or the dummy driver.

### Physical Android arm64

`engine/rhi/android/gles-clear/build_apk.sh` was repaired to work with the
installed SDK: it now builds from a stable working directory, signs through
`java -jar apksigner.jar`, and links the Vulkan renderer source plus
`-lvulkan`. The native activity now also picks up an already-published
`ANativeWindow` and polls the looper with a small timeout so fast surface
creation is not missed on Android 16.

The app was uninstalled before reinstalling, as required by this device, and
launched with `am start -n com.poko.glesclear/android.app.NativeActivity`.
Results:

```text
vulkan primary: 120/120 frames presented on 1080x2400
vulkan primary: 120/120 frames presented on 720x1600
```

The display size was restored to `1080x2400` after the second check. The
activity finishes after presenting, covering window teardown/close. Live
rotation/resize remains an ENG-05 concern; this gate covers window creation,
surface presentation at two sizes, and orderly teardown.

APK: `engine/rhi/android/gles-clear/pokox_gles_clear.apk`

## G2 — not accepted

G2 remains open and deferred. Completion requires the canonical
ENG-60 (Q16.16 math) → ENG-61 (SAP broadphase) → ENG-62 (GJK/EPA) → ENG-63
(sequential impulse solver) chain, followed by two-target evidence. No
physics implementation or shortcut probe was added in this gate run.
