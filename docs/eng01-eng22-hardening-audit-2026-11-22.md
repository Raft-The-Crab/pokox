# ENG-01–ENG-22 hardening audit — 2026-11-22

## Scope

A source/integration review of the existing engine tasks, building on `eng01-eng21-audit-2026-11-22.md` and `eng-progress.md`. This is not proof that every defect has been found, a new feature wave, or a waiver of pending gates. No anti-aliasing, new renderer capability, or next queue task was added. Historical evidence applies to its original revision only.

## Findings and fixes

1. **ENG-15: duration query reused while pending.** The pinned Diligent Vulkan backend discards the earlier result when `BeginQuery` is called again. The demo now permits one in-flight duration query, polls only after submission and starts another only after the result is collected. Skipped frames produce no sample, and a completed zero-frequency result is consumed without recording a fabricated duration. GPU availability is reported separately. A deterministic fake-query test covers delayed results, skipped draws and rearming; real software Vulkan produced GPU timings.
2. **ENG-17: completed worker jobs were called ready before installation.** Added `LoadState::awaiting_install` at the end of the enum, retaining the earlier values. `ready` now means a payload has been installed and can be acquired. Continue polling while awaiting installation; `is_loading` still describes queued/running work only. Consumers with exhaustive switches must handle the new state. Allocation-failure and acquire-before-poll regressions cover the transition.
3. **ENG-17: stale failures and inaccessible empty keys.** An unpolled failed job could later publish an obsolete error during a retry or after synchronous recovery. Retry now removes superseded completed failures only after enqueue succeeds; successful synchronous recovery clears them as well. Empty async keys are rejected with `std::invalid_argument`, consistent with synchronous acquire rejecting them. Three tests failed on the old implementation and passed after the fix. Owner-thread use, startup allocation and potentially blocking worker join are now documented instead of promising a universally nonblocking call.
4. **ENG-18: replaced textures could still use the old SRB.** Texture changes now invalidate the old pipeline and static binding, so the new view is actually bound. Texture upload uses temporary GPU resources and binds the pass to its first device before allocation. Null/malformed mip lists, invalid dimensions, too many levels and size overflow are rejected; allocation exceptions leave the previous texture intact. A fake test exercises replacement and failed initialization followed by a foreign device. Input pointers must still reference valid readable memory supplied by the caller.
5. **ENG-19–21: partial mesh setup could corrupt retry/recreation.** Immutable mesh buffers and pipeline camera/light buffers/SRB are constructed transactionally. First-device ownership is established before resource creation, even on failure. Oversized index counts are rejected before reading input, and allocation failures in `set_mesh` preserve the old mesh. A new test double injects a mid-rebuild failure, checks old buffer reuse on the original format, verifies foreign-device rejection after setup failure, and rejects counts too large for the draw API. These are control-flow tests, not GPU device-loss simulations.
6. **ENG-11/12: pinned ImGui could not compile on GCC.** The texture-ID cast was invalid for the default integer `ImTextureID` in the pinned 1.93.0 release. Fixed the cast and GCC-invalid fake descriptor type names. Font atlas creation is transactional so failure after creating a view cannot masquerade as success on the next draw. A sampler-failure retry regression and actual pinned-ImGui builds were added/run; fake objects now release their allocations.

## Evidence by task

