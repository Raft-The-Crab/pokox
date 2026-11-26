cmake_minimum_required(VERSION 3.28)
project(PokoX LANGUAGES CXX)

# Project-wide C++20: per-target cxx_std_20 features miss test/fault targets
# and the VS generator then defaults them to C++14.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

if(POKO_MUTE_X11_INTERACTION_TESTS AND (NOT BUILD_TESTING OR NOT POKO_WITH_IMGUI_DEMO OR NOT POKO_DEBUG OR NOT CMAKE_SYSTEM_NAME STREQUAL "Linux"))
  message(FATAL_ERROR "POKO_MUTE_X11_INTERACTION_TESTS requires Linux, BUILD_TESTING, POKO_WITH_IMGUI_DEMO and POKO_DEBUG")
endif()

if(POKO_WITH_CUBE_GOLDEN AND (NOT POKO_WITH_CUBE_DEMO OR NOT BUILD_TESTING OR NOT POKO_DEBUG OR NOT CMAKE_SYSTEM_NAME STREQUAL "Linux"))
  message(FATAL_ERROR "POKO_WITH_CUBE_GOLDEN requires Linux, BUILD_TESTING, POKO_WITH_CUBE_DEMO and POKO_DEBUG")
endif()

if(POKO_WITH_SHADER_ARTIFACTS AND (NOT CMAKE_SYSTEM_NAME STREQUAL "Linux"))
  message(FATAL_ERROR "POKO_WITH_SHADER_ARTIFACTS requires a Linux host glslangValidator")
endif()

find_program(GLSLANG_VALIDATOR glslangValidator)
if(POKO_WITH_SHADER_ARTIFACTS AND NOT GLSLANG_VALIDATOR)
  message(FATAL_ERROR "POKO_WITH_SHADER_ARTIFACTS=ON but glslangValidator was not found")
endif()

set(POKO_WARNING_FLAGS
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>)

