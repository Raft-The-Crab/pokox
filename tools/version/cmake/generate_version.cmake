# Generate the current exact-HEAD Git tag as byte-safe C++ build metadata.
if(NOT DEFINED POKO_SOURCE_DIR OR NOT DEFINED POKO_VERSION_HEADER)
  message(FATAL_ERROR "Version generation needs POKO_SOURCE_DIR and POKO_VERSION_HEADER")
endif()
set(version "unversioned")
if(EXISTS "${POKO_SOURCE_DIR}/.git")
  if(NOT DEFINED POKO_GIT_EXECUTABLE OR NOT EXISTS "${POKO_GIT_EXECUTABLE}")
    message(FATAL_ERROR "Git is required to determine a Git checkout's build version")
  endif()
  execute_process(COMMAND "${POKO_GIT_EXECUTABLE}" -C "${POKO_SOURCE_DIR}"
    rev-parse --show-toplevel RESULT_VARIABLE root_result OUTPUT_VARIABLE git_root
    ERROR_VARIABLE git_error OUTPUT_STRIP_TRAILING_WHITESPACE ENCODING NONE)
  if(NOT root_result STREQUAL "0")
    message(FATAL_ERROR "Cannot inspect Git checkout: ${git_error}")
  endif()
  file(REAL_PATH "${git_root}" git_root_real)
  file(REAL_PATH "${POKO_SOURCE_DIR}" source_root_real)
  if(WIN32)
    string(TOLOWER "${git_root_real}" git_root_real)
    string(TOLOWER "${source_root_real}" source_root_real)
  endif()
  if(NOT git_root_real STREQUAL source_root_real)
    message(FATAL_ERROR "The Git checkout root does not match the PokoX project root")
  endif()
  execute_process(COMMAND "${POKO_GIT_EXECUTABLE}" -C "${POKO_SOURCE_DIR}"
    rev-parse --verify --quiet HEAD RESULT_VARIABLE head_result OUTPUT_QUIET ERROR_QUIET
    ENCODING NONE)
  if(head_result STREQUAL "0")
    execute_process(COMMAND "${POKO_GIT_EXECUTABLE}" -C "${POKO_SOURCE_DIR}"
      for-each-ref --points-at=HEAD --sort=refname --count=1 "--format=%(refname:strip=2)" refs/tags
      RESULT_VARIABLE tag_result OUTPUT_VARIABLE tag ERROR_VARIABLE git_error
      OUTPUT_STRIP_TRAILING_WHITESPACE ENCODING NONE)
    if(NOT tag_result STREQUAL "0")
      message(FATAL_ERROR "Cannot read Git tags: ${git_error}")
    endif()
    if(NOT tag STREQUAL "")
      set(version "${tag}")
    endif()
  endif()
endif()
# Encode every UTF-8 byte to avoid interpreting tag punctuation as C++ syntax.
string(HEX "${version}" version_hex)
string(REGEX REPLACE "(..)" "\\\\x\\1" version_literal "${version_hex}")
get_filename_component(header_dir "${POKO_VERSION_HEADER}" DIRECTORY)
file(MAKE_DIRECTORY "${header_dir}")
file(CONFIGURE OUTPUT "${POKO_VERSION_HEADER}" CONTENT "#pragma once\nnamespace poko::build { inline constexpr char version[] = \"${version_literal}\"; }\n" @ONLY)
