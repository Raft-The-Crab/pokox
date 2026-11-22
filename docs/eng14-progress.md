# ENG-14 — CBOR config loader

Status: implemented and verified on Windows (MSYS2 UCRT64, GCC 16, Ninja).

## What was built

- `engine/foundation/include/poko/foundation/cbor.hpp` + `src/cbor.cpp` —
  dependency-free decode-only CBOR data model (spec 21 assigns CBOR
  serialization to foundation). Supports uint/nint/bytes/text/array/map/
  bool/null/half/float/double. Rejects tags, indefinite lengths, reserved
  argument forms, trailing bytes, invalid UTF-8, nesting > 32 and > 262144
  values. Container reserves are capped at the remaining input so a hostile
  length header cannot over-allocate. Never throws.
- `engine/foundation/include/poko/foundation/config.hpp` + `src/config.cpp` —
  `EngineConfig` + `load_file(path)` + `resolve(path, overrides)`:
  top-level `window` (width/height), `graphics` (adapter_id, validation) and
  `logging` (level, file, echo) sections, all optional with defaults. Wrong
  types, non-map sections, zero window dimensions and unknown level names
  fail the load; unknown keys are reported (`section.key`) not fatal. Files
  capped at 1 MiB. `resolve()` merges explicit CLI overrides over file
  settings (CLI wins for validation/adapter; window/logging are file-only).
- `engine/foundation/include/poko/foundation/config_logging.hpp` —
  `config::LogGuard` RAII bridge to ENG-13 logging; a no-op unless the
  target defines `POKO_ENGINE_LOGGING=1` and links `poko_logging`.
- `poko_config` CMake target (always built, no dependencies).
- `--config file.cbor` on every runnable engine demo:
  `pokox_vulkan_clear`, `pokox_triangle`/`pokox_depth`/`pokox_uniform`,
  `pokox_imgui_demo`/`pokox_imgui_demo_strip`, `pokox_fallback_clear`
  (and the dependency-free `pokox_fallback_demo_double` test binary).
  Window size, adapter_id and validation come from the file; explicit CLI
  flags still win. `logging.file` initializes ENG-13 logging where
  `poko_logging` is linked.
- `VulkanClearBackend`/`OpenGLClearBackend` gained defaulted
  adapter/width/height parameters (source-compatible) so the fallback demo
  honors file settings.

## Verification

- `pokox_config_file_test` (both build trees): decoder edge cases
  (argument widths, negatives, floats, nesting, truncation, reserved/
  indefinite forms, UTF-8, depth/value caps) and config accept/reject/merge
  paths (full, partial+unknown keys, wrong types, zero size, bad level,
  bad section, bad root, malformed CBOR, missing file, CLI-override wins,
  empty-path defaults).
- `build/` 24/24 and `build-full/` 29/29 targeted CTest pass.
- End-to-end on the AMD GPU: `pokox_vulkan_clear` and
  `pokox_fallback_clear --frames 5 --config x.cbor` both applied
  `validation=false` from the file (`validation_requested=false`) and wrote
  the structured `config: settings loaded` record to the configured log.

## Defects found by the new tests during implementation

- Major-7 items consumed their float payload twice (argument reader ran
  before the simple/float branch) — floats decoded as truncated.
- `half_to_double` used the single-precision exponent bias (exp-25)
  instead of 15 — all half floats decoded wrong.
- Unimplemented simple values were reported `malformed` instead of
  `unsupported`.

## Not done / future

- No CBOR *encoder* yet — ENG-36 (schema versioning/migrations) and asset
  manifests will need canonical encoding; the decoder is ready for it.
- `pokox` and `pokox_window_demo` do not consume config yet (no settings
  surface to apply).
- OpenGL backend ignores `adapter_id` (GL has no adapter selection); the
  Vulkan fallback path honors it.

## Integration review, 2026-11-22

The configuration loader now catches allocation failures at its public boundary. Allocation-fault coverage was added; see `project-review-2026-11-22.md` for limitations.
