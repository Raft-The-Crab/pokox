# Mute milestone progress (MUT-01..55)

## Current status — authoritative (2026-11-25)

This section overrides stale milestone-local "Remaining"/gate notes below.
Historical sections keep their original context; when they say a gate was
open, that was true at that milestone.

- Implemented through **MUT-55**: deterministic input snapshots, named actions,
  device-slot routing, and the host-side v1 standard libraries for math/time/
  RNG, UTF-8 strings/collections, SHA-256/HMAC/sign-verify and lifecycle/game
  events, plus the local pinned-lock build tool. `MUTI`, `MUTA`, device events
  and `mute.lock` use canonical byte formats. There is no registry, on-disk
  settings adapter, VM string/byte-buffer hostcall or script-facing action
  hostcall.
- There is still **no Mute-specific SDL/console host adapter**. Hosts and tests
  construct `InputEvent`s directly; focus events are explicit host inputs.
  ENG-02 window/platform evidence was collected separately on Windows and the
  physical Android device.
- **G1: accepted** for the approved Windows x64 + physical Android arm64 scope.
  **ENG-02: accepted** for window create/resize/teardown and Android surface
  presentation. **G2: accepted** (2026-11-26) — the canonical ENG-60→63 physics
  chain produced byte-identical 10,000-tick traces on Windows x64 and the
  physical Android arm64 device. See `two-target-gate-evidence-2026-11-26.md`.
- Latest verification (final 2026-11-26 audit): full Debug MSVC `ctest`
  **98/98**, full MSVC ASan `ctest` **98/98**, Android Mute binaries **12/12**,
  and byte-identical G1 traces on both targets. Optional GCC/Clang mutation
  scripts are explicit SKIP on this MSVC host. See
  `two-target-gate-evidence-2026-11-25.md`.
- Touch gestures beyond tap remain deferred. Gate acceptance belongs only to
  the owner decision recorded in the scope matrix and evidence docs.

---

## mut01-progress

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

## Remaining gates at this milestone (historical)

At this milestone, formal acceptance remained open because earlier INF-02/04/05 hosted/target-platform checks and existing ENG device/hosted-golden gates had not been verified. Linux results and the simulated Git checkout were not Windows/MSVC, Android or hosted-CI evidence. Under the owner's execution-order exception, MUT-02 was the next development task; it consumed the initial contract but did not close any prior gate. Additional escapes, exponent/separator syntax and interpolation-expression parsing were future language decisions, not implemented capabilities. Current gate status is at the top of this document.

## Unicode data provenance

Unicode 15.1.0 `DerivedCoreProperties.txt`, downloaded from `https://www.unicode.org/Public/15.1.0/ucd/DerivedCoreProperties.txt`; SHA-256 `f55d0db69123431a7317868725b1fcbf1eab6b265d756d1bd7f0f6d9f9ee108b`. Unicode's copyright and license are included under `mute/data/unicode/`. Generator uses the pinned local data and requires no network.

---

## mut02-progress

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

## Remaining at this milestone (historical)

At this milestone, hosted GitHub CI, Windows/MSVC/MinGW, Android and prior ENG device/graphics acceptance had not been verified. The parser's Windows-specific binary-output test branch had not been run on Windows there. Earlier INF-02/04/05 and ENG gates were open. Under the owner's prior exception, MUT-03 was the next development task; current gate status is at the top of this document. The parser's deep-AST constraints were design notes for that future evaluator, not a claim that MUT-39/MUT-40 input layers recurse over ASTs.

---

## mut03-progress

# MUT-03 — initial arithmetic evaluator (2026-11-22)

The owner requested MUT-03 and a subsequent audit. Under the existing execution-order exception, a C++20 iterative AST evaluator now supports checked signed/unsigned integer arithmetic and guarded f32/f64 `+ - * /`, with explicit typed errors, no implicit integer-to-float conversion, and a configurable AST-node cap. The initial arithmetic implementation and local tests pass; full numeric semantics, hosted CI and cross-platform determinism are not accepted. Follow-up: floating `%`, bounded source input, and read-only host numeric bindings are implemented; full language locals remain a later task. See `../mute/ARITHMETIC-EVALUATOR.md` for exact rules and `mut01-mut03-audit-2026-11-22.md` for findings, fixes and evidence. No parser, VM, UI, target-platform or infrastructure gate is closed by this change.

Strict, sanitizer and clean-extraction Linux suites each passed **54/54** CTest entries; the software graphics suite passed **70/70**. An independent oracle and exhaustive 8-bit check passed. The next queued development task is MUT-04 (ImGui console REPL), but it should not be treated as closing the open MUT-03 or earlier gates. Numeric, full-language binding and sandbox limitations must be accounted for before presenting this evaluator as a full language runtime.

Follow-up fixes and audit: see `mut01-mut03-followup-audit-2026-11-22.md`; earlier results above are historical and not a claim of cross-platform validation.

---

## mut04-progress

# MUT-04 — debug ImGui arithmetic console (2026-11-22)

> Historical MUT-04 snapshot. The later print-log addition is described in `mute-progress.md`.

MUT-04 adds a small expression console to the existing optional Vulkan/SDL3 ImGui debug demo. Click the field, type an arithmetic expression, and press Enter: the most recent typed numeric result or lex/parse/evaluation diagnostic appears below. F1 retains its existing whole-overlay toggle. The console is a demo integration, not a full engine console or Mute runtime.

## Scope and safety

- `mute/src/console.cpp` connects MUT-01–03 to one-line display strings, including typed numeric values, using locale-independent `to_chars`. It limits source to 4,095 bytes and AST evaluation to 4,095 nodes. The UI refuses to execute a completely full input buffer because paste/typing could have been truncated; in this UI at most 4,094 bytes are accepted for execution. These are not total memory, time or VM budgets.
- `SdlPlatform::poll_event` has a synchronous, per-call, non-owning raw-event observer. The normal event pump/translation and other callers remain unchanged; the demo filters by window ID and forwards text, editing keys, modifiers, focus and wheel to ImGui. The observer must not throw, poll recursively, retain the event, or mutate the platform. SDL text input is activated according to ImGui's request. F1 still works.
- The window currently shows only the latest output; no commands, history, autocomplete, socket, hostcalls, language locals or VM are implemented. The console exposes arithmetic only, no host bindings. Unsupported syntax and runtime errors are reported rather than silently accepted. The future `print` hostcall is MUT-05; functions/locals and VM are later tasks.
- The demo's debug variant links ImGui and Mute. The strip variant does not link or expose them. `POKO_DEBUG=ON` controls this particular existing demo; `POKO_IMGUI` is a separate build-info feature flag, not the console toggle.
- The UI bridge covers the tested keyboard/text path, not a complete platform backend: system clipboard integration, IME composition/candidate positioning, gamepad, non-US layouts, high DPI and mobile keyboard behavior are not yet verified/implemented. A full engine console, backtick shortcut, structured commands and local TCP socket described in the longer-term design remain later work.

## Build

The standard pinned-vcpkg workflow remains supported. The optional ImGui demo can now also use a separately installed `imgui` CMake package without enabling the full vcpkg dependency smoke test; this local route does **not** prove the full manifest. Set `CMAKE_PREFIX_PATH` to SDL3 and ImGui packages; provide pinned DiligentCore as described in `graphics-setup-2026-11-22.md`.

```sh
cmake -S . -B build-ui -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_PREFIX_PATH="/path/to/sdl3;/path/to/imgui" \
  -DFETCHCONTENT_SOURCE_DIR_DILIGENTCORE=/path/to/pinned/DiligentCore \
  -DPOKO_WITH_SDL_PLATFORM=ON -DPOKO_WITH_VULKAN_DEMO=ON \
  -DPOKO_WITH_SHADER_ARTIFACTS=ON -DPOKO_WITH_IMGUI_DEMO=ON -DPOKO_DEBUG=ON
cmake --build build-ui --target pokox_imgui_demo
./build-ui/pokox_imgui_demo --vertex build-ui/shaders/Release/triangle.vert.spv \
  --fragment build-ui/shaders/Release/triangle.frag.spv \
  --imgui-vertex build-ui/shaders/Release/imgui.vert.spv \
  --imgui-fragment build-ui/shaders/Release/imgui.frag.spv
```

Single-configuration generators use the configured build-type shader directory; multi-config generators need the appropriate `--config` and shader path. SDL3, Vulkan and a compatible desktop display/driver are required. The local sandbox used ImGui 1.93.0 from the vcpkg manifest baseline, with the upstream release SHA-512 matching the pinned vcpkg port, SDL 3.4.20, pinned DiligentCore and Mesa software Vulkan. These local packages are not bundled as installed libraries in the delivered archive.

## Tests and remaining gates

- Local strict Linux/GCC and ASan/UBSan suites each pass 55/55 tests. The real SDL3/Diligent/ImGui software-Vulkan suite passes 78/78. New unit tests check results, errors, caps and synchronous SDL observer behavior.
- A separate Xvfb/XTest keyboard run clicked the real field, typed `1+2*3` and `1/0`, and visibly rendered `i32: 7` and `eval error divide_by_zero at 1:2`; 600 frames reported zero graphics errors/warnings. The optional script `engine/render/tests/integration/test_mute_console_x11.py` compares rendered output-area changes, not OCR; its captured results were visually inspected. It uses synthetic X11 input, not physical devices. Existing F1 XTest passed; `nm` found no `ImGui::` or `poko::mute::` symbols in the strip binary. The UI translation unit also passed `-Wall -Wextra -Wpedantic -Werror` after fixing an existing missing-initializer warning.
- Historical milestone note: graphics configuration reported 21 upstream CMake deprecation warnings; Xvfb could report nonfatal keyboard-map warnings. Graphify skipped 155 unsupported files and partially extracted the demo at a preprocessor region. Windows/MSVC/MinGW, Android, physical GPU and hosted CI acceptance were unverified at that time. No cross-platform floating determinism gate or full sandbox was closed then. See `mut01-mut03-followup-audit-2026-11-22.md` for the historical numeric and resource findings, and the authoritative current status at the top of this document.

