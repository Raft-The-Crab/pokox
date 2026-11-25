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
// unit, identifier, unary, binary, and calls to functions in the supplied
// signature table. match/guard/for, member/index, await, strings and floats
// produce typed diagnostics, never silent output.
//
// All lowered values are i32 scalars (the register VM is i32-only); boolean
// results use the scalar "bool" type name.

struct LowerParam { std::string name; Type type; };
struct LowerResult {
  IrFunction fn;
  std::vector<IrDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};
// Callable signature table entry. sigs[i] corresponds to
// IrModule::functions[i]; calls resolve by name and encode index+1.
struct LowerSignature {
  std::string name;
  std::vector<Type> params;
  Type result{};
  std::uint32_t capabilities{0x3FFu};
};
struct LowerModuleResult {
  IrModule module;
  std::vector<IrDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

[[nodiscard]] LowerResult lower_function(
    const StatementAst& body, std::string_view name, const Type& result,
    std::span<const LowerParam> params);
// Call-aware variant: calls resolve against sigs, so self/mutual recursion
// works when the table contains every module function.
[[nodiscard]] LowerResult lower_function_ex(
    const StatementAst& body, std::string_view name, const Type& result,
    std::span<const LowerParam> params, std::span<const LowerSignature> sigs,
    std::uint32_t capabilities = 0x3FFu);
// Lowers every fn_decl in declaration order. The signature table is built
// first so any function may call any other. `@requires(...)` narrows the
// function mask to the program's allow: ceiling intersected with the listed
// capabilities; functions without the attribute keep 0x3FF.
[[nodiscard]] LowerModuleResult lower_module(const DeclarationAst& ast);
} // namespace poko::mute
