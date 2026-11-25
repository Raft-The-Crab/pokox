#include "poko/mute/lower.hpp"
#include "poko/mute/emit.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/declaration.hpp"
#include "poko/mute/hostcall.hpp"
#include <iostream>
#include <string>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
Type i32t() { return {TypeTag::scalar,"i32",{}}; }

// Parse a module, lower its first fn_decl body, verify+emit+run.
std::int32_t run_source(std::string_view src,std::string_view what) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) { std::cerr << "parse failed: " << src << '\n'; return -1; }
  const auto& nodes=d->nodes(); const auto& bodies=d->bodies();
  std::size_t body_idx=no_declaration;
  for (const auto& n:nodes) if (n.kind==DeclarationKind::fn_decl && n.body<bodies.size()) { body_idx=n.body; break; }
  if (body_idx==no_declaration) { std::cerr << "no fn: " << src << '\n'; return -1; }
  LowerResult lr=lower_function(bodies[body_idx],"f",i32t(),{});
  if (!lr.ok()) { std::cerr << "lower diags: " << what << '\n'; for (auto& x:lr.diagnostics) std::cerr<<"  code="<<(int)x.code<<" blk="<<x.block<<"\n"; return -1; }
  IrModule mod; mod.functions.push_back(lr.fn);
  auto ver=verify(mod);
  if (!ver.ok()) { std::cerr << "verify failed: " << what << '\n'; for (auto& dg:ver.diagnostics) std::cerr<<"  vcode="<<(int)dg.code<<" fn="<<dg.function<<" blk="<<dg.block<<" "<<dg.detail<<"\n"; return -1; }
  auto em=emit_bytecode(mod);
  if (!em.ok()) { std::cerr << "emit failed: " << what << '\n'; for (auto& x:em.errors) std::cerr<<"  ecode="<<(int)x.code<<"\n"; return -1; }
  std::array<std::int32_t,256> r{};
  auto res=run_register_vm(em.functions[0],r);
  if (const auto* e=std::get_if<VmError>(&res)) { std::cerr << "vm error " << (int)e->code << ": " << what << '\n'; return -1; }
  return std::get<std::int32_t>(res);
}
bool compile_module(std::string_view src,EmitResult& em,std::size_t& entry) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) { std::cerr << "parse failed: " << src << '\n'; return false; }
  auto lm=lower_module(*d);
  if (!lm.ok()) {
    std::cerr << "lower module failed: " << src << '\n';
    for (auto& x:lm.diagnostics) std::cerr<<"  code="<<(int)x.code<<" fn="<<x.function<<" blk="<<x.block<<" "<<x.detail<<"\n";
    return false;
  }
  auto ver=verify(lm.module);
  if (!ver.ok()) {
    std::cerr << "module verify failed: " << src << '\n';
    for (auto& dg:ver.diagnostics) std::cerr<<"  vcode="<<(int)dg.code<<" fn="<<dg.function<<" blk="<<dg.block<<" "<<dg.detail<<"\n";
    return false;
  }
  entry=0;
  for (std::size_t i=0;i<lm.module.functions.size();++i)
    if (lm.module.functions[i].name=="f") entry=i;
  em=emit_bytecode(lm.module);
  if (!em.ok()) { std::cerr << "module emit failed: " << src << '\n'; return false; }
  return true;
}
std::int32_t run_module(std::string_view src,std::string_view what,std::size_t budget=100'000) {
  EmitResult em; std::size_t entry=0;
  if (!compile_module(src,em,entry)) { std::cerr << "compile failed: " << what << '\n'; return -1; }
  VmModule module{em.functions,em.capabilities};
  auto res=run_register_module(module,entry,{},budget);
  if (const auto* e=std::get_if<VmError>(&res)) {
    std::cerr << "vm error " << (int)e->code << ": " << what << '\n'; return -1;
  }
  return std::get<std::int32_t>(res);
}

