if(NOT DEFINED POKO_EXECUTABLE OR NOT DEFINED EXPECT_IMGUI OR
   NOT DEFINED EXPECT_D3D12 OR NOT DEFINED EXPECT_DEBUG)
  message(FATAL_ERROR "Build info test is missing inputs")
endif()
execute_process(COMMAND "${POKO_EXECUTABLE}" --build-info
  RESULT_VARIABLE result OUTPUT_VARIABLE output ERROR_VARIABLE error)
if(NOT result STREQUAL "0")
  message(FATAL_ERROR "Build info command failed (${result}): ${error}")
endif()
string(REPLACE "\r\n" "\n" output "${output}")
set(expected "POKO_IMGUI=${EXPECT_IMGUI}\nPOKO_D3D12=${EXPECT_D3D12}\nPOKO_DEBUG=${EXPECT_DEBUG}\n")
if(NOT output STREQUAL expected)
  message(FATAL_ERROR "Build info mismatch. Expected [${expected}], got [${output}]")
endif()
