#include "poko/mute/register_vm.hpp"
#include <limits>
#include <bit>
namespace poko::mute {
VmResult run_register_vm(std::span<const Instruction> code,std::array<std::int32_t,256> r,std::size_t budget) {
  if (budget>100'000) return VmError{VmErrorCode::invalid_budget,0};
  auto valid=validate_bytecode(code);
  if (const auto* e=std::get_if<BytecodeError>(&valid)) return VmError{VmErrorCode::invalid_bytecode,e->offset};
  r[0]=0; std::size_t pc=0, steps=0;
  while (pc<code.size()) {
    if (steps>=budget) return VmError{VmErrorCode::budget_exceeded,pc};
    ++steps; const auto i=code[pc]; const auto current=pc; ++pc;
    const auto x=r[i.b], y=r[i.c]; std::int64_t value=0;
    switch (i.op) {
      case Opcode::add:value=static_cast<std::int64_t>(x)+y;break;
      case Opcode::sub:value=static_cast<std::int64_t>(x)-y;break;
      case Opcode::mul:value=static_cast<std::int64_t>(x)*y;break;
      case Opcode::div: case Opcode::mod:
        if (y==0) return VmError{VmErrorCode::divide_by_zero,current};
        if (x==std::numeric_limits<std::int32_t>::min() && y==-1) return VmError{VmErrorCode::overflow,current};
        value=i.op==Opcode::div ? x/y : x%y; break;
      case Opcode::neg:value=-static_cast<std::int64_t>(x);break;
      case Opcode::eq:value=x==y;break; case Opcode::ne:value=x!=y;break;
      case Opcode::lt:value=x<y;break; case Opcode::le:value=x<=y;break;
      case Opcode::gt:value=x>y;break; case Opcode::ge:value=x>=y;break;
      case Opcode::move:value=x;break;
      case Opcode::load_imm: {
        const auto pay=code[pc++];
        const auto u=static_cast<std::uint32_t>(pay.op) | (static_cast<std::uint32_t>(pay.a)<<8) |
          (static_cast<std::uint32_t>(pay.b)<<16) | (static_cast<std::uint32_t>(pay.c)<<24);
        r[i.a]=std::bit_cast<std::int32_t>(u);
        continue;
      }
      case Opcode::ext_prefix: {
        const auto payload=code[pc++];
        const auto bits=static_cast<std::uint32_t>(payload.op) | (static_cast<std::uint32_t>(payload.a)<<8) |
          (static_cast<std::uint32_t>(payload.b)<<16) | (static_cast<std::uint32_t>(payload.c)<<24);
        const bool take=i.a==1 || ((r[i.b]!=0)==(i.a==2));
        if (take) pc=static_cast<std::size_t>(static_cast<std::int64_t>(pc)+std::bit_cast<std::int32_t>(bits));
        continue;
      }
      case Opcode::jump:pc=static_cast<std::size_t>(static_cast<std::int64_t>(pc)+branch_offset(i));continue;
      case Opcode::branch_true:case Opcode::branch_false:
        if ((r[i.a]!=0)==(i.op==Opcode::branch_true)) pc=static_cast<std::size_t>(static_cast<std::int64_t>(pc)+branch_offset(i));
        continue;
      case Opcode::ret:return r[i.a];
      case Opcode::halt:return VmError{VmErrorCode::no_return,current};
      default:return VmError{VmErrorCode::invalid_bytecode,current};
    }
    if (value<std::numeric_limits<std::int32_t>::min() || value>std::numeric_limits<std::int32_t>::max()) return VmError{VmErrorCode::overflow,current};
    r[i.a]=static_cast<std::int32_t>(value);
  }
  return VmError{VmErrorCode::no_return,pc};
}
} // namespace poko::mute
