# Post-implementation audit — ENG-01 through ENG-13

Three parallel read-only audits (platform/foundation, frame graph + RHI, ENG-11/12/13) plus manual review. All confirmed defects were fixed and the affected suites re-verified on Windows (MSYS2 UCRT64, AMD Radeon).

## Bugs fixed

| Area | Defect | Fix |
|---|---|---|
| `imgui_demo.cpp` | SDL3 button constants are indices, not masks — right/middle/X buttons misreported | `SDL_BUTTON_*MASK` bits |
| `imgui_demo.cpp` | Mouse pos/buttons fed from whatever window had focus | Gate on `SDL_GetMouseFocus()`; report `(-FLT_MAX,-FLT_MAX)` when unfocused |
| `logging.cpp` | `g_initialized` plain bool read lock-free vs mutex writes — data race (UB) | `std::atomic<bool>` |
| `logging.cpp` | `spdlog::shutdown()` flushed/dropped every process logger; `"poko"` logger + file handle leaked until exit | `spdlog::drop("poko")`; records emit through a pinned `shared_ptr<spdlog::logger>` so foreign `set_default_logger` can't reroute them |
| `logging.cpp` | `emit()` could throw `bad_alloc` into engine code; `init()` missed `catch(...)` in `noexcept` | `emit` is `noexcept` + `catch(...)`; `init` catches all |
| `vulkan_imgui_pass.cpp` | Failed buffer growth released the buffer but kept stale capacity → next frame `MapBuffer(nullptr)` crash | Create into locals; on failure release + zero capacity; promote on success |
| `vulkan_imgui_pass.cpp` | `owner` device check had a partial-init gap; `frame_buffer`/`binding` created into members could go stale on failure | `owner` bound at first `draw()`; pipeline resources built into locals and promoted together |
| `opengl_clear_renderer.cpp` | Failed `initialize()` left `impl_` allocated → all retries returned `already_initialized` | Build into `pending`, commit `impl_` only on success (matches Vulkan renderer) |
| `imgui_demo.cpp` | Early `return 1` paths skipped `ImGui::DestroyContext()` | `ImGuiContextGuard` RAII |
| `frame_graph.cpp` | Empty `after` name reported `unknown_dependency` instead of `empty_name` | Explicit empty check |
| `sdl_platform.cpp` | HiDPI resize emitted duplicate `window_resized` events (`WINDOW_RESIZED` + `PIXEL_SIZE_CHANGED`) | Dedupe consecutive identical sizes |
| `CMakeLists.txt` | `pokox_imgui_demo_strip` was a byte-duplicate when `POKO_DEBUG=OFF` | Strip target/tests only exist when `POKO_DEBUG=ON` |

## Test updates

- `opengl_clear_faults.cpp`: failed `initialize()` now asserts `library_refs==0` (immediate cleanup) instead of the old leak-until-shutdown expectation.
- `logging_file_test.cpp`: rewritten for truncate-per-init semantics — verifies session 1 (level filtering, fields, timestamps) and session 2 (re-init truncation + info-level filter) separately.

## Verified

- `build/` dependency-free: **28/28 CTest pass** (after fault-test update).
- `build-full/`: imgui demo + strip + logging + framegraph + sdl faults + fallback suites pass; `pokox_imgui_demo --frames 30` clean.
- `vulkan_imgui_pass.hpp` now documents that `draw()` leaves pipeline/scissor state bound (pass must be last in frame).

## Known remaining gaps (documented, not defects)

- `VulkanImGuiPass` has no fault-injection unit test (largest untested file; needs Diligent fakes).
- Test-double signatures drift from real Diligent ABI (`EngineFactoryVk.h` fakes) — compile-isolated; a `decltype` contract check could catch divergence.
- `vulkan_diagnostics` `callback_restore_failed` is a permanent poison flag (conservative, restart-only recovery).
- `fallback_clear_backends` shutdown ordering skips diagnostics/window stop on failure path (terminal anyway via `cleanup_error_`).
- Platform minors: `Event::type` defaults to `quit_requested`; SDL error detail not snapshotted into platform API; resize event dropped if size query fails.
- MSVC compile leg, GitHub CI run, Android legs remain open per prior audits.

## Gap-closure round 2

- `fallback_clear_backends.cpp`: `shutdown()` now always stops diagnostics and the window even when renderer cleanup fails (previously returned early, leaving the SDL window and Diligent callback installed).
- `i_platform.hpp`: `Event::type` defaults to new `EventType::none` instead of `quit_requested` — a default-constructed Event no longer claims a quit.
- Fake/real signature drift — verified each claim against pinned Diligent headers: `SetMessageCallback` **is** `const`, `CreateSwapChainVk` **does** take `const NativeWindow&`, and `ClearRenderTarget` **does** take `const void*` (audit claims were wrong). Real drifts fixed: `SwapChainDesc::DepthBufferFormat` default corrected to `TEX_FORMAT_D32_FLOAT` (real default), and triangle fake `CreateBuffer` now takes `const BufferData*` with a matching `BufferData` struct.
- Verified: `build/` platform_contract + sdl_platform_faults + triangle_pass_faults + vulkan_faults (6/6) and `build-full/` fallback suite (4/4) all pass.
- `VulkanImGuiPass` fault-injection coverage — **added**: `engine/rhi/tests/fakes/imgui/` provides a dedicated Diligent double surface (superset of the base fake + all create/draw methods the pass uses), and `pokox_imgui_pass_faults` exercises bad-shader ctor, empty draw data, injected `CreateBuffer` failure + retry (the null-buffer regression), resource reuse, buffer growth, and foreign-device rejection. Passes under CTest.
- Diagnostics restore-failure recovery — **added**: `start_with_factory` retries the failed restore and clears the poison flag only on verified success; persistent failure stays fail-closed (vulkan_faults 3/3).

## Final audit round (pre-closeout)

Two fresh-eyes audits of the uncommitted surface found and fixed:

- `logging.cpp`: `g_logger` lock-free copy raced with init/shutdown writes → `std::atomic<std::shared_ptr<spdlog::logger>>`; also stopped installing "poko" as the process default logger (drop() at shutdown left spdlog's default null for unrelated callers — emit() uses the pinned logger regardless).
- `vulkan_diagnostics.cpp`: failed poisoned-state recovery let `~Impl()` restore `previous==nullptr` over the still-installed capture callback → restore now gated on `installed`.
- Fake fidelity: `DrawIndexedAttribs` aligned to real layout (Flags/FirstInstanceLocation, Uint32 BaseVertex, phantom fields removed); `BIND_FLAGS` values corrected; `IShaderResourceVariable::Set` now single `Set(IDeviceObject*)` matching real Diligent; test asserts `FrameData`→IBuffer and `FontTexture`→ITextureView bindings plus `pVS`/`pPS` non-null.
- `pokox_build_info` ctest failure was a stale `pokox` binary (INTERFACE flag change), resolved by rebuild — not a code bug.

Verified: build/ 28/28, build-full 49/49 (after pokox rebuild), imgui_pass_faults + logging_file_test + vulkan_faults all pass.

Remaining known fidelity gaps (harness-level, not defects): FakeDevice ignores most descriptor content (bind flags/usage/texture formats), MapBuffer has no bounds check, diagnostics-error path untested, most fake enum values are sequential rather than real Diligent values.
