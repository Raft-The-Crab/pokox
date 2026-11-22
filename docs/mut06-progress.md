# MUT-06 — initial functions and locals

This is the MUT-06 historical snapshot. Subsequent conditional and loop support is documented in `mut07-progress.md`.

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

Unit coverage includes factorial, Fibonacci, mutual recursion, scope/shadowing, reassignment, argument counts, unknown names, missing returns, immutable locals, overflow, divide-by-zero, source/nesting/call/budget traps and deterministic malformed-input exercises. Strict GCC and ASan/UBSan suites each passed 56/56; the software-Vulkan suite passed 79/79 on rerun. An interactive X11 check compared the recursion result to a known `i32: 120` result. One prior graphics run hit an intermittent cube-golden X11 capture failure; see the MUT-01–05 audit. Passing the local recursion criterion does not establish general Mute language compatibility, production safety, performance or Windows/Android/physical-GPU behavior. Those checks and the inherited determinism/platform gates remain open.
