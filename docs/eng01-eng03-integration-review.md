# ENG-01–ENG-03 integration review

Review date: 2026-11-21. This review distinguishes fresh checks in a Linux sandbox from earlier project-reported Windows results. It does not close any project acceptance gate.

## Organization

- Moved `.github/issue_templates/` to `.github/ISSUE_TEMPLATE/`, including both templates and `config.yml`. GitHub expects the latter directory, which is also the path documented in `CONTRIBUTING.md`.
- Updated the current directory inventory in `docs/structure.md`. The original `docs/structure-plan.md` is historical and was not rewritten.
- A subsequent organization pass moved engine source, public headers and foundation tests into module-specific scaffold subfolders. See `docs/structure.md` for current paths; compatibility headers preserve the original include paths. Historical commands below predate that move.

## Wiring examined

- ENG-01: CMake exposes the platform interface as `poko_platform`, and its contract test compiles against its public include directory.
- ENG-02: `POKO_WITH_SDL_PLATFORM` builds `poko_platform_sdl` from the SDL source, links the platform interface and SDL3, and builds the window demo. Fault tests compile the production backend against test doubles.
- ENG-03: `POKO_WITH_VULKAN_DEMO` requires the SDL platform option; the opt-in renderer links the SDL platform, SDL3 and Diligent Vulkan. The RHI seed tests compile platform and renderer sources together against isolated doubles. This is a source/configuration review, not a fresh real-SDK build.

## Fresh checks in this sandbox

- GCC 11.5.0, C++20, `-Wall -Wextra -Wpedantic -Werror`: platform interface contract and SDL backend fault tests compiled and passed.
- `python3 engine/platform/tests/unit/check_fault_sensitivity.py --cxx g++`: all 11 injected regressions were detected.
- `python3 engine/rhi/tests/unit/run_seed_checks.py --cxx g++`: Linux, Win32 and Android native-layout branches passed against test doubles; the demo argument and diagnostic checks passed too. These are not cross-builds or real GPU tests.
- `python3 engine/rhi/tests/unit/test_verify_desktop.py`: 12 evidence-runner tests passed.
- CMake/CTest and real SDL3/Diligent/Vulkan builds were not run: CMake and those dependencies were not available in this sandbox. No real window or GPU test was performed here.

## Acceptance and outstanding work

The supplied `eng03-windows-laptop-evidence.txt` reports a prior Windows MinGW run that displayed the expected blue clear on an AMD GPU. It also states that validation-layer loading was inferred, not independently confirmed. This was not reproduced during this review. MSVC, GitHub Actions, Android lifecycle/device testing and other project gates remain open. Several module READMEs contain older status statements that conflict with the later Windows evidence; consult the dated evidence and work queue before treating a historical statement as current. Renderer resize recreation remains future work (ENG-05).
