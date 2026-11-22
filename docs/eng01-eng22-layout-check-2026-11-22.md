# Project layout check — 2026-11-22

## Result

Reviewed the delivered ENG-01–22 audit archive and working project for module placement. No source file was moved: the reviewed engine source, tests, shaders, fake dependencies and golden fixture fit the established module layout. Other project assets and original files were preserved; this is not a content-quality audit of every character asset or unrelated scaffold.

- `engine/foundation`: common headers in `include/poko/foundation`, implementations in `src`, unit and integration tests under their respective `tests` folders. `duration_query_state.hpp` is colocated with frame statistics.
- `engine/platform`: canonical window interfaces under `include/poko/platform/window`, SDL implementations under `src/window`, test doubles and tests under `tests`.
- `engine/rhi`: device/diagnostics implementation and headers under matching `src/device`, `src/debug`, `include/poko/rhi/device`, and `include/poko/rhi/debug`; isolated fake SDK headers under `tests/fakes`; tests under `tests/unit` and `tests/integration`. Mesh fakes are isolated in `tests/fakes/mesh`.
- `engine/render`: frame graph/camera source and headers, demos under `src/passes`, GLSL under `shaders`, golden reference under `tests/fixtures/golden`, and X11/capture scripts under `tests/integration`. The golden encoder test also exercises fixture and subprocess safety and lives next to its integration capture helper.
- `engine/resource`: asset store and asset formats in the module's `include`/`src`; their tests are under `tests/unit`.
- `engine/build/cmake` holds shader build helpers; shared golden/version tools and the Linux dependency lock are under `tools`; audits are under `docs`. Character project files remain under `assets/characters`.

Old public headers are intentional forwarding headers. Original `engine/foundation/tests/` test copies are preserved; CMake uses their `unit`/`integration` counterparts. The original lower-case `.github/issue_templates` copies are also preserved; GitHub-facing templates live in `.github/ISSUE_TEMPLATE`. Historical dated reports describe the paths at the time of those runs, not necessarily canonical current paths.

## Documentation fix

`structure.md` previously described a 2,714-directory planned scaffold as if it existed in the delivered archive. Recounting the archive yielded 134 directories, excluding the project root and `.git`; hidden skills/configuration and the graph cache are included. Its inventory is now labeled as a plan and the actual archive snapshot is stated separately. In particular, absent planned placeholders are not silently created or represented as implemented modules. Counts can change when generated files/caches or the archive change.

## Checks and limits

- Extracted the previous audited ZIP to a clean location: no duplicate ZIP names, no absolute/traversal entries and no case-folding filename collisions outside `.git`.
- All 52 literal CMake-referenced source, test, helper, shader and fixture paths detected by the layout checker existed in the extraction; key fake/header/fixture directories were present. This static scan does not cover dynamically constructed paths.
- Configured a fresh strict C++20 build from the extracted archive with `-Wall -Wextra -Wpedantic -Werror`; **43/43 CTest entries passed**. This is the dependency-free configuration with test doubles, not a full platform or GPU test.
- No target-platform, full-manifest, GitHub CI or physical-GPU acceptance gate is closed by a folder review. See `eng01-eng22-hardening-audit-2026-11-22.md` for the full audit and open risks.
