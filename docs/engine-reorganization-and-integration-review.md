# Engine reorganization and ENG-01–03 review

Date: 2026-11-21. This continuation supersedes the placement assessment in `eng01-eng03-integration-review.md`. It does not close any project acceptance gate.

## Source organization

- The window platform interface and SDL header now live in `engine/platform/include/poko/platform/window/`; SDL implementation and window demo sources live in `engine/platform/src/window/`.
- The Vulkan clear renderer and demo live in `engine/rhi/include/poko/rhi/device/` and `engine/rhi/src/device/`. The diagnostic header and implementation live under the corresponding `debug/` directories.
- Build flags live in `engine/foundation/include/poko/foundation/`. The build-flag contract test moved to `engine/foundation/tests/unit/`; the dependency smoke test and build-info check moved to `engine/foundation/tests/integration/`.
- Existing public header paths remain as lightweight forwarding headers, so existing source includes keep working. New project sources use the organized paths. The cross-module compatibility test includes both forms together.
- Updated CMake, test runners, verification script, current documentation and the version-integration test's copied inputs. Preserved test-only third-party header paths and the foundation executable entry point; those have roles requiring their existing locations.
- Previously corrected GitHub issue templates remain in `.github/ISSUE_TEMPLATE/`. Historical dated evidence describes the paths used when it was recorded, not current reproduction paths.

## Fresh verification

Linux x64, GCC 11.5.0, CMake 3.31.10, C++20, Debug, `-Wall -Wextra -Wpedantic -Werror`:

- Dependency-free CMake build: **19/19 CTest passed**, including the compatibility-header test, platform contract and renderer tests using dependency doubles.
- Built SDL **3.4.20** locally, with dummy/offscreen support and without X11, Wayland or Vulkan. Enabled `POKO_WITH_SDL_PLATFORM`: **21/21 CTest passed**, including real SDL dummy-driver and invalid-driver tests. This is not a visible window or GPU test.
- Platform mutation runner: **11/11** intentional regressions detected. Renderer seed mutation runner: **8/8** intentional regressions detected; Linux, Win32 and Android native-layout branches and demo diagnostics passed against test doubles, not actual target SDKs or operating systems.

Typical reproduction, using installed CMake 3.28+ and a separately installed SDL3:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
cmake --build build -j 4
ctest --test-dir build --output-on-failure --no-tests=error
cmake -S . -B build-sdl -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON -DPOKO_WITH_SDL_PLATFORM=ON -DCMAKE_PREFIX_PATH=/path/to/sdl3
cmake --build build-sdl -j 4
ctest --test-dir build-sdl --output-on-failure --no-tests=error
python3 engine/platform/tests/unit/check_fault_sensitivity.py --cxx g++
python3 engine/rhi/tests/unit/run_seed_checks.py --cxx g++ --mutations
```

## Remaining limits

The real Diligent/Vulkan build and GPU presentation were not rerun here; Vulkan headers and Diligent are not installed. The earlier Windows MinGW evidence reports a successful visible clear, but that is a historical result, not a new verification. MSVC, GitHub Actions, Android activity/lifecycle and device testing, validation-layer load confirmation, and ENG-05 resize recreation remain outstanding. No acceptance gate is marked complete by this review.
