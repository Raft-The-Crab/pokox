# MUT-02 — arithmetic AST (2026-11-22)

## Scope and status

At the owner's request, MUT-02 proceeded under the existing execution-order exception while earlier INF/ENG hosted and target-platform gates remained open. The arithmetic parser and AST-dump golden criterion are **complete locally**; this does not close those gates or establish target-platform acceptance. `mute/ARITHMETIC-PARSER.md` specifies the grammar, API, AST ownership and error behavior.

The C++20 `poko_mute_parser` library links the lexer and parses one complete expression consisting of integer/float literals, identifiers, parentheses, unary `+`/`-`, and binary `+ - * / %`. Precedence and left associativity follow the specification. The AST is an owned flat node arena with original source spans and an iterative deterministic ASCII S-expression dump. Parser, dumper and AST destruction do not recurse on expression depth. Lexical errors are returned unchanged; parser diagnostics are distinct. No evaluator, type checker, conversion, numeric range handling, statements or broader language syntax is included. There is no built-in source or allocation quota.

## Evidence

- Nine byte-exact AST/error goldens exercise precedence, associativity, grouping, unary operators, Unicode and lexer/parser diagnostics. The project's shared harness compares each and rejects deliberate corruption. Golden stdout is binary on Windows and Git attributes preserve fixture bytes; a `core.autocrlf=true` checkout preserved all 37 checked fixture/UCD files byte-for-byte. This simulated setting is not a Windows execution.
- An independent recursive grammar agreed on 500 deterministic generated arithmetic expressions. Unit tests cover spans, ownership after source destruction, move behavior, errors, 20,000 randomized byte/ASCII inputs and chains of 30,000 unary operators, binary operations and parentheses. These are tests, not a proof of correctness or unbounded-resource safety.
- Strict C++20 Linux/GCC build (`-Wall -Wextra -Wpedantic -Werror`): **51/51** CTest entries passed. ASan/UBSan with leak detection: **51/51**. Real SDL3 + pinned Diligent software-Vulkan/Xvfb suite: **67/67**, including the unchanged screenshot golden. These suites contain doubles and are not equivalent to 67 live-device tests. Build logs showed no compiler warnings; the real-graphics configure step reported 21 upstream CMake deprecation warnings, and Xvfb reported nonfatal keyboard-map warnings.
- A clean extraction of the packaged archive built with strict warning-as-error flags and passed **51/51** CTest entries.
- Source-graph update succeeded but excluded 127 unsupported files and reported stale community labels; it is not a complete project map.

## Remaining

Hosted GitHub CI, Windows/MSVC/MinGW, Android and prior ENG device/graphics acceptance remain unverified. The parser's Windows-specific binary-output test branch was not run on Windows here. Earlier INF-02/04/05 and ENG gates remain open. Under the owner's prior exception the next development task is MUT-03, a tree-walk evaluator; its numeric, error and resource semantics require explicit design and tests. A future evaluator must avoid recursively walking arbitrarily deep ASTs or impose a safe depth/size policy.
