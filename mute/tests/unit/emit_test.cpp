#include "poko/mute/emit.hpp"
#include "poko/mute/hostcall.hpp"
#include "poko/mute/register_vm.hpp"
#include "poko/mute/declaration.hpp"
#include "poko/mute/lower.hpp"
#include "poko/mute/fold.hpp"
#include "poko/mute/optimize.hpp"
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
// f0 add(a,b) = a+b; f1 main() = add(20,22). Exercises the call window:
// main stages 20/22 in r224/r225, add's prologue moves them to r1/r2.
IrModule calls_module() {
  IrModule m;
  IrFunction add; add.name="add"; add.result=i32(); add.params={i32(),i32()};
  IrBlock ae; ae.label="entry";
  IrInstr sum; sum.op=IrOp::binary; sum.def=3; sum.result=i32(); sum.detail=0; sum.args={v(1),v(2)};
  IrInstr ar; ar.op=IrOp::return_; ar.result=i32(); ar.args={v(3)};
  ae.instrs={sum,ar}; add.blocks.push_back(ae); m.functions.push_back(add);
  IrFunction mainf; mainf.name="main"; mainf.result=i32();
  IrBlock me; me.label="entry";
  IrInstr a; a.op=IrOp::constant; a.def=1; a.result=i32(); a.args={pv(0,20)};
  IrInstr b; b.op=IrOp::constant; b.def=2; b.result=i32(); b.args={pv(0,22)};
  IrInstr call; call.op=IrOp::call; call.def=3; call.result=i32(); call.callee=1; call.args={v(1),v(2)};
  IrInstr mr; mr.op=IrOp::return_; mr.result=i32(); mr.args={v(3)};
  me.instrs={a,b,call,mr}; mainf.blocks.push_back(me); m.functions.push_back(mainf);
  return m;
}
// One function staging 40/2 through the call window into registered hostcall
// 7, then returning its result. Mirrors the IR shape a future hostcall
// lowering would produce (MUT-35 boundary + slice 5 emission).
IrModule hostcall_module() {
  IrModule m;
  IrFunction f; f.name="use_log"; f.result=i32();
  IrBlock e; e.label="entry";
  IrInstr a; a.op=IrOp::constant; a.def=1; a.result=i32(); a.args={pv(0,40)};
  IrInstr b; b.op=IrOp::constant; b.def=2; b.result=i32(); b.args={pv(0,2)};
  IrInstr hc; hc.op=IrOp::call_host; hc.def=3; hc.result=i32(); hc.callee=1;
  hc.args={v(1),v(2)}; hc.pos={3,1,4};
  IrInstr r; r.op=IrOp::return_; r.result=i32(); r.args={v(3)};
  e.instrs={a,b,hc,r}; f.blocks.push_back(e); m.functions.push_back(f);
  IrHostcall def; def.id=7; def.params={i32(),i32()}; def.result=i32();
  m.hostcalls.push_back(def);
  return m;
}
IrModule wide_call_module() {
  IrModule m;
  IrFunction callee; callee.name="wide"; callee.result=i32();
  callee.params.assign(33,i32());
  IrBlock ce; ce.label="entry";
  IrInstr cr; cr.op=IrOp::return_; cr.result=i32(); cr.args={v(1)};
  ce.instrs.push_back(cr); callee.blocks.push_back(ce); m.functions.push_back(callee);
  return m;
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
    std::array<std::int32_t,256> r{}; r[call_arg_base]=3; r[call_arg_base+1]=4;
    auto res=run_register_vm(e.functions[0],r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==7,"arith executes to 7");
  }
  // Control flow + phi edge moves.
  {
    auto e=emit_bytecode(select_module());
    check(e.ok(),"select emit ok");
    std::array<std::int32_t,256> r{}; r[call_arg_base]=3; r[call_arg_base+1]=7;
    auto res=run_register_vm(e.functions[0],r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==3,"select true -> x");
    r[call_arg_base]=9; r[call_arg_base+1]=7;
    res=run_register_vm(e.functions[0],r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==7,"select false -> y");
  }
  // Internal calls: args stage in the 224..255 window and the callee
  // prologue maps them to params 1..N.
  {
    auto e=emit_bytecode(calls_module());
    check(e.ok(),"call emit ok");
    check(e.capabilities.size()==e.functions.size(),"capabilities parallel to functions");
    VmModule module{e.functions,e.capabilities};
    auto res=run_register_module(module,1);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==42,"call executes to 42");
    std::array<std::int32_t,256> r{}; r[call_arg_base]=3; r[call_arg_base+1]=4;
    res=run_register_module(module,0,r);
    check(std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==7,"prologue maps window to params");
  }
  // IR -> call_host: args staged in the call window, hostcall id in operand a,
  // result bound to the IR def; dispatch checks the frame's capability mask.
  {
    auto m=hostcall_module();
    auto e=emit_bytecode(m);
    check(e.ok(),"call_host emit ok");
    check(e.functions.size()==1 && e.functions[0].size()==8,"call_host emits stage/call instruction words");
    auto listing=disassemble_bytecode(e.functions[0]);
    const auto* text=std::get_if<std::string>(&listing);
    check(text && text->find("call_host 7, r224, r3")!=std::string::npos,"call_host operand layout");
    check(text && text->find("mov r224, r1")!=std::string::npos &&
          text->find("mov r225, r2")!=std::string::npos,"hostcall args staged in window");
    HostcallTable table; HostcallDef d; d.id=7; d.version=1;
    d.params={HostType::integer,HostType::integer}; d.result=HostType::integer;
    d.capabilities=capability_log;
    bool ran=false;
    d.handler=[&](HostcallArgs args){ ran=true; return HostcallResult{std::int32_t{args[0]+args[1]}}; };
    check(table.add(d)==HostcallTable::AddError::ok,"register hostcall 7");
    VmEnvironment env; env.hostcalls=&table; env.capabilities=capability_log;
    auto res=run_register_vm(e.functions[0],{},100'000,&env);
    check(ran && std::holds_alternative<std::int32_t>(res) && std::get<std::int32_t>(res)==42,
          "call_host emission dispatches and binds result");
    ran=false; env.capabilities=0;
    auto denied=run_register_vm(e.functions[0],{},100'000,&env);
    check(!ran && std::get_if<VmError>(&denied) &&
          std::get<VmError>(denied).code==VmErrorCode::capability_denied,
          "emitted call_host obeys capability grant");
    check(source_position(e,0,6).byte==3,"call_host carries source position");
    auto bad=hostcall_module(); bad.functions[0].blocks[0].instrs[2].args.pop_back();
    auto be=emit_bytecode(bad);
    check(!be.diagnostics.empty(),"hostcall arity rejected by verifier");
  }
  // The staged window is 32 registers; a wider call is a typed emit error,
  // never a wrapped register index.
  {
    auto e=emit_bytecode(wide_call_module());
    check(!e.ok(),"33-parameter function rejected");
    bool too_many=false;
    for (const auto& err:e.errors) if (err.code==EmitErrorCode::too_many_values) too_many=true;
    check(too_many,"wide call reports too_many_values");
  }
  // Unsupported ops and failed verification are typed errors.
  {
    auto m=arith_module(); IrInstr load; load.op=IrOp::load; load.def=9; load.result=i32();
    load.args={v(1)}; // passes verify, emit still rejects
    m.functions[0].blocks[0].instrs.insert(m.functions[0].blocks[0].instrs.begin(),load);
    auto e=emit_bytecode(m); check(!e.ok() && !e.errors.empty(),"load rejected");
    // Constants now emit via load_imm and execute.
    { auto cm=arith_module(); IrInstr k; k.op=IrOp::constant; k.def=9; k.result=i32(); k.args={pv(0,40)};
      cm.functions[0].blocks[0].instrs.insert(cm.functions[0].blocks[0].instrs.begin(),k);
      cm.functions[0].blocks[0].instrs.back().args={v(9)}; // return the constant
      auto ce=emit_bytecode(cm); check(ce.ok(),"constant emits");
      std::array<std::int32_t,256> rr{}; rr[call_arg_base]=2;
      auto rr2=run_register_vm(ce.functions[0],rr);
      check(std::holds_alternative<std::int32_t>(rr2) && std::get<std::int32_t>(rr2)==40,"constant executes"); }
    auto bad=arith_module(); bad.functions[0].blocks.clear();
    auto e2=emit_bytecode(bad); check(!e2.diagnostics.empty(),"verify failure reported");
  }
  // Deterministic emission.
  { auto a=emit_bytecode(select_module()),b=emit_bytecode(select_module());
    check(a.functions[0]==b.functions[0],"emit deterministic"); }
}

// Parse source, lower the first fn_decl, optionally run the MUT-28/29/30
// pipeline, then emit. Returns the EmitResult; mod keeps the final IR.
bool compile_source(std::string_view src,bool optimize,EmitResult& em,IrModule& mod) {
  auto parsed=parse_declarations(src);
  const auto* d=std::get_if<DeclarationAst>(&parsed);
  if (!d) return false;
  const auto& nodes=d->nodes(); const auto& bodies=d->bodies();
  std::size_t body_idx=no_declaration;
  for (const auto& n:nodes) if (n.kind==DeclarationKind::fn_decl && n.body<bodies.size()) { body_idx=n.body; break; }
  if (body_idx==no_declaration) return false;
  LowerResult lr=lower_function(bodies[body_idx],"f",i32(),{});
  if (!lr.ok()) return false;
  mod.functions.push_back(lr.fn);
  if (optimize) {
    mod=fold_constants(mod);
    mod=simplify_control_flow(mod);
    mod=eliminate_dead_code(mod);
  }
  em=emit_bytecode(mod);
  return em.ok();
}

void position_cases() {
  // Every emitted word carries its IR instruction's position, including
  // phi moves and branch terminators.
  {
    auto m=select_module();
    m.functions[0].blocks[0].instrs[0].pos={2,1,3};   // compare
    m.functions[0].blocks[0].instrs[1].pos={4,1,5};   // branch
    m.functions[0].blocks[3].instrs[0].pos={11,1,12}; // phi
    auto e=emit_bytecode(m);
    check(e.ok(),"pos emit ok");
    check(e.positions.size()==1 && e.positions[0].size()==e.functions[0].size(),"pos map parallel to code");
    bool saw_cmp=false,saw_br=false,saw_phi=false;
    for (std::size_t pc=0;pc<e.positions[0].size();++pc) {
      const auto&p=e.positions[0][pc];
      if (p.byte==2) saw_cmp=true;
      if (p.byte==4) saw_br=true;
      if (p.byte==11) saw_phi=true;
    }
    check(saw_cmp,"alu position emitted");
    check(saw_br,"terminator position emitted");
    check(saw_phi,"phi-move position emitted");
    check(source_position(e,99,0).line==0,"oob function -> unset");
    check(source_position(e,0,e.functions[0].size()+5).line==0,"oob pc -> unset");
    // source_pcs: every pc stamped with the phi position is a valid
    // source-level breakpoint target.
    const auto pcs=source_pcs(e,0,{11,1,12});
    check(!pcs.empty(),"source_pcs finds phi pcs");
    for (const auto pc:pcs) {
      const auto p=source_position(e,0,pc);
      check(p.byte==11&&p.line==1&&p.column==12,"source_pcs positions consistent");
    }
    check(source_pcs(e,0,{99,9,9}).empty(),"source_pcs misses unknown pos");
  }
  // Runtime trap maps back to the trapping instruction's source position,
  // through both the baseline and the optimized pipeline.
  {
    const std::string src="package \"a\" version \"A\" fn f() -> i32 { let x = 4; let d = x - x; let q = 100 / d; return q; }";
    for (bool opt:{false,true}) {
      EmitResult em; IrModule mod;
      check(compile_source(src,opt,em,mod),opt?"opt src compiles":"src compiles");
      Position expect{};
      for (const auto& b:mod.functions[0].blocks) for (const auto& in:b.instrs)
        if (in.op==IrOp::binary && in.detail==3) expect=in.pos;
      check(expect.line!=0,"division carries a position");
      std::array<std::int32_t,256> r{};
      auto res=run_register_vm(em.functions[0],r);
      const auto* err=std::get_if<VmError>(&res);
      check(err && err->code==VmErrorCode::divide_by_zero,"division traps");
      if (err) {
        const auto p=source_position(em,0,err->pc);
        check(p.byte==expect.byte && p.line==expect.line && p.column==expect.column,
              opt?"optimized trap maps to division source":"trap maps to division source");
      }
    }
  }
  // Compile errors carry source positions: lower diagnostics, verify
  // diagnostics surfaced through emit, and emit errors.
  {
    const std::string src="package \"a\" version \"A\" fn f() -> i32 { return missing_name; }";
    auto parsed=parse_declarations(src);
    const auto* d=std::get_if<DeclarationAst>(&parsed);
    check(d!=nullptr,"bad-name source parses");
    if (d) {
      std::size_t body_idx=no_declaration;
      for (const auto& n:d->nodes()) if (n.kind==DeclarationKind::fn_decl) { body_idx=n.body; break; }
      LowerResult lr=lower_function(d->bodies()[body_idx],"f",i32(),{});
      check(!lr.ok() && !lr.diagnostics.empty(),"unknown name diagnosed");
      if (!lr.diagnostics.empty()) {
        const auto& dg=lr.diagnostics.front();
        check(dg.pos.line!=0,"lower diagnostic has a position");
        check(dg.pos.byte==src.find("missing_name"),"diagnostic byte offset matches source");
      }
    }
    auto m=arith_module();
    auto& t=m.functions[0].blocks[0].instrs.back();
    t.op=IrOp::jump; t.target=99; t.pos={7,3,9};
    auto e=emit_bytecode(m);
    check(!e.ok() && !e.diagnostics.empty(),"verify failure reported");
    bool found=false;
    for (const auto& dg:e.diagnostics) if (dg.pos.byte==7 && dg.pos.line==3 && dg.pos.column==9) found=true;
    check(found,"verify diagnostic carries instruction position");
    auto c=arith_module();
    IrInstr konst; konst.op=IrOp::load; konst.def=9; konst.result=i32(); konst.pos={3,1,4};
    konst.args={v(1)};
    c.functions[0].blocks[0].instrs.insert(c.functions[0].blocks[0].instrs.begin(),konst);
    auto ce=emit_bytecode(c);
    check(!ce.errors.empty() && ce.errors.front().pos.byte==3,"emit error carries position");
  }
}
} // namespace
int main() {
  cases();
  position_cases();
  if (failures) { std::cerr << failures << " emit test(s) failed\n"; return 1; }
  std::cout << "emit tests passed\n";
  return 0;
}
