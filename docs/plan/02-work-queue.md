# 02 — Ordered work queue

One canonical queue. Per-system docs used overlapping IDs (three different `R01`, two `K01`); those are resolved here. Every task has one owner-agnostic ID, one dependency set and one acceptance test.

**Character prototype note:** `assets/characters/preserved/` contains separate preservation-first Blender copies and experimental glTF exports. Engine face support, faithful export, and import tests are still unimplemented. This work does not change queue gates or mark AST-04 complete.

## Rules

1. A task is one behavior change, one PR, one test, one focused work session.
2. Main builds and all tests pass at every commit.
3. A task touches at most two modules.
4. Do not split a task until it has been attempted and genuinely does not fit a session.
5. A gate failure stops the queue. Do not start the next wave to "make progress elsewhere."
6. First 20 tasks are specified in exact execution order below.

## Canonical ID map

| Prefix | Area | Old IDs absorbed |
|---|---|---|
| INF | Infrastructure | T00–T04 |
| ENG | Engine renderer and production basics | R01–R12, P01–P10 |
| MUT | Mute language and VM | M01–M12; MUT-13–59 are new v1 planning |
| NET | Wire protocol | N01–N08 |
| BAK | Backend foundation | B01–B08 |
| SHL | Windows and Android shells | U01–U08, shell C01–C14 |
| VER | Versions, glyphs, registry, distribution | V01–V12, registry R01–R10, distribution K01–K10 |
| PUB | Publishing pipeline | publish tasks |
| MOD | Poko Mod | D01–D05 |
| ECO | Ledger and economy | E01–E09, ledger tasks |
| EXC | Exchange | market tasks |
| IDN | Identity and security | SEC01–SEC16, identity tasks |
| CLI | Client home and discovery | H01–H10, S01–S06 |
| AST | Asset pipeline | import tasks |
| LOC | Localization and accessibility | l10n tasks |
| STU | Studio extras | X01–X08 |
| COM | Community and contributors | community K01–K08 |
| SIM | Economy simulator | simulator tasks |
| LEG | Legal and privacy | L01–L06 |
| OPS | Operations | O01–O03 |
| FIX | Corrections | F1–F8 |
| ADD | Additions | add list |
| ENH | Enhancements | enhance list |

## Scaffold progress

