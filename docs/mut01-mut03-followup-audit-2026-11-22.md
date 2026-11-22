# MUT-01–03 follow-up fixes and audit (2026-11-22)

## Scope and result

Follow-up to `mut01-mut03-audit-2026-11-22.md`. Reviewed lexer → parser → evaluator integration, limits, numeric contracts, FP environment, tests, documentation, and archive layout. This is not a whole-engine audit or a proof of defect-free execution. Earlier ENG/INF gates still apply.

## Fixed or improved

1. **Float remainder implemented.** f32/f64 `%` uses `std::fmod`, with dividend-sign and signed-zero behavior, and rejects zero divisors. Finite inputs/results and the existing floating-environment checks apply. The independent bit-pattern test now includes generated `%` cases; targeted tests cover both types, negative operands, signed zero, subnormal results and zero divisors. Library and conversion equivalence across platforms is **not proven**.
2. **Bounded source input.** The lexer rejects inputs above 1 MiB by default *before* UTF-8 validation or allocations; the parser forwards the configurable `LexOptions`. Exact-limit, zero-limit, override and error-precedence cases are tested. This bounds the size of the input to lexer/parser, but is not a precise total-memory or CPU sandbox and is adjustable by callers.
3. **Optional host-provided numeric bindings.** Identifiers can resolve from a borrowed, read-only span, with exact names, duplicate/empty name rejection, checked referenced value representation/range, type checks and configurable count/name-byte limits. Names are sorted and looked up without mutable global state. Tests cover repeated use, inference, missing/duplicate/invalid/range/type errors, limits, f32 and non-finite values. No language declarations, scope, mutation, functions or locals are claimed; MUT-06 remains separate. Lex/parser/evaluator public C++ signatures changed: consumers should rebuild against the new headers.
4. **FP trap audit.** A signaling-NaN binding is rejected while x86 invalid-operation traps are unmasked; the exact SSE state is restored in the local test. This supplements, not replaces, the earlier overflow trap test. On a broken host, failure of floating environment setup/restoration still cannot guarantee restoration.

## Still open / not safely closable here

- **Cross-platform determinism and validation:** decimal conversion, `%`/other float behavior and floating-environment handling require actual Windows x64, Android arm64 and 10,000-tick cross-platform replay. This machine cannot establish those results. `std::fmod` alone is not a determinism proof. Hosted CI/MSVC/MinGW, Android and physical-device checks remain unverified; no acceptance gate is waived.
- **Numeric semantics:** unsigned unary minus remains deliberately rejected, signed division/remainder overflow and underflow policy remain provisional because the language design does not settle them. No claim that every future numeric semantic is finalized.
- **Sandbox:** source and binding limits plus evaluator node cap are not a VM instruction budget, strict total heap quota, or full denial-of-service defense. Allocation failures may propagate; caller must enforce suitable budgets/isolation. Future MUT-07/VM work remains needed.
- **Graphics build/tooling warnings:** previous full graphics configuration produced upstream CMake deprecations and Xvfb reported nonfatal keyboard-map warnings. No dependency versions or CI platform were changed merely to hide warnings. Graphify may omit unsupported files and stale community labels mean it is not exhaustive.

## Verification

- Final strict Linux/GCC suite: **54/54** CTest entries, strict C++ compiler warnings treated as errors.
- ASan/UBSan with leak detection: **54/54** entries; software Vulkan/Xvfb suite: **70/70** entries. Software emulation is not a physical GPU or cross-platform test.
- Exhaustive integer audit: all **655,360** signed and unsigned 8-bit operand/operator combinations. Randomized independent references: 600 i32 expressions, 500 typed integer boundary cases and 400 bounded f32/f64 comparisons including `%`. These do not prove all inputs or platforms.
- Clean extracted archive rebuilt and tested separately; see delivery verification log. Existing `.git` bytes in the original archive are preserved. Graph is a navigation aid, not an exhaustive audit.
