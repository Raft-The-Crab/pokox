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
  for (std::size_t fi=0;fi<module.functions.size();++fi) {
    const auto& fn=module.functions[fi];
    const std::size_t B=fn.blocks.size();
    // value id -> register is identity; ids must fit u8.
    std::uint32_t max_id=fn.params.size();
    for (const auto& b:fn.blocks) for (const auto& in:b.instrs) {
      max_id=std::max(max_id,in.def);
      for (const auto& a:in.args) max_id=std::max(max_id,a.value);
    }
    if (max_id>255) { out.errors.push_back({EmitErrorCode::too_many_values,fi}); return out; }
    // Supported ops only.
    for (std::size_t bi=0;bi<B;++bi) for (std::size_t ii=0;ii<fn.blocks[bi].instrs.size();++ii) {
      const auto op=fn.blocks[bi].instrs[ii].op;
      if (op==IrOp::call || op==IrOp::load || op==IrOp::store) {
        out.errors.push_back({EmitErrorCode::unsupported_op,fi,bi,ii}); return out;
      }
    }
    // Successor edges and phi move lists: moves[join][pred] = (dst,src).
    std::map<std::pair<std::size_t,std::size_t>,std::vector<std::pair<std::uint8_t,std::uint8_t>>> moves;
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
            {static_cast<std::uint8_t>(in.def),static_cast<std::uint8_t>(a.value)});
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
    struct Tramp { std::size_t join,pred; std::vector<std::pair<std::uint8_t,std::uint8_t>> mv; };
    std::vector<Tramp> tramps;
    std::map<std::pair<std::size_t,std::size_t>,std::size_t> edge_tramp; // (pred,join)->tramp idx
    for (const auto& [key,mv]:moves) {
      const auto join=key.first,pred=key.second;
      const auto& pt=fn.blocks[pred].instrs.back();
      if (pt.op==IrOp::branch) {
        edge_tramp[key]=tramps.size(); // key is {join,pred}
        tramps.push_back({join,pred,mv});
      }
    }
    // Layout: blocks then trampolines. Sizes depend on ext usage; iterate.
    const std::size_t T=tramps.size(), NB=B+T;
    std::vector<std::size_t> start(NB,0), sz(NB,0);
    std::vector<char> ext_jump(NB,0), ext_br(NB,0);
    auto term_kind=[&](std::size_t bi)->int { // 0 none,1 jump,2 ret,3 branch
      if (bi>=B || fn.blocks[bi].instrs.empty()) return 0;
      const auto op=fn.blocks[bi].instrs.back().op;
      return op==IrOp::jump?1:op==IrOp::return_?2:op==IrOp::branch?3:0;
    };
    auto instrs_size=[&](std::size_t bi)->std::size_t {
      if (bi>=B) { const auto& t=tramps[bi-B]; return t.mv.size()+1; }
      const auto& blk=fn.blocks[bi];
      std::size_t n=0;
      for (const auto& in:blk.instrs) {
        if (in.op==IrOp::phi || is_terminator_pub(in.op)) continue;
        n+=in.op==IrOp::constant?2:1;
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
      std::size_t pc=0; bool changed=false;
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
      if (!changed) break;
    }
    // Emit.
    Bytecode code;
    auto emit_moves=[&](std::vector<std::pair<std::uint8_t,std::uint8_t>> const& mv){
      for (const auto& [d,s]:mv) code.push_back(mov(d,s));
    };
    for (std::size_t bi=0;bi<NB;++bi) {
      if (bi>=B) { // trampoline: moves + jump to join
        const auto& t=tramps[bi-B];
        emit_moves(t.mv);
        const auto disp=static_cast<std::int32_t>(start[t.join])-static_cast<std::int32_t>(code.size()+1);
        code.push_back(br16(Opcode::jump,0,disp));
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
              out.errors.push_back({EmitErrorCode::unsupported_op,fi,bi,0}); return out;
            }
            const auto u=static_cast<std::uint32_t>(static_cast<std::int32_t>(imm));
            code.push_back(mk(Opcode::load_imm,d,0,0));
            code.push_back({static_cast<Opcode>(u&0xFF),static_cast<std::uint8_t>((u>>8)&0xFF),static_cast<std::uint8_t>((u>>16)&0xFF),static_cast<std::uint8_t>((u>>24)&0xFF)});
            break;
          }
          case IrOp::copy: code.push_back(mov(d,static_cast<std::uint8_t>(in.args[0].value))); break;
          case IrOp::unary: code.push_back(mk(op,d,static_cast<std::uint8_t>(in.args[0].value),0)); break;
          case IrOp::binary: case IrOp::compare:
            code.push_back(mk(op,d,static_cast<std::uint8_t>(in.args[0].value),static_cast<std::uint8_t>(in.args[1].value))); break;
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
        if (ext_jump[bi]) { auto p=br32(1,0,disp); code.push_back(p.first); code.push_back(p.second); }
        else code.push_back(br16(Opcode::jump,0,disp));
      } else if (term.op==IrOp::branch) {
        const auto cond=static_cast<std::uint8_t>(term.args.empty()?0:term.args[0].value);
        const auto toT=tgt_block(term.target), toF=tgt_block(term.target2);
        const auto dispT=static_cast<std::int32_t>(start[toT])-static_cast<std::int32_t>(code.size()+1);
        if (ext_br[bi]) { auto p=br32(2,cond,dispT); code.push_back(p.first); code.push_back(p.second); }
        else code.push_back(br16(Opcode::branch_true,cond,dispT));
        const auto dispJ=static_cast<std::int32_t>(start[toF])-static_cast<std::int32_t>(code.size()+1);
        if (ext_jump[bi]) { auto p=br32(1,0,dispJ); code.push_back(p.first); code.push_back(p.second); }
        else code.push_back(br16(Opcode::jump,0,dispJ));
      } else if (term.op==IrOp::return_) {
        code.push_back(mk(Opcode::ret,term.args.empty()?0:static_cast<std::uint8_t>(term.args[0].value),0,0));
      }
    }
    out.functions.push_back(std::move(code));
  }
  return out;
}
} // namespace poko::mute
