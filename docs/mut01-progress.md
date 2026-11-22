# MUT-01 — lexer core progress (2026-11-22)

## Scope and integration

At the owner's direction, work started on the lexer while previously documented infrastructure/graphics acceptance gates remained open. This is an execution-order exception, not acceptance of those gates. The dependency-free C++20 static library `poko_mute_lexer` is built by the main project and exports `mute/include/poko/mute/lexer.hpp`. Source, Unicode data/generator, unit tests and token goldens live under `mute/`. The existing minimal version integration fixture now copies the new build inputs. No parser, runtime, antialiasing, or unrelated task was added.

## Implemented

- Validates UTF-8 throughout the input, rejects an initial UTF-8 BOM, and preserves original byte offsets while treating CRLF as one line break. Bare CR is provisionally treated as a newline. Columns count Unicode scalar values, not grapheme clusters or tab display widths.
- Unicode 15.1 XID start/continue tables are generated from the included UCD data, verified with pinned SHA-256 and independently checked against every scalar/code-point position in that data. `_` is not an XID_Start, as the current specification literally states.
- Core identifiers, a provisional reserved-keyword set, numeric tokens, punctuation, longest-first operators, doc comments and raw strings; ordinary comments are skipped. Invalid inputs return one diagnostic rather than partially successful tokens.
- Interpolation-aware balancing of braces, nested strings and comments keeps a raw string intact; the expression itself is not lexed, validated, compiled or evaluated. Detailed current choices and unsupported syntax are in `mute/README.md`. The language specification does not yet settle the exact reserved words, escapes, numeric extensions, or interpolation grammar, so these choices are not asserted to be final.

## Local evidence

- Strict dependency-free Linux/GCC C++20 build, `-Wall -Wextra -Wpedantic -Werror`: 46/46 configured CTest entries passed, including all 3 new lexer-related entries.
- Linux address/undefined sanitizers and leak detection: 46/46 configured entries passed. Unit coverage includes 20,000 deterministic randomized arbitrary-byte/ASCII inputs and offsets; this is not a proof of memory safety.
- Three checked-in golden fixtures exercise core tokens, Unicode/CRLF/nested interpolation, and an invalid number. Each passes the existing byte-exact harness; deliberate corruption is rejected. Unicode generator reproducibility and UCD conformance are separately tested.
- Real SDL3 + pinned Diligent software-Vulkan configuration: 62/62 configured CTest entries passed, including the unchanged cube golden on Xvfb/llvmpipe. An initial attempt failed because `LP_NATIVE_VECTOR_WIDTH=128` was omitted; the documented pinned environment passed without changing the reference. This is not a physical-GPU, OpenGL-display or target-platform test. Configuration emitted 21 upstream CMake deprecation warnings; Xvfb emitted nonfatal keyboard-map warnings.
- A clean extraction of the packaged archive configured, built with strict warning-as-error flags and passed 46/46 CTest entries.
- Source-graph refresh succeeded but reported unsupported files/extractors and stale community labels; it is not a complete project map.

## Completion follow-up (2026-11-22)

The MUT-01 implementation and token-golden criterion are **complete locally for the initial lexical contract** in `mute/LEXICAL-CONTRACT.md`. The contract makes previously unspecified choices explicit; it is a development baseline, not an assertion that the language owner approved every future language feature. The parser, expression validation and compile-time interpolation are deliberately outside MUT-01.

- The complete published Mute syntax example now has a 208-token golden, constructed from an independent simple reference scanner and checked against the lexer. Nine source/diagnostic golden cases pass the shared byte-exact harness, and deliberate mismatches fail.
- Contract tests cover every reserved keyword, supported numeric suffix, punctuation/operator and maximal munch, Unicode and newline positions, UTF-8 boundary failures, error locations, comments, nested strings and 2,000 interpolation levels, plus 1,000 deterministic 40-token streams. The original randomized malformed-byte test remains in place.
- Found and fixed a Windows golden-output portability bug: the dump selects binary stdout on Windows. `.gitattributes` preserves LF golden output and exact-byte source/UCD input across Git checkout settings. A fresh temporary Git repository with `core.autocrlf=true` preserved all tested fixture and UCD bytes. Replaced a Python 3.10-only generator write API to retain the project's Python 3.9 minimum; Unicode tests verify stale output, full regeneration, and tampered-input rejection without changing output on failure. The Windows-specific branch and Python 3.9 were not run on their native platforms here.
- Final strict Linux/GCC C++20 suite: **48/48**; address/undefined sanitizers with leak detection: **48/48**; real SDL3 + pinned Diligent software Vulkan/Xvfb suite: **64/64**, including the unchanged cube golden. These include unit tests and doubles, not 64 physical-device tests. Real-graphics configure emitted 21 upstream CMake deprecation warnings; Xvfb emitted nonfatal keyboard-map warnings. No warning-free claim is made.
- A clean extraction of the final archive built with strict warning-as-error flags and passed **48/48** CTest entries.
- Source graph refresh succeeded but excluded 111 unsupported files and reported stale community labels; it is not a complete project map.

## Remaining gates

Formal acceptance remains open because earlier INF-02/04/05 hosted/target-platform checks and existing ENG device/hosted-golden gates have not been verified. Linux results and the simulated Git checkout are not Windows/MSVC, Android or hosted-CI evidence. Under the owner's existing execution-order exception, MUT-02 (arithmetic parser and AST golden) is the next development task; it consumes the initial contract but must not be represented as closing any prior gate. Additional escapes, exponent/separator syntax and interpolation-expression parsing are future language decisions, not implemented capabilities.

## Unicode data provenance

Unicode 15.1.0 `DerivedCoreProperties.txt`, downloaded from `https://www.unicode.org/Public/15.1.0/ucd/DerivedCoreProperties.txt`; SHA-256 `f55d0db69123431a7317868725b1fcbf1eab6b265d756d1bd7f0f6d9f9ee108b`. Unicode's copyright and license are included under `mute/data/unicode/`. Generator uses the pinned local data and requires no network.
