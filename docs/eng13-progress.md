# ENG-13 — Structured logging with file sink

Acceptance: *"Log file with timestamps."*

## Implementation

- New `poko_logging` STATIC library (`engine/foundation/`), built only under `POKO_WITH_DEPENDENCIES` since it wraps spdlog (already a vcpkg dependency).
- `poko/foundation/logging.hpp`: `init(Config{file_path, level, echo_to_console})`, `shutdown()`, and level functions `trace/debug/info/warn/error/critical(category, message, fields)`.
- Each record renders as `[YYYY-MM-DD HH:MM:SS.mmm] [level] [poko] category: message key=value ...` via an fmt pattern on a `basic_file_sink_mt` (truncate-on-open) plus optional `stdout_color_sink_mt` echo.
- Structured fields are `key=value` pairs appended to the message — deliberately simple; CBOR/JSON structured sinks are ENG-14+ territory.
- Thread-safe init/shutdown via mutex; calls before `init` or after `shutdown` are dropped (checked via an explicit `g_initialized` flag — `spdlog::default_logger()` auto-creates a console logger, so it cannot be used as the guard).
- Double `init` returns `errc::device_or_resource_busy`; sink/logger failures return `errc::io_error`. Re-init after `shutdown` drops the stale named logger (`spdlog::drop("poko")`) since `spdlog::shutdown()` flushes but does not unregister.

## Verification — Windows laptop (MSYS2 UCRT64)

`pokox_logging_file_test` (CTest): writes `%TEMP%/poko_eng13_logging/engine.log`, asserts ≥4 timestamped lines via regex `\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d+\]`, asserts category/field content, double-init rejection, and re-init after shutdown. **PASS**; sample line:

```
[2026-11-21 12:35:32.584] [debug] [poko] rhi: device created adapter=0 api=vulkan
```

## Reproduce / open work

```sh
cmake -B build-full -DPOKO_WITH_DEPENDENCIES=ON # plus prior options
ninja -C build-full pokox_logging_file_test && ./build-full/pokox_logging_file_test.exe
```

Not yet wired into engine subsystems (RHI/platform call sites) — ENG-14 (CBOR config) will consume settings such as log level/path. Async/file-rotation sinks, per-category levels, O(1) structured (CBOR) output, log shipping, MSVC/CI and Android legs remain open.
