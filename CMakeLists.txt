cmake_minimum_required(VERSION 3.28)
project(PokoX LANGUAGES CXX)

# A dependency-free executable verifies the compiler and generator first.
# Opt in to resolving and compiling against the vcpkg libraries separately.
option(POKO_WITH_DEPENDENCIES "Enable vcpkg dependency smoke test" OFF)
option(POKO_WITH_SDL_PLATFORM "Build the SDL3 platform and window demo" OFF)
option(POKO_WITH_VULKAN_DEMO "Build experimental Diligent/Vulkan clear seed" OFF)
option(POKO_IMGUI "Compile the ImGui feature path (UI integration comes later)" OFF)
option(POKO_D3D12 "Enable D3D12 where the Windows SDK is available" OFF)
option(POKO_DEBUG "Compile debug-only feature paths" OFF)
include(CTest)

if(POKO_WITH_VULKAN_DEMO AND NOT POKO_WITH_SDL_PLATFORM)
  message(FATAL_ERROR "POKO_WITH_VULKAN_DEMO requires POKO_WITH_SDL_PLATFORM=ON")
endif()
if(POKO_WITH_VULKAN_DEMO AND (ANDROID OR APPLE OR EMSCRIPTEN))
  message(FATAL_ERROR "The clear demo is desktop Windows/Linux-X11 only; Android activity/lifecycle packaging remains future work")
endif()

if(POKO_D3D12)
  if(NOT WIN32 OR MINGW)
    message(FATAL_ERROR "POKO_D3D12 requires a supported Windows SDK toolchain; MinGW/MSYS2 is not supported")
  endif()
  include(CheckCXXSourceCompiles)
  check_cxx_source_compiles("#include <d3d12.h>\n#include <dxgi.h>\n#include <d3dcompiler.h>\nint main() { return 0; }" POKO_HAS_D3D12_SDK)
  if(NOT POKO_HAS_D3D12_SDK)
    message(FATAL_ERROR "POKO_D3D12=ON requires Windows SDK headers d3d12.h, dxgi.h and d3dcompiler.h")
  endif()
endif()

add_library(poko_build_options INTERFACE)
target_include_directories(poko_build_options INTERFACE engine/foundation/include)
target_compile_definitions(poko_build_options INTERFACE
  POKO_IMGUI=$<BOOL:${POKO_IMGUI}>
  POKO_D3D12=$<BOOL:${POKO_D3D12}>
  POKO_DEBUG=$<BOOL:${POKO_DEBUG}>)

