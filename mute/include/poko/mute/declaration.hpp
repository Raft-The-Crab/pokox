#pragma once

#include "poko/mute/lexer.hpp"
#include "poko/mute/parser.hpp"
#include "poko/mute/statement.hpp"
#include <cstddef>
#include <limits>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

namespace poko::mute {

inline constexpr std::size_t no_declaration = std::numeric_limits<std::size_t>::max();
namespace detail { class DeclarationParser; }

enum class TypeKind { named, generic, tuple };
struct TypeNode {
  TypeKind kind{};
  Position begin{}, token_begin{};
  std::size_t end_byte{}, token_end_byte{};
  std::string spelling; // base name for named/generic, empty for tuple
  std::vector<std::size_t> args; // generic arguments or tuple elements
};

enum class DeclarationKind {
  module, package, version, allow, import, struct_decl, enum_decl, field,
  variant, state_decl, fn_decl, param, attribute
};
struct DeclarationNode {
  DeclarationKind kind{};
  Position begin{}, token_begin{};
  std::size_t end_byte{}, token_end_byte{};
  std::string spelling; // declared name, attribute name, import alias
  std::size_t type{no_declaration}; // index into DeclarationAst::types
  std::size_t value{no_declaration}; // index into DeclarationAst::values
  std::size_t body{no_declaration}; // index into DeclarationAst::bodies
  std::vector<std::size_t> children; // declaration node indices
};

class DeclarationAst {
 public:
  DeclarationAst() = default;
  DeclarationAst(const DeclarationAst&) = default;
  DeclarationAst& operator=(const DeclarationAst&) = default;
  DeclarationAst(DeclarationAst&&) noexcept = default;
  DeclarationAst& operator=(DeclarationAst&&) noexcept = default;
  [[nodiscard]] std::span<const DeclarationNode> nodes() const noexcept { return nodes_; }
  [[nodiscard]] std::span<const TypeNode> types() const noexcept { return types_; }
  [[nodiscard]] std::span<const Ast> values() const noexcept { return values_; }
  [[nodiscard]] std::span<const StatementAst> bodies() const noexcept { return bodies_; }
  [[nodiscard]] std::size_t root() const noexcept { return root_; }
 private:
  friend class detail::DeclarationParser;
  std::vector<DeclarationNode> nodes_;
  std::vector<TypeNode> types_;
  std::vector<Ast> values_;
  std::vector<StatementAst> bodies_;
  std::size_t root_{no_declaration};
};

enum class DeclarationErrorCode {
  expected_declaration, expected_identifier, expected_type, expected_lbrace,
  expected_rbrace, expected_rparen, expected_semicolon, expected_colon,
  expected_arrow, expected_equal, expected_string, expected_expression,
  unsupported_attribute, depth_exceeded, unexpected_token
};
struct DeclarationDiagnostic { DeclarationErrorCode code; Position position; };
using DeclarationResult = std::variant<DeclarationAst, Diagnostic, ParseDiagnostic, StatementDiagnostic, DeclarationDiagnostic>;

// Parses a whole source as a module of v1 declarations. Nested expression,
// statement and lexer errors are passed through unchanged with original positions.
[[nodiscard]] DeclarationResult parse_declarations(std::string_view source, LexOptions options = {});
[[nodiscard]] std::string_view name(DeclarationErrorCode code);
// Deterministic S-expression including a final newline.
[[nodiscard]] std::string dump_declaration_ast(const DeclarationAst& ast);
} // namespace poko::mute
