#include "poko/mute/lower.hpp"
#include "poko/mute/emit.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/declaration.hpp"
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
  if (!ver.ok()) { std::cerr << "verify failed: " << what << '\n'; return -1; }
  auto em=emit_bytecode(mod);
  if (!em.ok()) { std::cerr << "emit failed: " << what << '\n'; for (auto& x:em.errors) std::cerr<<"  ecode="<<(int)x.code<<"\n"; return -1; }
  std::array<std::int32_t,256> r{};
  auto res=run_register_vm(em.functions[0],r);
  if (const auto* e=std::get_if<VmError>(&res)) { std::cerr << "vm error " << (int)e->code << ": " << what << '\n'; return -1; }
  return std::get<std::int32_t>(res);
}
void cases() {
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 20 + 22; return x * 2; }","arith")==84,"arith -> 84");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 1; if x < 2 { let y = 5; } else { let y = 9; } return y; }","if-phi")==5,"if true -> 5");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 3; if x < 2 { let y = 5; } else { let y = 9; } return y; }","if-phi-f")==9,"if false -> 9");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { loop { break; } return 7; }","loop-break")==7,"loop break -> 7");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 3 { x = x + 1; } return x; }","while-count")==3,"while counter -> 3");
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { let x = 5; while x < 3 { let y = 1; } return x; }","while")==5,"while false -> 5");
  // Unsupported constructs produce diagnostics, not crashes.
  check(run_source("package \"a\" version \"A\" fn f() -> i32 { return missing_name; }","unknown")==-1,"unknown name rejected");
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " lower test(s) failed\n"; return 1; }
  std::cout << "lower tests passed\n";
  return 0;
}