- **INF-01:** The seven requested top-level areas and their README stubs exist in the delivered scaffold. This is an archive, not a verified Git repository or commit.
- **INF-02:** In progress. The minimal build and full-manifest dependency smoke test (including pinned DiligentCore) passed on Linux. MSYS2 and MSVC builds remain unverified, so the acceptance criterion is not yet met. See `../build.md` for details.
- **Execution-order exception, 2026-11-20:** The project owner deferred the INF-02 Windows checks and requested work continue. INF-03, INF-04 preparation and INF-06 proceeded before INF-02 acceptance, and INF-05 proceeded before INF-04 had a green CI run. Both pending acceptance checks remain open. This exception does not waive any phase or determinism gate.
- **INF-03:** Flag contracts and compile-time tests are implemented and pass on Linux; the actual D3D12-enabled Windows SDK path is not yet verified. The flags do not yet implement the future UI, debug features or graphics backend.
- **INF-04:** A GitHub Actions workflow for MSVC and MSYS2/MinGW builds and tests is present and statically linted. It has not run on GitHub; the two-toolchain green acceptance criterion is still open. See `../build.md`.
- **INF-05:** The byte-exact binary and PNG golden harness is implemented and tested locally for matching and mismatching inputs; it is registered with CTest. Windows CI execution remains pending. See `../../tools/testutils/harness/README.md`.
- **INF-06:** Git-tag version header generation and executable output are implemented and integration-tested on Linux. Windows testing and the INF-02 dependency remain pending; see `../../tools/version/README.md`.
- **ENG-01:** The owner requested this platform interface before the pending INF-02/INF-04 Windows acceptance checks. A backend-independent single-window contract and a test double were built and tested on Linux. The header is implemented; Windows and Android compilation remain unverified. This exception does not close the infrastructure gates.
- **ENG-02:** SDL3 single-window implementation and demo added under the same user-directed exception. Linux dummy-driver and virtual X11 creation, resize and close-request checks pass; Windows 11 and Android 11 are unverified, so target-platform acceptance remains open. Input and rendering are not implemented; ENG-03 needs a graphics-compatible window/surface contract. See `../../engine/platform/README.md`.
- **ENG-01/ENG-02 hardening, 2026-11-20:** Expanded interface contracts, added a dependency-free fault-injection test of the actual SDL backend, and expanded real-SDL lifecycle checks. Strict-warning and optimized function-double runs pass; ten deliberate regressions were caught. Real-SDL additions, CMake registration and target-platform checks remain unverified on this host. Production code/API are unchanged; no gate is closed. See `../eng01-eng02-hardening-evidence.txt`.
- **ENG-03 execution-order exception and prerequisite, 2026-11-20:** The owner deferred Windows/Android testing to the laptop and explicitly requested development continue. Added Vulkan window intent, actual-size queries and borrowed SDL-window access, with tests and a blank-window probe. ENG-03 remains in progress: no Diligent device, surface, swapchain or clear color is implemented/verified. Strict, optimized and sanitized function-double runs pass and 11 deliberate regressions are caught. No infrastructure or phase gate is waived. See `../eng-progress.md`.
- **ENG-03 clear-color source candidate, 2026-11-20:** Added opt-in pinned Diligent Vulkan setup/clear/present source, native-window mappings, cleanup/failure tests and a bounded desktop demo. Actual source compiles/runs against dependency doubles, including three native layouts; no real-SDK or GPU acceptance is claimed. Android packaging, validation-message hard-fail policy and device-loss handling remain open. See `../eng-progress.md` and `../../engine/rhi/README.md`. ENG-03 is not complete; no gate is closed.
- **ENG-03 diagnostics/evidence continuation, 2026-11-20:** Added exclusive graphics callback capture and demo failure on reported error/fatal messages through cleanup. A fresh-build laptop evidence runner preserves failure reports and never auto-accepts a gate. Dependency-double and evidence-handler tests pass; real SDK/GPU/Windows/Android acceptance remains open. See `../eng03-diagnostics-evidence.txt`.
- **Windows laptop run, 2026-11-20 (MSYS2 UCRT64 MinGW):** First real Windows verification. Dependency-free build 18/18 and full dependency SDL build 21/21 CTest passed, including real-SDL tests; a real `version_integration` UTF-8 defect was found and fixed (`ENCODING NONE`). `pokox_window_demo` opened a real window. The Vulkan clear demo built against real SDL3+vcpkg `sdl3[vulkan]`+Diligent and presented 120 frames on the AMD Radeon GPU with validation requested, 0 errors, exit 0 (`--adapter 0`); WARP auto-selection failure was captured correctly. Required manifest/CMake/MinGW fixes recorded in `../build.md` and `../eng03-windows-laptop-evidence.txt`. On 2026-11-21 a screen capture confirmed the blue clear color visually on the AMD Radeon GPU (123 interactive frames, 0 captured errors), meeting ENG-03's clear-color criterion on Windows MinGW. Still open: MSVC leg, GitHub CI run, Android. No gate is closed.
- **ENG-04 desktop fallback prototype, 2026-11-21:** The selector now connects Vulkan and Diligent OpenGL clear adapters in an opt-in desktop demo, with dependency-double fault tests. Real fallback and displayed color still require target-device evidence; Android OpenGL ES is unimplemented. ENG-04 remains open. See `../eng-progress.md`.
- **ENG-01–ENG-04 audit, 2026-11-21:** Fixed cleanup and diagnostics handling, guarded GL framebuffer encoding and added regression tests. Real SDL/Diligent Linux demos built; software Vulkan submitted frames, while OpenGL could not obtain a matching GLX visual. Windows fallback, Android and color acceptance remain open. See `../eng01-eng04-audit.md`.
- **ENG-05 desktop resize prototype, 2026-11-21:** The owner requested continued work while personally testing OpenGL. Desktop Vulkan and OpenGL resize recreation are in progress; real OpenGL resize, Android lifecycle/orientation and target-device visual acceptance remain open. This does not accept ENG-04 or waive prior infrastructure or phase gates. See `../eng-progress.md`.
- **ENG-01–ENG-05 layout and safety audit, 2026-11-21:** Confirmed organized source paths and compatibility forwarders; fixed minimized-window deferral and GL cleanup-error retention. Target-device and phase acceptance remain open. See `../eng01-eng05-layout-and-audit.md`.
- **ENG-06 frame-graph skeleton, 2026-11-21:** The owner requested the next task. CPU-only logical dependency scheduling and validation are implemented; GPU resources, barriers and RHI execution are not yet integrated. Prior acceptance gates remain open. See `../eng-progress.md`.
- **ENG-01–06 follow-up and ENG-07 shader artifacts, 2026-11-21:** Expanded graph dependency tests and added an opt-in host GLSL-to-SPIR-V build. Offline artifacts are not evidence of a rendered triangle; prior device checks remain open. See `../eng01-eng06-followup-audit.md` and `../eng-progress.md`.
- **ENG-01–07 follow-up review, 2026-11-21:** Hardened shader path collision and include checks and added regression coverage; target-platform acceptance remains open. See `../eng01-eng07-review.md`.
- **ENG-08 Vulkan triangle prototype, 2026-11-21:** A graph callback loads the ENG-07 shaders and renders a triangle on software Vulkan; target-device, OpenGL/ES and validation-layer acceptance remain open. See `../eng-progress.md`.
- **ENG-01–08 follow-up and ENG-09 depth prototype, 2026-11-21:** Hardened triangle pipeline device ownership and error handling; a software Vulkan depth test and disabled-depth control show the expected overlap. Target hardware and validation-layer acceptance remain open. See `../eng01-eng08-review.md` and `../eng-progress.md`.
- **ENG-10 uniform prototype, 2026-11-21:** A per-frame dynamic uniform buffer drives an animated near triangle with depth testing in software Vulkan. Target hardware and validation-layer acceptance remain open. See `../eng-progress.md`.
- **ENG-11 ImGui pass prototype, 2026-11-21:** An opt-in `pokox_imgui_demo` composites a draggable Dear ImGui 1.93 window over the Vulkan triangle inside one presented frame, driven by a two-node frame graph (`ui imgui` CPU pass, `forward frame` GPU pass). Verified on the Windows AMD GPU: 120 submitted frames, 0 captured errors. Keyboard/text input, multi-texture updates, OpenGL/ES and Android paths remain unimplemented; target-device and validation-layer acceptance remain open. See `../eng-progress.md`.
- **ENG-12 ImGui toggle and strip, 2026-11-21:** F1 toggles the ImGui overlay at runtime in `POKO_DEBUG=ON` builds; `POKO_DEBUG=OFF` compiles out every ImGui path — the pass source and `imgui::imgui` link are excluded, so release binaries carry no ImGui symbols (verified at object level: strip TU compiles without ImGui headers, `nm` shows 0 ImGui symbols). See `../eng-progress.md`.
- **ENG-13 Structured logging, 2026-11-21:** `poko_logging` library wraps spdlog with a timestamped file sink and `key=value` structured fields; verified by `pokox_logging_file_test` (timestamped log file assertions pass). See `../eng-progress.md`.
- **FIX-05:** The D1 migration creates `word_reservations` and its global `publish` row. Verified in local SQLite tests and a local D1 database using Wrangler 4.165.0, including migration reapplication and duplicate rejection. No remote database has been deployed or migrated. Reservation lookup and the first-release exception remain later validator/publishing work; see `08-publishing-and-versions.md`.
- **Character validation repair, 2026-11-20:** Portable adaptation output paths and corrected cross-mesh UV validation were added, with Blender reports for both rigs. BoyR6 has 37 source-existing cross-mesh triangle overlap pairs; later view-layer inspection found helpers hidden but exposed reversed face attachment placement; see `29-boyr6-character-adaptation.md`. This does not advance AST-04 or waive INF acceptance.
- **LEG-01 and subsequent tasks:** Not implemented or verified in this scaffold.
- **Linux software-graphics review, 2026-11-22:** Real SDL3 and pinned Diligent Vulkan/cube builds passed; 44/44 configured CTest entries passed, and a synthetic orbit/resize smoke test completed 300 frames on Xvfb + CPU llvmpipe with validation requested and zero reported graphics errors/warnings. Real spdlog tests passed after logger safety/portability fixes. This is not physical-device or full vcpkg acceptance; earlier gates remain open. See `../graphics-setup-2026-11-22.md`.
- **OpenGL fallback check, 2026-11-22:** The real Diligent OpenGL target compiled, but forced OpenGL failed safely on the virtual X11 display: its 240 GLX framebuffer configurations reported no sRGB capability. No OpenGL color or target-device acceptance is claimed. See `../graphics-setup-2026-11-22.md`.
- **ENG-01–20 audit and ENG-21 prototype, 2026-11-22:** Owner requested continuing despite open gates. Added adjustable world-space directional lighting and live arrow-key controls; software Vulkan showed a live image response. Audit identified an ENG-15 pending GPU-query issue and ENG-17 ready/install ambiguity, with OpenGL, target-platform and full ImGui coverage still open. No gate is waived. See `../eng01-eng21-audit-2026-11-22.md`.
- **ENG-22 software golden candidate, 2026-11-22:** Owner requested continuing with ENG-22. A fixed-view screenshot comparison and Linux CI job were added; local comparisons caught and fixed outward-face culling and reject a deliberately dimmed shader. The GitHub job has not run, so CI acceptance and all earlier gates remain open. See `../eng-progress.md`.
- **ENG-01–22 hardening audit, 2026-11-22:** Fixed pending GPU queries, async asset state/retry errors, renderer resource recovery, texture replacement, and pinned-ImGui GCC compatibility. Added regression coverage and verified a real software-Vulkan ImGui demo and F1 toggle. Full vcpkg, target-platform and CI gates remain open. See `../eng01-eng22-hardening-audit-2026-11-22.md`.
- **Archive layout check, 2026-11-22:** Confirmed engine source/test placement, preserved compatibility files, checked CMake archive references and built a clean extraction. Corrected the structure document to distinguish the planned scaffold from the actual ZIP. See `../eng01-eng22-layout-check-2026-11-22.md`.
- **MUT-01 lexer, 2026-11-22:** At the owner’s request, completed the initial C++20 lexer contract and local token-golden criterion despite earlier open gates. Hosted/target-platform verification and formal gate acceptance remain open. See `../mute-progress.md` and `../../mute/LEXICAL-CONTRACT.md`.
- **MUT-02 arithmetic AST, 2026-11-22:** At the owner’s request, implemented the arithmetic parser and passed AST goldens locally. Earlier hosted CI and platform gates remain open; no gate is waived. See `../mute-progress.md`.
- **MUT-03 arithmetic evaluator and MUT-01–03 audit, 2026-11-22:** Owner requested the next task and an audit. Initial checked arithmetic and local tests pass. A follow-up added floating remainder, bounded input and read-only host numeric bindings; full numeric semantics and hosted/target-platform gates remain open. See `../mute-progress.md` and `../mut01-mut03-followup-audit-2026-11-22.md`.
- **MUT-04 console, 2026-11-22:** Implemented the optional debug ImGui arithmetic console with real SDL text/key input, local software-Vulkan interaction evidence and release stripping. Full engine console, cross-platform tests and earlier gates remain open. See `../mute-progress.md`.
- **MUT-05 print, 2026-11-22:** Added an initial top-level print-to-ImGui host bridge and bounded log, with local integration tests. General function calls, VM hostcalls and target-platform gates remain open. See `../mute-progress.md`.
- **MUT-06 functions and locals, 2026-11-22:** Initial bounded i32 tree-walk subset demonstrates recursion and local scope; broader language/VM and inherited gates remain open. See `../mute-progress.md` and `../mut01-mut05-audit-2026-11-22.md`.
- **MUT-07 control flow, 2026-11-22:** Initial i32/bool branching and while loops with bounded tree-walk execution; a follow-up audit fixed stale console-input capacity checks. Production VM, platform and determinism gates remain open. See `../mute-progress.md` and `../mut01-mut07-audit-2026-11-22.md`.
- **MUT-08–10 progress and audit, 2026-11-22:** The existing program subset runs on a register VM and now round-trips through a source-backed compiled-program snapshot; pinned sin/cos match x64 and emulated ARM64 vectors. The short/extended-long branch encoding is decided and implemented in the low-level codec. Real Windows/Android evidence, the final `.pkB` compiler and verifier, and existing gates remain open. See `../mut08-mut10-completion-audit-2026-11-22.md`.
- **MUT-11 initial state, 2026-11-22:** Added bounded i32 state, transactional ticks, declaration-order xxHash64 and an unsigned CBOR schema preview; real-device replay gates and production `.pkB` authority remain open. See `../mut11-pkb-audit-2026-11-22.md`.
- **MUT-12 initial state snapshot, 2026-11-22:** Added bounded exact-source-bound i32 save/load, corruption checks, and round-trip tests. This is not a full input replay or gate acceptance. See `../mut01-mut12-three-pass-audit-2026-11-22.md`.
- **Post-MUT audit fixes / G1–G2 preflight, 2026-11-22:** State initializers are checked consistently when compiling and decoding prototype bytecode; optional exhaustive and software-X11 console tests are registered for the Linux CI lane. 10,000-tick local and emulated ARM64 traces match, but G1/G2, real target and hosted CI evidence remain open. See `../g1-g2-preflight-2026-11-22.md`.
- **Mute v1 planning extension, 2026-11-22:** Added MUT-13–59 as proposed work and a v1 completion review. Scope and API compatibility are not yet approved; no existing task or gate is newly accepted. See `30-mute-v1-completion.md`.
- **MUT-13 approved, 2026-11-23:** Owner approved the v1 scope/API/device/compatibility/deferral matrix in `../mut13-v1-scope-matrix.md` (semantic-cost budget accounting, channels deferred, authority attributes inactive until MUT-49, publishing deferred, Win10+/Android minSdk26/targetSdk35+, spec-default limits, no Luau parity).
- **MUT-14 complete, 2026-11-23:** Full v1 expression parser shipped in `mute/` (`04fcd7c`) — iterative shunting-yard covering all approved operators with precedence, span and invalid-expression goldens; 65/65 local CTest passed. CI for `04fcd7c`: Windows MSVC (deps + dependency-free), MinGW and lit-cube golden green; Linux GCC failed only on the pre-existing flaky `mute_x11_console` / `mute_x11_state_console` visual tests, unrelated to the parser.
- **MUT-15 complete, 2026-11-23:** Added a separate v1 statement/control-flow parser (`mute/include/poko/mute/statement.hpp`, `mute/src/parser/statement.cpp`) producing an owned `StatementAst` with S-expression dumps. Covers `let`/`var`, expression statements, `if`/`else if`/`else`, `while`, `for..in`, `loop`, `match` arms, `guard`, `break`, `continue`, `return`, blocks, depth guard (spec default 64), and typed diagnostics for malformed cases. 17 statement goldens + unit invariants/fuzz; the existing program interpreter/VM are unchanged. 67/67 local CTest passed. Commit `533918a` failed CI only on `version_integration` (its hard-coded source fixture omitted the new parser files); fixed in `8b32fa6` by adding them to `tools/version/tests/integration/test_version.py`. No existing gate is accepted by this parser-only milestone.
- **CI fixed, 2026-11-24 (green run `45324845861`, commit `d6139c3`; a later X11 input-readiness hardening commit `668ca72` could not be CI-verified because GitHub Actions was blocked by an account payment/spending-limit failure — owner action needed):** All five CI legs pass. Root cause of the long-standing Linux GCC failure was identified from the full CI log after improving the X11 tests' failure output: Diligent reported `Layer 'VK_LAYER_KHRONOS_validation' version (1.3.275) is less than the header version (1.3.290)` — Ubuntu 24.04's validation layer is older than the pinned Diligent headers, an environment mismatch, not an application defect. Added a narrow, explicit, unit-tested allowlist (`engine/rhi/src/debug/vulkan_diagnostics_filter.cpp`) for exactly that message: it is still logged but no longer counted as a warning; all other warnings and every error still hard-fail. The second failure was X11 input focus: the console test clicked the input field only once before six typed expressions, so after Return the field lost focus and pixel deltas were zero. Re-resolving the demo window on each capture (SDL can recreate it) and re-clicking the input before every entry fixed it. Also fixed a helper call that passed a float as the X coordinate. No gate policy was weakened beyond the documented, narrowly scoped environment allowlist.
- **Full MUT-01–20 audit, 2026-11-24:** Re-checked the seed's three recorded findings (compile-time state initializer validation, X11 console CI registration, exhaustive-arithmetic option) — all are addressed. Reviewed MUT-04–30 source and found four real defects in the v1 parser layer, all fixed with regressions: `pub` (a lexer keyword) was checked as an identifier so `pub fn` failed; the empty-call branch of the expression parser failed to clear `want_operand_`, rejecting `f()` anywhere; state initializers stopped before their own first token when another declaration followed on the same line; enum variant payloads `B(i32)` checked for `)` without consuming it, and their type children were dumped as declaration nodes. Added fixtures/regressions for each. Fuzzed 1,600 random malformed inputs through all four Mute dump CLIs under ASan with no crashes, hangs or sanitizer errors. ASan plus `/RTC1` are the available runtime checks; no UBSan/clang-cl exists on this toolchain. No gate is claimed accepted by this audit.
- **MUT-16 complete, 2026-11-24:** Added a v1 type/declaration parser (`mute/include/poko/mute/declaration.hpp`, `mute/src/parser/declaration.cpp`) producing an owned `DeclarationAst` with S-expression dumps. Covers package/version/allow/import, `struct` fields, `enum` variants, typed `@state` declarations, and `fn` declarations with parameters, return types, `pub`/`async`, v1 attributes (deferred authority attributes rejected per approved scope), named/generic/tuple types including nested `>>`; embedded function bodies reuse the MUT-15 statement parser and initializers reuse MUT-14 expressions with absolute positions. Added `unit` expression kind for `()` (canonical `ok(())`). 15 declaration goldens + unit invariants/fuzz; 69/69 local CTest passed. The existing program interpreter/VM are unchanged; no existing gate accepted by this parser-only milestone.
- **MUT-17–20 complete, 2026-11-24:** Added a standalone semantic-analysis library (`mute/include/poko/mute/semantic.hpp`, `mute/src/semantic/semantic.cpp`) over the existing declaration/statement/expression ASTs, leaving the parsers and old interpreter unchanged. Name resolution (module/function/block scopes, let/var bindings, loop variables, shadowing, duplicate/unknown names) plus type checking (scalars and calls, no implicit numeric conversion, aggregates/variants/struct fields, generics with invariant arguments and arity checks, operator trait constraints). 15 semantic goldens + unit tests; 71/71 local Debug CTest passed. This is static analysis only — it does not wire into the bytecode compiler or runtime; no existing gate accepted. Sanitizer audit (2026-11-24): ASan build (`build-msvc-asan`) clean; all 11 Mute-core tests pass under ASan; `mute_evaluator_reference` passes at 388s and `mute_g1_replay` at ~119s after raising its CTest timeout 120→300 (ASan legitimately needs longer). Five `pokox_vulkan/opengl_faults_*` allocation-injection tests fail under ASan but pass Debug — the known allocation-count sensitivity recorded in `.agents/skills/msvc-toolchain/SKILL.md`; not a product bug. `version_integration` passes under ASan with full toolchain env. No UBSan available: MSVC 14.44 has no UBSan and clang-cl is not installed. MUT-21 (packages/imports) is next in the Mute block, but the API tasks from MUT-38 onward need engine prerequisites.
- **MUT-21 complete, 2026-11-24:** Added `poko/mute/package.hpp` + `mute/src/package/package.cpp`: `resolve_packages` parses each supplied source as a v1 declaration module, checks declared `package`/`version` identity against the claimed input, and resolves `import "pkg://name[@word]" as alias` edges across the whole set — missing names, absent pinned words, unpinned ambiguity, one-version-per-name conflicts (including diamonds), duplicate identities, identity mismatches, malformed specs and import cycles are all diagnosed with typed codes and positions. `dump_lockfile` emits deterministic `# mute.lock v1` + sorted `name@version xxhash64` lines regardless of input order. 17 scenario groups in `mute_package_unit`; 73/73 local Debug CTest passed. Resolver is source-set only — no registry/fetch/lockfile reader yet. See `../mute-progress.md`. No existing gate accepted.
- **MUT-22 foundation complete, 2026-11-24:** Added `poko/mute/values.hpp` + `mute/src/vm/values.cpp`: `AggregateStore` provides refcounted string/array VM values behind bounded handles, deep `copy`, recursive `release`, per-tick arena reclamation via `reset_tick`, `@state`-style `promote` to the RC heap, and typed `ValueError` traps for wrong kind, bounds, dead handles, heap/arena/depth limits. `mute_values_unit` passes locally; not yet wired into `run_program` or bytecode (MUT-26/27). See `../mute-progress.md`. No existing gate accepted.
- **MUT-21–22 audit complete, 2026-11-24:** Reviewed the package resolver and aggregate value runtime. Fixed a real crash (dangling `Object*` across `objects_` reallocation in `copy_impl`), unbounded `copy`/`free_object` recursion (now depth-trapped/iterative), an arena-child-in-heap-parent dangling handle (`set_index` promotes on write), `reset_tick` heap-child ref leaks, partial-copy leaks, and added a 4096-input `input_limit` cap to `resolve_packages`. Regression tests added; Debug and ASan `mute_*` suites pass (30/30 ASan). See `../mute-progress.md`. No existing gate accepted.
- **MUT-22 limits resolved, 2026-11-24:** All four documented values-runtime limits fixed: `get_index` now returns `owned=false` borrowed Values that `release()` ignores; handles are generation-tagged 64-bit values so stale handles always fail validation; `set_index` rejects cycle-forming insertions via bounded reachability DFS (`ValueErrorCode::cycle`); generation counters now survive slot frees. Regression tests added for all three; Debug and ASan suites pass. See `../mute-progress.md`. No existing gate accepted.
- **MUT-23 foundation complete, 2026-11-24:** Added `poko/mute/scheduler.hpp` + `mute/src/vm/scheduler.cpp`: deterministic cooperative `Scheduler` with FIFO `spawn`, `await_task` suspend/resume, `cancel`, step/task budgets and terminal-state observation. `mute_scheduler_unit` passes locally (FIFO order, replay determinism, await ordering, cancellation, caps, self-await). Not yet wired into `run_program`/`await`/`spawn` syntax (MUT-26/54). See `../mute-progress.md`. No existing gate accepted.
- **MUT-24 foundation complete, 2026-11-24:** Added `analyze_determinism` (`mute/src/semantic/determinism.cpp` + `poko/mute/determinism.hpp`): validates `allow:` names against the approved v1 capability set, bans capability tokens in `@state` types/initializers, and rejects nondeterministic builtins (`now/time/clock/timestamp`→Time, `random/rand/uuid/guid`→Crypto, `env/getenv/hostname/username/pid/addr`→always) without the declared capability or inside `@state`. Scans `allow` decls, `@state` values and all `fn` bodies via `StatementAst`. `mute_determinism_unit` passes locally. See `../mute-progress.md`. No existing gate accepted.
- **MUT-25 foundation complete, 2026-11-24:** Added `poko/mute/ssa.hpp` + `mute/src/semantic/ssa.cpp`: typed SSA IR (`IrModule`/`IrFunction`/`IrBlock`/`IrInstr` reusing MUT-19 `Type`) with `verify()` rejecting malformed control flow (missing/mid-block terminators, dangling targets, predecessor-set mismatch, unreachable blocks, duplicate labels) and type errors (undefined values incl. gap ids, operand type mismatch, phi arity/input, return type). `mute_ssa_unit` passes; Debug `mute_*` 33/33 and ASan suite run. See `../mute-progress.md`. No existing gate accepted.
- **MUT-26 foundation complete, 2026-11-24:** Added `poko/mute/emit.hpp` + `mute/src/semantic/emit.cpp`: `emit_bytecode` lowers a verified `IrModule` onto the register ISA — identity register mapping, ALU/copy/compare ops, jump/branch with 16-bit displacement and `ext_prefix` long form, phi→edge moves with critical-edge trampoline splitting, typed `unsupported_op`/`too_many_values`/`bad_phi_operand` errors. `IrInstr` gained a `detail` sub-op field. `mute_emit_unit` passes including real `run_register_vm` execution of arith and branch+phi select. See `../mute-progress.md`. No existing gate accepted.
- **MUT-26 limits resolved, 2026-11-24:** Added `lower_function` (`mute/src/semantic/lower.cpp` + `poko/mute/lower.hpp`) — StatementAst→IrFunction for block/let/var/expression/if-else/while/loop/break/continue/return with int/bool/unit/ident/unary/binary exprs and land/lor short-circuit; phi merges on actual predecessors. Added `Opcode::load_imm` (0x70, `li rX, imm` + i32 payload) through bytecode codec, validator, assembler, disassembler and `run_register_vm`; `emit` now lowers `constant`. `mute_lower_unit` proves end-to-end parse→lower→verify→emit→execute on real Mute source (arith=84, if-phi select, loop-break, while-false). Debug `mute_*` 35/35. See `../mute-progress.md`. No existing gate accepted.
- **MUT-26 second pass, 2026-11-24:** Added assignment lowering (`=`/`+=`/`-=`/`*=`/`/=`/`%=`), loop-carried `while` phis (counters execute correctly), and a verifier fix letting phi operands reference later-layout defs (back edges). `mute_lower_unit` proves `while x<3 {x=x+1}` returns 3 end-to-end. Debug `mute_*` 35/35, ASan subset clean. See `../mute-progress.md`. No existing gate accepted.
- **MUT-26 third pass, 2026-11-24:** Added `for x in a..b` / `a..=b` lowering — desugared to a counted loop with header phis, increment block and break/continue targets; non-range iterables diagnosed. Restored `docs/mute-progress.md` (was truncated empty by a failed scripted write). `mute_lower_unit` covers sum/empty-range/inclusive/break cases; Debug `mute_*` 35/35, ASan subset clean. Remaining opens need ISA/VM extensions: calls, member/index, floats/strings/aggregates, bitwise ops, await/spawn, spilling, hostcalls. See `../mute-progress.md`. No existing gate accepted.
- **MUT-27 complete, 2026-11-24:** `validate_bytecode` now rejects empty streams and programs whose last real instruction can fall through (must be ret/halt/jump/unconditional ext long-jump); runs before encode/decode/assemble/disassemble/VM execution. `mute_bytecode_vm_unit` caught and fixed an over-strict rejection of legitimate trailing unconditional long jumps. Debug `mute_*` 36/36, ASan subset clean. See `../mute-progress.md`. No existing gate accepted.
- **MUT-28 complete, 2026-11-24:** Added `fold_constants` (`mute/include/poko/mute/fold.hpp` + `mute/src/semantic/fold.cpp`) — same-block def-before-use constant folding for binary/unary/compare/copy mirroring VM i64→i32 trap semantics; trapping/overflowing ops left unfolded so trap order is identical. `mute_fold_unit` proves value equality, trap preservation and no cross-block folding. Also fixed two real bugs found while landing it: `verify()` now uses computed dominators instead of layout-order approximation (fixes backward-edge operand rejection), and the `if` merge no longer emits r0 (value 0) phi operands on the no-else false edge (was causing infinite loops). Debug `mute_*` 36/36, ASan subset clean. See `../mute-progress.md`. No existing gate accepted.
- **MUT-29 complete, 2026-11-24:** Added `eliminate_dead_code` (`mute/include/poko/mute/optimize.hpp` + `mute/src/semantic/optimize.cpp`) — function-global liveness fixpoint removing unused pure defs (constant/copy/compare/phi); all arithmetic kept since every ALU op can trap. `mute_optimize_unit` covers dead-code removal, trap preservation and optimized-vs-baseline equality. Debug `mute_*` 37/37, ASan subset clean. See `../mute-progress.md`. No existing gate accepted.
- **MUT-30 complete, 2026-11-24:** Added `simplify_control_flow` — same-block constant branches become unconditional jumps, unreachable blocks removed with target/preds/phi-imm remapping and phi repair for eliminated edges. `mute_optimize_unit` proves `if 1<2` folds and returns 11. Debug `mute_*` 37/37, ASan subset clean. See `../mute-progress.md`. No existing gate accepted.
- Maintain `../structure.md` and the relevant status documents in the same change whenever the actual layout or project progress changes.