# Always check Git at build time; only rewrite the header when its value changes.
find_package(Git QUIET)
set(POKO_GENERATED_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(POKO_VERSION_HEADER "${POKO_GENERATED_INCLUDE_DIR}/poko/build_version.hpp")
add_custom_target(poko_version_header
  COMMAND "${CMAKE_COMMAND}"
    "-DPOKO_SOURCE_DIR:PATH=${CMAKE_CURRENT_SOURCE_DIR}"
    "-DPOKO_VERSION_HEADER:FILEPATH=${POKO_VERSION_HEADER}"
    "-DPOKO_GIT_EXECUTABLE:FILEPATH=${GIT_EXECUTABLE}"
    -P "${CMAKE_CURRENT_SOURCE_DIR}/tools/version/cmake/generate_version.cmake"
  BYPRODUCTS "${POKO_VERSION_HEADER}"
  VERBATIM)

add_executable(pokox engine/foundation/src/main.cpp)
add_dependencies(pokox poko_version_header)
target_include_directories(pokox PRIVATE "${POKO_GENERATED_INCLUDE_DIR}")
target_link_libraries(pokox PRIVATE poko_build_options)
target_compile_features(pokox PRIVATE cxx_std_20)
set_target_properties(pokox PROPERTIES CXX_EXTENSIONS OFF)
# Backend-independent platform contract, usable without SDL.
add_library(poko_platform INTERFACE)
target_include_directories(poko_platform INTERFACE engine/platform/include)
target_compile_features(poko_platform INTERFACE cxx_std_20)

if(POKO_WITH_DEPENDENCIES AND NOT CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "POKO_WITH_DEPENDENCIES requires the vcpkg toolchain; see docs/build.md")
endif()
if(POKO_WITH_SDL_PLATFORM OR POKO_WITH_DEPENDENCIES)
  find_package(SDL3 CONFIG REQUIRED)
endif()
if(POKO_WITH_SDL_PLATFORM)
  add_library(poko_platform_sdl STATIC engine/platform/src/sdl_platform.cpp)
  target_link_libraries(poko_platform_sdl PUBLIC poko_platform PRIVATE SDL3::SDL3)
  set_target_properties(poko_platform_sdl PROPERTIES CXX_EXTENSIONS OFF)
  add_executable(pokox_window_demo engine/platform/src/sdl_window_demo.cpp)
  target_link_libraries(pokox_window_demo PRIVATE poko_platform_sdl SDL3::SDL3)
  set_target_properties(pokox_window_demo PROPERTIES CXX_EXTENSIONS OFF)
endif()

if(BUILD_TESTING)
  add_executable(pokox_platform_contract engine/platform/tests/unit/i_platform_contract.cpp)
  target_link_libraries(pokox_platform_contract PRIVATE poko_platform)
  set_target_properties(pokox_platform_contract PROPERTIES CXX_EXTENSIONS OFF)
  add_test(NAME pokox_platform_contract COMMAND pokox_platform_contract)
  # Compile the production backend against a test-only SDL function double.
  # No SDL package is needed; this is control-flow coverage, not OS validation.
  add_executable(pokox_sdl_platform_faults
    engine/platform/src/sdl_platform.cpp
    engine/platform/tests/unit/sdl_platform_faults.cpp)
  target_include_directories(pokox_sdl_platform_faults PRIVATE engine/platform/tests/fakes)
  target_link_libraries(pokox_sdl_platform_faults PRIVATE poko_platform)
  set_target_properties(pokox_sdl_platform_faults PROPERTIES CXX_EXTENSIONS OFF)
  add_test(NAME pokox_sdl_platform_faults COMMAND pokox_sdl_platform_faults)
  set_tests_properties(pokox_sdl_platform_faults PROPERTIES TIMEOUT 15)
  if(POKO_WITH_SDL_PLATFORM)
    add_executable(pokox_sdl_platform_test engine/platform/tests/integration/sdl_platform_test.cpp)
    target_link_libraries(pokox_sdl_platform_test PRIVATE poko_platform_sdl SDL3::SDL3)
    set_target_properties(pokox_sdl_platform_test PROPERTIES CXX_EXTENSIONS OFF)
    add_test(NAME pokox_sdl_dummy COMMAND pokox_sdl_platform_test)
    set_tests_properties(pokox_sdl_dummy PROPERTIES ENVIRONMENT "SDL_VIDEODRIVER=dummy" TIMEOUT 15)
    add_test(NAME pokox_sdl_invalid_driver COMMAND pokox_sdl_platform_test --bad-driver)
    set_tests_properties(pokox_sdl_invalid_driver PROPERTIES ENVIRONMENT "SDL_VIDEODRIVER=poko-invalid-driver" TIMEOUT 15)
  endif()

  # Compile the actual renderer/platform against isolated dependency doubles.
  # These are compile/control-flow checks, not Windows/Android/GPU execution.
  foreach(test_platform IN ITEMS LINUX WIN32 ANDROID)
    string(TOLOWER "${test_platform}" test_platform_lower)
    set(test_target "pokox_vulkan_faults_${test_platform_lower}")
    add_executable(${test_target}
      engine/platform/src/sdl_platform.cpp
      engine/rhi/src/vulkan_clear_renderer.cpp
      engine/rhi/src/vulkan_diagnostics.cpp
      engine/rhi/tests/unit/vulkan_clear_faults.cpp)
    target_include_directories(${test_target} PRIVATE
      engine/rhi/include engine/rhi/tests/fakes engine/platform/tests/fakes)
    target_link_libraries(${test_target} PRIVATE poko_platform)
    target_compile_definitions(${test_target} PRIVATE "PLATFORM_${test_platform}=1")
    set_target_properties(${test_target} PROPERTIES CXX_EXTENSIONS OFF)
    add_test(NAME ${test_target} COMMAND ${test_target})
    set_tests_properties(${test_target} PROPERTIES TIMEOUT 15)
  endforeach()

  find_package(Python3 3.9 COMPONENTS Interpreter REQUIRED)
  add_test(NAME pokox_desktop_evidence_tests
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/rhi/tests/unit/test_verify_desktop.py")
  set_tests_properties(pokox_desktop_evidence_tests PROPERTIES TIMEOUT 30)
  if(NOT Git_FOUND)
    message(FATAL_ERROR "Git is required for the version integration test when BUILD_TESTING=ON")
  endif()
  add_test(NAME version_integration
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/tools/version/tests/integration/test_version.py"
      "--cmake=${CMAKE_COMMAND}" "--git=${GIT_EXECUTABLE}"
      "--generator=${CMAKE_GENERATOR}" "--platform=${CMAKE_GENERATOR_PLATFORM}")
  add_test(NAME d1_word_reservations
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/backend/storage/d1/tests/integration/test_word_reservations.py")
  add_test(NAME character_uv_overlap
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/assets/characters/work/test_uv_overlap.py")
  add_test(NAME golden_harness
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/tools/testutils/harness/golden.py" --self-test)
  add_test(NAME pokox_starts COMMAND pokox)
  add_test(NAME pokox_build_info COMMAND "${CMAKE_COMMAND}"
    "-DPOKO_EXECUTABLE=$<TARGET_FILE:pokox>"
    "-DEXPECT_IMGUI=$<BOOL:${POKO_IMGUI}>"
    "-DEXPECT_D3D12=$<BOOL:${POKO_D3D12}>"
    "-DEXPECT_DEBUG=$<BOOL:${POKO_DEBUG}>"
    -P "${CMAKE_CURRENT_SOURCE_DIR}/engine/foundation/tests/check_build_info.cmake")

  # Independently compile both branches for each flag. D3D12's enabled
  # contract test is platform-neutral; it does not exercise the backend.
  foreach(flag IN ITEMS IMGUI D3D12 DEBUG)
    foreach(value IN ITEMS 0 1)
      set(imgui 0)
      set(d3d12 0)
      set(debug 0)
      string(TOLOWER "${flag}" flag_lower)
      set(${flag_lower} ${value})
      set(test_target "pokox_flag_${flag_lower}_${value}")
      add_executable(${test_target} engine/foundation/tests/flags_contract.cpp)
      target_include_directories(${test_target} PRIVATE engine/foundation/include)
      target_compile_features(${test_target} PRIVATE cxx_std_20)
      target_compile_definitions(${test_target} PRIVATE
        POKO_IMGUI=${imgui} POKO_D3D12=${d3d12} POKO_DEBUG=${debug}
        EXPECT_IMGUI=${imgui} EXPECT_D3D12=${d3d12} EXPECT_DEBUG=${debug})
      add_test(NAME ${test_target} COMMAND ${test_target})
    endforeach()
  endforeach()
endif()

if(POKO_WITH_DEPENDENCIES)
  find_package(imgui CONFIG REQUIRED)
  find_package(spdlog CONFIG REQUIRED)
  find_package(Catch2 3 CONFIG REQUIRED)
endif()

if(POKO_WITH_DEPENDENCIES OR POKO_WITH_VULKAN_DEMO)
  # A pinned source integration is used because vcpkg has no DiligentCore port.
  # Do not build D3D12 by default: MSYS2 lacks the required Windows SDK.
  if(POKO_D3D12)
    set(DILIGENT_NO_DIRECT3D12 OFF CACHE BOOL "Controlled by POKO_D3D12" FORCE)
  else()
    set(DILIGENT_NO_DIRECT3D12 ON CACHE BOOL "Controlled by POKO_D3D12" FORCE)
  endif()
  set(DILIGENT_BUILD_TESTS OFF CACHE BOOL "Do not build Diligent tests")
  set(DILIGENT_INSTALL_CORE OFF CACHE BOOL "Do not install Diligent with PokoX")
  include(FetchContent)
  FetchContent_Declare(DiligentCore
    GIT_REPOSITORY https://github.com/DiligentGraphics/DiligentCore.git
    GIT_TAG b036337d68be2353c9950a85929acf796b9a6d50 # v2.5.6
    GIT_SUBMODULES_RECURSE TRUE
    EXCLUDE_FROM_ALL)
  FetchContent_MakeAvailable(DiligentCore)
  # GCC 16/libstdc++ no longer pulls <cstdint> in transitively; the pinned
  # glslang SPIRV header uses uint32_t without including it. Add the
  # missing include to the fetched source at configure time.
  set(POKO_GLSLANG_SPV_BUILDER "${diligentcore_SOURCE_DIR}/ThirdParty/glslang/SPIRV/SpvBuilder.h")
  if(EXISTS "${POKO_GLSLANG_SPV_BUILDER}")
    file(READ "${POKO_GLSLANG_SPV_BUILDER}" POKO_SPV_BUILDER_CONTENT)
    if(NOT POKO_SPV_BUILDER_CONTENT MATCHES "#include <cstdint>")
      string(REPLACE "#include <algorithm>" "#include <algorithm>\n#include <cstdint>"
        POKO_SPV_BUILDER_CONTENT "${POKO_SPV_BUILDER_CONTENT}")
      file(WRITE "${POKO_GLSLANG_SPV_BUILDER}" "${POKO_SPV_BUILDER_CONTENT}")
      message(STATUS "Patched missing <cstdint> include in glslang SpvBuilder.h")
    endif()
  endif()
endif()

if(POKO_WITH_DEPENDENCIES)
  if(BUILD_TESTING)
    add_executable(pokox_dependency_smoke engine/foundation/tests/dependency_smoke.cpp)
    target_compile_features(pokox_dependency_smoke PRIVATE cxx_std_20)
    set_target_properties(pokox_dependency_smoke PROPERTIES CXX_EXTENSIONS OFF)
    target_link_libraries(pokox_dependency_smoke PRIVATE
      SDL3::SDL3 imgui::imgui spdlog::spdlog Catch2::Catch2WithMain
      Diligent-GraphicsEngine)
    add_test(NAME pokox_dependency_smoke COMMAND pokox_dependency_smoke)
  endif()
endif()

if(POKO_WITH_VULKAN_DEMO)
  if(NOT TARGET Diligent-GraphicsEngineVk-static)
    message(FATAL_ERROR "Pinned Diligent Vulkan backend is unavailable; configure with DILIGENT_NO_VULKAN=OFF")
  endif()
  add_library(poko_rhi_vulkan STATIC
    engine/rhi/src/vulkan_clear_renderer.cpp engine/rhi/src/vulkan_diagnostics.cpp)
  target_include_directories(poko_rhi_vulkan PUBLIC engine/rhi/include
    PRIVATE "${diligentcore_SOURCE_DIR}/Common/interface")
  target_link_libraries(poko_rhi_vulkan PUBLIC poko_platform_sdl
    PRIVATE SDL3::SDL3 Diligent-GraphicsEngineVk-static Diligent-TargetPlatform)
  set_target_properties(poko_rhi_vulkan PROPERTIES CXX_EXTENSIONS OFF)
  add_executable(pokox_vulkan_clear engine/rhi/src/vulkan_clear_demo.cpp)
  target_link_libraries(pokox_vulkan_clear PRIVATE poko_rhi_vulkan SDL3::SDL3)
  set_target_properties(pokox_vulkan_clear PROPERTIES CXX_EXTENSIONS OFF)
endif()
