#pragma once

#include "poko/mute/ssa.hpp"

namespace poko::mute {

// MUT-29: eliminate proven-dead pure computations. Removes defs of
// instructions that cannot trap or cause effects (constant, copy, compare,
// phi) when their value is never used. Arithmetic (add/sub/mul/div/mod/neg)
// is NOT pure in this VM — every op can trap on overflow or division by
// zero — so dead arithmetic is preserved to keep trap order identical.
// Terminators, calls, loads and stores are always kept. Runs to a fixpoint.
[[nodiscard]] IrModule eliminate_dead_code(const IrModule& module);

// MUT-30: simplify proven-safe control flow. A `branch` whose condition is
// a constant defined earlier in the same block becomes an unconditional
// `jump` to the taken target — the formerly skipped arm is never evaluated.
// Blocks left unreachable are then removed and all jump/branch targets,
// predecessor lists and phi predecessor operands are remapped. Run
// verify() afterwards; the pass assumes verified input.
[[nodiscard]] IrModule simplify_control_flow(const IrModule& module);

} // namespace poko::mute
