# MUT-26 progress — IR to bytecode emission + AST lowering

Status: foundation implemented and verified locally. No gate accepted.

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
- No gate is accepted by this milestone; G1/G2 and platform gates unchanged.
