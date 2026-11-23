#include "poko/mute/declaration.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace poko::mute {
namespace detail {
struct DeclarationFailure { DeclarationResult result; };
[[noreturn]] void decl_fail(DeclarationErrorCode code, Position pos) {
  throw DeclarationFailure{DeclarationDiagnostic{code,pos}};
}
void decl_quoted(std::string& out, std::string_view text) {
  constexpr char hex[]="0123456789abcdef";
  out+='"';
  for (unsigned char byte:text) {
    if (byte>=32 && byte<=126 && byte!='"' && byte!='\\') out+=static_cast<char>(byte);
    else { out+="\\x"; out+=hex[byte>>4]; out+=hex[byte&15]; }
  }
  out+='"';
}
class DeclarationParser {
  static constexpr std::size_t depth_limit=64;
  std::string_view source_;
  std::vector<Token> tokens_;
  std::size_t pos_{}, depth_{};
  DeclarationAst ast_;

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
  [[nodiscard]] bool is_name(std::string_view word) const {
    return is_name(word,peek());
  }
  [[nodiscard]] bool is_name(std::string_view word,const Token& t) const {
    return t.kind==TokenKind::identifier && text(t)==word;
  }
  void expect_punct(char c,DeclarationErrorCode code=DeclarationErrorCode::unexpected_token) {
    if (!is_punct(c)) decl_fail(code,peek().begin);
    take();
  }
  void expect_keyword(std::string_view word) {
    if (!is_keyword(word)) decl_fail(DeclarationErrorCode::unexpected_token,peek().begin);
    take();
  }
  std::string_view expect_identifier() {
    if (peek().kind!=TokenKind::identifier) decl_fail(DeclarationErrorCode::expected_identifier,peek().begin);
    return text(take());
  }
  std::string_view expect_string() {
    if (peek().kind!=TokenKind::string_literal) decl_fail(DeclarationErrorCode::expected_string,peek().begin);
    return text(take());
  }
  struct Depth {
    std::size_t& value;
    explicit Depth(std::size_t& v,std::size_t limit,Position at):value(v) {
      if (value>=limit) decl_fail(DeclarationErrorCode::depth_exceeded,at);
      ++value;
    }
    ~Depth() { --value; }
    Depth(const Depth&)=delete;
    Depth& operator=(const Depth&)=delete;
  };
  [[nodiscard]] static DeclarationNode make_node(DeclarationKind kind,Position begin,std::size_t end_byte) {
    DeclarationNode node;
    node.kind=kind; node.begin=begin; node.end_byte=end_byte;
    node.token_begin=begin; node.token_end_byte=end_byte;
    return node;
  }
  std::size_t add_node(DeclarationNode node) {
    const auto index=ast_.nodes_.size();
    ast_.nodes_.push_back(std::move(node));
    return index;
  }
  std::size_t add_type(TypeNode node) {
    const auto index=ast_.types_.size();
    ast_.types_.push_back(std::move(node));
    return index;
  }
  // Nested generics may lex `>>` as one token; split it into two closing `>`.
  void split_shift() {
    if (peek().kind==TokenKind::op && text(peek())==">>") {
      const auto original=tokens_[pos_];
      auto& token=tokens_[pos_];
      token.end_byte=token.begin.byte+1;
      tokens_.insert(tokens_.begin()+static_cast<std::ptrdiff_t>(pos_)+1,
        Token{TokenKind::op,{original.begin.byte+1,original.begin.line,original.begin.column+1},original.end_byte});
    }
  }
  std::size_t type() {
    const Depth guard(depth_,depth_limit,peek().begin);
    const auto begin=peek().begin;
    if (is_punct('(')) {
      take();
      TypeNode node;
      node.kind=TypeKind::tuple; node.begin=begin; node.token_begin=begin;
      if (!is_punct(')')) {
        for (;;) {
          node.args.push_back(type());
          if (!is_punct(',')) break;
          take();
        }
      }
      if (!is_punct(')')) decl_fail(DeclarationErrorCode::expected_rparen,peek().begin);
      const auto close=take();
      node.end_byte=close.end_byte; node.token_end_byte=close.end_byte;
      return add_type(std::move(node));
    }
    if (peek().kind!=TokenKind::identifier) decl_fail(DeclarationErrorCode::expected_type,peek().begin);
    auto name=std::string(expect_identifier());
    while (is_op("::") || is_punct('.')) {
      take();
      name+=(tokens_[pos_-1].kind==TokenKind::op ? "::" : ".");
      name+=expect_identifier();
    }
    TypeNode node;
    node.kind=TypeKind::named; node.begin=begin; node.token_begin=begin;
    node.end_byte=tokens_[pos_-1].end_byte; node.token_end_byte=node.end_byte;
    node.spelling=std::move(name);
    if (is_op("<")) {
      take();
      node.kind=TypeKind::generic;
      for (;;) {
        split_shift();
        node.args.push_back(type());
        split_shift();
        if (is_op(">")) { const auto close=take(); node.end_byte=close.end_byte; node.token_end_byte=close.end_byte; break; }
        if (!is_punct(',')) decl_fail(DeclarationErrorCode::unexpected_token,peek().begin);
        take();
      }
    }
    return add_type(std::move(node));
  }
  std::size_t expression_until(std::string_view stop,DeclarationErrorCode code) {
    const auto first=pos_;
    while (!at_end()) {
      if (peek().kind==TokenKind::punctuation && text(peek())==stop) break;
      take();
    }
    if (first==pos_) decl_fail(code,peek().begin);
    auto result=parse_arithmetic(source_,tokens_,first,pos_);
    if (auto* error=std::get_if<Diagnostic>(&result)) throw DeclarationFailure{*error};
    if (auto* error=std::get_if<ParseDiagnostic>(&result)) throw DeclarationFailure{*error};
    ast_.values_.push_back(std::move(std::get<Ast>(result)));
    return ast_.values_.size()-1;
  }
  std::pair<std::size_t,std::size_t> block_range() {
    if (!is_punct('{')) decl_fail(DeclarationErrorCode::expected_lbrace,peek().begin);
    const auto open=pos_;
    std::size_t nesting=1;
    take(); // opening brace
    while (!at_end()) {
      const auto& token=peek();
      if (token.kind==TokenKind::punctuation && text(token)=="{") ++nesting;
      else if (token.kind==TokenKind::punctuation && text(token)=="}") {
        if (nesting==0) break;
        if (--nesting==0) break;
      }
      take();
    }
    if (at_end()) decl_fail(DeclarationErrorCode::expected_rbrace,peek().begin);
    const auto close=pos_;
    take();
    return {open,close+1};
  }
  std::size_t body(std::size_t open,std::size_t last) {
    auto result=parse_statements(source_,tokens_,open,last);
    if (auto* error=std::get_if<Diagnostic>(&result)) throw DeclarationFailure{*error};
    if (auto* error=std::get_if<ParseDiagnostic>(&result)) throw DeclarationFailure{*error};
    if (auto* error=std::get_if<StatementDiagnostic>(&result)) throw DeclarationFailure{*error};
    ast_.bodies_.push_back(std::move(std::get<StatementAst>(result)));
    return ast_.bodies_.size()-1;
  }
  std::size_t attribute() {
    const auto begin=take().begin; // '@'
    const auto name_begin=peek().begin;
    auto spelling=std::string("@")+std::string(expect_identifier());
    const auto name=spelling.substr(1);
    constexpr auto deferred=std::to_array<std::string_view>({"rpc","clientOnly","authorityOnly"});
    if (std::find(deferred.begin(),deferred.end(),name)!=deferred.end())
      decl_fail(DeclarationErrorCode::unsupported_attribute,name_begin);
    if (is_punct('(')) {
      const auto open=take();
      spelling+=text(open);
      std::size_t nesting=0;
      while (!at_end()) {
        const auto& token=peek();
        if (token.kind==TokenKind::punctuation && text(token)=="(") ++nesting;
        else if (token.kind==TokenKind::punctuation && text(token)==")") {
          if (nesting==0) break;
          --nesting;
        }
        spelling+=text(take());
      }
      if (!is_punct(')')) decl_fail(DeclarationErrorCode::expected_rparen,peek().begin);
      spelling+=text(take());
    }
    auto node=make_node(DeclarationKind::attribute,begin,tokens_[pos_-1].end_byte);
    node.spelling=std::move(spelling);
    return add_node(std::move(node));
  }
  std::size_t field() {
    const auto begin=peek().begin;
    auto node=make_node(DeclarationKind::field,begin,0);
    node.spelling=std::string(expect_identifier());
    if (!is_punct(':')) decl_fail(DeclarationErrorCode::expected_colon,peek().begin);
    take();
    node.type=type();
    node.end_byte=ast_.types_[node.type].end_byte;
    node.token_end_byte=node.end_byte;
    return add_node(std::move(node));
  }
  std::size_t struct_decl(const std::vector<std::size_t>& attributes) {
    const auto begin=take().begin;
    auto node=make_node(DeclarationKind::struct_decl,begin,0);
    node.spelling=std::string(expect_identifier());
    node.children=attributes;
    expect_punct('{',DeclarationErrorCode::expected_lbrace);
    if (!is_punct('}')) {
      for (;;) {
        node.children.push_back(field());
        if (!is_punct(',')) break;
        take();
        if (is_punct('}')) break;
      }
    }
    if (!is_punct('}')) decl_fail(DeclarationErrorCode::expected_rbrace,peek().begin);
    const auto close=take();
    node.end_byte=close.end_byte; node.token_end_byte=close.end_byte;
    return add_node(std::move(node));
  }
  std::size_t enum_decl(const std::vector<std::size_t>& attributes) {
    const auto begin=take().begin;
    auto node=make_node(DeclarationKind::enum_decl,begin,0);
    node.spelling=std::string(expect_identifier());
    node.children=attributes;
    expect_punct('{',DeclarationErrorCode::expected_lbrace);
    if (!is_punct('}')) {
      for (;;) {
        const auto variant_begin=peek().begin;
        auto variant=make_node(DeclarationKind::variant,variant_begin,0);
        variant.spelling=std::string(expect_identifier());
        if (is_punct('(')) {
          take();
          if (!is_punct(')')) {
            for (;;) {
              variant.children.push_back(type());
              if (!is_punct(',')) break;
              take();
            }
          }
          if (!is_punct(')')) decl_fail(DeclarationErrorCode::expected_rparen,peek().begin);
          take();
        }
        variant.end_byte=tokens_[pos_-1].end_byte; variant.token_end_byte=variant.end_byte;
        node.children.push_back(add_node(std::move(variant)));
        if (!is_punct(',')) break;
        take();
        if (is_punct('}')) break;
      }
    }
    if (!is_punct('}')) decl_fail(DeclarationErrorCode::expected_rbrace,peek().begin);
    const auto close=take();
    node.end_byte=close.end_byte; node.token_end_byte=close.end_byte;
    return add_node(std::move(node));
  }
  std::size_t state_decl(const std::vector<std::size_t>& attributes) {
    const auto begin=peek().begin;
    for (std::size_t i=0;i<2;++i) take(); // '@' 'state'
    expect_keyword("var");
    auto node=make_node(DeclarationKind::state_decl,begin,0);
    node.spelling=std::string(expect_identifier());
    node.children=attributes;
    if (!is_punct(':')) decl_fail(DeclarationErrorCode::expected_colon,peek().begin);
    take();
    node.type=type();
    if (!is_op("=")) decl_fail(DeclarationErrorCode::expected_equal,peek().begin);
    take();
    const auto first=pos_;
    for (;;) {
      if (at_end() || is_punct(';')) break;
      take();
      if (at_end() || is_punct(';')) break;
      const auto& next=peek();
      const auto value=text(next);
      constexpr auto starts=std::to_array<std::string_view>({
        "struct","enum","fn","package","version","allow","import"});
      const bool declaration_start=next.kind==TokenKind::keyword &&
        std::find(starts.begin(),starts.end(),value)!=starts.end();
      const bool state_attribute=is_punct('@') && is_name("state",peek(1));
      if (declaration_start || state_attribute) break;
    }
    if (first==pos_) decl_fail(DeclarationErrorCode::expected_expression,peek().begin);
    auto value=parse_arithmetic(source_,tokens_,first,pos_);
    if (auto* error=std::get_if<Diagnostic>(&value)) throw DeclarationFailure{*error};
    if (auto* error=std::get_if<ParseDiagnostic>(&value)) throw DeclarationFailure{*error};
    ast_.values_.push_back(std::move(std::get<Ast>(value)));
    node.value=ast_.values_.size()-1;
    if (is_punct(';')) take();
    node.end_byte=tokens_[pos_-1].end_byte; node.token_end_byte=node.end_byte;
    return add_node(std::move(node));
  }
  std::size_t fn_decl(const std::vector<std::size_t>& attributes) {
    const auto begin=peek().begin;
    if (is_keyword("pub")) take();
    const bool is_async=is_keyword("async");
    if (is_async) take();
    expect_keyword("fn");
    auto node=make_node(DeclarationKind::fn_decl,begin,0);
    node.spelling=std::string(expect_identifier());
    node.children=attributes;
    expect_punct('(');
    if (!is_punct(')')) {
      for (;;) {
        const auto param_begin=peek().begin;
        auto param=make_node(DeclarationKind::param,param_begin,0);
        param.spelling=std::string(expect_identifier());
        if (!is_punct(':')) decl_fail(DeclarationErrorCode::expected_colon,peek().begin);
        take();
        param.type=type();
        param.end_byte=ast_.types_[param.type].end_byte; param.token_end_byte=param.end_byte;
        node.children.push_back(add_node(std::move(param)));
        if (!is_punct(',')) break;
        take();
      }
    }
    if (!is_punct(')')) decl_fail(DeclarationErrorCode::expected_rparen,peek().begin);
    take();
    if (is_op("->")) {
      take();
      node.type=type();
    }
    const auto [open,last]=block_range();
    node.body=body(open,last);
    node.end_byte=tokens_[last-1].end_byte; node.token_end_byte=node.end_byte;
    return add_node(std::move(node));
  }
 public:
  DeclarationParser(std::string_view source,std::vector<Token> tokens):source_(source),tokens_(std::move(tokens)) {}
  DeclarationResult run() {
    if (tokens_.empty() || tokens_.back().kind!=TokenKind::end) throw std::logic_error("lexer did not produce EOF");
    auto module=make_node(DeclarationKind::module,peek().begin,0);
    while (!at_end()) {
      std::vector<std::size_t> attributes;
      while (is_punct('@')) {
        if (is_name("state",peek(1)) && peek(2).kind==TokenKind::keyword && text(peek(2))=="var") break;
        attributes.push_back(attribute());
      }
      if (is_punct('@') && is_name("state",peek(1))) {
        module.children.push_back(state_decl(attributes));
        continue;
      }
      if (is_keyword("struct")) { module.children.push_back(struct_decl(attributes)); continue; }
      if (is_keyword("enum")) { module.children.push_back(enum_decl(attributes)); continue; }
      if (is_keyword("fn") || is_keyword("async") || is_keyword("pub")) {
        module.children.push_back(fn_decl(attributes));
        continue;
      }
      if (is_keyword("package") || is_keyword("version")) {
        const auto begin=peek().begin;
        const auto kind=is_keyword("package") ? DeclarationKind::package : DeclarationKind::version;
        take();
        auto node=make_node(kind,begin,0);
        node.spelling=std::string(expect_string());
        node.end_byte=tokens_[pos_-1].end_byte; node.token_end_byte=node.end_byte;
        module.children.push_back(add_node(std::move(node)));
        continue;
      }
      if (is_keyword("allow")) {
        const auto begin=take().begin;
        auto node=make_node(DeclarationKind::allow,begin,0);
        if (!is_punct(':')) decl_fail(DeclarationErrorCode::expected_colon,peek().begin);
        take();
        for (;;) {
          node.children.push_back(add_node([&]{
            auto item=make_node(DeclarationKind::field,peek().begin,0);
            item.spelling=std::string(expect_identifier());
            item.end_byte=tokens_[pos_-1].end_byte; item.token_end_byte=item.end_byte;
            return item;
          }()));
          if (!is_punct(',')) break;
          take();
        }
        node.end_byte=tokens_[pos_-1].end_byte; node.token_end_byte=node.end_byte;
        module.children.push_back(add_node(std::move(node)));
        continue;
      }
      if (is_keyword("import")) {
        const auto begin=take().begin;
        auto node=make_node(DeclarationKind::import,begin,0);
        node.spelling=std::string(expect_string());
        expect_keyword("as");
        node.children.push_back(add_node([&]{
          auto alias=make_node(DeclarationKind::field,peek().begin,0);
          alias.spelling=std::string(expect_identifier());
          alias.end_byte=tokens_[pos_-1].end_byte; alias.token_end_byte=alias.end_byte;
          return alias;
        }()));
        node.end_byte=tokens_[pos_-1].end_byte; node.token_end_byte=node.end_byte;
        module.children.push_back(add_node(std::move(node)));
        continue;
      }
      decl_fail(DeclarationErrorCode::expected_declaration,peek().begin);
    }
    module.end_byte=source_.size();
    module.token_end_byte=module.end_byte;
    ast_.root_=add_node(std::move(module));
    return std::move(ast_);
  }
};
} // namespace detail

