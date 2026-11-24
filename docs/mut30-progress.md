# MUT-30 progress — proven-safe control-flow simplification

Status: implemented and verified locally. No gate accepted.

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
- No gate accepted.
