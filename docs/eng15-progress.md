# ENG-15 — Frame timing and stats

Status: implemented and verified on the AMD GPU (Windows, MSYS2 UCRT64).

## What was built

- `engine/foundation/include/poko/foundation/frame_stats.hpp` +
  `src/frame_stats.cpp` — `poko::stats::FrameStats`: dependency-free rolling
  statistics. `record_cpu()` once per presented frame, `record_gpu()` as
  duration-query results land; 120-sample windows give `cpu_ms()`, `gpu_ms()`
  and `fps()`. NaN/inf/negative samples are rejected.
- `pokox_frame_stats_test` (both trees): means, FPS, window wraparound,
  independent CPU/GPU windows, invalid-sample rejection.
- `pokox_imgui_demo` (+ `_strip`):
  - CPU frame time measured around `graph.execute()` (event poll + passes +
    submit).
  - GPU frame time via a lazily created Diligent `QUERY_TYPE_DURATION` query
    bracketing the scene+ImGui composite in `composite()`. A
    `DurationQueryState` gate allows only one outstanding query: `BeginQuery`
    is skipped while a previous result is still pending, and `GetData` is
    polled only then, so Diligent never discards an uncollected sample.
    Devices without `DurationQueries` support keep `gpu_ms()` at 0.
  - The ImGui demo window shows `CPU: x.xx ms   GPU: x.xx ms` alongside FPS.
  - `POKO_IMGUI_RESULT` now reports `cpu_ms=`/`gpu_ms=` averages.

## Verification

- `pokox_frame_stats_test` passes in `build/` and `build-full/`.
- Both trees build clean; `build/` 25/25 and `build-full/` 30/30 CTest pass.
- End-to-end on the AMD GPU:
  `pokox_imgui_demo --frames 120` →
  `POKO_IMGUI_RESULT submitted=120 ... cpu_ms=14.68 gpu_ms=0.25` — the
  duration query reports real GPU frame time and the ImGui window shows it.
- Note: Vulkan device init intermittently tripped a Diligent debug
  assertion (`FindQueueFamily` granularity VERIFY, VulkanPhysicalDevice.cpp:435)
  during this session — a transient driver/enumeration state, not a code
  defect; `--adapter 0` runs cleanly.

## Not done / future

- Per-pass GPU timings (ENG-44 builds on this: timestamps, validation
  layers, profiler ring per ENG-100).
- CPU stats are only wired into the ImGui demo; other demos can adopt
  `FrameStats` as the engine loop stabilizes.
- GPU timer measures the whole composite (scene + UI), not per-pass.
