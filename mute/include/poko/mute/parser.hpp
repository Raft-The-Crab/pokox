#pragma once

#include "poko/mute/lexer.hpp"
#include <cstddef>
#include <limits>
#include <span>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

namespace poko::mute {

enum class ExprKind { integer, floating, string, boolean, identifier, unary, binary, call, index, member, question, await };
enum class ArithmeticOp { none, plus, minus, multiply, divide, remainder };
// Full v1 operator set. ArithmeticOp is the subset the tree-walk evaluator
// understands; to_arithmetic() maps everything else to none.
enum class ExprOp {
  none, plus, minus, multiply, divide, remainder,
  bit_and, bit_or, bit_xor, shl, shr,
  eq, ne, lt, le, gt, ge, land, lor,
  assign, assign_add, assign_sub, assign_mul, assign_div, assign_mod,
  assign_and, assign_or, assign_xor, assign_shl, assign_shr,
  range, range_inclusive,
  neg, pos, not_op, move_op
};
inline constexpr std::size_t no_node = std::numeric_limits<std::size_t>::max();

// Every child index refers to an earlier node in the same AST. Parentheses
// extend the expression span without altering the spelling/token span.
struct ExprNode {
  ExprKind kind{};
  ExprOp op{ExprOp::none};
  Position begin{};
  std::size_t end_byte{};
  Position token_begin{};
  std::size_t token_end_byte{};
  std::size_t left{no_node};
  std::size_t right{no_node};
  std::vector<std::size_t> children; // call arguments; empty elsewhere
  std::string spelling; // owned literal/identifier/member spelling
};
namespace detail { class ExpressionParser; }
class Ast {
 public:
  Ast(const Ast&) = default;
  Ast& operator=(const Ast&) = default;
  Ast(Ast&& other) noexcept : nodes_(std::move(other.nodes_)), root_(std::exchange(other.root_, no_node)) {}
  Ast& operator=(Ast&& other) noexcept {
    if (this != &other) { nodes_ = std::move(other.nodes_); root_ = std::exchange(other.root_, no_node); }
    return *this;
  }
  [[nodiscard]] std::span<const ExprNode> nodes() const noexcept { return nodes_; }
  [[nodiscard]] std::size_t root() const noexcept { return root_; }
 private:
  friend class detail::ExpressionParser;
  Ast() = default;
  std::vector<ExprNode> nodes_;
  std::size_t root_{no_node};
};

enum class ParseErrorCode { expected_expression, expected_closing_parenthesis, unexpected_closing_parenthesis, unexpected_token, expected_closing_bracket, expected_member_name };
[[nodiscard]] constexpr ArithmeticOp to_arithmetic(ExprOp op) noexcept {
  switch (op) {
    case ExprOp::plus: case ExprOp::pos: return ArithmeticOp::plus;
    case ExprOp::minus: case ExprOp::neg: return ArithmeticOp::minus;
    case ExprOp::multiply: return ArithmeticOp::multiply;
    case ExprOp::divide: return ArithmeticOp::divide;
    case ExprOp::remainder: return ArithmeticOp::remainder;
    default: return ArithmeticOp::none;
  }
}
struct ParseDiagnostic { ParseErrorCode code; Position position; };
// A lexical error is returned unchanged. All AST spellings are owned.
using ParseResult = std::variant<Ast, Diagnostic, ParseDiagnostic>;
[[nodiscard]] ParseResult parse_arithmetic(std::string_view source, LexOptions options = {});
[[nodiscard]] std::string_view name(ParseErrorCode code);
// Deterministic ASCII S-expression including a final newline. Throws
// std::invalid_argument for a moved-from AST; allocation failures may propagate.
[[nodiscard]] std::string dump_ast(const Ast& ast);
} // namespace poko::mute
