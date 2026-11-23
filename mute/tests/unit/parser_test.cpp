#include "poko/mute/parser.hpp"
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool valid, std::string_view description) {
  if (!valid) { std::cerr << description << '\n'; ++failures; }
}
void tree(std::string_view input, std::string_view expected) {
  auto result=parse_arithmetic(input);
  const auto* ast=std::get_if<Ast>(&result);
  if (!ast) { std::cerr << "did not parse: " << input << '\n'; ++failures; return; }
  if (dump_ast(*ast)!=expected) { std::cerr << "unexpected AST for: " << input << '\n' << dump_ast(*ast); ++failures; }
  const auto nodes=ast->nodes();
  check(ast->root()<nodes.size(),"root out of range");
  for (std::size_t i=0; i<nodes.size(); ++i) {
    const auto& n=nodes[i];
    check(n.begin.byte<=n.token_begin.byte && n.token_end_byte<=n.end_byte && n.end_byte<=input.size(),"bad node span");
    if (n.kind==ExprKind::unary || n.kind==ExprKind::binary || n.kind==ExprKind::call ||
        n.kind==ExprKind::index || n.kind==ExprKind::member || n.kind==ExprKind::question ||
        n.kind==ExprKind::await) check(n.left<i,"left child not earlier");
    if (n.kind==ExprKind::binary || n.kind==ExprKind::index) check(n.right<i,"right child not earlier");
    else check(n.right==no_node,"unexpected right child");
    if (n.kind==ExprKind::call) for (const auto c:n.children) check(c<i,"call arg not earlier");
    else check(n.children.empty(),"unexpected children");
  }
}
void parse_error(std::string_view input, ParseErrorCode code, std::size_t byte, std::size_t line, std::size_t col) {
  auto result=parse_arithmetic(input); auto p=std::get_if<ParseDiagnostic>(&result);
  if (!p || p->code!=code || p->position.byte!=byte || p->position.line!=line || p->position.column!=col) {
    std::cerr << "wrong parse error in: " << input << '\n'; ++failures;
  }
}
void cases() {
  tree("1 + 2 * 3", "(binary + (integer \"1\") (binary * (integer \"2\") (integer \"3\")))\n");
  tree("(1 + 2) * 3", "(binary * (binary + (integer \"1\") (integer \"2\")) (integer \"3\"))\n");
  tree("8-3-2", "(binary - (binary - (integer \"8\") (integer \"3\")) (integer \"2\"))\n");
  tree("8/4*2%3", "(binary % (binary * (binary / (integer \"8\") (integer \"4\")) (integer \"2\")) (integer \"3\"))\n");
  tree("- -x * +2.5f64", "(binary * (unary - (unary - (identifier \"x\"))) (unary + (floating \"2.5f64\")))\n");
  tree("((0xffu8)) + caf\xc3\xa9", "(binary + (integer \"0xffu8\") (identifier \"caf\\xc3\\xa9\"))\n");
  tree("1 /* hi */ +\r\n 2 // ignored", "(binary + (integer \"1\") (integer \"2\"))\n");
  tree("1/0", "(binary / (integer \"1\") (integer \"0\"))\n"); // Parsing does not evaluate.
  parse_error("",ParseErrorCode::expected_expression,0,1,1);
  parse_error("1 +",ParseErrorCode::expected_expression,3,1,4);
  tree("()","(unit)\n");
  parse_error("(1+2",ParseErrorCode::expected_closing_parenthesis,4,1,5);
  parse_error("(1+2))",ParseErrorCode::unexpected_closing_parenthesis,5,1,6);
  parse_error("1 2",ParseErrorCode::unexpected_token,2,1,3);
  tree("1 << 2", "(binary << (integer \"1\") (integer \"2\"))\n");
  tree("a || b && c", "(binary || (identifier \"a\") (binary && (identifier \"b\") (identifier \"c\")))\n");
  tree("a | b ^ c & d", "(binary | (identifier \"a\") (binary ^ (identifier \"b\") (binary & (identifier \"c\") (identifier \"d\"))))\n");
  tree("a << b + c", "(binary << (identifier \"a\") (binary + (identifier \"b\") (identifier \"c\")))\n");
  tree("a == b < c", "(binary == (identifier \"a\") (binary < (identifier \"b\") (identifier \"c\")))\n");
  tree("a..b..=c", "(binary ..= (binary .. (identifier \"a\") (identifier \"b\")) (identifier \"c\"))\n");
  tree("x = y += 1", "(binary = (identifier \"x\") (binary += (identifier \"y\") (integer \"1\")))\n");
  tree("f(1, g(2)).name[0]?", "(question (index (member (call (identifier \"f\") (integer \"1\") (call (identifier \"g\") (integer \"2\"))) \"name\") (integer \"0\")))\n");
  tree("await net.request(\"x\")?", "(await (question (call (member (identifier \"net\") \"request\") (string \"\\x22x\\x22\"))))\n");
  tree("!ok && move(x)", "(binary && (unary ! (identifier \"ok\")) (unary move (identifier \"x\")))\n");
  tree("true", "(boolean \"true\")\n");
  parse_error("1\r\n * )",ParseErrorCode::expected_expression,6,2,4);
  parse_error("/// doc\n1",ParseErrorCode::expected_expression,0,1,1);
  auto limited=parse_arithmetic("1+2",LexOptions{2});
  const auto* limit_error=std::get_if<Diagnostic>(&limited);
  check(limit_error && limit_error->code==ErrorCode::source_too_large,"parser source budget not propagated");
  check(std::holds_alternative<Ast>(parse_arithmetic("1+2",LexOptions{3})),"parser exact source budget");
  auto bad=parse_arithmetic("1 + 0b2");
  auto lex_error=std::get_if<Diagnostic>(&bad);
  check(lex_error && lex_error->code==ErrorCode::invalid_number && lex_error->position.byte==4,"lexer error not propagated");
  auto invalid=parse_arithmetic(std::string("1+\xff",3));
  lex_error=std::get_if<Diagnostic>(&invalid);
  check(lex_error && lex_error->code==ErrorCode::invalid_utf8 && lex_error->position.byte==2,"UTF-8 error not propagated");
  auto span=parse_arithmetic(" -( 12 ) ");
  if (auto ast=std::get_if<Ast>(&span)) {
    const auto nodes=ast->nodes(); const auto& root=nodes[ast->root()]; const auto& n=nodes[root.left];
    check(root.begin.byte==1 && root.end_byte==8 && root.token_begin.byte==1 && root.token_end_byte==2,"unary expression span");
    check(n.begin.byte==2 && n.end_byte==8 && n.token_begin.byte==4 && n.token_end_byte==6 && n.spelling=="12","group versus token span");
  } else check(false,"span test did not parse");
  // The result must remain valid once its original source is gone.
  ParseResult owned=[] { std::string source="number + 9"; return parse_arithmetic(source); }();
  if (auto ast=std::get_if<Ast>(&owned)) check(dump_ast(*ast)=="(binary + (identifier \"number\") (integer \"9\"))\n","AST borrows source");
  else check(false,"owned source did not parse");
  if (auto old=std::get_if<Ast>(&owned)) {
    Ast moved=std::move(*old);
    check(dump_ast(moved)=="(binary + (identifier \"number\") (integer \"9\"))\n","moved AST changed");
    bool rejected=false;
    try { (void)dump_ast(*old); } catch (const std::invalid_argument&) { rejected=true; }
    check(rejected,"moved-from AST was not rejected");
    moved=std::move(moved);
    check(dump_ast(moved)=="(binary + (identifier \"number\") (integer \"9\"))\n","self-move damaged AST");
  }
}
void randomized_input() {
  std::mt19937 random(0x7202);
  for (int iteration=0;iteration<20000;++iteration) {
    std::string input; const auto count=random()%100;
    for (unsigned n=0;n<count;++n) input.push_back(static_cast<char>(random()%(iteration%2 ? 128 : 256)));
    auto result=parse_arithmetic(input);
    if (auto ast=std::get_if<Ast>(&result)) {
      const auto nodes=ast->nodes();
      check(ast->root()<nodes.size(),"randomized AST root invalid");
      for (std::size_t i=0;i<nodes.size();++i) {
        const auto& node=nodes[i];
        check(node.end_byte<=input.size(),"randomized node span invalid");
        if (node.kind==ExprKind::unary || node.kind==ExprKind::binary || node.kind==ExprKind::call ||
            node.kind==ExprKind::index || node.kind==ExprKind::member || node.kind==ExprKind::question ||
            node.kind==ExprKind::await) check(node.left<i,"randomized left invalid");
        if (node.kind==ExprKind::binary || node.kind==ExprKind::index) check(node.right<i,"randomized right invalid");
        if (node.kind==ExprKind::call) for (const auto c:node.children) check(c<i,"randomized call arg invalid");
      }
      (void)dump_ast(*ast);
    } else if (auto diagnostic=std::get_if<Diagnostic>(&result)) check(diagnostic->position.byte<=input.size(),"random lexical error offset invalid");
    else check(std::get<ParseDiagnostic>(result).position.byte<=input.size(),"random parser error offset invalid");
  }
}
void stress() {
  constexpr int count=30000;
  std::string unary(count,'-'); unary+='1';
  auto a=parse_arithmetic(unary);
  if (auto ast=std::get_if<Ast>(&a)) {
    check(ast->nodes().size()==static_cast<std::size_t>(count+1),"long unary chain size");
    auto dump=dump_ast(*ast); check(!dump.empty() && dump.back()=='\n',"long unary dump");
  } else check(false,"long unary chain failed");
  std::string parens(count,'('); parens+='1'; parens.append(count,')');
  auto b=parse_arithmetic(parens);
  if (auto ast=std::get_if<Ast>(&b)) check(ast->nodes().size()==1 && ast->nodes()[0].end_byte==parens.size(),"deep parenthesis span");
  else check(false,"deep parentheses failed");
  std::string chain="1"; for (int i=0;i<count;++i) chain += "+1";
  auto c=parse_arithmetic(chain);
  if (auto ast=std::get_if<Ast>(&c)) {
    check(ast->nodes().size()==static_cast<std::size_t>(2*count+1),"long binary chain size");
    auto dump=dump_ast(*ast); check(!dump.empty() && dump.back()=='\n',"long binary dump");
  } else check(false,"long binary chain failed");
}
}
int main() { cases(); stress(); randomized_input(); return failures ? 1 : 0; }
