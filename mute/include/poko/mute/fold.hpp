#pragma once

#include "poko/mute/ssa.hpp"

namespace poko::mute {

// MUT-28: proven-safe constant folding over verified SSA. Rewrites
// binary/unary/compare/copy instructions whose operands are constants
// defined earlier in the SAME block into `constant` instructions, preserving
// value ids, result types and trap behavior:
//   - Operations that would trap or overflow at runtime (div/mod by zero,
//     INT32_MIN/-1, i32 overflow) are left unfolded so the runtime reproduces
//     the identical trap in the identical order.
//   - Only same-block, def-before-use constants fold, so no dominance
//     reasoning is required.
//   - Float/string/aggregate ops are untouched (none exist in the IR yet).
// The pass never changes observable behavior; run verify() afterwards as usual.
[[nodiscard]] IrModule fold_constants(const IrModule& module);

} // namespace poko::mute