## Wave 0 — Infrastructure (INF)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| INF-01 | Repo layout and README stubs | — | Seven directories exist |
| INF-02 | CMake + vcpkg with SDL3, DiligentCore, ImGui, spdlog, Catch2 | INF-01 | Empty exe builds on MSYS2 and MSVC |
| INF-03 | Build flags POKO_IMGUI, POKO_D3D12, POKO_DEBUG | INF-02 | Each flag changes compile behavior |
| INF-04 | CI build and unit tests on push | INF-02 | Green on two toolchains |
| INF-05 | Golden-file harness for screenshots and bytes | INF-04 | Trivial golden passes and fails correctly |
| INF-06 | Version header from git tag | INF-02 | Build embeds version |
| LEG-01 | Draft document set | — | ToS, Privacy, Guidelines, Developer, Exchange, EULA, DMCA, Mod, Children's, Currency drafts exist |
| LEG-02 | Vendor DPA checklist | LEG-01 | Every vendor has a status |
| LEG-03 | Data map published | LEG-01 | Store, retention and rights per table |
| FIX-05 | Reserve word `publish` globally | INF-01 | `word_reservations` has global entry |

## Wave 1 — Engine seed and deterministic core (ENG, MUT)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| ENG-01 | IPlatform interface | INF-02 | Header compiles |
| ENG-02 | SDL3 platform implementation | ENG-01 | Window opens, closes, resizes |
| ENG-03 | Diligent init with Vulkan on SDL3 window | ENG-02 | Clear color appears |
| ENG-04 | OpenGL/ES backend behind same RHI | ENG-03 | Same clear on fallback |
| ENG-05 | Swapchain recreation on resize | ENG-03 | Resize without artifact |
| ENG-06 | Frame graph with dependency tracking | ENG-03 | Two dummy passes run in order |
| ENG-07 | GLSL to SPIR-V build-time compiler | ENG-06 | Shader artifact produced |
| ENG-08 | Forward pass colored triangle | ENG-07 | Triangle renders |
| ENG-09 | Depth buffer and depth test | ENG-08 | Overlap sorts correctly |
| ENG-10 | Uniform buffer per-frame data | ENG-09 | Triangle color changes |
| ENG-11 | ImGui pass in frame graph | ENG-10 | Demo window renders |
| ENG-12 | ImGui F1 toggle and release strip | ENG-11 | Release has no ImGui symbols |
| ENG-13 | Structured logging with file sink | INF-03 | Log file with timestamps |
| ENG-14 | CBOR config loader | ENG-13 | Engine reads settings |
| ENG-15 | Frame timing and stats | ENG-11 | CPU/GPU ms in ImGui |
| ENG-16 | Asset handle with refcount | ENG-14 | Load/release has no leaks |
| ENG-17 | Async load queue | ENG-16 | Asset loads without frame block |
| ENG-18 | KTX2 placeholder texture on quad | ENG-17 | Test texture renders |
| ENG-19 | Hand-written binary mesh load | ENG-17 | Cube renders with normals |
| ENG-20 | Camera with view/projection | ENG-19 | Cube orbits with mouse |
| ENG-21 | Directional light shader | ENG-20 | Lighting responds |
| ENG-22 | Golden screenshot of lit cube | ENG-21, INF-05 | CI compares golden |
| MUT-01 | Lexer core tokens | INF-05 | Token goldens pass |
| MUT-02 | Parser arithmetic AST | MUT-01 | AST dump golden |
| MUT-03 | Tree-walk evaluator | MUT-02 | Arithmetic correct |
| MUT-04 | ImGui console REPL | MUT-03 | Type expression, see result |
| MUT-05 | print hostcall to ImGui log | MUT-04 | Output appears |
| MUT-06 | Functions and locals | MUT-05 | Recursion works |
| MUT-07 | if/while and infinite-loop trap | MUT-06 | Budget stops runaway |
| MUT-08 | Register VM replaces tree-walk | MUT-07 | Same programs, same output |
| MUT-09 | Deterministic math port | MUT-08 | sin/cos match across x64/arm64 |
| MUT-10 | Bytecode encoder and disassembler | MUT-09 | Roundtrip passes |
| MUT-11 | @state and state hash | MUT-10 | Two runs identical hash |
| MUT-12 | State serialize for replay | MUT-11 | Save/load roundtrip |
| **GATE** | **G1, G2** | MUT-12, ENG-22 | Stop if hashes differ |