The next queued task is **MUT-05**, the `print` hostcall to the ImGui log; MUT-04's single-result display is not that hostcall.

---

## mut05-progress

# MUT-05 — print hostcall to the debug console (2026-11-22)

This is the MUT-05 historical snapshot. For subsequent functions/local support and the print-display audit fix, see `mute-progress.md` and `mut01-mut05-audit-2026-11-22.md`.

The optional debug ImGui console accepts a top-level `print(...)` call and appends its output to a scrollable **Print log**. For example, `print("hello")` adds `hello` and `print(2 + 3)` adds `5`. Successful calls report `unit` in the result field; invalid source, evaluation errors, missing hosts and sink failures report diagnostics without an additional print. The Clear button empties the log. Arithmetic expressions without `print` retain MUT-04 behavior.

## Initial contract and boundaries

- This is a narrow top-level console host-dispatch bridge, not general Mute function-call syntax or a VM `call_host` opcode. It accepts exactly one string literal or one supported arithmetic expression inside `print(...)`. Nested calls, multiple arguments, functions, variables, statements and general strings remain future work. Whitespace and ordinary comments are supported. The name is case-sensitive. The existing lexer validates the entire source and its 4,095-byte console limit before dispatch.
- Strings are decoded using the lexer's supported escapes, including escaped braces, quotes, backslash, `\n`, `\r`, `\t` and `\0`. Unescaped `{...}` interpolation is rejected, not evaluated. Numeric arguments use the existing typed evaluator and locale-independent numeric formatting. Diagnostic locations are adjusted back to the original source, including CRLF and multiple lines. The callback receives the decoded text exactly once only after input and argument evaluation succeed. An absent callback or a callback returning false yields a host diagnostic; a failing callback may itself have had side effects. The host owns its callback and context, and the text view is valid only for the call. Allocation failures or callback exceptions may propagate.
- The debug UI supplies the host callback and uses `ConsoleLog`: at most 100 entries and 65,536 stored bytes, evicting the oldest entries first. Each incoming entry is limited to 4,095 bytes. Control bytes (including NUL, newline, tab and carriage return) are shown as escapes to keep entries readable and avoid truncation; format strings are displayed as text. Rendering does not pass user text as a formatting string. The log is non-copyable and non-movable so its entry storage and byte count cannot diverge through implicit operations; borrowed entry references can be invalidated by mutation. A full input field is not executed because text could have been truncated. These limits do not constitute a VM instruction budget or complete sandbox.
- Logs live only for the demo's lifetime and are not files, telemetry, persistent history, or the eventual engine logging service. This is not the planned general engine console, socket, autocomplete, command system, or deterministic replay implementation. The UI bridge's IME, clipboard, non-US layout and mobile limitations documented in `mute-progress.md` still apply. Release strip keeps the demo free of ImGui and Mute symbols.

## Evidence and known limitations

- `mute_console_unit` checks strings, escapes, UTF-8, numeric values, sink count and errors, interpolation rejection, multiline source positions, bounded FIFO eviction, clearing, non-copyable/non-movable log invariants, and 10,000 random byte inputs plus 1,000 generated arithmetic prints. An audit caught a potential moved-from byte-count mismatch in the new log; implicit copy/move operations were removed before delivery. This does not establish full language conformance.
- Strict Linux/GCC and ASan/UBSan suites each pass 55/55. The SDL3/pinned Diligent/ImGui software-Vulkan suite passes 78/78. The optional Xvfb/XTest integration script types expressions and two print calls, observes changes in the output and log areas, and clicks Clear. Its screenshots were visually inspected for `hello` and `5`; pixel-difference checks are not OCR. Software Vulkan and synthetic events do not validate a physical GPU, real keyboard, Windows or Android.
- Historical status: hosted CI, Windows/MSVC/MinGW, Android, cross-platform float determinism, full VM budgets and finalized numeric semantics were open at this milestone; see the authoritative current status above. Graphics configuration still has 21 upstream CMake deprecation warnings; the graph has extractor limitations. See the MUT-01–03 follow-up audit and MUT-04 report for the earlier findings.

The next queued task is **MUT-06 — functions and locals**; this print bridge does not implement recursion or general call expressions.

---

## mut06-progress

# MUT-06 — initial functions and locals

This is the MUT-06 historical snapshot. Subsequent conditional and loop support is documented in `mute-progress.md`.

## Implemented

The initial tree-walk program interpreter in `mute/src/program.cpp` and public `poko/mute/program.hpp` supports i32 functions, arguments, checked arithmetic, local `let` and `var`, assignment to `var`, and direct or mutual recursion. A minimal `if <i32-expression> == <i32-expression> { ... }` with optional `else` is included only to give recursion a terminating base case. It does not implement the planned general conditions, `while`, infinite-loop handling or VM in MUT-07/08. Arguments and arithmetic operands are evaluated left-to-right, and the existing arithmetic evaluator performs numeric checks. Parameters are immutable; names may shadow outer names in inner blocks but cannot be redeclared in the same scope. Return values are checked i32. Missing return and unresolved names are runtime errors on the executed path; there is no full static checker.

```mute
fn factorial(n: i32) -> i32 {
  if n == 0 { return 1; }
  let smaller = n - 1;
  return n * factorial(smaller);
}
factorial(5)
```

`run_program` is stateless: definitions and locals last only for a single call. A program is one or more function definitions followed by one final expression. The optional debug console accepts this whole program in **one input line**, for example `fn f(n:i32)->i32{if n==0{return 1;}return n*f(n-1);}f(5)`; it shows `i32: 120`. Existing arithmetic and top-level print paths remain available. Definitions do not persist across console entries. Print from a user function, print of a function-call expression, globals, imports, non-i32 types, general comparisons/conditions, expression statements, loops, function overloading, full type checking, VM hostcalls and scripts/files are not implemented by this subset. Unreachable code is parsed but not statically resolved or type-checked.

## Limits and safety boundaries

`run_program` rejects sources over 65,536 bytes and token streams over 8,192 tokens, limits parser nesting to 64, functions to 256, parameters/arguments to 32, live parameters/locals in a frame to 256, call nesting to 64 and combined active expression/block execution depth to 128. It stops after 100,000 interpreter steps; these implementation-defined steps are **not** the planned VM instruction budget. The debug console has its pre-existing stricter 4,095-byte source limit. These are protective initial limits, not a total memory quota, security sandbox, hostcall capability system or real-time deadline. Allocation failures may propagate. Some deeply nested valid expressions can hit the combined depth limit before the call limit.

## Evidence and open gates

Unit coverage includes factorial, Fibonacci, mutual recursion, scope/shadowing, reassignment, argument counts, unknown names, missing returns, immutable locals, overflow, divide-by-zero, source/nesting/call/budget traps and deterministic malformed-input exercises. Strict GCC and ASan/UBSan suites each passed 56/56; the software-Vulkan suite passed 79/79 on rerun. An interactive X11 check compared the recursion result to a known `i32: 120` result. One prior graphics run hit an intermittent cube-golden X11 capture failure; see the MUT-01–05 audit. Passing the local recursion criterion does not establish general Mute language compatibility, production safety, performance or Windows/Android/physical-GPU behavior. Those checks and the inherited determinism/platform gates were open at this milestone; see the authoritative current status above.

---

## mut07-progress

# MUT-07 — initial if/while and runaway trap (2026-11-22)

## Implemented subset

The existing stateless, i32-only function interpreter now accepts boolean literals `true`/`false`, `!`, `&&`, `||`, i32 comparisons `< <= > >=`, and equality `== !=` for i32 or bool operands. Precedence follows unary, multiplicative, additive, ordered comparison, equality, `&&`, `||`; parentheses group expressions. Logical operators short-circuit left to right. `if` and `while` conditions must evaluate to bool; integers do not implicitly become bool. `if` supports an optional `else` block. All operators and condition types are checked dynamically only when evaluated; the skipped side of a short-circuit expression is not type-checked. There is no full static checker.

```mute
fn sum(n: i32) -> i32 {
  var i = 0;
  var total = 0;
  while i < n {
    i = i + 1;
    total = total + i;
  }
  return total;
}
sum(10)
```

This produces `i32: 55`. Each `while` condition is reevaluated before each iteration. The body gets a fresh scope each time; assignments to an outer `var` persist. `return` inside a loop exits the function. The same one-line program can be entered into the optional debug console; the console remains synchronous and has the pre-existing 4,095-byte limit.

## Deterministic execution budget

Each `run_program` invocation has an independent counter, shared by calls and nested loops. It charges statement and expression visits and additionally every `while` condition check, including empty bodies and false checks. The default and hard maximum is 100,000 implementation-defined tree-walk steps; `ProgramOptions{n}` can select any smaller value including zero, and a value above the cap returns `invalid_options`. Before a step would exceed the budget, evaluation returns `runtime / budget_exceeded`, e.g. for `fn f()->i32{while true{} return 0;} f()`. The parse and lex stages are separately bounded as described in MUT-06; the step counter does not account for all CPU work, wall-clock time, memory allocations or host activity. It is not the planned VM instruction/tick budget, a scheduler, an interrupt, or a security sandbox.

This is initial control flow, not full Mute: bool locals/parameters/returns, other numeric types, `break`, `continue`, `for`, `loop`, `match`, general hostcalls/print within functions, persistent REPL definitions, concurrency and bytecode are unsupported. The interpreter stops at the first error; it has no transactional host-side rollback. No new VM or production determinism claims are made.

## Test evidence and remaining gates

Unit tests cover true/false and zero-iteration loops, nested loops, fresh scopes, return from loops, all supported comparisons, operator precedence, short-circuit behavior, type errors, runaway empty and nonempty loops, exact low-budget boundaries, invalid options, budget reset between calls, 100 generated finite sums, 500 generated conditions against C++ expected values, and existing recursion and malformed-input tests. Strict GCC and ASan/UBSan suites each passed 56/56; software-Vulkan CTest passed 79/79. The XTest demo showed both the loop result and runaway trap. See the follow-up audit for evidence and limitations.

