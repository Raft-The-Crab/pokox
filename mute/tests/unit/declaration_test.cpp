#include "poko/mute/declaration.hpp"
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
void check(bool valid,std::string_view description) {
  if (!valid) { std::cerr << description << '\n'; ++failures; }
}
void tree(std::string_view input,std::string_view expected) {
  auto result=parse_declarations(input);
  const auto* ast=std::get_if<DeclarationAst>(&result);
  if (!ast) { std::cerr << "did not parse: " << input << '\n'; ++failures; return; }
  const auto output=dump_declaration_ast(*ast);
  if (output!=expected) { std::cerr << "unexpected AST for " << input << '\n' << output; ++failures; }
  const auto nodes=ast->nodes();
  check(ast->root()<nodes.size(),"root out of range");
  for (std::size_t i=0;i<nodes.size();++i) {
    const auto& n=nodes[i];
    check(n.begin.byte<=n.token_begin.byte && n.token_end_byte<=n.end_byte,"bad node span");
    for (const auto child:n.children) if (n.kind!=DeclarationKind::variant) check(child<i,"child not earlier");
  }
  const auto types=ast->types();
  for (const auto& type:types) for (const auto arg:type.args) check(arg<types.size(),"type arg invalid");
}
void error(std::string_view input,DeclarationErrorCode code,std::size_t line,std::size_t column) {
  auto result=parse_declarations(input);
  auto p=std::get_if<DeclarationDiagnostic>(&result);
  if (!p || p->code!=code || p->position.line!=line || p->position.column!=column) {
    std::cerr << "wrong declaration error in: " << input << '\n'; ++failures;
  }
}
void cases() {
  tree("struct Item { id: u32, name: string, price: u32 }","(module (struct \"Item\" (field \"id\" (named \"u32\")) (field \"name\" (named \"string\")) (field \"price\" (named \"u32\"))))\n");
  tree("enum E { A, B(i32), C(i32, string) }","(module (enum \"E\" (variant \"A\") (variant \"B\" (named \"i32\")) (variant \"C\" (named \"i32\") (named \"string\"))))\n");
  tree("enum ShopError { Insufficient, SoldOut, InvalidId }","(module (enum \"ShopError\" (variant \"Insufficient\") (variant \"SoldOut\") (variant \"InvalidId\")))\n");
  tree("struct Box { value: result<Unit, ShopError> }","(module (struct \"Box\" (field \"value\" (generic \"result\" (named \"Unit\") (named \"ShopError\")))))\n");
  tree("struct Map { values: map<u32, array<string>> }","(module (struct \"Map\" (field \"values\" (generic \"map\" (named \"u32\") (generic \"array\" (named \"string\"))))))\n");
  tree("struct Pair { data: (i32, string) }","(module (struct \"Pair\" (field \"data\" (tuple (named \"i32\") (named \"string\")))))\n");
  tree("@state var balance: u32 = 1500","(module (state \"balance\" (named \"u32\") (integer \"1500\")))\n");
  tree("pub fn f() { return 0; }","(module (fn \"f\" (block (return (integer \"0\")))))\n");
  tree("fn g() -> i32 { return f(); }","(module (fn \"g\" (named \"i32\") (block (return (call (identifier \"f\"))))))\n");
  tree("@state var x: i32 = 0 fn g() -> i32 { return 2; }","(module (state \"x\" (named \"i32\") (integer \"0\")) (fn \"g\" (named \"i32\") (block (return (integer \"2\")))))\n");
  tree("fn f() -> i32 { return 1; }","(module (fn \"f\" (named \"i32\") (block (return (integer \"1\")))))\n");
  tree("fn buy(id: u32) -> result<Unit, E> { return ok(()); }","(module (fn \"buy\" (param \"id\" (named \"u32\")) (generic \"result\" (named \"Unit\") (named \"E\")) (block (return (call (identifier \"ok\") (unit))))))\n");
  tree("async fn fetch() { return 0; }","(module (fn \"fetch\" (block (return (integer \"0\")))))\n");
  tree("@on(BuyPressed) fn buy() { return 0; }","(module (fn \"buy\" (attr \"@on(BuyPressed)\") (block (return (integer \"0\")))))\n");
  tree("package \"com.poko.hub\" version \"1\"","(module (package \"\\x22com.poko.hub\\x22\") (version \"\\x221\\x22\"))\n");
  tree("allow: net, ui","(module (allow (field \"net\") (field \"ui\")))\n");
  tree("import \"pkg://poko/ui\" as ui","(module (import \"\\x22pkg://poko/ui\\x22\" (field \"ui\")))\n");
  error("struct S { x u32 }",DeclarationErrorCode::expected_colon,1,14);
  error("fn f() return 1;",DeclarationErrorCode::expected_lbrace,1,8);
  error("fn f() { return 1;",DeclarationErrorCode::expected_rbrace,1,19);
  error("@rpc fn f() { return 0; }",DeclarationErrorCode::unsupported_attribute,1,2);
  error("?",DeclarationErrorCode::expected_declaration,1,1);
}
void depth_guard() {
  std::string source="struct S { x: ";
  for (int i=0;i<70;++i) source+="map<i32, ";
  source+="i32";
  for (int i=0;i<70;++i) source+=">";
  source+=" }";
  auto result=parse_declarations(source);
  auto p=std::get_if<DeclarationDiagnostic>(&result);
  check(p && p->code==DeclarationErrorCode::depth_exceeded,"declaration depth guard");
}
void randomized_input() {
  std::mt19937 rng(0x1616);
  for (int i=0;i<3000;++i) {
    std::string input; const auto count=rng()%70;
    for (unsigned n=0;n<count;++n) input.push_back(static_cast<char>(rng()%(i%2 ? 128 : 256)));
    auto result=parse_declarations(input);
    if (auto ast=std::get_if<DeclarationAst>(&result)) {
      const auto nodes=ast->nodes();
      check(ast->root()<nodes.size(),"randomized root invalid");
      for (const auto& node:nodes) {
        check(node.end_byte<=input.size(),"randomized span invalid");
        for (const auto child:node.children) if (node.kind!=DeclarationKind::variant) check(child<nodes.size(),"randomized child invalid");
      }
      (void)dump_declaration_ast(*ast);
    }
  }
}
}
int main() { cases(); depth_guard(); randomized_input(); return failures ? 1 : 0; }
