# Historical build notes — not current status

These are the unverified notes supplied with the original archive. For the current scaffold, see [build.md](build.md).

# Build status

**Current scaffold:** build setup is not present or verified. The archive contains no root `CMakeLists.txt`, `vcpkg.json`, or CI workflow, and no build or test was run for this scaffold. INF-02 is the next planned task.

The section below is retained from the supplied archive as a historical, unverified snapshot; its claims and commands do not describe a working build in this scaffold. Update this page as build files and verified results are added.

---

## Historical build notes (unverified)

# Build status

Last updated when INF-04 landed.

## Toolchain matrix

| Tool | Local (this workspace) | CI |
|---|---|---|
| Git | 2.55 | actions/checkout, full history |
| CMake | 4.4 | via MSYS2 / MSVC job |
| C++ compiler | MSYS2 MinGW g++ 16.2 | MinGW-w64 and MSVC |
| Python | 3.13 | MSYS2 python |
| vcpkg | not installed | not wired yet |
| MSVC (`cl`) | not installed | `windows-2022` runner |

## Commands

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

To exercise a different flag combination (INF-03):

```sh
cmake -S . -B build-imgui -DCMAKE_BUILD_TYPE=Debug -DPOKO_IMGUI=ON
cmake --build build-imgui
ctest --test-dir build-imgui --output-on-failure
```

Caveat: with `POKO_IMGUI=ON` the flag changes compile definitions, but the ImGui library itself is not linked until ENG-11 lands. This is intentional — the flag contract is tested independently of the dependency.

## Full dependencies

`-DPOKO_USE_VCPKG=ON` requires a vcpkg toolchain file:

```sh
cmake -S . -B build-vcpkg \
  -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake \
  -DPOKO_USE_VCPKG=ON
```

`vcpkg.json` declares SDL3, spdlog, Catch2 and ImGui. DiligentCore has no stable upstream port; ENG-03 will pin an overlay port or submodule before the RHI target is added. Until then the dependency-free path builds and tests foundation, platform, flags, version embedding and the golden harness.

## Golden files

`tools/golden/golden.py --golden <file> --actual <file>` compares bytes exactly. Regeneration is explicit with `--update`. `--self-test` proves both the pass and fail paths.
