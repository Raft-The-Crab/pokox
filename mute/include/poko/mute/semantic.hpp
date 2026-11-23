#pragma once

#include "poko/mute/declaration.hpp"
#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

namespace poko::mute {

// Types are structural; generic parameters are invariant (no subtyping except
// never <: T). `unknown` suppresses cascading diagnostics after an earlier
// error, `int_literal` is the unsuffixed-integer inference type.
enum class TypeTag {
  unknown, error, unit, never, int_literal, scalar, array, map,
  option, result, tuple, structure, enumeration, function
};
struct Type {
  TypeTag tag{TypeTag::unknown};
  std::string name;
  std::vector<Type> args; // generic arguments, tuple/function/param components
};
[[nodiscard]] bool same_type(const Type& a, const Type& b) noexcept;
[[nodiscard]] bool accepts(const Type& target, const Type& value) noexcept;
[[nodiscard]] std::string type_name(const Type& type);

enum class SemanticErrorCode {
  duplicate_declaration, duplicate_binding, unknown_name, unknown_type,
  unknown_function, unknown_field, wrong_arity, type_mismatch,
  invalid_operand, invalid_assignment, invalid_return, trait_not_satisfied,
  invalid_generic_arity, immutable_assignment
};
struct SemanticDiagnostic { SemanticErrorCode code; Position position; };
struct SemanticResult {
  std::vector<SemanticDiagnostic> diagnostics;
  [[nodiscard]] bool ok() const noexcept { return diagnostics.empty(); }
};

// Runs name resolution (MUT-17), scalar (MUT-18), aggregate (MUT-19) and
// generic/trait (MUT-20) checks over a parsed module. Diagnostics are ordered
// by traversal order and carry original source positions.
[[nodiscard]] SemanticResult analyze(const DeclarationAst& ast);
[[nodiscard]] std::string_view name(SemanticErrorCode code);
[[nodiscard]] std::string dump_semantic(const SemanticResult& result);
} // namespace poko::mute
