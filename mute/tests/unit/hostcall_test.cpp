// MUT-35: versioned, typed hostcall boundary. Valid calls dispatch; unknown
// ids, malformed arguments and signatures trap before dispatch.
#include "poko/mute/hostcall.hpp"
#include "poko/mute/bytecode.hpp"
#include "poko/mute/register_vm.hpp"
#include <array>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
HostcallDef def(std::uint32_t id,std::vector<HostType> params,HostType result,std::uint32_t caps=0) {
  HostcallDef d; d.id=id; d.version=1; d.params=std::move(params); d.result=result; d.capabilities=caps;
  d.handler=[](HostcallArgs){ return HostcallResult{std::int32_t{0}}; };
  return d;
}
VmErrorCode run_err(std::span<const Instruction> code,const VmEnvironment* env,std::array<std::int32_t,256> r={}) {
  auto res=run_register_vm(code,r,100'000,env);
  auto* e=std::get_if<VmError>(&res);
  return e ? e->code : VmErrorCode::invalid_bytecode;
}
} // namespace
int main() {
  // --- Table registration ---
  HostcallTable table;
  check(table.add(def(7,{HostType::integer,HostType::boolean},HostType::integer))==HostcallTable::AddError::ok,"add valid def");
  check(table.add(def(7,{HostType::integer},HostType::unit))==HostcallTable::AddError::duplicate_id,"duplicate id rejected");
  check(table.add(def(256,{},{HostType::unit}))==HostcallTable::AddError::invalid_id,"id >255 rejected");
  check(table.add(def(8,{HostType::unit},{HostType::unit}))==HostcallTable::AddError::invalid_signature,"unit param rejected");
  HostcallDef nohandler=def(9,{},{HostType::unit}); nohandler.handler={};
  check(table.add(nohandler)==HostcallTable::AddError::missing_handler,"missing handler rejected");
  check(table.add(def(10,{},{HostType::unit},0xFFFF))==HostcallTable::AddError::unknown_capability,"unknown capability bits rejected");
  HostcallDef v0=def(11,{},{HostType::unit}); v0.version=0;
  check(table.add(v0)==HostcallTable::AddError::invalid_signature,"version 0 rejected");
  check(table.find(7)!=nullptr && table.find(8)==nullptr,"find by id");

  // --- Valid dispatch ---
  bool called=false; std::vector<std::int32_t> seen;
  HostcallTable t2;
  HostcallDef add=def(1,{HostType::integer,HostType::integer},HostType::integer);
  add.handler=[&](HostcallArgs a){ called=true; seen.assign(a.begin(),a.end()); return HostcallResult{a[0]+a[1]}; };
  check(t2.add(add)==HostcallTable::AddError::ok,"register add hostcall");
  VmEnvironment env; env.hostcalls=&t2;
  std::array<std::int32_t,256> r{}; r[10]=20; r[11]=-3;
  Bytecode prog{{Opcode::call_host,1,10,12},{Opcode::ret,12,0,0}};
  auto res=run_register_vm(prog,r,100'000,&env);
  check(called && seen==std::vector<std::int32_t>{20,-3},"handler received arg window");
  check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==17,"result returned");

  // Discard result (c=0) still dispatches.
  called=false;
  Bytecode discard{{Opcode::call_host,1,10,0},{Opcode::ret,10,0,0}};
  res=run_register_vm(discard,r,100'000,&env);
  check(called && std::get<std::int32_t>(res)==20,"discarded result still dispatches");

  // Unit result ignores handler value; c must be 0.
  HostcallTable t3;
  HostcallDef unit=def(2,{HostType::integer},HostType::unit);
  unit.handler=[](HostcallArgs){ return HostcallResult{std::int32_t{99}}; };
  check(t3.add(unit)==HostcallTable::AddError::ok,"register unit hostcall");
  VmEnvironment env3; env3.hostcalls=&t3;
  Bytecode unit_ok{{Opcode::call_host,2,10,0},{Opcode::ret,10,0,0}};
  check(std::get<std::int32_t>(run_register_vm(unit_ok,r,100'000,&env3))==20,"unit result dispatches");
  Bytecode unit_bad{{Opcode::call_host,2,10,11},{Opcode::ret,1,0,0}};
  check(run_err(unit_bad,&env3,r)==VmErrorCode::hostcall_signature,"unit result with return reg rejected");

  // --- Pre-dispatch traps ---
  Bytecode unknown{{Opcode::call_host,99,10,12},{Opcode::ret,1,0,0}};
  check(run_err(unknown,&env,r)==VmErrorCode::unknown_hostcall,"unknown id traps");
  check(run_err(unknown,nullptr,r)==VmErrorCode::unknown_hostcall,"null environment traps");
  VmEnvironment wrong_abi; wrong_abi.hostcalls=&t2; wrong_abi.hostcall_abi=2;
  check(run_err(prog,&wrong_abi,r)==VmErrorCode::hostcall_signature,"abi version mismatch traps");
  // Arg window overflow: b=255 with 2 params needs r256.
  Bytecode wide{{Opcode::call_host,1,255,12},{Opcode::ret,1,0,0}};
  check(run_err(wide,&env,r)==VmErrorCode::hostcall_signature,"arg window overflow traps");
  // Boolean param rejects non-0/1 before dispatch.
  HostcallTable t4;
  bool bool_called=false;
  HostcallDef bdef=def(3,{HostType::boolean},HostType::integer);
  bdef.handler=[&](HostcallArgs){ bool_called=true; return HostcallResult{std::int32_t{1}}; };
  check(t4.add(bdef)==HostcallTable::AddError::ok,"register boolean hostcall");
  VmEnvironment env4; env4.hostcalls=&t4;
  r[10]=5;
  Bytecode bcall{{Opcode::call_host,3,10,12},{Opcode::ret,12,0,0}};
  check(run_err(bcall,&env4,r)==VmErrorCode::hostcall_signature && !bool_called,"non-boolean arg traps before dispatch");
  r[10]=1;
  check(std::get<std::int32_t>(run_register_vm(bcall,r,100'000,&env4))==1 && bool_called,"boolean arg dispatches");
  // Boolean result must be 0/1.
  HostcallTable t5;
  HostcallDef bres=def(4,{},{HostType::boolean});
  bres.handler=[](HostcallArgs){ return HostcallResult{std::int32_t{7}}; };
  check(t5.add(bres)==HostcallTable::AddError::ok,"register boolean-result hostcall");
  VmEnvironment env5; env5.hostcalls=&t5;
  Bytecode bres_call{{Opcode::call_host,4,10,12},{Opcode::ret,1,0,0}};
  check(run_err(bres_call,&env5,r)==VmErrorCode::hostcall_signature,"out-of-range boolean result traps");
  // Handler failure traps after dispatch.
  HostcallTable t6;
  HostcallDef faildef=def(5,{},{HostType::integer});
  faildef.handler=[](HostcallArgs){ return HostcallResult{HostcallError{HostcallErrorCode::failed}}; };
  check(t6.add(faildef)==HostcallTable::AddError::ok,"register failing hostcall");
  VmEnvironment env6; env6.hostcalls=&t6;
  Bytecode failcall{{Opcode::call_host,5,10,12},{Opcode::ret,1,0,0}};
  check(run_err(failcall,&env6,r)==VmErrorCode::hostcall_failed,"handler error traps");
  // Capability denial happens before dispatch; handler never runs.
  HostcallTable t7;
  bool denied_called=false;
  HostcallDef capdef=def(6,{},{HostType::integer},capability_log);
  capdef.handler=[&](HostcallArgs){ denied_called=true; return HostcallResult{std::int32_t{1}}; };
  check(t7.add(capdef)==HostcallTable::AddError::ok,"register capability hostcall");
  VmEnvironment env7; env7.hostcalls=&t7; // capabilities defaults to 0
  Bytecode capcall{{Opcode::call_host,6,10,12},{Opcode::ret,12,0,0}};
  check(run_err(capcall,&env7,r)==VmErrorCode::capability_denied && !denied_called,"missing capability denied before dispatch");
  env7.capabilities=capability_log;
  check(std::get<std::int32_t>(run_register_vm(capcall,r,100'000,&env7))==1 && denied_called,"granted capability dispatches");
  // call_host consumes budget like any instruction.
  Bytecode loop{{Opcode::call_host,1,10,12},{Opcode::jump,0,0xff,0xfe}};
  check(run_err(loop,&env,r)==VmErrorCode::budget_exceeded,"hostcall loop hits budget");

  // --- Codec roundtrip ---
  const Bytecode hc{{Opcode::call_host,7,200,3},{Opcode::ret,3,0,0}};
  const auto text=std::get<std::string>(disassemble_bytecode(hc));
  check(text=="0: call_host 7, r200, r3\n1: ret r3\n","call_host disassembly golden");
  check(std::get<Bytecode>(assemble_bytecode(text))==hc,"call_host assembly roundtrip");
  const auto wire=encode_bytecode(hc);
  check(std::get<Bytecode>(decode_bytecode(std::get<std::vector<std::uint8_t>>(wire)))==hc,"call_host wire roundtrip");
  check(std::holds_alternative<BytecodeError>(validate_bytecode(Bytecode{{Opcode::call_host,0,0,0}})),"call_host cannot be last");
  check(std::holds_alternative<BytecodeError>(assemble_bytecode("0: call_host r7, r10, r20\n")),"call_host id is not a register");
  check(std::holds_alternative<BytecodeError>(assemble_bytecode("0: call_host 300, r10, r20\n")),"call_host id range");

  if (failures) { std::cerr << failures << " hostcall check(s) failed\n"; return 1; }
  std::cout << "mute hostcall unit passed\n";
  return 0;
}
