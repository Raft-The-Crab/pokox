# MUT-26 — emit bytecode from IR (foundation)

Status: IR→register-bytecode emitter implemented and execution-tested
locally; AST→SSA lowering, literal pool, calls and hosted/target gates
remain open.

## What was added

- `mute/include/poko/mute/emit.hpp` and `mute/src/semantic/emit.cpp`:
  `emit_bytecode(const IrModule&)` lowers a verified `IrModule` onto the
  experimental register ISA (`poko/mute/bytecode.hpp`), one `Bytecode` per
  function.
- `IrInstr` gained a `detail` sub-op field (binary 0–4 = add/sub/mul/div/mod,
  unary 0 = neg, compare 0–5 = eq/ne/lt/le/gt/ge) and phi operands carry
  `imm = predecessor block index + 1` so edge moves are self-describing.
- `mute/tests/unit/emit_test.cpp` registered as CTest `mute_emit_unit`.

## Emission rules

- Runs `verify()` first; verification failures return the `IrDiagnostic`s
  and emit nothing.
- Value ids map to registers by identity (params occupy 1..N); ids above 255
  are `too_many_values`.
- `copy`→`mov`, `unary`→`neg`, `binary`/`compare`→reg-reg ALU ops,
  `jump`/`branch`→`jmp`/`br_true`+`jmp`, `return_`→`ret`.
- `phi` instructions become `mov` sequences on predecessor edges:
  unconditional-jump preds get inline moves before the terminator;
  conditional-branch preds get a trampoline block (moves + `jmp`) via edge
  splitting, so phi semantics stay correct on both edges.
- Branches that exceed the signed 16-bit `b:c` displacement automatically
  use the `ext_prefix` 32-bit payload form (kind 1 = jump, 2 = branch-true).
- `constant`, `call`, `load`, `store` return typed `unsupported_op` errors —
  the register ISA has no immediate-load or call encoding yet.

## Evidence

- Debug MSVC build clean; `mute_emit_unit` passes:
  - `p1+p2` emits and executes through `run_register_vm` → 7
  - compare+branch+phi select emits and executes both directions
    (3,7)→3 and (9,7)→7
  - `constant` rejected with `unsupported_op`; unverified module reports
    diagnostics
  - emission is deterministic
- Full Debug `mute_*` CTest: 34/34 pass. ASan `build-msvc-asan` `mute_*`
  suite run after this change.
- `tools/version` integration source list updated.

## Limits — resolved in the follow-up pass (same day)

- **AST→SSA lowering added.** `mute/include/poko/mute/lower.hpp` +
  `mute/src/semantic/lower.cpp`: `lower_function` converts a `StatementAst`
  body plus params into an `IrFunction` that passes `verify()`. Supported:
  block, let/var, expression, if/else (env merge via phi on actual
  predecessors), while, loop, break/continue, return; expressions integer,
  boolean, unit, identifier, unary, binary incl. `land`/`lor` short-circuit.
  `match`/`guard`/`for`, calls, member/index, await, strings and floats
  produce typed diagnostics. Loop-carried variable merging is conservative
  (pre-loop env) — documented v1 limit.
- **Literal support added.** New `Opcode::load_imm` (0x70): `li rX, imm`
  with a payload word carrying a signed i32 immediate — wired through
  `bytecode.cpp` (mnemonic, validate payload marking, assembler, disassembler)
  and `register_vm.cpp`. `emit` lowers `IrOp::constant` to it (i32 range
  checked). Constants now compile *and execute*.
- **End-to-end pipeline proven.** `mute_lower_unit` parses real Mute source
  (`package ... fn f() -> i32 { ... }`), lowers, verifies, emits and runs it
  through `run_register_vm`: arithmetic, if/else phi select, loop+break and
  while-false cases all return correct values; unknown names are rejected.

## Still open

- `for`/`match`/`guard` statements, function calls, member/index access,
  await/spawn lowering, floats/strings/aggregates, assignments
  (loop-carried vars), register spilling, and hostcalls remain unsupported.
- `load_imm` is i32-only; i64/f64 literal pools are later work.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.