### Mute v1 completion tasks (planned; span later waves)

MUT-01–12 are the deterministic-core seed, **not** completion of the language. MUT-13–59 are planned and unimplemented. They use existing infrastructure/engine/backend work; follow the existing phase gates and each task's prerequisites rather than treating this table as permission to jump gates. These IDs extend the canonical queue, not the first-20 execution order. The v1 scope and exact API/compatibility commitments require owner review in MUT-13; the initial target and unresolved decisions are in `30-mute-v1-completion.md`. No Roblox/Luau compatibility is implied.

| ID | Task | Depends on | Done when |
|---|---|---|---|
| MUT-13 | Review and freeze Mute v1 scope and API matrix | MUT-12 | Owner-approved versioned feature, device, compatibility and deferral matrix with testable criteria |
| MUT-14 | Complete v1 expression parser | MUT-13 | Precedence, spans and invalid-expression goldens cover approved operators |
| MUT-15 | Complete v1 statement and control-flow parser | MUT-14 | Approved branches, loops, `break`, `continue`, `return` and malformed cases have AST goldens |
| MUT-16 | Parse v1 type and declaration forms | MUT-15 | Struct, enum, function and state declarations round-trip through parser goldens |
| MUT-17 | Resolve names and lexical scopes | MUT-16 | Shadowing, duplicates, unknown names and cross-scope references have deterministic diagnostics |
| MUT-18 | Type-check v1 scalar expressions and calls | MUT-17 | Valid calls pass and bad argument, return and numeric conversions fail at compile time |
| MUT-19 | Type-check v1 aggregates and variants | MUT-18 | Approved arrays, maps, structs, enums, option and result cases have positive/negative tests |
| MUT-20 | Type-check approved generic/trait subset | MUT-19 | Instantiation and documented trait constraints pass and invalid uses fail deterministically |
| MUT-21 | Resolve packages, imports and lockfile | MUT-17 | Pinned dependency graph resolves reproducibly; missing, conflicting or cyclic imports are diagnosed |
| MUT-22 | Implement aggregate VM values and lifetimes | MUT-19, MUT-08 | Approved string/aggregate creation, access, copies, releases and bounds traps pass lifetime tests |
| MUT-23 | Implement approved cooperative async scheduling | MUT-22 | Await and FIFO spawn order replay identically; cancellation is tested |
| MUT-24 | Enforce determinism and capability analysis | MUT-18, MUT-21 | Disallowed nondeterministic operations and excess capabilities fail with locations |
| MUT-25 | Introduce validated typed SSA IR | MUT-19, MUT-24 | Lowering goldens and verifier reject malformed control flow and types |
| MUT-26 | Emit bytecode from IR | MUT-25, MUT-10, MUT-22 | Specified functions and control flow compile and execute; the agreed branch encoding and boundary tests pass |
| MUT-27 | Verify bytecode before execution | MUT-26 | Malformed opcodes, registers, control flow and host signatures are rejected without execution |
| MUT-28 | Optimize proven-safe constant expressions | MUT-27 | Safe constant folding works; overflow, floats and trap-order regressions match unoptimized execution |
| MUT-29 | Eliminate proven-dead pure computations | MUT-28 | Dead code disappears without suppressing observable traps, effects or defined budget behavior |
| MUT-30 | Simplify proven-safe control flow | MUT-29 | Branch simplification preserves behavior and does not evaluate a formerly skipped branch |
| MUT-31 | Differential-test optimized and baseline programs | MUT-30, MUT-37 | Corpus covers values, state, hostcall order, traps, source locations and documented budget semantics |
| MUT-32 | Add optimizer benchmark and reporting harness | MUT-31 | Pinned workloads report time/size and detect specified regressions; no unmeasured speedup claim |
| MUT-33 | Emit source mappings and useful diagnostics | MUT-26, MUT-30 | Runtime trap and compile errors identify source location, including optimized code |
| MUT-34 | Add debugger breakpoints and stepping | MUT-33, MUT-27 | Breakpoint, step and stack inspection work on a sample without changing sim state |
| MUT-35 | Add versioned, typed hostcall boundary | MUT-27 | Valid calls dispatch; unknown IDs, malformed arguments and signatures trap before dispatch |
| MUT-36 | Enforce runtime capabilities | MUT-35, MUT-24 | Missing, narrowed and nonserializable capabilities are rejected; denied hostcalls do not run |
| MUT-37 | Enforce VM resource limits | MUT-35 | Budget, call-depth, heap and hostcall quotas trap at tested boundaries without corruption |
| MUT-38 | Provide deterministic input snapshots | MUT-35, ENG-02, ENG-30 | Recorded input yields identical tick snapshots; focus loss and event ordering are tested |
| MUT-39 | Provide actions and rebindable key bindings | MUT-38 | Scripts read named actions; remaps, conflicts and persistence follow the approved v1 contract |
| MUT-40 | Support approved pointer, gamepad and touch inputs | MUT-39 | Device mappings, connect/disconnect and touch behavior pass approved target-device tests |
| MUT-41 | Expose UI bindings and events | MUT-35, STU-06 | Mute state updates UI and a button invokes its handler; invalid bindings fail |
| MUT-42 | Expose physics queries and body operations | MUT-35, ENG-63, ENG-64, ENG-65 | Raycast, overlap, body and character operations follow authority policy; denied writes fail |
| MUT-43 | Expose world/entity queries | MUT-35, ENG-33 | Filtered queries have stable order and stale or unauthorized handles are rejected |
| MUT-44 | Expose scene/entity commands and transforms | MUT-43, ENG-90 | Approved create, remove and transform commands respect deferred ordering and stale handles |
| MUT-45 | Expose approved camera controls | MUT-44, ENG-20 | Camera target and transforms respond to authorized scripts without mutating validated state |
| MUT-46 | Expose asset loading and handles | MUT-35, ENG-17 | Approved load, release and invalid-handle cases are covered without leaks |
| MUT-47 | Expose approved audio hostcalls | MUT-35, ENG-70 | Play/stop and capability denial work; cosmetic audio cannot mutate validated state |
| MUT-48 | Expose animation markers and parameters | MUT-35, ENG-81, ENG-82 | Clip marker and parameter dispatch obey their validated/trusted policy |
| MUT-49 | Expose approved network messaging and replication | MUT-35, NET-09, MUT-11 | Allowed messages/replication work and unauthorized or malformed calls are rejected |
| MUT-50 | Expose namespaced storage | MUT-36, GAME-05 | Approved get/set/delete, isolation, failure and offline/conflict behavior pass contract tests |
| MUT-51 | Complete approved deterministic math, time and RNG APIs | MUT-09, MUT-35 | Pinned vectors, seeded replay and simulation wall-clock rejection pass |
| MUT-52 | Complete approved string and collection library | MUT-22 | Documented operations, ordering, Unicode behavior and bounds failures pass golden tests |
| MUT-53 | Expose approved cryptographic APIs | MUT-36 | Approved hash, HMAC and signature verification vectors pass; unauthorized calls fail |
| MUT-54 | Dispatch lifecycle and game events to Mute | MUT-23, MUT-35 | Approved event order, subscriptions and teardown are deterministic and tested |
| MUT-55 | Provide package/build tooling and v1 documentation | MUT-21, MUT-26, MUT-33 | Fresh sample builds from a pinned lockfile with documented diagnostics and API reference |
| MUT-56 | Provide editor diagnostics and contextual completion | MUT-17, MUT-18, MUT-33, STU-04 | Agreed editor interface reports matching diagnostics and symbol/type completion; stale-edit behavior is tested |
| MUT-57 | Run v1 conformance, security and platform suite | MUT-31, MUT-36, MUT-37, MUT-39, MUT-40, MUT-41, MUT-42, MUT-43, MUT-44, MUT-45, MUT-46, MUT-47, MUT-48, MUT-49, MUT-50, MUT-51, MUT-52, MUT-53, MUT-54, MUT-55, MUT-56, INF-04 | Approved matrix passes on Windows x64, Android arm64 and Linux x64; no required gate is waived |
| MUT-58 | Run integrated Mute v1 game slice | MUT-57 | Approved sample exercises v1 APIs and replay end-to-end on the agreed device matrix |
| MUT-59 | Mute v1 completion review and release gate | MUT-01–58, G1, G2 | Owner accepts the frozen v1 matrix, evidence and documented deferrals; every required task and gate passes |

