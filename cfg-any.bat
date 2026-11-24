@echo off
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
"%TOOLS%\cmake.exe" -S . -B %2 -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=20 "-DCMAKE_MAKE_PROGRAM=%NINJA%"
"%TOOLS%\cmake.exe" --build %2 --target %1 -j 12
