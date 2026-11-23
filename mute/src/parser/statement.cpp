#include "poko/mute/statement.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace poko::mute {
namespace detail {
struct StatementFailure { StatementResult result; };
[[noreturn]] void stmt_fail(StatementErrorCode code, Position pos) {
  throw StatementFailure{StatementDiagnostic{code,pos}};
}
void quoted(std::string& out, std::string_view text) {
  constexpr char hex[]="0123456789abcdef";
  out+='"';
  for (unsigned char byte:text) {
    if (byte>=32 && byte<=126 && byte!='"' && byte!='\\') out+=static_cast<char>(byte);
    else { out+="\\x"; out+=hex[byte>>4]; out+=hex[byte&15]; }
  }
  out+='"';
}
class StatementParser {
  static constexpr std::size_t depth_limit=64;
  std::string_view source_;
  std::vector<Token> tokens_;
  std::size_t pos_{}, depth_{}, loop_depth_{};
  StatementAst ast_;

  [[nodiscard]] const Token& peek(std::size_t ahead=0) const {
    return tokens_[std::min(pos_+ahead,tokens_.size()-1)];
  }
  [[nodiscard]] bool at_end() const {
    return pos_>=tokens_.size() || tokens_[pos_].kind==TokenKind::end;
  }
  const Token& take() { return tokens_[pos_++]; }
  [[nodiscard]] std::string_view text(const Token& token) const {
    return source_.substr(token.begin.byte,token.end_byte-token.begin.byte);
  }
  [[nodiscard]] bool is_punct(char c) const {
    const auto& t=peek(); return t.kind==TokenKind::punctuation && text(t).size()==1 && text(t)[0]==c;
  }
  [[nodiscard]] bool is_keyword(std::string_view word) const {
    const auto& t=peek(); return t.kind==TokenKind::keyword && text(t)==word;
  }
  [[nodiscard]] bool is_op(std::string_view word) const {
    const auto& t=peek(); return t.kind==TokenKind::op && text(t)==word;
  }
  void expect_punct(char c) { if (!is_punct(c)) stmt_fail(StatementErrorCode::unexpected_token,peek().begin); take(); }
  void expect_keyword(std::string_view word) { if (!is_keyword(word)) stmt_fail(StatementErrorCode::unexpected_token,peek().begin); take(); }
  std::string_view expect_identifier() {
    if (peek().kind!=TokenKind::identifier) stmt_fail(StatementErrorCode::expected_identifier,peek().begin);
    const auto result=text(take()); return result;
  }
  struct Depth {
    std::size_t& value;
    explicit Depth(std::size_t& v,std::size_t limit,Position at):value(v) {
      if (value>=limit) stmt_fail(StatementErrorCode::depth_exceeded,at);
      ++value;
    }
    ~Depth() { --value; }
    Depth(const Depth&)=delete;
    Depth& operator=(const Depth&)=delete;
  };
  struct LoopScope {
    std::size_t& value;
    explicit LoopScope(std::size_t& v):value(v) { ++value; }
    ~LoopScope() { --value; }
    LoopScope(const LoopScope&)=delete;
    LoopScope& operator=(const LoopScope&)=delete;
  };
  [[nodiscard]] static bool expression_boundary(const Token& token,std::string_view value,int nesting) {
    if (nesting>0) return false;
    if (token.kind==TokenKind::punctuation && (value==";" || value=="{" || value=="}" || value==",")) return true;
    if (token.kind!=TokenKind::keyword) return false;
    constexpr auto statement_words=std::to_array<std::string_view>({
      "else","in","let","var","if","while","for","loop","match","guard","break","continue","return"});
    return std::find(statement_words.begin(),statement_words.end(),value)!=statement_words.end();
  }
  // [first,last) is the expression token range; last points at the boundary.
  [[nodiscard]] std::size_t expression_range(std::size_t first) const {
    int nesting=0;
    for (auto i=first;i<tokens_.size();++i) {
      const auto& token=tokens_[i];
      if (token.kind==TokenKind::end) return i;
      const auto value=text(token);
      if (token.kind==TokenKind::punctuation && (value=="(" || value=="[")) { ++nesting; continue; }
      if (token.kind==TokenKind::punctuation && (value==")" || value=="]")) {
        if (nesting==0) return i;
        --nesting;
        continue;
      }
      if (expression_boundary(token,value,nesting)) return i;
    }
    return tokens_.size()-1;
  }
  std::size_t add_expression(std::size_t first,std::size_t last,Position at) {
    if (first>=last) stmt_fail(StatementErrorCode::expected_expression,at);
    auto result=parse_arithmetic(source_,tokens_,first,last);
    if (auto* error=std::get_if<Diagnostic>(&result)) throw StatementFailure{*error};
    if (auto* error=std::get_if<ParseDiagnostic>(&result)) throw StatementFailure{*error};
    ast_.expressions_.push_back(std::move(std::get<Ast>(result)));
    return ast_.expressions_.size()-1;
  }
  std::size_t simple_expression() {
    const auto first=pos_;
    const auto last=expression_range(first);
    const auto at=peek().begin;
    const auto index=add_expression(first,last,at);
    pos_=last;
    return index;
  }
  std::size_t add_node(StatementNode node) {
    const auto index=ast_.nodes_.size();
    ast_.nodes_.push_back(std::move(node));
    return index;
  }
  [[nodiscard]] static StatementNode make_node(StatementKind kind,Position begin,std::size_t end_byte) {
    StatementNode node;
    node.kind=kind; node.begin=begin; node.end_byte=end_byte;
    node.token_begin=begin; node.token_end_byte=end_byte;
    return node;
  }
  std::size_t block() {
    const auto open=peek();
    expect_punct('{');
    auto node=make_node(StatementKind::block,open.begin,open.end_byte);
    while (!at_end() && !is_punct('}')) node.children.push_back(statement());
    if (at_end() || !is_punct('}')) stmt_fail(StatementErrorCode::expected_rbrace,peek().begin);
    const auto close=take();
    node.end_byte=close.end_byte; node.token_begin=open.begin; node.token_end_byte=close.end_byte;
    return add_node(std::move(node));
  }
  std::size_t branch_block() {
    if (!is_punct('{')) stmt_fail(StatementErrorCode::expected_lbrace,peek().begin);
    return block();
  }
  std::size_t declaration(bool is_mutable) {
    const auto begin=take().begin;
    const auto name=expect_identifier();
    if (is_punct(':')) {
      take();
      while (!at_end() && !is_punct('=') && !is_punct(';')) take();
    }
    if (!is_op("=")) stmt_fail(StatementErrorCode::unexpected_token,peek().begin);
    take();
    const auto expression=simple_expression();
    if (!is_punct(';')) stmt_fail(StatementErrorCode::expected_semicolon,peek().begin);
    const auto end=take().end_byte;
    auto node=make_node(is_mutable ? StatementKind::var_stmt : StatementKind::let_stmt,begin,end);
    node.expression=expression; node.spelling=std::string(name);
    return add_node(std::move(node));
  }
  std::size_t conditional() {
    const Depth guard(depth_,depth_limit,peek().begin);
    const auto begin=take().begin;
    const auto condition=simple_expression();
    const auto yes=branch_block();
    auto node=make_node(StatementKind::if_stmt,begin,ast_.nodes_[yes].end_byte);
    node.expression=condition; node.children.push_back(yes);
    if (is_keyword("else")) {
      const auto else_token=take();
      if (is_keyword("if")) node.children.push_back(conditional());
      else node.children.push_back(branch_block());
      node.end_byte=ast_.nodes_[node.children.back()].end_byte;
      node.token_end_byte=else_token.end_byte;
    }
    return add_node(std::move(node));
  }
  std::size_t while_loop() {
    const auto begin=take().begin;
    const auto condition=simple_expression();
    const LoopScope loops(loop_depth_);
    const auto body=branch_block();
    auto node=make_node(StatementKind::while_stmt,begin,ast_.nodes_[body].end_byte);
    node.expression=condition; node.children.push_back(body);
    return add_node(std::move(node));
  }
  std::size_t for_loop() {
    const auto begin=take().begin;
    const auto name=expect_identifier();
    if (!is_keyword("in")) stmt_fail(StatementErrorCode::expected_in,peek().begin);
    take();
    const auto iterable=simple_expression();
    const LoopScope loops(loop_depth_);
    const auto body=branch_block();
    auto node=make_node(StatementKind::for_stmt,begin,ast_.nodes_[body].end_byte);
    node.expression=iterable; node.children.push_back(body); node.spelling=std::string(name);
    return add_node(std::move(node));
  }
  std::size_t infinite_loop() {
    const auto begin=take().begin;
    const LoopScope loops(loop_depth_);
    const auto body=branch_block();
    auto node=make_node(StatementKind::loop_stmt,begin,ast_.nodes_[body].end_byte);
    node.children.push_back(body);
    return add_node(std::move(node));
  }
  std::size_t match_stmt() {
    const auto begin=take().begin;
    const auto subject=simple_expression();
    if (!is_punct('{')) stmt_fail(StatementErrorCode::expected_lbrace,peek().begin);
    const auto open=take();
    auto node=make_node(StatementKind::match_stmt,begin,open.end_byte);
    node.expression=subject;
    while (!at_end() && !is_punct('}')) {
      const auto arm_begin=peek().begin;
      const auto first=pos_;
      int nesting=0;
      while (!at_end()) {
        const auto& token=peek();
        const auto value=text(token);
        if (token.kind==TokenKind::punctuation && (value=="(" || value=="[")) { ++nesting; take(); continue; }
        if (token.kind==TokenKind::punctuation && (value==")" || value=="]")) { if (nesting>0) --nesting; take(); continue; }
        if (nesting==0 && token.kind==TokenKind::op && value=="=>") break;
        if (nesting==0 && token.kind==TokenKind::punctuation && (value=="," || value=="}" || value=="{")) break;
        take();
      }
      if (pos_==first || at_end() || peek().kind!=TokenKind::op || text(peek())!="=>")
        stmt_fail(StatementErrorCode::expected_arrow,peek().begin);
      const auto pattern_end=tokens_[pos_-1].end_byte;
      take();
      const auto body=branch_block();
      auto arm=make_node(StatementKind::match_arm,arm_begin,ast_.nodes_[body].end_byte);
      arm.spelling=std::string(source_.substr(tokens_[first].begin.byte,pattern_end-tokens_[first].begin.byte));
      arm.children.push_back(body);
      node.children.push_back(add_node(std::move(arm)));
      node.end_byte=ast_.nodes_[body].end_byte;
      if (is_punct(',')) take();
    }
    if (at_end() || !is_punct('}')) stmt_fail(StatementErrorCode::expected_rbrace,peek().begin);
    const auto close=take();
    node.end_byte=close.end_byte; node.token_end_byte=close.end_byte;
    return add_node(std::move(node));
  }
  std::size_t guard_stmt() {
    const auto begin=take().begin;
    const auto condition=simple_expression();
    expect_keyword("else");
    const auto body=branch_block();
    auto node=make_node(StatementKind::guard_stmt,begin,ast_.nodes_[body].end_byte);
    node.expression=condition; node.children.push_back(body);
    return add_node(std::move(node));
  }
  std::size_t jump(StatementKind kind,StatementErrorCode outside) {
    const auto begin=take().begin;
    if (loop_depth_==0) stmt_fail(outside,begin);
    if (!is_punct(';')) stmt_fail(StatementErrorCode::expected_semicolon,peek().begin);
    const auto end=take().end_byte;
    return add_node(make_node(kind,begin,end));
  }
  std::size_t return_stmt() {
    const auto begin=take().begin;
    if (is_punct(';')) {
      const auto end=take().end_byte;
      return add_node(make_node(StatementKind::return_stmt,begin,end));
    }
    const auto expression=simple_expression();
    if (!is_punct(';')) stmt_fail(StatementErrorCode::expected_semicolon,peek().begin);
    const auto end=take().end_byte;
    auto node=make_node(StatementKind::return_stmt,begin,end);
    node.expression=expression;
    return add_node(std::move(node));
  }
  std::size_t statement() {
    const Depth guard(depth_,depth_limit,peek().begin);
    if (is_punct('{')) return block();
    if (is_keyword("let")) return declaration(false);
    if (is_keyword("var")) return declaration(true);
    if (is_keyword("if")) return conditional();
    if (is_keyword("while")) return while_loop();
    if (is_keyword("for")) return for_loop();
    if (is_keyword("loop")) return infinite_loop();
    if (is_keyword("match")) return match_stmt();
    if (is_keyword("guard")) return guard_stmt();
    if (is_keyword("break")) return jump(StatementKind::break_stmt,StatementErrorCode::break_outside_loop);
    if (is_keyword("continue")) return jump(StatementKind::continue_stmt,StatementErrorCode::continue_outside_loop);
    if (is_keyword("return")) return return_stmt();
    if (at_end() || is_punct('}')) stmt_fail(StatementErrorCode::expected_statement,peek().begin);
    const auto begin=peek().begin;
    const auto expression=simple_expression();
    if (!is_punct(';')) stmt_fail(StatementErrorCode::expected_semicolon,peek().begin);
    const auto end=take().end_byte;
    auto node=make_node(StatementKind::expression,begin,end);
    node.expression=expression;
    return add_node(std::move(node));
  }
 public:
  StatementParser(std::string_view source,std::vector<Token> tokens):source_(source),tokens_(std::move(tokens)) {}
  StatementResult run() {
    if (tokens_.empty() || tokens_.back().kind!=TokenKind::end) throw std::logic_error("lexer did not produce EOF");
    auto root=block();
    if (!at_end()) stmt_fail(StatementErrorCode::unexpected_token,peek().begin);
    ast_.root_=root;
    return std::move(ast_);
  }
};
} // namespace detail

