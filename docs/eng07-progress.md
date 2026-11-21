# ENG-07 — build-time GLSL to SPIR-V

The owner requested continuation after the ENG-01–06 audit. This slice implements the build-time artifact criterion, not the subsequent rendering task, and does not waive earlier device or project gates.

## Implemented

- Opt in with `POKO_WITH_SHADER_ARTIFACTS=ON` and an available host `glslangValidator`/`glslang`; the default build does not need the compiler. CMake reports the selected executable and version. No SDK is downloaded or bundled, and compiler versions are not pinned.
- The `pokox_shaders` build target compiles checked-in vertex and fragment GLSL 450 samples to Vulkan 1.1 SPIR-V in the build tree, separated by configuration. See `engine/render/README.md` for commands and cross-compilation notes.
- Inputs, rule script and compiler identity/executable are dependencies. Compilation uses a temporary file; failures remove old and temporary outputs. The rule rejects unsupported includes, including comment-separated directives and escaped-line forms, and checks lexical and existing canonical paths before removing an output or temporary file that could alias the source or compiler. If the build system fails before the rule starts (for example, a missing source dependency), an older output can still remain: only use artifacts from a successful build. Its size and magic checks are not a full SPIR-V validator.
- The integration test invokes a real host compiler in paths containing spaces, verifies headers and a source-triggered rebuild, checks compiler path changes on non-Windows hosts, and tests syntax failures, cleanup, include rejection (including disguised directives), commented-out includes and output/source/compiler collision protection, including symlinked parent paths on non-Windows hosts.

## Verification and boundaries

On Linux, glslang 14.3.0 produced vertex and fragment SPIR-V. Both particular artifacts passed a separate SPIRV-Tools Vulkan 1.1 validation; that independent local check is not a validation stage installed in the build pipeline. Shader-enabled, default and SDL audit suites are summarized in `eng01-eng06-followup-audit.md`.

At the ENG-07 milestone no runtime shader loading or GPU rendering was implemented. ENG-08 subsequently added an experimental Vulkan triangle demo; see `eng08-progress.md`. General shader reflection, include dependency tracking, shader variants and OpenGL/ES translation remain unimplemented. Windows/MSVC, Android and actual GPU visual acceptance remain unverified, as do the earlier OpenGL fallback and resize checks. Do not treat offline artifacts as evidence of a rendered triangle.
