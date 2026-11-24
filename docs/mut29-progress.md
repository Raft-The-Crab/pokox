# MUT-29 progress — dead pure-code elimination

Status: implemented and verified locally. No gate accepted.

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
- No gate accepted.
