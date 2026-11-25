// MUT-37: VM resource limits. Budget, call-depth and hostcall quotas trap at
// tested boundaries without corruption. Heap quotas are enforced inside
// AggregateStore (MUT-22) and are covered by mute_values_unit.
#include "poko/mute/hostcall.hpp"
#include "poko/mute/bytecode.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/emit.hpp"
#include "poko/mute/lower.hpp"
#include "poko/mute/declaration.hpp"
#include <array>
#include <iostream>
#include <string>
#include <variant>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }

// Real Opcode::call frames: rec(n) descends n+1 frames below entry f.
bool compile_recursion(int n,EmitResult& em,std::size_t& entry) {
  const std::string src="package \"a\" version \"A\" fn rec(n: i32) -> i32 { "
    "if n == 0 { return 0; } return rec(n - 1); } fn f() -> i32 { return rec("+
    std::to_string(n)+"); }";
  auto parsed=parse_declarations(src);
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  if (!ast) return false;
  auto lm=lower_module(*ast);
  if (!lm.ok()) return false;
  em=emit_bytecode(lm.module);
  if (!em.ok()) return false;
  entry=0;
  for (std::size_t i=0;i<lm.module.functions.size();++i)
    if (lm.module.functions[i].name=="f") entry=i;
  return true;
}
VmResult run_recursion(const EmitResult& em,std::size_t entry,std::size_t limit,VmRunState* state) {
  VmEnvironment env; env.state=state; env.max_call_depth=limit;
  VmModule module{em.functions,em.capabilities};
  return run_register_module(module,entry,{},100'000,&env);
}
} // namespace
int main() {
  // Instruction budget: spec default cap is 1M; beyond it is invalid_budget.
  Bytecode tiny{{Opcode::ret,1,0,0}};
  check(std::get<std::int32_t>(run_register_vm(tiny,{},1'000'000))==0,"max budget accepted");
  check(std::get<VmError>(run_register_vm(tiny,{},1'000'001)).code==VmErrorCode::invalid_budget,"budget over cap rejected");
  Bytecode spin{{Opcode::jump,0,0xff,0xff}};
  check(std::get<VmError>(run_register_vm(spin,{},10)).code==VmErrorCode::budget_exceeded,"instruction budget traps");

  // Hostcall quota: default 1000/run; a tighter limit traps at the boundary.
  HostcallTable table;
  HostcallDef d; d.id=1; d.result=HostType::integer;
  d.handler=[](HostcallArgs){ return HostcallResult{std::int32_t{7}}; };
  (void)table.add(d);
  VmEnvironment env; env.hostcalls=&table; env.max_hostcalls=3;
  // call_host + jump back = 2 steps per dispatch; budget 100 is ample.
  Bytecode loop{{Opcode::call_host,1,0,2},{Opcode::jump,0,0xff,0xfe}};
  VmRunState state;
  env.state=&state;
  auto res=run_register_vm(loop,{},100,&env);
  auto* e=std::get_if<VmError>(&res);
  check(e && e->code==VmErrorCode::hostcall_quota,"hostcall quota traps at limit");
  check(state.hostcalls==3,"quota charged exactly max dispatches");
  check(state.depth==0,"depth restored after trap");
  // Without the shared state the same loop hits the instruction budget first.
  VmEnvironment untracked; untracked.hostcalls=&table;
  res=run_register_vm(loop,{},100,&untracked);
  e=std::get_if<VmError>(&res);
  check(e && e->code==VmErrorCode::budget_exceeded,"untracked run still budget-bounded");

  // Call depth: shared state bounds host-mediated VM recursion.
  VmRunState deep; deep.depth=64;
  VmEnvironment denv; denv.hostcalls=&table; denv.state=&deep; denv.max_call_depth=64;
  res=run_register_vm(tiny,{},100,&denv);
  e=std::get_if<VmError>(&res);
  check(e && e->code==VmErrorCode::call_depth_exceeded,"depth 64 boundary traps");
  check(deep.depth==64,"rejected run does not consume depth");
  deep.depth=0;
  res=run_register_vm(tiny,{},100,&denv);
  check(std::holds_alternative<std::int32_t>(res) && deep.depth==0,"depth restored after success");

  // Nested re-entry through a hostcall handler shares the run state.
  VmRunState nest; nest.depth=62; nest.hostcalls=0;
  VmEnvironment nenv; nenv.state=&nest; nenv.max_call_depth=64;
  HostcallTable ntable;
  HostcallDef nd; nd.id=9; nd.result=HostType::integer;
  nd.handler=[&](HostcallArgs)->HostcallResult {
    Bytecode inner{{Opcode::ret,1,0,0}};
    auto inner_res=run_register_vm(inner,{},100,&nenv);
    return std::holds_alternative<VmError>(inner_res)
      ? HostcallResult{HostcallError{HostcallErrorCode::failed}}
      : HostcallResult{std::int32_t{3}};
  };
  (void)ntable.add(nd);
  nenv.hostcalls=&ntable;
  Bytecode outer{{Opcode::call_host,9,0,2},{Opcode::ret,2,0,0}};
  res=run_register_vm(outer,{},100,&nenv);
  // depth 62 -> outer run depth 63, handler's nested run reaches 64 (ok),
  // returns; outer completes. A third level would trap.
  check(std::get<std::int32_t>(res)==3 && nest.depth==62,"nested run shares and restores depth");

  // Quota is per shared state, not per call frame.
  VmRunState qstate;
  VmEnvironment qenv; qenv.hostcalls=&table; qenv.state=&qstate; qenv.max_hostcalls=2;
  res=run_register_vm(loop,{},100,&qenv);
  e=std::get_if<VmError>(&res);
  check(e && e->code==VmErrorCode::hostcall_quota && qstate.hostcalls==2,"shared quota accumulates across run");

  // Real call frames share the depth counter. Entry f starts at depth 1 and
  // rec(n)..rec(0) adds n+1 calls, so rec(9) reaches depth 11; a limit one
  // lower traps at the call instruction and restores depth on exit.
  {
    EmitResult em; std::size_t entry=0;
    check(compile_recursion(9,em,entry),"rec(9) compiles");
    VmRunState st;
    if (!em.functions.empty()) {
      auto ok=run_recursion(em,entry,11,&st);
      check(std::holds_alternative<std::int32_t>(ok) && std::get<std::int32_t>(ok)==0 && st.depth==0,
            "11 frames allow rec(9); depth restored");
      auto trap=run_recursion(em,entry,10,&st);
      auto* ce=std::get_if<VmError>(&trap);
      check(ce && ce->code==VmErrorCode::call_depth_exceeded && st.depth==0 && st.hostcalls==0,
            "10 frames trap a real Opcode::call; depth restored");
    }
  }
  // The spec default depth-64 boundary applies to compiled recursion too:
  // rec(62) reaches depth 64, rec(63) needs one frame more.
  {
    EmitResult em; std::size_t entry=0;
    check(compile_recursion(62,em,entry),"rec(62) compiles");
    VmRunState st;
    if (!em.functions.empty()) {
      auto ok=run_recursion(em,entry,64,&st);
      check(std::holds_alternative<std::int32_t>(ok) && st.depth==0,"depth 64 allows 63 nested calls");
    }
    check(compile_recursion(63,em,entry),"rec(63) compiles");
    auto trap=run_recursion(em,entry,64,&st);
    auto* ce=std::get_if<VmError>(&trap);
    check(ce && ce->code==VmErrorCode::call_depth_exceeded && st.depth==0,
          "depth 64 traps the 64th nested call");
  }

  if (failures) { std::cerr << failures << " limits check(s) failed\n"; return 1; }
  std::cout << "mute limits unit passed\n";
  return 0;
}
