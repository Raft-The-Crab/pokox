@echo off
if not defined POKO_MSVC set "POKO_MSVC=C:\BuildTools\VC\Tools\MSVC\14.44.35207"
if not defined POKO_SDK set "POKO_SDK=C:\Program Files (x86)\Windows Kits\10"
if not defined POKO_SDKV set "POKO_SDKV=10.0.26100.0"
if not defined POKO_REPO set "POKO_REPO=C:\Users\mysti.LAPTOP.000\Desktop\Project Poko"
set "MSVC=%POKO_MSVC%"
set "SDK=%POKO_SDK%"
set "SDKV=%POKO_SDKV%"
set "PATH=%MSVC%\bin\Hostx64\x64;%SDK%\bin\%SDKV%\x64;%PATH%"
set "INCLUDE=%MSVC%\include;%SDK%\Include\%SDKV%\ucrt;%SDK%\Include\%SDKV%\um;%SDK%\Include\%SDKV%\shared;%SDK%\Include\%SDKV%\winrt"
set "LIB=%MSVC%\lib\x64;%SDK%\Lib\%SDKV%\ucrt\x64;%SDK%\Lib\%SDKV%\um\x64"
set "LIBPATH=%LIB%"
set "TOOLS=%LOCALAPPDATA%\Microsoft\WinGet\Links"
set "NINJA=%LOCALAPPDATA%\Microsoft\WinGet\Packages\Ninja-build.Ninja_Microsoft.Winget.Source_8wekyb3d8bbwe\ninja.exe"
cd /d "%POKO_REPO%"
"%TOOLS%\cmake.exe" -S . -B build-msvc-asan -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 "-DCMAKE_MAKE_PROGRAM=%NINJA%" "-DCMAKE_CXX_FLAGS=/fsanitize=address /EHsc" "-DCMAKE_EXE_LINKER_FLAGS=/fsanitize=address"
if errorlevel 1 exit /b 1
"%TOOLS%\cmake.exe" --build build-msvc-asan -j 12
if errorlevel 1 exit /b 1
set "ASAN_OPTIONS=detect_leaks=0"
"%TOOLS%\ctest.exe" --test-dir build-msvc-asan -j 12 --output-on-failure --no-tests=error
