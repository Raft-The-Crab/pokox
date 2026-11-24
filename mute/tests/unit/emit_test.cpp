#include "poko/mute/emit.hpp"
#include "poko/mute/register_vm.hpp"
#include <iostream>
#include <string>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
Type i32() { return {TypeTag::scalar,"i32",{}}; }
IrOperand v(std::uint32_t id) { return {id,0}; }
IrOperand pv(std::uint32_t id,std::uint64_t imm) { return {id,imm}; }

IrModule arith_module() {
  IrModule m; IrFunction f; f.name="add"; f.result=i32(); f.params={i32(),i32()};
  IrBlock e; e.label="entry";
  IrInstr bin; bin.op=IrOp::binary; bin.def=3; bin.result=i32(); bin.detail=0; bin.args={v(1),v(2)};
  e.instrs.push_back(bin);
  IrInstr ret; ret.op=IrOp::return_; ret.result=i32(); ret.args={v(3)};
  e.instrs.push_back(ret); f.blocks.push_back(e); m.functions.push_back(f); return m;
}
IrModule select_module() {
  IrModule m; IrFunction f; f.name="sel"; f.result=i32(); f.params={i32(),i32()};
  IrBlock e; e.label="entry";
  IrInstr cmp; cmp.op=IrOp::compare; cmp.def=3; cmp.result={TypeTag::scalar,"bool",{}}; cmp.detail=2; cmp.args={v(1),v(2)};
  e.instrs.push_back(cmp);
  IrInstr br; br.op=IrOp::branch; br.args={v(3)}; br.target=2; br.target2=3;
  e.instrs.push_back(br);
  IrBlock a; a.label="a"; a.preds={1};
  IrInstr ca; ca.op=IrOp::copy; ca.def=4; ca.result=i32(); ca.args={v(1)};
  a.instrs.push_back(ca); IrInstr ja; ja.op=IrOp::jump; ja.target=4; a.instrs.push_back(ja);
  IrBlock b; b.label="b"; b.preds={1};
  IrInstr cb; cb.op=IrOp::copy; cb.def=5; cb.result=i32(); cb.args={v(2)};
  b.instrs.push_back(cb); IrInstr jb; jb.op=IrOp::jump; jb.target=4; b.instrs.push_back(jb);
  IrBlock j; j.label="join"; j.preds={2,3};
  IrInstr phi; phi.op=IrOp::phi; phi.def=6; phi.result=i32();
  phi.args={pv(4,2),pv(5,3),pv(4,2),pv(5,3)};
  j.instrs.push_back(phi);
  IrInstr r; r.op=IrOp::return_; r.result=i32(); r.args={v(6)}; j.instrs.push_back(r);
  f.blocks={e,a,b,j}; m.functions.push_back(f); return m;
}
void cases() {
  // Straight-line: emit + execute.
  {
    auto e=emit_bytecode(arith_module());
    check(e.ok(),"arith emit ok");
    check(e.functions.size()==1,"one function");
    std::array<std::int32_t,256> r{}; r[1]=3; r[2]=4;
    auto res=run_register_vm(e.functions[0],r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==7,"arith executes to 7");
  }
  // Control flow + phi edge moves.
  {
    auto e=emit_bytecode(select_module());
    check(e.ok(),"select emit ok");
    std::array<std::int32_t,256> r{}; r[1]=3; r[2]=7;
    auto res=run_register_vm(e.functions[0],r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==3,"select true -> x");
    r[1]=9; r[2]=7;
    res=run_register_vm(e.functions[0],r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==7,"select false -> y");
  }
  // Unsupported ops and failed verification are typed errors.
  {
    auto m=arith_module(); IrInstr konst; konst.op=IrOp::constant; konst.def=9; konst.result=i32(); konst.args={pv(0,5)};
    m.functions[0].blocks[0].instrs.insert(m.functions[0].blocks[0].instrs.begin(),konst);
    auto e=emit_bytecode(m); check(!e.ok() && !e.errors.empty(),"constant rejected");
    auto bad=arith_module(); bad.functions[0].blocks.clear();
    auto e2=emit_bytecode(bad); check(!e2.diagnostics.empty(),"verify failure reported");
  }
  // Deterministic emission.
  { auto a=emit_bytecode(select_module()),b=emit_bytecode(select_module());
    check(a.functions[0]==b.functions[0],"emit deterministic"); }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " emit test(s) failed\n"; return 1; }
  std::cout << "emit tests passed\n";
  return 0;
}
