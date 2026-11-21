# ENG-01–06 follow-up audit

The owner requested another review of file placement and potential problems before continuing. Existing engine source, headers, tests, shaders and build helpers remain grouped under their owning subfolders; compatibility headers are retained for prior include paths. No additional misplaced project-owned source files or newly confirmed ENG-01–06 implementation defects were identified in this review. Prior findings and limitations are retained in the earlier ENG-01–05 audit and ENG-06 progress note.

## Improvements

- Expanded CPU frame-graph tests with 64 deterministic, varied eight-pass acyclic resource graphs registered in reverse order. An independent ordering check verifies producer/consumer dependencies; this strengthens coverage rather than claiming GPU integration.
- Implemented the next task, ENG-07, including checks for failed shader builds, stale artifacts, compiler changes, unsupported includes, path quoting and source/output collision. See `eng07-progress.md`.

## Verification (Linux, GCC 11.5 and CMake 3.31)

- Fresh default Debug build: **27/27** CTests passed without requiring a shader compiler.
- Strict-warning SDL-enabled audit build: **29/29** CTests passed; the incremental project build produced no compiler warnings. This is not a claim that all dependencies or all platforms are warning-free.
- Shader-enabled build with a real glslang 14.3.0 host tool: **28/28** CTests passed, including shader compilation and failure/rebuild checks. Both resulting modules passed a separate SPIRV-Tools Vulkan 1.1 validation. A nonexistent compiler was rejected at configure time.
- Frame-graph and OpenGL-double tests plus the fallback-double demo passed **4/4** under AddressSanitizer and UndefinedBehaviorSanitizer after supplying the required local sanitizer runtime libraries. Eight deliberately injected frame-graph faults were detected. The OpenGL tests use fakes, not an actual GL driver.

## Remaining acceptance work

Automated checks on Linux cannot prove Windows/MSVC, Android lifecycle or real OpenGL output/resize correctness. Third-party Diligent configuration emits upstream warnings, and the earlier GCC static-analysis run reported likely library-related false positives. The CPU frame graph is still not connected to RHI resources, barriers or GPU submission; no device-loss recovery has been demonstrated. These are open, not silently accepted.