DeclarationResult parse_declarations(std::string_view source,LexOptions options) {
  auto result=lex(source,options);
  if (auto* error=std::get_if<Diagnostic>(&result)) return *error;
  try {
    return detail::DeclarationParser(source,std::get<std::vector<Token>>(std::move(result))).run();
  } catch (const detail::DeclarationFailure& failure) {
    return failure.result;
  }
}
std::string_view name(DeclarationErrorCode code) {
  constexpr auto names=std::to_array<std::string_view>({
    "expected_declaration","expected_identifier","expected_type","expected_lbrace",
    "expected_rbrace","expected_rparen","expected_semicolon","expected_colon",
    "expected_arrow","expected_equal","expected_string","expected_expression",
    "unsupported_attribute","depth_exceeded","unexpected_token"});
  return names.at(static_cast<std::size_t>(code));
}
std::string dump_declaration_ast(const DeclarationAst& ast) {
  const auto nodes=ast.nodes();
  const auto types=ast.types();
  const auto values=ast.values();
  const auto bodies=ast.bodies();
  if (ast.root()>=nodes.size() || nodes.empty()) throw std::invalid_argument("empty or moved-from declaration AST");
  enum class Action { visit_type, visit_node, visit_value, visit_body, close, raw };
  struct Task { Action action; std::size_t index; std::string text; };
  std::vector<Task> stack{{Action::visit_node,ast.root(),{}}};
  auto kind_name=[](DeclarationKind k)->std::string_view {
    switch (k) {
      case DeclarationKind::module: return "module";
      case DeclarationKind::package: return "package";
      case DeclarationKind::version: return "version";
      case DeclarationKind::allow: return "allow";
      case DeclarationKind::import: return "import";
      case DeclarationKind::struct_decl: return "struct";
      case DeclarationKind::enum_decl: return "enum";
      case DeclarationKind::field: return "field";
      case DeclarationKind::variant: return "variant";
      case DeclarationKind::state_decl: return "state";
      case DeclarationKind::fn_decl: return "fn";
      case DeclarationKind::param: return "param";
      case DeclarationKind::attribute: return "attr";
    }
    return "?";
  };
  std::string out;
  while (!stack.empty()) {
    const auto task=std::move(stack.back()); stack.pop_back();
    if (task.action==Action::raw) { out+=task.text; continue; }
    if (task.action==Action::close) { out+=')'; continue; }
    if (task.action==Action::visit_type) {
      if (task.index>=types.size()) throw std::invalid_argument("invalid type index");
      const auto& type=types[task.index];
      out+='(';
      out+=type.kind==TypeKind::tuple ? "tuple" : type.kind==TypeKind::generic ? "generic" : "named";
      if (!type.spelling.empty()) { out+=' '; detail::decl_quoted(out,type.spelling); }
      stack.push_back({Action::close,0,{}});
      for (auto i=type.args.size();i-->0;) {
        stack.push_back({Action::visit_type,type.args[i],{}});
        stack.push_back({Action::raw,0," "});
      }
      continue;
    }
    if (task.action==Action::visit_value) {
      if (task.index>=values.size()) throw std::invalid_argument("invalid value index");
      auto text=dump_ast(values[task.index]);
      if (!text.empty() && text.back()=='\n') text.pop_back();
      out+=text; continue;
    }
    if (task.action==Action::visit_body) {
      if (task.index>=bodies.size()) throw std::invalid_argument("invalid body index");
      auto text=dump_statement_ast(bodies[task.index]);
      if (!text.empty() && text.back()=='\n') text.pop_back();
      out+=text; continue;
    }
    const auto& node=nodes[task.index];
    out+='('; out+=kind_name(node.kind);
    if (!node.spelling.empty()) { out+=' '; detail::decl_quoted(out,node.spelling); }
    stack.push_back({Action::close,0,{}});
    if (node.body!=no_declaration) {
      stack.push_back({Action::visit_body,node.body,{}});
      stack.push_back({Action::raw,0," "});
    }
    if (node.value!=no_declaration) {
      stack.push_back({Action::visit_value,node.value,{}});
      stack.push_back({Action::raw,0," "});
    }
    if (node.type!=no_declaration) {
      stack.push_back({Action::visit_type,node.type,{}});
      stack.push_back({Action::raw,0," "});
    }
    // Variant payload children are type indices; all other children are nodes.
    const bool type_children=node.kind==DeclarationKind::variant;
    for (auto i=node.children.size();i-->0;) {
      if (type_children) {
        if (node.children[i]>=types.size()) throw std::invalid_argument("invalid variant type index");
        stack.push_back({Action::visit_type,node.children[i],{}});
      } else {
        if (node.children[i]>=nodes.size()) throw std::invalid_argument("invalid declaration child index");
        stack.push_back({Action::visit_node,node.children[i],{}});
      }
      stack.push_back({Action::raw,0," "});
    }
  }
  out+='\n';
  return out;
}
} // namespace poko::mute
