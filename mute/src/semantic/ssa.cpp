#include "poko/mute/ssa.hpp"
#include <algorithm>
#include <array>
#include <iterator>
#include <map>
#include <set>
namespace poko::mute {
namespace {
bool is_terminator(IrOp op) { return op==IrOp::jump || op==IrOp::branch || op==IrOp::return_; }
} // namespace

IrResult verify(const IrModule& module) {
  IrResult result;
  auto report=[&](IrErrorCode c,std::string d,std::size_t f,std::size_t b){
    result.diagnostics.push_back({c,std::move(d),f,b});
  };
  for (std::size_t fi=0;fi<module.functions.size();++fi) {
    const auto& fn=module.functions[fi];
    if (fn.blocks.empty()) { report(IrErrorCode::empty_function,fn.name,fi,0); continue; }
    std::set<std::string> labels;
    for (std::size_t bi=0;bi<fn.blocks.size();++bi)
      if (!labels.insert(fn.blocks[bi].label).second)
        report(IrErrorCode::duplicate_label,fn.blocks[bi].label,fi,bi);
    // Reachability from entry block 0 via terminator targets.
    std::vector<char> reachable(fn.blocks.size(),0); reachable[0]=1;
    for (bool grew=true;grew;) {
      grew=false;
      for (std::size_t bi=0;bi<fn.blocks.size();++bi) if (reachable[bi] && !fn.blocks[bi].instrs.empty()) {
        const auto& t=fn.blocks[bi].instrs.back();
        for (const auto tgt:{t.target,t.target2})
          if (tgt!=0 && tgt<=fn.blocks.size() && !reachable[tgt-1]) { reachable[tgt-1]=1; grew=true; }
      }
    }
    for (std::size_t bi=0;bi<fn.blocks.size();++bi)
      if (!reachable[bi]) report(IrErrorCode::unreachable_block,"block "+std::to_string(bi),fi,bi);
    // Pre-scan: every def id in the function with its defining block and
    // instruction index, plus result types.
    std::map<std::uint32_t,Type> all_defs;
    std::map<std::uint32_t,std::pair<std::size_t,std::size_t>> def_loc;
    for (std::size_t bpi=0;bpi<fn.blocks.size();++bpi)
      for (std::size_t iii=0;iii<fn.blocks[bpi].instrs.size();++iii) {
        const auto& in=fn.blocks[bpi].instrs[iii];
        if (in.def!=0) { all_defs[in.def]=in.result; def_loc[in.def]={bpi,iii}; }
      }
    // Dominators over reachable blocks (standard iterative dataflow on the
    // actual terminator edges). A def is usable at (block,instr) iff its
    // block dominates the use block, or it is an earlier instruction in the
    // same block. Params (ids 1..N) dominate everything.
    const std::size_t nb=fn.blocks.size();
    std::vector<std::set<std::uint32_t>> apreds(nb);
    for (std::size_t bpi=0;bpi<nb;++bpi) {
      if (!reachable[bpi] || fn.blocks[bpi].instrs.empty()) continue;
      const auto& t=fn.blocks[bpi].instrs.back();
      for (const auto tgt:{t.target,t.target2})
        if (tgt!=0 && tgt<=nb) apreds[tgt-1].insert(static_cast<std::uint32_t>(bpi));
    }
    std::set<std::uint32_t> reachable_set;
    for (std::size_t bpi=0;bpi<nb;++bpi) if (reachable[bpi]) reachable_set.insert(bpi);
    std::vector<std::set<std::uint32_t>> dom(nb);
    for (std::size_t bpi=0;bpi<nb;++bpi) dom[bpi]=reachable[bpi]?reachable_set:std::set<std::uint32_t>{};
    dom[0]={static_cast<std::uint32_t>(0)};
    for (bool grew=true;grew;) {
      grew=false;
      for (std::size_t bpi=1;bpi<nb;++bpi) {
        if (!reachable[bpi]) continue;
        std::set<std::uint32_t> next{static_cast<std::uint32_t>(bpi)};
        bool first=true;
        for (const auto p:apreds[bpi]) {
          if (first) { next.insert(dom[p].begin(),dom[p].end()); first=false; }
          else {
            std::set<std::uint32_t> inter;
            std::set_intersection(next.begin(),next.end(),dom[p].begin(),dom[p].end(),
              std::inserter(inter,inter.begin()));
            next=std::move(inter);
          }
        }
        if (first) next.insert(static_cast<std::uint32_t>(bpi)); // no reachable preds: only itself
        if (next!=dom[bpi]) { dom[bpi]=std::move(next); grew=true; }
      }
    }
    const std::size_t nparams=fn.params.size();
    auto dominates=[&](std::uint32_t def_id,std::size_t use_bi,std::size_t use_ii)->bool {
      if (def_id>=1 && def_id<=nparams) return true;
      const auto it=def_loc.find(def_id);
      if (it==def_loc.end()) return false;
      const auto [dbi,dii]=it->second;
      if (dbi==use_bi) return dii<use_ii;
      return dom[use_bi].count(dbi)!=0;
    };
    std::set<std::uint32_t> seen_defs;
    for (std::size_t bi=0;bi<fn.blocks.size();++bi) {
      const auto& block=fn.blocks[bi];
      if (block.instrs.empty()) { report(IrErrorCode::missing_terminator,block.label,fi,bi); continue; }
      if (!reachable[bi]) continue; // still check structure below via preds
      const auto& term=block.instrs.back();
      if (!is_terminator(term.op)) report(IrErrorCode::missing_terminator,block.label,fi,bi);
      if (term.op==IrOp::jump && (term.target==0 || term.target>fn.blocks.size()))
        report(IrErrorCode::bad_terminator,"jump target",fi,bi);
      if (term.op==IrOp::branch && (term.target==0 || term.target2==0 ||
          term.target>fn.blocks.size() || term.target2>fn.blocks.size()))
        report(IrErrorCode::bad_terminator,"branch target",fi,bi);
      if (term.op==IrOp::return_ && !same_type(term.result,fn.result))
        report(IrErrorCode::type_mismatch,"return type",fi,bi);
      // Actual predecessor edges must equal declared preds.
      std::set<std::uint32_t> expected,actual(block.preds.begin(),block.preds.end());
      for (std::size_t pj=0;pj<fn.blocks.size();++pj) {
        if (fn.blocks[pj].instrs.empty()) continue;
        const auto& pt=fn.blocks[pj].instrs.back();
        if (pt.target==bi+1 || pt.target2==bi+1) expected.insert(static_cast<std::uint32_t>(pj+1));
      }
      if (expected!=actual) report(IrErrorCode::bad_terminator,"predecessor set mismatch",fi,bi);
      for (std::size_t ii=0;ii<block.instrs.size();++ii) {
        const auto& in=block.instrs[ii];
        const bool last=ii+1==block.instrs.size();
        if (is_terminator(in.op) && !last) { report(IrErrorCode::bad_terminator,"mid-block terminator",fi,bi); break; }
        if (!is_terminator(in.op) && last) { report(IrErrorCode::missing_terminator,block.label,fi,bi); break; }
        if (in.def!=0) {
          if (!seen_defs.insert(in.def).second)
            report(IrErrorCode::type_mismatch,"duplicate def "+std::to_string(in.def),fi,bi);
        }
        for (const auto& arg:in.args) {
          const bool phi_arg=in.op==IrOp::phi;
          const bool known=phi_arg ? (all_defs.count(arg.value) || (arg.value>=1 && arg.value<=nparams))
                                   : (arg.value==0 || dominates(arg.value,bi,ii));
          if (arg.value!=0 && !known) {
            report(IrErrorCode::undefined_value,"value "+std::to_string(arg.value),fi,bi); continue;
          }
          if (phi_arg && arg.value!=0) {
            const auto it=all_defs.find(arg.value);
            const Type& t=it!=all_defs.end()?it->second:(arg.value>=1 && arg.value<=nparams?fn.params[arg.value-1]:Type{});
            if (t.tag==TypeTag::unknown) report(IrErrorCode::type_mismatch,"phi input type",fi,bi);
          }
        }
        if (in.op==IrOp::phi && in.args.size()!=2*expected.size())
          report(IrErrorCode::phi_arity,"phi operands "+std::to_string(in.args.size())+" vs preds "+std::to_string(expected.size()),fi,bi);
        if (in.op==IrOp::binary || in.op==IrOp::compare) {
          if (in.args.size()<2) report(IrErrorCode::bad_operand_count,"binary needs 2",fi,bi);
          else {
            const auto ta=all_defs.count(in.args[0].value)?all_defs.at(in.args[0].value):(in.args[0].value>=1&&in.args[0].value<=nparams?fn.params[in.args[0].value-1]:Type{});
            const auto tb=all_defs.count(in.args[1].value)?all_defs.at(in.args[1].value):(in.args[1].value>=1&&in.args[1].value<=nparams?fn.params[in.args[1].value-1]:Type{});
            if (ta.tag!=TypeTag::unknown && tb.tag!=TypeTag::unknown && !same_type(ta,tb))
              report(IrErrorCode::type_mismatch,"operand types differ",fi,bi);
          }
        }
      }
    }
  }
  return result;
}
std::string dump_ir(const IrModule& module) {
  std::string out;
  for (const auto& fn:module.functions) {
    out+="fn "+fn.name+"\n";
    for (const auto& b:fn.blocks) {
      out+="  "+b.label+":\n";
      for (const auto& in:b.instrs) {
        out+="    op="+std::to_string(static_cast<int>(in.op))+" def="+std::to_string(in.def)+
             " args="+std::to_string(in.args.size())+" target="+std::to_string(in.target)+
             "/"+std::to_string(in.target2)+"\n";
      }
    }
  }
  return out;
}
std::string_view name(IrErrorCode code) {
  constexpr auto names=std::array<std::string_view,10>{
    "empty_function","missing_entry","missing_terminator","bad_terminator",
    "undefined_value","phi_arity","type_mismatch","bad_operand_count",
    "duplicate_label","unreachable_block"};
  return names.at(static_cast<std::size_t>(code));
}
} // namespace poko::mute