### Engine completion tasks (specs 21–28)

These expand the engine beyond the seed. They slot into the waves as dependencies allow; none changes the first 20 tasks.

| ID | Task | Depends on | Spec | Done when |
|---|---|---|---|---|
| ENG-30 | Main loop with fixed accumulator and spiral guard | ENG-06 | 21 | 20 Hz sim, variable render, clamp verified |
| ENG-31 | Job system with dependency tokens | ENG-30 | 21 | Sim results identical under thread reordering |
| ENG-32 | Allocator hierarchy and tracking | ENG-31 | 21 | Per-arena watermarks and leak report |
| ENG-33 | ECS archetypes, queries, command buffer | ENG-32 | 21 | Ascending-index iteration; deferred structural changes |
| ENG-34 | VFS with four roots and async IO | ENG-17 | 21 | No path escapes its root |
| ENG-35 | CVar and console system | ENG-13 | 21 | Commands drive tests over local socket |
| ENG-36 | CBOR schema versioning for engine data | ENG-14, VER-04 | 21 | Unmigrated schema fails explicitly |
| ENG-40 | RHI resource lifetime and retirement list | ENG-06 | 22 | Three-frame retirement, no stalls |
| ENG-41 | Transient render target pool | ENG-40 | 22 | Reuse verified, 60-frame release |
| ENG-42 | Bindless descriptors with fallback path | ENG-40 | 22 | Same material code on both paths |
| ENG-43 | Shader source language and permutations | ENG-07 | 22 | Permutation explosion rejected |
| ENG-44 | GPU timestamps and validation layers | ENG-15 | 22 | Pass times in profiler |
| ENG-50 | Material templates and property blocks | ENG-08 | 23 | Property mismatch is compile error |
| ENG-51 | Culling: frustum, occlusion, LOD | ENG-20, ENG-50 | 23 | Deterministic draw order |
| ENG-52 | Clustered lighting and cascaded shadows | ENG-51 | 23 | Four cascades A tier |
| ENG-53 | Post stack with feature flags | ENG-52 | 23 | Every effect disables cleanly (G15) |
| ENG-60 | Q16.16 math primitive suite | MUT-09 | 24 | Exact cross-platform goldens |
| ENG-61 | SAP broadphase with sorted pair output | ENG-60 | 24 | Pair order stable |
| ENG-62 | GJK/EPA narrowphase and manifolds | ENG-61 | 24 | Stable contact order |
| ENG-63 | Sequential impulse solver with warm start | ENG-62 | 24 | Fixed iteration determinism |
| ENG-64 | Character controller through solver | ENG-63 | 24 | Matches position_step rule |
| ENG-65 | Visual physics and soft body path | ENG-63 | 24 | Cannot write validated state |
| ENG-70 | Mixer graph and four buses | ENG-17 | 25 | Under 2 ms CPU on Windows |
| ENG-71 | Opus streaming voices | ENG-70 | 25 | No underrun on 10 s track |
| ENG-72 | Spatial audio with HRTF fallback | ENG-71 | 25 | Stereo fallback correct |
| ENG-73 | Live voice chat rooms | NET-07, ENG-71 | 25 | Never logged or replayed |
| ENG-80 | Skeleton and skinning | ENG-19 | 26 | GPU skin matches bind pose |
| ENG-81 | Clip compression and event markers | ENG-80 | 26 | Tick-exact events |
| ENG-82 | State machine and blend trees | ENG-81 | 26 | Flat runtime table |
| ENG-83 | IK and sim-animation path | ENG-63, ENG-82 | 26 | Sim pose deterministic |
| ENG-90 | Scene graph and prefabs | ENG-33 | 27 | Entities sorted by id on write |
| ENG-91 | Scene CBOR and migrations | ENG-90, ENG-36 | 27 | Older word migrates |
| ENG-92 | Zone streaming and prefetch | ENG-91, CLI-04 | 27 | No geometry pop |
| ENG-93 | Scene editor commands and gizmos | ENG-92, STU-03 | 27 | 1,000 commands undo exactly |
| ENG-100 | Profiler ring and flame graph | ENG-15 | 28 | Under 0.5 ms overhead |
| ENG-101 | Debug draw API and toggles | ENG-100 | 28 | Compiled out of release |
| ENG-102 | Replay recorder and signed playback | BAK-08, ENG-60 | 28 | Hash matches every tick |
| ENG-103 | Crash handler and report format | ENG-13 | 28 | No tokens or chat in report |

