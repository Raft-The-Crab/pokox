#include "poko/mute/ssa.hpp"
#include <array>
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
    // Value defs: params are ids 1..N; instruction defs must be unique and
    // operands may only reference ids defined earlier in layout order
    // (a conservative approximation of dominance for the foundation pass).
    std::vector<Type> defs(1);
    std::set<std::uint32_t> defined_ids;
    for (std::size_t pi=0;pi<fn.params.size();++pi) { defs.push_back(fn.params[pi]); defined_ids.insert(static_cast<std::uint32_t>(pi+1)); }
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
          if (in.def>=defs.size()) defs.resize(in.def+1);
          defs[in.def]=in.result; defined_ids.insert(in.def);
        }
        for (const auto& arg:in.args) {
          if (arg.value!=0 && !defined_ids.count(arg.value)) {
            report(IrErrorCode::undefined_value,"value "+std::to_string(arg.value),fi,bi); continue;
          }
          if (in.op==IrOp::phi && arg.value!=0 && defs[arg.value].tag==TypeTag::unknown)
            report(IrErrorCode::type_mismatch,"phi input type",fi,bi);
        }
        if (in.op==IrOp::phi && in.args.size()!=2*expected.size())
          report(IrErrorCode::phi_arity,"phi operands "+std::to_string(in.args.size())+" vs preds "+std::to_string(expected.size()),fi,bi);
        if (in.op==IrOp::binary || in.op==IrOp::compare) {
          if (in.args.size()<2) report(IrErrorCode::bad_operand_count,"binary needs 2",fi,bi);
          else if (in.args[0].value<defs.size() && in.args[1].value<defs.size() && defined_ids.count(in.args[0].value) && defined_ids.count(in.args[1].value) &&
                   !same_type(defs[in.args[0].value],defs[in.args[1].value]))
            report(IrErrorCode::type_mismatch,"operand types differ",fi,bi);
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