void cases() {
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 20 + 22; return x * 2; }","arith")==84,"arith -> 84");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 1; if x < 2 { let y = 5; } else { let y = 9; } return y; }","if-phi")==5,"if true -> 5");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 3; if x < 2 { let y = 5; } else { let y = 9; } return y; }","if-phi-f")==9,"if false -> 9");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { loop { break; } return 7; }","loop-break")==7,"loop break -> 7");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 3 { x = x + 1; } return x; }","while-count")==3,"while counter -> 3");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 5; while x < 3 { let y = 1; } return x; }","while")==5,"while false -> 5");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..3 { s = s + i; } return s; }","for-range")==3,"for 0..3 sum -> 3");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..=3 { s = s + i; } return s; }","for-range-inc")==6,"for 0..=3 sum -> 6");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..3 { for j in 0..3 { s = s + j; } } return s; }","for-nested")==9,"nested for sum -> 9");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 1; if x > 0 { if x < 2 { let y = 4; } else { let y = 8; } } else { let y = 0; } return y; }","if-nested")==4,"nested if -> 4");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { for i in 5..2 { let x = 1; } return 9; }","for-empty")==9,"for empty -> 9");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..4 { if i == 2 { break; } s = s + i; } return s; }","for-break")==1,"for break -> 1");
  // Unsupported constructs produce diagnostics, not crashes.
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { return missing_name; }","unknown")==-1,"unknown name rejected");

  // Module lowering: calls resolve through the signature table, so forward
  // references, self recursion and mutual recursion all work.
  check(run_module("package \"a\" version \"A\" fn add(a: i32, b: i32) -> i32 { return a + b; } fn f() -> i32 { return add(20, 22); }","module-call")==42,"module call -> 42");
  check(run_module("package \"a\" version \"A\" fn fib(n: i32) -> i32 { if n < 2 { return n; } return fib(n - 1) + fib(n - 2); } fn f() -> i32 { return fib(10); }","fib")==55,"recursive fib(10) -> 55");
  check(run_module("package \"a\" version \"A\" fn even(n: i32) -> i32 { if n == 0 { return 1; } return odd(n - 1); } fn odd(n: i32) -> i32 { if n == 0 { return 0; } return even(n - 1); } fn f() -> i32 { return even(10); }","mutual")==1,"mutual recursion even(10) -> 1");
  check(run_module("package \"a\" version \"A\" fn id(x: i32) -> i32 { return x; } fn f() -> i32 { return id(id(7)); }","nested-call")==7,"nested call -> 7");
  // Unknown callee is a typed diagnostic, never silent output.
  {
    auto parsed=parse_declarations("package \"a\" version \"A\" fn f() -> i32 { return nope(1); }");
    const auto* d=std::get_if<DeclarationAst>(&parsed);
    check(d!=nullptr,"unknown-callee parses");
    if (d) {
      auto lm=lower_module(*d);
      check(!lm.ok(),"unknown callee diagnosed");
      bool found=false;
      for (const auto& x:lm.diagnostics) if (x.code==IrErrorCode::undefined_value) found=true;
      check(found,"unknown callee uses undefined_value");
    }
  }
  // @requires narrows the function mask against the allow: ceiling; unknown
  // capability names contribute no bits, and absent attributes keep 0x3FF.
  {
    auto parsed=parse_declarations(
        "package \"a\" version \"A\" allow: Net, Time\n"
        "@requires(Net) fn only_net() -> i32 { return 1; }\n"
        "@requires(Net, Time) fn net_time() -> i32 { return 2; }\n"
        "@requires(Storage) fn denied() -> i32 { return 3; }\n"
        "fn plain() -> i32 { return 4; }\n");
    const auto* d=std::get_if<DeclarationAst>(&parsed);
    check(d!=nullptr,"requires module parses");
    if (d) {
      auto lm=lower_module(*d);
      check(lm.ok(),"requires module lowers");
      auto mask=[&](std::string_view name) -> std::uint32_t {
        for (const auto& fn:lm.module.functions) if (fn.name==name) return fn.capabilities;
        return 0xDEADBEEFu;
      };
      check(mask("only_net")==capability_net,"@requires(Net) -> Net");
      check(mask("net_time")==(capability_net|capability_time),"@requires(Net,Time) -> Net|Time");
      check(mask("denied")==0,"@requires outside ceiling -> 0");
      check(mask("plain")==capability_all,"no @requires -> full mask");
    }
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " lower test(s) failed\n"; return 1; }
  std::cout << "lower tests passed\n";
  return 0;
}
