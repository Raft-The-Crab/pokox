// MUT-36: runtime capability enforcement. Missing, narrowed and
// non-serializable capabilities are rejected; denied hostcalls do not run.
#include "poko/mute/hostcall.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/determinism.hpp"
#include "poko/mute/declaration.hpp"
#include "poko/mute/emit.hpp"
#include <array>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
HostcallDef def(std::uint32_t id,std::uint32_t caps=0) {
  HostcallDef d; d.id=id; d.version=1; d.result=HostType::integer; d.capabilities=caps;
  d.handler=[](HostcallArgs){ return HostcallResult{std::int32_t{1}}; };
  return d;
}
VmErrorCode run_err(const VmEnvironment* env,std::uint32_t id=1) {
  Bytecode prog{{Opcode::call_host,static_cast<std::uint8_t>(id),0,2},{Opcode::ret,2,0,0}};
  auto res=run_register_vm(prog,{},100'000,env);
  auto* e=std::get_if<VmError>(&res);
  return e ? e->code : VmErrorCode::invalid_bytecode;
}
std::uint32_t ceiling(std::string_view src) {
  auto parsed=parse_declarations(src);
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  return ast ? program_capability_mask(*ast) : 0xFFFFFFFFu;
}
Type i32() { return {TypeTag::scalar,"i32",{}}; }
IrOperand v(std::uint32_t id) { return {id,0}; }
IrOperand pv(std::uint32_t id,std::uint64_t imm) { return {id,imm}; }
// entry f calls priv(x), whose body issues hostcall 9 (requires Log).
// Per-function masks model the output of lower_module's @requires narrowing.
IrModule narrowed_module(std::uint32_t callee_mask,std::uint32_t caller_mask) {
  IrModule m;
  IrFunction priv; priv.name="priv"; priv.result=i32(); priv.params={i32()};
  priv.capabilities=callee_mask;
  IrBlock pb; pb.label="entry";
  IrInstr hc; hc.op=IrOp::call_host; hc.def=2; hc.result=i32(); hc.callee=1; hc.args={v(1)};
  IrInstr pr; pr.op=IrOp::return_; pr.result=i32(); pr.args={v(2)};
  pb.instrs={hc,pr}; priv.blocks.push_back(pb); m.functions.push_back(priv);
  IrFunction f; f.name="f"; f.result=i32(); f.capabilities=caller_mask;
  IrBlock fb; fb.label="entry";
  IrInstr k; k.op=IrOp::constant; k.def=1; k.result=i32(); k.args={pv(0,41)};
  IrInstr call; call.op=IrOp::call; call.def=2; call.result=i32(); call.callee=1; call.args={v(1)};
  IrInstr fr; fr.op=IrOp::return_; fr.result=i32(); fr.args={v(2)};
  fb.instrs={k,call,fr}; f.blocks.push_back(fb); m.functions.push_back(f);
  IrHostcall h; h.id=9; h.params={i32()}; h.result=i32(); m.hostcalls.push_back(h);
  return m;
}
VmResult run_narrowed(const EmitResult& em,const VmEnvironment& env) {
  VmModule module{em.functions,em.capabilities};
  return run_register_module(module,1,{},100'000,&env);
}
} // namespace
int main() {
  // Program allow: ceiling -> mask.
  check(ceiling("package \"a\" version \"A\" allow: Net, Time")==(capability_net|capability_time),"allow ceiling mask");
  check(ceiling("package \"a\" version \"A\"")==0,"no allow = empty ceiling");
  check(ceiling("package \"a\" version \"A\" allow: Teleport")==0,"unknown capability contributes no bits");
  check(capability_from_name("Spawn")==capability_spawn && capability_from_name("Bogus")==0,"name table roundtrip");
  check(capability_name(capability_log)=="Log" && capability_name(0x8000).empty(),"bit to name");

  // Effective grant = ceiling & host grant (narrowing).
  const auto prog=capability_net|capability_time;
  check(effective_capabilities(prog,capability_all)==prog,"host grant all keeps ceiling");
  check(effective_capabilities(prog,capability_net)==capability_net,"host narrows grant");
  check(effective_capabilities(0,capability_all)==0,"empty ceiling grants nothing");

  // Bind-time rejection: unauthorized ids are reported before any run.
  HostcallTable table;
  check(table.add(def(1))==HostcallTable::AddError::ok,"register cap-free hostcall");
  check(table.add(def(2,capability_log))==HostcallTable::AddError::ok,"register Log hostcall");
  check(table.add(def(3,capability_net|capability_time))==HostcallTable::AddError::ok,"register Net+Time hostcall");
  auto bad=unauthorized_hostcalls(table,effective_capabilities(prog,capability_net));
  check(bad==std::vector<std::uint32_t>({2,3}),"narrowed grant flags Log and Net+Time hostcalls");
  check(unauthorized_hostcalls(table,capability_all).empty(),"full grant authorizes all");

  // Runtime denial: missing capability -> trap, handler never runs.
  bool ran=false;
  HostcallTable t2; HostcallDef d2=def(1,capability_log); d2.handler=[&](HostcallArgs){ran=true;return HostcallResult{std::int32_t{1}};};
  (void)t2.add(d2);
  VmEnvironment env; env.hostcalls=&t2; env.capabilities=capability_net; // Log not granted
  check(run_err(&env)==VmErrorCode::capability_denied && !ran,"missing capability denied, handler not run");
  env.capabilities=capability_log;
  {
    Bytecode p{{Opcode::call_host,1,0,2},{Opcode::ret,2,0,0}};
    auto res=run_register_vm(p,{},100'000,&env);
    check(std::holds_alternative<std::int32_t>(res)&&std::get<std::int32_t>(res)==1 && ran,"granted capability dispatches");
  }

  // Non-serializable hostcalls rejected in serialized/replay runs only.
  HostcallTable t3; HostcallDef d3=def(4); d3.serializable=false; bool ran3=false;
  d3.handler=[&](HostcallArgs){ran3=true;return HostcallResult{std::int32_t{2}};};
  (void)t3.add(d3);
  VmEnvironment env3; env3.hostcalls=&t3; env3.capabilities=capability_all;
  Bytecode p3{{Opcode::call_host,4,0,2},{Opcode::ret,2,0,0}};
  {
    auto res=run_register_vm(p3,{},100'000,&env3);
    check(std::get<std::int32_t>(res)==2 && ran3,"serializable=false still runs live");
  }
  env3.serialized_run=true;
  {
    auto res=run_register_vm(p3,{},100'000,&env3);
    auto* e=std::get_if<VmError>(&res);
    check(e && e->code==VmErrorCode::capability_denied,"non-serializable hostcall denied in serialized run");
  }

  // Per-function @requires narrowing is enforced by real call frames: the
  // callee's mask, the caller's mask and the host grant must all allow Log.
  {
    HostcallTable table; bool ran=false;
    HostcallDef d=def(9,capability_log);
    d.params={HostType::integer};  // module signature passes one i32 arg
    d.handler=[&](HostcallArgs args){ ran=true; return HostcallResult{std::int32_t{args[0]+1}}; };
    check(table.add(d)==HostcallTable::AddError::ok,"register hostcall 9");
    VmEnvironment env; env.hostcalls=&table; env.capabilities=capability_log;
    auto em=emit_bytecode(narrowed_module(capability_log,capability_all));
    check(em.ok(),"narrowed call module emits");
    if (em.ok()) {
      auto res=run_narrowed(em,env);
      check(ran && std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==42,
            "@requires(Log) callee dispatches through call frame");
      ran=false;
      em=emit_bytecode(narrowed_module(0,capability_all));
      auto denied=run_narrowed(em,env);
      check(!ran && std::get_if<VmError>(&denied) &&
            std::get<VmError>(denied).code==VmErrorCode::capability_denied,
            "callee narrowed to zero capabilities cannot call Log hostcall");
      ran=false;
      em=emit_bytecode(narrowed_module(capability_all,0));
      auto caller_denied=run_narrowed(em,env);
      check(!ran && std::get_if<VmError>(&caller_denied) &&
            std::get<VmError>(caller_denied).code==VmErrorCode::capability_denied,
            "caller narrowing intersects callee grant at dispatch");
    }
  }

  // Capability tokens can never enter @state (MUT-24) — spot-check the ban
  // still holds through the shared name table.
  auto parsed=parse_declarations("package \"a\" version \"A\" @state var s: Storage = ()");
  const auto* ast=std::get_if<DeclarationAst>(&parsed);
  check(ast && !analyze_determinism(*ast).ok(),"capability token in @state still rejected");

  if (failures) { std::cerr << failures << " capability check(s) failed\n"; return 1; }
  std::cout << "mute capability unit passed\n";
  return 0;
}
