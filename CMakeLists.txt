cmake_minimum_required(VERSION 3.28)
project(PokoX LANGUAGES CXX)

# A dependency-free executable verifies the compiler and generator first.
# Opt in to resolving and compiling against the vcpkg libraries separately.
option(POKO_WITH_DEPENDENCIES "Enable vcpkg dependency smoke test" OFF)
option(POKO_WITH_SDL_PLATFORM "Build the SDL3 platform and window demo" OFF)
option(POKO_WITH_VULKAN_DEMO "Build experimental Diligent/Vulkan clear seed" OFF)
option(POKO_WITH_FALLBACK_DEMO "Build experimental Vulkan/OpenGL fallback demo" OFF)
option(POKO_WITH_SHADER_ARTIFACTS "Compile sample GLSL to SPIR-V using a host glslang tool" OFF)
option(POKO_WITH_TRIANGLE_DEMO "Build experimental Vulkan frame-graph triangle demo" OFF)
option(POKO_WITH_DEPTH_DEMO "Build experimental Vulkan depth-test demo" OFF)
option(POKO_WITH_UNIFORM_DEMO "Build experimental Vulkan per-frame uniform demo" OFF)
option(POKO_WITH_IMGUI_DEMO "Build experimental Vulkan ImGui frame-graph demo" OFF)
option(POKO_IMGUI "Compile the ImGui feature path (UI integration comes later)" OFF)
option(POKO_D3D12 "Enable D3D12 where the Windows SDK is available" OFF)
option(POKO_DEBUG "Compile debug-only feature paths" OFF)
include(CTest)

if((POKO_WITH_TRIANGLE_DEMO OR POKO_WITH_DEPTH_DEMO OR POKO_WITH_UNIFORM_DEMO OR POKO_WITH_IMGUI_DEMO) AND (NOT POKO_WITH_VULKAN_DEMO OR NOT POKO_WITH_SHADER_ARTIFACTS))
  message(FATAL_ERROR "Triangle/depth/uniform demos require POKO_WITH_VULKAN_DEMO=ON and POKO_WITH_SHADER_ARTIFACTS=ON")
endif()
if(POKO_WITH_FALLBACK_DEMO AND NOT POKO_WITH_VULKAN_DEMO)
  message(FATAL_ERROR "POKO_WITH_FALLBACK_DEMO requires POKO_WITH_VULKAN_DEMO=ON and POKO_WITH_SDL_PLATFORM=ON")
endif()
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
  add_library(poko_platform_sdl STATIC engine/platform/src/window/sdl_platform.cpp)
  target_link_libraries(poko_platform_sdl PUBLIC poko_platform PRIVATE SDL3::SDL3)
  set_target_properties(poko_platform_sdl PROPERTIES CXX_EXTENSIONS OFF)
  add_executable(pokox_window_demo engine/platform/src/window/sdl_window_demo.cpp)
  target_link_libraries(pokox_window_demo PRIVATE poko_platform_sdl SDL3::SDL3)
  set_target_properties(pokox_window_demo PROPERTIES CXX_EXTENSIONS OFF)
endif()

# CPU-only frame graph skeleton, independent of SDL and graphics SDKs.
add_library(poko_framegraph STATIC engine/render/src/framegraph/frame_graph.cpp)
target_include_directories(poko_framegraph PUBLIC engine/render/include)
target_compile_features(poko_framegraph PUBLIC cxx_std_20)
set_target_properties(poko_framegraph PROPERTIES CXX_EXTENSIONS OFF)