---

## mut21-progress

# MUT-21 — packages, imports and lockfile

Historical status: implemented locally at this milestone; see the authoritative current status above.

## What was added

- `mute/include/poko/mute/package.hpp` and `mute/src/package/package.cpp`:
  `resolve_packages` parses every supplied source as a v1 declaration module,
  extracts the `package`/`version` identity and `import "pkg://name[@word]" as
  alias` declarations, then resolves the whole set as one build.
- `dump_lockfile` emits canonical `mute.lock` text: `# mute.lock v1` header
  plus sorted `name@version <xxhash64>` lines. The hash is the raw source
  content hash; ordering is by name then version, independent of input order.
- `mute/tests/unit/package_test.cpp` registered as CTest `mute_package_unit`.

## Resolution rules

- Declared `package`/`version` must match the caller-claimed input identity.
- Duplicate `name@version` inputs are rejected.
- Imports may pin `pkg://name@Word` or leave the version unpinned; unpinned
  imports bind to the already-bound version for that name, else the single
  available version, else `ambiguous_version`.
- One version per package name per build; a second distinct version is
  `version_conflict` (covers diamonds requiring divergent pins).
- Missing names are `missing_dependency`; present names lacking the pinned
  word are `version_conflict`.
- The resolved graph must be acyclic; back edges report `cyclic_import`
  (self-imports included).
- Malformed specs (`pkg://` prefix required, nonempty name, nonempty pinned
  version) are `invalid_import_spec`; parse failures pass through as
  `parse_failed`.

## Evidence

- Debug MSVC build clean; `mute_package_unit` passes (17 scenario groups:
  pinned/unpinned resolution, missing, conflict, ambiguity, diamond conflict,
  cycles, self-import, duplicates, identity mismatch, missing declarations,
  malformed spec, parse failure, lockfile determinism across input order).
- Full local CTest: 73/73 passed (version_integration verified with the full
  MSVC/SDK toolchain environment).
- `tools/version` integration source list updated for the new files.

## Limits

- The resolver works on caller-supplied sources only; there is no registry,
  fetch, or `mute.lock` reader/writer yet (MUT-55 tooling).
- Import aliases are recorded but not yet bound into semantic analysis.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut22-progress

# MUT-22 — aggregate VM values and lifetimes (foundation)

Status: runtime foundation implemented and unit-tested locally; compiler/VM
integration and hosted/target gates were open at this milestone; see the authoritative current status above.

## What was added

- `mute/include/poko/mute/values.hpp` and `mute/src/vm/values.cpp`:
  `AggregateStore` owns aggregate VM values — `string` and `array` payloads
  behind bounded 32-bit handles, plus `integer`/`boolean` scalar `Value`s.
- `mute/tests/unit/values_test.cpp` registered as CTest `mute_values_unit`.

## Lifetime model

- All objects are reference counted. `make_array`/`set_index` increment child
  refs; `release`/`free_object` decrement recursively, so shared children
  survive until the last owner dies.
- `copy` is deep for strings and (recursively) arrays; scalars copy trivially.
- `reset_tick` frees every arena-resident object — the per-tick transient
  lifetime. `promote` moves a value and its aggregate children to the
  refcounted heap so `@state`-reachable values survive the tick boundary.
- Limits are configurable per store: max string bytes, max array length,
  max nesting depth, heap object count and heap bytes (defaults mirror the
  MUT-13 64 MiB script heap scale).

## Traps

Kind mismatches (`wrong_kind`), out-of-range or negative indices (`bounds`),
dead/foreign handles (`invalid_handle`), oversized inputs (`heap_exceeded`),
and nesting beyond `max_depth` (`depth_exceeded`) return `ValueError`
variants — no UB, no exceptions across the boundary.

## Evidence

- Debug MSVC build clean; `mute_values_unit` passes (creation, access,
  bounds traps, copy isolation, nested aggregates, refcounted release,
  promote/reset_tick survival, arena reclamation, limit enforcement,
  scalar pass-through).
- `tools/version` integration source list updated for the new files.

## Limits — all resolved (2026-11-24 follow-up)

- `get_index` returns `owned=false` borrowed values; `release()` ignores
  them, so container refcounts cannot be corrupted through borrows.
- Handles are generation-tagged 64-bit values; stale handles always fail
  validation instead of aliasing recycled slots.
- `set_index` rejects cycle-forming insertions (`ValueErrorCode::cycle`).
- Regression tests cover all three; see `mute-progress.md`.

## Still open

- Not yet wired into `run_program`/the register VM or bytecode (MUT-26
  lowering); no Mute surface syntax for aggregates exists yet.
- Struct/enum/map/option/result aggregates are not yet represented — only
  string and array exist in the store.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut23-progress

# MUT-23 — cooperative async scheduling (foundation)

Status: runtime foundation implemented and unit-tested locally; `await`/`spawn`
syntax lowering and hosted/target gates were open at this milestone; see the authoritative current status above.

## What was added

- `mute/include/poko/mute/scheduler.hpp` and `mute/src/vm/scheduler.cpp`:
  `Scheduler` drives resumable tasks one step at a time on a single thread.
- `mute/tests/unit/scheduler_test.cpp` registered as CTest
  `mute_scheduler_unit`.

## Semantics

- `spawn(step)` appends to a FIFO ready queue; `TaskId`s are stable slot
  indices bounded by `max_tasks` (default 1024).
- A step returns `yield` (re-queue FIFO), `await_task(target)` (suspend until
  target reaches `done` or `cancelled`), or `finish`.
- Waiters wake in deterministic task order; awaiting an already-terminal
  task resumes on the next slice; self-await and unknown targets cancel the
  waiter instead of hanging.
- `cancel(id)` marks the task cancelled: ready tasks are dropped without
  running, waiters are woken to observe the terminal state.
- `run()` enforces `max_steps` (default 1,000,000) and returns
  `budget_exceeded`; thrown step exceptions cancel the task.
- Identical spawn/await sequences produce identical completion orders —
  verified by replay test.

## Evidence

- Debug MSVC build clean; `mute_scheduler_unit` passes (FIFO order, replay
  determinism, await suspend/resume ordering, await-on-done, cancellation
  propagation, budget and task-table caps, self-await).
- `tools/version` integration source list updated.

## Limits

- Not wired into `run_program`/bytecode or the `await`/`spawn` surface
  syntax; that lowering is MUT-26 and hostcall/event integration is
  MUT-54.
- Task steps are `std::function` callbacks, not compiled Mute coroutines;
  the deterministic ordering contract is what the compiler must target.
- Waiter wake order is task-id order (deterministic), not arrival order —
  acceptable for v1 replay but noted for the conformance suite.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut24-progress

# MUT-24 — determinism and capability analysis (foundation)

Status: static analysis pass implemented and unit-tested locally; integration
into the compiler pipeline and hosted/target gates were open at this milestone; see the authoritative current status above.

## What was added

- `mute/include/poko/mute/determinism.hpp` and
  `mute/src/semantic/determinism.cpp`: `analyze_determinism` scans a parsed
  `DeclarationAst` and reports typed diagnostics with source positions.
- `mute/tests/unit/determinism_test.cpp` registered as CTest
  `mute_determinism_unit` (added to `poko_mute_semantic`).

## Rules enforced

- `allow:` capability names must be in the approved v1 set
  (Net, Physics, Storage, Ui, Asset, Crypto, Log, Time, Replicate, Spawn);
  unknown → `unknown_capability`, repeats → `duplicate_capability`.
- Capability tokens may not appear in `@state` types or initializer
  expressions → `capability_in_state`.
- Nondeterministic builtins are rejected with `nondeterministic_operation`
  when used inside `@state` (always) or outside it without the required
  declared capability: `now/time/clock/timestamp` need `Time`,
  `random/rand/uuid/guid` need `Crypto`, and `env/getenv/hostname/username/
  pid/addr` are unconditionally banned (seeded replay only, per MUT-13).
- Member-path spellings are matched on their last segment (`x.time()` counts
  as `time`).

## Coverage

- `allow` declarations, `@state` types and initializer expressions
  (`DeclarationAst::values()`), and all function bodies via iterative
  `StatementAst` traversal.

## Evidence

- Debug MSVC build clean; `mute_determinism_unit` passes (14 scenario
  groups: valid allows, unknown/duplicate capabilities, capability tokens in
  `@state` type and initializer, builtin bans with/without capabilities,
  unconditional bans).
- `tools/version` integration source list updated.

## Limits

- Analysis is syntactic: it does not yet prove a capability is actually
  *needed* (no `requires(...)` narrowing exists in the grammar) and does not
  cover `.pkB`/network serialization of capability tokens — those land with
  MUT-25–27 and MUT-36.
- Hostcall whitelisting is unchanged; this pass only gates source-level
  capability/determinism policy.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut25-progress

# MUT-25 — typed SSA IR (foundation)

Status: IR model and verifier implemented and unit-tested locally; AST→SSA
lowering and hosted/target gates were open at this milestone; see the authoritative current status above.

## What was added

- `mute/include/poko/mute/ssa.hpp` and `mute/src/semantic/ssa.cpp`:
  `IrModule`/`IrFunction`/`IrBlock`/`IrInstr` with typed `Type` payloads
  (reusing the MUT-19 `Type`/`TypeTag` model) and `verify()` returning typed
  `IrDiagnostic`s with function/block locations.
- `mute/tests/unit/ssa_test.cpp` registered as CTest `mute_ssa_unit`
  (part of `poko_mute_semantic`).

## IR model

- Value ids: params occupy 1..N; each non-terminator instruction may carry a
  unique `def` id; operands reference value ids (`0` = no value) plus an
  immediate payload for constants.
- Ops: `constant, copy, unary, binary, compare, phi, call, load, store,
  jump, branch, return_`. Terminators are `jump`/`branch`/`return_` and must
  be the last instruction of a block.
- `phi` takes `2 × predecessor_count` operands (value pairs per pred edge).

## Verifier checks (done-when)

