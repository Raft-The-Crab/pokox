# Two-target gate evidence — 2026-11-26 (G2)

## Scope

G2 physics determinism gate per `docs/plan/24-engine-physics.md` and the
scope decision in `two-target-gate-evidence-2026-11-25.md`: Windows x64 +
physical Android arm64 must produce byte-identical replay traces. This run
claims **G2 accepted evidence** for the canonical ENG-60→63 chain
(Q16.16 Fixed math → SAP broadphase → GJK/EPA narrowphase → sequential
impulse solver). G1 was re-verified in the same runner execution.

## Environment

- Windows: this laptop, Windows 11 x64, MSVC 19.44 (`14.44.35207`), Ninja
  Debug build at `build-msvc/`.
- Android: Xiaomi `24117RN76G` (`tanzanite`), arm64, Android 16, API 36,
  connected via `C:\Android\platform-tools\adb.exe`.
- Android cross-compiler: NDK 22.1.7171670 (`aarch64-linux-android30`,
  clang++ `-O2`, `-fno-fast-math -ffp-contract=off`), build-only shim
  `tools/targets/android_std_shim.hpp`.
- Runner: `tools/targets/run_dual_target_tests.py` (extended with
  `PHYSICS_SOURCES` and a G2 probe leg on both targets; probe timeouts
  raised to 2400 s Windows / 3600 s Android for the 10,000-tick physics
  trace).

## Probe

`engine/physics/tools/g2_replay_probe.cpp` (`poko_physics_g2_replay_probe`)
runs a compiled-in deterministic scenario — no fixture file, no I/O in the
sim path: a static floor slab and pillar, eight spheres and four boxes
dropped from staggered heights with varied mass, friction, restitution and
initial horizontal velocity. Every tick applies gravity, rebuilds broadphase
bounds, runs SAP pair generation, `collide()` (GJK/EPA) per overlapping
pair, feeds `ContactConstraint`s to the warm-started sequential impulse
solver, integrates, then prints `tick pairs contacts hash` — a 64-bit FNV-1a
over raw Q16.16 state bits (positions + velocities of every body, pair and
contact counts). Integer-only hashing: no pointers, floats or
platform-dependent state.

## Results

Runner executed both legs concurrently on 2026-11-26 ~10:10–10:19 (+08:00).

| Check | Result |
|---|---|
| Windows MSVC Debug full `ctest` | 102/102 passed |
| Android arm64 Mute unit binaries on device | 12/12 passed |
| Windows G1 probe exit / lines | 0 / 10,000 |
| Android G1 probe exit / lines | 0 / 10,000 |
| G1 LF trace SHA-256 (both legs) | `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68` (matches accepted G1 hash) |
| Windows G2 probe exit / lines | 0 / 10,000 |
| Android G2 probe exit / lines | 0 / 10,000 |
| G2 LF trace SHA-256 (both legs) | `dd383cc338cd4ba179622aa64918d896de994c9ce20366b7018ba28c4eba1385` |
| G2 byte-for-byte trace comparison | identical |
| Runner verdict | `all_tests_ok: true`, `G1: accepted-evidence`, `G2: accepted-evidence` |

Artifacts:

- `artifacts/dual-target/gate-report.json`
- `artifacts/dual-target/g2-windows.trace`
- `artifacts/dual-target/g2-android.trace`
- `artifacts/dual-target/g1-windows.trace` / `g1-android.trace` (re-verified)
- `artifacts/dual-target/logs/`

## Narrowphase defects found and fixed during validation

Driving the probe exposed real ENG-62 bugs that unit tests had not covered;
all fixes are in `engine/physics/src/narrowphase.cpp` and are covered by the
byte-identical trace itself:

- **Degenerate EPA seed false positive.** `origin_in_tetra`'s sign test is
  vacuous on coplanar input: for a flat tetrahedron every opposite vertex
  lies in the face plane (`s_opp ≈ 0`), so the strict sign checks never
  reject and the origin "fits" inside any sliver. For separated shapes the
  seed search then accepted a `vol = 0` tetrahedron and EPA expanded a
  garbage hull, reporting impossible depths (observed ≈ 34 world units on a
  sphere 8 units below a floor slab — enough to slingshot bodies). Fixed by
  requiring a minimum vertex altitude above every face plane
  (`kTetraMinAltRaw` ≈ 0.001 units); flat seeds are rejected and separated
  pairs correctly report `touching = false`.
- **Sphere–sphere EPA non-convergence.** A sphere's CSO is curved, so EPA
  expansion never reaches `depth_eps` and burns the full iteration cap
  (~8.5 ms per call in benchmarks) — the dominant probe cost. Added an
  analytic fast path for two single-vertex radius shapes: exact center-line
  penetration, B→A normal, same near-touch handoff window as the GJK path.
  ~10,000× faster on that pair type and *more* accurate than the polytope
  approximation.
- Phantom near-touch contacts on separated pairs are filtered by the
  existing signed-depth guard once the seed search stops producing garbage.

## Remaining limitations (unchanged, documented in code)

- EPA depth remains polytope-approximated for non-spherical CSOs (~2% on
  the unit tests); manifold is EPA-face witnesses, not full face clipping.
- The ENG-62 scale guard scales large scenes down for Q16.16 headroom;
  the near-touch handoff window is expressed in scaled units, so for very
  large worlds the effective gap tolerance scales up correspondingly.
- Solver remains translational-only (no angular/inertia), no sleep/wake,
  no split impulses, no joints — per ENG-63 documented scope.
- G2 evidence covers the probe scenario and unit suites on the two gate
  targets; it does not claim production-scene coverage or ENG-64+ features.
