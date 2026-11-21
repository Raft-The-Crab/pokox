# Explicit host-tool compilation; no network or implicit SDK installation.
function(poko_compile_shader output source stage)
  if(NOT stage STREQUAL "vert" AND NOT stage STREQUAL "frag")
    message(FATAL_ERROR "Unsupported shader stage '${stage}'; expected vert or frag")
  endif()
  if(NOT IS_ABSOLUTE "${source}" OR NOT IS_ABSOLUTE "${output}")
    message(FATAL_ERROR "Shader source and output paths must be absolute")
  endif()
  set(script "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/compile_shader.cmake")
  set(tool_dependencies "${POKO_GLSLANG_EXECUTABLE}")
  if(POKO_SHADER_TOOL_SIGNATURE)
    list(APPEND tool_dependencies "${POKO_SHADER_TOOL_SIGNATURE}")
  endif()
  add_custom_command(
    OUTPUT "${output}"
    COMMAND "${CMAKE_COMMAND}"
      "-DPOKO_SHADER_SOURCE:FILEPATH=${source}"
      "-DPOKO_SHADER_OUTPUT:FILEPATH=${output}"
      "-DPOKO_SHADER_STAGE:STRING=${stage}"
      "-DPOKO_SHADER_COMPILER:FILEPATH=${POKO_GLSLANG_EXECUTABLE}"
      -P "${script}"
    DEPENDS "${source}" "${script}" ${tool_dependencies}
    COMMENT "Compiling ${stage} shader to SPIR-V"
    VERBATIM)
endfunction()