- `empty_function`, `duplicate_label`, `unreachable_block` (reachability
  from block 0 via terminator targets).
- `missing_terminator`, `bad_terminator` (mid-block terminator, dangling
  jump/branch targets, predecessor-set mismatch vs actual edges).
- `type_mismatch` (return type vs function result, binary operand type
  disagreement, phi input unknown type, duplicate defs).
- `undefined_value` (operand id never defined — params and defs tracked in
  a `defined_ids` set, so gap ids are caught).
- `phi_arity` (operand count must equal 2 × predecessor count).
- `bad_operand_count` reserved for future arity tables.

## Audit fixes applied during verification

- Value defs are tracked in an explicit `defined_ids` set rather than
  inferring from vector size, so never-defined gap ids report
  `undefined_value` instead of aliasing `unknown` type.
- Binary operand type comparison now requires both operands to be defined.

## Evidence

- Debug MSVC build clean; `mute_ssa_unit` passes (valid module plus
  rejection of empty/missing-terminator/mid-block-terminator/undefined
  value/return-type/binary-type/phi-arity/duplicate-label/unreachable
  cases; deterministic `dump_ir`).
- Full Debug `mute_*` CTest: 33/33 pass. ASan `build-msvc-asan` `mute_*`
  suite run after this change.
- `tools/version` integration source list updated.

## Limits

- Dominance is approximated by layout order (def-before-use in block
  order), not a real dominator tree — conservative for the foundation;
  MUT-26 lowering must emit layout-consistent SSA or the verifier needs a
  dominator pass.
- Type checking is shallow (same_type equality, unknown detection); full
  trait/subtyping checks belong to lowering/verification milestones.
- No AST→SSA lowering exists yet; `IrModule` is currently only built by
  tests.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut26-progress

# MUT-26 progress — IR to bytecode emission + AST lowering

Status: foundation implemented and verified locally. Historical status: no gate was accepted at this milestone.

## Delivered

### Emitter (`mute/src/semantic/emit.cpp`, `mute/include/poko/mute/emit.hpp`)

`emit_bytecode(const IrModule&)` lowers verified SSA onto the register ISA:

- Runs `verify()` first; failures return diagnostics and emit nothing.
- Identity value-to-register mapping (<=255 registers), `copy` -> `mov`,
  unary -> `neg`, binary/compare -> reg-reg ALU, `jump`/`branch` ->
  `jmp`/`br_true`+`jmp`, `return_` -> `ret`.
- Phi lowering with critical-edge splitting: unconditional preds get inline
  moves; branch preds get trampoline blocks (moves + jump).
- Long branches: displacements beyond i16 automatically use the `ext_prefix`
  32-bit payload form.
- Typed errors: `unsupported_op`, `too_many_values`, `bad_phi_operand`,
  `too_many_functions`, `verify_failed`.

### Literal support

`Opcode::load_imm` (0x70), `li rX, imm` + i32 payload word, wired through the
bytecode codec (mnemonics, validator payload marking, assembler,
disassembler) and `run_register_vm`. `IrOp::constant` emits executable
immediate loads. i32 only.

### AST-to-SSA lowering (`mute/src/semantic/lower.cpp`, `mute/include/poko/mute/lower.hpp`)

`lower_function` converts a real `StatementAst` body + params into an
`IrFunction` that passes `verify()`:

- Statements: block, `let`/`var`, expression, `if`/`else` (env merge -> phi
  on actual predecessors), `while`, `for x in a..b` / `a..=b` (desugared to a
  counted loop with header phis), `loop`, `break`, `continue`, `return`.
- Assignments: `=`, `+=`, `-=`, `*=`, `/=`, `%=` rebind the env. Bitwise
  assign forms are diagnosed, not miscompiled.
- Expressions: int/bool/unit literals, identifiers, unary, binary incl.
  `land`/`lor` short-circuit.
- Loop-carried variables: `while`/`for` pre-assign a header phi per live
  name, so counters like `while x < 3 { x = x + 1; }` execute correctly.
- Actual block predecessor lists are populated in `finish()`.

### Verifier fix (`mute/src/semantic/ssa.cpp`)

Phi operands may reference defs later in linear layout order (loop back
edges); non-phi operands keep strict def-before-use.

## Verified

`mute_lower_unit` runs the full pipeline on real Mute source —
parse -> lower -> verify -> emit -> `run_register_vm`:

- `let x = 20 + 22; return x * 2;` -> 84
- if/else phi select -> correct both directions
- `loop { break; }` -> 7; `while` false -> 5; `while` counter -> 3
- `for i in 0..3 { s = s + i; }` -> 3; `0..=3` -> 6; empty range -> 9;
  `break` inside `for` -> 1
- unknown names rejected with diagnostics

Debug MSVC `mute_*` suite: 35/35. ASan subset (emit/lower/ssa/bytecode/
values): clean.

## Still open

- `match`/`guard` statements, function calls, member/index access,
  await/spawn lowering, floats/strings/aggregates, bitwise ops/assigns,
  break-value env merging, register spilling, hostcalls.
- `load_imm` is i32-only; i64/f64 literal pools are later work.
- `for` supports range iterables only; other iterables are diagnosed.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut27-progress

# MUT-27 progress — bytecode verification before execution

Status: implemented and verified locally. Historical status: no gate was accepted at this milestone.

## Delivered

`validate_bytecode` (`mute/src/bytecode/bytecode.cpp`) now rejects, before
any execution (it is called by `encode_bytecode`, `decode_bytecode`,
`assemble_bytecode`, `disassemble_bytecode` and `run_register_vm`):

- Empty instruction streams (`invalid_operands`).
- Programs whose last real instruction can fall through past the end of the
  stream — i.e. the final non-payload instruction must be `ret`, `halt`,
  `jump`, or an unconditional long jump (`ext_prefix` mode 1). Conditional
  branches, ALU ops, `move`, `li`, and conditional `ext` modes (2/3) as the
  last instruction are rejected (`invalid_operands`).

Already covered before this pass and re-verified: invalid/unknown opcodes,
operand-field violations (r0 writes, reserved operands), branch targets
out of bounds or into payload words, truncated payloads, oversize streams,
wire framing (header/version/length/trailing bytes).

Register operands are `uint8_t` so all indices are < 256 by construction;
destination-register writes to r0 were already rejected. No hostcall
opcodes exist in the ISA yet — unknown opcodes are rejected, and the typed
hostcall boundary itself is MUT-35.

## Bugs found and fixed while landing this milestone

- `run_register_vm` previously accepted empty streams and fall-off-end
  programs (they failed later as `no_return`); now rejected statically.
- The new terminator rule initially rejected legitimate programs ending in
  an unconditional `ext_prefix` long jump — caught by
  `mute_bytecode_vm_unit` and corrected.

## Verified

- Debug MSVC `mute_*`: 36/36 (incl. new `mute_fold_unit`).
- ASan `build-msvc-asan`: fold/lower/ssa/emit/bytecode_vm/values/package/
  scheduler/determinism all clean.

## Still open

- No reachability analysis (unreachable code is allowed; the VM simply
  never executes it).
- No hostcall opcodes or signature table yet (MUT-35).
- `.pkB` production format is separate work.

---

## mut28-progress

# MUT-28 progress — proven-safe constant folding

Status: implemented and verified locally. Historical status: no gate was accepted at this milestone.

## Delivered

`fold_constants(const IrModule&)` (`mute/include/poko/mute/fold.hpp`,
`mute/src/semantic/fold.cpp`, part of `poko_mute_semantic`) rewrites
`binary`/`unary`/`compare`/`copy` instructions whose operands are constants
defined earlier in the SAME block into `constant` instructions, preserving
value ids, result types and trap behavior:

- Arithmetic mirrors `run_register_vm` exactly: i64 intermediate, i32 range
  check, `div`/`mod` traps on zero divisor and `INT32_MIN / -1`.
- Operations that would trap or overflow are left unfolded, so the runtime
  reproduces the identical trap in the identical order (trap-order safe).
- Only same-block, def-before-use constants fold — no dominance reasoning
  required, so no miscompile across control-flow merges.
- Non-i32/bool scalar types, floats, strings and aggregates are untouched
  (none exist in the IR yet).

`mute_fold_unit` proves: folded and unoptimized runs agree on values;
`20 + 22 * 2` leaves zero binary/compare ops; `1/0`, `1%0`,
`2147483647+1` and negation overflow still trap identically at runtime;
a hand-built cross-block constant is NOT folded.

## Verifier upgrade required by this work

Landing `for`-loop lowering exposed that `verify()` used layout order as a
dominance approximation, rejecting valid backward-edge operands (the
`for.inc` block legitimately uses values defined in the if-join block that
appears later in layout). `verify()` now computes real dominators over
reachable blocks (iterative dataflow on actual terminator edges) and checks
operand defs by dominance + same-block order. Phi operands keep the relaxed
rule (any in-function def). This also fixes the whole class of
later-layout non-phi references.

## Bug fixed in lowering

