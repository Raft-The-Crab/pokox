#include "poko/mute/debugger.hpp"
#include "poko/mute/bytecode.hpp"
#include <iostream>
#include <string>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
Instruction pay(std::uint32_t u) { return {static_cast<Opcode>(u&0xFF),static_cast<std::uint8_t>((u>>8)&0xFF),static_cast<std::uint8_t>((u>>16)&0xFF),static_cast<std::uint8_t>((u>>24)&0xFF)}; }
Instruction imm(std::uint8_t d) { return {Opcode::load_imm,d,0,0}; }

// r1=5; r2=7; r3=r1+r2; return r3  -> 12
Bytecode arith() {
  return {imm(1),pay(5),imm(2),pay(7),{Opcode::add,3,1,2},{Opcode::ret,3,0,0}};
}
// r1=1; r2=0; r3=r1/r2; return r3  -> divide_by_zero at pc 4
Bytecode divzero() {
  return {imm(1),pay(1),imm(2),pay(0),{Opcode::div,3,1,2},{Opcode::ret,3,0,0}};
}
void cases() {
  // Step through a sample: inspect registers and stack at each stop.
  {
    const auto code=arith();
    VmDebugger dbg(code);
    check(dbg.pc()==0 && !dbg.finished(),"starts at pc 0");
    check(dbg.stack().size()==1 && dbg.stack()[0]==0,"one frame at entry");
    auto s1=dbg.step(); // load_imm r1 (consumes payload)
    check(s1.stop==DebugStop::stepped && s1.pc==2,"step 1 -> pc 2");
    check(dbg.registers()[1]==5,"r1 loaded after step");
    auto s2=dbg.step(); // load_imm r2 consumes its payload word
    check(s2.stop==DebugStop::stepped && s2.pc==4,"step 2 -> pc 4");
    check(dbg.registers()[2]==7,"r2 loaded");
    dbg.add_breakpoint(4); // add instruction — already passed; use next bp instead
    dbg.remove_breakpoint(4);
    dbg.add_breakpoint(5); // ret
    auto r=dbg.run();
    check(r.stop==DebugStop::breakpoint && r.pc==5,"breakpoint before ret");
    check(dbg.registers()[3]==12,"r3 computed before ret breakpoint");
    check(dbg.stack().size()==1 && dbg.stack()[0]==5,"frame at breakpoint");
    auto fin=dbg.step();
    check(fin.stop==DebugStop::returned,"returns after ret step");
    check(std::holds_alternative<std::int32_t>(fin.result) && std::get<std::int32_t>(fin.result)==12,"result 12");
    check(dbg.finished() && dbg.stack().empty(),"finished, stack empty");
  }
  // Breakpoint hit mid-run via run().
  {
    const auto code=arith();
    VmDebugger dbg(code);
    dbg.add_breakpoint(4); // add
    auto r=dbg.run();
    check(r.stop==DebugStop::breakpoint && r.pc==4,"run stops at add");
    check(dbg.registers()[3]==0,"add not yet executed");
    check(dbg.steps()==2,"two instructions executed");
    dbg.remove_breakpoint(4);
    auto fin=dbg.run();
    check(fin.stop==DebugStop::returned && std::get<std::int32_t>(fin.result)==12,"continues to return");
  }
  // Trap surfaces as VmError with the trapping pc.
  {
    const auto code=divzero();
    VmDebugger dbg(code);
    auto r=dbg.run();
    check(r.stop==DebugStop::trapped,"div traps");
    const auto* e=std::get_if<VmError>(&r.result);
    check(e && e->code==VmErrorCode::divide_by_zero && e->pc==4,"trap pc is div");
    check(dbg.last_pc()==4,"last_pc tracks trap");
  }
  // Stepping ignores breakpoints for the stepped instruction only.
  {
    const auto code=arith();
    VmDebugger dbg(code);
    dbg.add_breakpoint(0);
    auto s=dbg.step();
    check(s.stop==DebugStop::stepped && s.pc==2,"step ignores entry breakpoint");
    auto r=dbg.run();
    check(r.stop==DebugStop::returned,"run completes (pc 0 bp passed)");
  }
  // Debugging does not mutate caller state and matches run_register_vm.
  {
    std::array<std::int32_t,256> regs{};
    const auto code=arith();
    VmDebugger dbg(code,regs);
    auto fin=dbg.run();
    check(std::get<std::int32_t>(fin.result)==12,"debugger result");
    check(regs[1]==0 && regs[3]==0,"caller register file untouched");
    auto direct=run_register_vm(arith(),regs);
    check(std::get<std::int32_t>(direct)==std::get<std::int32_t>(fin.result),"matches direct run");
  }
  // Module-aware debugging: a call pushes a frame; stack() reports the
  // suspended caller pc followed by the callee pc, and returning restores
  // the caller's register file exactly.
  {
    const std::vector<Bytecode> functions={
      {{Opcode::ret,224,0,0}},                                     // fn0: identity(staged arg)
      {imm(224),pay(9),imm(1),pay(77),                             // fn1: stage 9, set r1=77
       {Opcode::call,0,224,2},{Opcode::ret,2,0,0}}                 // call fn0 -> r2, return
    };
    VmModule module{functions,{}};
    VmDebugger dbg(module,1);
    check(dbg.pc()==0 && dbg.stack().size()==1,"module debugger starts in entry frame");
    const auto s1=dbg.step(), s2=dbg.step(); // load_imm r224, r1 -> pc 4 (call)
    check(s1.stop==DebugStop::stepped && s2.stop==DebugStop::stepped,"two steps reach call");
    check(dbg.pc()==4,"call instruction reached");
    dbg.add_breakpoint(0); // fn0 entry pc; fn1's pc 0 is already behind us
    auto hit=dbg.run();
    check(hit.stop==DebugStop::breakpoint && hit.pc==0,"breakpoint in callee");
    check(dbg.stack()==std::vector<std::size_t>({5,0}),"stack reports caller return pc then callee pc");
    check(dbg.registers()[224]==9 && dbg.registers()[1]==0,"callee sees staged arg and fresh registers");
    auto back=dbg.step();
    check(back.stop==DebugStop::stepped && back.pc==5,"ret returns to caller pc");
    check(dbg.stack()==std::vector<std::size_t>({5}),"one frame after callee returns");
    check(dbg.registers()[1]==77 && dbg.registers()[2]==9,"caller registers restored with result bound");
    auto fin=dbg.step();
    check(fin.stop==DebugStop::returned && std::get<std::int32_t>(fin.result)==9,"module run returns 9");
    check(dbg.stack().empty(),"stack empty after final return");
  }
  // Budget and invalid input trap identically to the VM.
  {
    const auto code2=arith();
    VmDebugger dbg(code2,{},2);
    auto r=dbg.run();
    check(r.stop==DebugStop::trapped,"budget trap");
    const auto* e=std::get_if<VmError>(&r.result);
    check(e && e->code==VmErrorCode::budget_exceeded,"budget_exceeded");
    const Bytecode bad_code{{static_cast<Opcode>(0xEE),0,0,0},{Opcode::ret,0,0,0}};
    VmDebugger bad(bad_code);
    auto rb=bad.run();
    check(rb.stop==DebugStop::trapped,"invalid opcode traps");
  }
}
} // namespace
int main() {
  cases();
  if (failures) { std::cerr << failures << " debugger test(s) failed\n"; return 1; }
  std::cout << "debugger tests passed\n";
  return 0;
}
