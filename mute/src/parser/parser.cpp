#include "poko/mute/parser.hpp"
#include <array>
#include <deque>
#include <stdexcept>
#include <utility>

namespace poko::mute {
namespace {
std::string_view op_spelling(ExprOp op) {
  switch (op) {
    case ExprOp::plus: return "+"; case ExprOp::minus: return "-";
    case ExprOp::multiply: return "*"; case ExprOp::divide: return "/";
    case ExprOp::remainder: return "%"; case ExprOp::bit_and: return "&";
    case ExprOp::bit_or: return "|"; case ExprOp::bit_xor: return "^";
    case ExprOp::shl: return "<<"; case ExprOp::shr: return ">>";
    case ExprOp::eq: return "=="; case ExprOp::ne: return "!=";
    case ExprOp::lt: return "<"; case ExprOp::le: return "<=";
    case ExprOp::gt: return ">"; case ExprOp::ge: return ">=";
    case ExprOp::land: return "&&"; case ExprOp::lor: return "||";
    case ExprOp::range: return ".."; case ExprOp::range_inclusive: return "..=";
    case ExprOp::assign: return "="; case ExprOp::assign_add: return "+=";
    case ExprOp::assign_sub: return "-="; case ExprOp::assign_mul: return "*=";
    case ExprOp::assign_div: return "/="; case ExprOp::assign_mod: return "%=";
    case ExprOp::assign_and: return "&="; case ExprOp::assign_or: return "|=";
    case ExprOp::assign_xor: return "^="; case ExprOp::assign_shl: return "<<=";
    case ExprOp::assign_shr: return ">>=";
    case ExprOp::neg: return "-"; case ExprOp::pos: return "+";
    case ExprOp::not_op: return "!"; case ExprOp::move_op: return "move";
    case ExprOp::none: break;
  }
  throw std::invalid_argument("invalid AST operator");
}
ExprOp expr_op(std::string_view spelling) {
  if (spelling == "+") return ExprOp::plus;
  if (spelling == "-") return ExprOp::minus;
  if (spelling == "*") return ExprOp::multiply;
  if (spelling == "/") return ExprOp::divide;
  if (spelling == "%") return ExprOp::remainder;
  if (spelling == "&") return ExprOp::bit_and;
  if (spelling == "|") return ExprOp::bit_or;
  if (spelling == "^") return ExprOp::bit_xor;
  if (spelling == "<<") return ExprOp::shl;
  if (spelling == ">>") return ExprOp::shr;
  if (spelling == "==") return ExprOp::eq;
  if (spelling == "!=") return ExprOp::ne;
  if (spelling == "<") return ExprOp::lt;
  if (spelling == "<=") return ExprOp::le;
  if (spelling == ">") return ExprOp::gt;
  if (spelling == ">=") return ExprOp::ge;
  if (spelling == "&&") return ExprOp::land;
  if (spelling == "||") return ExprOp::lor;
  if (spelling == "..") return ExprOp::range;
  if (spelling == "..=") return ExprOp::range_inclusive;
  if (spelling == "=") return ExprOp::assign;
  if (spelling == "+=") return ExprOp::assign_add;
  if (spelling == "-=") return ExprOp::assign_sub;
  if (spelling == "*=") return ExprOp::assign_mul;
  if (spelling == "/=") return ExprOp::assign_div;
  if (spelling == "%=") return ExprOp::assign_mod;
  if (spelling == "&=") return ExprOp::assign_and;
  if (spelling == "|=") return ExprOp::assign_or;
  if (spelling == "^=") return ExprOp::assign_xor;
  if (spelling == "<<=") return ExprOp::assign_shl;
  if (spelling == ">>=") return ExprOp::assign_shr;
  return ExprOp::none;
}
bool is_assign_op(ExprOp op) {
  return op>=ExprOp::assign && op<=ExprOp::assign_shr;
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
// Full v1 expression grammar (docs/plan/04-mute.md precedence, high to low):
// postfix . [] () ?; prefix unary ! - + move await; * / %; + -; << >>; &; ^; |;
// comparisons; equality; &&; ||; ranges; assignment (right associative).
// Iterative shunting-yard: every nested construct is a heap frame, so deeply
// nested input cannot exhaust the native stack (Linux CI uses 8 MB by default).
class ExpressionParser {
  enum class FrameKind { group, call, index, prefix, binary };
  struct Frame {
    FrameKind kind;
    ExprOp op{ExprOp::none};
    Token token;
    std::size_t left{no_node};
    bool await_node{false};
    std::vector<std::size_t> args;
  };
  std::string_view source_;
  std::vector<Token> tokens_;
  std::size_t pos_{};
  Ast ast_;
  std::vector<Frame> frames_;
  std::vector<std::size_t> values_;
  bool want_operand_{true};

  [[nodiscard]] const Token& peek(std::size_t ahead=0) const { return tokens_[std::min(pos_+ahead,tokens_.size()-1)]; }
  [[nodiscard]] bool at_end() const { return pos_>=tokens_.size() || tokens_[pos_].kind==TokenKind::end; }
  const Token& take() { return tokens_[pos_++]; }
  [[nodiscard]] std::string_view text(const Token& token) const {
    return source_.substr(token.begin.byte, token.end_byte - token.begin.byte);
  }
  [[nodiscard]] bool is_punct(char c) const {
    const auto& t=peek(); return t.kind==TokenKind::punctuation && text(t).size()==1 && text(t)[0]==c;
  }
  [[nodiscard]] bool is_keyword(std::string_view word) const {
    const auto& t=peek(); return t.kind==TokenKind::keyword && text(t)==word;
  }
  ParseDiagnostic fail(ParseErrorCode code,const Token& at) const { return ParseDiagnostic{code,at.begin}; }
  ParseDiagnostic fail(ParseErrorCode code) const { return fail(code,peek()); }
  std::size_t add_node(ExprNode node) {
    const auto index=ast_.nodes_.size();
    ast_.nodes_.push_back(std::move(node));
    return index;
  }
  static constexpr int level_of(ExprOp op) {
    switch (op) {
      case ExprOp::range: case ExprOp::range_inclusive: return 1;
      case ExprOp::lor: return 2;
      case ExprOp::land: return 3;
      case ExprOp::eq: case ExprOp::ne: return 4;
      case ExprOp::lt: case ExprOp::le: case ExprOp::gt: case ExprOp::ge: return 5;
      case ExprOp::bit_or: return 6;
      case ExprOp::bit_xor: return 7;
      case ExprOp::bit_and: return 8;
      case ExprOp::shl: case ExprOp::shr: return 9;
      case ExprOp::plus: case ExprOp::minus: return 10;
      case ExprOp::multiply: case ExprOp::divide: case ExprOp::remainder: return 11;
      default: return -1;
    }
  }
  [[nodiscard]] static bool is_op_frame(const Frame& f) {
    return f.kind==FrameKind::prefix || f.kind==FrameKind::binary;
  }
  [[nodiscard]] static int frame_level(const Frame& f) {
    if (f.kind==FrameKind::prefix) return 12;
    return is_assign_op(f.op) ? 0 : level_of(f.op);
  }
  void reduce_one() {
    const auto frame=std::move(frames_.back()); frames_.pop_back();
    const auto right=values_.back(); values_.pop_back();
    ExprNode node;
    node.token_begin=frame.token.begin; node.token_end_byte=frame.token.end_byte;
    if (frame.kind==FrameKind::prefix) {
      node.kind=frame.await_node ? ExprKind::await : ExprKind::unary;
      if (!frame.await_node) node.op=frame.op;
      node.begin=frame.token.begin; node.end_byte=ast_.nodes_[right].end_byte;
      node.left=right;
    } else {
      node.kind=ExprKind::binary; node.op=frame.op;
      node.begin=ast_.nodes_[frame.left].begin; node.end_byte=ast_.nodes_[right].end_byte;
      node.left=frame.left; node.right=right;
    }
    values_.push_back(add_node(std::move(node)));
  }
  void reduce_all() {
    while (!frames_.empty() && is_op_frame(frames_.back())) reduce_one();
  }
 public:
  ExpressionParser(std::string_view source, std::vector<Token> tokens)
      : source_(source), tokens_(std::move(tokens)) {}
  [[nodiscard]] ParseResult run() {
    if (tokens_.empty() || tokens_.back().kind!=TokenKind::end) throw std::logic_error("lexer did not produce EOF");
    while (!at_end()) {
      const auto& t=peek();
      if (want_operand_) {
        ExprOp pref=ExprOp::none; bool is_await=false;
        if (t.kind==TokenKind::op) {
          const auto spelling=text(t);
          if (spelling=="!") pref=ExprOp::not_op;
          else if (spelling=="-") pref=ExprOp::neg;
          else if (spelling=="+") pref=ExprOp::pos;
        } else if (is_keyword("move")) pref=ExprOp::move_op;
        else if (is_keyword("await")) is_await=true;
        if (pref!=ExprOp::none || is_await) {
          take();
          frames_.push_back({FrameKind::prefix,pref,t,no_node,is_await,{}});
          continue;
        }
        if (is_punct('(')) {
          take();
          if (is_punct(')')) {
            const auto close=take();
            ExprNode node;
            node.kind=ExprKind::unit;
            node.begin=t.begin; node.end_byte=close.end_byte;
            node.token_begin=t.begin; node.token_end_byte=close.end_byte;
            values_.push_back(add_node(std::move(node)));
            want_operand_=false;
            continue;
          }
          frames_.push_back({FrameKind::group,ExprOp::none,t});
          continue;
        }
        if (is_punct(')') && !frames_.empty() && frames_.back().kind==FrameKind::call && frames_.back().args.empty()) {
          auto frame=frames_.back(); frames_.pop_back();
          take();
          ExprNode node;
          node.kind=ExprKind::call;
          node.begin=ast_.nodes_[frame.left].begin; node.end_byte=t.end_byte;
          node.token_begin=frame.token.begin; node.token_end_byte=t.end_byte;
          node.left=frame.left; node.children=std::move(frame.args);
          values_.push_back(add_node(std::move(node)));
          continue;
        }
        if (t.kind==TokenKind::integer || t.kind==TokenKind::floating ||
            t.kind==TokenKind::string_literal || t.kind==TokenKind::identifier ||
            (t.kind==TokenKind::keyword && (text(t)=="true" || text(t)=="false"))) {
          take();
          ExprNode node;
          node.kind=t.kind==TokenKind::integer ? ExprKind::integer :
                    t.kind==TokenKind::floating ? ExprKind::floating :
                    t.kind==TokenKind::string_literal ? ExprKind::string :
                    t.kind==TokenKind::identifier ? ExprKind::identifier : ExprKind::boolean;
          node.begin=t.begin; node.end_byte=t.end_byte;
          node.token_begin=t.begin; node.token_end_byte=t.end_byte;
          node.spelling=text(t);
          values_.push_back(add_node(std::move(node)));
          want_operand_=false;
          continue;
        }
        return fail(ParseErrorCode::expected_expression,t);
      }
      if (is_punct('.')) {
        take();
        const auto& name=peek();
        if (name.kind!=TokenKind::identifier) return fail(ParseErrorCode::expected_member_name,name);
        take();
        const auto base=values_.back(); values_.pop_back();
        ExprNode node;
        node.kind=ExprKind::member;
        node.begin=ast_.nodes_[base].begin; node.end_byte=name.end_byte;
        node.token_begin=t.begin; node.token_end_byte=t.end_byte;
        node.left=base; node.spelling=text(name);
        values_.push_back(add_node(std::move(node)));
        continue;
      }
      if (is_punct('[')) {
        take();
        const auto base=values_.back(); values_.pop_back();
        frames_.push_back({FrameKind::index,ExprOp::none,t,base});
        want_operand_=true;
        continue;
      }
      if (is_punct('(')) {
        take();
        const auto callee=values_.back(); values_.pop_back();
        frames_.push_back({FrameKind::call,ExprOp::none,t,callee});
        want_operand_=true;
        continue;
      }
      if (t.kind==TokenKind::op && text(t)=="?") {
        take();
        const auto base=values_.back(); values_.pop_back();
        ExprNode node;
        node.kind=ExprKind::question;
        node.begin=ast_.nodes_[base].begin; node.end_byte=t.end_byte;
        node.token_begin=t.begin; node.token_end_byte=t.end_byte;
        node.left=base;
        values_.push_back(add_node(std::move(node)));
        continue;
      }
      if (t.kind==TokenKind::op) {
        const auto op=expr_op(text(t));
        const int level=is_assign_op(op) ? 0 : level_of(op);
        if (level>=0) {
          while (!frames_.empty() && is_op_frame(frames_.back())) {
            const auto top_level=frame_level(frames_.back());
            const bool left_assoc=!is_assign_op(frames_.back().op);
            if (top_level>level || (top_level==level && left_assoc)) reduce_one();
            else break;
          }
          const auto left=values_.back(); values_.pop_back();
          take();
          frames_.push_back({FrameKind::binary,op,t,left});
          want_operand_=true;
          continue;
        }
      }
      if (is_punct(')') || is_punct(']') || is_punct(',')) {
        reduce_all();
        if (frames_.empty()) return fail(is_punct(',') ? ParseErrorCode::unexpected_token : ParseErrorCode::unexpected_closing_parenthesis,t);
        if (is_punct(',')) {
          if (frames_.back().kind!=FrameKind::call) return fail(ParseErrorCode::unexpected_token,t);
          frames_.back().args.push_back(values_.back()); values_.pop_back();
          take();
          want_operand_=true;
          continue;
        }
        auto frame=frames_.back(); frames_.pop_back();
        const bool closing_bracket=is_punct(']');
        if (frame.kind==FrameKind::index && closing_bracket) {
          take();
          const auto index=values_.back(); values_.pop_back();
          ExprNode node;
          node.kind=ExprKind::index;
          node.begin=ast_.nodes_[frame.left].begin; node.end_byte=t.end_byte;
          node.token_begin=frame.token.begin; node.token_end_byte=frame.token.end_byte;
          node.left=frame.left; node.right=index;
          values_.push_back(add_node(std::move(node)));
          continue;
        }
        if (frame.kind==FrameKind::call && !closing_bracket) {
          take();
          auto args=std::move(frame.args); args.push_back(values_.back()); values_.pop_back();
          ExprNode node;
          node.kind=ExprKind::call;
          node.begin=ast_.nodes_[frame.left].begin; node.end_byte=t.end_byte;
          node.token_begin=frame.token.begin; node.token_end_byte=t.end_byte;
          node.left=frame.left; node.children=std::move(args);
          values_.push_back(add_node(std::move(node)));
          continue;
        }
        if (frame.kind==FrameKind::group && !closing_bracket) {
          take();
          auto& grouped=ast_.nodes_[values_.back()];
          grouped.begin=frame.token.begin; grouped.end_byte=t.end_byte;
          continue;
        }
        return fail(closing_bracket ? ParseErrorCode::expected_closing_bracket : ParseErrorCode::unexpected_closing_parenthesis,t);
      }
      return fail(ParseErrorCode::unexpected_token,t);
    }
    if (want_operand_) return fail(ParseErrorCode::expected_expression,peek());
    reduce_all();
    if (!frames_.empty()) {
      const auto code=frames_.back().kind==FrameKind::index ? ParseErrorCode::expected_closing_bracket
                      : ParseErrorCode::expected_closing_parenthesis;
      return fail(code,peek());
    }
    if (values_.size()!=1) return fail(ParseErrorCode::unexpected_token,peek());
    ast_.root_=values_.back();
    return std::move(ast_);
  }
};
} // namespace detail
ParseResult parse_arithmetic(std::string_view source, LexOptions options) {
  auto result = lex(source, options);
  if (auto* error = std::get_if<Diagnostic>(&result)) return *error;
  return detail::ExpressionParser(source, std::get<std::vector<Token>>(std::move(result))).run();
}
ParseResult parse_arithmetic(std::string_view source, const std::vector<Token>& tokens, std::size_t first, std::size_t last) {
  if (first>last || last>tokens.size()) throw std::invalid_argument("invalid expression token range");
  std::vector<Token> subset(tokens.begin()+static_cast<std::ptrdiff_t>(first),tokens.begin()+static_cast<std::ptrdiff_t>(last));
  const Position end_position=last<tokens.size() ? tokens[last].begin : Position{source.size(),1,1};
  subset.push_back({TokenKind::end,end_position,end_position.byte});
  return detail::ExpressionParser(source,std::move(subset)).run();
}
std::string_view name(ParseErrorCode code) {
  constexpr auto names = std::to_array<std::string_view>({"expected_expression", "expected_closing_parenthesis", "unexpected_closing_parenthesis", "unexpected_token", "expected_closing_bracket", "expected_member_name"});
  return names.at(static_cast<std::size_t>(code));
}
std::string dump_ast(const Ast& ast) {
  const auto nodes = ast.nodes();
  if (ast.root() >= nodes.size()) throw std::invalid_argument("empty or moved-from AST");
  enum class Action { visit, space, close, raw };
  struct Task { Action action; std::size_t index; std::string_view text; };
  std::vector<Task> stack{{Action::visit, ast.root(), {}}};
  std::string out;
  std::deque<std::string> member_names; // stable storage for raw name tasks
  auto kind_name=[&](ExprKind k)->std::string_view {
    switch (k) {
      case ExprKind::integer: return "integer"; case ExprKind::floating: return "floating";
      case ExprKind::string: return "string"; case ExprKind::boolean: return "boolean";
      case ExprKind::identifier: return "identifier"; case ExprKind::unit: return "unit";
      case ExprKind::unary: return "unary";
      case ExprKind::binary: return "binary"; case ExprKind::call: return "call";
      case ExprKind::index: return "index"; case ExprKind::member: return "member";
      case ExprKind::question: return "question"; case ExprKind::await: return "await";
    }
    return "?";
  };
  while (!stack.empty()) {
    const auto task = stack.back(); stack.pop_back();
    if (task.action == Action::space) { out += ' '; continue; }
    if (task.action == Action::close) { out += ')'; continue; }
    if (task.action == Action::raw) { out += task.text; continue; }
    const auto& node = nodes[task.index];
    const auto k=node.kind;
    if (k==ExprKind::unit) { out += "(unit)"; continue; }
    if (k==ExprKind::integer || k==ExprKind::floating || k==ExprKind::string ||
        k==ExprKind::boolean || k==ExprKind::identifier) {
      out += '('; out += kind_name(k); out += ' ';
      quoted(out, node.spelling); out += ')';
      continue;
    }
    if (k==ExprKind::member) {
      member_names.emplace_back();
      quoted(member_names.back(),node.spelling);
      out += "(member ";
      stack.push_back({Action::close,0,{}});
      stack.push_back({Action::raw,0,member_names.back()});
      stack.push_back({Action::space,0,{}});
      stack.push_back({Action::visit,node.left,{}});
      continue;
    }
    if (k==ExprKind::call) {
      out += "(call ";
      stack.push_back({Action::close,0,{}});
      for (std::size_t i=node.children.size(); i-- >0;) {
        stack.push_back({Action::visit,node.children[i],{}});
        stack.push_back({Action::space,0,{}});
      }
      stack.push_back({Action::visit,node.left,{}});
      continue;
    }
    if (k==ExprKind::index) {
      out += "(index ";
      stack.push_back({Action::close,0,{}});
      stack.push_back({Action::visit,node.right,{}});
      stack.push_back({Action::space,0,{}});
      stack.push_back({Action::visit,node.left,{}});
      continue;
    }
    if (k==ExprKind::unary || k==ExprKind::question || k==ExprKind::await) {
      out += '('; out += kind_name(k); out += ' ';
      if (k==ExprKind::unary) { out += op_spelling(node.op); out += ' '; }
      stack.push_back({Action::close,0,{}});
      stack.push_back({Action::visit,node.left,{}});
      continue;
    }
    out += "(binary ";
    out += op_spelling(node.op); out += ' ';
    stack.push_back({Action::close,0,{}});
    stack.push_back({Action::visit,node.right,{}});
    stack.push_back({Action::space,0,{}});
    stack.push_back({Action::visit,node.left,{}});
  }
  out += '\n';
  return out;
}
} // namespace poko::mute