## Wave 2 — Trust primitives (NET, BAK, IDN)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| IDN-01 | Firebase integration and account record | INF-04 | Sign-in creates PokoX record |
| IDN-02 | Device keypair and TOFU binding | IDN-01 | First sign-in binds, second skips |
| IDN-03 | Trust levels and step-up | IDN-02 | New device lands Basic |
| NET-01 | UDP socket echo | MUT-12 | Two processes echo |
| NET-02 | BitBuffer primitives | NET-01 | Bit-width goldens pass |
| NET-03 | Frame header, seq, HMAC | NET-02 | Replay rejected |
| NET-04 | Delta encoding against static schema | NET-03 | Only changed bits on wire |
| NET-05 | Two demos move each other's cube | NET-04, ENG-20 | First multiplayer moment |
| NET-06 | XOR-FEC parity | NET-05 | 1 loss recovered, 2 detected |
| NET-07 | uWS binary fallback | NET-06 | Same payload over WebSocket |
| NET-08 | Jitter buffer and interpolation | NET-07 | Motion smooth under injected jitter |
| NET-09 | ChaCha20-Poly1305 game plane | NET-03 | Two clients exchange encrypted frames |
| BAK-01 | Postgres schema | INF-01 | Migrations apply |
| BAK-02 | In-memory authority for one session | BAK-01, MUT-11 | Two clients agree |
| BAK-03 | Firebase token verification at Worker | IDN-01 | Invalid token rejected |
| BAK-04 | Device revocation path | IDN-02 | Revoked device fails within 5 min |
| BAK-05 | `.pkB` generator from test Mute | MUT-10, BAK-02 | Authority rejects invalid position |
| BAK-06 | Rule evaluator fixed-cost fuzz | BAK-05 | No rule exceeds budget |
| BAK-07 | Projected state hash and sequence window | BAK-06, NET-03 | Mismatch rejected generically |
| BAK-08 | Replay ring 64 ticks to R2 | BAK-07 | ImGui replay viewer scrubs |
| **GATE** | **G3, G4, G5** | BAK-08, NET-09 | Stop if invalid state accepted |

