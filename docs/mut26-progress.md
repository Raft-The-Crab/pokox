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

## Limits

- No AST→SSA lowering exists yet; `IrModule` is still test-built. That is
  the missing middle of the pipeline (MUT-25 produced the IR, this emits
  bytecode from it).
- No literal pool: `constant` is unsupported until the ISA grows an
  immediate-load op or a constant region.
- No calls, floats, strings, aggregates or hostcalls in emitted code.
- Register allocation is identity-mapping (no spilling); 255-value cap.
- Phi lowering assumes verifier-clean input; malformed phi operand
  attribution is `bad_phi_operand`.
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.