| Task | Current audit evidence | Important remaining qualification |
|---|---|---|
| ENG-01 | Platform interface and fault/contract tests pass in local suites. | Windows/Android compilation of this revision unverified. |
| ENG-02 | SDL fault tests and real SDL integration run in Linux suites. | Real target Windows/Android lifecycle and high-DPI unverified. |
| ENG-03 | Real pinned Diligent + SDL software Vulkan; validation requested and validation layer observed. | Physical GPU, current Windows/Android, loss/recovery still open. |
| ENG-04 | Real fallback builds and selector/failure doubles pass. | Virtual X11 lacked an sRGB GLX visual; GL/ES rendering parity and target-device behavior remain open. |
| ENG-05 | Existing resize fault/visual checks and golden run; prior software-X11 cube orbit/resize checks. | Current hardware, Android, real high-DPI, GL resize not established. |
| ENG-06 | Frame-graph ordering, cycle and mutation tests pass. | CPU scheduler only; no claim of GPU barriers or automatic resource management. |
| ENG-07 | Host compiler produced shader binaries; current ImGui SPIR-V validated against Vulkan 1.1. | No Vulkan 1.0 guarantee; other platform toolchains unverified. |
| ENG-08 | Triangle build and validation-enabled ImGui-scene render on software Vulkan. | Real hardware and GL/ES visual parity unverified. |
| ENG-09 | Depth and fault suites pass; prior depth-on versus depth-off visual evidence. | Current target hardware not tested. |
| ENG-10 | Uniform update/fault tests pass; real demo builds. | Target hardware and full platform matrix remain open. |
| ENG-11 | Pinned ImGui 1.93.0 (download SHA-512 checked against vcpkg port), real Diligent and SDL debug demo: 120 frames; dedicated real-ImGui/fake-Diligent fault tests pass. | This manual integration build is not the complete vcpkg build. Keyboard/text input, arbitrary UI textures, GL/ES and Android remain incomplete. |
| ENG-12 | Stripped executable linked without ImGui symbols; synthetic F1 hide/show visibly changed the image both ways over 1,500 frames. | Linux Xvfb/llvmpipe, not physical input or target-device proof. |
| ENG-13 | Dependency-free logger doubles pass; real spdlog checks from the preceding Linux review. | Full current vcpkg manifest and target-platform checks not run. |
| ENG-14 | Configuration, override and allocation tests pass; demos consume settings. | Target platform/full-manifest integration unverified. |
| ENG-15 | Delayed-query lifecycle tests plus real debug/strip GPU samples; no per-frame GPU stalls added. | Unsupported devices and true GPU latency not represented by this software Vulkan run; missing samples are not zero work. |
| ENG-16 | Handle, refcount, allocation and lifetime tests pass with sanitizers. | Handle/store APIs are owner-thread-only; arbitrary concurrency is not supported. |
| ENG-17 | Retry, recovery, empty-key and ready/install regressions pass; allocation failure is retried. | Callers must poll on the owner thread; no integration of async loading with texture streaming. |
| ENG-18 | KTX2 parser tests, texture replacement/device control-flow tests and real demo build pass; earlier independent KTX2 visual upload passed. | No new full-mip sampling or physical-GPU test this revision; raw-pointer inputs require valid caller-owned memory. |
| ENG-19 | Mesh parsing, new buffer/pipeline fault tests and real cube golden pass. | Fake resource-failure tests are not physical-device fault or GPU memory-pressure tests. |
| ENG-20 | CPU camera tests and real cube golden pass; prior synthetic camera/orbit/resize smoke. | Target input, Android and high-DPI remain unverified. |
| ENG-21 | Directional-light tests and real cube golden pass; earlier live arrow-key software test. | The simple identity-model Lambert prototype is not a material/shadow system. |
| ENG-22 | Real software-Vulkan fixed-view golden comparison passes; golden harness and encoder tests pass. | Baseline is specific to the documented llvmpipe environment; the GitHub job has not run, and physical-GPU determinism is not asserted. |

## Final verification

- Strict dependency-free C++20 build, `-Wall -Wextra -Wpedantic -Werror`: **43/43** CTest entries passed. These include multiple dependency doubles, not 43 live-device tests.
- Dependency-free ASan/UBSan build with leak detection: **43/43** passed; not a sanitizer run of the real Vulkan driver.
- Real SDL3 + pinned Diligent Vulkan/GL build on Linux: **59/59** configured tests passed, including the exact cube golden on Xvfb + Mesa llvmpipe. The suite includes unit tests/doubles and does not establish that OpenGL displayed a frame.
- Actual pinned ImGui 1.93.0 sources, SDL3 and Diligent were compiled in a separate manual debug and stripped build with logging disabled, not a full-manifest/vcpkg build. Under Xvfb/llvmpipe, each rendered 120 frames with validation requested, the Khronos validation layer observed, and 0 captured graphics errors/warnings. Both reported real GPU samples. `nm -C` found no `ImGui::` symbols in the stripped executable.
- Optional synthetic-X11 test toggled F1 twice, changed 138,240 image bytes in each direction, submitted 1,500 frames and reported 0 captured graphics errors/warnings and an available GPU duration. This demonstrates a visual response, not full input/UI correctness.
- Existing ImGui failure tests use real ImGui draw data and fake Diligent objects; they pass with the new sampler-retry check, including a separate ASan/UBSan run with leak detection over the ImGui sources and test doubles. UI shaders pass `spirv-val --target-env vulkan1.1`; workflow files pass actionlint. These do not mean GitHub CI has run.
- The source graph was refreshed. Graphify reports a partial extraction for preprocessor-heavy `imgui_demo.cpp` and symbol-less forwarding fake headers; this is an indexing warning, not a compiler diagnostic. Semantic document indexing was not refreshed.

## Open risks and next work

Full vcpkg/ImGui/logging integration, current MSVC/Windows, Android, real high-DPI, real OpenGL display and physical GPU remain unverified. The upstream Diligent configuration emits CMake deprecation warnings; Xvfb can emit nonfatal keyboard-map warnings. The local successful builds do not establish a warning-free project or prove absence of bugs. Keep all earlier infrastructure/platform and golden CI gates open. A later task can address anti-aliasing; none was added in this hardening pass. Re-run target checks on the user's laptop before accepting platform milestones.