## Wave 3 — Authoring (SHL, AST, STU, PUB)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| SHL-01 | cbindgen header and Rust staticlib | INF-02 | MSYS2 link succeeds |
| SHL-02 | poko_shell_create with ABI check | SHL-01 | Null and mismatch return codes |
| SHL-03 | push_event accumulation | SHL-02 | Event golden passes |
| SHL-04 | frame runs egui with RawInput | SHL-03 | Label renders |
| SHL-05 | Tessellation to PokoMesh | SHL-04 | Vertex golden matches |
| SHL-06 | Texture delta export | SHL-05 | Font atlas uploads |
| SHL-07 | release with RAII guard | SHL-06 | 10k frames flat memory |
| SHL-08 | Panic boundary on all exports | SHL-07 | Forced panic returns -3 |
| SHL-09 | SDL3 event bridge in engine | SHL-08, ENG-02 | Mouse/keyboard drive egui |
| SHL-10 | Text input and IME | SHL-09 | CJK typed into field |
| SHL-11 | Vulkan UI pass | SHL-10, ENG-06 | Shell over game viewport |
| SHL-12 | Theme tokens and bevel widgets | SHL-11 | Classic and Flat goldens |
| SHL-13 | Reentrancy guard | SHL-08 | Nested call returns -5 |
| SHL-14 | DPI resize path | SHL-12 | Atlas regenerates |
| SHL-15 | Kotlin Activity and JNI handle | INF-02 | Native handle created |
| SHL-16 | Compose chrome over SDL surface | SHL-15 | Shell renders on Android |
| SHL-17 | Lifecycle callbacks | SHL-16 | Pause/resume/kill map correctly |
| STU-01 | Node schema and .ui.json parser | SHL-12 | Typed properties parse |
| STU-02 | Constraint layout solver | STU-01 | Same bounds at any resolution |
| STU-03 | Canvas with rulers and 9-slice | STU-02 | Selection and guides work |
| STU-04 | Tree, inspector, undo stack | STU-03 | 1,000 edits undo exactly |
| STU-05 | State binding to Mute symbols | STU-04, MUT-11 | Rename breaks build |
| STU-06 | Event wiring to Mute | STU-05 | Click jumps to function |
| STU-07 | Live preview and device presets | STU-06 | Android and 720p previews |
| STU-08 | Hot reload patches | STU-07 | 100 patches preserve @state |
| STU-09 | Binary UI compiler and loader | STU-08 | No JSON parsing at runtime |
| STU-10 | Theme token system | STU-09 | Classic example ships |
| AST-01 | Importer framework and .meta | INF-05 | Deterministic output |
| AST-02 | KTX2 + Basis pipeline | AST-01 | Vulkan and GL/ES parity |
| AST-03 | Opus audio pipeline | AST-01 | Stream vs decoded |
| AST-04 | PokoMesh with quantization and LOD | AST-01 | 30–50% of glTF size |
| AST-05 | SDF font atlas with subsetting | AST-01 | CJK subset only used glyphs |
| AST-06 | Chunk packer with CID table | AST-02, BAK-08 | Scene tags work |
| AST-07 | Studio import UI | AST-06 | Settings panel and preview |
| AST-08 | CDN caching and dedupe | AST-06 | Shared CID stored once |
| PUB-01 | Developer key generation and signing | IDN-03 | Signed manifest verifies |
| PUB-02 | Local build and preflight | PUB-01, STU-09 | Report shows caps and determinism |
| PUB-03 | Submission endpoint and gates | PUB-02 | Each gate rejects crafted bad input |
| PUB-04 | R2 content-addressed storage | PUB-03 | Dedupe verified |
| PUB-05 | D1 release manifests | PUB-04 | Version pointers resolve |
| PUB-06 | Review tier routing | PUB-05 | Tier 0 auto, others queue |
| **GATE** | **G6, G7** | STU-05, AST-02 | Stop if bindings or textures fail |

## Wave 4 — Delivery (CLI, LOC, VER distribution)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| CLI-01 | Boot and signed self-update | SHL-12 | Corrupt patch falls back |
| CLI-02 | Keystore token storage | IDN-03 | No plaintext token |
| CLI-03 | Catalog sync and manifest cache | PUB-05 | Version list correct |
| CLI-04 | Patcher with CID verify and resume | AST-06 | 1,000 interruptions identical |
| CLI-05 | Local cache with LRU | CLI-04 | 8 GB cap, active chunks kept |
| CLI-06 | Session launch and entitlement | NET-07, BAK-03 | Modified client cannot join |
| CLI-07 | Offline mode and pending sync | CLI-05 | Zero Pokoins offline |
| CLI-08 | Dashboard layout three columns | SHL-12 | Anatomy renders |
| CLI-09 | Feed, friends, groups panels | CLI-08 | Data bound |
| CLI-10 | Featured game and popular rows | CLI-08 | Cards render |
| CLI-11 | Character and wallet panels | CLI-08, ECO-01 | Balance read-only correct |
| CLI-12 | Status bar and notifications | CLI-08 | Connection and build shown |
| CLI-13 | Search with filters | CLI-10 | Tags and rating filter |
| LOC-01 | String catalog compiler | STU-09 | Plural and placeholder validation |
| LOC-02 | Extraction from markup and Mute | LOC-01 | Keys extracted |
| LOC-03 | Runtime resolver and fallback | LOC-02 | Missing key shows base |
| LOC-04 | RTL layout mode | LOC-03, STU-02 | Mirrored without clipping |
| LOC-05 | Font fallback chain | AST-05, LOC-04 | Tofu + warning |
| LOC-06 | Accessibility tree generation | STU-04 | Every interactive node present |
| LOC-07 | Keyboard and gamepad navigation | LOC-06 | Full traversal |
| FIX-01 | Dividend from 15% pool only | ECO-03 | Play payout intact |
| FIX-02 | Clicker activityMode varied | BAK-06 | Varied interaction required |
| FIX-08 | Click events Validated with seq | BAK-05 | Clicker policy works |
| **GATE** | **G8, G9** | CLI-04, CLI-07 | Stop if cache or offline unsafe |

## Wave 5 — Economy and play (ECO, BAK matchmaker)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| ECO-01 | Ledger schema and primitives | BAK-01 | Conservation constraint holds |
| ECO-02 | Idempotency and materialized balance | ECO-01 | Duplicate credits once |
| ECO-03 | Faucets with activity proof | ECO-02, FIX-02 | Stationary earns zero |
| ECO-04 | Sinks and void account | ECO-02 | Tax to void |
| ECO-05 | R computation job and publication | ECO-04 | R bounded and published |
| ECO-06 | Fraud detection and cases | ECO-03, MOD-01 | Signals create cases |
| BAK-09 | Matchmaker allocation and tickets | NET-03, BAK-02 | Ticket issued |
| BAK-10 | Queue in Valkey | BAK-09 | FIFO under load |
| BAK-11 | Slot registry with atomic counters | BAK-09 | CCU never exceeds 20 |
| BAK-12 | Wake lock and cold start | BAK-11 | Two triggers produce one wake |
| BAK-13 | BYO registration and challenge | BAK-11 | Unsigned endpoint never Ready |
| BAK-14 | Reconnection flow | BAK-09 | Same tick within 30 s |
| BAK-15 | Party and friend joins | BAK-14 | Party affinity works |
| SIM-01 | Ledger library extraction | ECO-01 | Sim and prod share code |
| SIM-02 | Scenario parser and seeded RNG | SIM-01 | Same seed same actions |
| SIM-03 | Agent behavior model | SIM-02 | Seven types act |
| SIM-04 | Weekly loop and rate computation | SIM-03 | 52 weeks under 1 s |
| SIM-05 | Metrics and healthy bands | SIM-04 | Charts render |
| SIM-06 | Shock events | SIM-05 | Expected deviations |
| SIM-07 | Golden scenarios in CI | SIM-06 | Three baselines pass |
| SIM-08 | Studio tuning panel | SIM-07 | Sliders compare |
| **GATE** | **G10, G11** | ECO-05, BAK-11 | Stop if conservation or CCU broken |

## Wave 6 — Safety and versions (PUB, MOD, VER, IDN security)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| PUB-07 | Updates and migrations | PUB-05, STU-05 | Version routing works |
| PUB-08 | Rollback with reverse migration | PUB-07 | Pointer moves, audit written |
| PUB-09 | GitHub mirror via Actions | PUB-04 | Source mirrored |
| PUB-10 | Takedown with market refunds | PUB-08, EXC-05 | Ledger preserved |
| MOD-01 | Key issuance and single-use | IDN-03 | Reused key rejected |
| MOD-02 | Immutable audit and export | MOD-01 | No update/delete path |
| MOD-03 | Live dashboard from Firestore | BAK-11 | 5 s freshness |
| MOD-04 | Drill-down game to player | MOD-03 | Heartbeat freshness |
| MOD-05 | Replay viewer panel | BAK-08, SHL-11 | Signed blob renders |
| MOD-06 | Case state machine | MOD-02 | Timeout returns to Open |
| MOD-07 | Two-vote actions | MOD-06 | One moderator cannot act |
| MOD-08 | Appeal with ledger reversal | MOD-07, ECO-02 | Overturn restores balances |
| MOD-09 | Detector precision tracking | MOD-08 | Dismiss reasons logged |
| VER-01 | Glyph table v1 generator | INF-02 | Goldens across languages |
| VER-02 | Word validator and reservations | VER-01 | Bad words rejected |
| VER-03 | WordKey derivation in Worker | VER-02 | Goldens match Studio |
| VER-04 | Registry schema and position | PUB-05 | Positions monotonic |
| VER-05 | Publish validation steps | VER-04 | Each failure code returned |
| VER-06 | Atomic publish transaction | VER-05 | Crash leaves no half state |
| VER-07 | Migration graph validation | VER-06 | Missing path blocks publish |
| VER-08 | KV cache and invalidation | VER-07 | Publish clears old manifest |
| VER-09 | GitHub Release creation | VER-08, PUB-03 | Tagged release with assets |
| VER-10 | client/latest endpoint | VER-09 | No GitHub API from client |
| VER-11 | Signature and hash verification | VER-10 | Bad binary never installs |
| VER-12 | R2 installer mirror | VER-11 | GitHub outage serves binary |
| VER-13 | Delta patch by WordKey | VER-12 | Patch applies and verifies |
| VER-14 | APK sideload flow | VER-11 | Installs on Android 11 |
| VER-15 | Revision byte in manifest | VER-04 | Hotfix without new word |
| IDN-04 | Login velocity and impossible travel | IDN-03 | Step-up triggers |
| IDN-05 | Device graph ban evasion | IDN-04 | Cluster flagged |
| IDN-06 | Donor token scoping | BAK-13 | Cross-game read denied |
| IDN-07 | Kill switch endpoint | BAK-09, MOD-02 | One invalidation disables target |
| IDN-08 | Key rotation drill | IDN-07 | 1 h overlap verified |
| IDN-09 | Red-team suite in CI | NET-09, BAK-07 | 20 patterns run |
| **GATE** | **G12, G13** | PUB-10, MOD-08 | Stop if gates bypassed or audit altered |

