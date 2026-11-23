#pragma once

#include "poko/mute/lexer.hpp"
#include "poko/mute/parser.hpp"
#include <cstddef>
#include <limits>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

namespace poko::mute {

enum class StatementKind {
  block, let_stmt, var_stmt, expression, if_stmt, while_stmt, for_stmt,
  loop_stmt, match_stmt, match_arm, guard_stmt, break_stmt, continue_stmt, return_stmt
};
inline constexpr std::size_t no_statement = std::numeric_limits<std::size_t>::max();
namespace detail { class StatementParser; }

// Statements own their expression ASTs; child indices refer to earlier nodes
// in the same StatementAst, matching the expression AST invariant.
struct StatementNode {
  StatementKind kind{};
  Position begin{}, token_begin{};
  std::size_t end_byte{}, token_end_byte{};
  std::size_t expression{no_statement}; // index into StatementAst::expressions
  std::vector<std::size_t> children;
  std::string spelling; // declared loop variable or match pattern
};

class StatementAst {
 public:
  StatementAst() = default;
  StatementAst(const StatementAst&) = default;
  StatementAst& operator=(const StatementAst&) = default;
  StatementAst(StatementAst&&) noexcept = default;
  StatementAst& operator=(StatementAst&&) noexcept = default;
  [[nodiscard]] std::span<const StatementNode> nodes() const noexcept { return nodes_; }
  [[nodiscard]] std::span<const Ast> expressions() const noexcept { return expressions_; }
  [[nodiscard]] std::size_t root() const noexcept { return root_; }
 private:
  friend class detail::StatementParser;
  std::vector<StatementNode> nodes_;
  std::vector<Ast> expressions_;
  std::size_t root_{no_statement};
};

enum class StatementErrorCode {
  expected_statement, expected_identifier, expected_expression, expected_semicolon,
  expected_lbrace, expected_rbrace, expected_else, expected_in, expected_arrow,
  break_outside_loop, continue_outside_loop, depth_exceeded, unexpected_token
};
struct StatementDiagnostic { StatementErrorCode code; Position position; };
using StatementResult = std::variant<StatementAst, Diagnostic, ParseDiagnostic, StatementDiagnostic>;

// Parses a whole source as a statement block. Lexer and expression errors are
// passed through unchanged so diagnostics keep their original positions.
[[nodiscard]] StatementResult parse_statements(std::string_view source, LexOptions options = {});
[[nodiscard]] std::string_view name(StatementErrorCode code);
// Deterministic S-expression including a final newline. Throws
// std::invalid_argument for a moved-from/empty AST.
[[nodiscard]] std::string dump_statement_ast(const StatementAst& ast);
} // namespace poko::mute
