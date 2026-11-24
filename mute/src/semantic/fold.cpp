#include "poko/mute/fold.hpp"
#include <limits>

namespace poko::mute {
namespace {

constexpr std::int64_t kI32Min=std::numeric_limits<std::int32_t>::min();
constexpr std::int64_t kI32Max=std::numeric_limits<std::int32_t>::max();

bool int_scalar(const Type& t) {
  return t.tag==TypeTag::scalar && (t.name=="i32" || t.name=="bool");
}

// Mirrors run_register_vm arithmetic exactly: i64 intermediate, i32 range
// trap, div/mod zero and INT32_MIN/-1 traps.
struct Folded { std::int64_t value; bool ok; };

Folded eval_binary(std::uint8_t detail,std::int64_t x,std::int64_t y) {
  std::int64_t r=0;
  switch (detail) {
    case 0: r=x+y; break;
    case 1: r=x-y; break;
    case 2: r=x*y; break;
    case 3:
      if (y==0 || (x==kI32Min && y==-1)) return {0,false};
      r=x/y; break;
    case 4:
      if (y==0 || (x==kI32Min && y==-1)) return {0,false};
      r=x%y; break;
    default: return {0,false};
  }
  if (r<kI32Min || r>kI32Max) return {0,false};
  return {r,true};
}

Folded eval_unary(std::uint8_t detail,std::int64_t x) {
  if (detail!=0) return {0,false};
  const std::int64_t r=-x;
  if (r<kI32Min || r>kI32Max) return {0,false};
  return {r,true};
}

Folded eval_compare(std::uint8_t detail,std::int64_t x,std::int64_t y) {
  switch (detail) {
    case 0: return {x==y?1:0,true};
    case 1: return {x!=y?1:0,true};
    case 2: return {x<y?1:0,true};
    case 3: return {x<=y?1:0,true};
    case 4: return {x>y?1:0,true};
    case 5: return {x>=y?1:0,true};
    default: return {0,false};
  }
}

} // namespace

IrModule fold_constants(const IrModule& module) {
  IrModule out=module;
  for (auto& fn:out.functions) {
    for (auto& blk:fn.blocks) {
      // def id -> constant value, valid only for defs earlier in this block.
      std::vector<std::pair<std::uint32_t,std::int64_t>> consts;
      consts.reserve(blk.instrs.size());
      auto lookup=[&](std::uint32_t id)->const std::int64_t* {
        for (auto it=consts.rbegin();it!=consts.rend();++it)
          if (it->first==id) return &it->second;
        return nullptr;
      };
      for (auto& in:blk.instrs) {
        if (in.op==IrOp::constant && in.def!=0 && int_scalar(in.result) && !in.args.empty())
          consts.push_back({in.def,static_cast<std::int64_t>(in.args[0].imm)});
        const bool foldable=
          (in.op==IrOp::binary || in.op==IrOp::compare) ? in.args.size()>=2 :
          (in.op==IrOp::unary || in.op==IrOp::copy) ? in.args.size()>=1 : false;
        if (!foldable || in.def==0 || !int_scalar(in.result)) continue;
        const auto* x=lookup(in.args[0].value);
        if (!x) continue;
        Folded f{0,false};
        if (in.op==IrOp::copy) {
          f={*x,true};
        } else if (in.op==IrOp::unary) {
          f=eval_unary(in.detail,*x);
        } else {
          const auto* y=lookup(in.args[1].value);
          if (!y) continue;
          f=in.op==IrOp::binary ? eval_binary(in.detail,*x,*y)
                               : eval_compare(in.detail,*x,*y);
        }
        if (!f.ok) continue; // leave the trap/overflow for the runtime
        in.op=IrOp::constant;
        in.args={IrOperand{0,static_cast<std::uint64_t>(f.value)}};
        in.detail=0; in.target=0; in.target2=0;
        consts.push_back({in.def,f.value});
      }
    }
  }
  return out;
}

} // namespace poko::mute
