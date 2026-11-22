#include "poko/mute/parser.hpp"
#include <array>
#include <stdexcept>
#include <utility>

namespace poko::mute {
namespace {
std::string_view symbol(ArithmeticOp op) {
  switch (op) {
    case ArithmeticOp::plus: return "+";
    case ArithmeticOp::minus: return "-";
    case ArithmeticOp::multiply: return "*";
    case ArithmeticOp::divide: return "/";
    case ArithmeticOp::remainder: return "%";
    case ArithmeticOp::none: break;
  }
  throw std::invalid_argument("invalid AST operator");
}
ArithmeticOp arithmetic_op(std::string_view spelling) {
  if (spelling == "+") return ArithmeticOp::plus;
  if (spelling == "-") return ArithmeticOp::minus;
  if (spelling == "*") return ArithmeticOp::multiply;
  if (spelling == "/") return ArithmeticOp::divide;
  if (spelling == "%") return ArithmeticOp::remainder;
  return ArithmeticOp::none;
}
void quoted(std::string& out, std::string_view text) {
  constexpr char hex[] = "0123456789abcdef";
  out += '"';
  for (unsigned char byte : text) {
    if (byte >= 32 && byte <= 126 && byte != '"' && byte != '\\') out += static_cast<char>(byte);
    else { out += "\\x"; out += hex[byte >> 4]; out += hex[byte & 15]; }
  }
  out += '"';
}
}
namespace detail {
class ArithmeticParser {
  enum class StackKind { opening, unary, binary };
  struct Pending { StackKind kind; ArithmeticOp op; Token token; };
  std::string_view source_;
  std::vector<Token> tokens_;
  std::vector<Pending> pending_;
  std::vector<std::size_t> values_;
  Ast ast_;
  [[nodiscard]] std::string_view text(const Token& token) const {
    return source_.substr(token.begin.byte, token.end_byte - token.begin.byte);
  }
  static int precedence(const Pending& op) {
    if (op.kind == StackKind::unary) return 3;
    return op.op == ArithmeticOp::multiply || op.op == ArithmeticOp::divide || op.op == ArithmeticOp::remainder ? 2 : 1;
  }
  void reduce() {
    const auto pending = pending_.back(); pending_.pop_back();
    const auto right = values_.back(); values_.pop_back();
    ExprNode node;
    node.op = pending.op;
    node.token_begin = pending.token.begin;
    node.token_end_byte = pending.token.end_byte;
    if (pending.kind == StackKind::unary) {
      node.kind = ExprKind::unary;
      node.begin = pending.token.begin;
      node.end_byte = ast_.nodes_[right].end_byte;
      node.left = right;
    } else {
      const auto left = values_.back(); values_.pop_back();
      node.kind = ExprKind::binary;
      node.begin = ast_.nodes_[left].begin;
      node.end_byte = ast_.nodes_[right].end_byte;
      node.left = left; node.right = right;
    }
    values_.push_back(ast_.nodes_.size());
    ast_.nodes_.push_back(std::move(node));
  }
  void leaf(const Token& token) {
    ExprNode node;
    node.kind = token.kind == TokenKind::integer ? ExprKind::integer :
                token.kind == TokenKind::floating ? ExprKind::floating : ExprKind::identifier;
    node.begin = token.begin; node.end_byte = token.end_byte;
    node.token_begin = token.begin; node.token_end_byte = token.end_byte;
    node.spelling = text(token);
    values_.push_back(ast_.nodes_.size());
    ast_.nodes_.push_back(std::move(node));
  }
 public:
  ArithmeticParser(std::string_view source, std::vector<Token> tokens)
      : source_(source), tokens_(std::move(tokens)) {}
  [[nodiscard]] ParseResult run() {
    bool expecting_operand = true;
    for (const auto& token : tokens_) {
      const auto value = text(token);
      if (expecting_operand) {
        if (token.kind == TokenKind::op && (value == "+" || value == "-")) {
          pending_.push_back({StackKind::unary, arithmetic_op(value), token});
        } else if (token.kind == TokenKind::punctuation && value == "(") {
          pending_.push_back({StackKind::opening, ArithmeticOp::none, token});
        } else if (token.kind == TokenKind::integer || token.kind == TokenKind::floating || token.kind == TokenKind::identifier) {
          leaf(token); expecting_operand = false;
        } else {
          return ParseDiagnostic{ParseErrorCode::expected_expression, token.begin};
        }
        continue;
      }
      if (token.kind == TokenKind::op && arithmetic_op(value) != ArithmeticOp::none) {
        const Pending next{StackKind::binary, arithmetic_op(value), token};
        while (!pending_.empty() && pending_.back().kind != StackKind::opening && precedence(pending_.back()) >= precedence(next)) reduce();
        pending_.push_back(next); expecting_operand = true;
      } else if (token.kind == TokenKind::punctuation && value == ")") {
        while (!pending_.empty() && pending_.back().kind != StackKind::opening) reduce();
        if (pending_.empty()) return ParseDiagnostic{ParseErrorCode::unexpected_closing_parenthesis, token.begin};
        const auto opening = pending_.back().token; pending_.pop_back();
        auto& grouped = ast_.nodes_[values_.back()];
        grouped.begin = opening.begin; grouped.end_byte = token.end_byte;
      } else if (token.kind == TokenKind::end) {
        while (!pending_.empty()) {
          if (pending_.back().kind == StackKind::opening) return ParseDiagnostic{ParseErrorCode::expected_closing_parenthesis, token.begin};
          reduce();
        }
        ast_.root_ = values_.back();
        return std::move(ast_);
      } else {
        return ParseDiagnostic{ParseErrorCode::unexpected_token, token.begin};
      }
    }
    throw std::logic_error("lexer did not produce EOF");
  }
};
} // namespace detail
ParseResult parse_arithmetic(std::string_view source, LexOptions options) {
  auto result = lex(source, options);
  if (auto* error = std::get_if<Diagnostic>(&result)) return *error;
  return detail::ArithmeticParser(source, std::get<std::vector<Token>>(std::move(result))).run();
}
std::string_view name(ParseErrorCode code) {
  constexpr auto names = std::to_array<std::string_view>({"expected_expression", "expected_closing_parenthesis", "unexpected_closing_parenthesis", "unexpected_token"});
  return names.at(static_cast<std::size_t>(code));
}
std::string dump_ast(const Ast& ast) {
  const auto nodes = ast.nodes();
  if (ast.root() >= nodes.size()) throw std::invalid_argument("empty or moved-from AST");
  enum class Action { visit, space, close };
  struct Task { Action action; std::size_t index; };
  std::vector<Task> stack{{Action::visit, ast.root()}};
  std::string out;
  while (!stack.empty()) {
    const auto task = stack.back(); stack.pop_back();
    if (task.action == Action::space) { out += ' '; continue; }
    if (task.action == Action::close) { out += ')'; continue; }
    const auto& node = nodes[task.index];
    if (node.kind == ExprKind::integer || node.kind == ExprKind::floating || node.kind == ExprKind::identifier) {
      out += node.kind == ExprKind::integer ? "(integer " : node.kind == ExprKind::floating ? "(floating " : "(identifier ";
      quoted(out, node.spelling); out += ')';
    } else {
      out += node.kind == ExprKind::unary ? "(unary " : "(binary ";
      out += symbol(node.op); out += ' ';
      stack.push_back({Action::close, 0});
      if (node.kind == ExprKind::binary) { stack.push_back({Action::visit,node.right}); stack.push_back({Action::space,0}); }
      stack.push_back({Action::visit,node.left});
    }
  }
  out += '\n';
  return out;
}
} // namespace poko::mute