# ENG-07 is opt-in so dependency-free and cross builds do not accidentally
# execute a target-architecture compiler. Select a host tool explicitly if needed.
if(POKO_WITH_SHADER_ARTIFACTS)
  set(POKO_GLSLANG_EXECUTABLE "" CACHE FILEPATH "Host glslangValidator or glslang executable")
  if(NOT POKO_GLSLANG_EXECUTABLE)
    find_program(POKO_GLSLANG_HOST_TOOL NAMES glslangValidator glslang NO_CMAKE_FIND_ROOT_PATH)
    if(NOT POKO_GLSLANG_HOST_TOOL)
      message(FATAL_ERROR "ENG-07 needs a host glslangValidator or glslang; set POKO_GLSLANG_EXECUTABLE")
    endif()
    set(POKO_GLSLANG_EXECUTABLE "${POKO_GLSLANG_HOST_TOOL}" CACHE FILEPATH "Host glslangValidator or glslang executable" FORCE)
  endif()
  if(NOT EXISTS "${POKO_GLSLANG_EXECUTABLE}" OR IS_DIRECTORY "${POKO_GLSLANG_EXECUTABLE}")
    message(FATAL_ERROR "POKO_GLSLANG_EXECUTABLE is not a host executable file")
  endif()
  execute_process(COMMAND "${POKO_GLSLANG_EXECUTABLE}" --version RESULT_VARIABLE POKO_GLSLANG_STATUS
    OUTPUT_VARIABLE POKO_GLSLANG_VERSION ERROR_VARIABLE POKO_GLSLANG_ERROR)
  if(NOT POKO_GLSLANG_STATUS STREQUAL "0")
    message(FATAL_ERROR "Host glslang cannot run: ${POKO_GLSLANG_STATUS} ${POKO_GLSLANG_ERROR}")
  endif()
  string(REGEX MATCH "^[^\r\n]*" POKO_GLSLANG_VERSION_LINE "${POKO_GLSLANG_VERSION}")
  message(STATUS "ENG-07 host compiler: ${POKO_GLSLANG_EXECUTABLE} (${POKO_GLSLANG_VERSION_LINE})")
  # A changed compiler path/version must invalidate outputs even when the new
  # executable's timestamp is older than the previous artifact (e.g. Make).
  set(POKO_SHADER_TOOL_SIGNATURE "${CMAKE_CURRENT_BINARY_DIR}/shader-tool-signature.txt")
  file(GENERATE OUTPUT "${POKO_SHADER_TOOL_SIGNATURE}"
    CONTENT "compiler=${POKO_GLSLANG_EXECUTABLE}\nversion=${POKO_GLSLANG_VERSION}\n")
  include(engine/build/cmake/PokoShaders.cmake)
  set(POKO_VERTEX_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/triangle.vert.spv")
  set(POKO_FRAGMENT_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/triangle.frag.spv")
  poko_compile_shader("${POKO_VERTEX_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/triangle.vert" vert)
  poko_compile_shader("${POKO_FRAGMENT_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/triangle.frag" frag)
  set(POKO_SHADER_OUTPUTS "${POKO_VERTEX_SPV}" "${POKO_FRAGMENT_SPV}")
  if(POKO_WITH_DEPTH_DEMO)
    set(POKO_DEPTH_VERTEX_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/depth.vert.spv")
    set(POKO_DEPTH_FRAGMENT_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/depth.frag.spv")
    poko_compile_shader("${POKO_DEPTH_VERTEX_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/depth.vert" vert)
    poko_compile_shader("${POKO_DEPTH_FRAGMENT_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/depth.frag" frag)
    list(APPEND POKO_SHADER_OUTPUTS "${POKO_DEPTH_VERTEX_SPV}" "${POKO_DEPTH_FRAGMENT_SPV}")
  endif()
  if(POKO_WITH_UNIFORM_DEMO)
    set(POKO_UNIFORM_VERTEX_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/uniform.vert.spv")
    set(POKO_UNIFORM_FRAGMENT_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/uniform.frag.spv")
    poko_compile_shader("${POKO_UNIFORM_VERTEX_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/uniform.vert" vert)
    poko_compile_shader("${POKO_UNIFORM_FRAGMENT_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/uniform.frag" frag)
    list(APPEND POKO_SHADER_OUTPUTS "${POKO_UNIFORM_VERTEX_SPV}" "${POKO_UNIFORM_FRAGMENT_SPV}")
  endif()
  if(POKO_WITH_IMGUI_DEMO AND POKO_DEBUG)
    set(POKO_IMGUI_VERTEX_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/imgui.vert.spv")
    set(POKO_IMGUI_FRAGMENT_SPV "${CMAKE_CURRENT_BINARY_DIR}/shaders/$<CONFIG>/imgui.frag.spv")
    poko_compile_shader("${POKO_IMGUI_VERTEX_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/imgui.vert" vert)
    poko_compile_shader("${POKO_IMGUI_FRAGMENT_SPV}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/shaders/imgui.frag" frag)
    list(APPEND POKO_SHADER_OUTPUTS "${POKO_IMGUI_VERTEX_SPV}" "${POKO_IMGUI_FRAGMENT_SPV}")
  endif()
  add_custom_target(pokox_shaders ALL DEPENDS ${POKO_SHADER_OUTPUTS})
endif()

# Backend selection is dependency-free; concrete backend adapters are opt-in.
add_library(poko_clear_backend_selection STATIC engine/rhi/src/device/clear_backend_selection.cpp)
target_include_directories(poko_clear_backend_selection PUBLIC engine/rhi/include)
target_compile_features(poko_clear_backend_selection PUBLIC cxx_std_20)
set_target_properties(poko_clear_backend_selection PROPERTIES CXX_EXTENSIONS OFF)

if(BUILD_TESTING)
  add_executable(pokox_framegraph_tests engine/render/tests/unit/frame_graph_test.cpp)
  target_link_libraries(pokox_framegraph_tests PRIVATE poko_framegraph)
  set_target_properties(pokox_framegraph_tests PROPERTIES CXX_EXTENSIONS OFF)
  add_test(NAME pokox_framegraph_tests COMMAND pokox_framegraph_tests)
  set_tests_properties(pokox_framegraph_tests PROPERTIES TIMEOUT 15)
  add_executable(pokox_clear_backend_selection engine/rhi/tests/unit/clear_backend_selection.cpp)
  target_link_libraries(pokox_clear_backend_selection PRIVATE poko_clear_backend_selection)
  add_test(NAME pokox_clear_backend_selection COMMAND pokox_clear_backend_selection)
  # Keep historic header include paths working alongside the organized paths.
  add_executable(pokox_public_header_compat engine/rhi/tests/integration/public_header_compat.cpp)
  target_include_directories(pokox_public_header_compat PRIVATE engine/rhi/include)
  target_link_libraries(pokox_public_header_compat PRIVATE poko_platform poko_build_options)
  set_target_properties(pokox_public_header_compat PROPERTIES CXX_EXTENSIONS OFF)
  add_test(NAME pokox_public_header_compat COMMAND pokox_public_header_compat)
  add_executable(pokox_platform_contract engine/platform/tests/unit/i_platform_contract.cpp)
  target_link_libraries(pokox_platform_contract PRIVATE poko_platform)
  set_target_properties(pokox_platform_contract PROPERTIES CXX_EXTENSIONS OFF)
  add_test(NAME pokox_platform_contract COMMAND pokox_platform_contract)
  # Compile the production backend against a test-only SDL function double.
  # No SDL package is needed; this is control-flow coverage, not OS validation.
  add_executable(pokox_sdl_platform_faults
    engine/platform/src/window/sdl_platform.cpp
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
      engine/platform/src/window/sdl_platform.cpp
      engine/rhi/src/device/vulkan_clear_renderer.cpp
      engine/rhi/src/debug/vulkan_diagnostics.cpp
      engine/rhi/tests/unit/vulkan_clear_faults.cpp)
    target_include_directories(${test_target} PRIVATE
      engine/rhi/include engine/rhi/tests/fakes engine/platform/tests/fakes)
    target_link_libraries(${test_target} PRIVATE poko_platform)
    target_compile_definitions(${test_target} PRIVATE "PLATFORM_${test_platform}=1")
    set_target_properties(${test_target} PROPERTIES CXX_EXTENSIONS OFF)
    add_test(NAME ${test_target} COMMAND ${test_target})
    set_tests_properties(${test_target} PROPERTIES TIMEOUT 15)
  endforeach()

  # Production triangle/depth pass against isolated SDK doubles; not GPU acceptance.
  add_executable(pokox_triangle_pass_faults
    engine/rhi/src/device/vulkan_triangle_pass.cpp
    engine/rhi/tests/unit/vulkan_triangle_pass_test.cpp)
  target_include_directories(pokox_triangle_pass_faults PRIVATE engine/rhi/include engine/rhi/tests/fakes/triangle)
  target_link_libraries(pokox_triangle_pass_faults PRIVATE poko_build_options)
  target_compile_features(pokox_triangle_pass_faults PRIVATE cxx_std_20)
  set_target_properties(pokox_triangle_pass_faults PROPERTIES CXX_EXTENSIONS OFF)
  add_test(NAME pokox_triangle_pass_faults COMMAND pokox_triangle_pass_faults "${CMAKE_CURRENT_BINARY_DIR}/triangle-pass-test.spv")
  set_tests_properties(pokox_triangle_pass_faults PROPERTIES TIMEOUT 15)

  # Actual GL seed compiled against isolated test-only SDK declarations.
  foreach(test_platform IN ITEMS LINUX WIN32)
    string(TOLOWER "${test_platform}" test_platform_lower)
    set(test_target "pokox_opengl_faults_${test_platform_lower}")
    add_executable(${test_target}
      engine/platform/src/window/sdl_platform.cpp
      engine/rhi/src/device/vulkan_clear_renderer.cpp
      engine/rhi/src/debug/vulkan_diagnostics.cpp
      engine/rhi/src/device/opengl_clear_renderer.cpp
      engine/rhi/src/device/fallback_clear_backends.cpp
      engine/rhi/src/device/clear_backend_selection.cpp
      engine/rhi/tests/unit/opengl_clear_faults.cpp)
    target_include_directories(${test_target} PRIVATE engine/rhi/include engine/rhi/tests/fakes engine/platform/tests/fakes)
    target_link_libraries(${test_target} PRIVATE poko_platform)
    target_compile_definitions(${test_target} PRIVATE "PLATFORM_${test_platform}=1")
    set_target_properties(${test_target} PROPERTIES CXX_EXTENSIONS OFF)
    add_test(NAME ${test_target} COMMAND ${test_target})
    set_tests_properties(${test_target} PROPERTIES TIMEOUT 15)
  endforeach()

  # Drive the actual fallback demo and adapters with test-owned dependencies.
  add_library(pokox_fallback_fake_fixture OBJECT engine/rhi/tests/unit/opengl_clear_faults.cpp)
  target_include_directories(pokox_fallback_fake_fixture PRIVATE engine/rhi/include engine/rhi/tests/fakes engine/platform/tests/fakes)
  target_link_libraries(pokox_fallback_fake_fixture PRIVATE poko_platform)
  target_compile_definitions(pokox_fallback_fake_fixture PRIVATE PLATFORM_LINUX=1 main=poko_gl_fixture_main)
  add_executable(pokox_fallback_demo_double
    engine/platform/src/window/sdl_platform.cpp
    engine/rhi/src/device/vulkan_clear_renderer.cpp engine/rhi/src/debug/vulkan_diagnostics.cpp
    engine/rhi/src/device/opengl_clear_renderer.cpp engine/rhi/src/device/fallback_clear_backends.cpp
    engine/rhi/src/device/clear_backend_selection.cpp engine/rhi/src/device/fallback_clear_demo.cpp
    $<TARGET_OBJECTS:pokox_fallback_fake_fixture>)
  target_include_directories(pokox_fallback_demo_double PRIVATE engine/rhi/include engine/rhi/tests/fakes engine/platform/tests/fakes)
  target_link_libraries(pokox_fallback_demo_double PRIVATE poko_platform)
  target_compile_definitions(pokox_fallback_demo_double PRIVATE PLATFORM_LINUX=1)
  add_test(NAME pokox_fallback_demo_vulkan COMMAND pokox_fallback_demo_double --frames 2)
  set_tests_properties(pokox_fallback_demo_vulkan PROPERTIES PASS_REGULAR_EXPRESSION "backend=vulkan submitted=2" TIMEOUT 15)
  add_test(NAME pokox_fallback_demo_opengl COMMAND pokox_fallback_demo_double --force-opengl --frames 2)
  set_tests_properties(pokox_fallback_demo_opengl PROPERTIES PASS_REGULAR_EXPRESSION "backend=opengl submitted=2" TIMEOUT 15)
  add_test(NAME pokox_fallback_demo_auto COMMAND pokox_fallback_demo_double --frames 2)
  set_tests_properties(pokox_fallback_demo_auto PROPERTIES ENVIRONMENT "POKO_TEST_VULKAN_UNAVAILABLE=1" PASS_REGULAR_EXPRESSION "backend=opengl submitted=2" TIMEOUT 15)
  add_test(NAME pokox_fallback_demo_invalid COMMAND pokox_fallback_demo_double --frames 0)
  set_tests_properties(pokox_fallback_demo_invalid PROPERTIES WILL_FAIL TRUE TIMEOUT 15)

  find_package(Python3 3.9 COMPONENTS Interpreter REQUIRED)
  if(POKO_WITH_SHADER_ARTIFACTS)
    add_test(NAME pokox_shader_pipeline
      COMMAND "${Python3_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/tests/integration/test_shader_pipeline.py"
        "--cmake=${CMAKE_COMMAND}" "--compiler=${POKO_GLSLANG_EXECUTABLE}")
    set_tests_properties(pokox_shader_pipeline PROPERTIES TIMEOUT 120)
  endif()
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
    -P "${CMAKE_CURRENT_SOURCE_DIR}/engine/foundation/tests/integration/check_build_info.cmake")

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
      add_executable(${test_target} engine/foundation/tests/unit/flags_contract.cpp)
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
  if(POKO_WITH_FALLBACK_DEMO AND WIN32)
    # The pinned WGL backend requests at most 4.4. Try the project's 4.6
    # target first; the renderer rejects a lower negotiated version.
    set(POKO_GL_WINDOWS_CONTEXT "${diligentcore_SOURCE_DIR}/Graphics/GraphicsEngineOpenGL/src/GLContextWindows.cpp")
    file(READ "${POKO_GL_WINDOWS_CONTEXT}" POKO_GL_WINDOWS_SOURCE)
    set(POKO_GL_OLD "std::pair<int, int> gl_versions[] = {{4, 4}, {4, 3}, {4, 2}};")
    set(POKO_GL_NEW "std::pair<int, int> gl_versions[] = {{4, 6}, {4, 5}, {4, 4}, {4, 3}, {4, 2}};")
    string(FIND "${POKO_GL_WINDOWS_SOURCE}" "${POKO_GL_NEW}" POKO_GL_ALREADY_PATCHED)
    if(POKO_GL_ALREADY_PATCHED EQUAL -1)
      string(FIND "${POKO_GL_WINDOWS_SOURCE}" "${POKO_GL_OLD}" POKO_GL_PATCH_ANCHOR)
      if(POKO_GL_PATCH_ANCHOR EQUAL -1)
        message(FATAL_ERROR "Pinned Diligent WGL version list changed; cannot apply the 4.6 patch safely")
      endif()
      string(REPLACE "${POKO_GL_OLD}" "${POKO_GL_NEW}" POKO_GL_WINDOWS_SOURCE "${POKO_GL_WINDOWS_SOURCE}")
      file(WRITE "${POKO_GL_WINDOWS_CONTEXT}" "${POKO_GL_WINDOWS_SOURCE}")
    endif()
    # The desktop fallback policy requires an sRGB default framebuffer, but
    # legacy ChoosePixelFormat cannot request WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB.
    # Prefer an ARB pixel format when the driver exposes it; keep the legacy
    # path as fallback. Anchor-checked like the version patch above.
    set(POKO_GL_PIXFMT_OLD [[        m_WindowHandleToDeviceContext = GetDC(hWnd);
        int nPixelFormat              = ChoosePixelFormat(m_WindowHandleToDeviceContext, &pfd);

        if (nPixelFormat == 0)
            LOG_ERROR_AND_THROW("Invalid Pixel Format");

        BOOL bResult = SetPixelFormat(m_WindowHandleToDeviceContext, nPixelFormat, &pfd);
        if (!bResult)
            LOG_ERROR_AND_THROW("Failed to set Pixel Format");]])
    set(POKO_GL_PIXFMT_NEW [[        m_WindowHandleToDeviceContext = GetDC(hWnd);
        int nPixelFormat              = 0;
        // The fallback policy requires an sRGB default framebuffer. Legacy
        // ChoosePixelFormat cannot request WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB,
        // so prefer an ARB pixel format when the driver exposes it.
        using PFNChoosePixelFormatARB = BOOL(WINAPI*)(HDC, const int*, const FLOAT*, UINT, int*, UINT*);
        using PFNGetPixelFormatAttribIVARB = BOOL(WINAPI*)(HDC, int, int, UINT, int*);
        auto pfnChoosePF = reinterpret_cast<PFNChoosePixelFormatARB>(
            wglGetProcAddress("wglChoosePixelFormatARB"));
        auto pfnGetPFA = reinterpret_cast<PFNGetPixelFormatAttribIVARB>(
            wglGetProcAddress("wglGetPixelFormatAttribivARB"));
        if (!pfnChoosePF || !pfnGetPFA)
        {
            // WGL extension entry points resolve only after a GL context
            // exists; a temporary hidden window/context exposes them (the
            // same approach wglew uses), enabling ARB pixel-format selection.
            WNDCLASSW wc{}; wc.lpfnWndProc = DefWindowProcW;
            wc.hInstance = GetModuleHandleW(nullptr);
            wc.lpszClassName = L"DiligentWglProbe";
            RegisterClassW(&wc);
            HWND probeWnd = CreateWindowW(wc.lpszClassName, L"", WS_OVERLAPPED,
                                          0, 0, 16, 16, nullptr, nullptr,
                                          wc.hInstance, nullptr);
            HDC probeDc = probeWnd ? GetDC(probeWnd) : nullptr;
            if (probeDc)
            {
                PIXELFORMATDESCRIPTOR probePfd{};
                probePfd.nSize = sizeof(probePfd); probePfd.nVersion = 1;
                probePfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
                probePfd.iPixelType = PFD_TYPE_RGBA; probePfd.cColorBits = 32;
                probePfd.iLayerType = PFD_MAIN_PLANE;
                int probePf = ChoosePixelFormat(probeDc, &probePfd);
                HGLRC probeCtx = nullptr;
                if (probePf && SetPixelFormat(probeDc, probePf, &probePfd))
                    probeCtx = wglCreateContext(probeDc);
                if (probeCtx && wglMakeCurrent(probeDc, probeCtx))
                {
                    pfnChoosePF = reinterpret_cast<PFNChoosePixelFormatARB>(
                        wglGetProcAddress("wglChoosePixelFormatARB"));
                    pfnGetPFA = reinterpret_cast<PFNGetPixelFormatAttribIVARB>(
                        wglGetProcAddress("wglGetPixelFormatAttribivARB"));
                }
                if (probeCtx) { wglMakeCurrent(nullptr, nullptr); wglDeleteContext(probeCtx); }
                ReleaseDC(probeWnd, probeDc);
            }
            if (probeWnd) DestroyWindow(probeWnd);
        }
        if (pfnChoosePF && pfnGetPFA)
        {
            const int pfAttribs[] = {
                WGL_DRAW_TO_WINDOW_ARB,    TRUE,
                WGL_SUPPORT_OPENGL_ARB,    TRUE,
                WGL_DOUBLE_BUFFER_ARB,     TRUE,
                WGL_PIXEL_TYPE_ARB,        WGL_TYPE_RGBA_ARB,
                WGL_COLOR_BITS_ARB,        32,
                WGL_DEPTH_BITS_ARB,        pfd.cDepthBits,
                WGL_STENCIL_BITS_ARB,      pfd.cStencilBits,
                WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB, TRUE,
                0, 0};
            int formats[64]; UINT numFormats = 0;
            if (pfnChoosePF(m_WindowHandleToDeviceContext, pfAttribs, nullptr, 64,
                            formats, &numFormats))
            {
                for (UINT i = 0; i < numFormats; ++i)
                {
                    int srgbCapable = 0;
                    if (pfnGetPFA(m_WindowHandleToDeviceContext, formats[i],
                                  WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB, 1, &srgbCapable) && srgbCapable)
                    { nPixelFormat = formats[i]; break; }
                }
            }
        }
        if (nPixelFormat == 0)
        {
            nPixelFormat = ChoosePixelFormat(m_WindowHandleToDeviceContext, &pfd);
            if (nPixelFormat == 0)
                LOG_ERROR_AND_THROW("Invalid Pixel Format");
        }

        BOOL bResult = SetPixelFormat(m_WindowHandleToDeviceContext, nPixelFormat, &pfd);
        if (!bResult)
            LOG_ERROR_AND_THROW("Failed to set Pixel Format");]])
    string(FIND "${POKO_GL_WINDOWS_SOURCE}" "${POKO_GL_PIXFMT_NEW}" POKO_GL_PIXFMT_PATCHED)
    if(POKO_GL_PIXFMT_PATCHED EQUAL -1)
      string(FIND "${POKO_GL_WINDOWS_SOURCE}" "${POKO_GL_PIXFMT_OLD}" POKO_GL_PIXFMT_ANCHOR)
      if(POKO_GL_PIXFMT_ANCHOR EQUAL -1)
        message(FATAL_ERROR "Pinned Diligent WGL pixel-format block changed; cannot apply the sRGB patch safely")
      endif()
      string(REPLACE "${POKO_GL_PIXFMT_OLD}" "${POKO_GL_PIXFMT_NEW}" POKO_GL_WINDOWS_SOURCE "${POKO_GL_WINDOWS_SOURCE}")
      file(WRITE "${POKO_GL_WINDOWS_CONTEXT}" "${POKO_GL_WINDOWS_SOURCE}")
      message(STATUS "Patched Diligent WGL pixel-format selection for sRGB framebuffer")
    endif()
  endif()
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
  add_library(poko_logging STATIC engine/foundation/src/logging.cpp)
  target_include_directories(poko_logging PUBLIC engine/foundation/include)
  target_link_libraries(poko_logging PUBLIC spdlog::spdlog)
  set_target_properties(poko_logging PROPERTIES CXX_EXTENSIONS OFF)
  target_compile_features(poko_logging PUBLIC cxx_std_20)
  if(BUILD_TESTING)
    add_executable(pokox_dependency_smoke engine/foundation/tests/integration/dependency_smoke.cpp)
    target_compile_features(pokox_dependency_smoke PRIVATE cxx_std_20)
    set_target_properties(pokox_dependency_smoke PROPERTIES CXX_EXTENSIONS OFF)
    target_link_libraries(pokox_dependency_smoke PRIVATE
      SDL3::SDL3 imgui::imgui spdlog::spdlog Catch2::Catch2WithMain
      Diligent-GraphicsEngine)
    add_test(NAME pokox_dependency_smoke COMMAND pokox_dependency_smoke)
    add_executable(pokox_logging_file_test engine/foundation/tests/integration/logging_file_test.cpp)
    target_compile_features(pokox_logging_file_test PRIVATE cxx_std_20)
    set_target_properties(pokox_logging_file_test PROPERTIES CXX_EXTENSIONS OFF)
    target_link_libraries(pokox_logging_file_test PRIVATE poko_logging)
    add_test(NAME pokox_logging_file_test COMMAND pokox_logging_file_test)
  endif()
endif()

if(POKO_WITH_VULKAN_DEMO)
  if(NOT TARGET Diligent-GraphicsEngineVk-static)
    message(FATAL_ERROR "Pinned Diligent Vulkan backend is unavailable; configure with DILIGENT_NO_VULKAN=OFF")
  endif()
  add_library(poko_rhi_vulkan STATIC
    engine/rhi/src/device/vulkan_clear_renderer.cpp engine/rhi/src/debug/vulkan_diagnostics.cpp)
  target_include_directories(poko_rhi_vulkan PUBLIC engine/rhi/include
    PRIVATE "${diligentcore_SOURCE_DIR}/Common/interface")
  target_link_libraries(poko_rhi_vulkan PUBLIC poko_platform_sdl
    PRIVATE SDL3::SDL3 Diligent-GraphicsEngineVk-static Diligent-TargetPlatform)
  set_target_properties(poko_rhi_vulkan PROPERTIES CXX_EXTENSIONS OFF)
  add_executable(pokox_vulkan_clear engine/rhi/src/device/vulkan_clear_demo.cpp)
  target_link_libraries(pokox_vulkan_clear PRIVATE poko_rhi_vulkan SDL3::SDL3)
  set_target_properties(pokox_vulkan_clear PROPERTIES CXX_EXTENSIONS OFF)
endif()

foreach(demo IN ITEMS triangle depth uniform)
  string(TOUPPER "${demo}" demo_upper)
  if(POKO_WITH_${demo_upper}_DEMO)
    set(demo_target "pokox_${demo}")
    add_executable(${demo_target} engine/render/src/passes/triangle_demo.cpp
      engine/rhi/src/device/vulkan_triangle_pass.cpp)
    target_include_directories(${demo_target} PRIVATE "${diligentcore_SOURCE_DIR}/Common/interface")
    target_link_libraries(${demo_target} PRIVATE poko_framegraph poko_rhi_vulkan SDL3::SDL3
      Diligent-GraphicsEngineVk-static Diligent-TargetPlatform)
    if(demo STREQUAL "depth")
      target_compile_definitions(${demo_target} PRIVATE POKO_DEMO_DEPTH=1)
    elseif(demo STREQUAL "uniform")
      target_compile_definitions(${demo_target} PRIVATE POKO_DEMO_UNIFORM=1)
    endif()
    add_dependencies(${demo_target} pokox_shaders)
    set_target_properties(${demo_target} PROPERTIES CXX_EXTENSIONS OFF)
    if(BUILD_TESTING)
      add_test(NAME ${demo_target}_missing_shader COMMAND ${demo_target} --vertex missing.vert.spv --fragment missing.frag.spv)
      set_tests_properties(${demo_target}_missing_shader PROPERTIES WILL_FAIL TRUE TIMEOUT 15)
      add_test(NAME ${demo_target}_bad_args COMMAND ${demo_target} --frames 0)
      set_tests_properties(${demo_target}_bad_args PROPERTIES WILL_FAIL TRUE TIMEOUT 15)
      add_test(NAME ${demo_target}_inputs COMMAND "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/tests/integration/test_triangle_inputs.py" "$<TARGET_FILE:${demo_target}>")
      set_tests_properties(${demo_target}_inputs PROPERTIES TIMEOUT 30)
    endif()
  endif()
endforeach()

if(POKO_WITH_IMGUI_DEMO)
  if(NOT POKO_WITH_DEPENDENCIES)
    message(FATAL_ERROR "POKO_WITH_IMGUI_DEMO requires POKO_WITH_DEPENDENCIES=ON for the imgui package")
  endif()
  set(pokox_imgui_sources engine/render/src/passes/imgui_demo.cpp)
  if(POKO_DEBUG)
    # Debug builds keep the ImGui overlay and F1 toggle; release strips every
    # ImGui code path and never links imgui, so the binary has no ImGui symbols.
    list(APPEND pokox_imgui_sources engine/rhi/src/device/vulkan_imgui_pass.cpp)
  endif()
  add_executable(pokox_imgui_demo ${pokox_imgui_sources}
    engine/rhi/src/device/vulkan_triangle_pass.cpp)
  target_include_directories(pokox_imgui_demo PRIVATE "${diligentcore_SOURCE_DIR}/Common/interface")
  target_compile_definitions(pokox_imgui_demo PRIVATE POKO_DEBUG=$<BOOL:${POKO_DEBUG}>)
  target_link_libraries(pokox_imgui_demo PRIVATE poko_framegraph poko_rhi_vulkan SDL3::SDL3
    Diligent-GraphicsEngineVk-static Diligent-TargetPlatform)
  if(POKO_DEBUG)
    target_link_libraries(pokox_imgui_demo PRIVATE imgui::imgui)
  endif()
  add_dependencies(pokox_imgui_demo pokox_shaders)
  set_target_properties(pokox_imgui_demo PROPERTIES CXX_EXTENSIONS OFF)
  set(pokox_imgui_test_targets pokox_imgui_demo)
  if(POKO_DEBUG)
    # Strip variant: identical demo compiled with POKO_DEBUG=0 — no ImGui pass
    # source, no imgui link — proving release binaries carry no ImGui symbols.
    # (When POKO_DEBUG=OFF, pokox_imgui_demo itself already is the strip build.)
    add_executable(pokox_imgui_demo_strip
      engine/render/src/passes/imgui_demo.cpp
      engine/rhi/src/device/vulkan_triangle_pass.cpp)
    target_include_directories(pokox_imgui_demo_strip PRIVATE "${diligentcore_SOURCE_DIR}/Common/interface")
    target_compile_definitions(pokox_imgui_demo_strip PRIVATE POKO_DEBUG=0)
    target_link_libraries(pokox_imgui_demo_strip PRIVATE poko_framegraph poko_rhi_vulkan SDL3::SDL3
      Diligent-GraphicsEngineVk-static Diligent-TargetPlatform)
    add_dependencies(pokox_imgui_demo_strip pokox_shaders)
    set_target_properties(pokox_imgui_demo_strip PROPERTIES CXX_EXTENSIONS OFF)
    list(APPEND pokox_imgui_test_targets pokox_imgui_demo_strip)
  endif()
  # Fault-injection coverage for VulkanImGuiPass against test-owned Diligent
  # doubles (engine/rhi/tests/fakes/imgui). Real ImGui produces the draw data;
  # no GPU or Diligent ABI involved.
  add_executable(pokox_imgui_pass_faults
    engine/rhi/tests/unit/imgui_pass_faults.cpp
    engine/rhi/src/device/vulkan_imgui_pass.cpp
    engine/rhi/src/debug/vulkan_diagnostics.cpp)
  target_include_directories(pokox_imgui_pass_faults PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/rhi/tests/fakes/imgui"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/rhi/tests/fakes"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/rhi/include")
  target_link_libraries(pokox_imgui_pass_faults PRIVATE imgui::imgui)
  set_target_properties(pokox_imgui_pass_faults PROPERTIES CXX_EXTENSIONS OFF)
  if(BUILD_TESTING)
    add_test(NAME pokox_imgui_pass_faults COMMAND pokox_imgui_pass_faults)
    set_tests_properties(pokox_imgui_pass_faults PROPERTIES TIMEOUT 30)
  endif()
  if(BUILD_TESTING)
    foreach(target IN LISTS pokox_imgui_test_targets)
      add_test(NAME ${target}_missing_shader COMMAND ${target}
        --vertex missing.vert.spv --fragment missing.frag.spv
        --imgui-vertex missing.imgui.vert.spv --imgui-fragment missing.imgui.frag.spv)
      set_tests_properties(${target}_missing_shader PROPERTIES WILL_FAIL TRUE TIMEOUT 15)
      add_test(NAME ${target}_bad_args COMMAND ${target} --frames 0)
      set_tests_properties(${target}_bad_args PROPERTIES WILL_FAIL TRUE TIMEOUT 15)
      add_test(NAME ${target}_inputs COMMAND "${Python3_EXECUTABLE}"
        "${CMAKE_CURRENT_SOURCE_DIR}/engine/render/tests/integration/test_imgui_inputs.py" "$<TARGET_FILE:${target}>")
      set_tests_properties(${target}_inputs PROPERTIES TIMEOUT 30)
    endforeach()
  endif()
endif()

if(POKO_WITH_FALLBACK_DEMO)
  if(NOT TARGET Diligent-GraphicsEngineOpenGL-static)
    message(FATAL_ERROR "Pinned Diligent OpenGL backend is unavailable; configure with DILIGENT_NO_OPENGL=OFF")
  endif()
  add_library(poko_rhi_fallback STATIC engine/rhi/src/device/opengl_clear_renderer.cpp engine/rhi/src/device/fallback_clear_backends.cpp)
  target_include_directories(poko_rhi_fallback PUBLIC engine/rhi/include PRIVATE "${diligentcore_SOURCE_DIR}/Common/interface")
  target_link_libraries(poko_rhi_fallback PUBLIC poko_clear_backend_selection poko_rhi_vulkan PRIVATE SDL3::SDL3 Diligent-GraphicsEngineOpenGL-static Diligent-TargetPlatform)
  set_target_properties(poko_rhi_fallback PROPERTIES CXX_EXTENSIONS OFF)
  add_executable(pokox_fallback_clear engine/rhi/src/device/fallback_clear_demo.cpp)
  target_link_libraries(pokox_fallback_clear PRIVATE poko_rhi_fallback SDL3::SDL3)
  set_target_properties(pokox_fallback_clear PROPERTIES CXX_EXTENSIONS OFF)
endif()
