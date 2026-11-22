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

enum class ExprKind { integer, floating, identifier, unary, binary };
enum class ArithmeticOp { none, plus, minus, multiply, divide, remainder };
inline constexpr std::size_t no_node = std::numeric_limits<std::size_t>::max();

// Every child index refers to an earlier node in the same AST. Parentheses
// extend the expression span without altering the spelling/token span.
struct ExprNode {
  ExprKind kind{};
  ArithmeticOp op{ArithmeticOp::none};
  Position begin{};
  std::size_t end_byte{};
  Position token_begin{};
  std::size_t token_end_byte{};
  std::size_t left{no_node};
  std::size_t right{no_node};
  std::string spelling; // owned literal/identifier spelling, empty for operators
};
namespace detail { class ArithmeticParser; }
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
  friend class detail::ArithmeticParser;
  Ast() = default;
  std::vector<ExprNode> nodes_;
  std::size_t root_{no_node};
};

enum class ParseErrorCode { expected_expression, expected_closing_parenthesis, unexpected_closing_parenthesis, unexpected_token };
struct ParseDiagnostic { ParseErrorCode code; Position position; };
// A lexical error is returned unchanged. All AST spellings are owned.
using ParseResult = std::variant<Ast, Diagnostic, ParseDiagnostic>;
[[nodiscard]] ParseResult parse_arithmetic(std::string_view source, LexOptions options = {});
[[nodiscard]] std::string_view name(ParseErrorCode code);
// Deterministic ASCII S-expression including a final newline. Throws
// std::invalid_argument for a moved-from AST; allocation failures may propagate.
[[nodiscard]] std::string dump_ast(const Ast& ast);
} // namespace poko::mute
