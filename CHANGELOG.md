# Changelog

All notable changes to PokoX are documented here. The format follows
[Keep a Changelog](https://keepachangelog.com/en/1.1.0/) and the project
has not made a versioned release yet; entries are grouped by task until
the first release tag exists.

## [Unreleased]

### Added

- Project scaffold: `engine/`, `client/`, `server/`, `backend/`, `mod/`,
  `mute/`, `studio/`, `applications/`, `tools/`, `assets/`, `docs/`
  (INF-01).
- CMake build foundation with `vcpkg.json` manifest (SDL3, ImGui, spdlog,
  Catch2), dependency-free default target, and opt-in flags
  `POKO_WITH_DEPENDENCIES`, `POKO_WITH_SDL_PLATFORM`,
  `POKO_WITH_VULKAN_DEMO`, `POKO_IMGUI`, `POKO_D3D12`, `POKO_DEBUG`
  (INF-02/INF-03).
- GitHub Actions CI for Windows MSVC and MSYS2 MinGW toolchains
  (INF-04, pending first green run).
- Byte-exact golden-file test harness under `tools/testutils/` (INF-05).
- Git-tag build version metadata; untagged builds report `unversioned`
  (INF-06).
- Backend-independent `IPlatform` single-window contract and test double
  (ENG-01).
- SDL3 window backend, `pokox_window_demo`, and platform fault-injection
  tests (ENG-02).
- Vulkan window intent, size queries, and borrowed SDL native-window
  access as ENG-03 prerequisites.
- Opt-in Diligent/Vulkan clear-color source candidate (`POKO_WITH_VULKAN_DEMO`)
  with desktop demo, diagnostics capture, and laptop evidence runner
  (ENG-03, in progress — not yet accepted).
- Legal document drafts under `docs/legal/` (LEG-01 drafts; counsel review
  required before ship).
- Planning specs under `docs/plan/` (31 documents).
- Character asset work: BlockyR6 and BoyR6 adapted `.blend`/`.glb` sources,
  animation v2 sets, and preservation-first prototypes under `assets/`.

### Fixed

- `tools/version/cmake/generate_version.cmake`: pass `ENCODING NONE` to
  `git` subprocess calls so non-ASCII tag names and checkout paths are not
  corrupted by the Windows console codepage during `execute_process`
  output capture (found by `version_integration` on Windows).

### Changed

- `vcpkg.json`: `sdl3` now enables the `vulkan` feature, required for
  `SDL_WINDOW_VULKAN` and the ENG-03 clear demo.
- `CMakeLists.txt`: configure-time patch adds a missing `<cstdint>`
  include to the pinned DiligentCore glslang `SpvBuilder.h` (GCC 16
  compatibility).
- `pokox_vulkan_clear`: new `--adapter N` option and
  `ClearConfig::adapter_id` for explicit Vulkan physical-device selection.
- `.github/workflows/ci.yml`: MinGW job passes `-DMINGW_BUILD=TRUE` so
  Diligent skips its DXC/ATL path that MinGW cannot compile.

### Added (continued)

- `LICENSE` (proprietary, contributor no-copy/no-release terms),
  `CONTRIBUTING.md`, `CHANGELOG.md`, `CODE_OF_CONDUCT.md`, `SECURITY.md`,
  pull request template, and bug/feature issue templates.
- `docs/eng03-windows-laptop-evidence.txt`: first real Windows
  verification record.

### Notes

- Windows (MSVC and MSYS2) and Android acceptance checks are still open
  for INF-02/INF-04 and ENG-01/02/03; see `docs/build.md`,
  `docs/plan/02-work-queue.md`, and `docs/eng03-progress.md`.
- The Vulkan clear demo is a source candidate verified against dependency
  doubles; real SDK compilation, GPU output, and validation-layer
  acceptance remain pending.
