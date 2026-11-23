#include "poko/mute/semantic.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <variant>
using namespace poko::mute;
namespace {
int failures=0;
void ok(std::string_view source) {
  auto parsed=parse_declarations(source);
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  if (!ast) { std::cerr << "parse failed: " << source << '\n'; ++failures; return; }
  const auto result=analyze(*ast);
  if (!result.ok()) {
    std::cerr << "unexpected semantic error " << name(result.diagnostics.front().code)
              << " in: " << source << '\n'; ++failures;
  }
}
void error(std::string_view source,SemanticErrorCode code,std::size_t line,std::size_t column) {
  auto parsed=parse_declarations(source);
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  if (!ast) { std::cerr << "parse failed: " << source << '\n'; ++failures; return; }
  const auto result=analyze(*ast);
  const auto found=std::find_if(result.diagnostics.begin(),result.diagnostics.end(),
    [&](const SemanticDiagnostic& d){ return d.code==code && d.position.line==line && d.position.column==column; });
  if (found==result.diagnostics.end()) { std::cerr << "missing " << name(code) << " at " << line << ':' << column << " in: " << source << '\n'; ++failures; }
}
void cases() {
  ok("fn f() -> i32 { return 1; }");
  ok("struct Item { id: u32, price: u32 } fn total(i: Item) -> u32 { return i.price; }");
  ok("struct E {} fn f() -> result<Unit, E> { return ok(()); }");
  ok("fn f() -> i32 { let x = 1; { let x = 2; } return x; }");
  ok("@state var x: i32 = 0");
  error("fn f() -> i32 { return y; }",SemanticErrorCode::unknown_name,1,24);
  error("fn f() -> i32 { let x = 1; let x = 2; return 0; }",SemanticErrorCode::duplicate_binding,1,28);
  error("struct A {} struct A {}",SemanticErrorCode::duplicate_declaration,1,13);
  error("fn f() -> i32 { let x = 1; x = 2; return 0; }",SemanticErrorCode::immutable_assignment,1,28);
  error("fn f() -> bool { return 1; }",SemanticErrorCode::invalid_return,1,18);
  error("fn f() -> i32 { return true; }",SemanticErrorCode::invalid_return,1,17);
  error("fn add(a: i32, b: i32) -> i32 { return a + b; } fn f() -> i32 { return add(1); }",SemanticErrorCode::wrong_arity,1,72);
  error("struct A {} fn f(a: A) -> A { return a; } fn g() -> A { return f(1); }",SemanticErrorCode::type_mismatch,1,66);
  error("struct S { x: i32 } fn f(s: S) -> i32 { return s.y; }",SemanticErrorCode::unknown_field,1,48);
  error("fn f() -> i32 { return 1 + true; }",SemanticErrorCode::trait_not_satisfied,1,24);
  error("struct S { v: array<missing> }",SemanticErrorCode::unknown_type,1,21);
  error("struct S { v: array<i32, i32> }",SemanticErrorCode::invalid_generic_arity,1,15);
}
}
int main() { cases(); return failures ? 1 : 0; }