## Wave 7 — Platforms and extras (EXC, LOC, ENG AAA, COM)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| EXC-01 | Share ledger schema | ECO-01 | Conservation per game |
| EXC-02 | Bonding curve pricing | EXC-01 | Formula matches spec |
| EXC-03 | Atomic dual-ledger orders | EXC-02 | Kill test no orphans |
| EXC-04 | Circuit breaker and position caps | EXC-03 | Breaker trips correctly |
| EXC-05 | Dividends from 15% pool | EXC-04, FIX-01 | Exact floor math |
| EXC-06 | Wash-trade detection | EXC-05, ECO-06 | Reversal correct |
| EXC-07 | Exchange UI in client | CLI-11, EXC-06 | Ticker and orders render |
| LOC-08 | Remapping, reduced motion, color palette | LOC-07 | Settings persist |
| LOC-09 | Windows UI Automation adapter | LOC-07 | Narrator smoke passes |
| LOC-10 | Android AccessibilityNodeInfo adapter | SHL-17, LOC-07 | TalkBack smoke passes |
| ENG-23 | AA graphics features | ENG-22 | Clean fallback to A |
| ENG-24 | AAA partial feature flags | ENG-23 | 20+ features toggle |
| ENG-25 | Soft body and advanced physics | ENG-24, MUT-09 | Determinism preserved |
| COM-01 | Contributor portal and roles | IDN-03 | Role declared |
| COM-02 | CLA and DCO enforcement | COM-01 | Unsigned commit rejected |
| COM-03 | Contributor onboarding ladder | COM-02 | Five changes to Trusted |
| COM-04 | Donor staging 72 h | BAK-13 | Staging before production |
| COM-05 | Donor anti-capture limits | COM-04 | Ten nodes max per entity |
| COM-06 | Community council election | COM-03 | Advisory only |
| COM-07 | Credits panel in client | COM-03 | Anonymous toggle works |
| LEG-04 | DMCA agent registered | LEG-01 | Registration confirmed |
| LEG-05 | Incident runbook and contacts | LEG-01, IDN-07 | Templates and chain exist |
| LEG-06 | Backup and restore drill | LEG-05 | Quarterly restore passes |
| **GATE** | **G14, G15** | EXC-06, ENG-24 | Stop if ledgers or fallback fail |

## Wave 8 — Slices and launch (game content)

| ID | Task | Depends on | Done when |
|---|---|---|---|
| GAME-01 | Poko Bakery Mute game logic | MUT-12, STU-09 | Click loop works offline |
| GAME-02 | Bakery UI screens | STU-10, GAME-01 | Grid, buttons, tabs |
| GAME-03 | Buns local economy | GAME-01 | Buns never become Pokoins |
| GAME-04 | Prestige and achievements | GAME-03 | Reset grants multiplier |
| GAME-05 | Cloud saves and 2 h offline cap | CLI-07, GAME-03 | Conflict resolves to server |
| GAME-06 | Leaderboards | BAK-11, GAME-03 | Server-owned scores |
| GAME-07 | Chat and reports in game | NET-07, MOD-01 | Reports attach to session |
| GAME-08 | Bakery cosmetic skins | EXC-01, GAME-03 | Pokoins buy cosmetics only |
| GAME-09 | Share listing for Bakery | EXC-07 | Support via Exchange |
| GAME-10 | Playground 3D arena | ENG-25, BAK-07 | Soft body demo runs |
| GAME-11 | Authority validation for Playground | GAME-10, BAK-07 | Reconciliation visible |
| GAME-12 | Load test 20 CCU | BAK-11, GAME-11 | Sustained, no drift |
| GAME-13 | 5% loss FEC recovery test | NET-06, GAME-12 | Recovery verified |
| GAME-14 | Android 30 fps test | GAME-09, SHL-17 | Slice A meets target |
| GAME-15 | Docs and ToS published | LEG-01, STU-10 | Public pages live |
| **GATE** | **G16, G17** | GAME-14, GAME-13 | Launch only if both pass |

## Corrections, additions and enhancements placement

| Item | Placed as |
|---|---|
| FIX-01 dividend pool | Wave 4 |
| FIX-02 clicker activity | Wave 4 |
| FIX-03 platform CCU wording | Documentation pass in LEG-01 |
| FIX-04 syllable table | VER-01 |
| FIX-05 reserved `publish` | Wave 0 |
| FIX-06 Aiven Valkey removal | 03-architecture.md |
| FIX-07 revision byte | VER-15 |
| FIX-08 click events validated | Wave 4 |
| ADD friend referral | CLI-14, next wave after CLI-13 |
| ADD player profile | CLI-15 |
| ADD group treasury | CLI-16 |
| ADD trust score | EXC-08, MOD-10 |
| ADD achievements | GAME-04 covers core; COM-08 cross-game |
| ADD seasonal events | OPS-04 |
| ADD news/blog | OPS-05 |
| ADD revenue dashboard | STU-11 |
| ADD support tickets | OPS-06 |
| ADD developer API keys | PUB-11 |
| ADD replay clip sharing | MOD-11 |
| ADD Poko Bot | OPS-07 |
| ENH HF capacity page | OPS-08 |
| ENH version UX | CLI-17 |
| ENH WordKey KV cache | VER-16 |
| ENH chunk prefetch | CLI-18 |
| ENH R inputs published | ECO-07 |
| ENH security.txt | LEG-07 |
| ENH audio cues | LOC-11 |

## First 20 tasks — exact execution order

These are the first twenty commits. No task may be skipped or reordered without updating this file.

| # | ID | Task | Acceptance | Gate |
|---|---|---|---|---|
| 1 | INF-01 | Create repo layout | Seven directories with README stubs exist | — |
| 2 | INF-02 | CMake + vcpkg toolchain | Empty exe builds on MSYS2 and MSVC | — |
| 3 | INF-03 | Build flags | POKO_IMGUI, POKO_D3D12, POKO_DEBUG each change behavior | — |
| 4 | INF-04 | CI on push | Build and tests green on two toolchains | — |
| 5 | INF-05 | Golden harness | A golden passes and fails correctly | — |
| 6 | INF-06 | Version header | Git tag embedded in binary | — |
| 7 | FIX-05 | Reserve `publish` | Global reservation row present | — |
| 8 | LEG-01 | Draft legal documents | Ten drafts exist, marked "needs counsel" | — |
| 9 | ENG-01 | IPlatform interface | Header compiles, no implementation | — |
| 10 | ENG-02 | SDL3 platform | Window opens, closes, resizes | — |
| 11 | ENG-03 | Vulkan init on SDL3 window | Clear color appears | — |
| 12 | ENG-04 | OpenGL/ES backend | Same clear color on fallback device | — |
| 13 | ENG-05 | Swapchain recreation | Resize without crash or artifact | — |
| 14 | ENG-06 | Frame graph skeleton | Two dummy passes execute in order | — |
| 15 | ENG-07 | GLSL to SPIR-V | Build produces shader artifact | — |
| 16 | ENG-08 | Forward pass triangle | Triangle renders through graph | — |
| 17 | ENG-09 | Depth buffer and test | Overlapping triangles sort correctly | — |
| 18 | ENG-10 | Per-frame uniform buffer | Triangle color changes each frame | — |
| 19 | ENG-11 | ImGui pass | ImGui demo window renders over triangle | — |
| 20 | ENG-12 | ImGui toggle and strip | Debug shows UI, release has no ImGui symbols | — |

Task 21 begins MUT-01. The engine seed ends at ENG-22 and the deterministic-core gate follows MUT-12. Mute v1 completion is separately planned through MUT-59.

## Integration review, 2026-11-22

Camera projection and Vulkan depth-range defects were fixed with a dependency-free regression test; strict-warning CTest passed on Linux. Target GPU visual verification and existing platform gates remain open. See `../integration-review-2026-11-22.md`.

## Broader review, 2026-11-22

KTX2 parsing, configuration allocation safety and asset lifetime/retry failures were repaired with regression tests. Target SDK, device and earlier phase-gate verification remain open. See `../project-review-2026-11-22.md`.
