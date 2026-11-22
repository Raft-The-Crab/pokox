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
