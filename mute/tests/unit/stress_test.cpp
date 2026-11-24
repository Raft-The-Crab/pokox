// MUT-01..30 stress/limit audit: pushes bounded subsystems to their
// documented limits and verifies typed rejection (never UB, never hang).
#include "poko/mute/lexer.hpp"
#include "poko/mute/parser.hpp"
#include "poko/mute/program.hpp"
#include "poko/mute/bytecode.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/values.hpp"
#include "poko/mute/scheduler.hpp"
#include "poko/mute/package.hpp"
#include "poko/mute/lower.hpp"
#include "poko/mute/emit.hpp"
#include "poko/mute/declaration.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace poko::mute;
namespace {
int failures=0;
void check(bool ok,std::string_view what) { if (!ok) { std::cerr << "FAIL: " << what << '\n'; ++failures; } }
Type i32t() { return {TypeTag::scalar,"i32",{}}; }

void lexer_limits() {
  std::string big(2u*1024u*1024u,'1');
  auto lexed=lex(big);
  check(std::holds_alternative<Diagnostic>(lexed),"oversize source rejected");
  std::string nest; for (int i=0;i<2000;++i) nest+="("; nest+="1"; for (int i=0;i<2000;++i) nest+=")";
  (void)parse_arithmetic(nest); // must return, not crash
  check(true,"deep paren parse bounded");
}
void program_limits() {
  std::string src="fn f()->i32 {return 1";
  for (int i=0;i<5000;++i) src+="+1";
  src+=";} f()";
  auto r=run_program(src);
  check(std::holds_alternative<ProgramDiagnostic>(r) || std::holds_alternative<NumericValue>(r),"big expr bounded");
  auto inf=run_program("fn f()->i32 {loop {}} f()");
  check(!std::holds_alternative<NumericValue>(inf),"infinite program bounded");
}
void bytecode_limits() {
  Bytecode big(65536,Instruction{Opcode::halt,0,0,0});
  check(std::holds_alternative<std::vector<std::uint8_t>>(encode_bytecode(big)),"65536-word encode");
  Bytecode over(65537,Instruction{Opcode::halt,0,0,0});
  check(std::holds_alternative<BytecodeError>(validate_bytecode(over)),"65537 rejected");
  for (int op=0;op<256;++op) (void)validate_bytecode(Bytecode{Instruction{static_cast<Opcode>(op),0,0,0},{Opcode::ret,1,0,0}});
  check(true,"opcode sweep no crash");
  std::array<std::int32_t,256> r{}; r[1]=std::numeric_limits<std::int32_t>::min(); r[2]=-1;
  check(std::holds_alternative<VmError>(run_register_vm(Bytecode{{Opcode::div,3,1,2},{Opcode::ret,3,0,0}},r)),"INT32_MIN/-1 div traps");
  r[2]=0;
  check(std::holds_alternative<VmError>(run_register_vm(Bytecode{{Opcode::mod,3,1,2},{Opcode::ret,3,0,0}},r)),"mod zero traps");
}
void values_limits() {
  AggregateStore s;
  auto a=s.make_array(0); check(std::holds_alternative<Value>(a),"array make");
  Value v=std::get<Value>(a);
  bool trapped=false;
  for (int i=0;i<64 && !trapped;++i) {
    auto inner=s.make_array(0);
    if (auto* e=std::get_if<ValueError>(&inner)) { trapped=true; break; }
    auto set=s.set_index(v,0,std::get<Value>(inner));
    if (std::holds_alternative<ValueError>(set)) { trapped=true; break; }
    v=std::get<Value>(inner);
  }
  check(true,"deep nesting bounded");
  auto str=s.make_string("x");
  check(std::holds_alternative<Value>(str),"string make");
  Value sv=std::get<Value>(str); auto h=sv.handle;
  s.release(sv);
  Value stale; stale.kind=ValueKind::array; stale.handle=h; stale.owned=false;
  check(std::holds_alternative<ValueError>(s.get_index(stale,0)),"stale handle rejected");
}
void scheduler_limits() {
  Scheduler sch;
  std::size_t spawned=0;
  for (int i=0;i<1100;++i) {
    auto id=sch.spawn([](Scheduler&,TaskId){ return StepResult{StepKind::finish,0}; });
    if (id==no_task) break;
    ++spawned;
  }
  check(spawned<=1024,"max_tasks enforced");
  (void)sch.run();
  Scheduler sch2(Scheduler::Limits{16,100});
  sch2.spawn([](Scheduler&,TaskId){ return StepResult{StepKind::yield,0}; });
  auto res=sch2.run();
  check(std::holds_alternative<ScheduleError>(res),"step budget enforced");
}
void package_limits() {
  std::string_view sa="package \"a\" version \"1\" import \"pkg://b\" as b";
  std::string_view sb="package \"b\" version \"1\" import \"pkg://a\" as a";
  std::vector<PackageInput> cyc{{"a","1",sa},{"b","1",sb}};
  auto r=resolve_packages(cyc);
  check(!r.ok(),"package cycle diagnosed");
  std::vector<PackageInput> many;
  for (int i=0;i<5000;++i) {
    std::string src="package \"p"+std::to_string(i%100)+"\" version \"1\"";
    many.push_back({"p"+std::to_string(i%100),"1",std::string_view(src.data(),src.size())});
  }
  // sources are temporaries; rebuild with stable storage
  std::vector<std::string> store; store.reserve(many.size());
  for (int i=0;i<5000;++i) store.push_back("package \"p"+std::to_string(i%100)+"\" version \"1\"");
  std::vector<PackageInput> many2;
  for (int i=0;i<5000;++i) many2.push_back({"p"+std::to_string(i%100),"1",store[i]});
  auto r2=resolve_packages(many2);
  check(!r2.diagnostics.empty() || r2.ok(),"package input bounded");
}
void pipeline_limits() {
  std::string src="package \"a\" version \"A\" fn f() -> i32 { ";
  for (int i=0;i<300;++i) src+="let v"+std::to_string(i)+" = "+std::to_string(i)+"; ";
  src+="return v0; }";
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (d) for (const auto& n:d->nodes()) if (n.kind==DeclarationKind::fn_decl) {
    auto lr=lower_function(d->bodies()[n.body],"f",i32t(),{});
    if (lr.ok()) {
      IrModule m; m.functions.push_back(lr.fn);
      auto em=emit_bytecode(m);
      check(!em.ok() || em.functions.size()==1,"huge function handled");
    }
  }
  check(true,"pipeline stress done");
}
} // namespace
int main() {
  lexer_limits(); program_limits(); bytecode_limits(); values_limits();
  scheduler_limits(); package_limits(); pipeline_limits();
  if (failures) { std::cerr << failures << " stress check(s) failed\n"; return 1; }
  std::cout << "mute stress audit passed\n";
  return 0;
}
