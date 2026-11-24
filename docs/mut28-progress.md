# MUT-28 progress — proven-safe constant folding

Status: implemented and verified locally. No gate accepted.

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
- No gate accepted.