StatementResult parse_statements(std::string_view source,LexOptions options) {
  auto result=lex(source,options);
  if (auto* error=std::get_if<Diagnostic>(&result)) return *error;
  try {
    return detail::StatementParser(source,std::get<std::vector<Token>>(std::move(result))).run();
  } catch (const detail::StatementFailure& failure) {
    return failure.result;
  }
}
StatementResult parse_statements(std::string_view source, const std::vector<Token>& tokens, std::size_t first, std::size_t last) {
  if (first>last || last>tokens.size()) throw std::invalid_argument("invalid statement token range");
  std::vector<Token> subset(tokens.begin()+static_cast<std::ptrdiff_t>(first),tokens.begin()+static_cast<std::ptrdiff_t>(last));
  const Position end_position=last<tokens.size() ? tokens[last].begin : Position{source.size(),1,1};
  subset.push_back({TokenKind::end,end_position,end_position.byte});
  try {
    return detail::StatementParser(source,std::move(subset)).run();
  } catch (const detail::StatementFailure& failure) {
    return failure.result;
  }
}
std::string_view name(StatementErrorCode code) {
  constexpr auto names=std::to_array<std::string_view>({
    "expected_statement","expected_identifier","expected_expression","expected_semicolon",
    "expected_lbrace","expected_rbrace","expected_else","expected_in","expected_arrow",
    "break_outside_loop","continue_outside_loop","depth_exceeded","unexpected_token"});
  return names.at(static_cast<std::size_t>(code));
}
std::string dump_statement_ast(const StatementAst& ast) {
  const auto nodes=ast.nodes();
  const auto expressions=ast.expressions();
  if (ast.root()>=nodes.size() || nodes.empty()) throw std::invalid_argument("empty or moved-from statement AST");
  enum class Action { visit, close, raw };
  struct Task { Action action; std::size_t index; std::string text; };
  std::vector<Task> stack{{Action::visit,ast.root(),{}}};
  auto kind_name=[](StatementKind k)->std::string_view {
    switch (k) {
      case StatementKind::block: return "block";
      case StatementKind::let_stmt: return "let";
      case StatementKind::var_stmt: return "var";
      case StatementKind::expression: return "expr";
      case StatementKind::if_stmt: return "if";
      case StatementKind::while_stmt: return "while";
      case StatementKind::for_stmt: return "for";
      case StatementKind::loop_stmt: return "loop";
      case StatementKind::match_stmt: return "match";
      case StatementKind::match_arm: return "arm";
      case StatementKind::guard_stmt: return "guard";
      case StatementKind::break_stmt: return "break";
      case StatementKind::continue_stmt: return "continue";
      case StatementKind::return_stmt: return "return";
    }
    return "?";
  };
  std::string out;
  while (!stack.empty()) {
    const auto task=std::move(stack.back()); stack.pop_back();
    if (task.action==Action::raw) { out+=task.text; continue; }
    if (task.action==Action::close) { out+=')'; continue; }
    const auto& node=nodes[task.index];
    out+='('; out+=kind_name(node.kind);
    if (!node.spelling.empty()) { out+=' '; detail::quoted(out,node.spelling); }
    if (node.expression!=no_statement && node.expression<expressions.size()) {
      auto text=dump_ast(expressions[node.expression]);
      if (!text.empty() && text.back()=='\n') text.pop_back();
      out+=' '; out+=text;
    }
    stack.push_back({Action::close,0,{}});
    for (auto i=node.children.size();i-->0;) {
      if (node.children[i]>=nodes.size()) throw std::invalid_argument("invalid statement child index");
      stack.push_back({Action::visit,node.children[i],{}});
      stack.push_back({Action::raw,0," "});
    }
  }
  out+='\n';
  return out;
}
} // namespace poko::mute
