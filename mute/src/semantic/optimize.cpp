#include "poko/mute/optimize.hpp"
#include <algorithm>
#include <set>

namespace poko::mute {
namespace {

bool is_terminator(IrOp op) { return op==IrOp::jump || op==IrOp::branch || op==IrOp::return_; }
// Ops that cannot trap and have no observable effect. Arithmetic is excluded:
// every ALU op can trap (overflow / divide by zero) in this VM.
bool is_pure(IrOp op) { return op==IrOp::constant || op==IrOp::copy || op==IrOp::compare || op==IrOp::phi; }

} // namespace

IrModule eliminate_dead_code(const IrModule& module) {
  IrModule out=module;
  for (auto& fn:out.functions) {
    // Liveness is function-global: SSA values flow across blocks (phis,
    // branches), so a def in one block can be used in another.
    std::set<std::uint32_t> used;
    for (const auto& blk:fn.blocks)
      for (const auto& in:blk.instrs)
        if (!is_pure(in.op) || is_terminator(in.op))
          for (const auto& a:in.args) if (a.value!=0) used.insert(a.value);
    for (bool grew=true;grew;) {
      grew=false;
      for (const auto& blk:fn.blocks) for (const auto& in:blk.instrs) {
        if (!is_pure(in.op) || in.def==0 || !used.count(in.def)) continue;
        for (const auto& a:in.args) if (a.value!=0 && used.insert(a.value).second) grew=true;
      }
    }
    for (auto& blk:fn.blocks) {
      auto& instrs=blk.instrs;
      instrs.erase(std::remove_if(instrs.begin(),instrs.end(),[&](const IrInstr& in){
        return is_pure(in.op) && in.def!=0 && !used.count(in.def);
      }),instrs.end());
    }
  }
  return out;
}

IrModule simplify_control_flow(const IrModule& module) {
  IrModule out=module;
  for (auto& fn:out.functions) {
    const std::size_t nb=fn.blocks.size();
    // Pass 1: fold branches on same-block-earlier constants.
    for (auto& blk:fn.blocks) {
      if (blk.instrs.empty()) continue;
      auto& term=blk.instrs.back();
      if (term.op!=IrOp::branch || term.args.empty()) continue;
      const auto cid=term.args[0].value;
      if (cid==0) continue;
      const IrInstr* con=nullptr;
      for (const auto& in:blk.instrs) {
        if (in.def==cid && in.op==IrOp::constant) { con=&in; break; }
        if (in.def==cid) break; // def is not a constant; stop scanning
      }
      if (!con || con->args.empty()) continue;
      const auto cval=static_cast<std::int64_t>(con->args[0].imm);
      const bool take=cval!=0;
      term.op=IrOp::jump;
      term.args.clear();
      term.target=take?term.target:term.target2;
      term.target2=0;
    }
    // Pass 2: drop unreachable blocks and remap indices.
    std::vector<char> reach(nb,0); reach[0]=1;
    for (bool grew=true;grew;) {
      grew=false;
      for (std::size_t bi=0;bi<nb;++bi) if (reach[bi] && !fn.blocks[bi].instrs.empty()) {
        const auto& t=fn.blocks[bi].instrs.back();
        for (const auto tgt:{t.target,t.target2})
          if (tgt!=0 && tgt<=nb && !reach[tgt-1]) { reach[tgt-1]=1; grew=true; }
      }
    }
    std::vector<std::uint32_t> remap(nb,0);
    std::vector<IrBlock> kept;
    kept.reserve(nb);
    for (std::size_t bi=0;bi<nb;++bi) {
      if (!reach[bi]) continue;
      remap[bi]=static_cast<std::uint32_t>(kept.size()+1);
      kept.push_back(std::move(fn.blocks[bi]));
    }
    // Always rebuild: pass 1 may have changed edges even when no block was
    // removed, leaving declared preds stale.
    for (auto& blk:kept) {
      for (auto& in:blk.instrs) {
        if (in.target) in.target=remap[in.target-1];
        if (in.target2) in.target2=remap[in.target2-1];
        if (in.op==IrOp::phi) {
          // Phi operands carry imm = predecessor block index + 1; remap each.
          for (std::size_t k=0;k+1<in.args.size();k+=2)
            if (in.args[k].imm) in.args[k].imm=remap[in.args[k].imm-1];
          for (std::size_t k=1;k<in.args.size();k+=2)
            if (in.args[k].imm) in.args[k].imm=remap[in.args[k].imm-1];
        }
        blk.preds.clear();
      }
    }
    // Rebuild declared preds from actual edges.
    for (std::size_t bi=0;bi<kept.size();++bi) {
      std::set<std::uint32_t> ps;
      for (std::size_t pj=0;pj<kept.size();++pj) {
        if (kept[pj].instrs.empty()) continue;
        const auto& t=kept[pj].instrs.back();
        if (t.target==bi+1 || t.target2==bi+1) ps.insert(static_cast<std::uint32_t>(pj+1));
      }
      kept[bi].preds.assign(ps.begin(),ps.end());
    }
    // Repair phis: pass 1 may have removed an edge while both endpoints
    // stayed reachable, leaving phi operands for a predecessor that no
    // longer exists. Drop operand pairs whose (remapped) pred id is not an
    // actual predecessor.
    for (auto& blk:kept) {
      const std::set<std::uint32_t> ps(blk.preds.begin(),blk.preds.end());
      for (auto& in:blk.instrs) {
        if (in.op!=IrOp::phi) continue;
        std::vector<IrOperand> kept_args;
        kept_args.reserve(in.args.size());
        for (const auto& a:in.args)
          if (a.imm!=0 && ps.count(static_cast<std::uint32_t>(a.imm))) kept_args.push_back(a);
        in.args=std::move(kept_args);
      }
    }
    fn.blocks=std::move(kept);
  }
  return out;
}

} // namespace poko::mute
