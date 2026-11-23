@echo off
rem Poko MSVC debug+sanitizer build.
rem cl.exe-valid flags from the project debugging profile:
rem   /Od /W4 /WX /analyze /sdl /RTC1 /RTCsu /RTCu /RTCs /fsanitize=address /Zi
rem NOT valid for cl.exe (need clang-cl, not installed):
rem   /fsanitize=fuzzer  /fsanitize=fuzzer,address  /dynamicdeopt
rem /O1 and /O2 conflict with /Od; use a separate Release config for those.
set "MSVC=C:\BuildTools\VC\Tools\MSVC\14.44.35207"
set "SDK=C:\Program Files (x86)\Windows Kits\10"
set "SDKV=10.0.26100.0"
set "PATH=%MSVC%\bin\Hostx64\x64;%SDK%\bin\%SDKV%\x64;%PATH%"
set "INCLUDE=%MSVC%\include;%SDK%\Include\%SDKV%\ucrt;%SDK%\Include\%SDKV%\um;%SDK%\Include\%SDKV%\shared;%SDK%\Include\%SDKV%\winrt"
set "LIB=%MSVC%\lib\x64;%SDK%\Lib\%SDKV%\ucrt\x64;%SDK%\Lib\%SDKV%\um\x64"
set "LIBPATH=%LIB%"
set "TOOLS=%LOCALAPPDATA%\Microsoft\WinGet\Links"
set "NINJA=%LOCALAPPDATA%\Microsoft\WinGet\Packages\Ninja-build.Ninja_Microsoft.Winget.Source_8wekyb3d8bbwe\ninja.exe"
cd /d "C:\Users\mysti.LAPTOP.000\Desktop\Project Poko"
set "FLAGS=/Od /W4 /WX /analyze /sdl /RTC1 /RTCsu /RTCu /RTCs /fsanitize=address /Zi"
if not exist build-msvc-debug (
  "%TOOLS%\cmake.exe" -S . -B build-msvc-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 "-DCMAKE_MAKE_PROGRAM=%NINJA%" "-DCMAKE_CXX_FLAGS=%FLAGS%" "-DCMAKE_EXE_LINKER_FLAGS=/fsanitize=address"
  if errorlevel1 exit /b 1
)
"%TOOLS%\cmake.exe" --build build-msvc-debug -j 12
if errorlevel 1 exit /b 1
cd build-msvc-debug
set "ASAN_OPTIONS=detect_leaks=0"
"%TOOLS%\ctest.exe" -j 12 --output-on-failure
