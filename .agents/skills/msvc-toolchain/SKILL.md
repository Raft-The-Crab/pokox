---
name: msvc-toolchain
description: Build, test, and debug Poko with the MSVC/Windows toolchain on this machine. Use whenever compiling, running tests, or configuring sanitizer/debug builds on Windows.
---

# MSVC Toolchain (this machine)

- Compiler: `C:\BuildTools\VC\Tools\MSVC\14.44.35207` (MSVC 19.44), Windows SDK `10.0.26100.0`.
- There is NO `vcvarsall.bat`/`VsDevCmd.bat`/MSBuild — set env manually (scripts live in `tools/msvc/`: `msvcenv.bat`, `msvcbuild.bat`, `msvcasan.bat`, `msvc-debug.bat`).
- CMake/CTest/Ninja are standalone WinGet installs at `%LOCALAPPDATA%\Microsoft\WinGet\Links\` — MSYS2 is NOT required for builds.
- Python is python.org 3.13 (`%LOCALAPPDATA%\Programs\Python\Python313`); git is Git for Windows (`C:\Program Files\Git`).
- CMake cannot use the "Visual Studio" generator — always use `-G Ninja`.
- Always pass `-DCMAKE_CXX_STANDARD=20` (MSVC defaults to C++14; some fault-test targets lack `cxx_std_20`).

## Build dirs

- `build-msvc/` — plain Debug build (Ninja)
- `build-msvc-asan/` — `/fsanitize=address /fsanitize-address-use-after-scope`
- `build-msvc-debug/` — full debug profile via `msvc-debug.bat`

## Debug profile flags (cl.exe)

`/Od /W4 /WX /analyze /sdl /RTC1 /RTCsu /RTCu /RTCs /fsanitize=address /Zi`

NOT valid for `cl.exe` (require clang-cl, not installed):
`/fsanitize=fuzzer`, `/fsanitize=fuzzer,address`, `/dynamicdeopt`. `/O1`/`/O2` conflict with `/Od` — use a Release config for optimization.

## Test

```
cd build-msvc && ctest -j 12 --output-on-failure
```

ASan tests need the runtime DLL dir on PATH:
`PATH="/c/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64:$PATH"`

Known MSVC-only test quirks: `mute_program_unit` needs `/STACK:8MB` (already in CMakeLists); `pokox_config_allocation_test` aborts under MSVC debug CRT (operator-new injection vs CRT heap — harness issue, not product); fault-injection tests are allocation-count sensitive under ASan.

## Performance tuning (Ryzen 7 5700U, 16 GB)

Use `-j 12` max for builds/tests — 16 threads can exhaust RAM on debug+ASan builds.
