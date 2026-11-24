#include "poko/mute/lower.hpp"
#include "poko/mute/fold.hpp"
#include "poko/mute/optimize.hpp"
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

LowerResult lower_src(std::string_view src) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) return {};
  const auto& nodes=d->nodes(); const auto& bodies=d->bodies();
  for (const auto& n:nodes) if (n.kind==DeclarationKind::fn_decl && n.body<bodies.size())
    return lower_function(bodies[n.body],"f",i32t(),{});
  return {};
}
IrModule module_of(std::string_view src) {
  IrModule mod; auto lr=lower_src(src);
  if (lr.ok()) mod.functions.push_back(lr.fn);
  return mod;
}
VmResult run_mod(const IrModule& mod) {
  auto em=emit_bytecode(mod);
  if (!em.ok()) return VmError{VmErrorCode::invalid_bytecode,0};
  std::array<std::int32_t,256> r{};
  return run_register_vm(em.functions[0],r);
}
std::int32_t val(const VmResult& r) { return std::holds_alternative<std::int32_t>(r)?std::get<std::int32_t>(r):-999; }
std::size_t count_op(const IrModule& m,IrOp op) {
  std::size_t n=0; for (auto& f:m.functions) for (auto& b:f.blocks) for (auto& i:b.instrs) if (i.op==op) ++n; return n;
}
std::size_t count_instrs(const IrModule& m) {
  std::size_t n=0; for (auto& f:m.functions) for (auto& b:f.blocks) n+=b.instrs.size(); return n;
}
// Full pipeline: lower -> verify -> fold -> dce -> simplify -> verify -> emit -> run.
VmResult run_opt(std::string_view src,IrModule* keep=nullptr) {
  auto mod=module_of(src);
  if (mod.functions.empty()) return VmError{VmErrorCode::invalid_bytecode,0};
  if (!verify(mod).ok()) return VmError{VmErrorCode::invalid_bytecode,0};
  mod=fold_constants(mod);
  mod=eliminate_dead_code(mod);
  mod=simplify_control_flow(mod);
  auto pv=verify(mod);
  if (!pv.ok()) { std::cerr<<"post-opt verify failed\n"; for (auto& dg:pv.diagnostics) std::cerr<<"  vcode="<<(int)dg.code<<" blk="<<dg.block<<" "<<dg.detail<<"\n"; return VmError{VmErrorCode::invalid_bytecode,0}; }
  if (keep) *keep=mod;
  return run_mod(mod);
}
VmResult run_base(std::string_view src) {
  auto mod=module_of(src);
  if (mod.functions.empty() || !verify(mod).ok()) return VmError{VmErrorCode::invalid_bytecode,0};
  return run_mod(mod);
}
void cases() {
  const char* srcs[]={
    "package \"a\" version \"A\" fn f() -> i32 { let x = 20 + 22; return x * 2; }",
    "package \"a\" version \"A\" fn f() -> i32 { let x = 1; if x < 2 { let y = 5; } else { let y = 9; } return y; }",
    "package \"a\" version \"A\" fn f() -> i32 { let x = 0; while x < 3 { x = x + 1; } return x; }",
    "package \"a\" version \"A\" fn f() -> i32 { let s = 0; for i in 0..4 { if i == 2 { break; } s = s + i; } return s; }",
    "package \"a\" version \"A\" fn f() -> i32 { if 1 < 2 { return 11; } return 22; }",
    "package \"a\" version \"A\" fn f() -> i32 { return 6 * 7 - 8 / 2; }",
  };
  for (const char* s:srcs) {
    const auto a=run_base(s), b=run_opt(s);
    check(val(a)==val(b) && std::holds_alternative<std::int32_t>(a)==std::holds_alternative<std::int32_t>(b),s);
  }
  // DCE removes dead pure defs but keeps trapping arithmetic.
  {
    IrModule m=module_of("package \"a\" version \"A\" fn f() -> i32 { let dead = 1 + 2; let dead2 = 9 < 4; return 7; }");
    const auto before=count_instrs(m);
    m=eliminate_dead_code(m);
    check(count_instrs(m)<before,"dead code removed");
    // `1 + 2` can trap in principle -> must survive; `9 < 4` is pure -> gone.
    check(count_op(m,IrOp::binary)>=1,"trapping arithmetic preserved");
    check(count_op(m,IrOp::compare)==0,"dead compare removed");
  }
  // Used pure defs survive.
  {
    IrModule m=module_of("package \"a\" version \"A\" fn f() -> i32 { let c = 3 < 4; return c; }");
    // bool return may not lower to i32; just ensure DCE doesn't crash and verify passes.
    m=eliminate_dead_code(m);
    check(verify(m).ok(),"dce keeps used compare");
  }
  // Control-flow simplification: constant branch folds and dead arm drops.
  {
    IrModule m=module_of("package \"a\" version \"A\" fn f() -> i32 { if 1 < 2 { return 11; } return 22; }");
    m=fold_constants(m);           // 1<2 -> constant true
    const auto blocks_before=m.functions[0].blocks.size();
    m=simplify_control_flow(m);
    check(verify(m).ok(),"simplified module verifies");
    check(m.functions[0].blocks.size()<blocks_before,"dead arm block removed");
    check(val(run_mod(m))==11,"simplified result");
  }
  // Traps preserved through the whole pipeline.
  {
    const char* s="package \"a\" version \"A\" fn f() -> i32 { return 1 / 0; }";
    const auto a=run_base(s), b=run_opt(s);
    const auto* ea=std::get_if<VmError>(&a); const auto* eb=std::get_if<VmError>(&b);
    check(ea && eb && ea->code==eb->code,"div-by-zero trap preserved");
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " optimize test(s) failed\n"; return 1; }
  std::cout << "optimize tests passed\n";
  return 0;
}
