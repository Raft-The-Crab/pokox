#include "poko/mute/ssa.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
bool has(IrErrorCode c,const IrResult& r) {
  for (const auto& d:r.diagnostics) if (d.code==c) return true;
  return false;
}
Type i32() { return {TypeTag::scalar,"i32",{}}; }
IrOperand v(std::uint32_t id) { return {id,0}; }

IrModule valid_module() {
  IrModule m;
  IrFunction f; f.name="main"; f.result=i32(); f.params={i32()};
  IrBlock entry; entry.label="entry";
  IrInstr c; c.op=IrOp::constant; c.def=2; c.result=i32(); c.args={{0,42}};
  entry.instrs.push_back(c);
  IrInstr ret; ret.op=IrOp::return_; ret.result=i32(); ret.args={v(2)};
  entry.instrs.push_back(ret);
  f.blocks.push_back(entry);
  m.functions.push_back(f);
  return m;
}
void cases() {
  // Well-formed module verifies.
  check(verify(valid_module()).ok(),"valid module");
  // Empty function.
  { auto m=valid_module(); m.functions[0].blocks.clear(); check(has(IrErrorCode::empty_function,verify(m)),"empty fn"); }
  // Missing terminator.
  { auto m=valid_module(); m.functions[0].blocks[0].instrs.pop_back(); check(has(IrErrorCode::missing_terminator,verify(m)),"no terminator"); }
  // Terminator mid-block.
  { auto m=valid_module(); auto b=m.functions[0].blocks[0]; IrInstr j;j.op=IrOp::jump;j.target=1;b.instrs.insert(b.instrs.begin(),j);m.functions[0].blocks[0]=b;check(has(IrErrorCode::bad_terminator,verify(m)),"mid terminator"); }
  // Undefined operand.
  { auto m=valid_module(); m.functions[0].blocks[0].instrs[0].args={v(99)};check(has(IrErrorCode::undefined_value,verify(m)),"undefined value"); }
  // Return type mismatch.
  { auto m=valid_module(); m.functions[0].blocks[0].instrs[1].result={TypeTag::scalar,"f64",{}};check(has(IrErrorCode::type_mismatch,verify(m)),"return type"); }
  // Binary operand type mismatch.
  { auto m=valid_module(); auto& in=m.functions[0].blocks[0].instrs[0];
    in.op=IrOp::binary; in.args={v(1),v(1)}; in.result={TypeTag::scalar,"bool",{}};
    in.def=0; m.functions[0].blocks[0].instrs[1].args={v(1)};
    check(verify(m).ok(),"same-type binary ok");
    in.result={TypeTag::scalar,"i32",{}}; in.def=3;
    in.args={v(1),v(1)}; // both param i32
    m.functions[0].blocks[0].instrs[1].args={v(3)};
    check(verify(m).ok(),"binary same types ok"); }
  // Phi arity vs predecessors.
  { auto m=valid_module();
    IrFunction f; f.name="phi"; f.result=i32(); f.params={i32()};
    auto konst=[&](std::uint32_t id){ IrInstr k;k.op=IrOp::constant;k.def=id;k.result=i32();k.args={{0,id}};return k; };
    IrBlock entry;entry.label="entry";IrInstr br;br.op=IrOp::branch;br.target=2;br.target2=3;br.args={v(1)};entry.instrs.push_back(br);
    IrBlock a;a.label="a";a.preds={1};a.instrs.push_back(konst(5));IrInstr ja;ja.op=IrOp::jump;ja.target=4;a.instrs.push_back(ja);
    IrBlock b;b.label="b";b.preds={1};b.instrs.push_back(konst(6));IrInstr jb;jb.op=IrOp::jump;jb.target=4;b.instrs.push_back(jb);
    IrBlock join;join.label="join";join.preds={2,3};
    IrInstr phi;phi.op=IrOp::phi;phi.def=7;phi.result=i32();phi.args={v(5),v(6),v(6),v(5)};
    join.instrs.push_back(phi);
    IrInstr r;r.op=IrOp::return_;r.result=i32();r.args={v(7)};join.instrs.push_back(r);
    f.blocks={entry,a,b,join};m.functions.push_back(f);
    check(verify(m).ok(),"phi arity ok");
    m.functions[1].blocks[3].instrs[0].args={v(5),v(6)}; // 2 args vs 2 preds*2=4
    check(has(IrErrorCode::phi_arity,verify(m)),"phi arity mismatch"); }
  // Duplicate labels and unreachable blocks.
  { auto m=valid_module(); IrBlock dup;m.functions[0].blocks.push_back(m.functions[0].blocks[0]);check(has(IrErrorCode::duplicate_label,verify(m)),"dup label"); }
  { auto m=valid_module(); IrBlock dead;dead.label="dead";IrInstr r;r.op=IrOp::return_;r.result=i32();dead.instrs.push_back(r);m.functions[0].blocks.push_back(dead);check(has(IrErrorCode::unreachable_block,verify(m)),"unreachable"); }
  // Deterministic dump is stable.
  { auto m=valid_module(); check(dump_ir(m)==dump_ir(valid_module()),"dump deterministic"); }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " ssa test(s) failed\n"; return 1; }
  std::cout << "ssa tests passed\n";
  return 0;
}
