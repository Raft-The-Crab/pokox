#include "poko/mute/emit.hpp"
#include <array>
#include <map>
#include <set>
#include <limits>
namespace poko::mute {
namespace {
bool is_terminator_pub(IrOp op) { return op==IrOp::jump || op==IrOp::branch || op==IrOp::return_; }
Opcode alu(IrOp op,std::uint8_t d) {
  static constexpr std::array<Opcode,5> bin{Opcode::add,Opcode::sub,Opcode::mul,Opcode::div,Opcode::mod};
  static constexpr std::array<Opcode,6> cmp{Opcode::eq,Opcode::ne,Opcode::lt,Opcode::le,Opcode::gt,Opcode::ge};
  switch (op) {
    case IrOp::binary: return bin.at(d>4?4:d);
    case IrOp::compare: return cmp.at(d>5?5:d);
    case IrOp::unary: return Opcode::neg;
    default: return Opcode::move;
  }
}
Instruction mk(Opcode op,std::uint8_t a,std::uint8_t b,std::uint8_t c) { return {op,a,b,c}; }
Instruction mov(std::uint8_t d,std::uint8_t s) { return mk(Opcode::move,d,s,0); }
// 16-bit displacement in b:c, signed.
Instruction br16(Opcode op,std::uint8_t a,std::int32_t disp) {
  const auto u=static_cast<std::uint16_t>(static_cast<std::int16_t>(disp));
  return mk(op,a,static_cast<std::uint8_t>(u>>8),static_cast<std::uint8_t>(u&0xFF));
}
struct PhiMove { std::uint8_t d,s; Position pos; };
// ext_prefix long branch: kind 1=jump,2=branch-true on r[b],3=branch-false.
std::pair<Instruction,Instruction> br32(std::uint8_t kind,std::uint8_t reg,std::int32_t disp) {
  const auto u=static_cast<std::uint32_t>(disp);
  Instruction pay{static_cast<Opcode>(u&0xFF),static_cast<std::uint8_t>((u>>8)&0xFF),
                  static_cast<std::uint8_t>((u>>16)&0xFF),static_cast<std::uint8_t>((u>>24)&0xFF)};
  return {mk(Opcode::ext_prefix,kind,reg,0),pay};
}
} // namespace

EmitResult emit_bytecode(const IrModule& module) {
  EmitResult out;
  auto ver=verify(module);
  if (!ver.ok()) { out.diagnostics=std::move(ver.diagnostics); return out; }
  if (module.functions.size()>256) { out.errors.push_back({EmitErrorCode::too_many_functions}); return out; }
  out.functions.reserve(module.functions.size());
  out.capabilities.reserve(module.functions.size());
  for (std::size_t fi=0;fi<module.functions.size();++fi) {
    const auto& fn=module.functions[fi];
    const std::size_t B=fn.blocks.size();
    // value id -> register is identity; ids must stay below the call window.
    std::uint32_t max_id=fn.params.size();
    for (const auto& b:fn.blocks) for (const auto& in:b.instrs) {
      max_id=std::max(max_id,in.def);
      for (const auto& a:in.args) max_id=std::max(max_id,a.value);
    }
    if (max_id>=call_arg_base || fn.params.size()>call_arg_window) {
      out.errors.push_back({EmitErrorCode::too_many_values,fi}); return out;
    }
    // Supported ops only.
    for (std::size_t bi=0;bi<B;++bi) for (std::size_t ii=0;ii<fn.blocks[bi].instrs.size();++ii) {
      const auto& in=fn.blocks[bi].instrs[ii];
      if (in.op==IrOp::load || in.op==IrOp::store) {
        out.errors.push_back({EmitErrorCode::unsupported_op,fi,bi,ii,in.pos}); return out;
      }
      if (in.op==IrOp::call || in.op==IrOp::call_host) {
        // The staging window is 32 registers at call_arg_base. More arguments
        // would wrap the uint8 register index and clobber r0/r1.
        if (in.args.size()>call_arg_window) {
          out.errors.push_back({EmitErrorCode::too_many_values,fi,bi,ii,in.pos}); return out;
        }
      }
      if (in.op==IrOp::call_host) {
        if (in.callee==0 || in.callee>module.hostcalls.size() ||
            module.hostcalls[in.callee-1].id>255) {
          out.errors.push_back({EmitErrorCode::unsupported_op,fi,bi,ii,in.pos}); return out;
        }
      }
    }
    // Successor edges and phi move lists: moves[join][pred] = (dst,src,pos).
    std::map<std::pair<std::size_t,std::size_t>,std::vector<PhiMove>> moves;
    std::set<std::size_t> joins;
    for (std::size_t bi=0;bi<B;++bi) {
      const auto& blk=fn.blocks[bi];
      bool in_phi=true;
      for (const auto& in:blk.instrs) {
        if (in.op!=IrOp::phi) { in_phi=false; break; }
        joins.insert(bi);
        for (const auto& a:in.args) {
          if (a.imm==0 || a.imm>B) { out.errors.push_back({EmitErrorCode::bad_phi_operand,fi,bi,0}); return out; }
          moves[{bi,static_cast<std::size_t>(a.imm-1)}].push_back(
            {static_cast<std::uint8_t>(in.def),static_cast<std::uint8_t>(a.value),in.pos});
        }
      }
      (void)in_phi;
    }
    // Actual predecessors per block from terminators.
    std::vector<std::vector<std::size_t>> preds(B);
    for (std::size_t bi=0;bi<B;++bi) {
      if (fn.blocks[bi].instrs.empty()) continue;
      const auto& t=fn.blocks[bi].instrs.back();
      if (t.target) preds[t.target-1].push_back(bi);
      if (t.target2) preds[t.target2-1].push_back(bi);
    }
    // Trampolines for phi edges whose pred ends in a conditional branch.
    struct Tramp { std::size_t join,pred; std::vector<PhiMove> mv; Position pos; };
    std::vector<Tramp> tramps;
    std::map<std::pair<std::size_t,std::size_t>,std::size_t> edge_tramp; // (pred,join)->tramp idx
    for (const auto& [key,mv]:moves) {
      const auto join=key.first,pred=key.second;
      const auto& pt=fn.blocks[pred].instrs.back();
      if (pt.op==IrOp::branch) {
        edge_tramp[key]=tramps.size(); // key is {join,pred}
        tramps.push_back({join,pred,mv,pt.pos});
      }
    }
    // Layout: prologue, blocks, then trampolines. Sizes depend on ext usage;
    // iterate. `prologue` words precede block 0 in the emitted stream.
    const std::size_t T=tramps.size(), NB=B+T, prologue=fn.params.size();
    std::vector<std::size_t> start(NB,0), sz(NB,0);
    std::vector<char> ext_jump(NB,0), ext_br(NB,0);
    auto term_kind=[&](std::size_t bi)->int { // 0 none,1 jump,2 ret,3 branch
      if (bi>=B || fn.blocks[bi].instrs.empty()) return 0;
      const auto op=fn.blocks[bi].instrs.back().op;
      return op==IrOp::jump?1:op==IrOp::return_?2:op==IrOp::branch?3:0;
    };
    auto instrs_size=[&](std::size_t bi)->std::size_t {
      if (bi>=B) { const auto& t=tramps[bi-B]; return t.mv.size()+(ext_jump[bi]?2:1); }
      const auto& blk=fn.blocks[bi];
      std::size_t n=0;
      for (const auto& in:blk.instrs) {
        if (in.op==IrOp::phi || is_terminator_pub(in.op)) continue;
        if (in.op==IrOp::constant) n+=2;
        else if (in.op==IrOp::call || in.op==IrOp::call_host) n+=in.args.size()+1;
        else n+=1;
      }
      const int tk=term_kind(bi);
      if (tk==1) n+=ext_jump[bi]?2:1;
      else if (tk==2) n+=1;
      else if (tk==3) n+=(ext_br[bi]?2:1)+(ext_jump[bi]?2:1); // br_true + jmp
      // inline phi moves for unconditional-jump edges out of this block
      for (const auto& [key,mv]:moves)
        if (key.second==bi && !edge_tramp.count(key)) n+=mv.size();
      return n;
    };
    for (int iter=0;iter<8;++iter) {
      std::size_t pc=prologue; bool changed=false;
      for (std::size_t i=0;i<NB;++i) { start[i]=pc; const auto s=instrs_size(i); if (sz[i]!=s){sz[i]=s;changed=true;} pc+=s; }
      // Simple ext decision: if block distance in words could exceed i16.
      for (std::size_t i=0;i<B;++i) {
        const int tk=term_kind(i); if (!tk) continue;
        const auto& t=fn.blocks[i].instrs.back();
        auto far=[&](std::uint32_t tgt)->bool {
          if (!tgt) return false;
          // conservative: distance between block starts
          const auto d=static_cast<std::int64_t>(start[tgt-1])-static_cast<std::int64_t>(start[i]);
          return d>30000 || d< -30000;
        };
        const bool ej=t.target&&far(t.target), ej2=t.target2&&far(t.target2);
        if (tk==1 && ej!=static_cast<bool>(ext_jump[i])) { ext_jump[i]=ej; changed=true; }
        if (tk==3) {
          if (ej!=static_cast<bool>(ext_br[i])) { ext_br[i]=ej; changed=true; }
          if (ej2!=static_cast<bool>(ext_jump[i])) { ext_jump[i]=ej2; changed=true; }
        }
      }
      // Trampolines are unconditional jumps to their join block.
      for (std::size_t i=B;i<NB;++i) {
        const auto d=static_cast<std::int64_t>(start[tramps[i-B].join])-static_cast<std::int64_t>(start[i]);
        const bool ej=d>30000 || d< -30000;
        if (ej!=static_cast<bool>(ext_jump[i])) { ext_jump[i]=ej; changed=true; }
      }
      if (!changed) break;
    }
    // Emit. smap records the source position of every emitted word (MUT-33).
    Bytecode code;
    std::vector<Position> smap;
    auto put=[&](Instruction in,Position p){ code.push_back(in); smap.push_back(p); };
    auto put2=[&](Instruction a,Instruction b,Position p){ put(a,p); put(b,p); };
    auto emit_moves=[&](std::vector<PhiMove> const& mv){
      for (const auto& m:mv) put(mov(m.d,m.s),m.pos);
    };
    // Prologue: move the caller-staged argument window into params 1..N.
    for (std::size_t k=0;k<prologue;++k)
      put(mov(static_cast<std::uint8_t>(k+1),static_cast<std::uint8_t>(call_arg_base+k)),Position{});
    for (std::size_t bi=0;bi<NB;++bi) {
      if (bi>=B) { // trampoline: moves + jump to join
        const auto& t=tramps[bi-B];
        emit_moves(t.mv);
        const auto disp=static_cast<std::int32_t>(start[t.join])-static_cast<std::int32_t>(code.size()+1);
        if (ext_jump[bi]) { auto p=br32(1,0,disp); put2(p.first,p.second,t.pos); }
        else put(br16(Opcode::jump,0,disp),t.pos);
        continue;
      }
      const auto& blk=fn.blocks[bi];
      for (const auto& in:blk.instrs) {
        if (in.op==IrOp::phi || is_terminator_pub(in.op)) continue;
        const auto d=static_cast<std::uint8_t>(in.def); const auto op=alu(in.op,in.detail);
        switch (in.op) {
          case IrOp::constant: {
            const auto imm=static_cast<std::int64_t>(in.args.empty()?0:in.args[0].imm);
            if (imm<std::numeric_limits<std::int32_t>::min() || imm>std::numeric_limits<std::int32_t>::max()) {
              out.errors.push_back({EmitErrorCode::unsupported_op,fi,bi,0,in.pos}); return out;
            }
            const auto u=static_cast<std::uint32_t>(static_cast<std::int32_t>(imm));
            put(mk(Opcode::load_imm,d,0,0),in.pos);
            put({static_cast<Opcode>(u&0xFF),static_cast<std::uint8_t>((u>>8)&0xFF),static_cast<std::uint8_t>((u>>16)&0xFF),static_cast<std::uint8_t>((u>>24)&0xFF)},in.pos);
            break;
          }
          case IrOp::copy: put(mov(d,static_cast<std::uint8_t>(in.args[0].value)),in.pos); break;
          case IrOp::unary: put(mk(op,d,static_cast<std::uint8_t>(in.args[0].value),0),in.pos); break;
          case IrOp::binary: case IrOp::compare:
            put(mk(op,d,static_cast<std::uint8_t>(in.args[0].value),static_cast<std::uint8_t>(in.args[1].value)),in.pos); break;
          case IrOp::call: case IrOp::call_host: {
            for (std::size_t k=0;k<in.args.size();++k)
              put(mov(static_cast<std::uint8_t>(call_arg_base+k),
                      static_cast<std::uint8_t>(in.args[k].value)),in.pos);
            const bool discards=in.def==0 || in.result.tag==TypeTag::unit;
            const auto dest=static_cast<std::uint8_t>(discards?0:in.def);
            if (in.op==IrOp::call)
              put(mk(Opcode::call,static_cast<std::uint8_t>(in.callee-1),call_arg_base,dest),in.pos);
            else
              put(mk(Opcode::call_host,
                     static_cast<std::uint8_t>(module.hostcalls[in.callee-1].id),call_arg_base,dest),in.pos);
            break;
          }
          default: break;
        }
      }
      // inline phi moves for unconditional-jump out-edges
      const auto& term=blk.instrs.back();
      if (term.op==IrOp::jump) {
        for (const auto& [key,mv]:moves)
          if (key.second==bi && !edge_tramp.count(key)) emit_moves(mv);
      }
      // terminator
      auto tgt_block=[&](std::uint32_t t)->std::size_t {
        if (!t) return 0;
        const auto join=t-1;
        auto it=edge_tramp.find({join,bi});
        if (it!=edge_tramp.end()) return B+it->second;
        return join;
      };
      if (term.op==IrOp::jump) {
        const auto to=tgt_block(term.target);
        const auto disp=static_cast<std::int32_t>(start[to])-static_cast<std::int32_t>(code.size()+1);
        if (ext_jump[bi]) { auto p=br32(1,0,disp); put2(p.first,p.second,term.pos); }
        else put(br16(Opcode::jump,0,disp),term.pos);
      } else if (term.op==IrOp::branch) {
        const auto cond=static_cast<std::uint8_t>(term.args.empty()?0:term.args[0].value);
        const auto toT=tgt_block(term.target), toF=tgt_block(term.target2);
        const auto dispT=static_cast<std::int32_t>(start[toT])-static_cast<std::int32_t>(code.size()+1);
        if (ext_br[bi]) { auto p=br32(2,cond,dispT); put2(p.first,p.second,term.pos); }
        else put(br16(Opcode::branch_true,cond,dispT),term.pos);
        const auto dispJ=static_cast<std::int32_t>(start[toF])-static_cast<std::int32_t>(code.size()+1);
        if (ext_jump[bi]) { auto p=br32(1,0,dispJ); put2(p.first,p.second,term.pos); }
        else put(br16(Opcode::jump,0,dispJ),term.pos);
      } else if (term.op==IrOp::return_) {
        put(mk(Opcode::ret,term.args.empty()?0:static_cast<std::uint8_t>(term.args[0].value),0,0),term.pos);
      }
    }
    out.functions.push_back(std::move(code));
    out.positions.push_back(std::move(smap));
    out.capabilities.push_back(fn.capabilities);
  }
  return out;
}

Position source_position(const EmitResult& result,std::size_t function,std::size_t pc) noexcept {
  if (function>=result.positions.size()) return {};
  const auto& m=result.positions[function];
  if (pc>=m.size()) return {};
  for (std::size_t i=pc+1;i>0;--i) {
    const auto& p=m[i-1];
    if (p.line!=0) return p;
  }
  return {};
}

std::vector<std::size_t> source_pcs(const EmitResult& result,std::size_t function,const Position& pos) {
  std::vector<std::size_t> out;
  if (function>=result.positions.size()) return out;
  const auto& m=result.positions[function];
  for (std::size_t pc=0;pc<m.size();++pc) {
    const auto& p=m[pc];
    if (p.byte==pos.byte && p.line==pos.line && p.column==pos.column) out.push_back(pc);
  }
  return out;
}
} // namespace poko::mute
