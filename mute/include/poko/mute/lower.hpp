#pragma once

#include "poko/mute/ssa.hpp"
#include "poko/mute/statement.hpp"
#include <span>
#include <string>
#include <utility>
#include <vector>

namespace poko::mute {

// AST -> SSA lowering (MUT-26 pipeline middle). Converts one function body
// (StatementAst) plus its parameter list into an IrFunction that passes
// verify(). Supported statements: block, let/var, expression, if/else, while,
// loop, break/continue, return. Supported expressions: integer, boolean,
// unit, identifier, unary, binary. match/guard/for, calls, member/index,
// await, strings and floats produce typed diagnostics, never silent output.
//
// All lowered values are i32 scalars (the register VM is i32-only); boolean
// results use the scalar "bool" type name.

struct LowerParam { std::string name; Type type; };
struct LowerResult {
  IrFunction fn;
  std::vector<IrDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

[[nodiscard]] LowerResult lower_function(
    const StatementAst& body, std::string_view name, const Type& result,
    std::span<const LowerParam> params);
} // namespace poko::mute