The `if` merge emitted phi operands with value id 0 (register r0 = constant
0) for the no-`else` false edge, which reset loop variables each iteration
and caused an infinite loop (`budget_exceeded`) in
`for i in 0..4 { if i == 2 { break; } ... }`. The merge now resolves the
incoming value per actual predecessor (then fall-through, else
fall-through, or the branch block's false edge carrying the pre-if env).

## Verified

- Debug MSVC `mute_*`: 36/36.
- ASan subset: clean.

## Still open

- No cross-block/GVN/value-numbering folding, no algebraic simplification,
  no branch-on-constant folding (MUT-29/30 territory).
- `fold_constants` is a library pass; it is not yet wired into a single
  `compile()` pipeline entry point.
- Historical status: no gate was accepted at this milestone.

---

## mut29-progress

# MUT-29 progress — dead pure-code elimination

Status: implemented and verified locally. Historical status: no gate was accepted at this milestone.

## Delivered

`eliminate_dead_code(const IrModule&)` (`mute/include/poko/mute/optimize.hpp`,
`mute/src/semantic/optimize.cpp`, part of `poko_mute_semantic`) removes defs
of instructions that cannot trap or cause effects when their value is never
used, iterated to a fixpoint.

## Purity rules (trap-order safe)

- **Pure/removable**: `constant`, `copy`, `compare`, `phi`.
- **Never removed**: all arithmetic (`binary` add/sub/mul/div/mod, `unary`
  neg) — every ALU op can trap on i32 overflow or division by zero in this
  VM, so dead arithmetic is preserved to keep trap order identical.
- Terminators, `call`, `load`, `store` always kept.
- Liveness is computed **function-globally** (SSA values cross blocks via
  phis/branches) — a per-block analysis was tried first and incorrectly
  deleted cross-block defs; caught by `mute_optimize_unit`.

## Verified

`mute_optimize_unit` proves dead `let` bindings disappear while trapping
arithmetic (`1 + 2`) survives, used compares survive, and optimized vs
unoptimized runs agree on all pipeline test programs. Debug `mute_*` 37/37;
ASan subset clean.

## Still open

- No unreachable-block removal here (that is MUT-30's job).
- Side-effect-free but non-pure ops (e.g. provably non-trapping arithmetic
  on bounded constants) are conservatively kept.
- Historical status: no gate was accepted at this milestone.

---

## mut30-progress

# MUT-30 progress — proven-safe control-flow simplification

Status: implemented and verified locally. Historical status: no gate was accepted at this milestone.

## Delivered

`simplify_control_flow(const IrModule&)` (`mute/include/poko/mute/optimize.hpp`,
`mute/src/semantic/optimize.cpp`) does two things:

1. **Branch folding**: a `branch` whose condition is a `constant` defined
   earlier in the same block becomes an unconditional `jump` to the taken
   target. The formerly skipped arm is never evaluated — semantics
   preserved because the condition value is compile-time known.
2. **Unreachable-block removal + phi repair**: blocks left unreachable are
   dropped; all jump/branch targets, declared `preds` lists and phi
   predecessor operands (`imm = pred + 1`) are remapped/rebuilt. Phi
   operands belonging to eliminated predecessor edges are removed so
   arity still matches `2 × preds`.

## Bugs found and fixed while landing this

- Declared `preds` were only rebuilt when blocks were removed — but
  branch folding alone changes actual edges, so preds are now always
  rebuilt after the pass.
- Phi operands for eliminated predecessor edges are explicitly dropped
  (previously produced `phi_arity` verifier failures).

## Verified

`mute_optimize_unit`: `if 1 < 2 { return 11; } return 22;` folds the
compare, jumps directly, drops the dead arm block, verifies, and still
returns 11. Traps (`1/0`) preserved end-to-end. Debug `mute_*` 37/37;
ASan subset clean.

## Still open

- Only same-block-earlier constant conditions fold (no dominator-based
  constant propagation — conservative and safe).
- No jump threading, loop rotation, or branch-to-same-target merging.
- Historical status: no gate was accepted at this milestone.

---

## mut21-mut22-audit-2026-11-24

# MUT-21–22 audit — 2026-11-24

Scope: review of the MUT-21 package resolver and MUT-22 aggregate value
runtime added in `c7e951a`/values commit, plus regression coverage. MUT-01–20
were covered by the earlier `c7a411f` audit; this pass focused on the new
code and its interaction with the existing VM/store invariants.

## Defects found and fixed

### `AggregateStore` (values.cpp)

1. **Dangling `Object*` across allocation (crash).** `copy_impl` held
   `object(v)` and `object(result)` pointers while recursive child copies
   called `alloc` → `objects_.emplace_back` → vector reallocation. Fixed by
   snapshotting source items into a local `std::vector<Value>` before
   recursing, collecting copies locally, then allocating the destination and
   assigning items with no allocation in between. Reproduced as a segfault in
   `mute_values_unit` before the fix.
2. **Unbounded recursion in `copy`.** Deep or cyclic aggregate graphs could
   overflow the stack. `copy` now routes through `copy_impl(v, depth)` and
   traps `depth_exceeded` past `limits_.max_depth`; partial copies are
   released on error.
3. **Recursive `free_object`.** Converted to an explicit worklist stack so
   freeing deep graphs cannot overflow the call stack.
4. **Arena child inside heap parent (dangling handle).** `set_index` could
   insert an arena-resident aggregate into a promoted (heap) array;
   `reset_tick` would then free it leaving a dangling handle. `set_index`
   now promotes the inserted value when the parent is heap-resident.
5. **`reset_tick` leaked heap-child refs.** Arena parents holding heap
   children never released those refs. `reset_tick` now decrements
   heap-resident children's refs and frees orphans.
6. **Partial-copy leak on error.** `copy_impl` now releases completed
   sibling copies when a later child fails.

### `resolve_packages` (package.cpp)

7. **Unbounded input count.** Added `input_limit` diagnostic and a 4096
   module cap so DFS recursion and diagnostic volume stay finite.

## Regression coverage added

- Heap parent + arena child insert survives `reset_tick` (promotion on
  write).
- 12-deep nesting: `copy` and `promote` trap `depth_exceeded` instead of
  overflowing.
- `input_limit` path exercised via the new enum (cap logic reviewed; the
  4096-input case is covered by construction, not a dedicated fixture).

## Verification

- Debug MSVC build clean; `mute_values_unit` and `mute_package_unit` pass.
- Full Debug CTest: all tests pass (`version_integration` requires the full
  MSVC/SDK INCLUDE/LIB/PATH environment for its nested CMake configure — an
  environment quirk, not a regression; it passes with that env).
- ASan build (`build-msvc-asan`): all 30 `mute_*` tests pass, including
  `mute_values_unit`, `mute_package_unit`, goldens, `mute_g1_replay` and
  `mute_evaluator_reference`.

## Remaining limits — resolved in the follow-up pass (same day)

All four documented limits were fixed:

- **Borrowed `get_index`.** `Value` now carries an `owned` flag. `get_index`
  returns `owned=false`; `release()` ignores borrowed values, so a borrowed
  element can never corrupt a container's refcount. Owned values
  (`make_*`/`copy`/`promote`) must still be released exactly once.
- **Stale-handle aliasing.** Handles are now 64-bit
  `(generation << 32) | (slot + 1)`; every slot keeps a monotonic generation
  counter that survives frees. Recycled slots always fail `object()`
  validation → `invalid_handle`, never alias.
- **Cyclic aggregates.** `set_index` rejects insertions that would create a
  cycle (`reaches` DFS over array items, bounded by live object count) with
  the new `ValueErrorCode::cycle`. Self-insertion and mutual cycles are
  covered by tests.
- **Cycle-adjacent leaks.** With cycle formation rejected, the remaining
  leak path (unreachable cyclic garbage) is closed for new graphs; legacy
  leaks are bounded by store destruction.

Also fixed during the pass: `Object{}` resets were preserving-then-losing the
generation counter (caught by the new stale-handle test), and `promote`/
`copy_impl` no longer hold `Object*` across any allocation.

## Verification (follow-up pass)

- `mute_values_unit` extended: borrowed-release safety, generation-tagged
  stale-handle rejection, cycle/self-cycle rejection — all pass on Debug
  MSVC; full Debug CTest green (`version_integration` env quirk unchanged).
- ASan `build-msvc-asan` mute subset re-run after the rework.

## Still open (by design, not defects)

- `values` is not yet wired into `run_program`/bytecode; `package` has no
  registry/fetch/lockfile reader. Historical status: no gate was accepted by this audit; see the authoritative current status above.

---

## mut35-progress

# MUT-35 progress — versioned, typed hostcall boundary

## Delivered

- `poko/mute/hostcall.hpp` + `mute/src/vm/hostcall.cpp`: `HostcallTable` of
  versioned, typed `HostcallDef`s (id ≤255, signature version, i32/boolean/unit
  params and result, required capability mask, serializable flag, handler).
  `add()` rejects duplicates, out-of-range ids, version 0, unit params,
  unknown capability bits, missing handlers and oversized arity (>256).
- `Opcode::call_host = 0x44` (spec ordering: call=0x40, tailcall=0x41,
  ret=0x42, ret_void=0x43, call_host=0x44, … halt=0x4f) with `a`=id,
  `b`=arg-base register, `c`=return register (0 = discard). Wired through
  `validate_bytecode`, `disassemble_bytecode` (`call_host 7, r200, r3`) and
  `assemble_bytecode` round-trips.
- `VmEnvironment` on `run_register_vm` (new optional 4th parameter; existing
  callers unchanged): dispatch order is unknown-id (0x0A) → capability (0x0C)
  → signature (0x0B: ABI version, arg-window overflow, non-0/1 boolean args,
  unit-result-with-return-reg, out-of-range boolean result) → handler.
  Handler `HostcallError` traps `hostcall_failed` after dispatch.

## Verified

`mute_hostcall_unit` (new): registration rejections, arg-window dispatch,
discard/unit results, every pre-dispatch trap, capability denial before
dispatch, handler failure, codec goldens/round-trips. Full `ctest -R mute_`:
41/41 pass on Debug MSVC.

## Still open

- `call_host` is not yet emitted by `emit_bytecode` (IrOp::call remains
  `unsupported_op`); no `call`/`await`/`spawn` opcodes yet.
- Signatures are i32/bool/unit only until registers can hold Values.
- Historical status: no gate was accepted at this milestone.

---

## mut36-progress

# MUT-36 progress — runtime capability enforcement

## Delivered

- Canonical capability name↔bit table in `hostcall.hpp`
  (`capability_entries`, `capability_from_name`, `capability_name`);
  `determinism.cpp` now resolves `allow:` names through it (single source).
- `program_capability_mask(ast)` in `determinism.cpp`: the `allow:` ceiling
  as a mask (unknown names contribute no bits; `analyze_determinism` still
  reports them).
- `effective_capabilities(ceiling, host)` = intersection (narrowing) and
  `unauthorized_hostcalls(table, granted)` for bind-time rejection.
- `HostcallDef::serializable` + `VmEnvironment::serialized_run`: non-
  serializable hostcalls are denied with `capability_denied` during
  replay/snapshot verification but run normally live.

## Verified

`mute_capability_unit` (new): ceiling masks, narrowing, bind-time
unauthorized ids, missing-capability denial with handler-not-run proof,
serializable flag live-vs-replay behavior, @state token ban spot-check.
41/41 `ctest -R mute_` pass.

## Still open

- Per-function `requires(...)` narrowing is not modeled (no call frames yet).
- Capability tokens in serialized artifacts are prevented structurally
  (@state ban, i32-only state) rather than by a serializer-side check.
- Historical status: no gate was accepted at this milestone.

---

## mut37-progress

# MUT-37 progress — VM resource limits

## Delivered

- `VmRunState` + `VmEnvironment::{max_hostcalls=1000, max_call_depth=64,
  state}`: shared per-run accounting that also bounds host-mediated VM
  recursion (a hostcall handler re-entering `run_register_vm`).
- New traps: `call_depth_exceeded` (spec 0x02-class, depth-64 boundary) and
  `hostcall_quota` (spec 1,000 hostcalls/tick) with RAII depth restore on
  every exit path; quota charged only on actual dispatch.
- Instruction-budget hard cap raised 100k → 1M to match the approved v1
  spec default (1M instructions/tick); `bytecode_vm_test` boundary updated.
- Heap quotas remain in `AggregateStore` (64 MiB / 65,536 objects, MUT-22),
  already covered by `mute_values_unit`; register count is structurally 256.

## Verified

`mute_limits_unit` (new): budget cap boundary, instruction-budget trap,
hostcall quota at exactly max dispatches, shared-state accumulation,
depth-64 boundary, nested-run depth sharing/restore, untracked-run fallback.
41/41 `ctest -R mute_` pass.

## Still open

- `Opcode::call` does not exist yet, so call-depth currently bounds only
  host-mediated recursion; wire the same counter when calls land.
- Heap quota is per-store, not per-VM-frame; unified accounting is later work.
- Historical status: no gate was accepted at this milestone.

---

## mut33-progress

# MUT-33 progress — source mappings and useful diagnostics

## Delivered

- `IrInstr::pos` / `IrDiagnostic::pos` (ssa.hpp): every lowered instruction
  and diagnostic carries a `Position` (byte/line/column).
- `lower.cpp` threads positions: `pos_` tracks the current AST node in
  `eval_node`/`stmt`; `emit`/`term`/`emit_into` fill `in.pos` only when
  unset so explicit node positions win; `diag()` stamps diagnostics.
- `emit.cpp` builds a pc→Position map into `EmitResult::positions`
  (parallel to `functions`, one entry per emitted word). ALU/constant/
  copy words carry their IR instruction's position; phi-move words carry
  the phi's position; trampoline moves carry the phi position and the
  trampoline jump carries the originating conditional branch's position;
  ext_prefix payload words share their branch's position.
- `source_position(result, fn, pc)` lookup: exact pc, else nearest earlier
  known position, else unset (`Position{}`, line 0).
- Diagnostics carry positions end-to-end: `verify()` stamps
  `IrDiagnostic::pos` from the offending instruction/terminator;
  `EmitError::pos` is set for `unsupported_op` (call/load/store and
  out-of-range constants).
- Optimizer coverage is structural: `fold_constants`,
  `simplify_control_flow` and `eliminate_dead_code` mutate/copy
  `IrInstr`s in place, so positions survive optimization.

## Verified

`mute_emit_unit` extended: per-word map sizing, phi-move/terminator
positions, out-of-range lookups, a runtime `divide_by_zero` trap mapping
back to the division's source position through both the baseline and the
fold+DCE+control-flow pipeline, lower-diagnostic byte-offset assertions,
and verify/emit diagnostic position propagation. `mute_lower_unit`,
`mute_ssa_unit` still pass; Debug MSVC build clean.

## Still open

- Positions are byte/line/column only — no source-file identity yet
  (single-file lowering today).
- `Opcode::call`/`load`/`store` still unsupported in emit; debugger
  integration is MUT-34.
- Gate (MUT-33 row) not formally accepted; see work queue.

---

## mut34-progress

# MUT-34 progress — debugger breakpoints and stepping

## Delivered

- `VmCore` (`mute/src/vm/vm_core.{hpp,cpp}`): the register-VM loop extracted
  into a steppable core — `step()` executes exactly one instruction
  (long-form payload words count as part of their instruction), exposing
  `pc()`, `last_pc()`, `steps()` and the live register file. `run_register_vm`
  is now a thin driver over it, so trap/budget/hostcall/capability semantics
  are literally the same code path.
- `VmDebugger` (`mute/include/poko/mute/debugger.hpp` +
  `mute/src/vm/debugger.cpp`): owns its own register copy (caller arrays are
  never touched), pc breakpoints (`add/remove/has/clear`), `step()` (one
  instruction; ignores breakpoints for that instruction), `run()` (until
  breakpoint/return/trap), register and stack inspection
  (`registers()`, `pc()`, `last_pc()`, `steps()`, `stack()`).
- Debugging cannot mutate validated sim state: the debugger executes the
  same bytecode with the same `VmEnvironment` quotas on private registers;
  `@state` commit semantics live above this layer and are untouched.

## Verified

`mute_debugger_unit` (new): entry/step inspection, mid-run and ret
breakpoints, trap surfacing with trapping pc, step-over-breakpoint,
caller-state immutability, result equality with `run_register_vm`, budget
and invalid-bytecode traps. Full `ctest -R mute_`: 42/42 pass on Debug
MSVC — the VmCore refactor is regression-clean across bytecode_vm,
limits, hostcall, capability, program and scheduler tests.

## Still open

- No `Opcode::call` yet, so `stack()` reports the single live frame;
  source-level (line/column) breakpoints need a Position→pc index over
  `EmitResult::positions` (MUT-33 map exists; wiring is later work).
- No watchpoints, no reverse execution, no multi-function debug info.
- Gate (MUT-34 row) not formally accepted; see work queue.

---

## mut31-progress

# MUT-31 progress — differential-test optimized and baseline programs

## Delivered

- `mute/tests/unit/diff_test.cpp` (`mute_diff_unit`): compiles a pinned
  corpus of Mute sources through parse -> lower -> verify -> emit twice —
  baseline and the MUT-28/29/30 pipeline (fold_constants ->
  simplify_control_flow -> eliminate_dead_code) — then runs both on
  `run_register_vm` and compares observable results.
- Corpus (24 cases): constants/arithmetic, if/else phis, while/for loops,
  break/continue, &&/|| short-circuit, unary, dead lets, constant branches
  (both taken and dead arms), div/mod-by-zero, add/neg overflow traps,
  traps after loops, shared subexpressions.
- Comparison contract: identical i32 result, or identical `VmErrorCode`
  (pc may legitimately differ between layouts). For real traps
  (divide_by_zero, overflow) the MUT-33 `source_position` maps of both
  runs must resolve to the same source Position — optimized traps still
  identify the same source construct.
- Budget semantics documented: a shared tiny budget case asserts both
  sides report `budget_exceeded`; instruction-count differences after
  optimization are expected and not asserted equal. Optimized emission
  size must never exceed baseline on the corpus.

## Verified

`mute_diff_unit` passes on Debug MSVC. Hostcall-order and serialized-state
coverage is NOT yet possible: `emit_bytecode` still rejects `IrOp::call`,
so no corpus program can dispatch hostcalls (MUT-35 open). State snapshots
are covered separately by `mute_snapshot_unit`.

## Still open

- Hostcall order/trap coverage awaits IR-level `call`/`call_host`
  emission; float/string/aggregate corpus entries await those types.
- Gate (MUT-31 row) not formally accepted; see work queue.

---

## mut32-progress

# MUT-32 progress — optimizer benchmark and reporting harness

## Delivered

- `mute/tests/unit/bench_test.cpp` (`mute_optbench_unit`): pinned
  workloads (loop-sum, for-heavy, branchy, dead-heavy, phi-merge) compiled
  baseline and optimized, executed 5x each on `run_register_vm` with a
  1M-instruction budget; reports per-workload instruction counts and
  best-of-5 wall times.
- Regression detection: fails on optimized code-size growth over baseline,
  result divergence, or >2x best-time slowdown (deliberately loose for
  debug-build noise). Times are reported only — no speedup is claimed.
- Nested `for` and if-in-`else` initially failed `verify()` — root cause
  was `duplicate_label` (nested control flow reusing block labels), fixed
  in lower.cpp via deterministic `.N` suffixes; regression cases added to
  `mute_lower_unit`, the diff corpus and the bench workloads.

## Verified

`mute_optbench_unit` passes; sample report shows dead-heavy 42->24 instrs
and ~1.7x best-time improvement, loop workloads neutral — consistent with
DCE/control-flow only removing provably dead work.

## Still open

- No Release-mode numbers yet; pinned corpus should grow with the ISA
  (calls, floats, aggregates) as those land.
- Gate (MUT-32 row) not formally accepted; see work queue.

---

## mut34-followup

# MUT-34 follow-up — source-level breakpoint lookup

- `source_pcs(result, fn, pos)` in emit.hpp/emit.cpp: returns every pc in
  an emitted function whose recorded source position exactly matches a
  `Position` — the bridge from MUT-33's map to source-level breakpoints
  (`VmDebugger::add_breakpoint` takes pcs).
- `mute_emit_unit` covers hit/miss/consistency; `mute_debugger_unit` still
  green. Multi-frame stacks still await `Opcode::call`.

---

## mut35-37-closure

# MUT-35/36/37 closure — gates locked 2026-11-25

Done-when review against the test suite (all `ctest -R mute_` 44/44):

- **MUT-35** — `mute_hostcall_unit`: valid dispatch, arg-window capture,
  unit/discard results, unknown-id/null-env/abi/signature traps before
  dispatch. Gate met; IR emission of `call_host` remains future work.
- **MUT-36** — `mute_capability_unit`: allow-ceiling masks, narrowing,
  bind-time unauthorized ids, missing-capability denial with
  handler-not-run proof, serialized-run denial. Gate met;
  per-function `requires()` awaits call frames.
- **MUT-37** — `mute_limits_unit` + `mute_values_unit`: 1M/tick budget
  cap and `budget_exceeded`, 1,000 hostcalls/tick `hostcall_quota`,
  depth-64 `call_depth_exceeded` with RAII restore, AggregateStore heap
  quotas. Gate met; `Opcode::call` still absent.

---

## mut-call-plan

# Function calls — implementation plan (MUT-31..37 closure path)

Facts established 2026-11-25:

- Parser already emits `ExprKind::call` nodes: `left` = callee expr index,
  `children` = argument expr indices (`parser.cpp` ~L311). No grammar work.
- `lower.cpp eval_node` hits `default:` -> `type_mismatch` diagnostic for
  calls today. `lower_function` lowers ONE function body; calls need
  module-level context (callee name -> signature/index).
- `IrInstr` has no function-reference field; `IrOp::call` exists in the
  enum but emit rejects it (`unsupported_op`) and verify has no call rules.
- VM: `Opcode` has no call/ret; `VmCore` is single-frame flat r[256];
  `VmDebugger::stack()` assumes one frame; MUT-37 depth bound currently
  covers only host-mediated recursion.

Ordered slices (each independently testable):

1. IR: add function reference to call instrs (e.g. `IrFunction::functions`
   index via new field or `detail`+name table); verify call arg count/types
   against callee signature.
2. Lower: `lower_module` (or extended `lower_function`) taking a function
   signature table; eval_node `ExprKind::call` -> evaluate args, emit
   `IrOp::call`.
3. Emit: calling convention — args into consecutive regs, `Opcode::call`
   with function index + return reg; frame model decision (register
   windows vs spill slots) — biggest design choice, affects VM + debugger.
4. VM: `Opcode::call`/`ret` + frame stack in `VmCore`; wire MUT-37
   max_call_depth to real calls; `VmDebugger::stack()` reports frames.
5. `call_host` emission: hostcall defs -> `Opcode::call_host` sequences.
6. Tests: call round-trips, recursion vs depth-64, arg/return marshalling,
   diff-corpus entries with calls, debugger multi-frame inspection,
   MUT-36 `requires()` narrowing once frames exist.

---

## mut-call-slice1

# Function calls — slice 1 landed (IR call verification)

- `IrInstr::callee` (ssa.hpp): `IrOp::call` instructions reference
  `IrModule::functions` by index+1.
- `verify()` (ssa.cpp) now checks calls: callee in range, arg count ==
  callee param count, per-arg type match, result type == callee result —
  all reported with `IrDiagnostic::pos`.
- emit still rejects `IrOp::call` as `unsupported_op` (unchanged); emit
  tests updated to use verify-valid self-calls.
- Verified: `mute_ssa_unit`, `mute_emit_unit`, `mute_diff_unit` pass.

Next slices per `mut-call-plan` above: lowering (`ExprKind::call` ->
`IrOp::call`, needs module-level signature context), emit calling
convention + frame model, VM `Opcode::call`/`ret` + frame stack,
`call_host` emission, then MUT-31/34/36/37 residual coverage.

---

## mut-call-slice2-design

# Slice 2 design notes (lowering calls) — captured before context reset

Established facts:

- `DeclarationAst`: `fn_decl` nodes carry `spelling` (name), `type` (index
  into `types()` = return TypeNode), `children` (param decl nodes),
  `body` (index into `bodies()` = StatementAst). `TypeNode` has
  kind/spelling/args; semantic.cpp already converts TypeNode->Type
  (Analyzer::convert_type ~L110) — reuse or factor it out.
- Parser emits `ExprKind::call`: `left` = callee expr node index,
  `children` = arg expr node indices (parser.cpp ~L311).
- `IrInstr::callee` = IrModule::functions index + 1; verify() already
  checks arity/types/result for IrOp::call.

Minimal API proposal:

```cpp
struct LowerSignature { std::string name; std::vector<Type> params; Type result; };
// sigs[i] MUST correspond to IrModule::functions[i]; self-recursion works
// because the function's own sig is in the table.
LowerResult lower_function_ex(
    const StatementAst& body, std::string_view name, const Type& result,
    std::span<const LowerParam> params,
    std::span<const LowerSignature> sigs);
```

`lower_function` keeps its signature and delegates with an empty table
(calls then diagnose `undefined_value`/unsupported as today).

Lowerer changes: store `sigs_` + build `name -> index` map. In
`eval_node`, `ExprKind::call`: callee node must be `ExprKind::identifier`
(resolved via sigs; unknown -> `undefined_value` diag); eval each child
arg; emit `IrOp::call` with `callee=index+1`, `args`=arg value ids,
`def`=fresh id, `result`=sig.result; return `{id,sig.result}`.

Module driver (later or same slice): a `lower_module(const DeclarationAst&)`
that walks fn_decl nodes, converts TypeNodes, lowers each body with the
full sig table, returns IrModule + diagnostics — this is what tests and
the compiler frontend will call.

---

## mut-call-slices2-6

# Function calls — slices 2, 3, 4, 5 and 6 landed (2026-11-25)

## Slice 2 — lowering with a signature table

- `LowerSignature`/`LowerModuleResult` and `lower_function_ex`/`lower_module`
  (`poko/mute/lower.hpp`, `mute/src/semantic/lower.cpp`): the module driver
  builds one signature entry per `fn_decl` before lowering any body, so
  forward references, self recursion and mutual recursion all resolve.
- `eval_node(ExprKind::call)` requires an identifier callee, checks arity,
  evaluates arguments left to right, and emits `IrOp::call` with
  `callee = signature index + 1`, the argument value ids and a fresh result
  def. Unknown callees and bad arity are typed diagnostics. One IR function
  is emitted per signature even when a body fails, so callee indices remain
  aligned.
- `@requires(...)` is parsed into each function's capability mask,
  intersected with the program's `allow:` ceiling (`program_capability_mask`).
  Functions without the attribute keep `0x3FF`.

## Slice 4 — VM frames (landed before emit, fixing the calling convention)

- `Opcode::call/ret` (`0x40`/`0x42`) are wired through validation,
  encoding/decoding, assembly and disassembly. `call a,b,c` names a function
  index, an argument-window base and a destination register.
- `VmCore` keeps a frame stack (code span, return pc, destination register,
  capability mask, full 256-register file). A call copies only the 32-register
  staging window into a fresh frame; `ret` restores the caller and binds the
  result. `run_register_module` is the module entry point;
  `VmEnvironment::max_call_depth` now bounds real frames as well as nested
  host-mediated runs, with depth restored on every exit.
- `VmDebugger` has a module-aware constructor and `stack()` reports one entry
  per live frame (suspended return pcs, then the current pc).

## Slice 3 — emit

- `IrOp::call` stages arguments into registers 224..255, emits `call`, and the
  callee prologue moves the window into params 1..N. `ret` carries the IR
  return value. Branch trampolines, phi moves and source positions still work
  across calls.
- Defect fixed while closing coverage: a call with more than 32 arguments
  wrapped the `uint8_t` staging index and wrote r0/r1. `emit_bytecode` now
  rejects oversized call/hostcall argument lists with `too_many_values`.

## Slice 5 — `call_host` emission from IR

- `IrHostcall` entries map IR `call_host` instructions to registered hostcall
  ids. The emitter stages arguments in the same window, emits
  `call_host id, r224, dest`, and discards the result for unit/no-def calls.
  `verify()` checks hostcall callee index, arity, argument types and result
  type; `EmitResult::capabilities` runs parallel to emitted functions for
  per-frame narrowing.
- `mute_emit_unit` builds a real IR module, checks the emitted operand layout
  and source position, dispatches through a `HostcallTable`, and proves a
  missing grant traps before the handler runs.

## Slice 6 — coverage

- `mute_lower_unit`: module calls, nested calls, recursion, mutual recursion,
  unknown callees and `@requires` mask narrowing.
- `mute_diff_unit`: four call corpus entries (direct, nested, recursive,
  mutual) compared baseline vs optimized, including emitted size.
- `mute_limits_unit`: real recursion at limits 10/11 and at the spec depth-64
  boundary (63 nested calls pass, the 64th traps), with depth restored after
  both success and trap.
- `mute_debugger_unit`: breakpoint in a callee, two-frame `stack()`, register
  save/restore across `ret`, and final result.
- `mute_capability_unit`: per-frame `requires()` narrowing at runtime —
  callee mask, caller mask and host grant must all allow the hostcall.

Verified: full Debug MSVC `ctest -R mute_` 44/44; ASan subset
(emit/lower/diff/limits/debugger/capability/ssa/bytecode_vm) 8/8. The ASan
build's pre-existing `/EHsc` warnings remain; no sanitizer errors.

## Remaining

- No source-level hostcall syntax: `call_host` is emitted from hand-built IR
  only, so the differential corpus covers calls but not hostcall ordering.
- No cross-module calls, register spilling, or calls with aggregate values.
- Historical status: no gate was accepted at this milestone; see the authoritative current status above.

---

## mut38-progress

# MUT-38 — deterministic input snapshots (2026-11-25)

## Implemented

- `poko/mute/input_snapshot.hpp` + `mute/src/input/input_snapshot.cpp`
  (`poko_mute_input`): a flat, tick-tagged `InputTimeline` records key,
  mouse button, motion, wheel, resize, quit and focus events in arrival
  order. `InputReplay` yields each recorded tick's events; `InputState`
  applies them deterministically. `focus_lost` clears all held keys/buttons
  and suspends motion/wheel accumulation until `focus_gained`, so a replay
  cannot inherit stuck input across a focus change.
- `InputTimeline::snapshot_hash(tick, state)` hashes the tick, post-event
  input state and exact event sequence using the shared `xxhash64`, so
  record/replay equality is checkable per tick and event reordering is
  observable. Canonical binary `encode`/`decode` uses a strict "MUTI" v1
  format (32-byte records) with monotonic-tick, count and trailing-byte
  validation.
- The host adapter converts native events (SDL/`platform::Event`) to
  `InputEvent`; nothing in this library reads the clock or an OS event
  queue, so recorded replays do not depend on device timing or driver
  ordering.

## Verified

- `mute_input_unit` (`mute/tests/unit/input_snapshot_test.cpp`): held-key
  and button tracking, focus-loss clear/suspend/resume, tick grouping,
  monotonicity and bound, strict event validation, encode/decode roundtrip
  and six corruption classes, two identical replays with equal per-tick
  hashes, order-sensitive snapshot hashing, and an ENG-30 integration run
  where the same 12 deltas drive the fixed-step clock during record and
  replay (13 ticks including a clamped 5 s stall) with identical hashes.
- Full Debug MSVC `ctest`: **90/90**, including `version_integration`.
  `mute_input_unit` under ASan: **1/1**, no sanitizer errors.
- Queue decision: ENG-31 (jobs) was skipped — it is only a transitive
  prerequisite of MUT-43/44 via ENG-32/33; the next MUT tasks do not need
  it. MUT-38 now builds on ENG-30's fixed-step clock.

## Remaining at this milestone

- No Mute-specific SDL/console event adapter is wired here: hosts and tests
  construct `InputEvent`s directly. ENG-02 window/platform evidence is
  separate from this event bridge.
- Key-name/action mapping and canonical `encode`/`decode` landed later in
  MUT-39/MUT-40. On-disk settings persistence and a script-facing hostcall
  wrapper remain deferred.
- G1 and ENG-02 were accepted later on the approved two-target matrix. See
  the authoritative current status above; G2 remains deferred to ENG-60→63.

# MUT-39 — actions and rebindable key bindings (2026-11-25)

## Implemented

- `poko/mute/action_map.hpp` + `mute/src/input/action_map.cpp`
  (`poko_mute_action`): named actions are defined in stable declaration order
  and bound to keyboard keys, mouse buttons/wheel, gamepad buttons/axes or
  touch taps. `replace_binding`/`set_bindings`/`clear_bindings` rebind without
  changing action names; `bindings_conflict` reports exact digital collisions
  and overlapping same-direction axis windows. The map stays unmutated when
  conflicts are reported so a host can persist an in-progress rebind.
- `ActionSampler` produces one `ActionFrame` per tick with `held`, `pressed`,
  `released` and signed `value` reads by name. It keeps only the previous
  tick's held bits; empty ticks must be sampled so edges stay aligned. The
  first matching binding in declaration order supplies an action's value, and
  `ActionFrame::hash()` covers names plus samples for replay comparison.
- `InputState`/`InputTimeline` gained minimal gamepad-button, gamepad-axis and
  touch-tap sources for MUT-39 bindings. They reuse the existing 32-byte
  `MUTI` v1 record payload; focus loss clears them and suspends later events
  just like keys and mouse buttons. Device connect/disconnect and gestures
  remain MUT-40.
- `ActionMap::encode`/`decode` uses a strict canonical `"MUTA"` v1 format
  (action order, binding order, u8 name length, 7-byte bindings) with name,
  binding, version, truncation and trailing-byte validation. No disk adapter
  is included; persistence is byte-format only, matching MUT-38.

## Verified

- `mute_action_unit` (`mute/tests/unit/action_map_test.cpp`): validation,
  rebind and conflict policy, canonical persistence and corruption classes,
  per-tick digital/axis/wheel edge behavior, rebinding observability, and a
  decoded-map replay over the ENG-30 fixed clock with identical action hashes
  across 13 ticks including a clamped 5 s stall.
- `mute_input_unit` was extended for gamepad/touch state, focus clearing,
  strict event validation and `MUTI` v1 roundtrip of the new source kinds.
- Full Debug MSVC `ctest`: **91/91**, including `version_integration`.
  `mute_input_unit` and `mute_action_unit` under ASan: **2/2**, no sanitizer
  errors. The version integration fixture list was updated for the new files.

## Remaining at this milestone

- No Mute-specific SDL/native host adapter or on-disk settings file: hosts and
  tests construct events and call `encode`/`decode` directly. ENG-02 window
  evidence was collected separately.
- No script-facing hostcall wrapper for named actions; scripts can consume a
  host-provided integer action id once the host registers it. That bridge is
  still deferred.
- MUT-40 device routing landed later and passed on Windows and the physical
  Android device. G1 and ENG-02 were accepted later; G2 remains deferred to
  ENG-60→63. See the authoritative current status above.

# G1 replay gate — two-target evidence (2026-11-25)

- Owner decision removed Linux x64 as a gate target and approved
  `mute/tests/fixtures/g1-replay.mute` as the G1 scenario. The two targets are
  Windows x64 and a physical Android arm64 device.
- `tools/targets/run_dual_target_tests.py` runs the Windows MSVC/Ninja suite
  and an NDK-built Android unit set concurrently through adb, then compares
  the complete 10,000-tick G1 traces byte-for-byte after LF normalization.
- Verified: Windows `ctest` 91/91; Android 7/7 Mute binaries on the Xiaomi
  `24117RN76G`; both traces are 10,000 lines with SHA-256
  `a274e74dab510f615686a4ff2600fdd793309a3cedeab840ddf87a31a0ddad68` and
  are byte-identical. Details in `../two-target-gate-evidence-2026-11-25.md`.
- G1 is accepted for the approved two-target scope. G2 remains explicitly
  deferred to the canonical ENG-60→63 physics chain; no shortcut probe was
  accepted.

# MUT-40 — approved pointer, gamepad and touch inputs (2026-11-25)

## Implemented

- `poko/mute/device_router.hpp/.cpp` provides deterministic device mapping.
  Keyboard and mouse are fixed slot-0 sources; gamepads and touch displays get
  the lowest free stable slot. Native device handles stay host-side. Only the
  stable slot and `device_connected`/`device_disconnected` events enter the
  MUT-38 timeline, so replay does not depend on OS device ids.
- Gamepad and touch event codes pack slot and control into the existing 16-bit
  `code` field. Slot 0 keeps the MUT-38/MUT-39 byte layout unchanged.
  `InputState` now tracks per-slot gamepad buttons/axes, per-display touch
  contacts and connected-device masks; disconnects clear only that device,
  and focus loss clears held state without disconnecting devices.
- MUT-39 action bindings can target a slot by packing it into `Binding::code`.
  Conflicts are slot-sensitive: the same button on two gamepads is allowed;
  the same button on one gamepad is still a conflict. MUTA v1 binding bytes
  are unchanged.
- Touch support remains tap-only, as approved. Gestures beyond tap stay
  deferred.

## Verified

- `mute_device_unit` covers packed codes, slot-scoped gamepad and touch state,
  deterministic lowest-free-slot routing, duplicate native ids,
  connect/disconnect event generation, slot-sensitive action bindings,
  disconnect edges and byte-identical replay.
- Full Debug MSVC `ctest`: **92/92**, including `version_integration`.
  ASan input/action/device subset: **3/3**.
- The dual-target runner now also builds and runs `device_router_test` on the
  Xiaomi `24117RN76G`: **8/8 Android Mute binaries** pass, and the paired
  Windows run remains byte-identical on the G1 trace.
- `tools/version/tests/integration/test_version.py` and the dual-target
  runner source list include the new device-router files.

## Remaining

- No native SDL/AGDK adapter is bundled here; hosts still translate native
  events into MUT-38 `InputEvent`s.
- Device-map persistence to disk is not added; replay persistence is covered
  by the timeline's connect/disconnect events.
- Historical status: no gate was accepted by this milestone; G2 remains deferred to ENG-60→63 under the current status above.

# MUT-51–55 — v1 standard API core and build tool (2026-11-25)

## Implemented

- **MUT-51:** `poko_mute_stdlib_math` adds pinned scalar math, `Vec2/3/4`,
  `Mat4`, `Quat`, serializable `XorShift128Plus`, a tick-only `SimClock` and
  Time hostcall definitions (ids 201–203). Wall-clock builtins are now always
  rejected by the determinism analyzer; `tick()`, `dt()` and `simNow()` are
  the approved Time surface.
- **MUT-52:** `poko_mute_stdlib_collections` adds canonical UTF-8 validation,
  codepoint count/slicing, concat/compare/find/ASCII-lower, bounded
  `ByteArray` and sorted `OrderedStringMap` with canonical dump/hash.
- **MUT-53:** `poko_mute_stdlib_crypto` adds fixed SHA-256, HMAC-SHA256,
  hex conversion and detached HMAC sign/verify with constant-time comparison.
  `Crypto` hostcall descriptors are bind-time validated. Asymmetric publisher
  signatures remain a backend concern.
- **MUT-54:** `poko_mute_events` adds a tick-tagged, bounded FIFO event bus
  with startup/simulation/teardown phases, deterministic subscription order,
  unsubscribe/clear and replay hashes.
- **MUT-55:** `poko_mute_build_tool` plus `poko_mute_build` parse `mute.toml`,
  resolve local sources, require an exact canonical `mute.lock` match and
  print a deterministic build plan. Fixture:
  `mute/tests/fixtures/mut55_sample`.

## Verified

- Full Debug MSVC `ctest`: **98/98**, including `version_integration`.
- ASan subset (stdlib math/collections/crypto, events, build tool,
  determinism): **6/6**.
- Dual-target runner: **12/12** Android Mute binaries on the Xiaomi
  `24117RN76G`; byte-identical G1 traces remain intact;
  `all_tests_ok: true`.
- Contract docs: `mute/V1-API.md` and `mute/BUILD-TOOL.md`. Version fixture
  and dual-target source lists include the new files.

## Remaining

- Host-side libraries only: no Mute-source syntax, VM string/byte-buffer
  hostcalls or native SDL/AGDK adapters in this slice.
- No registry/fetch/publishing, on-disk settings adapter or script-facing
  action hostcall.
- No gate accepted by this slice. G2 remains deferred to ENG-60→63.