add_library(poko_config INTERFACE)
target_compile_features(poko_config INTERFACE cxx_std_20)
set_target_properties(poko_config PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(poko_config INTERFACE ${POKO_WARNING_FLAGS})

if(POKO_D3D12)
  target_compile_definitions(poko_config INTERFACE POKO_D3D12=1)
endif()

if(POKO_IMGUI)
  target_compile_definitions(poko_config INTERFACE POKO_IMGUI=1)
endif()

if(POKO_SOFT_BODY)
  target_compile_definitions(poko_config INTERFACE POKO_SOFT_BODY=1)
endif()

add_library(poko_clear_backend_selection INTERFACE)
if(POKO_WITH_VULKAN_DEMO OR POKO_WITH_FALLBACK_DEMO OR POKO_WITH_TRIANGLE_DEMO OR POKO_WITH_DEPTH_DEMO OR POKO_WITH_UNIFORM_DEMO OR POKO_WITH_IMGUI_DEMO OR POKO_WITH_CUBE_DEMO)
  target_compile_definitions(poko_clear_backend_selection INTERFACE POKO_CLEAR_USE_VULKAN=1)
endif()

add_subdirectory(engine)
add_subdirectory(mute)
add_subdirectory(tools)

if(BUILD_TESTING)
  add_executable(pokox_foundation_test engine/foundation/tests/foundation_test.cpp)
  target_link_libraries(pokox_foundation_test PRIVATE poko_foundation)
  add_test(NAME foundation_unit COMMAND pokox_foundation_test)

  add_executable(pokox_fixed_math_test engine/foundation/tests/fixed_math_test.cpp)
  target_link_libraries(pokox_fixed_math_test PRIVATE poko_foundation)
  add_test(NAME fixed_math_unit COMMAND pokox_fixed_math_test)

  add_executable(pokox_software_rasterizer_test engine/rhi/tests/software_rasterizer_test.cpp)
  target_link_libraries(pokox_software_rasterizer_test PRIVATE poko_rhi_software)
  add_test(NAME software_rasterizer_unit COMMAND pokox_software_rasterizer_test)

  add_executable(pokox_framegraph_test engine/render/tests/framegraph_test.cpp)
  target_link_libraries(pokox_framegraph_test PRIVATE poko_render)
  add_test(NAME framegraph_unit COMMAND pokox_framegraph_test)

  add_executable(pokox_d3d12_stub_test engine/rhi/tests/d3d12_stub_test.cpp)
  target_link_libraries(pokox_d3d12_stub_test PRIVATE poko_rhi_d3d12_stub)
  add_test(NAME d3d12_stub_unit COMMAND pokox_d3d12_stub_test)

  add_executable(pokox_command_queue_test engine/rhi/tests/command_queue_test.cpp)
  target_link_libraries(pokox_command_queue_test PRIVATE poko_rhi_d3d12_stub)
  add_test(NAME command_queue_unit COMMAND pokox_command_queue_test)

  add_executable(pokox_shader_reflection_test engine/rhi/tests/shader_reflection_test.cpp)
  target_link_libraries(pokox_shader_reflection_test PRIVATE poko_rhi_d3d12_stub)
  add_test(NAME shader_reflection_unit COMMAND pokox_shader_reflection_test)

  add_executable(pokox_pso_cache_test engine/rhi/tests/pso_cache_test.cpp)
  target_link_libraries(pokox_pso_cache_test PRIVATE poko_rhi_d3d12_stub)
  add_test(NAME pso_cache_unit COMMAND pokox_pso_cache_test)

  add_executable(pokox_ring_allocator_test engine/rhi/tests/ring_allocator_test.cpp)
  target_link_libraries(pokox_ring_allocator_test PRIVATE poko_rhi_d3d12_stub)
  add_test(NAME ring_allocator_unit COMMAND pokox_ring_allocator_test)

  add_executable(pokox_fuzzy_match_test tools/testutils/fuzzy_match_test.cpp)
  target_link_libraries(pokox_fuzzy_match_test PRIVATE poko_testutils)
  add_test(NAME fuzzy_match_unit COMMAND pokox_fuzzy_match_test)

  add_executable(pokox_version_test tools/version/version_test.cpp)
  target_link_libraries(pokox_version_test PRIVATE poko_version)
  add_test(NAME version_unit COMMAND pokox_version_test)

  add_executable(pokox_physics_test engine/physics/tests/unit/physics_test.cpp)
  target_link_libraries(pokox_physics_test PRIVATE poko_physics)
  add_test(NAME physics_unit COMMAND pokox_physics_test)

  add_executable(pokox_sap_broadphase_test engine/physics/tests/unit/sap_broadphase_test.cpp)
  target_link_libraries(pokox_sap_broadphase_test PRIVATE poko_physics)
  add_test(NAME sap_broadphase_unit COMMAND pokox_sap_broadphase_test)

  add_executable(pokox_narrowphase_test engine/physics/tests/unit/narrowphase_test.cpp)
  target_link_libraries(pokox_narrowphase_test PRIVATE poko_physics)
  add_test(NAME narrowphase_unit COMMAND pokox_narrowphase_test)

  add_executable(pokox_solver_test engine/physics/tests/unit/solver_test.cpp)
  target_link_libraries(pokox_solver_test PRIVATE poko_physics)
  add_test(NAME solver_unit COMMAND pokox_solver_test)

  add_executable(pokox_character_controller_test engine/physics/tests/unit/character_controller_test.cpp)
  target_link_libraries(pokox_character_controller_test PRIVATE poko_physics)
  add_test(NAME character_controller_unit COMMAND pokox_character_controller_test)

  add_executable(pokox_soft_body_test engine/physics/tests/unit/soft_body_test.cpp)
  target_link_libraries(pokox_soft_body_test PRIVATE poko_physics)
  add_test(NAME soft_body_unit COMMAND pokox_soft_body_test)

  add_executable(pokox_mute_lexer_test mute/tests/unit/lexer_test.cpp)
  target_link_libraries(pokox_mute_lexer_test PRIVATE poko_mute_lexer)
  add_test(NAME mute_lexer_unit COMMAND pokox_mute_lexer_test)

  add_executable(pokox_mute_parser_test mute/tests/unit/parser_test.cpp)
  target_link_libraries(pokox_mute_parser_test PRIVATE poko_mute_parser)
  add_test(NAME mute_parser_unit COMMAND pokox_mute_parser_test)

  add_executable(pokox_mute_evaluator_test mute/tests/unit/evaluator_test.cpp)
  target_link_libraries(pokox_mute_evaluator_test PRIVATE poko_mute_evaluator)
  add_test(NAME mute_evaluator_unit COMMAND pokox_mute_evaluator_test)

  add_executable(pokox_mute_ir_test mute/tests/unit/ir_test.cpp)
  target_link_libraries(pokox_mute_ir_test PRIVATE poko_mute_ir)
  add_test(NAME mute_ir_unit COMMAND pokox_mute_ir_test)

  add_executable(pokox_mute_emit_test mute/tests/unit/emit_test.cpp)
  target_link_libraries(pokox_mute_emit_test PRIVATE poko_mute_emit)
  add_test(NAME mute_emit_unit COMMAND pokox_mute_emit_test)

  add_executable(pokox_mute_bytecode_test mute/tests/unit/bytecode_test.cpp)
  target_link_libraries(pokox_mute_bytecode_test PRIVATE poko_mute_bytecode)
  add_test(NAME mute_bytecode_unit COMMAND pokox_mute_bytecode_test)

  add_executable(pokox_mute_vm_test mute/tests/unit/vm_test.cpp)
  target_link_libraries(pokox_mute_vm_test PRIVATE poko_mute_vm)
  add_test(NAME mute_vm_unit COMMAND pokox_mute_vm_test)

  add_executable(pokox_mute_determinism_test mute/tests/unit/determinism_test.cpp)
  target_link_libraries(pokox_mute_determinism_test PRIVATE poko_mute_determinism)
  add_test(NAME mute_determinism_unit COMMAND pokox_mute_determinism_test)

  add_executable(pokox_mute_values_test mute/tests/unit/values_test.cpp)
  target_link_libraries(pokox_mute_values_test PRIVATE poko_mute_values)
  add_test(NAME mute_values_unit COMMAND pokox_mute_values_test)

  add_executable(pokox_mute_hostcall_test mute/tests/unit/hostcall_test.cpp)
  target_link_libraries(pokox_mute_hostcall_test PRIVATE poko_mute_program)
  add_test(NAME mute_hostcall_unit COMMAND pokox_mute_hostcall_test)

  add_executable(pokox_mute_stdlib_math_test mute/tests/unit/stdlib_math_test.cpp)
  target_link_libraries(pokox_mute_stdlib_math_test PRIVATE poko_mute_stdlib_math)
  add_test(NAME mute_stdlib_math_unit COMMAND pokox_mute_stdlib_math_test)

  add_executable(pokox_mute_stdlib_crypto_test mute/tests/unit/stdlib_crypto_test.cpp)
  target_link_libraries(pokox_mute_stdlib_crypto_test PRIVATE poko_mute_stdlib_crypto)
  add_test(NAME mute_stdlib_crypto_unit COMMAND pokox_mute_stdlib_crypto_test)
endif()
