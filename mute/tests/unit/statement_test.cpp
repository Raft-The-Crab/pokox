#include "poko/mute/statement.hpp"
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
void dump(std::string_view input, std::string_view expected) {
  auto result=parse_statements(input);
  const auto* ast=std::get_if<StatementAst>(&result);
  if (!ast) { std::cerr << "did not parse: " << input << '\n'; ++failures; return; }
  const auto output=dump_statement_ast(*ast);
  if (output!=expected) { std::cerr << "unexpected AST for " << input << '\n' << output; ++failures; }
  const auto nodes=ast->nodes();
  check(ast->root()<nodes.size(),"root out of range");
  for (std::size_t i=0;i<nodes.size();++i) {
    const auto& n=nodes[i];
    check(n.begin.byte<=n.token_begin.byte && n.token_end_byte<=n.end_byte,"bad node span");
    for (const auto child:n.children) check(child<i,"child not earlier");
  }
}
void error(std::string_view input, StatementErrorCode code, std::size_t line, std::size_t column) {
  auto result=parse_statements(input);
  auto p=std::get_if<StatementDiagnostic>(&result);
  if (!p || p->code!=code || p->position.line!=line || p->position.column!=column) {
    std::cerr << "wrong statement error in: " << input << '\n'; ++failures;
  }
}
void cases() {
  dump("{ let x = 1; }","(block (let \"x\" (integer \"1\")))\n");
  dump("{ var y = 2; y = y + 1; }","(block (var \"y\" (integer \"2\")) (expr (binary = (identifier \"y\") (binary + (identifier \"y\") (integer \"1\")))))\n");
  dump("{ if x { return 1; } }","(block (if (identifier \"x\") (block (return (integer \"1\")))))\n");
  dump("{ while i < 3 { i = i + 1; } }","(block (while (binary < (identifier \"i\") (integer \"3\")) (block (expr (binary = (identifier \"i\") (binary + (identifier \"i\") (integer \"1\")))))))\n");
  dump("{ loop { break; } }","(block (loop (block (break))))\n");
  dump("{ for item in catalog { use(item); } }","(block (for \"item\" (identifier \"catalog\") (block (expr (call (identifier \"use\") (identifier \"item\"))))))\n");
  dump("{ guard ok else { return 1; } return 0; }","(block (guard (identifier \"ok\") (block (return (integer \"1\")))) (return (integer \"0\")))\n");
  dump("{ match x { A => { return 1; } B => { return 2; } } }","(block (match (identifier \"x\") (arm \"A\" (block (return (integer \"1\")))) (arm \"B\" (block (return (integer \"2\"))))))\n");
  error("{ break; }",StatementErrorCode::break_outside_loop,1,3);
  error("{ continue; }",StatementErrorCode::continue_outside_loop,1,3);
  error("{ let x = 1 }",StatementErrorCode::expected_semicolon,1,13);
  error("{ if x return 1; }",StatementErrorCode::expected_lbrace,1,8);
  error("{ for x items {} }",StatementErrorCode::expected_in,1,9);
  error("{ match x { A { return 1; } } }",StatementErrorCode::expected_arrow,1,15);
  auto empty=parse_statements("{}");
  if (auto ast=std::get_if<StatementAst>(&empty)) check(dump_statement_ast(*ast)=="(block)\n","empty block");
  else check(false,"empty block did not parse");
  auto lex=parse_statements("{ let x = 0b2; }");
  check(std::holds_alternative<Diagnostic>(lex),"statement lexer error not propagated");
  auto nested=parse_statements("{ if a { if b { return 1; } } }");
  if (auto ast=std::get_if<StatementAst>(&nested)) check(dump_statement_ast(*ast).find("(if (identifier \"b\")")!=std::string::npos,"nested if");
  else check(false,"nested if did not parse");
}
void depth_guard() {
  std::string source;
  for (int i=0;i<70;++i) source+="{";
  source+="return 1;";
  for (int i=0;i<70;++i) source+="}";
  auto result=parse_statements(source);
  auto p=std::get_if<StatementDiagnostic>(&result);
  check(p && p->code==StatementErrorCode::depth_exceeded,"statement depth guard");
}
void randomized_input() {
  std::mt19937 rng(0x5117);
  for (int i=0;i<4000;++i) {
    std::string input; const auto count=rng()%80;
    for (unsigned n=0;n<count;++n) input.push_back(static_cast<char>(rng()%(i%2 ? 128 : 256)));
    auto result=parse_statements(input);
    if (auto ast=std::get_if<StatementAst>(&result)) {
      const auto nodes=ast->nodes();
      check(ast->root()<nodes.size(),"randomized root invalid");
      for (const auto& node:nodes) {
        check(node.end_byte<=input.size(),"randomized span invalid");
        for (const auto child:node.children) check(child<nodes.size(),"randomized child invalid");
      }
      (void)dump_statement_ast(*ast);
    }
  }
}
}
int main() { cases(); depth_guard(); randomized_input(); return failures ? 1 : 0; }
