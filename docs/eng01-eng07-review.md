# ENG-01–07 follow-up review

Scope: review and improve ENG-01 through ENG-07, without starting ENG-08. Prior reports retain the detailed platform, renderer, layout and frame-graph findings.

## Findings and improvements

- **Shader source/tool overwrite risk (fixed):** a different lexical output path through a symlinked parent could refer to the shader source. The old rule deleted its output before compiling, so it could delete that source. The rule now checks both normalized paths and existing canonical paths before removing either the final or temporary output, and also protects the compiler executable. Regression tests cover direct, normalized, temporary-output and symlinked-parent collisions; symlink tests run on non-Windows hosts.
- **Untracked include bypass (fixed):** GLSL accepts comment-separated directives such as `#/**/include`, which the old include check missed. The check now accounts for escaped line continuations and comment whitespace, preserving newlines, and rejects include directives. Tests cover multiple forms and confirm commented-out text is not mistaken for an active include. Shader includes remain unsupported until dependency tracking is added.
- **Build-failure limitation clarified:** if a build fails before invoking the shader rule, such as a missing input dependency, an older output may still be present. Artifacts must only be consumed after a successful build.
- Reviewed source placement and prior ENG-01–06 fixes; compatibility forwarding headers remain intentional. No other new confirmed implementation defects were found in this pass.

## Checks and limits

- Linux GCC 11.5 / CMake 3.31: fresh Debug build with SDL3 and real glslang 14.3.0, strict compiler warnings and `-Werror`; **30/30** CTests passed. The fresh configure and initial build emitted no warnings in this configuration. After the final shader fixes the same full suite was rerun. Both resulting shader modules passed a separate SPIRV-Tools Vulkan 1.1 validation.
- Default no-shader build was retested separately. Existing Vulkan and OpenGL fallback demo targets rebuilt against the actual dependencies without compiler warnings in the incremental build. Four frame-graph/OpenGL-double checks passed with AddressSanitizer and UndefinedBehaviorSanitizer. Doubles do not validate a graphics driver.
- The source/tool collision checks are build-time safeguards, not a security boundary against concurrent filesystem changes. Compiler versions are not pinned; include handling is not transitive dependency support or full GLSL analysis, and the build itself does not perform full SPIR-V validation.
- Real Windows/MSVC, Android, OpenGL fallback and resize/visual acceptance, device-loss handling, CI, and frame-graph integration with GPU resources/barriers remain open. No claim of artifact-free real-device rendering is made.
