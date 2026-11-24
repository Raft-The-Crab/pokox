#include "poko/mute/lower.hpp"
#include "poko/mute/fold.hpp"
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

// Parse + lower + verify, optionally fold, emit and run. Returns the VM result.
VmResult run_source(std::string_view src,bool fold,std::string_view what,IrModule* keep=nullptr) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) { std::cerr << "parse failed: " << src << '\n'; return VmError{VmErrorCode::invalid_bytecode,0}; }
  const auto& nodes=d->nodes(); const auto& bodies=d->bodies();
  std::size_t body_idx=no_declaration;
  for (const auto& n:nodes) if (n.kind==DeclarationKind::fn_decl && n.body<bodies.size()) { body_idx=n.body; break; }
  if (body_idx==no_declaration) { std::cerr << "no fn: " << src << '\n'; return VmError{VmErrorCode::invalid_bytecode,0}; }
  LowerResult lr=lower_function(bodies[body_idx],"f",i32t(),{});
  if (!lr.ok()) { std::cerr << "lower diags: " << what << '\n'; return VmError{VmErrorCode::invalid_bytecode,0}; }
  IrModule mod; mod.functions.push_back(lr.fn);
  auto ver=verify(mod);
  if (!ver.ok()) { std::cerr << "verify failed: " << what << '\n'; return VmError{VmErrorCode::invalid_bytecode,0}; }
  if (fold) mod=fold_constants(mod);
  ver=verify(mod);
  if (!ver.ok()) { std::cerr << "verify after fold failed: " << what << '\n'; return VmError{VmErrorCode::invalid_bytecode,0}; }
  if (keep) *keep=mod;
  auto em=emit_bytecode(mod);
  if (!em.ok()) { std::cerr << "emit failed: " << what << '\n'; return VmError{VmErrorCode::invalid_bytecode,0}; }
  std::array<std::int32_t,256> r{};
  return run_register_vm(em.functions[0],r);
}
std::int32_t val(const VmResult& r) { return std::holds_alternative<std::int32_t>(r)?std::get<std::int32_t>(r):-999; }
std::size_t count_op(const IrModule& m,IrOp op) {
  std::size_t n=0; for (auto& f:m.functions) for (auto& b:f.blocks) for (auto& i:b.instrs) if (i.op==op) ++n; return n;
}
void cases() {
  // Folding produces identical results.
  const char* srcs[]={
    "package \"a\" version \"A\" fn f() -> i32 { return 20 + 22 * 2; }",
    "package \"a\" version \"A\" fn f() -> i32 { return (6 - 10) / 2; }",
    "package \"a\" version \"A\" fn f() -> i32 { return 7 % 3 + 1; }",
    "package \"a\" version \"A\" fn f() -> i32 { let x = 4; return -x + 10; }",
    "package \"a\" version \"A\" fn f() -> i32 { if 1 < 2 { return 11; } return 22; }",
  };
  for (const char* s:srcs) {
    const auto a=run_source(s,false,"base");
    const auto b=run_source(s,true,"fold");
    check(val(a)==val(b) && std::holds_alternative<std::int32_t>(a) == std::holds_alternative<std::int32_t>(b),s);
  }
  // The fold actually fires: 20+22*2 leaves zero binary/compare ops.
  IrModule m;
  check(std::holds_alternative<std::int32_t>(run_source("package \"a\" version \"A\" fn f() -> i32 { return 20 + 22 * 2; }",true,"fold-count",&m)),"folded run");
  check(count_op(m,IrOp::binary)==0 && count_op(m,IrOp::compare)==0,"constants folded away");
  // Traps must NOT be folded away: runtime still traps identically.
  const char* traps[]={
    "package \"a\" version \"A\" fn f() -> i32 { return 1 / 0; }",
    "package \"a\" version \"A\" fn f() -> i32 { return 1 % 0; }",
    "package \"a\" version \"A\" fn f() -> i32 { return 2147483647 + 1; }",
    "package \"a\" version \"A\" fn f() -> i32 { return -(-2147483647 - 1); }",
  };
  for (const char* s:traps) {
    const auto a=run_source(s,false,"trap-base");
    const auto b=run_source(s,true,"trap-fold");
    const auto* ea=std::get_if<VmError>(&a); const auto* eb=std::get_if<VmError>(&b);
    check(ea && eb && ea->code==eb->code,s);
  }
  // Constants from other blocks must not fold (no dominance proof).
  {
    IrModule mod;
    IrFunction fn; fn.name="g"; fn.result=i32t();
    IrBlock b0; b0.label="entry";
    IrInstr c; c.op=IrOp::constant; c.def=1; c.result=i32t(); c.args={{0,41}};
    IrInstr j; j.op=IrOp::jump; j.target=2;
    b0.instrs={c,j};
    IrBlock b1; b1.label="use"; b1.preds={1};
    IrInstr add; add.op=IrOp::binary; add.def=2; add.result=i32t(); add.detail=0;
    add.args={{1,0},{1,0}};
    IrInstr r; r.op=IrOp::return_; r.result=i32t(); r.args={{2,0}};
    b1.instrs={add,r};
    fn.blocks={b0,b1}; mod.functions.push_back(fn);
    auto hv=verify(mod);
    if (!hv.ok()) for (auto& dg:hv.diagnostics) std::cerr<<"  verify code="<<(int)dg.code<<" fn="<<dg.function<<" blk="<<dg.block<<" "<<dg.detail<<"\n";
    check(hv.ok(),"hand module verifies");
    const auto folded=fold_constants(mod);
    check(folded.functions[0].blocks[1].instrs[0].op==IrOp::binary,"cross-block constant not folded");
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " fold test(s) failed\n"; return 1; }
  std::cout << "fold tests passed\n";
  return 0;
}
